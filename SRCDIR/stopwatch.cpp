   #include <wx/wx.h>

#include "stopwatch.h"


StopWatch::StopWatch()
{
}

StopWatch::~StopWatch()
{
}

void StopWatch::Start(void)
{
   m_stopwatch.Start();
}

void StopWatch::Sleep_ms(long ms)
{
   wxThread::Sleep(ms);
}



long StopWatch::Time(void)
{
   return m_stopwatch.Time();
}
