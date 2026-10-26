#include "types.h"

#include <wx/wx.h>
#include <map>
#include <list>
using namespace std;
#include "midi.h"
#include "clickarea.h"
#include "keyboard.h"
#include "presetkeyboard.h"
#include "stopwatch.h"
#include "proph2000.h"
#include "GUILayout.h"
#include "midikeypresetsel.h"
#include "main.h"
#include "playpanel.h"

#define MODWHEEL_OPTIONS (wxSL_VERTICAL | wxSL_LABELS | wxSL_INVERSE)
#define KEYBOARD_HEIGHT 260


PlayPanel::PlayPanel(wxWindow *parent, MyPanel *topframe, MIDI *midi, Proph2000 *proph, int width) :
   wxPanel(parent, wxID_ANY),
   m_topframe(topframe), m_midi(midi), m_inhibit(false)
{
   wxBoxSizer *vsizer = new wxBoxSizer(wxVERTICAL);
   vsizer->AddSpacer(16);

   wxStaticText *help = new wxStaticText(this, wxID_ANY,
      wxT("Choose a preset, then play it with the mouse. Notes are sent to the Prophet over MIDI."));
   vsizer->Add(help, 0, wxLEFT, 8);
   vsizer->AddSpacer(16);

   m_presetselection = new MIDIKeyPresetSelImpl(this, this);
   vsizer->Add(m_presetselection, 0, wxLEFT, 8);
   vsizer->AddSpacer(16);

   wxBoxSizer *hsizer = new wxBoxSizer(wxHORIZONTAL);
   hsizer->AddSpacer(8);

   m_modwheel = new wxSlider(this, wxID_ANY, 0, 0, 127, wxDefaultPosition, wxSize(50, KEYBOARD_HEIGHT), MODWHEEL_OPTIONS);
   hsizer->Add(m_modwheel);
   hsizer->AddSpacer(8);

   int kbwidth = width - 140;
   if(kbwidth < 400)
   {
      kbwidth = 400;
   }
   m_keyboard = new PresetKeyboard(this, wxID_ANY, wxDefaultPosition, wxSize(kbwidth, KEYBOARD_HEIGHT), NULL, proph, midi, 0);
   hsizer->Add(m_keyboard);
   vsizer->Add(hsizer);

   SetSizer(vsizer);

   m_modwheel->Bind(wxEVT_SLIDER, &PlayPanel::OnModWheelChange, this);
   m_keyboard->setMIDIInhibit(false);
}


void PlayPanel::setMIDIInhibit(bool flag)
{
   m_keyboard->setMIDIInhibit(flag);
   m_inhibit = flag;
}


void PlayPanel::presetSelected(uint8_t preset)
{
   m_topframe->activatePreset(preset);
}


void PlayPanel::activatePreset(uint8_t preset)
{
   m_keyboard->setPreset(preset);
   switch(preset)
   {
      case 0:  m_presetselection->selectPreset1();  break;
      case 1:  m_presetselection->selectPreset2();  break;
      case 2:  m_presetselection->selectPreset3();  break;
      case 3:  m_presetselection->selectPreset4();  break;
      case 4:  m_presetselection->selectPreset5();  break;
      case 5:  m_presetselection->selectPreset6();  break;
      case 6:  m_presetselection->selectPreset7();  break;
      case 7:  m_presetselection->selectPreset8();  break;
      case 8:  m_presetselection->selectPreset9();  break;
      case 9:  m_presetselection->selectPreset10(); break;
      case 10: m_presetselection->selectPreset11(); break;
      case 11: m_presetselection->selectPreset12(); break;
      default: break;
   }
}


void PlayPanel::OnModWheelChange(wxCommandEvent &event)
{
   if(m_midi && !m_inhibit)
   {
      if(!m_midi->isMIDIopen())
      {
         m_midi->init();
      }
      if(m_midi->isMIDIopen())
      {
         m_midi->sendController(1, m_modwheel->GetValue());
      }
   }
}
