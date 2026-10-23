#include <list>
#include <map>
#include <string>
using namespace std;

#include "types.h"
#include "midi.h"

#ifndef _CONSOLE
   #include "wx/wx.h"
#endif

#ifdef USE_CURLSERIAL
   #include "CurlSerial.h"
#endif
#ifdef USE_CSERIAL
   #include "Serial.h"
#endif

#include <stdio.h>
#include "logger.h"

#if defined(DEBUG_VERSION)
   #define LOG_STREAM_TO_FILE
#endif

#ifdef USE_PORTMIDI
   #include "portmidi.h"
   #include "porttime.h"

   #define MIDI_SYSEX 0xf0
   #define MIDI_EOX 0xf7
   #define MIDI_APP_BUFSIZE 65534

   volatile unsigned char m_midi_rx_buf[MIDI_APP_BUFSIZE];
   volatile unsigned int m_midi_rx_in_idx;
   volatile unsigned int m_midi_rx_out_idx;

   static PmStream *midi_in;
   static PmStream *midi_out;
#endif


#ifdef LOG_STREAM_TO_FILE
   FILE *mf;
   uint16_t mtbytes = 0;
   uint16_t mtlfcnt = 0;
   bool mttx = true;
#endif



MIDI::MIDI(Logger *log) : m_in_device_id(0), m_out_device_id(0), m_channel(1), m_open(false), m_use_midi(true),
   m_burst_com(1), m_burst_speed(0x10), m_log(log)
{
	unsigned i;

#ifdef USE_MSSMIDI
   midi_setLogger(m_log);
#endif

#ifdef LOG_STREAM_TO_FILE
   mf = fopen("MIDI_data.txt", "w");
#endif

#ifndef _CONSOLE
   m_in_queue_mutex = new wxMutex();
#endif

#ifdef USE_PORTMIDI
   m_midi_rx_in_idx = 0;
   m_midi_rx_out_idx = 0;
   unsigned char in_idx = 0;
   unsigned char out_idx = 0;


   Pm_Initialize();

   m_devs_connected = Pm_CountDevices();
   //m_log->log("m_devs_connected %d", m_devs_connected);

   for(i = 0; i < m_devs_connected; i++)
   {
      //m_log->log("%d %s", i, Pm_GetDeviceInfo(i)->name);
      if(Pm_GetDeviceInfo(i)->input)
      {
         m_in_devices_map[in_idx] = i;
         in_idx++;
         //m_log->log(" input");
      }
      if(Pm_GetDeviceInfo(i)->output)
      {
         m_out_devices_map[out_idx] = i;
         out_idx++;
         //m_log->log(" output");
      }
   }
#endif


#ifdef USE_MSSMIDI
   MIDIINCAPS inputCapabilities;
   MIDIOUTCAPS outputCapabilities;

	m_devs_connected = midiInGetNumDevs();

   for (i = 0; i < m_devs_connected; i++) 
   {
      midiInGetDevCaps(i, &inputCapabilities, sizeof(inputCapabilities));
      m_in_devices.push_back(inputCapabilities);
      //m_log->log("Input devices:[%d] %s", i, inputCapabilities.szPname);
   }

	m_devs_connected = midiOutGetNumDevs();

   for (i = 0; i < m_devs_connected; i++) 
   {
      midiOutGetDevCaps(i, &outputCapabilities, sizeof(outputCapabilities));
      m_out_devices.push_back(outputCapabilities);
      //m_log->log("Output devices:[%d] %s", i, outputCapabilities.szPname);
   }
#endif

   m_serial_in_in_idx = 0;
   m_serial_in_out_idx = 0;

#ifdef USE_CURLSERIAL
   m_serial = new CurlSerial();
   m_serial->setComPort("COM1");
   m_serial->setSerialSpeed("256000");
#endif
#ifdef USE_CSERIAL
   m_serial = new CSerial();
#endif
}


MIDI::~MIDI()
{
#ifdef LOG_STREAM_TO_FILE
   fclose(mf);
#endif
   if(m_open)
   {
      close();
   }
#ifdef USE_PORTMIDI
   Pm_Terminate();
#endif

#ifndef _CONSOLE
   delete m_in_queue_mutex;
#endif
#ifdef USE_CURLSERIAL
   delete m_serial;
#endif
#ifdef USE_CSERIAL
   delete m_serial;
#endif
}


void MIDI::log(const char *str)
{
#ifdef LOG_STREAM_TO_FILE
   fprintf(mf, "\n%s\n", str);
#endif
}


void MIDI::logerror(const char *str)
{
#ifdef LOG_STREAM_TO_FILE
   fprintf(mf, "\n!!! %s\n", str);
#endif
}

void MIDI::setUseMIDI(bool flag)
{
   if(isMIDIopen())
   {
      close();
   }
   m_use_midi = flag;
}

void MIDI::alwaysBurst(bool flag)
{
   m_always_burst = flag;
   if (m_always_burst)
   {
      /*Set Burst_HW to the configured speed */
         uint8_t baud_au8[5];
         m_log->log("sendBaudRate(%d)", m_burst_speed);
         baud_au8[0] = 0xf0;
         baud_au8[1] = 0x01;
         baud_au8[2] = 0x7a;
         baud_au8[3] = m_burst_speed;
         baud_au8[4] = 0xf7;
         sendMIDIPacket(baud_au8, sizeof(baud_au8));
//         resetRx();
   }
   else
   {
         uint8_t baud_au8[5];
         m_log->log("sendBaudRate(%d)", 0x10);
         baud_au8[0] = 0xf0;
         baud_au8[1] = 0x01;
         baud_au8[2] = 0x7a;
         baud_au8[3] = 0x10;
         baud_au8[4] = 0xf7;
         sendMIDIPacket(baud_au8, sizeof(baud_au8));
//         resetRx();
   }
}

void MIDI::setBurstHWCOM(uint8_t port)
{
   char ctmp[100];
   if(isMIDIopen())
   {
      close();
   }
   m_burst_com = port;
   sprintf(ctmp, "COM%d", port);
#ifdef USE_CURLSERIAL
   m_serial->setComPort(ctmp);
#endif
}


bool MIDI::init(void)
{
   bool retval = false;

   if(!m_open)
   {
      char ret = 1;

      if(m_use_midi)
      {
#ifdef USE_PORTMIDI
         unsigned char latency = 0;
         PmError err;

         unsigned char indev = 0;
         unsigned char outdev = 0;

         map<int, int>::iterator myItr = m_in_devices_map.begin();
         while((myItr != m_in_devices_map.end()) && (!indev))
         {
            if((*myItr).first == m_in_device_id)
            {
               indev = (*myItr).second;
            }
            ++myItr;
         }

         myItr = m_out_devices_map.begin();
         while((myItr != m_out_devices_map.end()) && (!outdev))
         {
            if((*myItr).first == m_out_device_id)
            {
               outdev = (*myItr).second;
            }
            ++myItr;
         }

         //m_log->log("in:%d out:%d", indev, outdev);

         // PortMidi 2.x doesn't range check the device id in Pm_OpenInput/Pm_OpenOutput
         // and crashes if no (or not this) MIDI device is connected
         const PmDeviceInfo *in_info = Pm_GetDeviceInfo(indev);
         const PmDeviceInfo *out_info = Pm_GetDeviceInfo(outdev);
         if(!in_info || !in_info->input || !out_info || !out_info->output)
         {
            m_log->log("MIDI::init() no MIDI device available");
         }
         else if((err = Pm_OpenInput(&midi_in, indev, NULL, 512, NULL, NULL)) == pmNoError)
         {
            err = Pm_OpenOutput(&midi_out, outdev, NULL, 0, NULL, NULL, latency);
            if(err == pmNoError)
            {
               ret = 0;
            }
            else
            {
               m_log->log("MIDI::init() out %s", Pm_GetErrorText(err));
               Pm_Close(midi_in);
            }
         }
         else
         {
            m_log->log("MIDI::init() in %s", Pm_GetErrorText(err));
         }
#endif



#ifdef USE_MSSMIDI
         //m_log->log("MIDI::init() in:%d out:%d", m_in_device_id, m_out_device_id);

         ret = midi_init(m_in_device_id, m_out_device_id);

         //m_log->log("MIDI::init() returns %d", ret);
#endif

         if(ret == 0)
         {
            retval = true;
            m_open = true;
         }
         else
         {
#ifdef _CONSOLE
            m_log->log("Could not open MIDI device");
#else
            wxMessageDialog edialog(NULL, wxT("Could not open MIDI device"), wxT("Error"));
            edialog.ShowModal();
#endif
         }
      }
      else
      {
#ifdef USE_CURLSERIAL
         if(m_serial->initSerial())
         {
            m_open = true;
            retval = true;
         }
         else
         {
            wxMessageDialog edialog(NULL, wxT("Could not open serial device"), wxT("Error"));
            edialog.ShowModal();
         }
#endif
#ifdef USE_CSERIAL
         if(m_serial->IsOpen())
         {
            m_serial->Close();
         }

         char ctmp[100];
         sprintf(ctmp, "COM%d", m_burst_com);
		 wxString s = ctmp;

         if(m_serial->Open(s.wc_str()) == ERROR_SUCCESS)
         {
            m_serial->Setup(CSerial::EBaud256000,CSerial::EData8,CSerial::EParNone,CSerial::EStop1);
            m_serial->SetupHandshaking(CSerial::EHandshakeOff);

            m_open = true;
            retval = true;
         }
         else
         {
#ifdef _CONSOLE
            m_log->log("Could not open serial device");
#else
            wxMessageDialog edialog(NULL, wxT("Could not open serial device"), wxT("Error"));
            edialog.ShowModal();
#endif
         }
#endif
      }
   }
   else
   {
      retval = true;
   }

   return retval;
}


void MIDI::loadConfig(FILE *file)
{
   if(file)
   {
      uint8_t t;
      fread(&m_in_device_id, 1, 1, file);
      fread(&m_out_device_id, 1, 1, file);
      fread(&m_channel, 1, 1, file);
      fread(&t, 1, 1, file);
      if(t)
      {
         m_use_midi = true;
         m_log->log("Use MIDI");
      }
      else
      {
         m_use_midi = false;
         m_log->log("Use burst HW");
      }
      fread(&t, 1, 1, file);
      setBurstHWCOM(t);
      fread(&m_burst_speed, 1, 1, file);
   }
}


void MIDI::saveConfig(FILE *file)
{
   if(file)
   {
      uint8_t t;
      fwrite(&m_in_device_id, 1, 1, file);
      fwrite(&m_out_device_id, 1, 1, file);
      fwrite(&m_channel, 1, 1, file);
      if(m_use_midi)
      {
         t = 1;
      }
      else
      {
         t = 0;
      }
      fwrite(&t, 1, 1, file);
      fwrite(&m_burst_com, 1, 1, file);
      fwrite(&m_burst_speed, 1, 1, file);
   }
}


void MIDI::sendMIDIPacket(unsigned char *data, unsigned char len)
{
   uint8_t i;
#ifdef LOG_STREAM_TO_FILE
   mttx = true;

   mtbytes = 0;
   mtlfcnt = 0;

   fprintf(mf, "\nTX to Prophet:\n\t");
   for(i = 0; i < len; i++)
   {
      fprintf(mf, "%.2X ", data[i]);
      mtbytes++;
      mtlfcnt++;
      if(mtlfcnt >= 18)
      {
         mtlfcnt = 0;
         fprintf(mf, "\n\t");
      }
      if(data[i] == 0xf7)
      {
         fprintf(mf, "\npacket size %d\n", mtbytes);
         mtbytes = 0;
      }
   }
#endif

   if(m_use_midi)
   {
#ifdef USE_PORTMIDI
      Pm_WriteSysEx(midi_out, 0, data);
#endif
#ifdef USE_MSSMIDI
      midi_senddata(data, len);
#endif
   }
   else
   {
      if(m_open)
      {
#ifdef USE_CURLSERIAL
         m_serial->writeSerial(data, len);
#endif
#ifdef USE_CSERIAL
         m_serial->Write(data, len);
#endif
      }
   }
}

void MIDI::close(void)
{
   if(m_use_midi)
   {
#ifdef USE_PORTMIDI
      if(m_open)
      {
         Pm_Close(midi_out);
         Pm_Close(midi_in);
      }
#endif
#ifdef USE_MSSMIDI
      midi_exit(0);
#endif
   }
   else
   {
#ifdef USE_CURLSERIAL
      if(m_serial->isSerialOpen())
      {
         m_serial->closeSerial();
      }
#endif
#ifdef USE_CSERIAL
      if(m_serial->IsOpen())
      {
         m_serial->Close();
      }
#endif
   }
   m_open = false;
}


void MIDI::sendProgramChange(uint8_t value)
{
   if(m_open)
   {
      for(int i = 0; i < 16; i++)
      {
         if(m_use_midi)
         {
#ifdef USE_PORTMIDI
            PmEvent buffer;
            buffer.message = Pm_Message(0xC0 + i, value, 0);
            Pm_Write(midi_out, &buffer, 1);
#endif
#ifdef USE_MSSMIDI
            midi_programchange(i, value);
#endif
         }
         else
         {
            uint8_t ctmp[2];
            ctmp[0] = 0xC0 + i;
            ctmp[1] = value;
#ifdef USE_CURLSERIAL
            m_serial->writeSerial(ctmp, 2);
#endif
#ifdef USE_CSERIAL
            m_serial->Write(ctmp, 2);
#endif
         }
      }
   }
}


void MIDI::sendController(uint8_t ctrl_id, uint8_t value)
{
   if(m_open)
   {
      if(m_use_midi)
      {
#ifdef USE_PORTMIDI
         PmEvent buffer;
         buffer.message = Pm_Message(0xB0 + (m_channel - 1), ctrl_id, value);
         Pm_Write(midi_out, &buffer, 1);      
#endif
#ifdef USE_MSSMIDI
         midi_controlchange(m_channel - 1, ctrl_id, value);
#endif
      }
      else
      {
         uint8_t ctmp[3];
         ctmp[0] = 0xB0 + (m_channel - 1);
         ctmp[1] = ctrl_id;
         ctmp[2] = value;
#ifdef USE_CURLSERIAL
         m_serial->writeSerial(ctmp, 3);
#endif
#ifdef USE_CSERIAL
         m_serial->Write(ctmp, 3);
#endif
      }
   }
}


void MIDI::flush(void)
{
   if(m_open)
   {
      if(m_use_midi)
      {
#ifdef USE_PORTMIDI
         int count;
         PmEvent in_event;
         do
         {
            count = Pm_Read(midi_in, &in_event, 1);
         }
         while(count == 1);
#ifndef _CONSOLE
         m_in_queue_mutex->Lock();
#endif
         m_midi_rx_in_idx = 0;
         m_midi_rx_out_idx = 0;
#ifndef _CONSOLE
         m_in_queue_mutex->Unlock();
#endif
#endif
#ifdef USE_MSSMIDI
         midi_flush();
#ifndef _CONSOLE
         m_in_queue_mutex->Lock();
#endif
         m_serial_in_in_idx = 0;
         m_serial_in_out_idx = 0;
#ifndef _CONSOLE
         m_in_queue_mutex->Unlock();
#endif
#endif
      }
      else
      {
#ifndef _CONSOLE
         m_in_queue_mutex->Lock();
#endif
         m_serial_in_in_idx = 0;
         m_serial_in_out_idx = 0;
#ifndef _CONSOLE
         m_in_queue_mutex->Unlock();
#endif
#ifdef USE_CURLSERIAL
         m_serial->Purge();
#endif
#ifdef USE_CSERIAL
         m_serial->Purge();
#endif
      }
   }
}

bool MIDI::dataAvailable(void)
{
   bool retval = false;
   if(m_open)
   {
      if(m_use_midi)
      {
#ifdef USE_PORTMIDI
#ifndef _CONSOLE
         m_in_queue_mutex->Lock();
#endif
         if(m_midi_rx_in_idx != m_midi_rx_out_idx)
         {
            retval = true;
         }
#ifndef _CONSOLE
         m_in_queue_mutex->Unlock();
#endif
#endif
#ifdef USE_MSSMIDI
#ifndef _CONSOLE
         m_in_queue_mutex->Lock();
#endif
         if(m_serial_in_in_idx != m_serial_in_out_idx)
         {
            retval = true;
         }
#ifndef _CONSOLE
         m_in_queue_mutex->Unlock();
#endif
#endif
      }
      else
      {
#ifndef _CONSOLE
         m_in_queue_mutex->Lock();
#endif
         if(m_serial_in_in_idx != m_serial_in_out_idx)
         {
            retval = true;
         }
#ifndef _CONSOLE
         m_in_queue_mutex->Unlock();
#endif
      }
   }
   return retval;
}


unsigned char MIDI::getDataByte(void)
{
   unsigned char data = 0;

   if(m_use_midi)
   {
#ifdef USE_PORTMIDI
      if(m_open)
      {
#ifndef _CONSOLE
         m_in_queue_mutex->Lock();
#endif
         data = m_midi_rx_buf[m_midi_rx_out_idx];
         m_midi_rx_out_idx++;
         if(m_midi_rx_out_idx >= MIDI_APP_BUFSIZE)
         {
            m_midi_rx_out_idx = 0;
         }
#ifndef _CONSOLE
         m_in_queue_mutex->Unlock();
#endif
      }
#endif
#ifdef USE_MSSMIDI
      if(m_open)
      {
#ifndef _CONSOLE
         m_in_queue_mutex->Lock();
#endif
         data = m_serial_in_au[m_serial_in_out_idx];
         m_serial_in_out_idx++;
         if(m_serial_in_out_idx >= SERIAL_IN_BUF_SIZE)
         {
            m_serial_in_out_idx = 0;
         }
#ifndef _CONSOLE
         m_in_queue_mutex->Unlock();
#endif
      }
#endif
   }
   else
   {
#ifndef _CONSOLE
      m_in_queue_mutex->Lock();
#endif
      data = m_serial_in_au[m_serial_in_out_idx];
      m_serial_in_out_idx++;
      if(m_serial_in_out_idx >= SERIAL_IN_BUF_SIZE)
      {
         m_serial_in_out_idx = 0;
      }
#ifndef _CONSOLE
      m_in_queue_mutex->Unlock();
#endif
   }

#ifdef LOG_STREAM_TO_FILE
   if(mttx)
   {
      mtbytes = 0;
      mtlfcnt = 0;
      mttx = false;
      fprintf(mf, "\nRX from Prophet:\n\t");
   }

   fprintf(mf, "%.2X ", data);
   mtbytes++;
   mtlfcnt++;
   if(mtlfcnt >= 18)
   {
      mtlfcnt = 0;
      fprintf(mf, "\n\t");
   }
   if(data == 0xf7)
   {
      fprintf(mf, "\npacket size %d\n\n", mtbytes);
      mtbytes = 0;
   }
#endif
   return data;
}

void MIDI::sendNoteOn(uint8_t note, uint8_t velocity)
{
   if(m_use_midi)
   {
#ifdef USE_PORTMIDI
      PmEvent buffer;
      buffer.message = Pm_Message(0x90 + (m_channel - 1), note, velocity);
      Pm_Write(midi_out, &buffer, 1);
#endif
#ifdef USE_MSSMIDI
      midi_noteon(m_channel - 1, note, velocity);
#endif
   }
   else
   {
      uint8_t ctmp[3];
      ctmp[0] = 0x90 + (m_channel - 1);
      ctmp[1] = note;
      ctmp[2] = velocity;
#ifdef USE_CURLSERIAL
      m_serial->writeSerial(ctmp, 3);
#endif
#ifdef USE_CSERIAL
      m_serial->Write(ctmp, 3);
#endif
   }
}

void MIDI::sendNoteOff(uint8_t note, uint8_t velocity)
{
   if(m_use_midi)
   {
#ifdef USE_PORTMIDI
      PmEvent buffer;
      buffer.message = Pm_Message(0x80 + (m_channel - 1), note, velocity);
      Pm_Write(midi_out, &buffer, 1);
#endif
#ifdef USE_MSSMIDI
      midi_noteoff(m_channel - 1, note, velocity);
#endif
   }
   else
   {
      uint8_t ctmp[3];
      ctmp[0] = 0x80 + (m_channel - 1);
      ctmp[1] = note;
      ctmp[2] = velocity;
#ifdef USE_CURLSERIAL
      m_serial->writeSerial(ctmp, 3);
#endif
#ifdef USE_CSERIAL
      m_serial->Write(ctmp, 3);
#endif
   }
}


void MIDI::handler(void)
{
   if(m_use_midi)
   {
#ifdef USE_PORTMIDI
      if(m_open)
      {
         PmEvent in_event;
         int shift;
         int count;
         do
         {
            count = Pm_Read(midi_in, &in_event, 1);
            if(count < 0)
            {
               // e.g. pmBufferOverflow: in_event holds no data
               m_log->log("MIDI input error: %s", Pm_GetErrorText((PmError)count));
               break;
            }
            if(count)
            {
              // reset for every event: otherwise the EOX of the previous message stops
              // the loop below and the first bytes (incl. 0xf0) of the next sysex
              // message get lost, if both are read within one call
              int data = 0;
              /* compare 4 bytes of data until you reach an eox */
              for (shift = 0; shift < 32 && (data != MIDI_EOX); shift += 8) 
              //for (shift = 0; shift < 32; shift += 8) 
              {
				     if(((in_event.message >> shift) & 0xFF) != 0xff)
				     {
#ifndef _CONSOLE
                    m_in_queue_mutex->Lock();
#endif
                    m_midi_rx_buf[m_midi_rx_in_idx++] = data = (in_event.message >> shift) & 0xFF;
                     //m_log->log("rx: 0x%.2x", data);
                     if(m_midi_rx_in_idx >= MIDI_APP_BUFSIZE) 
                     {
                        m_midi_rx_in_idx = 0;
                     }
#ifndef _CONSOLE
                     m_in_queue_mutex->Unlock();
#endif
                 }
              }
            }
         }while(count);
      }
#endif
#ifdef USE_MSSMIDI
      if(m_open)
      {
         while(midi_check())
         {
            unsigned char db = midi_receivedata();

            if(db != 0xff)
            {
#ifndef _CONSOLE
               m_in_queue_mutex->Lock();
#endif
               m_serial_in_au[m_serial_in_in_idx] = db;
               m_serial_in_in_idx++;
               if(m_serial_in_in_idx >= SERIAL_IN_BUF_SIZE)
               {
                  m_serial_in_in_idx = 0;
               }
#ifndef _CONSOLE
               m_in_queue_mutex->Unlock();
#endif
            }
         }
      }
#endif
   }
   else
   {
      if(m_open)
      {
         unsigned char ctmp[2];
#ifdef USE_CURLSERIAL
         uint8_t len = 1;
#else
   #ifdef USE_CSERIAL
         DWORD len = 1;
   #else
         uint8_t len = 0; // dummy;
   #endif
#endif
         do
         {
#ifdef USE_CURLSERIAL
            len = m_serial->readSerial(ctmp, 1);
#endif
#ifdef USE_CSERIAL
            m_serial->Read(ctmp, 1, &len, 0, 1);
#endif
            if(len)
            {
               uint8_t i;
               for(i = 0; i < len; i++)
               {
                  if(ctmp[i] != 0xff)
                  {
#ifndef _CONSOLE
                     m_in_queue_mutex->Lock();
#endif
                     m_serial_in_au[m_serial_in_in_idx] = ctmp[i];
                     m_serial_in_in_idx++;
                     if(m_serial_in_in_idx >= SERIAL_IN_BUF_SIZE)
                     {
                        m_serial_in_in_idx = 0;
                     }
#ifndef _CONSOLE
                     m_in_queue_mutex->Unlock();
#endif
                  }
               }
            }
         }while(len);
      }
   }
}

