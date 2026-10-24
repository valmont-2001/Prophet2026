#include "types.h"
#include <wx/wx.h>

#include "audio.h"

#ifdef __WXMAC__
   #define FRAMES_PER_BUFFER 4096
#else
   #define FRAMES_PER_BUFFER 256
#endif

static int patestCallback( const void *inputBuffer, void *outputBuffer,
                           unsigned long framesPerBuffer,
                           const PaStreamCallbackTimeInfo* timeInfo,
                           PaStreamCallbackFlags statusFlags,
                           void *userData )
{
   Audio *audio = (Audio*)userData;
#ifdef __USING_FLOAT_AUDIO
   float *out = (float*)outputBuffer;
#else
   uint16_t *out = (uint16_t*)outputBuffer;
#endif
   uint16_t i;
   uint8_t ch;
   (void) inputBuffer; /* Prevent unused variable warning. */
   bool abort = false;

   if(audio->getLoopFlag())
   {
      for( i=0; i<framesPerBuffer; i++ )
      {
         if(audio->getStereoMode())
         {
#ifdef __USING_FLOAT_AUDIO
            float value_l = audio->getAudioLData()[audio->getAudioOutIndex()];
            float value_r = audio->getAudioRData()[audio->getAudioOutIndex()];
#else
            int32_t value_l = (int32_t)((int32_t)audio->getAudioLData()[audio->getAudioOutIndex()]) * 8;
            int32_t value_r = (int32_t)((int32_t)audio->getAudioRData()[audio->getAudioOutIndex()]) * 8;
#endif

            if(audio->getOutputChannels() == 2)
            {
               *out++ = value_l;
               *out++ = value_r;
            }
            else
            {
               for(ch = 0; ch < audio->getOutputChannels(); ch++)
               {
                  *out++ = value_l;
               }
            }
         }
         else
         {
#ifdef __USING_FLOAT_AUDIO
            float value = audio->getAudioLData()[audio->getAudioOutIndex()];
#else
            int32_t value = (int32_t)((int32_t)audio->getAudioLData()[audio->getAudioOutIndex()]) * 8;
#endif

            for(ch = 0; ch < audio->getOutputChannels(); ch++)
            {
               *out++ = value;
            }
         }

         audio->setAudioOutIndex(audio->getAudioOutIndex() + 1);
         if(audio->getAudioOutIndex() >= (audio->getAudioDataLength()))
         {
            audio->setAudioOutIndex(0);
         }
      }
   }
   else
   {
      for( i=0; i<framesPerBuffer; i++ )
      {
         if(audio->getAudioOutIndex() < (audio->getAudioDataLength()))
         {
            if(audio->getStereoMode())
            {
#ifdef __USING_FLOAT_AUDIO
               float value_l = audio->getAudioLData()[audio->getAudioOutIndex()];
               float value_r = audio->getAudioRData()[audio->getAudioOutIndex()];
#else
               int32_t value_l = (int32_t)((int32_t)audio->getAudioLData()[audio->getAudioOutIndex()]) * 8;
               int32_t value_r = (int32_t)((int32_t)audio->getAudioRData()[audio->getAudioOutIndex()]) * 8;
#endif
               if(audio->getOutputChannels() == 2)
               {
                  *out++ = value_l;
                  *out++ = value_r;
               }
               else
               {
                  for(ch = 0; ch < audio->getOutputChannels(); ch++)
                  {
                     *out++ = value_l;
                  }
               }
            }
            else
            {
#ifdef __USING_FLOAT_AUDIO
               float value = audio->getAudioLData()[audio->getAudioOutIndex()];
#else
               int32_t value = (int32_t)((int32_t)audio->getAudioLData()[audio->getAudioOutIndex()]) * 8;
#endif
               for(ch = 0; ch < audio->getOutputChannels(); ch++)
               {
                  *out++ = value;
               }
            }
            audio->setAudioOutIndex(audio->getAudioOutIndex() + 1);
         }
         else
         {
            for(ch = 0; ch < audio->getOutputChannels(); ch++)
            {
               *out++ = 0;
            }
            abort = true;
            audio->setPlaying(false);
         }
      }
   }
return 0;
   if(abort)
   {
      return paComplete;
   }
   else
   {
      return 0;
   }
}


Audio::Audio() : 
   m_initialized(false), m_stream_open(false), m_stream_started(false), m_length(0), m_audio_l_data(NULL), m_audio_r_data(NULL),
   m_loop(false), m_audio_out_idx(0), m_samplerate(0), m_is_playing(false), m_audio_device_id(0), m_outputchannels(0),
   m_stereo_mode(false)
{
   PaError err;

   err = Pa_Initialize();
   if( err != paNoError )
   {
      wxLogMessage(wxT("Pa_Initialize() error"));
   }
   else
   {
      m_initialized = true;
   }

   uint8_t devcnt = Pa_GetDeviceCount();

   uint8_t i;
   uint8_t i2 = 0;
   for(i = 0; i < devcnt; i++)
   {
      const PaDeviceInfo *dev;
      dev = Pa_GetDeviceInfo(i);
 //     wxLogMessage("audio device: %s in_ch:%d out_ch:%d", dev->name, dev->maxInputChannels, dev->maxOutputChannels);

      //if((dev->maxOutputChannels >= 2) && (dev->maxInputChannels == 0)) // input==0??
      if(dev->maxOutputChannels >= 2) // input==0??
      {
         m_audio_devices[i2] = i;
         i2++;
      }
   }
//         wxLogMessage("audio devices: %d", devcnt);

}


Audio::~Audio()
{
   PaError err;

   if(m_stream_started)
   {
      err = Pa_StopStream( m_stream );
      if( err != paNoError )
      {
         wxLogMessage(wxT("Pa_StopStream() error"));
      }
   }

   if(m_stream_open)
   {
      err = Pa_CloseStream( m_stream );
      if( err != paNoError )
      {
         wxLogMessage(wxT("Pa_CloseStream() error"));
      }
   }

   Pa_Terminate();

   if(m_audio_l_data)
   {
      delete m_audio_l_data;
   }
   if(m_audio_r_data)
   {
      delete m_audio_r_data;
   }
}


void Audio::setAudioDeviceID(uint32_t id)
{
   m_audio_device_id = id;
}


void Audio::loadConfig(FILE *file)
{
   if(file)
   {
      fread(&m_audio_device_id, 1, 4, file);
   }
}


void Audio::saveConfig(FILE *file)
{
   if(file)
   {
      fwrite(&m_audio_device_id, 1, 4, file);
   }
}


bool Audio::openStream(uint32_t samplerate)
{
   bool retval = false;
   PaError err;

   if(!m_stream_open)
   {
      m_samplerate = samplerate;

      unsigned char outdev = 0;

      map<int, int>::iterator myItr = m_audio_devices.begin();
      while((myItr != m_audio_devices.end()) && (!outdev))
      {
         if((*myItr).first == m_audio_device_id)
         {
            outdev = (*myItr).second;
         }
         ++myItr;
      }

      const PaDeviceInfo *devinfo;
      devinfo = Pa_GetDeviceInfo(outdev);
      
      m_outputchannels = devinfo->maxOutputChannels;
      wxLogMessage("%d", m_outputchannels);

//      wxLogMessage("dev %d lat:%d hlat:%d", outdev, devinfo->defaultLowOutputLatency, devinfo->defaultHighOutputLatency);

      PaStreamParameters outparam;
      outparam.channelCount = m_outputchannels; // open all channels
      outparam.device = outdev;
#ifdef __USING_FLOAT_AUDIO
      outparam.sampleFormat = paFloat32;  /* 32 bit floating point output */
#else
      outparam.sampleFormat = paInt16;  /* 32 bit floating point output */
#endif
      outparam.suggestedLatency = devinfo->defaultLowOutputLatency;
      //outparam.suggestedLatency = devinfo->defaultHighOutputLatency;
      outparam.hostApiSpecificStreamInfo = NULL;

      err = Pa_OpenStream( &m_stream,
                             NULL,
                             &outparam,
                             samplerate,
                             FRAMES_PER_BUFFER,
                             paNoFlag,
                             patestCallback,
                                   this );
      if( err != paNoError )
      {
         wxLogMessage(wxT("Pa_OpenDefaultStream() error"));
      }
      else
      {
         m_stream_open = true;
         retval = true;
      }

   }
   return retval;
}


bool Audio::closeStream(void)
{
   bool retval = false;
   PaError err;
   if(m_stream_open)
   {
      err = Pa_CloseStream( m_stream );
      if( err != paNoError )
      {
         wxLogMessage(wxT("Pa_CloseStream() error"));
      }
      else
      {
         retval = true;
      }
      m_stream_open = false;
   }   
   return retval;
}


bool Audio::startStream(void)
{
   bool retval = false;
   PaError err;

   if(!m_stream_started)
   {   
      err = Pa_StartStream( m_stream );
      if( err != paNoError )
      {
         wxLogMessage(wxT("Pa_StartStream() error"));
      }
      else
      {
         m_is_playing = true;
         m_stream_started = true;
         retval = true;
      }
   }

   return retval;
}


bool Audio::stopStream(void)
{
   bool retval = false;
   PaError err;
   
   err = Pa_StopStream( m_stream );
   if( err != paNoError )
   {
      wxLogMessage(wxT("Pa_StopStream() error"));
   }
   else
   {
      retval = true;
   }
   m_is_playing = false;
   m_stream_started = false;
   return retval;
}


void Audio::setAudioData(uint16_t *data, uint32_t length)
{
   uint32_t i;
   m_length = length;
   m_stereo_mode = false;
   stop();
   if(m_audio_l_data)
   {
      delete m_audio_l_data;
   }
#ifdef __USING_FLOAT_AUDIO
   m_audio_l_data = new(float[length]);
#else
   m_audio_l_data = new(uint16_t[length]);
#endif
   for(i = 0; i < length; i++)
   {
#ifdef __USING_FLOAT_AUDIO
      m_audio_l_data[i] = (float)data[i];
      m_audio_l_data[i] -= (4096 / 2);
      m_audio_l_data[i] /= (4096 / 2);
#else
      m_audio_l_data[i] = data[i];
#endif
   }
}

void Audio::setStereoAudioData(uint16_t *data_l, uint16_t *data_r, uint32_t length)
{
   uint32_t i;
   m_length = length;
   m_stereo_mode = true;
   stop();
   if(m_audio_l_data)
   {
      delete m_audio_l_data;
   }
   if(m_audio_r_data)
   {
      delete m_audio_r_data;
   }
#ifdef __USING_FLOAT_AUDIO
   m_audio_l_data = new(float[length]);
   m_audio_r_data = new(float[length]);
#else
   m_audio_l_data = new(uint16_t[length]);
   m_audio_r_data = new(uint16_t[length]);
#endif
   for(i = 0; i < length; i++)
   {
#ifdef __USING_FLOAT_AUDIO
      m_audio_l_data[i] = (float)data_l[i];
      m_audio_l_data[i] -= (4096 / 2);
      m_audio_l_data[i] /= (4096 / 2);
      m_audio_r_data[i] = (float)data_r[i];
      m_audio_r_data[i] -= (4096 / 2);
      m_audio_r_data[i] /= (4096 / 2);
#else
      m_audio_l_data[i] = data_l[i];
      m_audio_r_data[i] = data_r[i];
#endif
   }
}


void Audio::play(bool loop, uint32_t samplerate)
{
   m_loop = loop;

   //if(m_samplerate != samplerate)
   {
      stop();
      closeStream();
   }
   m_audio_out_idx = 0;
   openStream(samplerate);
   startStream();
}


void Audio::stop(void)
{
   if(m_stream_started)
   {
      stopStream();
   }
}

