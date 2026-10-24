#ifndef __WAVEH__
#define __WAVEH__


#define WAVE_LOAD_MAX_WORDS MAX_SAMPLE_WORDS_PER_MEMORY

class Logger;

class Wave
{
public:
   typedef enum { WAVE_BOTH = 0, WAVE_LEFT, WAVE_RIGHT } channel_mode_te;
   typedef enum { LOOP_NORMAL, LOOP_REVERSE, LOOP_BF, LOOP_UNDEF } loop_mode_te;

   Wave(Logger *log);
   Wave(uint16_t *sampledata, uint32_t words, uint32_t samplerate); // data must be in 12-bit format
   ~Wave();

   bool load(const char *filename, channel_mode_te channel_mode);
   bool save(const char *filename) const;

   uint8_t *getResourceData(void) { return m_sample_resource; };
   uint32_t getResourceSize(void) const { return m_sample_resource_size; };

   uint32_t getSampleWords(void) const { return m_words; };
   uint32_t getSampleRate(void) const { return m_sample_rate; };
   uint16_t* getSampleData(void) const { return m_sample_data; };  // data is in 12-bit format

   loop_mode_te getLoopMode(void) const { return m_loop_type; };
   uint32_t getLoopStart(void) const { return m_loop_start; };
   uint32_t getLoopEnd(void) const { return m_loop_end; };

   void setLoopStart(uint32_t words);
   void setLoopEnd(uint32_t words);
   void setLoopType(loop_mode_te type);

private:
   Logger *m_log;
   uint8_t *m_sample_resource;
   uint32_t m_sample_resource_size;
   uint16_t *m_sample_data;
   uint32_t m_words;
   uint32_t m_sample_rate;
   uint32_t m_loop_start;
   uint32_t m_loop_end;
   uint32_t m_wave_resource_length;
   bool m_loop_enabled;
   loop_mode_te m_loop_type;

   void updateWaveResource(void);
   bool findDataChunk(FILE *file);

   void processLoopInfo(FILE *file);

};



#endif
