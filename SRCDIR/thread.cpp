#include <wx/wx.h>
#include <wx/thread.h>
#include <wx/dynarray.h>
#include <wx/numdlg.h>
#include <wx/progdlg.h>
#include <wx/spinctrl.h>
#include "thread.h"
#include "types.h"
#include "stopwatch.h"
#include "proph2000.h"
#include "main.h"
#ifdef _WIN32
   #include <windows.h>
#endif
#include <list>
#include <map>
using namespace std;
#include "midi.h"

MyThread::MyThread(Proph2000 *proph, MyPanel *main, MIDI *midi)
        : wxThread(), m_proph(proph), m_main(main), m_midi(midi)
{
}


void MyThread::OnExit()
{
}


void *MyThread::Entry()
{
   while(!TestDestroy())
   {
#ifdef __WXMAC__
      wxWakeUpIdle();
      //do
      {
         wxWakeUpIdle(); // handler functions will be called in eventhandler MyPanel::OnIdle()
      }
      if(!m_main->getTransferInProgress())
      {
         wxThread::Sleep(20);
      }
#else
      while(m_main->getTransferInProgress())
      {
         m_proph->handler();
         m_main->handler();
      }
#endif
      wxThread::Sleep(1);
   }
   return NULL;
}

