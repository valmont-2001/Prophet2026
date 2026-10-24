#ifndef __PRESETKEYBOARDH__
#define __PRESETKEYBOARDH__

class Keyboard;
class MyPresetParam;
class Proph2000;
class MIDI;

class PresetKeyboard : public Keyboard
{
public:
    PresetKeyboard(wxWindow *parent, wxWindowID id, const wxPoint& pos, const wxSize& size, MyPresetParam *presetparamdlg,
                   Proph2000 *proph, MIDI *midi, uint8_t preset_u8);
    ~PresetKeyboard();

    virtual void setupKeyboadInfo(void);

    void setPreset(uint8_t preset_u8);

    void setMIDIInhibit(bool flag) { m_inhibit = flag; };

private:
   MyPresetParam *m_presetparamdlg;
   uint8_t m_preset_u8;
   Proph2000 *m_proph;
   wxSize m_size;
   MIDI *m_midi;
   bool m_inhibit;

   virtual void noteOn(void);
   virtual void noteOff(void);

   void setupMergeMode(void);
   void setupSplitMode(void);
   void setupLeftOnlyMode(void);
   void setupRightOnlyMode(void);
   void setupLayerMode(void);

};


#endif
