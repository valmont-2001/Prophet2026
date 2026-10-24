#include "types.h"

#include <wx/wx.h>
#include <wx/string.h>
#include <wx/file.h>
#include <wx/spinctrl.h>
#ifdef _WIN32
    #include <windows.h>
#endif
#include <list>
#include <map>
using namespace std;
#include "midi.h"
#include "clickarea.h"
#include "keyboard.h"
#include "presetkeyboard.h"
#include "presetparam.h"
#include "stopwatch.h"
#include "proph2000.h"


PresetKeyboard::PresetKeyboard(wxWindow *parent, wxWindowID id, const wxPoint& pos, const wxSize& size,MyPresetParam *presetparamdlg,
                               Proph2000 *proph, MIDI *midi, uint8_t preset_u8) :
   Keyboard(parent, id, pos, size), m_presetparamdlg(presetparamdlg), m_proph(proph), 
   m_preset_u8(preset_u8), m_size(size), m_midi(midi)
{
}


PresetKeyboard::~PresetKeyboard()
{
}


void PresetKeyboard::setPreset(uint8_t preset_u8)
{
   m_preset_u8 = preset_u8;
   Refresh(true);
}


void PresetKeyboard::noteOn(void)
{
   if(m_presetparamdlg)
   {
      m_presetparamdlg->handleKeyboardNoteEvent(m_note);
   }
   if(m_midi)
   {
      if(!m_inhibit)
      {
         if(!m_midi->isMIDIopen())
         {
            m_midi->init();
         }   
         if(m_midi->isMIDIopen())
         {
            m_midi->sendNoteOn(m_note, m_velocity);
         }
      }
   }
}


void PresetKeyboard::noteOff(void)
{
   if(m_midi)
   {
      if(!m_inhibit)
      {
         if(m_midi->isMIDIopen())
         {
            m_midi->sendNoteOff(m_note, m_velocity);
         }
      }
   }
}

void PresetKeyboard::setupKeyboadInfo(void)
{
   switch(m_proph->m_preset_param_as[m_preset_u8].val_s.keyboard_mode)
   {
      case 0: // merge
         setupMergeMode();
         break;
      case 1: // split
         setupSplitMode();
         break;
      case 2: // right only
         setupRightOnlyMode();
         break;
      case 3: // left only
         setupLeftOnlyMode();
         break;
      case 4: // layer
         setupLayerMode();
         break;
      case 5: // positional crossfade
         setupLayerMode();
         break;
      case 6: // velocity switch
         setupLayerMode();
         break;
      case 7: // velocity crossfade
         setupLayerMode();
         break;
      case 8: // mod wheel crossfade
         setupLayerMode();
         break;
   }
}

void PresetKeyboard::setupSplitMode(void)
{
   uint8_t splitpoint = m_proph->m_preset_param_as[m_preset_u8].val_s.split_point;
   int8_t transpose = SOUND_NOT_MAPPED_VALUE;
   uint8_t prevkey;
   uint8_t start;
   uint8_t end;
   
   if(m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side)
   {
      start = 8;
      end = 16;
   }
   else
   {
      start = 0;
      end = 8;
   }

   list<pair<uint8_t, uint8_t> > map_layout;
   for(int i = start; i < end; i++)
   {
      //if(m_proph->getSampleWords(i))
      {
         pair<uint8_t, uint8_t> v;
         v.second = i;

         switch(m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number)
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
         
         //if(v.first < splitpoint)
         {
            if((transpose != SOUND_NOT_MAPPED_VALUE) && (v.first <= 126) && (m_proph->m_sound_param_as[i].val_s.sample_status & 0x10))
            {
               map_layout.push_back(v);
            }
         }
      }
   }
   map_layout.sort();
   
   bool ready = false;
   prevkey = 0;
   list<pair<uint8_t, uint8_t> > tmpmap;   
   list<pair<uint8_t, uint8_t> >::iterator map1itr = map_layout.begin();
   while((map1itr != map_layout.end()) && (!ready))
   {
      if((*map1itr).first < splitpoint)
      {
         tmpmap.push_back(*map1itr);
         prevkey = (*map1itr).first;
      }
      else
      {
         ready = true;
         (*map1itr).first = splitpoint - 1;
         if((*map1itr).first != prevkey)
         {
            tmpmap.push_back(*map1itr);
         }
      }
      map1itr++;
   }
   map_layout = tmpmap;

   if(m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side)
   {
      start = 8;
      end = 16;
   }
   else
   {
      start = 0;
      end = 8;
   }
   for(int i = start; i < end; i++)
   {
      //if(m_proph->getSampleWords(i))
      {
         pair<uint8_t, uint8_t> v;
         v.second = i;

         switch(m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number)
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
         
         if(v.first >= splitpoint)
         {
            if((transpose != SOUND_NOT_MAPPED_VALUE) && (v.first <= 126) && (m_proph->m_sound_param_as[i].val_s.sample_status & 0x10))
            {
               map_layout.push_back(v);
            }
         }
      }
   }

   map_layout.sort();

   resetKeyboardColours();

   prevkey = 0;
   bool setsplitpoint = false;
   list<pair<uint8_t, uint8_t> >::const_iterator map_itr = map_layout.begin();
   while(map_itr != map_layout.end())
   {
      uint16_t i;
      uint8_t note;
      wxColour keycol;

      if((*map_itr).second >= 8)
      {
         if(!setsplitpoint)
         {
            setsplitpoint = true;
            prevkey = splitpoint;
         }
      }

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
   wxString s = "S";
   addNoteText(splitpoint, s, *wxRED, false);
}

void PresetKeyboard::setupMergeMode(void)
{
   list<pair<uint8_t, uint8_t> > map_layout;
   int8_t transpose = SOUND_NOT_MAPPED_VALUE;
   uint8_t s;
   uint8_t e;

   if(m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side)
   {
      s = 8;
      e = 16;
   }
   else
   {
      s = 0;
      e = 8;
   }

   for(int i = s; i < e; i++)
   {
      //if(m_proph->getSampleWords(i))
      {
         pair<uint8_t, uint8_t> v;
         v.second = i;

         switch(m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number)
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
         if((transpose != SOUND_NOT_MAPPED_VALUE) && (v.first <= 126) && (m_proph->m_sound_param_as[i].val_s.sample_status & 0x10))
         {         
            map_layout.push_back(v);
         }
      }
   }

   if((m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side != m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side) ||
      (m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number != m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number))
   {
      if(m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side)
      {
         s = 8;
         e = 16;
      }
      else
      {
         s = 0;
         e = 8;
      }
      for(int i = s; i < e; i++)
      {
         //if(m_proph->getSampleWords(i))
         {
            pair<uint8_t, uint8_t> v;
            v.second = i;

            switch(m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number)
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
            if((transpose != SOUND_NOT_MAPPED_VALUE) && (v.first <= 126) && (m_proph->m_sound_param_as[i].val_s.sample_status & 0x10))
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

void PresetKeyboard::setupLeftOnlyMode(void)
{
   list<pair<uint8_t, uint8_t> > map_layout;
   int8_t transpose = SOUND_NOT_MAPPED_VALUE;
   uint8_t start;
   uint8_t end;

   if(m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side)
   {
      start = 8;
      end = 16;
   }
   else
   {
      start = 0;
      end = 8;
   }
   for(int i = start; i < end; i++)
   {
      //if(m_proph->getSampleWords(i))
      {
         pair<uint8_t, uint8_t> v;
         v.second = i;

         switch(m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number)
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
         if((transpose != SOUND_NOT_MAPPED_VALUE) && (v.first <= 126) && (m_proph->m_sound_param_as[i].val_s.sample_status & 0x10))
         {                  
            map_layout.push_back(v);
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


void PresetKeyboard::setupRightOnlyMode(void)
{
   list<pair<uint8_t, uint8_t> > map_layout;
   int8_t transpose = SOUND_NOT_MAPPED_VALUE;

   uint8_t start;
   uint8_t end;

   if(m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side)
   {
      start = 8;
      end = 16;
   }
   else
   {
      start = 0;
      end = 8;
   }

   for(int i = start; i < end; i++)
   {
      //if(m_proph->getSampleWords(i))
      {
         pair<uint8_t, uint8_t> v;
         v.second = i;

         switch(m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number)
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
         if((transpose != SOUND_NOT_MAPPED_VALUE) && (v.first <= 126) && (m_proph->m_sound_param_as[i].val_s.sample_status & 0x10))
         {                  
            map_layout.push_back(v);
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

void PresetKeyboard::setupLayerMode(void)
{
   list<pair<uint8_t, uint8_t> > map_layout;
   int8_t transpose = SOUND_NOT_MAPPED_VALUE;
   uint8_t start;
   uint8_t end;

   if(m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side)
   {
      start = 8;
      end = 16;
   }
   else
   {
      start = 0;
      end = 8;
   }

   for(int i = start; i < end; i++)
   {
      //if(m_proph->getSampleWords(i))
      {
         pair<uint8_t, uint8_t> v;
         v.second = i;

         switch(m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number)
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
         if((transpose != SOUND_NOT_MAPPED_VALUE) && (v.first <= 126) && (m_proph->m_sound_param_as[i].val_s.sample_status & 0x10))
         {                  
            map_layout.push_back(v);
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

   // -------------------------------------------------------------------------------------
   list<pair<uint8_t, uint8_t> > empty_layout;
   map_layout = empty_layout;

   if(m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side)
   {
      start = 8;
      end = 16;
   }
   else
   {
      start = 0;
      end = 8;
   }

   for(int i = start; i < end; i++)
   {
      //if(m_proph->getSampleWords(i))
      {
         pair<uint8_t, uint8_t> v;
         v.second = i;

         switch(m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number)
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
         if((transpose != SOUND_NOT_MAPPED_VALUE) && (v.first <= 126) && (m_proph->m_sound_param_as[i].val_s.sample_status & 0x10))
         {                  
            map_layout.push_back(v);
         }
      }
   }
   map_layout.sort();

   prevkey = 0;
   map_itr = map_layout.begin();
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
      }

      //wxLogMessage("  sample %d  %d - %d ", (*map_itr).second, prevkey, (*map_itr).first);

      wxString str;
      str.sprintf("%d", (*map_itr).second + 1);

      note = (*map_itr).first;
      if(note > KEYBOARD_MAX_KEY)
      {
         note = KEYBOARD_MAX_KEY;
      }
      addBlackNoteText(note, str, true);

      prevkey = note + 1;
      ++map_itr;
   }
}
