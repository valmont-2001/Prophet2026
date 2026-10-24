#ifndef __LOADSAMPLEH__
#define __LOADSAMPLEH__

class MyPanel;
class Proph2000;
class Wave;
class WaveDisp;
class Audio;
class LoadSampleDialog;
class SoundFont;
class Logger;

class LoadSampleDlg : public LoadSampleDialog
{
public:
    LoadSampleDlg(wxWindow* parent, const wxPoint& pos, int w, int h, MyPanel *topframe, Proph2000 *proph, Audio *audio, Logger *log);
    ~LoadSampleDlg();

   void show(uint8_t sample_id);

private:
   Logger *m_log;
   MyPanel *m_topframe;
   Proph2000 *m_proph;
   Wave *m_play_wave;
   Audio *m_audio;
   uint8_t m_sample_id;
   uint16_t *m_sample_data_l_au16;
   uint16_t *m_sample_data_r_au16;
   uint16_t *m_sample_data_orig_l_au16;
   uint16_t *m_sample_data_orig_r_au16;
   uint32_t m_sample_words_orig;
   uint32_t m_sample_words;
   uint32_t m_sample_rate;
   uint32_t m_sample_rate_orig;
   uint32_t m_loop_start;
   uint32_t m_loop_end;
   uint32_t m_loop_out_start;
   uint32_t m_loop_out_end;
   Wave::loop_mode_te m_loop_type;
   wxString m_wave_filename;
   uint32_t m_old_start_point;
   uint32_t m_old_end_point;
   uint8_t m_root_key;
   SoundFont *m_soundfont;
   wxString m_samplename;

   void OnLoad(wxCommandEvent &event);
   void OnPlay(wxCommandEvent &event);
   void OnImport(wxCommandEvent &event);
   void OnCancel(wxCommandEvent &event);
   void OnSoundChange(wxCommandEvent &event);
   void OnDestSampleRate(wxCommandEvent &event);
   void OnChannelSelect(wxCommandEvent &event);
   void OnStartPoint(wxSpinEvent &event);
   void OnEndPoint(wxSpinEvent &event);

   void makeSoundFontActive(uint8_t sound);

   void importSampleToSlot(uint8_t sample_id, uint16_t *sample_data_pau16);

   void wavMode(void);
   void soundFontMode(void);

   wxString getNote(uint8_t number_u8);


   void convertSampleRate(uint16_t *sample_data_orig_pau16, uint16_t *sample_dest_data_pau16);

   void normalize(void);

   void loadWave(const wxString &filename);
   void loadSoundFont(const wxString &filename);

};


#endif
