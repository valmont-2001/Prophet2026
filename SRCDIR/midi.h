#ifndef __MIDIH__
#define __MIDIH__

//#define USE_PORTMIDI     // define by preprocessor settings!
//#define USE_MSSMIDI      // define by preprocessor settings!

// BurstHW communication:
//#define USE_CURLSERIAL   // define by preprocessor settings!
//#define USE_CSERIAL      // define by preprocessor settings!


#define SERIAL_IN_BUF_SIZE (1024*32)


#ifdef USE_MSSMIDI
   #include <windows.h>
   #include "mss.h"
#endif


#ifndef _CONSOLE
   class wxMutex;
#endif

#ifdef USE_CURLSERIAL
   class CurlSerial;
#endif

#ifdef USE_CSERIAL
   class CSerial;
#endif

class Logger;

class MIDI
{
public:
	MIDI(Logger *log);
	~MIDI();

#ifdef USE_PORTMIDI
   map<int, int> &getInputDeviceList(void) { return m_in_devices_map; };
   map<int, int> &getOutputDeviceList(void) { return m_out_devices_map; };
#endif


#ifdef USE_MSSMIDI
   const list<MIDIINCAPS> &getInputDeviceList(void) const { return m_in_devices; };
   const list<MIDIOUTCAPS> &getOutputDeviceList(void) const { return m_out_devices; };
#endif

   void log(const char *str);
   void logerror(const char *str);

   unsigned char getInDeviceID(void) const { return m_in_device_id; };
   unsigned char getOutDeviceID(void) const { return m_out_device_id; };
   void setInDeviceID(unsigned char id) { m_in_device_id = id; };
   void setOutDeviceID(unsigned char id) { m_out_device_id = id; };

   unsigned char getChannel(void) const { return m_channel; }; // 1..16
   void setChannel(unsigned char ch) { m_channel = ch; }; // 1..16

   void sendMIDIPacket(unsigned char *data, unsigned char len);

   void sendNoteOn(uint8_t note, uint8_t velocity);
   void sendNoteOff(uint8_t note, uint8_t velocity);

   void sendProgramChange(uint8_t value);
   void sendController(uint8_t ctrl_id, uint8_t value);

   bool isMIDIopen(void) const { return m_open; };

   bool useMIDI(void) const { return m_use_midi; };
   void setUseMIDI(bool flag);
   void alwaysBurst(bool flag);
   bool getBurstState(void) {return m_always_burst; };
   uint8_t getBurstHWCOM(void) const { return m_burst_com; }; // 1..
   void setBurstHWCOM(uint8_t port); // 1..
   uint8_t getBurstSpeed(void) const { return m_burst_speed; };
   void setBurstSpeed(uint8_t speed) { m_burst_speed = speed; };

   bool dataAvailable(void);
   unsigned char getDataByte(void);

   void handler(void);

   bool init(void);
   void close(void);
   void flush(void);

   void loadConfig(FILE *file);
   void saveConfig(FILE *file);



private:
#ifdef USE_MSSMIDI
   list<MIDIINCAPS> m_in_devices;
   list<MIDIOUTCAPS> m_out_devices;
#endif   

#ifdef USE_PORTMIDI
   map<int, int> m_in_devices_map;
   map<int, int> m_out_devices_map;
#endif


#ifndef _CONSOLE
   wxMutex *m_in_queue_mutex;
#endif
   unsigned int m_devs_connected;
   unsigned char m_in_device_id;
   unsigned char m_out_device_id;
   unsigned char m_channel;
   unsigned char m_burst_com;
   unsigned char m_burst_speed;
   Logger *m_log;

   uint16_t m_serial_in_in_idx;
   uint16_t m_serial_in_out_idx;
   uint8_t m_serial_in_au[SERIAL_IN_BUF_SIZE];
  
   bool m_open;
   bool m_use_midi;
   bool m_always_burst;

#ifdef USE_CURLSERIAL
   CurlSerial *m_serial;
#endif
#ifdef USE_CSERIAL
   CSerial *m_serial;
#endif


};


#endif
