#ifndef __SOFTPROPHETH__
#define __SOFTPROPHETH__

// "Faux Prophet": moteur de lecture logiciel qui rejoue les vrais samples comme un Prophet 2000
// (transposition a partir de la frequence d'echantillonnage d'origine, boucles sustain/release,
// enveloppes ADSR d'amplificateur et de filtre, filtre passe-bas 4 poles resonant, velocite, maps/presets).
//
// Ce fichier ne depend ni de wxWidgets ni de PortAudio: le moteur peut etre teste seul.

#include <stdint.h>
#include <vector>
#include <memory>
#include <mutex>

namespace softprophet
{

// Modes clavier d'un preset (meme numerotation que le Prophet / l'editeur)
enum KeyboardMode
{
   MODE_MERGE = 0, MODE_SPLIT = 1, MODE_RIGHT_ONLY = 2, MODE_LEFT_ONLY = 3, MODE_LAYER = 4,
   MODE_POSITIONAL_XFADE = 5, MODE_VELOCITY_SWITCH = 6, MODE_VELOCITY_XFADE = 7, MODE_MODWHEEL_XFADE = 8
};

// Un son pret a jouer. Les valeurs de parametres sont celles de l'editeur (valeurs "brutes" decodees).
struct SoundData
{
   std::vector<float> pcm;      // echantillons normalises -1..+1
   float rate_hz;               // frequence d'echantillonnage d'origine: 15625, 31250 ou 41667
   int start, end;              // zone lue: [start, end[ (indices dans pcm)
   int sus_start, sus_end;      // boucle de sustain
   int rel_start, rel_end;      // boucle de release
   bool sus_loop, rel_loop;
   bool bf;                     // boucle de release en mode arriere/avant (back/forth)
   bool reverse;                // lecture a l'envers

   // Enveloppes: attaque/decay/release 0..63 (0=instantane pour l'attaque, 63=infini pour decay/release),
   // sustain 0..255 (0=OFF, mode ADR; 255=niveau maximum)
   int amp_a, amp_d, amp_s, amp_r;
   int filt_a, filt_d, filt_s, filt_r;
   int amp_peak_vel, filt_peak_vel;   // -128..+127
   int attack_vel, release_vel;       // -128..+127

   int cutoff;        // 0..127
   int resonance;     // 0..127
   int key_track;     // 0..127 (63 = 1:1)
   int env_amount;    // -128..+127

   SoundData();
};

// Une zone du clavier: du dernier hi_key de la zone precedente +1 jusqu'a hi_key
struct Zone
{
   int hi_key;        // derniere touche (numero MIDI) de la zone
   int sound;         // numero du son 0..15
   int orig_key;      // touche a laquelle le sample sonne a sa hauteur d'origine
   int gain;          // melange relatif 0..255
};

struct Patch
{
   std::shared_ptr<const SoundData> sounds[16];
   std::vector<Zone> left;      // zones de la map gauche (triees par hi_key)
   std::vector<Zone> right;     // zones de la map droite
   int mode;
   int split_point;             // numero de touche MIDI
   int velocity_threshold;      // 0..127
   Patch();
};

class Engine
{
public:
   explicit Engine(double out_rate, int max_voices = 16);
   ~Engine();

   // --- a appeler depuis le fil de l'interface ---
   void setPatch(std::shared_ptr<const Patch> patch);
   void noteOn(int note, int velocity);
   void noteOff(int note);
   void allNotesOff();
   void setHold(bool on);              // pedale: les relachements sont retenus
   void setModWheel(float value01);

   // --- a appeler depuis le fil audio ---
   void render(float *left, float *right, int frames);   // ecrit (ecrase) les tampons

   int activeVoices() const { return m_active_voices; }
   double outputRate() const { return m_out_rate; }

private:
   struct Impl;
   Impl *m_impl;
   double m_out_rate;
   int m_active_voices;
};

// Fonctions utilitaires exposees pour les tests
float envTimeSeconds(int value);                       // 0..62 -> secondes
float cutoffHz(int cutoff, int key_track, int note, float env_octaves);

} // namespace softprophet

#endif
