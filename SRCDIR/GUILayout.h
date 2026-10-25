///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct  8 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUILAYOUT_H__
#define __GUILAYOUT_H__

#include <wx/artprov.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/gauge.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/statline.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include "types.h"
#include <wx/wx.h>
#include "wavedisp.h"
#include <wx/spinctrl.h>
#include <wx/checkbox.h>
#include <wx/tglbtn.h>
#include <wx/odcombo.h>
#include <wx/slider.h>
#include "envdisp.h"
#include <wx/statbox.h>
#include <wx/choice.h>
#include <wx/dialog.h>
#include <wx/radiobox.h>
#include <wx/hyperlink.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class SamplesPanel
///////////////////////////////////////////////////////////////////////////////
class SamplesPanel : public wxPanel 
{
	private:
	
	protected:
		wxStaticText* m_staticText1110;
		wxStaticText* m_staticText266;
		wxGauge* m_a_memory_usage;
		wxTextCtrl* m_a_memory_usage_txt;
		wxStaticText* m_staticText292;
		wxStaticText* m_staticText1117;
		wxTextCtrl* m_sample_words1;
		wxTextCtrl* m_sample_rate1;
		wxButton* m_button179;
		wxButton* m_button180;
		wxButton* m_button181;
		wxButton* m_button182;
		wxTextCtrl* m_sample_name1;
		wxStaticText* m_staticText11171;
		wxTextCtrl* m_sample_words2;
		wxTextCtrl* m_sample_rate2;
		wxButton* m_button1791;
		wxButton* m_button1801;
		wxButton* m_button1811;
		wxButton* m_button1821;
		wxTextCtrl* m_sample_name2;
		wxStaticText* m_staticText11172;
		wxTextCtrl* m_sample_words3;
		wxTextCtrl* m_sample_rate3;
		wxButton* m_button1792;
		wxButton* m_button1802;
		wxButton* m_button1812;
		wxButton* m_button1822;
		wxTextCtrl* m_sample_name3;
		wxStaticText* m_staticText1125;
		wxTextCtrl* m_sample_words4;
		wxTextCtrl* m_sample_rate4;
		wxButton* m_button17921;
		wxButton* m_button18021;
		wxButton* m_button18121;
		wxButton* m_button18221;
		wxTextCtrl* m_sample_name4;
		wxStaticText* m_staticText1127;
		wxTextCtrl* m_sample_words5;
		wxTextCtrl* m_sample_rate5;
		wxButton* m_button179211;
		wxButton* m_button180211;
		wxButton* m_button181211;
		wxButton* m_button182211;
		wxTextCtrl* m_sample_name5;
		wxStaticText* m_staticText1126;
		wxTextCtrl* m_sample_words6;
		wxTextCtrl* m_sample_rate6;
		wxButton* m_button1792111;
		wxButton* m_button1802111;
		wxButton* m_button1812111;
		wxButton* m_button1822111;
		wxTextCtrl* m_sample_name6;
		wxStaticText* m_staticText11261;
		wxTextCtrl* m_sample_words7;
		wxTextCtrl* m_sample_rate7;
		wxButton* m_button17921111;
		wxButton* m_button18021111;
		wxButton* m_button18121111;
		wxButton* m_button18221111;
		wxTextCtrl* m_sample_name7;
		wxStaticText* m_staticText112611;
		wxTextCtrl* m_sample_words8;
		wxTextCtrl* m_sample_rate8;
		wxButton* m_button179211111;
		wxButton* m_button180211111;
		wxButton* m_button181211111;
		wxButton* m_button182211111;
		wxTextCtrl* m_sample_name8;
		wxStaticLine* m_staticline13;
		wxStaticText* m_staticText11101;
		wxStaticText* m_staticText267;
		wxGauge* m_b_memory_usage;
		wxTextCtrl* m_b_memory_usage_txt;
		wxStaticText* m_staticText291;
		wxStaticText* m_staticText11173;
		wxTextCtrl* m_sample_words9;
		wxTextCtrl* m_sample_rate9;
		wxButton* m_button1793;
		wxButton* m_button1803;
		wxButton* m_button1813;
		wxButton* m_button1823;
		wxTextCtrl* m_sample_name9;
		wxStaticText* m_staticText111711;
		wxTextCtrl* m_sample_words10;
		wxTextCtrl* m_sample_rate10;
		wxButton* m_button17911;
		wxButton* m_button18011;
		wxButton* m_button18111;
		wxButton* m_button18211;
		wxTextCtrl* m_sample_name10;
		wxStaticText* m_staticText111721;
		wxTextCtrl* m_sample_words11;
		wxTextCtrl* m_sample_rate11;
		wxButton* m_button17922;
		wxButton* m_button18022;
		wxButton* m_button18122;
		wxButton* m_button18222;
		wxTextCtrl* m_sample_name11;
		wxStaticText* m_staticText11251;
		wxTextCtrl* m_sample_words12;
		wxTextCtrl* m_sample_rate12;
		wxButton* m_button179212;
		wxButton* m_button180212;
		wxButton* m_button181212;
		wxButton* m_button182212;
		wxTextCtrl* m_sample_name12;
		wxStaticText* m_staticText11271;
		wxTextCtrl* m_sample_words13;
		wxTextCtrl* m_sample_rate13;
		wxButton* m_button1792112;
		wxButton* m_button1802112;
		wxButton* m_button1812112;
		wxButton* m_button1822112;
		wxTextCtrl* m_sample_name13;
		wxStaticText* m_staticText11262;
		wxTextCtrl* m_sample_words14;
		wxTextCtrl* m_sample_rate14;
		wxButton* m_button17921112;
		wxButton* m_button18021112;
		wxButton* m_button18121112;
		wxButton* m_button18221112;
		wxTextCtrl* m_sample_name14;
		wxStaticText* m_staticText112612;
		wxTextCtrl* m_sample_words15;
		wxTextCtrl* m_sample_rate15;
		wxButton* m_button179211112;
		wxButton* m_button180211112;
		wxButton* m_button181211112;
		wxButton* m_button182211112;
		wxTextCtrl* m_sample_name15;
		wxStaticText* m_staticText1126111;
		wxTextCtrl* m_sample_words16;
		wxTextCtrl* m_sample_rate16;
		wxButton* m_button1792111111;
		wxButton* m_button1802111111;
		wxButton* m_button1812111111;
		wxButton* m_button1822111111;
		wxTextCtrl* m_sample_name16;
		wxStaticLine* m_staticline131;
		wxButton* m_button106;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnPlay1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDelete1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoad1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNameChange1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPlay2( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDelete2( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoad2( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave2( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNameChange2( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPlay3( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDelete3( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoad3( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave3( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNameChange3( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPlay4( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDelete4( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoad4( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave4( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNameChange4( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPlay5( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDelete5( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoad5( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave5( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNameChange5( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPlay6( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDelete6( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoad6( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave6( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNameChange6( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPlay7( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDelete7( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoad7( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave7( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNameChange7( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPlay8( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDelete8( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoad8( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave8( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNameChange8( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPlay9( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDelete9( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoad9( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave9( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNameChange9( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPlay10( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDelete10( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoad10( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave10( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNameChange10( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPlay11( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDelete11( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoad11( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave11( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNameChange11( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPlay12( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDelete12( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoad12( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave12( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNameChange12( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPlay13( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDelete13( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoad13( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave13( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNameChange13( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPlay14( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDelete14( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoad14( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave14( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNameChange14( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPlay15( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDelete15( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoad15( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave15( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNameChange15( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPlay16( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDelete16( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoad16( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave16( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNameChange16( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveAll( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		SamplesPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 960,553 ), long style = wxTAB_TRAVERSAL ); 
		~SamplesPanel();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class SoundLoopPanel
///////////////////////////////////////////////////////////////////////////////
class SoundLoopPanel : public wxPanel 
{
	private:
	
	protected:
		wxPanel* m_wavedisp_panel;
		wxMenu* m_menu161;
		WaveDisp *m_wave_disp;
		wxPanel* m_panel811;
		wxStaticText* m_staticText6022;
		wxSpinCtrl* m_start_point;
		wxButton* m_button23;
		wxButton* m_button33;
		wxButton* m_button43;
		wxButton* m_button53;
		wxStaticText* m_staticText6032;
		wxSpinCtrl* m_sustainloop_start;
		wxButton* m_button212;
		wxButton* m_button313;
		wxButton* m_button413;
		wxButton* m_button513;
		wxStaticText* m_staticText6042;
		wxSpinCtrl* m_releaseloop_start;
		wxButton* m_button2113;
		wxButton* m_button3112;
		wxButton* m_button4112;
		wxButton* m_button5112;
		wxStaticText* m_staticText60211;
		wxSpinCtrl* m_end_point;
		wxButton* m_button221;
		wxButton* m_button321;
		wxButton* m_button421;
		wxButton* m_button521;
		wxStaticText* m_staticText60311;
		wxSpinCtrl* m_sustainloop_end;
		wxButton* m_button21111;
		wxButton* m_button3121;
		wxButton* m_button4121;
		wxButton* m_button5121;
		wxStaticText* m_staticText60411;
		wxSpinCtrl* m_releaseloop_end;
		wxButton* m_button21121;
		wxButton* m_button31111;
		wxButton* m_button41111;
		wxButton* m_button51111;
		wxMenu* m_menu1611;
		wxPanel* m_panel155;
		wxStaticText* m_staticText6151;
		wxTextCtrl* m_sample_words_txt;
		wxCheckBox* m_sust_loop_ena;
		wxStaticText* m_staticText1192;
		wxTextCtrl* m_sample_rate;
		wxCheckBox* m_reverse_ena;
		wxToggleButton* m_play_button;
		wxStaticText* m_staticText1194;
		wxCheckBox* m_forward_loop_ena;
		wxStaticText* m_staticText280;
		wxOwnerDrawnComboBox* m_wave_selection;
		wxCheckBox* m_release_loop_ena;
		wxStaticText* m_staticText6221;
		wxSlider* m_velocity_start_point;
		wxStaticText* m_staticText6241;
		wxSlider* m_tune_table;
		wxMenu* m_menu1612;
		wxMenu* m_menu16111;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnLoad( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnGetSound( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnGetSoundParam( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCopy( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCopyParamToAll( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDeleteSound( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnImport( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExport( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPurge( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStartPoint( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnMoveStartPointBackward10( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMoveStartPointBackward1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMoveStartPointForward1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMoveStartPointForward10( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSustainLoopStart( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnMoveSustainStartPointBackward10( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMoveSustainStartPointBackward1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMoveSustainStartPointForward1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMoveSustainStartPointForward10( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnReleaseLoopStart( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnMoveReleaseStartPointBackward10( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMoveReleaseStartPointBackward1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMoveReleaseStartPointForward1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMoveReleaseStartPointForward10( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEndPoint( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnMoveEndPointBackward10( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMoveEndPointBackward1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMoveEndPointForward1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMoveEndPointForward10( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSustainLoopEnd( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnMoveSustainEndPointBackward10( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMoveSustainEndPointBackward1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMoveSustainEndPointForward1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMoveSustainEndPointForward10( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnReleaseLoopEnd( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnMoveReleaseEndPointBackward10( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMoveReleaseEndPointBackward1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMoveReleaseEndPointForward1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMoveReleaseEndPointForward10( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSustLoopChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCheckboxChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPlay( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnForwardLoopChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnWaveSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSliderChange( wxScrollEvent& event ) { event.Skip(); }
		
	
	public:
		
		SoundLoopPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 970,410 ), long style = wxTAB_TRAVERSAL ); 
		~SoundLoopPanel();
		
		void m_wavedisp_panelOnContextMenu( wxMouseEvent &event )
		{
			m_wavedisp_panel->PopupMenu( m_menu161, event.GetPosition() );
		}
		
		void m_panel811OnContextMenu( wxMouseEvent &event )
		{
			m_panel811->PopupMenu( m_menu1611, event.GetPosition() );
		}
		
		void m_panel155OnContextMenu( wxMouseEvent &event )
		{
			m_panel155->PopupMenu( m_menu1612, event.GetPosition() );
		}
		
		void SoundLoopPanelOnContextMenu( wxMouseEvent &event )
		{
			this->PopupMenu( m_menu16111, event.GetPosition() );
		}
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class SoundSamplePanel
///////////////////////////////////////////////////////////////////////////////
class SoundSamplePanel : public wxPanel 
{
	private:
	
	protected:
		wxPanel* m_panel66;
		wxStaticText* m_staticText463;
		wxStaticText* m_staticText471;
		wxStaticText* m_staticText488;
		wxStaticText* m_staticText489;
		wxStaticText* m_staticText472;
		wxTextCtrl* m_begin_addr;
		wxStaticText* m_staticText464;
		wxTextCtrl* m_start_point_addr;
		wxStaticText* m_staticText465;
		wxTextCtrl* m_sustain_loop_start_addr;
		wxStaticText* m_staticText466;
		wxTextCtrl* m_sustain_loop_end_addr;
		wxStaticText* m_staticText467;
		wxTextCtrl* m_release_loop_start_addr;
		wxStaticText* m_staticText468;
		wxTextCtrl* m_release_loop_end_addr;
		wxStaticText* m_staticText469;
		wxTextCtrl* m_end_point_addr;
		wxStaticText* m_staticText470;
		wxTextCtrl* m_finish_addr;
		wxMenu* m_menu1611;
		wxPanel* m_panel68;
		wxStaticText* m_staticText494;
		wxStaticText* m_staticText495;
		wxStaticText* m_staticText496;
		wxStaticText* m_staticText497;
		wxStaticText* m_staticText498;
		wxSlider* m_velocity_start_point;
		wxStaticText* m_staticText499;
		wxSlider* m_tune_table;
		wxStaticText* m_staticText504;
		wxStaticText* m_staticText505;
		wxStaticText* m_staticText500;
		wxTextCtrl* m_root_key;
		wxStaticText* m_staticText501;
		wxTextCtrl* m_sample_rate;
		wxCheckBox* m_sample_deleted;
		wxStaticText* m_staticText502;
		wxCheckBox* m_sampled;
		wxStaticText* m_staticText503;
		wxMenu* m_menu1612;
		wxPanel* m_panel67;
		wxStaticText* m_staticText473;
		wxStaticText* m_staticText474;
		wxStaticText* m_staticText475;
		wxStaticText* m_staticText476;
		wxStaticText* m_staticText490;
		wxStaticText* m_staticText491;
		wxStaticText* m_staticText492;
		wxStaticText* m_staticText493;
		wxStaticText* relative_mix_map1_txt;
		wxTextCtrl* m_hi_key_map1;
		wxTextCtrl* m_transpose_map1;
		wxSpinCtrl* m_relative_mix_map1;
		wxStaticText* relative_mix_map2_txt;
		wxTextCtrl* m_hi_key_map2;
		wxTextCtrl* m_transpose_map2;
		wxSpinCtrl* m_relative_mix_map2;
		wxStaticText* relative_mix_map3_txt;
		wxTextCtrl* m_hi_key_map3;
		wxTextCtrl* m_transpose_map3;
		wxSpinCtrl* m_relative_mix_map3;
		wxStaticText* relative_mix_map4_txt;
		wxTextCtrl* m_hi_key_map4;
		wxTextCtrl* m_transpose_map4;
		wxSpinCtrl* m_relative_mix_map4;
		wxStaticText* relative_mix_map5_txt;
		wxTextCtrl* m_hi_key_map5;
		wxTextCtrl* m_transpose_map5;
		wxSpinCtrl* m_relative_mix_map5;
		wxStaticText* relative_mix_map6_txt;
		wxTextCtrl* m_hi_key_map6;
		wxTextCtrl* m_transpose_map6;
		wxSpinCtrl* m_relative_mix_map6;
		wxStaticText* relative_mix_map7_txt;
		wxTextCtrl* m_hi_key_map7;
		wxTextCtrl* m_transpose_map7;
		wxSpinCtrl* m_relative_mix_map7;
		wxStaticText* relative_mix_map8_txt;
		wxTextCtrl* m_hi_key_map8;
		wxTextCtrl* m_transpose_map8;
		wxSpinCtrl* m_relative_mix_map8;
		wxMenu* m_menu161;
		wxStaticText* m_staticText281;
		wxPanel* m_panel62;
		wxStaticText* m_staticText276;
		wxStaticText* m_staticText277;
		wxStaticText* m_staticText290;
		wxStaticText* m_staticText291;
		wxToggleButton* m_used_in_map1;
		wxToggleButton* m_used_in_map2;
		wxToggleButton* m_used_in_map3;
		wxToggleButton* m_used_in_map4;
		wxToggleButton* m_used_in_map5;
		wxToggleButton* m_used_in_map6;
		wxToggleButton* m_used_in_map7;
		wxToggleButton* m_used_in_map8;
		wxMenu* m_menu1613;
		wxMenu* m_menu16111;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnLoad( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnGetSound( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnGetSoundParam( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCopy( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCopyParamToAll( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDeleteSound( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnImport( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExport( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPurge( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnRootKey( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCheckboxChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHighKey1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSpinChange( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnHighKey2( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHighKey3( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHighKey4( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHighKey5( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHighKey6( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHighKey7( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnHighKey8( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsedInMap1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsedInMap2( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsedInMap3( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsedInMap4( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsedInMap5( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsedInMap6( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsedInMap7( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsedInMap8( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		SoundSamplePanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 970,410 ), long style = wxTAB_TRAVERSAL ); 
		~SoundSamplePanel();
		
		void m_panel66OnContextMenu( wxMouseEvent &event )
		{
			m_panel66->PopupMenu( m_menu1611, event.GetPosition() );
		}
		
		void m_panel68OnContextMenu( wxMouseEvent &event )
		{
			m_panel68->PopupMenu( m_menu1612, event.GetPosition() );
		}
		
		void m_panel67OnContextMenu( wxMouseEvent &event )
		{
			m_panel67->PopupMenu( m_menu161, event.GetPosition() );
		}
		
		void m_panel62OnContextMenu( wxMouseEvent &event )
		{
			m_panel62->PopupMenu( m_menu1613, event.GetPosition() );
		}
		
		void SoundSamplePanelOnContextMenu( wxMouseEvent &event )
		{
			this->PopupMenu( m_menu16111, event.GetPosition() );
		}
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class SoundSynthPanel
///////////////////////////////////////////////////////////////////////////////
class SoundSynthPanel : public wxPanel 
{
	private:
	
	protected:
		wxPanel* m_vca_env_panel;
		EnvDisp *m_vca_env_disp;
		wxMenu* m_menu1612;
		wxPanel* m_vcf_env_panel;
		EnvDisp *m_vcf_env_disp;
		wxMenu* m_menu1613;
		wxPanel* m_panel64111;
		wxStaticText* m_staticText235111;
		wxStaticText* m_staticText234111;
		wxStaticText* m_staticText238111;
		wxStaticText* m_staticText239111;
		wxSlider* m_attack_vel_sensitivity;
		wxSlider* m_release_vel_sensitivity;
		wxSlider* m_amp_peak_vel_sensitivity;
		wxSlider* m_filt_peak_vel_sensitivity;
		wxStaticText* m_staticText247111;
		wxStaticText* m_staticText248111;
		wxStaticText* m_staticText246111;
		wxStaticText* m_staticText249111;
		wxTextCtrl* m_attack_vel_sensitivity_val;
		wxTextCtrl* m_release_vel_sensitivity_val;
		wxTextCtrl* m_amp_peak_vel_sensitivity_val;
		wxTextCtrl* m_filt_peak_vel_sensitivity_val;
		wxMenu* m_menu161;
		wxPanel* m_panel62;
		wxStaticText* m_staticText279;
		wxStaticText* m_staticText280;
		wxStaticText* m_staticText2901;
		wxStaticText* m_staticText291;
		wxToggleButton* m_used_in_map1;
		wxToggleButton* m_used_in_map2;
		wxToggleButton* m_used_in_map3;
		wxToggleButton* m_used_in_map4;
		wxToggleButton* m_used_in_map5;
		wxToggleButton* m_used_in_map6;
		wxToggleButton* m_used_in_map7;
		wxToggleButton* m_used_in_map8;
		wxMenu* m_menu1614;
		wxPanel* m_panel59;
		wxStaticText* m_staticText235;
		wxStaticText* m_staticText234;
		wxStaticText* m_staticText238;
		wxStaticText* m_staticText239;
		wxStaticText* m_staticText240;
		wxSlider* m_amp_attack_rate;
		wxSlider* m_amp_decay_rate;
		wxSlider* m_amp_sustain_level;
		wxSlider* m_amp_release;
		wxSlider* m_amp_2nd_release;
		wxStaticText* m_staticText246;
		wxStaticText* m_staticText247;
		wxStaticText* m_staticText248;
		wxStaticText* m_staticText249;
		wxStaticText* m_staticText250;
		wxTextCtrl* m_amp_attack_rate_val;
		wxTextCtrl* m_amp_decay_rate_val;
		wxTextCtrl* m_amp_sustain_level_val;
		wxTextCtrl* m_amp_release_val;
		wxTextCtrl* m_amp_2nd_release_val;
		wxMenu* m_menu1615;
		wxPanel* m_panel641;
		wxStaticText* m_staticText2351;
		wxStaticText* m_staticText2341;
		wxStaticText* m_staticText2381;
		wxStaticText* m_staticText2391;
		wxStaticText* m_staticText2401;
		wxSlider* m_filt_attack_rate;
		wxSlider* m_filt_decay_rate;
		wxSlider* m_filt_sustain_level;
		wxSlider* m_filt_release_rate;
		wxSlider* m_filt_2nd_release_rate;
		wxStaticText* m_staticText2461;
		wxStaticText* m_staticText2471;
		wxStaticText* m_staticText2481;
		wxStaticText* m_staticText2491;
		wxStaticText* m_staticText2501;
		wxTextCtrl* m_filt_attack_rate_val;
		wxTextCtrl* m_filt_decay_rate_val;
		wxTextCtrl* m_filt_sustain_level_val;
		wxTextCtrl* m_filt_release_rate_val;
		wxTextCtrl* m_filt_2nd_release_rate_val;
		wxMenu* m_menu1616;
		wxPanel* m_panel6411;
		wxStaticText* m_staticText23511;
		wxStaticText* m_staticText23811;
		wxStaticText* m_staticText23911;
		wxStaticText* m_staticText23411;
		wxSlider* m_filt_cutoff;
		wxSlider* m_filt_resonance;
		wxSlider* m_filt_env_amount;
		wxSlider* m_filt_key_tracking;
		wxStaticText* m_staticText24611;
		wxStaticText* m_staticText24711;
		wxStaticText* m_staticText24811;
		wxStaticText* m_staticText24911;
		wxTextCtrl* m_filt_cutoff_val;
		wxTextCtrl* m_filt_resonance_val;
		wxTextCtrl* m_filt_env_amount_val;
		wxTextCtrl* m_filt_key_tracking_val;
		wxMenu* m_menu1617;
		wxMenu* m_menu1611;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnLoad( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnGetSound( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnGetSoundParam( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCopy( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCopyParamToAll( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDeleteSound( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnImport( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExport( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPurge( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLeftDown( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnVelocityAttackSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnVelocityReleaseSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnVelocityVCAPeakSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnVelocityVFCPeakSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnUsedInMap1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsedInMap2( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsedInMap3( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsedInMap4( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsedInMap5( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsedInMap6( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsedInMap7( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsedInMap8( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAmpAttackSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnAmpDecaySliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnAmpSustainSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnAmpReleaseSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnAmpAltReleaseSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnFilterAttackSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnFilterDecaySliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnFilterSustainSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnFilterReleaseSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnFilterAltReleaseSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnFilterCutoffSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnFilterResonanceSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnFilterEnvelopeAmountSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnFilterKeyboardTrackSliderChange( wxScrollEvent& event ) { event.Skip(); }
		
	
	public:
		
		SoundSynthPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 970,410 ), long style = wxTAB_TRAVERSAL ); 
		~SoundSynthPanel();
		
		void m_vca_env_panelOnContextMenu( wxMouseEvent &event )
		{
			m_vca_env_panel->PopupMenu( m_menu1612, event.GetPosition() );
		}
		
		void m_vcf_env_panelOnContextMenu( wxMouseEvent &event )
		{
			m_vcf_env_panel->PopupMenu( m_menu1613, event.GetPosition() );
		}
		
		void m_panel64111OnContextMenu( wxMouseEvent &event )
		{
			m_panel64111->PopupMenu( m_menu161, event.GetPosition() );
		}
		
		void m_panel62OnContextMenu( wxMouseEvent &event )
		{
			m_panel62->PopupMenu( m_menu1614, event.GetPosition() );
		}
		
		void m_panel59OnContextMenu( wxMouseEvent &event )
		{
			m_panel59->PopupMenu( m_menu1615, event.GetPosition() );
		}
		
		void m_panel641OnContextMenu( wxMouseEvent &event )
		{
			m_panel641->PopupMenu( m_menu1616, event.GetPosition() );
		}
		
		void m_panel6411OnContextMenu( wxMouseEvent &event )
		{
			m_panel6411->PopupMenu( m_menu1617, event.GetPosition() );
		}
		
		void SoundSynthPanelOnContextMenu( wxMouseEvent &event )
		{
			this->PopupMenu( m_menu1611, event.GetPosition() );
		}
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MapPanel
///////////////////////////////////////////////////////////////////////////////
class MapPanel : public wxPanel 
{
	private:
	
	protected:
		wxToggleButton* m_select_map_1;
		wxToggleButton* m_select_map_2;
		wxToggleButton* m_select_map_3;
		wxToggleButton* m_select_map_4;
		wxToggleButton* m_select_map_5;
		wxToggleButton* m_select_map_6;
		wxToggleButton* m_select_map_7;
		wxToggleButton* m_select_map_8;
		wxStaticLine* m_staticline18;
		wxToggleButton* m_select_map_9;
		wxToggleButton* m_select_map_10;
		wxToggleButton* m_select_map_11;
		wxToggleButton* m_select_map_12;
		wxToggleButton* m_select_map_13;
		wxToggleButton* m_select_map_14;
		wxToggleButton* m_select_map_15;
		wxToggleButton* m_select_map_16;
		wxPanel* m_vca_env_panel;
		EnvDisp *m_vca_env_disp;
		wxPanel* m_vcf_env_panel;
		EnvDisp *m_vcf_env_disp;
		wxPanel* m_panel64111;
		wxStaticText* m_staticText234111;
		wxStaticText* m_staticText238111;
		wxStaticText* m_staticText239111;
		wxStaticText* m_staticText283;
		wxStaticLine* m_staticline1;
		wxCheckBox* m_sound_direction_reversed;
		wxSlider* m_attack_vel_sensitivity;
		wxSlider* m_release_vel_sensitivity;
		wxSlider* m_amp_peak_vel_sensitivity;
		wxSlider* m_filt_peak_vel_sensitivity;
		wxStaticLine* m_staticline7;
		wxSlider* m_velocity_start_point;
		wxStaticText* m_staticText247111;
		wxStaticText* m_staticText248111;
		wxStaticText* m_staticText246111;
		wxStaticText* m_staticText249111;
		wxStaticText* m_staticText284;
		wxStaticText* m_staticText250111;
		wxTextCtrl* m_attack_vel_sensitivity_percentage;
		wxTextCtrl* m_release_vel_sensitivity_percentage;
		wxTextCtrl* m_amp_peak_vel_sensitivity_percentage;
		wxTextCtrl* m_filt_peak_vel_sensitivity_percentage;
		wxStaticText* m_staticText285;
		wxTextCtrl* m_velocity_start_point_percentage;
		wxMenu* m_menu74;
		wxPanel* m_panel59;
		wxStaticText* m_staticText235;
		wxStaticText* m_staticText234;
		wxStaticText* m_staticText238;
		wxStaticText* m_staticText239;
		wxStaticText* m_staticText240;
		wxSlider* m_amp_attack_rate;
		wxSlider* m_amp_decay_rate;
		wxSlider* m_amp_sustain_level;
		wxSlider* m_amp_release_rate;
		wxSlider* m_amp_2nd_release_rate;
		wxStaticText* m_staticText246;
		wxStaticText* m_staticText247;
		wxStaticText* m_staticText248;
		wxStaticText* m_staticText249;
		wxStaticText* m_staticText250;
		wxTextCtrl* m_amp_attack_rate_percentage;
		wxTextCtrl* m_amp_decay_rate_percentage;
		wxTextCtrl* m_amp_sustain_level_percentage;
		wxTextCtrl* m_amp_release_rate_percentage;
		wxTextCtrl* m_amp_2nd_release_rate_percentage;
		wxMenu* m_menu71;
		wxPanel* m_panel641;
		wxStaticText* m_staticText2351;
		wxStaticText* m_staticText2341;
		wxStaticText* m_staticText2381;
		wxStaticText* m_staticText2391;
		wxStaticText* m_staticText2401;
		wxSlider* m_filt_attack_rate;
		wxSlider* m_filt_decay_rate;
		wxSlider* m_filt_sustain_level;
		wxSlider* m_filt_release_rate;
		wxSlider* m_filt_2nd_release_rate;
		wxStaticText* m_staticText2461;
		wxStaticText* m_staticText2471;
		wxStaticText* m_staticText2481;
		wxStaticText* m_staticText2491;
		wxStaticText* m_staticText2501;
		wxTextCtrl* m_filt_attack_rate_percentage;
		wxTextCtrl* m_filt_decay_rate_percentage;
		wxTextCtrl* m_filt_sustain_level_percentage;
		wxTextCtrl* m_filt_release_rate_percentage;
		wxTextCtrl* m_filt_2nd_release_rate_percentage;
		wxMenu* m_menu72;
		wxPanel* m_panel6411;
		wxPanel* m_panel40;
		wxMenu* m_menu7211;
		wxPanel* m_panel41;
		wxStaticText* m_staticText293;
		wxStaticText* m_staticText23811;
		wxStaticText* m_staticText23911;
		wxSlider* m_filt_cutoff;
		wxSlider* m_filt_resonance;
		wxSlider* m_filt_env_amount;
		wxSlider* m_filt_keyboard_tracking;
		wxStaticText* m_staticText24611;
		wxStaticText* m_staticText24711;
		wxStaticText* m_staticText24811;
		wxStaticText* m_staticText24911;
		wxTextCtrl* m_filt_cutoff_percentage;
		wxTextCtrl* m_filt_resonance_percentage;
		wxTextCtrl* m_filt_env_amount_percentage;
		wxTextCtrl* m_filt_keyboard_tracking_percentage;
		wxMenu* m_menu72111;
		wxStaticText* m_staticText289;
		wxStaticText* m_staticText288;
		wxToggleButton* m_using_snd_1;
		wxToggleButton* m_using_snd_2;
		wxToggleButton* m_using_snd_3;
		wxToggleButton* m_using_snd_4;
		wxToggleButton* m_using_snd_5;
		wxToggleButton* m_using_snd_6;
		wxToggleButton* m_using_snd_7;
		wxToggleButton* m_using_snd_8;
		wxMenu* m_menu721;
		wxMenu* m_menu7;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSelectMap1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectMap2( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectMap3( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectMap4( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectMap5( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectMap6( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectMap7( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectMap8( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectMap9( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectMap10( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectMap11( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectMap12( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectMap13( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectMap14( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectMap15( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectMap16( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLeftDown( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnCheckboxChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnVelocityAttackSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnVelocityReleaseSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnVelocityVCAPeakSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnVelocityVFCPeakSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnVelocitySampleStartSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnLoad( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCopy( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAmpAttackSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnAmpDecaySliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnAmpSustainSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnAmpReleaseSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnAmpAltReleaseSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnFilterAttackSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnFilterDecaySliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnFilterSustainSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnFilterReleaseSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnFilterAltReleaseSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnFilterCutoffSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnFilterResonanceSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnFilterEnvelopeAmountSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnFilterKeyboardTrackSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnUsingSound1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsingSound2( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsingSound3( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsingSound4( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsingSound5( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsingSound6( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsingSound7( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsingSound8( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MapPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 980,452 ), long style = wxTAB_TRAVERSAL ); 
		~MapPanel();
		
		void m_panel64111OnContextMenu( wxMouseEvent &event )
		{
			m_panel64111->PopupMenu( m_menu74, event.GetPosition() );
		}
		
		void m_panel59OnContextMenu( wxMouseEvent &event )
		{
			m_panel59->PopupMenu( m_menu71, event.GetPosition() );
		}
		
		void m_panel641OnContextMenu( wxMouseEvent &event )
		{
			m_panel641->PopupMenu( m_menu72, event.GetPosition() );
		}
		
		void m_panel40OnContextMenu( wxMouseEvent &event )
		{
			m_panel40->PopupMenu( m_menu7211, event.GetPosition() );
		}
		
		void m_panel41OnContextMenu( wxMouseEvent &event )
		{
			m_panel41->PopupMenu( m_menu72111, event.GetPosition() );
		}
		
		void m_panel6411OnContextMenu( wxMouseEvent &event )
		{
			m_panel6411->PopupMenu( m_menu721, event.GetPosition() );
		}
		
		void MapPanelOnContextMenu( wxMouseEvent &event )
		{
			this->PopupMenu( m_menu7, event.GetPosition() );
		}
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class PresetPanel
///////////////////////////////////////////////////////////////////////////////
class PresetPanel : public wxPanel 
{
	private:
	
	protected:
		wxMenu* m_menu2;
		wxToggleButton* m_select_preset1;
		wxToggleButton* m_select_preset2;
		wxToggleButton* m_select_preset3;
		wxToggleButton* m_select_preset4;
		wxToggleButton* m_select_preset5;
		wxToggleButton* m_select_preset6;
		wxToggleButton* m_select_preset7;
		wxToggleButton* m_select_preset8;
		wxToggleButton* m_select_preset9;
		wxToggleButton* m_select_preset10;
		wxToggleButton* m_select_preset11;
		wxToggleButton* m_select_preset12;
		wxPanel* m_panel7611;
		wxStaticText* m_staticText1121;
		wxStaticText* m_staticText11121;
		wxStaticText* m_staticText111111;
		wxStaticText* m_staticText711;
		wxSlider* m_lfo_freq;
		wxSlider* m_lfo_init_amount;
		wxSlider* m_lfo_vel_sensitivity;
		wxStaticText* m_staticText1221;
		wxStaticText* m_staticText12121;
		wxStaticText* m_staticText121111;
		wxStaticText* m_staticText911;
		wxChoice* m_vibrato;
		wxChoice* m_lfo_filt;
		wxChoice* m_lfo_amp;
		wxMenu* m_menu21;
		wxPanel* m_panel764;
		wxStaticText* m_staticText651;
		wxStaticText* m_staticText661;
		wxStaticText* m_staticText671;
		wxStaticText* m_staticText681;
		wxStaticText* m_staticText692;
		wxChoice* m_left_map_selection;
		wxStaticText* m_staticText6911;
		wxChoice* m_keyboard_mode;
		wxStaticText* m_staticText6931;
		wxChoice* m_right_map_selection;
		wxStaticText* m_staticText6941;
		wxTextCtrl* m_split_point;
		wxStaticText* m_staticText6951;
		wxSlider* m_transpose;
		wxStaticText* m_staticText6981;
		wxCheckBox* m_dyn_alloc;
		wxStaticText* m_staticText69511;
		wxSlider* m_vel_switch_threshold;
		wxStaticText* m_staticText695112;
		wxSlider* m_pitchwheel_range;
		wxMenu* m_menu22;
		wxPanel* m_panel25;
		wxStaticText* m_staticText45;
		wxStaticText* m_staticText279;
		wxChoice* m_stack_voices;
		wxCheckBox* m_stack_voices_preset_on;
		wxStaticText* m_staticText280;
		wxSlider* m_stack_delay;
		wxStaticText* m_staticText281;
		wxSlider* m_stack_detune;
		wxMenu* m_menu23;
		wxPanel* m_panel26;
		wxStaticText* m_staticText4461;
		wxStaticText* m_staticText4466;
		wxStaticText* m_staticText44661;
		wxStaticText* m_staticText86;
		wxStaticText* m_staticText443;
		wxChoice* m_arp_mode;
		wxChoice* m_arp_oct;
		wxChoice* m_arp_repeats;
		wxChoice* m_arp_latch_mode;
		wxStaticText* m_staticText4462;
		wxStaticText* m_staticText44651;
		wxStaticText* m_staticText446611;
		wxStaticText* m_staticText4411;
		wxTextCtrl* m_arp_split_point;
		wxChoice* m_arp_split_type;
		wxSlider* m_arp_rate;
		wxCheckBox* m_arp_preset_on;
		wxMenu* m_menu24;
		wxPanel* m_panel27;
		wxStaticText* m_staticText1012;
		wxStaticText* m_staticText102;
		wxStaticText* m_staticText103;
		wxStaticText* m_staticText108;
		wxChoice* m_midi_left_ch;
		wxCheckBox* m_rx_mod_wheel;
		wxCheckBox* m_tx_mod_wheel;
		wxStaticText* m_staticText111;
		wxChoice* m_midi_right_ch;
		wxCheckBox* m_rx_pitch_wheel;
		wxCheckBox* m_tx_pitch_wheel;
		wxStaticText* m_staticText109;
		wxChoice* m_midi_mode;
		wxCheckBox* m_rx_program_chg;
		wxCheckBox* m_tx_program_chg;
		wxStaticText* m_staticText101213;
		wxStaticText* m_staticText1122;
		wxCheckBox* m_rx_pressure_as_mod_wheel;
		wxCheckBox* m_tx_mod_wheel_as_pressure;
		wxMenu* m_menu25;
		wxPanel* m_panel41;
		wxToggleButton* m_left_map_selector;
		wxToggleButton* m_using_snd_1;
		wxToggleButton* m_using_snd_2;
		wxToggleButton* m_using_snd_3;
		wxToggleButton* m_using_snd_4;
		wxToggleButton* m_using_snd_5;
		wxToggleButton* m_using_snd_6;
		wxToggleButton* m_using_snd_7;
		wxToggleButton* m_using_snd_8;
		wxPanel* m_panel42;
		wxToggleButton* m_right_map_selector;
		wxToggleButton* m_using_snd_9;
		wxToggleButton* m_using_snd_10;
		wxToggleButton* m_using_snd_11;
		wxToggleButton* m_using_snd_12;
		wxToggleButton* m_using_snd_13;
		wxToggleButton* m_using_snd_14;
		wxToggleButton* m_using_snd_15;
		wxToggleButton* m_using_snd_16;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnLoad( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCopy( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectPreset1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectPreset2( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectPreset3( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectPreset4( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectPreset5( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectPreset6( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectPreset7( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectPreset8( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectPreset9( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectPreset10( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectPreset11( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectPreset12( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLFOFreqSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnLFOInitAmountSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnLFOVelocitySliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnComboChanged( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLeftMapSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRightMapSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSplitPoint( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnKeyboardTransposeSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnCheckboxChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnKeyboardVelocitySwitchSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnPitchwheelSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnStackDelaySliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnStackDetuneSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnArpSplitPoint( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnArpRateSliderChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void OnLeftMapSelector( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsingSound1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsingSound2( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsingSound3( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsingSound4( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsingSound5( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsingSound6( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsingSound7( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsingSound8( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRightMapSelector( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsingSound9( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsingSound10( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsingSound11( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsingSound12( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsingSound13( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsingSound14( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsingSound15( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUsingSound16( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		PresetPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 980,450 ), long style = wxTAB_TRAVERSAL ); 
		~PresetPanel();
		
		void PresetPanelOnContextMenu( wxMouseEvent &event )
		{
			this->PopupMenu( m_menu2, event.GetPosition() );
		}
		
		void m_panel7611OnContextMenu( wxMouseEvent &event )
		{
			m_panel7611->PopupMenu( m_menu21, event.GetPosition() );
		}
		
		void m_panel764OnContextMenu( wxMouseEvent &event )
		{
			m_panel764->PopupMenu( m_menu22, event.GetPosition() );
		}
		
		void m_panel25OnContextMenu( wxMouseEvent &event )
		{
			m_panel25->PopupMenu( m_menu23, event.GetPosition() );
		}
		
		void m_panel26OnContextMenu( wxMouseEvent &event )
		{
			m_panel26->PopupMenu( m_menu24, event.GetPosition() );
		}
		
		void m_panel27OnContextMenu( wxMouseEvent &event )
		{
			m_panel27->PopupMenu( m_menu25, event.GetPosition() );
		}
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MapScaledValuesDialog
///////////////////////////////////////////////////////////////////////////////
class MapScaledValuesDialog : public wxDialog 
{
	private:
	
	protected:
		wxPanel* m_panel64111;
		wxStaticText* m_staticText235111;
		wxStaticText* m_staticText234111;
		wxStaticText* m_staticText238111;
		wxStaticText* m_staticText239111;
		wxStaticText* m_staticText230;
		wxStaticText* m_staticText247111;
		wxStaticText* m_staticText248111;
		wxStaticText* m_staticText246111;
		wxStaticText* m_staticText249111;
		wxStaticText* m_staticText229;
		wxTextCtrl* m_attack_vel_sensitivity;
		wxTextCtrl* m_release_vel_sensitivity;
		wxTextCtrl* m_amp_peak_vel_sensitivity;
		wxTextCtrl* m_filt_peak_vel_sensitivity;
		wxTextCtrl* m_velocity_start_point;
		wxPanel* m_panel6411;
		wxStaticText* m_staticText23511;
		wxStaticText* m_staticText23811;
		wxStaticText* m_staticText23911;
		wxStaticText* m_staticText23411;
		wxStaticText* m_staticText24611;
		wxStaticText* m_staticText24711;
		wxStaticText* m_staticText24811;
		wxStaticText* m_staticText24911;
		wxTextCtrl* m_filt_cutoff;
		wxTextCtrl* m_filt_resonance;
		wxTextCtrl* m_filt_env_amount;
		wxTextCtrl* m_filt_keyboard_tracking;
		wxPanel* m_vca_env_panel;
		EnvDisp *m_vca_env_disp;
		wxPanel* m_vcf_env_panel;
		EnvDisp *m_vcf_env_disp;
		wxPanel* m_panel59;
		wxStaticText* m_staticText235;
		wxStaticText* m_staticText234;
		wxStaticText* m_staticText238;
		wxStaticText* m_staticText239;
		wxStaticText* m_staticText240;
		wxStaticText* m_staticText246;
		wxStaticText* m_staticText247;
		wxStaticText* m_staticText248;
		wxStaticText* m_staticText249;
		wxStaticText* m_staticText250;
		wxTextCtrl* m_amp_attack_rate;
		wxTextCtrl* m_amp_decay_rate;
		wxTextCtrl* m_amp_sustain_level;
		wxTextCtrl* m_amp_release_rate;
		wxTextCtrl* m_amp_2nd_release_rate;
		wxPanel* m_panel641;
		wxStaticText* m_staticText2351;
		wxStaticText* m_staticText2341;
		wxStaticText* m_staticText2381;
		wxStaticText* m_staticText2391;
		wxStaticText* m_staticText2401;
		wxStaticText* m_staticText2461;
		wxStaticText* m_staticText2471;
		wxStaticText* m_staticText2481;
		wxStaticText* m_staticText2491;
		wxStaticText* m_staticText2501;
		wxTextCtrl* m_filt_attack_rate;
		wxTextCtrl* m_filt_decay_rate;
		wxTextCtrl* m_filt_sustain_level;
		wxTextCtrl* m_filt_release_rate;
		wxTextCtrl* m_filt_2nd_release_rate;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnLeftDown( wxMouseEvent& event ) { event.Skip(); }
		
	
	public:
		
		MapScaledValuesDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxDOUBLE_BORDER|wxSIMPLE_BORDER ); 
		~MapScaledValuesDialog();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ConfigDlg
///////////////////////////////////////////////////////////////////////////////
class ConfigDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText278;
		wxOwnerDrawnComboBox* m_fontsize;
		wxStaticLine* m_staticline9;
		wxStaticText* m_staticText12701;
		wxOwnerDrawnComboBox* m_audio_device;
		wxStaticLine* m_staticline251;
		wxStaticText* m_staticText1270;
		wxOwnerDrawnComboBox* m_midi_in_device;
		wxStaticText* m_staticText1271;
		wxOwnerDrawnComboBox* m_midi_out_device;
		wxStaticText* m_staticText1272;
		wxSpinCtrl* m_midi_ch;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnFontSize( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAudioDevice( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnInDevice( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOutDevice( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnChannel( wxSpinEvent& event ) { event.Skip(); }
		
	
	public:
		
		ConfigDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Configuration"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 415,394 ), long style = wxDEFAULT_DIALOG_STYLE|wxDOUBLE_BORDER|wxSIMPLE_BORDER ); 
		~ConfigDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class SoundSelectionPanel
///////////////////////////////////////////////////////////////////////////////
class SoundSelectionPanel : public wxPanel 
{
	private:
	
	protected:
		wxToggleButton* m_select_sound1;
		wxToggleButton* m_select_sound2;
		wxToggleButton* m_select_sound3;
		wxToggleButton* m_select_sound4;
		wxToggleButton* m_select_sound5;
		wxToggleButton* m_select_sound6;
		wxToggleButton* m_select_sound7;
		wxToggleButton* m_select_sound8;
		wxStaticLine* m_staticline18;
		wxToggleButton* m_select_sound9;
		wxToggleButton* m_select_sound10;
		wxToggleButton* m_select_sound11;
		wxToggleButton* m_select_sound12;
		wxToggleButton* m_select_sound13;
		wxToggleButton* m_select_sound14;
		wxToggleButton* m_select_sound15;
		wxToggleButton* m_select_sound16;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSelectSound1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectSound2( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectSound3( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectSound4( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectSound5( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectSound6( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectSound7( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectSound8( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectSound9( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectSound10( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectSound11( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectSound12( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectSound13( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectSound14( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectSound15( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectSound16( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		SoundSelectionPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 980,42 ), long style = wxTAB_TRAVERSAL ); 
		~SoundSelectionPanel();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MIDIKeyboardPresetSelection
///////////////////////////////////////////////////////////////////////////////
class MIDIKeyboardPresetSelection : public wxPanel 
{
	private:
	
	protected:
		wxToggleButton* m_select_preset1;
		wxToggleButton* m_select_preset2;
		wxToggleButton* m_select_preset3;
		wxToggleButton* m_select_preset4;
		wxToggleButton* m_select_preset5;
		wxToggleButton* m_select_preset6;
		wxToggleButton* m_select_preset7;
		wxToggleButton* m_select_preset8;
		wxToggleButton* m_select_preset9;
		wxToggleButton* m_select_preset10;
		wxToggleButton* m_select_preset11;
		wxToggleButton* m_select_preset12;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSelectPreset1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectPreset2( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectPreset3( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectPreset4( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectPreset5( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectPreset6( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectPreset7( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectPreset8( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectPreset9( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectPreset10( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectPreset11( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectPreset12( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MIDIKeyboardPresetSelection( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 995,39 ), long style = wxTAB_TRAVERSAL ); 
		~MIDIKeyboardPresetSelection();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class AboutDlg
///////////////////////////////////////////////////////////////////////////////
class AboutDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText265;
		wxStaticText* m_staticText272;
		wxStaticText* m_version_label;
		wxStaticText* m_staticText276;
		wxStaticText* m_build_date_label;
		wxStaticText* m_staticText273;
		wxStaticText* m_staticText267;
		wxStaticText* m_staticText274;
		wxStaticText* m_staticText268;
		wxStaticText* m_staticText275;
		wxHyperlinkCtrl* m_hyperlink1;
		wxStaticText* m_staticText286;
		wxTextCtrl* m_textCtrl125;
		wxStaticText* m_copyright_text;
	
	public:
		
		AboutDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("About"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 327,282 ), long style = wxDEFAULT_DIALOG_STYLE|wxDOUBLE_BORDER ); 
		~AboutDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class SoundCopyDlg
///////////////////////////////////////////////////////////////////////////////
class SoundCopyDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText279;
		wxSpinCtrl* m_destination_number;
		wxCheckBox* m_copy_parameters_only;
		wxStaticText* m_staticText280;
		wxToggleButton* m_toggleBtn58;
		wxToggleButton* m_toggleBtn59;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnOK( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		SoundCopyDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Copy Sound"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE|wxDOUBLE_BORDER ); 
		~SoundCopyDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MapCopyDlg
///////////////////////////////////////////////////////////////////////////////
class MapCopyDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText279;
		wxOwnerDrawnComboBox* m_destination_number;
		wxCheckBox* m_copy_snd_mapping;
		wxStaticText* m_staticText280;
		wxToggleButton* m_toggleBtn58;
		wxToggleButton* m_toggleBtn59;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnDestinationChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOK( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MapCopyDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Copy Map"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE|wxDOUBLE_BORDER ); 
		~MapCopyDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class PresetCopyDlg
///////////////////////////////////////////////////////////////////////////////
class PresetCopyDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText279;
		wxSpinCtrl* m_destination_number;
		wxToggleButton* m_toggleBtn58;
		wxToggleButton* m_toggleBtn59;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnOK( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		PresetCopyDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Copy Preset"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE|wxDOUBLE_BORDER ); 
		~PresetCopyDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class LoadSampleDialog
///////////////////////////////////////////////////////////////////////////////
class LoadSampleDialog : public wxDialog 
{
	private:
	
	protected:
		wxPanel* m_wavedisp_panel;
		WaveDisp *m_wave_disp;
		wxPanel* m_panel47;
		wxRadioBox* m_dest_sample_rate;
		wxStaticText* m_staticText279;
		wxTextCtrl* m_sample_rate_orig_txt;
		wxStaticText* m_staticText280;
		wxTextCtrl* m_sample_words_txt;
		wxStaticText* m_staticText283;
		wxSpinCtrl* m_start_point;
		wxStaticText* m_staticText284;
		wxSpinCtrl* m_end_point;
		wxRadioBox* m_src_channel;
		wxStaticText* m_staticText2831;
		wxOwnerDrawnComboBox* m_selected_sound;
		wxStaticText* m_staticText2841;
		wxTextCtrl* m_rootkey_txt;
		wxPanel* m_panel46;
		wxButton* load_but;
		wxButton* play_but;
		wxButton* import_but;
		wxButton* cancel_but;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnDestSampleRate( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStartPoint( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnEndPoint( wxSpinEvent& event ) { event.Skip(); }
		virtual void OnChannelSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSoundChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLoad( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPlay( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnImport( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		LoadSampleDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Import Sample"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 600,540 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~LoadSampleDialog();
	
};

#endif //__GUILAYOUT_H__
