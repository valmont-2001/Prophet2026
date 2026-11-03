#ifndef __PLAYPANELH__
#define __PLAYPANELH__

#include "presetlistener.h"

class MyPanel;
class MIDI;
class Proph2000;
class Audio;
class PresetKeyboard;
class MIDIKeyPresetSelImpl;
class SoftProphetPlayer;

// Onglet "Play": choisir un preset puis le jouer avec un clavier virtuel a la souris.
//  - "Play on this computer": le faux Prophet rejoue les vrais samples (boucles, enveloppes, filtre...)
//  - "Also send to the Prophet (MIDI)": envoie aussi les notes au vrai Prophet, pour comparer a l'oreille
class PlayPanel : public wxPanel, public PresetSelectionListener, public KeyListener
{
public:
   PlayPanel(wxWindow *parent, MyPanel *topframe, MIDI *midi, Proph2000 *proph, Audio *audio, int width);
   ~PlayPanel();

   void setMIDIInhibit(bool flag);
   virtual void presetSelected(uint8_t preset);
   void activatePreset(uint8_t preset);

   void reloadSounds();     // relit samples, sons, maps et preset depuis les donnees de l'editeur
   void allNotesOff();

   virtual void keyDown(uint8_t note, uint8_t velocity);
   virtual void keyUp(uint8_t note, uint8_t velocity);

private:
   MyPanel *m_topframe;
   MIDI *m_midi;
   Proph2000 *m_proph;
   Audio *m_audio;
   MIDIKeyPresetSelImpl *m_presetselection;
   PresetKeyboard *m_keyboard;
   wxSlider *m_modwheel;
   wxCheckBox *m_soft_check;
   wxCheckBox *m_midi_check;
   wxCheckBox *m_hold_check;
   wxButton *m_reload_button;
   wxStaticText *m_status;
   SoftProphetPlayer *m_player;
   uint8_t m_preset;
   bool m_inhibit;

   bool softEnabled() const;
   bool midiEnabled() const;
   bool ensureSoftStarted();
   void sendMIDINote(bool on, uint8_t note, uint8_t velocity);
   void sendMIDIController(uint8_t controller, uint8_t value);
   void setStatus(const wxString &text);

   void OnModWheelChange(wxCommandEvent &event);
   void OnSoftToggle(wxCommandEvent &event);
   void OnHoldToggle(wxCommandEvent &event);
   void OnReload(wxCommandEvent &event);
};

#endif
