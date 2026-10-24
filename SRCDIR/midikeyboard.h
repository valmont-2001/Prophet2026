#ifndef __MIDIKEYBOARDH__
#define __MIDIKEYBOARDH__

class Keyboard;
class MIDI;

class MIDIKeyboard : public Keyboard
{
public:
    MIDIKeyboard(wxWindow *parent, wxWindowID id, const wxPoint& pos, const wxSize& size, MIDI *midi);
    ~MIDIKeyboard();

    void setMIDIInhibit(bool flag) { m_inhibit = flag; };

private:
   MIDI *m_midi;
   bool m_inhibit;

   virtual void noteOn(void);
   virtual void noteOff(void);
};


#endif
