#include "types.h"
#include "soundfontsample.h"



SoundFontSample::SoundFontSample(uint32_t length, uint32_t loop_start, uint32_t loop_end, uint32_t samplerate, uint16_t *sampledata, uint8_t *name, int8_t tune, uint8_t root_key) :
   m_length(length), m_loop_start(loop_start), m_loop_end(loop_end), m_samplerate(samplerate), m_tune(tune), m_root_key(root_key)
{
   uint32_t i;

   m_sampledata_pu16 = new(uint16_t[length]);
   for(i = 0; i < length; i++)
   {
      m_sampledata_pu16[i] = sampledata[i];
   }
   for(i = 0; i < 20; i++)
   {
      m_name[i] = name[i];
   }
}

SoundFontSample::SoundFontSample(const SoundFontSample &rhnd) :
   m_length(rhnd.m_length), m_loop_start(rhnd.m_loop_start), m_loop_end(rhnd.m_loop_end), m_samplerate(rhnd.m_samplerate),
   m_tune(rhnd.m_tune), m_root_key(rhnd.m_root_key)
{
   uint32_t i;

   m_sampledata_pu16 = new(uint16_t[rhnd.m_length]);
   for(i = 0; i < rhnd.m_length; i++)
   {
      m_sampledata_pu16[i] = rhnd.m_sampledata_pu16[i];
   }
   for(i = 0; i < 20; i++)
   {
      m_name[i] = rhnd.m_name[i];
   }
}

SoundFontSample::~SoundFontSample()
{
   delete m_sampledata_pu16;
}


