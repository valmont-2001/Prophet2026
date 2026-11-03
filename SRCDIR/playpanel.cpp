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
#include "audio.h"
#include "softprophet_adapter.h"
#include "softprophet_player.h"
#include "playpanel.h"

#define MODWHEEL_OPTIONS (wxSL_VERTICAL | wxSL_LABELS | wxSL_INVERSE)
#define KEYBOARD_HEIGHT 260


PlayPanel::PlayPanel(wxWindow *parent, MyPanel *topframe, MIDI *midi, Proph2000 *proph, Audio *audio, int width) :
   wxPanel(parent, wxID_ANY),
   m_topframe(topframe), m_midi(midi), m_proph(proph), m_audio(audio), m_player(NULL), m_preset(0), m_inhibit(false)
{
   wxBoxSizer *vsizer = new wxBoxSizer(wxVERTICAL);
   vsizer->AddSpacer(12);

   // --- options de lecture
   wxBoxSizer *opts = new wxBoxSizer(wxHORIZONTAL);
   m_soft_check = new wxCheckBox(this, wxID_ANY, wxT("Play on this computer (soft Prophet)"));
   m_soft_check->SetValue(true);
   m_midi_check = new wxCheckBox(this, wxID_ANY, wxT("Also send notes to the Prophet (MIDI)"));
   m_hold_check = new wxCheckBox(this, wxID_ANY, wxT("Hold"));
   m_reload_button = new wxButton(this, wxID_ANY, wxT("Reload sounds"));
   opts->Add(m_soft_check, 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 24);
   opts->Add(m_midi_check, 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 24);
   opts->Add(m_hold_check, 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 24);
   opts->Add(m_reload_button, 0, wxALIGN_CENTER_VERTICAL);
   vsizer->Add(opts, 0, wxLEFT, 8);
   vsizer->AddSpacer(6);

   m_status = new wxStaticText(this, wxID_ANY, wxT("Pick a preset, then play. The soft Prophet reads the samples, loops, envelopes and filter of the editor."));
   vsizer->Add(m_status, 0, wxLEFT, 8);
   vsizer->AddSpacer(12);

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
   m_keyboard->setMIDIInhibit(false);
   m_keyboard->setKeyListener(this);
   hsizer->Add(m_keyboard);
   vsizer->Add(hsizer);

   SetSizer(vsizer);

   m_modwheel->Bind(wxEVT_SLIDER, &PlayPanel::OnModWheelChange, this);
   m_soft_check->Bind(wxEVT_CHECKBOX, &PlayPanel::OnSoftToggle, this);
   m_hold_check->Bind(wxEVT_CHECKBOX, &PlayPanel::OnHoldToggle, this);
   m_reload_button->Bind(wxEVT_BUTTON, &PlayPanel::OnReload, this);
}


PlayPanel::~PlayPanel()
{
   delete m_player;
   m_player = NULL;
}


bool PlayPanel::softEnabled() const
{
   return m_soft_check->GetValue();
}


bool PlayPanel::midiEnabled() const
{
   return m_midi_check->GetValue();
}


void PlayPanel::setStatus(const wxString &text)
{
   m_status->SetLabel(text);
}


void PlayPanel::setMIDIInhibit(bool flag)
{
   m_inhibit = flag;
   m_keyboard->setMIDIInhibit(flag);
}


// ---------------------------------------------------------------------------------------------
// Faux Prophet
// ---------------------------------------------------------------------------------------------
bool PlayPanel::ensureSoftStarted()
{
   if(!m_player)
   {
      m_player = new SoftProphetPlayer();
   }
   if(!m_player->isRunning())
   {
      if(!m_player->start(m_audio))
      {
         setStatus(wxT("Could not open the audio output. Check the audio device in the configuration."));
         m_soft_check->SetValue(false);
         return false;
      }
      reloadSounds();
   }
   return true;
}


void PlayPanel::reloadSounds()
{
   if(!softEnabled() || !m_player || !m_player->isRunning() || m_inhibit)
   {
      return;
   }
   int n = 0;
   std::shared_ptr<softprophet::Patch> patch = softProphetBuildPatch(m_proph, m_preset, &n);
   m_player->engine()->setPatch(patch);
   if(n > 0)
   {
      setStatus(wxString::Format(wxT("Soft Prophet ready: preset %d, %d sound(s), audio output %.0f Hz"),
                                 (int)m_preset + 1, n, m_player->sampleRate()));
   }
   else
   {
      setStatus(wxString::Format(wxT("Preset %d plays no sound: load or transfer samples, and check its maps."), (int)m_preset + 1));
   }
}


void PlayPanel::allNotesOff()
{
   if(m_player && m_player->isRunning())
   {
      m_player->engine()->allNotesOff();
   }
}


void PlayPanel::sendMIDINote(bool on, uint8_t note, uint8_t velocity)
{
   if(!m_midi || m_inhibit)
   {
      return;
   }
   if(!m_midi->isMIDIopen())
   {
      m_midi->init();
   }
   if(m_midi->isMIDIopen())
   {
      if(on)
      {
         m_midi->sendNoteOn(note, velocity);
      }
      else
      {
         m_midi->sendNoteOff(note, velocity);
      }
   }
}


void PlayPanel::sendMIDIController(uint8_t controller, uint8_t value)
{
   if(!m_midi || m_inhibit)
   {
      return;
   }
   if(!m_midi->isMIDIopen())
   {
      m_midi->init();
   }
   if(m_midi->isMIDIopen())
   {
      m_midi->sendController(controller, value);
   }
}


void PlayPanel::keyDown(uint8_t note, uint8_t velocity)
{
   if(softEnabled() && ensureSoftStarted())
   {
      m_player->engine()->noteOn(note, velocity);
   }
   if(midiEnabled())
   {
      sendMIDINote(true, note, velocity);
   }
}


void PlayPanel::keyUp(uint8_t note, uint8_t velocity)
{
   if(m_player && m_player->isRunning())
   {
      m_player->engine()->noteOff(note);
   }
   if(midiEnabled())
   {
      sendMIDINote(false, note, velocity);
   }
}


// ---------------------------------------------------------------------------------------------
// Preset et controles
// ---------------------------------------------------------------------------------------------
void PlayPanel::presetSelected(uint8_t preset)
{
   m_topframe->activatePreset(preset);
}


void PlayPanel::activatePreset(uint8_t preset)
{
   m_preset = preset;
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
   allNotesOff();
   reloadSounds();
}


void PlayPanel::OnModWheelChange(wxCommandEvent &event)
{
   const int value = m_modwheel->GetValue();
   if(m_player && m_player->isRunning())
   {
      m_player->engine()->setModWheel((float)value / 127.0f);
   }
   if(midiEnabled())
   {
      sendMIDIController(1, (uint8_t)value);
   }
}


void PlayPanel::OnSoftToggle(wxCommandEvent &event)
{
   if(softEnabled())
   {
      if(ensureSoftStarted())
      {
         reloadSounds();
      }
   }
   else
   {
      allNotesOff();
      setStatus(wxT("Computer playback is off."));
   }
}


void PlayPanel::OnHoldToggle(wxCommandEvent &event)
{
   const bool on = m_hold_check->GetValue();
   if(m_player && m_player->isRunning())
   {
      m_player->engine()->setHold(on);
   }
   if(midiEnabled())
   {
      sendMIDIController(64, on ? 127 : 0);   // pedale de sustain
   }
}


void PlayPanel::OnReload(wxCommandEvent &event)
{
   if(softEnabled() && ensureSoftStarted())
   {
      reloadSounds();
   }
}
