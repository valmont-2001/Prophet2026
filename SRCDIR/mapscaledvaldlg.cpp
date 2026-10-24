#include "types.h"
#include <wx/wx.h>
#include "GUILayout.h"
#include "mapscaledvaldlg.h"
#include "stopwatch.h"
#include "proph2000.h"


MapScaleValuesDlg::MapScaleValuesDlg(wxWindow* parent, wxWindowID id, Proph2000 *proph, uint8_t sound_u8, uint8_t map_u8, const wxPoint& pos) :
   MapScaledValuesDialog(parent),
   m_proph(proph), m_sound_u8(sound_u8), m_map_u8(map_u8)
{
   wxString str;
   str.sprintf(wxT("Scaled Values of Sound %d"), sound_u8 + 1);
   SetTitle(str);
   show_vcf_env_amount = false;
   updateGUI();
}


MapScaleValuesDlg::~MapScaleValuesDlg()
{
}


uint8_t MapScaleValuesDlg::calcPercentage(int8_t value)
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

void MapScaleValuesDlg::updateGUI(void)
{
   wxString str;
   uint8_t percentage;
   int16_t t;

   uint8_t vca_a;
   uint8_t vca_d;
   uint8_t vca_s;
   uint8_t vca_r;
   uint8_t vca_r_2nd;
   uint8_t volume_in_map;

   uint8_t vcf_a;
   uint8_t vcf_d;
   uint8_t vcf_s;
   uint8_t vcf_r;
   uint8_t vcf_r_2nd;

   int16_t vcf_env_amount;
   int16_t vcf_unscaled_env_amount;
   wxStaticBoxSizer* mySizer;
   mySizer=(wxStaticBoxSizer*)m_vcf_env_panel->GetSizer();			


// Determine volume level of sound in map

   switch(m_map_u8)
      {
         case 0:
             volume_in_map = m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map1;
			 break;
         case 1:
             volume_in_map = m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map2;
             break;
         case 2:
             volume_in_map = m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map3;
	         break;
         case 3:
             volume_in_map = m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map4;
			 break;
         case 4:
             volume_in_map = m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map5;
	         break;
         case 5:
			 volume_in_map = m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map6;
	         break;
         case 6:
             volume_in_map = m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map7;
	         break;
         case 7:
			 volume_in_map = m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map8;
	         break;
         case 8:
             volume_in_map = m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map1;
			 break;
         case 9:
			 volume_in_map = m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map2;
			 break;
         case 10:
			 volume_in_map = m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map3;
			 break;
         case 11:
			 volume_in_map = m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map4;
			 break;
         case 12:
			 volume_in_map = m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map5;
			 break;
         case 13:
			 volume_in_map = m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map6;
			 break;
         case 14:
			 volume_in_map = m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map7;
			 break;
         case 15:
			 volume_in_map = m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map8;
			 break;
      }

// volume_in_map is containing volume level now
   
   percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_release_rate - 0x80));
   t = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_release_rate;
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_release_rate == 0x3f)
   {
      str = wxT("INF");
      vca_r = 0x3f;
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
      vca_r = t;
      str.sprintf(wxT("%d"), t);
   }
   m_amp_release_rate->SetValue(str);

   percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_2nd_release_rate - 0x80));
   t = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_2nd_release_rate;
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_2nd_release_rate == 0x3f)
   {
      str = wxT("INF");
      vca_r_2nd = 0x3f;
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
      vca_r_2nd = t;
      str.sprintf(wxT("%d"), t);
   }
   m_amp_2nd_release_rate->SetValue(str);

   percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_decay_rate - 0x80));
   t = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_decay_rate;
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_decay_rate == 0x3f)
   {
      str = wxT("INF");
      vca_d = 0x3f;
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
      vca_d = t;
      str.sprintf(wxT("%d"), t);
   }
   m_amp_decay_rate->SetValue(str);


   percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_sustain_level - 0x80));
   t = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_sustain_level;
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_sustain_level == 0x00)
   {
      str = wxT("OFF");
      vca_s = 0;
   }
   else
   {
      t = (t * percentage) / 100;
      t = t / 2; // Burt: This will reduce the sustain level always by 50% to accomodate the 
	             // Prophet 2000 displayed value vs. the real data value
      vca_s = t *2;
      if(vca_s > 255)
      {
         vca_s = 255;
      }
      if(t > 127)
      {
         t = 127;
      }
      str.sprintf(wxT("%d"), t);
   }
   m_amp_sustain_level->SetValue(str);


   percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_attack_rate - 0x80));
   t = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_attack_rate;
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_attack_rate == 0x00)
   {
      str = wxT("INST.");
      vca_a = 0;
   }
   else
   {
      t = (t * percentage) / 100;
      if(t > 62)
      {
         t = 62;
      }
      vca_a = t;
      if(t > 0)
      {
         str.sprintf(wxT("%d"), t);
      }
      else
      {
         str = wxT("INST.");
      }
   }
   m_amp_attack_rate->SetValue(str);

   m_vca_env_disp->clearView();

   wxColour col;

   switch(m_sound_u8)
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

   wxColour origcol;
   origcol = wxColour(255, 255, 255);

   /* we need to draw from front to back to have the original graph in back */
   

   m_vca_env_disp->drawADSR(vca_a, vca_d, vca_s, vca_r, vca_r_2nd,volume_in_map, col, 0, 2);


   m_vca_env_disp->drawADSR(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_attack_rate,
         m_proph->m_sound_param_as[m_sound_u8].val_s.amp_decay_rate,
         m_proph->m_sound_param_as[m_sound_u8].val_s.amp_sustain_level, 
         m_proph->m_sound_param_as[m_sound_u8].val_s.amp_release_rate,
         m_proph->m_sound_param_as[m_sound_u8].val_s.amp_2nd_release_rate, 255,
         origcol, 0, 1);

   percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.amp_peak_vel_sensitivity - 0x80));
   t = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_peak_vel_sensitivity - 0x80;
   t = (t * percentage) / 100;
   if(t > 127)
   {
      t = 127;
   }
   else
   if(t < -127)
   {
      t = -127;
   }
   str.sprintf(wxT("%d"), t);
   m_amp_peak_vel_sensitivity->SetValue(str);

   percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.attack_vel_sensitivity - 0x80));
   t = m_proph->m_sound_param_as[m_sound_u8].val_s.attack_vel_sensitivity - 0x80;
   t = (t * percentage) / 100;
   if(t > 127)
   {
      t = 127;
   }
   else
   if(t < -127)
   {
      t = -127;
   }
   str.sprintf(wxT("%d"), t);
   m_attack_vel_sensitivity->SetValue(str);

   percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.release_vel_sensitivity - 0x80));
   t = m_proph->m_sound_param_as[m_sound_u8].val_s.release_vel_sensitivity - 0x80;
   t = (t * percentage) / 100;
   if(t > 127)
   {
      t = 127;
   }
   else
   if(t < -127)
   {
      t = -127;
   }
   str.sprintf(wxT("%d"), t);
   m_release_vel_sensitivity->SetValue(str);

   // --------------------------------------------------------------------------------------------------------------------
   percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_release_rate - 0x80));
   t = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_release_rate;
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_release_rate == 0x3f)
   {
      str = wxT("INF");
      vcf_r = 0x3f;
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
      vcf_r = t;
      str.sprintf(wxT("%d"), t);
   }
   m_filt_release_rate->SetValue(str);

   percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_2nd_release_rate - 0x80));
   t = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_2nd_release_rate;
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_2nd_release_rate == 0x3f)
   {
      str = wxT("INF");
      vcf_r_2nd = 0x3f;
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
      vcf_r_2nd = t;
      str.sprintf(wxT("%d"), t);
   }
   m_filt_2nd_release_rate->SetValue(str);

   percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_decay_rate - 0x80));
   t = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_decay_rate;
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_decay_rate == 0x3f)
   {
      str = wxT("INF");
      vcf_d = 0x3f;
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
      vcf_d = t;
      str.sprintf(wxT("%d"), t);
   }
   m_filt_decay_rate->SetValue(str);


   percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_sustain_level - 0x80));
   t = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_sustain_level;
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_sustain_level == 0x00)
   {
      str = wxT("OFF");
      vcf_s = 0;
   }
   else
   {
      t = (t * percentage) / 100;
      t = t / 2; 
	  vcf_s = t *2;
      if(vcf_s > 255)
      {
         vcf_s = 255;
      }
      if(t > 127)
      {
         t = 127;
      }
      
      str.sprintf(wxT("%d"), t);
   }
   m_filt_sustain_level->SetValue(str);


   percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_attack_rate - 0x80));
   t = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_attack_rate;
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_attack_rate == 0x00)
   {
      str = wxT("INST.");
      vcf_a = 0;
   }
   else
   {
      t = (t * percentage) / 100;
      if(t > 62)
      {
         t = 62;
      }
      vcf_a = t;
      if(t > 0)
      {
         str.sprintf(wxT("%d"), t);
      }
      else
      {
         str = wxT("INST.");
      }
   }
   m_filt_attack_rate->SetValue(str);

   m_vcf_env_disp->clearView();

   if(!show_vcf_env_amount)
   {
	   vcf_unscaled_env_amount = 255;
	   mySizer->GetStaticBox()->SetLabel("VCF Envelope Graph");
   }
   else
   {
	   mySizer->GetStaticBox()->SetLabel("VCF Envelope Amount");
	   vcf_unscaled_env_amount = (m_proph->m_sound_param_as[m_sound_u8].val_s.filt_env_amount - 0x80) * 2;
   }

   m_vcf_env_panel->SetSizer(mySizer);

   if(!show_vcf_env_amount)
   {
	   vcf_env_amount = 255;
   }
   else
   {
      percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_env_amount - 0x80));
      vcf_env_amount = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_env_amount;
      vcf_env_amount = (vcf_env_amount * percentage) / 100;
      vcf_env_amount = (vcf_env_amount - 0x80) * 2;
      if( vcf_env_amount > 255)
      {
         vcf_env_amount = 255;
      }
      if (vcf_env_amount < -255)
      {
         vcf_env_amount = -255;
      }
   }
   		 
/*	   vcf_env_amount = (m_proph->m_sound_param_as[m_sound_u8].val_s.filt_env_amount - 0x80) * 2;
	   percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_env_amount - 0x80));
	   vcf_env_amount = (vcf_env_amount * percentage)/100;
	   if ( vcf_env_amount > 255 ) vcf_env_amount = 255;
	   if ( vcf_env_amount < -255) vcf_env_amount = -255;
 }*/


      m_vcf_env_disp->drawADSR(vcf_a, vcf_d, vcf_s, vcf_r, vcf_r_2nd, vcf_env_amount, col, 0, 2);

      m_vcf_env_disp->drawADSR(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_attack_rate,
         m_proph->m_sound_param_as[m_sound_u8].val_s.filt_decay_rate,
         m_proph->m_sound_param_as[m_sound_u8].val_s.filt_sustain_level, 
         m_proph->m_sound_param_as[m_sound_u8].val_s.filt_release_rate, 
         m_proph->m_sound_param_as[m_sound_u8].val_s.filt_2nd_release_rate,vcf_unscaled_env_amount,
         origcol, 0, 1);

   
   percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_peak_vel_sensitivity - 0x80));
   t = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_peak_vel_sensitivity - 0x80;
   t = (t * percentage) / 100;
   if(t > 127)
   {
      t = 127;
   }
   else
   if(t < -127)
   {
      t = -127;
   }
   str.sprintf(wxT("%d"), t);
   m_filt_peak_vel_sensitivity->SetValue(str);

   // --------------------------------------------------------------------------------------------------------------------
   percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_cutoff - 0x80));
   t = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_cutoff[1];
   t |= ((uint16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.filt_cutoff[0] << 8);
   t = (t - 127) / 128;
   t = (t * percentage) / 100;
   t = t / 2;
   if(t > 127)
   {
      t = 127;
   }
   str.sprintf(wxT("%d"), t);
   m_filt_cutoff->SetValue(str);

   percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_resonance - 0x80));
   t = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_resonance[1];
   t |= ((uint16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.filt_resonance[0] << 8);
   t = (t - 63) / 64;
   t = (t * percentage) / 100;
   t = t / 2;
   if(t > 127)
   {
      t = 127;
   }
   str.sprintf(wxT("%d"), t);
   m_filt_resonance->SetValue(str);

   percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_env_amount - 0x80));
   t = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_env_amount;
   t = (t * percentage) / 100;
   t = (t - 0x80);

/*   percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_env_amount - 0x80));
   t = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_env_amount - 0x80;
   t = (t * percentage) / 100; */
   if(t > 127)
   {
      t = 127;
   }
   else
   if(t < -127)
   {
      t = -127;
   }
   str.sprintf(wxT("%d"), t);
   m_filt_env_amount->SetValue(str);

   percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.filt_keyboard_tracking - 0x80));
   t = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_key_tracking;
   t = (t * percentage) / 100;
   t = t / 2;
   if(t > 127)
   {
      t = 127;
   }
   str.sprintf(wxT("%d"), t);
   m_filt_keyboard_tracking->SetValue(str);

   // --------------------------------------------------------------------------------------------------------------------
   percentage = calcPercentage((int8_t)(m_proph->m_map_param_as[m_map_u8].val_s.velocity_start_point - 0x80));
   t = m_proph->m_sound_param_as[m_sound_u8].val_s.velocity_start_point - 0x80;
   t = (t * percentage) / 100;
   if(t > 127)
   {
      t = 127;
   }
   else
   if(t < -127)
   {
      t = -127;
   }
   str.sprintf(wxT("%d"), t);
   m_velocity_start_point->SetValue(str);
       
   
   m_vca_env_disp->Refresh();
   m_vcf_env_disp->Refresh();

}

void MapScaleValuesDlg::OnLeftDown(wxMouseEvent& event)
{
	show_vcf_env_amount = !show_vcf_env_amount;
	updateGUI();
}
