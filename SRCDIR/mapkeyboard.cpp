#include "types.h"

#include <wx/wx.h>
#include <wx/string.h>
#include <wx/file.h>
#include <wx/spinctrl.h>

#ifdef _WIN32
    #include <windows.h>
#endif
#include <map>
#include <list>
using namespace std;
#include "midi.h"
#include "clickarea.h"
#include "keyboard.h"
#include "mapkeyboard.h"
#include "mapparam.h"
#include "stopwatch.h"
#include "proph2000.h"


MapKeyboard::MapKeyboard(wxWindow *parent, wxWindowID id, const wxPoint& pos, const wxSize& size, MyMapParam *mapparamdlg,
                               Proph2000 *proph, uint8_t map_u8) :
   Keyboard(parent, id, pos, size), m_mapparamdlg(mapparamdlg), m_proph(proph), 
   m_map_u8(map_u8), m_size(size)
{
}


MapKeyboard::~MapKeyboard()
{
}


void MapKeyboard::activateMap(uint8_t map_u8)
{
   m_map_u8 = map_u8;
   Refresh(true);
}


void MapKeyboard::noteOn(void)
{
   list<pair<uint8_t, uint8_t> > map_layout;
   int8_t transpose = SOUND_NOT_MAPPED_VALUE;
   if(m_map_u8 <= 7)
   {
      for(int i = 0; i < 8; i++)
      {
         //if(m_proph->getSampleWords(i))
         {
            pair<uint8_t, uint8_t> v;
            v.second = i;

            switch(m_map_u8)
            {
               case 0:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map1;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map1;
                  break;
               case 1:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map2;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map2;
                  break;
               case 2:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map3;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map3;
                  break;
               case 3:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map4;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map4;
                  break;
               case 4:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map5;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map5;
                  break;
               case 5:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map6;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map6;
                  break;
               case 6:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map7;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map7;
                  break;
               case 7:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map8;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map8;
                  break;
            }
            if(transpose != SOUND_NOT_MAPPED_VALUE)
            {                     
               map_layout.push_back(v);
            }
         }
      }
   }
   else
   {
      for(int i = 8; i < 16; i++)
      {
         //if(m_proph->getSampleWords(i))
         {
            pair<uint8_t, uint8_t> v;
            v.second = i;

            switch(m_map_u8)
            {
               case 8:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map1;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map1;
                  break;
               case 9:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map2;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map2;
                  break;
               case 10:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map3;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map3;
                  break;
               case 11:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map4;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map4;
                  break;
               case 12:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map5;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map5;
                  break;
               case 13:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map6;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map6;
                  break;
               case 14:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map7;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map7;
                  break;
               case 15:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map8;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map8;
                  break;
            }
            if(transpose != SOUND_NOT_MAPPED_VALUE)
            {                     
               map_layout.push_back(v);
            }
         }
      }
   }
   map_layout.sort();

   uint8_t prevkey = 0;
   list<pair<uint8_t, uint8_t> >::const_iterator map_itr = map_layout.begin();
   while(map_itr != map_layout.end())
   {
      uint16_t i;
      uint8_t note;

      for(i = prevkey; i <= (*map_itr).first; i++)
      {
         if(m_note == i)
         {
            m_mapparamdlg->showScaledSampleValues((*map_itr).second);
         }
      }

      note = (*map_itr).first;
      if(note > KEYBOARD_MAX_KEY)
      {
         note = KEYBOARD_MAX_KEY;
      }

      prevkey = note + 1;
      ++map_itr;
   }
}


void MapKeyboard::noteOff(void)
{
}

void MapKeyboard::setupKeyboadInfo(void)
{
   list<pair<uint8_t, uint8_t> > map_layout;
   int8_t transpose = SOUND_NOT_MAPPED_VALUE;
   if(m_map_u8 <= 7)
   {
      for(int i = 0; i < 8; i++)
      {
         //if(m_proph->getSampleWords(i))
         {
            pair<uint8_t, uint8_t> v;
            v.second = i;

            switch(m_map_u8)
            {
               case 0:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map1;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map1;
                  break;
               case 1:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map2;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map2;
                  break;
               case 2:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map3;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map3;
                  break;
               case 3:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map4;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map4;
                  break;
               case 4:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map5;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map5;
                  break;
               case 5:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map6;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map6;
                  break;
               case 6:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map7;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map7;
                  break;
               case 7:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map8;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map8;
                  break;
            }
            if(transpose != SOUND_NOT_MAPPED_VALUE)
            {                     
               map_layout.push_back(v);
            }
         }
      }
   }
   else
   {
      for(int i = 8; i < 16; i++)
      {
         //if(m_proph->getSampleWords(i))
         {
            pair<uint8_t, uint8_t> v;
            v.second = i;

            switch(m_map_u8)
            {
               case 8:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map1;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map1;
                  break;
               case 9:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map2;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map2;
                  break;
               case 10:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map3;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map3;
                  break;
               case 11:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map4;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map4;
                  break;
               case 12:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map5;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map5;
                  break;
               case 13:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map6;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map6;
                  break;
               case 14:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map7;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map7;
                  break;
               case 15:
                  v.first = m_proph->m_sound_param_as[i].val_s.hi_key_map8;
                  transpose = (int8_t)m_proph->m_sound_param_as[i].val_s.transpose_map8;
                  break;
            }
            if(transpose != SOUND_NOT_MAPPED_VALUE)
            {                     
               map_layout.push_back(v);
            }
         }
      }
   }
   map_layout.sort();


   resetKeyboardColours();

   uint8_t prevkey = 0;
   list<pair<uint8_t, uint8_t> >::const_iterator map_itr = map_layout.begin();
   while(map_itr != map_layout.end())
   {
      uint16_t i;
      uint8_t note;
      wxColour keycol;

      for(i = prevkey; i <= (*map_itr).first; i++)
      {
         // setup colours
         switch((*map_itr).second)
         {
            case 0:
               keycol = SOUND1_COLOUR;
               break;
            case 1:
               keycol = SOUND2_COLOUR;
               break;
            case 2:
               keycol = SOUND3_COLOUR;
               break;
            case 3:
               keycol = SOUND4_COLOUR;
               break;
            case 4:
               keycol = SOUND5_COLOUR;
               break;
            case 5:
               keycol = SOUND6_COLOUR;
               break;
            case 6:
               keycol = SOUND7_COLOUR;
               break;
            case 7:
               keycol = SOUND8_COLOUR;
               break;
            case 8:
               keycol = SOUND9_COLOUR;
               break;
            case 9:
               keycol = SOUND10_COLOUR;
               break;
            case 10:
               keycol = SOUND11_COLOUR;
               break;
            case 11:
               keycol = SOUND12_COLOUR;
               break;
            case 12:
               keycol = SOUND13_COLOUR;
               break;
            case 13:
               keycol = SOUND14_COLOUR;
               break;
            case 14:
               keycol = SOUND15_COLOUR;
               break;
            case 15:
               keycol = SOUND16_COLOUR;
               break;
         }
         if(isBlackKey(i))
         {
            wxColour dim = SOUND_BLACK_KEY_COLOUR_DIM;
            int16_t r;
            int16_t g;
            int16_t b;
      
            r = keycol.Red() - dim.Red();
            g = keycol.Green() - dim.Green();
            b = keycol.Blue() - dim.Blue();

            if(r < 0)
            {
               r = 0;
            }
            if(g < 0)
            {
               g = 0;
            }
            if(b < 0)
            {
               b = 0;
            }

            keycol = wxColour(r, g, b);
         }
         setUpperNoteColour(i, keycol);
         setLowerNoteColour(i, keycol);
      }


      //wxLogMessage("  sample %d  %d - %d ", (*map_itr).second, prevkey, (*map_itr).first);

      wxString str;
      str.sprintf("%d", (*map_itr).second + 1);

      note = (*map_itr).first;
      if(note > KEYBOARD_MAX_KEY)
      {
         note = KEYBOARD_MAX_KEY;
      }
      addBlackNoteText(note, str, false);

      prevkey = note + 1;
      ++map_itr;
   }
}


