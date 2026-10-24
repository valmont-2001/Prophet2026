#include "types.h"

#include <stdio.h>
#include <wx/wx.h>
#include <wx/string.h>
#include <wx/file.h>
#include <wx/spinctrl.h>
#include <wx/slider.h>

#include "GUILayout.h"
#include "mapparam.h"
#include "main.h"
#include "stopwatch.h"
#include "proph2000.h"
#include <map>
#include <list>
using namespace std;
#include "envdispobj.h"
#include "clickarea.h"
#include "keyboard.h"
#include "mapkeyboard.h"
#include "mapcopydlg.h"
#include "mapscaledvaldlg.h"
#include "mappanel.h"
#define wxDEFAULT_FONT_SIZE 6


MapPanelImpl::MapPanelImpl(wxWindow *parent, MyPanel *topframe, Proph2000 *proph, uint8_t map_u8, MyMapParam *mapparam) :
   MapPanel(parent),
   m_topframe(topframe), m_proph(proph), m_map_u8(map_u8), m_mapparam(mapparam)
{
	uint8_t pointSize;
    
#ifdef __WXMAC__ //130205
    SetSize(wxSize(GetSize().GetWidth(), GetSize().GetHeight() + 92));
    SetMinSize(wxSize(GetMinSize().GetWidth(), GetMinSize().GetHeight() + 92));
    SetMaxSize(wxSize(GetMaxSize().GetWidth(), GetMaxSize().GetHeight() + 92));
#endif
    
	wxFont myFont;
	myFont = parent->GetFont();
	pointSize = myFont.GetPointSize();
	myFont.SetPointSize((pointSize == wxDEFAULT || pointSize == -1)
                    ? wxDEFAULT_FONT_SIZE
                    : pointSize );
	topframe->SetFont(myFont);

   deselectAllMapButtons();
   m_select_map_1->SetValue(true);
   show_vcf_env_amount = false;
   trigger = false;
   activateMap(0);
 //  updateVCAGraph = true;
 //  updateVCFGraph = true;
 //  displaySettings();
 //  updateGUI();

// Doesn't work...
//      SetFont(wxFont(GENERAL_FONT_SIZE, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

}


MapPanelImpl::~MapPanelImpl()
{
}

void MapPanelImpl::makeActive(uint8_t map_u8)
{
   deselectAllMapButtons();
   switch(map_u8)
   {
      case 0:
         m_select_map_1->SetValue(true);
         break;
      case 1:
         m_select_map_2->SetValue(true);
         break;
      case 2:
         m_select_map_3->SetValue(true);
         break;
      case 3:
         m_select_map_4->SetValue(true);
         break;
      case 4:
         m_select_map_5->SetValue(true);
         break;
      case 5:
         m_select_map_6->SetValue(true);
         break;
      case 6:
         m_select_map_7->SetValue(true);
         break;
      case 7:
         m_select_map_8->SetValue(true);
         break;
      case 8:
         m_select_map_9->SetValue(true);
         break;
      case 9:
         m_select_map_10->SetValue(true);
         break;
      case 10:
         m_select_map_11->SetValue(true);
         break;
      case 11:
         m_select_map_12->SetValue(true);
         break;
      case 12:
         m_select_map_13->SetValue(true);
         break;
      case 13:
         m_select_map_14->SetValue(true);
         break;
      case 14:
         m_select_map_15->SetValue(true);
         break;
      case 15:
         m_select_map_16->SetValue(true);
         break;
      default:
         break;
   }
   updateVCAGraph = true;
   updateVCFGraph = true;
   m_proph->sendSelectRequest();
}

void MapPanelImpl::displaySettings(void)
{
   updateVCAGraph = true;
   updateVCFGraph = true;
   m_amp_release_rate->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_release_rate - 0x80));
   m_amp_release_rate_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_release_rate - 0x80)));
   m_amp_2nd_release_rate->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_2nd_release_rate - 0x80));
   m_amp_2nd_release_rate_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_2nd_release_rate - 0x80)));
   m_amp_decay_rate->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_decay_rate - 0x80));
   m_amp_decay_rate_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_decay_rate - 0x80)));
   m_amp_sustain_level->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_sustain_level - 0x80));
   m_amp_sustain_level_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_sustain_level - 0x80)));
   m_amp_attack_rate->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_attack_rate - 0x80));
   m_amp_attack_rate_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_attack_rate - 0x80)));
   m_amp_peak_vel_sensitivity->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_peak_vel_sensitivity - 0x80));
   m_amp_peak_vel_sensitivity_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_peak_vel_sensitivity - 0x80)));
   m_filt_release_rate->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_release_rate - 0x80));
   m_filt_release_rate_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_release_rate - 0x80)));
   m_filt_2nd_release_rate->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_2nd_release_rate - 0x80));
   m_filt_2nd_release_rate_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_2nd_release_rate - 0x80)));
   m_filt_decay_rate->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_decay_rate - 0x80));
   m_filt_decay_rate_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_decay_rate - 0x80)));
   m_filt_sustain_level->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_sustain_level - 0x80));
   m_filt_sustain_level_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_sustain_level - 0x80)));
   m_filt_attack_rate->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_attack_rate - 0x80));
   m_filt_attack_rate_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_attack_rate - 0x80)));
   m_filt_peak_vel_sensitivity->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_peak_vel_sensitivity - 0x80));
   m_filt_peak_vel_sensitivity_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_peak_vel_sensitivity - 0x80)));
   m_filt_resonance->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_resonance - 0x80));
   m_filt_resonance_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_resonance - 0x80)));
   m_filt_cutoff->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_cutoff - 0x80));
   m_filt_cutoff_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_cutoff - 0x80)));
   m_filt_env_amount->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_env_amount - 0x80));
   m_filt_env_amount_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_env_amount - 0x80)));
   m_filt_keyboard_tracking->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_keyboard_tracking - 0x80));
   m_filt_keyboard_tracking_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_keyboard_tracking - 0x80)));

   m_attack_vel_sensitivity->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.attack_vel_sensitivity - 0x80));
   m_attack_vel_sensitivity_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.attack_vel_sensitivity - 0x80)));
   m_release_vel_sensitivity->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.release_vel_sensitivity - 0x80));
   m_release_vel_sensitivity_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.release_vel_sensitivity - 0x80)));
   
   //str.sprintf("%d", m_proph->m_map_param_as[m_map_u8].val_s.sound_direction);
   //m_sound_direction->SetValue(str);

   if(m_proph->m_map_param_as[m_map_u8].val_s.sound_direction & 0x08)
   {
      m_sound_direction_reversed->SetValue(true);
   }
   else
   {
      m_sound_direction_reversed->SetValue(false);
   }

   m_velocity_start_point->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.velocity_start_point - 0x80));
   m_velocity_start_point_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.velocity_start_point - 0x80)));

}

void MapPanelImpl::activateMap(uint8_t map_u8)
{
   m_map_u8 = map_u8;
   displaySettings();
   updateGUI();
   m_proph->sendSelectRequest();
 //  updateUsedSounds();
}

void MapPanelImpl::updateGUI(void)
{
   wxString str;
   uint8_t i;
   uint8_t s;
   uint8_t e;
   uint8_t o;
   uint8_t used_sounds_cnt = 0;

   int16_t volume;
/*
   	uint8_t pointSize;
	wxFont myFont;
	myFont = this->GetFont();
	pointSize = myFont.GetPointSize();
	myFont.SetPointSize((pointSize == wxDEFAULT || pointSize == -1)
                    ? wxDEFAULT_FONT_SIZE
                    : pointSize );
	this->SetFont(myFont);
*/
   wxStaticBoxSizer* mySizer;
   mySizer=(wxStaticBoxSizer*)m_vcf_env_panel->GetSizer();			



   if(m_map_u8 < 8)
   {
      s = 0;
      e = 8;
   }
   else
   {
      s = 8;
      e = 16;
   }

   o = 0;

   for(i = s; i < e; i++) // Find out whether sound is in the Map
   {
      switch(m_map_u8)
      {
         case 0:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map1 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i < 8)
               {
                  if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10) used_sounds_cnt++;               
               }
            }
         break;
         case 1:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map2 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i < 8)
               {
                  if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10) used_sounds_cnt++;               
               }
            }
         break;
         case 2:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map3 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i < 8)
               {
                  if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10) used_sounds_cnt++;               
			   }
            }
         break;
         case 3:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map4 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i < 8)
               {
                  if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10) used_sounds_cnt++;               
			   }
            }
         break;
         case 4:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map5 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i < 8)
               {
                  if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10) used_sounds_cnt++;               
			   }
            }
         break;
         case 5:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map6 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i < 8)
               {
                  if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10) used_sounds_cnt++;               
			   }
            }
         break;
         case 6:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map7 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i < 8)
               {
                  if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10) used_sounds_cnt++;               
			   }
            }
         break;
         case 7:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map8 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i < 8)
               {
                  if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10) used_sounds_cnt++;               
			   }
            }
         break;
         case 8:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map1 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i >= 8)
               {
                  if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10) used_sounds_cnt++;               
			   }
            }
         break;
         case 9:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map2 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i >= 8)
               {
                  if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10) used_sounds_cnt++;               
			   }
            }
         break;
         case 10:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map3 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i >= 8)
               {
                 if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10) used_sounds_cnt++;               
			   }
            }
         break;
         case 11:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map4 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i >= 8)
               {
                  if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10) used_sounds_cnt++;               
			   }
            }
         break;
         case 12:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map5 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i >= 8)
               {
                  if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10) used_sounds_cnt++;               
			   }
            }
         break;
         case 13:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map6 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i >= 8)
               {
                  if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10) used_sounds_cnt++;               
			   }
            }
         break;
         case 14:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map7 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i >= 8)
               {
                  if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10) used_sounds_cnt++;               
			   }
            }
         break;
         case 15:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map8 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i >= 8)
               {
                  if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10) used_sounds_cnt++;               
			   }
            }
         break;
      }
   }
   if (updateVCAGraph == true)
   {
      m_vca_env_disp->clearView();
   }
   if (updateVCFGraph == true)
   {
      m_vcf_env_disp->clearView();
   }

   for(i = s; i < e; i++) // Find out whether sound is in the Map
   {
      wxColour col;
      switch(i)
      {
         case 0:
            col = SOUND1_COLOUR;
            break;
         case 1:
            col = SOUND2_COLOUR;
            break;
         case 2:
            col = SOUND3_COLOUR;
            break;
         case 3:
            col = SOUND4_COLOUR;
            break;
         case 4:
            col = SOUND5_COLOUR;
            break;
         case 5:
            col = SOUND6_COLOUR;
            break;
         case 6:
            col = SOUND7_COLOUR;
            break;
         case 7:
            col = SOUND8_COLOUR;
            break;
         case 8:
            col = SOUND9_COLOUR;
            break;
         case 9:
            col = SOUND10_COLOUR;
            break;
         case 10:
            col = SOUND11_COLOUR;
            break;
         case 11:
            col = SOUND12_COLOUR;
            break;
         case 12:
            col = SOUND13_COLOUR;
            break;
         case 13:
            col = SOUND14_COLOUR;
            break;
         case 14:
            col = SOUND15_COLOUR;
            break;
         case 15:
            col = SOUND16_COLOUR;
            break;
      }

      bool draw = false;
	   bool using_sound = false;

      switch(m_map_u8)
      {
         case 0:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map1 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i < 8)
               {
                  draw = true;
				      if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10)
					      using_sound = true;
				      volume=m_proph->m_sound_param_as[i].val_s.relative_mix_map1;
               }
            }
         break;
         case 1:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map2 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i < 8)
               {
                  draw = true;
  				      if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10)
					      using_sound = true;
				      volume=m_proph->m_sound_param_as[i].val_s.relative_mix_map2;
               }
            }
         break;
         case 2:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map3 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i < 8)
               {
                  draw = true;
  				      if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10)
					      using_sound = true;
				      volume=m_proph->m_sound_param_as[i].val_s.relative_mix_map3;
			      }
            }
         break;
         case 3:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map4 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i < 8)
               {
                  draw = true;
  				      if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10)
					      using_sound = true;
				      volume=m_proph->m_sound_param_as[i].val_s.relative_mix_map4;
			      }
            }
         break;
         case 4:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map5 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i < 8)
               {
                  draw = true;
  				      if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10)
					      using_sound = true;
				      volume=m_proph->m_sound_param_as[i].val_s.relative_mix_map5;
			      }
            }
         break;
         case 5:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map6 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i < 8)
               {
                  draw = true;
  				      if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10)
					      using_sound = true;
				      volume=m_proph->m_sound_param_as[i].val_s.relative_mix_map6;

			      }
            }
         break;
         case 6:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map7 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i < 8)
               {
                  draw = true;
  				      if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10)
					      using_sound = true;
				      volume=m_proph->m_sound_param_as[i].val_s.relative_mix_map7;
			      }
            }
         break;
         case 7:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map8 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i < 8)
               {
                  draw = true;
  				      if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10)
					      using_sound = true;
				      volume=m_proph->m_sound_param_as[i].val_s.relative_mix_map8;

			      }
            }
         break;
         case 8:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map1 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i >= 8)
               {
                  draw = true;
  				      if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10)
					      using_sound = true;
				      volume=m_proph->m_sound_param_as[i].val_s.relative_mix_map1;

			      }
            }
         break;
         case 9:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map2 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i >= 8)
               {
                  draw = true;
  				      if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10)
					      using_sound = true;
				      volume=m_proph->m_sound_param_as[i].val_s.relative_mix_map2;
			      }
            }
         break;
         case 10:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map3 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i >= 8)
               {
                  draw = true;
  				      if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10)
					      using_sound = true;
				      volume=m_proph->m_sound_param_as[i].val_s.relative_mix_map3;
			      }
            }
         break;
         case 11:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map4 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i >= 8)
               {
                  draw = true;
  				      if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10)
					      using_sound = true;
				      volume=m_proph->m_sound_param_as[i].val_s.relative_mix_map4;
			      }
            }
         break;
         case 12:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map5 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i >= 8)
               {
                  draw = true;
  				      if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10)
					      using_sound = true;
				      volume=m_proph->m_sound_param_as[i].val_s.relative_mix_map5;
			      }
            }
         break;
         case 13:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map6 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i >= 8)
               {
                  draw = true;
  				      if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10)
					      using_sound = true;
				      volume=m_proph->m_sound_param_as[i].val_s.relative_mix_map6;
			   }
            }
         break;
         case 14:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map7 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i >= 8)
               {
                  draw = true;
  				      if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10)
					      using_sound = true;
				      volume=m_proph->m_sound_param_as[i].val_s.relative_mix_map7;
			   }
            }
         break;
         case 15:
            if(m_proph->m_sound_param_as[i].val_s.transpose_map8 != SOUND_NOT_MAPPED_VALUE)
            {
               if(i >= 8)
               {
                  draw = true;
  				      if(m_proph->m_sound_param_as[i].val_s.sample_status & 0x10)
					      using_sound = true;
				      volume=m_proph->m_sound_param_as[i].val_s.relative_mix_map8;
			   }
            }
         break;
      }
      
	  draw = using_sound;
	  updateUsedSounds(i,using_sound);

     if(draw)
      {
         uint8_t a;
         uint8_t d;
         uint8_t s;
         uint8_t r;
         uint8_t r_2nd;
         uint8_t percentage;
         int16_t t;
         if (updateVCAGraph == true)
         {
            percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_release_rate - 0x80));
            t = m_proph->m_sound_param_as[i].val_s.amp_release_rate;
            if(m_proph->m_sound_param_as[i].val_s.amp_release_rate == 0x3f)
            {
               r = 0x3f;
            }
            else
            {
               t = (t * percentage) / 100;
               if(t >= 0x3e)
               {
                  t = 0x3e;
               }
               if(t == 0)
               {
                  t = 1;
               }
               r = t;
            }

            percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_2nd_release_rate - 0x80));
            t = m_proph->m_sound_param_as[i].val_s.amp_2nd_release_rate;
            if(m_proph->m_sound_param_as[i].val_s.amp_2nd_release_rate == 0x3f)
            {
               r_2nd = 0x3f;
            }
            else
            {
               t = (t * percentage) / 100;
               if(t >= 0x3e)
               {
                  t = 0x3e;
               }
               if(t == 0)
               {
                  t = 1;
               }
               r_2nd = t;
            }

            percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_decay_rate - 0x80));
            t = m_proph->m_sound_param_as[i].val_s.amp_decay_rate;
            if(m_proph->m_sound_param_as[i].val_s.amp_decay_rate == 0x3f)
            {
               d = 0x3f;
            }
            else
            {
               t = (t * percentage) / 100;
               if(t >= 0x3e)
               {
                  t = 0x3e;
               }
               if(t == 0)
               {
                  t = 1;
               }
               d = t;
            }
       
            percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_sustain_level - 0x80));
            t = m_proph->m_sound_param_as[i].val_s.amp_sustain_level;
            if(m_proph->m_sound_param_as[i].val_s.amp_sustain_level == 0x00)
            {
               s = 0;
            }
            else
            {
               t = (t * percentage) / 100;
              // t = t / 2; no scaling for graphical display
               if(t > 255)
               {
                  t = 255;
               }
               s = t;
            }

            percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_attack_rate - 0x80));
            t = m_proph->m_sound_param_as[i].val_s.amp_attack_rate;
            if(m_proph->m_sound_param_as[i].val_s.amp_attack_rate == 0x00)
            {
               a = 0;
            }
            else
            {
               t = (t * percentage) / 100;
               if(t > 62)
               {
                  t = 62;
               }
               a = t;
            }

            m_vca_env_disp->drawADSR(a, d, s, r, r_2nd, volume,col, o, used_sounds_cnt);
         }
         if (updateVCFGraph == true)
         {
            percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_release_rate - 0x80));
            t = m_proph->m_sound_param_as[i].val_s.filt_release_rate;
            if(m_proph->m_sound_param_as[i].val_s.filt_release_rate == 0x3f)
            {
               r = 0x3f;
            }
            else
            {
               t = (t * percentage) / 100;
               if(t >= 0x3e)
               {
                  t = 0x3e;
               }
               if(t == 0)
               {
                  t = 1;
               }
               r = t;
            }

            percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_2nd_release_rate - 0x80));
            t = m_proph->m_sound_param_as[i].val_s.filt_2nd_release_rate;
            if(m_proph->m_sound_param_as[i].val_s.filt_2nd_release_rate == 0x3f)
            {
               r_2nd = 0x3f;
            }
            else
            {
               t = (t * percentage) / 100;
               if(t >= 0x3e)
               {
                  t = 0x3e;
               }
               if(t == 0)
               {
                  t = 1;
               }
               r_2nd = t;
            }

            percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_decay_rate - 0x80));
            t = m_proph->m_sound_param_as[i].val_s.filt_decay_rate;
            if(m_proph->m_sound_param_as[i].val_s.filt_decay_rate == 0x3f)
            {
               d = 0x3f;
            }
            else
            {
               t = (t * percentage) / 100;
               if(t >= 0x3e)
               {
                  t = 0x3e;
               }
               if(t == 0)
               {
                  t = 1;
               }
               d = t;
            }

            percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_sustain_level - 0x80));
            t = m_proph->m_sound_param_as[i].val_s.filt_sustain_level;
            if(m_proph->m_sound_param_as[i].val_s.filt_sustain_level == 0x00)
            {
               s = 0;
            }
            else
            {
               t = (t * percentage) / 100;
             //  t = t / 2; No scaling for graphical display
              if(t > 255)
               {
                  t = 255;
               }
               s = t;
            }

            percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_attack_rate - 0x80));
            t = m_proph->m_sound_param_as[i].val_s.filt_attack_rate;
            if(m_proph->m_sound_param_as[i].val_s.filt_attack_rate == 0x00)
            {
               a = 0;
            }
            else
            {
               t = (t * percentage) / 100;
               if(t > 62)
               {
                  t = 62;
               }
               a = t;
            }

		    if (!show_vcf_env_amount) 
		    {
			    volume = 255;
			    if (trigger) mySizer->GetStaticBox()->SetLabel("VCF Envelope Graph");
		    }
		    else
		    {
			    if (trigger) mySizer->GetStaticBox()->SetLabel("VCF Envelope Amount");
   /* Doesn't match Prophet implementation */
   /*			 volume = (m_proph->m_sound_param_as[i].val_s.filt_env_amount - 0x80) * 2;
			    percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_env_amount - 0x80));
			    volume = (volume * percentage)/100;
			    if ( volume > 255 ) volume = 255;
			    if ( volume < -255) volume = -255; */
   /* ----- */
             percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_env_amount - 0x80));
             volume = m_proph->m_sound_param_as[i].val_s.filt_env_amount;
             volume = (volume * percentage) / 100;
             volume = (volume - 0x80) * 2;
               if(volume > 255)
               {
                  volume = 255;
               }
               if (volume < -255)
               {
                  volume = -255;
               }

		    }
   		 
		    if (trigger) // Need to refresh top line
		    {
			    m_vcf_env_panel->SetSizer(mySizer);
			    trigger = !trigger;
		    }
          m_vcf_env_disp->drawADSR(a, d, s, r, r_2nd, volume,col, o , used_sounds_cnt);
          }
       o++;
      }
   }
   if (updateVCAGraph == true)
   {
      m_vca_env_disp->Refresh(true);
      updateVCAGraph = false;
   }
   if (updateVCFGraph == true)
   {
      m_vcf_env_disp->Refresh(true);
      updateVCFGraph = false;
   }

//   m_amp_release_rate->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_release_rate - 0x80));
//   m_amp_release_rate_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_release_rate - 0x80)));
//   m_amp_2nd_release_rate->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_2nd_release_rate - 0x80));
//   m_amp_2nd_release_rate_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_2nd_release_rate - 0x80)));
//   m_amp_decay_rate->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_decay_rate - 0x80));
//   m_amp_decay_rate_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_decay_rate - 0x80)));
//   m_amp_sustain_level->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_sustain_level - 0x80));
//   m_amp_sustain_level_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_sustain_level - 0x80)));
//   m_amp_attack_rate->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_attack_rate - 0x80));
//   m_amp_attack_rate_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_attack_rate - 0x80)));
//   m_amp_peak_vel_sensitivity->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_peak_vel_sensitivity - 0x80));
//   m_amp_peak_vel_sensitivity_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_peak_vel_sensitivity - 0x80)));
//   m_filt_release_rate->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_release_rate - 0x80));
//   m_filt_release_rate_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_release_rate - 0x80)));
//   m_filt_2nd_release_rate->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_2nd_release_rate - 0x80));
//   m_filt_2nd_release_rate_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_2nd_release_rate - 0x80)));
//   m_filt_decay_rate->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_decay_rate - 0x80));
//   m_filt_decay_rate_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_decay_rate - 0x80)));
//   m_filt_sustain_level->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_sustain_level - 0x80));
//   m_filt_sustain_level_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_sustain_level - 0x80)));
//   m_filt_attack_rate->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_attack_rate - 0x80));
//   m_filt_attack_rate_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_attack_rate - 0x80)));
//   m_filt_peak_vel_sensitivity->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_peak_vel_sensitivity - 0x80));
//   m_filt_peak_vel_sensitivity_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_peak_vel_sensitivity - 0x80)));
//   m_filt_resonance->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_resonance - 0x80));
//   m_filt_resonance_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_resonance - 0x80)));
//   m_filt_cutoff->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_cutoff - 0x80));
//   m_filt_cutoff_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_cutoff - 0x80)));
//   m_filt_env_amount->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_env_amount - 0x80));
//   m_filt_env_amount_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_env_amount - 0x80)));
//   m_filt_keyboard_tracking->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_keyboard_tracking - 0x80));
//   m_filt_keyboard_tracking_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_keyboard_tracking - 0x80)));

//   m_attack_vel_sensitivity->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.attack_vel_sensitivity - 0x80));
//   m_attack_vel_sensitivity_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.attack_vel_sensitivity - 0x80)));
//   m_release_vel_sensitivity->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.release_vel_sensitivity - 0x80));
//   m_release_vel_sensitivity_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.release_vel_sensitivity - 0x80)));
   
   //str.sprintf("%d", m_proph->m_map_param_as[m_map_u8].val_s.sound_direction);
   //m_sound_direction->SetValue(str);

//   if(m_proph->m_map_param_as[m_map_u8].val_s.sound_direction & 0x08)
//   {
//      m_sound_direction_reversed->SetValue(true);
//   }
//   else
//   {
//      m_sound_direction_reversed->SetValue(false);
//   }

//   m_velocity_start_point->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.velocity_start_point - 0x80));
//   m_velocity_start_point_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.velocity_start_point - 0x80)));

}


uint8_t MapPanelImpl::calcPercentage(int8_t value)
{
   uint8_t percentage;
   if(value >= 0)
   {
      percentage = ((uint16_t)value * 100) / 127;
      percentage += 100;
   }
   else
   {
      value = -value;
      percentage = ((uint16_t)value * 100) / 127;
      percentage = (100 - percentage);
   }

   return percentage;
}

wxString MapPanelImpl::calcPercentageStr(int8_t value)
{
   wxString str;
   uint8_t percentage;
   if(value >= 0)
   {
      percentage = ((uint16_t)value * 100) / 127;
      percentage += 100;
      str.sprintf(wxT("%d%%"), percentage);
   }
   else
   {
      value = -value;
      percentage = ((uint16_t)value * 100) / 127;
      percentage = (100 - percentage);
      str.sprintf(wxT("%d%%"), percentage);
   }

   return str;
}


void MapPanelImpl::OnParamChange(wxCommandEvent &event)
{
}


void MapPanelImpl::OnSliderChange(wxScrollEvent &event)
{
//  m_proph->m_map_param_as[m_map_u8].val_s.amp_release_rate = (int8_t)m_amp_release_rate->GetValue() + 0x80;
//   m_proph->m_map_param_as[m_map_u8].val_s.amp_2nd_release_rate = (int8_t)m_amp_2nd_release_rate->GetValue() + 0x80;
//   m_proph->m_map_param_as[m_map_u8].val_s.amp_decay_rate = (int8_t)m_amp_decay_rate->GetValue() + 0x80;
//   m_proph->m_map_param_as[m_map_u8].val_s.amp_sustain_level = (int8_t)m_amp_sustain_level->GetValue() + 0x80;
//   m_proph->m_map_param_as[m_map_u8].val_s.amp_attack_rate = (int8_t)m_amp_attack_rate->GetValue() + 0x80;
//   m_proph->m_map_param_as[m_map_u8].val_s.amp_peak_vel_sensitivity = (int8_t)m_amp_peak_vel_sensitivity->GetValue() + 0x80;
//   m_proph->m_map_param_as[m_map_u8].val_s.filt_attack_rate = (int8_t)m_filt_attack_rate->GetValue() + 0x80;
//   m_proph->m_map_param_as[m_map_u8].val_s.filt_release_rate = (int8_t)m_filt_release_rate->GetValue() + 0x80;
//   m_proph->m_map_param_as[m_map_u8].val_s.filt_2nd_release_rate = (int8_t)m_filt_2nd_release_rate->GetValue() + 0x80;
//   m_proph->m_map_param_as[m_map_u8].val_s.filt_decay_rate = (int8_t)m_filt_decay_rate->GetValue() + 0x80;
//   m_proph->m_map_param_as[m_map_u8].val_s.filt_sustain_level = (int8_t)m_filt_sustain_level->GetValue() + 0x80;
//   m_proph->m_map_param_as[m_map_u8].val_s.filt_peak_vel_sensitivity = (int8_t)m_filt_peak_vel_sensitivity->GetValue() + 0x80;
//   m_proph->m_map_param_as[m_map_u8].val_s.filt_env_amount = (int8_t)m_filt_env_amount->GetValue() + 0x80;
//   m_proph->m_map_param_as[m_map_u8].val_s.filt_keyboard_tracking = (int8_t)m_filt_keyboard_tracking->GetValue() + 0x80;
//   m_proph->m_map_param_as[m_map_u8].val_s.attack_vel_sensitivity = (int8_t)m_attack_vel_sensitivity->GetValue() + 0x80;
//   m_proph->m_map_param_as[m_map_u8].val_s.release_vel_sensitivity = (int8_t)m_release_vel_sensitivity->GetValue() + 0x80;
//   m_proph->m_map_param_as[m_map_u8].val_s.velocity_start_point = (int8_t)m_velocity_start_point->GetValue() + 0x80;
//   m_proph->m_map_param_as[m_map_u8].val_s.filt_cutoff = (int8_t)m_filt_cutoff->GetValue() + 0x80;
//   m_proph->m_map_param_as[m_map_u8].val_s.filt_resonance = (int8_t)m_filt_resonance->GetValue() + 0x80;

//   m_proph->updateParamBytesFromStruct();
// //   updateGUI();
/* Good code 
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferMap2Proph(m_map_u8))
      {
         m_topframe->transferStarted();
      }
   }
   updateGUI();
*/
}


void MapPanelImpl::OnCheckboxChange(wxCommandEvent& event)
{
   
   if(!m_sound_direction_reversed->GetValue())
   {
      m_proph->m_map_param_as[m_map_u8].val_s.sound_direction = m_proph->m_map_param_as[m_map_u8].val_s.sound_direction & (~0x08);
      if(m_proph->getStereoMode())
      {
         if(m_map_u8 < 8)
         {
            m_proph->m_map_param_as[m_map_u8 + 8].val_s.sound_direction = m_proph->m_map_param_as[m_map_u8].val_s.sound_direction & (~0x08);
         }
         else
         {
            m_proph->m_map_param_as[m_map_u8 - 8].val_s.sound_direction = m_proph->m_map_param_as[m_map_u8].val_s.sound_direction & (~0x08);
         }
      }
   }
   else
   {
      m_proph->m_map_param_as[m_map_u8].val_s.sound_direction |= 0x08;
      if(m_proph->getStereoMode())
      {
         if(m_map_u8 < 8)
         {
            m_proph->m_map_param_as[m_map_u8 + 8].val_s.sound_direction |= 0x08;
         }
         else
         {
            m_proph->m_map_param_as[m_map_u8 - 8].val_s.sound_direction |= 0x08;
         }
      }
   }

   m_proph->updateParamBytesFromStruct();
   updateGUI();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferMap2Proph(m_map_u8))
      {
         m_topframe->transferStarted();
      }
   }
}

void MapPanelImpl::OnAmpAttackSliderChange(wxScrollEvent& event)
{
   m_proph->m_map_param_as[m_map_u8].val_s.amp_attack_rate = (int8_t)m_amp_attack_rate->GetValue() + 0x80;
   if(m_proph->getStereoMode())
   {
      if(m_map_u8 < 8)
      {
         m_proph->m_map_param_as[m_map_u8 + 8].val_s.amp_attack_rate = (int8_t)m_amp_attack_rate->GetValue() + 0x80;
      }
      else
      {
         m_proph->m_map_param_as[m_map_u8 - 8].val_s.amp_attack_rate = (int8_t)m_amp_attack_rate->GetValue() + 0x80;
      }
   }
//   m_amp_attack_rate->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_attack_rate - 0x80));
   m_amp_attack_rate_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_attack_rate - 0x80)));
   updateVCAGraph = true;
   m_proph->updateParamBytesFromStruct();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferMap2Proph(m_map_u8))
      {
         m_topframe->transferStarted();
      }
   }
   updateGUI();
}

void MapPanelImpl::OnAmpDecaySliderChange(wxScrollEvent& event)
{
   m_proph->m_map_param_as[m_map_u8].val_s.amp_decay_rate = (int8_t)m_amp_decay_rate->GetValue() + 0x80;
   if(m_proph->getStereoMode())
   {
      if(m_map_u8 < 8)
      {
         m_proph->m_map_param_as[m_map_u8 + 8].val_s.amp_decay_rate = (int8_t)m_amp_decay_rate->GetValue() + 0x80;
      }
      else
      {
         m_proph->m_map_param_as[m_map_u8 - 8].val_s.amp_decay_rate = (int8_t)m_amp_decay_rate->GetValue() + 0x80;
      }
   }
//   m_amp_decay_rate->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_decay_rate - 0x80));
   m_amp_decay_rate_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_decay_rate - 0x80)));
   updateVCAGraph = true;
   m_proph->updateParamBytesFromStruct();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferMap2Proph(m_map_u8))
      {
         m_topframe->transferStarted();
      }
   }
   updateGUI();
}

void MapPanelImpl::OnAmpSustainSliderChange(wxScrollEvent& event)
{
   m_proph->m_map_param_as[m_map_u8].val_s.amp_sustain_level = (int8_t)m_amp_sustain_level->GetValue() + 0x80;
   if(m_proph->getStereoMode())
   {
      if(m_map_u8 < 8)
      {
         m_proph->m_map_param_as[m_map_u8 + 8].val_s.amp_sustain_level = (int8_t)m_amp_sustain_level->GetValue() + 0x80;
      }
      else
      {
         m_proph->m_map_param_as[m_map_u8 - 8].val_s.amp_sustain_level = (int8_t)m_amp_sustain_level->GetValue() + 0x80;
      }
   }
//   m_amp_sustain_level->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_sustain_level - 0x80));
   m_amp_sustain_level_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_sustain_level - 0x80)));
   updateVCAGraph = true;
   m_proph->updateParamBytesFromStruct();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferMap2Proph(m_map_u8))
      {
         m_topframe->transferStarted();
      }
   }
   updateGUI();
}

void MapPanelImpl::OnAmpReleaseSliderChange(wxScrollEvent& event)
{
   m_proph->m_map_param_as[m_map_u8].val_s.amp_release_rate = (int8_t)m_amp_release_rate->GetValue() + 0x80;
   if(m_proph->getStereoMode())
   {
      if(m_map_u8 < 8)
      {
         m_proph->m_map_param_as[m_map_u8 + 8].val_s.amp_release_rate = (int8_t)m_amp_release_rate->GetValue() + 0x80;
      }
      else
      {
         m_proph->m_map_param_as[m_map_u8 - 8].val_s.amp_release_rate = (int8_t)m_amp_release_rate->GetValue() + 0x80;
      }
   }
//   m_amp_release_rate->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_release_rate - 0x80));
   m_amp_release_rate_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_release_rate - 0x80)));
   updateVCAGraph = true;
   m_proph->updateParamBytesFromStruct();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferMap2Proph(m_map_u8))
      {
         m_topframe->transferStarted();
      }
   }
   updateGUI();
}

void MapPanelImpl::OnAmpAltReleaseSliderChange(wxScrollEvent& event)
{
   m_proph->m_map_param_as[m_map_u8].val_s.amp_2nd_release_rate = (int8_t)m_amp_2nd_release_rate->GetValue() + 0x80;
   if(m_proph->getStereoMode())
   {
      if(m_map_u8 < 8)
      {
         m_proph->m_map_param_as[m_map_u8 + 8].val_s.amp_2nd_release_rate = (int8_t)m_amp_2nd_release_rate->GetValue() + 0x80;
      }
      else
      {
         m_proph->m_map_param_as[m_map_u8 - 8].val_s.amp_2nd_release_rate = (int8_t)m_amp_2nd_release_rate->GetValue() + 0x80;
      }
   }
//   m_amp_2nd_release_rate->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_2nd_release_rate - 0x80));
   m_amp_2nd_release_rate_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_2nd_release_rate - 0x80)));
   updateVCAGraph = true;
   m_proph->updateParamBytesFromStruct();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferMap2Proph(m_map_u8))
      {
         m_topframe->transferStarted();
      }
   }
   updateGUI();

}

void MapPanelImpl::OnFilterAttackSliderChange(wxScrollEvent& event)
{
   m_proph->m_map_param_as[m_map_u8].val_s.filt_attack_rate = (int8_t)m_filt_attack_rate->GetValue() + 0x80;
   if(m_proph->getStereoMode())
   {
      if(m_map_u8 < 8)
      {
         m_proph->m_map_param_as[m_map_u8 + 8].val_s.filt_attack_rate = (int8_t)m_filt_attack_rate->GetValue() + 0x80;
      }
      else
      {
         m_proph->m_map_param_as[m_map_u8 - 8].val_s.filt_attack_rate = (int8_t)m_filt_attack_rate->GetValue() + 0x80;
      }
   }
//   m_filt_attack_rate->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_attack_rate - 0x80));
   m_filt_attack_rate_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_attack_rate - 0x80)));
   updateVCFGraph = true;
   m_proph->updateParamBytesFromStruct();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferMap2Proph(m_map_u8))
      {
         m_topframe->transferStarted();
      }
   }
   updateGUI();
}

void MapPanelImpl::OnFilterDecaySliderChange(wxScrollEvent& event)
{
   m_proph->m_map_param_as[m_map_u8].val_s.filt_decay_rate = (int8_t)m_filt_decay_rate->GetValue() + 0x80;
   if(m_proph->getStereoMode())
   {
      if(m_map_u8 < 8)
      {
         m_proph->m_map_param_as[m_map_u8 + 8].val_s.filt_decay_rate = (int8_t)m_filt_decay_rate->GetValue() + 0x80;
      }
      else
      {
         m_proph->m_map_param_as[m_map_u8 - 8].val_s.filt_decay_rate = (int8_t)m_filt_decay_rate->GetValue() + 0x80;
      }
   }
//   m_filt_decay_rate->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_decay_rate - 0x80));
   m_filt_decay_rate_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_decay_rate - 0x80)));
   updateVCFGraph = true;
   m_proph->updateParamBytesFromStruct();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferMap2Proph(m_map_u8))
      {
         m_topframe->transferStarted();
      }
   }
   updateGUI();
}

void MapPanelImpl::OnFilterSustainSliderChange(wxScrollEvent& event)
{
   m_proph->m_map_param_as[m_map_u8].val_s.filt_sustain_level = (int8_t)m_filt_sustain_level->GetValue() + 0x80;
   if(m_proph->getStereoMode())
   {
      if(m_map_u8 < 8)
      {
         m_proph->m_map_param_as[m_map_u8 + 8].val_s.filt_sustain_level = (int8_t)m_filt_sustain_level->GetValue() + 0x80;
      }
      else
      {
         m_proph->m_map_param_as[m_map_u8 - 8].val_s.filt_sustain_level = (int8_t)m_filt_sustain_level->GetValue() + 0x80;
      }
   }
//   m_filt_sustain_level->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_sustain_level - 0x80));
   m_filt_sustain_level_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_sustain_level - 0x80)));
   updateVCFGraph = true;
   m_proph->updateParamBytesFromStruct();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferMap2Proph(m_map_u8))
      {
         m_topframe->transferStarted();
      }
   }
   updateGUI();
}

void MapPanelImpl::OnFilterReleaseSliderChange(wxScrollEvent& event)
{
   m_proph->m_map_param_as[m_map_u8].val_s.filt_release_rate = (int8_t)m_filt_release_rate->GetValue() + 0x80;
   if(m_proph->getStereoMode())
   {
      if(m_map_u8 < 8)
      {
         m_proph->m_map_param_as[m_map_u8 + 8].val_s.filt_release_rate = (int8_t)m_filt_release_rate->GetValue() + 0x80;
      }
      else
      {
         m_proph->m_map_param_as[m_map_u8 - 8].val_s.filt_release_rate = (int8_t)m_filt_release_rate->GetValue() + 0x80;
      }
   }
//   m_filt_release_rate->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_release_rate - 0x80));
   m_filt_release_rate_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_release_rate - 0x80)));
   updateVCFGraph = true;
   m_proph->updateParamBytesFromStruct();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferMap2Proph(m_map_u8))
      {
         m_topframe->transferStarted();
      }
   }
   updateGUI();
}

void MapPanelImpl::OnFilterAltReleaseSliderChange(wxScrollEvent& event)
{
   m_proph->m_map_param_as[m_map_u8].val_s.filt_2nd_release_rate = (int8_t)m_filt_2nd_release_rate->GetValue() + 0x80;
   if(m_proph->getStereoMode())
   {
      if(m_map_u8 < 8)
      {
         m_proph->m_map_param_as[m_map_u8 + 8].val_s.filt_2nd_release_rate = (int8_t)m_filt_2nd_release_rate->GetValue() + 0x80;
      }
      else
      {
         m_proph->m_map_param_as[m_map_u8 - 8].val_s.filt_2nd_release_rate = (int8_t)m_filt_2nd_release_rate->GetValue() + 0x80;
      }
   }
//   m_filt_2nd_release_rate->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_2nd_release_rate - 0x80));
   m_filt_2nd_release_rate_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_2nd_release_rate - 0x80)));

   updateVCFGraph = true;
   m_proph->updateParamBytesFromStruct();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferMap2Proph(m_map_u8))
      {
         m_topframe->transferStarted();
      }
   }
   updateGUI();
}

void MapPanelImpl::OnFilterCutoffSliderChange(wxScrollEvent& event)
{
   m_proph->m_map_param_as[m_map_u8].val_s.filt_cutoff = (int8_t)m_filt_cutoff->GetValue() + 0x80;
   if(m_proph->getStereoMode())
   {
      if(m_map_u8 < 8)
      {
         m_proph->m_map_param_as[m_map_u8 + 8].val_s.filt_cutoff = (int8_t)m_filt_cutoff->GetValue() + 0x80;
      }
      else
      {
         m_proph->m_map_param_as[m_map_u8 - 8].val_s.filt_cutoff = (int8_t)m_filt_cutoff->GetValue() + 0x80;
      }
   }
//   m_filt_cutoff->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_cutoff - 0x80));
   m_filt_cutoff_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_cutoff - 0x80)));
   m_proph->updateParamBytesFromStruct();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferMap2Proph(m_map_u8))
      {
         m_topframe->transferStarted();
      }
   }
   updateGUI();
}

void MapPanelImpl::OnFilterResonanceSliderChange(wxScrollEvent& event)
{
   m_proph->m_map_param_as[m_map_u8].val_s.filt_resonance = (int8_t)m_filt_resonance->GetValue() + 0x80;
   if(m_proph->getStereoMode())
   {
      if(m_map_u8 < 8)
      {
         m_proph->m_map_param_as[m_map_u8 + 8].val_s.filt_resonance = (int8_t)m_filt_resonance->GetValue() + 0x80;
      }
      else
      {
         m_proph->m_map_param_as[m_map_u8 - 8].val_s.filt_resonance = (int8_t)m_filt_resonance->GetValue() + 0x80;
      }
   }
//   m_filt_resonance->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_resonance - 0x80));
   m_filt_resonance_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_resonance - 0x80)));
   m_proph->updateParamBytesFromStruct();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferMap2Proph(m_map_u8))
      {
         m_topframe->transferStarted();
      }
   }
   updateGUI();
}

void MapPanelImpl::OnFilterEnvelopeAmountSliderChange(wxScrollEvent& event)
{
   m_proph->m_map_param_as[m_map_u8].val_s.filt_env_amount = (int8_t)m_filt_env_amount->GetValue() + 0x80;
   if(m_proph->getStereoMode())
   {
      if(m_map_u8 < 8)
      {
         m_proph->m_map_param_as[m_map_u8 + 8].val_s.filt_env_amount = (int8_t)m_filt_env_amount->GetValue() + 0x80;
      }
      else
      {
         m_proph->m_map_param_as[m_map_u8 - 8].val_s.filt_env_amount = (int8_t)m_filt_env_amount->GetValue() + 0x80;
      }
   }
//   m_filt_env_amount->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_env_amount - 0x80));
   m_filt_env_amount_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_env_amount - 0x80)));
   updateVCFGraph = true;
   m_proph->updateParamBytesFromStruct();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferMap2Proph(m_map_u8))
      {
         m_topframe->transferStarted();
      }
   }
   updateGUI();
}

void MapPanelImpl::OnFilterKeyboardTrackSliderChange(wxScrollEvent& event)
{
   m_proph->m_map_param_as[m_map_u8].val_s.filt_keyboard_tracking = (int8_t)m_filt_keyboard_tracking->GetValue() + 0x80;
   if(m_proph->getStereoMode())
   {
      if(m_map_u8 < 8)
      {
         m_proph->m_map_param_as[m_map_u8 + 8].val_s.filt_keyboard_tracking = (int8_t)m_filt_keyboard_tracking->GetValue() + 0x80;
      }
      else
      {
         m_proph->m_map_param_as[m_map_u8 - 8].val_s.filt_keyboard_tracking = (int8_t)m_filt_keyboard_tracking->GetValue() + 0x80;
      }
   }
//   m_filt_keyboard_tracking->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_keyboard_tracking - 0x80));
   m_filt_keyboard_tracking_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_keyboard_tracking - 0x80)));
   m_proph->updateParamBytesFromStruct();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferMap2Proph(m_map_u8))
      {
         m_topframe->transferStarted();
      }
   }
   updateGUI();
}

void MapPanelImpl::OnVelocityAttackSliderChange(wxScrollEvent& event)
{
   m_proph->m_map_param_as[m_map_u8].val_s.attack_vel_sensitivity = (int8_t)m_attack_vel_sensitivity->GetValue() + 0x80;
   if(m_proph->getStereoMode())
   {
      if(m_map_u8 < 8)
      {
         m_proph->m_map_param_as[m_map_u8 + 8].val_s.attack_vel_sensitivity = (int8_t)m_attack_vel_sensitivity->GetValue() + 0x80;
      }
      else
      {
         m_proph->m_map_param_as[m_map_u8 - 8].val_s.attack_vel_sensitivity = (int8_t)m_attack_vel_sensitivity->GetValue() + 0x80;
      }
   }
//   m_attack_vel_sensitivity->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.attack_vel_sensitivity - 0x80));
   m_attack_vel_sensitivity_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.attack_vel_sensitivity - 0x80)));
   m_proph->updateParamBytesFromStruct();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferMap2Proph(m_map_u8))
      {
         m_topframe->transferStarted();
      }
   }
   updateGUI();
}

void MapPanelImpl::OnVelocityReleaseSliderChange(wxScrollEvent& event)
{
   m_proph->m_map_param_as[m_map_u8].val_s.release_vel_sensitivity = (int8_t)m_release_vel_sensitivity->GetValue() + 0x80;
   if(m_proph->getStereoMode())
   {
      if(m_map_u8 < 8)
      {
         m_proph->m_map_param_as[m_map_u8 + 8].val_s.release_vel_sensitivity = (int8_t)m_release_vel_sensitivity->GetValue() + 0x80;
      }
      else
      {
         m_proph->m_map_param_as[m_map_u8 - 8].val_s.release_vel_sensitivity = (int8_t)m_release_vel_sensitivity->GetValue() + 0x80;
      }
   }
//   m_release_vel_sensitivity->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.release_vel_sensitivity - 0x80));
   m_release_vel_sensitivity_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.release_vel_sensitivity - 0x80)));
   m_proph->updateParamBytesFromStruct();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferMap2Proph(m_map_u8))
      {
         m_topframe->transferStarted();
      }
   }
   updateGUI();
}

void MapPanelImpl::OnVelocityVCAPeakSliderChange(wxScrollEvent& event)
{
   m_proph->m_map_param_as[m_map_u8].val_s.amp_peak_vel_sensitivity = (int8_t)m_amp_peak_vel_sensitivity->GetValue() + 0x80;
   if(m_proph->getStereoMode())
   {
      if(m_map_u8 < 8)
      {
         m_proph->m_map_param_as[m_map_u8 + 8].val_s.amp_peak_vel_sensitivity = (int8_t)m_amp_peak_vel_sensitivity->GetValue() + 0x80;
      }
      else
      {
         m_proph->m_map_param_as[m_map_u8 - 8].val_s.amp_peak_vel_sensitivity = (int8_t)m_amp_peak_vel_sensitivity->GetValue() + 0x80;
      }
   }
//   m_amp_peak_vel_sensitivity->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_peak_vel_sensitivity - 0x80));
   m_amp_peak_vel_sensitivity_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_peak_vel_sensitivity - 0x80)));
   m_proph->updateParamBytesFromStruct();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferMap2Proph(m_map_u8))
      {
         m_topframe->transferStarted();
      }
   }
   updateGUI();

}

void MapPanelImpl::OnVelocityVFCPeakSliderChange(wxScrollEvent& event)
{
   m_proph->m_map_param_as[m_map_u8].val_s.filt_peak_vel_sensitivity = (int8_t)m_filt_peak_vel_sensitivity->GetValue() + 0x80;
   if(m_proph->getStereoMode())
   {
      if(m_map_u8 < 8)
      {
         m_proph->m_map_param_as[m_map_u8 + 8].val_s.filt_peak_vel_sensitivity = (int8_t)m_filt_peak_vel_sensitivity->GetValue() + 0x80;
      }
      else
      {
         m_proph->m_map_param_as[m_map_u8 - 8].val_s.filt_peak_vel_sensitivity = (int8_t)m_filt_peak_vel_sensitivity->GetValue() + 0x80;
      }
   }
//   m_filt_peak_vel_sensitivity->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_peak_vel_sensitivity - 0x80));
   m_filt_peak_vel_sensitivity_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_peak_vel_sensitivity - 0x80)));
   m_proph->updateParamBytesFromStruct();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferMap2Proph(m_map_u8))
      {
         m_topframe->transferStarted();
      }
   }
   updateGUI();
}

void MapPanelImpl::OnVelocitySampleStartSliderChange(wxScrollEvent& event)
{
   m_proph->m_map_param_as[m_map_u8].val_s.velocity_start_point = (int8_t)m_velocity_start_point->GetValue() + 0x80;
   if(m_proph->getStereoMode())
   {
      if(m_map_u8 < 8)
      {
         m_proph->m_map_param_as[m_map_u8 + 8].val_s.velocity_start_point = (int8_t)m_velocity_start_point->GetValue() + 0x80;
      }
      else
      {
         m_proph->m_map_param_as[m_map_u8 - 8].val_s.velocity_start_point = (int8_t)m_velocity_start_point->GetValue() + 0x80;
      }
   }
//   m_velocity_start_point->SetValue((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.velocity_start_point - 0x80));
   m_velocity_start_point_percentage->SetValue(calcPercentageStr((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.velocity_start_point - 0x80)));
   m_proph->updateParamBytesFromStruct();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferMap2Proph(m_map_u8))
      {
         m_topframe->transferStarted();
      }
   }
   updateGUI();
}



void MapPanelImpl::OnLoad(wxCommandEvent& event)
{
   m_mapparam->OnLoad(event);
}

void MapPanelImpl::OnSave(wxCommandEvent& event)
{
   m_mapparam->OnSave(event);
}


void MapPanelImpl::OnCopy(wxCommandEvent& event)
{
   m_mapparam->OnCopy(event);
}


void MapPanelImpl::OnSelectMap1(wxCommandEvent& event)
{
   deselectAllMapButtons();
   m_select_map_1->SetValue(true);
   m_mapparam->activateMap(0);
}

void MapPanelImpl::OnSelectMap2(wxCommandEvent& event)
{
   deselectAllMapButtons();
   m_select_map_2->SetValue(true);
   m_mapparam->activateMap(1);
}

void MapPanelImpl::OnSelectMap3(wxCommandEvent& event)
{
   deselectAllMapButtons();
   m_select_map_3->SetValue(true);
   m_mapparam->activateMap(2);
}

void MapPanelImpl::OnSelectMap4(wxCommandEvent& event)
{
   deselectAllMapButtons();
   m_select_map_4->SetValue(true);
   m_mapparam->activateMap(3);
}

void MapPanelImpl::OnSelectMap5(wxCommandEvent& event)
{
   deselectAllMapButtons();
   m_select_map_5->SetValue(true);
   m_mapparam->activateMap(4);
}

void MapPanelImpl::OnSelectMap6(wxCommandEvent& event)
{
   deselectAllMapButtons();
   m_select_map_6->SetValue(true);
   m_mapparam->activateMap(5);
}

void MapPanelImpl::OnSelectMap7(wxCommandEvent& event)
{
   deselectAllMapButtons();
   m_select_map_7->SetValue(true);
   m_mapparam->activateMap(6);
}

void MapPanelImpl::OnSelectMap8(wxCommandEvent& event)
{
   deselectAllMapButtons();
   m_select_map_8->SetValue(true);
   m_mapparam->activateMap(7);
}

void MapPanelImpl::OnSelectMap9(wxCommandEvent& event)
{
   deselectAllMapButtons();
   m_select_map_9->SetValue(true);
   m_mapparam->activateMap(8);
}

void MapPanelImpl::OnSelectMap10(wxCommandEvent& event)
{
   deselectAllMapButtons();
   m_select_map_10->SetValue(true);
   m_mapparam->activateMap(9);
}

void MapPanelImpl::OnSelectMap11(wxCommandEvent& event)
{
   deselectAllMapButtons();
   m_select_map_11->SetValue(true);
   m_mapparam->activateMap(10);
}

void MapPanelImpl::OnSelectMap12(wxCommandEvent& event)
{
   deselectAllMapButtons();
   m_select_map_12->SetValue(true);
   m_mapparam->activateMap(11);
}

void MapPanelImpl::OnSelectMap13(wxCommandEvent& event)
{
   deselectAllMapButtons();
   m_select_map_13->SetValue(true);
   m_mapparam->activateMap(12);
}

void MapPanelImpl::OnSelectMap14(wxCommandEvent& event)
{
   deselectAllMapButtons();
   m_select_map_14->SetValue(true);
   m_mapparam->activateMap(13);
}

void MapPanelImpl::OnSelectMap15(wxCommandEvent& event)
{
   deselectAllMapButtons();
   m_select_map_15->SetValue(true);
   m_mapparam->activateMap(14);
}

void MapPanelImpl::OnSelectMap16(wxCommandEvent& event)
{
   deselectAllMapButtons();
   m_select_map_16->SetValue(true);
   m_mapparam->activateMap(15);
}

void MapPanelImpl::OnLeftDown(wxMouseEvent& event)
{
	show_vcf_env_amount = !show_vcf_env_amount;
   updateVCFGraph = true;
	trigger = true;
	updateGUI();
}
void MapPanelImpl::deselectAllMapButtons(void)
{
   m_select_map_1->SetValue(false);
   m_select_map_2->SetValue(false);
   m_select_map_3->SetValue(false);
   m_select_map_4->SetValue(false);
   m_select_map_5->SetValue(false);
   m_select_map_6->SetValue(false);
   m_select_map_7->SetValue(false);
   m_select_map_8->SetValue(false);
   m_select_map_9->SetValue(false);
   m_select_map_10->SetValue(false);
   m_select_map_11->SetValue(false);
   m_select_map_12->SetValue(false);
   m_select_map_13->SetValue(false);
   m_select_map_14->SetValue(false);
   m_select_map_15->SetValue(false);
   m_select_map_16->SetValue(false);
}

void MapPanelImpl::updateUsedSounds(uint8_t soundID, bool status)
{
   switch(soundID)
	   {
		case 0:
			m_using_snd_1->SetLabel(wxT("1"));
         if(status)
         {
			   m_using_snd_1->SetValue(true);
         }
         else
         {
			   m_using_snd_1->SetValue(false);
         }
			break;
		case 1:
			m_using_snd_2->SetLabel(wxT("2"));
         if(status)
         {
			   m_using_snd_2->SetValue(true);
         }
         else
         {
			   m_using_snd_2->SetValue(false);
         }
			break;
		case 2:
			m_using_snd_3->SetLabel(wxT("3"));
         if(status)
         {
			   m_using_snd_3->SetValue(true);
         }
         else
         {
			   m_using_snd_3->SetValue(false);
         }
			break;
		case 3:
			m_using_snd_4->SetLabel(wxT("4"));
         if(status)
         {
			   m_using_snd_4->SetValue(true);
         }
         else
         {
			   m_using_snd_4->SetValue(false);
         }
			break;
		case 4:
			m_using_snd_5->SetLabel(wxT("5"));
         if(status)
         {
			   m_using_snd_5->SetValue(true);
         }
         else
         {
			   m_using_snd_5->SetValue(false);
         }
			break;
		case 5:
			m_using_snd_6->SetLabel(wxT("6"));
         if(status)
         {
			   m_using_snd_6->SetValue(true);
         }
         else
         {
			   m_using_snd_6->SetValue(false);
         }
			break;
		case 6:
			m_using_snd_7->SetLabel(wxT("7"));
         if(status)
         {
			   m_using_snd_7->SetValue(true);
         }
         else
         {
			   m_using_snd_7->SetValue(false);
         }
			break;
		case 7:
			m_using_snd_8->SetLabel(wxT("8"));
         if(status)
         {
			   m_using_snd_8->SetValue(true);
         }
         else
         {
			   m_using_snd_8->SetValue(false);
         }
			break;
		case 8:
			m_using_snd_1->SetLabel(wxT("9"));
         if(status)
         {
			   m_using_snd_1->SetValue(true);
         }
         else
         {
			   m_using_snd_1->SetValue(false);
         }
			break;
		case 9:
			m_using_snd_2->SetLabel(wxT("10"));
         if(status)
         {
			   m_using_snd_2->SetValue(true);
         }
         else
         {
			   m_using_snd_2->SetValue(false);
         }
			break;
		case 10:
			m_using_snd_3->SetLabel(wxT("11"));
         if(status)
         {
			   m_using_snd_3->SetValue(true);
         }
         else
         {
			   m_using_snd_3->SetValue(false);
         }
			break;
		case 11:
			m_using_snd_4->SetLabel(wxT("12"));
         if(status)
         {
			   m_using_snd_4->SetValue(true);
         }
         else
         {
			   m_using_snd_4->SetValue(false);
         }
			break;
		case 12:
			m_using_snd_5->SetLabel(wxT("13"));
         if(status)
         {
			   m_using_snd_5->SetValue(true);
         }
         else
         {
			   m_using_snd_5->SetValue(false);
         }
			break;
		case 13:
			m_using_snd_6->SetLabel(wxT("14"));
         if(status)
         {
			   m_using_snd_6->SetValue(true);
         }
         else
         {
			   m_using_snd_6->SetValue(false);
         }
			break;
		case 14:
			m_using_snd_7->SetLabel(wxT("15"));
         if(status)
         {
			   m_using_snd_7->SetValue(true);
         }
         else
         {
			   m_using_snd_7->SetValue(false);
         }
			break;
		case 15:
			m_using_snd_8->SetLabel(wxT("16"));
         if(status)
         {
			   m_using_snd_8->SetValue(true);
         }
         else
         {
			   m_using_snd_8->SetValue(false);
         }
			break;
	   default: break;
	   }
}

void MapPanelImpl::OnUsingSound1(wxCommandEvent& event)
{
   if(m_map_u8 < 8)
   {
      m_topframe->activateSoundOnGui(0);
   }
   else
   {
      m_topframe->activateSoundOnGui(0 + 8);
   }
}

void MapPanelImpl::OnUsingSound2(wxCommandEvent& event)
{
   if(m_map_u8 < 8)
   {
      m_topframe->activateSoundOnGui(1);
   }
   else
   {
      m_topframe->activateSoundOnGui(1 + 8);
   }
}

void MapPanelImpl::OnUsingSound3(wxCommandEvent& event)
{
   if(m_map_u8 < 8)
   {
      m_topframe->activateSoundOnGui(2);
   }
   else
   {
      m_topframe->activateSoundOnGui(2 + 8);
   }
}

void MapPanelImpl::OnUsingSound4(wxCommandEvent& event)
{
   if(m_map_u8 < 8)
   {
      m_topframe->activateSoundOnGui(3);
   }
   else
   {
      m_topframe->activateSoundOnGui(3 + 8);
   }
}

void MapPanelImpl::OnUsingSound5(wxCommandEvent& event)
{
   if(m_map_u8 < 8)
   {
      m_topframe->activateSoundOnGui(4);
   }
   else
   {
      m_topframe->activateSoundOnGui(4 + 8);
   }
}

void MapPanelImpl::OnUsingSound6(wxCommandEvent& event)
{
   if(m_map_u8 < 8)
   {
      m_topframe->activateSoundOnGui(5);
   }
   else
   {
      m_topframe->activateSoundOnGui(5 + 8);
   }
}

void MapPanelImpl::OnUsingSound7(wxCommandEvent& event)
{
   if(m_map_u8 < 8)
   {
      m_topframe->activateSoundOnGui(6);
   }
   else
   {
      m_topframe->activateSoundOnGui(6 + 8);
   }
}

void MapPanelImpl::OnUsingSound8(wxCommandEvent& event)
{
   if(m_map_u8 < 8)
   {
      m_topframe->activateSoundOnGui(7);
   }
   else
   {
      m_topframe->activateSoundOnGui(7 + 8);
   }
}



