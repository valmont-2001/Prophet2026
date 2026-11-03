// Banc de tests du "faux Prophet" (SRCDIR/softprophet.*), sans interface ni carte son.
// Chaque test mesure le son produit (hauteur, niveaux, temps, spectre) et le compare au comportement
// decrit dans le manuel du Prophet 2000.
//
//   softprophet_test            -> lance tous les tests
//   softprophet_test --demo dir -> ecrit aussi des fichiers WAV d'ecoute dans le dossier "dir"

#include "softprophet.h"

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <complex>
#include <algorithm>

using namespace softprophet;

static const double SR = 48000.0;
static const double PI = 3.14159265358979323846;
static int g_fail = 0;
static int g_pass = 0;

static void check(bool ok, const char *name, const char *fmt, ...)
{
   char buf[400];
   va_list ap;
   va_start(ap, fmt);
   vsnprintf(buf, sizeof(buf), fmt, ap);
   va_end(ap);
   printf("[%s] %-34s %s\n", ok ? "PASS" : "FAIL", name, buf);
   if(ok) g_pass++; else g_fail++;
}

// ------------------------------------------------------------------ outils
struct Ev { double t; int type; int a; int b; };   // type 0=on 1=off 2=hold on 3=hold off 4=all off 5=modwheel(a/127)

static std::vector<float> render(Engine &e, double seconds, std::vector<Ev> evs, int *max_active = NULL)
{
   std::sort(evs.begin(), evs.end(), [](const Ev &x, const Ev &y) { return x.t < y.t; });
   const int B = 32;
   size_t total = (size_t)(seconds * SR);
   std::vector<float> out(total), l(B), r(B);
   size_t ei = 0;
   int mx = 0;
   for(size_t pos = 0; pos < total; pos += B)
   {
      double t = (double)pos / SR;
      while((ei < evs.size()) && (evs[ei].t <= t + 1e-9))
      {
         const Ev &v = evs[ei++];
         switch(v.type)
         {
            case 0: e.noteOn(v.a, v.b); break;
            case 1: e.noteOff(v.a); break;
            case 2: e.setHold(true); break;
            case 3: e.setHold(false); break;
            case 4: e.allNotesOff(); break;
            case 5: e.setModWheel(v.a / 127.0f); break;
         }
      }
      e.render(&l[0], &r[0], B);
      mx = std::max(mx, e.activeVoices());
      for(int i = 0; i < B && pos + i < total; i++) out[pos + i] = l[i];
   }
   if(max_active) *max_active = mx;
   return out;
}

static std::shared_ptr<SoundData> loopedSound(const std::vector<float> &pcm, float rate, int ls, int le)
{
   std::shared_ptr<SoundData> s(new SoundData);
   s->pcm = pcm;
   s->rate_hz = rate;
   s->start = 0;
   s->end = (int)pcm.size();
   s->sus_loop = true;
   s->sus_start = ls;
   s->sus_end = le;
   s->key_track = 0;
   return s;
}

static std::vector<float> sine(int cycles, int period, float amp = 1.0f)
{
   std::vector<float> v(cycles * period);
   for(size_t i = 0; i < v.size(); i++) v[i] = amp * (float)sin(2.0 * PI * (double)i / period);
   return v;
}

static std::shared_ptr<Patch> simplePatch(std::shared_ptr<const SoundData> s, int orig_key = 60, int gain = 255)
{
   std::shared_ptr<Patch> p(new Patch);
   p->sounds[0] = s;
   Zone z;
   z.hi_key = 127; z.sound = 0; z.orig_key = orig_key; z.gain = gain;
   p->right.push_back(z);
   p->mode = MODE_RIGHT_ONLY;
   return p;
}

static double freqByZeroCrossings(const std::vector<float> &x, double t0, double t1)
{
   size_t a = (size_t)(t0 * SR), b = std::min((size_t)(t1 * SR), x.size());
   int n = 0;
   double first = -1, last = -1;
   for(size_t i = a + 1; i < b; i++)
   {
      if((x[i - 1] < 0) && (x[i] >= 0))
      {
         double frac = -x[i - 1] / (x[i] - x[i - 1]);
         double pos = (double)(i - 1) + frac;
         if(first < 0) first = pos;
         last = pos;
         n++;
      }
   }
   if(n < 3) return 0;
   return (double)(n - 1) * SR / (last - first);
}

static double rms(const std::vector<float> &x, double t0, double t1)
{
   size_t a = (size_t)(t0 * SR), b = std::min((size_t)(t1 * SR), x.size());
   double s = 0;
   for(size_t i = a; i < b; i++) s += (double)x[i] * x[i];
   return b > a ? sqrt(s / (double)(b - a)) : 0;
}

static double peakAbs(const std::vector<float> &x, double t0, double t1)
{
   size_t a = (size_t)(t0 * SR), b = std::min((size_t)(t1 * SR), x.size());
   double m = 0;
   for(size_t i = a; i < b; i++) m = std::max(m, (double)fabs(x[i]));
   return m;
}

// le limiteur de sortie est tanh(): on le retire pour mesurer des niveaux
static double lin(double y) { return atanh(std::max(-0.999999, std::min(0.999999, y))); }

typedef std::complex<double> cd;
static void fft(std::vector<cd> &a)
{
   size_t n = a.size();
   for(size_t i = 1, j = 0; i < n; i++)
   {
      size_t bit = n >> 1;
      for(; j & bit; bit >>= 1) j ^= bit;
      j ^= bit;
      if(i < j) std::swap(a[i], a[j]);
   }
   for(size_t len = 2; len <= n; len <<= 1)
   {
      double ang = -2 * PI / (double)len;
      cd wl(cos(ang), sin(ang));
      for(size_t i = 0; i < n; i += len)
      {
         cd w(1);
         for(size_t j = 0; j < len / 2; j++)
         {
            cd u = a[i + j], v = a[i + j + len / 2] * w;
            a[i + j] = u + v;
            a[i + j + len / 2] = u - v;
            w *= wl;
         }
      }
   }
}

// densite spectrale (Welch), N=4096
static std::vector<double> psd(const std::vector<float> &x, double t0, double t1)
{
   const size_t N = 4096;
   size_t a = (size_t)(t0 * SR), b = std::min((size_t)(t1 * SR), x.size());
   std::vector<double> p(N / 2, 0.0);
   int cnt = 0;
   for(size_t s = a; s + N <= b; s += N / 2)
   {
      std::vector<cd> buf(N);
      for(size_t i = 0; i < N; i++) buf[i] = (double)lin(x[s + i]) * (0.5 - 0.5 * cos(2 * PI * (double)i / (double)N));
      fft(buf);
      for(size_t k = 0; k < N / 2; k++) p[k] += std::norm(buf[k]);
      cnt++;
   }
   for(size_t k = 0; k < p.size(); k++) p[k] /= std::max(1, cnt);
   return p;
}

// gain (amplitude) moyenne dans une bande [f0,f1]
static double bandGain(const std::vector<double> &p, const std::vector<double> &ref, double f0, double f1)
{
   const double N = 4096;
   size_t k0 = (size_t)(f0 * N / SR), k1 = (size_t)(f1 * N / SR);
   double a = 0, b = 0;
   for(size_t k = k0; k <= k1 && k < p.size(); k++) { a += p[k]; b += ref[k]; }
   return sqrt(a / std::max(b, 1e-30));
}

// 4 poles identiques en serie: le point a -3 dB est a 0,435 x la frequence reglee (frequence de resonance)
static double minus3dB(double fc) { return fc * sqrt(pow(2.0, 0.25) - 1.0); }

static double db(double g) { return 20.0 * log10(std::max(g, 1e-12)); }

// -3 dB par rapport au gain en bande passante basse (100-200 Hz)
static double findMinus3dB(const std::vector<double> &p, const std::vector<double> &ref)
{
   double pb = bandGain(p, ref, 60, 120);
   for(double f = 250; f < 20000; f *= 1.03)
   {
      if(bandGain(p, ref, f / 1.06, f * 1.06) < pb * 0.7071) return f;
   }
   return 0;
}

static std::vector<float> noise(size_t n, float amp)
{
   std::vector<float> v(n);
   unsigned int s = 12345;
   for(size_t i = 0; i < n; i++)
   {
      s = s * 1664525u + 1013904223u;
      v[i] = amp * ((float)(s >> 8) / (float)(1 << 24) * 2.0f - 1.0f);
   }
   return v;
}

static std::shared_ptr<SoundData> constSound(float v, size_t n = 4096)
{
   std::vector<float> pcm(n, v);
   std::shared_ptr<SoundData> s = loopedSound(pcm, 31250.0f, 0, (int)n);
   s->rel_loop = true;            // sinon, apres le relachement, la lecture file jusqu'a la fin du sample
   s->rel_start = 0;
   s->rel_end = (int)n;
   s->cutoff = 127;
   return s;
}

// ------------------------------------------------------------------ tests
static void testPitch()
{
   const double f0 = 31250.0 / 64.0;
   std::shared_ptr<SoundData> s = loopedSound(sine(40, 64), 31250.0f, 64 * 4, 64 * 36);
   for(int note : {48, 60, 67, 72, 84})
   {
      Engine e(SR);
      e.setPatch(simplePatch(s, 60));
      std::vector<float> o = render(e, 0.8, { { 0.0, 0, note, 100 } });
      double f = freqByZeroCrossings(o, 0.1, 0.7);
      double exp_f = f0 * pow(2.0, (note - 60) / 12.0);
      check(fabs(f / exp_f - 1.0) < 0.003, "pitch (31,25 kHz)", "note %d: %.2f Hz, attendu %.2f Hz", note, f, exp_f);
   }
   // les trois frequences d'echantillonnage du Prophet: meme note, hauteurs differentes
   for(float rate : {15625.0f, 31250.0f, 41667.0f})
   {
      std::shared_ptr<SoundData> s2 = loopedSound(sine(40, 64), rate, 64 * 4, 64 * 36);
      Engine e(SR);
      e.setPatch(simplePatch(s2, 60));
      std::vector<float> o = render(e, 0.8, { { 0.0, 0, 60, 100 } });
      double f = freqByZeroCrossings(o, 0.1, 0.7);
      check(fabs(f / (rate / 64.0) - 1.0) < 0.003, "pitch selon la frequence du sample", "%.0f Hz -> %.2f Hz (attendu %.2f)", rate, f, rate / 64.0);
   }
   // touche d'origine decalee par la transposition de map
   Engine e(SR);
   e.setPatch(simplePatch(s, 48));
   std::vector<float> o = render(e, 0.8, { { 0.0, 0, 48, 100 } });
   double f = freqByZeroCrossings(o, 0.1, 0.7);
   check(fabs(f / f0 - 1.0) < 0.003, "touche d'origine", "orig_key=48 jouee a 48: %.2f Hz (attendu %.2f)", f, f0);
}

static void testSustainLoop()
{
   std::vector<float> pcm = sine(40, 64, 0.6f);   // 2560 mots = 82 ms a 31,25 kHz
   {
      std::shared_ptr<SoundData> s = loopedSound(pcm, 31250.0f, 64 * 4, 64 * 36);
      s->sus_loop = false;
      Engine e(SR);
      e.setPatch(simplePatch(s));
      std::vector<float> o = render(e, 1.5, { { 0.0, 0, 60, 100 } });
      double early = rms(o, 0.02, 0.06), late = rms(o, 1.0, 1.4);
      check(early > 0.05 && late < 1e-4, "sans boucle: silence", "rms debut %.3f, apres 1 s %.6f", early, late);
   }
   {
      std::shared_ptr<SoundData> s = loopedSound(pcm, 31250.0f, 64 * 4, 64 * 36);
      Engine e(SR);
      e.setPatch(simplePatch(s));
      std::vector<float> o = render(e, 3.0, { { 0.0, 0, 60, 100 } });
      double early = rms(o, 0.02, 0.06), late = rms(o, 2.0, 2.4);
      check(fabs(late / early - 1.0) < 0.05, "boucle de sustain", "rms debut %.3f, apres 2 s %.3f (maintenu)", early, late);
   }
}

static void testReleaseLoop()
{
   // zone A (amplitude 1) puis zone B (amplitude 0,25): sustain dans A, release dans B
   std::vector<float> pcm = sine(20, 64, 1.0f);
   std::vector<float> b = sine(20, 64, 0.25f);
   pcm.insert(pcm.end(), b.begin(), b.end());       // 2560 mots
   std::shared_ptr<SoundData> s = loopedSound(pcm, 31250.0f, 320, 960);
   s->rel_loop = true;
   s->rel_start = 1600;
   s->rel_end = 2240;
   s->amp_r = 45;                                   // release long (~5 s)
   Engine e(SR);
   e.setPatch(simplePatch(s));
   std::vector<float> o = render(e, 2.0, { { 0.0, 0, 60, 127 }, { 0.5, 1, 60, 0 } });
   double held = peakAbs(o, 0.3, 0.45);
   double rel_env = pow(0.001, 0.3 / envTimeSeconds(45));      // niveau d'enveloppe 0,3 s apres le relachement
   double after = peakAbs(o, 0.80, 0.85);
   double exp_after = lin(held) * 0.25 * pow(0.001, 0.32 / envTimeSeconds(45));
   check(held > 0.2, "boucle sustain tenue", "amplitude %.3f pendant la tenue", held);
   check(fabs(lin(after) / exp_after - 1.0) < 0.12, "release loop apres relachement",
         "amplitude %.4f, attendu ~%.4f (zone B x enveloppe %.2f)", lin(after), exp_after, rel_env);

   // sans boucle de release: apres le relachement la lecture va jusqu'a la fin du sample, puis silence
   s = loopedSound(pcm, 31250.0f, 320, 960);
   s->amp_r = 45;
   Engine e2(SR);
   e2.setPatch(simplePatch(s));
   o = render(e2, 2.0, { { 0.0, 0, 60, 127 }, { 0.5, 1, 60, 0 } });
   check(peakAbs(o, 1.0, 1.5) < 1e-4, "sans release loop: fin du sample", "silence apres la fin (%.6f)", peakAbs(o, 1.0, 1.5));

   // release loop seule (pas de sustain loop): elle boucle aussi pendant la tenue
   s = loopedSound(pcm, 31250.0f, 320, 960);
   s->sus_loop = false;
   s->rel_loop = true; s->rel_start = 1600; s->rel_end = 2240;
   Engine e3(SR);
   e3.setPatch(simplePatch(s));
   o = render(e3, 1.5, { { 0.0, 0, 60, 127 } });
   double lvl = peakAbs(o, 1.0, 1.2);
   check(lvl > 0.05 && fabs(lin(lvl) / (0.25 * 0.5) - 1.0) < 0.1, "release loop seule = boucle", "amplitude %.3f maintenue apres 1 s", lvl);
}

static void testBackForth()
{
   // rampe 0..1: en avant -> dent de scie (saut), arriere/avant -> triangle (continu)
   std::vector<float> ramp(256);
   for(int i = 0; i < 256; i++) ramp[i] = (float)i / 255.0f * 0.5f;
   double mx[2];
   for(int bf = 0; bf < 2; bf++)
   {
      std::shared_ptr<SoundData> s = loopedSound(ramp, 31250.0f, 0, 0);
      s->sus_loop = false;
      s->rel_loop = true; s->rel_start = 0; s->rel_end = 256;
      s->bf = (bf == 1);
      Engine e(SR);
      e.setPatch(simplePatch(s));
      std::vector<float> o = render(e, 0.6, { { 0.0, 0, 60, 127 } });
      double m = 0;
      for(size_t i = (size_t)(0.2 * SR); i < (size_t)(0.5 * SR); i++) m = std::max(m, (double)fabs(o[i] - o[i - 1]));
      mx[bf] = m;
   }
   check(mx[0] > 5.0 * mx[1], "boucle avant/arriere (bF)", "saut max: avant %.4f, avant/arriere %.4f", mx[0], mx[1]);
}

static void testReverse()
{
   std::vector<float> ramp(2000);
   for(int i = 0; i < 2000; i++) ramp[i] = (float)i / 2000.0f * 0.8f;
   std::shared_ptr<SoundData> s = loopedSound(ramp, 31250.0f, 0, 0);
   s->sus_loop = false;
   s->reverse = true;
   s->cutoff = 127;
   Engine e(SR);
   e.setPatch(simplePatch(s));
   std::vector<float> o = render(e, 0.06, { { 0.0, 0, 60, 127 } });
   double a = fabs(o[(size_t)(0.004 * SR)]), b = fabs(o[(size_t)(0.04 * SR)]);
   check(a > 2.0 * b, "lecture a l'envers", "niveau au debut %.3f > niveau plus tard %.3f", a, b);
}

// mesure du niveau d'enveloppe: sample constant, filtre ouvert
static std::vector<float> envCurve(std::shared_ptr<SoundData> s, double secs, std::vector<Ev> evs, int *active = NULL)
{
   Engine e(SR);
   e.setPatch(simplePatch(s));
   std::vector<float> o = render(e, secs, evs, active);
   const double unit = 0.2 * 0.5;           // niveau du sample x gain de voix
   for(size_t i = 0; i < o.size(); i++) o[i] = (float)(lin(o[i]) / unit);
   return o;
}
static double at(const std::vector<float> &c, double t) { return c[(size_t)(t * SR)]; }

static void testEnvelopes()
{
   // attaque (lineaire): a mi-parcours le niveau vaut 0,5
   {
      std::shared_ptr<SoundData> s = constSound(0.2f);
      s->amp_a = 40;
      double T = envTimeSeconds(40);
      std::vector<float> c = envCurve(s, T + 0.5, { { 0.0, 0, 60, 127 } });
      check(fabs(at(c, T / 2) - 0.5) < 0.03 && fabs(at(c, T * 1.02) - 1.0) < 0.03, "attaque ADSR",
            "attaque %.2f s: niveau a mi-temps %.3f (0,5), au sommet %.3f", T, at(c, T / 2), at(c, T * 1.02));
   }
   // decay vers le niveau de sustain, puis maintien
   {
      std::shared_ptr<SoundData> s = constSound(0.2f);
      s->amp_a = 0; s->amp_d = 30; s->amp_s = 128;
      double D = envTimeSeconds(30), sus = 128.0 / 255.0;
      std::vector<float> c = envCurve(s, D + 2.0, { { 0.0, 0, 60, 127 } });
      double exp_half = sus + (1.0 - sus) * pow(0.001, 0.5);
      check(fabs(at(c, D / 2 + 0.0015) - exp_half) < 0.03, "decay ADSR", "a mi-decay %.3f (attendu %.3f)", at(c, D / 2 + 0.0015), exp_half);
      check(fabs(at(c, D + 1.5) - sus) < 0.01, "niveau de sustain", "%.3f (attendu %.3f)", at(c, D + 1.5), sus);
   }
   // release: apres le relachement le niveau retombe de 60 dB au bout du temps regle
   {
      std::shared_ptr<SoundData> s = constSound(0.2f);
      s->amp_s = 255; s->amp_r = 30;
      double R = envTimeSeconds(30);
      std::vector<float> c = envCurve(s, 1.0 + R * 1.2, { { 0.0, 0, 60, 127 }, { 1.0, 1, 60, 0 } });
      check(fabs(at(c, 1.0 + R / 2) - pow(0.001, 0.5)) < 0.01 && at(c, 1.0 + R * 1.1) < 0.002, "release ADSR",
            "a mi-release %.4f (attendu %.4f), apres %.5f", at(c, 1.0 + R / 2), pow(0.001, 0.5), at(c, 1.0 + R * 1.1));
   }
   // decay infini: le niveau reste au sommet, sustain ignore
   {
      std::shared_ptr<SoundData> s = constSound(0.2f);
      s->amp_d = 63; s->amp_s = 60;
      std::vector<float> c = envCurve(s, 3.0, { { 0.0, 0, 60, 127 } });
      check(fabs(at(c, 2.5) - 1.0) < 0.02, "decay infini", "niveau %.3f apres 2,5 s (reste au sommet)", at(c, 2.5));
   }
   // release infini: la note continue apres le relachement
   {
      std::shared_ptr<SoundData> s = constSound(0.2f);
      s->amp_d = 10; s->amp_s = 200; s->amp_r = 63;
      std::vector<float> c = envCurve(s, 3.0, { { 0.0, 0, 60, 127 }, { 0.5, 1, 60, 0 } });
      check(fabs(at(c, 2.5) - 200.0 / 255.0) < 0.02, "release infini (drone)", "niveau %.3f apres le relachement", at(c, 2.5));
   }
   // sustain OFF (mode ADR): la voix se libere une fois le decay termine
   {
      std::shared_ptr<SoundData> s = constSound(0.2f);
      s->amp_d = 20; s->amp_s = 0;
      Engine e(SR);
      e.setPatch(simplePatch(s));
      render(e, envTimeSeconds(20) * 1.5 + 0.2, { { 0.0, 0, 60, 127 } });
      check(e.activeVoices() == 0, "sustain OFF (ADR)", "voix actives apres le decay: %d", e.activeVoices());
   }
}

static void testVelocity()
{
   std::shared_ptr<SoundData> s = constSound(0.2f);
   s->amp_peak_vel = 127;
   std::vector<float> c127 = envCurve(s, 0.2, { { 0.0, 0, 60, 127 } });
   std::vector<float> c64 = envCurve(s, 0.2, { { 0.0, 0, 60, 64 } });
   check(fabs(at(c127, 0.1) - 1.0) < 0.02 && fabs(at(c64, 0.1) - (1.0 - (1.0 - 64.0 / 127.0))) < 0.02, "vitesse -> crete (positive)",
         "vel 127: %.3f, vel 64: %.3f (attendu ~0,50)", at(c127, 0.1), at(c64, 0.1));
   s = constSound(0.2f);
   s->amp_peak_vel = -127;
   std::vector<float> n127 = envCurve(s, 0.2, { { 0.0, 0, 60, 127 } });
   std::vector<float> n32 = envCurve(s, 0.2, { { 0.0, 0, 60, 32 } });
   check(at(n127, 0.1) < 0.02 && at(n32, 0.1) > 0.6, "vitesse -> crete (negative)", "vel 127: %.3f, vel 32: %.3f", at(n127, 0.1), at(n32, 0.1));

   // vitesse d'attaque: sensibilite positive, jouer fort raccourcit l'attaque
   s = constSound(0.2f);
   s->amp_a = 40; s->attack_vel = 127;
   std::vector<float> fast = envCurve(s, 3.0, { { 0.0, 0, 60, 127 } });
   std::vector<float> slow = envCurve(s, 3.0, { { 0.0, 0, 60, 20 } });
   double T = envTimeSeconds(40);
   check(at(fast, T * 0.25 * 0.5) > 0.45 && at(slow, T * 0.5) < 0.2, "vitesse -> vitesse d'attaque",
         "fort: %.2f a T/8, doux: %.2f a T/2", at(fast, T * 0.125), at(slow, T * 0.5));
}

static void testFilter()
{
   std::vector<float> nz = noise(65536, 0.2f);
   // reference: filtre ouvert
   std::shared_ptr<SoundData> ref = loopedSound(nz, 31250.0f, 0, (int)nz.size());
   ref->cutoff = 127; ref->key_track = 0;
   Engine er(SR);
   er.setPatch(simplePatch(ref));
   std::vector<double> pref = psd(render(er, 3.2, { { 0.0, 0, 60, 127 } }), 0.2, 3.1);

   const int cutoffs[] = { 70, 80, 90 };
   for(int c : cutoffs)
   {
      std::shared_ptr<SoundData> s = loopedSound(nz, 31250.0f, 0, (int)nz.size());
      s->cutoff = c; s->key_track = 0;
      Engine e(SR);
      e.setPatch(simplePatch(s));
      std::vector<double> p = psd(render(e, 3.2, { { 0.0, 0, 60, 127 } }), 0.2, 3.1);
      double fcs = cutoffHz(c, 0, 60, 0);
      double expect = minus3dB(fcs);
      double got = findMinus3dB(p, pref);
      check(fabs(got / expect - 1.0) < 0.12, "frequence de coupure", "cutoff %d (%.0f Hz): -3 dB a %.0f Hz (attendu %.0f Hz = 0,435 x coupure)", c, fcs, got, expect);
      if(c == 70)
      {
         double g3 = db(bandGain(p, pref, fcs * 2.8, fcs * 3.2));
         double g6 = db(bandGain(p, pref, fcs * 5.6, fcs * 6.4));
         check(fabs((g3 - g6) - 24.0) < 3.0, "pente du filtre (4 poles)", "%.1f dB entre 3x et 6x la coupure (24 dB/oct)", g3 - g6);
      }
   }

   // resonance: bosse a la coupure
   {
      std::shared_ptr<SoundData> s = loopedSound(nz, 31250.0f, 0, (int)nz.size());
      s->cutoff = 70; s->key_track = 0; s->resonance = 60;
      Engine e(SR);
      e.setPatch(simplePatch(s));
      std::vector<double> p = psd(render(e, 3.2, { { 0.0, 0, 60, 127 } }), 0.2, 3.1);
      double fc = cutoffHz(70, 0, 60, 0);
      double peak = db(bandGain(p, pref, fc * 0.93, fc * 1.07)) - db(bandGain(p, pref, 60, 120));
      double k = 4.0 * 60.0 / 90.0;
      check(fabs(peak - 20.0 * log10(1.0 / (1.0 - k / 4.0))) < 3.5, "resonance: bosse a la coupure", "%.1f dB (theorie %.1f dB)", peak, 20.0 * log10(1.0 / (1.0 - k / 4.0)));
   }

   // auto-oscillation: impulsion unique, resonance maximale -> sinus a la frequence de coupure
   for(int res : {127, 60})
   {
      std::vector<float> imp(4096, 0.0f);
      imp[10] = 0.5f;
      std::shared_ptr<SoundData> s = loopedSound(imp, 31250.0f, 100, 4000);
      s->cutoff = 70; s->key_track = 0; s->resonance = res;
      Engine e(SR);
      e.setPatch(simplePatch(s));
      std::vector<float> o = render(e, 1.6, { { 0.0, 0, 60, 127 } });
      double fc = cutoffHz(70, 0, 60, 0);
      if(res == 127)
      {
         double f = freqByZeroCrossings(o, 0.5, 0.8);
         double r1 = rms(o, 0.5, 0.6), r2 = rms(o, 1.4, 1.5);
         check(fabs(f / fc - 1.0) < 0.04 && r2 > 0.01 && fabs(r2 / r1 - 1.0) < 0.3, "auto-oscillation (res 127)",
               "sinus a %.0f Hz (coupure %.0f Hz), niveau stable %.3f -> %.3f", f, fc, r1, r2);
      }
      else
      {
         double r1 = rms(o, 0.02, 0.06), r2 = rms(o, 1.4, 1.5);
         check(r2 < 0.05 * r1, "pas d'oscillation (res 60)", "niveau %.4f -> %.6f", r1, r2);
      }
   }

   // suivi de clavier: 1:1 -> la coupure double a l'octave
   {
      double fcs[2];
      int notes[2] = { 60, 72 };
      for(int i = 0; i < 2; i++)
      {
         std::shared_ptr<SoundData> s = loopedSound(nz, 31250.0f, 0, (int)nz.size());
         s->cutoff = 75; s->key_track = 63;
         Engine e(SR);
         e.setPatch(simplePatch(s, 60));
         std::vector<double> p = psd(render(e, 3.2, { { 0.0, 0, notes[i], 127 } }), 0.2, 3.1);
         Engine e2(SR);
         std::shared_ptr<SoundData> r = loopedSound(nz, 31250.0f, 0, (int)nz.size());
         r->cutoff = 127; r->key_track = 0;
         e2.setPatch(simplePatch(r, 60));
         std::vector<double> pr = psd(render(e2, 3.2, { { 0.0, 0, notes[i], 127 } }), 0.2, 3.1);
         fcs[i] = findMinus3dB(p, pr);
      }
      check(fabs(fcs[1] / fcs[0] - 2.0) < 0.25, "suivi de clavier 1:1", "coupure %.0f Hz (do 60) -> %.0f Hz (do 72): rapport %.2f", fcs[0], fcs[1], fcs[1] / fcs[0]);
   }

   // quantite d'enveloppe de filtre: balayage de haut en bas
   {
      std::shared_ptr<SoundData> s = loopedSound(nz, 31250.0f, 0, (int)nz.size());
      s->cutoff = 40; s->key_track = 0; s->env_amount = 127;
      s->filt_a = 0; s->filt_d = 38; s->filt_s = 0;
      Engine e(SR);
      e.setPatch(simplePatch(s));
      std::vector<float> o = render(e, 3.0, { { 0.0, 0, 60, 127 } });
      // centre de gravite spectral
      auto centroid = [&](double t0, double t1)
      {
         std::vector<double> p = psd(o, t0, t1);
         double num = 0, den = 0;
         for(size_t k = 1; k < p.size(); k++) { double f = (double)k * SR / 4096.0; num += f * p[k]; den += p[k]; }
         return num / std::max(den, 1e-30);
      };
      double c1 = centroid(0.01, 0.18), c2 = centroid(2.5, 2.95);
      check(c1 > 3.0 * c2 && c2 < 800.0, "enveloppe de filtre positive", "centre spectral %.0f Hz au debut -> %.0f Hz a la fin", c1, c2);
   }
}

static void testMapsAndModes()
{
   std::shared_ptr<Patch> p(new Patch);
   std::shared_ptr<SoundData> s0 = loopedSound(sine(40, 64), 31250.0f, 256, 2304);     // 488,28 Hz a la touche d'origine
   std::shared_ptr<SoundData> s1 = loopedSound(sine(80, 32), 31250.0f, 128, 2432);     // 976,56 Hz
   p->sounds[0] = s0; p->sounds[1] = s1;
   Zone l1 = { 59, 0, 48, 255 }, l2 = { 127, 0, 72, 255 };
   Zone r1 = { 59, 1, 48, 255 }, r2 = { 127, 1, 60, 255 };
   p->left.push_back(l1); p->left.push_back(l2);
   p->right.push_back(r1); p->right.push_back(r2);
   const double fa = 31250.0 / 64.0, fb = 31250.0 / 32.0;

   struct Case { int mode; int note; int vel; double expect; const char *label; };
   Case cases[] = {
      { MODE_LEFT_ONLY, 48, 100, fa, "left only" },
      { MODE_RIGHT_ONLY, 48, 100, fb, "right only" },
      { MODE_SPLIT, 48, 100, fa, "split (sous le point)" },
      { MODE_SPLIT, 72, 100, fb * pow(2.0, 12.0 / 12.0), "split (au-dessus)" },
      { MODE_VELOCITY_SWITCH, 60, 30, fa * pow(2.0, 12.0 / 12.0) * 1.0, "velocity switch (doux -> gauche)" },
      { MODE_VELOCITY_SWITCH, 60, 100, fb, "velocity switch (fort -> droite)" },
   };
   for(const Case &c : cases)
   {
      p->mode = c.mode; p->split_point = 60; p->velocity_threshold = 64;
      Engine e(SR);
      e.setPatch(p);
      std::vector<float> o = render(e, 0.8, { { 0.0, 0, c.note, c.vel } });
      double f = freqByZeroCrossings(o, 0.15, 0.7);
      // zone gauche haute: son 0, touche d'origine 72 -> note 60 donne une octave plus bas
      double exp_f = c.expect;
      if(c.mode == MODE_VELOCITY_SWITCH && c.vel == 30) exp_f = fa * pow(2.0, (60 - 72) / 12.0);
      if(c.mode == MODE_SPLIT && c.note == 72) exp_f = fb * pow(2.0, (72 - 60) / 12.0);
      check(fabs(f / exp_f - 1.0) < 0.01, "mode clavier", "%-34s %.1f Hz (attendu %.1f Hz)", c.label, f, exp_f);
   }
   // layer: les deux sons sonnent ensemble -> deux pics spectraux
   p->mode = MODE_LAYER;
   Engine e(SR);
   e.setPatch(p);
   std::vector<float> o = render(e, 1.2, { { 0.0, 0, 48, 100 } });
   std::vector<double> ps = psd(o, 0.2, 1.1);
   const double N = 4096;
   auto bin = [&](double f) { size_t k = (size_t)(f * N / SR + 0.5); double m = 0; for(size_t j = k - 2; j <= k + 2; j++) m = std::max(m, ps[j]); return m; };
   double pa = bin(fa), pb = bin(fb), floor_ = bin(3000.0);
   check(pa > 100 * floor_ && pb > 100 * floor_, "mode layer", "pics a %.0f Hz et %.0f Hz presents", fa, fb);
}

static void testVoices()
{
   std::shared_ptr<SoundData> s = loopedSound(sine(40, 64), 31250.0f, 256, 2304);
   Engine e(SR, 8);
   e.setPatch(simplePatch(s));
   std::vector<Ev> evs;
   for(int i = 0; i < 12; i++) evs.push_back({ 0.01 * i, 0, 48 + i, 100 });
   int mx = 0;
   std::vector<float> o = render(e, 0.3, evs, &mx);
   check(mx == 8 && peakAbs(o, 0.1, 0.3) > 0.01, "polyphonie + vol de voix", "max %d voix (limite 8), le son continue", mx);

   // pedale de maintien
   s = loopedSound(sine(40, 64), 31250.0f, 256, 2304);
   s->amp_r = 20;
   Engine e2(SR);
   e2.setPatch(simplePatch(s));
   o = render(e2, 1.2, { { 0.0, 2, 0, 0 }, { 0.0, 0, 60, 100 }, { 0.2, 1, 60, 0 }, { 0.7, 3, 0, 0 } });
   double held = rms(o, 0.5, 0.65), freed = rms(o, 1.05, 1.15);
   check(held > 0.05 && freed < 0.2 * held, "pedale de maintien", "tenu %.3f pendant la pedale, %.4f apres son relachement", held, freed);
}

// ------------------------------------------------------------------ fichiers WAV d'ecoute
static void writeWav(const std::string &path, const std::vector<float> &x)
{
   FILE *f = fopen(path.c_str(), "wb");
   if(!f) return;
   uint32_t n = (uint32_t)x.size(), sr = (uint32_t)SR, bytes = n * 2, riff = 36 + bytes, fmtlen = 16, byterate = sr * 2;
   uint16_t fmt = 1, ch = 1, align = 2, bits = 16;
   fwrite("RIFF", 1, 4, f); fwrite(&riff, 4, 1, f); fwrite("WAVEfmt ", 1, 8, f);
   fwrite(&fmtlen, 4, 1, f); fwrite(&fmt, 2, 1, f); fwrite(&ch, 2, 1, f); fwrite(&sr, 4, 1, f);
   fwrite(&byterate, 4, 1, f); fwrite(&align, 2, 1, f); fwrite(&bits, 2, 1, f);
   fwrite("data", 1, 4, f); fwrite(&bytes, 4, 1, f);
   float peak = 1e-6f;
   for(size_t i = 0; i < x.size(); i++) peak = std::max(peak, (float)fabs(x[i]));
   const float norm = 0.7f / peak;      // normalise a -3 dBFS pour l'ecoute
   for(size_t i = 0; i < x.size(); i++)
   {
      int16_t v = (int16_t)std::max(-32767.0f, std::min(32767.0f, x[i] * 32767.0f * norm));
      fwrite(&v, 2, 1, f);
   }
   fclose(f);
}

// son "cordes" synthetique: dent de scie douce, attaque + decroissance, boucle de sustain, queue de release
static std::shared_ptr<SoundData> demoString()
{
   const int period = 64, cycles = 120;
   std::vector<float> pcm(period * cycles);
   for(int i = 0; i < (int)pcm.size(); i++)
   {
      double ph = (double)(i % period) / period;
      double saw = 0, tri = 0;
      for(int h = 1; h <= 14; h++) saw += sin(2 * PI * h * ph) / h;
      tri = saw * 0.6 + 0.3 * sin(2 * PI * ph);
      double c = (double)i / (period * 12.0);
      double env = c < 1.0 ? (0.4 + 0.6 * c) * (1.0 + 0.5 * exp(-c * 6.0)) : 1.0;
      if(i > period * (cycles - 30)) env *= 1.0 - 0.7 * (double)(i - period * (cycles - 30)) / (period * 30.0);
      pcm[i] = (float)(0.7 * env * tri / 1.2);
   }
   std::shared_ptr<SoundData> s = loopedSound(pcm, 31250.0f, period * 40, period * 60);
   s->rel_loop = true; s->rel_start = period * 95; s->rel_end = period * 115;
   s->amp_a = 12; s->amp_d = 63; s->amp_s = 255; s->amp_r = 28;
   s->cutoff = 78; s->resonance = 30; s->key_track = 63;
   s->filt_a = 8; s->filt_d = 30; s->filt_s = 90; s->filt_r = 25; s->env_amount = 70;
   s->amp_peak_vel = 60; s->filt_peak_vel = 90;
   return s;
}

static void demos(const std::string &dir)
{
   // 1) gamme: meme sample transpose sur plus d'une octave
   {
      Engine e(SR);
      e.setPatch(simplePatch(demoString(), 60));
      std::vector<Ev> ev;
      int scale[] = { 48, 52, 55, 60, 64, 67, 72 };
      for(int i = 0; i < 7; i++) { ev.push_back({ 0.5 * i, 0, scale[i], 100 }); ev.push_back({ 0.5 * i + 0.45, 1, scale[i], 0 }); }
      writeWav(dir + "/1_gamme_transposition.wav", render(e, 4.5, ev));
   }
   // 2) accord tenu puis relache: boucle de sustain, puis boucle de release
   {
      Engine e(SR);
      e.setPatch(simplePatch(demoString(), 60));
      std::vector<Ev> ev = { { 0.1, 0, 48, 110 }, { 0.1, 0, 55, 110 }, { 0.1, 0, 60, 110 }, { 0.1, 0, 64, 110 },
                             { 3.0, 1, 48, 0 }, { 3.0, 1, 55, 0 }, { 3.0, 1, 60, 0 }, { 3.0, 1, 64, 0 } };
      writeWav(dir + "/2_accord_boucle_et_release.wav", render(e, 7.0, ev));
   }
   // 3) balayage de filtre avec resonance, du doux au fort
   {
      std::shared_ptr<SoundData> s = demoString();
      s->cutoff = 45; s->resonance = 75; s->env_amount = 110; s->filt_a = 0; s->filt_d = 34; s->filt_s = 40; s->key_track = 40;
      Engine e(SR);
      e.setPatch(simplePatch(s, 60));
      std::vector<Ev> ev = { { 0.1, 0, 48, 120 }, { 1.4, 1, 48, 0 }, { 1.8, 0, 55, 70 }, { 3.1, 1, 55, 0 }, { 3.5, 0, 60, 127 }, { 4.8, 1, 60, 0 } };
      writeWav(dir + "/3_filtre_enveloppe_resonance.wav", render(e, 7.0, ev));
   }
   printf("WAV d'ecoute ecrits dans %s\n", dir.c_str());
}

int main(int argc, char **argv)
{
   testPitch();
   testSustainLoop();
   testReleaseLoop();
   testBackForth();
   testReverse();
   testEnvelopes();
   testVelocity();
   testFilter();
   testMapsAndModes();
   testVoices();
   for(int i = 1; i + 1 < argc; i++)
   {
      if(!strcmp(argv[i], "--demo")) demos(argv[i + 1]);
   }
   printf("\n%d tests reussis, %d echoues\n", g_pass, g_fail);
   return g_fail ? 1 : 0;
}
