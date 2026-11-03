#include "softprophet.h"

#include <math.h>
#include <algorithm>
#include <string.h>

namespace softprophet
{

// ---------------------------------------------------------------------------------------------
// Constantes de calibrage. Elles decrivent le comportement "analogique" suppose du Prophet 2000
// (voir le manuel, section 7). Ce sont les valeurs a ajuster si l'oreille dit autre chose.
// ---------------------------------------------------------------------------------------------
static const double CUTOFF_MAX_HZ       = 20000.0;  // cutoff = 127
static const double CUTOFF_UNITS_PER_OCT = 14.1;    // "environ 14 unites par octave"
static const double ENV_FULL_OCTAVES    = 9.0;      // env amount = 127 -> balayage de la plage de 9 octaves
static const int    KEYTRACK_REF_NOTE   = 60;       // touche pour laquelle le suivi de clavier ne change rien
static const double TIME_MIN_S          = 0.0015;   // "instantane"
static const double TIME_BASE_S         = 0.003;    // temps pour la valeur 0+ ...
static const double TIME_RANGE          = 30000.0;  // ... jusqu'a 90 s pour la valeur 62
static const double RESONANCE_OSC_VALUE = 90.0;     // "debut d'oscillation environ 90"
static const double VOICE_GAIN          = 0.5;
static const double PI_D                = 3.14159265358979323846;


SoundData::SoundData() :
   rate_hz(31250.0f), start(0), end(0), sus_start(0), sus_end(0), rel_start(0), rel_end(0),
   sus_loop(false), rel_loop(false), bf(false), reverse(false),
   amp_a(0), amp_d(63), amp_s(255), amp_r(0), filt_a(0), filt_d(63), filt_s(255), filt_r(0),
   amp_peak_vel(0), filt_peak_vel(0), attack_vel(0), release_vel(0),
   cutoff(127), resonance(0), key_track(63), env_amount(0)
{
}

Patch::Patch() : mode(MODE_LAYER), split_point(60), velocity_threshold(0)
{
}


float envTimeSeconds(int value)
{
   if(value <= 0)
   {
      return (float)TIME_MIN_S;
   }
   if(value > 62)
   {
      value = 62;
   }
   return (float)(TIME_BASE_S * pow(TIME_RANGE, (double)value / 62.0));
}


float cutoffHz(int cutoff, int key_track, int note, float env_octaves)
{
   double oct = ((double)cutoff - 127.0) / CUTOFF_UNITS_PER_OCT;
   oct += ((double)(note - KEYTRACK_REF_NOTE) * ((double)key_track / 63.0)) / 12.0;
   oct += env_octaves;
   return (float)(CUTOFF_MAX_HZ * pow(2.0, oct));
}


// ---------------------------------------------------------------------------------------------
// Enveloppe ADSR
// ---------------------------------------------------------------------------------------------
namespace
{

struct Env
{
   enum Stage { OFF, ATT, DEC, SUS, REL };
   Stage st;
   float level;
   float a_inc, d_coef, s_level, r_coef;
   bool d_inf, r_inf;

   Env() : st(OFF), level(0), a_inc(1), d_coef(0), s_level(1), r_coef(0), d_inf(false), r_inf(false) { }

   // time_ad / time_r: facteurs de vitesse (velocite)
   void start(int a, int d, int s, int r, double time_ad, double time_r, double sr)
   {
      double ta = envTimeSeconds(a) * time_ad;
      double td = envTimeSeconds(d) * time_ad;
      double tr = envTimeSeconds(r) * time_r;
      a_inc = (float)(1.0 / (ta * sr));
      d_inf = (d >= 63);
      r_inf = (r >= 63);
      // la decroissance atteint 0,1% de l'ecart restant au bout du temps regle (60 dB)
      d_coef = (float)pow(0.001, 1.0 / (td * sr));
      r_coef = (float)pow(0.001, 1.0 / (tr * sr));
      s_level = (float)s / 255.0f;
      level = 0;
      st = ATT;
   }

   void release()
   {
      if(st != OFF)
      {
         st = REL;
      }
   }

   inline float tick()
   {
      switch(st)
      {
         case ATT:
            level += a_inc;
            if(level >= 1.0f)
            {
               level = 1.0f;
               st = DEC;
            }
            break;
         case DEC:
            if(d_inf)
            {
               level = 1.0f;
            }
            else
            {
               level = s_level + (level - s_level) * d_coef;
               if((level - s_level) < 0.0005f)
               {
                  level = s_level;
                  st = SUS;
               }
            }
            break;
         case SUS:
            level = s_level;
            break;
         case REL:
            if(!r_inf)
            {
               level *= r_coef;
               if(level < 0.00001f)
               {
                  level = 0;
                  st = OFF;
               }
            }
            break;
         default:
            level = 0;
            break;
      }
      return level;
   }
};


// ---------------------------------------------------------------------------------------------
// Voix
// ---------------------------------------------------------------------------------------------
struct Voice
{
   bool active;
   bool released;
   bool pedal_held;
   int note;
   uint64_t age;
   std::shared_ptr<const SoundData> snd;
   float gain;

   // lecture du sample
   double pos;
   int dir;
   double inc;
   bool play_done;

   // enveloppes
   Env amp, fil;
   float amp_peak, fil_peak;

   // filtre
   double base_oct_hz;     // frequence de coupure de base (Hz), suivi de clavier compris
   double env_octaves;     // amplitude du balayage de l'enveloppe (octaves, signee)
   double res_k;
   double z[4];
   double G;
   int ctrl;

   Voice() : active(false), released(false), pedal_held(false), note(0), age(0), gain(0), pos(0), dir(1), inc(1),
      play_done(false), amp_peak(1), fil_peak(1), base_oct_hz(1000), env_octaves(0), res_k(0), G(0.1), ctrl(0)
   {
      z[0] = z[1] = z[2] = z[3] = 0;
   }
};

inline float hermite(float xm1, float x0, float x1, float x2, float t)
{
   float c1 = 0.5f * (x1 - xm1);
   float c2 = xm1 - 2.5f * x0 + 2.0f * x1 - 0.5f * x2;
   float c3 = 0.5f * (x2 - xm1) + 1.5f * (x0 - x1);
   return ((c3 * t + c2) * t + c1) * t + x0;
}

inline double softLimit(double x)
{
   // limiteur doux: transparent aux faibles niveaux
   return 3.0 * tanh(x * (1.0 / 3.0));
}

// facteur de temps selon la velocite: sensibilite positive -> jouer fort raccourcit
inline double rateScale(int sens, double v01)
{
   return pow(2.0, -2.0 * ((double)sens / 127.0) * (2.0 * v01 - 1.0));
}

// echelle de crete selon la velocite
inline float peakScale(int sens, double v01)
{
   double s = (double)sens / 127.0;
   double pk;
   if(s >= 0.0)
   {
      pk = 1.0 - s * (1.0 - v01);
   }
   else
   {
      pk = 1.0 + s * v01;
   }
   if(pk < 0.0)
   {
      pk = 0.0;
   }
   if(pk > 1.0)
   {
      pk = 1.0;
   }
   return (float)pk;
}

const Zone *findZone(const std::vector<Zone> &zones, int note)
{
   int lo = 0;
   for(size_t i = 0; i < zones.size(); i++)
   {
      if((note >= lo) && (note <= zones[i].hi_key))
      {
         return &zones[i];
      }
      lo = zones[i].hi_key + 1;
   }
   return NULL;
}

struct Event
{
   enum Type { NOTE_ON, NOTE_OFF, ALL_OFF, HOLD, MODWHEEL } type;
   int a;
   int b;
   float f;
};

} // namespace


struct Engine::Impl
{
   std::mutex m;
   std::vector<Event> pending;
   std::shared_ptr<const Patch> pending_patch;
   bool has_pending_patch;
   std::vector<std::shared_ptr<const Patch> > retired;

   std::shared_ptr<const Patch> patch;
   std::vector<Voice> voices;
   uint64_t clock;
   bool hold;
   float modwheel;
   std::vector<float> mix;
   double sr;

   Impl() : has_pending_patch(false), clock(0), hold(false), modwheel(0), sr(48000) { }

   // ------------------------------------------------------------------ allocation d'une voix
   Voice *allocVoice()
   {
      Voice *best = NULL;
      for(size_t i = 0; i < voices.size(); i++)
      {
         if(!voices[i].active)
         {
            return &voices[i];
         }
      }
      // vol de voix: d'abord une voix relachee la plus faible, sinon la plus ancienne
      for(size_t i = 0; i < voices.size(); i++)
      {
         if(voices[i].released)
         {
            if(!best || (voices[i].amp.level < best->amp.level))
            {
               best = &voices[i];
            }
         }
      }
      if(!best)
      {
         for(size_t i = 0; i < voices.size(); i++)
         {
            if(!best || (voices[i].age < best->age))
            {
               best = &voices[i];
            }
         }
      }
      return best;
   }

   void startVoice(const Zone &z, int note, int vel, float gain_mul)
   {
      if(!patch || (z.sound < 0) || (z.sound > 15) || !patch->sounds[z.sound])
      {
         return;
      }
      std::shared_ptr<const SoundData> snd = patch->sounds[z.sound];
      if(snd->pcm.empty() || (snd->end <= snd->start))
      {
         return;
      }
      Voice *v = allocVoice();
      if(!v)
      {
         return;
      }
      double v01 = (double)vel / 127.0;
      if(v01 < 0.0)
      {
         v01 = 0.0;
      }
      if(v01 > 1.0)
      {
         v01 = 1.0;
      }

      *v = Voice();
      v->active = true;
      v->note = note;
      v->age = ++clock;
      v->snd = snd;
      v->gain = (float)(VOICE_GAIN * ((double)z.gain / 255.0) * gain_mul);

      // transposition: touche jouee par rapport a la touche d'origine, depuis la frequence d'origine du sample
      double semis = (double)(note - z.orig_key);
      v->inc = ((double)snd->rate_hz / sr) * pow(2.0, semis / 12.0);

      if(snd->reverse)
      {
         v->pos = (double)(snd->end - 1);
         v->dir = -1;
      }
      else
      {
         v->pos = (double)snd->start;
         v->dir = 1;
      }

      double ad = rateScale(snd->attack_vel, v01);
      double rr = rateScale(snd->release_vel, v01);
      v->amp.start(snd->amp_a, snd->amp_d, snd->amp_s, snd->amp_r, ad, rr, sr);
      v->fil.start(snd->filt_a, snd->filt_d, snd->filt_s, snd->filt_r, ad, rr, sr);
      v->amp_peak = peakScale(snd->amp_peak_vel, v01);
      v->fil_peak = peakScale(snd->filt_peak_vel, v01);

      v->base_oct_hz = cutoffHz(snd->cutoff, snd->key_track, note, 0.0f);
      v->env_octaves = ((double)snd->env_amount / 127.0) * ENV_FULL_OCTAVES;
      v->res_k = 4.0 * ((double)snd->resonance / RESONANCE_OSC_VALUE);
      v->ctrl = 0;
   }

   // ------------------------------------------------------------------ evenements
   void doNoteOn(int note, int vel)
   {
      if(!patch)
      {
         return;
      }
      const Zone *l = NULL;
      const Zone *r = NULL;
      float gl = 1.0f;
      float gr = 1.0f;
      switch(patch->mode)
      {
         case MODE_RIGHT_ONLY:
            r = findZone(patch->right, note);
            break;
         case MODE_LEFT_ONLY:
            l = findZone(patch->left, note);
            break;
         case MODE_SPLIT:
            if(note < patch->split_point)
            {
               l = findZone(patch->left, note);
            }
            else
            {
               r = findZone(patch->right, note);
            }
            break;
         case MODE_VELOCITY_SWITCH:
            if(vel < patch->velocity_threshold)
            {
               l = findZone(patch->left, note);
            }
            else
            {
               r = findZone(patch->right, note);
            }
            break;
         case MODE_VELOCITY_XFADE:
            gl = 1.0f - (float)vel / 127.0f;
            gr = (float)vel / 127.0f;
            l = findZone(patch->left, note);
            r = findZone(patch->right, note);
            break;
         case MODE_MODWHEEL_XFADE:
            gl = 1.0f - modwheel;
            gr = modwheel;
            l = findZone(patch->left, note);
            r = findZone(patch->right, note);
            break;
         case MODE_MERGE:
         case MODE_LAYER:
         case MODE_POSITIONAL_XFADE: // approximation: les deux maps sonnent
         default:
            l = findZone(patch->left, note);
            r = findZone(patch->right, note);
            break;
      }
      if(l)
      {
         startVoice(*l, note, vel, gl);
      }
      if(r)
      {
         startVoice(*r, note, vel, gr);
      }
   }

   void releaseVoice(Voice &v)
   {
      v.released = true;
      v.amp.release();
      v.fil.release();
   }

   void doNoteOff(int note)
   {
      for(size_t i = 0; i < voices.size(); i++)
      {
         Voice &v = voices[i];
         if(v.active && (v.note == note) && !v.released && !v.pedal_held)
         {
            if(hold)
            {
               v.pedal_held = true;
            }
            else
            {
               releaseVoice(v);
            }
         }
      }
   }

   void doHold(bool on)
   {
      hold = on;
      if(!on)
      {
         for(size_t i = 0; i < voices.size(); i++)
         {
            Voice &v = voices[i];
            if(v.active && v.pedal_held)
            {
               v.pedal_held = false;
               releaseVoice(v);
            }
         }
      }
   }

   void doAllOff()
   {
      for(size_t i = 0; i < voices.size(); i++)
      {
         voices[i].active = false;
      }
   }

   // ------------------------------------------------------------------ rendu d'une voix
   // retourne false quand la voix est terminee
   bool renderVoice(Voice &v, float *out, int frames)
   {
      const SoundData &s = *v.snd;
      const int n = (int)s.pcm.size();
      const float *pcm = &s.pcm[0];
      const double sr_d = sr;

      const bool sus_valid = s.sus_loop && (s.sus_end > s.sus_start + 1);
      const bool rel_valid = s.rel_loop && (s.rel_end > s.rel_start + 1);

      for(int f = 0; f < frames; f++)
      {
         // --- enveloppes
         float ea = v.amp.tick();
         float ef = v.fil.tick();

         // fin de voix: sample termine, enveloppe d'amplitude retombee a zero apres le relachement,
         // ou mode ADR (sustain OFF) une fois la decroissance terminee
         if(v.play_done || (v.amp.st == Env::OFF) || ((v.amp.st == Env::SUS) && (v.amp.s_level <= 0.0f)))
         {
            return false;
         }

         // --- boucle active
         bool loop_on = false;
         int ls = 0;
         int le = 0;
         bool bf_active = false;
         if(!s.reverse)
         {
            if(sus_valid && !v.released)
            {
               loop_on = true;
               ls = s.sus_start;
               le = s.sus_end;
            }
            else if(rel_valid && (v.released || !s.sus_loop))
            {
               loop_on = true;
               ls = s.rel_start;
               le = s.rel_end;
               bf_active = s.bf;
            }
         }

         // --- lecture (interpolation cubique, bouclage pris en compte pour les voisins)
         int ip = (int)floor(v.pos);
         float t = (float)(v.pos - (double)ip);
         float x[4];
         for(int k = 0; k < 4; k++)
         {
            int i = ip - 1 + k;
            if(loop_on)
            {
               if(bf_active)
               {
                  if(i >= le)
                  {
                     i = 2 * (le - 1) - i;
                  }
                  if(i < ls)
                  {
                     i = 2 * ls - i;
                  }
               }
               else if(i >= le)
               {
                  i = ls + ((i - le) % (le - ls));
               }
            }
            if(i < 0)
            {
               i = 0;
            }
            if(i >= n)
            {
               i = n - 1;
            }
            x[k] = pcm[i];
         }
         double in = (double)hermite(x[0], x[1], x[2], x[3], t);

         // --- avance
         v.pos += (double)v.dir * v.inc;
         if(s.reverse)
         {
            if(v.pos < (double)s.start)
            {
               v.play_done = true;
            }
         }
         else if(loop_on)
         {
            if((v.dir > 0) && (v.pos >= (double)le))
            {
               if(bf_active)
               {
                  v.dir = -1;
                  v.pos = 2.0 * (double)le - v.pos;
               }
               else
               {
                  v.pos = (double)ls + fmod(v.pos - (double)le, (double)(le - ls));
               }
            }
            else if((v.dir < 0) && (v.pos <= (double)ls))
            {
               v.dir = 1;
               v.pos = 2.0 * (double)ls - v.pos;
            }
         }
         else
         {
            if(v.dir < 0)
            {
               // sortie d'une boucle avant/arriere: on repart vers l'avant
               v.dir = 1;
            }
            if(v.pos >= (double)s.end)
            {
               v.play_done = true;
            }
         }

         // --- filtre passe-bas 4 poles (TPT / "zero delay feedback"), coefficients a cadence reduite
         if(v.ctrl == 0)
         {
            double oct = v.env_octaves * (double)(ef * v.fil_peak);
            double fc = v.base_oct_hz * pow(2.0, oct);
            if(fc > 0.45 * sr_d)
            {
               fc = 0.45 * sr_d;
            }
            if(fc < 8.0)
            {
               fc = 8.0;
            }
            double g = tan(PI_D * fc / sr_d);
            v.G = g / (1.0 + g);
         }
         v.ctrl = (v.ctrl + 1) & 7;

         const double G = v.G;
         const double G2 = G * G;
         const double G3 = G2 * G;
         const double G4 = G3 * G;
         const double a = 1.0 - G;
         const double s1 = a * v.z[0];
         const double s2 = a * v.z[1];
         const double s3 = a * v.z[2];
         const double s4 = a * v.z[3];
         const double S = G3 * s1 + G2 * s2 + G * s3 + s4;
         double u = (in - v.res_k * S) / (1.0 + v.res_k * G4);
         u = softLimit(u);
         double y = u;
         for(int k = 0; k < 4; k++)
         {
            double vv = G * (y - v.z[k]);
            double yy = vv + v.z[k];
            v.z[k] = yy + vv;
            y = yy;
         }

         out[f] += (float)(y * (double)ea * (double)v.amp_peak * (double)v.gain);
      }
      return true;
   }

   void applyPending()
   {
      std::unique_lock<std::mutex> lk(m, std::try_to_lock);
      if(!lk.owns_lock())
      {
         return;
      }
      if(has_pending_patch)
      {
         if(patch)
         {
            retired.push_back(patch);   // liberee plus tard par le fil de l'interface
         }
         patch = pending_patch;
         pending_patch.reset();
         has_pending_patch = false;
      }
      std::vector<Event> ev;
      ev.swap(pending);
      lk.unlock();
      for(size_t i = 0; i < ev.size(); i++)
      {
         switch(ev[i].type)
         {
            case Event::NOTE_ON:  doNoteOn(ev[i].a, ev[i].b); break;
            case Event::NOTE_OFF: doNoteOff(ev[i].a); break;
            case Event::ALL_OFF:  doAllOff(); break;
            case Event::HOLD:     doHold(ev[i].a != 0); break;
            case Event::MODWHEEL: modwheel = ev[i].f; break;
         }
      }
   }
};


Engine::Engine(double out_rate, int max_voices) : m_impl(new Impl), m_out_rate(out_rate), m_active_voices(0)
{
   m_impl->sr = out_rate;
   m_impl->voices.resize(max_voices);
}


Engine::~Engine()
{
   delete m_impl;
}


void Engine::setPatch(std::shared_ptr<const Patch> patch)
{
   std::lock_guard<std::mutex> lk(m_impl->m);
   m_impl->retired.clear();
   m_impl->pending_patch = patch;
   m_impl->has_pending_patch = true;
}


void Engine::noteOn(int note, int velocity)
{
   Event e;
   e.type = Event::NOTE_ON;
   e.a = note;
   e.b = velocity < 1 ? 1 : (velocity > 127 ? 127 : velocity);
   e.f = 0;
   std::lock_guard<std::mutex> lk(m_impl->m);
   m_impl->pending.push_back(e);
}


void Engine::noteOff(int note)
{
   Event e;
   e.type = Event::NOTE_OFF;
   e.a = note;
   e.b = 0;
   e.f = 0;
   std::lock_guard<std::mutex> lk(m_impl->m);
   m_impl->pending.push_back(e);
}


void Engine::allNotesOff()
{
   Event e;
   e.type = Event::ALL_OFF;
   e.a = e.b = 0;
   e.f = 0;
   std::lock_guard<std::mutex> lk(m_impl->m);
   m_impl->pending.push_back(e);
}


void Engine::setHold(bool on)
{
   Event e;
   e.type = Event::HOLD;
   e.a = on ? 1 : 0;
   e.b = 0;
   e.f = 0;
   std::lock_guard<std::mutex> lk(m_impl->m);
   m_impl->pending.push_back(e);
}


void Engine::setModWheel(float value01)
{
   Event e;
   e.type = Event::MODWHEEL;
   e.a = e.b = 0;
   e.f = value01 < 0 ? 0 : (value01 > 1 ? 1 : value01);
   std::lock_guard<std::mutex> lk(m_impl->m);
   m_impl->pending.push_back(e);
}


void Engine::render(float *left, float *right, int frames)
{
   Impl &im = *m_impl;
   im.applyPending();

   if((int)im.mix.size() < frames)
   {
      im.mix.resize(frames);
   }
   memset(&im.mix[0], 0, sizeof(float) * frames);

   int active = 0;
   for(size_t i = 0; i < im.voices.size(); i++)
   {
      Voice &v = im.voices[i];
      if(v.active)
      {
         if(!im.renderVoice(v, &im.mix[0], frames))
         {
            v.active = false;
            v.snd.reset();
         }
         else
         {
            active++;
         }
      }
   }
   m_active_voices = active;

   for(int f = 0; f < frames; f++)
   {
      float o = (float)tanh((double)im.mix[f]);   // limiteur doux de sortie
      left[f] = o;
      right[f] = o;
   }
}

} // namespace softprophet
