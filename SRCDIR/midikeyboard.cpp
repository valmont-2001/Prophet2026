#include "types.h"

#include <wx/wx.h>
#include <wx/string.h>
#include <wx/file.h>
#include <wx/spinctrl.h>
#ifdef _WIN32
    #include <windows.h>
#endif
#include <list>
#include <map>
using namespace std;
#include "midi.h"
#include "clickarea.h"
#include "keyboard.h"
#include "midikeyboard.h"


MIDIKeyboard::MIDIKeyboard(wxWindow *parent, wxWindowID id, const wxPoint& pos, const wxSize& size, MIDI *midi) :
   Keyboard(parent, id, pos, size), m_midi(midi), m_inhibit(false)
{
}


MIDIKeyboard::~MIDIKeyboard()
{
}


void MIDIKeyboard::noteOn(void)
{
   if(!m_inhibit)
   {
      if(!m_midi->isMIDIopen())
      {
         m_midi->init();
      }   
      if(m_midi->isMIDIopen())
      {
         m_midi->sendNoteOn(m_note, m_velocity);
      }
   }
}

void MIDIKeyboard::noteOff(void)
{
   if(!m_inhibit)
   {
      if(m_midi->isMIDIopen())
      {
         m_midi->sendNoteOff(m_note, m_velocity);
      }
   }
}

