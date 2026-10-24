#ifndef __SOUNDKEYBOARDH__
#define __SOUNDKEYBOARDH__

class Keyboard;
class MySoundParam;
class Proph2000;

class SoundKeyboard : public Keyboard
{
public:
    SoundKeyboard(wxWindow *parent, wxWindowID id, const wxPoint& pos, const wxSize& size, 
                  MySoundParam *soundparamdlg, Proph2000 *proph, uint8_t sound);
    ~SoundKeyboard();

    virtual void setupKeyboadInfo(void);

    void activateSound(uint8_t sound);

    void setKeyboardEditSelection(MySoundParam::keyboard_edit_selection_te mode);

private:
   MySoundParam *m_soundparamdlg;
   Proph2000 *m_proph;
   uint8_t m_sound;
   MySoundParam::keyboard_edit_selection_te m_keyboard_edit_selection_e;

   virtual void noteOn(void);
   virtual void noteOff(void);
   virtual void rightClick(void);

};


#endif
