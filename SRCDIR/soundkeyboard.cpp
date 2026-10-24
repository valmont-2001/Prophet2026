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
#include "stopwatch.h"
#include "proph2000.h"
#include "soundparam.h"
#include "soundkeyboard.h"


SoundKeyboard::SoundKeyboard(wxWindow *parent, wxWindowID id, const wxPoint& pos, const wxSize& size, 
                             MySoundParam *soundparamdlg, Proph2000 *proph, uint8_t sound) :
   Keyboard(parent, id, pos, size), m_soundparamdlg(soundparamdlg), m_proph(proph), m_sound(sound),
   m_keyboard_edit_selection_e(MySoundParam::ROOT)
{
}


SoundKeyboard::~SoundKeyboard()
{
}

void SoundKeyboard::activateSound(uint8_t sound)
{
   m_sound = sound;
   Refresh(true);
}

void SoundKeyboard::noteOn(void)
{
   m_soundparamdlg->setTransposeOrigin(m_note);
}


void SoundKeyboard::noteOff(void)
{
}

void SoundKeyboard::rightClick(void)
{
   m_soundparamdlg->noteEvent(m_note);
}


void SoundKeyboard::setKeyboardEditSelection(MySoundParam::keyboard_edit_selection_te mode)
{
   m_keyboard_edit_selection_e = mode;
   Refresh(true);
}


void SoundKeyboard::setupKeyboadInfo(void)
{
//   uint8_t t;
   
   wxString s = "R";

   addNoteText(m_proph->m_sound_param_as[m_sound].val_s.root_key, s, *wxRED, false);

   switch(m_keyboard_edit_selection_e)
   {
      case MySoundParam::ROOT:
         if(m_sound < 8)
         {
            if(m_proph->m_sound_param_as[m_sound].val_s.transpose_map1 != SOUND_NOT_MAPPED_VALUE)
            {
               s = "1";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map1, s, *wxRED, false);
            }
            else
            {
               s = "";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map1, s, *wxRED, false);
            }

            if(m_proph->m_sound_param_as[m_sound].val_s.transpose_map2 != SOUND_NOT_MAPPED_VALUE)
            {
               s = "2";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map2, s, *wxRED, false);
            }
            else
            {
               s = "";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map2, s, *wxRED, false);
            }

            if(m_proph->m_sound_param_as[m_sound].val_s.transpose_map3 != SOUND_NOT_MAPPED_VALUE)
            {
               s = "3";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map3, s, *wxRED, false);
            }
            else
            {
               s = "";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map3, s, *wxRED, false);
            }

            if(m_proph->m_sound_param_as[m_sound].val_s.transpose_map4 != SOUND_NOT_MAPPED_VALUE)
            {
               s = "4";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map4, s, *wxRED, false);
            }
            else
            {
               s = "";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map4, s, *wxRED, false);
            }

            if(m_proph->m_sound_param_as[m_sound].val_s.transpose_map5 != SOUND_NOT_MAPPED_VALUE)
            {
               s = "5";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map5, s, *wxRED, false);
            }
            else
            {
               s = "";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map5, s, *wxRED, false);
            }

            if(m_proph->m_sound_param_as[m_sound].val_s.transpose_map6 != SOUND_NOT_MAPPED_VALUE)
            {
               s = "6";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map6, s, *wxRED, false);
            }
            else
            {
               s = "";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map6, s, *wxRED, false);
            }

            if(m_proph->m_sound_param_as[m_sound].val_s.transpose_map7 != SOUND_NOT_MAPPED_VALUE)
            {
               s = "7";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map7, s, *wxRED, false);
            }
            else
            {
               s = "";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map7, s, *wxRED, false);
            }

            if(m_proph->m_sound_param_as[m_sound].val_s.transpose_map8 != SOUND_NOT_MAPPED_VALUE)
            {
               s = "8";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map8, s, *wxRED, false);
            }
            else
            {
               s = "";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map8, s, *wxRED, false);
            }
         }
         else
         {
/*            addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map1, wxString(wxT("9")), *wxRED, false);
            addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map2, wxString(wxT("A")), *wxRED, false);
            addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map3, wxString(wxT("B")), *wxRED, false);
            addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map4, wxString(wxT("C")), *wxRED, false);
            addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map5, wxString(wxT("D")), *wxRED, false);
            addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map6, wxString(wxT("E")), *wxRED, false);
            addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map7, wxString(wxT("F")), *wxRED, false);
            addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map8, wxString(wxT("G")), *wxRED, false);
*/
            if(m_proph->m_sound_param_as[m_sound].val_s.transpose_map1 != SOUND_NOT_MAPPED_VALUE)
            {
               s = "9";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map1, s, *wxRED, false);
            }
            else
            {
               s = "";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map1, s, *wxRED, false);
            }

            if(m_proph->m_sound_param_as[m_sound].val_s.transpose_map2 != SOUND_NOT_MAPPED_VALUE)
            {
               s = "A";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map2, s, *wxRED, false);
            }
            else
            {
               s = "";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map2, s, *wxRED, false);
            }

            if(m_proph->m_sound_param_as[m_sound].val_s.transpose_map3 != SOUND_NOT_MAPPED_VALUE)
            {
               s = "B";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map3, s, *wxRED, false);
            }
            else
            {
               s = "";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map3, s, *wxRED, false);
            }

            if(m_proph->m_sound_param_as[m_sound].val_s.transpose_map4 != SOUND_NOT_MAPPED_VALUE)
            {
               s = "C";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map4, s, *wxRED, false);
            }
            else
            {
               s = "";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map4, s, *wxRED, false);
            }

            if(m_proph->m_sound_param_as[m_sound].val_s.transpose_map5 != SOUND_NOT_MAPPED_VALUE)
            {
               s = "D";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map5, s, *wxRED, false);
            }
            else
            {
               s = "";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map5, s, *wxRED, false);
            }

            if(m_proph->m_sound_param_as[m_sound].val_s.transpose_map6 != SOUND_NOT_MAPPED_VALUE)
            {
               s = "E";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map6, s, *wxRED, false);
            }
            else
            {
               s = "";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map6, s, *wxRED, false);
            }

            if(m_proph->m_sound_param_as[m_sound].val_s.transpose_map7 != SOUND_NOT_MAPPED_VALUE)
            {
               s = "F";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map7, s, *wxRED, false);
            }
            else
            {
               s = "";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map7, s, *wxRED, false);
            }

            if(m_proph->m_sound_param_as[m_sound].val_s.transpose_map8 != SOUND_NOT_MAPPED_VALUE)
            {
               s = "G";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map8, s, *wxRED, false);
            }
            else
            {
               s = "";
               addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map8, s, *wxRED, false);
            }
         }
         break;
      case MySoundParam::HIKEY1:
         s = "H";
         addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map1, s, *wxRED, false);
         s = "O";
         addNoteText(m_proph->m_sound_param_as[m_sound].val_s.root_key + (int8_t)m_proph->m_sound_param_as[m_sound].val_s.transpose_map1, s, *wxRED, false);
         break;
      case MySoundParam::HIKEY2:
         s = "H";
         addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map2, s, *wxRED, false);
         s = "O";
         addNoteText(m_proph->m_sound_param_as[m_sound].val_s.root_key + (int8_t)m_proph->m_sound_param_as[m_sound].val_s.transpose_map2, s, *wxRED, false);
         break;
      case MySoundParam::HIKEY3:
         s = "H";
         addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map3, s, *wxRED, false);
         s = "O";
         addNoteText(m_proph->m_sound_param_as[m_sound].val_s.root_key + (int8_t)m_proph->m_sound_param_as[m_sound].val_s.transpose_map3, s, *wxRED, false);
         break;
      case MySoundParam::HIKEY4:
         s = "H";
         addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map4, s, *wxRED, false);
         s = "O";
         addNoteText(m_proph->m_sound_param_as[m_sound].val_s.root_key + (int8_t)m_proph->m_sound_param_as[m_sound].val_s.transpose_map4, s, *wxRED, false);
         break;
      case MySoundParam::HIKEY5:
         s = "H";
         addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map5, s, *wxRED, false);
         s = "O";
         addNoteText(m_proph->m_sound_param_as[m_sound].val_s.root_key + (int8_t)m_proph->m_sound_param_as[m_sound].val_s.transpose_map5, s, *wxRED, false);
         break;
      case MySoundParam::HIKEY6:
         s = "H";
         addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map6, s, *wxRED, false);
         s = "O";
         addNoteText(m_proph->m_sound_param_as[m_sound].val_s.root_key + (int8_t)m_proph->m_sound_param_as[m_sound].val_s.transpose_map6, s, *wxRED, false);
         break;
      case MySoundParam::HIKEY7:
         s = "H";
         addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map7, s, *wxRED, false);
         s = "O";
         addNoteText(m_proph->m_sound_param_as[m_sound].val_s.root_key + (int8_t)m_proph->m_sound_param_as[m_sound].val_s.transpose_map7, s, *wxRED, false);
         break;
      case MySoundParam::HIKEY8:
         s = "H";
         addNoteText(m_proph->m_sound_param_as[m_sound].val_s.hi_key_map8, s, *wxRED, false);
         s = "O";
         addNoteText(m_proph->m_sound_param_as[m_sound].val_s.root_key + (int8_t)m_proph->m_sound_param_as[m_sound].val_s.transpose_map8, s, *wxRED, false);
         break;
   }
}




