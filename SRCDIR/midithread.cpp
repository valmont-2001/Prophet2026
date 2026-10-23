#include <wx/wx.h>
#include <wx/thread.h>
#include <wx/dynarray.h>
#include <wx/numdlg.h>
#include <wx/progdlg.h>
#include <wx/spinctrl.h>
#include "midithread.h"
#include "types.h"
#include "stopwatch.h"
#include "proph2000.h"
#include "main.h"
#ifndef __WXMAC__
   #include <windows.h>
#endif
#include <list>
#include <map>
using namespace std;
#include "midi.h"

MIDIThread::MIDIThread(Proph2000 *proph, MyPanel *main, MIDI *midi)
        : wxThread(), m_proph(proph), m_main(main), m_midi(midi)
{
}


void MIDIThread::OnExit()
{
}

void *MIDIThread::Entry()
{

   while(!TestDestroy())
   {
      m_midi->handler();
#if 0
      wxThread::Sleep(1);
#else
      if(m_midi->useMIDI())
      {
         if(m_main->getTransferInProgress())
         {
            wxThread::Sleep(0);
         }
         else
         {
            wxThread::Sleep(1);
         }
      }
      else
      {
         wxThread::Sleep(1);
      }
#endif
   }
   return NULL;
}

