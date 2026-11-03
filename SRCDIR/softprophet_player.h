#ifndef __SOFTPROPHETPLAYERH__
#define __SOFTPROPHETPLAYERH__

#include "softprophet.h"

class Audio;

// Sortie audio (PortAudio) du faux Prophet: ouvre un flux continu sur la carte son choisie dans la configuration.
class SoftProphetPlayer
{
public:
   SoftProphetPlayer();
   ~SoftProphetPlayer();

   // ouvre le flux audio (device choisi dans Audio, sinon la sortie par defaut). Retourne false si impossible.
   bool start(Audio *audio);
   void stop();
   bool isRunning() const { return m_running; }
   double sampleRate() const { return m_rate; }

   softprophet::Engine *engine() { return m_engine; }

private:
   void *m_stream;            // PaStream*
   softprophet::Engine *m_engine;
   double m_rate;
   int m_channels;
   bool m_running;
   bool m_pa_initialized;
   std::vector<float> m_left, m_right;

   static int paCallback(const void *input, void *output, unsigned long frames, const void *timeinfo,
                         unsigned long flags, void *userdata);
};

#endif
