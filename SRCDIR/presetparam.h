#ifndef __PRESETPARAMH__
#define __PRESETPARAMH__

class MyPanel;
class Proph2000;
class PresetKeyboard;
class PresetPanelImpl;

class MyPresetParam : public wxPanel
{
public:
    MyPresetParam(wxWindow *parent, MyPanel *topframe, Proph2000 *proph, uint8_t preset_u8);
    ~MyPresetParam();

    void updateGUI(void);

    void OnLoad(wxCommandEvent& event);
    void OnSave(wxCommandEvent& event);
    void OnCopy(wxCommandEvent& event);

    void handleKeyboardNoteEvent(uint8_t note);

    void transferStarted(void);
    void transferEnded(void);

    void activatePreset(uint8_t preset_u8);

	DECLARE_EVENT_TABLE()
private:
   MyPanel *m_topframe;
   Proph2000 *m_proph;
   uint8_t m_preset_u8;
   PresetKeyboard *m_preset_keyboard;
   wxComboBox *m_edit_selection;
   PresetPanelImpl *m_panel;
   //wxMenu *m_menu;

   void OnMouseRightDown(wxMouseEvent &event);
};


#endif
