#ifndef __SOUNDFONTH__
#define __SOUNDFONTH__

#include <stdio.h>

class SoundFontSample;

class SoundFont
{
public:
   SoundFont();
   ~SoundFont();

   bool load(const char *filename);
   
   const list<SoundFontSample>& getSampleList(void) const { return m_samples; };
   

private:
   uint8_t *m_data_pu8;
   uint16_t m_version_major;
   uint16_t m_version_minor;
   int16_t *m_sample_data_pi16;
   list<SoundFontSample> m_samples;

   bool readChunk(FILE *f);
   bool readListChunk(FILE *f);
   void processInfoList(uint8_t *p, uint32_t size);
   void processSDTAList(uint8_t *p, uint32_t size);
   void processPDTAList(uint8_t *p, uint32_t size);

   uint8_t *processChunk(uint8_t *p);
   uint8_t *processSHDRChunk(uint8_t *p, uint32_t size);
};


#endif
