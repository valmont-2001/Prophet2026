#ifndef __MAPPARAMH__
#define __MAPPARAMH__

class MyPanel;
class Proph2000;
class wxSliderCtrl;
class MapKeyboard;
class MapScaleValuesDlg;
class MapPanelImpl;

class MyMapParam : public wxPanel
{
public:
    MyMapParam(wxWindow *parent, MyPanel *topframe, Proph2000 *proph, uint8_t map_u8);
    ~MyMapParam();

   void activateMap(uint8_t map_u8);
   void makeActive(uint8_t map_u8);

   void updateGUI(void);

   void transferStarted(void);
   void transferEnded(void);

   void OnLoad(wxCommandEvent& event);
   void OnSave(wxCommandEvent& event);
   void OnCopy(wxCommandEvent& event);

   void showScaledSampleValues(uint8_t sample_id);

	DECLARE_EVENT_TABLE()
private:
   MyPanel *m_topframe;
   Proph2000 *m_proph;
   //wxMenu *m_menu;
   uint8_t m_map_u8;
   wxSlider *m_amp_release_rate;
   wxTextCtrl *m_amp_release_rate_percentage;
   wxSlider *m_amp_2nd_release_rate;
   wxTextCtrl *m_amp_2nd_release_rate_percentage;
   wxSlider *m_amp_decay_rate;
   wxTextCtrl *m_amp_decay_rate_percentage;
   wxSlider *m_amp_sustain_level;
   wxTextCtrl *m_amp_sustain_level_percentage;
   wxSlider *m_amp_attack_rate;
   wxTextCtrl *m_amp_attack_rate_percentage;
   wxSlider *m_amp_peak_vel_sensitivity;
   wxTextCtrl *m_amp_peak_vel_sensitivity_percentage;
   wxSlider *m_filt_release_rate;
   wxTextCtrl *m_filt_release_rate_percentage;
   wxSlider *m_filt_2nd_release_rate;
   wxTextCtrl *m_filt_2nd_release_rate_percentage;
   wxSlider *m_filt_decay_rate;
   wxTextCtrl *m_filt_decay_rate_percentage;
   wxSlider *m_filt_sustain_level;
   wxTextCtrl *m_filt_sustain_level_percentage;
   wxSlider *m_filt_attack_rate;
   wxTextCtrl *m_filt_attack_rate_percentage;
   wxSlider *m_filt_peak_vel_sensitivity;
   wxTextCtrl *m_filt_peak_vel_sensitivity_percentage;
   wxSlider *m_filt_resonance;
   wxTextCtrl *m_filt_resonance_percentage;
   wxSlider *m_filt_env_amount;
   wxTextCtrl *m_filt_env_amount_percentage;
   wxSlider *m_filt_keyboard_tracking;
   wxTextCtrl *m_filt_keyboard_tracking_percentage;
   wxSlider *m_filt_cutoff;
   wxTextCtrl *m_filt_cutoff_percentage;
   wxSlider *m_attack_vel_sensitivity;
   wxTextCtrl *m_attack_vel_sensitivity_percentage;
   wxSlider *m_release_vel_sensitivity;
   wxTextCtrl *m_release_vel_sensitivity_percentage;
   //wxTextCtrl *m_sound_direction;
   wxCheckBox *m_sound_direction_reversed;
   wxSlider *m_velocity_start_point;
   wxTextCtrl *m_velocity_start_point_percentage;
   MapKeyboard *m_mapkeyboard;
   MapPanelImpl *m_panel;
   
   void OnParamChange(wxCommandEvent &event);
   void OnSliderChange(wxScrollEvent &event);
   void OnMouseRightDown(wxMouseEvent &event);

   wxString calcPercentage(int8_t value);

   void OnCheckboxChange(wxCommandEvent& event);

};


#endif
