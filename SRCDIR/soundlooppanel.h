#ifndef __SNDLOOPPANELH__
#define __SNDLOOPPANELH__

class MyPanel;
class Proph2000;
class SoundKeyboard;
class WaveDisp;
class wxToggleButton;
class Wave;
class SoundLoopPanel;
class MySoundParam;


class SoundLoopPanelImpl : public SoundLoopPanel
{
public:
    SoundLoopPanelImpl(wxWindow *parent, MyPanel *topframe, Proph2000 *proph, uint8_t sound_u8, MySoundParam *panel);
    ~SoundLoopPanelImpl();

    void updateGUI(void);

    void transferStarted(void);
    void transferEnded(void);

    void activateSound(uint8_t sound_u8);

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

    void setUpdateLoopParamsActive(bool flag) { m_update_loop_params_active = flag; };

    wxToggleButton *getPlayButton(void);

    void updateWaveView(void);

    uint16_t getWaveSelection(void) const;

    void resetWaveViewZoom(void);

private:
   MyPanel *m_topframe;
   uint8_t m_sound_u8;
   Proph2000 *m_proph;
   MySoundParam *m_panel;
   uint32_t m_old_start_point;
   uint32_t m_old_end_point;
   uint32_t m_old_sustainloop_start;
   uint32_t m_old_sustainloop_end;
   uint32_t m_old_releaseloop_start;
   uint32_t m_old_releaseloop_end;
   bool m_update_loop_params_active;
   bool m_update_gui_inhibit;


   void OnSliderChange(wxScrollEvent &event);
   void OnCheckboxChange(wxCommandEvent& event);
   void OnSustLoopChange(wxCommandEvent& event);
   void OnForwardLoopChange(wxCommandEvent& event);
   void OnWaveSelection(wxCommandEvent& event);

   void OnStartPoint(wxSpinEvent &event);
   void OnEndPoint(wxSpinEvent &event);

   void OnSustainLoopStart(wxSpinEvent &event);
   void OnSustainLoopEnd(wxSpinEvent &event);

   void OnReleaseLoopStart(wxSpinEvent &event);
   void OnReleaseLoopEnd(wxSpinEvent &event);

   void updateLoopParameters(void);

   void OnMoveStartPointForward1(wxCommandEvent& event);
   void OnMoveStartPointForward10(wxCommandEvent& event);
   void moveStartPointForward(void);
   void OnMoveStartPointBackward1(wxCommandEvent& event);
   void OnMoveStartPointBackward10(wxCommandEvent& event);
   void moveStartPointBackward(void);

   void OnMoveEndPointBackward1(wxCommandEvent& event);
   void OnMoveEndPointBackward10(wxCommandEvent& event);
   void moveEndPointBackward(void);
   void OnMoveEndPointForward1(wxCommandEvent& event);
   void OnMoveEndPointForward10(wxCommandEvent& event);
   void moveEndPointForward(void);

   void OnMoveSustainStartPointForward1(wxCommandEvent& event);
   void OnMoveSustainStartPointForward10(wxCommandEvent& event);
   void moveSustainStartPointForward(void);
   void OnMoveSustainStartPointBackward1(wxCommandEvent& event);
   void OnMoveSustainStartPointBackward10(wxCommandEvent& event);
   void moveSustainStartPointBackward(void);

   void OnMoveSustainEndPointForward1(wxCommandEvent& event);
   void OnMoveSustainEndPointForward10(wxCommandEvent& event);
   void moveSustainEndPointForward(void);
   void OnMoveSustainEndPointBackward1(wxCommandEvent& event);
   void OnMoveSustainEndPointBackward10(wxCommandEvent& event);
   void moveSustainEndPointBackward(void);

   void OnMoveReleaseStartPointForward1(wxCommandEvent& event);
   void OnMoveReleaseStartPointForward10(wxCommandEvent& event);
   void moveReleaseStartPointForward(void);
   void OnMoveReleaseStartPointBackward1(wxCommandEvent& event);
   void OnMoveReleaseStartPointBackward10(wxCommandEvent& event);
   void moveReleaseStartPointBackward(void);

   void OnMoveReleaseEndPointForward1(wxCommandEvent& event);
   void OnMoveReleaseEndPointForward10(wxCommandEvent& event);
   void moveReleaseEndPointForward(void);
   void OnMoveReleaseEndPointBackward1(wxCommandEvent& event);
   void OnMoveReleaseEndPointBackward10(wxCommandEvent& event);
   void moveReleaseEndPointBackward(void);
};




#endif
