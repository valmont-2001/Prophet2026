#include "types.h"
#include <stdio.h>
#include "wave.h"
#include "logger.h"
   #include <wx/wx.h>
#include "stopwatch.h"
#include "proph2000.h"



//#define LOG_LOAD_WAVE_PARAM


Wave::Wave(Logger *log) : 
   m_sample_data(NULL), m_words(0), m_sample_rate(0), m_sample_resource(NULL), m_sample_resource_size(0),
   m_loop_enabled(false), m_loop_end(0), m_loop_type(LOOP_UNDEF), m_wave_resource_length(0), m_log(log)
{
}


Wave::Wave(uint16_t *sampledata, uint32_t words, uint32_t samplerate) : 
   m_sample_rate(samplerate), m_loop_start(0), m_loop_end(0), m_loop_type(LOOP_UNDEF), m_loop_enabled(false), m_wave_resource_length(0)
{
   uint32_t i;
   m_sample_data = new(uint16_t[words]);
   for(i = 0; i < words; i++)
   {
      int32_t val;
      val = sampledata[i] - (4096 / 2);
      m_sample_data[i] = ((uint16_t)val << 4);
   }
   m_words = words;

   m_sample_resource_size = (words * 2) + 1000;
   m_sample_resource = new(uint8_t[m_sample_resource_size]);
   
   updateWaveResource();
}


Wave::~Wave()
{
   if(m_sample_data)
   {
      delete m_sample_data;
   }
   if(m_sample_resource)
   {
      delete m_sample_resource;
   }
}


bool Wave::save(const char *filename) const
{
   bool retval = false;
   FILE *myF;
   myF = fopen(filename, "wb");
   if(myF)
   {
      fwrite(m_sample_resource, 1, m_wave_resource_length, myF);

      fclose(myF);
      retval = true;
   }
   return retval;
}


bool Wave::load(const char *filename, channel_mode_te channel_mode)
{
   bool retval = false;

   FILE *myF;
   myF = fopen(filename, "rb");
   if(myF)
   {
      uint8_t ctmp[1000];
      uint16_t t_u16;
      uint32_t t_u32;

      if(m_sample_data)
      {
         delete m_sample_data;
         m_sample_data = NULL;
         m_words = 0;
      }

      m_loop_start = 0;
      m_loop_type = LOOP_UNDEF;
      m_loop_enabled = false;

      fread(ctmp, 1, 4, myF);
      if((ctmp[0] == 'R') && (ctmp[1] == 'I') && (ctmp[2] == 'F') && (ctmp[3] == 'F'))
      {
         fread(&t_u32, 1, 4, myF);
         fread(ctmp, 1, 4, myF);
         if((ctmp[0] == 'W') && (ctmp[1] == 'A') && (ctmp[2] == 'V') && (ctmp[3] == 'E'))
         {
            bool fmtfound = false;
            bool error = false;

            do
            {
               fread(ctmp, 1, 4, myF);
               if((ctmp[0] == 'f') && (ctmp[1] == 'm') && (ctmp[2] == 't') && (ctmp[3] == ' '))
               {
                  fmtfound = true;
               }
               else
               {
                  fread(&t_u32, 1, 4, myF);
                  uint32_t i;
                  for(i = 0; i < t_u32; i++)
                  {
                     fread(ctmp, 1, 1, myF);
                  }
               }
            }while((!fmtfound) && (!error));

            
            if(fmtfound)
            {
               fread(&t_u32, 1, 4, myF);

               //if(t_u32 == 16)
               {
                  uint16_t audiofmt;
                  uint16_t numchannels;
                  uint32_t byterate;
                  uint16_t blockalign;
                  uint16_t bitspersample;

                  fread(&audiofmt, 1, 2, myF);
                  fread(&numchannels, 1, 2, myF);
                  fread(&m_sample_rate, 1, 4, myF);
                  fread(&byterate, 1, 4, myF);
                  fread(&blockalign, 1, 2, myF);
                  fread(&bitspersample, 1, 2, myF);

                  if((t_u32 - 16) > 0)
                  {
                     fread(ctmp, 1, t_u32 - 16, myF);
                  }

                  //fread(ctmp, 1, 4, myF);
                  //if((ctmp[0] == 'd') && (ctmp[1] == 'a') && (ctmp[2] == 't') && (ctmp[3] == 'a'))
                  if(findDataChunk(myF))
                  {
                     uint32_t bytes;

                     uint32_t i;
                     fread(&bytes, 1, 4, myF); // == NumSamples * NumChannels * BitsPerSample/8

                     m_words = (bytes / numchannels) / (bitspersample / 8);

                     m_loop_end = m_words;


                     if(m_words >= (WAVE_LOAD_MAX_WORDS * 2))
                     {
                        m_words = (WAVE_LOAD_MAX_WORDS * 2);
                     }

                     m_sample_data = new(uint16_t[m_words + (4096)]);
                     if(m_sample_resource)
                     {
                        delete m_sample_resource;
                     }
                     m_sample_resource = new(uint8_t[(m_words * 2) + 1000]);
                     bytes = m_words * numchannels * (bitspersample / 8);

                     i = 0;

                     uint8_t t1_u8;
                     uint8_t t2_u8;
                     uint8_t t3_u8;
                     uint8_t t4_u8;
                     uint8_t t5_u8;
                     uint8_t t6_u8;

                     while(i < m_words)
                     {
                        switch(bitspersample)
                        {
                           case 8:
                              if(numchannels > 1)
                              {
                                 uint16_t t2_u8;
                                 uint32_t t3_i16;
                                 uint8_t t_u8;

                                 switch(channel_mode)
                                 {
                                 case WAVE_BOTH:
                                    fread(&t_u8, 1, 1, myF);
                                    fread(&t2_u8, 1, 1, myF);
                                    t_u16 = t_u8;
                                    t_u16 += t2_u8;
                                    t_u16 /= 2;
                                    t_u8 = t_u16;
                                    //t_u8 += 128;
                                    m_sample_data[i] = (t_u8 << 4);
                                    break;
                                 case WAVE_LEFT:
                                    fread(&t_u8, 1, 1, myF);
                                    //t_u8 += 128;
                                    m_sample_data[i] = (t_u8 << 4);
                                    fread(&t_u8, 1, 1, myF); // skip right channel
                                    break;
                                 case WAVE_RIGHT:
                                    fread(&t_u8, 1, 1, myF); // skip left channel
                                    fread(&t_u8, 1, 1, myF);
                                    //t_u8 += 128;
                                    m_sample_data[i] = (t_u8 << 4);
                                    break;
                                 }
                              }
                              else
                              {
                                 uint8_t t_u8;
                                 // mono
                                 fread(&t_u8, 1, 1, myF);
                                 t_u8 += 128;
                                 m_sample_data[i] = ((uint16_t)t_u8) << 4;
                              }
                              break;
                           case 16:
                              if(numchannels > 1)
                              {
                                 uint16_t t2_u16;
                                 uint32_t t3_i32;
                                 switch(channel_mode)
                                 {
                                 case WAVE_BOTH:
                                    fread(&t_u16, 1, 2, myF);
                                    fread(&t2_u16, 1, 2, myF);
                                    t3_i32 = ((int16_t)t_u16 + (int16_t)t2_u16);
                                    t3_i32 /= 2;
                                    t_u16 = (uint16_t)t3_i32;
                                    t_u16 += 32768;
                                    m_sample_data[i] = (t_u16 >> 4);
                                    break;
                                 case WAVE_LEFT:
                                    fread(&t_u16, 1, 2, myF);
                                    t_u16 += 32768;
                                    m_sample_data[i] = (t_u16 >> 4);
                                    fread(&t_u16, 1, 2, myF); // skip right channel
                                    break;
                                 case WAVE_RIGHT:
                                    fread(&t_u16, 1, 2, myF); // skip left channel
                                    fread(&t_u16, 1, 2, myF);
                                    t_u16 += 32768;
                                    m_sample_data[i] = (t_u16 >> 4);
                                    break;
                                 }
                              }
                              else
                              {
                                 // mono
                                 fread(&t_u16, 1, 2, myF);
                                 t_u16 += 32768;
                                 m_sample_data[i] = (t_u16 >> 4);
                              }
                              break;
                           case 24:
                              if(numchannels > 1)
                              {
                                 uint16_t t2_u16;
                                 uint32_t t3_i32;

                                 switch(channel_mode)
                                 {
                                 case WAVE_BOTH:
                                    fread(&t1_u8, 1, 1, myF);
                                    fread(&t2_u8, 1, 1, myF);
                                    fread(&t3_u8, 1, 1, myF);

                                    fread(&t4_u8, 1, 1, myF);
                                    fread(&t5_u8, 1, 1, myF);
                                    fread(&t6_u8, 1, 1, myF);

                                    t_u16 = ((uint16_t)t3_u8 << 8) + t2_u8;
                                    t2_u16 = ((uint16_t)t6_u8 << 8) + t5_u8;

                                    t3_i32 = ((int16_t)t_u16 + (int16_t)t2_u16);
                                    t3_i32 /= 2;
                                    t_u16 = (uint16_t)t3_i32;
                                    t_u16 += 32768;
                                    m_sample_data[i] = (t_u16 >> 4);
                                    break;
                                 case WAVE_LEFT:
                                    fread(&t1_u8, 1, 1, myF);
                                    fread(&t2_u8, 1, 1, myF);
                                    fread(&t3_u8, 1, 1, myF);

                                    fread(&t4_u8, 1, 1, myF);
                                    fread(&t5_u8, 1, 1, myF);
                                    fread(&t6_u8, 1, 1, myF);

                                    t_u16 = ((uint16_t)t3_u8 << 8) + t2_u8;
                                    t_u16 += 32768;
                                    m_sample_data[i] = (t_u16 >> 4);
                                    break;
                                 case WAVE_RIGHT:
                                    fread(&t1_u8, 1, 1, myF);
                                    fread(&t2_u8, 1, 1, myF);
                                    fread(&t3_u8, 1, 1, myF);

                                    fread(&t4_u8, 1, 1, myF);
                                    fread(&t5_u8, 1, 1, myF);
                                    fread(&t6_u8, 1, 1, myF);

                                    //t_u16 = ((uint16_t)t6_u8 << 8) + t4_u8;
                                    t_u16 = ((uint16_t)t6_u8 << 8) + t5_u8;
                                    t_u16 += 32768;
                                    m_sample_data[i] = (t_u16 >> 4);
                                    break;
                                 }
                              }
                              else
                              {
                                 // mono
                                 fread(&t1_u8, 1, 1, myF);
                                 fread(&t2_u8, 1, 1, myF);
                                 fread(&t3_u8, 1, 1, myF);

                                 t_u16 = ((uint16_t)t3_u8 << 8) + t2_u8;

                                 t_u16 += 32768;
                                 m_sample_data[i] = (t_u16 >> 4);
                              }
                              break;
                           default:
                              break;
                        }
                        i++;
                     }

                     processLoopInfo(myF);

                  }
               }
            }
         }
      }
      else
      {
         m_log->log("Wave::load(%s) is no wave file", filename);
      }

      retval = true;
      fclose(myF);
      updateWaveResource();
   }

   return retval;
}

void Wave::processLoopInfo(FILE *file)
{
   char ctmp[10];
   bool ready = false;
   unsigned long i;
   while(!ready)
   {
      if(fread(ctmp, 1, 4, file) == 4)
      {

         if((ctmp[0] == 's') && (ctmp[1] == 'm') && (ctmp[2] == 'p') && (ctmp[3] == 'l'))
         {
            uint32_t type;
            uint32_t start;
            uint32_t end;
            uint32_t cuepoint;
            uint32_t samplerdata;
            uint32_t numloops;

            for(i = 0; i < 0x20; i++)
            {
               fread(ctmp, 1, 1, file);
            }

            fread(&numloops, 1, 4, file);

            fread(&samplerdata, 1, 4, file);


            fread(&cuepoint, 1, 4, file);

            fread(&type, 1, 4, file);

            switch(type)
            {
               case 0:
                  m_loop_type = LOOP_NORMAL;
               break;
               case 1:
                  m_loop_type = LOOP_BF;
               break;
               case 2:
                  m_loop_type = LOOP_REVERSE;
               break;
               default:
                  m_loop_type = LOOP_UNDEF;
                  break;
            }

            fread(&start, 1, 4, file);
            m_loop_start = start;
            fread(&end, 1, 4, file);
            m_loop_end = end;
            m_loop_enabled = true;

            ready = true;
         }
         else
         {
            uint32_t chunksize;
            if(fread(&chunksize, 1, 4, file) == 4)
            {
               for(i = 0; i < chunksize; i++)
               {
                  if(fread(ctmp, 1, 1, file) != 1)
                  {
                     ready = true;
                     break;
                  }
               }
            }
            else
            {
               ready = true;
            }
         }

      }
      else
      {
         ready = true;
      }
   }
}

bool Wave::findDataChunk(FILE *file)
{
   bool retval = false;
   char ctmp[10];
   bool ready = false;
   while(!ready)
   {
      fread(ctmp, 1, 4, file);
      if((ctmp[0] == 'd') && (ctmp[1] == 'a') && (ctmp[2] == 't') && (ctmp[3] == 'a'))
      {
         ready = true;
         retval = true;
      }
      else
      {
         uint32_t chunksize;
         if(fread(&chunksize, 1, 4, file) == 4)
         {
            for(unsigned long i = 0; i < chunksize; i++)
            {
               if(fread(ctmp, 1, 1, file) != 1)
               {
                  ready = true;
                  break;
               }
            }
         }
         else
         {
            ready = true;
         }
      }
   }

   return retval;
}


void Wave::updateWaveResource(void)
{
   uint32_t i;
   uint32_t t_u32;
   uint16_t t_u16;
   uint32_t *p32;
   uint16_t *p16;

   if(!m_sample_resource)
   {
      m_sample_resource = new(uint8_t[(1000 * 2) + 1000 + (m_words * 2)]);
   }

   m_sample_resource[0] = 'R';
   m_sample_resource[1] = 'I';
   m_sample_resource[2] = 'F';
   m_sample_resource[3] = 'F';

   t_u32 = 36 + m_words;
   p32 = (uint32_t*)&m_sample_resource[4];
   *p32 = t_u32;

   m_sample_resource[8] = 'W';
   m_sample_resource[9] = 'A';
   m_sample_resource[10] = 'V';
   m_sample_resource[11] = 'E';
      
   m_sample_resource[12] = 'f';
   m_sample_resource[13] = 'm';
   m_sample_resource[14] = 't';
   m_sample_resource[15] = ' ';

   t_u32 = 16;
   p32 = (uint32_t*)&m_sample_resource[16];
   *p32 = t_u32;
     
   t_u16 = 1;  // audio format = pcm
   p16 = (uint16_t*)&m_sample_resource[20];
   *p16 = t_u16;

   t_u16 = 1;  // num channels
   p16 = (uint16_t*)&m_sample_resource[22];
   *p16 = t_u16;

   t_u32 = m_sample_rate; // sample rate
   p32 = (uint32_t*)&m_sample_resource[24];
   *p32 = t_u32;

   t_u32 = m_sample_rate * 1 * 2; // == SampleRate * NumChannels * BitsPerSample/8
   p32 = (uint32_t*)&m_sample_resource[28];
   *p32 = t_u32;
   
   t_u16 = 2;  // block align
   p16 = (uint16_t*)&m_sample_resource[32];
   *p16 = t_u16;

   t_u16 = 16;  // 16 bit
   p16 = (uint16_t*)&m_sample_resource[34];
   *p16 = t_u16;

   m_sample_resource[36] = 'd';
   m_sample_resource[37] = 'a';
   m_sample_resource[38] = 't';
   m_sample_resource[39] = 'a';


   t_u32 = m_words * 2; // == NumSamples * NumChannels * BitsPerSample/8
   p32 = (uint32_t*)&m_sample_resource[40];
   *p32 = t_u32;

   for(i = 0; i < m_words; i++)
   {
      m_sample_resource[(i * 2) + 44 + 1] = (m_sample_data[i] & 0xff00) >> 8;
      m_sample_resource[(i * 2) + 44] = m_sample_data[i] & 0xff;
   }

   m_wave_resource_length = (m_words * 2) + 44;

   if(m_loop_type != LOOP_UNDEF)
   {
      m_sample_resource[m_wave_resource_length++] = 's';
      m_sample_resource[m_wave_resource_length++] = 'm';
      m_sample_resource[m_wave_resource_length++] = 'p';
      m_sample_resource[m_wave_resource_length++] = 'l';

      p32 = (uint32_t*)&m_sample_resource[m_wave_resource_length];
      m_wave_resource_length += 4;
      *p32 = 36 + (1 * 24) ; // chunk size (36 + (Num Sample Loops * 24) )

      p32 = (uint32_t*)&m_sample_resource[m_wave_resource_length];
      m_wave_resource_length += 4;
      *p32 = 0; // Manufacturer

      p32 = (uint32_t*)&m_sample_resource[m_wave_resource_length];
      m_wave_resource_length += 4;
      *p32 = 0; // Product

      p32 = (uint32_t*)&m_sample_resource[m_wave_resource_length];
      m_wave_resource_length += 4;
      *p32 = 0; // Sample Period

      p32 = (uint32_t*)&m_sample_resource[m_wave_resource_length];
      m_wave_resource_length += 4;
      *p32 = 0; // MIDI Unity Note

      p32 = (uint32_t*)&m_sample_resource[m_wave_resource_length];
      m_wave_resource_length += 4;
      *p32 = 0; // MIDI Pitch Fraction

      p32 = (uint32_t*)&m_sample_resource[m_wave_resource_length];
      m_wave_resource_length += 4;
      *p32 = 0; // SMPTE Format

      p32 = (uint32_t*)&m_sample_resource[m_wave_resource_length];
      m_wave_resource_length += 4;
      *p32 = 0; // SMPTE Offset

      p32 = (uint32_t*)&m_sample_resource[m_wave_resource_length];
      m_wave_resource_length += 4;
      *p32 = 1; // Num Sample Loops

      p32 = (uint32_t*)&m_sample_resource[m_wave_resource_length];
      m_wave_resource_length += 4;
      *p32 = 0; // Sampler Data

      // loop 1
      p32 = (uint32_t*)&m_sample_resource[m_wave_resource_length];
      m_wave_resource_length += 4;
      *p32 = 1; // Cue Point ID

      p32 = (uint32_t*)&m_sample_resource[m_wave_resource_length];
      m_wave_resource_length += 4;
      switch(m_loop_type)
      {
         case LOOP_NORMAL:
            *p32 = 0; // Type
            break;
         case LOOP_REVERSE:
            *p32 = 2; // Type
            break;
         case LOOP_BF:
            *p32 = 1; // Type
            break;
         case LOOP_UNDEF:
            *p32 = 0; // Type
            break;
         default:
            break;
      }

      p32 = (uint32_t*)&m_sample_resource[m_wave_resource_length];
      m_wave_resource_length += 4;
      *p32 = m_loop_start; 

      p32 = (uint32_t*)&m_sample_resource[m_wave_resource_length];
      m_wave_resource_length += 4;
      *p32 = m_loop_end; 

      p32 = (uint32_t*)&m_sample_resource[m_wave_resource_length];
      m_wave_resource_length += 4;
      *p32 = 0;  // Fraction

      p32 = (uint32_t*)&m_sample_resource[m_wave_resource_length];
      m_wave_resource_length += 4;
      *p32 = 0;  // Play Count
   }
}


void Wave::setLoopStart(uint32_t words)
{ 
   m_loop_start = words; 
   updateWaveResource();
}

void Wave::setLoopEnd(uint32_t words)
{ 
   m_loop_end = words; 
   updateWaveResource();
}


void Wave::setLoopType(loop_mode_te type) 
{ 
   m_loop_type = type; 
   updateWaveResource();
}




