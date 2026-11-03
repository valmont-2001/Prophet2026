#include "types.h"

#include <wx/wx.h>
#include <list>
#include <map>
#include <algorithm>
using namespace std;
#include "stopwatch.h"
#include "proph2000.h"
#include "softprophet_adapter.h"

using namespace softprophet;

namespace
{

struct MapEntry
{
   int hi_key;
   int transpose;
   int mix;
};

// zone d'un son pour la map n (0..7)
template<class V> MapEntry entryOf(const V &v, int n)
{
   MapEntry e = { 0, SOUND_NOT_MAPPED_VALUE, 255 };
   switch(n)
   {
#define ENTRY(k) case (k - 1): e.hi_key = v.hi_key_map##k; e.transpose = (int8_t)v.transpose_map##k; e.mix = v.relative_mix_map##k; break;
      ENTRY(1) ENTRY(2) ENTRY(3) ENTRY(4) ENTRY(5) ENTRY(6) ENTRY(7) ENTRY(8)
#undef ENTRY
      default: break;
   }
   return e;
}

int clampi(int v, int lo, int hi)
{
   return v < lo ? lo : (v > hi ? hi : v);
}

// zones d'une map du preset: map "side" (0: sons 1-8, 1: sons 9-16), numero 0..7
vector<Zone> zonesOfMap(Proph2000 *p, int side, int number, bool used[16])
{
   vector<Zone> zones;
   const int first = side ? 8 : 0;
   for(int i = first; i < first + 8; i++)
   {
      if(p->getSampleWords(i) == 0)
      {
         continue;
      }
      const MapEntry e = entryOf(p->m_sound_param_as[i].val_s, number);
      if(e.transpose == SOUND_NOT_MAPPED_VALUE)
      {
         continue;   // ce son n'est pas place dans cette map
      }
      Zone z;
      z.hi_key = e.hi_key;
      z.sound = i;
      // le sample sonne a sa hauteur d'origine sur la touche root_key + transposition
      z.orig_key = (int)p->m_sound_param_as[i].val_s.root_key + e.transpose;
      z.gain = e.mix;
      zones.push_back(z);
      used[i] = true;
   }
   sort(zones.begin(), zones.end(), [](const Zone &a, const Zone &b) { return a.hi_key < b.hi_key; });
   return zones;
}

shared_ptr<const SoundData> buildSound(Proph2000 *p, int i)
{
   const uint32_t words = p->getSampleWords(i);
   if(words == 0)
   {
      return shared_ptr<const SoundData>();
   }
   const uint16_t *data = p->getSampleData(i);
   const auto &v = p->m_sound_param_as[i].val_s;

   shared_ptr<SoundData> s(new SoundData);
   s->pcm.resize(words);
   for(uint32_t k = 0; k < words; k++)
   {
      // mots de 12 bits non signes, centre sur 2048
      s->pcm[k] = ((float)(data[k] & 0x0fff) - 2048.0f) / 2048.0f;
   }

   switch(p->getSampleRate(i))
   {
      case Proph2000::SR_15625HZ: s->rate_hz = 15625.0f; break;
      case Proph2000::SR_41667HZ: s->rate_hz = 41667.0f; break;
      case Proph2000::SR_31250HZ:
      default:                    s->rate_hz = 31250.0f; break;
   }

   const int w = (int)words;
   s->start = clampi((int)p->getStartPoint(i), 0, w - 1);
   s->end = clampi((int)p->getEndPoint(i) + 1, s->start + 1, w);
   s->sus_start = clampi((int)p->getSustainLoopStart(i), 0, w - 1);
   s->sus_end = clampi((int)p->getSustainLoopEnd(i), 0, w);
   s->rel_start = clampi((int)p->getReleaseLoopStart(i), 0, w - 1);
   s->rel_end = clampi((int)p->getReleaseLoopEnd(i), 0, w);
   s->sus_loop = p->sustainLoopEnabled(i);
   s->rel_loop = p->releaseLoopEnabled(i);
   s->bf = p->bfLoopEnabled(i);
   s->reverse = p->reverseEnabled(i);

   // enveloppes (valeurs brutes comme dans l'editeur)
   s->amp_a = clampi(v.amp_attack_rate, 0, 63);
   s->amp_d = clampi(v.amp_decay_rate, 0, 63);
   s->amp_s = v.amp_sustain_level;
   s->amp_r = clampi(v.amp_release_rate, 0, 63);
   s->filt_a = clampi(v.filt_attack_rate, 0, 63);
   s->filt_d = clampi(v.filt_decay_rate, 0, 63);
   s->filt_s = v.filt_sustain_level;
   s->filt_r = clampi(v.filt_release_rate, 0, 63);
   s->amp_peak_vel = (int)v.amp_peak_vel_sensitivity - 0x80;
   s->filt_peak_vel = (int)v.filt_peak_vel_sensitivity - 0x80;
   s->attack_vel = (int)v.attack_vel_sensitivity - 0x80;
   s->release_vel = (int)v.release_vel_sensitivity - 0x80;

   // filtre: cutoff et resonance sont sur 2 octets, affiches /2 dans l'editeur (0..127)
   {
      uint16_t t = v.filt_cutoff[1] | ((uint16_t)v.filt_cutoff[0] << 8);
      s->cutoff = clampi(t >= 127 ? (((int)t - 127) / 128) / 2 : 0, 0, 127);
      if((v.filt_resonance[0] == 0) && (v.filt_resonance[1] == 0))
      {
         s->resonance = 0;
      }
      else
      {
         t = v.filt_resonance[1] | ((uint16_t)v.filt_resonance[0] << 8);
         s->resonance = clampi(t >= 63 ? (((int)t - 63) / 64) / 2 : 0, 0, 127);
      }
   }
   s->env_amount = (int)v.filt_env_amount - 0x80;
   s->key_track = clampi((int)v.filt_key_tracking / 2, 0, 127);

   return s;
}

} // namespace


shared_ptr<Patch> softProphetBuildPatch(Proph2000 *proph, uint8_t preset, int *nb_sounds)
{
   shared_ptr<Patch> patch(new Patch);
   if(nb_sounds)
   {
      *nb_sounds = 0;
   }
   if(!proph || (preset > 11))
   {
      return patch;
   }

   const auto &pr = proph->m_preset_param_as[preset].val_s;
   bool used[16] = { false };

   patch->left = zonesOfMap(proph, pr.left_x_map_side ? 1 : 0, pr.left_x_map_number & 7, used);
   patch->right = zonesOfMap(proph, pr.right_y_map_side ? 1 : 0, pr.right_y_map_number & 7, used);
   patch->mode = pr.keyboard_mode <= 8 ? pr.keyboard_mode : MODE_LAYER;
   patch->split_point = pr.split_point;
   patch->velocity_threshold = pr.vel_switch_threshold;

   int n = 0;
   for(int i = 0; i < 16; i++)
   {
      if(used[i])
      {
         patch->sounds[i] = buildSound(proph, i);
         if(patch->sounds[i])
         {
            n++;
         }
      }
   }
   if(nb_sounds)
   {
      *nb_sounds = n;
   }
   return patch;
}
