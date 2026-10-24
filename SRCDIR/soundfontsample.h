#ifndef __SNDFNTSMPLH__
#define __SNDFNTSMPLH__


class SoundFontSample
{
public:
   SoundFontSample(uint32_t length, uint32_t loop_start, uint32_t loop_end, uint32_t samplerate, uint16_t *sampledata, uint8_t *name, int8_t tune, uint8_t root_key);
   SoundFontSample(const SoundFontSample &rhnd);
   ~SoundFontSample();

   uint32_t getLength(void) const { return m_length; };
   uint32_t getLoopStart(void) const { return m_loop_start; };
   uint32_t getLoopEnd(void) const { return m_loop_end; };
   uint32_t getSampleRate(void) const { return m_samplerate; };
   uint16_t *getSampleData(void) const { return m_sampledata_pu16; };
   const uint8_t *getName(void) const { return m_name; };
   int8_t getTune(void) const { return m_tune; };
   uint8_t getRootKey(void) const { return m_root_key; };

private:
   uint32_t m_length;
   uint32_t m_loop_start;
   uint32_t m_loop_end;
   uint32_t m_samplerate;
   uint8_t m_root_key;
   uint16_t *m_sampledata_pu16;  // contains 12-bit sample data
   uint8_t m_name[20];
   int8_t m_tune;
};



#endif
