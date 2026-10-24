#include "types.h"


#include <wx/wx.h>
#include <wx/string.h>
#include <wx/file.h>
#include <wx/spinctrl.h>
#include <wx/notebook.h>
#include <wx/tglbtn.h>
#include <wx/sound.h>

#include "types.h"
#include "GUILayout.h"
#include "main.h"
#include "stopwatch.h"
#include "proph2000.h"
#include "soundparam.h"
#include <list>
#include <map>
using namespace std;
#include "clickarea.h"
#include "keyboard.h"
#include "soundkeyboard.h"
#include "wavedisp.h"
#include "wave.h"
#include "soundcopydlg.h"
#include "loadsample.h"
#include "audio.h"
#include "soundsamplepanel.h"
#include "soundsynthpanel.h"
#include "soundlooppanel.h"
#include "logger.h"

//#define __DEACTIVATE_PARAM


#define ZERO_CROSSING_RANGE_DELTA 10
#define MOVE_POINTS_BIG_STEPS_TICKS 2000


#define SLIDER_OPTIONS (wxSL_HORIZONTAL | wxSL_LABELS)
#define SLIDER_WIDTH 120
#define VALUE_TEXT_WIDTH 40


typedef enum
{
   GUI_ELEMENT_CHANGED = 2000,
   GUI_KEYBOARD_EDIT_SELECTION,
   GUI_LOAD_SOUND,
   GUI_SAVE_SOUND,
   GUI_SLIDER_CHANGED,
   GUI_CHECKBOX_CHANGED,
   GUI_SUST_LOOP_CHANGED,
   GUI_FORWARD_LOOP_CHANGED,
   GUI_START_POINT,
   GUI_END_POINT,
   GUI_SUSTLOOP_START,
   GUI_SUSTLOOP_END,
   GUI_RELLOOP_START,
   GUI_RELLOOP_END,
   GUI_WAVESELECTION,
   GUI_PLAY,
   GUI_NOTEBOOK_CHANGED,
   GUI_PURGE,
   GUI_COPY,
   GUI_GETSOUND,
   GUI_GETPARAM,
   GUI_DELETE,
   GUI_IMPORT,
   GUI_EXPORT,
   GUI_STARTPOINT_BKWD1,
   GUI_STARTPOINT_BKWD10,
   GUI_STARTPOINT_FRWD1,
   GUI_STARTPOINT_FRWD10,
   GUI_ENDPOINT_BKWD1,
   GUI_ENDPOINT_BKWD10,
   GUI_ENDPOINT_FRWD1,
   GUI_ENDPOINT_FRWD10,
   GUI_STARTSUS_BKWD1,
   GUI_STARTSUS_BKWD10,
   GUI_STARTSUS_FRWD1,
   GUI_STARTSUS_FRWD10,
   GUI_ENDSUS_BKWD1,
   GUI_ENDSUS_BKWD10,
   GUI_ENDSUS_FRWD1,
   GUI_ENDSUS_FRWD10,
   GUI_STARTREL_BKWD1,
   GUI_STARTREL_BKWD10,
   GUI_STARTREL_FRWD1,
   GUI_STARTREL_FRWD10,
   GUI_ENDREL_BKWD1,
   GUI_ENDREL_BKWD10,
   GUI_ENDREL_FRWD1,
   GUI_ENDREL_FRWD10,
   GUI_ROOT_KEY,
   GUI_HI_KEY_1,
   GUI_HI_KEY_2,
   GUI_HI_KEY_3,
   GUI_HI_KEY_4,
   GUI_HI_KEY_5,
   GUI_HI_KEY_6,
   GUI_HI_KEY_7,
   GUI_HI_KEY_8
};



BEGIN_EVENT_TABLE(MySoundParam, wxPanel)
   EVT_RIGHT_DOWN(MySoundParam::OnMouseRightDown)
   EVT_COMBOBOX(GUI_KEYBOARD_EDIT_SELECTION, MySoundParam::OnKeyboardEditSelection)
   EVT_MENU(GUI_COPY, MySoundParam::OnCopy)
   EVT_MENU(GUI_LOAD_SOUND, MySoundParam::OnLoad)
   EVT_MENU(GUI_SAVE_SOUND, MySoundParam::OnSave)
   EVT_MENU(GUI_GETSOUND, MySoundParam::OnGetSound)
   EVT_MENU(GUI_GETPARAM, MySoundParam::OnGetSoundParam)
   EVT_MENU(GUI_DELETE, MySoundParam::OnDeleteSound)
   EVT_MENU(GUI_IMPORT, MySoundParam::OnImport)
   EVT_MENU(GUI_EXPORT, MySoundParam::OnExport)
   EVT_TOGGLEBUTTON(GUI_PLAY, MySoundParam::OnPlay)
   EVT_MENU(GUI_PURGE, MySoundParam::OnPurge)
   EVT_NOTEBOOK_PAGE_CHANGED(GUI_NOTEBOOK_CHANGED, MySoundParam::OnNotebookChanged)
END_EVENT_TABLE()


MySoundParam::MySoundParam(wxWindow *parent, MyPanel *topframe, Proph2000 *proph, uint8_t sound_u8, Audio *audio,
                           Logger *log) :
   wxPanel(parent, wxID_ANY),
   m_topframe(topframe), m_proph(proph), m_sound_u8(sound_u8), m_audio(audio),
    m_async_play_active(false), m_log(log)
{
   wxBoxSizer *hsizer = new wxBoxSizer (wxHORIZONTAL);
   wxBoxSizer *vsizer = new wxBoxSizer( wxVERTICAL );

   uint8_t font_size;
   uint16_t height;

   m_load_smp_dlg = new LoadSampleDlg(this, wxDefaultPosition, 600, 500, m_topframe, m_proph, m_audio, m_log);

   //m_notebook = new wxNotebook(this, GUI_NOTEBOOK_CHANGED, wxDefaultPosition, wxSize(parent->GetSize().GetWidth(), parent->GetSize().GetHeight() - 263));
#ifdef __WXMAC__ //130205
    m_notebook = new wxNotebook(this, GUI_NOTEBOOK_CHANGED, wxDefaultPosition, wxSize(972 + 100, 415 + 90)); //970
#else
   m_notebook = new wxNotebook(this, GUI_NOTEBOOK_CHANGED, wxDefaultPosition, wxSize(972, 415)); //970
#endif
   m_looppanel = new SoundLoopPanelImpl(m_notebook, m_topframe, m_proph, m_sound_u8, this);
   m_notebook->AddPage(m_looppanel, wxT(" Loop Editor "));
   m_samplepanel = new SoundSamplePanelImpl(m_notebook, m_topframe, m_proph, m_sound_u8, this);
   m_notebook->AddPage(m_samplepanel, wxT(" Sample Configuration "));
   m_synthpanel = new SoundSynthPanelImpl(m_notebook, m_topframe, m_proph, m_sound_u8, this);
   m_notebook->AddPage(m_synthpanel, wxT(" Analogue Settings "));

   hsizer->AddSpacer(5);
   hsizer->Add(m_notebook);
   vsizer->Add(hsizer);
   vsizer->AddSpacer(9);

   hsizer = new wxBoxSizer (wxHORIZONTAL);
   hsizer->AddSpacer(6);
   wxStaticText *txt = new wxStaticText(this, wxID_ANY, wxT("Edit:"),wxDefaultPosition,wxSize(wxDefaultSize.x,12),wxALIGN_BOTTOM|wxALIGN_LEFT| wxALL);
   hsizer->Add(txt);
   hsizer->AddSpacer(20);
   m_edit_selection = new wxComboBox(this, GUI_KEYBOARD_EDIT_SELECTION,"",wxDefaultPosition,wxSize(137,wxDefaultSize.y));
   hsizer->Add(m_edit_selection);
   hsizer->AddSpacer(15);

   font_size = topframe->GetFont().GetPointSize();
   height = font_size + 15;
   m_play_button = new wxToggleButton(this, GUI_PLAY, wxT("Play Sample"), wxDefaultPosition, wxSize(92, height));
   hsizer->Add(m_play_button);
 
   vsizer->Add(hsizer);
   vsizer->AddSpacer(8);


   m_edit_selection->Append(wxT("Root Key"));
   if(sound_u8 < 8)
   {
      m_edit_selection->Append(wxT("Key mapping in Map 1"));
      m_edit_selection->Append(wxT("Key mapping in Map 2"));
      m_edit_selection->Append(wxT("Key mapping in Map 3"));
      m_edit_selection->Append(wxT("Key mapping in Map 4"));
      m_edit_selection->Append(wxT("Key mapping in Map 5"));
      m_edit_selection->Append(wxT("Key mapping in Map 6"));
      m_edit_selection->Append(wxT("Key mapping in Map 7"));
      m_edit_selection->Append(wxT("Key mapping in Map 8"));
   }
   else
   {
      m_edit_selection->Append(wxT("Key mapping in Map 9"));
      m_edit_selection->Append(wxT("Key mapping in Map A"));
      m_edit_selection->Append(wxT("Key mapping in Map B"));
      m_edit_selection->Append(wxT("Key mapping in Map C"));
      m_edit_selection->Append(wxT("Key mapping in Map D"));
      m_edit_selection->Append(wxT("Key mapping in Map E"));
      m_edit_selection->Append(wxT("Key mapping in Map F"));
      m_edit_selection->Append(wxT("Key mapping in Map G"));
   }
   m_edit_selection->SetSelection(0);

   m_sound_keyboard = new SoundKeyboard(this, wxID_ANY, wxDefaultPosition, wxSize(970, 100), this, m_proph, m_sound_u8);
   hsizer = new wxBoxSizer( wxHORIZONTAL );
   hsizer->SetMinSize( wxSize( -1,140) ); 
   hsizer->AddSpacer(5);
   hsizer->Add(m_sound_keyboard,wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_BOTTOM);
//   vsizer->Fit( this );

   vsizer->Add(hsizer);

   SetSizer(vsizer);

   updateGUI();

   m_copydlg = new SoundCopyDialog(this, wxID_ANY);
   m_copydlg->CenterOnScreen();
}


MySoundParam::~MySoundParam()
{
   stopPlayback();
   delete m_copydlg;
   delete m_load_smp_dlg;
   delete m_sound_keyboard;
   delete m_samplepanel;
   delete m_synthpanel;
   delete m_looppanel;
}

void MySoundParam::activateSound(uint8_t sound_u8)
{
   uint8_t seltmp;
   m_sound_u8 = sound_u8;
   m_looppanel->activateSound(sound_u8);
   m_samplepanel->activateSound(sound_u8);
   m_synthpanel->activateSound(sound_u8);

   seltmp = m_edit_selection->GetSelection();
   m_edit_selection->Clear();
   m_edit_selection->Append(wxT("Root Key"));
   if(sound_u8 < 8)
   {
      m_edit_selection->Append(wxT("Key mapping in Map 1"));
      m_edit_selection->Append(wxT("Key mapping in Map 2"));
      m_edit_selection->Append(wxT("Key mapping in Map 3"));
      m_edit_selection->Append(wxT("Key mapping in Map 4"));
      m_edit_selection->Append(wxT("Key mapping in Map 5"));
      m_edit_selection->Append(wxT("Key mapping in Map 6"));
      m_edit_selection->Append(wxT("Key mapping in Map 7"));
      m_edit_selection->Append(wxT("Key mapping in Map 8"));
   }
   else
   {
      m_edit_selection->Append(wxT("Key mapping in Map 9"));
      m_edit_selection->Append(wxT("Key mapping in Map A"));
      m_edit_selection->Append(wxT("Key mapping in Map B"));
      m_edit_selection->Append(wxT("Key mapping in Map C"));
      m_edit_selection->Append(wxT("Key mapping in Map D"));
      m_edit_selection->Append(wxT("Key mapping in Map E"));
      m_edit_selection->Append(wxT("Key mapping in Map F"));
      m_edit_selection->Append(wxT("Key mapping in Map G"));
   }
   m_edit_selection->SetSelection(seltmp);

   updateGUI();
   m_sound_keyboard->activateSound(sound_u8);
   m_sound_keyboard->setKeyboardEditSelection((keyboard_edit_selection_te)m_edit_selection->GetSelection());
   m_proph->sendSelectRequest();
}


void MySoundParam::updateWaveView(void)
{
   m_looppanel->updateWaveView();
}

void MySoundParam::resetWaveViewZoom(void)
{
   m_looppanel->resetWaveViewZoom();
}


void MySoundParam::OnImport(wxCommandEvent& event)
{
   m_load_smp_dlg->show(m_sound_u8);
   m_topframe->updateGUI();
   m_topframe->resetWaveViewZoom();
   m_topframe->updateWaveView();
}


void MySoundParam::OnExport(wxCommandEvent& event)
{
   if(m_proph->getSampleWords(m_sound_u8))
   {
      wxFileDialog outdialog(this,
                     wxT("Save Wave File"),
                     wxEmptyString,
                     wxEmptyString,
                     wxT("Wave Files (*.wav)|*.wav"),
                     wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
      if (outdialog.ShowModal() == wxID_OK)
      {
         wxString filen = outdialog.GetPath();
         if(filen.find(wxT(".wav")) == wxString::npos)
         {
            filen += wxT(".wav");
         }

         if(!m_proph->saveWave(m_sound_u8, filen.mb_str()))
         {
            wxMessageDialog edialog(this, wxT("Could not save Wave File"), wxT("Error"));
            edialog.ShowModal();
         }
      }
   }
}


void MySoundParam::OnPurge(wxCommandEvent& event)
{
   stopPlayback();

   purge(m_sound_u8);

   if(m_proph->getStereoMode())
   {
      if(m_sound_u8 < 8)
      {
         purge(m_sound_u8 + 8);
      }
      else
      {
         purge(m_sound_u8 - 8);
      }
   }

   m_topframe->updateGUI();

   updateWaveView();
}


void MySoundParam::purge(uint8_t sound_u8)
{
   uint32_t i;
   uint32_t newwords;
   uint32_t oldstart;
   uint32_t oldend;
   uint32_t oldsuststart;
   uint32_t oldsustend;
   uint32_t oldrelstart;
   uint32_t oldrelend;

   if(m_proph->getSampleWords(sound_u8) != 0)
   {
      oldstart = m_proph->getStartPoint(sound_u8);
      oldend = m_proph->getEndPoint(sound_u8);

      oldsuststart = m_proph->getSustainLoopStart(sound_u8);
      oldsustend = m_proph->getSustainLoopEnd(sound_u8);

      oldrelstart = m_proph->getReleaseLoopStart(sound_u8);
      oldrelend = m_proph->getReleaseLoopEnd(sound_u8);

      newwords = oldend - oldstart;

      uint16_t *tmp = new(uint16_t[MAX_SAMPLE_WORDS_PER_MEMORY]);
      uint16_t *p = m_proph->getSampleData(sound_u8) + oldstart;

      for(i = 0; i < newwords; i++)
      {   
         tmp[i] = p[i];
      }

      p = m_proph->getSampleData(sound_u8);

      for(i = 0; i < MAX_SAMPLE_WORDS_PER_MEMORY; i++)
      {
         p[i] = 4096 / 2;
      }

      for(i = 0; i < (newwords - 4); i++)
      {
         p[i] = tmp[i];
      }

      // normalize
      int16_t t;
      int16_t min;
      int16_t max;
      float scale;
      
      min = 0;
      max = 0;

      for(i = 0; i < (newwords - 4); i++)
      {
         t = p[i] - (4096 / 2);
         if(t < min)
         {
            min = t;
         }
         if(t > max)
         {
            max = t;
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
         for(i = 0; i < newwords; i++)
         {
            t = p[i] - (4096 / 2);
            t = t * scale;
            p[i] = t + (4096 / 2);
         }
      }

      m_proph->m_sound_param_as[sound_u8].val_s.begin_addr[2] = 0 & 0xff;
      m_proph->m_sound_param_as[sound_u8].val_s.begin_addr[1] = (0 & 0xff00) >> 8;
      m_proph->m_sound_param_as[sound_u8].val_s.begin_addr[0] = (0 & 0xff0000) >> 16;

      m_proph->m_sound_param_as[sound_u8].val_s.start_point[2] = 0 & 0xff;
      m_proph->m_sound_param_as[sound_u8].val_s.start_point[1] = (0 & 0xff00) >> 8;
      m_proph->m_sound_param_as[sound_u8].val_s.start_point[0] = (0 & 0xff0000) >> 16;

      oldsuststart -= oldstart;
      m_proph->m_sound_param_as[sound_u8].val_s.sustain_loop_start[2] = oldsuststart & 0xff;
      m_proph->m_sound_param_as[sound_u8].val_s.sustain_loop_start[1] = (oldsuststart & 0xff00) >> 8;
      m_proph->m_sound_param_as[sound_u8].val_s.sustain_loop_start[0] = (oldsuststart & 0xff0000) >> 16;

      oldrelstart -= oldstart;
      m_proph->m_sound_param_as[sound_u8].val_s.release_loop_start[2] = oldrelstart & 0xff;
      m_proph->m_sound_param_as[sound_u8].val_s.release_loop_start[1] = (oldrelstart & 0xff00) >> 8;
      m_proph->m_sound_param_as[sound_u8].val_s.release_loop_start[0] = (oldrelstart & 0xff0000) >> 16;

      m_proph->m_sound_param_as[sound_u8].val_s.end_point[2] = newwords & 0xff;
      m_proph->m_sound_param_as[sound_u8].val_s.end_point[1] = (newwords & 0xff00) >> 8;
      m_proph->m_sound_param_as[sound_u8].val_s.end_point[0] = (newwords & 0xff0000) >> 16;

      newwords = newwords - (newwords & 0x3ff) + 0x3ff;
      m_proph->m_sound_param_as[sound_u8].val_s.finish_addr[2] = newwords & 0xff;
      m_proph->m_sound_param_as[sound_u8].val_s.finish_addr[1] = (newwords & 0xff00) >> 8;
      m_proph->m_sound_param_as[sound_u8].val_s.finish_addr[0] = (newwords & 0xff0000) >> 16;

      oldrelend -= oldstart;
      m_proph->m_sound_param_as[sound_u8].val_s.release_loop_end[2] = oldrelend & 0xff;
      m_proph->m_sound_param_as[sound_u8].val_s.release_loop_end[1] = (oldrelend & 0xff00) >> 8;
      m_proph->m_sound_param_as[sound_u8].val_s.release_loop_end[0] = (oldrelend & 0xff0000) >> 16;

      oldsustend -= oldstart;
      m_proph->m_sound_param_as[sound_u8].val_s.sustain_loop_end[2] = oldsustend & 0xff;
      m_proph->m_sound_param_as[sound_u8].val_s.sustain_loop_end[1] = (oldsustend & 0xff00) >> 8;
      m_proph->m_sound_param_as[sound_u8].val_s.sustain_loop_end[0] = (oldsustend & 0xff0000) >> 16;

      m_proph->updateParamBytesFromStruct();
      m_proph->remapMemory();

      delete tmp;
   }
}


void MySoundParam::setUpdateLoopParamsActive(bool flag)
{
   m_looppanel->setUpdateLoopParamsActive(flag);
}


void MySoundParam::updateGUI(void)
{
   wxString str;
//   uint32_t t;

   m_looppanel->setUpdateLoopParamsActive(false);

   m_samplepanel->updateGUI();
   m_synthpanel->displaySettings();
   m_synthpanel->updateGUI();
   m_looppanel->updateGUI();

   if(m_proph->getSampleWords(m_sound_u8))
   {
      m_play_button->Enable();
      m_looppanel->getPlayButton()->Enable();
   }
   else
   {
      m_play_button->Disable();
      m_looppanel->getPlayButton()->Disable();
   }

   m_sound_keyboard->Refresh(true);

   m_looppanel->setUpdateLoopParamsActive(true);
}

void MySoundParam::noteEvent(uint8_t note)
{
   uint8_t orig_key;
   uint8_t low_keys;
   uint8_t high_keys;

   switch(m_proph->getSampleRate(m_sound_u8))
   {
      case Proph2000::SR_15625HZ:
         low_keys = 18;
         high_keys = 24;
         break;
      case Proph2000::SR_31250HZ:
         low_keys = 18;
         high_keys = 12;
         break;
      case Proph2000::SR_41667HZ:
         low_keys = 23;
         high_keys = 7;
         break;
      default:
         break;
   }

   switch(m_edit_selection->GetSelection())
   {
      case ROOT:
         break;
      case HIKEY1:
         if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map1 == SOUND_NOT_MAPPED_VALUE)
         {
            orig_key = m_proph->m_sound_param_as[m_sound_u8].val_s.root_key;
         }
         else
         {
            orig_key = m_proph->m_sound_param_as[m_sound_u8].val_s.root_key + m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map1;
         }

         if(note > (orig_key + high_keys))
         {
            note = orig_key + high_keys;
         }

         m_proph->m_sound_param_as[m_sound_u8].val_s.hi_key_map1 = note;
         if(m_proph->getStereoMode())
         {
            if(m_sound_u8 < 8)
            {
               m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.hi_key_map1 = note;
            }
            else
            {
               m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.hi_key_map1 = note;
            }
         }
         break;
      case HIKEY2:
         if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map2 == SOUND_NOT_MAPPED_VALUE)
         {
            orig_key = m_proph->m_sound_param_as[m_sound_u8].val_s.root_key;
         }
         else
         {
            orig_key = m_proph->m_sound_param_as[m_sound_u8].val_s.root_key + m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map2;
         }

         if(note > (orig_key + high_keys))
         {
            note = orig_key + high_keys;
         }
         m_proph->m_sound_param_as[m_sound_u8].val_s.hi_key_map2 = note;
         if(m_proph->getStereoMode())
         {
            if(m_sound_u8 < 8)
            {
               m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.hi_key_map2 = note;
            }
            else
            {
               m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.hi_key_map2 = note;
            }
         }
         break;
      case HIKEY3:
         if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map3 == SOUND_NOT_MAPPED_VALUE)
         {
            orig_key = m_proph->m_sound_param_as[m_sound_u8].val_s.root_key;
         }
         else
         {
            orig_key = m_proph->m_sound_param_as[m_sound_u8].val_s.root_key + m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map3;
         }

         if(note > (orig_key + high_keys))
         {
            note = orig_key + high_keys;
         }
         m_proph->m_sound_param_as[m_sound_u8].val_s.hi_key_map3 = note;
         if(m_proph->getStereoMode())
         {
            if(m_sound_u8 < 8)
            {
               m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.hi_key_map3 = note;
            }
            else
            {
               m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.hi_key_map3 = note;
            }
         }

         break;
      case HIKEY4:
         if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map4 == SOUND_NOT_MAPPED_VALUE)
         {
            orig_key = m_proph->m_sound_param_as[m_sound_u8].val_s.root_key;
         }
         else
         {
            orig_key = m_proph->m_sound_param_as[m_sound_u8].val_s.root_key + m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map4;
         }

         if(note > (orig_key + high_keys))
         {
            note = orig_key + high_keys;
         }
         m_proph->m_sound_param_as[m_sound_u8].val_s.hi_key_map4 = note;
         if(m_proph->getStereoMode())
         {
            if(m_sound_u8 < 8)
            {
               m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.hi_key_map4 = note;
            }
            else
            {
               m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.hi_key_map4 = note;
            }
         }
         break;
      case HIKEY5:
         if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map5 == SOUND_NOT_MAPPED_VALUE)
         {
            orig_key = m_proph->m_sound_param_as[m_sound_u8].val_s.root_key;
         }
         else
         {
            orig_key = m_proph->m_sound_param_as[m_sound_u8].val_s.root_key + m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map5;
         }

         if(note > (orig_key + high_keys))
         {
            note = orig_key + high_keys;
         }
         m_proph->m_sound_param_as[m_sound_u8].val_s.hi_key_map5 = note;
         if(m_proph->getStereoMode())
         {
            if(m_sound_u8 < 8)
            {
               m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.hi_key_map5 = note;
            }
            else
            {
               m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.hi_key_map5 = note;
            }
         }
         break;
      case HIKEY6:
         if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map6 == SOUND_NOT_MAPPED_VALUE)
         {
            orig_key = m_proph->m_sound_param_as[m_sound_u8].val_s.root_key;
         }
         else
         {
            orig_key = m_proph->m_sound_param_as[m_sound_u8].val_s.root_key + m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map6;
         }

         if(note > (orig_key + high_keys))
         {
            note = orig_key + high_keys;
         }
         m_proph->m_sound_param_as[m_sound_u8].val_s.hi_key_map6 = note;
         if(m_proph->getStereoMode())
         {
            if(m_sound_u8 < 8)
            {
               m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.hi_key_map6 = note;
            }
            else
            {
               m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.hi_key_map6 = note;
            }
         }
         break;
      case HIKEY7:
         if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map7 == SOUND_NOT_MAPPED_VALUE)
         {
            orig_key = m_proph->m_sound_param_as[m_sound_u8].val_s.root_key;
         }
         else
         {
            orig_key = m_proph->m_sound_param_as[m_sound_u8].val_s.root_key + m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map7;
         }

         if(note > (orig_key + high_keys))
         {
            note = orig_key + high_keys;
         }
         m_proph->m_sound_param_as[m_sound_u8].val_s.hi_key_map7 = note;
         if(m_proph->getStereoMode())
         {
            if(m_sound_u8 < 8)
            {
               m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.hi_key_map7 = note;
            }
            else
            {
               m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.hi_key_map7 = note;
            }
         }
         break;
      case HIKEY8:
         if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map8 == SOUND_NOT_MAPPED_VALUE)
         {
            orig_key = m_proph->m_sound_param_as[m_sound_u8].val_s.root_key;
         }
         else
         {
            orig_key = m_proph->m_sound_param_as[m_sound_u8].val_s.root_key + m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map8;
         }

         if(note > (orig_key + high_keys))
         {
            note = orig_key + high_keys;
         }
         m_proph->m_sound_param_as[m_sound_u8].val_s.hi_key_map8 = note;
         if(m_proph->getStereoMode())
         {
            if(m_sound_u8 < 8)
            {
               m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.hi_key_map8 = note;
            }
            else
            {
               m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.hi_key_map8 = note;
            }
         }
         break;
   }
   
   m_proph->updateParamBytesFromStruct();
   m_topframe->updateGUI();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferSoundParam2Proph(m_sound_u8))
      {
         m_topframe->transferStarted();
      }
   }
}


void MySoundParam::setTransposeOrigin(uint8_t note)
{
   int16_t t;
   switch(m_edit_selection->GetSelection())
   {
      case ROOT:
         m_proph->m_sound_param_as[m_sound_u8].val_s.root_key = note;
         if(m_proph->getStereoMode())
         {
            if(m_sound_u8 < 8)
            {
               m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.root_key = note;
            }
            else
            {
               m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.root_key = note;
            }
         }
         break;
      case HIKEY1:
         t = (int16_t)note - (int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.root_key;
         if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map1 == (uint8_t)t)
         {
            m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map1 = SOUND_NOT_MAPPED_VALUE;
            if(m_proph->getStereoMode())
            {
               if(m_sound_u8 < 8)
               {
                  m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.transpose_map1 = SOUND_NOT_MAPPED_VALUE;
               }
               else
               {
                  m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.transpose_map1 = SOUND_NOT_MAPPED_VALUE;
               }
            }
         }
         else
         {
            m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map1 = (uint8_t)t;
            if(m_proph->getStereoMode())
            {
               if(m_sound_u8 < 8)
               {
                  m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.transpose_map1 = (uint8_t)t;
               }
               else
               {
                  m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.transpose_map1 = (uint8_t)t;
               }
            }
         }
         break;
      case HIKEY2:
         t = (int16_t)note - (int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.root_key;
         if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map2 == (uint8_t)t)
         {
            m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map2 = SOUND_NOT_MAPPED_VALUE;
            if(m_proph->getStereoMode())
            {
               if(m_sound_u8 < 8)
               {
                  m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.transpose_map2 = SOUND_NOT_MAPPED_VALUE;
               }
               else
               {
                  m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.transpose_map2 = SOUND_NOT_MAPPED_VALUE;
               }
            }
         }
         else
         {
            m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map2 = (uint8_t)t;
            if(m_proph->getStereoMode())
            {
               if(m_sound_u8 < 8)
               {
                  m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.transpose_map2 = (uint8_t)t;
               }
               else
               {
                  m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.transpose_map2 = (uint8_t)t;
               }
            }
         }
         break;
      case HIKEY3:
         t = (int16_t)note - (int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.root_key;
         if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map3 == (uint8_t)t)
         {
            m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map3 = SOUND_NOT_MAPPED_VALUE;
            if(m_proph->getStereoMode())
            {
               if(m_sound_u8 < 8)
               {
                  m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.transpose_map3 = SOUND_NOT_MAPPED_VALUE;
               }
               else
               {
                  m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.transpose_map3 = SOUND_NOT_MAPPED_VALUE;
               }
            }
         }
         else
         {
            m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map3 = (uint8_t)t;
            if(m_proph->getStereoMode())
            {
               if(m_sound_u8 < 8)
               {
                  m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.transpose_map3 = (uint8_t)t;
               }
               else
               {
                  m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.transpose_map3 = (uint8_t)t;
               }
            }
         }
         break;
      case HIKEY4:
         t = (int16_t)note - (int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.root_key;
         if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map4 == (uint8_t)t)
         {
            m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map4 = SOUND_NOT_MAPPED_VALUE;
            if(m_proph->getStereoMode())
            {
               if(m_sound_u8 < 8)
               {
                  m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.transpose_map4 = SOUND_NOT_MAPPED_VALUE;
               }
               else
               {
                  m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.transpose_map4 = SOUND_NOT_MAPPED_VALUE;
               }
            }
         }
         else
         {
            m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map4 = (uint8_t)t;
            if(m_proph->getStereoMode())
            {
               if(m_sound_u8 < 8)
               {
                  m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.transpose_map4 = (uint8_t)t;
               }
               else
               {
                  m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.transpose_map4 = (uint8_t)t;
               }
            }
         }
         break;
      case HIKEY5:
         t = (int16_t)note - (int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.root_key;
         if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map5 == (uint8_t)t)
         {
            m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map5 = SOUND_NOT_MAPPED_VALUE;
            if(m_proph->getStereoMode())
            {
               if(m_sound_u8 < 8)
               {
                  m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.transpose_map5 = SOUND_NOT_MAPPED_VALUE;
               }
               else
               {
                  m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.transpose_map5 = SOUND_NOT_MAPPED_VALUE;
               }
            }
         }
         else
         {
            m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map5 = (uint8_t)t;
            if(m_proph->getStereoMode())
            {
               if(m_sound_u8 < 8)
               {
                  m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.transpose_map5 = (uint8_t)t;
               }
               else
               {
                  m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.transpose_map5 = (uint8_t)t;
               }
            }
         }
         break;
      case HIKEY6:
         t = (int16_t)note - (int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.root_key;
         if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map6 == (uint8_t)t)
         {
            m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map6 = SOUND_NOT_MAPPED_VALUE;
            if(m_proph->getStereoMode())
            {
               if(m_sound_u8 < 8)
               {
                  m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.transpose_map6 = SOUND_NOT_MAPPED_VALUE;
               }
               else
               {
                  m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.transpose_map6 = SOUND_NOT_MAPPED_VALUE;
               }
            }
         }
         else
         {
            m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map6 = (uint8_t)t;
            if(m_proph->getStereoMode())
            {
               if(m_sound_u8 < 8)
               {
                  m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.transpose_map6 = (uint8_t)t;
               }
               else
               {
                  m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.transpose_map6 = (uint8_t)t;
               }
            }
         }
         break;
      case HIKEY7:
         t = (int16_t)note - (int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.root_key;
         if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map7 == (uint8_t)t)
         {
            m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map7 = SOUND_NOT_MAPPED_VALUE;
            if(m_proph->getStereoMode())
            {
               if(m_sound_u8 < 8)
               {
                  m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.transpose_map7 = SOUND_NOT_MAPPED_VALUE;
               }
               else
               {
                  m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.transpose_map7 = SOUND_NOT_MAPPED_VALUE;
               }
            }
         }
         else
         {
            m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map7 = (uint8_t)t;
            if(m_proph->getStereoMode())
            {
               if(m_sound_u8 < 8)
               {
                  m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.transpose_map7 = (uint8_t)t;
               }
               else
               {
                  m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.transpose_map7 = (uint8_t)t;
               }
            }
         }
         break;
      case HIKEY8:
         t = (int16_t)note - (int16_t)m_proph->m_sound_param_as[m_sound_u8].val_s.root_key;
         if(m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map8 == (uint8_t)t)
         {
            m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map8 = SOUND_NOT_MAPPED_VALUE;
            if(m_proph->getStereoMode())
            {
               if(m_sound_u8 < 8)
               {
                  m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.transpose_map8 = SOUND_NOT_MAPPED_VALUE;
               }
               else
               {
                  m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.transpose_map8 = SOUND_NOT_MAPPED_VALUE;
               }
            }
         }
         else
         {
            m_proph->m_sound_param_as[m_sound_u8].val_s.transpose_map8 = (uint8_t)t;
            if(m_proph->getStereoMode())
            {
               if(m_sound_u8 < 8)
               {
                  m_proph->m_sound_param_as[m_sound_u8 + 8].val_s.transpose_map8 = (uint8_t)t;
               }
               else
               {
                  m_proph->m_sound_param_as[m_sound_u8 - 8].val_s.transpose_map8 = (uint8_t)t;
               }
            }
         }
         break;
   }
   
   m_proph->updateParamBytesFromStruct();
   m_topframe->updateGUI();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferSoundParam2Proph(m_sound_u8))
      {
         m_topframe->transferStarted();
      }
   }
}


void MySoundParam::OnKeyboardEditSelection(wxCommandEvent &event)
{
   m_sound_keyboard->setKeyboardEditSelection((keyboard_edit_selection_te)m_edit_selection->GetSelection());
}


void MySoundParam::OnLoad(wxCommandEvent& event)
{
   wxString wildcards =
                 wxString::Format
                 (
                     wxT("Sound Files (*.p2s)|*.p2s"),
                     wxFileSelectorDefaultWildcardStr,
                     wxFileSelectorDefaultWildcardStr
                 );

   wxFileDialog indialog(this, wxT("Load Sound File"),
                     wxEmptyString, wxEmptyString, wildcards,
                     wxFD_OPEN);

   if (indialog.ShowModal() == wxID_OK)
   {
      FILE *mf;
      mf = fopen(indialog.GetPath().mb_str(), "rb");

      if(mf)
      {
         uint32_t t;
         char name[MAX_SAMPLE_NAME_LEN];

         name[0] = 0;
   
         m_looppanel->setUpdateLoopParamsActive(false); // loading will cause some unwanted GUI events

         m_proph->deleteSample(m_sound_u8);

         fread(&m_proph->m_soundparam_au8[m_sound_u8], 1, SOUND_PARAM_BYTES * 2, mf);
         fread(&t, 1, 4, mf);
         fread(m_proph->getSampleData(m_sound_u8), 1, t * 2, mf);
         fread(name, 1, MAX_SAMPLE_NAME_LEN, mf);
         wxLogMessage("name: %s", name);
         fclose(mf);
         m_proph->setSampleName(name, m_sound_u8);
         m_proph->updateStructsFromParamBytes();
         m_proph->remapMemory();
         m_topframe->updateGUI();
         resetWaveViewZoom();
         updateWaveView();

         m_looppanel->setUpdateLoopParamsActive(true); // loading will cause some unwanted GUI events
      }
      else
      {
         wxMessageDialog edialog(this, wxT("Could not load Dump File"), wxT("Error"));
         edialog.ShowModal();
      }
   }
}


void MySoundParam::OnSave(wxCommandEvent& event)
{
   wxFileDialog outdialog(this,
                  wxT("Save sound file"),
                  wxEmptyString,
                  wxEmptyString,
                  wxT("Sound files (*.p2s)|*.p2s"),
                  wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
   if (outdialog.ShowModal() == wxID_OK)
   {
      wxString filen = outdialog.GetPath();
      if(filen.find(wxT(".p2s")) == wxString::npos)
      {
         filen += wxT(".p2s");
      }
      FILE *mf;
      mf = fopen(filen.mb_str(), "wb");

      if(mf)
      {
         uint32_t t;
         fwrite(&m_proph->m_soundparam_au8[m_sound_u8], 1, SOUND_PARAM_BYTES * 2, mf);
         t = m_proph->getSampleWords(m_sound_u8);
         fwrite(&t, 1, 4, mf);
         fwrite(m_proph->getSampleData(m_sound_u8), 1, t * 2, mf);
         fwrite(m_proph->getSampleName(m_sound_u8), 1, MAX_SAMPLE_NAME_LEN, mf);
         wxLogMessage("sname: %s", m_proph->getSampleName(m_sound_u8));
         fclose(mf);
      }
      else
      {
         wxMessageDialog edialog(this, wxT("Could not save Sound File"), wxT("Error"));
         edialog.ShowModal();
      }
   }
}




void MySoundParam::OnPlay(wxCommandEvent& event)
{
   if(m_play_button->GetValue() || m_looppanel->getPlayButton()->GetValue())
   {
      startPlayback();
   }
   else
   {
      stopPlayback();
   }
}

void MySoundParam::startPlayback(void)
{
   uint16_t samplerate;

   if(m_async_play_active)
   {
      m_async_play_active = false;
   }


   switch(m_proph->getSampleRate(m_sound_u8))
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

   switch(m_looppanel->getWaveSelection())
   {
      case 0:
         if(m_proph->m_sound_param_as[m_sound_u8].val_s.sample_status & 0x08)
         {
            // reverse
            if(m_proph->getStereoMode())
            {
               uint32_t i;
               uint16_t *p_l;
               uint16_t *p_r;
               
               if(m_sound_u8 < 8)
               {
                  p_l = &m_proph->getSampleData(m_sound_u8)[m_proph->getStartPoint(m_sound_u8)];
                  p_r = &m_proph->getSampleData(m_sound_u8 + 8)[m_proph->getStartPoint(m_sound_u8 + 8)];
               }
               else
               {
                  p_l = &m_proph->getSampleData(m_sound_u8 - 8)[m_proph->getStartPoint(m_sound_u8 - 8)];
                  p_r = &m_proph->getSampleData(m_sound_u8)[m_proph->getStartPoint(m_sound_u8)];
               }
               uint32_t len = m_proph->getEndPoint(m_sound_u8) - m_proph->getStartPoint(m_sound_u8);

               for(i = 0; i < len; i++)
               {
                  m_loop_play_tmp_buf_l[i] = p_l[(len - 1) - i];
                  m_loop_play_tmp_buf_r[i] = p_r[(len - 1) - i];
               }
               m_audio->setStereoAudioData(m_loop_play_tmp_buf_l, m_loop_play_tmp_buf_r, len);
            }
            else
            {
               uint32_t i;
               uint16_t *p = &m_proph->getSampleData(m_sound_u8)[m_proph->getStartPoint(m_sound_u8)];
               uint32_t len = m_proph->getEndPoint(m_sound_u8) - m_proph->getStartPoint(m_sound_u8);

               for(i = 0; i < len; i++)
               {
                  m_loop_play_tmp_buf_l[i] = p[(len - 1) - i];
               }
               m_audio->setAudioData(m_loop_play_tmp_buf_l, len);
            }
            m_audio->play(false, samplerate);
            m_play_button->SetValue(false);
            m_looppanel->getPlayButton()->SetValue(false);
         }
         else
         {
            if(m_proph->getStereoMode())
            {
               if(m_sound_u8 < 8)
               {
                  m_audio->setStereoAudioData(&m_proph->getSampleData(m_sound_u8)[m_proph->getStartPoint(m_sound_u8)], &m_proph->getSampleData(m_sound_u8 + 8)[m_proph->getStartPoint(m_sound_u8 + 8)], m_proph->getEndPoint(m_sound_u8) - m_proph->getStartPoint(m_sound_u8));
               }
               else
               {
                  m_audio->setStereoAudioData(&m_proph->getSampleData(m_sound_u8 - 8)[m_proph->getStartPoint(m_sound_u8 - 8)], &m_proph->getSampleData(m_sound_u8)[m_proph->getStartPoint(m_sound_u8)], m_proph->getEndPoint(m_sound_u8) - m_proph->getStartPoint(m_sound_u8));
               }
            }
            else
            {
               m_audio->setAudioData(&m_proph->getSampleData(m_sound_u8)[m_proph->getStartPoint(m_sound_u8)], m_proph->getEndPoint(m_sound_u8) - m_proph->getStartPoint(m_sound_u8));
            }
            m_audio->play(false, samplerate);
            m_play_button->SetValue(false);
            m_looppanel->getPlayButton()->SetValue(false);
         }
         break;
      case 1:
         // sustain loop
         if(m_proph->m_sound_param_as[m_sound_u8].val_s.sample_status & 0x08)
         {
            // reverse
            if(m_proph->getStereoMode())
            {
               uint32_t i;
               uint16_t *p_l;
               uint16_t *p_r;

               if(m_sound_u8 < 8)
               {
                  p_l = &m_proph->getSampleData(m_sound_u8)[m_proph->getSustainLoopStart(m_sound_u8)];
                  p_r = &m_proph->getSampleData(m_sound_u8 + 8)[m_proph->getSustainLoopStart(m_sound_u8 + 8)];
               }
               else
               {
                  p_l = &m_proph->getSampleData(m_sound_u8 - 8)[m_proph->getSustainLoopStart(m_sound_u8 - 8)];
                  p_r = &m_proph->getSampleData(m_sound_u8)[m_proph->getSustainLoopStart(m_sound_u8)];
               }
               uint32_t len = m_proph->getSustainLoopEnd(m_sound_u8) - m_proph->getSustainLoopStart(m_sound_u8);
               len++;
               for(i = 0; i < len; i++)
               {
                  m_loop_play_tmp_buf_l[i] = p_l[(len - 1) - i];
                  m_loop_play_tmp_buf_r[i] = p_r[(len - 1) - i];
               }
               m_audio->setStereoAudioData(m_loop_play_tmp_buf_l, m_loop_play_tmp_buf_r, len);
               m_audio->play(true, samplerate);
            }
            else
            {
               uint32_t i;
               uint16_t *p = &m_proph->getSampleData(m_sound_u8)[m_proph->getSustainLoopStart(m_sound_u8)];
               uint32_t len = m_proph->getSustainLoopEnd(m_sound_u8) - m_proph->getSustainLoopStart(m_sound_u8);
               len++;
               for(i = 0; i < len; i++)
               {
                  m_loop_play_tmp_buf_l[i] = p[(len - 1) - i];
               }
               m_audio->setAudioData(m_loop_play_tmp_buf_l, len);
               m_audio->play(true, samplerate);
            }
            //PlaySound((LPCSTR)m_play_wave->getResourceData(), NULL, SND_MEMORY | SND_ASYNC | SND_LOOP);
         }
         else
         {
            uint16_t *p = &m_proph->getSampleData(m_sound_u8)[m_proph->getSustainLoopStart(m_sound_u8)];
			   uint32_t len = m_proph->getSustainLoopEnd(m_sound_u8) - m_proph->getSustainLoopStart(m_sound_u8);
            len++;
            m_audio->setAudioData(p, len);
            m_audio->play(true, samplerate);
         }
         m_async_play_active = true;
         break;
      case 2:
         // release loop
         if(m_proph->m_sound_param_as[m_sound_u8].val_s.sample_status & 0x04)
         {
            // back and forth
            if(m_proph->m_sound_param_as[m_sound_u8].val_s.sample_status & 0x08)
            {
               // reverse
               if(m_proph->getStereoMode())
               {
                  uint16_t *tmp_l;
                  uint16_t *tmp_r;
                  uint16_t *p_l;
                  uint16_t *p_r;
                  
                  if(m_sound_u8)
                  {
                     p_l = &m_proph->getSampleData(m_sound_u8)[m_proph->getReleaseLoopStart(m_sound_u8)];
                     p_r = &m_proph->getSampleData(m_sound_u8 + 8)[m_proph->getReleaseLoopStart(m_sound_u8 + 8)];
                  }
                  else
                  {
                     p_l = &m_proph->getSampleData(m_sound_u8 - 8)[m_proph->getReleaseLoopStart(m_sound_u8 - 8)];
                     p_r = &m_proph->getSampleData(m_sound_u8)[m_proph->getReleaseLoopStart(m_sound_u8)];
                  }

                  uint32_t len = m_proph->getReleaseLoopEnd(m_sound_u8) - m_proph->getReleaseLoopStart(m_sound_u8);
                  uint32_t i;
                  tmp_l = m_loop_play_tmp_buf_l;
                  tmp_r = m_loop_play_tmp_buf_r;
                  len++;

                  for(i = 0; i < len; i++)
                  {
                     tmp_l[i] = p_l[(len - 1) - i];
                     tmp_r[i] = p_r[(len - 1) - i];
                     //wxLogMessage("tmp[%d] = p[%d]", i, (len - 1) - i);
                  }

                  for(i = 1; i < (len - 1); i++)
                  {
                     //wxLogMessage("tmp[%d] = p[%d]", i + (len - 1), i);
                     tmp_l[i + (len - 1)] = p_l[i];
                     tmp_r[i + (len - 1)] = p_r[i];
                  }

                  m_audio->setStereoAudioData(m_loop_play_tmp_buf_l, m_loop_play_tmp_buf_r, (len * 2) - 2);
                  m_audio->play(true, samplerate);
               }
               else
               {
                  uint16_t *tmp;
                  uint16_t *p = &m_proph->getSampleData(m_sound_u8)[m_proph->getReleaseLoopStart(m_sound_u8)];
                  uint32_t len = m_proph->getReleaseLoopEnd(m_sound_u8) - m_proph->getReleaseLoopStart(m_sound_u8);
                  uint32_t i;
                  tmp = m_loop_play_tmp_buf_l;
                  len++;

                  for(i = 0; i < len; i++)
                  {
                     tmp[i] = p[(len - 1) - i];
                     //wxLogMessage("tmp[%d] = p[%d]", i, (len - 1) - i);
                  }

                  for(i = 1; i < (len - 1); i++)
                  {
                     //wxLogMessage("tmp[%d] = p[%d]", i + (len - 1), i);
                     tmp[i + (len - 1)] = p[i];
                  }

                  m_audio->setAudioData(m_loop_play_tmp_buf_l, (len * 2) - 2);
                  m_audio->play(true, samplerate);
               }
            }
            else
            {
               if(m_proph->getStereoMode())
               {
                  uint16_t *tmp_l;
                  uint16_t *tmp_r;
                  uint16_t *p_l;
                  uint16_t *p_r;

                  if(m_sound_u8 < 8)
                  {
                     p_l = &m_proph->getSampleData(m_sound_u8)[m_proph->getReleaseLoopStart(m_sound_u8)];
                     p_r = &m_proph->getSampleData(m_sound_u8 + 8)[m_proph->getReleaseLoopStart(m_sound_u8 + 8)];
                  }
                  else
                  {
                     p_l = &m_proph->getSampleData(m_sound_u8 - 8)[m_proph->getReleaseLoopStart(m_sound_u8 - 8)];
                     p_r = &m_proph->getSampleData(m_sound_u8)[m_proph->getReleaseLoopStart(m_sound_u8)];
                  }
                  uint32_t len = m_proph->getReleaseLoopEnd(m_sound_u8) - m_proph->getReleaseLoopStart(m_sound_u8);
                  uint32_t i;
                  tmp_l = m_loop_play_tmp_buf_l;
                  tmp_r = m_loop_play_tmp_buf_r;
                  len++;

                  for(i = 0; i < len; i++)
                  {
                     tmp_l[i] = p_l[i];
                     tmp_r[i] = p_r[i];
                     //wxLogMessage("tmp[%d] = p[%d]", i, i);
                  }

                  for(i = 1; i < (len - 1); i++)
                  {
                     tmp_l[i + (len - 1)] = p_l[(len - 1) - i];
                     tmp_r[i + (len - 1)] = p_r[(len - 1) - i];
                     //wxLogMessage("tmp[%d] = p[%d]", i + (len - 1), (len - 1) - i);
                  }

                  m_audio->setStereoAudioData(m_loop_play_tmp_buf_l, m_loop_play_tmp_buf_r, (len * 2) - 2);
                  m_audio->play(true, samplerate);
               }
               else
               {
                  uint16_t *tmp;
                  uint16_t *p = &m_proph->getSampleData(m_sound_u8)[m_proph->getReleaseLoopStart(m_sound_u8)];
                  uint32_t len = m_proph->getReleaseLoopEnd(m_sound_u8) - m_proph->getReleaseLoopStart(m_sound_u8);
                  uint32_t i;
                  tmp = m_loop_play_tmp_buf_l;
                  len++;

                  for(i = 0; i < len; i++)
                  {
                     tmp[i] = p[i];
                     //wxLogMessage("tmp[%d] = p[%d]", i, i);
                  }

                  for(i = 1; i < (len - 1); i++)
                  {
                     tmp[i + (len - 1)] = p[(len - 1) - i];
                     //wxLogMessage("tmp[%d] = p[%d]", i + (len - 1), (len - 1) - i);
                  }

                  m_audio->setAudioData(m_loop_play_tmp_buf_l, (len * 2) - 2);
                  m_audio->play(true, samplerate);
               }
            }
         }
         else
         {
            // one direction
            if(m_proph->m_sound_param_as[m_sound_u8].val_s.sample_status & 0x08)
            {
               // reverse
               if(m_proph->getStereoMode())
               {
                  uint32_t i;
                  uint16_t *p_l;
                  uint16_t *p_r;
                  
                  if(m_sound_u8 < 8)
                  {
                     p_l = &m_proph->getSampleData(m_sound_u8)[m_proph->getReleaseLoopStart(m_sound_u8)];
                     p_r = &m_proph->getSampleData(m_sound_u8 + 8)[m_proph->getReleaseLoopStart(m_sound_u8 + 8)];
                  }
                  else
                  {
                     p_l = &m_proph->getSampleData(m_sound_u8 - 8)[m_proph->getReleaseLoopStart(m_sound_u8 - 8)];
                     p_r = &m_proph->getSampleData(m_sound_u8)[m_proph->getReleaseLoopStart(m_sound_u8)];
                  }
                  
                  uint32_t len = m_proph->getReleaseLoopEnd(m_sound_u8) - m_proph->getReleaseLoopStart(m_sound_u8);
                  len++;
                  for(i = 0; i < len; i++)
                  {
                     m_loop_play_tmp_buf_l[i] = p_l[(len - 1) - i];
                     m_loop_play_tmp_buf_r[i] = p_r[(len - 1) - i];
                     //wxLogMessage("tmp[%d] = p[%d]", i, (len - 1) - i);
                  }
                  m_audio->setStereoAudioData(m_loop_play_tmp_buf_l, m_loop_play_tmp_buf_r, len);
                  m_audio->play(true, samplerate);
               }
               else
               {
                  uint32_t i;
                  uint16_t *p = &m_proph->getSampleData(m_sound_u8)[m_proph->getReleaseLoopStart(m_sound_u8)];
                  uint32_t len = m_proph->getReleaseLoopEnd(m_sound_u8) - m_proph->getReleaseLoopStart(m_sound_u8);
                  len++;
                  for(i = 0; i < len; i++)
                  {
                     m_loop_play_tmp_buf_l[i] = p[(len - 1) - i];
                     //wxLogMessage("tmp[%d] = p[%d]", i, (len - 1) - i);
                  }
                  m_audio->setAudioData(m_loop_play_tmp_buf_l, len);
                  m_audio->play(true, samplerate);
               }
            }
            else
            {
               if(m_proph->getStereoMode())
               {
                  uint16_t *p_l;
                  uint16_t *p_r;
                  
                  if(m_sound_u8 < 8)
                  {
                     p_l = &m_proph->getSampleData(m_sound_u8)[m_proph->getReleaseLoopStart(m_sound_u8)];
                     p_r = &m_proph->getSampleData(m_sound_u8 + 8)[m_proph->getReleaseLoopStart(m_sound_u8 + 8)];
                  }
                  else
                  {
                     p_l = &m_proph->getSampleData(m_sound_u8 - 8)[m_proph->getReleaseLoopStart(m_sound_u8 - 8)];
                     p_r = &m_proph->getSampleData(m_sound_u8)[m_proph->getReleaseLoopStart(m_sound_u8)];
                  }

                  uint32_t len = m_proph->getReleaseLoopEnd(m_sound_u8) - m_proph->getReleaseLoopStart(m_sound_u8);
                  len++;
                  m_audio->setStereoAudioData(p_l, p_r, len);
                  m_audio->play(true, samplerate);
               }
               else
               {
                  uint16_t *p = &m_proph->getSampleData(m_sound_u8)[m_proph->getReleaseLoopStart(m_sound_u8)];
                  uint32_t len = m_proph->getReleaseLoopEnd(m_sound_u8) - m_proph->getReleaseLoopStart(m_sound_u8);
                  len++;
                  m_audio->setAudioData(p, len);
                  m_audio->play(true, samplerate);
               }
            }      
         }

         m_async_play_active = true;
         break;
      default:
         break;
   }
}


void MySoundParam::stopPlayback(void)
{
   if(m_async_play_active)
   {
      m_audio->stop();
      m_async_play_active = false;
      m_play_button->SetValue(false);
      m_looppanel->getPlayButton()->SetValue(false);
   }
}


void MySoundParam::transferStarted(void)
{

   m_play_button->Disable();
   m_looppanel->getPlayButton()->Disable();
}

void MySoundParam::transferEnded(void)
{
   if(m_proph->getSampleWords(m_sound_u8))
   {
      m_play_button->Enable();
      m_looppanel->getPlayButton()->Enable();
   }
}



void MySoundParam::OnNotebookChanged(wxNotebookEvent& event)
{
   if(m_async_play_active)
   {
      stopPlayback();
   }
   m_topframe->soundNoteBookChanged(m_notebook->GetSelection());
}

void MySoundParam::setSubNotebook(uint8_t selection)
{
   m_notebook->SetSelection(selection);
}

void MySoundParam::OnCopy(wxCommandEvent& event)
{
   SoundCopyDialog dlg(this, wxID_ANY);

   m_copydlg->ShowModal();

   if(m_copydlg->getCopyFlag())
   {
      uint32_t i;

      if(m_copydlg->getCopyParametersOnly())
      {
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.amp_release_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_release_rate;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.amp_2nd_release_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_2nd_release_rate;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.amp_decay_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_decay_rate;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.amp_sustain_level = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_sustain_level;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.amp_attack_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_attack_rate;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.amp_peak_vel_sensitivity = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_peak_vel_sensitivity;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.filt_release_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_release_rate;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.filt_decay_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_decay_rate;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.filt_sustain_level = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_sustain_level;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.filt_attack_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_attack_rate;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.filt_peak_vel_sensitivity = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_peak_vel_sensitivity;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.filt_resonance[0] = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_resonance[0];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.filt_resonance[1] = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_resonance[1];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.filt_cutoff[0] = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_cutoff[0];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.filt_cutoff[1] = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_cutoff[1];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.filt_env_amount = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_env_amount;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.filt_key_tracking = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_key_tracking;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.attack_vel_sensitivity = m_proph->m_sound_param_as[m_sound_u8].val_s.attack_vel_sensitivity;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.release_vel_sensitivity = m_proph->m_sound_param_as[m_sound_u8].val_s.release_vel_sensitivity;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.velocity_start_point = m_proph->m_sound_param_as[m_sound_u8].val_s.velocity_start_point;
         //m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.root_key = m_proph->m_sound_param_as[m_sound_u8].val_s.root_key;
         //m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.tune_table = m_proph->m_sound_param_as[m_sound_u8].val_s.tune_table;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.amp_2nd_release_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_2nd_release_rate;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.amp_2nd_release_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_2nd_release_rate;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.amp_2nd_release_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_2nd_release_rate;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.amp_2nd_release_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_2nd_release_rate;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.amp_2nd_release_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_2nd_release_rate;
         m_proph->updateParamBytesFromStruct();
         if(m_topframe->getOnlineUpdateActive())
         {
            if(m_proph->transferSoundParam2Proph(m_copydlg->getDestination() - 1))
            {
               m_topframe->transferStarted();
            }
         }
      }
      else
      {
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.amp_release_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_release_rate;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.amp_2nd_release_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_2nd_release_rate;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.amp_decay_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_decay_rate;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.amp_sustain_level = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_sustain_level;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.amp_attack_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_attack_rate;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.amp_peak_vel_sensitivity = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_peak_vel_sensitivity;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.filt_release_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_release_rate;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.filt_decay_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_decay_rate;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.filt_sustain_level = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_sustain_level;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.filt_attack_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_attack_rate;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.filt_peak_vel_sensitivity = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_peak_vel_sensitivity;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.filt_resonance[0] = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_resonance[0];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.filt_resonance[1] = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_resonance[1];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.filt_cutoff[0] = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_cutoff[0];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.filt_cutoff[1] = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_cutoff[1];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.filt_env_amount = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_env_amount;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.filt_key_tracking = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_key_tracking;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.attack_vel_sensitivity = m_proph->m_sound_param_as[m_sound_u8].val_s.attack_vel_sensitivity;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.release_vel_sensitivity = m_proph->m_sound_param_as[m_sound_u8].val_s.release_vel_sensitivity;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.velocity_start_point = m_proph->m_sound_param_as[m_sound_u8].val_s.velocity_start_point;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.begin_addr[0] = m_proph->m_sound_param_as[m_sound_u8].val_s.begin_addr[0];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.begin_addr[1] = m_proph->m_sound_param_as[m_sound_u8].val_s.begin_addr[1];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.begin_addr[2] = m_proph->m_sound_param_as[m_sound_u8].val_s.begin_addr[2];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.start_point[0] = m_proph->m_sound_param_as[m_sound_u8].val_s.start_point[0];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.start_point[1] = m_proph->m_sound_param_as[m_sound_u8].val_s.start_point[1];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.start_point[2] = m_proph->m_sound_param_as[m_sound_u8].val_s.start_point[2];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.sustain_loop_start[0] = m_proph->m_sound_param_as[m_sound_u8].val_s.sustain_loop_start[0];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.sustain_loop_start[1] = m_proph->m_sound_param_as[m_sound_u8].val_s.sustain_loop_start[1];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.sustain_loop_start[2] = m_proph->m_sound_param_as[m_sound_u8].val_s.sustain_loop_start[2];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.sustain_loop_end[0] = m_proph->m_sound_param_as[m_sound_u8].val_s.sustain_loop_end[0];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.sustain_loop_end[1] = m_proph->m_sound_param_as[m_sound_u8].val_s.sustain_loop_end[1];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.sustain_loop_end[2] = m_proph->m_sound_param_as[m_sound_u8].val_s.sustain_loop_end[2];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.release_loop_start[0] = m_proph->m_sound_param_as[m_sound_u8].val_s.release_loop_start[0];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.release_loop_start[1] = m_proph->m_sound_param_as[m_sound_u8].val_s.release_loop_start[1];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.release_loop_start[2] = m_proph->m_sound_param_as[m_sound_u8].val_s.release_loop_start[2];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.release_loop_end[0] = m_proph->m_sound_param_as[m_sound_u8].val_s.release_loop_end[0];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.release_loop_end[1] = m_proph->m_sound_param_as[m_sound_u8].val_s.release_loop_end[1];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.release_loop_end[2] = m_proph->m_sound_param_as[m_sound_u8].val_s.release_loop_end[2];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.end_point[0] = m_proph->m_sound_param_as[m_sound_u8].val_s.end_point[0];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.end_point[1] = m_proph->m_sound_param_as[m_sound_u8].val_s.end_point[1];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.end_point[2] = m_proph->m_sound_param_as[m_sound_u8].val_s.end_point[2];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.finish_addr[0] = m_proph->m_sound_param_as[m_sound_u8].val_s.finish_addr[0];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.finish_addr[1] = m_proph->m_sound_param_as[m_sound_u8].val_s.finish_addr[1];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.finish_addr[2] = m_proph->m_sound_param_as[m_sound_u8].val_s.finish_addr[2];
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.sample_status = m_proph->m_sound_param_as[m_sound_u8].val_s.sample_status;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.velocity_start_point = m_proph->m_sound_param_as[m_sound_u8].val_s.velocity_start_point;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.sample_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.sample_rate;         
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.root_key = m_proph->m_sound_param_as[m_sound_u8].val_s.root_key;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.tune_table = m_proph->m_sound_param_as[m_sound_u8].val_s.tune_table;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.amp_2nd_release_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_2nd_release_rate;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.amp_2nd_release_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_2nd_release_rate;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.amp_2nd_release_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_2nd_release_rate;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.amp_2nd_release_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_2nd_release_rate;
         m_proph->m_sound_param_as[m_copydlg->getDestination() - 1].val_s.amp_2nd_release_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_2nd_release_rate;
         m_proph->updateParamBytesFromStruct();

         m_proph->updateStructsFromParamBytes();
         for(i = 0; i < m_proph->getSampleWords(m_sound_u8); i++)
         {
            m_proph->getSampleData(m_copydlg->getDestination() - 1)[i] = m_proph->getSampleData(m_sound_u8)[i];
         }

         m_proph->setSampleName(m_proph->getSampleName(m_sound_u8), m_copydlg->getDestination() - 1);

         m_proph->remapMemory();
      }

      m_proph->updateStructsFromParamBytes();
      
      m_topframe->updateGUI();
      m_topframe->updateWaveView();
   }
}



void MySoundParam::OnCopyParamToAll(wxCommandEvent& event)
{
   copyParamToAll();
}


void MySoundParam::applyParameterToAll(bool flag)
{
   m_synthpanel->applyParameterToAll(flag);
}


void MySoundParam::copyParamToAll(void)
{
   uint8_t i;

   for(i = 0; i < 16; i++)
   {
      m_proph->m_sound_param_as[i].val_s.amp_release_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_release_rate;
      m_proph->m_sound_param_as[i].val_s.amp_2nd_release_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_2nd_release_rate;
      m_proph->m_sound_param_as[i].val_s.amp_decay_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_decay_rate;
      m_proph->m_sound_param_as[i].val_s.amp_sustain_level = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_sustain_level;
      m_proph->m_sound_param_as[i].val_s.amp_attack_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_attack_rate;
      m_proph->m_sound_param_as[i].val_s.amp_peak_vel_sensitivity = m_proph->m_sound_param_as[m_sound_u8].val_s.amp_peak_vel_sensitivity;
      m_proph->m_sound_param_as[i].val_s.filt_2nd_release_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_2nd_release_rate;
      m_proph->m_sound_param_as[i].val_s.filt_release_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_release_rate;
      m_proph->m_sound_param_as[i].val_s.filt_decay_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_decay_rate;
      m_proph->m_sound_param_as[i].val_s.filt_sustain_level = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_sustain_level;
      m_proph->m_sound_param_as[i].val_s.filt_attack_rate = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_attack_rate;
      m_proph->m_sound_param_as[i].val_s.filt_peak_vel_sensitivity = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_peak_vel_sensitivity;
      m_proph->m_sound_param_as[i].val_s.filt_resonance[0] = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_resonance[0];
      m_proph->m_sound_param_as[i].val_s.filt_resonance[1] = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_resonance[1];
      m_proph->m_sound_param_as[i].val_s.filt_cutoff[0] = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_cutoff[0];
      m_proph->m_sound_param_as[i].val_s.filt_cutoff[1] = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_cutoff[1];
      m_proph->m_sound_param_as[i].val_s.filt_env_amount = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_env_amount;
      m_proph->m_sound_param_as[i].val_s.filt_key_tracking = m_proph->m_sound_param_as[m_sound_u8].val_s.filt_key_tracking;
      m_proph->m_sound_param_as[i].val_s.attack_vel_sensitivity = m_proph->m_sound_param_as[m_sound_u8].val_s.attack_vel_sensitivity;
      m_proph->m_sound_param_as[i].val_s.release_vel_sensitivity = m_proph->m_sound_param_as[m_sound_u8].val_s.release_vel_sensitivity;
      m_proph->m_sound_param_as[i].val_s.velocity_start_point = m_proph->m_sound_param_as[m_sound_u8].val_s.velocity_start_point;
      //m_proph->m_sound_param_as[i].val_s.root_key = m_proph->m_sound_param_as[m_sound_u8].val_s.root_key;
      //m_proph->m_sound_param_as[i].val_s.tune_table = m_proph->m_sound_param_as[m_sound_u8].val_s.tune_table;
      m_proph->updateParamBytesFromStruct();
   }

   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferAllSoundParameter2Prophet())
      {
         m_topframe->transferStarted();
      }
   }

   m_proph->updateStructsFromParamBytes();
   
   m_topframe->updateGUI();
   m_topframe->updateWaveView();
}


void MySoundParam::OnGetSound(wxCommandEvent& event)
{
   if(m_proph->transferSound2PC(m_sound_u8))
   {
      m_topframe->transferStarted();
   }
}

void MySoundParam::OnGetSoundParam(wxCommandEvent& event)
{
   if(m_proph->transferSoundParam2PC(m_sound_u8))
   {
      m_topframe->transferStarted();
   }
}

void MySoundParam::OnDeleteSound(wxCommandEvent& event)
{
   stopPlayback();
   m_proph->setSampleName("", m_sound_u8);
   m_proph->deleteSample(m_sound_u8);

   if(m_proph->getStereoMode())
   {
      if(m_sound_u8 < 8)
      {
         m_proph->setSampleName("", m_sound_u8 + 8);
         m_proph->deleteSample(m_sound_u8 + 8);
      }
      else
      {
         m_proph->setSampleName("", m_sound_u8 - 8);
         m_proph->deleteSample(m_sound_u8 - 8);
      }
   }

   resetWaveViewZoom();
   updateWaveView();
}


void MySoundParam::OnMouseRightDown(wxMouseEvent &event)
{
   //PopupMenu(m_menu, event.GetPosition());
}

