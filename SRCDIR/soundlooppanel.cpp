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
#include "clickarea.h"
#include "keyboard.h"
#include "soundkeyboard.h"
#include "wavedisp.h"
#include "wave.h"
#include "soundcopydlg.h"
#include "loadsample.h"
#include "audio.h"
#include "soundsamplepanel.h"
#include "soundsynthpanel.h"
#include "soundlooppanel.h"

#define ZERO_CROSSING_RANGE_DELTA 10
#define MOVE_POINTS_BIG_STEPS_TICKS 2000



SoundLoopPanelImpl::SoundLoopPanelImpl(wxWindow *parent, MyPanel *topframe, Proph2000 *proph, uint8_t sound_u8, MySoundParam *panel) :
   SoundLoopPanel(parent),
   m_topframe(topframe), m_proph(proph), m_sound_u8(sound_u8), m_old_start_point(0), m_old_end_point(0),
   m_old_sustainloop_start(0), m_old_sustainloop_end(0),
   m_old_releaseloop_start(0), m_old_releaseloop_end(0),
   m_panel(panel), m_update_loop_params_active(true), m_update_gui_inhibit(false)
{
   activateSound(0);
   
#ifdef __WXMAC__ // 130205
   m_wave_selection->SetMinSize(wxSize(125, -1));
   m_velocity_start_point->SetMinSize(wxSize(255, -1));
   m_tune_table->ToggleWindowStyle(wxBORDER_SUNKEN);
   m_velocity_start_point->ToggleWindowStyle(wxBORDER_SUNKEN);
#endif
   
   m_wave_disp->setSampleData(m_proph->getSampleData(m_sound_u8));

   m_wave_selection->AppendString(wxT("whole sample"));
   m_wave_selection->AppendString(wxT("sustain loop"));
   m_wave_selection->AppendString(wxT("release loop"));
   m_wave_selection->SetSelection(0);
   m_wave_disp->setHighlightType(WaveDisp::WAVEDISP_SAMPLERANGE);

   updateGUI();
}


SoundLoopPanelImpl::~SoundLoopPanelImpl()
{
}


void SoundLoopPanelImpl::OnPlay(wxCommandEvent& event)
{
   m_panel->OnPlay(event);
}

wxToggleButton* SoundLoopPanelImpl::getPlayButton(void)
{
   return m_play_button;
}

void SoundLoopPanelImpl::activateSound(uint8_t sound_u8)
{
   m_sound_u8 = sound_u8;
   
   m_update_loop_params_active = false;

   m_wave_disp->setSampleData(m_proph->getSampleData(m_sound_u8));

    m_end_point->SetRange(0, m_end_point->GetMax());
    m_sustainloop_end->SetRange(0, m_sustainloop_end->GetMax());
    m_releaseloop_end->SetRange(0, m_releaseloop_end->GetMax());
    m_start_point->SetRange(m_start_point->GetMin(), MAX_SAMPLE_BANK_WORDS_EXTENDED);
    m_end_point->SetRange(m_end_point->GetMin(), MAX_SAMPLE_BANK_WORDS_EXTENDED);
    m_sustainloop_start->SetRange(m_sustainloop_start->GetMin(), MAX_SAMPLE_BANK_WORDS_EXTENDED);
    m_sustainloop_end->SetRange(m_sustainloop_end->GetMin(), MAX_SAMPLE_BANK_WORDS_EXTENDED);
    m_releaseloop_start->SetRange(m_releaseloop_start->GetMin(), MAX_SAMPLE_BANK_WORDS_EXTENDED);
    m_releaseloop_end->SetRange(m_releaseloop_end->GetMin(),  MAX_SAMPLE_BANK_WORDS_EXTENDED);
   m_start_point->SetValue(m_proph->getStartPoint(m_sound_u8));
   m_end_point->SetValue(m_proph->getEndPoint(m_sound_u8));

   m_sustainloop_start->SetValue(m_proph->getSustainLoopStart(m_sound_u8));
   m_sustainloop_end->SetValue(m_proph->getSustainLoopEnd(m_sound_u8));

   m_releaseloop_start->SetValue(m_proph->getReleaseLoopStart(m_sound_u8));
   m_releaseloop_end->SetValue(m_proph->getReleaseLoopEnd(m_sound_u8));

   m_end_point->SetRange(m_start_point->GetValue() + 1, m_end_point->GetMax());
   m_sustainloop_end->SetRange(m_sustainloop_start->GetValue() + 1, m_sustainloop_end->GetMax());
   m_releaseloop_end->SetRange(m_releaseloop_start->GetValue() + 1, m_releaseloop_end->GetMax());
    
   updateWaveView();
   updateGUI();

   m_update_loop_params_active = true;
}


void SoundLoopPanelImpl::OnImport(wxCommandEvent& event)
{
	m_panel->OnImport(event);
}


void SoundLoopPanelImpl::OnExport(wxCommandEvent& event)
{
	m_panel->OnExport(event);
}


void SoundLoopPanelImpl::OnPurge(wxCommandEvent& event)
{
	m_panel->OnPurge(event);
}

void SoundLoopPanelImpl::resetWaveViewZoom(void)
{
   m_wave_disp->resetZoom();
   m_wave_disp->render();
}

void SoundLoopPanelImpl::updateWaveView(void)
{
   m_start_point->SetValue(m_proph->getStartPoint(m_sound_u8));
   m_end_point->SetValue(m_proph->getEndPoint(m_sound_u8));

   m_sustainloop_start->SetValue(m_proph->getSustainLoopStart(m_sound_u8));
   m_sustainloop_end->SetValue(m_proph->getSustainLoopEnd(m_sound_u8));

   m_releaseloop_start->SetValue(m_proph->getReleaseLoopStart(m_sound_u8));
   m_releaseloop_end->SetValue(m_proph->getReleaseLoopEnd(m_sound_u8));

   m_wave_disp->setStartPoint(m_proph->getStartPoint(m_sound_u8));
   m_wave_disp->setEndPoint(m_proph->getEndPoint(m_sound_u8));
   m_wave_disp->setSampleWords(m_proph->getSampleWords(m_sound_u8));

   m_wave_disp->setSustainLoopStart(m_proph->getSustainLoopStart(m_sound_u8));
   m_wave_disp->setSustainLoopEnd(m_proph->getSustainLoopEnd(m_sound_u8));
   m_wave_disp->setDisplaySustainLoop(m_proph->sustainLoopEnabled(m_sound_u8));

   m_wave_disp->setReleaseLoopStart(m_proph->getReleaseLoopStart(m_sound_u8));
   m_wave_disp->setReleaseLoopEnd(m_proph->getReleaseLoopEnd(m_sound_u8));
   m_wave_disp->setDisplayReleaseLoop(m_proph->releaseLoopEnabled(m_sound_u8));

   m_wave_disp->Refresh(true);
}

void SoundLoopPanelImpl::OnWaveSelection(wxCommandEvent& event)
{
   m_panel->stopPlayback();
   switch(m_wave_selection->GetSelection())
   {
      case 0:
         m_wave_disp->setHighlightType(WaveDisp::WAVEDISP_SAMPLERANGE);
         break;
      case 1:
         m_wave_disp->setHighlightType(WaveDisp::WAVEDISP_SUSTAINLOOP);
         break;
      case 2:
         m_wave_disp->setHighlightType(WaveDisp::WAVEDISP_RELEASELOOP);
         break;
      default:
         break;
   }
}

void SoundLoopPanelImpl::updateGUI(void)
{
   wxString str;

   if(!m_update_gui_inhibit)
   {
      str.sprintf(wxT("%d"), m_proph->getSampleWords(m_sound_u8));
      m_sample_words_txt->SetValue(str);

      m_start_point->SetRange(m_start_point->GetMin(), m_proph->getSampleWords(m_sound_u8));
      m_end_point->SetRange(m_end_point->GetMin(), m_proph->getSampleWords(m_sound_u8));
      
      if(m_proph->m_sound_param_as[m_sound_u8].val_s.sample_status & 0x01)
      {
         m_sust_loop_ena->SetValue(true);
         m_forward_loop_ena->Disable();
         m_forward_loop_ena->SetValue(false);
      }
      else
      {
         m_sust_loop_ena->SetValue(false);
         m_forward_loop_ena->Enable();
      }
      if(m_proph->m_sound_param_as[m_sound_u8].val_s.sample_status & 0x02)
      {
         m_release_loop_ena->SetValue(true);
      }
      else
      {
         m_release_loop_ena->SetValue(false);
      }
      if(m_proph->m_sound_param_as[m_sound_u8].val_s.sample_status & 0x04)
      {
         m_forward_loop_ena->SetValue(true);
         m_sust_loop_ena->Disable();
         m_sust_loop_ena->SetValue(false);
      }
      else
      {
         m_forward_loop_ena->SetValue(false);
         m_sust_loop_ena->Enable();
      }
      if(m_proph->m_sound_param_as[m_sound_u8].val_s.sample_status & 0x08)
      {
         m_reverse_ena->SetValue(true);
      }
      else
      {
         m_reverse_ena->SetValue(false);
      }

      m_velocity_start_point->SetValue((int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.velocity_start_point - 0x80);

      m_tune_table->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.tune_table);

      switch(m_proph->m_sound_param_as[m_sound_u8].val_s.sample_rate)
      {
         case 0:
            m_sample_rate->SetValue(wxT("31.250kHz"));
            break;
         case 1:
            m_sample_rate->SetValue(wxT("41.667kHz"));
            break;
         case 0xff:
            m_sample_rate->SetValue(wxT("15.625kHz"));
            break;
         default:
            m_sample_rate->SetValue(wxT("invalid"));
            break;
      }
   }
}


void SoundLoopPanelImpl::OnSustLoopChange(wxCommandEvent& event)
{
   if(m_sust_loop_ena->GetValue())
   {
      m_forward_loop_ena->SetValue(false);
      m_forward_loop_ena->Disable();
   }
   else
   {
      m_forward_loop_ena->Enable();
   }
   OnCheckboxChange(event);
   m_wave_disp->setDisplaySustainLoop(m_proph->sustainLoopEnabled(m_sound_u8));
   m_wave_disp->setDisplayReleaseLoop(m_proph->releaseLoopEnabled(m_sound_u8));
}

void SoundLoopPanelImpl::OnForwardLoopChange(wxCommandEvent& event)
{
   if(m_forward_loop_ena->GetValue())
   {
      m_sust_loop_ena->SetValue(false);
      m_sust_loop_ena->Disable();
   }
   else
   {
      m_sust_loop_ena->Enable();
   }

   OnCheckboxChange(event);
   m_wave_disp->setDisplaySustainLoop(m_proph->sustainLoopEnabled(m_sound_u8));
   m_wave_disp->setDisplayReleaseLoop(m_proph->releaseLoopEnabled(m_sound_u8));
}


void SoundLoopPanelImpl::OnCheckboxChange(wxCommandEvent& event)
{
   if(m_sust_loop_ena->GetValue())
   {
      m_proph->m_sound_param_as[m_sound_u8].val_s.sample_status |= 0x01;
      if(m_proph->getStereoMode())
      {
         if(m_sound_u8 < 8)
         {
            m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.sample_status |= 0x01;
         }
         else
         {
            m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.sample_status |= 0x01;
         }
      }
   }
   else
   {
      m_proph->m_sound_param_as[m_sound_u8].val_s.sample_status &= ~0x01;
      if(m_proph->getStereoMode())
      {
         if(m_sound_u8 < 8)
         {
            m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.sample_status &= ~0x01;
         }
         else
         {
            m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.sample_status &= ~0x01;
         }
      }
   }
   if(m_release_loop_ena->GetValue())
   {
      m_proph->m_sound_param_as[m_sound_u8].val_s.sample_status |= 0x02;
      if(m_proph->getStereoMode())
      {
         if(m_sound_u8 < 8)
         {
            m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.sample_status |= 0x02;
         }
         else
         {
            m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.sample_status |= 0x02;
         }
      }
   }
   else
   {
      m_proph->m_sound_param_as[m_sound_u8].val_s.sample_status &= ~0x02;
      if(m_proph->getStereoMode())
      {
         if(m_sound_u8 < 8)
         {
            m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.sample_status &= ~0x02;
         }
         else
         {
            m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.sample_status &= ~0x02;
         }
      }
   }
   if(m_forward_loop_ena->GetValue())
   {
      m_proph->m_sound_param_as[m_sound_u8].val_s.sample_status |= 0x04;
      if(m_proph->getStereoMode())
      {
         if(m_sound_u8 < 8)
         {
            m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.sample_status |= 0x04;
         }
         else
         {
            m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.sample_status |= 0x04;
         }
      }
   }
   else
   {
      m_proph->m_sound_param_as[m_sound_u8].val_s.sample_status &= ~0x04;
      if(m_proph->getStereoMode())
      {
         if(m_sound_u8 < 8)
         {
            m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.sample_status &= ~0x04;
         }
         else
         {
            m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.sample_status &= ~0x04;
         }
      }
   }
   if(m_reverse_ena->GetValue())
   {
      m_proph->m_sound_param_as[m_sound_u8].val_s.sample_status |= 0x08;
      if(m_proph->getStereoMode())
      {
         if(m_sound_u8 < 8)
         {
            m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.sample_status |= 0x08;
         }
         else
         {
            m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.sample_status |= 0x08;
         }
      }
   }
   else
   {
      m_proph->m_sound_param_as[m_sound_u8].val_s.sample_status &= ~0x08;
      if(m_proph->getStereoMode())
      {
         if(m_sound_u8 < 8)
         {
            m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.sample_status &= ~0x08;
         }
         else
         {
            m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.sample_status &= ~0x08;
         }
      }
   }

   m_proph->updateParamBytesFromStruct();
   updateGUI();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferSoundParam2Proph(m_sound_u8))
      {
         m_topframe->transferStarted();
      }
   }

   if(m_panel->getAsyncPlayActiveFlag())
   {
      m_panel->startPlayback();
   }
}


void SoundLoopPanelImpl::OnSliderChange(wxScrollEvent &event)
{
//   uint16_t t;
   m_proph->m_sound_param_as[m_sound_u8].val_s.tune_table = m_tune_table->GetValue();
   m_proph->m_sound_param_as[m_sound_u8].val_s.velocity_start_point = m_velocity_start_point->GetValue() + 0x80;

   if(m_proph->getStereoMode())
   {
      if(m_sound_u8 < 8)
      {
         m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.tune_table = m_tune_table->GetValue();
         m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.velocity_start_point = m_velocity_start_point->GetValue() + 0x80;
      }
      else
      {
         m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.tune_table = m_tune_table->GetValue();
         m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.velocity_start_point = m_velocity_start_point->GetValue() + 0x80;
      }
   }

   m_proph->updateParamBytesFromStruct();
   updateGUI();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferSoundParam2Proph(m_sound_u8))
      {
         m_topframe->transferStarted();
      }
   }
}


void SoundLoopPanelImpl::OnLoad(wxCommandEvent& event)
{
	m_panel->OnLoad(event);
}


void SoundLoopPanelImpl::OnSave(wxCommandEvent& event)
{
	m_panel->OnSave(event);
}


void SoundLoopPanelImpl::updateLoopParameters(void)
{
   m_update_gui_inhibit = true;
   if(m_update_loop_params_active)
   {
      for(int i = 0; i < 2; i++)
      {
         // check loop point constraints and correct if required
         if(m_end_point->GetValue() <= m_sustainloop_start->GetValue())
         {
            m_sustainloop_start->SetValue(m_end_point->GetValue() - 1);
         }
         if(m_end_point->GetValue() <= m_sustainloop_end->GetValue())
         {
            m_sustainloop_end->SetValue(m_end_point->GetValue() - 1);
         }
         if(m_sustainloop_end->GetValue() <= m_sustainloop_start->GetValue())
         {
            m_sustainloop_start->SetValue(m_sustainloop_end->GetValue() - 1);
         }

         if(m_end_point->GetValue() <= m_releaseloop_start->GetValue())
         {
            m_releaseloop_start->SetValue(m_end_point->GetValue() - 1);
         }
         if(m_end_point->GetValue() <= m_releaseloop_end->GetValue())
         {
            m_releaseloop_end->SetValue(m_end_point->GetValue() - 1);
         }
         if(m_releaseloop_end->GetValue() <= m_releaseloop_start->GetValue())
         {
            m_releaseloop_start->SetValue(m_releaseloop_end->GetValue() - 1);
         }

         if(m_sustainloop_start->GetValue() <= m_start_point->GetValue())
         {
            m_sustainloop_start->SetValue(m_start_point->GetValue() + 1);
         }
         if(m_releaseloop_start->GetValue() <= m_start_point->GetValue())
         {
            m_releaseloop_start->SetValue(m_start_point->GetValue() + 1);
         }
         if(m_releaseloop_end->GetValue() <= m_sustainloop_end->GetValue())
         {
            //m_releaseloop_end->SetValue(m_sustainloop_end->GetValue() + 1);
            m_sustainloop_end->SetValue(m_releaseloop_end->GetValue() - 1);
         }
      }


      m_wave_disp->setStartPoint(m_start_point->GetValue());
      m_proph->setStartPoint(m_sound_u8, m_start_point->GetValue());
      if(m_proph->getStereoMode())
      {
         if(m_sound_u8 < 8)
         {
            m_proph->setStartPoint(m_sound_u8 + 8, m_start_point->GetValue());
         }
         else
         {
            m_proph->setStartPoint(m_sound_u8 - 8, m_start_point->GetValue());
         }
      }

      m_wave_disp->setEndPoint(m_end_point->GetValue());
      m_proph->setEndPoint(m_sound_u8, m_end_point->GetValue());
      if(m_proph->getStereoMode())
      {
         if(m_sound_u8 < 8)
         {
            m_proph->setEndPoint(m_sound_u8 + 8, m_end_point->GetValue());
         }
         else
         {
            m_proph->setEndPoint(m_sound_u8 - 8, m_end_point->GetValue());
         }
      }

      m_wave_disp->setSustainLoopStart(m_sustainloop_start->GetValue());
      m_proph->setSustainLoopStart(m_sound_u8, m_sustainloop_start->GetValue());
      if(m_proph->getStereoMode())
      {
         if(m_sound_u8 < 8)
         {
            m_proph->setSustainLoopStart(m_sound_u8 + 8, m_sustainloop_start->GetValue());
         }
         else
         {
            m_proph->setSustainLoopStart(m_sound_u8 - 8, m_sustainloop_start->GetValue());
         }
      }
      m_wave_disp->setSustainLoopEnd(m_sustainloop_end->GetValue());
      m_proph->setSustainLoopEnd(m_sound_u8, m_sustainloop_end->GetValue());
      if(m_proph->getStereoMode())
      {
         if(m_sound_u8 < 8)
         {
            m_proph->setSustainLoopEnd(m_sound_u8 + 8, m_sustainloop_end->GetValue());
         }
         else
         {
            m_proph->setSustainLoopEnd(m_sound_u8 - 8, m_sustainloop_end->GetValue());
         }
      }

      m_wave_disp->setReleaseLoopStart(m_releaseloop_start->GetValue());
      m_proph->setReleaseLoopStart(m_sound_u8, m_releaseloop_start->GetValue());
      if(m_proph->getStereoMode())
      {
         if(m_sound_u8 < 8)
         {
            m_proph->setReleaseLoopStart(m_sound_u8 + 8, m_releaseloop_start->GetValue());
         }
         else
         {
            m_proph->setReleaseLoopStart(m_sound_u8 - 8, m_releaseloop_start->GetValue());
         }
      }
      m_wave_disp->setReleaseLoopEnd(m_releaseloop_end->GetValue());
      m_proph->setReleaseLoopEnd(m_sound_u8, m_releaseloop_end->GetValue());
      if(m_proph->getStereoMode())
      {
         if(m_sound_u8 < 8)
         {
            m_proph->setReleaseLoopEnd(m_sound_u8 + 8, m_releaseloop_end->GetValue());
         }
         else
         {
            m_proph->setReleaseLoopEnd(m_sound_u8 - 8, m_releaseloop_end->GetValue());
         }
      }

      m_wave_disp->Refresh(true);

      if(m_panel->getAsyncPlayActiveFlag())
      {
         m_panel->startPlayback();
      }

      if(m_topframe->getOnlineUpdateActive())
      {
         if(m_proph->transferSoundParam2Proph(m_sound_u8))
         {
            m_topframe->transferStarted();
         }
      }
   }
   m_update_gui_inhibit = false;
   updateGUI();
}

uint16_t SoundLoopPanelImpl::getWaveSelection(void) const
{
   return m_wave_selection->GetSelection();
}

void SoundLoopPanelImpl::OnStartPoint(wxSpinEvent &event)
{
   wxString str;
   if(m_update_loop_params_active)
   {
      m_end_point->SetRange(m_start_point->GetValue() + 1, m_end_point->GetMax());
   }

   if(m_old_start_point != m_start_point->GetValue())
   {
      if( (((int32_t)m_old_start_point - (int32_t)m_start_point->GetValue()) <= 10) && (((int32_t)m_old_start_point - (int32_t)m_start_point->GetValue()) >= -10))
      {
         uint32_t t = m_start_point->GetValue();
         uint16_t *p;
         p = m_proph->getSampleData(m_sound_u8);
         if(((int32_t)m_old_start_point - (int32_t)m_start_point->GetValue()) < 0)
         {
            while(((p[t] >= ((4096 / 2) + ZERO_CROSSING_RANGE_DELTA)) || (p[t] <= ((4096 / 2) - ZERO_CROSSING_RANGE_DELTA)))  && ((int32_t)t < (m_end_point->GetValue() - 1)))
            {
               t++;
            }
         }
         else
         {
            while(((p[t] >= ((4096 / 2) + ZERO_CROSSING_RANGE_DELTA)) || (p[t] <= ((4096 / 2) - ZERO_CROSSING_RANGE_DELTA)))  && (t > 0))
            {
               t--;
            }
         }

         m_start_point->SetValue(t);
      }

      if(m_start_point->GetValue() >= m_end_point->GetValue())
      {
         m_start_point->SetValue(m_end_point->GetValue() - 1);
      }

      //m_end_point->SetMin(m_start_point->GetValue() + 1);

      str.sprintf(wxT("%d"), m_end_point->GetValue() - m_start_point->GetValue());
      m_sample_words_txt->SetValue(str);

      updateLoopParameters();

      m_old_start_point = m_start_point->GetValue();
   }
}


void SoundLoopPanelImpl::OnEndPoint(wxSpinEvent &event)
{
   wxString str;

   if(m_update_loop_params_active)
   {
      m_end_point->SetRange(m_start_point->GetValue() + 1, m_end_point->GetMax());
   }

   if(m_sustainloop_end->GetMin() <= m_end_point->GetValue())
   {
      m_sustainloop_end->SetRange(m_end_point->GetValue(), m_sustainloop_end->GetMax());
   }

   if(m_old_end_point != m_end_point->GetValue())
   {

      if(m_end_point->GetValue() <= m_start_point->GetValue())
      {
         m_end_point->SetValue(m_start_point->GetValue() + 1);
      }

      //m_start_point->SetMax(m_end_point->GetValue() - 1);

      str.sprintf(wxT("%d"), m_end_point->GetValue() - m_start_point->GetValue());
      m_sample_words_txt->SetValue(str);

      updateLoopParameters();
         
      m_old_end_point = m_end_point->GetValue();
   }
}


void SoundLoopPanelImpl::OnSustainLoopStart(wxSpinEvent &event)
{
   wxString str;
   if(m_update_loop_params_active)
   {
      m_sustainloop_end->SetRange(m_sustainloop_start->GetValue() + 1, m_sustainloop_end->GetMax());
   }
   if(m_old_sustainloop_start != m_sustainloop_start->GetValue())
   {
      if(m_sustainloop_start->GetValue() >= m_sustainloop_end->GetValue())
      {
         m_sustainloop_start->SetValue(m_sustainloop_end->GetValue() - 1);
      }

      updateLoopParameters();

      m_old_sustainloop_start = m_sustainloop_start->GetValue();
   }
}


void SoundLoopPanelImpl::OnMoveStartPointForward1(wxCommandEvent& event)
{
   moveStartPointForward();
}

void SoundLoopPanelImpl::OnMoveStartPointForward10(wxCommandEvent& event)
{
   m_start_point->SetValue(m_start_point->GetValue() + MOVE_POINTS_BIG_STEPS_TICKS);
   moveStartPointForward();
}

void SoundLoopPanelImpl::OnMoveStartPointBackward1(wxCommandEvent& event)
{
   moveStartPointBackward();
}

void SoundLoopPanelImpl::OnMoveStartPointBackward10(wxCommandEvent& event)
{
   int32_t t = m_start_point->GetValue();
   t -= MOVE_POINTS_BIG_STEPS_TICKS;
   if(t < 0)
   {
      t = 0;
   }
   m_start_point->SetValue(t);
   moveStartPointBackward();
}

void SoundLoopPanelImpl::OnMoveEndPointBackward1(wxCommandEvent& event)
{
   moveEndPointBackward();
}

void SoundLoopPanelImpl::OnMoveEndPointBackward10(wxCommandEvent& event)
{
   int32_t t = m_end_point->GetValue();
   t -= MOVE_POINTS_BIG_STEPS_TICKS;
   if(t < 0)
   {
      t = 0;
   }
   m_end_point->SetValue(t);
   moveEndPointBackward();
}

void SoundLoopPanelImpl::OnMoveEndPointForward1(wxCommandEvent& event)
{
   moveEndPointForward();
}

void SoundLoopPanelImpl::OnMoveEndPointForward10(wxCommandEvent& event)
{
   m_end_point->SetValue(m_end_point->GetValue() + MOVE_POINTS_BIG_STEPS_TICKS);
   moveEndPointForward();
}

void SoundLoopPanelImpl::OnMoveSustainStartPointForward1(wxCommandEvent& event)
{
   moveSustainStartPointForward();
}

void SoundLoopPanelImpl::OnMoveSustainStartPointForward10(wxCommandEvent& event)
{
   m_sustainloop_start->SetValue(m_sustainloop_start->GetValue() + MOVE_POINTS_BIG_STEPS_TICKS);
   moveSustainStartPointForward();
}

void SoundLoopPanelImpl::moveSustainStartPointForward(void)
{
   uint32_t t = m_sustainloop_start->GetValue();
   uint16_t *p;
   p = m_proph->getSampleData(m_sound_u8);

   t++;

   while( ((p[t - 1] < (4096 / 2)) && (p[t] < (4096 / 2)) || ((p[t - 1] > (4096 / 2)) && (p[t] > (4096 / 2)))) && ((int32_t)t < (m_sustainloop_end->GetValue() - 1)))
   {
      t++;
   }

   m_sustainloop_start->SetValue(t);

   if(m_sustainloop_start->GetValue() >= m_sustainloop_end->GetValue())
   {
      m_sustainloop_start->SetValue(m_sustainloop_end->GetValue() - 1);
   }

   updateLoopParameters();

   m_old_sustainloop_start = m_sustainloop_start->GetValue();
}

void SoundLoopPanelImpl::OnMoveSustainStartPointBackward1(wxCommandEvent& event)
{
   moveSustainStartPointBackward();
}

void SoundLoopPanelImpl::OnMoveSustainStartPointBackward10(wxCommandEvent& event)
{
   int32_t t = m_sustainloop_start->GetValue();
   t -= MOVE_POINTS_BIG_STEPS_TICKS;
   if(t < 0)
   {
      t = 0;
   }
   m_sustainloop_start->SetValue(t);
   moveSustainStartPointBackward();
}

void SoundLoopPanelImpl::moveSustainStartPointBackward(void)
{
   int32_t t = m_sustainloop_start->GetValue();
   uint16_t *p;
   p = m_proph->getSampleData(m_sound_u8);

   t--;
   if(t < 0)
   {
      t = 0;
   }

   while( ((p[t - 1] < (4096 / 2)) && (p[t] < (4096 / 2)) || ((p[t - 1] > (4096 / 2)) && (p[t] > (4096 / 2)))) && (t > 1))
   {
      t--;
   }

   m_sustainloop_start->SetValue(t);

   if(m_sustainloop_start->GetValue() >= m_sustainloop_end->GetValue())
   {
      m_sustainloop_start->SetValue(m_sustainloop_end->GetValue() - 1);
   }

   updateLoopParameters();

   m_old_sustainloop_start = m_sustainloop_start->GetValue();

}

void SoundLoopPanelImpl::OnMoveSustainEndPointForward1(wxCommandEvent& event)
{
   moveSustainEndPointForward();
}

void SoundLoopPanelImpl::OnMoveSustainEndPointForward10(wxCommandEvent& event)
{
   m_sustainloop_end->SetValue(m_sustainloop_end->GetValue() + MOVE_POINTS_BIG_STEPS_TICKS);
   moveSustainEndPointForward();
}

void SoundLoopPanelImpl::moveSustainEndPointForward(void)
{
   uint32_t t = m_sustainloop_end->GetValue();
   uint16_t *p;
   p = m_proph->getSampleData(m_sound_u8);

   t+=2;

   if(m_panel->getIntelligentLoopPoints())
   {
      int32_t t2;
      int32_t t3;
      
      bool fertig = false;
      t2 = ((int32_t)p[m_sustainloop_start->GetValue()] - (4096 / 2)) + ((int32_t)p[m_sustainloop_start->GetValue() + 3] - (4096 / 2));

      do
      {
         while( ((p[t - 1] < (4096 / 2)) && (p[t] < (4096 / 2)) || ((p[t - 1] > (4096 / 2)) && (p[t] > (4096 / 2)))) && (t < (m_proph->getSampleWords(m_sound_u8) - 1)))
         {
            t++;
         }

         t3 = ((int32_t)p[t] - (4096 / 2)) + ((int32_t)p[t + 3] - (4096 / 2));
         if(t2 > 0)
         {
            if(t3 > 0)
            {
               fertig = true;
            }
            else
            {
               t++;
            }
         }
         else
         {
            if(t3 <= 0)
            {
               fertig = true;
            }
            else
            {
               t++;
            }
         }
         if(t >= (m_proph->getSampleWords(m_sound_u8) - 1))
         {
            fertig = true;
         }
      }
      while(!fertig);

   }
   else
   {
      while( ((p[t - 1] < (4096 / 2)) && (p[t] < (4096 / 2)) || ((p[t - 1] > (4096 / 2)) && (p[t] > (4096 / 2)))) && (t < (m_proph->getSampleWords(m_sound_u8) - 1)))
      {
         t++;
      }
   }

   t--;

   m_sustainloop_end->SetValue(t);

   if(m_sustainloop_end->GetValue() <= m_sustainloop_start->GetValue())
   {
      m_sustainloop_end->SetValue(m_sustainloop_start->GetValue() + 1);
   }
   
   updateLoopParameters();
   
   m_old_sustainloop_end = m_sustainloop_end->GetValue();
}

void SoundLoopPanelImpl::OnMoveSustainEndPointBackward1(wxCommandEvent& event)
{
   moveSustainEndPointBackward();
}

void SoundLoopPanelImpl::OnMoveSustainEndPointBackward10(wxCommandEvent& event)
{
   int32_t t = m_sustainloop_end->GetValue();
   t -= MOVE_POINTS_BIG_STEPS_TICKS;
   if(t < 0)
   {
      t = 0;
   }
   m_sustainloop_end->SetValue(t);
   moveSustainEndPointBackward();
}

void SoundLoopPanelImpl::moveSustainEndPointBackward(void)
{
   int32_t t = m_sustainloop_end->GetValue();
   uint16_t *p;
   p = m_proph->getSampleData(m_sound_u8);

   t--;
   if(t < 0)
   {
      t = 0;
   }

   if(m_panel->getIntelligentLoopPoints())
   {
      int32_t t2;
      int32_t t3;
      
      bool fertig = false;
      t2 = ((int32_t)p[m_sustainloop_start->GetValue()] - (4096 / 2)) + ((int32_t)p[m_sustainloop_start->GetValue() + 3] - (4096 / 2));

      do
      {
         while( ((p[t - 1] < (4096 / 2)) && (p[t] < (4096 / 2)) || ((p[t - 1] > (4096 / 2)) && (p[t] > (4096 / 2)))) && (t > (m_sustainloop_start->GetValue() + 1)))
         {
            t--;
         }

         t3 = ((int32_t)p[t] - (4096 / 2)) + ((int32_t)p[t + 3] - (4096 / 2));
         if(t2 > 0)
         {
            if(t3 > 0)
            {
               fertig = true;
            }
            else
            {
               t--;
            }
         }
         else
         {
            if(t3 <= 0)
            {
               fertig = true;
            }
            else
            {
               t--;
            }
         }
         if(t <= (m_sustainloop_start->GetValue() + 1))
         {
            fertig = true;
         }
      }
      while(!fertig);

   }
   else
   {
      while( ((p[t - 1] < (4096 / 2)) && (p[t] < (4096 / 2)) || ((p[t - 1] > (4096 / 2)) && (p[t] > (4096 / 2)))) && (t > (m_sustainloop_start->GetValue() + 1)))
      {
         t--;
      }
   }

   t--;

   m_sustainloop_end->SetValue(t);

   if(m_sustainloop_end->GetValue() <= m_sustainloop_start->GetValue())
   {
      m_sustainloop_end->SetValue(m_sustainloop_start->GetValue() + 1);
   }
   
   updateLoopParameters();
   
   m_old_sustainloop_end = m_sustainloop_end->GetValue();
}

void SoundLoopPanelImpl::OnMoveReleaseStartPointForward1(wxCommandEvent& event)
{
   moveReleaseStartPointForward();
}

void SoundLoopPanelImpl::OnMoveReleaseStartPointForward10(wxCommandEvent& event)
{
   m_releaseloop_start->SetValue(m_releaseloop_start->GetValue() + MOVE_POINTS_BIG_STEPS_TICKS);
   moveReleaseStartPointForward();
}

void SoundLoopPanelImpl::moveReleaseStartPointForward(void)
{
   uint32_t t = m_releaseloop_start->GetValue();
   uint16_t *p;
   uint32_t cnt = 0;
   p = m_proph->getSampleData(m_sound_u8);
   t++;

   if(m_proph->m_sound_param_as[m_sound_u8].val_s.sample_status & 0x04)
   {
      // bf loop
      bool fertig = false;

      while(((p[t + 1] - p[t]) == 0) && ((int32_t)t < (m_releaseloop_end->GetValue() - 1)))
      {
         t++;
      }

      if((p[t + 1] - p[t]) > 1)
      {
         while(!fertig && ((int32_t)t < (m_releaseloop_end->GetValue() - 1)))
         {
            t++;
            if((p[t + 1] - p[t]) < 0)
            {
               fertig = true;
            }
         }
      }
      else
      {
         while(!fertig && ((int32_t)t < (m_releaseloop_end->GetValue() - 1)))
         {
            t++;
            if((p[t + 1] - p[t]) > 0)
            {
               fertig = true;
            }
         }
      }
   }
   else
   {
      while( ((p[t - 1] < (4096 / 2)) && (p[t] < (4096 / 2)) || ((p[t - 1] > (4096 / 2)) && (p[t] > (4096 / 2)))) && ((int32_t)t < (m_releaseloop_end->GetValue() - 1)))
      {
         t++;
      }
   }

   m_releaseloop_start->SetValue(t);
   if(m_releaseloop_start->GetValue() >= m_releaseloop_end->GetValue())
   {
      m_releaseloop_start->SetValue(m_releaseloop_end->GetValue() - 1);
   }

   updateLoopParameters();

   m_old_releaseloop_start = m_releaseloop_start->GetValue();
}

void SoundLoopPanelImpl::OnMoveReleaseStartPointBackward1(wxCommandEvent& event)
{
   moveReleaseStartPointBackward();
}

void SoundLoopPanelImpl::OnMoveReleaseStartPointBackward10(wxCommandEvent& event)
{
   int32_t t = m_releaseloop_start->GetValue();
   t -= MOVE_POINTS_BIG_STEPS_TICKS;
   if(t < 0)
   {
      t = 0;
   }
   m_releaseloop_start->SetValue(t);
   moveReleaseStartPointBackward();
}

void SoundLoopPanelImpl::moveReleaseStartPointBackward(void)
{
   int32_t t = m_releaseloop_start->GetValue();
   uint16_t *p;
   uint32_t cnt = 0;
   p = m_proph->getSampleData(m_sound_u8);

   t--;
   if(t < 0)
   {
      t = 0;
   }
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.sample_status & 0x04)
   {
      // bf loop
      bool fertig = false;

      while(((p[t + 1] - p[t]) == 0) && ((int32_t)t > 1))
      {
         t--;
      }

      if((p[t + 1] - p[t]) > 1)
      {
         while(!fertig && ((int32_t)t > 1))
         {
            t--;
            if((p[t + 1] - p[t]) < 0)
            {
               fertig = true;
            }
         }
      }
      else
      {
         while(!fertig && ((int32_t)t > 1))
         {
            t--;
            if((p[t + 1] - p[t]) > 0)
            {
               fertig = true;
            }
         }
      }   
   }
   else
   {
      while( ((p[t - 1] < (4096 / 2)) && (p[t] < (4096 / 2)) || ((p[t - 1] > (4096 / 2)) && (p[t] > (4096 / 2)))) && (t > 1))
      {
         t--;
      }
   }
   m_releaseloop_start->SetValue(t);
   if(m_releaseloop_start->GetValue() >= m_releaseloop_end->GetValue())
   {
      m_releaseloop_start->SetValue(m_releaseloop_end->GetValue() - 1);
   }

   updateLoopParameters();

   m_old_releaseloop_start = m_releaseloop_start->GetValue();
}

void SoundLoopPanelImpl::OnMoveReleaseEndPointForward1(wxCommandEvent& event)
{
   moveReleaseEndPointForward();
}

void SoundLoopPanelImpl::OnMoveReleaseEndPointForward10(wxCommandEvent& event)
{
   m_releaseloop_end->SetValue(m_releaseloop_end->GetValue() + MOVE_POINTS_BIG_STEPS_TICKS);
   moveReleaseEndPointForward();
}

void SoundLoopPanelImpl::moveReleaseEndPointForward(void)
{
   uint32_t t = m_releaseloop_end->GetValue();
   uint16_t *p;
   uint32_t cnt = 0;
   p = m_proph->getSampleData(m_sound_u8);
   t += 2;

   if(m_proph->m_sound_param_as[m_sound_u8].val_s.sample_status & 0x04)
   {
      while( (((p[t - 1] < p[t]) && (p[t + 1] > p[t]) || ((p[t - 1] > p[t]) && (p[t + 1] < p[t])) || (cnt < 20))) && (t < (m_proph->getSampleWords(m_sound_u8) - 1)))
      {
         cnt++;
         t++;
      }
      t++;
   }
   else
   {
      if(m_panel->getIntelligentLoopPoints())
      {
         int32_t t2;
         int32_t t3;
         
         bool fertig = false;
         t2 = ((int32_t)p[m_releaseloop_start->GetValue()] - (4096 / 2)) + ((int32_t)p[m_releaseloop_start->GetValue() + 3] - (4096 / 2));

         do
         {
            while( ((p[t - 1] < (4096 / 2)) && (p[t] < (4096 / 2)) || ((p[t - 1] > (4096 / 2)) && (p[t] > (4096 / 2)))) && (t < (m_proph->getSampleWords(m_sound_u8) - 1)))
            {
               t++;
            }

            t3 = ((int32_t)p[t] - (4096 / 2)) + ((int32_t)p[t + 3] - (4096 / 2));
            if(t2 > 0)
            {
               if(t3 > 0)
               {
                  fertig = true;
               }
               else
               {
                  t++;
               }
            }
            else
            {
               if(t3 <= 0)
               {
                  fertig = true;
               }
               else
               {
                  t++;
               }
            }
            if(t >= (m_proph->getSampleWords(m_sound_u8) - 1))
            {
               fertig = true;
            }
         }
         while(!fertig);

      }
      else
      {
         while( ((p[t - 1] < (4096 / 2)) && (p[t] < (4096 / 2)) || ((p[t - 1] > (4096 / 2)) && (p[t] > (4096 / 2)))) && (t < (m_proph->getSampleWords(m_sound_u8) - 1)))
         {
            t++;
         }
      }
   }

   t--;

   m_releaseloop_end->SetValue(t);

   if(m_releaseloop_end->GetValue() <= m_releaseloop_start->GetValue())
   {
      m_releaseloop_end->SetValue(m_releaseloop_start->GetValue() + 1);
   }
   
   updateLoopParameters();
   
   m_old_releaseloop_end = m_releaseloop_end->GetValue();
}

void SoundLoopPanelImpl::OnMoveReleaseEndPointBackward1(wxCommandEvent& event)
{
   moveReleaseEndPointBackward();
}

void SoundLoopPanelImpl::OnMoveReleaseEndPointBackward10(wxCommandEvent& event)
{
   int32_t t = m_releaseloop_end->GetValue();
   t -= MOVE_POINTS_BIG_STEPS_TICKS;
   if(t < 0)
   {
      t = 0;
   }
   m_releaseloop_end->SetValue(t);
   moveReleaseEndPointBackward();
}

void SoundLoopPanelImpl::moveReleaseEndPointBackward(void)
{
   int32_t t = m_releaseloop_end->GetValue();
   uint16_t *p;
   uint32_t cnt = 0;
   p = m_proph->getSampleData(m_sound_u8);

   t--;
   if(t < 0)
   {
      t = 0;
   }

   if(m_proph->m_sound_param_as[m_sound_u8].val_s.sample_status & 0x04)
   {
      while( (((p[t - 1] < p[t]) && (p[t + 1] > p[t]) || ((p[t - 1] > p[t]) && (p[t + 1] < p[t])) || (cnt < 20))) && (t > (m_releaseloop_start->GetValue() + 1)))
      {
         t--;
         cnt++;
      }
      t++;
   }
   else
   {
      if(m_panel->getIntelligentLoopPoints())
      {
         int32_t t2;
         int32_t t3;
         
         bool fertig = false;
         t2 = ((int32_t)p[m_releaseloop_start->GetValue()] - (4096 / 2)) + ((int32_t)p[m_releaseloop_start->GetValue() + 3] - (4096 / 2));

         do
         {
            while( ((p[t - 1] < (4096 / 2)) && (p[t] < (4096 / 2)) || ((p[t - 1] > (4096 / 2)) && (p[t] > (4096 / 2)))) && (t > (m_releaseloop_start->GetValue() + 1)))
            {
               t--;
            }

            t3 = ((int32_t)p[t] - (4096 / 2)) + ((int32_t)p[t + 3] - (4096 / 2));
            if(t2 > 0)
            {
               if(t3 > 0)
               {
                  fertig = true;
               }
               else
               {
                  t--;
               }
            }
            else
            {
               if(t3 <= 0)
               {
                  fertig = true;
               }
               else
               {
                  t--;
               }
            }
            if(t <= (m_releaseloop_start->GetValue() + 1))
            {
               fertig = true;
            }
         }
         while(!fertig);

      }
      else
      {
         while( ((p[t - 1] < (4096 / 2)) && (p[t] < (4096 / 2)) || ((p[t - 1] > (4096 / 2)) && (p[t] > (4096 / 2)))) && (t > (m_releaseloop_start->GetValue() + 1)))
         {
            t--;
         }
      }
   }
   t--;

   m_releaseloop_end->SetValue(t);
   
   if(m_releaseloop_end->GetValue() <= m_releaseloop_start->GetValue())
   {
      m_releaseloop_end->SetValue(m_releaseloop_start->GetValue() + 1);
   }
   
   updateLoopParameters();
   
   m_old_releaseloop_end = m_releaseloop_end->GetValue();
}


void SoundLoopPanelImpl::moveEndPointBackward(void)
{
   wxString str;

   int32_t t = m_end_point->GetValue();
   uint16_t *p;
   p = m_proph->getSampleData(m_sound_u8);

   t--;
   if(t < 5)
   {
      t = 5;
   }

   while( ((p[t - 1] < (4096 / 2)) && (p[t] < (4096 / 2)) || ((p[t - 1] > (4096 / 2)) && (p[t] > (4096 / 2)))) && (t > (m_start_point->GetValue() + 4)))
   {
      t--;
   }

   m_end_point->SetValue(t);

   if(m_end_point->GetValue() <= m_start_point->GetValue())
   {
      m_end_point->SetValue(m_start_point->GetValue() + 1);
   }

   //m_start_point->SetMax(m_end_point->GetValue() - 1);

   str.sprintf(wxT("%d"), m_end_point->GetValue() - m_start_point->GetValue());
   m_sample_words_txt->SetValue(str);

   updateLoopParameters();
      
   m_old_end_point = m_end_point->GetValue();
}

void SoundLoopPanelImpl::moveStartPointForward(void)
{
   wxString str;

   uint32_t t = m_start_point->GetValue();
   uint16_t *p;
   p = m_proph->getSampleData(m_sound_u8);
   t++;

   while( ((p[t - 1] < (4096 / 2)) && (p[t] < (4096 / 2)) || ((p[t - 1] > (4096 / 2)) && (p[t] > (4096 / 2)))) && ((int32_t)t < (m_end_point->GetValue() - 1)))
   {
      t++;
   }

   m_start_point->SetValue(t);

   if(m_start_point->GetValue() >= m_end_point->GetValue())
   {
      m_start_point->SetValue(m_end_point->GetValue() - 1);
   }

   //m_end_point->SetMin(m_start_point->GetValue() + 1);

   str.sprintf(wxT("%d"), m_end_point->GetValue() - m_start_point->GetValue());
   m_sample_words_txt->SetValue(str);

   updateLoopParameters();

   m_old_start_point = m_start_point->GetValue();
} 

void SoundLoopPanelImpl::moveEndPointForward(void)
{
   wxString str;

   uint32_t t = m_end_point->GetValue();
   uint16_t *p;
   p = m_proph->getSampleData(m_sound_u8);
   t++;

   while( ((p[t - 1] < (4096 / 2)) && (p[t] < (4096 / 2)) || ((p[t - 1] > (4096 / 2)) && (p[t] > (4096 / 2)))) && (t < (m_proph->getSampleWords(m_sound_u8) - 1)))
   {
      t++;
   }

   m_end_point->SetValue(t);

   if(m_end_point->GetValue() <= m_start_point->GetValue())
   {
      m_end_point->SetValue(m_start_point->GetValue() + 1);
   }

   //m_start_point->SetMax(m_end_point->GetValue() - 1);

   str.sprintf(wxT("%d"), m_end_point->GetValue() - m_start_point->GetValue());
   m_sample_words_txt->SetValue(str);

   updateLoopParameters();
      
   m_old_end_point = m_end_point->GetValue();
} 


void SoundLoopPanelImpl::moveStartPointBackward(void)
{
   wxString str;

   int32_t t = m_start_point->GetValue();
   uint16_t *p;
   p = m_proph->getSampleData(m_sound_u8);
   t--;

   if(t < 0)
   {
      t = 0;
   }

   while( ((p[t - 1] < (4096 / 2)) && (p[t] < (4096 / 2)) || ((p[t - 1] > (4096 / 2)) && (p[t] > (4096 / 2)))) && (t > 1))
   {
      t--;
   }


   m_start_point->SetValue(t);

   //m_end_point->SetMin(m_start_point->GetValue() + 1);

   str.sprintf(wxT("%d"), m_end_point->GetValue() - m_start_point->GetValue());
   m_sample_words_txt->SetValue(str);

   updateLoopParameters();

   m_old_start_point = m_start_point->GetValue();
} 


void SoundLoopPanelImpl::OnSustainLoopEnd(wxSpinEvent &event)
{
   if(m_update_loop_params_active)
   {
      m_sustainloop_end->SetRange(m_sustainloop_start->GetValue() + 1, m_sustainloop_end->GetMax());
   }

   if(m_old_sustainloop_end != m_sustainloop_end->GetValue())
   {
      if(m_sustainloop_end->GetValue() <= m_sustainloop_start->GetValue())
      {
         m_sustainloop_end->SetValue(m_sustainloop_start->GetValue() + 1);
      }
      
      updateLoopParameters();
      
      m_old_sustainloop_end = m_sustainloop_end->GetValue();
   }
}


void SoundLoopPanelImpl::OnReleaseLoopStart(wxSpinEvent &event)
{
   wxString str;
   if(m_update_loop_params_active)
   {
      m_releaseloop_end->SetRange(m_releaseloop_start->GetValue() + 1, m_releaseloop_end->GetMax());
   }
   if(m_old_releaseloop_start != m_releaseloop_start->GetValue())
   {

      if(m_releaseloop_start->GetValue() >= m_releaseloop_end->GetValue())
      {
         m_releaseloop_start->SetValue(m_releaseloop_end->GetValue() - 1);
      }

      updateLoopParameters();

      m_old_releaseloop_start = m_releaseloop_start->GetValue();
   }
}


void SoundLoopPanelImpl::OnReleaseLoopEnd(wxSpinEvent &event)
{
   if(m_update_loop_params_active)
   {
      m_releaseloop_end->SetRange(m_releaseloop_start->GetValue() + 1, m_releaseloop_end->GetMax());
      m_sustainloop_end->SetRange(m_sustainloop_end->GetMin(), m_releaseloop_end->GetValue() - 1);
   }
   //if(m_old_releaseloop_end != m_releaseloop_end->GetValue())
   {

      if(m_releaseloop_end->GetValue() <= m_releaseloop_start->GetValue())
      {
         m_releaseloop_end->SetValue(m_releaseloop_start->GetValue() + 1);
      }
      
      updateLoopParameters();
      
      m_old_releaseloop_end = m_releaseloop_end->GetValue();
   }
}


void SoundLoopPanelImpl::transferStarted(void)
{
}

void SoundLoopPanelImpl::transferEnded(void)
{
}

void SoundLoopPanelImpl::OnCopy(wxCommandEvent& event)
{
   m_panel->OnCopy(event);
}


void SoundLoopPanelImpl::OnCopyParamToAll(wxCommandEvent& event)
{
   m_panel->OnCopyParamToAll(event);
}

void SoundLoopPanelImpl::OnGetSound(wxCommandEvent& event)
{
   m_panel->OnGetSound(event);
}

void SoundLoopPanelImpl::OnGetSoundParam(wxCommandEvent& event)
{
   m_panel->OnGetSoundParam(event);
}

void SoundLoopPanelImpl::OnDeleteSound(wxCommandEvent& event)
{
   m_panel->OnDeleteSound(event);
}

