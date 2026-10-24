#ifndef __PROPH2000H__
#define __PROPH2000H__

#define GENERAL_FONT_SIZE 8 //Test, use 8 here for release
#define KEYBOARD_C1_OFFSET 36
#define KEYBOARD_C3 (KEYBOARD_C1_OFFSET + 24)

#define SOUND_NOT_MAPPED_VALUE 0x58

#define SOUND_BLACK_KEY_COLOUR_DIM wxColour(50, 50, 50)
#define SOUND1_COLOUR wxColour(255, 0, 0)
#define SOUND2_COLOUR wxColour(255, 255, 0)
#define SOUND3_COLOUR wxColour(0, 255, 0)
#define SOUND4_COLOUR wxColour(155, 155, 255)
#define SOUND5_COLOUR wxColour(0, 255, 255)
#define SOUND6_COLOUR wxColour(255, 128, 0)
#define SOUND7_COLOUR wxColour(128, 128, 0)
#define SOUND8_COLOUR wxColour(128, 128, 128)
#define SOUND9_COLOUR wxColour(0, 0, 255)
#define SOUND10_COLOUR wxColour(255, 0, 255)
#define SOUND11_COLOUR wxColour(245, 162, 137)
#define SOUND12_COLOUR wxColour(216, 167, 206)
#define SOUND13_COLOUR wxColour(183, 211, 171)
#define SOUND14_COLOUR wxColour(236, 175, 147)
#define SOUND15_COLOUR wxColour(255, 232, 179)
#define SOUND16_COLOUR wxColour(235, 248, 250)
#define LEFT 0
#define RIGHT 1


class MIDI;
class Logger;
class MyPanel;
class wxProgressDialog;
class StopWatch;

#define SOUND_PARAM_BYTES 76
#define PRESET_PARAM_BYTES 47
#define MAP_PARAM_BYTES 22

#define MAX_SAMPLE_WORDS_PER_MEMORY (514*1024)
#define MAX_SAMPLE_BANK_WORDS_UNEXTENDED (128 * 1024)
#define MAX_SAMPLE_BANK_WORDS_EXTENDED (256 * 1024)

#define MAX_SAMPLE_NAME_LEN 255

typedef union
{
   uint8_t bytes_au8[SOUND_PARAM_BYTES]; // currently 73 bytes mapped
   struct
   {
      uint8_t amp_release_rate;
      uint8_t amp_2nd_release_rate;
      uint8_t amp_decay_rate;
      uint8_t amp_sustain_level;
      uint8_t amp_attack_rate;
      uint8_t amp_peak_vel_sensitivity;
      uint8_t filt_release_rate;
      uint8_t filt_2nd_release_rate;
      uint8_t filt_decay_rate;
      uint8_t filt_sustain_level;
      uint8_t filt_attack_rate;
      uint8_t filt_peak_vel_sensitivity;
      uint8_t filt_resonance[2];
      uint8_t filt_cutoff[2];
      uint8_t filt_env_amount;
      uint8_t filt_key_tracking;
      uint8_t attack_vel_sensitivity;
      uint8_t release_vel_sensitivity;
      uint8_t begin_addr[3];
      uint8_t start_point[3];
      uint8_t sustain_loop_start[3];
      uint8_t sustain_loop_end[3];
      uint8_t release_loop_start[3];
      uint8_t release_loop_end[3];
      uint8_t end_point[3];
      uint8_t finish_addr[3];
      uint8_t sample_status;
      uint8_t velocity_start_point;
      uint8_t root_key;
      uint8_t tune_table;
      uint8_t transpose_map1;
      uint8_t transpose_map2;
      uint8_t transpose_map3;
      uint8_t transpose_map4;
      uint8_t transpose_map5;
      uint8_t transpose_map6;
      uint8_t transpose_map7;
      uint8_t transpose_map8;
      uint8_t hi_key_map1;
      uint8_t hi_key_map2;
      uint8_t hi_key_map3;
      uint8_t hi_key_map4;
      uint8_t hi_key_map5;
      uint8_t hi_key_map6;
      uint8_t hi_key_map7;
      uint8_t hi_key_map8;
      uint8_t relative_mix_map1;
      uint8_t relative_mix_map2;
      uint8_t relative_mix_map3;
      uint8_t relative_mix_map4;
      uint8_t relative_mix_map5;
      uint8_t relative_mix_map6;
      uint8_t relative_mix_map7;
      uint8_t relative_mix_map8;
      uint8_t sample_rate;
   } val_s;
} sound_param_ts;


typedef union
{
   uint8_t bytes_au8[PRESET_PARAM_BYTES]; // currently 30 bytes mapped
   struct
   {
      uint8_t left_x_map_number;
      uint8_t left_x_map_side;
      uint8_t right_y_map_number;
      uint8_t right_y_map_side;
      uint8_t lfo_freq;
      uint8_t lfo_init_amount;
      uint8_t lfo_vel_sensitivity;
      uint8_t vibrato;
      uint8_t lfo_filt;
      uint8_t lfo_amp;
      uint8_t keyboard_mode;
      uint8_t split_point;
      uint8_t transpose;
      uint8_t dyn_alloc;
      uint8_t vel_switch_threshold;
      uint8_t stack_voices;
      uint8_t stack_delay;
      uint8_t stack_detune;
      uint8_t arp_mode;
      uint8_t arp_oct;
      uint8_t arp_repeats;
      uint8_t arp_rate;
      uint8_t arp_latch_mode;
      uint8_t arp_not_used;
      uint8_t arp_split_point;
      uint8_t arp_split_type;
      uint8_t pitchwheel_range;
      uint8_t midi_mode;
      uint8_t midi_opts;
      uint8_t midi_right_ch;
      uint8_t midi_left_ch;
   } val_s;
} preset_param_ts;


typedef union
{
   uint8_t bytes_au8[MAP_PARAM_BYTES]; // currently 20 bytes mapped
   struct
   {
      uint8_t amp_release_rate;
      uint8_t amp_2nd_release_rate;
      uint8_t amp_decay_rate;
      uint8_t amp_sustain_level;
      uint8_t amp_attack_rate;
      uint8_t amp_peak_vel_sensitivity;
      uint8_t filt_release_rate;
      uint8_t filt_2nd_release_rate;
      uint8_t filt_decay_rate;
      uint8_t filt_sustain_level;
      uint8_t filt_attack_rate;
      uint8_t filt_peak_vel_sensitivity;
      uint8_t filt_resonance;
      uint8_t filt_resonance_l;
      uint8_t filt_cutoff;
      uint8_t filt_cutoff_l;
      uint8_t filt_env_amount;
      uint8_t filt_keyboard_tracking;
      uint8_t attack_vel_sensitivity;
      uint8_t release_vel_sensitivity;
      uint8_t sound_direction;
      uint8_t velocity_start_point;
   } val_s;
} map_param_ts;


typedef struct 
{
   uint8_t stereo_mode;
   uint8_t r02;
   uint8_t r03;
   uint8_t r04;
   uint8_t r05;
   uint8_t r06;
   uint8_t r07;
   uint8_t r08;
   uint8_t r09;
   uint8_t r10;
   uint8_t r11;
   uint8_t r12;
   uint8_t r13;
   uint8_t r14;
   uint8_t r15;
   uint8_t r16;
   uint8_t r17;
   uint8_t r18;
   uint8_t r19;
   uint8_t r20;
   uint8_t r21;
   uint8_t r22;
   uint8_t r23;
   uint8_t r24;
   uint8_t r25;
   uint8_t r26;
   uint8_t r27;
   uint8_t r28;
   uint8_t r29;
   uint8_t r30;
   uint8_t r31;
   uint8_t r32;
   uint8_t r33;
   uint8_t r34;
} p2kconfig_ts;

#define MIDI_RX_BUF_SIZE (64*1024)

class Proph2000
{
public:
   typedef enum { PROPH_IDLE, PROPH_DUMP2PC, PROPH_DUMP2PROPH, PROPH_TX_PRESET, PROPH_TX_SOUNDPARAM, PROPH_TX_MAP,
                  PROPH_GETPARAMETER, PROPH_RX_SOUND, PROPH_RX_SINGLE_SOUND_PARAM, PROPH_UPDATEALLPARAMETER,
                  PROPH_UPDATEALLSOUNDPARAMETER } main_mode_te;
   typedef enum { TRX_NOERROR, TRX_TIMEOUT, TRX_NO_RESPONSE } trx_error_te;
   typedef enum { SR_15625HZ, SR_31250HZ, SR_41667HZ } sample_rate_te;

   Proph2000(Logger *log); // as compare object
   Proph2000(MIDI *midi, MyPanel *main, Logger *log);
   Proph2000(const Proph2000 &rhnd);
   ~Proph2000();

   void clear(void);
   bool load(const char *filename);
   bool save(const char *filename) const;

   void sendPanic(void);

   bool doCompare(const Proph2000 &rhnd); // true=different

   bool saveWave(uint8_t sample_id, const char *filename);

   void setSampleData(uint8_t sample_id, uint16_t *data, uint32_t sample_words, uint32_t sample_rate);

   bool getRXHandshakeFlag(void) const { return m_use_rx_handshake; };
   void setRXHandshakeFlag(bool flag) { m_use_rx_handshake = flag; };

   bool transfer2PC(void);
   bool transfer2Prophet(void);
   bool transferPreset2Proph(uint8_t preset_u8); 
   bool transferSoundParam2Proph(uint8_t sound_u8); 
   bool transferSoundParam2PC(uint8_t sound_u8); 
   bool transferMap2Proph(uint8_t map_u8); 
   bool transferParameter2PC(void);
   bool transferSound2PC(uint8_t sound_u8); 
   bool transferParameter2Prophet(void);
   bool transferAllSoundParameter2Prophet(void);

   void updateStructsFromParamBytes(void);
   void updateParamBytesFromStruct(void);

   void handler(void);

   void remapMemory(void);
   bool getExtendedMemory(void) const { return m_extended_memory; };
   void setExtendedMemory(bool flag);

   main_mode_te getTransferMode(void) const { return m_main_mode_e; };
   trx_error_te getTransferError(void) const { return m_trx_error_e; };

   uint32_t getSampleWords(uint8_t sample_id) const;
   uint32_t getStartPoint(uint8_t sample_id) const;
   void setStartPoint(uint8_t sample_id, uint32_t words);
   uint32_t getEndPoint(uint8_t sample_id) const;
   void setEndPoint(uint8_t sample_id, uint32_t words);

   uint32_t getSustainLoopStart(uint8_t sample_id) const;
   void setSustainLoopStart(uint8_t sample_id, uint32_t words);
   uint32_t getSustainLoopEnd(uint8_t sample_id) const;
   void setSustainLoopEnd(uint8_t sample_id, uint32_t words);

   uint32_t getReleaseLoopStart(uint8_t sample_id) const;
   void setReleaseLoopStart(uint8_t sample_id, uint32_t words);
   uint32_t getReleaseLoopEnd(uint8_t sample_id) const;
   void setReleaseLoopEnd(uint8_t sample_id, uint32_t words);

   bool sustainLoopEnabled(uint8_t sample_id) const;

   bool releaseLoopEnabled(uint8_t sample_id) const;
   void setReleaseLoopActive(uint8_t sample_id, bool flag);

   bool bfLoopEnabled(uint8_t sample_id) const;
   void setBfLoopActive(uint8_t sample_id, bool flag);

   bool reverseEnabled(uint8_t sample_id) const;
   void setReverseActive(uint8_t sample_id, bool flag);

   bool getStereoMode(void) const;
   void setStereoMode(bool flag);

   void abort(void);

   bool transferFinished(void);
   

   sample_rate_te getSampleRate(uint8_t sample_id) const;
   uint16_t *getSampleData(uint8_t sample_id) { return &m_sampledata_au16[sample_id][0]; };

   void deleteSample(uint8_t sample_id); 

   main_mode_te getLastTransferJob(void) { return m_last_main_mode_e; };

   void sendSelectRequest(void);

   void setSampleName(const char *name, uint8_t sample_id);
   const char *getSampleName(uint8_t sample_id) const { return m_samplename_au8[sample_id]; };

   sound_param_ts m_sound_param_as[16];
   map_param_ts m_map_param_as[16];
   preset_param_ts m_preset_param_as[12];

   uint8_t m_soundparam_au8[16][(SOUND_PARAM_BYTES * 2) + 1024];
   uint8_t m_mapparam_au8[16][(MAP_PARAM_BYTES * 2) + 1024];
   uint8_t m_presetparam_au8[12][(PRESET_PARAM_BYTES * 2) + 1024];

private:
   typedef enum { RX_NOT_FINISHED, RX_FINISHED } rx_mode_te;
   typedef enum { INVALID_PACKET, ACK_PACKET, NACK_PACKET, CANCEL_PACKET,
                  DUMP_REQ_PACKET, WAIT_PACKET, DUMP_HEADER_PACKET,
                  DATA_PACKET, GENERIC_DUMP_REQ_PACKET,
                  SOUND_PARAM_PACKET, PRESET_PARAM_PACKET,
                  MAP_PARAM_PACKET } rx_packet_te;

   MyPanel *m_main;
   Logger *m_log;
   MIDI *m_midi;
   bool m_send_select_request;
   bool m_send_stereo_trigger;
   uint8_t m_packet_counter;
   uint8_t m_req_during_transfer_cnt;
   char m_samplename_au8[16][MAX_SAMPLE_NAME_LEN];
   uint16_t m_sampledata_au16[16][MAX_SAMPLE_WORDS_PER_MEMORY];
   uint32_t m_sample_length_words_au32[16];
   p2kconfig_ts m_p2kconfig_s;
   uint32_t m_sampledata_rx_idx;
   main_mode_te m_main_mode_e;
   main_mode_te m_last_main_mode_e;
   uint16_t m_sub_mode_u16;
   uint8_t m_handle_id;
   rx_mode_te m_rx_mode_e;
   uint8_t m_midi_rx_buf[MIDI_RX_BUF_SIZE];
   uint16_t m_midi_rx_idx;
   StopWatch m_estimated_timer;
   StopWatch m_retry_timeout;
   StopWatch m_ack_timeout;
   StopWatch m_transfer_time;
   StopWatch m_sample_transfer_time;
   StopWatch m_data_packet_latency_time;
   uint16_t m_worst_case_latency;
   bool m_first_latency_measurement;
   uint8_t m_retry_cnt;
   trx_error_te m_trx_error_e;
   rx_packet_te m_rx_packet_e;
   bool m_map_received_data;
   uint8_t m_map_rx_slot;
   uint8_t m_current_rx_slot;
   wxProgressDialog *m_progress_dlg;
   wxString m_progress_msg;
   uint16_t m_invalid_packet_cnt;
   uint8_t m_last_data_packet_size;
   uint32_t m_transfered_total;
   float m_ms_for_1_word;
   uint32_t m_total_words_to_transfer;
   bool m_extended_memory;
   bool m_use_rx_handshake;

   uint8_t m_test_last_nack_paket;

   void sendMIDIPacket(uint8_t *data, uint8_t len);
   void sendSampleDumpRequest(uint8_t channel_u8, uint8_t sample_id_u8, bool map_received_data);
   void sendAck(uint8_t channel_u8, uint8_t packet_number_u8);
   void sendNack(uint8_t channel_u8, uint8_t packet_number_u8);
   void sendCancel(uint8_t channel_u8, uint8_t packet_number_u8);
   void sendWait(uint8_t channel_u8, uint8_t packet_number_u8);
   void sendGenericDumpRequest(uint8_t selection_u8, bool map_received_data); // 0x00-0x0f:sound param   0x40-0x4b:preset param  0x60-0x6f:map param
   void sendRecoverMemory(uint8_t sample_u8); // 0x00-0x0f
   void sendDeleteMemory(uint8_t sample_u8); // 0x00-0x0f: sample  0x10:Mem A  0x11:Mem B  0x12:All
   void sendSoundParamDump(uint8_t sound_u8); // 0-15
   void sendPresetParamDump(uint8_t preset_u8); // 0-11
   void sendMapParamDump(uint8_t map_u8); // 0-15
   void sendDataPacketBlock(uint16_t *sample_data); // sends 60 sample words of data (12bits right justified); clear packet counter on first packet!
   void sendDumpHeader(uint8_t ch, uint8_t sample);

   void receiveHandler(void);
   void handleReceivedDumpHeader(void);
   void handleReceivedDataPacket(void);
   void handleReceivedSoundParameter(void);
   void handleReceivedPresetParameter(void);
   void handleReceivedMapParameter(void);

   void handleTransfer2PC(void);
   void handleTransfer2Prophet(void);
   void handleTransferParameter2PC(void);
   void handleTransferPreset2Prophet(void);
   void handleTransferMap2Prophet(void);
   void handleTransferSoundParam2Prophet(void);
   void handleTransferSound2PC(void);
   void handleTransferSingleSoundParameter2PC(void);
   void handleParameter2Prophet(void);
   void handleAllSoundParameter2Prophet(void);

   void logInvalidPacket(void);

   void flushRX(void) { m_midi_rx_idx = 0; };

   void resetRx(void);

};


#endif
