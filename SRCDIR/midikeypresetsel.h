#ifndef __MIDIKEYPRESELH__
#define __MIDIKEYPRESELH__

class MyPanel;
class Proph2000;
class SoundSynthPanel;
class MIDIKeyboardDlg;


class MIDIKeyPresetSelImpl : public MIDIKeyboardPresetSelection
{
public:
    MIDIKeyPresetSelImpl(wxWindow *parent, MIDIKeyboardDlg *panel);
    ~MIDIKeyPresetSelImpl();
    void selectPreset1();
    void selectPreset2();
    void selectPreset3();
    void selectPreset4();
    void selectPreset5();
    void selectPreset6();
    void selectPreset7();
    void selectPreset8();
    void selectPreset9();
    void selectPreset10();
    void selectPreset11();
    void selectPreset12();

private:
   MIDIKeyboardDlg *m_panel;

   void OnSelectPreset1(wxCommandEvent& event);
   void OnSelectPreset2(wxCommandEvent& event);
   void OnSelectPreset3(wxCommandEvent& event);
   void OnSelectPreset4(wxCommandEvent& event);
   void OnSelectPreset5(wxCommandEvent& event);
   void OnSelectPreset6(wxCommandEvent& event);
   void OnSelectPreset7(wxCommandEvent& event);
   void OnSelectPreset8(wxCommandEvent& event);
   void OnSelectPreset9(wxCommandEvent& event);
   void OnSelectPreset10(wxCommandEvent& event);
   void OnSelectPreset11(wxCommandEvent& event);
   void OnSelectPreset12(wxCommandEvent& event);

   void deselectAllPresetButtons(void);
};




#endif
