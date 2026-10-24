#include "types.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>

#ifdef _WIN32
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



CfgDlg::CfgDlg(wxWindow* parent, wxWindowID id, MIDI *midi, Proph2000 *proph, Audio *audio, MyFrame *mainframe, const wxPoint& pos):
   ConfigDlg(parent),
   m_midi(midi), m_proph(proph), m_audio(audio), m_mainframe(mainframe)
{
   map<int, int>::iterator myItr = m_midi->getInputDeviceList().begin();
   while(myItr != m_midi->getInputDeviceList().end())
   {
      wxString str;
      str.sprintf(wxT("%s"), m_midi->getMIDIInDevice()->getPortName((*myItr).second).c_str());
      m_midi_in_device->Append(str);
      ++myItr;
   }

   map<int, int>::iterator myItr2 = m_midi->getOutputDeviceList().begin();
   while(myItr2 != m_midi->getOutputDeviceList().end())
   {
      wxString str;
      str.sprintf(wxT("%s"), m_midi->getMIDIOutDevice()->getPortName((*myItr2).second).c_str());
      m_midi_out_device->Append(str);
      ++myItr2;
   }


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

void CfgDlg::OnAudioDevice(wxCommandEvent &event)
{
   m_audio->setAudioDeviceID(m_audio_device->GetSelection());
}

