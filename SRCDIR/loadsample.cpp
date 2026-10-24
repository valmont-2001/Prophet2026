#include "types.h"


#include <wx/wx.h>
#include <wx/string.h>
#include <wx/file.h>
#include <wx/spinctrl.h>
#include "GUILayout.h"
#include "wave.h"
#include "loadsample.h"
#include "main.h"
#include "stopwatch.h"
#include "proph2000.h"
#include "wavedisp.h"
#include "audio.h"
#include "soundfontsample.h"
#include "soundfont.h"
#include "logger.h"

#define ZERO_CROSSING_RANGE_DELTA 10


extern "C" 
{
   #include "samplerate.h"
};


LoadSampleDlg::LoadSampleDlg(wxWindow* parent, const wxPoint& pos, int w, int h, MyPanel *topframe, Proph2000 *proph, Audio *audio,
                             Logger *log) :
   LoadSampleDialog(parent),
   m_topframe(topframe), m_proph(proph), m_sample_id(0), m_sample_words(0), m_sample_rate(0),
   m_play_wave(NULL), m_sample_data_orig_l_au16(NULL), m_sample_data_orig_r_au16(NULL), m_sample_words_orig(0), m_sample_rate_orig(0), m_old_start_point(0), m_old_end_point(0),
   m_audio(audio), m_loop_start(0), m_loop_end(2), m_root_key(255), m_log(log)
{
   m_sample_data_l_au16 = new(uint16_t[MAX_SAMPLE_WORDS_PER_MEMORY]);
   m_sample_data_r_au16 = new(uint16_t[MAX_SAMPLE_WORDS_PER_MEMORY]);
   m_wave_disp->setSampleData(m_sample_data_l_au16);
   m_soundfont = new SoundFont();

   m_src_channel->Disable();
   m_selected_sound->Disable();
   m_rootkey_txt->Disable();
}


LoadSampleDlg::~LoadSampleDlg()
{
   delete m_soundfont;
   delete m_sample_data_l_au16;
   delete m_sample_data_r_au16;
   if(m_play_wave)
   {
      delete m_play_wave;
   }
   if(m_sample_data_orig_l_au16)
   {
      delete m_sample_data_orig_l_au16;
   }
   if(m_sample_data_orig_r_au16)
   {
      delete m_sample_data_orig_r_au16;
   }
}

void LoadSampleDlg::wavMode(void)
{
   if(m_proph->getStereoMode())
   {
      m_src_channel->Disable();
   }
   else
   {
      m_src_channel->Enable();
   }
   m_selected_sound->Disable();
   m_rootkey_txt->Disable();
   m_root_key = 255;
}

void LoadSampleDlg::soundFontMode(void)
{
   m_src_channel->Disable();
   m_selected_sound->Enable();
   m_rootkey_txt->Enable();
}



void LoadSampleDlg::show(uint8_t sample_id)
{
   //loadSoundFont("ElPiano1.sf2");
   wxString title;
   m_sample_id = sample_id;
   title.sprintf(wxT("Import Sample %d"), sample_id + 1);
   SetTitle(title);
   if(m_proph->getStereoMode())
   {
      m_src_channel->Hide();
   }
   else
   {
      m_src_channel->Show();
   }
   ShowModal();
}


void LoadSampleDlg::OnLoad(wxCommandEvent &event)
{
   wxString wildcards =
                 wxString::Format
                 (
                     wxT("Wav/SoundFont files (*.wav;*.sf2)|*.wav;*.sf2"),
                     wxFileSelectorDefaultWildcardStr,
                     wxFileSelectorDefaultWildcardStr
                 );

   wxFileDialog indialog(this, wxT("Load sound file"),
                     wxEmptyString, wxEmptyString, wildcards,
                     wxFD_OPEN);

   if (indialog.ShowModal() == wxID_OK)
   {
      m_wave_filename = indialog.GetPath();
      wxString s = m_wave_filename;
      s.LowerCase();
      if(s.find(wxT(".wav")) != wxString::npos)
      {
         m_samplename = indialog.GetFilename();
         loadWave(m_wave_filename);
         wavMode();
      }
      else
      {
         loadSoundFont(m_wave_filename);
         soundFontMode();
      }
      m_wave_disp->resetZoom();
      m_wave_disp->Refresh(true);
      m_old_end_point = m_sample_words;
   }
}


void LoadSampleDlg::loadSoundFont(const wxString &filename)
{
   m_soundfont->load(filename.mb_str());

   list<SoundFontSample>::const_iterator myItr = m_soundfont->getSampleList().begin();
   m_selected_sound->Clear();
   while(myItr != m_soundfont->getSampleList().end())
   {
      m_selected_sound->AppendString((*myItr).getName());
      ++myItr;
   }

   m_selected_sound->SetSelection(0);

   if(m_soundfont->getSampleList().size())
   {
      makeSoundFontActive(0);
   }
}


void LoadSampleDlg::OnSoundChange(wxCommandEvent &event)
{
   makeSoundFontActive(m_selected_sound->GetSelection());
}

void LoadSampleDlg::makeSoundFontActive(uint8_t sound)
{
   uint32_t i;
   list<SoundFontSample>::const_iterator myItr = m_soundfont->getSampleList().begin();
   for(i = 0; i < sound; i++)
   {
      ++myItr;
   }

   m_sample_words_orig = (*myItr).getLength();
   m_sample_rate_orig = (*myItr).getSampleRate();

   if(m_sample_words_orig > MAX_SAMPLE_WORDS_PER_MEMORY)
   {
      m_sample_words_orig = MAX_SAMPLE_WORDS_PER_MEMORY;
   }

   if(m_sample_words_orig)
   {
      if(m_sample_data_orig_l_au16)
      {
         delete m_sample_data_orig_l_au16;
      }

      m_sample_data_orig_l_au16 = new(uint16_t[m_sample_words_orig]);
      for(i = 0; i < m_sample_words_orig; i++)
      {
         m_sample_data_orig_l_au16[i] = (uint16_t)(*myItr).getSampleData()[i];
      }

      if(m_proph->getStereoMode())
      {
         // sound fonts currently only imported in mono!
         if(m_sample_data_orig_r_au16)
         {
            delete m_sample_data_orig_r_au16;
         }

         m_sample_data_orig_r_au16 = new(uint16_t[m_sample_words_orig]);
         for(i = 0; i < m_sample_words_orig; i++)
         {
            m_sample_data_orig_r_au16[i] = (uint16_t)(*myItr).getSampleData()[i];
         }
      }
   }

   m_loop_start = (*myItr).getLoopStart();
   m_loop_end = (*myItr).getLoopEnd();
   m_root_key = (*myItr).getRootKey() + 12;

   if(m_root_key != 255)
   {
      m_rootkey_txt->SetValue(getNote(m_root_key));
   }
   else
   {
      m_rootkey_txt->SetValue("");
   }

   m_samplename = (*myItr).getName();

   convertSampleRate(m_sample_data_orig_l_au16, m_sample_data_l_au16);
}


wxString LoadSampleDlg::getNote(uint8_t number_u8)
{
   wxString retval;
   wxString t;

   switch(number_u8 % 12)
   {
      case 0:
         retval = wxT("C");
         break;
      case 1:
         retval = wxT("C#");
         break;
      case 2:
         retval = wxT("D");
         break;
      case 3:
         retval = wxT("D#");
         break;
      case 4:
         retval = wxT("E");
         break;
      case 5:
         retval = wxT("F");
         break;
      case 6:
         retval = wxT("F#");
         break;
      case 7:
         retval = wxT("G");
         break;
      case 8:
         retval = wxT("G#");
         break;
      case 9:
         retval = wxT("A");
         break;
      case 10:
         retval = wxT("A#");
         break;
      case 11:
         retval = wxT("B");
         break;
   }

   t.sprintf(wxT("%d"), (number_u8 - 24) / 12);
   retval += t;

   return retval;
}

void LoadSampleDlg::loadWave(const wxString &filename)
{
   Wave myWave(m_log);
   Wave::channel_mode_te channel_mode_e;

   if(m_proph->getStereoMode())
   {
      channel_mode_e = Wave::WAVE_LEFT;
   }
   else
   {
      switch(m_src_channel->GetSelection())
      {
         case 0:
            channel_mode_e = Wave::WAVE_BOTH;
            break;
         case 1:
            channel_mode_e = Wave::WAVE_LEFT;
            break;
         case 2:
            channel_mode_e = Wave::WAVE_RIGHT;
            break;
         default:
            channel_mode_e = Wave::WAVE_BOTH;
            break;
      }
   }

   if(myWave.load(filename.mb_str(), channel_mode_e))
   {
      uint32_t i;

      m_sample_words_orig = myWave.getSampleWords();
      m_sample_rate_orig = myWave.getSampleRate();
      m_loop_type = myWave.getLoopMode();

      if(m_sample_words_orig > MAX_SAMPLE_WORDS_PER_MEMORY)
      {
         m_sample_words_orig = MAX_SAMPLE_WORDS_PER_MEMORY;
      }

      if(m_sample_words_orig)
      {
         if(m_sample_data_orig_l_au16)
         {
            delete m_sample_data_orig_l_au16;
         }

         m_sample_data_orig_l_au16 = new(uint16_t[m_sample_words_orig]);
         for(i = 0; i < m_sample_words_orig; i++)
         {
            m_sample_data_orig_l_au16[i] = (uint16_t)myWave.getSampleData()[i];
         }
      }

      m_loop_start = myWave.getLoopStart();
      m_loop_end = myWave.getLoopEnd();

      convertSampleRate(m_sample_data_orig_l_au16, m_sample_data_l_au16);

      if(m_proph->getStereoMode())
      {
         if(myWave.load(filename.mb_str(), Wave::WAVE_RIGHT))
         {
            if(m_sample_words_orig)
            {
               if(m_sample_data_orig_r_au16)
               {
                  delete m_sample_data_orig_r_au16;
               }

               m_sample_data_orig_r_au16 = new(uint16_t[m_sample_words_orig]);
               for(i = 0; i < m_sample_words_orig; i++)
               {
                  m_sample_data_orig_r_au16[i] = (uint16_t)myWave.getSampleData()[i];
               }
            }
         }
         convertSampleRate(m_sample_data_orig_r_au16, m_sample_data_r_au16);
      }
   }
   else
   {
      m_wave_filename = wxT("");
   }
}


void LoadSampleDlg::OnPlay(wxCommandEvent &event)
{
   if(m_sample_words)
   {
      if(m_proph->getStereoMode())
      {
         m_audio->setStereoAudioData(m_sample_data_l_au16 + (m_start_point->GetValue() * 2), m_sample_data_r_au16 + (m_start_point->GetValue() * 2), (m_end_point->GetValue() - m_start_point->GetValue()));
      }
      else
      {
         m_audio->setAudioData(m_sample_data_l_au16 + (m_start_point->GetValue() * 2), (m_end_point->GetValue() - m_start_point->GetValue()));
      }

      m_audio->play(false, m_sample_rate);
      //PlaySound((LPCSTR)m_play_wave->getResourceData(), NULL, SND_MEMORY);
   }
}


void LoadSampleDlg::normalize(void)
{
   uint32_t i;
   int16_t t;
   int16_t min;
   int16_t max;
   float scale;
   
   min = 0;
   max = 0;

   for(i = 0; i < (m_sample_words - 4); i++)
   {
      t = m_sample_data_l_au16[i] - (4096 / 2);
      if(t < min)
      {
         min = t;
      }
      if(t > max)
      {
         max = t;
      }
      if(m_proph->getStereoMode())
      {
         t = m_sample_data_r_au16[i] - (4096 / 2);
         if(t < min)
         {
            min = t;
         }
         if(t > max)
         {
            max = t;
         }
      }
   }

   //wxLogMessage("min:%d max:%d", min, max);
   min = -min;
   if(min > max)
   {
      max = min;
   }
   if(max)
   {
      scale = ((float)4095 / 2) / (float)max;
      //wxLogMessage("normalize scale: %f", scale);
      for(i = 0; i < m_sample_words; i++)
      {
         t = m_sample_data_l_au16[i] - (4096 / 2);
         t = t * scale;
         m_sample_data_l_au16[i] = t + (4096 / 2);
         if(m_proph->getStereoMode())
         {
            t = m_sample_data_r_au16[i] - (4096 / 2);
            t = t * scale;
            m_sample_data_r_au16[i] = t + (4096 / 2);
         }
      }
   }
}


void LoadSampleDlg::convertSampleRate(uint16_t *sample_data_orig_pau16, uint16_t *sample_dest_data_pau16)
{
   uint32_t i;
   float *indata;
   float *outdata;
   wxString str;

   if(m_sample_words_orig)
   {
      SRC_DATA src;

      switch(m_dest_sample_rate->GetSelection())
      {
         case 0:
            m_sample_rate = 15625;
            break;
         case 1:
            m_sample_rate = 31250;
            break;
         case 2:
            m_sample_rate = 41667;
            break;
         default:
            m_sample_rate = 41667;
            break;
      }

      str.sprintf(wxT("%d Hz"), m_sample_rate_orig);
      m_sample_rate_orig_txt->SetValue(str);

      m_loop_out_start = m_loop_start;
      m_loop_out_end = m_loop_end;

      if(m_sample_rate != m_sample_rate_orig)
      {
         double ratio = (double)m_sample_rate / (double)m_sample_rate_orig;

         m_loop_out_start = (uint32_t)((double)m_loop_out_start * ratio);
         m_loop_out_end = (uint32_t)((double)m_loop_out_end * ratio);

         indata = new(float[m_sample_words_orig]);
         outdata = new(float[MAX_SAMPLE_WORDS_PER_MEMORY]);

         src_short_to_float_array((const short *)sample_data_orig_pau16, indata, m_sample_words_orig);

         src.data_in = indata;
         src.data_out = outdata;
         src.input_frames = m_sample_words_orig;
         src.output_frames = MAX_SAMPLE_WORDS_PER_MEMORY;
         src.src_ratio = (float)m_sample_rate / (float)m_sample_rate_orig;

         src_simple(&src, SRC_SINC_BEST_QUALITY, 1);

         m_sample_words = src.output_frames_gen;

         if(m_sample_words >= MAX_SAMPLE_WORDS_PER_MEMORY)
         {
            m_sample_words = (MAX_SAMPLE_WORDS_PER_MEMORY - 1);
         }

         src_float_to_short_array(outdata, (short *)sample_dest_data_pau16, m_sample_words);

         delete outdata;
         delete indata;
      }
      else
      {
         m_sample_words = m_sample_words_orig;

         if(m_sample_words >= MAX_SAMPLE_WORDS_PER_MEMORY)
         {
            m_sample_words = (MAX_SAMPLE_WORDS_PER_MEMORY - 1);
         }

         for(i = 0; i < m_sample_words; i++)
         {
            sample_dest_data_pau16[i] = (uint16_t)sample_data_orig_pau16[i];
         }
      }
      m_start_point->SetRange(0, m_sample_words);
      m_end_point->SetRange(0, m_sample_words);
      m_start_point->SetValue(0);
      m_end_point->SetValue(m_sample_words);

      str.sprintf(wxT("%d"), m_end_point->GetValue() - m_start_point->GetValue());
      m_sample_words_txt->SetValue(str);

      normalize();

      m_wave_disp->setSampleWords(m_sample_words);

      m_wave_disp->setStartPoint(m_start_point->GetValue());
      m_wave_disp->setEndPoint(m_end_point->GetValue());
      m_wave_disp->Refresh(true);
   }
}


void LoadSampleDlg::OnImport(wxCommandEvent &event)
{
   if(m_proph->getStereoMode())
   {
      if(m_sample_id < 8)
      {
         importSampleToSlot(m_sample_id, m_sample_data_l_au16);
         importSampleToSlot(m_sample_id + 8, m_sample_data_r_au16);
      }
      else
      {
         importSampleToSlot(m_sample_id - 8, m_sample_data_l_au16);
         importSampleToSlot(m_sample_id, m_sample_data_r_au16);
      }
   }
   else
   {
      importSampleToSlot(m_sample_id, m_sample_data_l_au16);
   }
   
   Close();
}


void LoadSampleDlg::importSampleToSlot(uint8_t sample_id, uint16_t *sample_data_pau16)
{

   int16_t min;
   int16_t max;

   min = 0;
   max = 0;
   uint32_t words;

   words = (m_end_point->GetValue() - m_start_point->GetValue());

   if(words > 0)
   {
      if(m_root_key != 255)
      {
         m_proph->m_sound_param_as[sample_id].val_s.root_key = m_root_key;
         m_proph->updateParamBytesFromStruct();
      }

      m_proph->setSampleName(m_samplename.char_str(), sample_id);

      m_proph->setSampleData(sample_id, sample_data_pau16 + (m_start_point->GetValue() * 2), words, m_sample_rate);

      m_proph->setReleaseLoopStart(sample_id, m_loop_out_start);
      m_proph->setReleaseLoopEnd(sample_id, m_loop_out_end);

      switch(m_loop_type)
      {
         case Wave::LOOP_BF:
            m_proph->setReleaseLoopActive(sample_id, true);
            m_proph->setReverseActive(sample_id, false);
            m_proph->setBfLoopActive(sample_id, true);
            break;
         case Wave::LOOP_NORMAL:
            m_proph->setReleaseLoopActive(sample_id, true);
            m_proph->setReverseActive(sample_id, false);
            m_proph->setBfLoopActive(sample_id, false);
            break;
         case Wave::LOOP_REVERSE:
            m_proph->setReleaseLoopActive(sample_id, true);
            m_proph->setReverseActive(sample_id, true);
            m_proph->setBfLoopActive(sample_id, false);
            break;
         case Wave::LOOP_UNDEF:
            break;
         default:
            break;
      }

   }
}


void LoadSampleDlg::OnCancel(wxCommandEvent &event)
{
   Close();
}


void LoadSampleDlg::OnDestSampleRate(wxCommandEvent &event)
{
   convertSampleRate(m_sample_data_orig_l_au16, m_sample_data_l_au16);
   if(m_proph->getStereoMode())
   {
      convertSampleRate(m_sample_data_orig_r_au16, m_sample_data_r_au16);
   }
}


void LoadSampleDlg::OnChannelSelect(wxCommandEvent &event)
{
   if(m_wave_filename != "")
   {
      loadWave(m_wave_filename);
      m_wave_disp->Refresh(true);
   }
}


void LoadSampleDlg::OnStartPoint(wxSpinEvent &event)
{
   wxString str;

   if( (((int32_t)m_old_start_point - (int32_t)m_start_point->GetValue()) <= 10) && (((int32_t)m_old_start_point - (int32_t)m_start_point->GetValue()) >= -10))
   {
      uint32_t t = m_start_point->GetValue();

      if(((int32_t)m_old_start_point - (int32_t)m_start_point->GetValue()) < 0)
      {
         while(((m_sample_data_l_au16[t] >= ((4096 / 2) + ZERO_CROSSING_RANGE_DELTA)) || (m_sample_data_l_au16[t] <= ((4096 / 2) - ZERO_CROSSING_RANGE_DELTA)))  && ((int32_t)t < (m_end_point->GetValue() - 1)))
         {
            t++;
         }
      }
      else
      {
         while(((m_sample_data_l_au16[t] >= ((4096 / 2) + ZERO_CROSSING_RANGE_DELTA)) || (m_sample_data_l_au16[t] <= ((4096 / 2) - ZERO_CROSSING_RANGE_DELTA)))  && (t > 0))
         {
            t--;
         }
      }

      m_start_point->SetValue(t);
   }

   if(m_start_point->GetValue() >= m_end_point->GetValue())
   {
      m_start_point->SetValue(m_end_point->GetValue() - 1);
   }

   //m_end_point->SetMin(m_start_point->GetValue() + 1);

   str.sprintf(wxT("%d"), m_end_point->GetValue() - m_start_point->GetValue());
   m_sample_words_txt->SetValue(str);

   m_wave_disp->setStartPoint(m_start_point->GetValue());

   m_wave_disp->Refresh(true);

   m_old_start_point = m_start_point->GetValue();
}


void LoadSampleDlg::OnEndPoint(wxSpinEvent &event)
{
   wxString str;

   if( (((int32_t)m_old_end_point - (int32_t)m_end_point->GetValue()) <= 10) && (((int32_t)m_old_end_point - (int32_t)m_end_point->GetValue()) >= -10))
   {
      uint32_t t = m_end_point->GetValue() - 1;

      if(((int32_t)m_old_end_point - (int32_t)m_end_point->GetValue()) < 0)
      {
         while(((m_sample_data_l_au16[t] >= ((4096 / 2) + ZERO_CROSSING_RANGE_DELTA)) || (m_sample_data_l_au16[t] <= ((4096 / 2) - ZERO_CROSSING_RANGE_DELTA)))  && (t < (m_sample_words - 1)))
         {
            t++;
         }
      }
      else
      {
         while(((m_sample_data_l_au16[t] >= ((4096 / 2) + ZERO_CROSSING_RANGE_DELTA)) || (m_sample_data_l_au16[t] <= ((4096 / 2) - ZERO_CROSSING_RANGE_DELTA)))  && ((int32_t)t > (m_start_point->GetValue() + 1)))
         {
            t--;
         }
      }

      m_end_point->SetValue(t);
   }

   if(m_end_point->GetValue() <= m_start_point->GetValue())
   {
      m_end_point->SetValue(m_start_point->GetValue() + 1);
   }

   //m_start_point->SetMax(m_end_point->GetValue() - 1);

   str.sprintf(wxT("%d"), m_end_point->GetValue() - m_start_point->GetValue());
   m_sample_words_txt->SetValue(str);
   
   m_wave_disp->setEndPoint(m_end_point->GetValue());

   m_wave_disp->Refresh(true);

   m_old_end_point = m_end_point->GetValue();
}

