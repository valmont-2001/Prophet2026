#ifndef __SAMPLESH__
#define __SAMPLESH__

#define USE_PORT_AUDIO

class MyPanel;
class Proph2000;
class Wave;
class LoadSampleDlg;
class Audio;
class SamplesPanel;
class Logger;

class Samples : public SamplesPanel
{
public:
    Samples(wxWindow *parent, MyPanel *topframe, Proph2000 *proph, Audio *audio, Logger *log);
    ~Samples();

   void updateGUI(void);

private:
   Logger *m_log;
   MyPanel *m_topframe;
   Proph2000 *m_proph;
   LoadSampleDlg *m_load_smp_dlg;
   Audio *m_audio;
#ifndef USE_PORT_AUDIO
   Wave *m_play_wave;
#endif

   void OnLoad1(wxCommandEvent &event);
   void OnLoad2(wxCommandEvent &event);
   void OnLoad3(wxCommandEvent &event);
   void OnLoad4(wxCommandEvent &event);
   void OnLoad5(wxCommandEvent &event);
   void OnLoad6(wxCommandEvent &event);
   void OnLoad7(wxCommandEvent &event);
   void OnLoad8(wxCommandEvent &event);
   void OnLoad9(wxCommandEvent &event);
   void OnLoad10(wxCommandEvent &event);
   void OnLoad11(wxCommandEvent &event);
   void OnLoad12(wxCommandEvent &event);
   void OnLoad13(wxCommandEvent &event);
   void OnLoad14(wxCommandEvent &event);
   void OnLoad15(wxCommandEvent &event);
   void OnLoad16(wxCommandEvent &event);

   void OnSave1(wxCommandEvent &event);
   void OnSave2(wxCommandEvent &event);
   void OnSave3(wxCommandEvent &event);
   void OnSave4(wxCommandEvent &event);
   void OnSave5(wxCommandEvent &event);
   void OnSave6(wxCommandEvent &event);
   void OnSave7(wxCommandEvent &event);
   void OnSave8(wxCommandEvent &event);
   void OnSave9(wxCommandEvent &event);
   void OnSave10(wxCommandEvent &event);
   void OnSave11(wxCommandEvent &event);
   void OnSave12(wxCommandEvent &event);
   void OnSave13(wxCommandEvent &event);
   void OnSave14(wxCommandEvent &event);
   void OnSave15(wxCommandEvent &event);
   void OnSave16(wxCommandEvent &event);

   void OnDelete1(wxCommandEvent &event);
   void OnDelete2(wxCommandEvent &event);
   void OnDelete3(wxCommandEvent &event);
   void OnDelete4(wxCommandEvent &event);
   void OnDelete5(wxCommandEvent &event);
   void OnDelete6(wxCommandEvent &event);
   void OnDelete7(wxCommandEvent &event);
   void OnDelete8(wxCommandEvent &event);
   void OnDelete9(wxCommandEvent &event);
   void OnDelete10(wxCommandEvent &event);
   void OnDelete11(wxCommandEvent &event);
   void OnDelete12(wxCommandEvent &event);
   void OnDelete13(wxCommandEvent &event);
   void OnDelete14(wxCommandEvent &event);
   void OnDelete15(wxCommandEvent &event);
   void OnDelete16(wxCommandEvent &event);


   void OnSaveAll(wxCommandEvent &event);

   void OnPlay1(wxCommandEvent &event);
   void OnPlay2(wxCommandEvent &event);
   void OnPlay3(wxCommandEvent &event);
   void OnPlay4(wxCommandEvent &event);
   void OnPlay5(wxCommandEvent &event);
   void OnPlay6(wxCommandEvent &event);
   void OnPlay7(wxCommandEvent &event);
   void OnPlay8(wxCommandEvent &event);
   void OnPlay9(wxCommandEvent &event);
   void OnPlay10(wxCommandEvent &event);
   void OnPlay11(wxCommandEvent &event);
   void OnPlay12(wxCommandEvent &event);
   void OnPlay13(wxCommandEvent &event);
   void OnPlay14(wxCommandEvent &event);
   void OnPlay15(wxCommandEvent &event);
   void OnPlay16(wxCommandEvent &event);


   void OnNameChange1(wxCommandEvent& event);
   void OnNameChange2(wxCommandEvent& event);
   void OnNameChange3(wxCommandEvent& event);
   void OnNameChange4(wxCommandEvent& event);
   void OnNameChange5(wxCommandEvent& event);
   void OnNameChange6(wxCommandEvent& event);
   void OnNameChange7(wxCommandEvent& event);
   void OnNameChange8(wxCommandEvent& event);
   void OnNameChange9(wxCommandEvent& event);
   void OnNameChange10(wxCommandEvent& event);
   void OnNameChange11(wxCommandEvent& event);
   void OnNameChange12(wxCommandEvent& event);
   void OnNameChange13(wxCommandEvent& event);
   void OnNameChange14(wxCommandEvent& event);
   void OnNameChange15(wxCommandEvent& event);
   void OnNameChange16(wxCommandEvent& event);

   void play(uint8_t sound);
   void load(uint8_t sound);
   void save(uint8_t sound);
   void deleteSound(uint8_t sound);

   wxString getSampleRateText(uint8_t sound);

   void setSampleName(wxTextCtrl *ctrl, uint8_t sample_id);

};


#endif
