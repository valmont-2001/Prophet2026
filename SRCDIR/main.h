#ifndef __MAINH__
#define __MAINH__

//#include <wx/wupdlock.h>

#ifdef __WXMAC__
   #define MAIN_WINDOW_WIDTH 1095
   #define MAIN_WINDOW_HEIGHT 765
#else
   #define MAIN_WINDOW_WIDTH 1015
   #define MAIN_WINDOW_HEIGHT 705
#endif

#define VERSION_STR "Version 1.5b"


class MyThread;
class MyPanel;
class MIDI;
class Proph2000;
class MySoundParam;
class MyMapParam;
class MyPresetParam;
class Samples;
class MIDIKeyboardDlg;
class wxNotebookEvent;
class CfgDlg;
class Audio;
class About;
class WaveGen;
class SoundSelectionPanelImpl;
class wxNotebook;
class Logger;
class MyFrame;


// Define a new application type
class MyApp: public wxApp
{
public:
    bool OnInit();

private:
   MyFrame *frame;
};

// Define a new frame type
class MyFrame: public wxFrame
{
public:
    MyFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString& name = wxT("frame"));
   ~MyFrame();

   void transferStarted(void);
   void transferEnded(void);
   void enableTransfer2ProphetControls(bool flag);
   void setMemoryOverloaded(bool flag) { m_memory_overloaded = flag; };
   uint8_t getFontSize(void) const { return m_font_size; };
   void setFontSize(uint8_t size) { m_font_size = size; };
   void updateMenuState(Proph2000 *proph);

private:
   MyPanel *m_panel;
   wxMenuItem *m_online_update_menuitem;
   wxMenuBar* m_menubar;
   wxLogWindow *m_log_window;
   About *m_about;
   Logger *m_log;
   bool m_memory_overloaded;
   uint8_t m_font_size;

   void OnMIDIKeyboard(wxCommandEvent& event);
   void OnStereoMode(wxCommandEvent& event);
   void OnOnlineUpdate(wxCommandEvent& event);
   void OnExtendedMemory(wxCommandEvent& event);
   void OnShowLog(wxCommandEvent& event);
   void OnDiscard(wxCommandEvent& event);
   void OnTx2PC(wxCommandEvent& event);
   void OnTx2Prophet(wxCommandEvent& event);
   void OnGetParameter(wxCommandEvent& event);
   void OnUpdateAllParameter(wxCommandEvent& event);
   void OnLoad(wxCommandEvent& event);
   void OnSave(wxCommandEvent& event);
   void OnCompareFile(wxCommandEvent& event);
   void OnConfig(wxCommandEvent& event);
   void OnIntelligentLoopPoints(wxCommandEvent& event);
   void OnAbout(wxCommandEvent& event);
   void OnAbort(wxCommandEvent& event);
   void OnPanic(wxCommandEvent& event);
   void OnApplyParameterToAll(wxCommandEvent& event);
   void OnDropFiles(wxDropFilesEvent &event);
#ifdef __WXMAC__
   void OnClose(wxCloseEvent &event);
#endif
   void OnSizeEvent(wxSizeEvent& event);  

    DECLARE_EVENT_TABLE()
};

class MyPanel : public wxScrolledWindow
{
public:
    MyPanel(wxFrame *frame, int x, int y, int w, int h, MyFrame *topframe, Logger *log);
    ~MyPanel();

   void handler(void);
   void transferFinished(bool closemidi);
   
   void saveConfig(void);

   void MIDIkeyboardDialog(void);

   void updateGUI(void);
   void setOnlineUpdateActive(bool flag);
   bool getOnlineUpdateActive(void) const { return m_onlineupdate_active; };
   void setExtendedMemory(bool flag);
   void setIntelligentLoopPoints(bool flag);

   void enableTransfer2ProphetControls(bool flag);
   
   void updateWaveView(void);
   void resetWaveViewZoom(void);

   void applyParameterToAll(bool flag);
   void OnDiscard(void);
   void OnTx2PC(void);
   void OnTx2Prophet(void);
   void OnGetParameter(void);
   void OnUpdateAllParameter(void);
   void OnLoad(void);
   void OnSave(void);
   void OnConfig(void);
   void OnAbort(void);
   void panic(void);
   void OnCompareFile(void);
   void OnStereoMode(bool flag);
   
#ifdef __WXMAC__
   void refreshNotebook(void);
#endif

   void load(const char *filename);

   void activatePreset(uint8_t preset_u8);

   void activateSoundOnGui(uint8_t sound_u8);
   void activateMapOnGui(uint8_t map_u8);

   bool getTransferInProgress(void) const { return m_transfer_in_progress; };

   void transferStarted(void);
   void transferEnded(void);

   void setRXHandshake(bool flag);

   void OnSizeEvent(uint16_t w, uint16_t h);  

   void soundNoteBookChanged(uint8_t selection);

   DECLARE_EVENT_TABLE()
private:
   MyFrame *m_topframe;
   Logger *m_log;
   MIDI *m_midi;
   Audio *m_audio;
   Samples *m_samples;
   Proph2000 *m_proph;
   MyThread *m_thread;
   MySoundParam *m_sound_param;
   MyMapParam *m_map_param;
   MyPresetParam *m_preset_param;
   MIDIKeyboardDlg *m_midikeyboard;
   CfgDlg *m_cfg_dlg;
   WaveGen *m_wavegen;
   wxRadioBox *m_map_select;
   wxRadioBox *m_preset_select;
   SoundSelectionPanelImpl *m_sound_selection;
   wxNotebook *m_notebook;
   bool m_onlineupdate_active;
   bool m_transfer_in_progress;
   wxSize m_orig_window_size;
   wxSize m_normal_window_size;
   bool m_handle_size_events;

   void initStereoModeDefaults(void);

   void OnGetParameter(wxCommandEvent& event);
   void OnMainNotebookChanged(wxNotebookEvent& event);
   void OnPresetChanged(wxNotebookEvent& event);
   void OnSoundTabChanged(wxCommandEvent& event);
   void OnIdle(wxIdleEvent &event);
   

   wxPanel *createSoundPanel(wxWindow *parent);
   wxPanel *createMapPanel(wxWindow *parent);
   wxPanel *createPresetPanel(wxWindow *parent);
   wxPanel *createSamplesPanel(wxWindow *parent);

};


#endif

