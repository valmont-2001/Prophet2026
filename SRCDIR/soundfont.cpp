#include "types.h"
#include <list>
#include <iostream>
using namespace std;
#include "soundfontsample.h"
#include "soundfont.h"
#include <stdio.h>
#include <wx/wx.h>


SoundFont::SoundFont() : m_data_pu8(NULL), m_version_major(0), m_version_minor(0), m_sample_data_pi16(NULL)
{
}

SoundFont::~SoundFont()
{
   if(m_data_pu8)
   {
      delete m_data_pu8;
   }
   if(m_sample_data_pi16)
   {
      delete m_sample_data_pi16;
   }
}


bool SoundFont::load(const char *filename)
{
   bool retval = false;

   list<SoundFontSample> emptylist;
   m_samples = emptylist;

   FILE *mf = fopen(filename, "rb");

   if(m_data_pu8)
   {
      delete m_data_pu8;
   }
   m_data_pu8 = new(uint8_t[1024*1024*50]);

   if(mf)
   {
      char ctmp[5];
      ctmp[4] = 0;
      
      if(fread(ctmp, 1, 4, mf) == 4)
      {
         uint32_t t_u32;

         //wxLogMessage("Chunk: %s", ctmp);

         fread(&t_u32, 1, 4, mf);
         //cout << "size: " << t_u32 << endl;

         if((ctmp[0] == 'R') && (ctmp[1] == 'I') && (ctmp[2] == 'F') && (ctmp[3] == 'F'))
         {
            if(fread(ctmp, 1, 4, mf) == 4)
            {
               if((ctmp[0] == 's') && (ctmp[1] == 'f') && (ctmp[2] == 'b') && (ctmp[3] == 'k'))
               {
                  while(readChunk(mf));
               }
            }
            retval = true;
         }
      }

      fclose(mf);
   }

   return retval;
}


bool SoundFont::readChunk(FILE *f)
{
   bool retval = false;
   char ctmp[5];
   ctmp[4] = 0;

   if(fread(ctmp, 1, 4, f) == 4)
   {
      if((ctmp[0] == 'L') && (ctmp[1] == 'I') && (ctmp[2] == 'S') && (ctmp[3] == 'T'))
      {
         retval = readListChunk(f);
      }
      else
      {
         uint32_t t_u32;
         //cout << "unknown chunk: " << ctmp << endl;
         fread(&t_u32, 1, 4, f);
         //cout << " size: " << t_u32 << endl;
         for(uint32_t i = 0; i < t_u32; i++)
         {
            fread(ctmp, 1, 1, f);
         }
         retval = true;
      }
   }

   return retval;
}


bool SoundFont::readListChunk(FILE *f)
{
   bool retval = false;
   uint32_t csize;

   //cout << "Chunk: LIST" << endl;

   fread(&csize, 1, 4, f);
   //cout << " size: " << csize << endl;
   if(fread(m_data_pu8, 1, csize, f) == csize)
   {
      if((m_data_pu8[0] == 'I') && (m_data_pu8[1] == 'N') && (m_data_pu8[2] == 'F') && (m_data_pu8[3] == 'O'))
      {
         processInfoList(m_data_pu8 + 4, csize);
      }
      if((m_data_pu8[0] == 's') && (m_data_pu8[1] == 'd') && (m_data_pu8[2] == 't') && (m_data_pu8[3] == 'a'))
      {
         processSDTAList(m_data_pu8 + 4, csize);
      }
      else
      if((m_data_pu8[0] == 'p') && (m_data_pu8[1] == 'd') && (m_data_pu8[2] == 't') && (m_data_pu8[3] == 'a'))
      {
         processPDTAList(m_data_pu8 + 4, csize);
      }
      else
      {
         //m_data_pu8[4] = 0;
         //cout << m_data_pu8 << endl;
      }

      retval = true;
   }
   return retval;
}

void SoundFont::processInfoList(uint8_t *p, uint32_t size)
{
   uint8_t *ps = p;
   //cout << " chunk: INFO size:" << size << endl;
   do
   {
      p = processChunk(p);
   }
   while( (p - ps) < (size - 4));
}


uint8_t* SoundFont::processChunk(uint8_t *p)
{
   char ctmp[5];
   uint32_t s;

   ctmp[4] = 0;
   ctmp[0] = *p;
   p++;
   ctmp[1] = *p;
   p++;
   ctmp[2] = *p;
   p++;
   ctmp[3] = *p;
   p++;

   s = *((uint32_t*)p);
   //cout << " chunk: " << ctmp << " size: " << s << endl;
   p += 4;

   if((ctmp[0] == 'i') && (ctmp[1] == 'f') && (ctmp[2] == 'i') && (ctmp[3] == 'l'))
   {
      m_version_major = *((uint16_t*)p);
      p += 2;
      m_version_minor = *((uint16_t*)p);
      p += 2;
      //cout << "SoundFont v" << m_version_major << "." << m_version_minor << endl;
   }
   else
   if((ctmp[0] == 's') && (ctmp[1] == 'm') && (ctmp[2] == 'p') && (ctmp[3] == 'l'))
   {
      if(m_sample_data_pi16)
      {
         delete m_sample_data_pi16;
      }
      m_sample_data_pi16 = new(int16_t[s / 2]);

      for(uint32_t i = 0; i < (s / 2); i++)
      {
         m_sample_data_pi16[i] = *((int16_t*)p);
         p += 2;
      }

      p += s;
   }
   else
   if((ctmp[0] == 's') && (ctmp[1] == 'h') && (ctmp[2] == 'd') && (ctmp[3] == 'r'))
   {
      p = processSHDRChunk(p, s);
   }
   else
   {
      //cout << " not supported chunk" << endl;
      p += s;
   }

   return p;
}

void SoundFont::processSDTAList(uint8_t *p, uint32_t size)
{
   uint8_t *ps = p;
   //cout << " chunk: SDTA size:" << size << endl;
   do
   {
      p = processChunk(p);
   }
   while( (p - ps) < (size - 4));
}


void SoundFont::processPDTAList(uint8_t *p, uint32_t size)
{
   uint8_t *ps = p;
   //cout << " chunk: PDTA size:" << size << endl;
   do
   {
      p = processChunk(p);
   }
   while( (p - ps) < (size - 4));
}


uint8_t* SoundFont::processSHDRChunk(uint8_t *p, uint32_t size)
{
   uint8_t *ps = p;
   uint32_t i;
   uint8_t name[20];
   uint32_t start;
   uint32_t end;
   uint32_t loop_start;
   uint32_t loop_end;
   uint32_t samplerate;
   uint8_t orig_key;
   int8_t correction;
   uint16_t link;
   uint16_t type;
   uint32_t length;

   do
   {
      for(i = 0; i < 20; i++)
      {
         name[i] = *p;
         p++;
      }
      start = *((uint32_t*)p);
      p += 4;
      end = *((uint32_t*)p);
      p += 4;
      loop_start = *((uint32_t*)p) - start;
      p += 4;
      loop_end = *((uint32_t*)p) - start;
      p += 4;
      samplerate = *((uint32_t*)p);
      p += 4;
      orig_key = *p;
      p++;
      correction = *((int8_t*)p);
      p++;
      link = *((uint16_t*)p);
      p += 2;
      type = *((uint16_t*)p);
      p += 2;

      length = end - start;


      if((length != 0) && (type != 0x8001) && (type != 0x8002) && (type != 0x8004) && (type != 0x8008))
      {
         int16_t *sda = m_sample_data_pi16 + start;
         uint16_t *sd = new(uint16_t[length]);
         for(i = 0; i < length; i++)
         {
            uint16_t val;
            switch(type)
            {
               case 1: // mono
               case 2: // right
               case 4: // left
                  val = (uint16_t)((sda[i] / 16) + (4096 / 2)); // make it 12-bit and unsigned
                  break;
               case 8: // linked
                  val = (uint16_t)((sda[i] / 16) + (4096 / 2)); // make it 12-bit and unsigned
                  break;
               default:
                  val = (uint16_t)((sda[i] / 16) + (4096 / 2)); // make it 12-bit and unsigned
                  break;
            }
            sd[i] = val;
         }
         SoundFontSample sample(length, loop_start, loop_end, samplerate, sd, name, correction, orig_key);
         m_samples.push_back(sample);
         delete sd;
      }
   }
   while( (p - ps) < (size - 4));

   return p;
}





