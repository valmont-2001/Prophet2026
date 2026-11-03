#include "types.h"

#include <wx/wx.h>
#include <list>
#include <map>
using namespace std;
#include <portaudio.h>
#include "audio.h"
#include "softprophet_player.h"


SoftProphetPlayer::SoftProphetPlayer() :
   m_stream(NULL), m_engine(NULL), m_rate(0), m_channels(2), m_running(false), m_pa_initialized(false)
{
}


SoftProphetPlayer::~SoftProphetPlayer()
{
   stop();
}


int SoftProphetPlayer::paCallback(const void *input, void *output, unsigned long frames, const void *timeinfo,
                                  unsigned long flags, void *userdata)
{
   SoftProphetPlayer *self = (SoftProphetPlayer *)userdata;
   float *out = (float *)output;
   unsigned long done = 0;
   const int ch = self->m_channels;

   while(done < frames)
   {
      unsigned long n = frames - done;
      if(n > self->m_left.size())
      {
         n = self->m_left.size();
      }
      self->m_engine->render(&self->m_left[0], &self->m_right[0], (int)n);
      for(unsigned long i = 0; i < n; i++)
      {
         if(ch >= 2)
         {
            out[(done + i) * ch] = self->m_left[i];
            out[(done + i) * ch + 1] = self->m_right[i];
         }
         else
         {
            out[done + i] = self->m_left[i];
         }
      }
      done += n;
   }
   return paContinue;
}


bool SoftProphetPlayer::start(Audio *audio)
{
   if(m_running)
   {
      return true;
   }

   if(Pa_Initialize() != paNoError)
   {
      return false;
   }
   m_pa_initialized = true;

   PaDeviceIndex dev = Pa_GetDefaultOutputDevice();
   if(audio)
   {
      map<int, int> &devs = audio->getAudioDevicesList();
      map<int, int>::iterator it = devs.find((int)audio->getAudioDeviceID());
      if(it != devs.end())
      {
         dev = (PaDeviceIndex)it->second;
      }
   }
   const PaDeviceInfo *info = (dev != paNoDevice) ? Pa_GetDeviceInfo(dev) : NULL;
   if(!info || (info->maxOutputChannels < 1))
   {
      stop();
      return false;
   }

   m_channels = info->maxOutputChannels >= 2 ? 2 : 1;
   m_rate = info->defaultSampleRate > 0 ? info->defaultSampleRate : 44100.0;

   PaStreamParameters out;
   out.device = dev;
   out.channelCount = m_channels;
   out.sampleFormat = paFloat32;
   out.suggestedLatency = info->defaultLowOutputLatency;
   out.hostApiSpecificStreamInfo = NULL;

   m_engine = new softprophet::Engine(m_rate);
   m_left.assign(1024, 0.0f);
   m_right.assign(1024, 0.0f);

   PaStream *stream = NULL;
   PaError err = Pa_OpenStream(&stream, NULL, &out, m_rate, paFramesPerBufferUnspecified, paNoFlag, &SoftProphetPlayer::paCallback, this);
   if(err != paNoError)
   {
      stop();
      return false;
   }
   m_stream = stream;
   if(Pa_StartStream(stream) != paNoError)
   {
      stop();
      return false;
   }
   m_running = true;
   return true;
}


void SoftProphetPlayer::stop()
{
   if(m_stream)
   {
      Pa_StopStream((PaStream *)m_stream);
      Pa_CloseStream((PaStream *)m_stream);
      m_stream = NULL;
   }
   m_running = false;
   delete m_engine;
   m_engine = NULL;
   if(m_pa_initialized)
   {
      Pa_Terminate();
      m_pa_initialized = false;
   }
}
