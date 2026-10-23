#include <iostream>
#include <string>
#include <list>
#include <map>
using namespace std;

#ifndef __WXMAC__
    //#include <windows.h>
#endif

#include <stdio.h>

#include <wx/wx.h>
#include <wx/string.h>
#include <wx/file.h>
#include <wx/spinctrl.h>
#include <wx/notebook.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/wupdlock.h>

#include "GUILayout.h"

#include "types.h"
#include "thread.h"
#include "main.h"
#include "MIDI.h"
#include "stopwatch.h"
#include "proph2000.h"
#include "soundparam.h"
#include "mapparam.h"
#include "presetparam.h"
#include "samples.h"
#include "cfgdlg.h"
#include "midikeyboarddlg.h"
#include "audio.h"
#include "about.h"
#include "wavegenconfig.h"
#include "wavegen.h"
#include "soundselection.h"
#include "proph2000.h"
#include "logger.h"
#include "macstyle.h"


IMPLEMENT_APP(MyApp)

#define WINDOW_TITLE wxT("Prophet 2012")


typedef enum
{
   GUI_IN_DEVICE = 0,
   GUI_OUT_DEVICE,
   GUI_CHANNEL,
   GUI_TX2PC,
   GUI_TX2PROPHET,
   GUI_LOAD,
   GUI_SAVE,
   GUI_MIDIKEYBOARD,
   GUI_ONLINEUPDATE,
   GUI_GETPARAMETER,
   GUI_UPDATE_ALL_PARAMETER,
   GUI_EXTENDEDRAM,
   GUI_DISCARD,
   GUI_SHOWLOG,
   GUI_MAIN_NOTEBOOK_CHANGED,
   GUI_CFG,
   GUI_PRESET_CHANGED,
   GUI_INTELLIGENT_LOOP_POINTS,
   GUI_ABOUT,
   GUI_ABORT,
   GUI_PANIC,
   GUI_MAP_CHANGED,
   GUI_SOUND_TAB_CHANGED,
   GUI_COMPAREFILE,
   GUI_APPLY_PARAMETER_TO_ALL,
   GUI_STEREO_MODE
} GUI_ID_te;


BEGIN_EVENT_TABLE(MyFrame, wxFrame)
   EVT_MENU(GUI_MIDIKEYBOARD, MyFrame::OnMIDIKeyboard)
   EVT_MENU(GUI_ONLINEUPDATE, MyFrame::OnOnlineUpdate)
   EVT_MENU(GUI_STEREO_MODE, MyFrame::OnStereoMode)
   EVT_MENU(GUI_EXTENDEDRAM, MyFrame::OnExtendedMemory)
   EVT_MENU(GUI_INTELLIGENT_LOOP_POINTS, MyFrame::OnIntelligentLoopPoints)
   EVT_MENU(GUI_DISCARD, MyFrame::OnDiscard)
   EVT_MENU(GUI_TX2PC, MyFrame::OnTx2PC)
   EVT_MENU(GUI_TX2PROPHET, MyFrame::OnTx2Prophet)
   EVT_MENU(GUI_GETPARAMETER, MyFrame::OnGetParameter)
   EVT_MENU(GUI_UPDATE_ALL_PARAMETER, MyFrame::OnUpdateAllParameter)
   EVT_MENU(GUI_LOAD, MyFrame::OnLoad)
   EVT_MENU(GUI_SAVE, MyFrame::OnSave)
   EVT_MENU(GUI_COMPAREFILE, MyFrame::OnCompareFile)
   EVT_MENU(GUI_SHOWLOG, MyFrame::OnShowLog)
   EVT_MENU(GUI_CFG, MyFrame::OnConfig)
   EVT_MENU(GUI_ABOUT, MyFrame::OnAbout)
   EVT_MENU(GUI_ABORT, MyFrame::OnAbort)
   EVT_MENU(GUI_PANIC, MyFrame::OnPanic)
   EVT_MENU(GUI_APPLY_PARAMETER_TO_ALL, MyFrame::OnApplyParameterToAll)
   EVT_DROP_FILES(MyFrame::OnDropFiles)
   EVT_SIZE(MyFrame::OnSizeEvent)
#ifdef __WXMAC__
   EVT_CLOSE(MyFrame::OnClose)
#endif
END_EVENT_TABLE()

FILE *configfile;

// Location of Prophet2012.cfg
static wxString configFileName(bool write)
{
   wxString cfgfilename;
#ifdef __WXMAC__
   // ~/Library/Application Support/Prophet2012/ - the app bundle itself may be
   // read only (disk image, /Applications) and is replaced by every update
   wxFileName dir(wxStandardPaths::Get().GetUserDataDir(), wxEmptyString);
   if(write)
   {
      dir.Mkdir(wxS_DIR_DEFAULT, wxPATH_MKDIR_FULL);
   }
   cfgfilename = dir.GetPath(wxPATH_GET_SEPARATOR) + "Prophet2012.cfg";
   if(!write && !wxFileExists(cfgfilename))
   {
      // fall back to the location used by older versions (inside the bundle)
      wxString old = wxStandardPaths::Get().GetExecutablePath();
      old = old.SubString(0, old.rfind("Contents/") + 8) + "Resources/Prophet2012.cfg";
      if(wxFileExists(old))
      {
         cfgfilename = old;
      }
   }
#else
   cfgfilename = wxStandardPaths::Get().GetDataDir();
   cfgfilename += "\\";
   cfgfilename += "Prophet2012.cfg";
#endif
   return cfgfilename;
}

wxString argfilename;

// `Main program' equivalent, creating windows and returning main app frame
bool MyApp::OnInit()
{
   if(argc == 2)
   {
      argfilename = argv[1];
      if(argfilename.find(".p2k") == wxString::npos)
      {
         argfilename = "";
      }
   }

// wxSystemOptions::SetOption(wxT("msw.notebook.themed-background"), 0);
    // Create the main frame window
#ifdef __WXMAC__
   MacSetupStyle();
   frame = new MyFrame((wxFrame *) NULL, wxID_ANY, WINDOW_TITLE, wxDefaultPosition, wxSize(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT), wxMINIMIZE_BOX | wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX /*| wxCLIP_CHILDREN*/);
#else
   frame = new MyFrame((wxFrame *) NULL, wxID_ANY, WINDOW_TITLE, wxDefaultPosition, wxSize(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT), wxRESIZE_BORDER | wxMINIMIZE_BOX | wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX /*| wxCLIP_CHILDREN*/);
#endif

    frame->Centre(wxBOTH);

    // Show the frame
    frame->Show(true);

    SetTopWindow(frame);

#ifdef __WXMAC__
    // "Quit" in the application menu (Cmd+Q) is sent to the active window (e.g. the
    // MIDI keyboard or the log window). Handled here on application level, as
    // otherwise wxWidgets only leaves the main loop and the settings are not saved
    // in MyFrame::OnClose().
    Bind(wxEVT_MENU, [this](wxCommandEvent &WXUNUSED(event))
    {
       if(frame)
       {
          frame->Close(true);
       }
    }, wxID_EXIT);
#endif

    return true;
}




/* XPM */
static char *logo[] = {
/* columns rows colors chars-per-pixel */
"16 16 16 1",
"  c #040204",
". c #048284",
"X c #848284",
"o c #FCFAFC",
"O c #FC0204",
"+ c #BCBABC",
"@ c black",
"# c black",
"$ c black",
"% c black",
"& c black",
"* c black",
"= c black",
"- c black",
"; c black",
": c black",
/* pixels */
"..XXXXXXXXXX....",
"..Xooo+oo+oXX...",
"..Xooo+oo+oXoX..",
"..X++++++++    .",
"..XoXXOOOOOX+o .",
"..XoXXOOX+OO+o .",
"..X+++OO++OO++ .",
"..XoXXOOX+OO+o .",
"..XoXXOOOOOX+o .",
"..X+++OO++++++ .",
"..XoXXOOX+XX+o .",
"..XoXXOOX+XX+o .",
"..X+++++++++++ .",
"..Xooo+oo+oo+o .",
"..Xooo+oo+oo+o .",
"..             ."
};


MyFrame::MyFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, 
                 const wxSize& size, long style, const wxString& name) :
   wxFrame(parent, id, title, pos, size, style, name), m_memory_overloaded(false),
   m_panel(NULL),
#ifdef __WXMAC__
    m_font_size(12)
#else
    m_font_size(8)
#endif
{
   m_log_window = new wxLogWindow(this, wxT("Log"), false, false);
#ifdef __WXMAC__
   MacFixLogWindowMenu(m_log_window);
#endif
#if defined(DEBUG_VERSION) && !defined(BURT)
   m_log_window->Show();
#endif
   m_log = new Logger;

   m_log->log(VERSION_STR);

   wxIcon icon(logo);
   SetIcon(icon);
   SetStatusText(wxT("Prophet 2012 - (c) Marius Goebel"));

   DragAcceptFiles(true);

   SetMaxSize(size);
//   SetMinSize(size);   

   wxString cfgfilename = configFileName(false);

   configfile = fopen(cfgfilename.mb_str(), "r");

   if(configfile)
   {
      uint8_t t;
      if(fread(&t, 1, 1, configfile) == 1)
      {
         m_font_size = t;
      }
   }
   else
   {
      wxLogMessage("Could not read config file");
   }
   

   SetFont(wxFont(m_font_size, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

   wxMenu *fileMenu = new wxMenu;
   fileMenu->Append(GUI_LOAD, wxT("&Load"));
   fileMenu->Append(GUI_SAVE, wxT("&Save"));
   fileMenu->AppendSeparator();
   fileMenu->Append(GUI_DISCARD, wxT("&Discard"));
   fileMenu->AppendSeparator();
#if defined(DEBUG_VERSION)
   fileMenu->Append(GUI_COMPAREFILE, wxT("&Compare with file"));
   fileMenu->AppendSeparator();
#endif
   fileMenu->Append(GUI_ABOUT, wxT("&About"));

   wxMenu *transferMenu = new wxMenu;
   transferMenu->Append(GUI_TX2PC, wxT("&Transfer to Computer"));
   transferMenu->AppendSeparator();
   transferMenu->Append(GUI_TX2PROPHET, wxT("&Transfer to Prophet"));
   transferMenu->AppendSeparator();
#if defined(DEBUG_VERSION)
   transferMenu->Append(GUI_ABORT, wxT("&Abort"));
   transferMenu->AppendSeparator();
#endif
   transferMenu->Append(GUI_GETPARAMETER, wxT("&Get all parameter"));
   transferMenu->AppendSeparator();
   transferMenu->Append(GUI_UPDATE_ALL_PARAMETER, wxT("&Send all parameter"));
   transferMenu->AppendSeparator();
   transferMenu->Append(GUI_PANIC, wxT("&Send Panic"));
   transferMenu->AppendSeparator();
   transferMenu->AppendCheckItem(GUI_ONLINEUPDATE, wxT("Online"));   

   wxMenu *optionsMenu = new wxMenu;
   optionsMenu->AppendCheckItem(GUI_EXTENDEDRAM, wxT("Extended Memory (512MW)"));
   optionsMenu->AppendCheckItem(GUI_INTELLIGENT_LOOP_POINTS, wxT("Intelligent Loop Points"));
   optionsMenu->AppendCheckItem(GUI_APPLY_PARAMETER_TO_ALL, wxT("Apply parameter changes to all"));
   optionsMenu->AppendCheckItem(GUI_STEREO_MODE, wxT("Stereo mode"));   
   optionsMenu->AppendSeparator();
   optionsMenu->Append(GUI_CFG, wxT("&Config"));  

   wxMenu *viewMenu = new wxMenu;
   viewMenu->Append(GUI_MIDIKEYBOARD, wxT("MIDI Keyboard"));
   viewMenu->AppendSeparator();
   viewMenu->Append(GUI_SHOWLOG, wxT("Show Log"));

   m_menubar = new wxMenuBar( wxMB_DOCKABLE );
   m_menubar->Append(fileMenu, wxT("&File"));
   m_menubar->Append(transferMenu, wxT("&Transfer"));
   m_menubar->Append(optionsMenu, wxT("&Options"));
   m_menubar->Append(viewMenu, wxT("&View"));
   SetMenuBar(m_menubar);

#ifdef __WXMAC__
   m_panel = new MyPanel(this, pos.x, pos.y, size.GetWidth(), size.GetHeight()-20, this, m_log);
#else
   m_panel = new MyPanel(this, pos.x, pos.y, size.GetWidth(), size.GetHeight()-80, this, m_log);
#endif
   
   m_panel->setIntelligentLoopPoints(true);
   m_menubar->Check(GUI_INTELLIGENT_LOOP_POINTS, true);

   if(configfile)
   {
      uint8_t val;
      val = 0;
      fread(&val, 1, 1, configfile);
      if(val)
      {
         m_menubar->Check(GUI_ONLINEUPDATE, true);
         m_panel->setOnlineUpdateActive(true);
      }
      else
      {
         m_menubar->Check(GUI_ONLINEUPDATE, false);
         m_panel->setOnlineUpdateActive(false);
      }

      fread(&val, 1, 1, configfile);
      if(val)
      {
         m_menubar->Check(GUI_EXTENDEDRAM, true);
         m_panel->setExtendedMemory(true);
      }
      else
      {
         m_menubar->Check(GUI_EXTENDEDRAM, false);
         m_panel->setExtendedMemory(false);
      }

      fread(&val, 1, 1, configfile);
      if(val)
      {
         m_menubar->Check(GUI_INTELLIGENT_LOOP_POINTS, true);
         m_panel->setIntelligentLoopPoints(true);
      }
      else
      {
         m_menubar->Check(GUI_INTELLIGENT_LOOP_POINTS, false);
         m_panel->setIntelligentLoopPoints(false);
      }

      fread(&val, 1, 1, configfile);
      if(val)
      {
         m_panel->setRXHandshake(true);
      }
      else
      {
         m_panel->setRXHandshake(false);
      }

      fclose(configfile);
   }

   this->CreateStatusBar();

   m_about = new About(this);

   if(argfilename != "")
   {
      m_panel->load(argfilename.mb_str());
   }

   m_panel->updateGUI();
}

MyFrame::~MyFrame()
{
   delete m_log;
}


void MyFrame::updateMenuState(Proph2000 *proph)
{
   if(proph->getStereoMode())
   {
      m_menubar->Check(GUI_STEREO_MODE, true);
   }
   else
   {
      m_menubar->Check(GUI_STEREO_MODE, false);
   }
}



void MyFrame::OnDropFiles(wxDropFilesEvent &event)
{
   m_panel->load(event.m_files[0].mb_str());
}


void MyFrame::OnApplyParameterToAll(wxCommandEvent& event)
{
   m_panel->applyParameterToAll(event.IsChecked());
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
   m_about->ShowModal();
}

void MyFrame::OnAbort(wxCommandEvent& event)
{
   m_panel->OnAbort();
}

void MyFrame::OnPanic(wxCommandEvent& event)
{
   m_panel->panic();
}


void MyFrame::OnMIDIKeyboard(wxCommandEvent& event)
{
   m_panel->MIDIkeyboardDialog();
}


void MyFrame::OnOnlineUpdate(wxCommandEvent& event)
{
   m_panel->setOnlineUpdateActive(event.IsChecked());
}


void MyFrame::OnStereoMode(wxCommandEvent& event)
{
   m_panel->OnStereoMode(event.IsChecked());
}

void MyFrame::OnExtendedMemory(wxCommandEvent& event)
{
   m_panel->setExtendedMemory(event.IsChecked());
}


void MyFrame::OnIntelligentLoopPoints(wxCommandEvent& event)
{
   m_panel->setIntelligentLoopPoints(event.IsChecked());
}


void MyFrame::OnShowLog(wxCommandEvent& event)
{
   m_log_window->Show();
}

void MyFrame::OnDiscard(wxCommandEvent& event)
{
   m_panel->OnDiscard();
}


void MyFrame::OnTx2PC(wxCommandEvent& event)
{
   m_panel->OnTx2PC();
}


void MyFrame::OnTx2Prophet(wxCommandEvent& event)
{
   m_panel->OnTx2Prophet();
}


void MyFrame::OnGetParameter(wxCommandEvent& event)
{
   m_panel->OnGetParameter();
}

void MyFrame::OnUpdateAllParameter(wxCommandEvent& event)
{
   m_panel->OnUpdateAllParameter();
}

void MyFrame::transferStarted(void)
{
   SetStatusText(wxT("Transfer in Progress"));
   m_menubar->Enable(GUI_TX2PC, false);
   m_menubar->Enable(GUI_TX2PROPHET, false);
   m_menubar->Enable(GUI_GETPARAMETER, false);
   m_menubar->Enable(GUI_LOAD, false);
   m_menubar->Enable(GUI_SAVE, false);
   m_menubar->Enable(GUI_DISCARD, false);
}


void MyFrame::transferEnded(void)
{
   SetStatusText(wxT(""));
   m_menubar->Enable(GUI_TX2PC, true);
   if(!m_memory_overloaded)
   {
      m_menubar->Enable(GUI_TX2PROPHET, true);
   }
   m_menubar->Enable(GUI_GETPARAMETER, true);
   m_menubar->Enable(GUI_LOAD, true);
   m_menubar->Enable(GUI_SAVE, true);
   m_menubar->Enable(GUI_DISCARD, true);
}

void MyFrame::enableTransfer2ProphetControls(bool flag)
{
   m_menubar->Enable(GUI_TX2PROPHET, flag);
}

void MyFrame::OnLoad(wxCommandEvent& event)
{
   m_panel->OnLoad();
}

void MyFrame::OnCompareFile(wxCommandEvent& event)
{
   m_panel->OnCompareFile();
}


void MyFrame::OnSave(wxCommandEvent& event)
{
   m_panel->OnSave();
}

void MyFrame::OnConfig(wxCommandEvent& event)
{
   m_panel->OnConfig();
}


void MyFrame::OnSizeEvent(wxSizeEvent& event)
{
   //wxLogMessage("f:%dx%d", event.GetSize().GetWidth(), event.GetSize().GetHeight());

   if(m_panel)
   {
      m_panel->OnSizeEvent(event.GetSize().GetWidth(), event.GetSize().GetHeight());
   }
}

#ifdef __WXMAC__
void MyFrame::OnClose(wxCloseEvent &WXUNUSED(event))
{
   // closing the main window (also via its close button) quits the application
   m_panel->saveConfig();
   Destroy();
}
#endif


BEGIN_EVENT_TABLE(MyPanel, wxScrolledWindow)
   EVT_NOTEBOOK_PAGE_CHANGED(GUI_MAIN_NOTEBOOK_CHANGED, MyPanel::OnMainNotebookChanged)
   EVT_NOTEBOOK_PAGE_CHANGED(GUI_PRESET_CHANGED, MyPanel::OnPresetChanged)
   EVT_RADIOBOX(GUI_SOUND_TAB_CHANGED, MyPanel::OnSoundTabChanged)
   EVT_IDLE(MyPanel::OnIdle)
END_EVENT_TABLE()


MyPanel::MyPanel(wxFrame *frame, int x, int y, int w, int h, MyFrame *topframe,Logger *log) : 
wxScrolledWindow( frame, wxID_ANY, wxPoint(x, y), wxSize(w, h) ),
m_topframe(topframe), m_onlineupdate_active(false),
m_transfer_in_progress(false), m_sound_param(NULL), m_map_param(NULL), m_preset_param(NULL), m_samples(NULL), m_midikeyboard(NULL), 
m_sound_selection(NULL), m_log(log), m_midi(NULL), m_proph(NULL)
{
//   uint8_t i;
   wxWindowUpdateLocker noUpdates(this);

   m_orig_window_size = wxSize(w, h);

   SetMaxSize(wxSize(w, h));

   //SetVirtualSize(wxSize(w, h));

   m_midi = new MIDI(log);
   m_midi->loadConfig(configfile);

   m_audio = new Audio();
   m_audio->loadConfig(configfile);

   wxBoxSizer *vsizer = new wxBoxSizer( wxVERTICAL );

   m_proph = new Proph2000(m_midi, this, m_log);

   m_cfg_dlg = new CfgDlg(this, wxID_ANY, m_midi, m_proph, m_audio, m_topframe);

#ifdef __WXMAC__
   m_wavegen = new WaveGen(this, wxID_ANY, 0, m_proph, this, m_audio, wxDefaultPosition, wxSize(1024, 690 + 20), wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN);
#else
   m_wavegen = new WaveGen(this, wxID_ANY, 0, m_proph, this, m_audio, wxDefaultPosition, wxSize(1024, 690), wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN);
#endif

   m_notebook = new wxNotebook(this, GUI_MAIN_NOTEBOOK_CHANGED, wxDefaultPosition, wxSize(w, h), wxNB_NOPAGETHEME, " Prophet2012 " );

   // m_notebook->SetBackgroundColour(wxColour(0,0,0));
   
   m_notebook->AddPage(createSamplesPanel(m_notebook), wxT(" Samples "));
   m_notebook->AddPage(createSoundPanel(m_notebook), wxT(" Sounds "));
   m_notebook->AddPage(createMapPanel(m_notebook), wxT(" Maps "));
   m_notebook->AddPage(createPresetPanel(m_notebook), wxT(" Presets "));
   
   vsizer->Add(m_notebook);
   SetSizer(vsizer);

   m_midikeyboard = new MIDIKeyboardDlg(wxT("MIDI Keyboard"), wxDefaultPosition, 1024, 240, this, m_midi, m_proph);

#ifdef __WXMAC__
   MacAdaptLayout(m_notebook);
   MacAdaptLayout(m_wavegen);
   MacAdaptLayout(m_midikeyboard);
#endif

   if(configfile)
   {
      uint8_t val = 0;
      fread(&val, 1, 1, configfile);
      if(val)
      {
         m_midikeyboard->Show();
      }
      m_wavegen->loadConfig(configfile);
   }

   m_thread = new MyThread(m_proph, this, m_midi);
   m_thread->Create();
   m_thread->SetPriority(WXTHREAD_MAX_PRIORITY);
   m_thread->Run();

   m_normal_window_size = GetMaxSize();

#if 0
      m_proph->load("1.p2k");
      updateGUI();
      m_sound_param->resetWaveViewZoom();
      m_sound_param->updateWaveView();
#endif
}


MyPanel::~MyPanel()
{
//   uint8_t i;
#ifndef __WXMAC__
   saveConfig();
#endif

   m_thread->Delete();
   wxThread::Sleep(150);

   delete m_audio;

   delete m_sound_param;

   delete m_map_param;

   delete m_preset_param;

   delete m_cfg_dlg;

   delete m_samples;
   delete m_proph;

   if(m_midi->isMIDIopen())
   {
      m_midi->close();
   }

   delete m_midikeyboard;
   delete m_midi;
}

void MyPanel::saveConfig(void)
{
   wxString cfgfilename = configFileName(true);
   
   configfile = fopen(cfgfilename.mb_str(), "w");
   if(configfile)
   {
      uint8_t val;
      
      val = m_topframe->getFontSize();
      fwrite(&val, 1, 1, configfile);
      
      m_midi->saveConfig(configfile);
      
      m_audio->saveConfig(configfile);
      
      if(m_midikeyboard->IsShown())
      {
         val = 1;
      }
      else
      {
         val = 0;
      }
      
      fwrite(&val, 1, 1, configfile);
      
      m_wavegen->saveConfig(configfile);
      
      if(m_onlineupdate_active)
      {
         val = 1;
      }
      else
      {
         val = 0;
      }
      
      fwrite(&val, 1, 1, configfile);
      
      if(m_proph->getExtendedMemory())
      {
         val = 1;
      }
      else
      {
         val = 0;
      }
      
      fwrite(&val, 1, 1, configfile);
      
      
      if(m_sound_param->getIntelligentLoopPoints())
      {
         val = 1;
      }
      else
      {
         val = 0;
      }
      
      fwrite(&val, 1, 1, configfile);
      
      if(m_proph->getRXHandshakeFlag())
      {
         val = 1;
      }
      else
      {
         val = 0;
      }
      
      fwrite(&val, 1, 1, configfile);
      
      fclose(configfile);
   }
   else
   {
      wxLogMessage("Could not save config file");
   }
}

void MyPanel::OnIdle(wxIdleEvent &event)
{
#ifdef __WXMAC__
   if(m_proph)
   {
      m_proph->handler();
   }
   handler();
   if(m_midi)
   {
      m_midi->handler();
   }
#endif
}


void MyPanel::applyParameterToAll(bool flag)
{
   m_sound_param->applyParameterToAll(flag);
}

void MyPanel::OnAbort(void)
{
   m_proph->abort();
}


void MyPanel::OnSizeEvent(uint16_t w, uint16_t h)
{
   uint8_t h1 = 0;
   uint8_t h2 = 0;
   uint8_t v1 = 0;
   uint8_t v2 = 0;
   bool smallerview = false;

   //wxLogMessage("o: %dx%d   i:%dx%d", m_orig_window_size.GetWidth(), m_orig_window_size.GetHeight(), w, h);

   if(h < m_orig_window_size.GetHeight())
   {
      v1 = 20;
      v2 = 50;
      smallerview = true;
   }

   if(w < m_orig_window_size.GetWidth())
   {
      h1 = 20;
      h2 = 50;
      smallerview = true;
   }

   //wxLogMessage("SetScrollbars(%d, %d, %d, %d)", h1, v1, h2, v2);
   SetScrollbars(h1, v1, h2, v2);
   if(smallerview)
   {
      SetSize(wxSize(w - 10, h - 76));
   }
   else
   {
      SetSize(m_normal_window_size);
   }
}


void MyPanel::activateSoundOnGui(uint8_t sound_u8)
{
   m_notebook->SetSelection(1);
   m_sound_param->activateSound(sound_u8);
   m_sound_selection->makeActive(sound_u8);
   m_proph->sendSelectRequest();
}

void MyPanel::activateMapOnGui(uint8_t map_u8)
{
   m_notebook->SetSelection(2);
   m_map_param->activateMap(map_u8);
   m_map_param->makeActive(map_u8);
   m_proph->sendSelectRequest();
}

void MyPanel::activatePreset(uint8_t preset_u8)
{
   m_preset_param->activatePreset(preset_u8);
   m_midikeyboard->activatePreset(preset_u8);

   if(m_onlineupdate_active)
   {
      if(!m_transfer_in_progress)
      {
         if(!m_midi->isMIDIopen())
         {
            m_midi->init();
         }   
         if(m_midi->isMIDIopen())
         {
            m_midi->sendProgramChange(preset_u8);
         }
      }
   }
   m_proph->sendSelectRequest();
}


void MyPanel::OnSoundTabChanged(wxCommandEvent& event)
{
   m_sound_param->activateSound(event.GetSelection());
   m_proph->sendSelectRequest();
}


wxPanel* MyPanel::createSoundPanel(wxWindow *parent)
{
   wxPanel *retval;
   wxWindow *child_parent;
//   uint8_t i;

	retval = new wxPanel(parent , wxID_ANY /*, wxDefaultPosition,wxSize(240, 320) */ );
   child_parent = retval;

   wxBoxSizer *vsizer = new wxBoxSizer( wxVERTICAL );

   wxBoxSizer *hsizer = new wxBoxSizer( wxHORIZONTAL );
   hsizer->AddSpacer(5);

   m_sound_param = new MySoundParam(child_parent, this, m_proph, 0, m_audio, m_wavegen, m_log);
   m_sound_selection = new SoundSelectionPanelImpl(child_parent, m_sound_param, m_proph);
   hsizer->Add(m_sound_selection);
   vsizer->Add(hsizer);

   hsizer = new wxBoxSizer( wxHORIZONTAL );
   hsizer->AddSpacer(5);
   hsizer->Add(m_sound_param);
   vsizer->Add(hsizer);
   vsizer->AddSpacer(10);

   retval->SetSizer( vsizer );

   return retval;
}

wxPanel* MyPanel::createMapPanel(wxWindow *parent)
{
   wxPanel *retval;
   wxWindow *child_parent;
//   uint8_t i;
   wxString str;

	retval = new wxPanel(parent , wxID_ANY /*, wxDefaultPosition,wxSize(240, 320) */ );
   child_parent = retval;

   wxBoxSizer *vsizer = new wxBoxSizer( wxVERTICAL );
   // vsizer->AddSpacer(10); // Vertical offset of Child Panel

   wxBoxSizer *hsizer = new wxBoxSizer( wxHORIZONTAL );
   hsizer->AddSpacer(5); // Horizontal offset of Child Panel

   m_map_param = new MyMapParam(child_parent, this, m_proph, 0);
   hsizer->Add(m_map_param);

   vsizer->Add(hsizer);

   retval->SetSizer( vsizer );

   return retval;
}

wxPanel* MyPanel::createPresetPanel(wxWindow *parent)
{
   wxPanel *retval;
   wxWindow *child_parent;
//   uint8_t i;

	retval = new wxPanel(parent , wxID_ANY /*, wxDefaultPosition,wxSize(240, 320) */ );
   child_parent = retval;

   wxBoxSizer *vsizer = new wxBoxSizer( wxVERTICAL );


   wxBoxSizer *hsizer = new wxBoxSizer( wxHORIZONTAL );
   hsizer->AddSpacer(5);
   
   m_preset_param = new MyPresetParam(child_parent, this, m_proph, 0);
   hsizer->Add(m_preset_param);


   vsizer->Add(hsizer);
 //  vsizer->AddSpacer(10);

   retval->SetSizer( vsizer );

   return retval;
}

wxPanel* MyPanel::createSamplesPanel(wxWindow *parent)
{
   wxPanel *retval;
   wxWindow *child_parent;

	retval = new wxPanel(parent , wxID_ANY /*, wxDefaultPosition,wxSize(240, 320) */ );
   child_parent = retval;

   wxBoxSizer *vsizer = new wxBoxSizer( wxVERTICAL );
   vsizer->AddSpacer(10);

   wxBoxSizer *hsizer = new wxBoxSizer( wxHORIZONTAL );
   hsizer->AddSpacer(10);

   m_samples = new Samples(child_parent, this, m_proph, m_audio, m_wavegen, m_log);

   hsizer->Add(m_samples);


   vsizer->Add(hsizer);
//   vsizer->AddSpacer(10);

   retval->SetSizer( vsizer );

   return retval;
}

void MyPanel::enableTransfer2ProphetControls(bool flag)
{
   if(!m_transfer_in_progress)
   {
      if(flag)
      {
         m_topframe->enableTransfer2ProphetControls(true);
         m_topframe->setMemoryOverloaded(false);
      }
      else
      {
         m_topframe->enableTransfer2ProphetControls(false);
         m_topframe->setMemoryOverloaded(true);
      }
   }
}


void MyPanel::OnPresetChanged(wxNotebookEvent& event)
{
   if(getOnlineUpdateActive())
   {
      if(!m_transfer_in_progress)
      {
         if(!m_midi->isMIDIopen())
         {
            m_midi->init();
         }   
         if(m_midi->isMIDIopen())
         {
            m_midi->sendProgramChange(event.GetSelection());
         }
      }
   }
   m_proph->sendSelectRequest();
}


void MyPanel::setExtendedMemory(bool flag) 
{ 
   if(flag)
   {
      wxLogMessage("Extended memory");
   }
   else
   {
      wxLogMessage("Standard memory");
   }
   m_proph->setExtendedMemory(flag);
   m_sound_param->updateGUI();
   m_samples->updateGUI();
}


void MyPanel::setRXHandshake(bool flag)
{
   if(flag)
   {
      wxLogMessage("RX handshake active");
   }
   else
   {
      wxLogMessage("RX handshake inactive");
   }
   m_proph->setRXHandshakeFlag(flag);
}


void MyPanel::setIntelligentLoopPoints(bool flag)
{
   m_sound_param->setIntelligentLoopPoints(flag);
}


void MyPanel::setOnlineUpdateActive(bool flag)
{
   m_onlineupdate_active = flag;
   m_proph->sendSelectRequest();
}


void MyPanel::OnStereoMode(bool flag)
{
   m_proph->setStereoMode(flag);
   if(flag)
   {
      initStereoModeDefaults();
   }
   updateGUI();
}

void MyPanel::initStereoModeDefaults(void)
{
   uint8_t i;
   for(i = 0; i < 12; i++)
   {
      m_proph->m_preset_param_as[i].val_s.midi_mode = 3; // mode 3B
      m_proph->m_preset_param_as[i].val_s.keyboard_mode = 4; // layer mode
   }
   m_proph->updateParamBytesFromStruct();
}


void MyPanel::transferStarted(void)
{
   m_topframe->transferStarted();

   m_midikeyboard->setMIDIInhibit(true);
   m_transfer_in_progress = true;

   m_sound_param->transferStarted();

   m_map_param->transferStarted();

   m_preset_param->transferStarted();
}


void MyPanel::transferEnded(void)
{
//   uint8_t i;

   m_topframe->transferEnded();

   m_transfer_in_progress = false;
   
   m_midikeyboard->setMIDIInhibit(false);

   m_sound_param->transferEnded();

   m_map_param->transferEnded();

   m_preset_param->transferEnded();
}


void MyPanel::OnConfig(void)
{
   m_cfg_dlg->ShowModal();
   m_proph->sendSelectRequest();
}


void MyPanel::OnTx2PC(void)
{
   if(m_proph->transfer2PC())
   {
      transferStarted();
   } 
   m_proph->sendSelectRequest();
}


void MyPanel::OnTx2Prophet(void)
{
   if(m_proph->transfer2Prophet())
   {
      transferStarted();
   }
   m_proph->sendSelectRequest();
}


void MyPanel::OnGetParameter(void)
{
   if(m_proph->transferParameter2PC())
   {
      transferStarted();
   }
   m_proph->sendSelectRequest();
}


void MyPanel::OnUpdateAllParameter(void)
{
   if(m_proph->transferParameter2Prophet())
   {
      transferStarted();
   }
   m_proph->sendSelectRequest();
}

void MyPanel::OnLoad(void)
{
   m_sound_param->setUpdateLoopParamsActive(false); // to avoid unwanted GUI events

   wxString wildcards =
                 wxString::Format
                 (
                     wxT("Data files (*.p2k)|*.p2k"),
                     wxFileSelectorDefaultWildcardStr,
                     wxFileSelectorDefaultWildcardStr
                 );

   wxFileDialog indialog(this, wxT("Load Data File"),
                     wxEmptyString, wxEmptyString, wildcards,
                     wxFD_OPEN);

   if (indialog.ShowModal() == wxID_OK)
   {
      if(!m_proph->load(indialog.GetPath().mb_str()))
      {
         wxMessageDialog edialog(this, wxT("Could not load Data File"), wxT("Error"));
         edialog.ShowModal();
      }
      else
      {
         wxString str;
         str = WINDOW_TITLE;
         str += wxT(" - ");
         str += indialog.GetFilename();
         m_topframe->SetTitle(str);
         updateGUI();
         m_sound_param->resetWaveViewZoom();
         m_sound_param->updateWaveView();
      }
   }

   m_sound_param->setUpdateLoopParamsActive(true); // to avoid unwanted GUI events
   m_proph->sendSelectRequest();

   m_topframe->updateMenuState(m_proph);
   
#ifdef __WXMAC__
   refreshNotebook();
#endif
}

#ifdef __WXMAC__
void MyPanel::refreshNotebook(void)
{
   uint8_t selected_nb = m_notebook->GetSelection();
   if(selected_nb)
   {
      m_notebook->SetSelection(0); // fix refresh bug
      m_notebook->SetSelection(selected_nb); // fix refresh bug
   }
   else
   {
      m_notebook->SetSelection(1); // fix refresh bug
      m_notebook->SetSelection(0); // fix refresh bug
   }   
}
#endif

void MyPanel::OnCompareFile(void)
{
   wxString wildcards =
                 wxString::Format
                 (
                     wxT("Data files (*.p2k)|*.p2k"),
                     wxFileSelectorDefaultWildcardStr,
                     wxFileSelectorDefaultWildcardStr
                 );

   wxFileDialog indialog(this, wxT("Compare Data File with memory content"),
                     wxEmptyString, wxEmptyString, wildcards,
                     wxFD_OPEN);

   if (indialog.ShowModal() == wxID_OK)
   {
      Proph2000 *ref = new Proph2000(m_log);
      ref->load(indialog.GetPath().mb_str());
      m_proph->doCompare(*ref);
      delete ref;
   }
}

void MyPanel::load(const char *filename)
{
   if(m_proph->load(filename))
   {
      wxString str;
      str = WINDOW_TITLE;
      str += wxT(" - ");
      str += filename;
      m_topframe->SetTitle(str);
      updateGUI();
      m_sound_param->resetWaveViewZoom();
      m_sound_param->updateWaveView();
   }
   m_proph->sendSelectRequest();
}

void MyPanel::OnSave(void)
{
   wxFileDialog outdialog(this,
                  wxT("Save Data File"),
                  wxEmptyString,
                  wxEmptyString,
                  wxT("Data Files (*.p2k)|*.p2k"),
                  wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
   if (outdialog.ShowModal() == wxID_OK)
   {
      wxString filen = outdialog.GetPath();
      if(filen.find(wxT(".p2k")) == wxString::npos)
      {
         filen += wxT(".p2k");
      }
      if(m_proph->save(filen.mb_str()))
      {
         wxString str;
         str = WINDOW_TITLE;
         str += wxT(" - ");
         str += outdialog.GetFilename();
         m_topframe->SetTitle(str);
      }
      else
      {
         wxMessageDialog edialog(this, wxT("Could not save Data File"), wxT("Error"));
         edialog.ShowModal();
      }
   }
   m_proph->sendSelectRequest();
}


void MyPanel::updateGUI(void)
{
   uint8_t i;

   m_cfg_dlg->updateGUI();

   if(m_sound_selection)
   {
      m_sound_selection->updateGUI();
      for(i = 0; i < 16; i++)
      {
         if(m_proph->getSampleWords(i))
         {
            m_sound_selection->setEmptySlot(i, false);
         }
         else
         {
            m_sound_selection->setEmptySlot(i, true);
         }
      }
   }

   if(m_sound_param)
   {
      m_sound_param->updateGUI();
   }

   if(m_map_param)
   {
      m_map_param->updateGUI();
   }

   if(m_preset_param)
   {
      m_preset_param->updateGUI();
   }
   
   if(m_samples)
   {
      m_samples->updateGUI();
   }
   if(m_midikeyboard)
   {
      m_midikeyboard->Refresh(true);
   }
}


void MyPanel::updateWaveView(void)
{
   m_sound_param->updateWaveView();
}

void MyPanel::resetWaveViewZoom(void)
{
   m_sound_param->resetWaveViewZoom();
}


void MyPanel::handler(void)
{
}


void MyPanel::transferFinished(bool closemidi)
{
   transferEnded();

   m_proph->updateStructsFromParamBytes();

   if(closemidi && m_midi->isMIDIopen())
   {
      m_midi->close();
      wxLogMessage("Closing MIDI IF");
   }
   switch(m_proph->getTransferError())
   {
      case Proph2000::TRX_NOERROR:
         break;
      case Proph2000::TRX_TIMEOUT:
         {
            wxMessageDialog edialog(this, wxT("Communication Timeout! Please check Settings and Cables!"), wxT("Timeout"));
            edialog.ShowModal();
         }
         break;
      case Proph2000::TRX_NO_RESPONSE:
         {
            wxMessageDialog edialog(this, wxT("Communication Problem! Please check Settings and Cables!"), wxT("No Response"));
            edialog.ShowModal();
         }
         break;
      default:
         break;
   }

   updateGUI();

   if(m_proph->getLastTransferJob() == Proph2000::PROPH_RX_SINGLE_SOUND_PARAM)
   {
      m_sound_param->updateWaveView();
   }

   m_samples->updateGUI();

#ifdef __WXMAC__
   refreshNotebook();
#endif
}


void MyPanel::MIDIkeyboardDialog(void)
{
   m_midikeyboard->Show();
}


void MyPanel::OnDiscard(void)
{
   m_topframe->SetTitle(WINDOW_TITLE);
   m_proph->clear();
   if(m_proph->getStereoMode())
   {
      initStereoModeDefaults();
   }
   updateGUI();
   m_sound_param->resetWaveViewZoom();
   m_sound_param->updateWaveView();
#ifdef __WXMAC__
   refreshNotebook();
#endif
}


void MyPanel::OnMainNotebookChanged(wxNotebookEvent& event)
{
   updateGUI();
   if(m_sound_param)
   {
      m_sound_param->stopPlayback();
   }
   m_proph->sendSelectRequest();
}


void MyPanel::soundNoteBookChanged(uint8_t selection)
{
   updateGUI();
   if(m_sound_param)
   {
      m_sound_param->setSubNotebook(selection);
   }
   m_proph->sendSelectRequest();
}


void MyPanel::panic(void)
{
   if(m_midi->init())
   {
//      uint8_t i;
/*      m_midi->sendController(123,0x7F);   Not supported */
      m_proph->sendPanic();
   }
}


