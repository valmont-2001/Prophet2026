#include "types.h"
   #include <wx/wx.h>
   #include <wx/spinctrl.h>
   #include "progresswin.h"
#include "stopwatch.h"
#include "proph2000.h"
#include "logger.h"
#include <list>
#include <map>
using namespace std;
#include "midi.h"
	#include "main.h"
#include "wave.h"


#define RECEIVE_PACKET_TIMEOUT_MS 2000
#define TRANSFER2PROPH_RETRY_TIMEOUT 1000
#define TRANSFER2PROPH_ACK_TIMEOUT 800
#define TRANSFER2PC_RETRY_TIMEOUT 600
#define WORDS_TO_ESTIMATED_TIME_CALC 3000


//#define LOG_DATA_PACKET_RECEIVED
//#define LOG_DATA_PACKET_COUNTER
//#define LOG_ACK_RECEIVED
#define LOG_CANCEL_RECEIVED
//#define LOG_SEND_ACK
#define LOG_SEND_DUMP_HEADER
#define LOG_SEND_DUMP_HEADER_CONTENT
#define LOG_RX_DUMP_HEADER
#define LOG_SEND_SAMPLE_DUMP_REQUEST
#define LOG_SEND_SOUND_PARAM_DUMP
#define LOG_RX_SOUNDPARAM
//#define LOG_UPDATE_STRUCTS_FROM_PARAMBYTES_CALL
//#define LOG_UPDATE_PARAMBYTES_FROM_STRUCTS_CALL

//#define NACK_ON_ERROR_HANDLING // only in handshake mode -> does not work!
//#define LOG_DATA_PACKET_ACK_LATENCY


Proph2000::Proph2000(Logger *log)  : m_midi(NULL), m_packet_counter(0), m_main_mode_e(PROPH_IDLE), m_sub_mode_u16(0), m_handle_id(0), 
   m_rx_mode_e(RX_NOT_FINISHED), m_midi_rx_idx(0), m_trx_error_e(TRX_NOERROR), m_rx_packet_e(INVALID_PACKET),
   m_map_received_data(false), m_map_rx_slot(0), m_sampledata_rx_idx(0), m_current_rx_slot(0), m_invalid_packet_cnt(0),
   m_retry_cnt(0), m_transfered_total(0), m_ms_for_1_word(0), m_total_words_to_transfer(0), 
   m_extended_memory(false), m_use_rx_handshake(false), m_send_select_request(true),
   m_test_last_nack_paket(255), m_log(log), m_send_stereo_trigger(false)
   ,m_main(NULL)
{
   m_progress_dlg = NULL;
   
   memset(&m_p2kconfig_s, 0, sizeof(m_p2kconfig_s));

   clear();
}

   Proph2000::Proph2000(MIDI *midi, MyPanel *main, Logger *log) 
   : m_midi(midi), m_packet_counter(0), m_main_mode_e(PROPH_IDLE), m_sub_mode_u16(0), m_handle_id(0), 
   m_rx_mode_e(RX_NOT_FINISHED), m_midi_rx_idx(0), m_trx_error_e(TRX_NOERROR), m_rx_packet_e(INVALID_PACKET),
   m_map_received_data(false), m_map_rx_slot(0), m_sampledata_rx_idx(0), m_current_rx_slot(0), m_invalid_packet_cnt(0),
   m_retry_cnt(0), m_transfered_total(0), m_ms_for_1_word(0), m_total_words_to_transfer(0), 
   m_extended_memory(false), m_use_rx_handshake(false), m_send_select_request(true),
   m_first_latency_measurement(true), m_log(log), m_send_stereo_trigger(false)
   ,m_main(main)
{
   clear();
   m_progress_dlg = new ProgressWindow(wxT("Transfer"), 100); // cachee jusqu'au debut d'un transfert

   uint8_t i;
   for(i = 0; i < 16; i++)
   {
      m_samplename_au8[i][0] = 0;
   }

}


Proph2000::Proph2000(const Proph2000 &rhnd) : m_midi(rhnd.m_midi), m_packet_counter(rhnd.m_packet_counter), m_main_mode_e(PROPH_IDLE), m_sub_mode_u16(0), 
   m_handle_id(0), m_rx_mode_e(RX_NOT_FINISHED), m_midi_rx_idx(0), m_trx_error_e(TRX_NOERROR), m_rx_packet_e(INVALID_PACKET),
   m_map_received_data(false), m_map_rx_slot(0), m_sampledata_rx_idx(0), m_current_rx_slot(0), m_invalid_packet_cnt(0),
   m_retry_cnt(0), m_req_during_transfer_cnt(0), m_log(rhnd.m_log), m_send_stereo_trigger(rhnd.m_send_stereo_trigger)
{
   memcpy(&m_sound_param_as, &rhnd.m_sound_param_as, sizeof(m_sound_param_as));
   memcpy(&m_preset_param_as, &rhnd.m_preset_param_as, sizeof(m_preset_param_as));
   memcpy(&m_map_param_as, &rhnd.m_map_param_as, sizeof(m_map_param_as));
   memcpy(&m_sampledata_au16, &rhnd.m_sampledata_au16, sizeof(m_sampledata_au16));
   memcpy(&m_sample_length_words_au32, &rhnd.m_sample_length_words_au32, sizeof(m_sample_length_words_au32));
   uint8_t i;
   uint32_t i2;
   for(i = 0; i < 16; i++)
   {
      for(i2 = 0; i2 < ((1024 * 1024) / 2);i2++)
      {
         m_sampledata_au16[i][i2] = 4096 / 2;
      }
      i2 = 0;
      m_samplename_au8[i][0] = 0;
      while(rhnd.m_samplename_au8[i][i2] != 0)
      {
         m_samplename_au8[i][i2] = rhnd.m_samplename_au8[i][i2];
         i2++;
      }
   }
}


Proph2000::~Proph2000()
{
   if(m_progress_dlg)
   {
      delete m_progress_dlg;
   }
}


bool Proph2000::getStereoMode(void) const
{
   bool retval;
   if(m_p2kconfig_s.stereo_mode == 1)
   {
      retval = true;
   }
   else
   {
      retval = false;
   }
   return retval;
}


void Proph2000::setStereoMode(bool flag)
{
   if(flag)
   {
      m_p2kconfig_s.stereo_mode =  1;
   }
   else
   {
      m_p2kconfig_s.stereo_mode =  0;
   }
}


void Proph2000::abort(void)
{
   m_trx_error_e = TRX_NO_RESPONSE;
   m_main_mode_e = PROPH_IDLE; 
   m_main->transferFinished(true);
   m_progress_dlg->Hide();
}

void Proph2000::setSampleName(const char *name, uint8_t sample_id)
{
   uint16_t i = 0;

   for(i = 0; i < MAX_SAMPLE_NAME_LEN; i++)
   {
      m_samplename_au8[sample_id][i] = 0;
   }

   i = 0;

   do
   {
      m_samplename_au8[sample_id][i] = name[i];
      i++;
   }
   while((name[i] != 0) && (i < (MAX_SAMPLE_NAME_LEN - 1)));

   m_samplename_au8[sample_id][i] = 0;
}


void Proph2000::sendPanic(void)
{
   m_midi->sendNoteOn(40, 1);
   m_midi->sendNoteOff(40, 1);
}


bool Proph2000::doCompare(const Proph2000 &rhnd)
{
   uint8_t i;
   uint8_t i2;
   uint32_t as;
   uint32_t ad;
   bool retval = false;

   m_log->log("Compare:");

   for(i = 0; i < 16; i++)
   {
      for(i2 = 0; i2 < (MAP_PARAM_BYTES * 2); i2++)
      {
         if(m_mapparam_au8[i][i2] != rhnd.m_mapparam_au8[i][i2])
         {
            m_log->log("m_mapparam_au8[map %d][%d] different", i + 1, i2);
            retval = true;
         }
      }
   }

   for(i = 0; i < 12; i++)
   {
      for(i2 = 0; i2 < (PRESET_PARAM_BYTES * 2); i2++)
      {
         if(m_presetparam_au8[i][i2] != rhnd.m_presetparam_au8[i][i2])
         {
            m_log->log("m_presetparam_au8[preset %d][%d] different", i + 1, i2);
            retval = true;
         }
      }
   }

   for(i = 0; i < 16; i++)
   {
      if(m_sound_param_as[i].val_s.amp_release_rate != rhnd.m_sound_param_as[i].val_s.amp_release_rate)
      {
         m_log->log("Sound %d: amp_release_rate: %d != %d", i + 1, m_sound_param_as[i].val_s.amp_release_rate, 
            rhnd.m_sound_param_as[i].val_s.amp_release_rate);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.amp_2nd_release_rate != rhnd.m_sound_param_as[i].val_s.amp_2nd_release_rate)
      {
         m_log->log("Sound %d: amp_2nd_release_rate: %d != %d", i + 1, m_sound_param_as[i].val_s.amp_2nd_release_rate, 
            rhnd.m_sound_param_as[i].val_s.amp_2nd_release_rate);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.amp_decay_rate != rhnd.m_sound_param_as[i].val_s.amp_decay_rate)
      {
         m_log->log("Sound %d: amp_decay_rate: %d != %d", i + 1, m_sound_param_as[i].val_s.amp_decay_rate, 
            rhnd.m_sound_param_as[i].val_s.amp_decay_rate);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.amp_sustain_level != rhnd.m_sound_param_as[i].val_s.amp_sustain_level)
      {
         m_log->log("Sound %d: amp_sustain_level: %d != %d", i + 1, m_sound_param_as[i].val_s.amp_sustain_level, 
            rhnd.m_sound_param_as[i].val_s.amp_sustain_level);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.amp_attack_rate != rhnd.m_sound_param_as[i].val_s.amp_attack_rate)
      {
         m_log->log("Sound %d: amp_attack_rate: %d != %d", i + 1, m_sound_param_as[i].val_s.amp_attack_rate, 
            rhnd.m_sound_param_as[i].val_s.amp_attack_rate);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.amp_peak_vel_sensitivity != rhnd.m_sound_param_as[i].val_s.amp_peak_vel_sensitivity)
      {
         m_log->log("Sound %d: amp_peak_vel_sensitivity: %d != %d", i + 1, m_sound_param_as[i].val_s.amp_peak_vel_sensitivity, 
            rhnd.m_sound_param_as[i].val_s.amp_peak_vel_sensitivity);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.filt_release_rate != rhnd.m_sound_param_as[i].val_s.filt_release_rate)
      {
         m_log->log("Sound %d: filt_release_rate: %d != %d", i + 1, m_sound_param_as[i].val_s.filt_release_rate, 
            rhnd.m_sound_param_as[i].val_s.filt_release_rate);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.filt_2nd_release_rate != rhnd.m_sound_param_as[i].val_s.filt_2nd_release_rate)
      {
         m_log->log("Sound %d: filt_2nd_release_rate: %d != %d", i + 1, m_sound_param_as[i].val_s.filt_2nd_release_rate, 
            rhnd.m_sound_param_as[i].val_s.filt_2nd_release_rate);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.filt_decay_rate != rhnd.m_sound_param_as[i].val_s.filt_decay_rate)
      {
         m_log->log("Sound %d: filt_decay_rate: %d != %d", i + 1, m_sound_param_as[i].val_s.filt_decay_rate, 
            rhnd.m_sound_param_as[i].val_s.filt_decay_rate);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.filt_sustain_level != rhnd.m_sound_param_as[i].val_s.filt_sustain_level)
      {
         m_log->log("Sound %d: filt_sustain_level: %d != %d", i + 1, m_sound_param_as[i].val_s.filt_sustain_level, 
            rhnd.m_sound_param_as[i].val_s.filt_sustain_level);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.filt_attack_rate != rhnd.m_sound_param_as[i].val_s.filt_attack_rate)
      {
         m_log->log("Sound %d: filt_attack_rate: %d != %d", i + 1, m_sound_param_as[i].val_s.filt_attack_rate, 
            rhnd.m_sound_param_as[i].val_s.filt_attack_rate);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.filt_peak_vel_sensitivity != rhnd.m_sound_param_as[i].val_s.filt_peak_vel_sensitivity)
      {
         m_log->log("Sound %d: filt_peak_vel_sensitivity: %d != %d", i + 1, m_sound_param_as[i].val_s.filt_peak_vel_sensitivity, 
            rhnd.m_sound_param_as[i].val_s.filt_peak_vel_sensitivity);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.filt_resonance[0] != rhnd.m_sound_param_as[i].val_s.filt_resonance[0])
      {
         m_log->log("Sound %d: filt_resonance[0]: %d != %d", i + 1, m_sound_param_as[i].val_s.filt_resonance[0], 
            rhnd.m_sound_param_as[i].val_s.filt_resonance[0]);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.filt_resonance[1] != rhnd.m_sound_param_as[i].val_s.filt_resonance[1])
      {
         m_log->log("Sound %d: filt_resonance[1]: %d != %d", i + 1, m_sound_param_as[i].val_s.filt_resonance[1], 
            rhnd.m_sound_param_as[i].val_s.filt_resonance[1]);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.filt_cutoff[0] != rhnd.m_sound_param_as[i].val_s.filt_cutoff[0])
      {
         m_log->log("Sound %d: filt_cutoff[0]: %d != %d", i + 1, m_sound_param_as[i].val_s.filt_cutoff[0], 
            rhnd.m_sound_param_as[i].val_s.filt_cutoff[0]);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.filt_cutoff[1] != rhnd.m_sound_param_as[i].val_s.filt_cutoff[1])
      {
         m_log->log("Sound %d: filt_cutoff[1]: %d != %d", i + 1, m_sound_param_as[i].val_s.filt_cutoff[1], 
            rhnd.m_sound_param_as[i].val_s.filt_cutoff[1]);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.filt_env_amount != rhnd.m_sound_param_as[i].val_s.filt_env_amount)
      {
         m_log->log("Sound %d: filt_env_amount: %d != %d", i + 1, m_sound_param_as[i].val_s.filt_env_amount, 
            rhnd.m_sound_param_as[i].val_s.filt_env_amount);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.filt_key_tracking != rhnd.m_sound_param_as[i].val_s.filt_key_tracking)
      {
         m_log->log("Sound %d: filt_key_tracking: %d != %d", i + 1, m_sound_param_as[i].val_s.filt_key_tracking, 
            rhnd.m_sound_param_as[i].val_s.filt_key_tracking);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.attack_vel_sensitivity != rhnd.m_sound_param_as[i].val_s.attack_vel_sensitivity)
      {
         m_log->log("Sound %d: attack_vel_sensitivity: %d != %d", i + 1, m_sound_param_as[i].val_s.attack_vel_sensitivity, 
            rhnd.m_sound_param_as[i].val_s.attack_vel_sensitivity);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.release_vel_sensitivity != rhnd.m_sound_param_as[i].val_s.release_vel_sensitivity)
      {
         m_log->log("Sound %d: release_vel_sensitivity: %d != %d", i + 1, m_sound_param_as[i].val_s.release_vel_sensitivity, 
            rhnd.m_sound_param_as[i].val_s.release_vel_sensitivity);
         retval = true;
      }

      as = m_sound_param_as[i].val_s.begin_addr[2];
      as |= ((uint32_t)m_sound_param_as[i].val_s.begin_addr[1] << 8);
      as |= ((uint32_t)m_sound_param_as[i].val_s.begin_addr[0] << 16);

      ad = rhnd.m_sound_param_as[i].val_s.begin_addr[2];
      ad |= ((uint32_t)rhnd.m_sound_param_as[i].val_s.begin_addr[1] << 8);
      ad |= ((uint32_t)rhnd.m_sound_param_as[i].val_s.begin_addr[0] << 16);

      if(as != ad)
      {
         m_log->log("Sound %d: begin_addr: 0x%.6x != 0x%.6x", i + 1, as, ad);
         retval = true;
      }

      as = m_sound_param_as[i].val_s.start_point[2];
      as |= ((uint32_t)m_sound_param_as[i].val_s.start_point[1] << 8);
      as |= ((uint32_t)m_sound_param_as[i].val_s.start_point[0] << 16);

      ad = rhnd.m_sound_param_as[i].val_s.start_point[2];
      ad |= ((uint32_t)rhnd.m_sound_param_as[i].val_s.start_point[1] << 8);
      ad |= ((uint32_t)rhnd.m_sound_param_as[i].val_s.start_point[0] << 16);

      if(as != ad)
      {
         m_log->log("Sound %d: start_point: 0x%.6x != 0x%.6x", i + 1, as, ad);
         retval = true;
      }

      as = m_sound_param_as[i].val_s.sustain_loop_start[2];
      as |= ((uint32_t)m_sound_param_as[i].val_s.sustain_loop_start[1] << 8);
      as |= ((uint32_t)m_sound_param_as[i].val_s.sustain_loop_start[0] << 16);

      ad = rhnd.m_sound_param_as[i].val_s.sustain_loop_start[2];
      ad |= ((uint32_t)rhnd.m_sound_param_as[i].val_s.sustain_loop_start[1] << 8);
      ad |= ((uint32_t)rhnd.m_sound_param_as[i].val_s.sustain_loop_start[0] << 16);

      if(as != ad)
      {
         m_log->log("Sound %d: sustain_loop_start: 0x%.6x != 0x%.6x", i + 1, as, ad);
         retval = true;
      }

      as = m_sound_param_as[i].val_s.sustain_loop_end[2];
      as |= ((uint32_t)m_sound_param_as[i].val_s.sustain_loop_end[1] << 8);
      as |= ((uint32_t)m_sound_param_as[i].val_s.sustain_loop_end[0] << 16);

      ad = rhnd.m_sound_param_as[i].val_s.sustain_loop_end[2];
      ad |= ((uint32_t)rhnd.m_sound_param_as[i].val_s.sustain_loop_end[1] << 8);
      ad |= ((uint32_t)rhnd.m_sound_param_as[i].val_s.sustain_loop_end[0] << 16);

      if(as != ad)
      {
         m_log->log("Sound %d: sustain_loop_end: 0x%.6x != 0x%.6x", i + 1, as, ad);
         retval = true;
      }

      as = m_sound_param_as[i].val_s.release_loop_start[2];
      as |= ((uint32_t)m_sound_param_as[i].val_s.release_loop_start[1] << 8);
      as |= ((uint32_t)m_sound_param_as[i].val_s.release_loop_start[0] << 16);

      ad = rhnd.m_sound_param_as[i].val_s.release_loop_start[2];
      ad |= ((uint32_t)rhnd.m_sound_param_as[i].val_s.release_loop_start[1] << 8);
      ad |= ((uint32_t)rhnd.m_sound_param_as[i].val_s.release_loop_start[0] << 16);

      if(as != ad)
      {
         m_log->log("Sound %d: release_loop_start: 0x%.6x != 0x%.6x", i + 1, as, ad);
         retval = true;
      }

      as = m_sound_param_as[i].val_s.release_loop_end[2];
      as |= ((uint32_t)m_sound_param_as[i].val_s.release_loop_end[1] << 8);
      as |= ((uint32_t)m_sound_param_as[i].val_s.release_loop_end[0] << 16);

      ad = rhnd.m_sound_param_as[i].val_s.release_loop_end[2];
      ad |= ((uint32_t)rhnd.m_sound_param_as[i].val_s.release_loop_end[1] << 8);
      ad |= ((uint32_t)rhnd.m_sound_param_as[i].val_s.release_loop_end[0] << 16);

      if(as != ad)
      {
         m_log->log("Sound %d: release_loop_end: 0x%.6x != 0x%.6x", i + 1, as, ad);
         retval = true;
      }

      as = m_sound_param_as[i].val_s.end_point[2];
      as |= ((uint32_t)m_sound_param_as[i].val_s.end_point[1] << 8);
      as |= ((uint32_t)m_sound_param_as[i].val_s.end_point[0] << 16);

      ad = rhnd.m_sound_param_as[i].val_s.end_point[2];
      ad |= ((uint32_t)rhnd.m_sound_param_as[i].val_s.end_point[1] << 8);
      ad |= ((uint32_t)rhnd.m_sound_param_as[i].val_s.end_point[0] << 16);

      if(as != ad)
      {
         m_log->log("Sound %d: end_point: 0x%.6x != 0x%.6x", i + 1, as, ad);
         retval = true;
      }

      as = m_sound_param_as[i].val_s.finish_addr[2];
      as |= ((uint32_t)m_sound_param_as[i].val_s.finish_addr[1] << 8);
      as |= ((uint32_t)m_sound_param_as[i].val_s.finish_addr[0] << 16);

      ad = rhnd.m_sound_param_as[i].val_s.finish_addr[2];
      ad |= ((uint32_t)rhnd.m_sound_param_as[i].val_s.finish_addr[1] << 8);
      ad |= ((uint32_t)rhnd.m_sound_param_as[i].val_s.finish_addr[0] << 16);

      if(as != ad)
      {
         m_log->log("Sound %d: finish_addr: 0x%.6x != 0x%.6x", i + 1, as, ad);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.sample_status != rhnd.m_sound_param_as[i].val_s.sample_status)
      {
         m_log->log("Sound %d: sample_status: %d != %d", i + 1, m_sound_param_as[i].val_s.sample_status, 
            rhnd.m_sound_param_as[i].val_s.sample_status);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.velocity_start_point != rhnd.m_sound_param_as[i].val_s.velocity_start_point)
      {
         m_log->log("Sound %d: velocity_start_point: %d != %d", i + 1, m_sound_param_as[i].val_s.velocity_start_point, 
            rhnd.m_sound_param_as[i].val_s.velocity_start_point);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.root_key != rhnd.m_sound_param_as[i].val_s.root_key)
      {
         m_log->log("Sound %d: root_key: %d != %d", i + 1, m_sound_param_as[i].val_s.root_key, 
            rhnd.m_sound_param_as[i].val_s.root_key);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.tune_table != rhnd.m_sound_param_as[i].val_s.tune_table)
      {
         m_log->log("Sound %d: tune_table: %d != %d", i + 1, m_sound_param_as[i].val_s.tune_table, 
            rhnd.m_sound_param_as[i].val_s.tune_table);
         retval = true;
      }

      if(m_sound_param_as[i].val_s.transpose_map1 != rhnd.m_sound_param_as[i].val_s.transpose_map1)
      {
         m_log->log("Sound %d: transpose_map1: %d != %d", i + 1, m_sound_param_as[i].val_s.transpose_map1, 
            rhnd.m_sound_param_as[i].val_s.transpose_map1);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.transpose_map2 != rhnd.m_sound_param_as[i].val_s.transpose_map2)
      {
         m_log->log("Sound %d: transpose_map2: %d != %d", i + 1, m_sound_param_as[i].val_s.transpose_map2, 
            rhnd.m_sound_param_as[i].val_s.transpose_map2);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.transpose_map3 != rhnd.m_sound_param_as[i].val_s.transpose_map3)
      {
         m_log->log("Sound %d: transpose_map3: %d != %d", i + 1, m_sound_param_as[i].val_s.transpose_map3, 
            rhnd.m_sound_param_as[i].val_s.transpose_map3);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.transpose_map4 != rhnd.m_sound_param_as[i].val_s.transpose_map4)
      {
         m_log->log("Sound %d: transpose_map4: %d != %d", i + 1, m_sound_param_as[i].val_s.transpose_map4, 
            rhnd.m_sound_param_as[i].val_s.transpose_map4);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.transpose_map5 != rhnd.m_sound_param_as[i].val_s.transpose_map5)
      {
         m_log->log("Sound %d: transpose_map5: %d != %d", i + 1, m_sound_param_as[i].val_s.transpose_map5, 
            rhnd.m_sound_param_as[i].val_s.transpose_map5);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.transpose_map6 != rhnd.m_sound_param_as[i].val_s.transpose_map6)
      {
         m_log->log("Sound %d: transpose_map6: %d != %d", i + 1, m_sound_param_as[i].val_s.transpose_map6, 
            rhnd.m_sound_param_as[i].val_s.transpose_map6);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.transpose_map7 != rhnd.m_sound_param_as[i].val_s.transpose_map7)
      {
         m_log->log("Sound %d: transpose_map7: %d != %d", i + 1, m_sound_param_as[i].val_s.transpose_map7, 
            rhnd.m_sound_param_as[i].val_s.transpose_map7);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.transpose_map8 != rhnd.m_sound_param_as[i].val_s.transpose_map8)
      {
         m_log->log("Sound %d: transpose_map8: %d != %d", i + 1, m_sound_param_as[i].val_s.transpose_map8, 
            rhnd.m_sound_param_as[i].val_s.transpose_map8);
         retval = true;
      }

      if(m_sound_param_as[i].val_s.hi_key_map1 != rhnd.m_sound_param_as[i].val_s.hi_key_map1)
      {
         m_log->log("Sound %d: hi_key_map1: %d != %d", i + 1, m_sound_param_as[i].val_s.hi_key_map1, 
            rhnd.m_sound_param_as[i].val_s.hi_key_map1);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.hi_key_map2 != rhnd.m_sound_param_as[i].val_s.hi_key_map2)
      {
         m_log->log("Sound %d: hi_key_map2: %d != %d", i + 1, m_sound_param_as[i].val_s.hi_key_map2, 
            rhnd.m_sound_param_as[i].val_s.hi_key_map2);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.hi_key_map3 != rhnd.m_sound_param_as[i].val_s.hi_key_map3)
      {
         m_log->log("Sound %d: hi_key_map3: %d != %d", i + 1, m_sound_param_as[i].val_s.hi_key_map3, 
            rhnd.m_sound_param_as[i].val_s.hi_key_map3);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.hi_key_map4 != rhnd.m_sound_param_as[i].val_s.hi_key_map4)
      {
         m_log->log("Sound %d: hi_key_map4: %d != %d", i + 1, m_sound_param_as[i].val_s.hi_key_map4, 
            rhnd.m_sound_param_as[i].val_s.hi_key_map4);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.hi_key_map5 != rhnd.m_sound_param_as[i].val_s.hi_key_map5)
      {
         m_log->log("Sound %d: hi_key_map5: %d != %d", i + 1, m_sound_param_as[i].val_s.hi_key_map5, 
            rhnd.m_sound_param_as[i].val_s.hi_key_map5);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.hi_key_map6 != rhnd.m_sound_param_as[i].val_s.hi_key_map6)
      {
         m_log->log("Sound %d: hi_key_map6: %d != %d", i + 1, m_sound_param_as[i].val_s.hi_key_map6, 
            rhnd.m_sound_param_as[i].val_s.hi_key_map6);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.hi_key_map7 != rhnd.m_sound_param_as[i].val_s.hi_key_map7)
      {
         m_log->log("Sound %d: hi_key_map7: %d != %d", i + 1, m_sound_param_as[i].val_s.hi_key_map7, 
            rhnd.m_sound_param_as[i].val_s.hi_key_map7);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.hi_key_map8 != rhnd.m_sound_param_as[i].val_s.hi_key_map8)
      {
         m_log->log("Sound %d: hi_key_map8: %d != %d", i + 1, m_sound_param_as[i].val_s.hi_key_map8, 
            rhnd.m_sound_param_as[i].val_s.hi_key_map8);
         retval = true;
      }

      if(m_sound_param_as[i].val_s.relative_mix_map1 != rhnd.m_sound_param_as[i].val_s.relative_mix_map1)
      {
         m_log->log("Sound %d: relative_mix_map1: %d != %d", i + 1, m_sound_param_as[i].val_s.relative_mix_map1, 
            rhnd.m_sound_param_as[i].val_s.relative_mix_map1);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.relative_mix_map2 != rhnd.m_sound_param_as[i].val_s.relative_mix_map2)
      {
         m_log->log("Sound %d: relative_mix_map2: %d != %d", i + 1, m_sound_param_as[i].val_s.relative_mix_map2, 
            rhnd.m_sound_param_as[i].val_s.relative_mix_map2);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.relative_mix_map3 != rhnd.m_sound_param_as[i].val_s.relative_mix_map3)
      {
         m_log->log("Sound %d: relative_mix_map3: %d != %d", i + 1, m_sound_param_as[i].val_s.relative_mix_map3, 
            rhnd.m_sound_param_as[i].val_s.relative_mix_map3);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.relative_mix_map4 != rhnd.m_sound_param_as[i].val_s.relative_mix_map4)
      {
         m_log->log("Sound %d: relative_mix_map4: %d != %d", i + 1, m_sound_param_as[i].val_s.relative_mix_map4, 
            rhnd.m_sound_param_as[i].val_s.relative_mix_map4);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.relative_mix_map5 != rhnd.m_sound_param_as[i].val_s.relative_mix_map5)
      {
         m_log->log("Sound %d: relative_mix_map6: %d != %d", i + 1, m_sound_param_as[i].val_s.relative_mix_map6, 
            rhnd.m_sound_param_as[i].val_s.relative_mix_map6);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.relative_mix_map7 != rhnd.m_sound_param_as[i].val_s.relative_mix_map7)
      {
         m_log->log("Sound %d: relative_mix_map7: %d != %d", i + 1, m_sound_param_as[i].val_s.relative_mix_map7, 
            rhnd.m_sound_param_as[i].val_s.relative_mix_map7);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.relative_mix_map8 != rhnd.m_sound_param_as[i].val_s.relative_mix_map8)
      {
         m_log->log("Sound %d: relative_mix_map8: %d != %d", i + 1, m_sound_param_as[i].val_s.relative_mix_map8, 
            rhnd.m_sound_param_as[i].val_s.relative_mix_map8);
         retval = true;
      }
      if(m_sound_param_as[i].val_s.sample_rate != rhnd.m_sound_param_as[i].val_s.sample_rate)
      {
         m_log->log("Sound %d: sample_rate: %d != %d", i + 1, m_sound_param_as[i].val_s.sample_rate, 
            rhnd.m_sound_param_as[i].val_s.sample_rate);
         retval = true;
      }
   }

   if(!retval)
   {
      m_log->log("No differences!");
   }

   return retval;
}


void Proph2000::sendSelectRequest(void) 
{ 
   m_send_select_request = true; 
}


void Proph2000::setExtendedMemory(bool flag) 
{ 
   m_extended_memory = flag; 
   remapMemory();
}


uint32_t Proph2000::getSampleWords(uint8_t sample_id) const
{ 
   uint32_t retval = 0;
   if(m_sound_param_as[sample_id].val_s.sample_status)
   {
      uint32_t begin_adr;
      begin_adr = m_sound_param_as[sample_id].val_s.begin_addr[2];
      begin_adr |= ((uint32_t)m_sound_param_as[sample_id].val_s.begin_addr[1] << 8);
      begin_adr |= ((uint32_t)m_sound_param_as[sample_id].val_s.begin_addr[0] << 16);

      retval = m_sound_param_as[sample_id].val_s.finish_addr[2];
      retval |= ((uint32_t)m_sound_param_as[sample_id].val_s.finish_addr[1] << 8);
      retval |= ((uint32_t)m_sound_param_as[sample_id].val_s.finish_addr[0] << 16);

      retval = retval - begin_adr;
   }
   return retval;
}


uint32_t Proph2000::getStartPoint(uint8_t sample_id) const
{
   uint32_t retval = 0;
   if(m_sound_param_as[sample_id].val_s.sample_status)
   {
      uint32_t begin_adr;
      begin_adr = m_sound_param_as[sample_id].val_s.begin_addr[2];
      begin_adr |= ((uint32_t)m_sound_param_as[sample_id].val_s.begin_addr[1] << 8);
      begin_adr |= ((uint32_t)m_sound_param_as[sample_id].val_s.begin_addr[0] << 16);

      retval = m_sound_param_as[sample_id].val_s.start_point[2];
      retval |= ((uint32_t)m_sound_param_as[sample_id].val_s.start_point[1] << 8);
      retval |= ((uint32_t)m_sound_param_as[sample_id].val_s.start_point[0] << 16);

      retval = retval - begin_adr;
   }
   return retval;
}


void Proph2000::setStartPoint(uint8_t sample_id, uint32_t words)
{
   uint32_t adr;
   adr = m_sound_param_as[sample_id].val_s.begin_addr[2];
   adr |= ((uint32_t)m_sound_param_as[sample_id].val_s.begin_addr[1] << 8);
   adr |= ((uint32_t)m_sound_param_as[sample_id].val_s.begin_addr[0] << 16);

   adr += words;

   m_sound_param_as[sample_id].val_s.start_point[2] = adr & 0xff;
   m_sound_param_as[sample_id].val_s.start_point[1] = (adr & 0xff00) >> 8;
   m_sound_param_as[sample_id].val_s.start_point[0] = (adr & 0xff0000) >> 16;

   updateParamBytesFromStruct();
}


uint32_t Proph2000::getEndPoint(uint8_t sample_id) const
{
   uint32_t retval = 0;
   if(m_sound_param_as[sample_id].val_s.sample_status)
   {
      uint32_t begin_adr;
      begin_adr = m_sound_param_as[sample_id].val_s.begin_addr[2];
      begin_adr |= ((uint32_t)m_sound_param_as[sample_id].val_s.begin_addr[1] << 8);
      begin_adr |= ((uint32_t)m_sound_param_as[sample_id].val_s.begin_addr[0] << 16);

      retval = m_sound_param_as[sample_id].val_s.end_point[2];
      retval |= ((uint32_t)m_sound_param_as[sample_id].val_s.end_point[1] << 8);
      retval |= ((uint32_t)m_sound_param_as[sample_id].val_s.end_point[0] << 16);

      retval = retval - begin_adr;
   }
   return retval;
}

void Proph2000::setEndPoint(uint8_t sample_id, uint32_t words)
{
   uint32_t adr;
   adr = m_sound_param_as[sample_id].val_s.begin_addr[2];
   adr |= ((uint32_t)m_sound_param_as[sample_id].val_s.begin_addr[1] << 8);
   adr |= ((uint32_t)m_sound_param_as[sample_id].val_s.begin_addr[0] << 16);

   adr += words;

   m_sound_param_as[sample_id].val_s.end_point[2] = adr & 0xff;
   m_sound_param_as[sample_id].val_s.end_point[1] = (adr & 0xff00) >> 8;
   m_sound_param_as[sample_id].val_s.end_point[0] = (adr & 0xff0000) >> 16;

   updateParamBytesFromStruct();
}

uint32_t Proph2000::getSustainLoopStart(uint8_t sample_id) const
{
   uint32_t retval = 0;
   if(m_sound_param_as[sample_id].val_s.sample_status)
   {
      uint32_t begin_adr;
      begin_adr = m_sound_param_as[sample_id].val_s.begin_addr[2];
      begin_adr |= ((uint32_t)m_sound_param_as[sample_id].val_s.begin_addr[1] << 8);
      begin_adr |= ((uint32_t)m_sound_param_as[sample_id].val_s.begin_addr[0] << 16);

      retval = m_sound_param_as[sample_id].val_s.sustain_loop_start[2];
      retval |= ((uint32_t)m_sound_param_as[sample_id].val_s.sustain_loop_start[1] << 8);
      retval |= ((uint32_t)m_sound_param_as[sample_id].val_s.sustain_loop_start[0] << 16);

      retval = retval - begin_adr;
   }
   return retval;
}

void Proph2000::setSustainLoopStart(uint8_t sample_id, uint32_t words)
{
   uint32_t adr;
   adr = m_sound_param_as[sample_id].val_s.begin_addr[2];
   adr |= ((uint32_t)m_sound_param_as[sample_id].val_s.begin_addr[1] << 8);
   adr |= ((uint32_t)m_sound_param_as[sample_id].val_s.begin_addr[0] << 16);

   adr += words;

   m_sound_param_as[sample_id].val_s.sustain_loop_start[2] = adr & 0xff;
   m_sound_param_as[sample_id].val_s.sustain_loop_start[1] = (adr & 0xff00) >> 8;
   m_sound_param_as[sample_id].val_s.sustain_loop_start[0] = (adr & 0xff0000) >> 16;

   updateParamBytesFromStruct();
}

uint32_t Proph2000::getSustainLoopEnd(uint8_t sample_id) const
{
   uint32_t retval = 0;
   if(m_sound_param_as[sample_id].val_s.sample_status)
   {
      uint32_t begin_adr;
      begin_adr = m_sound_param_as[sample_id].val_s.begin_addr[2];
      begin_adr |= ((uint32_t)m_sound_param_as[sample_id].val_s.begin_addr[1] << 8);
      begin_adr |= ((uint32_t)m_sound_param_as[sample_id].val_s.begin_addr[0] << 16);

      retval = m_sound_param_as[sample_id].val_s.sustain_loop_end[2];
      retval |= ((uint32_t)m_sound_param_as[sample_id].val_s.sustain_loop_end[1] << 8);
      retval |= ((uint32_t)m_sound_param_as[sample_id].val_s.sustain_loop_end[0] << 16);

      retval = retval - begin_adr;
   }
   return retval;
}

void Proph2000::setSustainLoopEnd(uint8_t sample_id, uint32_t words)
{
   uint32_t adr;

   adr = m_sound_param_as[sample_id].val_s.begin_addr[2];
   adr |= ((uint32_t)m_sound_param_as[sample_id].val_s.begin_addr[1] << 8);
   adr |= ((uint32_t)m_sound_param_as[sample_id].val_s.begin_addr[0] << 16);

   adr += words;

   m_sound_param_as[sample_id].val_s.sustain_loop_end[2] = adr & 0xff;
   m_sound_param_as[sample_id].val_s.sustain_loop_end[1] = (adr & 0xff00) >> 8;
   m_sound_param_as[sample_id].val_s.sustain_loop_end[0] = (adr & 0xff0000) >> 16;

   updateParamBytesFromStruct();
}

uint32_t Proph2000::getReleaseLoopStart(uint8_t sample_id) const
{
   uint32_t retval = 0;
   if(m_sound_param_as[sample_id].val_s.sample_status)
   {
      uint32_t begin_adr;
      begin_adr = m_sound_param_as[sample_id].val_s.begin_addr[2];
      begin_adr |= ((uint32_t)m_sound_param_as[sample_id].val_s.begin_addr[1] << 8);
      begin_adr |= ((uint32_t)m_sound_param_as[sample_id].val_s.begin_addr[0] << 16);

      retval = m_sound_param_as[sample_id].val_s.release_loop_start[2];
      retval |= ((uint32_t)m_sound_param_as[sample_id].val_s.release_loop_start[1] << 8);
      retval |= ((uint32_t)m_sound_param_as[sample_id].val_s.release_loop_start[0] << 16);

      retval = retval - begin_adr;
   }
   return retval;
}

void Proph2000::setReleaseLoopStart(uint8_t sample_id, uint32_t words)
{
   uint32_t adr;

   adr = m_sound_param_as[sample_id].val_s.begin_addr[2];
   adr |= ((uint32_t)m_sound_param_as[sample_id].val_s.begin_addr[1] << 8);
   adr |= ((uint32_t)m_sound_param_as[sample_id].val_s.begin_addr[0] << 16);

   adr += words;

   m_sound_param_as[sample_id].val_s.release_loop_start[2] = adr & 0xff;
   m_sound_param_as[sample_id].val_s.release_loop_start[1] = (adr & 0xff00) >> 8;
   m_sound_param_as[sample_id].val_s.release_loop_start[0] = (adr & 0xff0000) >> 16;

   updateParamBytesFromStruct();
}

uint32_t Proph2000::getReleaseLoopEnd(uint8_t sample_id) const
{
   uint32_t retval = 0;
   if(m_sound_param_as[sample_id].val_s.sample_status)
   {
      uint32_t begin_adr;
      
      begin_adr = m_sound_param_as[sample_id].val_s.begin_addr[2];
      begin_adr |= ((uint32_t)m_sound_param_as[sample_id].val_s.begin_addr[1] << 8);
      begin_adr |= ((uint32_t)m_sound_param_as[sample_id].val_s.begin_addr[0] << 16);

      retval = m_sound_param_as[sample_id].val_s.release_loop_end[2];
      retval |= ((uint32_t)m_sound_param_as[sample_id].val_s.release_loop_end[1] << 8);
      retval |= ((uint32_t)m_sound_param_as[sample_id].val_s.release_loop_end[0] << 16);

      retval = retval - begin_adr;
   }
   return retval;
}

void Proph2000::setReleaseLoopEnd(uint8_t sample_id, uint32_t words)
{
   uint32_t adr;

   adr = m_sound_param_as[sample_id].val_s.begin_addr[2];
   adr |= ((uint32_t)m_sound_param_as[sample_id].val_s.begin_addr[1] << 8);
   adr |= ((uint32_t)m_sound_param_as[sample_id].val_s.begin_addr[0] << 16);

   adr += words;

   m_sound_param_as[sample_id].val_s.release_loop_end[2] = adr & 0xff;
   m_sound_param_as[sample_id].val_s.release_loop_end[1] = (adr & 0xff00) >> 8;
   m_sound_param_as[sample_id].val_s.release_loop_end[0] = (adr & 0xff0000) >> 16;

   updateParamBytesFromStruct();
}

void Proph2000::deleteSample(uint8_t sample_id)
{
   uint16_t i;
   for(i = 0; i < MAX_SAMPLE_NAME_LEN; i++)
   {
      m_samplename_au8[sample_id][i] = 0;
   }

   m_sound_param_as[sample_id].val_s.sample_status = 0;

   m_sound_param_as[sample_id].val_s.transpose_map1 = SOUND_NOT_MAPPED_VALUE;
   m_sound_param_as[sample_id].val_s.transpose_map2 = SOUND_NOT_MAPPED_VALUE;
   m_sound_param_as[sample_id].val_s.transpose_map3 = SOUND_NOT_MAPPED_VALUE;
   m_sound_param_as[sample_id].val_s.transpose_map4 = SOUND_NOT_MAPPED_VALUE;
   m_sound_param_as[sample_id].val_s.transpose_map5 = SOUND_NOT_MAPPED_VALUE;
   m_sound_param_as[sample_id].val_s.transpose_map6 = SOUND_NOT_MAPPED_VALUE;
   m_sound_param_as[sample_id].val_s.transpose_map7 = SOUND_NOT_MAPPED_VALUE;
   m_sound_param_as[sample_id].val_s.transpose_map8 = SOUND_NOT_MAPPED_VALUE;

   m_sound_param_as[sample_id].val_s.begin_addr[2] = 0 & 0xff;
   m_sound_param_as[sample_id].val_s.begin_addr[1] = (0 & 0xff00) >> 8;
   m_sound_param_as[sample_id].val_s.begin_addr[0] = (0 & 0xff0000) >> 16;

   m_sound_param_as[sample_id].val_s.start_point[2] = 0 & 0xff;
   m_sound_param_as[sample_id].val_s.start_point[1] = (0 & 0xff00) >> 8;
   m_sound_param_as[sample_id].val_s.start_point[0] = (0 & 0xff0000) >> 16;

   m_sound_param_as[sample_id].val_s.sustain_loop_start[2] = 1 & 0xff;
   m_sound_param_as[sample_id].val_s.sustain_loop_start[1] = (1 & 0xff00) >> 8;
   m_sound_param_as[sample_id].val_s.sustain_loop_start[0] = (1 & 0xff0000) >> 16;

   m_sound_param_as[sample_id].val_s.release_loop_start[2] = 1 & 0xff;
   m_sound_param_as[sample_id].val_s.release_loop_start[1] = (1 & 0xff00) >> 8;
   m_sound_param_as[sample_id].val_s.release_loop_start[0] = (1 & 0xff0000) >> 16;

   m_sound_param_as[sample_id].val_s.end_point[2] = 0 & 0xff;
   m_sound_param_as[sample_id].val_s.end_point[1] = (0 & 0xff00) >> 8;
   m_sound_param_as[sample_id].val_s.end_point[0] = (0 & 0xff0000) >> 16;

   m_sound_param_as[sample_id].val_s.finish_addr[2] = 0x3ff & 0xff;
   m_sound_param_as[sample_id].val_s.finish_addr[1] = (0x3ff & 0xff00) >> 8;
   m_sound_param_as[sample_id].val_s.finish_addr[0] = (0x3ff & 0xff0000) >> 16;

   m_sound_param_as[sample_id].val_s.release_loop_end[2] = 3 & 0xff;
   m_sound_param_as[sample_id].val_s.release_loop_end[1] = (3 & 0xff00) >> 8;
   m_sound_param_as[sample_id].val_s.release_loop_end[0] = (3 & 0xff0000) >> 16;

   m_sound_param_as[sample_id].val_s.sustain_loop_end[2] = 2 & 0xff;
   m_sound_param_as[sample_id].val_s.sustain_loop_end[1] = (2 & 0xff00) >> 8;
   m_sound_param_as[sample_id].val_s.sustain_loop_end[0] = (2 & 0xff0000) >> 16;

   updateParamBytesFromStruct();
   remapMemory();
}

bool Proph2000::sustainLoopEnabled(uint8_t sample_id) const
{
   bool retval = false;
   if(m_sound_param_as[sample_id].val_s.sample_status & 0x01)
   {
      retval = true;
   }
   return retval;
}

bool Proph2000::releaseLoopEnabled(uint8_t sample_id) const
{
   bool retval = false;
   if(m_sound_param_as[sample_id].val_s.sample_status & 0x02)
   {
      retval = true;
   }
   return retval;
}

void Proph2000::setReleaseLoopActive(uint8_t sample_id, bool flag)
{
   if(flag)
   {
      m_sound_param_as[sample_id].val_s.sample_status |= 0x02;
   }
   else
   {
      m_sound_param_as[sample_id].val_s.sample_status &= ~0x02;
   }
   updateParamBytesFromStruct();
}

bool Proph2000::bfLoopEnabled(uint8_t sample_id) const
{
   bool retval = false;
   if(m_sound_param_as[sample_id].val_s.sample_status & 0x04)
   {
      retval = true;
   }
   return retval;
}

void Proph2000::setBfLoopActive(uint8_t sample_id, bool flag)
{
   if(flag)
   {
      m_sound_param_as[sample_id].val_s.sample_status |= 0x04;
   }
   else
   {
      m_sound_param_as[sample_id].val_s.sample_status &= ~0x04;
   }
   updateParamBytesFromStruct();
}

bool Proph2000::reverseEnabled(uint8_t sample_id) const
{
   bool retval = false;
   if(m_sound_param_as[sample_id].val_s.sample_status & 0x08)
   {
      retval = true;
   }
   return retval;
}

void Proph2000::setReverseActive(uint8_t sample_id, bool flag)
{
   if(flag)
   {
      m_sound_param_as[sample_id].val_s.sample_status |= 0x08;
   }
   else
   {
      m_sound_param_as[sample_id].val_s.sample_status &= ~0x08;
   }
   updateParamBytesFromStruct();
}


void Proph2000::clear(void)
{
   uint8_t i;
   uint32_t i2;
   m_main_mode_e = PROPH_IDLE;
   m_sub_mode_u16 = 0;
   m_handle_id = 0;
   memset(&m_sound_param_as, 0, sizeof(m_sound_param_as));
   memset(&m_preset_param_as, 0, sizeof(m_preset_param_as));
   memset(&m_map_param_as, 0, sizeof(m_map_param_as));
   memset(&m_sample_length_words_au32, 0, sizeof(m_sample_length_words_au32));
   memset(&m_soundparam_au8, 0, sizeof(m_soundparam_au8));   
   memset(&m_mapparam_au8, 0, sizeof(m_mapparam_au8));   
   memset(&m_presetparam_au8, 0, sizeof(m_presetparam_au8));   

   for(i = 0; i < 16; i++)
   {
      for(i2 = 0; i2 < MAX_SAMPLE_NAME_LEN; i2++)
      {
         m_samplename_au8[i][i2] = 0;
      }
   }

   for(i = 0; i < 16; i++)
   {
      for(i2 = 0; i2 < MAX_SAMPLE_WORDS_PER_MEMORY; i2++)
      {
         m_sampledata_au16[i][i2] = (4096 / 2);
      }
   }

   for(i = 0; i < 16; i++)
   {
      m_sound_param_as[i].val_s.amp_decay_rate = 0x3f;
      m_sound_param_as[i].val_s.amp_sustain_level = 0xff;
      m_sound_param_as[i].val_s.amp_peak_vel_sensitivity = 0x80;
      m_sound_param_as[i].val_s.attack_vel_sensitivity = 0x80;
      m_sound_param_as[i].val_s.release_vel_sensitivity = 0x80;
      m_sound_param_as[i].val_s.filt_decay_rate = 0x3f;
      m_sound_param_as[i].val_s.filt_sustain_level = 0xff;
      m_sound_param_as[i].val_s.filt_env_amount = 0x80;
      m_sound_param_as[i].val_s.filt_peak_vel_sensitivity = 0x80;
      m_sound_param_as[i].val_s.root_key = KEYBOARD_C3;
      m_sound_param_as[i].val_s.filt_cutoff[1] = (32767 & 0xff);
      m_sound_param_as[i].val_s.filt_cutoff[0] = (32767 & 0xff00) >> 8;
      m_sound_param_as[i].val_s.filt_resonance[1] = (63 & 0xff);
      m_sound_param_as[i].val_s.filt_resonance[0] = (63 & 0xff00) >> 8;
      m_sound_param_as[i].val_s.transpose_map1 = SOUND_NOT_MAPPED_VALUE;
      m_sound_param_as[i].val_s.transpose_map2 = SOUND_NOT_MAPPED_VALUE;
      m_sound_param_as[i].val_s.transpose_map3 = SOUND_NOT_MAPPED_VALUE;
      m_sound_param_as[i].val_s.transpose_map4 = SOUND_NOT_MAPPED_VALUE;
      m_sound_param_as[i].val_s.transpose_map5 = SOUND_NOT_MAPPED_VALUE;
      m_sound_param_as[i].val_s.transpose_map6 = SOUND_NOT_MAPPED_VALUE;
      m_sound_param_as[i].val_s.transpose_map7 = SOUND_NOT_MAPPED_VALUE;
      m_sound_param_as[i].val_s.transpose_map8 = SOUND_NOT_MAPPED_VALUE;
      m_sound_param_as[i].val_s.relative_mix_map1 = 0xff;
      m_sound_param_as[i].val_s.relative_mix_map2 = 0xff;
      m_sound_param_as[i].val_s.relative_mix_map3 = 0xff;
      m_sound_param_as[i].val_s.relative_mix_map4 = 0xff;
      m_sound_param_as[i].val_s.relative_mix_map5 = 0xff;
      m_sound_param_as[i].val_s.relative_mix_map6 = 0xff;
      m_sound_param_as[i].val_s.relative_mix_map7 = 0xff;
      m_sound_param_as[i].val_s.relative_mix_map8 = 0xff;
      m_sound_param_as[i].val_s.velocity_start_point = 0x80;
      m_sound_param_as[i].val_s.amp_release_rate = 1;
      m_sound_param_as[i].val_s.amp_2nd_release_rate = 1;
      m_sound_param_as[i].val_s.filt_2nd_release_rate = 1;
      m_sound_param_as[i].val_s.filt_release_rate = 1;
   }
   for(i = 0; i < 16; i++)
   {
      m_map_param_as[i].val_s.amp_release_rate = 0x80;
      m_map_param_as[i].val_s.amp_2nd_release_rate = 0x80;
      m_map_param_as[i].val_s.amp_decay_rate = 0x80;
      m_map_param_as[i].val_s.amp_sustain_level = 0x80;
      m_map_param_as[i].val_s.amp_attack_rate = 0x80;
      m_map_param_as[i].val_s.amp_peak_vel_sensitivity = 0x80;
      m_map_param_as[i].val_s.filt_release_rate = 0x80;
      m_map_param_as[i].val_s.filt_2nd_release_rate = 0x80;
      m_map_param_as[i].val_s.filt_decay_rate = 0x80;
      m_map_param_as[i].val_s.filt_sustain_level = 0x80;
      m_map_param_as[i].val_s.filt_attack_rate = 0x80;
      m_map_param_as[i].val_s.filt_peak_vel_sensitivity = 0x80;
      m_map_param_as[i].val_s.filt_resonance = 0x80;
      m_map_param_as[i].val_s.filt_cutoff = 0x80;
      m_map_param_as[i].val_s.filt_env_amount = 0x80;
      m_map_param_as[i].val_s.filt_keyboard_tracking = 0x80;
      m_map_param_as[i].val_s.attack_vel_sensitivity = 0x80;
      m_map_param_as[i].val_s.release_vel_sensitivity = 0x80;
      m_map_param_as[i].val_s.sound_direction = 128;
      m_map_param_as[i].val_s.velocity_start_point = 0x80;
      m_map_param_as[i].val_s.filt_resonance_l = 0x80;
      m_map_param_as[i].val_s.filt_cutoff_l = 0x80;
   }
   for(i = 0; i < 12; i++)
   {
      m_preset_param_as[i].val_s.right_y_map_side = 1;
      m_preset_param_as[i].val_s.lfo_vel_sensitivity = 0x80;
      m_preset_param_as[i].val_s.split_point = KEYBOARD_C3;
      m_preset_param_as[i].val_s.pitchwheel_range = 2;
      m_preset_param_as[i].val_s.midi_mode = 2;
      m_preset_param_as[i].val_s.midi_opts = 0x77;
      m_preset_param_as[i].val_s.arp_oct = 1;
   }
   updateParamBytesFromStruct();
}


void Proph2000::remapMemory(void)
{
   uint8_t i;
   uint32_t last_adr = 0;
   uint32_t begin_adr;
   uint32_t startpoint;
   uint32_t sustain_loop_start;
   uint32_t sustain_loop_end;
   uint32_t release_loop_start;
   uint32_t release_loop_end;
   uint32_t endpoint;
   uint32_t finish_adr;
   uint32_t t;

   m_log->log("remapMemory()");

   updateStructsFromParamBytes();

   // sample <9: start >= 0x0 < 0x40000
   // sample >= 9: start >= 0x040000

   for(i = 0; i < 8; i++)
   {
      if(m_sound_param_as[i].val_s.sample_status)
      {
         //m_log->log("sample %d:", i);
         begin_adr = m_sound_param_as[i].val_s.begin_addr[2];
         begin_adr |= ((uint32_t)m_sound_param_as[i].val_s.begin_addr[1] << 8);
         begin_adr |= ((uint32_t)m_sound_param_as[i].val_s.begin_addr[0] << 16);

         m_sound_param_as[i].val_s.begin_addr[2] = last_adr & 0xff;
         m_sound_param_as[i].val_s.begin_addr[1] = (last_adr & 0xff00) >> 8;
         m_sound_param_as[i].val_s.begin_addr[0] = (last_adr & 0xff0000) >> 16;
         //m_log->log(" beginadr:0x%.6x", last_adr);
         t = m_sound_param_as[i].val_s.start_point[2];
         t |= ((uint32_t)m_sound_param_as[i].val_s.start_point[1] << 8);
         t |= ((uint32_t)m_sound_param_as[i].val_s.start_point[0] << 16);

         startpoint = t - begin_adr;
         startpoint += last_adr;
         //m_log->log(" startpoint:0x%.6x", startpoint);
         m_sound_param_as[i].val_s.start_point[2] = startpoint & 0xff;
         m_sound_param_as[i].val_s.start_point[1] = (startpoint & 0xff00) >> 8;
         m_sound_param_as[i].val_s.start_point[0] = (startpoint & 0xff0000) >> 16;

         t = m_sound_param_as[i].val_s.sustain_loop_start[2];
         t |= ((uint32_t)m_sound_param_as[i].val_s.sustain_loop_start[1] << 8);
         t |= ((uint32_t)m_sound_param_as[i].val_s.sustain_loop_start[0] << 16);

         sustain_loop_start = t - begin_adr;
         sustain_loop_start += last_adr;
         //m_log->log("  sustain_loop_start:0x%.6x", sustain_loop_start);
         m_sound_param_as[i].val_s.sustain_loop_start[2] = sustain_loop_start & 0xff;
         m_sound_param_as[i].val_s.sustain_loop_start[1] = (sustain_loop_start & 0xff00) >> 8;
         m_sound_param_as[i].val_s.sustain_loop_start[0] = (sustain_loop_start & 0xff0000) >> 16;

         t = m_sound_param_as[i].val_s.sustain_loop_end[2];
         t |= ((uint32_t)m_sound_param_as[i].val_s.sustain_loop_end[1] << 8);
         t |= ((uint32_t)m_sound_param_as[i].val_s.sustain_loop_end[0] << 16);

         sustain_loop_end = t - begin_adr;
         sustain_loop_end += last_adr;
         //m_log->log(" sustain_loop_end:0x%.6x", sustain_loop_end);
         m_sound_param_as[i].val_s.sustain_loop_end[2] = sustain_loop_end & 0xff;
         m_sound_param_as[i].val_s.sustain_loop_end[1] = (sustain_loop_end & 0xff00) >> 8;
         m_sound_param_as[i].val_s.sustain_loop_end[0] = (sustain_loop_end & 0xff0000) >> 16;

         t = m_sound_param_as[i].val_s.release_loop_start[2];
         t |= ((uint32_t)m_sound_param_as[i].val_s.release_loop_start[1] << 8);
         t |= ((uint32_t)m_sound_param_as[i].val_s.release_loop_start[0] << 16);

         release_loop_start = t - begin_adr;
         release_loop_start += last_adr;
         //m_log->log(" release_loop_start:0x%.6x", release_loop_start);
         m_sound_param_as[i].val_s.release_loop_start[2] = release_loop_start & 0xff;
         m_sound_param_as[i].val_s.release_loop_start[1] = (release_loop_start & 0xff00) >> 8;
         m_sound_param_as[i].val_s.release_loop_start[0] = (release_loop_start & 0xff0000) >> 16;

         t = m_sound_param_as[i].val_s.release_loop_end[2];
         t |= ((uint32_t)m_sound_param_as[i].val_s.release_loop_end[1] << 8);
         t |= ((uint32_t)m_sound_param_as[i].val_s.release_loop_end[0] << 16);

         release_loop_end = t - begin_adr;
         release_loop_end += last_adr;
         //m_log->log(" release_loop_end:0x%.6x", release_loop_end);
         m_sound_param_as[i].val_s.release_loop_end[2] = release_loop_end & 0xff;
         m_sound_param_as[i].val_s.release_loop_end[1] = (release_loop_end & 0xff00) >> 8;
         m_sound_param_as[i].val_s.release_loop_end[0] = (release_loop_end & 0xff0000) >> 16;

         t = m_sound_param_as[i].val_s.end_point[2];
         t |= ((uint32_t)m_sound_param_as[i].val_s.end_point[1] << 8);
         t |= ((uint32_t)m_sound_param_as[i].val_s.end_point[0] << 16);

         endpoint = t - begin_adr;
         endpoint += last_adr;
         //m_log->log(" endpoint:0x%.6x", endpoint);
         m_sound_param_as[i].val_s.end_point[2] = endpoint & 0xff;
         m_sound_param_as[i].val_s.end_point[1] = (endpoint & 0xff00) >> 8;
         m_sound_param_as[i].val_s.end_point[0] = (endpoint & 0xff0000) >> 16;

         t = m_sound_param_as[i].val_s.finish_addr[2];
         t |= ((uint32_t)m_sound_param_as[i].val_s.finish_addr[1] << 8);
         t |= ((uint32_t)m_sound_param_as[i].val_s.finish_addr[0] << 16);

         finish_adr = t - begin_adr;
         finish_adr += last_adr;

         finish_adr = finish_adr - (finish_adr & 0x3ff) + 0x3ff;
         //m_log->log(" finish_adr:0x%.6x", finish_adr);
         m_sound_param_as[i].val_s.finish_addr[2] = finish_adr & 0xff;
         m_sound_param_as[i].val_s.finish_addr[1] = (finish_adr & 0xff00) >> 8;
         m_sound_param_as[i].val_s.finish_addr[0] = (finish_adr & 0xff0000) >> 16;

         last_adr = finish_adr + 1;
      }
   }

   if(m_extended_memory)
   {
      last_adr = 0x040000;
   }
   else
   {
      last_adr = 0x020000;
   }

   for(i = 8; i < 16; i++)
   {
      if(m_sound_param_as[i].val_s.sample_status)
      {
         begin_adr = m_sound_param_as[i].val_s.begin_addr[2];
         begin_adr |= ((uint32_t)m_sound_param_as[i].val_s.begin_addr[1] << 8);
         begin_adr |= ((uint32_t)m_sound_param_as[i].val_s.begin_addr[0] << 16);

         m_sound_param_as[i].val_s.begin_addr[2] = last_adr & 0xff;
         m_sound_param_as[i].val_s.begin_addr[1] = (last_adr & 0xff00) >> 8;
         m_sound_param_as[i].val_s.begin_addr[0] = (last_adr & 0xff0000) >> 16;

         t = m_sound_param_as[i].val_s.start_point[2];
         t |= ((uint32_t)m_sound_param_as[i].val_s.start_point[1] << 8);
         t |= ((uint32_t)m_sound_param_as[i].val_s.start_point[0] << 16);

         startpoint = t - begin_adr;
         startpoint += last_adr;

         m_sound_param_as[i].val_s.start_point[2] = startpoint & 0xff;
         m_sound_param_as[i].val_s.start_point[1] = (startpoint & 0xff00) >> 8;
         m_sound_param_as[i].val_s.start_point[0] = (startpoint & 0xff0000) >> 16;

         t = m_sound_param_as[i].val_s.sustain_loop_start[2];
         t |= ((uint32_t)m_sound_param_as[i].val_s.sustain_loop_start[1] << 8);
         t |= ((uint32_t)m_sound_param_as[i].val_s.sustain_loop_start[0] << 16);

         sustain_loop_start = t - begin_adr;
         sustain_loop_start += last_adr;

         m_sound_param_as[i].val_s.sustain_loop_start[2] = sustain_loop_start & 0xff;
         m_sound_param_as[i].val_s.sustain_loop_start[1] = (sustain_loop_start & 0xff00) >> 8;
         m_sound_param_as[i].val_s.sustain_loop_start[0] = (sustain_loop_start & 0xff0000) >> 16;

         t = m_sound_param_as[i].val_s.sustain_loop_end[2];
         t |= ((uint32_t)m_sound_param_as[i].val_s.sustain_loop_end[1] << 8);
         t |= ((uint32_t)m_sound_param_as[i].val_s.sustain_loop_end[0] << 16);

         sustain_loop_end = t - begin_adr;
         sustain_loop_end += last_adr;

         m_sound_param_as[i].val_s.sustain_loop_end[2] = sustain_loop_end & 0xff;
         m_sound_param_as[i].val_s.sustain_loop_end[1] = (sustain_loop_end & 0xff00) >> 8;
         m_sound_param_as[i].val_s.sustain_loop_end[0] = (sustain_loop_end & 0xff0000) >> 16;

         t = m_sound_param_as[i].val_s.release_loop_start[2];
         t |= ((uint32_t)m_sound_param_as[i].val_s.release_loop_start[1] << 8);
         t |= ((uint32_t)m_sound_param_as[i].val_s.release_loop_start[0] << 16);

         release_loop_start = t - begin_adr;
         release_loop_start += last_adr;
         m_sound_param_as[i].val_s.release_loop_start[2] = release_loop_start & 0xff;
         m_sound_param_as[i].val_s.release_loop_start[1] = (release_loop_start & 0xff00) >> 8;
         m_sound_param_as[i].val_s.release_loop_start[0] = (release_loop_start & 0xff0000) >> 16;

         t = m_sound_param_as[i].val_s.release_loop_end[2];
         t |= ((uint32_t)m_sound_param_as[i].val_s.release_loop_end[1] << 8);
         t |= ((uint32_t)m_sound_param_as[i].val_s.release_loop_end[0] << 16);

         release_loop_end = t - begin_adr;
         release_loop_end += last_adr;
         m_sound_param_as[i].val_s.release_loop_end[2] = release_loop_end & 0xff;
         m_sound_param_as[i].val_s.release_loop_end[1] = (release_loop_end & 0xff00) >> 8;
         m_sound_param_as[i].val_s.release_loop_end[0] = (release_loop_end & 0xff0000) >> 16;

         t = m_sound_param_as[i].val_s.end_point[2];
         t |= ((uint32_t)m_sound_param_as[i].val_s.end_point[1] << 8);
         t |= ((uint32_t)m_sound_param_as[i].val_s.end_point[0] << 16);

         endpoint = t - begin_adr;
         endpoint += last_adr;
         m_sound_param_as[i].val_s.end_point[2] = endpoint & 0xff;
         m_sound_param_as[i].val_s.end_point[1] = (endpoint & 0xff00) >> 8;
         m_sound_param_as[i].val_s.end_point[0] = (endpoint & 0xff0000) >> 16;

         t = m_sound_param_as[i].val_s.finish_addr[2];
         t |= ((uint32_t)m_sound_param_as[i].val_s.finish_addr[1] << 8);
         t |= ((uint32_t)m_sound_param_as[i].val_s.finish_addr[0] << 16);

         finish_adr = t - begin_adr;
         finish_adr += last_adr;

         finish_adr = finish_adr - (finish_adr & 0x3ff) + 0x3ff;
         m_sound_param_as[i].val_s.finish_addr[2] = finish_adr & 0xff;
         m_sound_param_as[i].val_s.finish_addr[1] = (finish_adr & 0xff00) >> 8;
         m_sound_param_as[i].val_s.finish_addr[0] = (finish_adr & 0xff0000) >> 16;

         last_adr = finish_adr + 1;
      }
   }

   updateParamBytesFromStruct();
}


Proph2000::sample_rate_te Proph2000::getSampleRate(uint8_t sample_id) const
{
   sample_rate_te retval;

   switch(m_sound_param_as[sample_id].val_s.sample_rate)
   {
      case 0xff:
         retval = SR_15625HZ;
      break;
      case 0x00:
         retval = SR_31250HZ;
         break;
      case 0x01:
         retval = SR_41667HZ;
         break;
      default:
         retval = SR_41667HZ;
         break;
   }
   return retval;
}



void Proph2000::setSampleData(uint8_t sample_id, uint16_t *data, uint32_t sample_words, uint32_t sample_rate)
{
   uint32_t i;
   uint32_t copywords = sample_words;

   for(i = 0; i < MAX_SAMPLE_WORDS_PER_MEMORY; i++)
   {
      m_sampledata_au16[sample_id][i] = 4096 / 2;
   }

   if(m_extended_memory)
   {
      if(copywords > MAX_SAMPLE_BANK_WORDS_EXTENDED)
      {
         copywords = MAX_SAMPLE_BANK_WORDS_EXTENDED;
      }
   }
   else
   {
      if(copywords > MAX_SAMPLE_BANK_WORDS_UNEXTENDED)
      {
         copywords = MAX_SAMPLE_BANK_WORDS_UNEXTENDED;
      }
   }

   for(i = 0; i < copywords; i++)
   {
      m_sampledata_au16[sample_id][i] = data[i];
   }

   switch(sample_rate)
   {
      case 15625:
         m_sound_param_as[sample_id].val_s.sample_rate = 0xff;
      break;
      case 31250:
         m_sound_param_as[sample_id].val_s.sample_rate = 0x00;
         break;
      case 41667:
         m_sound_param_as[sample_id].val_s.sample_rate = 0x01;
         break;
      default:
         m_sound_param_as[sample_id].val_s.sample_rate = 0x01;
         break;
   }

   m_sound_param_as[sample_id].val_s.sample_status = 48;

   m_sound_param_as[sample_id].val_s.begin_addr[2] = 0 & 0xff;
   m_sound_param_as[sample_id].val_s.begin_addr[1] = (0 & 0xff00) >> 8;
   m_sound_param_as[sample_id].val_s.begin_addr[0] = (0 & 0xff0000) >> 16;

   m_sound_param_as[sample_id].val_s.start_point[2] = 0 & 0xff;
   m_sound_param_as[sample_id].val_s.start_point[1] = (0 & 0xff00) >> 8;
   m_sound_param_as[sample_id].val_s.start_point[0] = (0 & 0xff0000) >> 16;

   m_sound_param_as[sample_id].val_s.sustain_loop_start[2] = 0 & 0xff;
   m_sound_param_as[sample_id].val_s.sustain_loop_start[1] = (0 & 0xff00) >> 8;
   m_sound_param_as[sample_id].val_s.sustain_loop_start[0] = (0 & 0xff0000) >> 16;

   m_sound_param_as[sample_id].val_s.release_loop_start[2] = 0 & 0xff;
   m_sound_param_as[sample_id].val_s.release_loop_start[1] = (0 & 0xff00) >> 8;
   m_sound_param_as[sample_id].val_s.release_loop_start[0] = (0 & 0xff0000) >> 16;

   m_sound_param_as[sample_id].val_s.end_point[2] = copywords & 0xff;
   m_sound_param_as[sample_id].val_s.end_point[1] = (copywords & 0xff00) >> 8;
   m_sound_param_as[sample_id].val_s.end_point[0] = (copywords & 0xff0000) >> 16;

   copywords = copywords - (copywords & 0x3ff) + 0x3ff;
   m_sound_param_as[sample_id].val_s.finish_addr[2] = copywords & 0xff;
   m_sound_param_as[sample_id].val_s.finish_addr[1] = (copywords & 0xff00) >> 8;
   m_sound_param_as[sample_id].val_s.finish_addr[0] = (copywords & 0xff0000) >> 16;

   m_sound_param_as[sample_id].val_s.release_loop_end[2] = copywords & 0xff;
   m_sound_param_as[sample_id].val_s.release_loop_end[1] = (copywords & 0xff00) >> 8;
   m_sound_param_as[sample_id].val_s.release_loop_end[0] = (copywords & 0xff0000) >> 16;

   m_sound_param_as[sample_id].val_s.sustain_loop_end[2] = copywords & 0xff;
   m_sound_param_as[sample_id].val_s.sustain_loop_end[1] = (copywords & 0xff00) >> 8;
   m_sound_param_as[sample_id].val_s.sustain_loop_end[0] = (copywords & 0xff0000) >> 16;

   updateParamBytesFromStruct();
   remapMemory();
}


bool Proph2000::load(const char *filename)
{
   bool retval = false;
   m_log->log("load %s", filename);
   FILE *myF;
   myF = fopen(filename, "rb");
   if(myF)
   {
      uint8_t i;
      uint8_t ctmp[10];
      clear();

      memset(&m_p2kconfig_s, 0, sizeof(m_p2kconfig_s));

      fread(ctmp, 1, 5, myF);

      for(i = 0; i < 16; i++)
      {
         fread(&m_soundparam_au8[i], 1, SOUND_PARAM_BYTES * 2, myF);
      }
      for(i = 0; i < 12; i++)
      {      
         fread(&m_presetparam_au8[i], 1, PRESET_PARAM_BYTES * 2, myF);
      }
      for(i = 0; i < 16; i++)
      {
         fread(&m_mapparam_au8[i], 1, MAP_PARAM_BYTES * 2, myF);
      }

      for(i = 0; i < 16; i++)
      {
         fread(&m_sample_length_words_au32[i], 1, 4, myF);
         //m_log->log(" sample %d words:%d", i, m_sample_length_words_au32[i]);
         if(m_sample_length_words_au32[i])
         {
            uint32_t i2;
            for(i2 = 0; i2 < m_sample_length_words_au32[i]; i2++)
            {
               fread(&m_sampledata_au16[i][i2], 1, 2, myF);
            }
         }
      }

      for(i = 0; i < 16; i++)
      {
         fread(&m_samplename_au8[i][0], 1, MAX_SAMPLE_NAME_LEN, myF);
      }

      fread(&m_p2kconfig_s, 1, sizeof(m_p2kconfig_s), myF);

      remapMemory();

      retval = true;
      fclose(myF);
   }

   return retval;
}


bool Proph2000::save(const char *filename) const
{
   bool retval = false;

   m_log->log("save %s", filename);

   FILE *myF;
   myF = fopen(filename, "wb");
   if(myF)
   {
      uint8_t i;

      fwrite("P2K01", 1, 5, myF);

      for(i = 0; i < 16; i++)
      {
         fwrite(&m_soundparam_au8[i], 1, SOUND_PARAM_BYTES * 2, myF);
      }
      for(i = 0; i < 12; i++)
      {      
         fwrite(&m_presetparam_au8[i], 1, PRESET_PARAM_BYTES * 2, myF);
      }
      for(i = 0; i < 16; i++)
      {
         fwrite(&m_mapparam_au8[i], 1, MAP_PARAM_BYTES * 2, myF);
      }

      for(i = 0; i < 16; i++)
      {
         uint32_t len;
         len = getSampleWords(i);
         fwrite(&len, 1, 4, myF);
         if(len)
         {
            uint32_t i2;
            for(i2 = 0; i2 < len; i2++)
            {
               fwrite(&m_sampledata_au16[i][i2], 1, 2, myF);
            }
         }
      }

      for(i = 0; i < 16; i++)
      {
         fwrite(&m_samplename_au8[i][0], 1, MAX_SAMPLE_NAME_LEN, myF);
      }

      fwrite(&m_p2kconfig_s, 1, sizeof(m_p2kconfig_s), myF);

      retval = true;
      fclose(myF);
   }

   return retval;
}

bool Proph2000::saveWave(uint8_t sample_id, const char *filename)
{
   bool retval;

   if(getSampleWords(sample_id))
   {
      uint32_t samplerate;

      switch(getSampleRate(sample_id))
      {
         case SR_15625HZ:
            samplerate = 15625;
            break;
         case SR_31250HZ:
            samplerate = 31250;
            break;
         case SR_41667HZ:
            samplerate = 41667;
            break;
         default:
            samplerate = 41667;
            break;
      }
   
      Wave myWave(&m_sampledata_au16[sample_id][0], getSampleWords(sample_id), samplerate);

      if(releaseLoopEnabled(sample_id))
      {
         myWave.setLoopStart(getReleaseLoopStart(sample_id));
         myWave.setLoopEnd(getReleaseLoopEnd(sample_id));

         if(bfLoopEnabled(sample_id))
         {
            myWave.setLoopType(Wave::LOOP_BF);
         }
         else
         if(reverseEnabled(sample_id))
         {
            myWave.setLoopType(Wave::LOOP_REVERSE);
         }
         else
         {
            myWave.setLoopType(Wave::LOOP_NORMAL);
         }         
      }

      retval = myWave.save(filename);
   }
   else
   {
      retval = true;
   }

   return retval;
}

void Proph2000::sendMIDIPacket(uint8_t *data, uint8_t len)
{
   m_midi->sendMIDIPacket(data, len);
}



void Proph2000::sendSampleDumpRequest(uint8_t channel_u8, uint8_t sample_id_u8, bool map_received_data)
{
   uint8_t dump_request_au8[7];
#ifdef LOG_SEND_SAMPLE_DUMP_REQUEST
   m_log->log("sendSampleDumpRequest(ch:%d, sample:%d)", channel_u8 + 1, sample_id_u8 + 1);
#endif
   dump_request_au8[0] = 0xf0;
   dump_request_au8[1] = 0x7e;
   dump_request_au8[2] = channel_u8;
   dump_request_au8[3] = 0x03;
   dump_request_au8[4] = sample_id_u8;
   dump_request_au8[5] = 0x00;
   dump_request_au8[6] = 0xf7;
   m_map_received_data = map_received_data;
   m_map_rx_slot = sample_id_u8;
   resetRx();
   sendMIDIPacket(dump_request_au8, sizeof(dump_request_au8));
}


void Proph2000::sendAck(uint8_t channel_u8, uint8_t packet_number_u8)
{
   uint8_t ack_au8[6];
   ack_au8[0] = 0xf0;
   ack_au8[1] = 0x7e;
   ack_au8[2] = channel_u8;
   ack_au8[3] = 0x7f;
   ack_au8[4] = packet_number_u8;
   ack_au8[5] = 0xf7;
   resetRx();
   sendMIDIPacket(ack_au8, sizeof(ack_au8));
}

void Proph2000::sendNack(uint8_t channel_u8, uint8_t packet_number_u8)
{
   uint8_t nack_au8[6];
   m_log->log("sendNack(ch:%d, packet:%d)", channel_u8 + 1, packet_number_u8);
   nack_au8[0] = 0xf0;
   nack_au8[1] = 0x7e;
   nack_au8[2] = channel_u8;
   nack_au8[3] = 0x7e;   
   nack_au8[4] = packet_number_u8;
   nack_au8[5] = 0xf7;
   resetRx();
   sendMIDIPacket(nack_au8, sizeof(nack_au8));
}

void Proph2000::sendCancel(uint8_t channel_u8, uint8_t packet_number_u8)
{
   uint8_t cancel_au8[6];
   m_log->log("sendCancel(ch:%d, packet:%d)", channel_u8 + 1, packet_number_u8);
   cancel_au8[0] = 0xf0;
   cancel_au8[1] = 0x7e;
   cancel_au8[2] = channel_u8;
   cancel_au8[3] = 0x7d;
   cancel_au8[4] = packet_number_u8;
   cancel_au8[5] = 0xf7;
   resetRx();
   sendMIDIPacket(cancel_au8, sizeof(cancel_au8));
}

void Proph2000::sendWait(uint8_t channel_u8, uint8_t packet_number_u8)
{
   uint8_t wait_au8[6];
   //m_log->log("sendWait(ch:%d, packet:%d)", channel_u8 + 1, packet_number_u8);
   wait_au8[0] = 0xf0;
   wait_au8[1] = 0x7e;
   wait_au8[2] = channel_u8;
   wait_au8[3] = 0x7c;
   wait_au8[4] = packet_number_u8;
   wait_au8[5] = 0xf7;
   //resetRx(); -> hier kein resetRx() ! Ansonsten geht handshake algo nicht mehr
   sendMIDIPacket(wait_au8, sizeof(wait_au8));
}

void Proph2000::sendGenericDumpRequest(uint8_t selection_u8, bool map_received_data)
{
   uint8_t gen_au8[5];
   m_log->log("sendGenericDumpRequest(selection:%d)", selection_u8);
   gen_au8[0] = 0xf0;
   gen_au8[1] = 0x01;
   gen_au8[2] = 0;
   gen_au8[3] = selection_u8;
   gen_au8[4] = 0xf7;
   m_map_received_data = map_received_data;

   m_map_rx_slot = selection_u8;
   resetRx();
   sendMIDIPacket(gen_au8, sizeof(gen_au8));
}


void Proph2000::sendRecoverMemory(uint8_t sample_u8)
{
   uint8_t rec_au8[6];
   m_log->log("sendRecoverMemory(%d)", sample_u8);
   rec_au8[0] = 0xf0;
   rec_au8[1] = 0x01;
   rec_au8[2] = 0x11;
   rec_au8[3] = 0x7f;
   rec_au8[4] = sample_u8;
   rec_au8[5] = 0xf7;
   resetRx();
   sendMIDIPacket(rec_au8, sizeof(rec_au8));
}


void Proph2000::sendDeleteMemory(uint8_t sample_u8)
{
   uint8_t del_au8[6];
   m_log->log("sendDeleteMemory(%d)", sample_u8);
   del_au8[0] = 0xf0;
   del_au8[1] = 0x01;
   del_au8[2] = 0x11;
   del_au8[3] = 0x7e;
   del_au8[4] = sample_u8;
   del_au8[5] = 0xf7;
   resetRx();
   sendMIDIPacket(del_au8, sizeof(del_au8));
}

void Proph2000::sendSoundParamDump(uint8_t sound_u8)
{
   uint8_t buf_au8[157];
   uint8_t i;

#ifdef LOG_SEND_SOUND_PARAM_DUMP
   m_log->log("sendSoundParamDump(%d)", sound_u8 + 1);
#endif

   buf_au8[0] = 0xf0;
   buf_au8[1] = 0x01;
   buf_au8[2] = 0x11;
   buf_au8[3] = sound_u8 + 0x30;

   // 0mmm m000 0000 1111

   for(i = 0; i < (SOUND_PARAM_BYTES * 2); i++)
   {
      buf_au8[i + 4] = m_soundparam_au8[sound_u8][i];
   }

   buf_au8[156] = 0xf7;

#ifdef LOG_SEND_SOUND_PARAM_DUMP
   if(sound_u8 >= 0x30)
   {
      sound_u8 -= 0x30;
   }

   uint32_t begin_adr;
   begin_adr = m_sound_param_as[sound_u8].val_s.begin_addr[2];
   begin_adr |= ((uint32_t)m_sound_param_as[sound_u8].val_s.begin_addr[1] << 8);
   begin_adr |= ((uint32_t)m_sound_param_as[sound_u8].val_s.begin_addr[0] << 16);
   m_log->log("   start adr: 0x%.6x", begin_adr);
   m_log->log("   start point: %d", getStartPoint(sound_u8));
   m_log->log("   end point: %d", getEndPoint(sound_u8));
   m_log->log("   sustain loop start: %d", getSustainLoopStart(sound_u8));
   m_log->log("   sustain loop end: %d", getSustainLoopEnd(sound_u8));
   m_log->log("   release loop start: %d", getReleaseLoopStart(sound_u8));
   m_log->log("   release loop end: %d", getReleaseLoopEnd(sound_u8));
   m_log->log("   samstat: 0x%.2x", m_sound_param_as[sound_u8].val_s.sample_status);
   m_log->log("   samplerate: %d", m_sound_param_as[sound_u8].val_s.sample_rate);
   if(sustainLoopEnabled(sound_u8))
   {
      m_log->log("   sustain loop activated");
   }
   if(releaseLoopEnabled(sound_u8))
   {
      m_log->log("   release loop activated");
   }
#endif

   resetRx();
   sendMIDIPacket(buf_au8, sizeof(buf_au8));
}


void Proph2000::sendPresetParamDump(uint8_t preset_u8)
{
   uint8_t buf_au8[102];
   uint8_t i;

   m_log->log("sendPresetParamDump(%d)", preset_u8);
  
   buf_au8[0] = 0xf0;
   buf_au8[1] = 0x01;
   buf_au8[2] = 0x11;
   buf_au8[3] = preset_u8 + 0x40;

   for(i = 0; i < (PRESET_PARAM_BYTES * 2); i++)
   {
      buf_au8[i + 4] = m_presetparam_au8[preset_u8][i];
   }
   buf_au8[98] = 0xf7;

   resetRx();
   sendMIDIPacket(buf_au8, 99);
}


void Proph2000::sendMapParamDump(uint8_t map_u8)
{
   uint8_t buf_au8[49];
   uint8_t i;

   m_log->log("sendMapParamDump(%d)", map_u8);
   
   buf_au8[0] = 0xf0;
   buf_au8[1] = 0x01;
   buf_au8[2] = 0x11;
   buf_au8[3] = map_u8 + 0x60;


   for(i = 0; i < (MAP_PARAM_BYTES * 2); i++)
   {
      buf_au8[i + 4] = m_mapparam_au8[map_u8][i];
   }
   buf_au8[48] = 0xf7;

   resetRx();
   sendMIDIPacket(buf_au8, sizeof(buf_au8));
}


void Proph2000::sendDataPacketBlock(uint16_t *sample_data)
{
   uint8_t buf_au8[127];
   unsigned char crc;
   unsigned char i;
   buf_au8[0] = 0xf0;
   buf_au8[1] = 0x7e;
   buf_au8[2] = m_midi->getChannel() - 1;
   buf_au8[3] = 0x02;
   buf_au8[4] = m_packet_counter;

   for(i = 0; i < (120 / 2); i++)
   {
      buf_au8[(i * 2) + 5] = ((sample_data[i] & 0xfe0) >> 5); // 0b0000111111100000
      buf_au8[(i * 2) + 5 + 1] = ((sample_data[i] & 0x1f) << 2); // 0b00011111
   }

   // calc crc
   crc = 0x7e;
   for(i = 2; i < 125; i++)
   {
      crc ^= buf_au8[i];
   }

   buf_au8[125] = crc;
   buf_au8[126] = 0xf7;

   resetRx();
   sendMIDIPacket(buf_au8, sizeof(buf_au8));

   m_packet_counter++;
   if(m_packet_counter >= 0x80)
   {
      m_packet_counter = 0;
   }
   m_transfered_total += 60;

   m_ack_timeout.Start();
}


void Proph2000::sendDumpHeader(uint8_t ch, uint8_t sample)
{
   uint8_t buf_au8[21];
   uint32_t begin_adr;
   uint32_t sustain_loop_start;
   uint32_t sustain_loop_end;
   uint32_t t;

   buf_au8[0] = 0xf0;
   buf_au8[1] = 0x7e;
   buf_au8[2] = ch;
   buf_au8[3] = 0x01;
   buf_au8[4] = sample;
   buf_au8[5] = 0x00;
   buf_au8[6] = 0x0c;

#ifdef LOG_SEND_DUMP_HEADER
   m_log->log("sendDumpHeader(ch:%d, sample:%d):", ch, sample + 1);
#endif

   switch(m_sound_param_as[sample].val_s.sample_rate)
   {
      case 0xff:
            buf_au8[7] = 0x00;
            buf_au8[8] = 0x74;
            buf_au8[9] = 0x03;
            //m_log->log("    sample rate: 15.625kHz");
         break;
      case 0x00:
            buf_au8[7] = 0x00;
            buf_au8[8] = 0x7a;
            buf_au8[9] = 0x01;
            //m_log->log("    sample rate: 31.250kHz");
         break;
      case 0x01:
            buf_au8[7] = 0x40;
            buf_au8[8] = 0x3b;
            buf_au8[9] = 0x01;
            //m_log->log("    sample rate: 41.667kHz");
         break;
      default:
            m_log->log("          No correct sample rate!!");
         break;
   }

   m_log->log("   sample rate (raw): %.2x %.2x %.2x", buf_au8[7], buf_au8[8], buf_au8[9]);

   begin_adr = m_sound_param_as[sample].val_s.begin_addr[2];
   begin_adr |= ((uint32_t)m_sound_param_as[sample].val_s.begin_addr[1] << 8);
   begin_adr |= ((uint32_t)m_sound_param_as[sample].val_s.begin_addr[0] << 16);

   buf_au8[10] = (getSampleWords(sample) & 0x7f);
   buf_au8[11] = ((getSampleWords(sample) >> 7) & 0x7f);
   buf_au8[12] = ((getSampleWords(sample) >> 14) & 0x7f);
#ifdef LOG_SEND_DUMP_HEADER_CONTENT
   m_log->log("          sample words:%d", getSampleWords(sample));
#endif

   t = m_sound_param_as[sample].val_s.sustain_loop_start[2];
   t |= ((uint32_t)m_sound_param_as[sample].val_s.sustain_loop_start[1] << 8);
   t |= ((uint32_t)m_sound_param_as[sample].val_s.sustain_loop_start[0] << 16);

   sustain_loop_start = t - begin_adr;
#ifdef LOG_SEND_DUMP_HEADER_CONTENT
   m_log->log("          sustain_loop_start:%d", sustain_loop_start);
#endif
   buf_au8[13] = (sustain_loop_start & 0x7f);
   buf_au8[14] = ((sustain_loop_start >> 7) & 0x7f);
   buf_au8[15] = ((sustain_loop_start >> 14) & 0x7f);

   t = m_sound_param_as[sample].val_s.sustain_loop_end[2];
   t |= ((uint32_t)m_sound_param_as[sample].val_s.sustain_loop_end[1] << 8);
   t |= ((uint32_t)m_sound_param_as[sample].val_s.sustain_loop_end[0] << 16);

   sustain_loop_end = t - begin_adr;
#ifdef LOG_SEND_DUMP_HEADER_CONTENT
   m_log->log("          sustain_loop_end:%d", sustain_loop_end);
#endif
   buf_au8[16] = (sustain_loop_end & 0x7f);
   buf_au8[17] = ((sustain_loop_end >> 7) & 0x7f);
   buf_au8[18] = ((sustain_loop_end >> 14) & 0x7f);

   buf_au8[19] = 0x00;
   buf_au8[20] = 0xf7;

   resetRx();
   sendMIDIPacket(buf_au8, sizeof(buf_au8));
}


void Proph2000::resetRx(void)
{
   m_rx_mode_e = RX_NOT_FINISHED;
   m_rx_packet_e = INVALID_PACKET;
}


void Proph2000::handleReceivedDumpHeader(void)
{
   uint32_t t;
#ifdef LOG_RX_DUMP_HEADER
   m_log->log("handleReceivedDumpHeader()");
   m_log->log("    sample: %d", m_map_rx_slot + 1);
#endif
   if(m_map_received_data)
   {
      m_sample_length_words_au32[m_map_rx_slot] = 0;
      m_sample_length_words_au32[m_map_rx_slot] = m_midi_rx_buf[10];
      m_sample_length_words_au32[m_map_rx_slot] |= (m_midi_rx_buf[11] << 7);
      m_sample_length_words_au32[m_map_rx_slot] |= (m_midi_rx_buf[12] << 14);

      m_log->log("    sample words: %d", m_sample_length_words_au32[m_map_rx_slot]);

      //m_packet_counter = 0;
      m_sampledata_rx_idx = 0;
   }
#ifdef LOG_RX_DUMP_HEADER
   t = 0;
   t = m_midi_rx_buf[13];
   t |= (m_midi_rx_buf[14] << 7);
   t |= (m_midi_rx_buf[15] << 14);

   m_log->log("    sustain loop start: %d", t);

   t = 0;
   t = m_midi_rx_buf[16];
   t |= (m_midi_rx_buf[17] << 7);
   t |= (m_midi_rx_buf[18] << 14);

   m_log->log("    sustain loop end: %d", t);

   if((m_midi_rx_buf[7] == 0x00) && (m_midi_rx_buf[8] == 0x74) && (m_midi_rx_buf[9] == 0x03))
   {
      m_log->log("    sample rate: 15.625kHz");
   }
   else
   if((m_midi_rx_buf[7] == 0x00) && (m_midi_rx_buf[8] == 0x7a) && (m_midi_rx_buf[9] == 0x01))
   {
      m_log->log("    sample rate: 31.250kHz");
   }
   else
   if((m_midi_rx_buf[7] == 0x40) && (m_midi_rx_buf[8] == 0x3b) && (m_midi_rx_buf[9] == 0x01))
   {
      m_log->log("    sample rate: 41.667kHz");
   }
   else
   {
      m_log->log("    sample rate: INVALID");
   }
   m_log->log("    sample rate (raw): %.2x %.2x %.2x", m_midi_rx_buf[7], m_midi_rx_buf[8], m_midi_rx_buf[9]);
#endif
}

void Proph2000::handleReceivedDataPacket(void)
{
   uint8_t i;
   uint8_t c;

   m_packet_counter = m_midi_rx_buf[4];




   if(m_last_data_packet_size == 126)
   {
      c = 120;
   }
   else
   {
      c = m_last_data_packet_size - 6;
   }

   for(i = 0; i < (c / 2); i++)
   {
      m_sampledata_au16[m_map_rx_slot][m_sampledata_rx_idx] = ((uint16_t)m_midi_rx_buf[(i * 2) + 5] << 5);
      m_sampledata_au16[m_map_rx_slot][m_sampledata_rx_idx] |= ((m_midi_rx_buf[(i * 2) + 1 + 5]) >> 2);
      m_sampledata_rx_idx++;
      m_transfered_total++;
   }
}

void Proph2000::handleReceivedSoundParameter(void)
{
#ifdef LOG_RX_SOUNDPARAM
   m_log->log("handleReceivedSoundParameter()");
#endif
   if(m_map_received_data)
   {
      uint8_t i;

      m_map_rx_slot = m_midi_rx_buf[3];
      
      m_log->log("   sound: %d", m_map_rx_slot + 1);

      for(i = 0; i < (SOUND_PARAM_BYTES * 2); i++)
      {
         m_soundparam_au8[m_map_rx_slot][i] = m_midi_rx_buf[i + 4];
      }

      updateStructsFromParamBytes();
#ifdef LOG_RX_SOUNDPARAM
      m_log->log("   sample rate (raw): %d", m_sound_param_as[m_map_rx_slot].val_s.sample_rate);
      m_log->log("   start point: %d", getStartPoint(m_map_rx_slot));
      m_log->log("   end point: %d", getEndPoint(m_map_rx_slot));
      m_log->log("   sustain loop start: %d", getSustainLoopStart(m_map_rx_slot));
      m_log->log("   sustain loop end: %d", getSustainLoopEnd(m_map_rx_slot));
      m_log->log("   release loop start: %d", getReleaseLoopStart(m_map_rx_slot));
      m_log->log("   release loop end: %d", getReleaseLoopEnd(m_map_rx_slot));
      m_log->log("   samstat: 0x%.2x", m_sound_param_as[m_map_rx_slot].val_s.sample_status);
      if(sustainLoopEnabled(m_map_rx_slot))
      {
         m_log->log("   sustain loop activated");
      }
      if(releaseLoopEnabled(m_map_rx_slot))
      {
         m_log->log("   release loop activated");
      }
#endif
   }
}


void Proph2000::updateStructsFromParamBytes(void)
{
   uint8_t i;
   uint8_t i2;


   for(i2 = 0; i2 < 16; i2++)
   {
      for(i = 0; i < SOUND_PARAM_BYTES; i++)
      {
         m_sound_param_as[i2].bytes_au8[i] = m_soundparam_au8[i2][(i * 2)];
         m_sound_param_as[i2].bytes_au8[i] |= m_soundparam_au8[i2][(i * 2) + 1] << 1; 
      }
      for(i = 0; i < MAP_PARAM_BYTES; i++)
      {
         m_map_param_as[i2].bytes_au8[i] = m_mapparam_au8[i2][(i * 2)];
         m_map_param_as[i2].bytes_au8[i] |= m_mapparam_au8[i2][(i * 2) + 1] << 1;
      }
   }

   for(i2 = 0; i2 < 12; i2++)
   {
      for(i = 0; i < PRESET_PARAM_BYTES; i++)
      {
         m_preset_param_as[i2].bytes_au8[i] = m_presetparam_au8[i2][(i * 2)];
         m_preset_param_as[i2].bytes_au8[i] |= m_presetparam_au8[i2][(i * 2) + 1] << 1;
      }
   }
}

void Proph2000::updateParamBytesFromStruct(void)
{
   uint8_t i;
   uint8_t i2;


   for(i2 = 0; i2 < 16; i2++)
   {
      for(i = 0; i < SOUND_PARAM_BYTES; i++)
      {
         m_soundparam_au8[i2][(i * 2)] = m_sound_param_as[i2].bytes_au8[i] & 0x0f;
         m_soundparam_au8[i2][(i * 2) + 1] = (m_sound_param_as[i2].bytes_au8[i] >> 1) & 0x78;
      }
      for(i = 0; i < MAP_PARAM_BYTES; i++)
      {
         m_mapparam_au8[i2][(i * 2)] = m_map_param_as[i2].bytes_au8[i] & 0x0f;
         m_mapparam_au8[i2][(i * 2) + 1] = (m_map_param_as[i2].bytes_au8[i] >> 1) & 0x78;
      }
   }
   for(i2 = 0; i2 < 12; i2++)
   {
      for(i = 0; i < PRESET_PARAM_BYTES; i++)
      {
         m_presetparam_au8[i2][(i * 2)] = m_preset_param_as[i2].bytes_au8[i] & 0x0f;
         m_presetparam_au8[i2][(i * 2) + 1] = (m_preset_param_as[i2].bytes_au8[i] >> 1) & 0x78;
      }
   }
}

void Proph2000::handleReceivedPresetParameter(void)
{
   if(m_map_received_data)
   {
      uint8_t i;
      m_map_rx_slot = m_midi_rx_buf[3];

      if(m_map_rx_slot >= 0x40)
      {
         m_map_rx_slot -= 0x40;
      }
      
      m_log->log("    preset: %d", m_map_rx_slot + 1);

      for(i = 0; i < (PRESET_PARAM_BYTES * 2); i++)
      {
         m_presetparam_au8[m_map_rx_slot][i] = m_midi_rx_buf[i + 4];
      }
      updateStructsFromParamBytes();
   }
}

void Proph2000::handleReceivedMapParameter(void)
{
   if(m_map_received_data)
   {
      uint8_t i;
      m_map_rx_slot = m_midi_rx_buf[3];

      if(m_map_rx_slot >= 0x60)
      {
         m_map_rx_slot -= 0x60;
      }
      
      m_log->log("    map: %d", m_map_rx_slot + 1);

      for(i = 0; i < (MAP_PARAM_BYTES * 2); i++)
      {
         m_mapparam_au8[m_map_rx_slot][i] = m_midi_rx_buf[i + 4];
      }

      updateStructsFromParamBytes();
   }
}


void Proph2000::receiveHandler(void)
{
   m_rx_mode_e = RX_NOT_FINISHED;
   while((m_midi->dataAvailable()) && (m_rx_mode_e == RX_NOT_FINISHED))
   {
      uint8_t c;
      c = m_midi->getDataByte();

      if(c == 0xf0)
      {
         m_midi_rx_buf[0] = 0xf0;
         m_midi_rx_idx = 0;
      }
      else
      {
         m_midi_rx_buf[m_midi_rx_idx] = c;
      }

      if(m_midi_rx_buf[m_midi_rx_idx] == 0xf7)
      {
         m_rx_mode_e = RX_FINISHED;
         if((m_midi_rx_buf[0] == 0xf0) && (m_midi_rx_buf[1] == 0x7e) && (m_midi_rx_buf[3] == 0x02))
         {
            m_rx_mode_e = RX_FINISHED;
            m_rx_packet_e = DATA_PACKET;
            m_midi->log("DATA_PACKET received");
            m_last_data_packet_size = m_midi_rx_idx;
            //handleReceivedDataPacket();
            if(m_use_rx_handshake)
            {
               sendWait(m_midi_rx_buf[2], m_midi_rx_buf[4]);
            }
         }
         else
         if((m_midi_rx_buf[0] == 0xf0) && (m_midi_rx_buf[1] == 0x01) && (m_midi_rx_buf[2] == 0x00) && (m_midi_rx_idx == 4))
         {
            m_rx_packet_e = GENERIC_DUMP_REQ_PACKET;
            m_log->log("GENERIC_DUMP_REQ received");
            m_midi->log("GENERIC_DUMP_REQ received");
         }
         else
         if((m_midi_rx_buf[0] == 0xf0) && (m_midi_rx_buf[1] == 0x7e) && (m_midi_rx_buf[3] == 0x7f) && (m_midi_rx_idx == 5))
         {
            m_rx_packet_e = ACK_PACKET;
            m_midi->log("ACK received");
         }
         else
         if((m_midi_rx_buf[0] == 0xf0) && (m_midi_rx_buf[1] == 0x7e) && (m_midi_rx_buf[3] == 0x7e) && (m_midi_rx_idx == 5))
         {
            m_rx_packet_e = NACK_PACKET;
            m_log->log("NACK received");
            m_midi->log("NACK received");
         }
         else
         if((m_midi_rx_buf[0] == 0xf0) && (m_midi_rx_buf[1] == 0x7e) && (m_midi_rx_buf[3] == 0x7d) && (m_midi_rx_idx == 5))
         {
            m_rx_packet_e = CANCEL_PACKET;
#ifdef LOG_CANCEL_RECEIVED
            m_log->log("CANCEL received");
#endif
            m_midi->log("CANCEL received");
         }
         else
         if((m_midi_rx_buf[0] == 0xf0) && (m_midi_rx_buf[1] == 0x7e) && (m_midi_rx_buf[3] == 0x7c) && (m_midi_rx_idx == 5))
         {
            m_rx_packet_e = WAIT_PACKET;
            m_log->log("WAIT received");
            m_midi->log("WAIT received");
         }
         else
         if((m_midi_rx_buf[0] == 0xf0) && (m_midi_rx_buf[1] == 0x7e) && (m_midi_rx_buf[3] == 0x03) && (m_midi_rx_idx == 6))
         {
            m_rx_packet_e = DUMP_REQ_PACKET;
            m_log->log("DUMP_REQ received");
            m_midi->log("DUMP_REQ received");
         }
         else
         if((m_midi_rx_buf[0] == 0x01) && (m_midi_rx_buf[2] == 0x00) && (m_midi_rx_buf[3] == 0x0c) && (m_midi_rx_idx == 17))
         {
            uint8_t i;
            uint8_t ctmp[100];
            // workaround for 0xf0 0x7e 0x01 .. -> 0xf0 0x7e 0x01 0x01 ..
            m_log->log("!!! DUMP_HEADER corrupted -> fix !!!");
            m_midi->logerror("!!! DUMP_HEADER corrupted -> fix !!!");

            ctmp[0] = 0xf0;
            ctmp[1] = 0x7e;
            ctmp[2] = m_midi->getChannel() - 1; 

            for(i = 0; i < 18; i++)
            {
               ctmp[i + 3] = m_midi_rx_buf[i];
            }

            for(i = 0; i < 20; i++)
            {
               m_midi_rx_buf[i] = ctmp[i];
            }

            m_midi_rx_idx = 20;
         
            m_rx_packet_e = DUMP_HEADER_PACKET;
            m_log->log("DUMP_HEADER received");
            m_midi->log("DUMP_HEADER received");
            handleReceivedDumpHeader();
         }
         else
         if((m_midi_rx_buf[0] == 0xf0) && (m_midi_rx_buf[1] == 0x7e) && (m_midi_rx_buf[2] == 0x01) && (m_midi_rx_idx == 19))
         {
            uint8_t i;
            uint8_t ctmp[100];
            // workaround for 0xf0 0x7e 0x01 .. -> 0xf0 0x7e 0x01 0x01 ..
            m_log->log("!!! DUMP_HEADER corrupted -> fix !!!");
            m_midi->logerror("!!! DUMP_HEADER corrupted -> fix !!!");

            ctmp[0] = 0xf0;
            ctmp[1] = 0x7e;
            ctmp[2] = m_midi->getChannel() - 1; 
            ctmp[3] = 0x01;

            for(i = 3; i < 20; i++)
            {
               ctmp[i + 1] = m_midi_rx_buf[i];
            }

            for(i = 0; i < 20; i++)
            {
               m_midi_rx_buf[i] = ctmp[i];
            }

            m_midi_rx_idx = 20;
         
            m_rx_packet_e = DUMP_HEADER_PACKET;
            m_log->log("DUMP_HEADER received");
            m_midi->log("DUMP_HEADER received");
            handleReceivedDumpHeader();
         }
         else
         if((m_midi_rx_buf[0] == 0xf0) && (m_midi_rx_buf[1] == 0x7e) && (m_midi_rx_buf[3] == 0x01) && (m_midi_rx_idx == 20))
         {
            m_rx_packet_e = DUMP_HEADER_PACKET;
            m_log->log("DUMP_HEADER received");
            m_midi->log("DUMP_HEADER received");
            handleReceivedDumpHeader();
         }
         else
         if((m_midi_rx_buf[0] == 0xf0) && (m_midi_rx_buf[1] == 0x01) && (m_midi_rx_buf[2] == 0x11) && (m_midi_rx_idx == 48))
         {
            m_rx_packet_e = MAP_PARAM_PACKET;
            m_log->log("MAP_PARAM received");
            m_midi->log("MAP_PARAM received");
            handleReceivedMapParameter();
         }
         else
         if((m_midi_rx_buf[0] == 0xf0) && (m_midi_rx_buf[1] == 0x01) && (m_midi_rx_buf[2] == 0x11) && (m_midi_rx_idx == 98))
         {
            m_rx_packet_e = PRESET_PARAM_PACKET;            
            m_log->log("PRESET_PARAM received");
            m_midi->log("PRESET_PARAM received");
            handleReceivedPresetParameter();
         }
         else
         if((m_midi_rx_buf[0] == 0xf0) && (m_midi_rx_buf[1] == 0x01) && (m_midi_rx_buf[2] == 0x11) && (m_midi_rx_idx == 156))
         {
            m_rx_packet_e = SOUND_PARAM_PACKET;
            m_log->log("SOUND_PARAM received");
            m_midi->log("SOUND_PARAM received");
            handleReceivedSoundParameter();
         }
         else
         if((m_midi_rx_buf[0] != 0xf0) && (m_midi_rx_buf[m_midi_rx_idx] == 0xf7))
         {
            // broken sysex frame without start data -> skip
            m_rx_mode_e = RX_NOT_FINISHED;
            m_midi_rx_idx = 0;
            m_log->log("broken sysex frame -> skip");
            m_midi->logerror("broken sysex frame -> skip");
         }
         else
         if((m_midi_rx_buf[0] == 0xf0) && (m_midi_rx_buf[1] == 0x02) && (m_midi_rx_idx == 124))
         {
            uint8_t i;
            uint8_t ctmp[1000];

            m_midi->logerror("fixed data packet");

            m_log->log(" !!! fixed data packet !!!", m_midi_rx_idx);

            for(i = 1; i < 126; i++)
            {
               ctmp[i + 2] = m_midi_rx_buf[i];
            }
            ctmp[0] = 0xf0;
            ctmp[1] = 0x7e;
            ctmp[2] = 0x00;

            for(i = 0; i < 126; i++)
            {
               m_midi_rx_buf[i] = ctmp[i];
            }

            m_midi_rx_idx = 126;

            m_rx_mode_e = RX_FINISHED;
            m_rx_packet_e = DATA_PACKET;
            m_midi->log("DATA_PACKET received");
            m_last_data_packet_size = m_midi_rx_idx;
            //handleReceivedDataPacket();
            if(m_use_rx_handshake)
            {
               sendWait(m_midi_rx_buf[2], m_midi_rx_buf[4]);
            }
         }
         else
         {
            m_rx_mode_e = RX_FINISHED;
            m_rx_packet_e = INVALID_PACKET;
            m_log->log("****INVALID PACKET received");
            m_midi->logerror("INVALID PACKET");
            m_invalid_packet_cnt++;
            logInvalidPacket();
         }

         m_midi_rx_idx = 0;
      }
      else
      {
         m_midi_rx_idx++;
         if(m_midi_rx_idx >= MIDI_RX_BUF_SIZE)
         {
            m_midi_rx_idx = 0; // zuviele Daten im Buffer -> vermutlich hat Bertil zuviel in die Tasten gehauen :-) -> skip
         }
      }
   }
}

void Proph2000::logInvalidPacket(void)
{
   int i;
   m_midi->logerror("INVALID PACKET length");
   m_log->log(" INVALID PACKET length %d", m_midi_rx_idx);
   for(i = 0; i < m_midi_rx_idx; i++)
   {
      m_log->log("   0x%.2x", m_midi_rx_buf[i]);
   }
}

bool Proph2000::transferFinished(void)
{
   bool retval = false;
   if(m_main_mode_e == PROPH_IDLE)
   {
      retval = true;
   }
   return retval;
}

bool Proph2000::transfer2PC(void)
{
   bool retval = false;


   if(m_midi->isMIDIopen())
   {
      m_midi->close();
   }
   if(m_midi->init())
   {
      m_log->log("start transfer2PC");

      sendPanic();

      clear();

      m_main->updateGUI();

      m_transfer_time.Start();

      m_retry_timeout.Start();
      m_sub_mode_u16 = 0;
      m_current_rx_slot = 0;
      m_transfered_total = 0;
      m_total_words_to_transfer = 0;
      m_handle_id = 0;
      m_retry_cnt = 0;
      m_midi_rx_idx = 0;
      m_ms_for_1_word = 0;
      m_last_data_packet_size = 0;
      m_invalid_packet_cnt = 0;
      m_trx_error_e = TRX_NOERROR;
      m_rx_packet_e = INVALID_PACKET;
      m_main_mode_e = PROPH_DUMP2PC;
      m_last_main_mode_e = m_main_mode_e;
      //m_progress_dlg->Show();
      retval = true;
   }

   return retval;
}


bool Proph2000::transferParameter2PC(void)
{
   bool retval = false;


   if(m_midi->isMIDIopen())
   {
      m_midi->close();
   }
   if(m_midi->init())
   {
      m_log->log("start transfer Parameter2PC");

      m_main->updateGUI();

      m_retry_timeout.Start();
      m_sub_mode_u16 = 0;
      m_current_rx_slot = 0;
      m_transfered_total = 0;
      m_total_words_to_transfer = 0;
      m_handle_id = 0;
      m_retry_cnt = 0;
      m_midi_rx_idx = 0;
      m_ms_for_1_word = 0;
      m_last_data_packet_size = 0;
      m_invalid_packet_cnt = 0;
      m_trx_error_e = TRX_NOERROR;
      m_rx_packet_e = INVALID_PACKET;
      m_main_mode_e = PROPH_GETPARAMETER;
      m_last_main_mode_e = m_main_mode_e;
      //m_progress_dlg->Show();
      retval = true;
   }

   return retval;
}

bool Proph2000::transferParameter2Prophet(void)
{
   bool retval = false;


   if(m_midi->isMIDIopen())
   {
      m_midi->close();
   }
   if(m_midi->init())
   {
      m_log->log("start transferParameter2Prophet");

      m_retry_timeout.Start();
      m_sub_mode_u16 = 0;
      m_current_rx_slot = 0;
      m_transfered_total = 0;
      m_total_words_to_transfer = 0;
      m_handle_id = 0;
      m_retry_cnt = 0;
      m_midi_rx_idx = 0;
      m_ms_for_1_word = 0;
      m_last_data_packet_size = 0;
      m_invalid_packet_cnt = 0;
      m_trx_error_e = TRX_NOERROR;
      m_rx_packet_e = INVALID_PACKET;
      m_main_mode_e = PROPH_UPDATEALLPARAMETER;
      m_last_main_mode_e = m_main_mode_e;
      //m_progress_dlg->Show();
      retval = true;
   }

   return retval;
}

bool Proph2000::transferAllSoundParameter2Prophet(void)
{
   bool retval = false;


   if(m_main_mode_e == PROPH_IDLE)
   {
      if(m_midi->isMIDIopen())
      {
         m_midi->close();
      }
      if(m_midi->init())
      {
         m_log->log("start transferParameter2Prophet");

         m_retry_timeout.Start();
         m_sub_mode_u16 = 0;
         m_current_rx_slot = 0;
         m_transfered_total = 0;
         m_total_words_to_transfer = 0;
         m_handle_id = 0;
         m_retry_cnt = 0;
         m_midi_rx_idx = 0;
         m_ms_for_1_word = 0;
         m_last_data_packet_size = 0;
         m_invalid_packet_cnt = 0;
         m_trx_error_e = TRX_NOERROR;
         m_rx_packet_e = INVALID_PACKET;
         m_main_mode_e = PROPH_UPDATEALLSOUNDPARAMETER;
         m_last_main_mode_e = m_main_mode_e;
         //m_progress_dlg->Show();
         retval = true;
      }
   }
   else
   {
      m_req_during_transfer_cnt++;
   }

   return retval;
}


bool Proph2000::transfer2Prophet(void)
{
   bool retval = false;


   if(m_midi->isMIDIopen())
   {
      m_midi->close();
   }
   if(m_midi->init())
   {
      m_log->log("start transfer2Prophet");

      sendPanic();
   
      m_transfer_time.Start();

      m_sub_mode_u16 = 0;
      m_current_rx_slot = 0;
      m_transfered_total = 0;
      m_retry_cnt = 0;
      m_ms_for_1_word = 0;
      m_handle_id = 0;
      for(uint8_t i = 0; i < 16; i++)
      {
         m_total_words_to_transfer += getSampleWords(i);
      }
      m_midi_rx_idx = 0;
      m_last_data_packet_size = 0;
      m_invalid_packet_cnt = 0;
      m_trx_error_e = TRX_NOERROR;
      m_rx_packet_e = INVALID_PACKET;
      m_main_mode_e = PROPH_DUMP2PROPH;
      m_last_main_mode_e = m_main_mode_e;
      //m_progress_dlg->Show();
      retval = true;
   }
   return retval;
}

bool Proph2000::transferPreset2Proph(uint8_t preset_u8)
{
   bool retval = false;


   if(!m_midi->isMIDIopen())
   {
      m_midi->init();
   }
   if(m_midi->isMIDIopen())
   {
      if(m_main_mode_e == PROPH_IDLE)
      {
         m_retry_timeout.Start();
         m_sub_mode_u16 = 0;
         m_retry_cnt = 0;
         m_handle_id = preset_u8;
         m_midi_rx_idx = 0;
         m_invalid_packet_cnt = 0;
         m_trx_error_e = TRX_NOERROR;
         m_rx_packet_e = INVALID_PACKET;
         m_main_mode_e = PROPH_TX_PRESET;
         m_last_main_mode_e = m_main_mode_e;
      }
      else
      {
         m_req_during_transfer_cnt++;
      }
      retval = true;
   }
   return retval;
}

bool Proph2000::transferSoundParam2Proph(uint8_t sound_u8)
{
   bool retval = false;


   if(!m_midi->isMIDIopen())
   {
      m_midi->init();
   }
   if(m_midi->isMIDIopen())
   {
      if(m_main_mode_e == PROPH_IDLE)
      {
         m_midi->flush();
      
         m_retry_timeout.Start();
         m_sub_mode_u16 = 0;
         m_retry_cnt = 0;
         m_handle_id = sound_u8;
         m_midi_rx_idx = 0;
         m_invalid_packet_cnt = 0;
         m_trx_error_e = TRX_NOERROR;
         m_rx_packet_e = INVALID_PACKET;
         m_main_mode_e = PROPH_TX_SOUNDPARAM;
         m_last_main_mode_e = m_main_mode_e;

         if(getStereoMode())
         {
            m_send_stereo_trigger = true;
         }
      }
      else
      {
         m_req_during_transfer_cnt++;
      }
      retval = true;
   }
   return retval;
}

bool Proph2000::transferSoundParam2PC(uint8_t sound_u8)
{
   bool retval = false;


   if(m_midi->isMIDIopen())
   {
      m_midi->close();
   }
   if(m_midi->init())
   {
   
      m_retry_timeout.Start();
      m_sub_mode_u16 = 0;
      m_retry_cnt = 0;
      m_handle_id = sound_u8;
      m_midi_rx_idx = 0;
      m_invalid_packet_cnt = 0;
      m_trx_error_e = TRX_NOERROR;
      m_rx_packet_e = INVALID_PACKET;
      m_main_mode_e = PROPH_RX_SINGLE_SOUND_PARAM;
      m_last_main_mode_e = m_main_mode_e;
      retval = true;
   }
   return retval;
}

bool Proph2000::transferMap2Proph(uint8_t map_u8)
{
   bool retval = false;


   if(!m_midi->isMIDIopen())
   {
      m_midi->init();
      m_log->log("MIDI device opened");
   }
   if(m_midi->isMIDIopen())
   {
      if(m_main_mode_e == PROPH_IDLE)
      {   
         m_retry_timeout.Start();
         m_sub_mode_u16 = 0;
         m_retry_cnt = 0;
         m_handle_id = map_u8;
         m_midi_rx_idx = 0;
         m_invalid_packet_cnt = 0;
         m_trx_error_e = TRX_NOERROR;
         m_rx_packet_e = INVALID_PACKET;
         m_main_mode_e = PROPH_TX_MAP;
         m_last_main_mode_e = m_main_mode_e;
         if(getStereoMode())
         {
            m_send_stereo_trigger = true;
         }
      }
      else
      {
         m_req_during_transfer_cnt++;
      }
      retval = true;
   }
   return retval;
}

bool Proph2000::transferSound2PC(uint8_t sound_u8)
{
   bool retval = false;


   if(m_midi->isMIDIopen())
   {
      m_midi->close();
   }
   if(m_midi->init())
   {

      sendPanic();

      m_retry_timeout.Start();
      m_sub_mode_u16 = 0;
      m_retry_cnt = 0;
      m_handle_id = sound_u8;
      m_midi_rx_idx = 0;
      m_invalid_packet_cnt = 0;
      m_trx_error_e = TRX_NOERROR;
      m_rx_packet_e = INVALID_PACKET;
      m_main_mode_e = PROPH_RX_SOUND;
      m_last_main_mode_e = m_main_mode_e;
      retval = true;
   }
   return retval;
}


void Proph2000::handler(void)
{
   switch(m_main_mode_e)
   {
      case PROPH_IDLE:
         break;
      case PROPH_DUMP2PC:
         handleTransfer2PC();
         break;
      case PROPH_DUMP2PROPH:
         handleTransfer2Prophet();
         break;
      case PROPH_TX_PRESET:
         handleTransferPreset2Prophet();
         break;
      case PROPH_TX_SOUNDPARAM:
         handleTransferSoundParam2Prophet();
         break;
      case PROPH_TX_MAP:
         handleTransferMap2Prophet();
         break;
      case PROPH_GETPARAMETER:
         handleTransferParameter2PC();
         break;
      case PROPH_RX_SOUND:
         handleTransferSound2PC();
         break;
      case PROPH_RX_SINGLE_SOUND_PARAM:
         handleTransferSingleSoundParameter2PC();
         break;
      case PROPH_UPDATEALLPARAMETER:
         handleParameter2Prophet();
         break;
      case PROPH_UPDATEALLSOUNDPARAMETER:
         handleAllSoundParameter2Prophet();
         break;
      default:
         m_main_mode_e = PROPH_IDLE;
         break;
   }
}

void Proph2000::handleTransferSingleSoundParameter2PC(void)
{
   switch(m_sub_mode_u16)
   {
      case 0:
         m_progress_msg.sprintf("Receiving sound parameter #%d", m_current_rx_slot + 1);
         m_progress_dlg->Update(0 , m_progress_msg);
         m_progress_dlg->Show();
         // get sound param
         m_midi->flush();
         sendGenericDumpRequest(m_handle_id, true);
         m_sub_mode_u16++;
         break;
      case 1:
         receiveHandler();
         if((m_retry_timeout.Time() > TRANSFER2PC_RETRY_TIMEOUT) && (m_retry_cnt < 3))
         {
            m_retry_cnt++;
            m_retry_timeout.Start();
            m_sub_mode_u16 = 0;
            m_log->log("TIMEOUT -> retry");
         }
         if(m_retry_cnt >= 3)
         {
            m_log->log("No response");
            m_trx_error_e = TRX_NO_RESPONSE;
            m_main_mode_e = PROPH_IDLE; 
            m_midi->flush();
            m_main->transferFinished(true);
            m_progress_dlg->Hide();
         }
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == SOUND_PARAM_PACKET)
            {
               m_sub_mode_u16++;
            }
            resetRx();
         }
         break;
      case 2:
         //m_log->log("Invalid packets: %d", m_invalid_packet_cnt);
         m_main_mode_e = PROPH_IDLE;
         m_main->transferFinished(true);
         m_progress_dlg->Hide();
         break;
      default:
         m_main_mode_e = PROPH_IDLE;
         break;
   }
}



void Proph2000::handleTransferParameter2PC(void)
{
   switch(m_sub_mode_u16)
   {
      case 0:
         m_midi->flush();
         // get preset param
         m_progress_msg.sprintf("Receiving preset #%d", m_current_rx_slot + 1);
         m_progress_dlg->Update(((m_current_rx_slot + 1) * 100) / 12 , m_progress_msg);
         m_progress_dlg->Show();
         sendGenericDumpRequest(m_current_rx_slot + 0x40, false); // select preset
         m_sub_mode_u16++;
         break;
      case 1:
         receiveHandler();
         if((m_retry_timeout.Time() > TRANSFER2PC_RETRY_TIMEOUT) && (m_retry_cnt < 3))
         {
            m_retry_cnt++;
            m_retry_timeout.Start();
            m_sub_mode_u16 = 0;
            m_log->log("TIMEOUT -> retry");
         }
         if(m_retry_cnt >= 3)
         {
            m_log->log("No response");
            m_trx_error_e = TRX_NO_RESPONSE;
            m_main_mode_e = PROPH_IDLE; 
            m_midi->flush();
            m_main->transferFinished(true);
            m_progress_dlg->Hide();
         }
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == PRESET_PARAM_PACKET)
            {
               m_retry_timeout.Start();
               m_sub_mode_u16++;
            }
            resetRx();
         }
         break;
      case 2:
         // get preset param
         sendGenericDumpRequest(m_current_rx_slot + 0x40, true);
         m_sub_mode_u16++;
         break;
      case 3:
         receiveHandler();
         if((m_retry_timeout.Time() > TRANSFER2PC_RETRY_TIMEOUT) && (m_retry_cnt < 3))
         {
            m_retry_cnt++;
            m_retry_timeout.Start();
            m_sub_mode_u16 = 2;
            m_log->log("TIMEOUT -> retry");
         }
         if(m_retry_cnt >= 3)
         {
            m_log->log("No response");
            m_trx_error_e = TRX_NO_RESPONSE;
            m_main_mode_e = PROPH_IDLE; 
            m_midi->flush();
            m_main->transferFinished(true);
            m_progress_dlg->Hide();
         }
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == PRESET_PARAM_PACKET)
            {
               m_current_rx_slot++;
               if(m_current_rx_slot >= 12)
               {
                  m_sub_mode_u16++;
               }
               else
               {
                  m_sub_mode_u16 = 0;
                  m_retry_timeout.Start();
               }
            }
            resetRx();
         }
         break;
      case 4:
         m_current_rx_slot = 0;
         m_retry_cnt = 0;
         m_retry_timeout.Start();
         m_sub_mode_u16++;
         break;
      case 5:
         // get map param
         m_progress_msg.sprintf("Receiving map #%d", m_current_rx_slot + 1);
         m_progress_dlg->Update(((m_current_rx_slot + 1) * 100) / 16 , m_progress_msg);
         m_progress_dlg->Show();
         sendGenericDumpRequest(m_current_rx_slot + 0x60, true);
         m_sub_mode_u16++;
         break;
      case 6:
         receiveHandler();
         if((m_retry_timeout.Time() > TRANSFER2PC_RETRY_TIMEOUT) && (m_retry_cnt < 3))
         {
            m_retry_cnt++;
            m_retry_timeout.Start();
            m_sub_mode_u16 = 5;
            m_log->log("TIMEOUT -> retry");
         }
         if(m_retry_cnt >= 3)
         {
            m_log->log("No response");
            m_trx_error_e = TRX_NO_RESPONSE;
            m_main_mode_e = PROPH_IDLE; 
            m_midi->flush();
            m_main->transferFinished(true);
            m_progress_dlg->Hide();
         }
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == MAP_PARAM_PACKET)
            {
               m_current_rx_slot++;
               if(m_current_rx_slot >= 16)
               {
                  m_sub_mode_u16++;
               }
               else
               {
                  m_sub_mode_u16 = 5;
                  m_retry_timeout.Start();
               }
            }
            resetRx();
         }
         break;
      case 7:
         m_current_rx_slot = 0;
         m_sub_mode_u16++;
         m_retry_timeout.Start();
         break;
      case 8:
         // get sound param
         m_progress_msg.sprintf("Receiving sound parameter #%d", m_current_rx_slot + 1);
         m_progress_dlg->Update(((m_current_rx_slot + 1) * 100) / 12 , m_progress_msg);
         m_progress_dlg->Show();
         sendGenericDumpRequest(m_current_rx_slot, true);
         m_sub_mode_u16++;
         break;
      case 9:
         receiveHandler();
         if((m_retry_timeout.Time() > TRANSFER2PC_RETRY_TIMEOUT) && (m_retry_cnt < 3))
         {
            m_retry_cnt++;
            m_retry_timeout.Start();
            m_sub_mode_u16 = 8;
            m_log->log("TIMEOUT -> retry");
         }
         if(m_retry_cnt >= 3)
         {
            m_log->log("No response");
            m_trx_error_e = TRX_NO_RESPONSE;
            m_main_mode_e = PROPH_IDLE; 
            m_midi->flush();
            m_main->transferFinished(true);
            m_progress_dlg->Hide();
         }
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == SOUND_PARAM_PACKET)
            {
               m_current_rx_slot++;
               if(m_current_rx_slot >= 16)
               {
                  for(uint8_t i = 0; i < 16; i++)
                  {
                     m_total_words_to_transfer += getSampleWords(i);
                  }
                  m_estimated_timer.Start();

                  m_sub_mode_u16++;
                  m_retry_timeout.Start();
                  m_retry_cnt = 0;
                  m_current_rx_slot = 0;
               }
               else
               {
                  m_retry_timeout.Start();
                  m_retry_cnt = 0;
                  m_sub_mode_u16 = 8;
               }
            }
            resetRx();
         }
         break;
      case 10:
         m_current_rx_slot = 0;
         m_retry_cnt = 0;
         m_retry_timeout.Start();
         m_sub_mode_u16++;
         break;
      case 11:
         // request preset #1 to make it active
         sendGenericDumpRequest(0x40, false);
         m_sub_mode_u16++;
         break;
      case 12:
         receiveHandler();
         if((m_retry_timeout.Time() > TRANSFER2PC_RETRY_TIMEOUT) && (m_retry_cnt < 3))
         {
            m_retry_cnt++;
            m_retry_timeout.Start();
            m_sub_mode_u16 = 11;
            m_log->log("TIMEOUT -> retry");
         }
         if(m_retry_cnt >= 3)
         {
            m_log->log("No response");
            m_trx_error_e = TRX_NO_RESPONSE;
            m_main_mode_e = PROPH_IDLE; 
            m_midi->flush();
            m_main->transferFinished(true);
            m_progress_dlg->Hide();
         }
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == PRESET_PARAM_PACKET)
            {
               m_sub_mode_u16++;
            }
            resetRx();
         }
         break;
      case 13:
         //m_log->log("Invalid packets: %d", m_invalid_packet_cnt);
         m_main_mode_e = PROPH_IDLE;
         m_main->transferFinished(true);
         m_progress_dlg->Hide();
         break;
      default:
         m_main_mode_e = PROPH_IDLE;
         break;
   }
}


void Proph2000::handleTransfer2PC(void)
{
   switch(m_sub_mode_u16)
   {
      case 0:
         m_midi->flush();
         // get preset param
         m_log->log("-----------------------------------------");
         m_log->log("Select preset %d", m_current_rx_slot + 1);
         sendGenericDumpRequest(m_current_rx_slot + 0x40, false); // select preset
         m_sub_mode_u16++;
         break;
      case 1:
         receiveHandler();
         if((m_retry_timeout.Time() > TRANSFER2PC_RETRY_TIMEOUT) && (m_retry_cnt < 3))
         {
            m_retry_cnt++;
            m_retry_timeout.Start();
            m_sub_mode_u16 = 0;
            m_log->log("TIMEOUT -> retry");
         }
         if(m_retry_cnt >= 3)
         {
            m_log->log("No response");
            m_trx_error_e = TRX_NO_RESPONSE;
            m_main_mode_e = PROPH_IDLE; 
            m_midi->flush();
            m_main->transferFinished(true);
            m_progress_dlg->Hide();
         }
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == INVALID_PACKET)
            {
               m_sub_mode_u16 = 0;
               m_retry_timeout.Start();
               m_log->log("Retry...");
               m_retry_cnt++;
            }
            if(m_rx_packet_e == PRESET_PARAM_PACKET)
            {
               m_retry_timeout.Start();
               m_sub_mode_u16++;
            }
            resetRx();
         }
         break;
      case 2:
         // get preset param
         m_progress_msg.sprintf("Receiving preset #%d", m_current_rx_slot + 1);
         m_progress_dlg->Update(((m_current_rx_slot + 1) * 100) / 12 , m_progress_msg);
         m_progress_dlg->Show();
         StopWatch::Sleep_ms(30);
         m_log->log("Get preset %d parameters", m_current_rx_slot + 1);
         sendGenericDumpRequest(m_current_rx_slot + 0x40, true);
         m_sub_mode_u16++;
         break;
      case 3:
         receiveHandler();
         if((m_retry_timeout.Time() > TRANSFER2PC_RETRY_TIMEOUT) && (m_retry_cnt < 3))
         {
            m_retry_cnt++;
            m_retry_timeout.Start();
            m_sub_mode_u16 = 2;
            m_log->log("TIMEOUT -> retry");
         }
         if(m_retry_cnt >= 3)
         {
            m_log->log("No response");
            m_trx_error_e = TRX_NO_RESPONSE;
            m_main_mode_e = PROPH_IDLE; 
            m_midi->flush();
            m_main->transferFinished(true);
            m_progress_dlg->Hide();
         }
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == PRESET_PARAM_PACKET)
            {
               m_current_rx_slot++;
               if(m_current_rx_slot >= 12)
               {
                  m_sub_mode_u16++;
               }
               else
               {
                  m_sub_mode_u16 = 0;
                  m_retry_timeout.Start();
               }
            }
            resetRx();
         }
         break;
      case 4:
         m_current_rx_slot = 0;
         m_retry_cnt = 0;
         m_retry_timeout.Start();
         m_sub_mode_u16++;
         break;
      case 5:
         // get map param
         m_log->log("-----------------------------------------");
         m_progress_msg.sprintf("Receiving map #%d", m_current_rx_slot + 1);
         m_progress_dlg->Update(((m_current_rx_slot + 1) * 100) / 16 , m_progress_msg);
         StopWatch::Sleep_ms(30);
         m_log->log("Get map %d parameters", m_current_rx_slot + 1);
         sendGenericDumpRequest(m_current_rx_slot + 0x60, true);
         m_sub_mode_u16++;
         break;
      case 6:
         receiveHandler();
         if((m_retry_timeout.Time() > TRANSFER2PC_RETRY_TIMEOUT) && (m_retry_cnt < 3))
         {
            m_retry_cnt++;
            m_retry_timeout.Start();
            m_sub_mode_u16 = 5;
            m_log->log("TIMEOUT -> retry");
         }
         if(m_retry_cnt >= 3)
         {
            m_log->log("No response");
            m_trx_error_e = TRX_NO_RESPONSE;
            m_main_mode_e = PROPH_IDLE; 
            m_midi->flush();
            m_main->transferFinished(true);
            m_progress_dlg->Hide();
         }
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == MAP_PARAM_PACKET)
            {
               m_current_rx_slot++;
               if(m_current_rx_slot >= 16)
               {
                  m_sub_mode_u16++;
               }
               else
               {
                  m_sub_mode_u16 = 5;
                  m_retry_timeout.Start();
               }
            }
            resetRx();
         }
         break;
      case 7:
         m_current_rx_slot = 0;
         m_sub_mode_u16++;
         m_retry_timeout.Start();
         break;
      case 8:
         // get sound param
         m_log->log("-----------------------------------------");
         m_progress_msg.sprintf("Receiving sound parameter #%d", m_current_rx_slot + 1);
         m_progress_dlg->Update(((m_current_rx_slot + 1) * 100) / 16 , m_progress_msg);
         StopWatch::Sleep_ms(30);
         m_log->log("Get sound %d parameters", m_current_rx_slot + 1);
         sendGenericDumpRequest(m_current_rx_slot, true);
         m_sub_mode_u16++;
         break;
      case 9:
         receiveHandler();
         if((m_retry_timeout.Time() > TRANSFER2PC_RETRY_TIMEOUT) && (m_retry_cnt < 3))
         {
            m_retry_cnt++;
            m_retry_timeout.Start();
            m_sub_mode_u16 = 8;
            m_log->log("TIMEOUT -> retry");
         }
         if(m_retry_cnt >= 3)
         {
            m_log->log("No response");
            m_trx_error_e = TRX_NO_RESPONSE;
            m_main_mode_e = PROPH_IDLE; 
            m_midi->flush();
            m_main->transferFinished(true);
            m_progress_dlg->Hide();
         }
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == SOUND_PARAM_PACKET)
            {
               m_current_rx_slot++;
               if(m_current_rx_slot >= 16)
               {
                  for(uint8_t i = 0; i < 16; i++)
                  {
                     m_total_words_to_transfer += getSampleWords(i);
                  }
                  m_estimated_timer.Start();

                  m_sub_mode_u16++;

                  StopWatch::Sleep_ms(100);

                  m_retry_timeout.Start();
                  m_retry_cnt = 0;
                  m_current_rx_slot = 0;
               }
               else
               {
                  m_retry_timeout.Start();
                  m_retry_cnt = 0;
                  m_sub_mode_u16 = 8;
               }
            }
            resetRx();
         }
         break;
      case 10:
         // get sound param
         m_log->log("-----------------------------------------");

         StopWatch::Sleep_ms(30);

         m_log->log("Select sound %d", m_current_rx_slot + 1);
         sendGenericDumpRequest(m_current_rx_slot, false);
         m_sub_mode_u16++;
         break;
      case 11:
         receiveHandler();
         if((m_retry_timeout.Time() > TRANSFER2PC_RETRY_TIMEOUT) && (m_retry_cnt < 3))
         {
            m_retry_cnt++;
            m_retry_timeout.Start();
            m_sub_mode_u16 = 10;
            m_log->log("TIMEOUT -> retry");
         }
         if(m_retry_cnt >= 3)
         {
            m_log->log("No response");
            m_trx_error_e = TRX_NO_RESPONSE;
            m_main_mode_e = PROPH_IDLE; 
            m_midi->flush();
            m_main->transferFinished(true);
            m_progress_dlg->Hide();
         }
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == SOUND_PARAM_PACKET)
            {
               m_sub_mode_u16++;
               m_retry_timeout.Start();
               m_retry_cnt = 0;
            }
            resetRx();
         }
         break;
      case 12:
         // request sample data
         m_sub_mode_u16++;
         m_log->log("Request sample data");

         StopWatch::Sleep_ms(100);

         sendSampleDumpRequest(0, m_current_rx_slot, true);
         break;
      case 13:
         // send ACK on dump header
         receiveHandler();
         if((m_retry_timeout.Time() > TRANSFER2PC_RETRY_TIMEOUT) && (m_retry_cnt < 3))
         {
            m_retry_cnt++;
            m_retry_timeout.Start();
            m_sub_mode_u16 = 12;
            m_log->log("TIMEOUT -> retry");
         }
         if(m_retry_cnt >= 3)
         {
            m_log->log("No response");
            m_trx_error_e = TRX_NO_RESPONSE;
            m_main_mode_e = PROPH_IDLE; 
            m_midi->flush();
            m_main->transferFinished(true);
            m_progress_dlg->Hide();
         }
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == CANCEL_PACKET)
            {
               // empty sample received
               m_main->resetWaveViewZoom();
               m_main->updateWaveView();

               m_current_rx_slot++;
               if(m_current_rx_slot >= 16)
               {
                  m_sub_mode_u16 = 15; // all samples handled -> continue with next step
                  m_retry_timeout.Start();
                  resetRx();
               }
               else
               {
                  m_sub_mode_u16 = 10;
                  m_retry_timeout.Start();
                  resetRx();
               }
            }
            else
            if(m_rx_packet_e == DATA_PACKET)
            {
               // workaround: some dumps (related to specific disks) will send a data packet instead of the dump header->several retrys required
               m_sub_mode_u16 = 10;
               m_retry_timeout.Start();
               m_midi->logerror("Unexpected data packet instead of dump header -> send Cancel");
               m_log->log("Unexpected data packet instead of dump header -> send Cancel");
               sendCancel(0, 0);

               StopWatch::Sleep_ms(100);

               resetRx();
            }
            else
            {
               if(m_sample_length_words_au32[m_current_rx_slot])
               {
                  m_log->log("Receiving sample %d data...", m_current_rx_slot + 1);
                  m_progress_msg.sprintf("Receiving sample #%d", m_current_rx_slot + 1);
                  m_progress_dlg->Update(0, m_progress_msg);
                  m_progress_dlg->Show();
                  sendAck(m_midi->getChannel() - 1, 0);
                  m_sample_transfer_time.Start();
                  m_sub_mode_u16++;
               }
               else
               {
                  m_log->log("m_sample_length_words_au32[%d] == 0 -> send Cancel", m_current_rx_slot);
                  sendCancel(0, 0);
                  m_current_rx_slot++;
                  if(m_current_rx_slot >= 16)
                  {
                     m_sub_mode_u16 = 15; // all samples handled -> continue with next step
                  }
                  else
                  {
                     m_sub_mode_u16 = 10;
                     m_retry_timeout.Start();
                  }
               }
            }
            resetRx();
         }
         break;
      case 14:
         // handle data packets
         receiveHandler();
         if(m_ms_for_1_word == 0)
         {
            if(m_transfered_total >= WORDS_TO_ESTIMATED_TIME_CALC)
            {
               m_ms_for_1_word = (float)WORDS_TO_ESTIMATED_TIME_CALC / m_estimated_timer.Time();
            }
         }
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == DATA_PACKET)
            {
                  if(m_last_data_packet_size == 126)
                  {
                     handleReceivedDataPacket();
                     bool ready = false;
                     if(m_sample_length_words_au32[m_current_rx_slot])
                     {
                        if(m_ms_for_1_word == 0)
                        {
                           m_progress_dlg->Update((m_sampledata_rx_idx * 100) / m_sample_length_words_au32[m_current_rx_slot], m_progress_msg);
                        }
                        else
                        {
                           float val = ((m_total_words_to_transfer - m_transfered_total) / m_ms_for_1_word) / 1000;
                           if(val > 10000)
                           {
                              val = 0;
                           }
                           m_progress_msg.sprintf("Receiving sample #%d (%.1fs)", m_current_rx_slot + 1, val);
                           m_progress_dlg->Update((m_sampledata_rx_idx * 100) / m_sample_length_words_au32[m_current_rx_slot], m_progress_msg);
                        }
                     }

                     if(m_sampledata_rx_idx >= m_sample_length_words_au32[m_current_rx_slot])
                     {
                        ready = true;
                     }

                     if((m_last_data_packet_size < 126) || (ready == true))
                     {
                        if(m_sampledata_rx_idx < m_sample_length_words_au32[m_current_rx_slot])
                        {
                           m_log->log(" only received %d of %d words -> retry", m_sampledata_rx_idx, m_sample_length_words_au32[m_current_rx_slot]);
                           m_sub_mode_u16 = 10;
                           sendCancel(0, m_packet_counter);
                           m_retry_timeout.Start();
                        }
                        else
                        {
                           m_progress_dlg->Hide();
                           m_main->updateGUI();
                           m_main->resetWaveViewZoom();
                           m_main->updateWaveView();
#ifdef __WXMAC__
                           m_main->refreshNotebook();
#endif
                           m_log->log("sample words received: %d", m_sampledata_rx_idx);
                           m_log->log("Sample transfer time: %.1fs", (float)m_sample_transfer_time.Time() / 1000);

                           //sendAck(m_midi->getChannel() - 1, m_packet_counter);

                           if(m_invalid_packet_cnt)
                           {
                              m_invalid_packet_cnt = 0;
                              m_sub_mode_u16 = 10;
                              m_retry_timeout.Start();
                           }
                           else
                           {
                              m_current_rx_slot++;
                              if(m_current_rx_slot >= 16)
                              {
                                 m_sub_mode_u16++;
                              }
                              else
                              {
                                 m_sub_mode_u16 = 10;
                                 m_retry_timeout.Start();
                              }
                           }
                        }
                     }
                     if(m_use_rx_handshake)
                     {
                        sendAck(m_midi->getChannel() - 1, m_packet_counter);
                     }

               }
               else
               {
                  // non handshake mode
                  bool ready = false;
                  handleReceivedDataPacket();
                  if(m_sample_length_words_au32[m_current_rx_slot])
                  {
                     if(m_ms_for_1_word == 0)
                     {
                        m_progress_dlg->Update((m_sampledata_rx_idx * 100) / m_sample_length_words_au32[m_current_rx_slot], m_progress_msg);
                     }
                     else
                     {
                        m_progress_msg.sprintf("Receiving sample #%d (%.1fs)", m_current_rx_slot + 1, ((m_total_words_to_transfer - m_transfered_total) / m_ms_for_1_word) / 1000);
                        m_progress_dlg->Update((m_sampledata_rx_idx * 100) / m_sample_length_words_au32[m_current_rx_slot], m_progress_msg);
                     }
                  }

                  if(m_sampledata_rx_idx >= m_sample_length_words_au32[m_current_rx_slot])
                  {
                     ready = true;
                  }

                  if((m_last_data_packet_size < 126) || (ready == true))
                  {
                     if(m_sampledata_rx_idx < m_sample_length_words_au32[m_current_rx_slot])
                     {
                        m_log->log(" only received %d of %d words -> retry", m_sampledata_rx_idx, m_sample_length_words_au32[m_current_rx_slot]);
                        m_sub_mode_u16 = 10;
                        sendCancel(0, m_packet_counter);
                        m_retry_timeout.Start();
                     }
                     else
                     {
                        m_progress_dlg->Hide();
                        m_main->updateGUI();
                        m_main->resetWaveViewZoom();
                        m_main->updateWaveView();
                        m_log->log("sample words received: %d", m_sampledata_rx_idx);
                        m_log->log("Sample transfer time: %.1fs", (float)m_sample_transfer_time.Time() / 1000);
                        //sendAck(m_midi->getChannel() - 1, m_packet_counter);

                        if(m_invalid_packet_cnt)
                        {
                           m_invalid_packet_cnt = 0;
                           m_sub_mode_u16 = 10;
                           m_retry_timeout.Start();
                        }
                        else
                        {
                           m_current_rx_slot++;
                           if(m_current_rx_slot >= 16)
                           {
                              m_sub_mode_u16++;
                           }
                           else
                           {
                              m_sub_mode_u16 = 10;
                              m_retry_timeout.Start();
                           }
                        }
                     }
                  }
               }
            }
            else
            {
               m_log->log("!!!!!!! RESTART !!!!!!!!!!");
               m_midi->sendNoteOff(30, 100);  // abort current transfer

               StopWatch::Sleep_ms(100);

               m_sub_mode_u16 = 10; // restart transfer
               m_retry_timeout.Start();
            }
            resetRx();
         }
         break;
      case 15:
         m_current_rx_slot = 0;
         m_retry_cnt = 0;
         m_retry_timeout.Start();
         m_sub_mode_u16++;
         break;
      case 16:
         // request preset #1 to make it active
         sendGenericDumpRequest(0x40, false);
         m_sub_mode_u16++;
         break;
      case 17:
         receiveHandler();
         if((m_retry_timeout.Time() > TRANSFER2PC_RETRY_TIMEOUT) && (m_retry_cnt < 3))
         {
            m_retry_cnt++;
            m_retry_timeout.Start();
            m_sub_mode_u16 = 16;
            m_log->log("TIMEOUT -> retry");
         }
         if(m_retry_cnt >= 3)
         {
            m_log->log("No response");
            m_trx_error_e = TRX_NO_RESPONSE;
            m_main_mode_e = PROPH_IDLE; 
            m_midi->flush();
            m_main->transferFinished(true);
            m_progress_dlg->Hide();
         }
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == PRESET_PARAM_PACKET)
            {
               m_sub_mode_u16++;
            }
            resetRx();
         }
         break;
      case 18:
         m_log->log("-----------------------------------------");
         m_log->log("Total transfer time: %.1fs", (float)m_transfer_time.Time() / 1000);
         //m_log->log("Invalid packets: %d", m_invalid_packet_cnt);
         m_main_mode_e = PROPH_IDLE;
         m_main->transferFinished(true);
         m_progress_dlg->Hide();
         m_log->log("----------------FINISHED----------------");
         break;
      default:
         m_main_mode_e = PROPH_IDLE;
         break;
   }
}

void Proph2000::handleTransferSound2PC(void)
{
   switch(m_sub_mode_u16)
   {
      case 0:
         m_midi->flush();
         // get preset param
         m_sub_mode_u16++;
         m_ms_for_1_word = 0;
         m_transfered_total = 0;
         m_current_rx_slot = m_handle_id;
         break;
      case 1:
         // get sound param
         m_log->log("-----------------------------------------");

         StopWatch::Sleep_ms(30);

         m_progress_msg.sprintf("Receiving sound parameter #%d", m_current_rx_slot + 1);
         m_progress_dlg->Update(0 , m_progress_msg);

         m_log->log("Select sound %d", m_current_rx_slot + 1);
         sendGenericDumpRequest(m_current_rx_slot, true);
         m_sub_mode_u16++;
         break;
      case 2:
         receiveHandler();
         if((m_retry_timeout.Time() > TRANSFER2PC_RETRY_TIMEOUT) && (m_retry_cnt < 3))
         {
            m_retry_cnt++;
            m_retry_timeout.Start();
            m_sub_mode_u16 = 1;
            m_log->log("TIMEOUT -> retry");
         }
         if(m_retry_cnt >= 3)
         {
            m_log->log("No response");
            m_trx_error_e = TRX_NO_RESPONSE;
            m_main_mode_e = PROPH_IDLE; 
            m_midi->flush();
            m_main->transferFinished(true);
            m_progress_dlg->Hide();
         }
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == SOUND_PARAM_PACKET)
            {
               m_sub_mode_u16++;
               m_total_words_to_transfer = getSampleWords(m_current_rx_slot);
               m_retry_timeout.Start();
               m_retry_cnt = 0;
            }
            resetRx();
         }
         break;
      case 3:
         // request sample data
         m_sub_mode_u16++;
         m_log->log("Request sample data");

         StopWatch::Sleep_ms(100);

         sendSampleDumpRequest(0, m_current_rx_slot, true);
         break;
      case 4:
         // send ACK on dump header
         receiveHandler();
         if((m_retry_timeout.Time() > TRANSFER2PC_RETRY_TIMEOUT) && (m_retry_cnt < 3))
         {
            m_retry_cnt++;
            m_retry_timeout.Start();
            m_sub_mode_u16 = 3;
            m_log->log("TIMEOUT -> retry");
         }
         if(m_retry_cnt >= 3)
         {
            m_log->log("No response");
            m_trx_error_e = TRX_NO_RESPONSE;
            m_main_mode_e = PROPH_IDLE; 
            m_midi->flush();
            m_main->transferFinished(true);
            m_progress_dlg->Hide();
         }
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == CANCEL_PACKET)
            {
               // empty sample received
               m_main->resetWaveViewZoom();
               m_main->updateWaveView();

               m_sub_mode_u16 = 6;
            }
            else
            if(m_rx_packet_e == DATA_PACKET)
            {
               // workaround: some dumps (related to specific disks) will send a data packet instead of the dump header->several retrys required
               m_sub_mode_u16 = 3;
               m_retry_timeout.Start();
               m_midi->logerror("Unexpected data packet instead of dump header -> send Cancel");
               m_log->log("Unexpected data packet instead of dump header -> send Cancel");
               sendCancel(0, 0);

               StopWatch::Sleep_ms(100);

               resetRx();
            }
            else
            {
               if(m_sample_length_words_au32[m_current_rx_slot])
               {
                  m_log->log("Receiving sample %d data...", m_current_rx_slot + 1);
                  m_progress_msg.sprintf("Receiving sample #%d", m_current_rx_slot + 1);
                  m_progress_dlg->Update(0, m_progress_msg);
                  m_progress_dlg->Show();
                  sendAck(m_midi->getChannel() - 1, 0);
                  m_sample_transfer_time.Start();
                  m_sub_mode_u16++;
               }
               else
               {
                  m_log->log("m_sample_length_words_au32[%d] == 0 -> send Cancel", m_current_rx_slot);
                  sendCancel(0, 0);
                  m_sub_mode_u16 = 6;
               }
            }
            resetRx();
         }
         break;
      case 5:
         // handle data packets
         receiveHandler();
         if(m_ms_for_1_word == 0)
         {
            if(m_transfered_total >= WORDS_TO_ESTIMATED_TIME_CALC)
            {
               m_ms_for_1_word = (float)WORDS_TO_ESTIMATED_TIME_CALC / m_estimated_timer.Time();
            }
         }
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == DATA_PACKET)
            {
                  if(m_last_data_packet_size == 126)
                  {
                     handleReceivedDataPacket();
                     bool ready = false;
                     if(m_sample_length_words_au32[m_current_rx_slot])
                     {
                        if(m_ms_for_1_word == 0)
                        {
                           m_progress_dlg->Update((m_sampledata_rx_idx * 100) / m_sample_length_words_au32[m_current_rx_slot], m_progress_msg);
                        }
                        else
                        {
                           float val = ((m_total_words_to_transfer - m_transfered_total) / m_ms_for_1_word) / 1000;
                           if(val > 10000)
                           {
                              val = 0;
                           }
                           m_progress_msg.sprintf("Receiving sample #%d (%.1fs)", m_current_rx_slot + 1, val);
                           m_progress_dlg->Update((m_sampledata_rx_idx * 100) / m_sample_length_words_au32[m_current_rx_slot], m_progress_msg);
                        }
                     }

                     if(m_sampledata_rx_idx >= m_sample_length_words_au32[m_current_rx_slot])
                     {
                        ready = true;
                     }

                     if((m_last_data_packet_size < 126) || (ready == true))
                     {
                        if(m_sampledata_rx_idx < m_sample_length_words_au32[m_current_rx_slot])
                        {
                           m_log->log(" only received %d of %d words -> retry", m_sampledata_rx_idx, m_sample_length_words_au32[m_current_rx_slot]);
                           m_sub_mode_u16 = 3;
                           sendCancel(0, m_packet_counter);
                           m_retry_timeout.Start();
                        }
                        else
                        {
                           m_progress_dlg->Hide();
                           m_main->updateGUI();
                           m_main->resetWaveViewZoom();
                           m_main->updateWaveView();
                           m_log->log("sample words received: %d", m_sampledata_rx_idx);
                           m_log->log("Sample transfer time: %.1fs", (float)m_sample_transfer_time.Time() / 1000);

                           //sendAck(m_midi->getChannel() - 1, m_packet_counter);

                           if(m_invalid_packet_cnt)
                           {
                              m_invalid_packet_cnt = 0;
                              m_sub_mode_u16 = 3;
                              m_retry_timeout.Start();
                           }
                           else
                           {
                              m_sub_mode_u16 = 6;
                           }
                        }
                     }
                     if(m_use_rx_handshake)
                     {
                        sendAck(m_midi->getChannel() - 1, m_packet_counter);
                     }

               }
               else
               {
                  // non handshake mode
                  bool ready = false;
                  handleReceivedDataPacket();
                  if(m_sample_length_words_au32[m_current_rx_slot])
                  {
                     if(m_ms_for_1_word == 0)
                     {
                        m_progress_dlg->Update((m_sampledata_rx_idx * 100) / m_sample_length_words_au32[m_current_rx_slot], m_progress_msg);
                     }
                     else
                     {
                        m_progress_msg.sprintf("Receiving sample #%d (%.1fs)", m_current_rx_slot + 1, ((m_total_words_to_transfer - m_transfered_total) / m_ms_for_1_word) / 1000);
                        m_progress_dlg->Update((m_sampledata_rx_idx * 100) / m_sample_length_words_au32[m_current_rx_slot], m_progress_msg);
                     }
                  }

                  if(m_sampledata_rx_idx >= m_sample_length_words_au32[m_current_rx_slot])
                  {
                     ready = true;
                  }

                  if((m_last_data_packet_size < 126) || (ready == true))
                  {
                     if(m_sampledata_rx_idx < m_sample_length_words_au32[m_current_rx_slot])
                     {
                        m_log->log(" only received %d of %d words -> retry", m_sampledata_rx_idx, m_sample_length_words_au32[m_current_rx_slot]);
                        m_sub_mode_u16 = 3;
                        sendCancel(0, m_packet_counter);
                        m_retry_timeout.Start();
                     }
                     else
                     {
                        m_progress_dlg->Hide();
                        m_main->updateGUI();
                        m_main->resetWaveViewZoom();
                        m_main->updateWaveView();
                        m_log->log("sample words received: %d", m_sampledata_rx_idx);
                        m_log->log("Sample transfer time: %.1fs", (float)m_sample_transfer_time.Time() / 1000);
                        //sendAck(m_midi->getChannel() - 1, m_packet_counter);

                        if(m_invalid_packet_cnt)
                        {
                           m_invalid_packet_cnt = 0;
                           m_sub_mode_u16 = 3;
                           m_retry_timeout.Start();
                        }
                        else
                        {
                           m_sub_mode_u16 = 6;
                        }
                     }
                  }
               }
            }
            else
            {
               m_log->log("!!!!!!! RESTART !!!!!!!!!!");
               m_midi->sendNoteOff(30, 100);  // abort current transfer

               StopWatch::Sleep_ms(100);

               m_sub_mode_u16 = 3; // restart transfer
               m_retry_timeout.Start();
            }
            resetRx();
         }
         break;
      case 6:
         m_current_rx_slot = 0;
         m_retry_cnt = 0;
         m_retry_timeout.Start();
         m_sub_mode_u16++;
         break;
      case 7:
         m_log->log("-----------------------------------------");
         m_log->log("Total transfer time: %.1fs", (float)m_transfer_time.Time() / 1000);
         //m_log->log("Invalid packets: %d", m_invalid_packet_cnt);
         m_main_mode_e = PROPH_IDLE;
         m_main->transferFinished(true);
         m_progress_dlg->Hide();
         m_log->log("----------------FINISHED----------------");
#ifdef __WXMAC__
         m_main->refreshNotebook();
#endif
         break;
      default:
         m_main_mode_e = PROPH_IDLE;
         break;
   }
}

void Proph2000::handleTransfer2Prophet(void)
{
//   uint8_t i;
   switch(m_sub_mode_u16)
   {
      case 0:
         // clear memory
         m_midi->flush();

         m_log->log("Delete memory");
         sendDeleteMemory(0x12);
         m_retry_timeout.Start();
         m_sub_mode_u16++;
         break;
      case 1:
         receiveHandler();
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == ACK_PACKET)
            {
               m_sub_mode_u16++;
               m_estimated_timer.Start();
               m_retry_timeout.Start();
               m_retry_cnt = 0;
            }
            else
            {
               m_sub_mode_u16 = 0;
               m_retry_timeout.Start();
               m_retry_cnt++;
            }
            resetRx();
         }
         if((m_retry_timeout.Time() > TRANSFER2PROPH_RETRY_TIMEOUT) && (m_retry_cnt < 3))
         {
            m_retry_cnt++;
            m_retry_timeout.Start();
            m_sub_mode_u16 = 0;
            m_log->log("TIMEOUT -> retry");
         }
         if(m_retry_cnt >= 3)
         {
            m_sub_mode_u16++;
         }
         break;
      case 2:
         if(m_sound_param_as[m_current_rx_slot].val_s.sample_status)
         {
            m_log->log("-----------------------------------------");

            StopWatch::Sleep_ms(30);

            m_log->log("Select sound %d", m_current_rx_slot + 1);
            sendSampleDumpRequest(0, m_current_rx_slot, false);
            m_sub_mode_u16++;
         }
         else
         {
            m_sub_mode_u16 = 7;
            resetRx();
         }
         break;
      case 3:
         receiveHandler();
         if(m_rx_mode_e == RX_FINISHED)
         {
            if((m_rx_packet_e == SOUND_PARAM_PACKET)  || (m_rx_packet_e == CANCEL_PACKET))
            {
               m_sub_mode_u16++;
               m_log->log("Send sound parameters");
               sendSoundParamDump(m_current_rx_slot + 0x00);
               //StopWatch::Sleep_ms(100);

               m_retry_cnt = 0;
            }
            resetRx();
         }
         if((m_retry_timeout.Time() > TRANSFER2PROPH_RETRY_TIMEOUT) && (m_retry_cnt < 3))
         {
            m_retry_cnt++;
            m_retry_timeout.Start();
            m_sub_mode_u16 = 2;
            m_log->log("TIMEOUT -> retry");
         }
         if(m_retry_cnt >= 3)
         {
            m_log->log("No response");
            m_trx_error_e = TRX_NO_RESPONSE;
            m_main_mode_e = PROPH_IDLE; 
            m_midi->flush();
            m_main->transferFinished(true);
            m_progress_dlg->Hide();
         }
         break;
      case 4:
         m_log->log(" send sample %d (%d words)", m_current_rx_slot + 1, getSampleWords(m_current_rx_slot));
         if(m_sound_param_as[m_current_rx_slot].val_s.sample_status)
         {
            m_log->log("Send sample data");
            m_progress_msg.sprintf("Sending sample #%d", m_current_rx_slot + 1);
            m_progress_dlg->Update(0, m_progress_msg);
            m_progress_dlg->Show();

            StopWatch::Sleep_ms(30);

            sendDumpHeader(0, m_current_rx_slot);
            m_ack_timeout.Start();
            m_sample_transfer_time.Start();
            m_sampledata_rx_idx = 0;
            m_sub_mode_u16++;
            m_retry_cnt = 0;
         }
         else
         {
            m_sub_mode_u16 = 7;
            m_retry_cnt = 0;
         }
         break;
      case 5:
         receiveHandler();
         if(m_ack_timeout.Time() >= TRANSFER2PROPH_ACK_TIMEOUT)
         {
            m_log->log("!!! ACK timeout !!!");
            m_midi->logerror("ACK timeout");
            m_rx_mode_e = RX_FINISHED;
            m_rx_packet_e = ACK_PACKET;
         }
         if(m_ms_for_1_word == 0)
         {
            if(m_transfered_total >= WORDS_TO_ESTIMATED_TIME_CALC)
            {
               m_ms_for_1_word = (float)WORDS_TO_ESTIMATED_TIME_CALC / m_estimated_timer.Time();
            }
         }
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == ACK_PACKET)
            {
               if(m_sound_param_as[m_current_rx_slot].val_s.sample_status)
               {
                  if(m_ms_for_1_word == 0)
                  {
                     m_progress_dlg->Update((m_sampledata_rx_idx * 100) / getSampleWords(m_current_rx_slot), m_progress_msg);
                  }
                  else
                  {
                     float val = ((m_total_words_to_transfer - m_transfered_total) / m_ms_for_1_word) / 1000;
                     if(val > 10000)
                     {
                        val = 0;
                     }
                     m_progress_msg.sprintf("Sending sample #%d (%.1f)", m_current_rx_slot + 1, val);
                     m_progress_dlg->Update((m_sampledata_rx_idx * 100) / getSampleWords(m_current_rx_slot), m_progress_msg);
                  }
               }
               m_packet_counter = 0;
               sendDataPacketBlock(&m_sampledata_au16[m_current_rx_slot][m_sampledata_rx_idx]);
               m_sub_mode_u16++;
               m_retry_cnt = 0;
            }
            resetRx();
         }
         break;
      case 6:
         receiveHandler();
         if(m_ack_timeout.Time() >= TRANSFER2PROPH_ACK_TIMEOUT)
         {
            m_midi->logerror("ACK timeout");
            m_log->log("!!! ACK timeout !!!");
            m_rx_mode_e = RX_FINISHED;
            m_rx_packet_e = ACK_PACKET;
         }
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == ACK_PACKET)
            {
               m_sampledata_rx_idx += 60;
               if(m_sampledata_rx_idx >= getSampleWords(m_current_rx_slot))
               {
                  m_log->log("transfered %d sample words", (m_sampledata_rx_idx - 60));
                  m_log->log("Sample transfer time: %.1fs", (float)m_sample_transfer_time.Time() / 1000);

                  m_sub_mode_u16++;
                  m_log->log("-----------------------------------------");
                  m_retry_cnt = 0;
               }
               else
               {
                  sendDataPacketBlock(&m_sampledata_au16[m_current_rx_slot][m_sampledata_rx_idx]);
               }

               if(m_sound_param_as[m_current_rx_slot].val_s.sample_status)
               {
                  if(m_ms_for_1_word == 0)
                  {
                     m_progress_dlg->Update((m_sampledata_rx_idx * 100) / getSampleWords(m_current_rx_slot), m_progress_msg);
                  }
                  else
                  {
                     float val = ((m_total_words_to_transfer - m_transfered_total) / m_ms_for_1_word) / 1000;
                     if(val > 10000)
                     {
                        val = 0;
                     }
                     m_progress_msg.sprintf("Sending sample #%d (%.1f)", m_current_rx_slot + 1, val);
                     m_progress_dlg->Update((m_sampledata_rx_idx * 100) / getSampleWords(m_current_rx_slot), m_progress_msg);
                  }
               }
            }
            else
            if(m_rx_packet_e == NACK_PACKET)
            {
               sendDataPacketBlock(&m_sampledata_au16[m_current_rx_slot][m_sampledata_rx_idx]);
            }
            else
            if(m_rx_packet_e == CANCEL_PACKET)
            {
               m_sub_mode_u16++;
               
               m_retry_cnt = 0;
               m_log->log("transfered %d sample words", m_sampledata_rx_idx);
               m_log->log("Sample transfer time: %.1fs", (float)m_sample_transfer_time.Time() / 1000);
               m_progress_dlg->Hide();
               m_log->log("-----------------------------------------");
            }
         }
         break;
      case 7:
         if(m_sound_param_as[m_current_rx_slot].val_s.sample_status)
         {
            StopWatch::Sleep_ms(100); // die alte Zicke brauch hier eine kleine Pause!!!
            m_log->log("Send sound parameters");
            sendSoundParamDump(m_current_rx_slot + 0x00);
            receiveHandler();
         }
         m_sub_mode_u16++;
         m_retry_cnt = 0;
         break;
      case 8:
         m_sub_mode_u16++;
         m_log->log("-----------------------------------------");
         m_progress_msg.sprintf("Sending map #%d", m_current_rx_slot + 1);
         m_progress_dlg->Update(((m_current_rx_slot + 1) * 100) / 16 , m_progress_msg);
         m_progress_dlg->Show();
         StopWatch::Sleep_ms(30);
         m_log->log("Send map %d", m_current_rx_slot + 1);
         sendGenericDumpRequest(m_current_rx_slot + 0x60, false); // select map
         m_retry_timeout.Start();
         break;
      case 9:
         receiveHandler();
         if((m_retry_timeout.Time() > TRANSFER2PROPH_RETRY_TIMEOUT) && (m_retry_cnt < 3))
         {
            m_retry_cnt++;
            m_retry_timeout.Start();
            m_sub_mode_u16 = 8;
            m_log->log("TIMEOUT -> retry");
         }
         if(m_retry_cnt >= 3)
         {
            m_log->log("No response");
            m_trx_error_e = TRX_NO_RESPONSE;
            m_main_mode_e = PROPH_IDLE; 
            m_midi->flush();
            m_main->transferFinished(true);
            m_progress_dlg->Hide();
         }
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == MAP_PARAM_PACKET)
            {
               sendMapParamDump(m_current_rx_slot);
               m_current_rx_slot++;
               m_retry_cnt = 0;
               if(m_current_rx_slot >= 16)
               {
                  m_sub_mode_u16++;
                  m_log->log("-----------------------------------------");
                  m_retry_cnt = 0;
                  m_retry_timeout.Start();
                  m_current_rx_slot = 0;
               }
               else
               {
                  m_sub_mode_u16 = 2;
                  m_retry_timeout.Start();
               }
            }
            resetRx();
         }
         break;
      case 10:
         m_progress_msg.sprintf("Sending preset #%d", m_current_rx_slot + 1);
         m_progress_dlg->Update(((m_current_rx_slot + 1) * 100) / 12 , m_progress_msg);
         m_progress_dlg->Show();
         m_log->log("Send preset %d", m_current_rx_slot + 1);
         StopWatch::Sleep_ms(30);
         sendGenericDumpRequest(m_current_rx_slot + 0x40, false); // select preset
         m_sub_mode_u16++;
         break;
      case 11:
         receiveHandler();
         if((m_retry_timeout.Time() > TRANSFER2PROPH_RETRY_TIMEOUT) && (m_retry_cnt < 3))
         {
            m_retry_cnt++;
            m_retry_timeout.Start();
            m_sub_mode_u16 = 10;
            m_log->log("TIMEOUT -> retry");
         }
         if(m_retry_cnt >= 3)
         {
            m_log->log("No response");
            m_trx_error_e = TRX_NO_RESPONSE;
            m_main_mode_e = PROPH_IDLE; 
            m_midi->flush();
            m_main->transferFinished(true);
            m_progress_dlg->Hide();
         }
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == PRESET_PARAM_PACKET)
            {
               sendPresetParamDump(m_current_rx_slot);

               m_retry_cnt = 0;
               m_current_rx_slot++;
               if(m_current_rx_slot <= 11)
               {
                  m_retry_timeout.Start();
                  m_sub_mode_u16 = 10;
                  m_log->log("-----------------------------------------");
               }
               else
               {
                  m_sub_mode_u16++;
                  m_retry_timeout.Start();
               }
            }
            resetRx();
         }
         break;
      case 12:
         m_progress_dlg->Hide();
         m_log->log("-----------------------------------------");
         m_log->log("Select preset 1");
         sendGenericDumpRequest(0 + 0x40, false); // select preset #0
         m_sub_mode_u16++;
         break;
      case 13:
         receiveHandler();
         if((m_retry_timeout.Time() > TRANSFER2PROPH_RETRY_TIMEOUT) && (m_retry_cnt < 3))
         {
            m_retry_cnt++;
            m_retry_timeout.Start();
            m_sub_mode_u16 = 12;
            m_log->log("TIMEOUT -> retry");
            resetRx();
         }
         if(m_retry_cnt >= 3)
         {
            m_log->log("No response");
            m_trx_error_e = TRX_NO_RESPONSE;
            m_main_mode_e = PROPH_IDLE; 
            m_midi->flush();
            m_main->transferFinished(true);
            m_progress_dlg->Hide();
         }
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == PRESET_PARAM_PACKET)
            {
               m_sub_mode_u16++;
               m_retry_cnt = 0;
            }
            resetRx();
         }
         break;
      case 14:
         m_current_rx_slot = 0;
         m_retry_timeout.Start();
         m_sub_mode_u16++;
         break;
      case 15:
         m_log->log("-----------------------------------------");
         m_log->log("Total transfer time: %.1fs", (float)m_transfer_time.Time() / 1000);
         m_main_mode_e = PROPH_IDLE;
         m_main->transferFinished(true);
         m_progress_dlg->Hide();
         m_log->log("----------------FINISHED----------------");
         break;
      case 16:
         receiveHandler();
         if((m_retry_timeout.Time() > TRANSFER2PC_RETRY_TIMEOUT) && (m_retry_cnt < 3))
         {
            m_retry_cnt++;
            m_retry_timeout.Start();
            m_sub_mode_u16 = 15;
            m_log->log("TIMEOUT -> retry");
         }
         if(m_retry_cnt >= 3)
         {
            m_log->log("No response");
            m_trx_error_e = TRX_NO_RESPONSE;
            m_main_mode_e = PROPH_IDLE; 
            m_midi->flush();
            m_main->transferFinished(true);
            m_progress_dlg->Hide();
         }
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == SOUND_PARAM_PACKET)
            {
               m_sub_mode_u16++;
               m_retry_cnt = 0;
            }
            if((m_rx_packet_e == INVALID_PACKET) && (m_retry_cnt < 3))
            {
               m_retry_cnt++;
               m_retry_timeout.Start();
               m_sub_mode_u16 = 15;
               m_log->log("INVALID -> retry");
            }
            resetRx();
         }
         break;
      case 17:
         if(getSampleWords(m_current_rx_slot))
         {
            m_log->log("Send sound %d parameters", m_current_rx_slot + 1);
            sendSoundParamDump(m_current_rx_slot + 0x00);
         }
         m_current_rx_slot++;
         if(m_current_rx_slot >= 16)
         {
            m_sub_mode_u16++;
         }
         else
         {
            m_sub_mode_u16 = 15;
            m_retry_cnt = 0;
         }
         break;
      case 18:
         m_log->log("-----------------------------------------");
         m_log->log("Total transfer time: %.1fs", (float)m_transfer_time.Time() / 1000);
         m_main_mode_e = PROPH_IDLE;
         m_main->transferFinished(true);
         m_progress_dlg->Hide();
         m_log->log("----------------FINISHED----------------");
         break;
      default:
         m_main_mode_e = PROPH_IDLE;
         break;
   }
}

void Proph2000::handleParameter2Prophet(void)
{
//   uint8_t i;
   switch(m_sub_mode_u16)
   {
      case 0:
         m_midi->flush();

         m_sub_mode_u16++;
         break;
      case 1:
         if(m_sound_param_as[m_current_rx_slot].val_s.sample_status)
         {
            m_log->log("-----------------------------------------");
            m_progress_msg.sprintf("Sending sound parameter #%d", m_current_rx_slot + 1);
            m_progress_dlg->Update(((m_current_rx_slot + 1) * 100) / 16 , m_progress_msg);
            m_progress_dlg->Show();
            m_log->log("Select sound %d", m_current_rx_slot + 1);
            StopWatch::Sleep_ms(30);
            sendGenericDumpRequest(m_current_rx_slot, false);
            m_sub_mode_u16++;
         }
         else
         {
            m_sub_mode_u16 = 3;
            resetRx();
         }
         break;
      case 2:
         receiveHandler();
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == SOUND_PARAM_PACKET)
            {
               m_sub_mode_u16++;
               m_log->log("Send sound parameters");
               sendSoundParamDump(m_current_rx_slot + 0x00);
               StopWatch::Sleep_ms(50);

               m_retry_cnt = 0;
            }
            resetRx();
         }
         if((m_retry_timeout.Time() > TRANSFER2PROPH_RETRY_TIMEOUT) && (m_retry_cnt < 3))
         {
            m_retry_cnt++;
            m_retry_timeout.Start();
            m_sub_mode_u16 = 1;
            m_log->log("TIMEOUT -> retry");
         }
         if(m_retry_cnt >= 3)
         {
            m_log->log("No response");
            m_trx_error_e = TRX_NO_RESPONSE;
            m_main_mode_e = PROPH_IDLE; 
            m_midi->flush();
            m_main->transferFinished(true);
            m_progress_dlg->Hide();
         }
         break;
      case 3:
         m_sub_mode_u16++;
         m_progress_msg.sprintf("Sending map #%d", m_current_rx_slot + 1);
         m_progress_dlg->Update(((m_current_rx_slot + 1) * 100) / 16 , m_progress_msg);
         m_progress_dlg->Show();
         m_log->log("-----------------------------------------");
         m_log->log("Send map %d", m_current_rx_slot + 1);
         StopWatch::Sleep_ms(30);
         sendGenericDumpRequest(m_current_rx_slot + 0x60, false); // select map
         m_retry_timeout.Start();
         break;
      case 4:
         receiveHandler();
         if((m_retry_timeout.Time() > TRANSFER2PROPH_RETRY_TIMEOUT) && (m_retry_cnt < 3))
         {
            m_retry_cnt++;
            m_retry_timeout.Start();
            m_sub_mode_u16 = 3;
            m_log->log("TIMEOUT -> retry");
         }
         if(m_retry_cnt >= 3)
         {
            m_log->log("No response");
            m_trx_error_e = TRX_NO_RESPONSE;
            m_main_mode_e = PROPH_IDLE; 
            m_midi->flush();
            m_main->transferFinished(true);
            m_progress_dlg->Hide();
         }
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == MAP_PARAM_PACKET)
            {
               sendMapParamDump(m_current_rx_slot);
               StopWatch::Sleep_ms(50);
               m_current_rx_slot++;
               m_retry_cnt = 0;
               if(m_current_rx_slot >= 16)
               {
                  m_sub_mode_u16++;
                  m_log->log("-----------------------------------------");
                  m_retry_cnt = 0;
                  m_retry_timeout.Start();
                  m_current_rx_slot = 0;
               }
               else
               {
                  m_sub_mode_u16 = 1;
                  m_retry_timeout.Start();
               }
            }
            resetRx(); 
         }
         break;
      case 5:
         m_progress_msg.sprintf("Sending preset #%d", m_current_rx_slot + 1);
         m_progress_dlg->Update(((m_current_rx_slot + 1) * 100) / 12 , m_progress_msg);
         m_progress_dlg->Show();
         m_log->log("Send preset %d", m_current_rx_slot + 1);
         StopWatch::Sleep_ms(30);
         sendGenericDumpRequest(m_current_rx_slot + 0x40, false); // select preset
         m_sub_mode_u16++;
         break;
      case 6:
         receiveHandler();
         if((m_retry_timeout.Time() > TRANSFER2PROPH_RETRY_TIMEOUT) && (m_retry_cnt < 3))
         {
            m_retry_cnt++;
            m_retry_timeout.Start();
            m_sub_mode_u16 = 5;
            m_log->log("TIMEOUT -> retry");
         }
         if(m_retry_cnt >= 3)
         {
            m_log->log("No response");
            m_trx_error_e = TRX_NO_RESPONSE;
            m_main_mode_e = PROPH_IDLE; 
            m_midi->flush();
            m_main->transferFinished(true);
            m_progress_dlg->Hide();
         }
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == PRESET_PARAM_PACKET)
            {
               sendPresetParamDump(m_current_rx_slot);
               StopWatch::Sleep_ms(30);

               m_retry_cnt = 0;
               m_current_rx_slot++;
               if(m_current_rx_slot <= 11)
               {
                  m_retry_timeout.Start();
                  m_sub_mode_u16 = 5;
                  m_log->log("-----------------------------------------");
               }
               else
               {
                  m_sub_mode_u16++;
                  m_retry_timeout.Start();
               }
            }
            resetRx();
         }
         break;
      case 7:
         m_log->log("-----------------------------------------");
         m_log->log("Select preset 1");
         sendGenericDumpRequest(0 + 0x40, false); // select preset #0
         m_sub_mode_u16++;
         break;
      case 8:
         receiveHandler();
         if((m_retry_timeout.Time() > TRANSFER2PROPH_RETRY_TIMEOUT) && (m_retry_cnt < 3))
         {
            m_retry_cnt++;
            m_retry_timeout.Start();
            m_sub_mode_u16 = 7;
            m_log->log("TIMEOUT -> retry");
         }
         if(m_retry_cnt >= 3)
         {
            m_log->log("No response");
            m_trx_error_e = TRX_NO_RESPONSE;
            m_main_mode_e = PROPH_IDLE; 
            m_midi->flush();
            m_main->transferFinished(true);
            m_progress_dlg->Hide();
         }
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == PRESET_PARAM_PACKET)
            {
               m_sub_mode_u16++;
               m_retry_cnt = 0;
            }
            resetRx();
         }
         break;
      case 9:
         m_log->log("-----------------------------------------");
         m_main_mode_e = PROPH_IDLE;
         m_main->transferFinished(true);
         m_progress_dlg->Hide();
         m_log->log("----------------FINISHED----------------");
         break;
      default:
         m_main_mode_e = PROPH_IDLE;
         break;
   }
}

void Proph2000::handleAllSoundParameter2Prophet(void)
{
   switch(m_sub_mode_u16)
   {
      case 0:
         m_midi->flush();

         m_sub_mode_u16++;
         break;
      case 1:
         if(m_sound_param_as[m_current_rx_slot].val_s.sample_status)
         {
            m_log->log("-----------------------------------------");
            StopWatch::Sleep_ms(30);
            m_log->log("Select sound %d", m_current_rx_slot + 1);
            sendGenericDumpRequest(m_current_rx_slot, false);
            m_sub_mode_u16++;
         }
         else
         {
            m_current_rx_slot++;

            if(m_current_rx_slot >= 16)
            {
               m_sub_mode_u16 = 3;
               m_log->log("-----------------------------------------");
               m_retry_cnt = 0;
               m_retry_timeout.Start();
               m_current_rx_slot = 0;
            }
            else
            {
               m_sub_mode_u16 = 1;
               m_retry_timeout.Start();
            }
         }
         break;
      case 2:
         receiveHandler();
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == SOUND_PARAM_PACKET)
            {
               m_sub_mode_u16++;
               m_log->log("Send sound parameters");
               sendSoundParamDump(m_current_rx_slot + 0x00);
               StopWatch::Sleep_ms(100);
               m_current_rx_slot++;

               if(m_current_rx_slot >= 16)
               {
                  m_sub_mode_u16++;
                  m_log->log("-----------------------------------------");
                  m_retry_cnt = 0;
                  m_retry_timeout.Start();
                  m_current_rx_slot = 0;
               }
               else
               {
                  m_sub_mode_u16 = 1;
                  m_retry_timeout.Start();
               }

               m_retry_cnt = 0;
            }
            resetRx();
         }
         if((m_retry_timeout.Time() > TRANSFER2PROPH_RETRY_TIMEOUT) && (m_retry_cnt < 3))
         {
            m_retry_cnt++;
            m_retry_timeout.Start();
            m_sub_mode_u16 = 1;
            m_log->log("TIMEOUT -> retry");
         }
         if(m_retry_cnt >= 3)
         {
            m_log->log("No response");
            m_trx_error_e = TRX_NO_RESPONSE;
            m_main_mode_e = PROPH_IDLE; 
            m_midi->flush();
            m_main->transferFinished(true);
            m_progress_dlg->Hide();
         }
         break;
      case 3:
         m_log->log("-----------------------------------------");
         if(!m_req_during_transfer_cnt)
         {
            m_main_mode_e = PROPH_IDLE;
            m_main->transferFinished(true);
         }
         else
         {
            m_sub_mode_u16 = 0;
            m_req_during_transfer_cnt = 0;
         }
         m_progress_dlg->Hide();
         m_log->log("----------------FINISHED----------------");
         break;
      default:
         m_main_mode_e = PROPH_IDLE;
         break;
   }
}

void Proph2000::handleTransferPreset2Prophet(void)
{
   switch(m_sub_mode_u16)
   {
      case 0:
         m_midi->flush();
         if(m_send_select_request)
         {
            m_send_select_request = false;
            m_midi->flush();
            sendGenericDumpRequest(m_handle_id + 0x40, false); // select preset
            m_sub_mode_u16++;
         }
         else
         {
            m_sub_mode_u16 = 2;
         }
         break;
      case 1:
         receiveHandler();
         if((m_retry_timeout.Time() > TRANSFER2PROPH_RETRY_TIMEOUT) && (m_retry_cnt < 3))
         {
            m_retry_cnt++;
            m_retry_timeout.Start();
            m_sub_mode_u16 = 0;
            m_log->log("TIMEOUT -> retry");
         }
         if(m_retry_cnt >= 3)
         {
            m_log->log("No response");
            m_trx_error_e = TRX_NO_RESPONSE;
            m_main_mode_e = PROPH_IDLE; 
            m_midi->flush();
            m_main->transferFinished(true);
            m_progress_dlg->Hide();
         }
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == PRESET_PARAM_PACKET)
            {
               m_sub_mode_u16++;
            }
            resetRx();
         }
         break;
      case 2:
         sendPresetParamDump(m_handle_id);
         StopWatch::Sleep_ms(50);
         m_sub_mode_u16++;
         break;
      case 3:
         if(m_req_during_transfer_cnt)
         {
            m_sub_mode_u16 = 0;
            m_req_during_transfer_cnt = 0;
         }
         else
         {  
            m_main_mode_e = PROPH_IDLE;
            m_main->transferFinished(false);
         }
         break;
      default:
         m_main_mode_e = PROPH_IDLE;
         break;
   }
}


void Proph2000::handleTransferMap2Prophet(void)
{
   switch(m_sub_mode_u16)
   {
      case 0:
         m_midi->flush();
         if(m_send_select_request)
         {
            m_send_select_request = false;
            sendGenericDumpRequest(m_handle_id + 0x60, false); // select map
            m_sub_mode_u16++;
         }
         else
         {
            m_sub_mode_u16 = 2;
         }
         break;
      case 1:
         receiveHandler();
         if((m_retry_timeout.Time() > TRANSFER2PROPH_RETRY_TIMEOUT) && (m_retry_cnt < 3))
         {
            m_retry_cnt++;
            m_retry_timeout.Start();
            m_sub_mode_u16 = 0;
            m_midi->flush();
            m_log->log("TIMEOUT -> retry");
         }
         if(m_retry_cnt >= 3)
         {
            m_log->log("No response");
            m_trx_error_e = TRX_NO_RESPONSE;
            m_main_mode_e = PROPH_IDLE; 
            m_main->transferFinished(true);
            m_progress_dlg->Hide();
         }
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == MAP_PARAM_PACKET)
            {
               m_sub_mode_u16++;
            }
            resetRx();
         }
         break;
      case 2:
         StopWatch::Sleep_ms(30);
         sendMapParamDump(m_handle_id);
         m_sub_mode_u16++;
         break;
      case 3:
         if(m_req_during_transfer_cnt)
         {
            m_sub_mode_u16 = 0;
            m_req_during_transfer_cnt = 0;
            StopWatch::Sleep_ms(50);
         }
         else
         {  
            if(m_send_stereo_trigger)
            {
               // send other channel map as well
               m_send_stereo_trigger = false;
               m_retry_timeout.Start();
               m_sub_mode_u16 = 0;
               m_retry_cnt = 0;
               if(m_handle_id < 8)
               {
                  m_handle_id += 8;
               }
               else
               {
                  m_handle_id -= 8;
               }
               m_midi_rx_idx = 0;
               m_invalid_packet_cnt = 0;
               m_trx_error_e = TRX_NOERROR;
               m_rx_packet_e = INVALID_PACKET;
               m_main_mode_e = PROPH_TX_MAP;
               m_last_main_mode_e = m_main_mode_e;
            }
            else
            {
               m_main_mode_e = PROPH_IDLE;
               m_main->transferFinished(false);
            }
         }
         break;
      default:
         m_main_mode_e = PROPH_IDLE;
         break;
   }
}


void Proph2000::handleTransferSoundParam2Prophet(void)
{
   switch(m_sub_mode_u16)
   {
      case 0:
         m_midi->flush();
         if(m_send_select_request)
         {
            m_send_select_request = false;
            // select sound param
            sendGenericDumpRequest(m_handle_id, false);
            m_sub_mode_u16++;
         }
         else
         {
            m_sub_mode_u16 = 2;
         }
         break;
      case 1:
         receiveHandler();
         if((m_retry_timeout.Time() > TRANSFER2PC_RETRY_TIMEOUT) && (m_retry_cnt < 3))
         {
            m_retry_cnt++;
            m_retry_timeout.Start();
            m_sub_mode_u16 = 0;
            m_midi->flush();
            m_log->log("TIMEOUT -> retry");
         }
         if(m_retry_cnt >= 3)
         {
            m_log->log("No response");
            m_trx_error_e = TRX_NO_RESPONSE;
            m_main_mode_e = PROPH_IDLE; 
            m_main->transferFinished(true);
            m_progress_dlg->Hide();
         }
         if(m_rx_mode_e == RX_FINISHED)
         {
            if(m_rx_packet_e == SOUND_PARAM_PACKET)
            {
               m_sub_mode_u16++;
            }
            resetRx();
         }
         break;
      case 2:
         m_sub_mode_u16++;
         StopWatch::Sleep_ms(30);
         sendSoundParamDump(m_handle_id + 0x00);
         break;
      case 3:
         if(!m_req_during_transfer_cnt)
         {
            if(m_send_stereo_trigger)
            {
               // send the other channel sample param as well
               m_send_stereo_trigger = false;
               m_retry_timeout.Start();
               m_sub_mode_u16 = 0;
               m_retry_cnt = 0;
               if(m_handle_id < 8)
               {
                  m_handle_id += 8;
               }
               else
               {
                  m_handle_id -= 8;
               }
               m_midi_rx_idx = 0;
               m_invalid_packet_cnt = 0;
               m_trx_error_e = TRX_NOERROR;
               m_rx_packet_e = INVALID_PACKET;
               m_main_mode_e = PROPH_TX_SOUNDPARAM;
               m_last_main_mode_e = m_main_mode_e;
            }
            else
            {
               m_main_mode_e = PROPH_IDLE;
               m_main->transferFinished(false);
            }
         }
         else
         {
            StopWatch::Sleep_ms(50);
            m_sub_mode_u16 = 0;
            m_req_during_transfer_cnt = 0;
         }
         break;
      default:
         m_main_mode_e = PROPH_IDLE;
         break;
   }
}

