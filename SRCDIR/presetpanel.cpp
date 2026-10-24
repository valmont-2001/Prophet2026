#include "types.h"


#include <wx/wx.h>
#include <wx/string.h>
#include <wx/file.h>
#include <wx/spinctrl.h>

#include "GUILayout.h"
#include "main.h"
#include "presetpanel.h"
#include "stopwatch.h"
#include "stopwatch.h"
#include "proph2000.h"
#include <map>
#include <list>
using namespace std;
#include "presetcopydlg.h"
#include "presetparam.h"


	/**
	 * C++ version 0.4 char* style "itoa":
	 * Written by Lukás Chmela
	 * Released under GPLv3.
	 */
	char* my_itoa(int value, char* result, int base) {
		// check that the base if valid
		if (base < 2 || base > 36) { *result = '\0'; return result; }
	
		char* ptr = result, *ptr1 = result, tmp_char;
		int tmp_value;
	
		do {
			tmp_value = value;
			value /= base;
			*ptr++ = "ZYXWVUTSRQPONMLKJIHGFEDCBA9876543210123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" [35 + (tmp_value - value * base)];
		} while ( value );
	
		// Apply negative sign
		if (tmp_value < 0) *ptr++ = '-';
		*ptr-- = '\0';
		while(ptr1 < ptr) {
			tmp_char = *ptr;
			*ptr--= *ptr1;
			*ptr1++ = tmp_char;
		}
		return result;
	}
	
	

PresetPanelImpl::PresetPanelImpl(wxWindow *parent, MyPanel *topframe, Proph2000 *proph, uint8_t preset_u8, MyPresetParam *presetparam) :
   PresetPanel(parent),
   m_topframe(topframe), m_proph(proph), m_preset_u8(preset_u8), m_presetparam(presetparam)
{

#ifdef __WXMAC__ //130205
    m_lfo_freq->ToggleWindowStyle(wxBORDER_SUNKEN);
    m_lfo_init_amount->ToggleWindowStyle(wxBORDER_SUNKEN);
    m_lfo_vel_sensitivity->ToggleWindowStyle(wxBORDER_SUNKEN);
    m_arp_rate->ToggleWindowStyle(wxBORDER_SUNKEN);
    m_transpose->ToggleWindowStyle(wxBORDER_SUNKEN);
    m_vel_switch_threshold->ToggleWindowStyle(wxBORDER_SUNKEN);
    m_pitchwheel_range->ToggleWindowStyle(wxBORDER_SUNKEN);
    m_stack_delay->ToggleWindowStyle(wxBORDER_SUNKEN);
    m_stack_detune->ToggleWindowStyle(wxBORDER_SUNKEN);

    SetSize(wxSize(GetSize().GetWidth(), GetSize().GetHeight() + 85));
    SetMinSize(wxSize(GetMinSize().GetWidth(), GetMinSize().GetHeight() + 85));
    SetMaxSize(wxSize(GetMaxSize().GetWidth(), GetMaxSize().GetHeight() + 85));
#endif
    
   m_left_map_selection->AppendString(wxT("Map 1"));
   m_left_map_selection->AppendString(wxT("Map 2"));
   m_left_map_selection->AppendString(wxT("Map 3"));
   m_left_map_selection->AppendString(wxT("Map 4"));
   m_left_map_selection->AppendString(wxT("Map 5"));
   m_left_map_selection->AppendString(wxT("Map 6"));
   m_left_map_selection->AppendString(wxT("Map 7"));
   m_left_map_selection->AppendString(wxT("Map 8"));
   m_left_map_selection->AppendString(wxT("Map 9"));
   m_left_map_selection->AppendString(wxT("Map A"));
   m_left_map_selection->AppendString(wxT("Map B"));
   m_left_map_selection->AppendString(wxT("Map C"));
   m_left_map_selection->AppendString(wxT("Map D"));
   m_left_map_selection->AppendString(wxT("Map E"));
   m_left_map_selection->AppendString(wxT("Map F"));
   m_left_map_selection->AppendString(wxT("Map G"));

   m_right_map_selection->AppendString(wxT("Map 1"));
   m_right_map_selection->AppendString(wxT("Map 2"));
   m_right_map_selection->AppendString(wxT("Map 3"));
   m_right_map_selection->AppendString(wxT("Map 4"));
   m_right_map_selection->AppendString(wxT("Map 5"));
   m_right_map_selection->AppendString(wxT("Map 6"));
   m_right_map_selection->AppendString(wxT("Map 7"));
   m_right_map_selection->AppendString(wxT("Map 8"));
   m_right_map_selection->AppendString(wxT("Map 9"));
   m_right_map_selection->AppendString(wxT("Map A"));
   m_right_map_selection->AppendString(wxT("Map B"));
   m_right_map_selection->AppendString(wxT("Map C"));
   m_right_map_selection->AppendString(wxT("Map D"));
   m_right_map_selection->AppendString(wxT("Map E"));
   m_right_map_selection->AppendString(wxT("Map F"));
   m_right_map_selection->AppendString(wxT("Map G"));

   m_vibrato->AppendString(wxT("Off"));
   m_vibrato->AppendString(wxT("LFO"));
   m_vibrato->AppendString(wxT("Inverse LFO"));
   m_lfo_filt->AppendString(wxT("Off"));
   m_lfo_filt->AppendString(wxT("LFO"));
   m_lfo_filt->AppendString(wxT("Inverse LFO"));

   m_lfo_amp->AppendString(wxT("Off"));
   m_lfo_amp->AppendString(wxT("LFO"));
   m_lfo_amp->AppendString(wxT("Inverse LFO"));

   m_keyboard_mode->AppendString(wxT("Merge"));
   m_keyboard_mode->AppendString(wxT("Split"));
   m_keyboard_mode->AppendString(wxT("Right only"));
   m_keyboard_mode->AppendString(wxT("Left only"));
   m_keyboard_mode->AppendString(wxT("Layer"));
   m_keyboard_mode->AppendString(wxT("Positional Crossfade"));
   m_keyboard_mode->AppendString(wxT("Velocity Switch"));
   m_keyboard_mode->AppendString(wxT("Velocity Crossfade"));
   m_keyboard_mode->AppendString(wxT("Mod Wheel Crossfade"));

   m_stack_voices->AppendString(wxT("1"));
   m_stack_voices->AppendString(wxT("2"));
   m_stack_voices->AppendString(wxT("4"));
   m_stack_voices->AppendString(wxT("8"));

   m_arp_mode->AppendString(wxT("Up/Down"));
   m_arp_mode->AppendString(wxT("Up"));
   m_arp_mode->AppendString(wxT("Down"));
   m_arp_mode->AppendString(wxT("Assign"));
   m_arp_mode->AppendString(wxT("Random"));

   m_arp_repeats->AppendString(wxT("1"));
   m_arp_repeats->AppendString(wxT("2"));
   m_arp_repeats->AppendString(wxT("3"));
   m_arp_repeats->AppendString(wxT("4"));
   m_arp_repeats->AppendString(wxT("8"));
   m_arp_repeats->AppendString(wxT("16"));
   m_arp_repeats->AppendString(wxT("Random"));

   m_arp_oct->AppendString(wxT("1"));
   m_arp_oct->AppendString(wxT("2"));
   m_arp_oct->AppendString(wxT("3"));

   m_arp_latch_mode->AppendString(wxT("Normal"));
   m_arp_latch_mode->AppendString(wxT("Auto Latch"));
   m_arp_latch_mode->AppendString(wxT("Extend"));

   m_arp_split_type->AppendString(wxT("Off"));
   m_arp_split_type->AppendString(wxT("Below Split"));
   m_arp_split_type->AppendString(wxT("Above Split"));

   m_midi_mode->AppendString(wxT("Mode 0"));
   m_midi_mode->AppendString(wxT("Mode 1"));
   m_midi_mode->AppendString(wxT("Mode 3A"));
   m_midi_mode->AppendString(wxT("Mode 3B"));
   m_midi_mode->AppendString(wxT("Mode 4"));
   m_midi_mode->AppendString(wxT("Mode 1."));
   m_midi_mode->AppendString(wxT("Mode 3.A"));
   m_midi_mode->AppendString(wxT("Mode 3.B"));
   m_midi_mode->AppendString(wxT("Mode 4."));

   uint8_t i;
   for(i = 0; i < 16; i++)
   {
      wxString str;
      str.sprintf(wxT("%d"), i + 1);
      m_midi_left_ch->AppendString(str);
   }
   for(i = 0; i < 16; i++)
   {
      wxString str;
      str.sprintf(wxT("%d"), i + 1);
      m_midi_right_ch->AppendString(str);
   }
 //  displaySettings();
 //  updateGUI();

   deselectAllPresetButtons();
   m_select_preset1->SetValue(true);

   m_using_snd_1->SetValue(false);
   m_using_snd_2->SetValue(false);
   m_using_snd_3->SetValue(false);
   m_using_snd_4->SetValue(false);
   m_using_snd_5->SetValue(false);
   m_using_snd_6->SetValue(false);
   m_using_snd_7->SetValue(false);
   m_using_snd_8->SetValue(false);
   m_using_snd_9->SetValue(false);
   m_using_snd_10->SetValue(false);
   m_using_snd_11->SetValue(false);
   m_using_snd_12->SetValue(false);
   m_using_snd_13->SetValue(false);
   m_using_snd_14->SetValue(false);
   m_using_snd_15->SetValue(false);
   m_using_snd_16->SetValue(false);

   activatePreset(0);
}


PresetPanelImpl::~PresetPanelImpl()
{
}


void PresetPanelImpl::activatePreset(uint8_t preset_u8)
{
   m_preset_u8 = preset_u8;

   deselectAllPresetButtons();
   switch(preset_u8)
   {
      case 0:
         m_select_preset1->SetValue(true);
      break;
      case 1:
         m_select_preset2->SetValue(true);
      break;
      case 2:
         m_select_preset3->SetValue(true);
      break;
      case 3:
         m_select_preset4->SetValue(true);
      break;
      case 4:
         m_select_preset5->SetValue(true);
      break;
      case 5:
         m_select_preset6->SetValue(true);
      break;
      case 6:
         m_select_preset7->SetValue(true);
      break;
      case 7:
         m_select_preset8->SetValue(true);
      break;
      case 8:
         m_select_preset9->SetValue(true);
      break;
      case 9:
         m_select_preset10->SetValue(true);
      break;
      case 10:
         m_select_preset11->SetValue(true);
      break;
      case 11:
         m_select_preset12->SetValue(true);
      break;
   }
   displaySettings();
   updateGUI();
}

wxString PresetPanelImpl::getNote(uint8_t number_u8)
{
   wxString retval;
   wxString t;

   switch(number_u8 % 12)
   {
      case 0:
         retval = wxT("C");
         break;
      case 1:
         retval = wxT("C#");
         break;
      case 2:
         retval = wxT("D");
         break;
      case 3:
         retval = wxT("D#");
         break;
      case 4:
         retval = wxT("E");
         break;
      case 5:
         retval = wxT("F");
         break;
      case 6:
         retval = wxT("F#");
         break;
      case 7:
         retval = wxT("G");
         break;
      case 8:
         retval = wxT("G#");
         break;
      case 9:
         retval = wxT("A");
         break;
      case 10:
         retval = wxT("A#");
         break;
      case 11:
         retval = wxT("B");
         break;
   }

   t.sprintf(wxT("%d"), (number_u8 - 24) / 12);
   retval += t;

   return retval;
}


void PresetPanelImpl::OnSplitPoint(wxCommandEvent& event)
{
   uint8_t note;
   if(convertStringToNote(m_split_point->GetValue(), &note))
   {
      m_proph->m_preset_param_as[m_preset_u8].val_s.split_point = note;
      m_proph->updateParamBytesFromStruct();
      m_topframe->updateGUI();
      if(m_topframe->getOnlineUpdateActive())
      {
         if(m_proph->transferPreset2Proph(m_preset_u8))
         {
            m_topframe->transferStarted();
         }
      }
   }
}

void PresetPanelImpl::OnArpSplitPoint(wxCommandEvent& event)
{
   uint8_t note;
   if(convertStringToNote(m_arp_split_point->GetValue(), &note))
   {
      m_proph->m_preset_param_as[m_preset_u8].val_s.arp_split_point = note;
      m_proph->updateParamBytesFromStruct();
      m_topframe->updateGUI();
      if(m_topframe->getOnlineUpdateActive())
      {
         if(m_proph->transferPreset2Proph(m_preset_u8))
         {
            m_topframe->transferStarted();
         }
      }
   }
}


bool PresetPanelImpl::convertStringToNote(wxString str, uint8_t *note_pu8)
{
   uint8_t note = 0;
   bool retval = true;
   uint8_t pos = 0;
   str.MakeUpper();

   if(str.find(wxT("C#")) == 0)
   {
      note = 1;
      pos = 2;
   }else
   if(str.find(wxT("C")) == 0)
   {
      note = 0;
      pos = 1;
   }else
   if(str.find(wxT("D#")) == 0)
   {
      note = 3;
      pos = 2;
   }else
   if(str.find(wxT("D")) == 0)
   {
      note = 2;
      pos = 1;
   }else
   if(str.find(wxT("E")) == 0)
   {
      note = 4;
      pos = 1;
   }else
   if(str.find(wxT("F#")) == 0)
   {
      note = 6;
      pos = 2;
   }else
   if(str.find(wxT("F")) == 0)
   {
      note = 5;
      pos = 1;
   }else
   if(str.find(wxT("G#")) == 0)
   {
      note = 8;
      pos = 2;
   }else
   if(str.find(wxT("G")) == 0)
   {
      note = 7;
      pos = 1;
   }else
   if(str.find(wxT("A#")) == 0)
   {
      note = 10;
      pos = 2;
   }else
   if(str.find(wxT("A")) == 0)
   {
      note = 9;
      pos = 1;
   }else
   if(str.find(wxT("B")) == 0)
   {
      note = 11;
      pos = 1;
   }
   else
   {
      retval = false;
   }

   str = str.substr(pos);
   if(str != wxT(""))
   {
      long octave;
      str.ToLong(&octave);
      if((octave >= -3) && (octave <= 8))
      {
         note += ((octave * 12) + 24);
      }
      else
      {
         retval = false;
      }
   }
   else
   {
      retval = false;
   }

   *note_pu8 = note;

   return retval;
}

void PresetPanelImpl::displaySettings(void)
{
   // Sliders
   m_lfo_freq->SetValue(m_proph->m_preset_param_as[m_preset_u8].val_s.lfo_freq);
   m_lfo_init_amount->SetValue(m_proph->m_preset_param_as[m_preset_u8].val_s.lfo_init_amount);
   m_lfo_vel_sensitivity->SetValue((int8_t)(m_proph->m_preset_param_as[m_preset_u8].val_s.lfo_vel_sensitivity - 0x80));
   m_transpose->SetValue((int8_t)(m_proph->m_preset_param_as[m_preset_u8].val_s.transpose));
   m_vel_switch_threshold->SetValue(m_proph->m_preset_param_as[m_preset_u8].val_s.vel_switch_threshold);
   m_stack_delay->SetValue(m_proph->m_preset_param_as[m_preset_u8].val_s.stack_delay);
   m_stack_detune->SetValue(m_proph->m_preset_param_as[m_preset_u8].val_s.stack_detune);
   m_arp_rate->SetValue(m_proph->m_preset_param_as[m_preset_u8].val_s.arp_rate);
   m_pitchwheel_range->SetValue(m_proph->m_preset_param_as[m_preset_u8].val_s.pitchwheel_range);
}

void PresetPanelImpl::updateGUI(void)
{
   wxString str;
   uint8_t t_u8;


   switch(m_proph->m_preset_param_as[m_preset_u8].val_s.keyboard_mode)
   {
      case 0: // merge
         updateUsedSounds(m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side, m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number);
		   m_left_map_selector->SetValue(true);
         updateUsedSounds(m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side, m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number);
		   m_right_map_selector->SetValue(true);
         break;
      case 1: // split
         updateUsedSounds(m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side, m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number);
		   m_left_map_selector->SetValue(true);
		   updateUsedSounds(m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side, m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number);
		   m_right_map_selector->SetValue(true);
         break;
      case 2: // right only
		   m_left_map_selector->SetValue(false);
         updateUsedSounds(m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side, m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number);
		   m_right_map_selector->SetValue(true);
         break;
      case 3: // left only
		   m_left_map_selector->SetValue(true);
		   updateUsedSounds(m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side, m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number);
		   m_right_map_selector->SetValue(false);
         break;
      case 4: // layer
         updateUsedSounds(m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side, m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number);
		   m_left_map_selector->SetValue(true);
         updateUsedSounds(m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side, m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number);
		   m_right_map_selector->SetValue(true);
         break;
      case 5: // positional crossfade
         updateUsedSounds(m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side, m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number);
		   m_left_map_selector->SetValue(true);
         updateUsedSounds(m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side, m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number);
		   m_right_map_selector->SetValue(true);
         break;
      case 6: // velocity switch
         updateUsedSounds(m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side, m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number);
		   m_left_map_selector->SetValue(true);
         updateUsedSounds(m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side, m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number);
		   m_right_map_selector->SetValue(true);
		 break;
      case 7: // velocity crossfade
         updateUsedSounds(m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side, m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number);
		   m_left_map_selector->SetValue(true);
         updateUsedSounds(m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side, m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number);
		   m_right_map_selector->SetValue(true);
         break;
      case 8: // mod wheel crossfade
         updateUsedSounds(m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side, m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number);
		   m_left_map_selector->SetValue(true);
         updateUsedSounds(m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side, m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number);
		   m_right_map_selector->SetValue(true);
         break;
   }


   switch(m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side)
   {
      case 0:
         m_left_map_selection->SetSelection(m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number);
         break;
      case 1:
         m_left_map_selection->SetSelection(m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number + 8);
         break;
   }

   switch(m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side)
   {
      case 0:
         m_right_map_selection->SetSelection(m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number);
         break;
      case 1:
         m_right_map_selection->SetSelection(m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number + 8);
         break;
   }

//   m_lfo_freq->SetValue(m_proph->m_preset_param_as[m_preset_u8].val_s.lfo_freq);
//   m_lfo_init_amount->SetValue(m_proph->m_preset_param_as[m_preset_u8].val_s.lfo_init_amount);
//   m_lfo_vel_sensitivity->SetValue((int8_t)(m_proph->m_preset_param_as[m_preset_u8].val_s.lfo_vel_sensitivity - 0x80));
   m_vibrato->SetSelection(m_proph->m_preset_param_as[m_preset_u8].val_s.vibrato);
   m_lfo_filt->SetSelection(m_proph->m_preset_param_as[m_preset_u8].val_s.lfo_filt);
   m_lfo_amp->SetSelection(m_proph->m_preset_param_as[m_preset_u8].val_s.lfo_amp);
   m_keyboard_mode->SetSelection(m_proph->m_preset_param_as[m_preset_u8].val_s.keyboard_mode);
   str = getNote(m_proph->m_preset_param_as[m_preset_u8].val_s.split_point);
   m_split_point->SetValue(str);
//   m_transpose->SetValue((int8_t)(m_proph->m_preset_param_as[m_preset_u8].val_s.transpose));
   if(m_proph->m_preset_param_as[m_preset_u8].val_s.dyn_alloc)
   {
      m_dyn_alloc->SetValue(true);
   }
   else
   {
      m_dyn_alloc->SetValue(false);
   }
//   m_vel_switch_threshold->SetValue(m_proph->m_preset_param_as[m_preset_u8].val_s.vel_switch_threshold);
   m_stack_voices->SetSelection(m_proph->m_preset_param_as[m_preset_u8].val_s.stack_voices & 0x03);
   if(m_proph->m_preset_param_as[m_preset_u8].val_s.stack_voices & 0x20)
   {
      m_stack_voices_preset_on->SetValue(true);
   }
   else
   {
      m_stack_voices_preset_on->SetValue(false);
   }
//   m_stack_delay->SetValue(m_proph->m_preset_param_as[m_preset_u8].val_s.stack_delay);
//   m_stack_detune->SetValue(m_proph->m_preset_param_as[m_preset_u8].val_s.stack_detune);
   m_arp_mode->SetSelection(m_proph->m_preset_param_as[m_preset_u8].val_s.arp_mode & 0x07);
   if(m_proph->m_preset_param_as[m_preset_u8].val_s.arp_mode & 0x10)
   {
      m_arp_preset_on->SetValue(true);
   }
   else
   {
      m_arp_preset_on->SetValue(false);
   }

   m_arp_oct->SetSelection(m_proph->m_preset_param_as[m_preset_u8].val_s.arp_oct - 1);
   m_arp_repeats->SetSelection(m_proph->m_preset_param_as[m_preset_u8].val_s.arp_repeats);
//  m_arp_rate->SetValue(m_proph->m_preset_param_as[m_preset_u8].val_s.arp_rate);
   m_arp_latch_mode->SetSelection(m_proph->m_preset_param_as[m_preset_u8].val_s.arp_latch_mode);
   m_arp_split_point->SetValue(getNote(m_proph->m_preset_param_as[m_preset_u8].val_s.arp_split_point));
   m_arp_split_type->SetSelection(m_proph->m_preset_param_as[m_preset_u8].val_s.arp_split_type);
//   m_pitchwheel_range->SetValue(m_proph->m_preset_param_as[m_preset_u8].val_s.pitchwheel_range);
   m_midi_mode->SetSelection(m_proph->m_preset_param_as[m_preset_u8].val_s.midi_mode);

   t_u8 = m_proph->m_preset_param_as[m_preset_u8].val_s.midi_opts;
   if(t_u8 & 0x01)
   {
      m_tx_mod_wheel->SetValue(true);
   }
   else
   {
      m_tx_mod_wheel->SetValue(false);
   }
   if(t_u8 & 0x02)
   {
      m_tx_pitch_wheel->SetValue(true);
   }
   else
   {
      m_tx_pitch_wheel->SetValue(false);
   }
   if(t_u8 & 0x04)
   {
      m_tx_program_chg->SetValue(true);
   }
   else
   {
      m_tx_program_chg->SetValue(false);
   }
   if(t_u8 & 0x08)
   {
      m_tx_mod_wheel_as_pressure->SetValue(true);
   }
   else
   {
      m_tx_mod_wheel_as_pressure->SetValue(false);
   }
   if(t_u8 & 0x10)
   {
      m_rx_mod_wheel->SetValue(true);
   }
   else
   {
      m_rx_mod_wheel->SetValue(false);
   }
   if(t_u8 & 0x20)
   {
      m_rx_pitch_wheel->SetValue(true);
   }
   else
   {
      m_rx_pitch_wheel->SetValue(false);
   }
   if(t_u8 & 0x40)
   {
      m_rx_program_chg->SetValue(true);
   }
   else
   {
      m_rx_program_chg->SetValue(false);
   }
   if(t_u8 & 0x80)
   {
      m_rx_pressure_as_mod_wheel->SetValue(true);
   }
   else
   {
      m_rx_pressure_as_mod_wheel->SetValue(false);
   }

   m_midi_right_ch->SetSelection(m_proph->m_preset_param_as[m_preset_u8].val_s.midi_right_ch);
   m_midi_left_ch->SetSelection(m_proph->m_preset_param_as[m_preset_u8].val_s.midi_left_ch);
}

void PresetPanelImpl::set_left_sound_buttons(bool side)
{
	if (side != RIGHT)
	{
		m_using_snd_1->SetLabel("1");
		m_using_snd_2->SetLabel("2");
		m_using_snd_3->SetLabel("3");
		m_using_snd_4->SetLabel("4");
		m_using_snd_5->SetLabel("5");
		m_using_snd_6->SetLabel("6");
		m_using_snd_7->SetLabel("7");
		m_using_snd_8->SetLabel("8");
	}
	else
	{
		m_using_snd_1->SetLabel("9");
		m_using_snd_2->SetLabel("10");
		m_using_snd_3->SetLabel("11");
		m_using_snd_4->SetLabel("12");
		m_using_snd_5->SetLabel("13");
		m_using_snd_6->SetLabel("14");
		m_using_snd_7->SetLabel("15");
		m_using_snd_8->SetLabel("16");
	}
}

void PresetPanelImpl::set_right_sound_buttons(bool side)
{
	if (side != RIGHT)
	{
		m_using_snd_9->SetLabel("1");
		m_using_snd_10->SetLabel("2");
		m_using_snd_11->SetLabel("3");
		m_using_snd_12->SetLabel("4");
		m_using_snd_13->SetLabel("5");
		m_using_snd_14->SetLabel("6");
		m_using_snd_15->SetLabel("7");
		m_using_snd_16->SetLabel("8");
	}
	else
	{
		m_using_snd_9->SetLabel("9");
		m_using_snd_10->SetLabel("10");
		m_using_snd_11->SetLabel("11");
		m_using_snd_12->SetLabel("12");
		m_using_snd_13->SetLabel("13");
		m_using_snd_14->SetLabel("14");
		m_using_snd_15->SetLabel("15");
		m_using_snd_16->SetLabel("16");
	}
}

void PresetPanelImpl::updateUsedSounds(uint8_t map_side, uint8_t map)
{
   uint8_t i;
   uint8_t s;
   uint8_t e;
   uint8_t t_u8;
   uint8_t left_map_value;
   uint8_t right_map_value;
   char map_number[33];
   char map_text[128];

/* Update MAP Button texts */ 
   left_map_value = m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side *10 + m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number + 1;
   if (left_map_value >= 10 ) left_map_value -= 2; // left map value contains the values between 1 and 17
   right_map_value = m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side *10 + m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number + 1;
   if (right_map_value >= 10 ) right_map_value -= 2; // right map value contains the values between 1 and 17

   sprintf(map_text,"Map %s",my_itoa(left_map_value,map_number,17)); // We count from Map 1 to Map G, so a base of 17 is needed 
   m_left_map_selector->SetLabel(map_text);

   sprintf(map_text,"Map %s",my_itoa(right_map_value,map_number,17));
   m_right_map_selector->SetLabel(map_text);

   

/* update Sound Buttons */

/*
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side = 1;
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number = 7;
*/

/* Deal with sound numbers displayed for each map */
   left_map_value -=1; // Get absolute Map value 0 - 15
   if (left_map_value < 8 ) // Left memory half contains sounds 0-7, right contains 8-15
	   set_left_sound_buttons(LEFT);
   else
	   set_left_sound_buttons(RIGHT);

   right_map_value -=1; // Get absolute Map value 0 - 15
   if (right_map_value < 8 )
	   set_right_sound_buttons(LEFT);
   else
	   set_right_sound_buttons(RIGHT);

/* Scan each sound whether active in left or right map and highlight accordingly*/

/* switch value of buttons to highlight active sounds */
// Do left map
       t_u8 = left_map_value;
		 if ( left_map_value < 8 )
		 {
			 s = 0;
			 e = 8;
		 }
		 else
		 {
			 s = 8;
			 e = 16;
		 }

         for(i = s; i < e; i++) // was 8
         {
            wxToggleButton *sound_active;
            switch(i)
            {
               case 0:
			   case 8:
                  sound_active = m_using_snd_1;
                  break;
               case 1:
			   case 9:
                  sound_active = m_using_snd_2;
                  break;
               case 2:
			   case 10:
                  sound_active = m_using_snd_3;
                  break;
               case 3:
			   case 11:
                  sound_active = m_using_snd_4;
                  break;
               case 4:
			   case 12:
                  sound_active = m_using_snd_5;
                  break;
               case 5:
			   case 13:
                  sound_active = m_using_snd_6;
                  break;
               case 6:
			   case 14:
                  sound_active = m_using_snd_7;
                  break;
               case 7:
			   case 15:
                  sound_active = m_using_snd_8;
                  break;
			   default:
                  sound_active = m_using_snd_1;
                  break;
            }
            switch(t_u8)
            {
               case 0:
			      case 8:
                  sound_active->SetValue((m_proph->m_sound_param_as[i].val_s.transpose_map1 != SOUND_NOT_MAPPED_VALUE) && (m_proph->m_sound_param_as[i].val_s.sample_status & 0x10));
				      break;
               case 1:
			      case 9:
                  sound_active->SetValue((m_proph->m_sound_param_as[i].val_s.transpose_map2 != SOUND_NOT_MAPPED_VALUE) && (m_proph->m_sound_param_as[i].val_s.sample_status & 0x10));
				      break;
               case 2:
			      case 10:
                  sound_active->SetValue((m_proph->m_sound_param_as[i].val_s.transpose_map3 != SOUND_NOT_MAPPED_VALUE) && (m_proph->m_sound_param_as[i].val_s.sample_status & 0x10));
				      break;
               case 3:
			      case 11:
                  sound_active->SetValue((m_proph->m_sound_param_as[i].val_s.transpose_map4 != SOUND_NOT_MAPPED_VALUE) && (m_proph->m_sound_param_as[i].val_s.sample_status & 0x10));
				      break;
               case 4:
			      case 12:
				      sound_active->SetValue((m_proph->m_sound_param_as[i].val_s.transpose_map5 != SOUND_NOT_MAPPED_VALUE) && (m_proph->m_sound_param_as[i].val_s.sample_status & 0x10));
				      break;
               case 5:
			      case 13:
                  sound_active->SetValue((m_proph->m_sound_param_as[i].val_s.transpose_map6 != SOUND_NOT_MAPPED_VALUE) && (m_proph->m_sound_param_as[i].val_s.sample_status & 0x10));
                  break;
               case 6:
			      case 14:
                  sound_active->SetValue((m_proph->m_sound_param_as[i].val_s.transpose_map7 != SOUND_NOT_MAPPED_VALUE) && (m_proph->m_sound_param_as[i].val_s.sample_status & 0x10));
                  break;
               case 7:
			      case 15:
                  sound_active->SetValue((m_proph->m_sound_param_as[i].val_s.transpose_map8 != SOUND_NOT_MAPPED_VALUE) && (m_proph->m_sound_param_as[i].val_s.sample_status & 0x10));
				      break;
			      default:
				      break;
            }
		}
//do right map
         t_u8 = right_map_value;
		 if ( right_map_value < 8 )
		 {
			 s = 0;
			 e = 8;
		 }
		 else
		 {
			 s = 8;
			 e = 16;
		 }
         for(i = s; i < e; i++) // was 8
         {
            wxToggleButton *sound_active;
            switch(i)
            {
               case 0:
			   case 8:
                  sound_active = m_using_snd_9;
                  break;
               case 1:
			   case 9:
                  sound_active = m_using_snd_10;
                  break;
               case 2:
			   case 10:
                  sound_active = m_using_snd_11;
                  break;
               case 3:
			   case 11:
                  sound_active = m_using_snd_12;
                  break;
               case 4:
			   case 12:
                  sound_active = m_using_snd_13;
                  break;
               case 5:
			   case 13:
                  sound_active = m_using_snd_14;
                  break;
               case 6:
			   case 14:
                  sound_active = m_using_snd_15;
                  break;
               case 7:
			   case 15:
                  sound_active = m_using_snd_16;
                  break;
			   default:
                  sound_active = m_using_snd_9;
                  break;
            }
            switch(t_u8)
            {
               case 0:
			      case 8:
                  sound_active->SetValue((m_proph->m_sound_param_as[i].val_s.transpose_map1 != SOUND_NOT_MAPPED_VALUE) && (m_proph->m_sound_param_as[i].val_s.sample_status & 0x10));
				      break;
               case 1:
			      case 9:
                  sound_active->SetValue((m_proph->m_sound_param_as[i].val_s.transpose_map2 != SOUND_NOT_MAPPED_VALUE) && (m_proph->m_sound_param_as[i].val_s.sample_status & 0x10));
				      break;
               case 2:
			      case 10:
                  sound_active->SetValue((m_proph->m_sound_param_as[i].val_s.transpose_map3 != SOUND_NOT_MAPPED_VALUE) && (m_proph->m_sound_param_as[i].val_s.sample_status & 0x10));
				      break;
               case 3:
			      case 11:
                  sound_active->SetValue((m_proph->m_sound_param_as[i].val_s.transpose_map4 != SOUND_NOT_MAPPED_VALUE) && (m_proph->m_sound_param_as[i].val_s.sample_status & 0x10));
				      break;
               case 4:
			      case 12:
				      sound_active->SetValue((m_proph->m_sound_param_as[i].val_s.transpose_map5 != SOUND_NOT_MAPPED_VALUE) && (m_proph->m_sound_param_as[i].val_s.sample_status & 0x10));
				      break;
               case 5:
			      case 13:
                  sound_active->SetValue((m_proph->m_sound_param_as[i].val_s.transpose_map6 != SOUND_NOT_MAPPED_VALUE) && (m_proph->m_sound_param_as[i].val_s.sample_status & 0x10));
                  break;
               case 6:
			      case 14:
                  sound_active->SetValue((m_proph->m_sound_param_as[i].val_s.transpose_map7 != SOUND_NOT_MAPPED_VALUE) && (m_proph->m_sound_param_as[i].val_s.sample_status & 0x10));
                  break;
               case 7:
			      case 15:
                  sound_active->SetValue((m_proph->m_sound_param_as[i].val_s.transpose_map8 != SOUND_NOT_MAPPED_VALUE) && (m_proph->m_sound_param_as[i].val_s.sample_status & 0x10));
				      break;
			      default:
				      break;
			}
	 }
}


void PresetPanelImpl::OnParamChange(wxCommandEvent &event)
{
}


void PresetPanelImpl::OnLeftMapSelect(wxCommandEvent &event)
{
   switch(m_left_map_selection->GetSelection())
   {
      case 0:
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side = 0;
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number = 0;
         break;
      case 1:
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side = 0;
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number = 1;
         break;
      case 2:
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side = 0;
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number = 2;
         break;
      case 3:
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side = 0;
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number = 3;
         break;
      case 4:
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side = 0;
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number = 4;
         break;
      case 5:
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side = 0;
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number = 5;
         break;
      case 6:
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side = 0;
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number = 6;
         break;
      case 7:
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side = 0;
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number = 7;
         break;
      case 8:
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side = 1;
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number = 0;
         break;
      case 9:
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side = 1;
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number = 1;
         break;
      case 10:
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side = 1;
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number = 2;
         break;
      case 11:
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side = 1;
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number = 3;
         break;
      case 12:
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side = 1;
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number = 4;
         break;
      case 13:
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side = 1;
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number = 5;
         break;
      case 14:
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side = 1;
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number = 6;
         break;
      case 15:
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side = 1;
         m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number = 7;
         break;
   }
   m_proph->updateParamBytesFromStruct();
   m_topframe->updateGUI();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferPreset2Proph(m_preset_u8))
      {
         m_topframe->transferStarted();
      }
   }
}

void PresetPanelImpl::OnRightMapSelect(wxCommandEvent &event)
{
   switch(m_right_map_selection->GetSelection())
   {
      case 0:
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side = 0;
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number = 0;
         break;
      case 1:
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side = 0;
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number = 1;
         break;
      case 2:
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side = 0;
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number = 2;
         break;
      case 3:
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side = 0;
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number = 3;
         break;
      case 4:
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side = 0;
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number = 4;
         break;
      case 5:
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side = 0;
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number = 5;
         break;
      case 6:
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side = 0;
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number = 6;
         break;
      case 7:
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side = 0;
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number = 7;
         break;
      case 8:
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side = 1;
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number = 0;
         break;
      case 9:
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side = 1;
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number = 1;
         break;
      case 10:
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side = 1;
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number = 2;
         break;
      case 11:
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side = 1;
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number = 3;
         break;
      case 12:
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side = 1;
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number = 4;
         break;
      case 13:
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side = 1;
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number = 5;
         break;
      case 14:
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side = 1;
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number = 6;
         break;
      case 15:
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side = 1;
         m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number = 7;
         break;
   }
   m_proph->updateParamBytesFromStruct();
   m_topframe->updateGUI();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferPreset2Proph(m_preset_u8))
      {
         m_topframe->transferStarted();
      }
   }
}

void PresetPanelImpl::OnSliderChange(wxScrollEvent &event)
{
//   m_proph->m_preset_param_as[m_preset_u8].val_s.lfo_freq = m_lfo_freq->GetValue();
//   m_proph->m_preset_param_as[m_preset_u8].val_s.lfo_init_amount = m_lfo_init_amount->GetValue();
//   m_proph->m_preset_param_as[m_preset_u8].val_s.lfo_vel_sensitivity = (int8_t)m_lfo_vel_sensitivity->GetValue() + 0x80;
//   m_proph->m_preset_param_as[m_preset_u8].val_s.transpose = (int8_t)m_transpose->GetValue();
//   m_proph->m_preset_param_as[m_preset_u8].val_s.vel_switch_threshold = m_vel_switch_threshold->GetValue();
//   m_proph->m_preset_param_as[m_preset_u8].val_s.stack_delay = m_stack_delay->GetValue();
//   m_proph->m_preset_param_as[m_preset_u8].val_s.stack_detune = m_stack_detune->GetValue();
//   m_proph->m_preset_param_as[m_preset_u8].val_s.arp_rate = m_arp_rate->GetValue();
//   m_proph->m_preset_param_as[m_preset_u8].val_s.pitchwheel_range = m_pitchwheel_range->GetValue();
//   m_proph->updateParamBytesFromStruct();
//   m_topframe->updateGUI();
//   if(m_topframe->getOnlineUpdateActive())
//   {
//      if(m_proph->transferPreset2Proph(m_preset_u8))
//      {
//         m_topframe->transferStarted();
//      }
//   }
}
void PresetPanelImpl::OnLFOFreqSliderChange(wxScrollEvent &event)
{
   m_proph->m_preset_param_as[m_preset_u8].val_s.lfo_freq = m_lfo_freq->GetValue();
   m_proph->updateParamBytesFromStruct();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferPreset2Proph(m_preset_u8))
      {
         m_topframe->transferStarted();
      }
   }
   updateGUI();
}

void PresetPanelImpl::OnLFOInitAmountSliderChange(wxScrollEvent &event)
{
   m_proph->m_preset_param_as[m_preset_u8].val_s.lfo_init_amount = m_lfo_init_amount->GetValue();
   m_proph->updateParamBytesFromStruct();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferPreset2Proph(m_preset_u8))
      {
         m_topframe->transferStarted();
      }
   }
   updateGUI();
}

void PresetPanelImpl::OnLFOVelocitySliderChange(wxScrollEvent &event)
{
   m_proph->m_preset_param_as[m_preset_u8].val_s.lfo_vel_sensitivity = (int8_t)m_lfo_vel_sensitivity->GetValue() + 0x80;
   m_proph->updateParamBytesFromStruct();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferPreset2Proph(m_preset_u8))
      {
         m_topframe->transferStarted();
      }
   }
   updateGUI();
}

void PresetPanelImpl::OnKeyboardTransposeSliderChange(wxScrollEvent &event)
{
   m_proph->m_preset_param_as[m_preset_u8].val_s.transpose = (int8_t)m_transpose->GetValue();
   m_proph->updateParamBytesFromStruct();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferPreset2Proph(m_preset_u8))
      {
         m_topframe->transferStarted();
      }
   }
   updateGUI();
}

void PresetPanelImpl::OnKeyboardVelocitySwitchSliderChange(wxScrollEvent &event)
{
   m_proph->m_preset_param_as[m_preset_u8].val_s.vel_switch_threshold = m_vel_switch_threshold->GetValue();
   m_proph->updateParamBytesFromStruct();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferPreset2Proph(m_preset_u8))
      {
         m_topframe->transferStarted();
      }
   }
   updateGUI();
}

void PresetPanelImpl::OnStackDelaySliderChange(wxScrollEvent &event)
{
   m_proph->m_preset_param_as[m_preset_u8].val_s.stack_delay = m_stack_delay->GetValue();
   m_proph->updateParamBytesFromStruct();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferPreset2Proph(m_preset_u8))
      {
         m_topframe->transferStarted();
      }
   }
   updateGUI();
}

void PresetPanelImpl::OnStackDetuneSliderChange(wxScrollEvent &event)
{
   m_proph->m_preset_param_as[m_preset_u8].val_s.stack_detune = m_stack_detune->GetValue();
   m_proph->updateParamBytesFromStruct();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferPreset2Proph(m_preset_u8))
      {
         m_topframe->transferStarted();
      }
   }
   updateGUI();
}

void PresetPanelImpl::OnArpRateSliderChange(wxScrollEvent &event)
{
   m_proph->m_preset_param_as[m_preset_u8].val_s.arp_rate = m_arp_rate->GetValue();
   m_proph->updateParamBytesFromStruct();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferPreset2Proph(m_preset_u8))
      {
         m_topframe->transferStarted();
      }
   }
   updateGUI();
}

void PresetPanelImpl::OnPitchwheelSliderChange(wxScrollEvent &event)
{
   m_proph->m_preset_param_as[m_preset_u8].val_s.pitchwheel_range = m_pitchwheel_range->GetValue();
   m_proph->updateParamBytesFromStruct();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferPreset2Proph(m_preset_u8))
      {
         m_topframe->transferStarted();
      }
   }
   updateGUI();
}

void PresetPanelImpl::OnComboChanged(wxCommandEvent &event)
{
   m_proph->m_preset_param_as[m_preset_u8].val_s.arp_repeats = m_arp_repeats->GetSelection();
   m_proph->m_preset_param_as[m_preset_u8].val_s.vibrato = m_vibrato->GetSelection();
   m_proph->m_preset_param_as[m_preset_u8].val_s.lfo_filt = m_lfo_filt->GetSelection();
   m_proph->m_preset_param_as[m_preset_u8].val_s.lfo_amp = m_lfo_amp->GetSelection();
   m_proph->m_preset_param_as[m_preset_u8].val_s.keyboard_mode = m_keyboard_mode->GetSelection();
   m_proph->m_preset_param_as[m_preset_u8].val_s.stack_voices = m_stack_voices->GetSelection();
   m_proph->m_preset_param_as[m_preset_u8].val_s.midi_left_ch = m_midi_left_ch->GetSelection();
   m_proph->m_preset_param_as[m_preset_u8].val_s.midi_right_ch = m_midi_right_ch->GetSelection();
   if(m_stack_voices_preset_on->GetValue())
   {
      m_proph->m_preset_param_as[m_preset_u8].val_s.stack_voices = (m_proph->m_preset_param_as[m_preset_u8].val_s.stack_voices & 0x03) + 0x20;
   }
   else
   {
      m_proph->m_preset_param_as[m_preset_u8].val_s.stack_voices = (m_proph->m_preset_param_as[m_preset_u8].val_s.stack_voices & 0x03);
   }


   m_proph->m_preset_param_as[m_preset_u8].val_s.arp_mode = m_arp_mode->GetSelection();
   if(m_arp_preset_on->GetValue())
   {
      m_proph->m_preset_param_as[m_preset_u8].val_s.arp_mode = (m_proph->m_preset_param_as[m_preset_u8].val_s.arp_mode & 0x07) + 0x10;
   }
   else
   {
      m_proph->m_preset_param_as[m_preset_u8].val_s.arp_mode = (m_proph->m_preset_param_as[m_preset_u8].val_s.arp_mode & 0x07);
   }

   m_proph->m_preset_param_as[m_preset_u8].val_s.arp_oct = m_arp_oct->GetSelection() + 1;
   m_proph->m_preset_param_as[m_preset_u8].val_s.arp_split_type = m_arp_split_type->GetSelection();
   m_proph->m_preset_param_as[m_preset_u8].val_s.midi_mode = m_midi_mode->GetSelection();
   m_proph->m_preset_param_as[m_preset_u8].val_s.arp_latch_mode = m_arp_latch_mode->GetSelection();

   m_proph->updateParamBytesFromStruct();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferPreset2Proph(m_preset_u8))
      {
         m_topframe->transferStarted();
      }
   }
   m_topframe->updateGUI();
}

void PresetPanelImpl::OnCheckboxChange(wxCommandEvent& event)
{
   uint8_t t_u8;
   if(m_dyn_alloc->GetValue())
   {
      m_proph->m_preset_param_as[m_preset_u8].val_s.dyn_alloc = 1;
   }
   else
   {
      m_proph->m_preset_param_as[m_preset_u8].val_s.dyn_alloc = 0;
   }

   if(m_stack_voices_preset_on->GetValue())
   {
      m_proph->m_preset_param_as[m_preset_u8].val_s.stack_voices = (m_proph->m_preset_param_as[m_preset_u8].val_s.stack_voices & 0x03) + 0x20;
   }
   else
   {
      m_proph->m_preset_param_as[m_preset_u8].val_s.stack_voices = (m_proph->m_preset_param_as[m_preset_u8].val_s.stack_voices & 0x03);
   }

   if(m_arp_preset_on->GetValue())
   {
      m_proph->m_preset_param_as[m_preset_u8].val_s.arp_mode = (m_proph->m_preset_param_as[m_preset_u8].val_s.arp_mode & 0x07) + 0x10;
   }
   else
   {
      m_proph->m_preset_param_as[m_preset_u8].val_s.arp_mode = (m_proph->m_preset_param_as[m_preset_u8].val_s.arp_mode & 0x07);
   }


   t_u8 = 0;
   if(m_tx_mod_wheel->GetValue())
   {
      t_u8 |= 0x01;
   } 
   if(m_tx_pitch_wheel->GetValue())
   {
      t_u8 |= 0x02;
   }
   if(m_tx_program_chg->GetValue())
   {
      t_u8 |= 0x04;
   }
   if(m_tx_mod_wheel_as_pressure->GetValue())
   {
      t_u8 |= 0x08;
   }
   if(m_rx_mod_wheel->GetValue())
   {
      t_u8 |= 0x10;
   }
   if(m_rx_pitch_wheel->GetValue())
   {
      t_u8 |= 0x20;
   }
   if(m_rx_program_chg->GetValue())
   {
      t_u8 |= 0x40;
   }
   if(m_rx_pressure_as_mod_wheel->GetValue())
   {
      t_u8 |= 0x80;
   }
   m_proph->m_preset_param_as[m_preset_u8].val_s.midi_opts = t_u8;

   m_proph->updateParamBytesFromStruct();
   m_topframe->updateGUI();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferPreset2Proph(m_preset_u8))
      {
         m_topframe->transferStarted();
      }
   }
}


void PresetPanelImpl::OnLoad(wxCommandEvent& event)
{
   m_presetparam->OnLoad(event);
}

void PresetPanelImpl::OnSave(wxCommandEvent& event)
{
   m_presetparam->OnSave(event);
}

void PresetPanelImpl::OnCopy(wxCommandEvent& event)
{
   m_presetparam->OnCopy(event);
}


void PresetPanelImpl::OnSelectPreset1(wxCommandEvent& event)
{
   m_topframe->activatePreset(0);
}

void PresetPanelImpl::OnSelectPreset2(wxCommandEvent& event)
{
   m_topframe->activatePreset(1);
}

void PresetPanelImpl::OnSelectPreset3(wxCommandEvent& event)
{
   m_topframe->activatePreset(2);
}

void PresetPanelImpl::OnSelectPreset4(wxCommandEvent& event)
{
   m_topframe->activatePreset(3);
}

void PresetPanelImpl::OnSelectPreset5(wxCommandEvent& event)
{
   m_topframe->activatePreset(4);
}

void PresetPanelImpl::OnSelectPreset6(wxCommandEvent& event)
{
   m_topframe->activatePreset(5);
}

void PresetPanelImpl::OnSelectPreset7(wxCommandEvent& event)
{
   m_topframe->activatePreset(6);
}

void PresetPanelImpl::OnSelectPreset8(wxCommandEvent& event)
{
   m_topframe->activatePreset(7);
}

void PresetPanelImpl::OnSelectPreset9(wxCommandEvent& event)
{
   m_topframe->activatePreset(8);
}

void PresetPanelImpl::OnSelectPreset10(wxCommandEvent& event)
{
   m_topframe->activatePreset(9);
}

void PresetPanelImpl::OnSelectPreset11(wxCommandEvent& event)
{
   m_topframe->activatePreset(10);
}

void PresetPanelImpl::OnSelectPreset12(wxCommandEvent& event)
{
   m_topframe->activatePreset(11);
}

void PresetPanelImpl::deselectAllPresetButtons(void)
{
   m_select_preset1->SetValue(false);
   m_select_preset2->SetValue(false);
   m_select_preset3->SetValue(false);
   m_select_preset4->SetValue(false);
   m_select_preset5->SetValue(false);
   m_select_preset6->SetValue(false);
   m_select_preset7->SetValue(false);
   m_select_preset8->SetValue(false);
   m_select_preset9->SetValue(false);
   m_select_preset10->SetValue(false);
   m_select_preset11->SetValue(false);
   m_select_preset12->SetValue(false);
   m_right_map_selector->SetValue(false);
   m_left_map_selector->SetValue(false);

}

void PresetPanelImpl::OnLeftMapSelector(wxCommandEvent& event)
{
	uint8_t left_map_selection;
	left_map_selection =  m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side *10 + m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_number ;
    if (left_map_selection >= 10 ) left_map_selection -= 2;
    m_topframe->activateMapOnGui(left_map_selection);
}

void PresetPanelImpl::OnRightMapSelector(wxCommandEvent& event)
{
	uint8_t right_map_selection;
	right_map_selection =  m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side *10 + m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_number ;
    if (right_map_selection >= 10 ) right_map_selection -= 2;
    m_topframe->activateMapOnGui(right_map_selection);
}


void PresetPanelImpl::OnUsingSound1(wxCommandEvent& event)
{
	if (m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side == 0)
		m_topframe->activateSoundOnGui(0);
	else
		m_topframe->activateSoundOnGui(0+8);
}

void PresetPanelImpl::OnUsingSound2(wxCommandEvent& event)
{
	if (m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side == 0)
		m_topframe->activateSoundOnGui(1);
	else
		m_topframe->activateSoundOnGui(1+8);
}

void PresetPanelImpl::OnUsingSound3(wxCommandEvent& event)
{
	if (m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side == 0)
		m_topframe->activateSoundOnGui(2);
	else
		m_topframe->activateSoundOnGui(2+8);
}

void PresetPanelImpl::OnUsingSound4(wxCommandEvent& event)
{
	if (m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side == 0)
		m_topframe->activateSoundOnGui(3);
	else
		m_topframe->activateSoundOnGui(3+8);
}

void PresetPanelImpl::OnUsingSound5(wxCommandEvent& event)
{
	if (m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side == 0)
		m_topframe->activateSoundOnGui(4);
	else
		m_topframe->activateSoundOnGui(4+8);
}

void PresetPanelImpl::OnUsingSound6(wxCommandEvent& event)
{
	if (m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side == 0)
		m_topframe->activateSoundOnGui(5);
	else
		m_topframe->activateSoundOnGui(5+8);
}

void PresetPanelImpl::OnUsingSound7(wxCommandEvent& event)
{
	if (m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side == 0)
		m_topframe->activateSoundOnGui(6);
	else
		m_topframe->activateSoundOnGui(6+8);
}

void PresetPanelImpl::OnUsingSound8(wxCommandEvent& event)
{
	if (m_proph->m_preset_param_as[m_preset_u8].val_s.left_x_map_side == 0)
		m_topframe->activateSoundOnGui(7);
	else
		m_topframe->activateSoundOnGui(7+8);
}

void PresetPanelImpl::OnUsingSound9(wxCommandEvent& event)
{
	if (m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side == 0)
		m_topframe->activateSoundOnGui(0);
	else
		m_topframe->activateSoundOnGui(0+8);
}

void PresetPanelImpl::OnUsingSound10(wxCommandEvent& event)
{
	if (m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side == 0)
		m_topframe->activateSoundOnGui(1);
	else
		m_topframe->activateSoundOnGui(1+8);

}

void PresetPanelImpl::OnUsingSound11(wxCommandEvent& event)
{
	if (m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side == 0)
		m_topframe->activateSoundOnGui(2);
	else
		m_topframe->activateSoundOnGui(2+8);

}

void PresetPanelImpl::OnUsingSound12(wxCommandEvent& event)
{
	if (m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side == 0)
		m_topframe->activateSoundOnGui(3);
	else
		m_topframe->activateSoundOnGui(3+8);

}

void PresetPanelImpl::OnUsingSound13(wxCommandEvent& event)
{
	if (m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side == 0)
		m_topframe->activateSoundOnGui(4);
	else
		m_topframe->activateSoundOnGui(4+8);

}

void PresetPanelImpl::OnUsingSound14(wxCommandEvent& event)
{
	if (m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side == 0)
		m_topframe->activateSoundOnGui(5);
	else
		m_topframe->activateSoundOnGui(5+8);

}

void PresetPanelImpl::OnUsingSound15(wxCommandEvent& event)
{
	if (m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side == 0)
		m_topframe->activateSoundOnGui(6);
	else
		m_topframe->activateSoundOnGui(6+8);

}

void PresetPanelImpl::OnUsingSound16(wxCommandEvent& event)
{
	if (m_proph->m_preset_param_as[m_preset_u8].val_s.right_y_map_side == 0)
		m_topframe->activateSoundOnGui(7);
	else
		m_topframe->activateSoundOnGui(7+8);

}





