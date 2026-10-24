#ifndef __SNDSYNTHPANELH__
#define __SNDSYNTHPANELH__

class MyPanel;
class Proph2000;
class SoundSynthPanel;
class MySoundParam;

class SoundSynthPanelImpl : public SoundSynthPanel
{
public:
    SoundSynthPanelImpl(wxWindow *parent, MyPanel *topframe, Proph2000 *proph, uint8_t sound_u8, MySoundParam *panel);
    ~SoundSynthPanelImpl();

    void updateGUI(void);
    void displaySettings(void);
    void applyParameterToAll(bool flag);

    void activateSound(uint8_t sound_u8);

private:
   MyPanel *m_topframe;
   uint8_t m_sound_u8;
   Proph2000 *m_proph;
   MySoundParam *m_panel;
   bool m_apply_to_all;
   bool show_vcf_env_amount;
   bool updateVCAGraph;
   bool updateVCFGraph;
   bool trigger;

   void OnParamChange(wxCommandEvent &event);
   void OnLoad(wxCommandEvent& event);
   void OnSave(wxCommandEvent& event);
   void OnSliderChange(wxScrollEvent &event);
   void OnPurge(wxCommandEvent& event);
   void OnPlay(wxCommandEvent& event);
   void OnCopy(wxCommandEvent& event);
   void OnCopyParamToAll(wxCommandEvent& event);
   void OnGetSound(wxCommandEvent& event);
   void OnGetSoundParam(wxCommandEvent& event);
   void OnDeleteSound(wxCommandEvent& event);
   void OnImport(wxCommandEvent& event);
   void OnExport(wxCommandEvent& event);
   void OnLeftDown(wxMouseEvent& event);

   void OnAmpAttackSliderChange(wxScrollEvent& event);
   void OnAmpDecaySliderChange(wxScrollEvent& event);
   void OnAmpSustainSliderChange(wxScrollEvent& event);
   void OnAmpReleaseSliderChange(wxScrollEvent& event);
   void OnAmpAltReleaseSliderChange(wxScrollEvent& event);
   void OnFilterAttackSliderChange(wxScrollEvent& event);
   void OnFilterDecaySliderChange(wxScrollEvent& event);
   void OnFilterSustainSliderChange(wxScrollEvent& event);
   void OnFilterReleaseSliderChange(wxScrollEvent& event);
   void OnFilterAltReleaseSliderChange(wxScrollEvent& event);
   void OnFilterCutoffSliderChange(wxScrollEvent& event);
   void OnFilterResonanceSliderChange(wxScrollEvent& event);
   void OnFilterEnvelopeAmountSliderChange(wxScrollEvent& event);
   void OnFilterKeyboardTrackSliderChange(wxScrollEvent& event);
   void OnVelocityAttackSliderChange(wxScrollEvent& event);
   void OnVelocityReleaseSliderChange(wxScrollEvent& event);
   void OnVelocityVCAPeakSliderChange(wxScrollEvent& event);
   void OnVelocityVFCPeakSliderChange(wxScrollEvent& event);


   void OnUsedInMap1(wxCommandEvent& event);
   void OnUsedInMap2(wxCommandEvent& event);
   void OnUsedInMap3(wxCommandEvent& event);
   void OnUsedInMap4(wxCommandEvent& event);
   void OnUsedInMap5(wxCommandEvent& event);
   void OnUsedInMap6(wxCommandEvent& event);
   void OnUsedInMap7(wxCommandEvent& event);
   void OnUsedInMap8(wxCommandEvent& event);
   void updateUsedInMapStatus(void);
};




#endif
