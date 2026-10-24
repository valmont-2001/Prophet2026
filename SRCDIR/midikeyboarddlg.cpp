#include "types.h"

#include <wx/wx.h>
#include <wx/string.h>
#include <wx/file.h>
#include <wx/spinctrl.h>
#ifdef _WIN32
    #include <windows.h>
#endif
#include <map>
#include <list>
using namespace std;
#include "midi.h"
#include "clickarea.h"
#include "keyboard.h"
#include "midikeyboard.h"
#include "presetkeyboard.h"
#include "midikeyboarddlg.h"
#include "stopwatch.h"
#include "proph2000.h"
#include "GUILayout.h"
#include "midikeypresetsel.h"
#include "main.h"

#define SLIDER_OPTIONS (wxSL_VERTICAL | wxSL_LABELS | wxSL_INVERSE)

typedef enum
{
   GUI_MODW_CHANGED = 8000
};


BEGIN_EVENT_TABLE(MIDIKeyboardDlg, wxDialog)
   EVT_COMMAND_SCROLL(GUI_MODW_CHANGED, MIDIKeyboardDlg::OnModWheelChange)
END_EVENT_TABLE()


MIDIKeyboardDlg::MIDIKeyboardDlg(const wxString &title, const wxPoint& pos, int w, int h, MyPanel *topframe, MIDI *midi, Proph2000 *proph) :
   wxDialog(NULL, wxID_ANY, title, pos, wxSize(w, h), wxMINIMIZE_BOX | wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN),
   m_topframe(topframe), m_midi(midi), m_inhibit(false)
{
   wxBoxSizer *vsizer = new wxBoxSizer( wxVERTICAL );
   vsizer->AddSpacer(10);

   wxBoxSizer *hsizer = new wxBoxSizer( wxHORIZONTAL );
   hsizer->AddSpacer(10);

   m_presetselection = new MIDIKeyPresetSelImpl(this, this);
   hsizer->Add(m_presetselection);
   vsizer->Add(hsizer);
   vsizer->AddSpacer(10);


   hsizer = new wxBoxSizer( wxHORIZONTAL );
   hsizer->AddSpacer(10);

   m_modwheel = new wxSlider(this, GUI_MODW_CHANGED, 0, 0, 127, wxDefaultPosition, wxSize(50, 150), SLIDER_OPTIONS); 
   hsizer->Add(m_modwheel);
   hsizer->AddSpacer(5);

   //m_keyboard = new MIDIKeyboard(this, wxID_ANY, wxDefaultPosition, wxSize(w - 30, h - 60), midi);
   m_keyboard = new PresetKeyboard(this, wxID_ANY, wxDefaultPosition, wxSize(w - 40 - 50, 150), NULL, proph, midi, 0);
   hsizer->Add(m_keyboard);
   vsizer->Add(hsizer);

   SetSizer(vsizer);

   m_keyboard->setMIDIInhibit(false);
}

MIDIKeyboardDlg::~MIDIKeyboardDlg()
{
   delete m_keyboard;
   delete m_presetselection;
}


void MIDIKeyboardDlg::setMIDIInhibit(bool flag) 
{ 
   m_keyboard->setMIDIInhibit(flag);
   m_inhibit = flag;
}


void MIDIKeyboardDlg::presetSelected(uint8_t preset)
{
   m_topframe->activatePreset(preset);
}

void MIDIKeyboardDlg::activatePreset(uint8_t preset)
{
   m_keyboard->setPreset(preset);
   switch(preset)
   {
      case 0:
         m_presetselection->selectPreset1();
         break;
      case 1:
         m_presetselection->selectPreset2();
         break;
      case 2:
         m_presetselection->selectPreset3();
         break;
      case 3:
         m_presetselection->selectPreset4();
         break;
      case 4:
         m_presetselection->selectPreset5();
         break;
      case 5:
         m_presetselection->selectPreset6();
         break;
      case 6:
         m_presetselection->selectPreset7();
         break;
      case 7:
         m_presetselection->selectPreset8();
         break;
      case 8:
         m_presetselection->selectPreset9();
         break;
      case 9:
         m_presetselection->selectPreset10();
         break;
      case 10:
         m_presetselection->selectPreset11();
         break;
      case 11:
         m_presetselection->selectPreset12();
         break;
      default: break;
   }
}


void MIDIKeyboardDlg::OnModWheelChange(wxScrollEvent &event)
{
   if(m_midi)
   {
      if(!m_inhibit)
      {
         if(!m_midi->isMIDIopen())
         {
            m_midi->init();
         }   
         if(m_midi->isMIDIopen())
         {
            m_midi->sendController(1, m_modwheel->GetValue());
         }
      }
   }
}


