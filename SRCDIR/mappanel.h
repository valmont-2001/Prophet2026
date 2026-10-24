#ifndef __MAPPANELH__
#define __MAPPANELH__

class MyPanel;
class Proph2000;
class wxSliderCtrl;
class MapKeyboard;
class MapScaleValuesDlg;
class MapPanel;
class MyMapParam;

class MapPanelImpl : public MapPanel
{
public:
    MapPanelImpl(wxWindow *parent, MyPanel *topframe, Proph2000 *proph, uint8_t map_u8, MyMapParam *mapparam);
    ~MapPanelImpl();

   void activateMap(uint8_t map_u8);
   void makeActive(uint8_t map_u8);
   void updateGUI(void);
   void displaySettings(void);

private:
   MyPanel *m_topframe;
   Proph2000 *m_proph;
   wxMenu *m_menu;
   uint8_t m_map_u8;
   MyMapParam *m_mapparam;
   bool show_vcf_env_amount;
   bool trigger;
   bool updateVCAGraph;
   bool updateVCFGraph;


   void OnParamChange(wxCommandEvent &event);
   void OnSliderChange(wxScrollEvent &event);
   void OnLoad(wxCommandEvent& event);
   void OnSave(wxCommandEvent& event);
   void OnCopy(wxCommandEvent& event);

   wxString calcPercentageStr(int8_t value);
   uint8_t calcPercentage(int8_t value);

   void OnCheckboxChange(wxCommandEvent& event);

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
   void OnVelocitySampleStartSliderChange(wxScrollEvent& event);
   
   void OnUsingSound1(wxCommandEvent& event);
   void OnUsingSound2(wxCommandEvent& event);
   void OnUsingSound3(wxCommandEvent& event);
   void OnUsingSound4(wxCommandEvent& event);
   void OnUsingSound5(wxCommandEvent& event);
   void OnUsingSound6(wxCommandEvent& event);
   void OnUsingSound7(wxCommandEvent& event);
   void OnUsingSound8(wxCommandEvent& event);

   void OnSelectMap1(wxCommandEvent& event);
   void OnSelectMap2(wxCommandEvent& event);
   void OnSelectMap3(wxCommandEvent& event);
   void OnSelectMap4(wxCommandEvent& event);
   void OnSelectMap5(wxCommandEvent& event);
   void OnSelectMap6(wxCommandEvent& event);
   void OnSelectMap7(wxCommandEvent& event);
   void OnSelectMap8(wxCommandEvent& event);
   void OnSelectMap9(wxCommandEvent& event);
   void OnSelectMap10(wxCommandEvent& event);
   void OnSelectMap11(wxCommandEvent& event);
   void OnSelectMap12(wxCommandEvent& event);
   void OnSelectMap13(wxCommandEvent& event);
   void OnSelectMap14(wxCommandEvent& event);
   void OnSelectMap15(wxCommandEvent& event);
   void OnSelectMap16(wxCommandEvent& event);
   void OnLeftDown(wxMouseEvent& event);

   void deselectAllMapButtons(void);
   void updateUsedSounds(uint8_t soundID, bool draw);



};


#endif
