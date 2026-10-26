#ifndef __PLAYPANELH__
#define __PLAYPANELH__

#include "presetlistener.h"

class MyPanel;
class MIDI;
class Proph2000;
class PresetKeyboard;
class MIDIKeyPresetSelImpl;

// Onglet "Play": choisir un preset puis le jouer avec un clavier virtuel a la souris.
// Meme contenu que la fenetre flottante "MIDI Keyboard", mais integre a la fenetre principale.
class PlayPanel : public wxPanel, public PresetSelectionListener
{
public:
   PlayPanel(wxWindow *parent, MyPanel *topframe, MIDI *midi, Proph2000 *proph, int width);

   void setMIDIInhibit(bool flag);
   virtual void presetSelected(uint8_t preset);
   void activatePreset(uint8_t preset);

private:
   MyPanel *m_topframe;
   MIDI *m_midi;
   MIDIKeyPresetSelImpl *m_presetselection;
   PresetKeyboard *m_keyboard;
   wxSlider *m_modwheel;
   bool m_inhibit;

   void OnModWheelChange(wxCommandEvent &event);
};

#endif
