#include "types.h"
#include <wx/wx.h>

//#include <unistd.h>

#include "GUILayout.h"
#include "soundselection.h"
#include "stopwatch.h"
#include "proph2000.h"
#include "soundparam.h"


SoundSelectionPanelImpl::SoundSelectionPanelImpl(wxWindow *parent, MySoundParam *panel, Proph2000 *proph) :
   SoundSelectionPanel(parent),
   m_panel(panel), m_proph(proph)
{
   deselectAllSoundButtons();
   m_select_sound1->SetValue(true);
}

SoundSelectionPanelImpl::~SoundSelectionPanelImpl()
{
}


void SoundSelectionPanelImpl::updateGUI(void)
{
   m_select_sound1->SetToolTip(m_proph->getSampleName(0));
   m_select_sound2->SetToolTip(m_proph->getSampleName(1));
   m_select_sound3->SetToolTip(m_proph->getSampleName(2));
   m_select_sound4->SetToolTip(m_proph->getSampleName(3));
   m_select_sound5->SetToolTip(m_proph->getSampleName(4));
   m_select_sound6->SetToolTip(m_proph->getSampleName(5));
   m_select_sound7->SetToolTip(m_proph->getSampleName(6));
   m_select_sound8->SetToolTip(m_proph->getSampleName(7));
   m_select_sound9->SetToolTip(m_proph->getSampleName(8));
   m_select_sound10->SetToolTip(m_proph->getSampleName(9));
   m_select_sound11->SetToolTip(m_proph->getSampleName(10));
   m_select_sound12->SetToolTip(m_proph->getSampleName(11));
   m_select_sound13->SetToolTip(m_proph->getSampleName(12));
   m_select_sound14->SetToolTip(m_proph->getSampleName(13));
   m_select_sound15->SetToolTip(m_proph->getSampleName(14));
   m_select_sound16->SetToolTip(m_proph->getSampleName(15));
}



void SoundSelectionPanelImpl::makeActive(uint8_t sound_u8)
{
   deselectAllSoundButtons();

   switch(sound_u8)
   {
      case 0:
         m_select_sound1->SetValue(true);
         break;
      case 1:
         m_select_sound2->SetValue(true);
         break;
      case 2:
         m_select_sound3->SetValue(true);
         break;
      case 3:
         m_select_sound4->SetValue(true);
         break;
      case 4:
         m_select_sound5->SetValue(true);
         break;
      case 5:
         m_select_sound6->SetValue(true);
         break;
      case 6:
         m_select_sound7->SetValue(true);
         break;
      case 7:
         m_select_sound8->SetValue(true);
         break;
      case 8:
         m_select_sound9->SetValue(true);
         break;
      case 9:
         m_select_sound10->SetValue(true);
         break;
      case 10:
         m_select_sound11->SetValue(true);
         break;
      case 11:
         m_select_sound12->SetValue(true);
         break;
      case 12:
         m_select_sound13->SetValue(true);
         break;
      case 13:
         m_select_sound14->SetValue(true);
         break;
      case 14:
         m_select_sound15->SetValue(true);
         break;
      case 15:
         m_select_sound16->SetValue(true);
         break;
      default:
         break;
   }
}


void SoundSelectionPanelImpl::setEmptySlot(uint8_t sound, bool flag)
{
    return;
   wxFont font;
   switch(sound)
   {
      case 0:
         if(!flag)
         {
            font = m_select_sound1->GetFont();
            font.SetWeight(wxFONTWEIGHT_BOLD);
            m_select_sound1->SetFont(font);
         }
         else
         {
            font = m_select_sound1->GetFont();
            font.SetWeight(wxFONTWEIGHT_NORMAL);
            m_select_sound1->SetFont(font);
         }
         m_select_sound1->Refresh(true);
      break;
      case 1:
           if(!flag)
           {
              font = m_select_sound2->GetFont();
              font.SetWeight(wxFONTWEIGHT_BOLD);
              m_select_sound2->SetFont(font);
           }
           else
           {
              font = m_select_sound2->GetFont();
              font.SetWeight(wxFONTWEIGHT_NORMAL);
              m_select_sound2->SetFont(font);
           }
         m_select_sound2->Refresh(true);
      break;
      case 2:
           if(!flag)
           {
              font = m_select_sound3->GetFont();
              font.SetWeight(wxFONTWEIGHT_BOLD);
              m_select_sound3->SetFont(font);
           }
           else
           {
              font = m_select_sound3->GetFont();
              font.SetWeight(wxFONTWEIGHT_NORMAL);
              m_select_sound3->SetFont(font);
           }
         m_select_sound3->Refresh(true);
      break;
      case 3:
           if(!flag)
           {
              font = m_select_sound4->GetFont();
              font.SetWeight(wxFONTWEIGHT_BOLD);
              m_select_sound4->SetFont(font);
           }
           else
           {
              font = m_select_sound4->GetFont();
              font.SetWeight(wxFONTWEIGHT_NORMAL);
              m_select_sound4->SetFont(font);
           }

         m_select_sound4->Refresh(true);
      break;
      case 4:
           if(!flag)
           {
              font = m_select_sound5->GetFont();
              font.SetWeight(wxFONTWEIGHT_BOLD);
              m_select_sound5->SetFont(font);
           }
           else
           {
              font = m_select_sound5->GetFont();
              font.SetWeight(wxFONTWEIGHT_NORMAL);
              m_select_sound5->SetFont(font);
           }

         m_select_sound5->Refresh(true);
      break;
      case 5:
           if(!flag)
           {
              font = m_select_sound6->GetFont();
              font.SetWeight(wxFONTWEIGHT_BOLD);
              m_select_sound6->SetFont(font);
           }
           else
           {
              font = m_select_sound6->GetFont();
              font.SetWeight(wxFONTWEIGHT_NORMAL);
              m_select_sound6->SetFont(font);
           }

         m_select_sound6->Refresh(true);
      break;
      case 6:
           if(!flag)
           {
              font = m_select_sound7->GetFont();
              font.SetWeight(wxFONTWEIGHT_BOLD);
              m_select_sound7->SetFont(font);
           }
           else
           {
              font = m_select_sound7->GetFont();
              font.SetWeight(wxFONTWEIGHT_NORMAL);
              m_select_sound7->SetFont(font);
           }

         m_select_sound7->Refresh(true);
      break;
      case 7:
           if(!flag)
           {
              font = m_select_sound8->GetFont();
              font.SetWeight(wxFONTWEIGHT_BOLD);
              m_select_sound8->SetFont(font);
           }
           else
           {
              font = m_select_sound8->GetFont();
              font.SetWeight(wxFONTWEIGHT_NORMAL);
              m_select_sound8->SetFont(font);
           }

         m_select_sound8->Refresh(true);
      break;
      case 8:
           if(!flag)
           {
              font = m_select_sound9->GetFont();
              font.SetWeight(wxFONTWEIGHT_BOLD);
              m_select_sound9->SetFont(font);
           }
           else
           {
              font = m_select_sound9->GetFont();
              font.SetWeight(wxFONTWEIGHT_NORMAL);
              m_select_sound9->SetFont(font);
           }

         m_select_sound9->Refresh(true);
      break;
      case 9:
           if(!flag)
           {
              font = m_select_sound10->GetFont();
              font.SetWeight(wxFONTWEIGHT_BOLD);
              m_select_sound10->SetFont(font);
           }
           else
           {
              font = m_select_sound10->GetFont();
              font.SetWeight(wxFONTWEIGHT_NORMAL);
              m_select_sound10->SetFont(font);
           }

         m_select_sound10->Refresh(true);
      break;
      case 10:
           if(!flag)
           {
              font = m_select_sound11->GetFont();
              font.SetWeight(wxFONTWEIGHT_BOLD);
              m_select_sound11->SetFont(font);
           }
           else
           {
              font = m_select_sound11->GetFont();
              font.SetWeight(wxFONTWEIGHT_NORMAL);
              m_select_sound11->SetFont(font);
           }

         m_select_sound11->Refresh(true);
      break;
      case 11:
           if(!flag)
           {
              font = m_select_sound12->GetFont();
              font.SetWeight(wxFONTWEIGHT_BOLD);
              m_select_sound12->SetFont(font);
           }
           else
           {
              font = m_select_sound12->GetFont();
              font.SetWeight(wxFONTWEIGHT_NORMAL);
              m_select_sound12->SetFont(font);
           }

         m_select_sound12->Refresh(true);
      break;
      case 12:
           if(!flag)
           {
              font = m_select_sound13->GetFont();
              font.SetWeight(wxFONTWEIGHT_BOLD);
              m_select_sound13->SetFont(font);
           }
           else
           {
              font = m_select_sound13->GetFont();
              font.SetWeight(wxFONTWEIGHT_NORMAL);
              m_select_sound13->SetFont(font);
           }

         m_select_sound13->Refresh(true);
      break;
      case 13:
           if(!flag)
           {
              font = m_select_sound14->GetFont();
              font.SetWeight(wxFONTWEIGHT_BOLD);
              m_select_sound14->SetFont(font);
           }
           else
           {
              font = m_select_sound14->GetFont();
              font.SetWeight(wxFONTWEIGHT_NORMAL);
              m_select_sound14->SetFont(font);
           }

         m_select_sound14->Refresh(true);
      break;
      case 14:
           if(!flag)
           {
              font = m_select_sound15->GetFont();
              font.SetWeight(wxFONTWEIGHT_BOLD);
              m_select_sound15->SetFont(font);
           }
           else
           {
              font = m_select_sound15->GetFont();
              font.SetWeight(wxFONTWEIGHT_NORMAL);
              m_select_sound15->SetFont(font);
           }

         m_select_sound15->Refresh(true);
      break;
      case 15:
           if(!flag)
           {
              font = m_select_sound16->GetFont();
              font.SetWeight(wxFONTWEIGHT_BOLD);
              m_select_sound16->SetFont(font);
           }
           else
           {
              font = m_select_sound16->GetFont();
              font.SetWeight(wxFONTWEIGHT_NORMAL);
              m_select_sound16->SetFont(font);
           }

         m_select_sound16->Refresh(true);
      break;
   }

}

void SoundSelectionPanelImpl::OnSelectSound1(wxCommandEvent &event)
{
   deselectAllSoundButtons();
   m_select_sound1->SetValue(true);
   m_panel->activateSound(0);
}

void SoundSelectionPanelImpl::OnSelectSound2(wxCommandEvent &event)
{
   deselectAllSoundButtons();
   m_select_sound2->SetValue(true);
   m_panel->activateSound(1);
}

void SoundSelectionPanelImpl::OnSelectSound3(wxCommandEvent &event)
{
   deselectAllSoundButtons();
   m_select_sound3->SetValue(true);
   m_panel->activateSound(2);
}

void SoundSelectionPanelImpl::OnSelectSound4(wxCommandEvent &event)
{
   deselectAllSoundButtons();
   m_select_sound4->SetValue(true);
   m_panel->activateSound(3);
}

void SoundSelectionPanelImpl::OnSelectSound5(wxCommandEvent &event)
{
   deselectAllSoundButtons();
   m_select_sound5->SetValue(true);
   m_panel->activateSound(4);
}

void SoundSelectionPanelImpl::OnSelectSound6(wxCommandEvent &event)
{
   deselectAllSoundButtons();
   m_select_sound6->SetValue(true);
   m_panel->activateSound(5);
}

void SoundSelectionPanelImpl::OnSelectSound7(wxCommandEvent &event)
{
   deselectAllSoundButtons();
   m_select_sound7->SetValue(true);
   m_panel->activateSound(6);
}

void SoundSelectionPanelImpl::OnSelectSound8(wxCommandEvent &event)
{
   deselectAllSoundButtons();
   m_select_sound8->SetValue(true);
   m_panel->activateSound(7);
}

void SoundSelectionPanelImpl::OnSelectSound9(wxCommandEvent &event)
{
   deselectAllSoundButtons();
   m_select_sound9->SetValue(true);
   m_panel->activateSound(8);
}

void SoundSelectionPanelImpl::OnSelectSound10(wxCommandEvent &event)
{
   deselectAllSoundButtons();
   m_select_sound10->SetValue(true);
   m_panel->activateSound(9);
}

void SoundSelectionPanelImpl::OnSelectSound11(wxCommandEvent &event)
{
   deselectAllSoundButtons();
   m_select_sound11->SetValue(true);
   m_panel->activateSound(10);
}

void SoundSelectionPanelImpl::OnSelectSound12(wxCommandEvent &event)
{
   deselectAllSoundButtons();
   m_select_sound12->SetValue(true);
   m_panel->activateSound(11);
}

void SoundSelectionPanelImpl::OnSelectSound13(wxCommandEvent &event)
{
   deselectAllSoundButtons();
   m_select_sound13->SetValue(true);
   m_panel->activateSound(12);
}

void SoundSelectionPanelImpl::OnSelectSound14(wxCommandEvent &event)
{
   deselectAllSoundButtons();
   m_select_sound14->SetValue(true);
   m_panel->activateSound(13);
}

void SoundSelectionPanelImpl::OnSelectSound15(wxCommandEvent &event)
{
   deselectAllSoundButtons();
   m_select_sound15->SetValue(true);
   m_panel->activateSound(14);
}

void SoundSelectionPanelImpl::OnSelectSound16(wxCommandEvent &event)
{
   deselectAllSoundButtons();
   m_select_sound16->SetValue(true);
   m_panel->activateSound(15);
}

void SoundSelectionPanelImpl::deselectAllSoundButtons(void)
{
   m_select_sound1->SetValue(false);
   m_select_sound2->SetValue(false);
   m_select_sound3->SetValue(false);
   m_select_sound4->SetValue(false);
   m_select_sound5->SetValue(false);
   m_select_sound6->SetValue(false);
   m_select_sound7->SetValue(false);
   m_select_sound8->SetValue(false);
   m_select_sound9->SetValue(false);
   m_select_sound10->SetValue(false);
   m_select_sound11->SetValue(false);
   m_select_sound12->SetValue(false);
   m_select_sound13->SetValue(false);
   m_select_sound14->SetValue(false);
   m_select_sound15->SetValue(false);
   m_select_sound16->SetValue(false);
}

