#ifndef __PRESETPANELH__
#define __PRESETPANELH__


class MyPanel;
class Proph2000;
class PresetKeyboard;
class MyPresetParam;


class PresetPanelImpl : public PresetPanel
{
public:
    PresetPanelImpl(wxWindow *parent, MyPanel *topframe, Proph2000 *proph, uint8_t preset_u8, MyPresetParam *presetparam);
    ~PresetPanelImpl();

    void displaySettings(void);
    void updateGUI(void);
    void activatePreset(uint8_t preset_u8);

    //void transferStarted(void);
    //void transferEnded(void);

private:
   MyPanel *m_topframe;
   Proph2000 *m_proph;
   uint8_t m_preset_u8;
   MyPresetParam *m_presetparam;

   void OnParamChange(wxCommandEvent &event);
   void OnLeftMapSelect(wxCommandEvent &event);
   void OnRightMapSelect(wxCommandEvent &event);
   void OnSliderChange(wxScrollEvent &event);
   void OnLFOFreqSliderChange(wxScrollEvent &event);
   void OnLFOInitAmountSliderChange(wxScrollEvent &event);
   void OnLFOVelocitySliderChange(wxScrollEvent &event);
   void OnKeyboardTransposeSliderChange(wxScrollEvent &event);
   void OnKeyboardVelocitySwitchSliderChange(wxScrollEvent &event);
   void OnStackDelaySliderChange(wxScrollEvent &event);
   void OnStackDetuneSliderChange(wxScrollEvent &event);
   void OnArpRateSliderChange(wxScrollEvent &event);
   void OnPitchwheelSliderChange(wxScrollEvent &event);


   void OnComboChanged(wxCommandEvent &event);
   void OnCheckboxChange(wxCommandEvent& event);
   void OnSplitPoint(wxCommandEvent& event);
   void OnArpSplitPoint(wxCommandEvent& event);

   bool convertStringToNote(wxString str, uint8_t *note_pu8);

   void OnLoad(wxCommandEvent& event);
   void OnSave(wxCommandEvent& event);
   void OnCopy(wxCommandEvent& event);

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

   void OnUsingSound1(wxCommandEvent& event);
   void OnUsingSound2(wxCommandEvent& event);
   void OnUsingSound3(wxCommandEvent& event);
   void OnUsingSound4(wxCommandEvent& event);
   void OnUsingSound5(wxCommandEvent& event);
   void OnUsingSound6(wxCommandEvent& event);
   void OnUsingSound7(wxCommandEvent& event);
   void OnUsingSound8(wxCommandEvent& event);
   void OnUsingSound9(wxCommandEvent& event);
   void OnUsingSound10(wxCommandEvent& event);
   void OnUsingSound11(wxCommandEvent& event);
   void OnUsingSound12(wxCommandEvent& event);
   void OnUsingSound13(wxCommandEvent& event);
   void OnUsingSound14(wxCommandEvent& event);
   void OnUsingSound15(wxCommandEvent& event);
   void OnUsingSound16(wxCommandEvent& event);

   void OnLeftMapSelector(wxCommandEvent& event);
   void OnRightMapSelector(wxCommandEvent& event);

   void set_left_sound_buttons(bool side);
   void set_right_sound_buttons(bool side);

   void updateUsedSounds(uint8_t map_side, uint8_t map);

   void deselectAllPresetButtons(void);

   wxString getNote(uint8_t number_u8);
};


#endif
