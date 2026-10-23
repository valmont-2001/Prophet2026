#include "types.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>

#ifndef __WXMAC__
    #include <windows.h>
#endif
#include <list>
#include <map>
using namespace std;

#include "GUILayout.h"

#include "cfgdlg.h"
#include "midi.h"
#include "stopwatch.h"
#include "proph2000.h"
#include "audio.h"
#include "main.h"

#ifdef USE_PORTMIDI
   #include <portmidi.h>
#endif


CfgDlg::CfgDlg(wxWindow* parent, wxWindowID id, MIDI *midi, Proph2000 *proph, Audio *audio, MyFrame *mainframe, const wxPoint& pos):
   ConfigDlg(parent),
   m_midi(midi), m_proph(proph), m_audio(audio), m_mainframe(mainframe)
{
#ifdef __WXMAC__
   m_use_burst_hw->Disable();
   m_burst_baud->SetMinSize(wxSize(150, -1)); // "31250 baud (100%)" doesn't fit the Windows size
#endif
   
   
#ifdef USE_PORTMIDI
   map<int, int>::iterator myItr = m_midi->getInputDeviceList().begin();
   while(myItr != m_midi->getInputDeviceList().end())
   {
      wxString str;
      str.sprintf(wxT("%s"), Pm_GetDeviceInfo((*myItr).second)->name);
      m_midi_in_device->Append(str);
      ++myItr;
   }

   map<int, int>::iterator myItr2 = m_midi->getOutputDeviceList().begin();
   while(myItr2 != m_midi->getOutputDeviceList().end())
   {
      wxString str;
      str.sprintf(wxT("%s"), Pm_GetDeviceInfo((*myItr2).second)->name);
      m_midi_out_device->Append(str);
      ++myItr2;
   }
#endif


#ifdef USE_MSSMIDI
   list<MIDIINCAPS>::const_iterator myItr = m_midi->getInputDeviceList().begin();
   while(myItr != m_midi->getInputDeviceList().end())
   {
      wxString str;
      str.sprintf(wxT("%s"), (*myItr).szPname);
      m_midi_in_device->Append(str);
      ++myItr;
   }

   list<MIDIOUTCAPS>::const_iterator myItr2 = m_midi->getOutputDeviceList().begin();
   while(myItr2 != m_midi->getOutputDeviceList().end())
   {
      wxString str;
      str.sprintf(wxT("%s"), (*myItr2).szPname);
      m_midi_out_device->Append(str);
      ++myItr2;
   }
#endif

   m_burst_hw_speed->SetValue(m_midi->getBurstSpeed());

   if(m_midi->useMIDI())
   {
      m_use_burst_hw->SetValue(false);
   }
   else
   {
      m_use_burst_hw->SetValue(true);
   }
   for(int i = 1; i < 10; i++)
   {
      wxString str;
      str.sprintf(wxT("COM%d"), i);
      m_burst_hw_com->Append(str);
   }
   m_burst_hw_com->SetSelection(m_midi->getBurstHWCOM() - 1);

   m_midi_in_device->SetSelection(m_midi->getInDeviceID());
   m_midi_out_device->SetSelection(m_midi->getOutDeviceID());
   m_midi_ch->SetValue(m_midi->getChannel());


   map<int, int>::iterator myAItr = audio->getAudioDevicesList().begin();
   while(myAItr != audio->getAudioDevicesList().end())
   {
      const PaDeviceInfo *dev;
      dev = Pa_GetDeviceInfo((*myAItr).second);
      m_audio_device->AppendString(dev->name);
      ++myAItr;
   }

   m_audio_device->SetSelection(audio->getAudioDeviceID());

   m_fontsize->AppendString("4");
   m_fontsize->AppendString("6");
   m_fontsize->AppendString("8");
   m_fontsize->AppendString("10");
   m_fontsize->AppendString("12");
   switch(m_mainframe->getFontSize())
   {
	  case 4:
         m_fontsize->SetSelection(0);
         break;
	  case 6:
         m_fontsize->SetSelection(1);
         break;
      case 8:
         m_fontsize->SetSelection(2);
         break;
      case 10:
         m_fontsize->SetSelection(3);
         break;
      case 12:
         m_fontsize->SetSelection(4);
         break;
      default:
         m_fontsize->SetSelection(2);
         break;
   }

   updateGUI();
}


CfgDlg::~CfgDlg()
{
}


void CfgDlg::OnFontSize(wxCommandEvent &event)
{
   switch(m_fontsize->GetSelection())
   {
      case 0:
         m_mainframe->setFontSize(4);
         break;
      case 1:
         m_mainframe->setFontSize(6);
         break;
      case 2:
         m_mainframe->setFontSize(8);
         break;
      case 3:
         m_mainframe->setFontSize(10);
         break;
      case 4:
         m_mainframe->setFontSize(12);
         break;
   }
   wxMessageDialog edialog(this, wxT("Please restart application to make settings active"), wxT("Remark"));
   edialog.ShowModal();
}


void CfgDlg::updateGUI(void)
{
   if(m_use_burst_hw->GetValue())
   {
      m_midi_in_device->Disable();
      m_midi_out_device->Disable();
      m_burst_hw_com->Enable();
      m_burst_hw_speed->Enable();
      m_always_burst->Enable();
   }
   else
   {
      m_midi_in_device->Enable();
      m_midi_out_device->Enable();
      m_burst_hw_com->Disable();
      m_burst_hw_speed->Disable();
      m_always_burst->Disable();
   }
   wxString str;
   str.sprintf(wxT("%d baud (%d%%)"), 500000 / m_midi->getBurstSpeed(), (uint16_t) (((((float)500000 / m_midi->getBurstSpeed()) / (float)31250)) * 100));
   m_burst_baud->SetValue(str);
}


void CfgDlg::OnBurstSpeed(wxScrollEvent &event)
{
   m_midi->setBurstSpeed(m_burst_hw_speed->GetValue());
   updateGUI();
}


void CfgDlg::OnBurstHWCOM(wxCommandEvent &event)
{
   m_midi->setBurstHWCOM(m_burst_hw_com->GetSelection() + 1);
   if(!m_midi->useMIDI())
   {
      if(m_midi->isMIDIopen())
      {
         m_midi->close();
      }
   }
}

void CfgDlg::OnInDevice(wxCommandEvent &event)
{
   m_midi->setInDeviceID(m_midi_in_device->GetSelection());
}


void CfgDlg::OnOutDevice(wxCommandEvent &event)
{
   m_midi->setOutDeviceID(m_midi_out_device->GetSelection());
}


void CfgDlg::OnChannel(wxSpinEvent &event)
{
   m_midi->setChannel(m_midi_ch->GetValue());
}

void CfgDlg::OnUseBurstHW(wxCommandEvent &event)
{
   if(!m_midi->useMIDI())
   {
      if(m_midi->isMIDIopen())
      {
         m_midi->close();
      }
   }
   if(m_use_burst_hw->GetValue())
   {
      m_midi->setUseMIDI(false);
      wxLogMessage("Use burst HW");
   }
   else
   {
      m_midi->setUseMIDI(true);
      wxLogMessage("Use MIDI");
   }
   updateGUI();
}

void CfgDlg::OnBurstAlways(wxCommandEvent &event)
{
   bool burst_always_state;
   burst_always_state = m_use_burst_hw->GetValue();
   m_midi->alwaysBurst(burst_always_state);
   updateGUI();
}


void CfgDlg::OnAudioDevice(wxCommandEvent &event)
{
   m_audio->setAudioDeviceID(m_audio_device->GetSelection());
}

