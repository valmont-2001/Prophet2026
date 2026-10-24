#ifndef __THREADH__
#define __THREADH__

class Proph2000;
class MyPanel;
class MIDI;

class MyThread : public wxThread
{
public:
    MyThread(Proph2000 *prop, MyPanel *main, MIDI *midi);

    // thread execution starts here
    virtual void *Entry();

    // called when the thread exits - whether it terminates normally or is
    // stopped with Delete() (but not when it is Kill()ed!)
    virtual void OnExit();

private:
   Proph2000 *m_proph;
   MyPanel *m_main;
   MIDI *m_midi;
};



#endif

