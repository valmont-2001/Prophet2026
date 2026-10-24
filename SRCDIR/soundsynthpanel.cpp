#include "types.h"


#include <wx/wx.h>
#include <wx/string.h>
#include <wx/file.h>
#include <wx/spinctrl.h>
#include <wx/notebook.h>
#include <wx/tglbtn.h>
#include <wx/sound.h>

#include "types.h"
#include "GUILayout.h"
#include "main.h"
#include "stopwatch.h"
#include "proph2000.h"
#include "soundparam.h"
#include <list>
#include <map>
using namespace std;
#include "soundsynthpanel.h"
#include "envdisp.h"


SoundSynthPanelImpl::SoundSynthPanelImpl(wxWindow *parent, MyPanel *topframe, Proph2000 *proph, uint8_t sound_u8, MySoundParam *panel) :
   SoundSynthPanel(parent),
   m_topframe(topframe), m_proph(proph), m_sound_u8(sound_u8), m_panel(panel), m_apply_to_all(false)
{
#ifdef __WXMAC__ //130205
    SetMaxSize(wxSize(GetMaxSize().GetWidth(), GetMaxSize().GetHeight() + 50));
    SetMinSize(wxSize(GetMinSize().GetWidth(), GetMinSize().GetHeight() + 50));
    SetSize(wxSize(GetSize().GetWidth(), GetSize().GetHeight() + 50));
#endif
   if(m_sound_u8 < 8)
   {
      m_used_in_map1->SetLabel(wxT("1"));
      m_used_in_map2->SetLabel(wxT("2"));
      m_used_in_map3->SetLabel(wxT("3"));
      m_used_in_map4->SetLabel(wxT("4"));
      m_used_in_map5->SetLabel(wxT("5"));
      m_used_in_map6->SetLabel(wxT("6"));
      m_used_in_map7->SetLabel(wxT("7"));
      m_used_in_map8->SetLabel(wxT("8"));
   }
   else
   {
      m_used_in_map1->SetLabel(wxT("9"));
      m_used_in_map2->SetLabel(wxT("A"));
      m_used_in_map3->SetLabel(wxT("B"));
      m_used_in_map4->SetLabel(wxT("C"));
      m_used_in_map5->SetLabel(wxT("D"));
      m_used_in_map6->SetLabel(wxT("E"));
      m_used_in_map7->SetLabel(wxT("F"));
      m_used_in_map8->SetLabel(wxT("G"));
   }
   show_vcf_env_amount = false;
   displaySettings();
   updateGUI();
}


SoundSynthPanelImpl::~SoundSynthPanelImpl()
{
}

void SoundSynthPanelImpl::applyParameterToAll(bool flag)
{
   m_apply_to_all = flag;
}

void SoundSynthPanelImpl::activateSound(uint8_t sound_u8)
{
   m_sound_u8 = sound_u8;
   if(m_sound_u8 < 8)
   {
      m_used_in_map1->SetLabel(wxT("1"));
      m_used_in_map2->SetLabel(wxT("2"));
      m_used_in_map3->SetLabel(wxT("3"));
      m_used_in_map4->SetLabel(wxT("4"));
      m_used_in_map5->SetLabel(wxT("5"));
      m_used_in_map6->SetLabel(wxT("6"));
      m_used_in_map7->SetLabel(wxT("7"));
      m_used_in_map8->SetLabel(wxT("8"));
   }
   else
   {
      m_used_in_map1->SetLabel(wxT("9"));
      m_used_in_map2->SetLabel(wxT("A"));
      m_used_in_map3->SetLabel(wxT("B"));
      m_used_in_map4->SetLabel(wxT("C"));
      m_used_in_map5->SetLabel(wxT("D"));
      m_used_in_map6->SetLabel(wxT("E"));
      m_used_in_map7->SetLabel(wxT("F"));
      m_used_in_map8->SetLabel(wxT("G"));
   }
   displaySettings();
   updateGUI();
}

void SoundSynthPanelImpl::OnUsedInMap1(wxCommandEvent& event)
{
   if(m_sound_u8 < 8)
   {
      m_topframe->activateMapOnGui(0);
   }
   else
   {
      m_topframe->activateMapOnGui(0 + 8);
   }
}

void SoundSynthPanelImpl::OnUsedInMap2(wxCommandEvent& event)
{
   if(m_sound_u8 < 8)
   {
      m_topframe->activateMapOnGui(1);
   }
   else
   {
      m_topframe->activateMapOnGui(1 + 8);
   }
}

void SoundSynthPanelImpl::OnUsedInMap3(wxCommandEvent& event)
{
   if(m_sound_u8 < 8)
   {
      m_topframe->activateMapOnGui(2);
   }
   else
   {
      m_topframe->activateMapOnGui(2 + 8);
   }
}

void SoundSynthPanelImpl::OnUsedInMap4(wxCommandEvent& event)
{
   if(m_sound_u8 < 8)
   {
      m_topframe->activateMapOnGui(3);
   }
   else
   {
      m_topframe->activateMapOnGui(3 + 8);
   }
}

void SoundSynthPanelImpl::OnUsedInMap5(wxCommandEvent& event)
{
   if(m_sound_u8 < 8)
   {
      m_topframe->activateMapOnGui(4);
   }
   else
   {
      m_topframe->activateMapOnGui(4 + 8);
   }
}

void SoundSynthPanelImpl::OnUsedInMap6(wxCommandEvent& event)
{
   if(m_sound_u8 < 8)
   {
      m_topframe->activateMapOnGui(5);
   }
   else
   {
      m_topframe->activateMapOnGui(5 + 8);
   }
}

void SoundSynthPanelImpl::OnUsedInMap7(wxCommandEvent& event)
{
   if(m_sound_u8 < 8)
   {
      m_topframe->activateMapOnGui(6);
   }
   else
   {
      m_topframe->activateMapOnGui(6 + 8);
   }
}

void SoundSynthPanelImpl::OnUsedInMap8(wxCommandEvent& event)
{
   if(m_sound_u8 < 8)
   {
      m_topframe->activateMapOnGui(7);
   }
   else
   {
      m_topframe->activateMapOnGui(7 + 8);
   }
}

void SoundSynthPanelImpl::updateUsedInMapStatus(void)
{
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map1 != SOUND_NOT_MAPPED_VALUE)
   {
      m_used_in_map1->SetValue(true);
   }
   else
   {
      m_used_in_map1->SetValue(false);
   }
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map2 != SOUND_NOT_MAPPED_VALUE)
   {
      m_used_in_map2->SetValue(true);
   }
   else
   {
      m_used_in_map2->SetValue(false);
   }
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map3 != SOUND_NOT_MAPPED_VALUE)
   {
      m_used_in_map3->SetValue(true);
   }
   else
   {
      m_used_in_map3->SetValue(false);
   }
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map4 != SOUND_NOT_MAPPED_VALUE)
   {
      m_used_in_map4->SetValue(true);
   }
   else
   {
      m_used_in_map4->SetValue(false);
   }
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map5 != SOUND_NOT_MAPPED_VALUE)
   {
      m_used_in_map5->SetValue(true);
   }
   else
   {
      m_used_in_map5->SetValue(false);
   }
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map6 != SOUND_NOT_MAPPED_VALUE)
   {
      m_used_in_map6->SetValue(true);
   }
   else
   {
      m_used_in_map6->SetValue(false);
   }
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map7 != SOUND_NOT_MAPPED_VALUE)
   {
      m_used_in_map7->SetValue(true);
   }
   else
   {
      m_used_in_map7->SetValue(false);
   }
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map8 != SOUND_NOT_MAPPED_VALUE)
   {
      m_used_in_map8->SetValue(true);
   }
   else
   {
      m_used_in_map8->SetValue(false);
   }
}

void SoundSynthPanelImpl::displaySettings(void)
{
   wxString str;
   uint32_t t;

   updateVCAGraph = true;
   updateVCFGraph = true;
   trigger = true;
   m_amp_release->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_release_rate);
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_release_rate == 0x3f)
   {
      str = wxT("INF");
   }
   else
   {
      str.sprintf(wxT("%d"), m_proph->m_sound_param_as[m_sound_u8].val_s.amp_release_rate);
   }
   m_amp_release_val->SetValue(str);

   m_amp_2nd_release->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_2nd_release_rate);
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_2nd_release_rate == 0x3f)
   {
      str = wxT("INF");
   }
   else
   {
      str.sprintf(wxT("%d"), m_proph->m_sound_param_as[m_sound_u8].val_s.amp_2nd_release_rate);
   }
   m_amp_2nd_release_val->SetValue(str);

   m_amp_decay_rate->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_decay_rate);
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_decay_rate == 0x3f)
   {
      str = wxT("INF");
   }
   else
   {
      str.sprintf(wxT("%d"), m_proph->m_sound_param_as[m_sound_u8].val_s.amp_decay_rate);
   }
   m_amp_decay_rate_val->SetValue(str);

   m_amp_sustain_level->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_sustain_level);
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_sustain_level == 0x00)
   {
      str = wxT("OFF");
   }
   else
   {
      str.sprintf(wxT("%d"), (m_proph->m_sound_param_as[m_sound_u8].val_s.amp_sustain_level) / 2);
   }
   m_amp_sustain_level_val->SetValue(str);

   m_amp_attack_rate->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_attack_rate);
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_attack_rate == 0x00)
   {
      str = wxT("INST.");
   }
   else
   {
      str.sprintf(wxT("%d"), m_proph->m_sound_param_as[m_sound_u8].val_s.amp_attack_rate);
   }
   m_amp_attack_rate_val->SetValue(str);

   m_amp_peak_vel_sensitivity->SetValue((int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.amp_peak_vel_sensitivity - 0x80);
   str.sprintf(wxT("%+d"), (int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.amp_peak_vel_sensitivity - 0x80);
   m_amp_peak_vel_sensitivity_val->SetValue(str);

   m_filt_release_rate->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_release_rate);
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_release_rate == 0x3f)
   {
      str = wxT("INF");
   }
   else
   {
      str.sprintf(wxT("%d"), m_proph->m_sound_param_as[m_sound_u8].val_s.filt_release_rate);
   }
   m_filt_release_rate_val->SetValue(str);

   m_filt_2nd_release_rate->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_2nd_release_rate);
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_2nd_release_rate == 0x3f)
   {
      str = wxT("INF");
   }
   else
   {
      str.sprintf(wxT("%d"), m_proph->m_sound_param_as[m_sound_u8].val_s.filt_2nd_release_rate);
   }
   m_filt_2nd_release_rate_val->SetValue(str);

   m_filt_decay_rate->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_decay_rate);
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_decay_rate == 0x3f)
   {
      str = wxT("INF");
   }
   else
   {
      str.sprintf(wxT("%d"), m_proph->m_sound_param_as[m_sound_u8].val_s.filt_decay_rate);
   }
   m_filt_decay_rate_val->SetValue(str);

   m_filt_sustain_level->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_sustain_level);
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_sustain_level == 0x00)
   {
      str = wxT("OFF");
   }
   else
   {
      str.sprintf(wxT("%d"), (m_proph->m_sound_param_as[m_sound_u8].val_s.filt_sustain_level) / 2);
   }
   m_filt_sustain_level_val->SetValue(str);

   m_filt_attack_rate->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_attack_rate);
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_attack_rate == 0x00)
   {
      str = wxT("INST.");
   }
   else
   {
      str.sprintf(wxT("%d"), m_proph->m_sound_param_as[m_sound_u8].val_s.filt_attack_rate);
   }
   m_filt_attack_rate_val->SetValue(str);

   m_filt_peak_vel_sensitivity->SetValue((int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.filt_peak_vel_sensitivity - 0x80);
   str.sprintf(wxT("%+d"), (int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.filt_peak_vel_sensitivity - 0x80);
   m_filt_peak_vel_sensitivity_val->SetValue(str);
   
   if((m_proph->m_sound_param_as[m_sound_u8].val_s.filt_resonance[0] == 0x00) && (m_proph->m_sound_param_as[m_sound_u8].val_s.filt_resonance[1] == 0x00))
   {
      m_filt_resonance_val->SetValue(wxT("0"));
      m_filt_resonance->SetValue(0);
   }
   else
   {
      t = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_resonance[1];
      t |= ((uint16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.filt_resonance[0] << 8);
      m_filt_resonance->SetValue((t - 63) / 64);
      str.sprintf(wxT("%d"), ((t - 63) / 64) / 2);
      m_filt_resonance_val->SetValue(str);
   }

   t = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_cutoff[1];
   t |= ((uint16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.filt_cutoff[0] << 8);
   m_filt_cutoff->SetValue((t - 127) / 128);
   str.sprintf(wxT("%d"), ((t - 127) / 128) / 2);
   m_filt_cutoff_val->SetValue(str);

   m_filt_env_amount->SetValue((int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.filt_env_amount - 0x80);
   str.sprintf(wxT("%+d"), (int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.filt_env_amount - 0x80);
   m_filt_env_amount_val->SetValue(str);

   m_filt_key_tracking->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_key_tracking);
   str.sprintf(wxT("%d"), (m_proph->m_sound_param_as[m_sound_u8].val_s.filt_key_tracking) / 2);
   m_filt_key_tracking_val->SetValue(str);

   m_attack_vel_sensitivity->SetValue((int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.attack_vel_sensitivity - 0x80);
   str.sprintf(wxT("%+d"), (int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.attack_vel_sensitivity - 0x80);
   m_attack_vel_sensitivity_val->SetValue(str);

   m_release_vel_sensitivity->SetValue((int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.release_vel_sensitivity - 0x80);
   str.sprintf(wxT("%+d"), (int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.release_vel_sensitivity - 0x80);
   m_release_vel_sensitivity_val->SetValue(str);

}

void SoundSynthPanelImpl::updateGUI(void)
{
/*   wxString str;
   uint32_t t;
*/
   int16_t volume;

   wxStaticBoxSizer* mySizer;
   mySizer=(wxStaticBoxSizer*)m_vcf_env_panel->GetSizer();			


   updateUsedInMapStatus();


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

   if ( updateVCAGraph == true )
   {
      m_vca_env_disp->clearView();
      m_vca_env_disp->drawADSR(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_attack_rate,
            m_proph->m_sound_param_as[m_sound_u8].val_s.amp_decay_rate,
            m_proph->m_sound_param_as[m_sound_u8].val_s.amp_sustain_level, 
            m_proph->m_sound_param_as[m_sound_u8].val_s.amp_release_rate,
            m_proph->m_sound_param_as[m_sound_u8].val_s.amp_2nd_release_rate,255,
            col, 0, 1);
      m_vca_env_disp->Refresh();
      updateVCAGraph = false;
   }


   if (!show_vcf_env_amount) 
   {
	   volume = 255;
	   if (trigger) mySizer->GetStaticBox()->SetLabel("VCF Envelope Graph");
   }
   else
   {
	   if (trigger) mySizer->GetStaticBox()->SetLabel("VCF Envelope Amount");
	   volume = (m_proph->m_sound_param_as[m_sound_u8].val_s.filt_env_amount - 0x80) * 2;
   }
   if (trigger) // Need to refresh top line
   {
	    m_vcf_env_panel->SetSizer(mySizer);
	    trigger = !trigger;
   }

   if ( updateVCFGraph == true )
   {
      m_vcf_env_disp->clearView();
      m_vcf_env_disp->drawADSR(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_attack_rate,
            m_proph->m_sound_param_as[m_sound_u8].val_s.filt_decay_rate,
            m_proph->m_sound_param_as[m_sound_u8].val_s.filt_sustain_level, 
            m_proph->m_sound_param_as[m_sound_u8].val_s.filt_release_rate, 
            m_proph->m_sound_param_as[m_sound_u8].val_s.filt_2nd_release_rate,volume,
            col, 0, 1);
      m_vcf_env_disp->Refresh();
      updateVCFGraph = false;
   }

/*
   m_amp_release->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_release_rate);
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_release_rate == 0x3f)
   {
      str = wxT("INF");
   }
   else
   {
      str.sprintf(wxT("%d"), m_proph->m_sound_param_as[m_sound_u8].val_s.amp_release_rate);
   }
   m_amp_release_val->SetValue(str);

   m_amp_2nd_release->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_2nd_release_rate);
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_2nd_release_rate == 0x3f)
   {
      str = wxT("INF");
   }
   else
   {
      str.sprintf(wxT("%d"), m_proph->m_sound_param_as[m_sound_u8].val_s.amp_2nd_release_rate);
   }
   m_amp_2nd_release_val->SetValue(str);

   m_amp_decay_rate->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_decay_rate);
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_decay_rate == 0x3f)
   {
      str = wxT("INF");
   }
   else
   {
      str.sprintf(wxT("%d"), m_proph->m_sound_param_as[m_sound_u8].val_s.amp_decay_rate);
   }
   m_amp_decay_rate_val->SetValue(str);

   m_amp_sustain_level->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_sustain_level);
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_sustain_level == 0x00)
   {
      str = wxT("OFF");
   }
   else
   {
      str.sprintf(wxT("%d"), (m_proph->m_sound_param_as[m_sound_u8].val_s.amp_sustain_level) / 2);
   }
   m_amp_sustain_level_val->SetValue(str);

   m_amp_attack_rate->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_attack_rate);
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_attack_rate == 0x00)
   {
      str = wxT("INST.");
   }
   else
   {
      str.sprintf(wxT("%d"), m_proph->m_sound_param_as[m_sound_u8].val_s.amp_attack_rate);
   }
   m_amp_attack_rate_val->SetValue(str);

   m_amp_peak_vel_sensitivity->SetValue((int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.amp_peak_vel_sensitivity - 0x80);
   str.sprintf(wxT("%+d"), (int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.amp_peak_vel_sensitivity - 0x80);
   m_amp_peak_vel_sensitivity_val->SetValue(str);

   m_filt_release_rate->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_release_rate);
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_release_rate == 0x3f)
   {
      str = wxT("INF");
   }
   else
   {
      str.sprintf(wxT("%d"), m_proph->m_sound_param_as[m_sound_u8].val_s.filt_release_rate);
   }
   m_filt_release_rate_val->SetValue(str);

   m_filt_2nd_release_rate->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_2nd_release_rate);
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_2nd_release_rate == 0x3f)
   {
      str = wxT("INF");
   }
   else
   {
      str.sprintf(wxT("%d"), m_proph->m_sound_param_as[m_sound_u8].val_s.filt_2nd_release_rate);
   }
   m_filt_2nd_release_rate_val->SetValue(str);

   m_filt_decay_rate->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_decay_rate);
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_decay_rate == 0x3f)
   {
      str = wxT("INF");
   }
   else
   {
      str.sprintf(wxT("%d"), m_proph->m_sound_param_as[m_sound_u8].val_s.filt_decay_rate);
   }
   m_filt_decay_rate_val->SetValue(str);

   m_filt_sustain_level->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_sustain_level);
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_sustain_level == 0x00)
   {
      str = wxT("OFF");
   }
   else
   {
      str.sprintf(wxT("%d"), (m_proph->m_sound_param_as[m_sound_u8].val_s.filt_sustain_level) / 2);
   }
   m_filt_sustain_level_val->SetValue(str);

   m_filt_attack_rate->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_attack_rate);
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_attack_rate == 0x00)
   {
      str = wxT("INST.");
   }
   else
   {
      str.sprintf(wxT("%d"), m_proph->m_sound_param_as[m_sound_u8].val_s.filt_attack_rate);
   }
   m_filt_attack_rate_val->SetValue(str);

   m_filt_peak_vel_sensitivity->SetValue((int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.filt_peak_vel_sensitivity - 0x80);
   str.sprintf(wxT("%+d"), (int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.filt_peak_vel_sensitivity - 0x80);
   m_filt_peak_vel_sensitivity_val->SetValue(str);
   
   if((m_proph->m_sound_param_as[m_sound_u8].val_s.filt_resonance[0] == 0x00) && (m_proph->m_sound_param_as[m_sound_u8].val_s.filt_resonance[1] == 0x00))
   {
      m_filt_resonance_val->SetValue(wxT("0"));
      m_filt_resonance->SetValue(0);
   }
   else
   {
      t = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_resonance[1];
      t |= ((uint16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.filt_resonance[0] << 8);
      m_filt_resonance->SetValue((t - 63) / 64);
      str.sprintf(wxT("%d"), ((t - 63) / 64) / 2);
      m_filt_resonance_val->SetValue(str);
   }

   t = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_cutoff[1];
   t |= ((uint16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.filt_cutoff[0] << 8);
   m_filt_cutoff->SetValue((t - 127) / 128);
   str.sprintf(wxT("%d"), ((t - 127) / 128) / 2);
   m_filt_cutoff_val->SetValue(str);

   m_filt_env_amount->SetValue((int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.filt_env_amount - 0x80);
   str.sprintf(wxT("%+d"), (int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.filt_env_amount - 0x80);
   m_filt_env_amount_val->SetValue(str);

   m_filt_key_tracking->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_key_tracking);
   str.sprintf(wxT("%d"), (m_proph->m_sound_param_as[m_sound_u8].val_s.filt_key_tracking) / 2);
   m_filt_key_tracking_val->SetValue(str);

   m_attack_vel_sensitivity->SetValue((int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.attack_vel_sensitivity - 0x80);
   str.sprintf(wxT("%+d"), (int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.attack_vel_sensitivity - 0x80);
   m_attack_vel_sensitivity_val->SetValue(str);

   m_release_vel_sensitivity->SetValue((int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.release_vel_sensitivity - 0x80);
   str.sprintf(wxT("%+d"), (int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.release_vel_sensitivity - 0x80);
   m_release_vel_sensitivity_val->SetValue(str);
*/
}


void SoundSynthPanelImpl::OnSliderChange(wxScrollEvent &event)
{
//   uint16_t t;
//   m_proph->m_sound_param_as[m_sound_u8].val_s.amp_attack_rate = m_amp_attack_rate->GetValue();
//   m_proph->m_sound_param_as[m_sound_u8].val_s.amp_decay_rate = m_amp_decay_rate->GetValue();
//   m_proph->m_sound_param_as[m_sound_u8].val_s.amp_sustain_level = m_amp_sustain_level->GetValue();
//   m_proph->m_sound_param_as[m_sound_u8].val_s.amp_release_rate = m_amp_release->GetValue();
//   m_proph->m_sound_param_as[m_sound_u8].val_s.amp_2nd_release_rate = m_amp_2nd_release->GetValue();
//   m_proph->m_sound_param_as[m_sound_u8].val_s.amp_peak_vel_sensitivity = m_amp_peak_vel_sensitivity->GetValue() + 0x80;
//   m_proph->m_sound_param_as[m_sound_u8].val_s.filt_attack_rate = m_filt_attack_rate->GetValue();
//   m_proph->m_sound_param_as[m_sound_u8].val_s.filt_decay_rate = m_filt_decay_rate->GetValue();
//   m_proph->m_sound_param_as[m_sound_u8].val_s.filt_sustain_level = m_filt_sustain_level->GetValue();
//   m_proph->m_sound_param_as[m_sound_u8].val_s.filt_release_rate = m_filt_release_rate->GetValue();
//   m_proph->m_sound_param_as[m_sound_u8].val_s.filt_2nd_release_rate = m_filt_2nd_release_rate->GetValue();
//   m_proph->m_sound_param_as[m_sound_u8].val_s.filt_peak_vel_sensitivity = m_filt_peak_vel_sensitivity->GetValue() + 0x80;
//   m_proph->m_sound_param_as[m_sound_u8].val_s.filt_env_amount = m_filt_env_amount->GetValue() + 0x80;
//   m_proph->m_sound_param_as[m_sound_u8].val_s.attack_vel_sensitivity = m_attack_vel_sensitivity->GetValue() + 0x80;
//   m_proph->m_sound_param_as[m_sound_u8].val_s.release_vel_sensitivity = m_release_vel_sensitivity->GetValue() + 0x80;
//   m_proph->m_sound_param_as[m_sound_u8].val_s.filt_key_tracking = m_filt_key_tracking->GetValue();

//   t = m_filt_cutoff->GetValue();
//   t = (t * 128) + 127;
//   m_proph->m_sound_param_as[m_sound_u8].val_s.filt_cutoff[1] = (t & 0xff);
//   m_proph->m_sound_param_as[m_sound_u8].val_s.filt_cutoff[0] = (t & 0xff00) >> 8;

//   t = m_filt_resonance->GetValue();
//   t = (t * 64) + 63;
//   m_proph->m_sound_param_as[m_sound_u8].val_s.filt_resonance[1] = (t & 0xff);
//   m_proph->m_sound_param_as[m_sound_u8].val_s.filt_resonance[0] = (t & 0xff00) >> 8;

//   m_proph->updateParamBytesFromStruct();
//   updateGUI();
//   if(m_topframe->getOnlineUpdateActive())
//   {
//      if(m_proph->transferSoundParam2Proph(m_sound_u8))
//      {
//         m_topframe->transferStarted();
//      }
//   }
}

void SoundSynthPanelImpl::OnAmpAttackSliderChange(wxScrollEvent& event)
{
   wxString str;
   m_proph->m_sound_param_as[m_sound_u8].val_s.amp_attack_rate = m_amp_attack_rate->GetValue();
   if(m_proph->getStereoMode())
   {
      if(m_sound_u8 < 8)
      {
         m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.amp_attack_rate = m_amp_attack_rate->GetValue();
      }
      else
      {
         m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.amp_attack_rate = m_amp_attack_rate->GetValue();
      }
   }
   updateVCAGraph = true;

   if(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_attack_rate == 0x00)
   {
      str = wxT("INST.");
   }
   else
   {
      str.sprintf(wxT("%d"), m_proph->m_sound_param_as[m_sound_u8].val_s.amp_attack_rate);
   }
   m_amp_attack_rate_val->SetValue(str);

   m_proph->updateParamBytesFromStruct();
   updateGUI();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_apply_to_all)
      {
         m_panel->copyParamToAll();
      }
      else
      {
         if(m_proph->transferSoundParam2Proph(m_sound_u8))
         {
            m_topframe->transferStarted();
         }
      }
   }
}

void SoundSynthPanelImpl::OnAmpDecaySliderChange(wxScrollEvent& event)
{
   wxString str;
   m_proph->m_sound_param_as[m_sound_u8].val_s.amp_decay_rate = m_amp_decay_rate->GetValue();
   if(m_proph->getStereoMode())
   {
      if(m_sound_u8 < 8)
      {
         m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.amp_decay_rate = m_amp_decay_rate->GetValue();
      }
      else
      {
         m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.amp_decay_rate = m_amp_decay_rate->GetValue();
      }
   }
   updateVCAGraph = true;

   if(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_decay_rate == 0x3f)
   {
      str = wxT("INF");
   }
   else
   {
      str.sprintf(wxT("%d"), m_proph->m_sound_param_as[m_sound_u8].val_s.amp_decay_rate);
   }
   m_amp_decay_rate_val->SetValue(str);

   m_proph->updateParamBytesFromStruct();
   updateGUI();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_apply_to_all)
      {
         m_panel->copyParamToAll();
      }
      else
      {
         if(m_proph->transferSoundParam2Proph(m_sound_u8))
         {
            m_topframe->transferStarted();
         }
      }
   }
}
void SoundSynthPanelImpl::OnAmpSustainSliderChange(wxScrollEvent& event)
{
   wxString str;
   m_proph->m_sound_param_as[m_sound_u8].val_s.amp_sustain_level = m_amp_sustain_level->GetValue();
   if(m_proph->getStereoMode())
   {
      if(m_sound_u8 < 8)
      {
         m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.amp_sustain_level = m_amp_sustain_level->GetValue();
      }
      else
      {
         m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.amp_sustain_level = m_amp_sustain_level->GetValue();
      }
   }
   updateVCAGraph = true;
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_sustain_level == 0x00)
   {
      str = wxT("OFF");
   }
   else
   {
      str.sprintf(wxT("%d"), (m_proph->m_sound_param_as[m_sound_u8].val_s.amp_sustain_level) / 2);
   }
   m_amp_sustain_level_val->SetValue(str);
   m_proph->updateParamBytesFromStruct();
   updateGUI();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_apply_to_all)
      {
         m_panel->copyParamToAll();
      }
      else
      {
         if(m_proph->transferSoundParam2Proph(m_sound_u8))
         {
            m_topframe->transferStarted();
         }
      }
   }
}

void SoundSynthPanelImpl::OnAmpReleaseSliderChange(wxScrollEvent& event)
{
   wxString str;
   m_proph->m_sound_param_as[m_sound_u8].val_s.amp_release_rate = m_amp_release->GetValue();
   if(m_proph->getStereoMode())
   {
      if(m_sound_u8 < 8)
      {
         m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.amp_release_rate = m_amp_release->GetValue();
      }
      else
      {
         m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.amp_release_rate = m_amp_release->GetValue();
      }
   }
   updateVCAGraph = true;
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_release_rate == 0x3f)
   {
      str = wxT("INF");
   }
   else
   {
      str.sprintf(wxT("%d"), m_proph->m_sound_param_as[m_sound_u8].val_s.amp_release_rate);
   }
   m_amp_release_val->SetValue(str);

   m_proph->updateParamBytesFromStruct();
   updateGUI();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_apply_to_all)
      {
         m_panel->copyParamToAll();
      }
      else
      {
         if(m_proph->transferSoundParam2Proph(m_sound_u8))
         {
            m_topframe->transferStarted();
         }
      }
   }
}

void SoundSynthPanelImpl::OnAmpAltReleaseSliderChange(wxScrollEvent& event)
{
   wxString str;
   m_proph->m_sound_param_as[m_sound_u8].val_s.amp_2nd_release_rate = m_amp_2nd_release->GetValue();
   if(m_proph->getStereoMode())
   {
      if(m_sound_u8 < 8)
      {
         m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.amp_2nd_release_rate = m_amp_2nd_release->GetValue();
      }
      else
      {
         m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.amp_2nd_release_rate = m_amp_2nd_release->GetValue();
      }
   }
   updateVCAGraph = true;
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.amp_2nd_release_rate == 0x3f)
   {
      str = wxT("INF");
   }
   else
   {
      str.sprintf(wxT("%d"), m_proph->m_sound_param_as[m_sound_u8].val_s.amp_2nd_release_rate);
   }
   m_amp_2nd_release_val->SetValue(str);
   m_proph->updateParamBytesFromStruct();
   updateGUI();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_apply_to_all)
      {
         m_panel->copyParamToAll();
      }
      else
      {
         if(m_proph->transferSoundParam2Proph(m_sound_u8))
         {
            m_topframe->transferStarted();
         }
      }
   }
}

void SoundSynthPanelImpl::OnFilterAttackSliderChange(wxScrollEvent& event)
{
   wxString str;
   m_proph->m_sound_param_as[m_sound_u8].val_s.filt_attack_rate = m_filt_attack_rate->GetValue();
   if(m_proph->getStereoMode())
   {
      if(m_sound_u8 < 8)
      {
         m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.filt_attack_rate = m_filt_attack_rate->GetValue();
      }
      else
      {
         m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.filt_attack_rate = m_filt_attack_rate->GetValue();
      }
   }
   updateVCFGraph = true;
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_attack_rate == 0x00)
   {
      str = wxT("INST.");
   }
   else
   {
      str.sprintf(wxT("%d"), m_proph->m_sound_param_as[m_sound_u8].val_s.filt_attack_rate);
   }
   m_filt_attack_rate_val->SetValue(str);
 
   m_proph->updateParamBytesFromStruct();
   updateGUI();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_apply_to_all)
      {
         m_panel->copyParamToAll();
      }
      else
      {
         if(m_proph->transferSoundParam2Proph(m_sound_u8))
         {
            m_topframe->transferStarted();
         }
      }
   }
}

void SoundSynthPanelImpl::OnFilterDecaySliderChange(wxScrollEvent& event)
{
   wxString str;
   m_proph->m_sound_param_as[m_sound_u8].val_s.filt_decay_rate = m_filt_decay_rate->GetValue();
   if(m_proph->getStereoMode())
   {
      if(m_sound_u8 < 8)
      {
         m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.filt_decay_rate = m_filt_decay_rate->GetValue();
      }
      else
      {
         m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.filt_decay_rate = m_filt_decay_rate->GetValue();
      }
   }
   updateVCFGraph = true;
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_decay_rate == 0x3f)
   {
      str = wxT("INF");
   }
   else
   {
      str.sprintf(wxT("%d"), m_proph->m_sound_param_as[m_sound_u8].val_s.filt_decay_rate);
   }
   m_filt_decay_rate_val->SetValue(str);

   m_proph->updateParamBytesFromStruct();
   updateGUI();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_apply_to_all)
      {
         m_panel->copyParamToAll();
      }
      else
      {
         if(m_proph->transferSoundParam2Proph(m_sound_u8))
         {
            m_topframe->transferStarted();
         }
      }
   }
}

void SoundSynthPanelImpl::OnFilterSustainSliderChange(wxScrollEvent& event)
{
   wxString str;
   m_proph->m_sound_param_as[m_sound_u8].val_s.filt_sustain_level = m_filt_sustain_level->GetValue();
   if(m_proph->getStereoMode())
   {
      if(m_sound_u8 < 8)
      {
         m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.filt_sustain_level = m_filt_sustain_level->GetValue();
      }
      else
      {
         m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.filt_sustain_level = m_filt_sustain_level->GetValue();
      }
   }
   updateVCFGraph = true;
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_sustain_level == 0x00)
   {
      str = wxT("OFF");
   }
   else
   {
      str.sprintf(wxT("%d"), (m_proph->m_sound_param_as[m_sound_u8].val_s.filt_sustain_level) / 2);
   }
   m_filt_sustain_level_val->SetValue(str);

   m_proph->updateParamBytesFromStruct();
   updateGUI();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_apply_to_all)
      {
         m_panel->copyParamToAll();
      }
      else
      {
         if(m_proph->transferSoundParam2Proph(m_sound_u8))
         {
            m_topframe->transferStarted();
         }
      }
   }
}

void SoundSynthPanelImpl::OnFilterReleaseSliderChange(wxScrollEvent& event)
{
   wxString str;
   m_proph->m_sound_param_as[m_sound_u8].val_s.filt_release_rate = m_filt_release_rate->GetValue();
   if(m_proph->getStereoMode())
   {
      if(m_sound_u8 < 8)
      {
         m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.filt_release_rate = m_filt_release_rate->GetValue();
      }
      else
      {
         m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.filt_release_rate = m_filt_release_rate->GetValue();
      }
   }
   updateVCFGraph = true;
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_release_rate == 0x3f)
   {
      str = wxT("INF");
   }
   else
   {
      str.sprintf(wxT("%d"), m_proph->m_sound_param_as[m_sound_u8].val_s.filt_release_rate);
   }
   m_filt_release_rate_val->SetValue(str);

   m_proph->updateParamBytesFromStruct();
   updateGUI();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_apply_to_all)
      {
         m_panel->copyParamToAll();
      }
      else
      {
         if(m_proph->transferSoundParam2Proph(m_sound_u8))
         {
            m_topframe->transferStarted();
         }
      }
   }
}

void SoundSynthPanelImpl::OnFilterAltReleaseSliderChange(wxScrollEvent& event)
{
   wxString str;
   m_proph->m_sound_param_as[m_sound_u8].val_s.filt_2nd_release_rate = m_filt_2nd_release_rate->GetValue();
   if(m_proph->getStereoMode())
   {
      if(m_sound_u8 < 8)
      {
         m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.filt_2nd_release_rate = m_filt_2nd_release_rate->GetValue();
      }
      else
      {
         m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.filt_2nd_release_rate = m_filt_2nd_release_rate->GetValue();
      }
   }
   updateVCFGraph = true;
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.filt_2nd_release_rate == 0x3f)
   {
      str = wxT("INF");
   }
   else
   {
      str.sprintf(wxT("%d"), m_proph->m_sound_param_as[m_sound_u8].val_s.filt_2nd_release_rate);
   }
   m_filt_2nd_release_rate_val->SetValue(str);
   m_proph->updateParamBytesFromStruct();
   updateGUI();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_apply_to_all)
      {
         m_panel->copyParamToAll();
      }
      else
      {
         if(m_proph->transferSoundParam2Proph(m_sound_u8))
         {
            m_topframe->transferStarted();
         }
      }
   }
}

void SoundSynthPanelImpl::OnFilterCutoffSliderChange(wxScrollEvent& event)
{
   wxString str;
   uint32_t t;
   t = m_filt_cutoff->GetValue();
   t = (t * 128) + 127;
   m_proph->m_sound_param_as[m_sound_u8].val_s.filt_cutoff[1] = (t & 0xff);
   m_proph->m_sound_param_as[m_sound_u8].val_s.filt_cutoff[0] = (t & 0xff00) >> 8;

   if(m_proph->getStereoMode())
   {
      if(m_sound_u8 < 8)
      {
         m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.filt_cutoff[1] = (t & 0xff);
         m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.filt_cutoff[0] = (t & 0xff00) >> 8;
      }
      else
      {
         m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.filt_cutoff[1] = (t & 0xff);
         m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.filt_cutoff[0] = (t & 0xff00) >> 8;
      }
   }

   t = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_cutoff[1];
   t |= ((uint16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.filt_cutoff[0] << 8);
   m_filt_cutoff->SetValue((t - 127) / 128);
   str.sprintf(wxT("%d"), ((t - 127) / 128) / 2);
   m_filt_cutoff_val->SetValue(str);

   m_proph->updateParamBytesFromStruct();
   updateGUI();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_apply_to_all)
      {
         m_panel->copyParamToAll();
      }
      else
      {
         if(m_proph->transferSoundParam2Proph(m_sound_u8))
         {
            m_topframe->transferStarted();
         }
      }
   }
}

void SoundSynthPanelImpl::OnFilterResonanceSliderChange(wxScrollEvent& event)
{
   wxString str;
   uint32_t t;

   t = m_filt_resonance->GetValue();
   t = (t * 64) + 63;
   m_proph->m_sound_param_as[m_sound_u8].val_s.filt_resonance[1] = (t & 0xff);
   m_proph->m_sound_param_as[m_sound_u8].val_s.filt_resonance[0] = (t & 0xff00) >> 8;

   if(m_proph->getStereoMode())
   {
      if(m_sound_u8 < 8)
      {
         m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.filt_resonance[1] = (t & 0xff);
         m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.filt_resonance[0] = (t & 0xff00) >> 8;
      }
      else
      {
         m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.filt_resonance[1] = (t & 0xff);
         m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.filt_resonance[0] = (t & 0xff00) >> 8;
      }
   }

   if((m_proph->m_sound_param_as[m_sound_u8].val_s.filt_resonance[0] == 0x00) && (m_proph->m_sound_param_as[m_sound_u8].val_s.filt_resonance[1] == 0x00))
   {
      m_filt_resonance_val->SetValue(wxT("0"));
      m_filt_resonance->SetValue(0);
   }
   else
   {
      t = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_resonance[1];
      t |= ((uint16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.filt_resonance[0] << 8);
      m_filt_resonance->SetValue((t - 63) / 64);
      str.sprintf(wxT("%d"), ((t - 63) / 64) / 2);
      m_filt_resonance_val->SetValue(str);
   }

   m_proph->updateParamBytesFromStruct();
   updateGUI();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_apply_to_all)
      {
         m_panel->copyParamToAll();
      }
      else
      {
         if(m_proph->transferSoundParam2Proph(m_sound_u8))
         {
            m_topframe->transferStarted();
         }
      }
   }
}

void SoundSynthPanelImpl::OnFilterEnvelopeAmountSliderChange(wxScrollEvent& event)
{
   wxString str;
   m_proph->m_sound_param_as[m_sound_u8].val_s.filt_env_amount = m_filt_env_amount->GetValue() + 0x80;
   if(m_proph->getStereoMode())
   {
      if(m_sound_u8 < 8)
      {
         m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.filt_env_amount = m_filt_env_amount->GetValue() + 0x80;
      }
      else
      {
         m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.filt_env_amount = m_filt_env_amount->GetValue() + 0x80;
      }
   }
   updateVCFGraph = true;
   str.sprintf(wxT("%+d"), (int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.filt_env_amount - 0x80);
   m_filt_env_amount_val->SetValue(str);

   m_proph->updateParamBytesFromStruct();
   updateGUI();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_apply_to_all)
      {
         m_panel->copyParamToAll();
      }
      else
      {
         if(m_proph->transferSoundParam2Proph(m_sound_u8))
         {
            m_topframe->transferStarted();
         }
      }
   }
}

void SoundSynthPanelImpl::OnFilterKeyboardTrackSliderChange(wxScrollEvent& event)
{
   wxString str;
   m_proph->m_sound_param_as[m_sound_u8].val_s.filt_key_tracking = m_filt_key_tracking->GetValue();
   if(m_proph->getStereoMode())
   {
      if(m_sound_u8 < 8)
      {
         m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.filt_key_tracking = m_filt_key_tracking->GetValue();
      }
      else
      {
         m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.filt_key_tracking = m_filt_key_tracking->GetValue();
      }
   }
   str.sprintf(wxT("%d"), (m_proph->m_sound_param_as[m_sound_u8].val_s.filt_key_tracking) / 2);
   m_filt_key_tracking_val->SetValue(str);

   m_proph->updateParamBytesFromStruct();
   updateGUI();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_apply_to_all)
      {
         m_panel->copyParamToAll();
      }
      else
      {
         if(m_proph->transferSoundParam2Proph(m_sound_u8))
         {
            m_topframe->transferStarted();
         }
      }
   }
}

void SoundSynthPanelImpl::OnVelocityAttackSliderChange(wxScrollEvent& event)
{
   wxString str;
   m_proph->m_sound_param_as[m_sound_u8].val_s.attack_vel_sensitivity = m_attack_vel_sensitivity->GetValue() + 0x80;
   if(m_proph->getStereoMode())
   {
      if(m_sound_u8 < 8)
      {
         m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.attack_vel_sensitivity = m_attack_vel_sensitivity->GetValue() + 0x80;
      }
      else
      {
         m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.attack_vel_sensitivity = m_attack_vel_sensitivity->GetValue() + 0x80;
      }
   }

   str.sprintf(wxT("%+d"), (int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.attack_vel_sensitivity - 0x80);
   m_attack_vel_sensitivity_val->SetValue(str);

   m_proph->updateParamBytesFromStruct();
   updateGUI();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_apply_to_all)
      {
         m_panel->copyParamToAll();
      }
      else
      {
         if(m_proph->transferSoundParam2Proph(m_sound_u8))
         {
            m_topframe->transferStarted();
         }
      }
   }
}

void SoundSynthPanelImpl::OnVelocityReleaseSliderChange(wxScrollEvent& event)
{
   wxString str;
   m_proph->m_sound_param_as[m_sound_u8].val_s.release_vel_sensitivity = m_release_vel_sensitivity->GetValue() + 0x80;
   if(m_proph->getStereoMode())
   {
      if(m_sound_u8 < 8)
      {
         m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.release_vel_sensitivity = m_release_vel_sensitivity->GetValue() + 0x80;
      }
      else
      {
         m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.release_vel_sensitivity = m_release_vel_sensitivity->GetValue() + 0x80;
      }
   }

   str.sprintf(wxT("%+d"), (int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.release_vel_sensitivity - 0x80);
   m_release_vel_sensitivity_val->SetValue(str);

   m_proph->updateParamBytesFromStruct();
   updateGUI();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_apply_to_all)
      {
         m_panel->copyParamToAll();
      }
      else
      {
         if(m_proph->transferSoundParam2Proph(m_sound_u8))
         {
            m_topframe->transferStarted();
         }
      }
   }
}

void SoundSynthPanelImpl::OnVelocityVCAPeakSliderChange(wxScrollEvent& event)
{
   wxString str;
   m_proph->m_sound_param_as[m_sound_u8].val_s.amp_peak_vel_sensitivity = m_amp_peak_vel_sensitivity->GetValue() + 0x80;
   if(m_proph->getStereoMode())
   {
      if(m_sound_u8 < 8)
      {
         m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.amp_peak_vel_sensitivity = m_amp_peak_vel_sensitivity->GetValue() + 0x80;
      }
      else
      {
         m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.amp_peak_vel_sensitivity = m_amp_peak_vel_sensitivity->GetValue() + 0x80;
      }
   }
   str.sprintf(wxT("%+d"), (int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.amp_peak_vel_sensitivity - 0x80);
   m_amp_peak_vel_sensitivity_val->SetValue(str);
   m_proph->updateParamBytesFromStruct();
   updateGUI();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_apply_to_all)
      {
         m_panel->copyParamToAll();
      }
      else
      {
         if(m_proph->transferSoundParam2Proph(m_sound_u8))
         {
            m_topframe->transferStarted();
         }
      }
   }
}

void SoundSynthPanelImpl::OnVelocityVFCPeakSliderChange(wxScrollEvent& event)
{
   wxString str;
   m_proph->m_sound_param_as[m_sound_u8].val_s.filt_peak_vel_sensitivity = m_filt_peak_vel_sensitivity->GetValue() + 0x80;
   if(m_proph->getStereoMode())
   {
      if(m_sound_u8 < 8)
      {
         m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.filt_peak_vel_sensitivity = m_filt_peak_vel_sensitivity->GetValue() + 0x80;
      }
      else
      {
         m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.filt_peak_vel_sensitivity = m_filt_peak_vel_sensitivity->GetValue() + 0x80;
      }
   }
   str.sprintf(wxT("%+d"), (int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.filt_peak_vel_sensitivity - 0x80);
   m_filt_peak_vel_sensitivity_val->SetValue(str);

   m_proph->updateParamBytesFromStruct();
   updateGUI();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_apply_to_all)
      {
         m_panel->copyParamToAll();
      }
      else
      {
         if(m_proph->transferSoundParam2Proph(m_sound_u8))
         {
            m_topframe->transferStarted();
         }
      }
   }
}


void SoundSynthPanelImpl::OnLeftDown(wxMouseEvent& event)
{
	show_vcf_env_amount = !show_vcf_env_amount;
   updateVCFGraph = true;
   trigger = true;
	updateGUI();
}

void SoundSynthPanelImpl::OnLoad(wxCommandEvent& event)
{
   m_panel->OnLoad(event);
   displaySettings();
}


void SoundSynthPanelImpl::OnSave(wxCommandEvent& event)
{
   m_panel->OnSave(event);
}


void SoundSynthPanelImpl::OnPlay(wxCommandEvent& event)
{
   m_panel->OnPlay(event);
}

void SoundSynthPanelImpl::OnCopy(wxCommandEvent& event)
{
   m_panel->OnCopy(event);
}

void SoundSynthPanelImpl::OnCopyParamToAll(wxCommandEvent& event)
{
   m_panel->OnCopyParamToAll(event);
}

void SoundSynthPanelImpl::OnGetSound(wxCommandEvent& event)
{
   m_panel->OnGetSound(event);
   displaySettings();
}

void SoundSynthPanelImpl::OnGetSoundParam(wxCommandEvent& event)
{
   m_panel->OnGetSoundParam(event);
   displaySettings();
}

void SoundSynthPanelImpl::OnDeleteSound(wxCommandEvent& event)
{
   m_panel->OnDeleteSound(event);
   displaySettings();
}



void SoundSynthPanelImpl::OnImport(wxCommandEvent& event)
{
   m_panel->OnImport(event);
   displaySettings();
}


void SoundSynthPanelImpl::OnExport(wxCommandEvent& event)
{
   m_panel->OnExport(event);
}


void SoundSynthPanelImpl::OnPurge(wxCommandEvent& event)
{
   m_panel->OnPurge(event);
   displaySettings();
}

