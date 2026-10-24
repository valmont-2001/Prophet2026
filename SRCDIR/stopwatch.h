#ifndef __STOPWATCHH__
#define __STOPWATCHH__


class StopWatch
{
public:
   StopWatch();
   ~StopWatch();

   void Start(void);
   long Time(void);

   static void Sleep_ms(long ms);

private:
   wxStopWatch m_stopwatch;
};


#endif
