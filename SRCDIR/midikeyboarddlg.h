#ifndef __MIDIKEYBOARDDLGH__
#define __MIDIKEYBOARDDLGH__

class MyPanel;
class MIDI;
class MIDIKeyboard;
class PresetKeyboard;
class Proph2000;
class MIDIKeyPresetSelImpl;

class MIDIKeyboardDlg : public wxDialog
{
public:
    MIDIKeyboardDlg(const wxString &title, const wxPoint& pos, int w, int h, MyPanel *topframe, MIDI *midi, Proph2000 *proph);
    ~MIDIKeyboardDlg();

    void setMIDIInhibit(bool flag);

    void presetSelected(uint8_t preset);
    void activatePreset(uint8_t preset);

	DECLARE_EVENT_TABLE()
private:
   MyPanel *m_topframe;
   MIDI *m_midi;
   wxRadioBox *m_preset;
   //MIDIKeyboard *m_keyboard;
   PresetKeyboard *m_keyboard;
   MIDIKeyPresetSelImpl *m_presetselection;
   wxSlider *m_modwheel;
   bool m_inhibit;

   void OnModWheelChange(wxScrollEvent &event);
};


#endif
