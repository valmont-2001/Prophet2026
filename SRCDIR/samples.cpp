#include "types.h"


#include <wx/wx.h>
#include <wx/string.h>
#include <wx/file.h>
#include <wx/spinctrl.h>

#include "GUILayout.h"
#include "samples.h"
#include "main.h"
#include "stopwatch.h"
#include "proph2000.h"
#include "wave.h"
#include "loadsample.h"
#include "audio.h"
#include "logger.h"


Samples::Samples(wxWindow *parent, MyPanel *topframe, Proph2000 *proph, Audio *audio, Logger *log) :
   SamplesPanel(parent),
   m_topframe(topframe), m_proph(proph), m_audio(audio), m_log(log)
{
//   uint8_t i;

#ifndef USE_PORT_AUDIO
   m_play_wave = NULL;
#endif
    
#ifdef __WXMAC__
    m_staticText1110->SetLabel("Bank A");
    m_staticText11101->SetLabel("Bank B");
#endif

   //updateGUI();

   m_load_smp_dlg = new LoadSampleDlg(this, wxDefaultPosition, 600, 500, m_topframe, m_proph, m_audio, m_log);

}


Samples::~Samples()
{
#ifndef USE_PORT_AUDIO
   if(m_play_wave)
   {
      delete m_play_wave;
   }
#endif
   delete m_load_smp_dlg;
}

void Samples::updateGUI(void)
{
   uint8_t i;
   wxString str;
   uint32_t t_u32;

   if(m_proph->getSampleName(0)[0] != 0)
   {
      m_sample_name1->SetValue(m_proph->getSampleName(0));
   }
   else
   {
      m_sample_name1->SetValue("");
   }

   if(m_proph->getSampleName(1)[0] != 0)
   {
      m_sample_name2->SetValue(m_proph->getSampleName(1));
   }
   else
   {
      m_sample_name2->SetValue("");
   }

   if(m_proph->getSampleName(2)[0] != 0)
   {
      m_sample_name3->SetValue(m_proph->getSampleName(2));
   }
   else
   {
      m_sample_name3->SetValue("");
   }

   if(m_proph->getSampleName(3)[0] != 0)
   {
      m_sample_name4->SetValue(m_proph->getSampleName(3));
   }
   else
   {
      m_sample_name4->SetValue("");
   }

   if(m_proph->getSampleName(4)[0] != 0)
   {
      m_sample_name5->SetValue(m_proph->getSampleName(4));
   }
   else
   {
      m_sample_name5->SetValue("");
   }

   if(m_proph->getSampleName(5)[0] != 0)
   {
      m_sample_name6->SetValue(m_proph->getSampleName(5));
   }
   else
   {
      m_sample_name6->SetValue("");
   }

   if(m_proph->getSampleName(6)[0] != 0)
   {
      m_sample_name7->SetValue(m_proph->getSampleName(6));
   }
   else
   {
      m_sample_name7->SetValue("");
   }

   if(m_proph->getSampleName(7)[0] != 0)
   {
      m_sample_name8->SetValue(m_proph->getSampleName(7));
   }
   else
   {
      m_sample_name8->SetValue("");
   }

   if(m_proph->getSampleName(8)[0] != 0)
   {
      m_sample_name9->SetValue(m_proph->getSampleName(8));
   }
   else
   {
      m_sample_name9->SetValue("");
   }

   if(m_proph->getSampleName(9)[0] != 0)
   {
      m_sample_name10->SetValue(m_proph->getSampleName(9));
   }
   else
   {
      m_sample_name10->SetValue("");
   }

   if(m_proph->getSampleName(10)[0] != 0)
   {
      m_sample_name11->SetValue(m_proph->getSampleName(10));
   }
   else
   {
      m_sample_name11->SetValue("");
   }

   if(m_proph->getSampleName(11)[0] != 0)
   {
      m_sample_name12->SetValue(m_proph->getSampleName(11));
   }
   else
   {
      m_sample_name12->SetValue("");
   }

   if(m_proph->getSampleName(12)[0] != 0)
   {
      m_sample_name13->SetValue(m_proph->getSampleName(12));
   }
   else
   {
      m_sample_name13->SetValue("");
   }

   if(m_proph->getSampleName(13)[0] != 0)
   {
      m_sample_name14->SetValue(m_proph->getSampleName(13));
   }
   else
   {
      m_sample_name14->SetValue("");
   }

   if(m_proph->getSampleName(14)[0] != 0)
   {
      m_sample_name15->SetValue(m_proph->getSampleName(14));
   }
   else
   {
      m_sample_name15->SetValue("");
   }

   if(m_proph->getSampleName(15)[0] != 0)
   {
      m_sample_name16->SetValue(m_proph->getSampleName(15));
   }
   else
   {
      m_sample_name16->SetValue("");
   }

   if(m_proph->getSampleWords(0) == 0)
   {
      m_sample_name1->Disable();
   }
   else
   {
      m_sample_name1->Enable();
   }

   if(m_proph->getSampleWords(1) == 0)
   {
      m_sample_name2->Disable();
   }
   else
   {
      m_sample_name2->Enable();
   }

   if(m_proph->getSampleWords(2) == 0)
   {
      m_sample_name3->Disable();
   }
   else
   {
      m_sample_name3->Enable();
   }

   if(m_proph->getSampleWords(3) == 0)
   {
      m_sample_name4->Disable();
   }
   else
   {
      m_sample_name4->Enable();
   }

   if(m_proph->getSampleWords(4) == 0)
   {
      m_sample_name5->Disable();
   }
   else
   {
      m_sample_name5->Enable();
   }

   if(m_proph->getSampleWords(5) == 0)
   {
      m_sample_name6->Disable();
   }
   else
   {
      m_sample_name6->Enable();
   }

   if(m_proph->getSampleWords(6) == 0)
   {
      m_sample_name7->Disable();
   }
   else
   {
      m_sample_name7->Enable();
   }

   if(m_proph->getSampleWords(7) == 0)
   {
      m_sample_name8->Disable();
   }
   else
   {
      m_sample_name8->Enable();
   }

   if(m_proph->getSampleWords(8) == 0)
   {
      m_sample_name9->Disable();
   }
   else
   {
      m_sample_name9->Enable();
   }

   if(m_proph->getSampleWords(9) == 0)
   {
      m_sample_name10->Disable();
   }
   else
   {
      m_sample_name10->Enable();
   }

   if(m_proph->getSampleWords(10) == 0)
   {
      m_sample_name11->Disable();
   }
   else
   {
      m_sample_name11->Enable();
   }

   if(m_proph->getSampleWords(11) == 0)
   {
      m_sample_name12->Disable();
   }
   else
   {
      m_sample_name12->Enable();
   }

   if(m_proph->getSampleWords(12) == 0)
   {
      m_sample_name13->Disable();
   }
   else
   {
      m_sample_name13->Enable();
   }

   if(m_proph->getSampleWords(13) == 0)
   {
      m_sample_name14->Disable();
   }
   else
   {
      m_sample_name14->Enable();
   }

   if(m_proph->getSampleWords(14) == 0)
   {
      m_sample_name15->Disable();
   }
   else
   {
      m_sample_name15->Enable();
   }

   if(m_proph->getSampleWords(15) == 0)
   {
      m_sample_name16->Disable();
   }
   else
   {
      m_sample_name16->Enable();
   }

   str.sprintf(wxT("%d"), m_proph->getSampleWords(0));
   m_sample_words1->SetValue(str);

   str.sprintf(wxT("%d"), m_proph->getSampleWords(1));
   m_sample_words2->SetValue(str);

   str.sprintf(wxT("%d"), m_proph->getSampleWords(2));
   m_sample_words3->SetValue(str);

   str.sprintf(wxT("%d"), m_proph->getSampleWords(3));
   m_sample_words4->SetValue(str);

   str.sprintf(wxT("%d"), m_proph->getSampleWords(4));
   m_sample_words5->SetValue(str);

   str.sprintf(wxT("%d"), m_proph->getSampleWords(5));
   m_sample_words6->SetValue(str);

   str.sprintf(wxT("%d"), m_proph->getSampleWords(6));
   m_sample_words7->SetValue(str);

   str.sprintf(wxT("%d"), m_proph->getSampleWords(7));
   m_sample_words8->SetValue(str);

   str.sprintf(wxT("%d"), m_proph->getSampleWords(8));
   m_sample_words9->SetValue(str);

   str.sprintf(wxT("%d"), m_proph->getSampleWords(9));
   m_sample_words10->SetValue(str);

   str.sprintf(wxT("%d"), m_proph->getSampleWords(10));
   m_sample_words11->SetValue(str);

   str.sprintf(wxT("%d"), m_proph->getSampleWords(11));
   m_sample_words12->SetValue(str);

   str.sprintf(wxT("%d"), m_proph->getSampleWords(12));
   m_sample_words13->SetValue(str);

   str.sprintf(wxT("%d"), m_proph->getSampleWords(13));
   m_sample_words14->SetValue(str);

   str.sprintf(wxT("%d"), m_proph->getSampleWords(14));
   m_sample_words15->SetValue(str);

   str.sprintf(wxT("%d"), m_proph->getSampleWords(15));
   m_sample_words16->SetValue(str);

   m_sample_rate1->SetValue(getSampleRateText(0));
   m_sample_rate2->SetValue(getSampleRateText(1));
   m_sample_rate3->SetValue(getSampleRateText(2));
   m_sample_rate4->SetValue(getSampleRateText(3));
   m_sample_rate5->SetValue(getSampleRateText(4));
   m_sample_rate6->SetValue(getSampleRateText(5));
   m_sample_rate7->SetValue(getSampleRateText(6));
   m_sample_rate8->SetValue(getSampleRateText(7));
   m_sample_rate9->SetValue(getSampleRateText(8));
   m_sample_rate10->SetValue(getSampleRateText(9));
   m_sample_rate11->SetValue(getSampleRateText(10));
   m_sample_rate12->SetValue(getSampleRateText(11));
   m_sample_rate13->SetValue(getSampleRateText(12));
   m_sample_rate14->SetValue(getSampleRateText(13));
   m_sample_rate15->SetValue(getSampleRateText(14));
   m_sample_rate16->SetValue(getSampleRateText(15));

   t_u32 = 0;
   uint16_t percentage;
   bool overloaded = false;

   for(i = 0; i < 8; i++)
   {
      t_u32 += m_proph->getSampleWords(i);
   }
   if(m_proph->getExtendedMemory())
   {
      percentage = (uint16_t)((t_u32 * 100) / (MAX_SAMPLE_BANK_WORDS_EXTENDED - 1));
   }
   else
   {
      percentage = (uint16_t)((t_u32 * 100) / (MAX_SAMPLE_BANK_WORDS_UNEXTENDED - 1));
   }
   m_a_memory_usage->SetValue(percentage);
   if(percentage > 100)
   {
      m_a_memory_usage_txt->SetBackgroundColour(wxColour(255, 0, 0));
      overloaded = true;
   }
   else
   {
      m_a_memory_usage_txt->SetBackgroundColour(wxColour(255, 255, 255));
   }
   str.sprintf(wxT("%d%%"), percentage);
   m_a_memory_usage_txt->SetValue(str);

   t_u32 = 0;
   for(i = 8; i < 16; i++)
   {
      t_u32 += m_proph->getSampleWords(i);
   }
   if(m_proph->getExtendedMemory())
   {
      percentage = (uint16_t)((t_u32 * 100) / (MAX_SAMPLE_BANK_WORDS_EXTENDED - 1));
   }
   else
   {
      percentage = (uint16_t)((t_u32 * 100) / (MAX_SAMPLE_BANK_WORDS_UNEXTENDED - 1));
   }
   m_b_memory_usage->SetValue(percentage);
   if(percentage > 100)
   {
      m_b_memory_usage_txt->SetBackgroundColour(wxColour(255, 0, 0));
      overloaded = true;
   }
   else
   {
      m_b_memory_usage_txt->SetBackgroundColour(wxColour(255, 255, 255));
   }
   str.sprintf(wxT("%d%%"), percentage);
   m_b_memory_usage_txt->SetValue(str);

   m_topframe->enableTransfer2ProphetControls(!overloaded);
}

wxString Samples::getSampleRateText(uint8_t sound)
{
   wxString str;
   if(m_proph->getSampleWords(sound))
   {
      switch(m_proph->getSampleRate(sound))
      {
         case Proph2000::SR_15625HZ:
            str = wxT("15.625kHz");
            break;
         case Proph2000::SR_31250HZ:
            str = wxT("31.250kHz");
            break;
         case Proph2000::SR_41667HZ:
            str = wxT("41.667kHz");
            break;
         default:
            str = wxT("INVALID");
            break;
      }
   }
   else
   {
      str = wxT("");
   }

   return str;
}

void Samples::play(uint8_t sound)
{
   if(m_proph->getSampleWords(sound))
   {
      uint32_t samplerate;

#ifndef USE_PORT_AUDIO
      if(m_play_wave)
      {
         delete m_play_wave;
      }
#endif

      switch(m_proph->getSampleRate(sound))
      {
         case Proph2000::SR_15625HZ:
            samplerate = 15625;
            break;
         case Proph2000::SR_31250HZ:
            samplerate = 31250;
            break;
         case Proph2000::SR_41667HZ:
            samplerate = 41667;
            break;
         default:
            samplerate = 41667;
            break;
      }

#ifndef USE_PORT_AUDIO
      m_play_wave = new Wave(m_proph->getSampleData(sound), m_proph->getSampleWords(sound), samplerate);
      PlaySound((LPCSTR)m_play_wave->getResourceData(), NULL, SND_MEMORY);
#endif
#ifdef USE_PORT_AUDIO
      if(m_proph->getStereoMode())
      {
         if(sound < 8)
         {
            m_audio->setStereoAudioData(m_proph->getSampleData(sound), m_proph->getSampleData(sound + 8), m_proph->getSampleWords(sound));
         }
         else
         {
            m_audio->setStereoAudioData(m_proph->getSampleData(sound - 8), m_proph->getSampleData(sound), m_proph->getSampleWords(sound));
         }
      }
      else
      {
         m_audio->setAudioData(m_proph->getSampleData(sound), m_proph->getSampleWords(sound));
      }
      m_audio->play(false, samplerate);
#endif
   }
}

void Samples::OnPlay1(wxCommandEvent &event)
{
   play(0);
}

void Samples::OnPlay2(wxCommandEvent &event)
{
   play(1);
}

void Samples::OnPlay3(wxCommandEvent &event)
{
   play(2);
}

void Samples::OnPlay4(wxCommandEvent &event)
{
   play(3);
}

void Samples::OnPlay5(wxCommandEvent &event)
{
   play(4);
}

void Samples::OnPlay6(wxCommandEvent &event)
{
   play(5);
}

void Samples::OnPlay7(wxCommandEvent &event)
{
   play(6);
}

void Samples::OnPlay8(wxCommandEvent &event)
{
   play(7);
}

void Samples::OnPlay9(wxCommandEvent &event)
{
   play(8);
}

void Samples::OnPlay10(wxCommandEvent &event)
{
   play(9);
}

void Samples::OnPlay11(wxCommandEvent &event)
{
   play(10);
}

void Samples::OnPlay12(wxCommandEvent &event)
{
   play(11);
}

void Samples::OnPlay13(wxCommandEvent &event)
{
   play(12);
}

void Samples::OnPlay14(wxCommandEvent &event)
{
   play(13);
}

void Samples::OnPlay15(wxCommandEvent &event)
{
   play(14);
}

void Samples::OnPlay16(wxCommandEvent &event)
{
   play(15);
}

void Samples::load(uint8_t sound)
{
   m_load_smp_dlg->show(sound);
   updateGUI();
   m_topframe->resetWaveViewZoom();
   m_topframe->updateWaveView();
#ifdef __WXMAC__
    m_topframe->refreshNotebook();
#endif
}

void Samples::OnLoad1(wxCommandEvent &event)
{
   load(0);
}

void Samples::OnLoad2(wxCommandEvent &event)
{
   load(1);
}

void Samples::OnLoad3(wxCommandEvent &event)
{
   load(2);
}

void Samples::OnLoad4(wxCommandEvent &event)
{
   load(3);
}

void Samples::OnLoad5(wxCommandEvent &event)
{
   load(4);
}

void Samples::OnLoad6(wxCommandEvent &event)
{
   load(5);
}

void Samples::OnLoad7(wxCommandEvent &event)
{
   load(6);
}

void Samples::OnLoad8(wxCommandEvent &event)
{
   load(7);
}

void Samples::OnLoad9(wxCommandEvent &event)
{
   load(8);
}

void Samples::OnLoad10(wxCommandEvent &event)
{
   load(9);
}

void Samples::OnLoad11(wxCommandEvent &event)
{
   load(10);
}

void Samples::OnLoad12(wxCommandEvent &event)
{
   load(11);
}

void Samples::OnLoad13(wxCommandEvent &event)
{
   load(12);
}

void Samples::OnLoad14(wxCommandEvent &event)
{
   load(13);
}

void Samples::OnLoad15(wxCommandEvent &event)
{
   load(14);
}

void Samples::OnLoad16(wxCommandEvent &event)
{
   load(15);
}

void Samples::save(uint8_t sound)
{
   if(m_proph->getSampleWords(sound))
   {
      wxFileDialog outdialog(this,
                     wxT("Save wave file"),
                     wxEmptyString,
                     wxEmptyString,
                     wxT("Wave files (*.wav)|*.wav"),
                     wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
      if (outdialog.ShowModal() == wxID_OK)
      {
         wxString filen = outdialog.GetPath();
         if(filen.find(wxT(".wav")) == wxString::npos)
         {
            filen += wxT(".wav");
         }

         if(!m_proph->saveWave(sound, filen.mb_str()))
         {
            wxMessageDialog edialog(this, wxT("Could not save wave file"), wxT("Error"));
            edialog.ShowModal();
         }
      }
   }
}

void Samples::OnSave1(wxCommandEvent &event)
{
   save(0);
}

void Samples::OnSave2(wxCommandEvent &event)
{
   save(1);
}

void Samples::OnSave3(wxCommandEvent &event)
{
   save(2);
}

void Samples::OnSave4(wxCommandEvent &event)
{
   save(3);
}

void Samples::OnSave5(wxCommandEvent &event)
{
   save(4);
}

void Samples::OnSave6(wxCommandEvent &event)
{
   save(5);
}

void Samples::OnSave7(wxCommandEvent &event)
{
   save(6);
}

void Samples::OnSave8(wxCommandEvent &event)
{
   save(7);
}

void Samples::OnSave9(wxCommandEvent &event)
{
   save(8);
}

void Samples::OnSave10(wxCommandEvent &event)
{
   save(9);
}

void Samples::OnSave11(wxCommandEvent &event)
{
   save(10);
}

void Samples::OnSave12(wxCommandEvent &event)
{
   save(11);
}

void Samples::OnSave13(wxCommandEvent &event)
{
   save(12);
}

void Samples::OnSave14(wxCommandEvent &event)
{
   save(13);
}

void Samples::OnSave15(wxCommandEvent &event)
{
   save(14);
}

void Samples::OnSave16(wxCommandEvent &event)
{
   save(15);
}

void Samples::deleteSound(uint8_t sound)
{
   if(m_proph->getStereoMode())
   {
      if(sound < 8)
      {
         m_proph->setSampleName("", sound);
         m_proph->deleteSample(sound);
         m_proph->setSampleName("", sound + 8);
         m_proph->deleteSample(sound + 8);
      }
      else
      {
         m_proph->setSampleName("", sound - 8);
         m_proph->deleteSample(sound - 8);
         m_proph->setSampleName("", sound);
         m_proph->deleteSample(sound);
      }
   }
   else
   {
      m_proph->setSampleName("", sound);
      m_proph->deleteSample(sound);
   }
   updateGUI();
   m_topframe->resetWaveViewZoom();
   m_topframe->updateWaveView();
#ifdef __WXMAC__
    m_topframe->refreshNotebook();
#endif
}

void Samples::OnDelete1(wxCommandEvent &event)
{
   deleteSound(0);
}

void Samples::OnDelete2(wxCommandEvent &event)
{
   deleteSound(1);
}

void Samples::OnDelete3(wxCommandEvent &event)
{
   deleteSound(2);
}

void Samples::OnDelete4(wxCommandEvent &event)
{
   deleteSound(3);
}

void Samples::OnDelete5(wxCommandEvent &event)
{
   deleteSound(4);
}

void Samples::OnDelete6(wxCommandEvent &event)
{
   deleteSound(5);
}

void Samples::OnDelete7(wxCommandEvent &event)
{
   deleteSound(6);
}

void Samples::OnDelete8(wxCommandEvent &event)
{
   deleteSound(7);
}

void Samples::OnDelete9(wxCommandEvent &event)
{
   deleteSound(8);
}

void Samples::OnDelete10(wxCommandEvent &event)
{
   deleteSound(9);
}

void Samples::OnDelete11(wxCommandEvent &event)
{
   deleteSound(10);
}

void Samples::OnDelete12(wxCommandEvent &event)
{
   deleteSound(11);
}

void Samples::OnDelete13(wxCommandEvent &event)
{
   deleteSound(12);
}

void Samples::OnDelete14(wxCommandEvent &event)
{
   deleteSound(13);
}

void Samples::OnDelete15(wxCommandEvent &event)
{
   deleteSound(14);
}

void Samples::OnDelete16(wxCommandEvent &event)
{
   deleteSound(15);
}

void Samples::OnSaveAll(wxCommandEvent &event)
{
   wxFileDialog outdialog(this,
                  wxT("Save all wave files"),
                  wxEmptyString,
                  wxEmptyString,
                  wxT("Wave files (*.wav)|*.wav"),
                  wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
   if (outdialog.ShowModal() == wxID_OK)
   {
      wxString filen = outdialog.GetPath();
      wxString prefix;
      uint8_t i;
      if(filen.find(wxT(".wav")) != wxString::npos)
      {
         prefix = filen.substr(0, filen.find(wxT(".wav")));
      }
      for(i = 0; i < 16; i++)
      {
         if(m_proph->getSampleWords(i))
         {
            wxString filename;
            filename.sprintf(wxT("%s_%.2d.wav"), prefix.c_str(), i + 1);
            m_proph->saveWave(i, filename.mb_str());
         }
      }
   }
}

void Samples::setSampleName(wxTextCtrl *ctrl, uint8_t sample_id)
{
   m_proph->setSampleName(ctrl->GetValue().char_str(), sample_id);
}

void Samples::OnNameChange1(wxCommandEvent& event)
{
   setSampleName(m_sample_name1, 0);   
}

void Samples::OnNameChange2(wxCommandEvent& event)
{
   setSampleName(m_sample_name2, 1);   
}

void Samples::OnNameChange3(wxCommandEvent& event)
{
   setSampleName(m_sample_name3, 2);   
}

void Samples::OnNameChange4(wxCommandEvent& event)
{
   setSampleName(m_sample_name4, 3);   
}

void Samples::OnNameChange5(wxCommandEvent& event)
{
   setSampleName(m_sample_name5, 4);   
}

void Samples::OnNameChange6(wxCommandEvent& event)
{
   setSampleName(m_sample_name6, 5);   
}

void Samples::OnNameChange7(wxCommandEvent& event)
{
   setSampleName(m_sample_name7, 6);   
}

void Samples::OnNameChange8(wxCommandEvent& event)
{
   setSampleName(m_sample_name8, 7);   
}

void Samples::OnNameChange9(wxCommandEvent& event)
{
   setSampleName(m_sample_name9, 8);   
}

void Samples::OnNameChange10(wxCommandEvent& event)
{
   setSampleName(m_sample_name10, 9);   
}

void Samples::OnNameChange11(wxCommandEvent& event)
{
   setSampleName(m_sample_name11, 10);   
}

void Samples::OnNameChange12(wxCommandEvent& event)
{
   setSampleName(m_sample_name12, 11);   
}

void Samples::OnNameChange13(wxCommandEvent& event)
{
   setSampleName(m_sample_name13, 12);   
}

void Samples::OnNameChange14(wxCommandEvent& event)
{
   setSampleName(m_sample_name14, 13);   
}

void Samples::OnNameChange15(wxCommandEvent& event)
{
   setSampleName(m_sample_name15, 14);   
}

void Samples::OnNameChange16(wxCommandEvent& event)
{
   setSampleName(m_sample_name16, 15);   
}



