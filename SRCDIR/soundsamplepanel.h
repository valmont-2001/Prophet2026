#ifndef __SNDSMPPANELH__
#define __SNDSMPPANELH__

class MyPanel;
class Proph2000;
class MySoundParam;


class SoundSamplePanelImpl : public SoundSamplePanel
{
public:
    SoundSamplePanelImpl(wxWindow *parent, MyPanel *topframe, Proph2000 *proph, uint8_t sound_u8, MySoundParam *panel);
    ~SoundSamplePanelImpl();

    void updateGUI(void);

    void activateSound(uint8_t sound_u8);

private:
   MyPanel *m_topframe;
   uint8_t m_sound_u8;
   Proph2000 *m_proph;
   MySoundParam *m_panel;
   bool m_update_gui_active;

   void OnCheckboxChange(wxCommandEvent& event);
   void OnSpinChange(wxSpinEvent &event);
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
   void OnHighKey1(wxCommandEvent& event);
   void OnHighKey2(wxCommandEvent& event);
   void OnHighKey3(wxCommandEvent& event);
   void OnHighKey4(wxCommandEvent& event);
   void OnHighKey5(wxCommandEvent& event);
   void OnHighKey6(wxCommandEvent& event);
   void OnHighKey7(wxCommandEvent& event);
   void OnHighKey8(wxCommandEvent& event);
   void OnHighKey(uint8_t map_id);
   void OnRootKey(wxCommandEvent& event);

   bool convertStringToNote(wxString str, uint8_t *note_pu8);

   void updateUsedInMapStatus(void);

   wxString getNote(uint8_t number_u8);

   void OnUsedInMap1(wxCommandEvent& event);
   void OnUsedInMap2(wxCommandEvent& event);
   void OnUsedInMap3(wxCommandEvent& event);
   void OnUsedInMap4(wxCommandEvent& event);
   void OnUsedInMap5(wxCommandEvent& event);
   void OnUsedInMap6(wxCommandEvent& event);
   void OnUsedInMap7(wxCommandEvent& event);
   void OnUsedInMap8(wxCommandEvent& event);

};




#endif
