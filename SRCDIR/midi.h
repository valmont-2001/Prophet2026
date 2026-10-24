#ifndef __MIDIH__
#define __MIDIH__

// Couche MIDI de l'application, basee uniquement sur RtMidi (https://github.com/thestk/rtmidi).

#include "RtMidi.h"

class wxMutex;
class Logger;

class MIDI
{
public:
   MIDI(Logger *log);
   ~MIDI();

   // Liste des peripheriques: index affiche dans l'interface -> index RtMidi
   map<int, int> &getInputDeviceList(void) { return m_in_devices_map; };
   map<int, int> &getOutputDeviceList(void) { return m_out_devices_map; };

   unsigned char getInDeviceID(void) const { return m_in_device_id; };
   unsigned char getOutDeviceID(void) const { return m_out_device_id; };
   void setInDeviceID(unsigned char id) { m_in_device_id = id; };
   void setOutDeviceID(unsigned char id) { m_out_device_id = id; };

   unsigned char getChannel(void) const { return m_channel; }; // 1..16
   void setChannel(unsigned char ch) { m_channel = ch; };      // 1..16

   bool init(void);   // ouvre les ports MIDI choisis
   void close(void);
   bool isMIDIopen(void) const { return m_open; };

   // Emission
   void sendMIDIPacket(unsigned char *data, unsigned char len); // SysEx ou message brut
   void sendNoteOn(uint8_t note, uint8_t velocity);
   void sendNoteOff(uint8_t note, uint8_t velocity);
   void sendProgramChange(uint8_t value);
   void sendController(uint8_t ctrl_id, uint8_t value);

   // Reception (file d'attente remplie par le callback RtMidi)
   bool dataAvailable(void);
   unsigned char getDataByte(void);
   void flush(void);

   // Journal du protocole: log() = trace detaillee (desactivee par defaut), logerror() = toujours ecrit
   void log(const char *str);
   void logerror(const char *str);
   void setTrace(bool flag) { m_trace = flag; };

   // Sauvegarde des reglages (format identique a l'ancienne version: 6 octets)
   void loadConfig(FILE *file);
   void saveConfig(FILE *file);

   void inCallback(double deltatime, std::vector<unsigned char> *message, void *userData);

   RtMidiOut *getMIDIOutDevice(void) { return m_midi_out; };
   RtMidiIn *getMIDIInDevice(void) { return m_midi_in; };

private:
   map<int, int> m_in_devices_map;
   map<int, int> m_out_devices_map;
   RtMidiOut *m_midi_out;
   RtMidiIn *m_midi_in;

   wxMutex *m_in_queue_mutex;
   unsigned char m_in_device_id;
   unsigned char m_out_device_id;
   unsigned char m_channel;
   Logger *m_log;

   bool m_open;
   bool m_trace;
};

#endif
