#include <list>
#include <map>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

#include "wx/wx.h"
#include "types.h"
#include "midi.h"
#include "logger.h"

// File d'attente de reception (alimentee par le callback RtMidi, vidée par getDataByte)
#define MIDI_APP_BUFSIZE 65534
static volatile unsigned char m_midi_rx_buf[MIDI_APP_BUFSIZE];
static volatile unsigned int m_midi_rx_in_idx = 0;
static volatile unsigned int m_midi_rx_out_idx = 0;

static MIDI *midi_instance = NULL;

static void mymidiincallback(double deltatime, std::vector<unsigned char> *message, void *userData)
{
   if(midi_instance)
   {
      midi_instance->inCallback(deltatime, message, userData);
   }
}


MIDI::MIDI(Logger *log) : m_midi_out(NULL), m_midi_in(NULL), m_in_device_id(0), m_out_device_id(0), m_channel(1),
   m_log(log), m_open(false), m_trace(false)
{
   m_in_queue_mutex = new wxMutex();
   midi_instance = this;

   try
   {
#ifdef __MACOSX__
      m_midi_out = new RtMidiOut(RtMidi::MACOSX_CORE);
      m_midi_in = new RtMidiIn(RtMidi::MACOSX_CORE);
#else
      m_midi_out = new RtMidiOut();
      m_midi_in = new RtMidiIn();
#endif
      m_midi_in->setCallback(&mymidiincallback);
      m_midi_in->ignoreTypes(false, true, true); // SysEx conserve; timing et active sensing ignores

      unsigned int i;
      unsigned int count = m_midi_out->getPortCount();
      for(i = 0; i < count; i++)
      {
         m_out_devices_map[i] = i;
      }
      count = m_midi_in->getPortCount();
      for(i = 0; i < count; i++)
      {
         m_in_devices_map[i] = i;
      }
   }
   catch(RtMidiError &error)
   {
      error.printMessage();
   }
}


MIDI::~MIDI()
{
   if(m_open)
   {
      close();
   }
   midi_instance = NULL;
   delete m_midi_out;
   delete m_midi_in;
   delete m_in_queue_mutex;
}


bool MIDI::init(void)
{
   if(m_open)
   {
      return true;
   }
   if(!m_midi_in || !m_midi_out)
   {
      return false;
   }

   unsigned int indev = 0;
   unsigned int outdev = 0;

   map<int, int>::iterator it = m_in_devices_map.find(m_in_device_id);
   if(it != m_in_devices_map.end())
   {
      indev = it->second;
   }
   it = m_out_devices_map.find(m_out_device_id);
   if(it != m_out_devices_map.end())
   {
      outdev = it->second;
   }

   try
   {
      m_midi_in->openPort(indev);
      m_midi_out->openPort(outdev);
      m_open = true;
   }
   catch(RtMidiError &error)
   {
      error.printMessage();
      wxMessageDialog edialog(NULL, wxT("Could not open MIDI device"), wxT("Error"));
      edialog.ShowModal();
   }
   return m_open;
}


void MIDI::close(void)
{
   if(m_open)
   {
      try
      {
         m_midi_in->closePort();
         m_midi_out->closePort();
      }
      catch(RtMidiError &error)
      {
         error.printMessage();
      }
   }
   m_open = false;
}


// Le fichier de configuration garde l'ancien format (6 octets) pour rester lisible par l'ancienne version:
// entree, sortie, canal, [reserve: 1], [reserve: 1], [reserve: 0x10]
void MIDI::loadConfig(FILE *file)
{
   if(file)
   {
      uint8_t reserved;
      fread(&m_in_device_id, 1, 1, file);
      fread(&m_out_device_id, 1, 1, file);
      fread(&m_channel, 1, 1, file);
      fread(&reserved, 1, 1, file);
      fread(&reserved, 1, 1, file);
      fread(&reserved, 1, 1, file);
   }
}


void MIDI::saveConfig(FILE *file)
{
   if(file)
   {
      const uint8_t reserved[3] = { 1, 1, 0x10 };
      fwrite(&m_in_device_id, 1, 1, file);
      fwrite(&m_out_device_id, 1, 1, file);
      fwrite(&m_channel, 1, 1, file);
      fwrite(reserved, 1, sizeof(reserved), file);
   }
}


void MIDI::sendMIDIPacket(unsigned char *data, unsigned char len)
{
   if(!m_open)
   {
      return;
   }
   std::vector<unsigned char> message(data, data + len);
   try
   {
      m_midi_out->sendMessage(&message);
   }
   catch(RtMidiError &error)
   {
      error.printMessage();
   }
}


void MIDI::sendNoteOn(uint8_t note, uint8_t velocity)
{
   uint8_t msg[3] = { (uint8_t)(0x90 + (m_channel - 1)), note, velocity };
   sendMIDIPacket(msg, sizeof(msg));
}


void MIDI::sendNoteOff(uint8_t note, uint8_t velocity)
{
   uint8_t msg[3] = { (uint8_t)(0x80 + (m_channel - 1)), note, velocity };
   sendMIDIPacket(msg, sizeof(msg));
}


void MIDI::sendProgramChange(uint8_t value)
{
   for(int i = 0; i < 16; i++) // sur les 16 canaux
   {
      uint8_t msg[2] = { (uint8_t)(0xC0 + i), value };
      sendMIDIPacket(msg, sizeof(msg));
   }
}


void MIDI::sendController(uint8_t ctrl_id, uint8_t value)
{
   uint8_t msg[3] = { (uint8_t)(0xB0 + (m_channel - 1)), ctrl_id, value };
   sendMIDIPacket(msg, sizeof(msg));
}


void MIDI::log(const char *str)
{
   if(m_trace && m_log)
   {
      m_log->log("%s", str);
   }
}


void MIDI::logerror(const char *str)
{
   if(m_log)
   {
      m_log->log("%s", str);
   }
}


void MIDI::flush(void)
{
   if(m_open)
   {
      m_in_queue_mutex->Lock();
      m_midi_rx_in_idx = 0;
      m_midi_rx_out_idx = 0;
      m_in_queue_mutex->Unlock();
   }
}


bool MIDI::dataAvailable(void)
{
   bool retval = false;
   if(m_open)
   {
      m_in_queue_mutex->Lock();
      retval = (m_midi_rx_in_idx != m_midi_rx_out_idx);
      m_in_queue_mutex->Unlock();
   }
   return retval;
}


unsigned char MIDI::getDataByte(void)
{
   unsigned char data = 0;
   if(m_open)
   {
      m_in_queue_mutex->Lock();
      data = m_midi_rx_buf[m_midi_rx_out_idx];
      m_midi_rx_out_idx++;
      if(m_midi_rx_out_idx >= MIDI_APP_BUFSIZE)
      {
         m_midi_rx_out_idx = 0;
      }
      m_in_queue_mutex->Unlock();
   }
   return data;
}


void MIDI::inCallback(double deltatime, std::vector<unsigned char> *message, void *userData)
{
   unsigned int nBytes = message->size();
   m_in_queue_mutex->Lock();
   for(unsigned int i = 0; i < nBytes; i++)
   {
      if(message->at(i) != 0xff)
      {
         m_midi_rx_buf[m_midi_rx_in_idx] = message->at(i);
         m_midi_rx_in_idx++;
         if(m_midi_rx_in_idx >= MIDI_APP_BUFSIZE)
         {
            m_midi_rx_in_idx = 0;
         }
      }
   }
   m_in_queue_mutex->Unlock();
}
