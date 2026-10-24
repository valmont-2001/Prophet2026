#ifndef __AUDIOH__
#define __AUDIOH__

#include <portaudio.h>

#include <map>
using namespace std;

#define __USING_FLOAT_AUDIO

class Audio
{
public:
   Audio();
   ~Audio();

   void setAudioData(uint16_t *data, uint32_t length);
   void setStereoAudioData(uint16_t *data_l, uint16_t *data_r, uint32_t length);
   void play(bool loop, uint32_t samplerate);
   void stop(void);

   bool getStereoMode(void) const { return m_stereo_mode; }
   
   uint8_t getOutputChannels(void) const { return m_outputchannels; };

#ifdef __USING_FLOAT_AUDIO
   float *getAudioLData(void) const { return m_audio_l_data; };
   float *getAudioRData(void) const { return m_audio_r_data; };
#else
   uint16_t *getAudioLData(void) const { return m_audio_l_data; };
   uint16_t *getAudioRData(void) const { return m_audio_r_data; };
#endif
   uint32_t getAudioDataLength(void) const { return m_length; };
   bool getLoopFlag(void) const { return m_loop; };
   uint32_t getAudioOutIndex(void) const { return m_audio_out_idx; };
   void setAudioOutIndex(uint32_t val) { m_audio_out_idx = val; };
   bool isPlaying(void) const {  return m_is_playing;  };
   void setPlaying(bool flag) {  m_is_playing = flag; }; // must only be called from Audio callback function

   map<int, int> &getAudioDevicesList(void) { return m_audio_devices; };

   uint32_t getAudioDeviceID(void) const { return m_audio_device_id; };
   void setAudioDeviceID(uint32_t id);

   void loadConfig(FILE *file);
   void saveConfig(FILE *file);

private:
   map<int, int> m_audio_devices;
   uint32_t m_audio_device_id;
   bool m_initialized;
   bool m_stream_open;
   bool m_stream_started;
   bool m_loop;
   bool m_is_playing;
   bool m_stereo_mode;
   uint8_t m_outputchannels;
   uint32_t m_length;
#ifdef __USING_FLOAT_AUDIO
   float *m_audio_l_data;
   float *m_audio_r_data;
#else
   uint16_t *m_audio_l_data;
   uint16_t *m_audio_r_data;
#endif
   uint32_t m_audio_out_idx;
   uint32_t m_samplerate;
   PaStream *m_stream;

   bool openStream(uint32_t samplerate);
   bool startStream(void);
   bool stopStream(void);
   bool closeStream(void);

};



#endif
