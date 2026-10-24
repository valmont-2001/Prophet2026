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
#include "soundsamplepanel.h"


SoundSamplePanelImpl::SoundSamplePanelImpl(wxWindow *parent, MyPanel *topframe, Proph2000 *proph, uint8_t sound_u8, MySoundParam *panel) :
   SoundSamplePanel(parent),
   m_topframe(topframe), m_proph(proph), m_sound_u8(sound_u8), m_panel(panel), m_update_gui_active(false)
{
#ifdef __WXMAC__ // 130205
    m_tune_table->ToggleWindowStyle(wxBORDER_SUNKEN);
    m_velocity_start_point->ToggleWindowStyle(wxBORDER_SUNKEN);
#endif
    
   if(m_sound_u8 < 8)
   {
      relative_mix_map1_txt->SetLabel(wxT("Map 1"));
      relative_mix_map2_txt->SetLabel(wxT("Map 2"));
      relative_mix_map3_txt->SetLabel(wxT("Map 3"));
      relative_mix_map4_txt->SetLabel(wxT("Map 4"));
      relative_mix_map5_txt->SetLabel(wxT("Map 5"));
      relative_mix_map6_txt->SetLabel(wxT("Map 6"));
      relative_mix_map7_txt->SetLabel(wxT("Map 7"));
      relative_mix_map8_txt->SetLabel(wxT("Map 8"));
   }
   else
   {
      relative_mix_map1_txt->SetLabel(wxT("Map 9"));
      relative_mix_map2_txt->SetLabel(wxT("Map A"));
      relative_mix_map3_txt->SetLabel(wxT("Map B"));
      relative_mix_map4_txt->SetLabel(wxT("Map C"));
      relative_mix_map5_txt->SetLabel(wxT("Map D"));
      relative_mix_map6_txt->SetLabel(wxT("Map E"));
      relative_mix_map7_txt->SetLabel(wxT("Map F"));
      relative_mix_map8_txt->SetLabel(wxT("Map G"));
   }

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

   updateGUI();
}


SoundSamplePanelImpl::~SoundSamplePanelImpl()
{
}

void SoundSamplePanelImpl::OnUsedInMap1(wxCommandEvent& event)
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

void SoundSamplePanelImpl::OnUsedInMap2(wxCommandEvent& event)
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

void SoundSamplePanelImpl::OnUsedInMap3(wxCommandEvent& event)
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

void SoundSamplePanelImpl::OnUsedInMap4(wxCommandEvent& event)
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

void SoundSamplePanelImpl::OnUsedInMap5(wxCommandEvent& event)
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

void SoundSamplePanelImpl::OnUsedInMap6(wxCommandEvent& event)
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

void SoundSamplePanelImpl::OnUsedInMap7(wxCommandEvent& event)
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

void SoundSamplePanelImpl::OnUsedInMap8(wxCommandEvent& event)
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

void SoundSamplePanelImpl::activateSound(uint8_t sound_u8)
{
   m_sound_u8 = sound_u8;
   if(m_sound_u8 < 8)
   {
      relative_mix_map1_txt->SetLabel(wxT("Map 1"));
      relative_mix_map2_txt->SetLabel(wxT("Map 2"));
      relative_mix_map3_txt->SetLabel(wxT("Map 3"));
      relative_mix_map4_txt->SetLabel(wxT("Map 4"));
      relative_mix_map5_txt->SetLabel(wxT("Map 5"));
      relative_mix_map6_txt->SetLabel(wxT("Map 6"));
      relative_mix_map7_txt->SetLabel(wxT("Map 7"));
      relative_mix_map8_txt->SetLabel(wxT("Map 8"));
   }
   else
   {
      relative_mix_map1_txt->SetLabel(wxT("Map 9"));
      relative_mix_map2_txt->SetLabel(wxT("Map A"));
      relative_mix_map3_txt->SetLabel(wxT("Map B"));
      relative_mix_map4_txt->SetLabel(wxT("Map C"));
      relative_mix_map5_txt->SetLabel(wxT("Map D"));
      relative_mix_map6_txt->SetLabel(wxT("Map E"));
      relative_mix_map7_txt->SetLabel(wxT("Map F"));
      relative_mix_map8_txt->SetLabel(wxT("Map G"));
   }

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
   updateGUI();
}

void SoundSamplePanelImpl::OnRootKey(wxCommandEvent& event)
{
   uint8_t note;
   if(convertStringToNote(m_root_key->GetValue(), &note))
   {
      m_proph->m_sound_param_as[m_sound_u8].val_s.root_key = note;
      if(m_proph->getStereoMode())
      {
         if(m_sound_u8 < 8)
         {
            m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.root_key = note;
         }
         else
         {
            m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.root_key = note;
         }
      }

      m_proph->updateParamBytesFromStruct();
      m_topframe->updateGUI();
      if(m_topframe->getOnlineUpdateActive())
      {
         if(m_proph->transferSoundParam2Proph(m_sound_u8))
         {
            m_topframe->transferStarted();
         }
      }
   }
}

void SoundSamplePanelImpl::OnHighKey1(wxCommandEvent& event)
{
   OnHighKey(0);
}

void SoundSamplePanelImpl::OnHighKey2(wxCommandEvent& event)
{
   OnHighKey(1);
}

void SoundSamplePanelImpl::OnHighKey3(wxCommandEvent& event)
{
   OnHighKey(2);
}

void SoundSamplePanelImpl::OnHighKey4(wxCommandEvent& event)
{
   OnHighKey(3);
}

void SoundSamplePanelImpl::OnHighKey5(wxCommandEvent& event)
{
   OnHighKey(4);
}

void SoundSamplePanelImpl::OnHighKey6(wxCommandEvent& event)
{
   OnHighKey(5);
}

void SoundSamplePanelImpl::OnHighKey7(wxCommandEvent& event)
{
   OnHighKey(6);
}

void SoundSamplePanelImpl::OnHighKey8(wxCommandEvent& event)
{
   OnHighKey(7);
}

void SoundSamplePanelImpl::OnHighKey(uint8_t map_id)
{
   uint8_t note;
   wxString notestr;
   if(!m_update_gui_active) // workaround: on startup gui will crash
   {
      switch(map_id)
      {
         case 0:
            notestr = m_hi_key_map1->GetValue();
            break;
         case 1:
            notestr = m_hi_key_map2->GetValue();
            break;
         case 2:
            notestr = m_hi_key_map3->GetValue();
            break;
         case 3:
            notestr = m_hi_key_map4->GetValue();
            break;
         case 4:
            notestr = m_hi_key_map5->GetValue();
            break;
         case 5:
            notestr = m_hi_key_map6->GetValue();
            break;
         case 6:
            notestr = m_hi_key_map7->GetValue();
            break;
         case 7:
            notestr = m_hi_key_map8->GetValue();
            break;
         default:
            break;
      }

      if(convertStringToNote(notestr, &note))
      {
         switch(map_id)
         {
            case 0:
               m_proph->m_sound_param_as[m_sound_u8].val_s.hi_key_map1 = note;
               if(m_proph->getStereoMode())
               {
                  if(m_sound_u8 < 8)
                  {
                     m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.hi_key_map1 = note;
                  }
                  else
                  {
                     m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.hi_key_map1 = note;
                  }
               }
               break;
            case 1:
               m_proph->m_sound_param_as[m_sound_u8].val_s.hi_key_map2 = note;
               if(m_proph->getStereoMode())
               {
                  if(m_sound_u8 < 8)
                  {
                     m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.hi_key_map2 = note;
                  }
                  else
                  {
                     m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.hi_key_map2 = note;
                  }
               }
               break;
            case 2:
               m_proph->m_sound_param_as[m_sound_u8].val_s.hi_key_map3 = note;
               if(m_proph->getStereoMode())
               {
                  if(m_sound_u8 < 8)
                  {
                     m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.hi_key_map3 = note;
                  }
                  else
                  {
                     m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.hi_key_map3 = note;
                  }
               }
               break;
            case 3:
               m_proph->m_sound_param_as[m_sound_u8].val_s.hi_key_map4 = note;
               if(m_proph->getStereoMode())
               {
                  if(m_sound_u8 < 8)
                  {
                     m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.hi_key_map4 = note;
                  }
                  else
                  {
                     m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.hi_key_map4 = note;
                  }
               }
               break;
            case 4:
               m_proph->m_sound_param_as[m_sound_u8].val_s.hi_key_map5 = note;
               if(m_proph->getStereoMode())
               {
                  if(m_sound_u8 < 8)
                  {
                     m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.hi_key_map5 = note;
                  }
                  else
                  {
                     m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.hi_key_map5 = note;
                  }
               }
               break;
            case 5:
               m_proph->m_sound_param_as[m_sound_u8].val_s.hi_key_map6 = note;
               if(m_proph->getStereoMode())
               {
                  if(m_sound_u8 < 8)
                  {
                     m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.hi_key_map6 = note;
                  }
                  else
                  {
                     m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.hi_key_map6 = note;
                  }
               }
               break;
            case 6:
               m_proph->m_sound_param_as[m_sound_u8].val_s.hi_key_map7 = note;
               if(m_proph->getStereoMode())
               {
                  if(m_sound_u8 < 8)
                  {
                     m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.hi_key_map7 = note;
                  }
                  else
                  {
                     m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.hi_key_map7 = note;
                  }
               }
               break;
            case 7:
               m_proph->m_sound_param_as[m_sound_u8].val_s.hi_key_map8 = note;
               if(m_proph->getStereoMode())
               {
                  if(m_sound_u8 < 8)
                  {
                     m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.hi_key_map8 = note;
                  }
                  else
                  {
                     m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.hi_key_map8 = note;
                  }
               }
               break;
            default:
               break;
         }
         m_proph->updateParamBytesFromStruct();

         m_topframe->updateGUI(); 
         if(m_topframe->getOnlineUpdateActive())
         {
            if(m_proph->transferSoundParam2Proph(m_sound_u8))
            {
               m_topframe->transferStarted();
            }
         }
      }
   }
}

bool SoundSamplePanelImpl::convertStringToNote(wxString str, uint8_t *note_pu8)
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


void SoundSamplePanelImpl::updateUsedInMapStatus(void)
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


void SoundSamplePanelImpl::updateGUI(void)
{
   wxString str;
   uint32_t t;
   m_update_gui_active = true;

   updateUsedInMapStatus();

   if(m_proph->m_sound_param_as[m_sound_u8].val_s.sample_status & 0x10)
   {
      m_sample_deleted->SetValue(false);
   }
   else
   {
      m_sample_deleted->SetValue(true);
   }
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.sample_status & 0x20)
   {
      m_sampled->SetValue(true);
   }
   else
   {
      m_sampled->SetValue(false);
   }


   if(m_sample_deleted->GetValue())
   {
      m_sampled->SetValue(false);
   }
   else
   {
      m_sampled->SetValue(true);
   }
   if(m_sampled->GetValue())
   {
      m_sample_deleted->SetValue(false);
   }
   else
   {
      m_sample_deleted->SetValue(true);
   }


   t = m_proph->m_sound_param_as[m_sound_u8].val_s.begin_addr[2];
   t |= ((uint32_t)m_proph->m_sound_param_as[m_sound_u8].val_s.begin_addr[1] << 8);
   t |= ((uint32_t)m_proph->m_sound_param_as[m_sound_u8].val_s.begin_addr[0] << 16);
   str.sprintf(wxT("0x%.6x"), t);
   m_begin_addr->SetValue(str);

   t = m_proph->m_sound_param_as[m_sound_u8].val_s.start_point[2];
   t |= ((uint32_t)m_proph->m_sound_param_as[m_sound_u8].val_s.start_point[1] << 8);
   t |= ((uint32_t)m_proph->m_sound_param_as[m_sound_u8].val_s.start_point[0] << 16);
   str.sprintf(wxT("0x%.6x"), t);
   m_start_point_addr->SetValue(str);

   t = m_proph->m_sound_param_as[m_sound_u8].val_s.sustain_loop_start[2];
   t |= ((uint32_t)m_proph->m_sound_param_as[m_sound_u8].val_s.sustain_loop_start[1] << 8);
   t |= ((uint32_t)m_proph->m_sound_param_as[m_sound_u8].val_s.sustain_loop_start[0] << 16);
   str.sprintf(wxT("0x%.6x"), t);
   m_sustain_loop_start_addr->SetValue(str);
   
   t = m_proph->m_sound_param_as[m_sound_u8].val_s.sustain_loop_end[2];
   t |= ((uint32_t)m_proph->m_sound_param_as[m_sound_u8].val_s.sustain_loop_end[1] << 8);
   t |= ((uint32_t)m_proph->m_sound_param_as[m_sound_u8].val_s.sustain_loop_end[0] << 16);
   str.sprintf(wxT("0x%.6x"), t);
   m_sustain_loop_end_addr->SetValue(str);
   
   t = m_proph->m_sound_param_as[m_sound_u8].val_s.release_loop_start[2];
   t |= ((uint32_t)m_proph->m_sound_param_as[m_sound_u8].val_s.release_loop_start[1] << 8);
   t |= ((uint32_t)m_proph->m_sound_param_as[m_sound_u8].val_s.release_loop_start[0] << 16);
   str.sprintf(wxT("0x%.6x"), t);
   m_release_loop_start_addr->SetValue(str);

   t = m_proph->m_sound_param_as[m_sound_u8].val_s.release_loop_end[2];
   t |= ((uint32_t)m_proph->m_sound_param_as[m_sound_u8].val_s.release_loop_end[1] << 8);
   t |= ((uint32_t)m_proph->m_sound_param_as[m_sound_u8].val_s.release_loop_end[0] << 16);
   str.sprintf(wxT("0x%.6x"), t);
   m_release_loop_end_addr->SetValue(str);

   t = m_proph->m_sound_param_as[m_sound_u8].val_s.end_point[2];
   t |= ((uint32_t)m_proph->m_sound_param_as[m_sound_u8].val_s.end_point[1] << 8);
   t |= ((uint32_t)m_proph->m_sound_param_as[m_sound_u8].val_s.end_point[0] << 16);
   str.sprintf(wxT("0x%.6x"), t);
   m_end_point_addr->SetValue(str);

   t = m_proph->m_sound_param_as[m_sound_u8].val_s.finish_addr[2];
   t |= ((uint32_t)m_proph->m_sound_param_as[m_sound_u8].val_s.finish_addr[1] << 8);
   t |= ((uint32_t)m_proph->m_sound_param_as[m_sound_u8].val_s.finish_addr[0] << 16);
   str.sprintf(wxT("0x%.6x"), t);
   m_finish_addr->SetValue(str);

   m_velocity_start_point->SetValue((int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.velocity_start_point - 0x80);

   m_root_key->SetValue(getNote(m_proph->m_sound_param_as[m_sound_u8].val_s.root_key));
   m_tune_table->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.tune_table);

   if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map1 != SOUND_NOT_MAPPED_VALUE)
   {
      str.sprintf(wxT("%d"), (int8_t)m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map1);
   }
   else
   {
      str = wxT("Off");
   }
   m_transpose_map1->SetValue(str);
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map2 != SOUND_NOT_MAPPED_VALUE)
   {
      str.sprintf(wxT("%d"), (int8_t)m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map2);
   }
   else
   {
      str = wxT("Off");
   }
   m_transpose_map2->SetValue(str);
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map3 != SOUND_NOT_MAPPED_VALUE)
   {
      str.sprintf(wxT("%d"), (int8_t)m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map3);
   }
   else
   {
      str = wxT("Off");
   }
   m_transpose_map3->SetValue(str);
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map4 != SOUND_NOT_MAPPED_VALUE)
   {
      str.sprintf(wxT("%d"), (int8_t)m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map4);
   }
   else
   {
      str = wxT("Off");
   }
   m_transpose_map4->SetValue(str);
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map5 != SOUND_NOT_MAPPED_VALUE)
   {
      str.sprintf(wxT("%d"), (int8_t)m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map5);
   }
   else
   {
      str = wxT("Off");
   }
   m_transpose_map5->SetValue(str);
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map6 != SOUND_NOT_MAPPED_VALUE)
   {
      str.sprintf(wxT("%d"), (int8_t)m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map6);
   }
   else
   {
      str = wxT("Off");
   }
   m_transpose_map6->SetValue(str);
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map7 != SOUND_NOT_MAPPED_VALUE)
   {
      str.sprintf(wxT("%d"), (int8_t)m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map7);
   }
   else
   {
      str = wxT("Off");
   }
   m_transpose_map7->SetValue(str);
   if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map8 != SOUND_NOT_MAPPED_VALUE)
   {
      str.sprintf(wxT("%d"), (int8_t)m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map8);
   }
   else
   {
      str = wxT("Off");
   }
   m_transpose_map8->SetValue(str);

   m_hi_key_map1->SetValue(getNote(m_proph->m_sound_param_as[m_sound_u8].val_s.hi_key_map1));
   m_hi_key_map2->SetValue(getNote(m_proph->m_sound_param_as[m_sound_u8].val_s.hi_key_map2));
   m_hi_key_map3->SetValue(getNote(m_proph->m_sound_param_as[m_sound_u8].val_s.hi_key_map3));
   m_hi_key_map4->SetValue(getNote(m_proph->m_sound_param_as[m_sound_u8].val_s.hi_key_map4));
   m_hi_key_map5->SetValue(getNote(m_proph->m_sound_param_as[m_sound_u8].val_s.hi_key_map5));
   m_hi_key_map6->SetValue(getNote(m_proph->m_sound_param_as[m_sound_u8].val_s.hi_key_map6));
   m_hi_key_map7->SetValue(getNote(m_proph->m_sound_param_as[m_sound_u8].val_s.hi_key_map7));
   m_hi_key_map8->SetValue(getNote(m_proph->m_sound_param_as[m_sound_u8].val_s.hi_key_map8));
   
   m_relative_mix_map1->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map1);
   m_relative_mix_map2->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map2);
   m_relative_mix_map3->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map3);
   m_relative_mix_map4->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map4);
   m_relative_mix_map5->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map5);
   m_relative_mix_map6->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map6);
   m_relative_mix_map7->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map7);
   m_relative_mix_map8->SetValue(m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map8);

   //str.sprintf("%d", m_proph->m_sound_param_as[m_sound_u8].val_s.sample_rate);
   //m_sample_rate->SetValue(str);
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
         m_sample_rate->SetValue(wxT("Invalid"));
         break;
   }
   m_update_gui_active = false;
}

void SoundSamplePanelImpl::OnCheckboxChange(wxCommandEvent& event)
{
   if(m_sample_deleted->GetValue())
   {
      m_sampled->SetValue(false);
   }
   else
   {
      m_sampled->SetValue(true);
   }
   if(m_sampled->GetValue())
   {
      m_sample_deleted->SetValue(false);
   }
   else
   {
      m_sample_deleted->SetValue(true);
   }

   if(m_sample_deleted->GetValue() == false)
   {
      m_proph->m_sound_param_as[m_sound_u8].val_s.sample_status |= 0x10;
      if(m_proph->getStereoMode())
      {
         if(m_sound_u8 < 8)
         {
            m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.sample_status |= 0x10;
         }
         else
         {
            m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.sample_status |= 0x10;
         }
      }
   }
   else
   {
      m_proph->m_sound_param_as[m_sound_u8].val_s.sample_status &= ~0x10;
      if(m_proph->getStereoMode())
      {
         if(m_sound_u8 < 8)
         {
            m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.sample_status &= ~0x10;
         }
         else
         {
            m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.sample_status &= ~0x10;
         }
      }
   }
   if(m_sampled->GetValue())
   {
      m_proph->m_sound_param_as[m_sound_u8].val_s.sample_status |= 0x20;
      if(m_proph->getStereoMode())
      {
         if(m_sound_u8 < 8)
         {
            m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.sample_status |= 0x20;
         }
         else
         {
            m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.sample_status |= 0x20;
         }
      }
   }
   else
   {
      m_proph->m_sound_param_as[m_sound_u8].val_s.sample_status &= ~0x20;
      if(m_proph->getStereoMode())
      {
         if(m_sound_u8 < 8)
         {
            m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.sample_status &= ~0x20;
         }
         else
         {
            m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.sample_status &= ~0x20;
         }
      }
   }
   m_proph->updateParamBytesFromStruct();
   m_topframe->updateGUI();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferSoundParam2Proph(m_sound_u8))
      {
         m_topframe->transferStarted();
      }
   }
}


void SoundSamplePanelImpl::OnSpinChange(wxSpinEvent &event)
{
   m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map1 = m_relative_mix_map1->GetValue();
   m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map2 = m_relative_mix_map2->GetValue();
   m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map3 = m_relative_mix_map3->GetValue();
   m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map4 = m_relative_mix_map4->GetValue();
   m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map5 = m_relative_mix_map5->GetValue();
   m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map6 = m_relative_mix_map6->GetValue();
   m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map7 = m_relative_mix_map7->GetValue();
   m_proph->m_sound_param_as[m_sound_u8].val_s.relative_mix_map8 = m_relative_mix_map8->GetValue();

   if(m_proph->getStereoMode())
   {
      if(m_sound_u8 < 8)
      {
         m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.relative_mix_map1 = m_relative_mix_map1->GetValue();
         m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.relative_mix_map2 = m_relative_mix_map2->GetValue();
         m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.relative_mix_map3 = m_relative_mix_map3->GetValue();
         m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.relative_mix_map4 = m_relative_mix_map4->GetValue();
         m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.relative_mix_map5 = m_relative_mix_map5->GetValue();
         m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.relative_mix_map6 = m_relative_mix_map6->GetValue();
         m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.relative_mix_map7 = m_relative_mix_map7->GetValue();
         m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.relative_mix_map8 = m_relative_mix_map8->GetValue();
      }
      else
      {
         m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.relative_mix_map1 = m_relative_mix_map1->GetValue();
         m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.relative_mix_map2 = m_relative_mix_map2->GetValue();
         m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.relative_mix_map3 = m_relative_mix_map3->GetValue();
         m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.relative_mix_map4 = m_relative_mix_map4->GetValue();
         m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.relative_mix_map5 = m_relative_mix_map5->GetValue();
         m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.relative_mix_map6 = m_relative_mix_map6->GetValue();
         m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.relative_mix_map7 = m_relative_mix_map7->GetValue();
         m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.relative_mix_map8 = m_relative_mix_map8->GetValue();
      }
   }

   m_proph->updateParamBytesFromStruct();
   m_topframe->updateGUI();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferSoundParam2Proph(m_sound_u8))
      {
         m_topframe->transferStarted();
      }
   }
}


void SoundSamplePanelImpl::OnSliderChange(wxScrollEvent &event)
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
   m_topframe->updateGUI();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferSoundParam2Proph(m_sound_u8))
      {
         m_topframe->transferStarted();
      }
   }
}


wxString SoundSamplePanelImpl::getNote(uint8_t number_u8)
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


void SoundSamplePanelImpl::OnLoad(wxCommandEvent& event)
{
   m_panel->OnLoad(event);
}


void SoundSamplePanelImpl::OnSave(wxCommandEvent& event)
{
   m_panel->OnSave(event);
}


void SoundSamplePanelImpl::OnPlay(wxCommandEvent& event)
{
   m_panel->OnPlay(event);
}

void SoundSamplePanelImpl::OnCopy(wxCommandEvent& event)
{
   m_panel->OnCopy(event);
}


void SoundSamplePanelImpl::OnCopyParamToAll(wxCommandEvent& event)
{
   m_panel->OnCopyParamToAll(event);
}


void SoundSamplePanelImpl::OnGetSound(wxCommandEvent& event)
{
   m_panel->OnGetSound(event);
}

void SoundSamplePanelImpl::OnGetSoundParam(wxCommandEvent& event)
{
   m_panel->OnGetSoundParam(event);
}

void SoundSamplePanelImpl::OnDeleteSound(wxCommandEvent& event)
{
   m_panel->OnDeleteSound(event);
}



void SoundSamplePanelImpl::OnImport(wxCommandEvent& event)
{
   m_panel->OnImport(event);
}


void SoundSamplePanelImpl::OnExport(wxCommandEvent& event)
{
   m_panel->OnExport(event);
}


void SoundSamplePanelImpl::OnPurge(wxCommandEvent& event)
{
   m_panel->OnPurge(event);
}

