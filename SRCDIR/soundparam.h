#ifndef __SNDPARAMH__
#define __SNDPARAMH__

class MyPanel;
class Proph2000;
class SoundKeyboard;
class WaveDisp;
class wxToggleButton;
class Wave;
class wxNotebookEvent;
class wxSound;
class wxNotebook;
class LoadSampleDlg;
class Audio;
class SoundSamplePanelImpl;
class SoundSynthPanelImpl;
class SoundLoopPanelImpl;
class SoundCopyDialog;
class Logger;

class MySoundParam : public wxPanel
{
public:
    MySoundParam(wxWindow *parent, MyPanel *topframe, Proph2000 *proph, uint8_t sound_u8, Audio *audio, Logger *log);
    ~MySoundParam();

    void updateGUI(void);

    void noteEvent(uint8_t note);
    void setTransposeOrigin(uint8_t note);

    void activateSound(uint8_t sound_u8);

    void updateWaveView(void);
    void resetWaveViewZoom(void);

    void copyParamToAll(void);
    void applyParameterToAll(bool flag);

    void startPlayback(void);
    void stopPlayback(void);

    void setSubNotebook(uint8_t selection);

    void transferStarted(void);
    void transferEnded(void);

    void OnPlay(wxCommandEvent& event);
    void OnCopy(wxCommandEvent& event);
    void OnCopyParamToAll(wxCommandEvent& event);
    void OnGetSound(wxCommandEvent& event);
    void OnGetSoundParam(wxCommandEvent& event);
    void OnDeleteSound(wxCommandEvent& event);
    void OnLoad(wxCommandEvent& event);
    void OnSave(wxCommandEvent& event);
    void OnPurge(wxCommandEvent& event);
    void OnImport(wxCommandEvent& event);
    void OnExport(wxCommandEvent& event);

    bool getAsyncPlayActiveFlag(void) const { return m_async_play_active; };
    void setAsyncPlayActiveFlag(bool flag) { m_async_play_active = flag; };

    void setUpdateLoopParamsActive(bool flag);


    void setIntelligentLoopPoints(bool flag) { m_intelligent_loop_points = flag; };
    bool getIntelligentLoopPoints(void) const { return m_intelligent_loop_points; };

    typedef enum { ROOT, HIKEY1, HIKEY2, HIKEY3, HIKEY4, HIKEY5, HIKEY6, HIKEY7, HIKEY8 } keyboard_edit_selection_te;

	DECLARE_EVENT_TABLE()
private:
   Logger *m_log;
   MyPanel *m_topframe;
   uint8_t m_sound_u8;
   Proph2000 *m_proph;
   SoundSamplePanelImpl *m_samplepanel;
   SoundSynthPanelImpl *m_synthpanel;
   SoundLoopPanelImpl *m_looppanel;
   SoundCopyDialog *m_copydlg;
   Audio *m_audio;
   bool m_intelligent_loop_points;
   wxToggleButton *m_play_button;
   uint16_t m_loop_play_tmp_buf_l[MAX_SAMPLE_WORDS_PER_MEMORY * 2];
   uint16_t m_loop_play_tmp_buf_r[MAX_SAMPLE_WORDS_PER_MEMORY * 2];
   wxNotebook *m_notebook;
   //wxMenu *m_menu;
   LoadSampleDlg *m_load_smp_dlg;
   bool m_async_play_active;

   wxComboBox *m_edit_selection;
   SoundKeyboard *m_sound_keyboard;

   void purge(uint8_t sound_u8);

   void OnParamChange(wxCommandEvent &event);
   void OnKeyboardEditSelection(wxCommandEvent &event);
   void OnSliderChange(wxScrollEvent &event);
   void OnCheckboxChange(wxCommandEvent& event);
   void OnWaveSelection(wxCommandEvent& event);
   void OnNotebookChanged(wxNotebookEvent& event);

   void OnMouseRightDown(wxMouseEvent &event);

   wxString getNote(uint8_t number_u8);
};




#endif
