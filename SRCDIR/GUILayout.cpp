///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct  8 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUILayout.h"

///////////////////////////////////////////////////////////////////////////

SamplesPanel::SamplesPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	wxBoxSizer* bSizer67;
	bSizer67 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer68;
	bSizer68 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1110 = new wxStaticText( this, wxID_ANY, wxT(" Bank A "), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT|wxRAISED_BORDER );
	m_staticText1110->Wrap( -1 );
	m_staticText1110->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	m_staticText1110->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_staticText1110->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer68->Add( m_staticText1110, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText266 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText266->Wrap( -1 );
	bSizer68->Add( m_staticText266, 0, wxALL, 5 );
	
	m_a_memory_usage = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxSize( 820,-1 ), wxGA_HORIZONTAL|wxGA_SMOOTH|wxDOUBLE_BORDER );
	m_a_memory_usage->SetValue( 0 ); 
	bSizer68->Add( m_a_memory_usage, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_a_memory_usage_txt = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CENTRE );
	m_a_memory_usage_txt->SetMaxLength( 0 ); 
	m_a_memory_usage_txt->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	m_a_memory_usage_txt->SetMinSize( wxSize( 40,-1 ) );
	m_a_memory_usage_txt->SetMaxSize( wxSize( 40,-1 ) );
	
	bSizer68->Add( m_a_memory_usage_txt, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP, 5 );
	
	m_staticText292 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText292->Wrap( -1 );
	bSizer68->Add( m_staticText292, 0, wxALL, 5 );
	
	
	bSizer67->Add( bSizer68, 0, wxEXPAND|wxALIGN_RIGHT, 0 );
	
	wxFlexGridSizer* fgSizer139;
	fgSizer139 = new wxFlexGridSizer( 0, 8, 0, 0 );
	fgSizer139->SetFlexibleDirection( wxBOTH );
	fgSizer139->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText1117 = new wxStaticText( this, wxID_ANY, wxT("Sample 1  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1117->Wrap( -1 );
	m_staticText1117->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer139->Add( m_staticText1117, 0, wxALL, 5 );
	
	m_sample_words1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_words1->SetMaxLength( 0 ); 
	fgSizer139->Add( m_sample_words1, 0, wxRIGHT|wxLEFT, 5 );
	
	m_sample_rate1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_rate1->SetMaxLength( 0 ); 
	fgSizer139->Add( m_sample_rate1, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_button179 = new wxButton( this, wxID_ANY, wxT("Play"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button179, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button180 = new wxButton( this, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button180, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button181 = new wxButton( this, wxID_ANY, wxT("Import"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button181, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button182 = new wxButton( this, wxID_ANY, wxT("Export"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button182, 0, wxRIGHT|wxLEFT, 5 );
	
	m_sample_name1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_sample_name1->SetMaxLength( 15 ); 
	fgSizer139->Add( m_sample_name1, 0, wxRIGHT|wxLEFT, 5 );
	
	m_staticText11171 = new wxStaticText( this, wxID_ANY, wxT("Sample 2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11171->Wrap( -1 );
	m_staticText11171->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer139->Add( m_staticText11171, 0, wxALL, 5 );
	
	m_sample_words2 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_words2->SetMaxLength( 0 ); 
	fgSizer139->Add( m_sample_words2, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_sample_rate2 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_rate2->SetMaxLength( 0 ); 
	fgSizer139->Add( m_sample_rate2, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_button1791 = new wxButton( this, wxID_ANY, wxT("Play"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button1791, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button1801 = new wxButton( this, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button1801, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button1811 = new wxButton( this, wxID_ANY, wxT("Import"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button1811, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button1821 = new wxButton( this, wxID_ANY, wxT("Export"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button1821, 0, wxRIGHT|wxLEFT, 5 );
	
	m_sample_name2 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_sample_name2->SetMaxLength( 15 ); 
	fgSizer139->Add( m_sample_name2, 0, wxRIGHT|wxLEFT, 5 );
	
	m_staticText11172 = new wxStaticText( this, wxID_ANY, wxT("Sample 3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11172->Wrap( -1 );
	m_staticText11172->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer139->Add( m_staticText11172, 0, wxALL, 5 );
	
	m_sample_words3 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_words3->SetMaxLength( 0 ); 
	fgSizer139->Add( m_sample_words3, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_sample_rate3 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_rate3->SetMaxLength( 0 ); 
	fgSizer139->Add( m_sample_rate3, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_button1792 = new wxButton( this, wxID_ANY, wxT("Play"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button1792, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );
	
	m_button1802 = new wxButton( this, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button1802, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button1812 = new wxButton( this, wxID_ANY, wxT("Import"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button1812, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button1822 = new wxButton( this, wxID_ANY, wxT("Export"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button1822, 0, wxRIGHT|wxLEFT, 5 );
	
	m_sample_name3 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_sample_name3->SetMaxLength( 15 ); 
	fgSizer139->Add( m_sample_name3, 0, wxRIGHT|wxLEFT, 5 );
	
	m_staticText1125 = new wxStaticText( this, wxID_ANY, wxT("Sample 4"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1125->Wrap( -1 );
	m_staticText1125->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer139->Add( m_staticText1125, 0, wxALL, 5 );
	
	m_sample_words4 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_words4->SetMaxLength( 0 ); 
	fgSizer139->Add( m_sample_words4, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_sample_rate4 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_rate4->SetMaxLength( 0 ); 
	fgSizer139->Add( m_sample_rate4, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_button17921 = new wxButton( this, wxID_ANY, wxT("Play"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button17921, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );
	
	m_button18021 = new wxButton( this, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button18021, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button18121 = new wxButton( this, wxID_ANY, wxT("Import"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button18121, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button18221 = new wxButton( this, wxID_ANY, wxT("Export"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button18221, 0, wxRIGHT|wxLEFT, 5 );
	
	m_sample_name4 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_sample_name4->SetMaxLength( 15 ); 
	fgSizer139->Add( m_sample_name4, 0, wxRIGHT|wxLEFT, 5 );
	
	m_staticText1127 = new wxStaticText( this, wxID_ANY, wxT("Sample 5"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1127->Wrap( -1 );
	m_staticText1127->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer139->Add( m_staticText1127, 0, wxALL, 5 );
	
	m_sample_words5 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_words5->SetMaxLength( 0 ); 
	fgSizer139->Add( m_sample_words5, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_sample_rate5 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_rate5->SetMaxLength( 0 ); 
	fgSizer139->Add( m_sample_rate5, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_button179211 = new wxButton( this, wxID_ANY, wxT("Play"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button179211, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );
	
	m_button180211 = new wxButton( this, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button180211, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button181211 = new wxButton( this, wxID_ANY, wxT("Import"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button181211, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button182211 = new wxButton( this, wxID_ANY, wxT("Export"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button182211, 0, wxRIGHT|wxLEFT, 5 );
	
	m_sample_name5 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_sample_name5->SetMaxLength( 15 ); 
	fgSizer139->Add( m_sample_name5, 0, wxRIGHT|wxLEFT, 5 );
	
	m_staticText1126 = new wxStaticText( this, wxID_ANY, wxT("Sample 6"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1126->Wrap( -1 );
	m_staticText1126->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer139->Add( m_staticText1126, 0, wxALL, 5 );
	
	m_sample_words6 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_words6->SetMaxLength( 0 ); 
	fgSizer139->Add( m_sample_words6, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_sample_rate6 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_rate6->SetMaxLength( 0 ); 
	fgSizer139->Add( m_sample_rate6, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_button1792111 = new wxButton( this, wxID_ANY, wxT("Play"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button1792111, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );
	
	m_button1802111 = new wxButton( this, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button1802111, 1, wxRIGHT|wxLEFT, 5 );
	
	m_button1812111 = new wxButton( this, wxID_ANY, wxT("Import"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button1812111, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button1822111 = new wxButton( this, wxID_ANY, wxT("Export"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button1822111, 0, wxRIGHT|wxLEFT, 5 );
	
	m_sample_name6 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_sample_name6->SetMaxLength( 15 ); 
	fgSizer139->Add( m_sample_name6, 0, wxRIGHT|wxLEFT, 5 );
	
	m_staticText11261 = new wxStaticText( this, wxID_ANY, wxT("Sample 7"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11261->Wrap( -1 );
	m_staticText11261->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer139->Add( m_staticText11261, 0, wxALL, 5 );
	
	m_sample_words7 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_words7->SetMaxLength( 0 ); 
	fgSizer139->Add( m_sample_words7, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_sample_rate7 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_rate7->SetMaxLength( 0 ); 
	fgSizer139->Add( m_sample_rate7, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_button17921111 = new wxButton( this, wxID_ANY, wxT("Play"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button17921111, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );
	
	m_button18021111 = new wxButton( this, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button18021111, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button18121111 = new wxButton( this, wxID_ANY, wxT("Import"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button18121111, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button18221111 = new wxButton( this, wxID_ANY, wxT("Export"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button18221111, 0, wxRIGHT|wxLEFT, 5 );
	
	m_sample_name7 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_sample_name7->SetMaxLength( 15 ); 
	fgSizer139->Add( m_sample_name7, 0, wxRIGHT|wxLEFT, 5 );
	
	m_staticText112611 = new wxStaticText( this, wxID_ANY, wxT("Sample 8   "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText112611->Wrap( -1 );
	m_staticText112611->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer139->Add( m_staticText112611, 0, wxALL, 5 );
	
	m_sample_words8 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_words8->SetMaxLength( 0 ); 
	fgSizer139->Add( m_sample_words8, 0, wxRIGHT|wxLEFT, 5 );
	
	m_sample_rate8 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_rate8->SetMaxLength( 0 ); 
	fgSizer139->Add( m_sample_rate8, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button179211111 = new wxButton( this, wxID_ANY, wxT("Play"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button179211111, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_button180211111 = new wxButton( this, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button180211111, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button181211111 = new wxButton( this, wxID_ANY, wxT("Import"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button181211111, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button182211111 = new wxButton( this, wxID_ANY, wxT("Export"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer139->Add( m_button182211111, 0, wxRIGHT|wxLEFT, 5 );
	
	m_sample_name8 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_sample_name8->SetMaxLength( 15 ); 
	fgSizer139->Add( m_sample_name8, 0, wxRIGHT|wxLEFT, 5 );
	
	
	bSizer67->Add( fgSizer139, 1, wxEXPAND, 5 );
	
	m_staticline13 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxSize( 935,-1 ), wxLI_HORIZONTAL );
	bSizer67->Add( m_staticline13, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer681;
	bSizer681 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText11101 = new wxStaticText( this, wxID_ANY, wxT(" Bank B "), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT|wxRAISED_BORDER );
	m_staticText11101->Wrap( -1 );
	m_staticText11101->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	m_staticText11101->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_staticText11101->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer681->Add( m_staticText11101, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText267 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText267->Wrap( -1 );
	bSizer681->Add( m_staticText267, 0, wxALL, 5 );
	
	m_b_memory_usage = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxSize( 820,-1 ), wxGA_HORIZONTAL|wxGA_SMOOTH|wxDOUBLE_BORDER );
	m_b_memory_usage->SetValue( 0 ); 
	bSizer681->Add( m_b_memory_usage, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_b_memory_usage_txt = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CENTRE );
	m_b_memory_usage_txt->SetMaxLength( 0 ); 
	m_b_memory_usage_txt->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	m_b_memory_usage_txt->SetMinSize( wxSize( 40,-1 ) );
	m_b_memory_usage_txt->SetMaxSize( wxSize( 40,-1 ) );
	
	bSizer681->Add( m_b_memory_usage_txt, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP, 5 );
	
	m_staticText291 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText291->Wrap( -1 );
	bSizer681->Add( m_staticText291, 0, wxALL, 5 );
	
	
	bSizer67->Add( bSizer681, 0, wxEXPAND|wxALIGN_RIGHT, 0 );
	
	wxFlexGridSizer* fgSizer1391;
	fgSizer1391 = new wxFlexGridSizer( 0, 8, 0, 0 );
	fgSizer1391->SetFlexibleDirection( wxBOTH );
	fgSizer1391->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText11173 = new wxStaticText( this, wxID_ANY, wxT("Sample 9"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11173->Wrap( -1 );
	m_staticText11173->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer1391->Add( m_staticText11173, 0, wxALIGN_CENTER_VERTICAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_sample_words9 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_words9->SetMaxLength( 0 ); 
	fgSizer1391->Add( m_sample_words9, 0, wxRIGHT|wxLEFT, 5 );
	
	m_sample_rate9 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_rate9->SetMaxLength( 0 ); 
	fgSizer1391->Add( m_sample_rate9, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_button1793 = new wxButton( this, wxID_ANY, wxT("Play"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button1793, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );
	
	m_button1803 = new wxButton( this, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button1803, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button1813 = new wxButton( this, wxID_ANY, wxT("Import"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button1813, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button1823 = new wxButton( this, wxID_ANY, wxT("Export"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button1823, 0, wxRIGHT|wxLEFT, 5 );
	
	m_sample_name9 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_sample_name9->SetMaxLength( 15 ); 
	fgSizer1391->Add( m_sample_name9, 0, wxRIGHT|wxLEFT, 5 );
	
	m_staticText111711 = new wxStaticText( this, wxID_ANY, wxT("Sample 10"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText111711->Wrap( -1 );
	m_staticText111711->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer1391->Add( m_staticText111711, 0, wxALL, 5 );
	
	m_sample_words10 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_words10->SetMaxLength( 0 ); 
	fgSizer1391->Add( m_sample_words10, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_sample_rate10 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_rate10->SetMaxLength( 0 ); 
	fgSizer1391->Add( m_sample_rate10, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_button17911 = new wxButton( this, wxID_ANY, wxT("Play"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button17911, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );
	
	m_button18011 = new wxButton( this, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button18011, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button18111 = new wxButton( this, wxID_ANY, wxT("Import"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button18111, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button18211 = new wxButton( this, wxID_ANY, wxT("Export"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button18211, 0, wxRIGHT|wxLEFT, 5 );
	
	m_sample_name10 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_sample_name10->SetMaxLength( 15 ); 
	fgSizer1391->Add( m_sample_name10, 0, wxRIGHT|wxLEFT, 5 );
	
	m_staticText111721 = new wxStaticText( this, wxID_ANY, wxT("Sample 11"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText111721->Wrap( -1 );
	m_staticText111721->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer1391->Add( m_staticText111721, 0, wxALL, 5 );
	
	m_sample_words11 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_words11->SetMaxLength( 0 ); 
	fgSizer1391->Add( m_sample_words11, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_sample_rate11 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_rate11->SetMaxLength( 0 ); 
	fgSizer1391->Add( m_sample_rate11, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_button17922 = new wxButton( this, wxID_ANY, wxT("Play"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button17922, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );
	
	m_button18022 = new wxButton( this, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button18022, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button18122 = new wxButton( this, wxID_ANY, wxT("Import"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button18122, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button18222 = new wxButton( this, wxID_ANY, wxT("Export"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button18222, 0, wxRIGHT|wxLEFT, 5 );
	
	m_sample_name11 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_sample_name11->SetMaxLength( 15 ); 
	fgSizer1391->Add( m_sample_name11, 0, wxRIGHT|wxLEFT, 5 );
	
	m_staticText11251 = new wxStaticText( this, wxID_ANY, wxT("Sample 12"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11251->Wrap( -1 );
	m_staticText11251->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer1391->Add( m_staticText11251, 0, wxALL, 5 );
	
	m_sample_words12 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_words12->SetMaxLength( 0 ); 
	fgSizer1391->Add( m_sample_words12, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_sample_rate12 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_rate12->SetMaxLength( 0 ); 
	fgSizer1391->Add( m_sample_rate12, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_button179212 = new wxButton( this, wxID_ANY, wxT("Play"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button179212, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );
	
	m_button180212 = new wxButton( this, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button180212, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button181212 = new wxButton( this, wxID_ANY, wxT("Import"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button181212, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button182212 = new wxButton( this, wxID_ANY, wxT("Export"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button182212, 0, wxRIGHT|wxLEFT, 5 );
	
	m_sample_name12 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_sample_name12->SetMaxLength( 15 ); 
	fgSizer1391->Add( m_sample_name12, 0, wxRIGHT|wxLEFT, 5 );
	
	m_staticText11271 = new wxStaticText( this, wxID_ANY, wxT("Sample 13"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11271->Wrap( -1 );
	m_staticText11271->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer1391->Add( m_staticText11271, 0, wxALL, 5 );
	
	m_sample_words13 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_words13->SetMaxLength( 0 ); 
	fgSizer1391->Add( m_sample_words13, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_sample_rate13 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_rate13->SetMaxLength( 0 ); 
	fgSizer1391->Add( m_sample_rate13, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_button1792112 = new wxButton( this, wxID_ANY, wxT("Play"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button1792112, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );
	
	m_button1802112 = new wxButton( this, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button1802112, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button1812112 = new wxButton( this, wxID_ANY, wxT("Import"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button1812112, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button1822112 = new wxButton( this, wxID_ANY, wxT("Export"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button1822112, 0, wxRIGHT|wxLEFT, 5 );
	
	m_sample_name13 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_sample_name13->SetMaxLength( 15 ); 
	fgSizer1391->Add( m_sample_name13, 0, wxRIGHT|wxLEFT, 5 );
	
	m_staticText11262 = new wxStaticText( this, wxID_ANY, wxT("Sample 14"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11262->Wrap( -1 );
	m_staticText11262->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer1391->Add( m_staticText11262, 0, wxALL, 5 );
	
	m_sample_words14 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_words14->SetMaxLength( 0 ); 
	fgSizer1391->Add( m_sample_words14, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_sample_rate14 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_rate14->SetMaxLength( 0 ); 
	fgSizer1391->Add( m_sample_rate14, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_button17921112 = new wxButton( this, wxID_ANY, wxT("Play"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button17921112, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );
	
	m_button18021112 = new wxButton( this, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button18021112, 1, wxRIGHT|wxLEFT, 5 );
	
	m_button18121112 = new wxButton( this, wxID_ANY, wxT("Import"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button18121112, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button18221112 = new wxButton( this, wxID_ANY, wxT("Export"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button18221112, 0, wxRIGHT|wxLEFT, 5 );
	
	m_sample_name14 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_sample_name14->SetMaxLength( 15 ); 
	fgSizer1391->Add( m_sample_name14, 0, wxRIGHT|wxLEFT, 5 );
	
	m_staticText112612 = new wxStaticText( this, wxID_ANY, wxT("Sample 15"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText112612->Wrap( -1 );
	m_staticText112612->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer1391->Add( m_staticText112612, 0, wxALL, 5 );
	
	m_sample_words15 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_words15->SetMaxLength( 0 ); 
	fgSizer1391->Add( m_sample_words15, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_sample_rate15 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_rate15->SetMaxLength( 0 ); 
	fgSizer1391->Add( m_sample_rate15, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_button179211112 = new wxButton( this, wxID_ANY, wxT("Play"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button179211112, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );
	
	m_button180211112 = new wxButton( this, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button180211112, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button181211112 = new wxButton( this, wxID_ANY, wxT("Import"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button181211112, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button182211112 = new wxButton( this, wxID_ANY, wxT("Export"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button182211112, 0, wxRIGHT|wxLEFT, 5 );
	
	m_sample_name15 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_sample_name15->SetMaxLength( 15 ); 
	fgSizer1391->Add( m_sample_name15, 0, wxRIGHT|wxLEFT, 5 );
	
	m_staticText1126111 = new wxStaticText( this, wxID_ANY, wxT("Sample 16"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1126111->Wrap( -1 );
	m_staticText1126111->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer1391->Add( m_staticText1126111, 0, wxALL, 5 );
	
	m_sample_words16 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_words16->SetMaxLength( 0 ); 
	fgSizer1391->Add( m_sample_words16, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_sample_rate16 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_rate16->SetMaxLength( 0 ); 
	fgSizer1391->Add( m_sample_rate16, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button1792111111 = new wxButton( this, wxID_ANY, wxT("Play"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button1792111111, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );
	
	m_button1802111111 = new wxButton( this, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button1802111111, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button1812111111 = new wxButton( this, wxID_ANY, wxT("Import"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button1812111111, 0, wxRIGHT|wxLEFT, 5 );
	
	m_button1822111111 = new wxButton( this, wxID_ANY, wxT("Export"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	fgSizer1391->Add( m_button1822111111, 0, wxRIGHT|wxLEFT, 5 );
	
	m_sample_name16 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_sample_name16->SetMaxLength( 15 ); 
	fgSizer1391->Add( m_sample_name16, 0, wxRIGHT|wxLEFT, 5 );
	
	
	bSizer67->Add( fgSizer1391, 1, wxBOTTOM|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer93;
	bSizer93 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizer67->Add( bSizer93, 0, wxEXPAND, 5 );
	
	m_staticline131 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxSize( 935,-1 ), wxLI_HORIZONTAL );
	bSizer67->Add( m_staticline131, 0, wxALL, 5 );
	
	m_button106 = new wxButton( this, wxID_ANY, wxT("Save all"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer67->Add( m_button106, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
	this->SetSizer( bSizer67 );
	this->Layout();
	
	// Connect Events
	m_button179->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay1 ), NULL, this );
	m_button180->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete1 ), NULL, this );
	m_button181->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad1 ), NULL, this );
	m_button182->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave1 ), NULL, this );
	m_sample_name1->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange1 ), NULL, this );
	m_button1791->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay2 ), NULL, this );
	m_button1801->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete2 ), NULL, this );
	m_button1811->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad2 ), NULL, this );
	m_button1821->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave2 ), NULL, this );
	m_sample_name2->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange2 ), NULL, this );
	m_button1792->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay3 ), NULL, this );
	m_button1802->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete3 ), NULL, this );
	m_button1812->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad3 ), NULL, this );
	m_button1822->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave3 ), NULL, this );
	m_sample_name3->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange3 ), NULL, this );
	m_button17921->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay4 ), NULL, this );
	m_button18021->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete4 ), NULL, this );
	m_button18121->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad4 ), NULL, this );
	m_button18221->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave4 ), NULL, this );
	m_sample_name4->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange4 ), NULL, this );
	m_button179211->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay5 ), NULL, this );
	m_button180211->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete5 ), NULL, this );
	m_button181211->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad5 ), NULL, this );
	m_button182211->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave5 ), NULL, this );
	m_sample_name5->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange5 ), NULL, this );
	m_button1792111->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay6 ), NULL, this );
	m_button1802111->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete6 ), NULL, this );
	m_button1812111->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad6 ), NULL, this );
	m_button1822111->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave6 ), NULL, this );
	m_sample_name6->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange6 ), NULL, this );
	m_button17921111->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay7 ), NULL, this );
	m_button18021111->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete7 ), NULL, this );
	m_button18121111->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad7 ), NULL, this );
	m_button18221111->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave7 ), NULL, this );
	m_sample_name7->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange7 ), NULL, this );
	m_button179211111->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay8 ), NULL, this );
	m_button180211111->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete8 ), NULL, this );
	m_button181211111->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad8 ), NULL, this );
	m_button182211111->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave8 ), NULL, this );
	m_sample_name8->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange8 ), NULL, this );
	m_button1793->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay9 ), NULL, this );
	m_button1803->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete9 ), NULL, this );
	m_button1813->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad9 ), NULL, this );
	m_button1823->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave9 ), NULL, this );
	m_sample_name9->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange9 ), NULL, this );
	m_button17911->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay10 ), NULL, this );
	m_button18011->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete10 ), NULL, this );
	m_button18111->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad10 ), NULL, this );
	m_button18211->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave10 ), NULL, this );
	m_sample_name10->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange10 ), NULL, this );
	m_button17922->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay11 ), NULL, this );
	m_button18022->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete11 ), NULL, this );
	m_button18122->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad11 ), NULL, this );
	m_button18222->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave11 ), NULL, this );
	m_sample_name11->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange11 ), NULL, this );
	m_button179212->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay12 ), NULL, this );
	m_button180212->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete12 ), NULL, this );
	m_button181212->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad12 ), NULL, this );
	m_button182212->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave12 ), NULL, this );
	m_sample_name12->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange12 ), NULL, this );
	m_button1792112->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay13 ), NULL, this );
	m_button1802112->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete13 ), NULL, this );
	m_button1812112->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad13 ), NULL, this );
	m_button1822112->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave13 ), NULL, this );
	m_sample_name13->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange13 ), NULL, this );
	m_button17921112->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay14 ), NULL, this );
	m_button18021112->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete14 ), NULL, this );
	m_button18121112->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad14 ), NULL, this );
	m_button18221112->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave14 ), NULL, this );
	m_sample_name14->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange14 ), NULL, this );
	m_button179211112->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay15 ), NULL, this );
	m_button180211112->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete15 ), NULL, this );
	m_button181211112->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad15 ), NULL, this );
	m_button182211112->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave15 ), NULL, this );
	m_sample_name15->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange15 ), NULL, this );
	m_button1792111111->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay16 ), NULL, this );
	m_button1802111111->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete16 ), NULL, this );
	m_button1812111111->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad16 ), NULL, this );
	m_button1822111111->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave16 ), NULL, this );
	m_sample_name16->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange16 ), NULL, this );
	m_button106->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSaveAll ), NULL, this );
}

SamplesPanel::~SamplesPanel()
{
	// Disconnect Events
	m_button179->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay1 ), NULL, this );
	m_button180->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete1 ), NULL, this );
	m_button181->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad1 ), NULL, this );
	m_button182->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave1 ), NULL, this );
	m_sample_name1->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange1 ), NULL, this );
	m_button1791->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay2 ), NULL, this );
	m_button1801->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete2 ), NULL, this );
	m_button1811->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad2 ), NULL, this );
	m_button1821->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave2 ), NULL, this );
	m_sample_name2->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange2 ), NULL, this );
	m_button1792->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay3 ), NULL, this );
	m_button1802->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete3 ), NULL, this );
	m_button1812->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad3 ), NULL, this );
	m_button1822->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave3 ), NULL, this );
	m_sample_name3->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange3 ), NULL, this );
	m_button17921->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay4 ), NULL, this );
	m_button18021->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete4 ), NULL, this );
	m_button18121->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad4 ), NULL, this );
	m_button18221->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave4 ), NULL, this );
	m_sample_name4->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange4 ), NULL, this );
	m_button179211->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay5 ), NULL, this );
	m_button180211->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete5 ), NULL, this );
	m_button181211->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad5 ), NULL, this );
	m_button182211->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave5 ), NULL, this );
	m_sample_name5->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange5 ), NULL, this );
	m_button1792111->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay6 ), NULL, this );
	m_button1802111->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete6 ), NULL, this );
	m_button1812111->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad6 ), NULL, this );
	m_button1822111->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave6 ), NULL, this );
	m_sample_name6->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange6 ), NULL, this );
	m_button17921111->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay7 ), NULL, this );
	m_button18021111->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete7 ), NULL, this );
	m_button18121111->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad7 ), NULL, this );
	m_button18221111->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave7 ), NULL, this );
	m_sample_name7->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange7 ), NULL, this );
	m_button179211111->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay8 ), NULL, this );
	m_button180211111->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete8 ), NULL, this );
	m_button181211111->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad8 ), NULL, this );
	m_button182211111->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave8 ), NULL, this );
	m_sample_name8->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange8 ), NULL, this );
	m_button1793->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay9 ), NULL, this );
	m_button1803->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete9 ), NULL, this );
	m_button1813->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad9 ), NULL, this );
	m_button1823->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave9 ), NULL, this );
	m_sample_name9->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange9 ), NULL, this );
	m_button17911->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay10 ), NULL, this );
	m_button18011->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete10 ), NULL, this );
	m_button18111->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad10 ), NULL, this );
	m_button18211->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave10 ), NULL, this );
	m_sample_name10->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange10 ), NULL, this );
	m_button17922->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay11 ), NULL, this );
	m_button18022->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete11 ), NULL, this );
	m_button18122->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad11 ), NULL, this );
	m_button18222->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave11 ), NULL, this );
	m_sample_name11->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange11 ), NULL, this );
	m_button179212->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay12 ), NULL, this );
	m_button180212->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete12 ), NULL, this );
	m_button181212->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad12 ), NULL, this );
	m_button182212->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave12 ), NULL, this );
	m_sample_name12->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange12 ), NULL, this );
	m_button1792112->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay13 ), NULL, this );
	m_button1802112->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete13 ), NULL, this );
	m_button1812112->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad13 ), NULL, this );
	m_button1822112->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave13 ), NULL, this );
	m_sample_name13->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange13 ), NULL, this );
	m_button17921112->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay14 ), NULL, this );
	m_button18021112->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete14 ), NULL, this );
	m_button18121112->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad14 ), NULL, this );
	m_button18221112->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave14 ), NULL, this );
	m_sample_name14->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange14 ), NULL, this );
	m_button179211112->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay15 ), NULL, this );
	m_button180211112->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete15 ), NULL, this );
	m_button181211112->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad15 ), NULL, this );
	m_button182211112->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave15 ), NULL, this );
	m_sample_name15->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange15 ), NULL, this );
	m_button1792111111->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnPlay16 ), NULL, this );
	m_button1802111111->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnDelete16 ), NULL, this );
	m_button1812111111->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnLoad16 ), NULL, this );
	m_button1822111111->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSave16 ), NULL, this );
	m_sample_name16->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SamplesPanel::OnNameChange16 ), NULL, this );
	m_button106->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SamplesPanel::OnSaveAll ), NULL, this );
	
}

SoundLoopPanel::SoundLoopPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	this->SetMinSize( wxSize( -1,410 ) );
	this->SetMaxSize( wxSize( -1,410 ) );
	
	wxFlexGridSizer* fgSizer25;
	fgSizer25 = new wxFlexGridSizer( 1, 1, 0, 0 );
	fgSizer25->AddGrowableRow( 1 );
	fgSizer25->AddGrowableRow( 2 );
	fgSizer25->SetFlexibleDirection( wxBOTH );
	fgSizer25->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_ALL );
	
	m_wavedisp_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( 970,300 ), wxTAB_TRAVERSAL );
	m_wavedisp_panel->SetMinSize( wxSize( 970,-1 ) );
	m_wavedisp_panel->SetMaxSize( wxSize( 970,-1 ) );
	
	m_menu161 = new wxMenu();
	wxMenuItem* m_menu_load1;
	m_menu_load1 = new wxMenuItem( m_menu161, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu161->Append( m_menu_load1 );
	
	wxMenuItem* m_menu_save1;
	m_menu_save1 = new wxMenuItem( m_menu161, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu161->Append( m_menu_save1 );
	
	m_menu161->AppendSeparator();
	
	wxMenuItem* m_menu_get_sound1;
	m_menu_get_sound1 = new wxMenuItem( m_menu161, wxID_ANY, wxString( wxT("Get Sound") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu161->Append( m_menu_get_sound1 );
	
	wxMenuItem* m_menu_get_sound_param1;
	m_menu_get_sound_param1 = new wxMenuItem( m_menu161, wxID_ANY, wxString( wxT("Get Sound Parameters") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu161->Append( m_menu_get_sound_param1 );
	
	m_menu161->AppendSeparator();
	
	wxMenuItem* m_menu_copy1;
	m_menu_copy1 = new wxMenuItem( m_menu161, wxID_ANY, wxString( wxT("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu161->Append( m_menu_copy1 );
	
	wxMenuItem* m_menu_copyparamtoall;
	m_menu_copyparamtoall = new wxMenuItem( m_menu161, wxID_ANY, wxString( wxT("Copy Parameters to all") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu161->Append( m_menu_copyparamtoall );
	
	m_menu161->AppendSeparator();
	
	wxMenuItem* m_menu_delete_sound1;
	m_menu_delete_sound1 = new wxMenuItem( m_menu161, wxID_ANY, wxString( wxT("Delete sample data") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu161->Append( m_menu_delete_sound1 );
	
	m_menu161->AppendSeparator();
	
	wxMenuItem* m_menu_import1;
	m_menu_import1 = new wxMenuItem( m_menu161, wxID_ANY, wxString( wxT("Import WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu161->Append( m_menu_import1 );
	
	wxMenuItem* m_menu_export1;
	m_menu_export1 = new wxMenuItem( m_menu161, wxID_ANY, wxString( wxT("Export WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu161->Append( m_menu_export1 );
	
	m_menu161->AppendSeparator();
	
	wxMenuItem* m_menu_purge1;
	m_menu_purge1 = new wxMenuItem( m_menu161, wxID_ANY, wxString( wxT("Purge") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu161->Append( m_menu_purge1 );
	
	m_wavedisp_panel->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( SoundLoopPanel::m_wavedisp_panelOnContextMenu ), NULL, this ); 
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );
	
	m_wave_disp = new WaveDisp(m_wavedisp_panel, wxID_ANY, wxDefaultPosition, wxSize(950, 185));
	m_wave_disp->SetMinSize( wxSize( -1,185 ) );
	
	bSizer11->Add( m_wave_disp, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	
	m_wavedisp_panel->SetSizer( bSizer11 );
	m_wavedisp_panel->Layout();
	fgSizer25->Add( m_wavedisp_panel, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	fgSizer25->Add( 0, 0, 1, 0, 5 );
	
	m_panel811 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer731;
	fgSizer731 = new wxFlexGridSizer( 0, 18, 0, 0 );
	fgSizer731->SetFlexibleDirection( wxBOTH );
	fgSizer731->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText6022 = new wxStaticText( m_panel811, wxID_ANY, wxT(" Start Address"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6022->Wrap( -1 );
	fgSizer731->Add( m_staticText6022, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_start_point = new wxSpinCtrl( m_panel811, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 10, 0 );
	fgSizer731->Add( m_start_point, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_button23 = new wxButton( m_panel811, wxID_ANY, wxT("<<"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	m_button23->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	fgSizer731->Add( m_button23, 0, wxTOP|wxBOTTOM, 5 );
	
	m_button33 = new wxButton( m_panel811, wxID_ANY, wxT("<"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	m_button33->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	fgSizer731->Add( m_button33, 0, wxTOP|wxBOTTOM, 5 );
	
	m_button43 = new wxButton( m_panel811, wxID_ANY, wxT(">"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	m_button43->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	fgSizer731->Add( m_button43, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_button53 = new wxButton( m_panel811, wxID_ANY, wxT(">>"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	m_button53->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	fgSizer731->Add( m_button53, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_staticText6032 = new wxStaticText( m_panel811, wxID_ANY, wxT("Sustain Loop Start"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6032->Wrap( -1 );
	fgSizer731->Add( m_staticText6032, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_sustainloop_start = new wxSpinCtrl( m_panel811, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 10, 0 );
	fgSizer731->Add( m_sustainloop_start, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_button212 = new wxButton( m_panel811, wxID_ANY, wxT("<<"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	m_button212->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	fgSizer731->Add( m_button212, 0, wxTOP|wxBOTTOM, 5 );
	
	m_button313 = new wxButton( m_panel811, wxID_ANY, wxT("<"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	m_button313->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	fgSizer731->Add( m_button313, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_button413 = new wxButton( m_panel811, wxID_ANY, wxT(">"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	m_button413->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	fgSizer731->Add( m_button413, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_button513 = new wxButton( m_panel811, wxID_ANY, wxT(">>"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	m_button513->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	fgSizer731->Add( m_button513, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_staticText6042 = new wxStaticText( m_panel811, wxID_ANY, wxT("Release Loop Start"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6042->Wrap( -1 );
	fgSizer731->Add( m_staticText6042, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_releaseloop_start = new wxSpinCtrl( m_panel811, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 10, 0 );
	fgSizer731->Add( m_releaseloop_start, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_button2113 = new wxButton( m_panel811, wxID_ANY, wxT("<<"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	m_button2113->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	fgSizer731->Add( m_button2113, 0, wxTOP|wxBOTTOM, 5 );
	
	m_button3112 = new wxButton( m_panel811, wxID_ANY, wxT("<"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	m_button3112->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	fgSizer731->Add( m_button3112, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_button4112 = new wxButton( m_panel811, wxID_ANY, wxT(">"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	m_button4112->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	fgSizer731->Add( m_button4112, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_button5112 = new wxButton( m_panel811, wxID_ANY, wxT(">>"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	m_button5112->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	fgSizer731->Add( m_button5112, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_staticText60211 = new wxStaticText( m_panel811, wxID_ANY, wxT("End Address"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText60211->Wrap( -1 );
	fgSizer731->Add( m_staticText60211, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_end_point = new wxSpinCtrl( m_panel811, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 10, 0 );
	fgSizer731->Add( m_end_point, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_button221 = new wxButton( m_panel811, wxID_ANY, wxT("<<"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	m_button221->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	fgSizer731->Add( m_button221, 0, wxTOP|wxBOTTOM, 5 );
	
	m_button321 = new wxButton( m_panel811, wxID_ANY, wxT("<"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	m_button321->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	fgSizer731->Add( m_button321, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_button421 = new wxButton( m_panel811, wxID_ANY, wxT(">"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	m_button421->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	fgSizer731->Add( m_button421, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_button521 = new wxButton( m_panel811, wxID_ANY, wxT(">>"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	m_button521->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	fgSizer731->Add( m_button521, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_staticText60311 = new wxStaticText( m_panel811, wxID_ANY, wxT("   Sustain Loop End"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText60311->Wrap( -1 );
	fgSizer731->Add( m_staticText60311, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxALIGN_RIGHT, 5 );
	
	m_sustainloop_end = new wxSpinCtrl( m_panel811, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 10, 0 );
	fgSizer731->Add( m_sustainloop_end, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_button21111 = new wxButton( m_panel811, wxID_ANY, wxT("<<"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	m_button21111->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	fgSizer731->Add( m_button21111, 0, wxTOP|wxBOTTOM, 5 );
	
	m_button3121 = new wxButton( m_panel811, wxID_ANY, wxT("<"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	m_button3121->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	fgSizer731->Add( m_button3121, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_button4121 = new wxButton( m_panel811, wxID_ANY, wxT(">"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	m_button4121->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	fgSizer731->Add( m_button4121, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_button5121 = new wxButton( m_panel811, wxID_ANY, wxT(">>"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	m_button5121->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	fgSizer731->Add( m_button5121, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_staticText60411 = new wxStaticText( m_panel811, wxID_ANY, wxT("Release Loop End"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText60411->Wrap( -1 );
	fgSizer731->Add( m_staticText60411, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5 );
	
	m_releaseloop_end = new wxSpinCtrl( m_panel811, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), wxSP_ARROW_KEYS, 0, 10, 0 );
	fgSizer731->Add( m_releaseloop_end, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_button21121 = new wxButton( m_panel811, wxID_ANY, wxT("<<"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	m_button21121->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	fgSizer731->Add( m_button21121, 0, wxTOP|wxBOTTOM, 5 );
	
	m_button31111 = new wxButton( m_panel811, wxID_ANY, wxT("<"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	m_button31111->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	fgSizer731->Add( m_button31111, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_button41111 = new wxButton( m_panel811, wxID_ANY, wxT(">"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	m_button41111->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	fgSizer731->Add( m_button41111, 0, wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_button51111 = new wxButton( m_panel811, wxID_ANY, wxT(">>"), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	m_button51111->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 90, false, wxEmptyString ) );
	
	fgSizer731->Add( m_button51111, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	wxBoxSizer* bSizer171;
	bSizer171 = new wxBoxSizer( wxVERTICAL );
	
	
	fgSizer731->Add( bSizer171, 0, 0, 5 );
	
	
	m_panel811->SetSizer( fgSizer731 );
	m_panel811->Layout();
	fgSizer731->Fit( m_panel811 );
	m_menu1611 = new wxMenu();
	wxMenuItem* m_menu_load11;
	m_menu_load11 = new wxMenuItem( m_menu1611, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1611->Append( m_menu_load11 );
	
	wxMenuItem* m_menu_save11;
	m_menu_save11 = new wxMenuItem( m_menu1611, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1611->Append( m_menu_save11 );
	
	m_menu1611->AppendSeparator();
	
	wxMenuItem* m_menu_get_sound11;
	m_menu_get_sound11 = new wxMenuItem( m_menu1611, wxID_ANY, wxString( wxT("Get Sound") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1611->Append( m_menu_get_sound11 );
	
	wxMenuItem* m_menu_get_sound_param11;
	m_menu_get_sound_param11 = new wxMenuItem( m_menu1611, wxID_ANY, wxString( wxT("Get Sound Parameters") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1611->Append( m_menu_get_sound_param11 );
	
	m_menu1611->AppendSeparator();
	
	wxMenuItem* m_menu_copy11;
	m_menu_copy11 = new wxMenuItem( m_menu1611, wxID_ANY, wxString( wxT("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1611->Append( m_menu_copy11 );
	
	wxMenuItem* m_menu_copyparamtoall1;
	m_menu_copyparamtoall1 = new wxMenuItem( m_menu1611, wxID_ANY, wxString( wxT("Copy Parameters to all") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1611->Append( m_menu_copyparamtoall1 );
	
	m_menu1611->AppendSeparator();
	
	wxMenuItem* m_menu_delete_sound11;
	m_menu_delete_sound11 = new wxMenuItem( m_menu1611, wxID_ANY, wxString( wxT("Delete sample data") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1611->Append( m_menu_delete_sound11 );
	
	m_menu1611->AppendSeparator();
	
	wxMenuItem* m_menu_import11;
	m_menu_import11 = new wxMenuItem( m_menu1611, wxID_ANY, wxString( wxT("Import WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1611->Append( m_menu_import11 );
	
	wxMenuItem* m_menu_export11;
	m_menu_export11 = new wxMenuItem( m_menu1611, wxID_ANY, wxString( wxT("Export WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1611->Append( m_menu_export11 );
	
	m_menu1611->AppendSeparator();
	
	wxMenuItem* m_menu_purge11;
	m_menu_purge11 = new wxMenuItem( m_menu1611, wxID_ANY, wxString( wxT("Purge") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1611->Append( m_menu_purge11 );
	
	m_panel811->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( SoundLoopPanel::m_panel811OnContextMenu ), NULL, this ); 
	
	fgSizer25->Add( m_panel811, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	fgSizer25->Add( 0, 0, 1, 0, 5 );
	
	m_panel155 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer111;
	bSizer111 = new wxBoxSizer( wxHORIZONTAL );
	
	wxFlexGridSizer* fgSizer145;
	fgSizer145 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer145->SetFlexibleDirection( wxBOTH );
	fgSizer145->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	fgSizer145->Add( 0, 2, 1, wxEXPAND, 5 );
	
	
	fgSizer145->Add( 0, 0, 1, 0, 5 );
	
	
	fgSizer145->Add( 0, 0, 1, 0, 5 );
	
	
	fgSizer145->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText6151 = new wxStaticText( m_panel155, wxID_ANY, wxT("Sample Size"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6151->Wrap( -1 );
	m_staticText6151->SetToolTip( wxT("Size of Sample in WORDS") );
	
	fgSizer145->Add( m_staticText6151, 0, wxALIGN_BOTTOM|wxALIGN_RIGHT|wxALL, 5 );
	
	m_sample_words_txt = new wxTextCtrl( m_panel155, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_sample_words_txt->SetMaxLength( 0 ); 
	fgSizer145->Add( m_sample_words_txt, 0, wxALIGN_BOTTOM, 5 );
	
	
	fgSizer145->Add( 16, 0, 1, 0, 0 );
	
	m_sust_loop_ena = new wxCheckBox( m_panel155, wxID_ANY, wxT("Sustain Loop"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	fgSizer145->Add( m_sust_loop_ena, 0, wxEXPAND|wxALIGN_BOTTOM|wxALL, 5 );
	
	m_staticText1192 = new wxStaticText( m_panel155, wxID_ANY, wxT("   Sample Rate"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1192->Wrap( -1 );
	fgSizer145->Add( m_staticText1192, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 5 );
	
	m_sample_rate = new wxTextCtrl( m_panel155, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 80,-1 ), 0 );
	m_sample_rate->SetMaxLength( 0 ); 
	fgSizer145->Add( m_sample_rate, 0, wxALIGN_BOTTOM, 5 );
	
	
	fgSizer145->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_reverse_ena = new wxCheckBox( m_panel155, wxID_ANY, wxT("Reverse"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	fgSizer145->Add( m_reverse_ena, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxEXPAND|wxALL, 5 );
	
	m_play_button = new wxToggleButton( m_panel155, wxID_ANY, wxT("P L A Y"), wxDefaultPosition, wxSize( 63,20 ), 0 );
	m_play_button->Hide();
	
	fgSizer145->Add( m_play_button, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxRIGHT|wxLEFT, 5 );
	
	m_staticText1194 = new wxStaticText( m_panel155, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1194->Wrap( -1 );
	fgSizer145->Add( m_staticText1194, 0, wxALL, 5 );
	
	
	fgSizer145->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_forward_loop_ena = new wxCheckBox( m_panel155, wxID_ANY, wxT("Back/Forward"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_forward_loop_ena->SetToolTip( wxT("This is only available in conjunction with the Release Loop and will disable the Sustain Loop") );
	
	fgSizer145->Add( m_forward_loop_ena, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND|wxALIGN_RIGHT, 5 );
	
	m_staticText280 = new wxStaticText( m_panel155, wxID_ANY, wxT("      Play Mode"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText280->Wrap( -1 );
	m_staticText280->SetToolTip( wxT("This affects the preview of Samples only - not a parameter of the Soundset") );
	
	fgSizer145->Add( m_staticText280, 0, wxALL, 5 );
	
	m_wave_selection = new wxOwnerDrawnComboBox( m_panel155, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 95,-1 ), 0, NULL, 0 ); 
	m_wave_selection->SetToolTip( wxT("This affects the preview of Samples only - not a parameter of the Soundset") );
	
	fgSizer145->Add( m_wave_selection, 0, wxRIGHT, 5 );
	
	
	fgSizer145->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_release_loop_ena = new wxCheckBox( m_panel155, wxID_ANY, wxT("Release Loop"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	fgSizer145->Add( m_release_loop_ena, 0, wxALIGN_RIGHT|wxALL|wxEXPAND, 5 );
	
	
	fgSizer145->Add( 0, 1, 1, wxEXPAND, 5 );
	
	
	fgSizer145->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizer111->Add( fgSizer145, 1, wxRIGHT, 5 );
	
	wxBoxSizer* bSizer114;
	bSizer114 = new wxBoxSizer( wxVERTICAL );
	
	
	bSizer114->Add( 0, 0, 0, 0, 5 );
	
	
	bSizer111->Add( bSizer114, 0, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer148;
	fgSizer148 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer148->SetFlexibleDirection( wxBOTH );
	fgSizer148->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText6221 = new wxStaticText( m_panel155, wxID_ANY, wxT("  Velocity Start"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6221->Wrap( -1 );
	fgSizer148->Add( m_staticText6221, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_BOTTOM|wxBOTTOM|wxLEFT, 5 );
	
	m_velocity_start_point = new wxSlider( m_panel155, wxID_ANY, 0, -127, 127, wxDefaultPosition, wxSize( 80,-1 ), wxSL_HORIZONTAL|wxSL_LABELS|wxSUNKEN_BORDER );
	fgSizer148->Add( m_velocity_start_point, 0, wxTOP|wxLEFT, 5 );
	
	m_staticText6241 = new wxStaticText( m_panel155, wxID_ANY, wxT("Tune"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6241->Wrap( -1 );
	fgSizer148->Add( m_staticText6241, 1, wxALIGN_RIGHT|wxTOP|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_tune_table = new wxSlider( m_panel155, wxID_ANY, 0, 0, 22, wxDefaultPosition, wxSize( 80,-1 ), wxSL_HORIZONTAL|wxSL_INVERSE|wxSL_LABELS|wxSUNKEN_BORDER );
	m_tune_table->SetToolTip( wxT("Each step will tune the sample down by ~4.5% of a semitone") );
	
	fgSizer148->Add( m_tune_table, 0, wxALIGN_BOTTOM|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
	bSizer111->Add( fgSizer148, 1, wxLEFT|wxEXPAND, 5 );
	
	
	bSizer111->Add( 320, 1, 0, wxBOTTOM, 5 );
	
	
	m_panel155->SetSizer( bSizer111 );
	m_panel155->Layout();
	bSizer111->Fit( m_panel155 );
	m_menu1612 = new wxMenu();
	wxMenuItem* m_menu_load12;
	m_menu_load12 = new wxMenuItem( m_menu1612, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1612->Append( m_menu_load12 );
	
	wxMenuItem* m_menu_save12;
	m_menu_save12 = new wxMenuItem( m_menu1612, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1612->Append( m_menu_save12 );
	
	m_menu1612->AppendSeparator();
	
	wxMenuItem* m_menu_get_sound12;
	m_menu_get_sound12 = new wxMenuItem( m_menu1612, wxID_ANY, wxString( wxT("Get Sound") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1612->Append( m_menu_get_sound12 );
	
	wxMenuItem* m_menu_get_sound_param12;
	m_menu_get_sound_param12 = new wxMenuItem( m_menu1612, wxID_ANY, wxString( wxT("Get Sound Parameters") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1612->Append( m_menu_get_sound_param12 );
	
	m_menu1612->AppendSeparator();
	
	wxMenuItem* m_menu_copy12;
	m_menu_copy12 = new wxMenuItem( m_menu1612, wxID_ANY, wxString( wxT("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1612->Append( m_menu_copy12 );
	
	wxMenuItem* m_menu_copyparamtoall2;
	m_menu_copyparamtoall2 = new wxMenuItem( m_menu1612, wxID_ANY, wxString( wxT("Copy Parameters to all") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1612->Append( m_menu_copyparamtoall2 );
	
	m_menu1612->AppendSeparator();
	
	wxMenuItem* m_menu_delete_sound12;
	m_menu_delete_sound12 = new wxMenuItem( m_menu1612, wxID_ANY, wxString( wxT("Delete sample data") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1612->Append( m_menu_delete_sound12 );
	
	m_menu1612->AppendSeparator();
	
	wxMenuItem* m_menu_import12;
	m_menu_import12 = new wxMenuItem( m_menu1612, wxID_ANY, wxString( wxT("Import WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1612->Append( m_menu_import12 );
	
	wxMenuItem* m_menu_export12;
	m_menu_export12 = new wxMenuItem( m_menu1612, wxID_ANY, wxString( wxT("Export WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1612->Append( m_menu_export12 );
	
	m_menu1612->AppendSeparator();
	
	wxMenuItem* m_menu_purge12;
	m_menu_purge12 = new wxMenuItem( m_menu1612, wxID_ANY, wxString( wxT("Purge") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1612->Append( m_menu_purge12 );
	
	m_panel155->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( SoundLoopPanel::m_panel155OnContextMenu ), NULL, this ); 
	
	fgSizer25->Add( m_panel155, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
	this->SetSizer( fgSizer25 );
	this->Layout();
	m_menu16111 = new wxMenu();
	wxMenuItem* m_menu_load111;
	m_menu_load111 = new wxMenuItem( m_menu16111, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu16111->Append( m_menu_load111 );
	
	wxMenuItem* m_menu_save111;
	m_menu_save111 = new wxMenuItem( m_menu16111, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu16111->Append( m_menu_save111 );
	
	m_menu16111->AppendSeparator();
	
	wxMenuItem* m_menu_get_sound111;
	m_menu_get_sound111 = new wxMenuItem( m_menu16111, wxID_ANY, wxString( wxT("Get Sound") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu16111->Append( m_menu_get_sound111 );
	
	wxMenuItem* m_menu_get_sound_param111;
	m_menu_get_sound_param111 = new wxMenuItem( m_menu16111, wxID_ANY, wxString( wxT("Get Sound Parameters") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu16111->Append( m_menu_get_sound_param111 );
	
	m_menu16111->AppendSeparator();
	
	wxMenuItem* m_menu_copy111;
	m_menu_copy111 = new wxMenuItem( m_menu16111, wxID_ANY, wxString( wxT("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu16111->Append( m_menu_copy111 );
	
	wxMenuItem* m_menu_copyparamtoall3;
	m_menu_copyparamtoall3 = new wxMenuItem( m_menu16111, wxID_ANY, wxString( wxT("Copy Parameters to all") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu16111->Append( m_menu_copyparamtoall3 );
	
	m_menu16111->AppendSeparator();
	
	wxMenuItem* m_menu_delete_sound111;
	m_menu_delete_sound111 = new wxMenuItem( m_menu16111, wxID_ANY, wxString( wxT("Delete sample data") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu16111->Append( m_menu_delete_sound111 );
	
	m_menu16111->AppendSeparator();
	
	wxMenuItem* m_menu_import111;
	m_menu_import111 = new wxMenuItem( m_menu16111, wxID_ANY, wxString( wxT("Import WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu16111->Append( m_menu_import111 );
	
	wxMenuItem* m_menu_export111;
	m_menu_export111 = new wxMenuItem( m_menu16111, wxID_ANY, wxString( wxT("Export WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu16111->Append( m_menu_export111 );
	
	m_menu16111->AppendSeparator();
	
	wxMenuItem* m_menu_purge111;
	m_menu_purge111 = new wxMenuItem( m_menu16111, wxID_ANY, wxString( wxT("Purge") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu16111->Append( m_menu_purge111 );
	
	this->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( SoundLoopPanel::SoundLoopPanelOnContextMenu ), NULL, this ); 
	
	
	// Connect Events
	this->Connect( m_menu_load1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnLoad ) );
	this->Connect( m_menu_save1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnSave ) );
	this->Connect( m_menu_get_sound1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnGetSound ) );
	this->Connect( m_menu_get_sound_param1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnGetSoundParam ) );
	this->Connect( m_menu_copy1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnCopy ) );
	this->Connect( m_menu_copyparamtoall->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnCopyParamToAll ) );
	this->Connect( m_menu_delete_sound1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnDeleteSound ) );
	this->Connect( m_menu_import1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnImport ) );
	this->Connect( m_menu_export1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnExport ) );
	this->Connect( m_menu_purge1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnPurge ) );
	m_start_point->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoundLoopPanel::OnStartPoint ), NULL, this );
	m_button23->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveStartPointBackward10 ), NULL, this );
	m_button33->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveStartPointBackward1 ), NULL, this );
	m_button43->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveStartPointForward1 ), NULL, this );
	m_button53->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveStartPointForward10 ), NULL, this );
	m_sustainloop_start->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoundLoopPanel::OnSustainLoopStart ), NULL, this );
	m_button212->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveSustainStartPointBackward10 ), NULL, this );
	m_button313->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveSustainStartPointBackward1 ), NULL, this );
	m_button413->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveSustainStartPointForward1 ), NULL, this );
	m_button513->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveSustainStartPointForward10 ), NULL, this );
	m_releaseloop_start->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoundLoopPanel::OnReleaseLoopStart ), NULL, this );
	m_button2113->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveReleaseStartPointBackward10 ), NULL, this );
	m_button3112->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveReleaseStartPointBackward1 ), NULL, this );
	m_button4112->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveReleaseStartPointForward1 ), NULL, this );
	m_button5112->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveReleaseStartPointForward10 ), NULL, this );
	m_end_point->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoundLoopPanel::OnEndPoint ), NULL, this );
	m_button221->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveEndPointBackward10 ), NULL, this );
	m_button321->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveEndPointBackward1 ), NULL, this );
	m_button421->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveEndPointForward1 ), NULL, this );
	m_button521->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveEndPointForward10 ), NULL, this );
	m_sustainloop_end->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoundLoopPanel::OnSustainLoopEnd ), NULL, this );
	m_button21111->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveSustainEndPointBackward10 ), NULL, this );
	m_button3121->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveSustainEndPointBackward1 ), NULL, this );
	m_button4121->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveSustainEndPointForward1 ), NULL, this );
	m_button5121->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveSustainEndPointForward10 ), NULL, this );
	m_releaseloop_end->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoundLoopPanel::OnReleaseLoopEnd ), NULL, this );
	m_button21121->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveReleaseEndPointBackward10 ), NULL, this );
	m_button31111->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveReleaseEndPointBackward1 ), NULL, this );
	m_button41111->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveReleaseEndPointForward1 ), NULL, this );
	m_button51111->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveReleaseEndPointForward10 ), NULL, this );
	this->Connect( m_menu_load11->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnLoad ) );
	this->Connect( m_menu_save11->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnSave ) );
	this->Connect( m_menu_get_sound11->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnGetSound ) );
	this->Connect( m_menu_get_sound_param11->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnGetSoundParam ) );
	this->Connect( m_menu_copy11->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnCopy ) );
	this->Connect( m_menu_copyparamtoall1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnCopyParamToAll ) );
	this->Connect( m_menu_delete_sound11->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnDeleteSound ) );
	this->Connect( m_menu_import11->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnImport ) );
	this->Connect( m_menu_export11->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnExport ) );
	this->Connect( m_menu_purge11->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnPurge ) );
	m_sust_loop_ena->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnSustLoopChange ), NULL, this );
	m_reverse_ena->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnCheckboxChange ), NULL, this );
	m_play_button->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnPlay ), NULL, this );
	m_forward_loop_ena->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnForwardLoopChange ), NULL, this );
	m_wave_selection->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnWaveSelection ), NULL, this );
	m_release_loop_ena->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnCheckboxChange ), NULL, this );
	m_velocity_start_point->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_tune_table->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_tune_table->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_tune_table->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_tune_table->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_tune_table->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_tune_table->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_tune_table->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_tune_table->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_tune_table->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	this->Connect( m_menu_load12->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnLoad ) );
	this->Connect( m_menu_save12->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnSave ) );
	this->Connect( m_menu_get_sound12->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnGetSound ) );
	this->Connect( m_menu_get_sound_param12->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnGetSoundParam ) );
	this->Connect( m_menu_copy12->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnCopy ) );
	this->Connect( m_menu_copyparamtoall2->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnCopyParamToAll ) );
	this->Connect( m_menu_delete_sound12->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnDeleteSound ) );
	this->Connect( m_menu_import12->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnImport ) );
	this->Connect( m_menu_export12->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnExport ) );
	this->Connect( m_menu_purge12->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnPurge ) );
	this->Connect( m_menu_load111->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnLoad ) );
	this->Connect( m_menu_save111->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnSave ) );
	this->Connect( m_menu_get_sound111->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnGetSound ) );
	this->Connect( m_menu_get_sound_param111->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnGetSoundParam ) );
	this->Connect( m_menu_copy111->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnCopy ) );
	this->Connect( m_menu_copyparamtoall3->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnCopyParamToAll ) );
	this->Connect( m_menu_delete_sound111->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnDeleteSound ) );
	this->Connect( m_menu_import111->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnImport ) );
	this->Connect( m_menu_export111->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnExport ) );
	this->Connect( m_menu_purge111->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnPurge ) );
}

SoundLoopPanel::~SoundLoopPanel()
{
	// Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnGetSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnGetSoundParam ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnCopy ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnCopyParamToAll ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnDeleteSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnImport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnExport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnPurge ) );
	m_start_point->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoundLoopPanel::OnStartPoint ), NULL, this );
	m_button23->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveStartPointBackward10 ), NULL, this );
	m_button33->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveStartPointBackward1 ), NULL, this );
	m_button43->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveStartPointForward1 ), NULL, this );
	m_button53->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveStartPointForward10 ), NULL, this );
	m_sustainloop_start->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoundLoopPanel::OnSustainLoopStart ), NULL, this );
	m_button212->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveSustainStartPointBackward10 ), NULL, this );
	m_button313->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveSustainStartPointBackward1 ), NULL, this );
	m_button413->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveSustainStartPointForward1 ), NULL, this );
	m_button513->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveSustainStartPointForward10 ), NULL, this );
	m_releaseloop_start->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoundLoopPanel::OnReleaseLoopStart ), NULL, this );
	m_button2113->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveReleaseStartPointBackward10 ), NULL, this );
	m_button3112->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveReleaseStartPointBackward1 ), NULL, this );
	m_button4112->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveReleaseStartPointForward1 ), NULL, this );
	m_button5112->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveReleaseStartPointForward10 ), NULL, this );
	m_end_point->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoundLoopPanel::OnEndPoint ), NULL, this );
	m_button221->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveEndPointBackward10 ), NULL, this );
	m_button321->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveEndPointBackward1 ), NULL, this );
	m_button421->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveEndPointForward1 ), NULL, this );
	m_button521->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveEndPointForward10 ), NULL, this );
	m_sustainloop_end->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoundLoopPanel::OnSustainLoopEnd ), NULL, this );
	m_button21111->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveSustainEndPointBackward10 ), NULL, this );
	m_button3121->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveSustainEndPointBackward1 ), NULL, this );
	m_button4121->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveSustainEndPointForward1 ), NULL, this );
	m_button5121->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveSustainEndPointForward10 ), NULL, this );
	m_releaseloop_end->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoundLoopPanel::OnReleaseLoopEnd ), NULL, this );
	m_button21121->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveReleaseEndPointBackward10 ), NULL, this );
	m_button31111->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveReleaseEndPointBackward1 ), NULL, this );
	m_button41111->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveReleaseEndPointForward1 ), NULL, this );
	m_button51111->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnMoveReleaseEndPointForward10 ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnGetSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnGetSoundParam ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnCopy ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnCopyParamToAll ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnDeleteSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnImport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnExport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnPurge ) );
	m_sust_loop_ena->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnSustLoopChange ), NULL, this );
	m_reverse_ena->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnCheckboxChange ), NULL, this );
	m_play_button->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnPlay ), NULL, this );
	m_forward_loop_ena->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnForwardLoopChange ), NULL, this );
	m_wave_selection->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnWaveSelection ), NULL, this );
	m_release_loop_ena->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SoundLoopPanel::OnCheckboxChange ), NULL, this );
	m_velocity_start_point->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_tune_table->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_tune_table->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_tune_table->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_tune_table->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_tune_table->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_tune_table->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_tune_table->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_tune_table->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	m_tune_table->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundLoopPanel::OnSliderChange ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnGetSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnGetSoundParam ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnCopy ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnCopyParamToAll ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnDeleteSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnImport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnExport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnPurge ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnGetSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnGetSoundParam ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnCopy ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnCopyParamToAll ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnDeleteSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnImport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnExport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundLoopPanel::OnPurge ) );
	
	delete m_menu161; 
	delete m_menu1611; 
	delete m_menu1612; 
	delete m_menu16111; 
}

SoundSamplePanel::SoundSamplePanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	this->SetMinSize( wxSize( -1,410 ) );
	this->SetMaxSize( wxSize( -1,410 ) );
	
	wxFlexGridSizer* fgSizer57;
	fgSizer57 = new wxFlexGridSizer( 0, 5, 0, 0 );
	fgSizer57->AddGrowableCol( 0 );
	fgSizer57->AddGrowableCol( 1 );
	fgSizer57->AddGrowableCol( 2 );
	fgSizer57->SetFlexibleDirection( wxBOTH );
	fgSizer57->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_panel66 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer58;
	fgSizer58 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer58->SetFlexibleDirection( wxBOTH );
	fgSizer58->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText463 = new wxStaticText( m_panel66, wxID_ANY, wxT("Mem"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText463->Wrap( -1 );
	m_staticText463->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer58->Add( m_staticText463, 0, wxALIGN_RIGHT|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_staticText471 = new wxStaticText( m_panel66, wxID_ANY, wxT("ory"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText471->Wrap( -1 );
	m_staticText471->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer58->Add( m_staticText471, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_staticText488 = new wxStaticText( m_panel66, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,14 ), 0 );
	m_staticText488->Wrap( -1 );
	fgSizer58->Add( m_staticText488, 0, wxALL, 5 );
	
	m_staticText489 = new wxStaticText( m_panel66, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText489->Wrap( -1 );
	fgSizer58->Add( m_staticText489, 0, wxALL, 5 );
	
	m_staticText472 = new wxStaticText( m_panel66, wxID_ANY, wxT("Begin Address"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText472->Wrap( -1 );
	fgSizer58->Add( m_staticText472, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_begin_addr = new wxTextCtrl( m_panel66, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 90,-1 ), wxTE_READONLY );
	m_begin_addr->SetMaxLength( 0 ); 
	fgSizer58->Add( m_begin_addr, 0, wxALL, 5 );
	
	m_staticText464 = new wxStaticText( m_panel66, wxID_ANY, wxT("Start Address"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText464->Wrap( -1 );
	fgSizer58->Add( m_staticText464, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_start_point_addr = new wxTextCtrl( m_panel66, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 90,-1 ), wxTE_READONLY );
	m_start_point_addr->SetMaxLength( 0 ); 
	fgSizer58->Add( m_start_point_addr, 0, wxALL, 5 );
	
	m_staticText465 = new wxStaticText( m_panel66, wxID_ANY, wxT("Sustain Loop Start"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText465->Wrap( -1 );
	fgSizer58->Add( m_staticText465, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_sustain_loop_start_addr = new wxTextCtrl( m_panel66, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 90,-1 ), wxTE_READONLY );
	m_sustain_loop_start_addr->SetMaxLength( 0 ); 
	fgSizer58->Add( m_sustain_loop_start_addr, 0, wxALL, 5 );
	
	m_staticText466 = new wxStaticText( m_panel66, wxID_ANY, wxT("Sustain Loop End"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText466->Wrap( -1 );
	fgSizer58->Add( m_staticText466, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_sustain_loop_end_addr = new wxTextCtrl( m_panel66, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 90,-1 ), wxTE_READONLY );
	m_sustain_loop_end_addr->SetMaxLength( 0 ); 
	fgSizer58->Add( m_sustain_loop_end_addr, 0, wxALL, 5 );
	
	m_staticText467 = new wxStaticText( m_panel66, wxID_ANY, wxT("Release Loop Start"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText467->Wrap( -1 );
	fgSizer58->Add( m_staticText467, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_release_loop_start_addr = new wxTextCtrl( m_panel66, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 90,-1 ), wxTE_READONLY );
	m_release_loop_start_addr->SetMaxLength( 0 ); 
	fgSizer58->Add( m_release_loop_start_addr, 0, wxALL, 5 );
	
	m_staticText468 = new wxStaticText( m_panel66, wxID_ANY, wxT("Release Loop End"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText468->Wrap( -1 );
	fgSizer58->Add( m_staticText468, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_release_loop_end_addr = new wxTextCtrl( m_panel66, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 90,-1 ), wxTE_READONLY );
	m_release_loop_end_addr->SetMaxLength( 0 ); 
	fgSizer58->Add( m_release_loop_end_addr, 0, wxALL, 5 );
	
	m_staticText469 = new wxStaticText( m_panel66, wxID_ANY, wxT("End Address"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText469->Wrap( -1 );
	fgSizer58->Add( m_staticText469, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_end_point_addr = new wxTextCtrl( m_panel66, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 90,-1 ), wxTE_READONLY );
	m_end_point_addr->SetMaxLength( 0 ); 
	fgSizer58->Add( m_end_point_addr, 0, wxALL, 5 );
	
	m_staticText470 = new wxStaticText( m_panel66, wxID_ANY, wxT("Finish Address"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText470->Wrap( -1 );
	fgSizer58->Add( m_staticText470, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_finish_addr = new wxTextCtrl( m_panel66, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 90,-1 ), wxTE_READONLY );
	m_finish_addr->SetMaxLength( 0 ); 
	fgSizer58->Add( m_finish_addr, 0, wxALL, 5 );
	
	
	m_panel66->SetSizer( fgSizer58 );
	m_panel66->Layout();
	fgSizer58->Fit( m_panel66 );
	m_menu1611 = new wxMenu();
	wxMenuItem* m_menu_load11;
	m_menu_load11 = new wxMenuItem( m_menu1611, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1611->Append( m_menu_load11 );
	
	wxMenuItem* m_menu_save11;
	m_menu_save11 = new wxMenuItem( m_menu1611, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1611->Append( m_menu_save11 );
	
	m_menu1611->AppendSeparator();
	
	wxMenuItem* m_menu_get_sound11;
	m_menu_get_sound11 = new wxMenuItem( m_menu1611, wxID_ANY, wxString( wxT("Get Sound") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1611->Append( m_menu_get_sound11 );
	
	wxMenuItem* m_menu_get_sound_param11;
	m_menu_get_sound_param11 = new wxMenuItem( m_menu1611, wxID_ANY, wxString( wxT("Get Sound Parameters") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1611->Append( m_menu_get_sound_param11 );
	
	m_menu1611->AppendSeparator();
	
	wxMenuItem* m_menu_copy11;
	m_menu_copy11 = new wxMenuItem( m_menu1611, wxID_ANY, wxString( wxT("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1611->Append( m_menu_copy11 );
	
	wxMenuItem* m_menu_copyparamtoall;
	m_menu_copyparamtoall = new wxMenuItem( m_menu1611, wxID_ANY, wxString( wxT("Copy Parameters to all") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1611->Append( m_menu_copyparamtoall );
	
	m_menu1611->AppendSeparator();
	
	wxMenuItem* m_menu_delete_sound11;
	m_menu_delete_sound11 = new wxMenuItem( m_menu1611, wxID_ANY, wxString( wxT("Delete sample data") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1611->Append( m_menu_delete_sound11 );
	
	m_menu1611->AppendSeparator();
	
	wxMenuItem* m_menu_import11;
	m_menu_import11 = new wxMenuItem( m_menu1611, wxID_ANY, wxString( wxT("Import WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1611->Append( m_menu_import11 );
	
	wxMenuItem* m_menu_export11;
	m_menu_export11 = new wxMenuItem( m_menu1611, wxID_ANY, wxString( wxT("Export WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1611->Append( m_menu_export11 );
	
	m_menu1611->AppendSeparator();
	
	wxMenuItem* m_menu_purge11;
	m_menu_purge11 = new wxMenuItem( m_menu1611, wxID_ANY, wxString( wxT("Purge") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1611->Append( m_menu_purge11 );
	
	m_panel66->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( SoundSamplePanel::m_panel66OnContextMenu ), NULL, this ); 
	
	fgSizer57->Add( m_panel66, 1, wxEXPAND|wxALL, 5 );
	
	m_panel68 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer60;
	fgSizer60 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer60->SetFlexibleDirection( wxBOTH );
	fgSizer60->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText494 = new wxStaticText( m_panel68, wxID_ANY, wxT("Sample"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText494->Wrap( -1 );
	m_staticText494->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer60->Add( m_staticText494, 0, wxALIGN_RIGHT|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_staticText495 = new wxStaticText( m_panel68, wxID_ANY, wxT(" Configuration"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText495->Wrap( -1 );
	m_staticText495->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer60->Add( m_staticText495, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_staticText496 = new wxStaticText( m_panel68, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText496->Wrap( -1 );
	fgSizer60->Add( m_staticText496, 0, wxALL, 5 );
	
	m_staticText497 = new wxStaticText( m_panel68, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText497->Wrap( -1 );
	fgSizer60->Add( m_staticText497, 0, wxALL, 5 );
	
	m_staticText498 = new wxStaticText( m_panel68, wxID_ANY, wxT("Velocity Start"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText498->Wrap( -1 );
	fgSizer60->Add( m_staticText498, 0, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_velocity_start_point = new wxSlider( m_panel68, wxID_ANY, 0, -127, 127, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS|wxSUNKEN_BORDER );
	fgSizer60->Add( m_velocity_start_point, 0, wxALL, 5 );
	
	m_staticText499 = new wxStaticText( m_panel68, wxID_ANY, wxT("Tune"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText499->Wrap( -1 );
	fgSizer60->Add( m_staticText499, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_tune_table = new wxSlider( m_panel68, wxID_ANY, 0, 0, 22, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_INVERSE|wxSL_LABELS|wxSUNKEN_BORDER );
	m_tune_table->SetToolTip( wxT("Each step will tune the sample down by ~4.5% of a semitone") );
	
	fgSizer60->Add( m_tune_table, 0, wxALIGN_BOTTOM|wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText504 = new wxStaticText( m_panel68, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,1 ), 0 );
	m_staticText504->Wrap( -1 );
	fgSizer60->Add( m_staticText504, 0, wxALL, 5 );
	
	m_staticText505 = new wxStaticText( m_panel68, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,5 ), 0 );
	m_staticText505->Wrap( -1 );
	fgSizer60->Add( m_staticText505, 0, wxALL, 5 );
	
	m_staticText500 = new wxStaticText( m_panel68, wxID_ANY, wxT("Root Key"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText500->Wrap( -1 );
	fgSizer60->Add( m_staticText500, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_root_key = new wxTextCtrl( m_panel68, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	m_root_key->SetMaxLength( 0 ); 
	fgSizer60->Add( m_root_key, 0, wxALIGN_BOTTOM|wxALL, 5 );
	
	m_staticText501 = new wxStaticText( m_panel68, wxID_ANY, wxT("Sample Rate"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText501->Wrap( -1 );
	fgSizer60->Add( m_staticText501, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_sample_rate = new wxTextCtrl( m_panel68, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_sample_rate->SetMaxLength( 0 ); 
	fgSizer60->Add( m_sample_rate, 0, wxALL, 5 );
	
	m_sample_deleted = new wxCheckBox( m_panel68, wxID_ANY, wxT("Sample deleted"), wxDefaultPosition, wxDefaultSize, 0 );
	m_sample_deleted->Enable( false );
	
	fgSizer60->Add( m_sample_deleted, 0, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText502 = new wxStaticText( m_panel68, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,20 ), 0 );
	m_staticText502->Wrap( -1 );
	fgSizer60->Add( m_staticText502, 0, wxALL, 5 );
	
	m_sampled = new wxCheckBox( m_panel68, wxID_ANY, wxT("Sampled"), wxDefaultPosition, wxDefaultSize, 0 );
	m_sampled->Enable( false );
	
	fgSizer60->Add( m_sampled, 0, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_BOTTOM, 5 );
	
	m_staticText503 = new wxStaticText( m_panel68, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,16 ), 0 );
	m_staticText503->Wrap( -1 );
	fgSizer60->Add( m_staticText503, 0, wxALL|wxALIGN_BOTTOM, 5 );
	
	
	m_panel68->SetSizer( fgSizer60 );
	m_panel68->Layout();
	fgSizer60->Fit( m_panel68 );
	m_menu1612 = new wxMenu();
	wxMenuItem* m_menu_load12;
	m_menu_load12 = new wxMenuItem( m_menu1612, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1612->Append( m_menu_load12 );
	
	wxMenuItem* m_menu_save12;
	m_menu_save12 = new wxMenuItem( m_menu1612, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1612->Append( m_menu_save12 );
	
	m_menu1612->AppendSeparator();
	
	wxMenuItem* m_menu_get_sound12;
	m_menu_get_sound12 = new wxMenuItem( m_menu1612, wxID_ANY, wxString( wxT("Get Sound") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1612->Append( m_menu_get_sound12 );
	
	wxMenuItem* m_menu_get_sound_param12;
	m_menu_get_sound_param12 = new wxMenuItem( m_menu1612, wxID_ANY, wxString( wxT("Get Sound Parameters") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1612->Append( m_menu_get_sound_param12 );
	
	m_menu1612->AppendSeparator();
	
	wxMenuItem* m_menu_copy12;
	m_menu_copy12 = new wxMenuItem( m_menu1612, wxID_ANY, wxString( wxT("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1612->Append( m_menu_copy12 );
	
	wxMenuItem* m_menu_copyparamtoall1;
	m_menu_copyparamtoall1 = new wxMenuItem( m_menu1612, wxID_ANY, wxString( wxT("Copy Parameters to all") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1612->Append( m_menu_copyparamtoall1 );
	
	m_menu1612->AppendSeparator();
	
	wxMenuItem* m_menu_delete_sound12;
	m_menu_delete_sound12 = new wxMenuItem( m_menu1612, wxID_ANY, wxString( wxT("Delete sample data") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1612->Append( m_menu_delete_sound12 );
	
	m_menu1612->AppendSeparator();
	
	wxMenuItem* m_menu_import12;
	m_menu_import12 = new wxMenuItem( m_menu1612, wxID_ANY, wxString( wxT("Import WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1612->Append( m_menu_import12 );
	
	wxMenuItem* m_menu_export12;
	m_menu_export12 = new wxMenuItem( m_menu1612, wxID_ANY, wxString( wxT("Export WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1612->Append( m_menu_export12 );
	
	m_menu1612->AppendSeparator();
	
	wxMenuItem* m_menu_purge12;
	m_menu_purge12 = new wxMenuItem( m_menu1612, wxID_ANY, wxString( wxT("Purge") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1612->Append( m_menu_purge12 );
	
	m_panel68->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( SoundSamplePanel::m_panel68OnContextMenu ), NULL, this ); 
	
	fgSizer57->Add( m_panel68, 1, wxEXPAND|wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_panel67 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer59;
	fgSizer59 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer59->AddGrowableCol( 0 );
	fgSizer59->AddGrowableCol( 1 );
	fgSizer59->AddGrowableCol( 2 );
	fgSizer59->AddGrowableCol( 3 );
	fgSizer59->SetFlexibleDirection( wxBOTH );
	fgSizer59->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText473 = new wxStaticText( m_panel67, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText473->Wrap( -1 );
	fgSizer59->Add( m_staticText473, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	m_staticText474 = new wxStaticText( m_panel67, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText474->Wrap( -1 );
	fgSizer59->Add( m_staticText474, 0, wxALL, 5 );
	
	m_staticText475 = new wxStaticText( m_panel67, wxID_ANY, wxT("Map Configuration"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText475->Wrap( -1 );
	m_staticText475->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer59->Add( m_staticText475, 0, wxALL, 5 );
	
	m_staticText476 = new wxStaticText( m_panel67, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText476->Wrap( -1 );
	fgSizer59->Add( m_staticText476, 0, wxALL, 5 );
	
	m_staticText490 = new wxStaticText( m_panel67, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText490->Wrap( -1 );
	fgSizer59->Add( m_staticText490, 0, wxALL, 5 );
	
	m_staticText491 = new wxStaticText( m_panel67, wxID_ANY, wxT("High Key"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText491->Wrap( -1 );
	fgSizer59->Add( m_staticText491, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText492 = new wxStaticText( m_panel67, wxID_ANY, wxT("Transpose"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText492->Wrap( -1 );
	fgSizer59->Add( m_staticText492, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText493 = new wxStaticText( m_panel67, wxID_ANY, wxT("Volume"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText493->Wrap( -1 );
	m_staticText493->SetToolTip( wxT("Controls Volume per Map") );
	
	fgSizer59->Add( m_staticText493, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	relative_mix_map1_txt = new wxStaticText( m_panel67, wxID_ANY, wxT(" Map 1"), wxDefaultPosition, wxDefaultSize, 0 );
	relative_mix_map1_txt->Wrap( -1 );
	relative_mix_map1_txt->SetFont( wxFont( 8, 70, 90, 92, false, wxEmptyString ) );
	
	fgSizer59->Add( relative_mix_map1_txt, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_hi_key_map1 = new wxTextCtrl( m_panel67, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_PROCESS_ENTER );
	m_hi_key_map1->SetMaxLength( 0 ); 
	fgSizer59->Add( m_hi_key_map1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_transpose_map1 = new wxTextCtrl( m_panel67, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	m_transpose_map1->SetMaxLength( 0 ); 
	fgSizer59->Add( m_transpose_map1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_relative_mix_map1 = new wxSpinCtrl( m_panel67, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 255, 255 );
	fgSizer59->Add( m_relative_mix_map1, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	relative_mix_map2_txt = new wxStaticText( m_panel67, wxID_ANY, wxT(" Map 2"), wxDefaultPosition, wxDefaultSize, 0 );
	relative_mix_map2_txt->Wrap( -1 );
	relative_mix_map2_txt->SetFont( wxFont( 8, 70, 90, 92, false, wxEmptyString ) );
	
	fgSizer59->Add( relative_mix_map2_txt, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_hi_key_map2 = new wxTextCtrl( m_panel67, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_PROCESS_ENTER );
	m_hi_key_map2->SetMaxLength( 0 ); 
	fgSizer59->Add( m_hi_key_map2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_transpose_map2 = new wxTextCtrl( m_panel67, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	m_transpose_map2->SetMaxLength( 0 ); 
	fgSizer59->Add( m_transpose_map2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_relative_mix_map2 = new wxSpinCtrl( m_panel67, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 255, 255 );
	fgSizer59->Add( m_relative_mix_map2, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	relative_mix_map3_txt = new wxStaticText( m_panel67, wxID_ANY, wxT(" Map 3"), wxDefaultPosition, wxDefaultSize, 0 );
	relative_mix_map3_txt->Wrap( -1 );
	relative_mix_map3_txt->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer59->Add( relative_mix_map3_txt, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_hi_key_map3 = new wxTextCtrl( m_panel67, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_PROCESS_ENTER );
	m_hi_key_map3->SetMaxLength( 0 ); 
	fgSizer59->Add( m_hi_key_map3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_transpose_map3 = new wxTextCtrl( m_panel67, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	m_transpose_map3->SetMaxLength( 0 ); 
	fgSizer59->Add( m_transpose_map3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_relative_mix_map3 = new wxSpinCtrl( m_panel67, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 255, 255 );
	fgSizer59->Add( m_relative_mix_map3, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	relative_mix_map4_txt = new wxStaticText( m_panel67, wxID_ANY, wxT(" Map 4"), wxDefaultPosition, wxDefaultSize, 0 );
	relative_mix_map4_txt->Wrap( -1 );
	relative_mix_map4_txt->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer59->Add( relative_mix_map4_txt, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_hi_key_map4 = new wxTextCtrl( m_panel67, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_PROCESS_ENTER );
	m_hi_key_map4->SetMaxLength( 0 ); 
	fgSizer59->Add( m_hi_key_map4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_transpose_map4 = new wxTextCtrl( m_panel67, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	m_transpose_map4->SetMaxLength( 0 ); 
	fgSizer59->Add( m_transpose_map4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_relative_mix_map4 = new wxSpinCtrl( m_panel67, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 255, 255 );
	fgSizer59->Add( m_relative_mix_map4, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	relative_mix_map5_txt = new wxStaticText( m_panel67, wxID_ANY, wxT(" Map 5"), wxDefaultPosition, wxDefaultSize, 0 );
	relative_mix_map5_txt->Wrap( -1 );
	relative_mix_map5_txt->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer59->Add( relative_mix_map5_txt, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_hi_key_map5 = new wxTextCtrl( m_panel67, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_PROCESS_ENTER );
	m_hi_key_map5->SetMaxLength( 0 ); 
	fgSizer59->Add( m_hi_key_map5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_transpose_map5 = new wxTextCtrl( m_panel67, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	m_transpose_map5->SetMaxLength( 0 ); 
	fgSizer59->Add( m_transpose_map5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_relative_mix_map5 = new wxSpinCtrl( m_panel67, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 255, 255 );
	fgSizer59->Add( m_relative_mix_map5, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	relative_mix_map6_txt = new wxStaticText( m_panel67, wxID_ANY, wxT(" Map 6"), wxDefaultPosition, wxDefaultSize, 0 );
	relative_mix_map6_txt->Wrap( -1 );
	relative_mix_map6_txt->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer59->Add( relative_mix_map6_txt, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_hi_key_map6 = new wxTextCtrl( m_panel67, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_PROCESS_ENTER );
	m_hi_key_map6->SetMaxLength( 0 ); 
	fgSizer59->Add( m_hi_key_map6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_transpose_map6 = new wxTextCtrl( m_panel67, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	m_transpose_map6->SetMaxLength( 0 ); 
	fgSizer59->Add( m_transpose_map6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_relative_mix_map6 = new wxSpinCtrl( m_panel67, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 255, 255 );
	fgSizer59->Add( m_relative_mix_map6, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	relative_mix_map7_txt = new wxStaticText( m_panel67, wxID_ANY, wxT(" Map 7"), wxDefaultPosition, wxDefaultSize, 0 );
	relative_mix_map7_txt->Wrap( -1 );
	relative_mix_map7_txt->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer59->Add( relative_mix_map7_txt, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_hi_key_map7 = new wxTextCtrl( m_panel67, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_PROCESS_ENTER );
	m_hi_key_map7->SetMaxLength( 0 ); 
	fgSizer59->Add( m_hi_key_map7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_transpose_map7 = new wxTextCtrl( m_panel67, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	m_transpose_map7->SetMaxLength( 0 ); 
	fgSizer59->Add( m_transpose_map7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_relative_mix_map7 = new wxSpinCtrl( m_panel67, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 255, 255 );
	fgSizer59->Add( m_relative_mix_map7, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	relative_mix_map8_txt = new wxStaticText( m_panel67, wxID_ANY, wxT(" Map 8"), wxDefaultPosition, wxDefaultSize, 0 );
	relative_mix_map8_txt->Wrap( -1 );
	relative_mix_map8_txt->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer59->Add( relative_mix_map8_txt, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_hi_key_map8 = new wxTextCtrl( m_panel67, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_PROCESS_ENTER );
	m_hi_key_map8->SetMaxLength( 0 ); 
	fgSizer59->Add( m_hi_key_map8, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_transpose_map8 = new wxTextCtrl( m_panel67, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_READONLY );
	m_transpose_map8->SetMaxLength( 0 ); 
	fgSizer59->Add( m_transpose_map8, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_relative_mix_map8 = new wxSpinCtrl( m_panel67, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 255, 255 );
	fgSizer59->Add( m_relative_mix_map8, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	
	m_panel67->SetSizer( fgSizer59 );
	m_panel67->Layout();
	fgSizer59->Fit( m_panel67 );
	m_menu161 = new wxMenu();
	wxMenuItem* m_menu_load1;
	m_menu_load1 = new wxMenuItem( m_menu161, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu161->Append( m_menu_load1 );
	
	wxMenuItem* m_menu_save1;
	m_menu_save1 = new wxMenuItem( m_menu161, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu161->Append( m_menu_save1 );
	
	m_menu161->AppendSeparator();
	
	wxMenuItem* m_menu_get_sound1;
	m_menu_get_sound1 = new wxMenuItem( m_menu161, wxID_ANY, wxString( wxT("Get Sound") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu161->Append( m_menu_get_sound1 );
	
	wxMenuItem* m_menu_get_sound_param1;
	m_menu_get_sound_param1 = new wxMenuItem( m_menu161, wxID_ANY, wxString( wxT("Get Sound Parameters") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu161->Append( m_menu_get_sound_param1 );
	
	m_menu161->AppendSeparator();
	
	wxMenuItem* m_menu_copy1;
	m_menu_copy1 = new wxMenuItem( m_menu161, wxID_ANY, wxString( wxT("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu161->Append( m_menu_copy1 );
	
	wxMenuItem* m_menu_copyparamtoall2;
	m_menu_copyparamtoall2 = new wxMenuItem( m_menu161, wxID_ANY, wxString( wxT("Copy Parameters to all") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu161->Append( m_menu_copyparamtoall2 );
	
	m_menu161->AppendSeparator();
	
	wxMenuItem* m_menu_delete_sound1;
	m_menu_delete_sound1 = new wxMenuItem( m_menu161, wxID_ANY, wxString( wxT("Delete sample data") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu161->Append( m_menu_delete_sound1 );
	
	m_menu161->AppendSeparator();
	
	wxMenuItem* m_menu_import1;
	m_menu_import1 = new wxMenuItem( m_menu161, wxID_ANY, wxString( wxT("Import WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu161->Append( m_menu_import1 );
	
	wxMenuItem* m_menu_export1;
	m_menu_export1 = new wxMenuItem( m_menu161, wxID_ANY, wxString( wxT("Export WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu161->Append( m_menu_export1 );
	
	m_menu161->AppendSeparator();
	
	wxMenuItem* m_menu_purge1;
	m_menu_purge1 = new wxMenuItem( m_menu161, wxID_ANY, wxString( wxT("Purge") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu161->Append( m_menu_purge1 );
	
	m_panel67->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( SoundSamplePanel::m_panel67OnContextMenu ), NULL, this ); 
	
	fgSizer57->Add( m_panel67, 1, wxEXPAND|wxALIGN_RIGHT|wxALL, 5 );
	
	m_staticText281 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 1,-1 ), 0 );
	m_staticText281->Wrap( -1 );
	fgSizer57->Add( m_staticText281, 0, wxTOP|wxBOTTOM|wxALIGN_RIGHT, 5 );
	
	m_panel62 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer54;
	fgSizer54 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer54->SetFlexibleDirection( wxBOTH );
	fgSizer54->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText276 = new wxStaticText( m_panel62, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText276->Wrap( -1 );
	fgSizer54->Add( m_staticText276, 0, wxRIGHT|wxLEFT, 5 );
	
	m_staticText277 = new wxStaticText( m_panel62, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText277->Wrap( -1 );
	fgSizer54->Add( m_staticText277, 0, wxRIGHT|wxLEFT, 5 );
	
	m_staticText290 = new wxStaticText( m_panel62, wxID_ANY, wxT("Used "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText290->Wrap( -1 );
	fgSizer54->Add( m_staticText290, 0, wxALIGN_BOTTOM|wxALIGN_RIGHT|wxBOTTOM, 5 );
	
	m_staticText291 = new wxStaticText( m_panel62, wxID_ANY, wxT("in Map"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText291->Wrap( -1 );
	fgSizer54->Add( m_staticText291, 0, wxEXPAND|wxALIGN_BOTTOM|wxALIGN_RIGHT|wxBOTTOM, 5 );
	
	m_used_in_map1 = new wxToggleButton( m_panel62, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_used_in_map1->SetMinSize( wxSize( 32,-1 ) );
	
	fgSizer54->Add( m_used_in_map1, 1, wxTOP|wxBOTTOM|wxEXPAND|wxALIGN_RIGHT, 5 );
	
	m_used_in_map2 = new wxToggleButton( m_panel62, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_used_in_map2->SetMinSize( wxSize( 32,-1 ) );
	
	fgSizer54->Add( m_used_in_map2, 1, wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	m_used_in_map3 = new wxToggleButton( m_panel62, wxID_ANY, wxT("3"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_used_in_map3->SetMinSize( wxSize( 30,-1 ) );
	
	fgSizer54->Add( m_used_in_map3, 1, wxEXPAND|wxTOP|wxBOTTOM, 5 );
	
	m_used_in_map4 = new wxToggleButton( m_panel62, wxID_ANY, wxT("4"), wxDefaultPosition, wxSize( 30,-1 ), wxDOUBLE_BORDER );
	fgSizer54->Add( m_used_in_map4, 1, wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	m_used_in_map5 = new wxToggleButton( m_panel62, wxID_ANY, wxT("5"), wxDefaultPosition, wxSize( 30,-1 ), wxDOUBLE_BORDER );
	fgSizer54->Add( m_used_in_map5, 1, wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	m_used_in_map6 = new wxToggleButton( m_panel62, wxID_ANY, wxT("6"), wxDefaultPosition, wxSize( 30,-1 ), wxDOUBLE_BORDER );
	fgSizer54->Add( m_used_in_map6, 1, wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	m_used_in_map7 = new wxToggleButton( m_panel62, wxID_ANY, wxT("7"), wxDefaultPosition, wxSize( 30,-1 ), wxDOUBLE_BORDER );
	fgSizer54->Add( m_used_in_map7, 1, wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	m_used_in_map8 = new wxToggleButton( m_panel62, wxID_ANY, wxT("8"), wxDefaultPosition, wxSize( 30,-1 ), wxDOUBLE_BORDER );
	fgSizer54->Add( m_used_in_map8, 1, wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	
	fgSizer54->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	fgSizer54->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	m_panel62->SetSizer( fgSizer54 );
	m_panel62->Layout();
	fgSizer54->Fit( m_panel62 );
	m_menu1613 = new wxMenu();
	wxMenuItem* m_menu_load13;
	m_menu_load13 = new wxMenuItem( m_menu1613, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1613->Append( m_menu_load13 );
	
	wxMenuItem* m_menu_save13;
	m_menu_save13 = new wxMenuItem( m_menu1613, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1613->Append( m_menu_save13 );
	
	m_menu1613->AppendSeparator();
	
	wxMenuItem* m_menu_get_sound13;
	m_menu_get_sound13 = new wxMenuItem( m_menu1613, wxID_ANY, wxString( wxT("Get Sound") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1613->Append( m_menu_get_sound13 );
	
	wxMenuItem* m_menu_get_sound_param13;
	m_menu_get_sound_param13 = new wxMenuItem( m_menu1613, wxID_ANY, wxString( wxT("Get Sound Parameters") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1613->Append( m_menu_get_sound_param13 );
	
	m_menu1613->AppendSeparator();
	
	wxMenuItem* m_menu_copy13;
	m_menu_copy13 = new wxMenuItem( m_menu1613, wxID_ANY, wxString( wxT("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1613->Append( m_menu_copy13 );
	
	wxMenuItem* m_menu_copyparamtoall3;
	m_menu_copyparamtoall3 = new wxMenuItem( m_menu1613, wxID_ANY, wxString( wxT("Copy Parameters to all") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1613->Append( m_menu_copyparamtoall3 );
	
	m_menu1613->AppendSeparator();
	
	wxMenuItem* m_menu_delete_sound13;
	m_menu_delete_sound13 = new wxMenuItem( m_menu1613, wxID_ANY, wxString( wxT("Delete sample data") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1613->Append( m_menu_delete_sound13 );
	
	m_menu1613->AppendSeparator();
	
	wxMenuItem* m_menu_import13;
	m_menu_import13 = new wxMenuItem( m_menu1613, wxID_ANY, wxString( wxT("Import WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1613->Append( m_menu_import13 );
	
	wxMenuItem* m_menu_export13;
	m_menu_export13 = new wxMenuItem( m_menu1613, wxID_ANY, wxString( wxT("Export WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1613->Append( m_menu_export13 );
	
	m_menu1613->AppendSeparator();
	
	wxMenuItem* m_menu_purge13;
	m_menu_purge13 = new wxMenuItem( m_menu1613, wxID_ANY, wxString( wxT("Purge") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1613->Append( m_menu_purge13 );
	
	m_panel62->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( SoundSamplePanel::m_panel62OnContextMenu ), NULL, this ); 
	
	fgSizer57->Add( m_panel62, 0, wxALIGN_RIGHT|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
	this->SetSizer( fgSizer57 );
	this->Layout();
	m_menu16111 = new wxMenu();
	wxMenuItem* m_menu_load111;
	m_menu_load111 = new wxMenuItem( m_menu16111, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu16111->Append( m_menu_load111 );
	
	wxMenuItem* m_menu_save111;
	m_menu_save111 = new wxMenuItem( m_menu16111, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu16111->Append( m_menu_save111 );
	
	m_menu16111->AppendSeparator();
	
	wxMenuItem* m_menu_get_sound111;
	m_menu_get_sound111 = new wxMenuItem( m_menu16111, wxID_ANY, wxString( wxT("Get Sound") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu16111->Append( m_menu_get_sound111 );
	
	wxMenuItem* m_menu_get_sound_param111;
	m_menu_get_sound_param111 = new wxMenuItem( m_menu16111, wxID_ANY, wxString( wxT("Get Sound Parameters") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu16111->Append( m_menu_get_sound_param111 );
	
	m_menu16111->AppendSeparator();
	
	wxMenuItem* m_menu_copy111;
	m_menu_copy111 = new wxMenuItem( m_menu16111, wxID_ANY, wxString( wxT("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu16111->Append( m_menu_copy111 );
	
	wxMenuItem* m_menu_copyparamtoall4;
	m_menu_copyparamtoall4 = new wxMenuItem( m_menu16111, wxID_ANY, wxString( wxT("Copy Parameters to all") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu16111->Append( m_menu_copyparamtoall4 );
	
	m_menu16111->AppendSeparator();
	
	wxMenuItem* m_menu_delete_sound111;
	m_menu_delete_sound111 = new wxMenuItem( m_menu16111, wxID_ANY, wxString( wxT("Delete sample data") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu16111->Append( m_menu_delete_sound111 );
	
	m_menu16111->AppendSeparator();
	
	wxMenuItem* m_menu_import111;
	m_menu_import111 = new wxMenuItem( m_menu16111, wxID_ANY, wxString( wxT("Import WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu16111->Append( m_menu_import111 );
	
	wxMenuItem* m_menu_export111;
	m_menu_export111 = new wxMenuItem( m_menu16111, wxID_ANY, wxString( wxT("Export WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu16111->Append( m_menu_export111 );
	
	m_menu16111->AppendSeparator();
	
	wxMenuItem* m_menu_purge111;
	m_menu_purge111 = new wxMenuItem( m_menu16111, wxID_ANY, wxString( wxT("Purge") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu16111->Append( m_menu_purge111 );
	
	this->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( SoundSamplePanel::SoundSamplePanelOnContextMenu ), NULL, this ); 
	
	
	// Connect Events
	this->Connect( m_menu_load11->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnLoad ) );
	this->Connect( m_menu_save11->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnSave ) );
	this->Connect( m_menu_get_sound11->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnGetSound ) );
	this->Connect( m_menu_get_sound_param11->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnGetSoundParam ) );
	this->Connect( m_menu_copy11->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnCopy ) );
	this->Connect( m_menu_copyparamtoall->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnCopyParamToAll ) );
	this->Connect( m_menu_delete_sound11->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnDeleteSound ) );
	this->Connect( m_menu_import11->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnImport ) );
	this->Connect( m_menu_export11->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnExport ) );
	this->Connect( m_menu_purge11->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnPurge ) );
	m_velocity_start_point->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_tune_table->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_tune_table->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_tune_table->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_tune_table->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_tune_table->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_tune_table->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_tune_table->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_tune_table->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_tune_table->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_root_key->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoundSamplePanel::OnRootKey ), NULL, this );
	m_sample_deleted->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SoundSamplePanel::OnCheckboxChange ), NULL, this );
	m_sampled->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SoundSamplePanel::OnCheckboxChange ), NULL, this );
	this->Connect( m_menu_load12->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnLoad ) );
	this->Connect( m_menu_save12->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnSave ) );
	this->Connect( m_menu_get_sound12->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnGetSound ) );
	this->Connect( m_menu_get_sound_param12->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnGetSoundParam ) );
	this->Connect( m_menu_copy12->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnCopy ) );
	this->Connect( m_menu_copyparamtoall1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnCopyParamToAll ) );
	this->Connect( m_menu_delete_sound12->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnDeleteSound ) );
	this->Connect( m_menu_import12->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnImport ) );
	this->Connect( m_menu_export12->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnExport ) );
	this->Connect( m_menu_purge12->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnPurge ) );
	m_hi_key_map1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoundSamplePanel::OnHighKey1 ), NULL, this );
	m_relative_mix_map1->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoundSamplePanel::OnSpinChange ), NULL, this );
	m_hi_key_map2->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoundSamplePanel::OnHighKey2 ), NULL, this );
	m_relative_mix_map2->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoundSamplePanel::OnSpinChange ), NULL, this );
	m_hi_key_map3->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoundSamplePanel::OnHighKey3 ), NULL, this );
	m_relative_mix_map3->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoundSamplePanel::OnSpinChange ), NULL, this );
	m_hi_key_map4->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoundSamplePanel::OnHighKey4 ), NULL, this );
	m_relative_mix_map4->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoundSamplePanel::OnSpinChange ), NULL, this );
	m_hi_key_map5->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoundSamplePanel::OnHighKey5 ), NULL, this );
	m_relative_mix_map5->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoundSamplePanel::OnSpinChange ), NULL, this );
	m_hi_key_map6->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoundSamplePanel::OnHighKey6 ), NULL, this );
	m_relative_mix_map6->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoundSamplePanel::OnSpinChange ), NULL, this );
	m_hi_key_map7->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SoundSamplePanel::OnHighKey7 ), NULL, this );
	m_relative_mix_map7->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoundSamplePanel::OnSpinChange ), NULL, this );
	m_hi_key_map8->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SoundSamplePanel::OnHighKey8 ), NULL, this );
	m_relative_mix_map8->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoundSamplePanel::OnSpinChange ), NULL, this );
	this->Connect( m_menu_load1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnLoad ) );
	this->Connect( m_menu_save1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnSave ) );
	this->Connect( m_menu_get_sound1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnGetSound ) );
	this->Connect( m_menu_get_sound_param1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnGetSoundParam ) );
	this->Connect( m_menu_copy1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnCopy ) );
	this->Connect( m_menu_copyparamtoall2->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnCopyParamToAll ) );
	this->Connect( m_menu_delete_sound1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnDeleteSound ) );
	this->Connect( m_menu_import1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnImport ) );
	this->Connect( m_menu_export1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnExport ) );
	this->Connect( m_menu_purge1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnPurge ) );
	m_used_in_map1->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSamplePanel::OnUsedInMap1 ), NULL, this );
	m_used_in_map2->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSamplePanel::OnUsedInMap2 ), NULL, this );
	m_used_in_map3->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSamplePanel::OnUsedInMap3 ), NULL, this );
	m_used_in_map4->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSamplePanel::OnUsedInMap4 ), NULL, this );
	m_used_in_map5->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSamplePanel::OnUsedInMap5 ), NULL, this );
	m_used_in_map6->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSamplePanel::OnUsedInMap6 ), NULL, this );
	m_used_in_map7->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSamplePanel::OnUsedInMap7 ), NULL, this );
	m_used_in_map8->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSamplePanel::OnUsedInMap8 ), NULL, this );
	this->Connect( m_menu_load13->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnLoad ) );
	this->Connect( m_menu_save13->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnSave ) );
	this->Connect( m_menu_get_sound13->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnGetSound ) );
	this->Connect( m_menu_get_sound_param13->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnGetSoundParam ) );
	this->Connect( m_menu_copy13->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnCopy ) );
	this->Connect( m_menu_copyparamtoall3->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnCopyParamToAll ) );
	this->Connect( m_menu_delete_sound13->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnDeleteSound ) );
	this->Connect( m_menu_import13->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnImport ) );
	this->Connect( m_menu_export13->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnExport ) );
	this->Connect( m_menu_purge13->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnPurge ) );
	this->Connect( m_menu_load111->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnLoad ) );
	this->Connect( m_menu_save111->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnSave ) );
	this->Connect( m_menu_get_sound111->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnGetSound ) );
	this->Connect( m_menu_get_sound_param111->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnGetSoundParam ) );
	this->Connect( m_menu_copy111->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnCopy ) );
	this->Connect( m_menu_copyparamtoall4->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnCopyParamToAll ) );
	this->Connect( m_menu_delete_sound111->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnDeleteSound ) );
	this->Connect( m_menu_import111->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnImport ) );
	this->Connect( m_menu_export111->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnExport ) );
	this->Connect( m_menu_purge111->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnPurge ) );
}

SoundSamplePanel::~SoundSamplePanel()
{
	// Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnGetSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnGetSoundParam ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnCopy ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnCopyParamToAll ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnDeleteSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnImport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnExport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnPurge ) );
	m_velocity_start_point->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_velocity_start_point->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_tune_table->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_tune_table->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_tune_table->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_tune_table->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_tune_table->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_tune_table->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_tune_table->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_tune_table->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_tune_table->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSamplePanel::OnSliderChange ), NULL, this );
	m_root_key->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoundSamplePanel::OnRootKey ), NULL, this );
	m_sample_deleted->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SoundSamplePanel::OnCheckboxChange ), NULL, this );
	m_sampled->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( SoundSamplePanel::OnCheckboxChange ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnGetSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnGetSoundParam ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnCopy ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnCopyParamToAll ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnDeleteSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnImport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnExport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnPurge ) );
	m_hi_key_map1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoundSamplePanel::OnHighKey1 ), NULL, this );
	m_relative_mix_map1->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoundSamplePanel::OnSpinChange ), NULL, this );
	m_hi_key_map2->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoundSamplePanel::OnHighKey2 ), NULL, this );
	m_relative_mix_map2->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoundSamplePanel::OnSpinChange ), NULL, this );
	m_hi_key_map3->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoundSamplePanel::OnHighKey3 ), NULL, this );
	m_relative_mix_map3->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoundSamplePanel::OnSpinChange ), NULL, this );
	m_hi_key_map4->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoundSamplePanel::OnHighKey4 ), NULL, this );
	m_relative_mix_map4->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoundSamplePanel::OnSpinChange ), NULL, this );
	m_hi_key_map5->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoundSamplePanel::OnHighKey5 ), NULL, this );
	m_relative_mix_map5->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoundSamplePanel::OnSpinChange ), NULL, this );
	m_hi_key_map6->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoundSamplePanel::OnHighKey6 ), NULL, this );
	m_relative_mix_map6->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoundSamplePanel::OnSpinChange ), NULL, this );
	m_hi_key_map7->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SoundSamplePanel::OnHighKey7 ), NULL, this );
	m_relative_mix_map7->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoundSamplePanel::OnSpinChange ), NULL, this );
	m_hi_key_map8->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( SoundSamplePanel::OnHighKey8 ), NULL, this );
	m_relative_mix_map8->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( SoundSamplePanel::OnSpinChange ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnGetSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnGetSoundParam ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnCopy ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnCopyParamToAll ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnDeleteSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnImport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnExport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnPurge ) );
	m_used_in_map1->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSamplePanel::OnUsedInMap1 ), NULL, this );
	m_used_in_map2->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSamplePanel::OnUsedInMap2 ), NULL, this );
	m_used_in_map3->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSamplePanel::OnUsedInMap3 ), NULL, this );
	m_used_in_map4->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSamplePanel::OnUsedInMap4 ), NULL, this );
	m_used_in_map5->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSamplePanel::OnUsedInMap5 ), NULL, this );
	m_used_in_map6->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSamplePanel::OnUsedInMap6 ), NULL, this );
	m_used_in_map7->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSamplePanel::OnUsedInMap7 ), NULL, this );
	m_used_in_map8->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSamplePanel::OnUsedInMap8 ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnGetSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnGetSoundParam ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnCopy ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnCopyParamToAll ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnDeleteSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnImport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnExport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnPurge ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnGetSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnGetSoundParam ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnCopy ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnCopyParamToAll ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnDeleteSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnImport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnExport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSamplePanel::OnPurge ) );
	
	delete m_menu1611; 
	delete m_menu1612; 
	delete m_menu161; 
	delete m_menu1613; 
	delete m_menu16111; 
}

SoundSynthPanel::SoundSynthPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	this->SetMinSize( wxSize( -1,410 ) );
	this->SetMaxSize( wxSize( -1,410 ) );
	
	wxFlexGridSizer* fgSizer24;
	fgSizer24 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer24->AddGrowableCol( 0 );
	fgSizer24->AddGrowableCol( 1 );
	fgSizer24->AddGrowableCol( 2 );
	fgSizer24->SetFlexibleDirection( wxBOTH );
	fgSizer24->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_vca_env_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_vca_env_panel->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( m_vca_env_panel, wxID_ANY, wxT("VCA Envelope Graph") ), wxVERTICAL );
	
	m_vca_env_disp = new EnvDisp(m_vca_env_panel, wxID_ANY, wxDefaultPosition, wxSize(285, 169));
	sbSizer1->Add( m_vca_env_disp, 1, wxEXPAND, 0 );
	
	
	m_vca_env_panel->SetSizer( sbSizer1 );
	m_vca_env_panel->Layout();
	sbSizer1->Fit( m_vca_env_panel );
	m_menu1612 = new wxMenu();
	wxMenuItem* m_menu_load12;
	m_menu_load12 = new wxMenuItem( m_menu1612, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1612->Append( m_menu_load12 );
	
	wxMenuItem* m_menu_save12;
	m_menu_save12 = new wxMenuItem( m_menu1612, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1612->Append( m_menu_save12 );
	
	m_menu1612->AppendSeparator();
	
	wxMenuItem* m_menu_get_sound12;
	m_menu_get_sound12 = new wxMenuItem( m_menu1612, wxID_ANY, wxString( wxT("Get Sound") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1612->Append( m_menu_get_sound12 );
	
	wxMenuItem* m_menu_get_sound_param12;
	m_menu_get_sound_param12 = new wxMenuItem( m_menu1612, wxID_ANY, wxString( wxT("Get Sound Parameters") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1612->Append( m_menu_get_sound_param12 );
	
	m_menu1612->AppendSeparator();
	
	wxMenuItem* m_menu_copy12;
	m_menu_copy12 = new wxMenuItem( m_menu1612, wxID_ANY, wxString( wxT("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1612->Append( m_menu_copy12 );
	
	wxMenuItem* m_menu_copyparamtoall1;
	m_menu_copyparamtoall1 = new wxMenuItem( m_menu1612, wxID_ANY, wxString( wxT("Copy Parameters to all") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1612->Append( m_menu_copyparamtoall1 );
	
	m_menu1612->AppendSeparator();
	
	wxMenuItem* m_menu_delete_sound12;
	m_menu_delete_sound12 = new wxMenuItem( m_menu1612, wxID_ANY, wxString( wxT("Delete sample data") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1612->Append( m_menu_delete_sound12 );
	
	m_menu1612->AppendSeparator();
	
	wxMenuItem* m_menu_import12;
	m_menu_import12 = new wxMenuItem( m_menu1612, wxID_ANY, wxString( wxT("Import WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1612->Append( m_menu_import12 );
	
	wxMenuItem* m_menu_export12;
	m_menu_export12 = new wxMenuItem( m_menu1612, wxID_ANY, wxString( wxT("Export WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1612->Append( m_menu_export12 );
	
	m_menu1612->AppendSeparator();
	
	wxMenuItem* m_menu_purge12;
	m_menu_purge12 = new wxMenuItem( m_menu1612, wxID_ANY, wxString( wxT("Purge") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1612->Append( m_menu_purge12 );
	
	m_vca_env_panel->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( SoundSynthPanel::m_vca_env_panelOnContextMenu ), NULL, this ); 
	
	fgSizer24->Add( m_vca_env_panel, 1, wxALL|wxEXPAND, 5 );
	
	m_vcf_env_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_vcf_env_panel->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( m_vcf_env_panel, wxID_ANY, wxT("VCF Envelope Graph") ), wxVERTICAL );
	
	m_vcf_env_disp = new EnvDisp(m_vcf_env_panel, wxID_ANY, wxDefaultPosition, wxSize(285, 169));
	m_vcf_env_disp->SetToolTip( wxT("Click to switch between VCF Envelope Settings and VCF Cutoff Modulation by the Envelope Settings") );
	
	sbSizer2->Add( m_vcf_env_disp, 1, wxEXPAND, 0 );
	
	
	m_vcf_env_panel->SetSizer( sbSizer2 );
	m_vcf_env_panel->Layout();
	sbSizer2->Fit( m_vcf_env_panel );
	m_menu1613 = new wxMenu();
	wxMenuItem* m_menu_load13;
	m_menu_load13 = new wxMenuItem( m_menu1613, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1613->Append( m_menu_load13 );
	
	wxMenuItem* m_menu_save13;
	m_menu_save13 = new wxMenuItem( m_menu1613, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1613->Append( m_menu_save13 );
	
	m_menu1613->AppendSeparator();
	
	wxMenuItem* m_menu_get_sound13;
	m_menu_get_sound13 = new wxMenuItem( m_menu1613, wxID_ANY, wxString( wxT("Get Sound") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1613->Append( m_menu_get_sound13 );
	
	wxMenuItem* m_menu_get_sound_param13;
	m_menu_get_sound_param13 = new wxMenuItem( m_menu1613, wxID_ANY, wxString( wxT("Get Sound Parameters") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1613->Append( m_menu_get_sound_param13 );
	
	m_menu1613->AppendSeparator();
	
	wxMenuItem* m_menu_copy13;
	m_menu_copy13 = new wxMenuItem( m_menu1613, wxID_ANY, wxString( wxT("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1613->Append( m_menu_copy13 );
	
	wxMenuItem* m_menu_copyparamtoall2;
	m_menu_copyparamtoall2 = new wxMenuItem( m_menu1613, wxID_ANY, wxString( wxT("Copy Parameters to all") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1613->Append( m_menu_copyparamtoall2 );
	
	m_menu1613->AppendSeparator();
	
	wxMenuItem* m_menu_delete_sound13;
	m_menu_delete_sound13 = new wxMenuItem( m_menu1613, wxID_ANY, wxString( wxT("Delete sample data") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1613->Append( m_menu_delete_sound13 );
	
	m_menu1613->AppendSeparator();
	
	wxMenuItem* m_menu_import13;
	m_menu_import13 = new wxMenuItem( m_menu1613, wxID_ANY, wxString( wxT("Import WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1613->Append( m_menu_import13 );
	
	wxMenuItem* m_menu_export13;
	m_menu_export13 = new wxMenuItem( m_menu1613, wxID_ANY, wxString( wxT("Export WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1613->Append( m_menu_export13 );
	
	m_menu1613->AppendSeparator();
	
	wxMenuItem* m_menu_purge13;
	m_menu_purge13 = new wxMenuItem( m_menu1613, wxID_ANY, wxString( wxT("Purge") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1613->Append( m_menu_purge13 );
	
	m_vcf_env_panel->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( SoundSynthPanel::m_vcf_env_panelOnContextMenu ), NULL, this ); 
	
	fgSizer24->Add( m_vcf_env_panel, 1, wxEXPAND|wxALL, 5 );
	
	m_panel64111 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer26111;
	fgSizer26111 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer26111->AddGrowableCol( 0 );
	fgSizer26111->AddGrowableCol( 1 );
	fgSizer26111->AddGrowableCol( 2 );
	fgSizer26111->AddGrowableCol( 3 );
	fgSizer26111->SetFlexibleDirection( wxBOTH );
	fgSizer26111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText235111 = new wxStaticText( m_panel64111, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText235111->Wrap( -1 );
	fgSizer26111->Add( m_staticText235111, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_staticText234111 = new wxStaticText( m_panel64111, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText234111->Wrap( -1 );
	m_staticText234111->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer26111->Add( m_staticText234111, 0, wxALIGN_RIGHT|wxTOP|wxLEFT, 5 );
	
	m_staticText238111 = new wxStaticText( m_panel64111, wxID_ANY, wxT("Velocity"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText238111->Wrap( -1 );
	m_staticText238111->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer26111->Add( m_staticText238111, 0, wxTOP, 5 );
	
	m_staticText239111 = new wxStaticText( m_panel64111, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText239111->Wrap( -1 );
	fgSizer26111->Add( m_staticText239111, 0, wxALIGN_RIGHT|wxTOP|wxRIGHT, 5 );
	
	m_attack_vel_sensitivity = new wxSlider( m_panel64111, wxID_ANY, 0, -127, 127, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	fgSizer26111->Add( m_attack_vel_sensitivity, 1, wxRIGHT|wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_release_vel_sensitivity = new wxSlider( m_panel64111, wxID_ANY, 0, -127, 127, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	fgSizer26111->Add( m_release_vel_sensitivity, 1, wxRIGHT|wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_amp_peak_vel_sensitivity = new wxSlider( m_panel64111, wxID_ANY, 0, -127, 127, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	fgSizer26111->Add( m_amp_peak_vel_sensitivity, 1, wxRIGHT|wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_filt_peak_vel_sensitivity = new wxSlider( m_panel64111, wxID_ANY, 0, -127, 127, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	fgSizer26111->Add( m_filt_peak_vel_sensitivity, 1, wxRIGHT|wxLEFT|wxEXPAND|wxALIGN_RIGHT, 5 );
	
	m_staticText247111 = new wxStaticText( m_panel64111, wxID_ANY, wxT("Attack"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText247111->Wrap( -1 );
	fgSizer26111->Add( m_staticText247111, 1, wxALIGN_RIGHT|wxRIGHT, 5 );
	
	m_staticText248111 = new wxStaticText( m_panel64111, wxID_ANY, wxT("Release"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText248111->Wrap( -1 );
	fgSizer26111->Add( m_staticText248111, 1, wxALIGN_RIGHT, 5 );
	
	m_staticText246111 = new wxStaticText( m_panel64111, wxID_ANY, wxT("VCA Peak"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText246111->Wrap( -1 );
	fgSizer26111->Add( m_staticText246111, 1, wxALIGN_RIGHT, 5 );
	
	m_staticText249111 = new wxStaticText( m_panel64111, wxID_ANY, wxT("VCF Peak"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText249111->Wrap( -1 );
	fgSizer26111->Add( m_staticText249111, 1, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxLEFT, 5 );
	
	m_attack_vel_sensitivity_val = new wxTextCtrl( m_panel64111, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_attack_vel_sensitivity_val->SetMaxLength( 4 ); 
	m_attack_vel_sensitivity_val->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	m_attack_vel_sensitivity_val->SetToolTip( wxT("Value as seen on Prophet Display") );
	
	fgSizer26111->Add( m_attack_vel_sensitivity_val, 0, wxALIGN_RIGHT, 5 );
	
	m_release_vel_sensitivity_val = new wxTextCtrl( m_panel64111, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_release_vel_sensitivity_val->SetMaxLength( 4 ); 
	m_release_vel_sensitivity_val->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	m_release_vel_sensitivity_val->SetToolTip( wxT("Value as seen on Prophet Display") );
	
	fgSizer26111->Add( m_release_vel_sensitivity_val, 0, wxALIGN_RIGHT, 5 );
	
	m_amp_peak_vel_sensitivity_val = new wxTextCtrl( m_panel64111, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_amp_peak_vel_sensitivity_val->SetMaxLength( 4 ); 
	m_amp_peak_vel_sensitivity_val->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	m_amp_peak_vel_sensitivity_val->SetToolTip( wxT("Value as seen on Prophet Display") );
	
	fgSizer26111->Add( m_amp_peak_vel_sensitivity_val, 0, wxALIGN_RIGHT|wxBOTTOM, 5 );
	
	m_filt_peak_vel_sensitivity_val = new wxTextCtrl( m_panel64111, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_filt_peak_vel_sensitivity_val->SetMaxLength( 4 ); 
	m_filt_peak_vel_sensitivity_val->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	m_filt_peak_vel_sensitivity_val->SetToolTip( wxT("Value as seen on Prophet Display") );
	
	fgSizer26111->Add( m_filt_peak_vel_sensitivity_val, 0, wxALIGN_RIGHT|wxRIGHT|wxLEFT, 5 );
	
	
	m_panel64111->SetSizer( fgSizer26111 );
	m_panel64111->Layout();
	fgSizer26111->Fit( m_panel64111 );
	m_menu161 = new wxMenu();
	wxMenuItem* m_menu_load1;
	m_menu_load1 = new wxMenuItem( m_menu161, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu161->Append( m_menu_load1 );
	
	wxMenuItem* m_menu_save1;
	m_menu_save1 = new wxMenuItem( m_menu161, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu161->Append( m_menu_save1 );
	
	m_menu161->AppendSeparator();
	
	wxMenuItem* m_menu_get_sound1;
	m_menu_get_sound1 = new wxMenuItem( m_menu161, wxID_ANY, wxString( wxT("Get Sound") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu161->Append( m_menu_get_sound1 );
	
	wxMenuItem* m_menu_get_sound_param1;
	m_menu_get_sound_param1 = new wxMenuItem( m_menu161, wxID_ANY, wxString( wxT("Get Sound Parameters") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu161->Append( m_menu_get_sound_param1 );
	
	m_menu161->AppendSeparator();
	
	wxMenuItem* m_menu_copy1;
	m_menu_copy1 = new wxMenuItem( m_menu161, wxID_ANY, wxString( wxT("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu161->Append( m_menu_copy1 );
	
	wxMenuItem* m_menu_copyparamtoall3;
	m_menu_copyparamtoall3 = new wxMenuItem( m_menu161, wxID_ANY, wxString( wxT("Copy Parameters to all") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu161->Append( m_menu_copyparamtoall3 );
	
	m_menu161->AppendSeparator();
	
	wxMenuItem* m_menu_delete_sound1;
	m_menu_delete_sound1 = new wxMenuItem( m_menu161, wxID_ANY, wxString( wxT("Delete sample data") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu161->Append( m_menu_delete_sound1 );
	
	m_menu161->AppendSeparator();
	
	wxMenuItem* m_menu_import1;
	m_menu_import1 = new wxMenuItem( m_menu161, wxID_ANY, wxString( wxT("Import WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu161->Append( m_menu_import1 );
	
	wxMenuItem* m_menu_export1;
	m_menu_export1 = new wxMenuItem( m_menu161, wxID_ANY, wxString( wxT("Export WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu161->Append( m_menu_export1 );
	
	m_menu161->AppendSeparator();
	
	wxMenuItem* m_menu_purge1;
	m_menu_purge1 = new wxMenuItem( m_menu161, wxID_ANY, wxString( wxT("Purge") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu161->Append( m_menu_purge1 );
	
	m_panel64111->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( SoundSynthPanel::m_panel64111OnContextMenu ), NULL, this ); 
	
	fgSizer24->Add( m_panel64111, 1, wxALL|wxEXPAND, 5 );
	
	m_panel62 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer54;
	fgSizer54 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer54->SetFlexibleDirection( wxBOTH );
	fgSizer54->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText279 = new wxStaticText( m_panel62, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText279->Wrap( -1 );
	fgSizer54->Add( m_staticText279, 0, wxRIGHT|wxLEFT, 5 );
	
	m_staticText280 = new wxStaticText( m_panel62, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText280->Wrap( -1 );
	fgSizer54->Add( m_staticText280, 0, wxRIGHT|wxLEFT, 5 );
	
	m_staticText2901 = new wxStaticText( m_panel62, wxID_ANY, wxT("Used "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2901->Wrap( -1 );
	fgSizer54->Add( m_staticText2901, 0, wxALIGN_BOTTOM|wxALIGN_RIGHT|wxBOTTOM, 5 );
	
	m_staticText291 = new wxStaticText( m_panel62, wxID_ANY, wxT("in Map"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText291->Wrap( -1 );
	fgSizer54->Add( m_staticText291, 1, wxALIGN_BOTTOM|wxBOTTOM, 5 );
	
	m_used_in_map1 = new wxToggleButton( m_panel62, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_used_in_map1->SetMinSize( wxSize( 32,-1 ) );
	
	fgSizer54->Add( m_used_in_map1, 1, wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	m_used_in_map2 = new wxToggleButton( m_panel62, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_used_in_map2->SetMinSize( wxSize( 32,-1 ) );
	
	fgSizer54->Add( m_used_in_map2, 1, wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	m_used_in_map3 = new wxToggleButton( m_panel62, wxID_ANY, wxT("3"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_used_in_map3->SetMinSize( wxSize( 30,-1 ) );
	
	fgSizer54->Add( m_used_in_map3, 1, wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	m_used_in_map4 = new wxToggleButton( m_panel62, wxID_ANY, wxT("4"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_used_in_map4->SetMinSize( wxSize( 30,-1 ) );
	
	fgSizer54->Add( m_used_in_map4, 1, wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	m_used_in_map5 = new wxToggleButton( m_panel62, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_used_in_map5->SetMinSize( wxSize( 30,-1 ) );
	
	fgSizer54->Add( m_used_in_map5, 1, wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	m_used_in_map6 = new wxToggleButton( m_panel62, wxID_ANY, wxT("6"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_used_in_map6->SetMinSize( wxSize( 30,-1 ) );
	
	fgSizer54->Add( m_used_in_map6, 1, wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	m_used_in_map7 = new wxToggleButton( m_panel62, wxID_ANY, wxT("7"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_used_in_map7->SetMinSize( wxSize( 30,-1 ) );
	
	fgSizer54->Add( m_used_in_map7, 1, wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	m_used_in_map8 = new wxToggleButton( m_panel62, wxID_ANY, wxT("8"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_used_in_map8->SetMinSize( wxSize( 30,-1 ) );
	
	fgSizer54->Add( m_used_in_map8, 1, wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	
	m_panel62->SetSizer( fgSizer54 );
	m_panel62->Layout();
	fgSizer54->Fit( m_panel62 );
	m_menu1614 = new wxMenu();
	wxMenuItem* m_menu_load14;
	m_menu_load14 = new wxMenuItem( m_menu1614, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1614->Append( m_menu_load14 );
	
	wxMenuItem* m_menu_save14;
	m_menu_save14 = new wxMenuItem( m_menu1614, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1614->Append( m_menu_save14 );
	
	m_menu1614->AppendSeparator();
	
	wxMenuItem* m_menu_get_sound14;
	m_menu_get_sound14 = new wxMenuItem( m_menu1614, wxID_ANY, wxString( wxT("Get Sound") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1614->Append( m_menu_get_sound14 );
	
	wxMenuItem* m_menu_get_sound_param14;
	m_menu_get_sound_param14 = new wxMenuItem( m_menu1614, wxID_ANY, wxString( wxT("Get Sound Parameters") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1614->Append( m_menu_get_sound_param14 );
	
	m_menu1614->AppendSeparator();
	
	wxMenuItem* m_menu_copy14;
	m_menu_copy14 = new wxMenuItem( m_menu1614, wxID_ANY, wxString( wxT("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1614->Append( m_menu_copy14 );
	
	wxMenuItem* m_menu_copyparamtoall4;
	m_menu_copyparamtoall4 = new wxMenuItem( m_menu1614, wxID_ANY, wxString( wxT("Copy Parameters to all") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1614->Append( m_menu_copyparamtoall4 );
	
	m_menu1614->AppendSeparator();
	
	wxMenuItem* m_menu_delete_sound14;
	m_menu_delete_sound14 = new wxMenuItem( m_menu1614, wxID_ANY, wxString( wxT("Delete sample data") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1614->Append( m_menu_delete_sound14 );
	
	m_menu1614->AppendSeparator();
	
	wxMenuItem* m_menu_import14;
	m_menu_import14 = new wxMenuItem( m_menu1614, wxID_ANY, wxString( wxT("Import WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1614->Append( m_menu_import14 );
	
	wxMenuItem* m_menu_export14;
	m_menu_export14 = new wxMenuItem( m_menu1614, wxID_ANY, wxString( wxT("Export WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1614->Append( m_menu_export14 );
	
	m_menu1614->AppendSeparator();
	
	wxMenuItem* m_menu_purge14;
	m_menu_purge14 = new wxMenuItem( m_menu1614, wxID_ANY, wxString( wxT("Purge") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1614->Append( m_menu_purge14 );
	
	m_panel62->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( SoundSynthPanel::m_panel62OnContextMenu ), NULL, this ); 
	
	fgSizer24->Add( m_panel62, 1, wxRIGHT|wxALIGN_RIGHT, 5 );
	
	m_panel59 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer26;
	fgSizer26 = new wxFlexGridSizer( 0, 5, 0, 0 );
	fgSizer26->AddGrowableCol( 0 );
	fgSizer26->AddGrowableCol( 1 );
	fgSizer26->AddGrowableCol( 3 );
	fgSizer26->AddGrowableCol( 4 );
	fgSizer26->SetFlexibleDirection( wxBOTH );
	fgSizer26->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText235 = new wxStaticText( m_panel59, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText235->Wrap( -1 );
	fgSizer26->Add( m_staticText235, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_staticText234 = new wxStaticText( m_panel59, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText234->Wrap( -1 );
	m_staticText234->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer26->Add( m_staticText234, 0, wxALIGN_RIGHT|wxTOP|wxLEFT, 5 );
	
	m_staticText238 = new wxStaticText( m_panel59, wxID_ANY, wxT("VCA Envel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText238->Wrap( -1 );
	m_staticText238->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer26->Add( m_staticText238, 0, wxALIGN_RIGHT|wxTOP, 5 );
	
	m_staticText239 = new wxStaticText( m_panel59, wxID_ANY, wxT("ope"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText239->Wrap( -1 );
	m_staticText239->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 70, 90, 92, false, wxEmptyString ) );
	
	fgSizer26->Add( m_staticText239, 0, wxTOP|wxRIGHT, 5 );
	
	m_staticText240 = new wxStaticText( m_panel59, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText240->Wrap( -1 );
	fgSizer26->Add( m_staticText240, 0, wxALIGN_RIGHT|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_amp_attack_rate = new wxSlider( m_panel59, wxID_ANY, 0, 0, 62, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	fgSizer26->Add( m_amp_attack_rate, 0, wxRIGHT|wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_amp_decay_rate = new wxSlider( m_panel59, wxID_ANY, 63, 1, 63, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	fgSizer26->Add( m_amp_decay_rate, 0, wxRIGHT|wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_amp_sustain_level = new wxSlider( m_panel59, wxID_ANY, 255, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	fgSizer26->Add( m_amp_sustain_level, 0, wxRIGHT|wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_amp_release = new wxSlider( m_panel59, wxID_ANY, 1, 1, 63, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	fgSizer26->Add( m_amp_release, 0, wxRIGHT|wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_amp_2nd_release = new wxSlider( m_panel59, wxID_ANY, 1, 1, 63, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	fgSizer26->Add( m_amp_2nd_release, 0, wxRIGHT|wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText246 = new wxStaticText( m_panel59, wxID_ANY, wxT("Attack"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText246->Wrap( -1 );
	fgSizer26->Add( m_staticText246, 0, wxALIGN_RIGHT|wxRIGHT, 5 );
	
	m_staticText247 = new wxStaticText( m_panel59, wxID_ANY, wxT("Decay"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText247->Wrap( -1 );
	fgSizer26->Add( m_staticText247, 0, wxALIGN_RIGHT|wxRIGHT, 5 );
	
	m_staticText248 = new wxStaticText( m_panel59, wxID_ANY, wxT("Sustain"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText248->Wrap( -1 );
	fgSizer26->Add( m_staticText248, 0, wxALIGN_RIGHT, 5 );
	
	m_staticText249 = new wxStaticText( m_panel59, wxID_ANY, wxT("Release"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText249->Wrap( -1 );
	fgSizer26->Add( m_staticText249, 0, wxALIGN_RIGHT|wxLEFT, 5 );
	
	m_staticText250 = new wxStaticText( m_panel59, wxID_ANY, wxT("   2nd Rel."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText250->Wrap( -1 );
	fgSizer26->Add( m_staticText250, 0, wxRIGHT|wxLEFT|wxALIGN_RIGHT, 5 );
	
	m_amp_attack_rate_val = new wxTextCtrl( m_panel59, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_amp_attack_rate_val->SetMaxLength( 4 ); 
	m_amp_attack_rate_val->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	m_amp_attack_rate_val->SetToolTip( wxT("Value as seen on Prophet Display") );
	
	fgSizer26->Add( m_amp_attack_rate_val, 0, wxALIGN_RIGHT|wxBOTTOM, 5 );
	
	m_amp_decay_rate_val = new wxTextCtrl( m_panel59, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_amp_decay_rate_val->SetMaxLength( 4 ); 
	m_amp_decay_rate_val->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	m_amp_decay_rate_val->SetToolTip( wxT("Value as seen on Prophet Display") );
	
	fgSizer26->Add( m_amp_decay_rate_val, 0, wxALIGN_RIGHT, 5 );
	
	m_amp_sustain_level_val = new wxTextCtrl( m_panel59, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_amp_sustain_level_val->SetMaxLength( 4 ); 
	m_amp_sustain_level_val->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	m_amp_sustain_level_val->SetToolTip( wxT("Value as seen on Prophet Display") );
	
	fgSizer26->Add( m_amp_sustain_level_val, 0, wxALIGN_RIGHT, 5 );
	
	m_amp_release_val = new wxTextCtrl( m_panel59, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_amp_release_val->SetMaxLength( 4 ); 
	m_amp_release_val->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	m_amp_release_val->SetToolTip( wxT("Value as seen on Prophet Display") );
	
	fgSizer26->Add( m_amp_release_val, 0, wxALIGN_RIGHT, 5 );
	
	m_amp_2nd_release_val = new wxTextCtrl( m_panel59, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_amp_2nd_release_val->SetMaxLength( 4 ); 
	m_amp_2nd_release_val->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	m_amp_2nd_release_val->SetToolTip( wxT("Value as seen on Prophet Display") );
	
	fgSizer26->Add( m_amp_2nd_release_val, 0, wxALIGN_RIGHT|wxRIGHT|wxLEFT, 5 );
	
	
	m_panel59->SetSizer( fgSizer26 );
	m_panel59->Layout();
	fgSizer26->Fit( m_panel59 );
	m_menu1615 = new wxMenu();
	wxMenuItem* m_menu_load15;
	m_menu_load15 = new wxMenuItem( m_menu1615, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1615->Append( m_menu_load15 );
	
	wxMenuItem* m_menu_save15;
	m_menu_save15 = new wxMenuItem( m_menu1615, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1615->Append( m_menu_save15 );
	
	m_menu1615->AppendSeparator();
	
	wxMenuItem* m_menu_get_sound15;
	m_menu_get_sound15 = new wxMenuItem( m_menu1615, wxID_ANY, wxString( wxT("Get Sound") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1615->Append( m_menu_get_sound15 );
	
	wxMenuItem* m_menu_get_sound_param15;
	m_menu_get_sound_param15 = new wxMenuItem( m_menu1615, wxID_ANY, wxString( wxT("Get Sound Parameters") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1615->Append( m_menu_get_sound_param15 );
	
	m_menu1615->AppendSeparator();
	
	wxMenuItem* m_menu_copy15;
	m_menu_copy15 = new wxMenuItem( m_menu1615, wxID_ANY, wxString( wxT("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1615->Append( m_menu_copy15 );
	
	wxMenuItem* m_menu_copyparamtoall5;
	m_menu_copyparamtoall5 = new wxMenuItem( m_menu1615, wxID_ANY, wxString( wxT("Copy Parameters to all") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1615->Append( m_menu_copyparamtoall5 );
	
	m_menu1615->AppendSeparator();
	
	wxMenuItem* m_menu_delete_sound15;
	m_menu_delete_sound15 = new wxMenuItem( m_menu1615, wxID_ANY, wxString( wxT("Delete sample data") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1615->Append( m_menu_delete_sound15 );
	
	m_menu1615->AppendSeparator();
	
	wxMenuItem* m_menu_import15;
	m_menu_import15 = new wxMenuItem( m_menu1615, wxID_ANY, wxString( wxT("Import WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1615->Append( m_menu_import15 );
	
	wxMenuItem* m_menu_export15;
	m_menu_export15 = new wxMenuItem( m_menu1615, wxID_ANY, wxString( wxT("Export WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1615->Append( m_menu_export15 );
	
	m_menu1615->AppendSeparator();
	
	wxMenuItem* m_menu_purge15;
	m_menu_purge15 = new wxMenuItem( m_menu1615, wxID_ANY, wxString( wxT("Purge") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1615->Append( m_menu_purge15 );
	
	m_panel59->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( SoundSynthPanel::m_panel59OnContextMenu ), NULL, this ); 
	
	fgSizer24->Add( m_panel59, 1, wxALIGN_BOTTOM|wxEXPAND|wxRIGHT|wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_panel641 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer261;
	fgSizer261 = new wxFlexGridSizer( 0, 5, 0, 0 );
	fgSizer261->AddGrowableCol( 0 );
	fgSizer261->AddGrowableCol( 1 );
	fgSizer261->AddGrowableCol( 3 );
	fgSizer261->AddGrowableCol( 4 );
	fgSizer261->SetFlexibleDirection( wxBOTH );
	fgSizer261->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText2351 = new wxStaticText( m_panel641, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2351->Wrap( -1 );
	fgSizer261->Add( m_staticText2351, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_staticText2341 = new wxStaticText( m_panel641, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2341->Wrap( -1 );
	m_staticText2341->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer261->Add( m_staticText2341, 0, wxALIGN_RIGHT|wxTOP|wxLEFT, 5 );
	
	m_staticText2381 = new wxStaticText( m_panel641, wxID_ANY, wxT("VCF Envel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2381->Wrap( -1 );
	m_staticText2381->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer261->Add( m_staticText2381, 0, wxTOP|wxALIGN_RIGHT, 5 );
	
	m_staticText2391 = new wxStaticText( m_panel641, wxID_ANY, wxT("ope"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2391->Wrap( -1 );
	m_staticText2391->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer261->Add( m_staticText2391, 0, wxTOP, 5 );
	
	m_staticText2401 = new wxStaticText( m_panel641, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2401->Wrap( -1 );
	fgSizer261->Add( m_staticText2401, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_filt_attack_rate = new wxSlider( m_panel641, wxID_ANY, 0, 0, 62, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	fgSizer261->Add( m_filt_attack_rate, 0, wxRIGHT|wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_filt_decay_rate = new wxSlider( m_panel641, wxID_ANY, 63, 1, 63, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	fgSizer261->Add( m_filt_decay_rate, 0, wxRIGHT|wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_filt_sustain_level = new wxSlider( m_panel641, wxID_ANY, 255, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	fgSizer261->Add( m_filt_sustain_level, 0, wxRIGHT|wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_filt_release_rate = new wxSlider( m_panel641, wxID_ANY, 1, 1, 63, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	fgSizer261->Add( m_filt_release_rate, 0, wxRIGHT|wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_filt_2nd_release_rate = new wxSlider( m_panel641, wxID_ANY, 1, 1, 63, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	fgSizer261->Add( m_filt_2nd_release_rate, 0, wxRIGHT|wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText2461 = new wxStaticText( m_panel641, wxID_ANY, wxT("Attack"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2461->Wrap( -1 );
	fgSizer261->Add( m_staticText2461, 0, wxALIGN_RIGHT|wxRIGHT, 5 );
	
	m_staticText2471 = new wxStaticText( m_panel641, wxID_ANY, wxT("Decay"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2471->Wrap( -1 );
	fgSizer261->Add( m_staticText2471, 0, wxALIGN_RIGHT|wxRIGHT, 5 );
	
	m_staticText2481 = new wxStaticText( m_panel641, wxID_ANY, wxT("Sustain"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2481->Wrap( -1 );
	fgSizer261->Add( m_staticText2481, 0, wxALIGN_RIGHT, 5 );
	
	m_staticText2491 = new wxStaticText( m_panel641, wxID_ANY, wxT("Release"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2491->Wrap( -1 );
	fgSizer261->Add( m_staticText2491, 0, wxALIGN_RIGHT|wxLEFT, 5 );
	
	m_staticText2501 = new wxStaticText( m_panel641, wxID_ANY, wxT("   2nd Rel."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2501->Wrap( -1 );
	fgSizer261->Add( m_staticText2501, 0, wxRIGHT|wxLEFT|wxALIGN_RIGHT, 5 );
	
	m_filt_attack_rate_val = new wxTextCtrl( m_panel641, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_filt_attack_rate_val->SetMaxLength( 4 ); 
	m_filt_attack_rate_val->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	m_filt_attack_rate_val->SetToolTip( wxT("Value as seen on Prophet Display") );
	
	fgSizer261->Add( m_filt_attack_rate_val, 0, wxALIGN_RIGHT|wxBOTTOM, 5 );
	
	m_filt_decay_rate_val = new wxTextCtrl( m_panel641, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_filt_decay_rate_val->SetMaxLength( 4 ); 
	m_filt_decay_rate_val->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	m_filt_decay_rate_val->SetToolTip( wxT("Value as seen on Prophet Display") );
	
	fgSizer261->Add( m_filt_decay_rate_val, 0, wxALIGN_RIGHT, 5 );
	
	m_filt_sustain_level_val = new wxTextCtrl( m_panel641, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_filt_sustain_level_val->SetMaxLength( 4 ); 
	m_filt_sustain_level_val->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	m_filt_sustain_level_val->SetToolTip( wxT("Value as seen on Prophet Display") );
	
	fgSizer261->Add( m_filt_sustain_level_val, 0, wxALIGN_RIGHT, 5 );
	
	m_filt_release_rate_val = new wxTextCtrl( m_panel641, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_filt_release_rate_val->SetMaxLength( 4 ); 
	m_filt_release_rate_val->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	m_filt_release_rate_val->SetToolTip( wxT("Value as seen on Prophet Display") );
	
	fgSizer261->Add( m_filt_release_rate_val, 0, wxALIGN_RIGHT, 5 );
	
	m_filt_2nd_release_rate_val = new wxTextCtrl( m_panel641, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_filt_2nd_release_rate_val->SetMaxLength( 4 ); 
	m_filt_2nd_release_rate_val->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	m_filt_2nd_release_rate_val->SetToolTip( wxT("Value as seen on Prophet Display") );
	
	fgSizer261->Add( m_filt_2nd_release_rate_val, 0, wxALIGN_RIGHT|wxRIGHT|wxLEFT, 5 );
	
	
	m_panel641->SetSizer( fgSizer261 );
	m_panel641->Layout();
	fgSizer261->Fit( m_panel641 );
	m_menu1616 = new wxMenu();
	wxMenuItem* m_menu_load16;
	m_menu_load16 = new wxMenuItem( m_menu1616, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1616->Append( m_menu_load16 );
	
	wxMenuItem* m_menu_save16;
	m_menu_save16 = new wxMenuItem( m_menu1616, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1616->Append( m_menu_save16 );
	
	m_menu1616->AppendSeparator();
	
	wxMenuItem* m_menu_get_sound16;
	m_menu_get_sound16 = new wxMenuItem( m_menu1616, wxID_ANY, wxString( wxT("Get Sound") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1616->Append( m_menu_get_sound16 );
	
	wxMenuItem* m_menu_get_sound_param16;
	m_menu_get_sound_param16 = new wxMenuItem( m_menu1616, wxID_ANY, wxString( wxT("Get Sound Parameters") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1616->Append( m_menu_get_sound_param16 );
	
	m_menu1616->AppendSeparator();
	
	wxMenuItem* m_menu_copy16;
	m_menu_copy16 = new wxMenuItem( m_menu1616, wxID_ANY, wxString( wxT("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1616->Append( m_menu_copy16 );
	
	wxMenuItem* m_menu_copyparamtoall6;
	m_menu_copyparamtoall6 = new wxMenuItem( m_menu1616, wxID_ANY, wxString( wxT("Copy Parameters to all") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1616->Append( m_menu_copyparamtoall6 );
	
	m_menu1616->AppendSeparator();
	
	wxMenuItem* m_menu_delete_sound16;
	m_menu_delete_sound16 = new wxMenuItem( m_menu1616, wxID_ANY, wxString( wxT("Delete sample data") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1616->Append( m_menu_delete_sound16 );
	
	m_menu1616->AppendSeparator();
	
	wxMenuItem* m_menu_import16;
	m_menu_import16 = new wxMenuItem( m_menu1616, wxID_ANY, wxString( wxT("Import WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1616->Append( m_menu_import16 );
	
	wxMenuItem* m_menu_export16;
	m_menu_export16 = new wxMenuItem( m_menu1616, wxID_ANY, wxString( wxT("Export WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1616->Append( m_menu_export16 );
	
	m_menu1616->AppendSeparator();
	
	wxMenuItem* m_menu_purge16;
	m_menu_purge16 = new wxMenuItem( m_menu1616, wxID_ANY, wxString( wxT("Purge") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1616->Append( m_menu_purge16 );
	
	m_panel641->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( SoundSynthPanel::m_panel641OnContextMenu ), NULL, this ); 
	
	fgSizer24->Add( m_panel641, 1, wxALIGN_BOTTOM|wxRIGHT|wxLEFT|wxEXPAND, 5 );
	
	m_panel6411 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer2611;
	fgSizer2611 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer2611->AddGrowableCol( 0 );
	fgSizer2611->AddGrowableCol( 1 );
	fgSizer2611->AddGrowableCol( 2 );
	fgSizer2611->AddGrowableCol( 3 );
	fgSizer2611->SetFlexibleDirection( wxBOTH );
	fgSizer2611->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText23511 = new wxStaticText( m_panel6411, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23511->Wrap( -1 );
	fgSizer2611->Add( m_staticText23511, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_staticText23811 = new wxStaticText( m_panel6411, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23811->Wrap( -1 );
	m_staticText23811->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer2611->Add( m_staticText23811, 0, wxALIGN_RIGHT|wxTOP|wxLEFT, 5 );
	
	m_staticText23911 = new wxStaticText( m_panel6411, wxID_ANY, wxT("Filter"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23911->Wrap( -1 );
	m_staticText23911->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer2611->Add( m_staticText23911, 0, wxTOP|wxRIGHT, 5 );
	
	m_staticText23411 = new wxStaticText( m_panel6411, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23411->Wrap( -1 );
	fgSizer2611->Add( m_staticText23411, 0, wxALIGN_RIGHT|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_filt_cutoff = new wxSlider( m_panel6411, wxID_ANY, 255, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	fgSizer2611->Add( m_filt_cutoff, 1, wxRIGHT|wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 7 );
	
	m_filt_resonance = new wxSlider( m_panel6411, wxID_ANY, 0, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	fgSizer2611->Add( m_filt_resonance, 1, wxRIGHT|wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 7 );
	
	m_filt_env_amount = new wxSlider( m_panel6411, wxID_ANY, 0, -127, 127, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	fgSizer2611->Add( m_filt_env_amount, 1, wxRIGHT|wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 7 );
	
	m_filt_key_tracking = new wxSlider( m_panel6411, wxID_ANY, 127, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	m_filt_key_tracking->SetToolTip( wxT("127 = 1:1 Tracking") );
	
	fgSizer2611->Add( m_filt_key_tracking, 1, wxRIGHT|wxLEFT|wxEXPAND|wxALIGN_RIGHT, 6 );
	
	m_staticText24611 = new wxStaticText( m_panel6411, wxID_ANY, wxT(" Cutoff  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24611->Wrap( -1 );
	fgSizer2611->Add( m_staticText24611, 1, wxALIGN_RIGHT, 5 );
	
	m_staticText24711 = new wxStaticText( m_panel6411, wxID_ANY, wxT("  Reson. "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24711->Wrap( -1 );
	fgSizer2611->Add( m_staticText24711, 1, wxALIGN_RIGHT, 5 );
	
	m_staticText24811 = new wxStaticText( m_panel6411, wxID_ANY, wxT("Env. Amt"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24811->Wrap( -1 );
	fgSizer2611->Add( m_staticText24811, 1, wxALIGN_RIGHT, 5 );
	
	m_staticText24911 = new wxStaticText( m_panel6411, wxID_ANY, wxT("KB Track"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24911->Wrap( -1 );
	fgSizer2611->Add( m_staticText24911, 1, wxALIGN_RIGHT|wxRIGHT|wxLEFT, 5 );
	
	m_filt_cutoff_val = new wxTextCtrl( m_panel6411, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_filt_cutoff_val->SetMaxLength( 4 ); 
	m_filt_cutoff_val->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	m_filt_cutoff_val->SetToolTip( wxT("Value as seen on Prophet Display") );
	
	fgSizer2611->Add( m_filt_cutoff_val, 0, wxALIGN_RIGHT|wxBOTTOM, 5 );
	
	m_filt_resonance_val = new wxTextCtrl( m_panel6411, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_filt_resonance_val->SetMaxLength( 4 ); 
	m_filt_resonance_val->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	m_filt_resonance_val->SetToolTip( wxT("Value as seen on Prophet Display") );
	
	fgSizer2611->Add( m_filt_resonance_val, 0, wxALIGN_RIGHT, 5 );
	
	m_filt_env_amount_val = new wxTextCtrl( m_panel6411, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_filt_env_amount_val->SetMaxLength( 4 ); 
	m_filt_env_amount_val->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	m_filt_env_amount_val->SetToolTip( wxT("Value as seen on Prophet Display") );
	
	fgSizer2611->Add( m_filt_env_amount_val, 0, wxALIGN_RIGHT, 5 );
	
	m_filt_key_tracking_val = new wxTextCtrl( m_panel6411, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_filt_key_tracking_val->SetMaxLength( 4 ); 
	m_filt_key_tracking_val->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	m_filt_key_tracking_val->SetToolTip( wxT("Value as seen on Prophet Display") );
	
	fgSizer2611->Add( m_filt_key_tracking_val, 1, wxALIGN_RIGHT|wxALIGN_BOTTOM|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
	m_panel6411->SetSizer( fgSizer2611 );
	m_panel6411->Layout();
	fgSizer2611->Fit( m_panel6411 );
	m_menu1617 = new wxMenu();
	wxMenuItem* m_menu_load17;
	m_menu_load17 = new wxMenuItem( m_menu1617, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1617->Append( m_menu_load17 );
	
	wxMenuItem* m_menu_save17;
	m_menu_save17 = new wxMenuItem( m_menu1617, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1617->Append( m_menu_save17 );
	
	m_menu1617->AppendSeparator();
	
	wxMenuItem* m_menu_get_sound17;
	m_menu_get_sound17 = new wxMenuItem( m_menu1617, wxID_ANY, wxString( wxT("Get Sound") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1617->Append( m_menu_get_sound17 );
	
	wxMenuItem* m_menu_get_sound_param17;
	m_menu_get_sound_param17 = new wxMenuItem( m_menu1617, wxID_ANY, wxString( wxT("Get Sound Parameters") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1617->Append( m_menu_get_sound_param17 );
	
	m_menu1617->AppendSeparator();
	
	wxMenuItem* m_menu_copy17;
	m_menu_copy17 = new wxMenuItem( m_menu1617, wxID_ANY, wxString( wxT("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1617->Append( m_menu_copy17 );
	
	wxMenuItem* m_menu_copyparamtoall7;
	m_menu_copyparamtoall7 = new wxMenuItem( m_menu1617, wxID_ANY, wxString( wxT("Copy Parameters to all") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1617->Append( m_menu_copyparamtoall7 );
	
	m_menu1617->AppendSeparator();
	
	wxMenuItem* m_menu_delete_sound17;
	m_menu_delete_sound17 = new wxMenuItem( m_menu1617, wxID_ANY, wxString( wxT("Delete sample data") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1617->Append( m_menu_delete_sound17 );
	
	m_menu1617->AppendSeparator();
	
	wxMenuItem* m_menu_import17;
	m_menu_import17 = new wxMenuItem( m_menu1617, wxID_ANY, wxString( wxT("Import WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1617->Append( m_menu_import17 );
	
	wxMenuItem* m_menu_export17;
	m_menu_export17 = new wxMenuItem( m_menu1617, wxID_ANY, wxString( wxT("Export WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1617->Append( m_menu_export17 );
	
	m_menu1617->AppendSeparator();
	
	wxMenuItem* m_menu_purge17;
	m_menu_purge17 = new wxMenuItem( m_menu1617, wxID_ANY, wxString( wxT("Purge") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1617->Append( m_menu_purge17 );
	
	m_panel6411->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( SoundSynthPanel::m_panel6411OnContextMenu ), NULL, this ); 
	
	fgSizer24->Add( m_panel6411, 1, wxRIGHT|wxLEFT|wxALIGN_BOTTOM|wxEXPAND, 5 );
	
	
	fgSizer24->Add( 76, 0, 1, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( fgSizer24 );
	this->Layout();
	m_menu1611 = new wxMenu();
	wxMenuItem* m_menu_load11;
	m_menu_load11 = new wxMenuItem( m_menu1611, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1611->Append( m_menu_load11 );
	
	wxMenuItem* m_menu_save11;
	m_menu_save11 = new wxMenuItem( m_menu1611, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1611->Append( m_menu_save11 );
	
	m_menu1611->AppendSeparator();
	
	wxMenuItem* m_menu_get_sound11;
	m_menu_get_sound11 = new wxMenuItem( m_menu1611, wxID_ANY, wxString( wxT("Get Sound") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1611->Append( m_menu_get_sound11 );
	
	wxMenuItem* m_menu_get_sound_param11;
	m_menu_get_sound_param11 = new wxMenuItem( m_menu1611, wxID_ANY, wxString( wxT("Get Sound Parameters") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1611->Append( m_menu_get_sound_param11 );
	
	m_menu1611->AppendSeparator();
	
	wxMenuItem* m_menu_copy11;
	m_menu_copy11 = new wxMenuItem( m_menu1611, wxID_ANY, wxString( wxT("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1611->Append( m_menu_copy11 );
	
	wxMenuItem* m_menu_copyparamtoall;
	m_menu_copyparamtoall = new wxMenuItem( m_menu1611, wxID_ANY, wxString( wxT("Copy Parameters to all") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1611->Append( m_menu_copyparamtoall );
	
	m_menu1611->AppendSeparator();
	
	wxMenuItem* m_menu_delete_sound11;
	m_menu_delete_sound11 = new wxMenuItem( m_menu1611, wxID_ANY, wxString( wxT("Delete sample data") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1611->Append( m_menu_delete_sound11 );
	
	m_menu1611->AppendSeparator();
	
	wxMenuItem* m_menu_import11;
	m_menu_import11 = new wxMenuItem( m_menu1611, wxID_ANY, wxString( wxT("Import WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1611->Append( m_menu_import11 );
	
	wxMenuItem* m_menu_export11;
	m_menu_export11 = new wxMenuItem( m_menu1611, wxID_ANY, wxString( wxT("Export WAV") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1611->Append( m_menu_export11 );
	
	m_menu1611->AppendSeparator();
	
	wxMenuItem* m_menu_purge11;
	m_menu_purge11 = new wxMenuItem( m_menu1611, wxID_ANY, wxString( wxT("Purge") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1611->Append( m_menu_purge11 );
	
	this->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( SoundSynthPanel::SoundSynthPanelOnContextMenu ), NULL, this ); 
	
	
	// Connect Events
	this->Connect( m_menu_load12->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnLoad ) );
	this->Connect( m_menu_save12->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnSave ) );
	this->Connect( m_menu_get_sound12->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSound ) );
	this->Connect( m_menu_get_sound_param12->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSoundParam ) );
	this->Connect( m_menu_copy12->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopy ) );
	this->Connect( m_menu_copyparamtoall1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopyParamToAll ) );
	this->Connect( m_menu_delete_sound12->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnDeleteSound ) );
	this->Connect( m_menu_import12->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnImport ) );
	this->Connect( m_menu_export12->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnExport ) );
	this->Connect( m_menu_purge12->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnPurge ) );
	m_vcf_env_disp->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( SoundSynthPanel::OnLeftDown ), NULL, this );
	this->Connect( m_menu_load13->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnLoad ) );
	this->Connect( m_menu_save13->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnSave ) );
	this->Connect( m_menu_get_sound13->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSound ) );
	this->Connect( m_menu_get_sound_param13->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSoundParam ) );
	this->Connect( m_menu_copy13->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopy ) );
	this->Connect( m_menu_copyparamtoall2->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopyParamToAll ) );
	this->Connect( m_menu_delete_sound13->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnDeleteSound ) );
	this->Connect( m_menu_import13->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnImport ) );
	this->Connect( m_menu_export13->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnExport ) );
	this->Connect( m_menu_purge13->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnPurge ) );
	m_attack_vel_sensitivity->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_release_vel_sensitivity->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	this->Connect( m_menu_load1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnLoad ) );
	this->Connect( m_menu_save1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnSave ) );
	this->Connect( m_menu_get_sound1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSound ) );
	this->Connect( m_menu_get_sound_param1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSoundParam ) );
	this->Connect( m_menu_copy1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopy ) );
	this->Connect( m_menu_copyparamtoall3->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopyParamToAll ) );
	this->Connect( m_menu_delete_sound1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnDeleteSound ) );
	this->Connect( m_menu_import1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnImport ) );
	this->Connect( m_menu_export1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnExport ) );
	this->Connect( m_menu_purge1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnPurge ) );
	m_used_in_map1->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSynthPanel::OnUsedInMap1 ), NULL, this );
	m_used_in_map2->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSynthPanel::OnUsedInMap2 ), NULL, this );
	m_used_in_map3->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSynthPanel::OnUsedInMap3 ), NULL, this );
	m_used_in_map4->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSynthPanel::OnUsedInMap4 ), NULL, this );
	m_used_in_map5->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSynthPanel::OnUsedInMap5 ), NULL, this );
	m_used_in_map6->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSynthPanel::OnUsedInMap6 ), NULL, this );
	m_used_in_map7->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSynthPanel::OnUsedInMap7 ), NULL, this );
	m_used_in_map8->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSynthPanel::OnUsedInMap8 ), NULL, this );
	this->Connect( m_menu_load14->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnLoad ) );
	this->Connect( m_menu_save14->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnSave ) );
	this->Connect( m_menu_get_sound14->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSound ) );
	this->Connect( m_menu_get_sound_param14->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSoundParam ) );
	this->Connect( m_menu_copy14->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopy ) );
	this->Connect( m_menu_copyparamtoall4->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopyParamToAll ) );
	this->Connect( m_menu_delete_sound14->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnDeleteSound ) );
	this->Connect( m_menu_import14->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnImport ) );
	this->Connect( m_menu_export14->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnExport ) );
	this->Connect( m_menu_purge14->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnPurge ) );
	m_amp_attack_rate->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_decay_rate->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_sustain_level->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_release->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_2nd_release->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	this->Connect( m_menu_load15->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnLoad ) );
	this->Connect( m_menu_save15->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnSave ) );
	this->Connect( m_menu_get_sound15->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSound ) );
	this->Connect( m_menu_get_sound_param15->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSoundParam ) );
	this->Connect( m_menu_copy15->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopy ) );
	this->Connect( m_menu_copyparamtoall5->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopyParamToAll ) );
	this->Connect( m_menu_delete_sound15->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnDeleteSound ) );
	this->Connect( m_menu_import15->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnImport ) );
	this->Connect( m_menu_export15->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnExport ) );
	this->Connect( m_menu_purge15->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnPurge ) );
	m_filt_attack_rate->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_decay_rate->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_sustain_level->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_release_rate->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	this->Connect( m_menu_load16->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnLoad ) );
	this->Connect( m_menu_save16->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnSave ) );
	this->Connect( m_menu_get_sound16->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSound ) );
	this->Connect( m_menu_get_sound_param16->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSoundParam ) );
	this->Connect( m_menu_copy16->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopy ) );
	this->Connect( m_menu_copyparamtoall6->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopyParamToAll ) );
	this->Connect( m_menu_delete_sound16->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnDeleteSound ) );
	this->Connect( m_menu_import16->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnImport ) );
	this->Connect( m_menu_export16->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnExport ) );
	this->Connect( m_menu_purge16->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnPurge ) );
	m_filt_cutoff->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_resonance->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_env_amount->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_key_tracking->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_key_tracking->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_key_tracking->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_key_tracking->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_key_tracking->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_key_tracking->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_key_tracking->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_key_tracking->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_key_tracking->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	this->Connect( m_menu_load17->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnLoad ) );
	this->Connect( m_menu_save17->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnSave ) );
	this->Connect( m_menu_get_sound17->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSound ) );
	this->Connect( m_menu_get_sound_param17->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSoundParam ) );
	this->Connect( m_menu_copy17->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopy ) );
	this->Connect( m_menu_copyparamtoall7->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopyParamToAll ) );
	this->Connect( m_menu_delete_sound17->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnDeleteSound ) );
	this->Connect( m_menu_import17->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnImport ) );
	this->Connect( m_menu_export17->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnExport ) );
	this->Connect( m_menu_purge17->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnPurge ) );
	this->Connect( m_menu_load11->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnLoad ) );
	this->Connect( m_menu_save11->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnSave ) );
	this->Connect( m_menu_get_sound11->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSound ) );
	this->Connect( m_menu_get_sound_param11->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSoundParam ) );
	this->Connect( m_menu_copy11->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopy ) );
	this->Connect( m_menu_copyparamtoall->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopyParamToAll ) );
	this->Connect( m_menu_delete_sound11->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnDeleteSound ) );
	this->Connect( m_menu_import11->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnImport ) );
	this->Connect( m_menu_export11->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnExport ) );
	this->Connect( m_menu_purge11->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnPurge ) );
}

SoundSynthPanel::~SoundSynthPanel()
{
	// Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSoundParam ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopy ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopyParamToAll ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnDeleteSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnImport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnExport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnPurge ) );
	m_vcf_env_disp->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( SoundSynthPanel::OnLeftDown ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSoundParam ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopy ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopyParamToAll ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnDeleteSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnImport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnExport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnPurge ) );
	m_attack_vel_sensitivity->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_release_vel_sensitivity->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSoundParam ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopy ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopyParamToAll ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnDeleteSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnImport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnExport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnPurge ) );
	m_used_in_map1->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSynthPanel::OnUsedInMap1 ), NULL, this );
	m_used_in_map2->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSynthPanel::OnUsedInMap2 ), NULL, this );
	m_used_in_map3->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSynthPanel::OnUsedInMap3 ), NULL, this );
	m_used_in_map4->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSynthPanel::OnUsedInMap4 ), NULL, this );
	m_used_in_map5->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSynthPanel::OnUsedInMap5 ), NULL, this );
	m_used_in_map6->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSynthPanel::OnUsedInMap6 ), NULL, this );
	m_used_in_map7->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSynthPanel::OnUsedInMap7 ), NULL, this );
	m_used_in_map8->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSynthPanel::OnUsedInMap8 ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSoundParam ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopy ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopyParamToAll ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnDeleteSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnImport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnExport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnPurge ) );
	m_amp_attack_rate->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_decay_rate->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_sustain_level->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_release->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_2nd_release->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSoundParam ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopy ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopyParamToAll ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnDeleteSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnImport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnExport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnPurge ) );
	m_filt_attack_rate->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_decay_rate->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_sustain_level->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_release_rate->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSoundParam ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopy ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopyParamToAll ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnDeleteSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnImport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnExport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnPurge ) );
	m_filt_cutoff->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_resonance->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_env_amount->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_key_tracking->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( SoundSynthPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_key_tracking->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( SoundSynthPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_key_tracking->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_key_tracking->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_key_tracking->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( SoundSynthPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_key_tracking->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( SoundSynthPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_key_tracking->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( SoundSynthPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_key_tracking->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( SoundSynthPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_key_tracking->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( SoundSynthPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSoundParam ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopy ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopyParamToAll ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnDeleteSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnImport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnExport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnPurge ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnGetSoundParam ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopy ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnCopyParamToAll ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnDeleteSound ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnImport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnExport ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( SoundSynthPanel::OnPurge ) );
	
	delete m_menu1612; 
	delete m_menu1613; 
	delete m_menu161; 
	delete m_menu1614; 
	delete m_menu1615; 
	delete m_menu1616; 
	delete m_menu1617; 
	delete m_menu1611; 
}

MapPanel::MapPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	this->SetMinSize( wxSize( -1,452 ) );
	this->SetMaxSize( wxSize( -1,452 ) );
	
	wxBoxSizer* bSizer63;
	bSizer63 = new wxBoxSizer( wxVERTICAL );
	
	bSizer63->SetMinSize( wxSize( 980,484 ) ); 
	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer32->SetMinSize( wxSize( 980,32 ) ); 
	m_select_map_1 = new wxToggleButton( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_map_1->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_map_1->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_map_1->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer32->Add( m_select_map_1, 0, wxALL, 5 );
	
	m_select_map_2 = new wxToggleButton( this, wxID_ANY, wxT("2"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_map_2->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_map_2->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_map_2->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	
	bSizer32->Add( m_select_map_2, 0, wxALL, 5 );
	
	m_select_map_3 = new wxToggleButton( this, wxID_ANY, wxT("3"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_map_3->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_map_3->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_map_3->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer32->Add( m_select_map_3, 0, wxALL, 5 );
	
	m_select_map_4 = new wxToggleButton( this, wxID_ANY, wxT("4"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_map_4->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_map_4->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_map_4->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer32->Add( m_select_map_4, 0, wxALL, 5 );
	
	m_select_map_5 = new wxToggleButton( this, wxID_ANY, wxT("5"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_map_5->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_map_5->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_map_5->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer32->Add( m_select_map_5, 0, wxALL, 5 );
	
	m_select_map_6 = new wxToggleButton( this, wxID_ANY, wxT("6"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_map_6->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_map_6->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_map_6->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer32->Add( m_select_map_6, 0, wxALL, 5 );
	
	m_select_map_7 = new wxToggleButton( this, wxID_ANY, wxT("7"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_map_7->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_map_7->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_map_7->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer32->Add( m_select_map_7, 0, wxALL, 5 );
	
	m_select_map_8 = new wxToggleButton( this, wxID_ANY, wxT("8"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_map_8->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_map_8->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_map_8->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer32->Add( m_select_map_8, 0, wxALL, 5 );
	
	m_staticline18 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizer32->Add( m_staticline18, 0, wxEXPAND|wxALL, 9 );
	
	m_select_map_9 = new wxToggleButton( this, wxID_ANY, wxT("9"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_map_9->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_map_9->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_map_9->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer32->Add( m_select_map_9, 0, wxALL, 5 );
	
	m_select_map_10 = new wxToggleButton( this, wxID_ANY, wxT("A"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_map_10->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_map_10->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_map_10->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer32->Add( m_select_map_10, 0, wxALL, 5 );
	
	m_select_map_11 = new wxToggleButton( this, wxID_ANY, wxT("B"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_map_11->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_map_11->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_map_11->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer32->Add( m_select_map_11, 0, wxALL, 5 );
	
	m_select_map_12 = new wxToggleButton( this, wxID_ANY, wxT("C"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_map_12->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_map_12->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_map_12->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer32->Add( m_select_map_12, 0, wxALL, 5 );
	
	m_select_map_13 = new wxToggleButton( this, wxID_ANY, wxT("D"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_map_13->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_map_13->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_map_13->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer32->Add( m_select_map_13, 0, wxALL, 5 );
	
	m_select_map_14 = new wxToggleButton( this, wxID_ANY, wxT("E"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_map_14->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_map_14->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_map_14->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer32->Add( m_select_map_14, 0, wxALL, 5 );
	
	m_select_map_15 = new wxToggleButton( this, wxID_ANY, wxT("F"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_map_15->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_map_15->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_map_15->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer32->Add( m_select_map_15, 0, wxALL, 5 );
	
	m_select_map_16 = new wxToggleButton( this, wxID_ANY, wxT("G"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_map_16->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_map_16->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_map_16->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer32->Add( m_select_map_16, 0, wxALL, 5 );
	
	
	bSizer63->Add( bSizer32, 0, wxALIGN_LEFT|wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer24;
	fgSizer24 = new wxFlexGridSizer( 0, 5, 0, 0 );
	fgSizer24->AddGrowableCol( 0 );
	fgSizer24->AddGrowableCol( 1 );
	fgSizer24->AddGrowableCol( 2 );
	fgSizer24->AddGrowableCol( 3 );
	fgSizer24->SetFlexibleDirection( wxBOTH );
	fgSizer24->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer24->SetMinSize( wxSize( 980,452 ) ); 
	m_vca_env_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_vca_env_panel->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( m_vca_env_panel, wxID_ANY, wxT("VCA Envelope Graph") ), wxVERTICAL );
	
	m_vca_env_disp = new EnvDisp(m_vca_env_panel, wxID_ANY, wxDefaultPosition, wxSize(300, 177));
	sbSizer1->Add( m_vca_env_disp, 1, wxEXPAND, 5 );
	
	
	m_vca_env_panel->SetSizer( sbSizer1 );
	m_vca_env_panel->Layout();
	sbSizer1->Fit( m_vca_env_panel );
	fgSizer24->Add( m_vca_env_panel, 1, wxALL|wxEXPAND|wxALIGN_BOTTOM, 5 );
	
	
	fgSizer24->Add( 4, 0, 0, 0, 5 );
	
	m_vcf_env_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_vcf_env_panel->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	wxStaticBoxSizer* sbSizer11;
	sbSizer11 = new wxStaticBoxSizer( new wxStaticBox( m_vcf_env_panel, wxID_ANY, wxT("VCF Envelope Graph") ), wxVERTICAL );
	
	m_vcf_env_disp = new EnvDisp(m_vcf_env_panel, wxID_ANY, wxDefaultPosition, wxSize(300,177));
	m_vcf_env_disp->SetToolTip( wxT("Click to switch between VCF Envelope Settings and VCF Cutoff Modulation by the Envelope Settings") );
	
	sbSizer11->Add( m_vcf_env_disp, 1, wxEXPAND, 0 );
	
	
	m_vcf_env_panel->SetSizer( sbSizer11 );
	m_vcf_env_panel->Layout();
	sbSizer11->Fit( m_vcf_env_panel );
	fgSizer24->Add( m_vcf_env_panel, 1, wxEXPAND|wxTOP|wxBOTTOM|wxALIGN_BOTTOM, 5 );
	
	
	fgSizer24->Add( 4, 0, 0, 0, 5 );
	
	m_panel64111 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer26111;
	fgSizer26111 = new wxFlexGridSizer( 0, 6, 0, 0 );
	fgSizer26111->SetFlexibleDirection( wxBOTH );
	fgSizer26111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText234111 = new wxStaticText( m_panel64111, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText234111->Wrap( -1 );
	fgSizer26111->Add( m_staticText234111, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText238111 = new wxStaticText( m_panel64111, wxID_ANY, wxT("Velocity"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText238111->Wrap( -1 );
	m_staticText238111->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer26111->Add( m_staticText238111, 0, wxALIGN_RIGHT|wxTOP|wxBOTTOM, 5 );
	
	m_staticText239111 = new wxStaticText( m_panel64111, wxID_ANY, wxT("Scaling"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText239111->Wrap( -1 );
	m_staticText239111->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer26111->Add( m_staticText239111, 0, wxTOP|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText283 = new wxStaticText( m_panel64111, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText283->Wrap( -1 );
	fgSizer26111->Add( m_staticText283, 0, 0, 5 );
	
	m_staticline1 = new wxStaticLine( m_panel64111, wxID_ANY, wxDefaultPosition, wxSize( -1,25 ), wxLI_VERTICAL );
	m_staticline1->Enable( false );
	
	fgSizer26111->Add( m_staticline1, 0, wxALIGN_RIGHT, 5 );
	
	m_sound_direction_reversed = new wxCheckBox( m_panel64111, wxID_ANY, wxT(" Reverse"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_sound_direction_reversed->SetToolTip( wxT("Reverses all samples in this map") );
	
	fgSizer26111->Add( m_sound_direction_reversed, 0, wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_attack_vel_sensitivity = new wxSlider( m_panel64111, wxID_ANY, 0, -127, 127, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	m_attack_vel_sensitivity->SetToolTip( wxT("Influences both ADSRs") );
	
	fgSizer26111->Add( m_attack_vel_sensitivity, 0, wxALIGN_CENTER_VERTICAL|wxRIGHT|wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_release_vel_sensitivity = new wxSlider( m_panel64111, wxID_ANY, 0, -127, 127, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	m_release_vel_sensitivity->SetToolTip( wxT("Influences both ADSRs") );
	
	fgSizer26111->Add( m_release_vel_sensitivity, 0, wxRIGHT|wxLEFT, 5 );
	
	m_amp_peak_vel_sensitivity = new wxSlider( m_panel64111, wxID_ANY, 0, -127, 127, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	m_amp_peak_vel_sensitivity->SetToolTip( wxT("VCA Envelope Amount") );
	
	fgSizer26111->Add( m_amp_peak_vel_sensitivity, 0, wxRIGHT|wxLEFT, 5 );
	
	m_filt_peak_vel_sensitivity = new wxSlider( m_panel64111, wxID_ANY, 0, -127, 127, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	m_filt_peak_vel_sensitivity->SetToolTip( wxT("Scale VCF Envelope Amount") );
	
	fgSizer26111->Add( m_filt_peak_vel_sensitivity, 0, wxRIGHT|wxLEFT, 5 );
	
	m_staticline7 = new wxStaticLine( m_panel64111, wxID_ANY, wxDefaultPosition, wxSize( -1,100 ), wxLI_VERTICAL );
	fgSizer26111->Add( m_staticline7, 0, wxLEFT|wxALIGN_RIGHT, 5 );
	
	m_velocity_start_point = new wxSlider( m_panel64111, wxID_ANY, 0, -127, 127, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	m_velocity_start_point->SetToolTip( wxT("Impact of Velocity on start point of all samples in this map") );
	
	fgSizer26111->Add( m_velocity_start_point, 0, wxALIGN_BOTTOM, 5 );
	
	m_staticText247111 = new wxStaticText( m_panel64111, wxID_ANY, wxT("Attack "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText247111->Wrap( -1 );
	fgSizer26111->Add( m_staticText247111, 1, wxALIGN_RIGHT|wxLEFT, 5 );
	
	m_staticText248111 = new wxStaticText( m_panel64111, wxID_ANY, wxT("Release"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText248111->Wrap( -1 );
	fgSizer26111->Add( m_staticText248111, 0, wxALIGN_RIGHT, 5 );
	
	m_staticText246111 = new wxStaticText( m_panel64111, wxID_ANY, wxT("VCA Peak"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText246111->Wrap( -1 );
	fgSizer26111->Add( m_staticText246111, 0, wxALIGN_RIGHT, 5 );
	
	m_staticText249111 = new wxStaticText( m_panel64111, wxID_ANY, wxT("VFC Peak"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText249111->Wrap( -1 );
	fgSizer26111->Add( m_staticText249111, 0, wxBOTTOM|wxLEFT|wxALIGN_RIGHT, 5 );
	
	m_staticText284 = new wxStaticText( m_panel64111, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText284->Wrap( -1 );
	fgSizer26111->Add( m_staticText284, 0, wxALL, 5 );
	
	m_staticText250111 = new wxStaticText( m_panel64111, wxID_ANY, wxT("Sample Start"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText250111->Wrap( -1 );
	m_staticText250111->SetToolTip( wxT("Impact of Velocity on start point of all samples in this map") );
	
	fgSizer26111->Add( m_staticText250111, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_attack_vel_sensitivity_percentage = new wxTextCtrl( m_panel64111, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_attack_vel_sensitivity_percentage->SetMaxLength( 4 ); 
	m_attack_vel_sensitivity_percentage->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer26111->Add( m_attack_vel_sensitivity_percentage, 0, wxALIGN_RIGHT, 5 );
	
	m_release_vel_sensitivity_percentage = new wxTextCtrl( m_panel64111, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_release_vel_sensitivity_percentage->SetMaxLength( 4 ); 
	m_release_vel_sensitivity_percentage->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer26111->Add( m_release_vel_sensitivity_percentage, 0, wxALIGN_RIGHT, 5 );
	
	m_amp_peak_vel_sensitivity_percentage = new wxTextCtrl( m_panel64111, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_amp_peak_vel_sensitivity_percentage->SetMaxLength( 4 ); 
	m_amp_peak_vel_sensitivity_percentage->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer26111->Add( m_amp_peak_vel_sensitivity_percentage, 0, wxALIGN_RIGHT|wxBOTTOM, 5 );
	
	m_filt_peak_vel_sensitivity_percentage = new wxTextCtrl( m_panel64111, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_filt_peak_vel_sensitivity_percentage->SetMaxLength( 4 ); 
	m_filt_peak_vel_sensitivity_percentage->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer26111->Add( m_filt_peak_vel_sensitivity_percentage, 0, wxALIGN_RIGHT, 5 );
	
	m_staticText285 = new wxStaticText( m_panel64111, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText285->Wrap( -1 );
	fgSizer26111->Add( m_staticText285, 0, wxALL, 5 );
	
	m_velocity_start_point_percentage = new wxTextCtrl( m_panel64111, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_velocity_start_point_percentage->SetMaxLength( 4 ); 
	m_velocity_start_point_percentage->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer26111->Add( m_velocity_start_point_percentage, 0, wxRIGHT|wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	m_panel64111->SetSizer( fgSizer26111 );
	m_panel64111->Layout();
	fgSizer26111->Fit( m_panel64111 );
	m_menu74 = new wxMenu();
	wxMenuItem* load_menu4;
	load_menu4 = new wxMenuItem( m_menu74, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu74->Append( load_menu4 );
	
	wxMenuItem* m_menuItem204;
	m_menuItem204 = new wxMenuItem( m_menu74, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu74->Append( m_menuItem204 );
	
	m_menu74->AppendSeparator();
	
	wxMenuItem* m_menuItem214;
	m_menuItem214 = new wxMenuItem( m_menu74, wxID_ANY, wxString( wxT("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu74->Append( m_menuItem214 );
	
	m_panel64111->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( MapPanel::m_panel64111OnContextMenu ), NULL, this ); 
	
	fgSizer24->Add( m_panel64111, 1, wxALIGN_RIGHT|wxALL|wxEXPAND, 5 );
	
	m_panel59 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer26;
	fgSizer26 = new wxFlexGridSizer( 0, 5, 0, 0 );
	fgSizer26->AddGrowableCol( 0 );
	fgSizer26->AddGrowableCol( 1 );
	fgSizer26->AddGrowableCol( 2 );
	fgSizer26->AddGrowableCol( 3 );
	fgSizer26->AddGrowableCol( 4 );
	fgSizer26->SetFlexibleDirection( wxBOTH );
	fgSizer26->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText235 = new wxStaticText( m_panel59, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText235->Wrap( -1 );
	fgSizer26->Add( m_staticText235, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_staticText234 = new wxStaticText( m_panel59, wxID_ANY, wxT("VCA"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText234->Wrap( -1 );
	m_staticText234->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer26->Add( m_staticText234, 0, wxALIGN_RIGHT|wxTOP|wxBOTTOM, 5 );
	
	m_staticText238 = new wxStaticText( m_panel59, wxID_ANY, wxT("Envelope"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText238->Wrap( -1 );
	m_staticText238->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer26->Add( m_staticText238, 0, wxTOP|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText239 = new wxStaticText( m_panel59, wxID_ANY, wxT("Scaling"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText239->Wrap( -1 );
	m_staticText239->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer26->Add( m_staticText239, 0, wxTOP|wxRIGHT, 5 );
	
	m_staticText240 = new wxStaticText( m_panel59, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText240->Wrap( -1 );
	fgSizer26->Add( m_staticText240, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_amp_attack_rate = new wxSlider( m_panel59, wxID_ANY, 0, -127, 127, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	fgSizer26->Add( m_amp_attack_rate, 0, wxRIGHT, 5 );
	
	m_amp_decay_rate = new wxSlider( m_panel59, wxID_ANY, 0, -127, 127, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	fgSizer26->Add( m_amp_decay_rate, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );
	
	m_amp_sustain_level = new wxSlider( m_panel59, wxID_ANY, 0, -127, 127, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	fgSizer26->Add( m_amp_sustain_level, 0, wxRIGHT|wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_amp_release_rate = new wxSlider( m_panel59, wxID_ANY, 0, -127, 127, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	fgSizer26->Add( m_amp_release_rate, 0, wxRIGHT|wxLEFT, 5 );
	
	m_amp_2nd_release_rate = new wxSlider( m_panel59, wxID_ANY, 0, -127, 127, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	fgSizer26->Add( m_amp_2nd_release_rate, 0, wxRIGHT|wxLEFT, 5 );
	
	m_staticText246 = new wxStaticText( m_panel59, wxID_ANY, wxT("Attack"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText246->Wrap( -1 );
	fgSizer26->Add( m_staticText246, 0, wxALIGN_RIGHT|wxRIGHT, 5 );
	
	m_staticText247 = new wxStaticText( m_panel59, wxID_ANY, wxT("Decay"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText247->Wrap( -1 );
	fgSizer26->Add( m_staticText247, 0, wxALIGN_RIGHT|wxRIGHT, 5 );
	
	m_staticText248 = new wxStaticText( m_panel59, wxID_ANY, wxT("Sustain"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText248->Wrap( -1 );
	fgSizer26->Add( m_staticText248, 0, wxALIGN_RIGHT, 5 );
	
	m_staticText249 = new wxStaticText( m_panel59, wxID_ANY, wxT("Release"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText249->Wrap( -1 );
	fgSizer26->Add( m_staticText249, 0, wxALIGN_RIGHT|wxLEFT, 5 );
	
	m_staticText250 = new wxStaticText( m_panel59, wxID_ANY, wxT("    2nd Rel."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText250->Wrap( -1 );
	fgSizer26->Add( m_staticText250, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );
	
	m_amp_attack_rate_percentage = new wxTextCtrl( m_panel59, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_amp_attack_rate_percentage->SetMaxLength( 4 ); 
	m_amp_attack_rate_percentage->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer26->Add( m_amp_attack_rate_percentage, 0, wxBOTTOM|wxALIGN_RIGHT, 5 );
	
	m_amp_decay_rate_percentage = new wxTextCtrl( m_panel59, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_amp_decay_rate_percentage->SetMaxLength( 4 ); 
	m_amp_decay_rate_percentage->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer26->Add( m_amp_decay_rate_percentage, 0, wxALIGN_RIGHT, 5 );
	
	m_amp_sustain_level_percentage = new wxTextCtrl( m_panel59, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_amp_sustain_level_percentage->SetMaxLength( 4 ); 
	m_amp_sustain_level_percentage->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer26->Add( m_amp_sustain_level_percentage, 0, wxALIGN_RIGHT, 5 );
	
	m_amp_release_rate_percentage = new wxTextCtrl( m_panel59, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_amp_release_rate_percentage->SetMaxLength( 4 ); 
	m_amp_release_rate_percentage->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer26->Add( m_amp_release_rate_percentage, 0, wxALIGN_RIGHT, 5 );
	
	m_amp_2nd_release_rate_percentage = new wxTextCtrl( m_panel59, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_amp_2nd_release_rate_percentage->SetMaxLength( 4 ); 
	m_amp_2nd_release_rate_percentage->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer26->Add( m_amp_2nd_release_rate_percentage, 0, wxALIGN_RIGHT|wxRIGHT|wxLEFT, 5 );
	
	
	fgSizer26->Add( 0, 4, 0, 0, 5 );
	
	
	fgSizer26->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	fgSizer26->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	fgSizer26->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	fgSizer26->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	m_panel59->SetSizer( fgSizer26 );
	m_panel59->Layout();
	fgSizer26->Fit( m_panel59 );
	m_menu71 = new wxMenu();
	wxMenuItem* load_menu1;
	load_menu1 = new wxMenuItem( m_menu71, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu71->Append( load_menu1 );
	
	wxMenuItem* m_menuItem201;
	m_menuItem201 = new wxMenuItem( m_menu71, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu71->Append( m_menuItem201 );
	
	m_menu71->AppendSeparator();
	
	wxMenuItem* m_menuItem211;
	m_menuItem211 = new wxMenuItem( m_menu71, wxID_ANY, wxString( wxT("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu71->Append( m_menuItem211 );
	
	m_panel59->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( MapPanel::m_panel59OnContextMenu ), NULL, this ); 
	
	fgSizer24->Add( m_panel59, 1, wxALL|wxEXPAND, 5 );
	
	
	fgSizer24->Add( 2, 0, 0, 0, 5 );
	
	m_panel641 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer261;
	fgSizer261 = new wxFlexGridSizer( 0, 5, 0, 0 );
	fgSizer261->AddGrowableCol( 0 );
	fgSizer261->AddGrowableCol( 1 );
	fgSizer261->AddGrowableCol( 2 );
	fgSizer261->AddGrowableCol( 3 );
	fgSizer261->AddGrowableCol( 4 );
	fgSizer261->SetFlexibleDirection( wxBOTH );
	fgSizer261->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText2351 = new wxStaticText( m_panel641, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2351->Wrap( -1 );
	fgSizer261->Add( m_staticText2351, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_staticText2341 = new wxStaticText( m_panel641, wxID_ANY, wxT("VCF"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2341->Wrap( -1 );
	m_staticText2341->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer261->Add( m_staticText2341, 0, wxALIGN_RIGHT|wxTOP|wxBOTTOM, 5 );
	
	m_staticText2381 = new wxStaticText( m_panel641, wxID_ANY, wxT("Envelope"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2381->Wrap( -1 );
	m_staticText2381->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer261->Add( m_staticText2381, 0, wxTOP|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText2391 = new wxStaticText( m_panel641, wxID_ANY, wxT("Scaling"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2391->Wrap( -1 );
	m_staticText2391->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer261->Add( m_staticText2391, 0, wxTOP, 5 );
	
	m_staticText2401 = new wxStaticText( m_panel641, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2401->Wrap( -1 );
	fgSizer261->Add( m_staticText2401, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_filt_attack_rate = new wxSlider( m_panel641, wxID_ANY, 0, -127, 127, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	fgSizer261->Add( m_filt_attack_rate, 0, wxRIGHT, 5 );
	
	m_filt_decay_rate = new wxSlider( m_panel641, wxID_ANY, 0, -127, 127, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	fgSizer261->Add( m_filt_decay_rate, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );
	
	m_filt_sustain_level = new wxSlider( m_panel641, wxID_ANY, 0, -127, 127, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	fgSizer261->Add( m_filt_sustain_level, 0, wxRIGHT|wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_filt_release_rate = new wxSlider( m_panel641, wxID_ANY, 0, -127, 127, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	fgSizer261->Add( m_filt_release_rate, 0, wxRIGHT|wxLEFT, 5 );
	
	m_filt_2nd_release_rate = new wxSlider( m_panel641, wxID_ANY, 0, -127, 127, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	fgSizer261->Add( m_filt_2nd_release_rate, 0, wxRIGHT|wxLEFT, 5 );
	
	m_staticText2461 = new wxStaticText( m_panel641, wxID_ANY, wxT("Attack"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2461->Wrap( -1 );
	fgSizer261->Add( m_staticText2461, 0, wxALIGN_RIGHT|wxRIGHT, 5 );
	
	m_staticText2471 = new wxStaticText( m_panel641, wxID_ANY, wxT("Decay"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2471->Wrap( -1 );
	fgSizer261->Add( m_staticText2471, 0, wxALIGN_RIGHT|wxRIGHT, 5 );
	
	m_staticText2481 = new wxStaticText( m_panel641, wxID_ANY, wxT("Sustain"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2481->Wrap( -1 );
	fgSizer261->Add( m_staticText2481, 0, wxALIGN_RIGHT, 5 );
	
	m_staticText2491 = new wxStaticText( m_panel641, wxID_ANY, wxT("Release"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2491->Wrap( -1 );
	fgSizer261->Add( m_staticText2491, 0, wxALIGN_RIGHT|wxLEFT, 5 );
	
	m_staticText2501 = new wxStaticText( m_panel641, wxID_ANY, wxT("    2nd Rel."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2501->Wrap( -1 );
	fgSizer261->Add( m_staticText2501, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );
	
	m_filt_attack_rate_percentage = new wxTextCtrl( m_panel641, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_filt_attack_rate_percentage->SetMaxLength( 4 ); 
	m_filt_attack_rate_percentage->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer261->Add( m_filt_attack_rate_percentage, 0, wxALIGN_RIGHT|wxBOTTOM, 5 );
	
	m_filt_decay_rate_percentage = new wxTextCtrl( m_panel641, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_filt_decay_rate_percentage->SetMaxLength( 4 ); 
	m_filt_decay_rate_percentage->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer261->Add( m_filt_decay_rate_percentage, 0, wxALIGN_RIGHT, 5 );
	
	m_filt_sustain_level_percentage = new wxTextCtrl( m_panel641, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_filt_sustain_level_percentage->SetMaxLength( 4 ); 
	m_filt_sustain_level_percentage->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer261->Add( m_filt_sustain_level_percentage, 0, wxALIGN_RIGHT, 5 );
	
	m_filt_release_rate_percentage = new wxTextCtrl( m_panel641, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_filt_release_rate_percentage->SetMaxLength( 4 ); 
	m_filt_release_rate_percentage->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer261->Add( m_filt_release_rate_percentage, 0, wxALIGN_RIGHT, 5 );
	
	m_filt_2nd_release_rate_percentage = new wxTextCtrl( m_panel641, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_filt_2nd_release_rate_percentage->SetMaxLength( 4 ); 
	m_filt_2nd_release_rate_percentage->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer261->Add( m_filt_2nd_release_rate_percentage, 0, wxALIGN_RIGHT|wxRIGHT|wxLEFT, 5 );
	
	
	m_panel641->SetSizer( fgSizer261 );
	m_panel641->Layout();
	fgSizer261->Fit( m_panel641 );
	m_menu72 = new wxMenu();
	wxMenuItem* load_menu2;
	load_menu2 = new wxMenuItem( m_menu72, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu72->Append( load_menu2 );
	
	wxMenuItem* m_menuItem202;
	m_menuItem202 = new wxMenuItem( m_menu72, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu72->Append( m_menuItem202 );
	
	m_menu72->AppendSeparator();
	
	wxMenuItem* m_menuItem212;
	m_menuItem212 = new wxMenuItem( m_menu72, wxID_ANY, wxString( wxT("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu72->Append( m_menuItem212 );
	
	m_panel641->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( MapPanel::m_panel641OnContextMenu ), NULL, this ); 
	
	fgSizer24->Add( m_panel641, 1, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	
	fgSizer24->Add( 2, 0, 0, 0, 5 );
	
	m_panel6411 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer2611;
	fgSizer2611 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer2611->AddGrowableRow( 0 );
	fgSizer2611->SetFlexibleDirection( wxHORIZONTAL );
	fgSizer2611->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_panel40 = new wxPanel( m_panel6411, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_menu7211 = new wxMenu();
	wxMenuItem* load_menu211;
	load_menu211 = new wxMenuItem( m_menu7211, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu7211->Append( load_menu211 );
	
	wxMenuItem* m_menuItem20211;
	m_menuItem20211 = new wxMenuItem( m_menu7211, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu7211->Append( m_menuItem20211 );
	
	m_menu7211->AppendSeparator();
	
	wxMenuItem* m_menuItem21211;
	m_menuItem21211 = new wxMenuItem( m_menu7211, wxID_ANY, wxString( wxT("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu7211->Append( m_menuItem21211 );
	
	m_panel40->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( MapPanel::m_panel40OnContextMenu ), NULL, this ); 
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizer17->Add( 5, 0, 0, 0, 5 );
	
	m_panel41 = new wxPanel( m_panel40, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer55;
	fgSizer55 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer55->SetFlexibleDirection( wxBOTH );
	fgSizer55->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText293 = new wxStaticText( m_panel41, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText293->Wrap( -1 );
	fgSizer55->Add( m_staticText293, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_staticText23811 = new wxStaticText( m_panel41, wxID_ANY, wxT("Filter"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23811->Wrap( -1 );
	m_staticText23811->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer55->Add( m_staticText23811, 0, wxTOP|wxBOTTOM|wxALIGN_RIGHT, 5 );
	
	m_staticText23911 = new wxStaticText( m_panel41, wxID_ANY, wxT("Scaling"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23911->Wrap( -1 );
	m_staticText23911->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer55->Add( m_staticText23911, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxBOTTOM, 5 );
	
	
	fgSizer55->Add( 68, 0, 1, wxEXPAND, 5 );
	
	m_filt_cutoff = new wxSlider( m_panel41, wxID_ANY, 0, -127, 127, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	fgSizer55->Add( m_filt_cutoff, 0, wxRIGHT|wxLEFT, 5 );
	
	m_filt_resonance = new wxSlider( m_panel41, wxID_ANY, 0, -127, 127, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	fgSizer55->Add( m_filt_resonance, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );
	
	m_filt_env_amount = new wxSlider( m_panel41, wxID_ANY, 0, -127, 127, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	fgSizer55->Add( m_filt_env_amount, 0, wxRIGHT|wxLEFT, 5 );
	
	m_filt_keyboard_tracking = new wxSlider( m_panel41, wxID_ANY, 0, -127, 127, wxDefaultPosition, wxDefaultSize, wxSL_BOTH|wxSL_INVERSE|wxSL_LABELS|wxSL_SELRANGE|wxSL_VERTICAL );
	fgSizer55->Add( m_filt_keyboard_tracking, 0, wxRIGHT|wxLEFT, 5 );
	
	m_staticText24611 = new wxStaticText( m_panel41, wxID_ANY, wxT("Cutoff "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24611->Wrap( -1 );
	fgSizer55->Add( m_staticText24611, 0, wxALIGN_RIGHT|wxLEFT, 5 );
	
	m_staticText24711 = new wxStaticText( m_panel41, wxID_ANY, wxT("Reson."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24711->Wrap( -1 );
	fgSizer55->Add( m_staticText24711, 0, wxALIGN_RIGHT|wxLEFT, 5 );
	
	m_staticText24811 = new wxStaticText( m_panel41, wxID_ANY, wxT("Env. Amt"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24811->Wrap( -1 );
	fgSizer55->Add( m_staticText24811, 0, wxALIGN_RIGHT, 5 );
	
	m_staticText24911 = new wxStaticText( m_panel41, wxID_ANY, wxT("KB Track"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24911->Wrap( -1 );
	fgSizer55->Add( m_staticText24911, 0, wxRIGHT|wxLEFT|wxALIGN_RIGHT, 5 );
	
	m_filt_cutoff_percentage = new wxTextCtrl( m_panel41, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_filt_cutoff_percentage->SetMaxLength( 4 ); 
	m_filt_cutoff_percentage->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer55->Add( m_filt_cutoff_percentage, 0, wxALIGN_RIGHT|wxBOTTOM, 5 );
	
	m_filt_resonance_percentage = new wxTextCtrl( m_panel41, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_filt_resonance_percentage->SetMaxLength( 4 ); 
	m_filt_resonance_percentage->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer55->Add( m_filt_resonance_percentage, 0, wxALIGN_RIGHT, 5 );
	
	m_filt_env_amount_percentage = new wxTextCtrl( m_panel41, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_filt_env_amount_percentage->SetMaxLength( 4 ); 
	m_filt_env_amount_percentage->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer55->Add( m_filt_env_amount_percentage, 0, wxALIGN_RIGHT, 5 );
	
	m_filt_keyboard_tracking_percentage = new wxTextCtrl( m_panel41, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_filt_keyboard_tracking_percentage->SetMaxLength( 4 ); 
	m_filt_keyboard_tracking_percentage->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer55->Add( m_filt_keyboard_tracking_percentage, 0, wxRIGHT|wxLEFT|wxALIGN_RIGHT, 5 );
	
	
	fgSizer55->Add( 0, 3, 0, 0, 5 );
	
	
	fgSizer55->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	fgSizer55->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	fgSizer55->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	m_panel41->SetSizer( fgSizer55 );
	m_panel41->Layout();
	fgSizer55->Fit( m_panel41 );
	m_menu72111 = new wxMenu();
	wxMenuItem* load_menu2111;
	load_menu2111 = new wxMenuItem( m_menu72111, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu72111->Append( load_menu2111 );
	
	wxMenuItem* m_menuItem202111;
	m_menuItem202111 = new wxMenuItem( m_menu72111, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu72111->Append( m_menuItem202111 );
	
	m_menu72111->AppendSeparator();
	
	wxMenuItem* m_menuItem212111;
	m_menuItem212111 = new wxMenuItem( m_menu72111, wxID_ANY, wxString( wxT("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu72111->Append( m_menuItem212111 );
	
	m_panel41->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( MapPanel::m_panel41OnContextMenu ), NULL, this ); 
	
	bSizer17->Add( m_panel41, 1, wxEXPAND|wxTOP|wxBOTTOM, 5 );
	
	
	m_panel40->SetSizer( bSizer17 );
	m_panel40->Layout();
	bSizer17->Fit( m_panel40 );
	fgSizer2611->Add( m_panel40, 1, 0, 0 );
	
	
	fgSizer2611->Add( 4, 0, 0, 0, 0 );
	
	wxFlexGridSizer* fgSizer57;
	fgSizer57 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer57->AddGrowableRow( 0 );
	fgSizer57->SetFlexibleDirection( wxBOTH );
	fgSizer57->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	fgSizer57->Add( 0, 18, 0, 0, 5 );
	
	
	fgSizer57->Add( 0, 0, 0, 0, 5 );
	
	m_staticText289 = new wxStaticText( m_panel6411, wxID_ANY, wxT("Using"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText289->Wrap( -1 );
	fgSizer57->Add( m_staticText289, 1, wxTOP|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText288 = new wxStaticText( m_panel6411, wxID_ANY, wxT("Sound"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText288->Wrap( -1 );
	fgSizer57->Add( m_staticText288, 1, wxTOP|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_using_snd_1 = new wxToggleButton( m_panel6411, wxID_ANY, wxT("1"), wxDefaultPosition, wxSize( 32,-1 ), wxDOUBLE_BORDER );
	fgSizer57->Add( m_using_snd_1, 1, wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	m_using_snd_2 = new wxToggleButton( m_panel6411, wxID_ANY, wxT("2"), wxDefaultPosition, wxSize( 32,-1 ), wxDOUBLE_BORDER );
	fgSizer57->Add( m_using_snd_2, 1, wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	m_using_snd_3 = new wxToggleButton( m_panel6411, wxID_ANY, wxT("3"), wxDefaultPosition, wxSize( 30,-1 ), wxDOUBLE_BORDER );
	fgSizer57->Add( m_using_snd_3, 1, wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	m_using_snd_4 = new wxToggleButton( m_panel6411, wxID_ANY, wxT("4"), wxDefaultPosition, wxSize( 30,-1 ), wxDOUBLE_BORDER );
	fgSizer57->Add( m_using_snd_4, 1, wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	m_using_snd_5 = new wxToggleButton( m_panel6411, wxID_ANY, wxT("5"), wxDefaultPosition, wxSize( 30,-1 ), wxDOUBLE_BORDER );
	fgSizer57->Add( m_using_snd_5, 1, wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	m_using_snd_6 = new wxToggleButton( m_panel6411, wxID_ANY, wxT("6"), wxDefaultPosition, wxSize( 30,-1 ), wxDOUBLE_BORDER );
	fgSizer57->Add( m_using_snd_6, 1, wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	m_using_snd_7 = new wxToggleButton( m_panel6411, wxID_ANY, wxT("7"), wxDefaultPosition, wxSize( 30,-1 ), wxDOUBLE_BORDER );
	fgSizer57->Add( m_using_snd_7, 1, wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	m_using_snd_8 = new wxToggleButton( m_panel6411, wxID_ANY, wxT("8"), wxDefaultPosition, wxSize( 30,-1 ), wxDOUBLE_BORDER );
	fgSizer57->Add( m_using_snd_8, 1, wxTOP|wxBOTTOM|wxEXPAND, 5 );
	
	
	fgSizer2611->Add( fgSizer57, 1, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	
	m_panel6411->SetSizer( fgSizer2611 );
	m_panel6411->Layout();
	fgSizer2611->Fit( m_panel6411 );
	m_menu721 = new wxMenu();
	wxMenuItem* load_menu21;
	load_menu21 = new wxMenuItem( m_menu721, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu721->Append( load_menu21 );
	
	wxMenuItem* m_menuItem2021;
	m_menuItem2021 = new wxMenuItem( m_menu721, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu721->Append( m_menuItem2021 );
	
	m_menu721->AppendSeparator();
	
	wxMenuItem* m_menuItem2121;
	m_menuItem2121 = new wxMenuItem( m_menu721, wxID_ANY, wxString( wxT("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu721->Append( m_menuItem2121 );
	
	m_panel6411->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( MapPanel::m_panel6411OnContextMenu ), NULL, this ); 
	
	fgSizer24->Add( m_panel6411, 1, wxRIGHT|wxLEFT, 0 );
	
	
	fgSizer24->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	fgSizer24->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	fgSizer24->Add( 0, 0, 0, 0, 5 );
	
	
	fgSizer24->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	fgSizer24->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	bSizer63->Add( fgSizer24, 0, 0, 0 );
	
	
	this->SetSizer( bSizer63 );
	this->Layout();
	m_menu7 = new wxMenu();
	wxMenuItem* load_menu;
	load_menu = new wxMenuItem( m_menu7, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu7->Append( load_menu );
	
	wxMenuItem* m_menuItem20;
	m_menuItem20 = new wxMenuItem( m_menu7, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu7->Append( m_menuItem20 );
	
	m_menu7->AppendSeparator();
	
	wxMenuItem* m_menuItem21;
	m_menuItem21 = new wxMenuItem( m_menu7, wxID_ANY, wxString( wxT("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu7->Append( m_menuItem21 );
	
	this->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( MapPanel::MapPanelOnContextMenu ), NULL, this ); 
	
	
	// Connect Events
	m_select_map_1->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap1 ), NULL, this );
	m_select_map_2->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap2 ), NULL, this );
	m_select_map_3->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap3 ), NULL, this );
	m_select_map_4->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap4 ), NULL, this );
	m_select_map_5->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap5 ), NULL, this );
	m_select_map_6->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap6 ), NULL, this );
	m_select_map_7->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap7 ), NULL, this );
	m_select_map_8->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap8 ), NULL, this );
	m_select_map_9->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap9 ), NULL, this );
	m_select_map_10->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap10 ), NULL, this );
	m_select_map_11->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap11 ), NULL, this );
	m_select_map_12->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap12 ), NULL, this );
	m_select_map_13->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap13 ), NULL, this );
	m_select_map_14->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap14 ), NULL, this );
	m_select_map_15->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap15 ), NULL, this );
	m_select_map_16->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap16 ), NULL, this );
	m_vcf_env_disp->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( MapPanel::OnLeftDown ), NULL, this );
	m_sound_direction_reversed->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MapPanel::OnCheckboxChange ), NULL, this );
	m_attack_vel_sensitivity->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_release_vel_sensitivity->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_velocity_start_point->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnVelocitySampleStartSliderChange ), NULL, this );
	m_velocity_start_point->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnVelocitySampleStartSliderChange ), NULL, this );
	m_velocity_start_point->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnVelocitySampleStartSliderChange ), NULL, this );
	m_velocity_start_point->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnVelocitySampleStartSliderChange ), NULL, this );
	m_velocity_start_point->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnVelocitySampleStartSliderChange ), NULL, this );
	m_velocity_start_point->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnVelocitySampleStartSliderChange ), NULL, this );
	m_velocity_start_point->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnVelocitySampleStartSliderChange ), NULL, this );
	m_velocity_start_point->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnVelocitySampleStartSliderChange ), NULL, this );
	m_velocity_start_point->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnVelocitySampleStartSliderChange ), NULL, this );
	this->Connect( load_menu4->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnLoad ) );
	this->Connect( m_menuItem204->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnSave ) );
	this->Connect( m_menuItem214->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnCopy ) );
	m_amp_attack_rate->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_decay_rate->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_sustain_level->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_release_rate->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release_rate->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release_rate->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release_rate->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release_rate->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release_rate->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release_rate->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release_rate->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release_rate->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_2nd_release_rate->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release_rate->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release_rate->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release_rate->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release_rate->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release_rate->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release_rate->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release_rate->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release_rate->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	this->Connect( load_menu1->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnLoad ) );
	this->Connect( m_menuItem201->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnSave ) );
	this->Connect( m_menuItem211->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnCopy ) );
	m_filt_attack_rate->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_decay_rate->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_sustain_level->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_release_rate->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	this->Connect( load_menu2->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnLoad ) );
	this->Connect( m_menuItem202->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnSave ) );
	this->Connect( m_menuItem212->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnCopy ) );
	this->Connect( load_menu211->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnLoad ) );
	this->Connect( m_menuItem20211->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnSave ) );
	this->Connect( m_menuItem21211->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnCopy ) );
	m_filt_cutoff->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_resonance->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_env_amount->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_keyboard_tracking->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_keyboard_tracking->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_keyboard_tracking->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_keyboard_tracking->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_keyboard_tracking->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_keyboard_tracking->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_keyboard_tracking->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_keyboard_tracking->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_keyboard_tracking->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	this->Connect( load_menu2111->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnLoad ) );
	this->Connect( m_menuItem202111->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnSave ) );
	this->Connect( m_menuItem212111->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnCopy ) );
	m_using_snd_1->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnUsingSound1 ), NULL, this );
	m_using_snd_2->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnUsingSound2 ), NULL, this );
	m_using_snd_3->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnUsingSound3 ), NULL, this );
	m_using_snd_4->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnUsingSound4 ), NULL, this );
	m_using_snd_5->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnUsingSound5 ), NULL, this );
	m_using_snd_6->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnUsingSound6 ), NULL, this );
	m_using_snd_7->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnUsingSound7 ), NULL, this );
	m_using_snd_8->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnUsingSound8 ), NULL, this );
	this->Connect( load_menu21->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnLoad ) );
	this->Connect( m_menuItem2021->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnSave ) );
	this->Connect( m_menuItem2121->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnCopy ) );
	this->Connect( load_menu->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnLoad ) );
	this->Connect( m_menuItem20->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnSave ) );
	this->Connect( m_menuItem21->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnCopy ) );
}

MapPanel::~MapPanel()
{
	// Disconnect Events
	m_select_map_1->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap1 ), NULL, this );
	m_select_map_2->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap2 ), NULL, this );
	m_select_map_3->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap3 ), NULL, this );
	m_select_map_4->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap4 ), NULL, this );
	m_select_map_5->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap5 ), NULL, this );
	m_select_map_6->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap6 ), NULL, this );
	m_select_map_7->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap7 ), NULL, this );
	m_select_map_8->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap8 ), NULL, this );
	m_select_map_9->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap9 ), NULL, this );
	m_select_map_10->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap10 ), NULL, this );
	m_select_map_11->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap11 ), NULL, this );
	m_select_map_12->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap12 ), NULL, this );
	m_select_map_13->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap13 ), NULL, this );
	m_select_map_14->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap14 ), NULL, this );
	m_select_map_15->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap15 ), NULL, this );
	m_select_map_16->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnSelectMap16 ), NULL, this );
	m_vcf_env_disp->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( MapPanel::OnLeftDown ), NULL, this );
	m_sound_direction_reversed->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MapPanel::OnCheckboxChange ), NULL, this );
	m_attack_vel_sensitivity->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_attack_vel_sensitivity->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnVelocityAttackSliderChange ), NULL, this );
	m_release_vel_sensitivity->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_release_vel_sensitivity->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnVelocityReleaseSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_amp_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnVelocityVCAPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_filt_peak_vel_sensitivity->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnVelocityVFCPeakSliderChange ), NULL, this );
	m_velocity_start_point->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnVelocitySampleStartSliderChange ), NULL, this );
	m_velocity_start_point->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnVelocitySampleStartSliderChange ), NULL, this );
	m_velocity_start_point->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnVelocitySampleStartSliderChange ), NULL, this );
	m_velocity_start_point->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnVelocitySampleStartSliderChange ), NULL, this );
	m_velocity_start_point->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnVelocitySampleStartSliderChange ), NULL, this );
	m_velocity_start_point->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnVelocitySampleStartSliderChange ), NULL, this );
	m_velocity_start_point->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnVelocitySampleStartSliderChange ), NULL, this );
	m_velocity_start_point->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnVelocitySampleStartSliderChange ), NULL, this );
	m_velocity_start_point->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnVelocitySampleStartSliderChange ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnCopy ) );
	m_amp_attack_rate->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_attack_rate->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnAmpAttackSliderChange ), NULL, this );
	m_amp_decay_rate->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_decay_rate->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnAmpDecaySliderChange ), NULL, this );
	m_amp_sustain_level->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_sustain_level->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnAmpSustainSliderChange ), NULL, this );
	m_amp_release_rate->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release_rate->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release_rate->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release_rate->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release_rate->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release_rate->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release_rate->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release_rate->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_release_rate->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnAmpReleaseSliderChange ), NULL, this );
	m_amp_2nd_release_rate->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release_rate->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release_rate->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release_rate->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release_rate->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release_rate->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release_rate->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release_rate->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	m_amp_2nd_release_rate->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnAmpAltReleaseSliderChange ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnCopy ) );
	m_filt_attack_rate->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_attack_rate->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnFilterAttackSliderChange ), NULL, this );
	m_filt_decay_rate->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_decay_rate->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnFilterDecaySliderChange ), NULL, this );
	m_filt_sustain_level->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_sustain_level->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnFilterSustainSliderChange ), NULL, this );
	m_filt_release_rate->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_release_rate->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnFilterReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	m_filt_2nd_release_rate->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnFilterAltReleaseSliderChange ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnCopy ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnCopy ) );
	m_filt_cutoff->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_cutoff->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnFilterCutoffSliderChange ), NULL, this );
	m_filt_resonance->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_resonance->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnFilterResonanceSliderChange ), NULL, this );
	m_filt_env_amount->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_env_amount->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnFilterEnvelopeAmountSliderChange ), NULL, this );
	m_filt_keyboard_tracking->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MapPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_keyboard_tracking->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MapPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_keyboard_tracking->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MapPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_keyboard_tracking->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MapPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_keyboard_tracking->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MapPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_keyboard_tracking->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MapPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_keyboard_tracking->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MapPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_keyboard_tracking->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MapPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	m_filt_keyboard_tracking->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MapPanel::OnFilterKeyboardTrackSliderChange ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnCopy ) );
	m_using_snd_1->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnUsingSound1 ), NULL, this );
	m_using_snd_2->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnUsingSound2 ), NULL, this );
	m_using_snd_3->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnUsingSound3 ), NULL, this );
	m_using_snd_4->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnUsingSound4 ), NULL, this );
	m_using_snd_5->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnUsingSound5 ), NULL, this );
	m_using_snd_6->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnUsingSound6 ), NULL, this );
	m_using_snd_7->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnUsingSound7 ), NULL, this );
	m_using_snd_8->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapPanel::OnUsingSound8 ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnCopy ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MapPanel::OnCopy ) );
	
	delete m_menu74; 
	delete m_menu71; 
	delete m_menu72; 
	delete m_menu7211; 
	delete m_menu72111; 
	delete m_menu721; 
	delete m_menu7; 
}

PresetPanel::PresetPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	this->SetMinSize( wxSize( -1,450 ) );
	this->SetMaxSize( wxSize( -1,450 ) );
	
	m_menu2 = new wxMenu();
	wxMenuItem* m_menuItem4;
	m_menuItem4 = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem4 );
	
	wxMenuItem* m_menuItem5;
	m_menuItem5 = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem5 );
	
	m_menu2->AppendSeparator();
	
	wxMenuItem* m_menuItem6;
	m_menuItem6 = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem6 );
	
	this->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( PresetPanel::PresetPanelOnContextMenu ), NULL, this ); 
	
	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxVERTICAL );
	
	bSizer35->SetMinSize( wxSize( 980,452 ) ); 
	wxBoxSizer* bSizer321;
	bSizer321 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer321->SetMinSize( wxSize( 980,32 ) ); 
	m_select_preset1 = new wxToggleButton( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxSize( 71,-1 ), wxDOUBLE_BORDER );
	m_select_preset1->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_preset1->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_preset1->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer321->Add( m_select_preset1, 0, wxALL|wxEXPAND|wxFIXED_MINSIZE, 5 );
	
	m_select_preset2 = new wxToggleButton( this, wxID_ANY, wxT("2"), wxDefaultPosition, wxSize( 72,-1 ), wxDOUBLE_BORDER );
	m_select_preset2->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_preset2->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_preset2->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer321->Add( m_select_preset2, 0, wxALL|wxEXPAND|wxFIXED_MINSIZE, 5 );
	
	m_select_preset3 = new wxToggleButton( this, wxID_ANY, wxT("3"), wxDefaultPosition, wxSize( 71,-1 ), wxDOUBLE_BORDER );
	m_select_preset3->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_preset3->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_preset3->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer321->Add( m_select_preset3, 0, wxALL|wxFIXED_MINSIZE, 5 );
	
	m_select_preset4 = new wxToggleButton( this, wxID_ANY, wxT("4"), wxDefaultPosition, wxSize( 72,-1 ), wxDOUBLE_BORDER );
	m_select_preset4->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_preset4->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_preset4->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer321->Add( m_select_preset4, 0, wxALL|wxFIXED_MINSIZE, 5 );
	
	m_select_preset5 = new wxToggleButton( this, wxID_ANY, wxT("5"), wxDefaultPosition, wxSize( 71,-1 ), wxDOUBLE_BORDER );
	m_select_preset5->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_preset5->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_preset5->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer321->Add( m_select_preset5, 0, wxALL|wxFIXED_MINSIZE, 5 );
	
	m_select_preset6 = new wxToggleButton( this, wxID_ANY, wxT("6"), wxDefaultPosition, wxSize( 72,-1 ), wxDOUBLE_BORDER );
	m_select_preset6->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_preset6->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_preset6->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer321->Add( m_select_preset6, 0, wxALL|wxFIXED_MINSIZE, 5 );
	
	m_select_preset7 = new wxToggleButton( this, wxID_ANY, wxT("7"), wxDefaultPosition, wxSize( 72,-1 ), wxDOUBLE_BORDER );
	m_select_preset7->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_preset7->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_preset7->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer321->Add( m_select_preset7, 0, wxALL|wxFIXED_MINSIZE, 5 );
	
	m_select_preset8 = new wxToggleButton( this, wxID_ANY, wxT("8"), wxDefaultPosition, wxSize( 72,-1 ), wxDOUBLE_BORDER );
	m_select_preset8->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_preset8->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_preset8->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer321->Add( m_select_preset8, 0, wxALL|wxFIXED_MINSIZE, 5 );
	
	m_select_preset9 = new wxToggleButton( this, wxID_ANY, wxT("9"), wxDefaultPosition, wxSize( 71,-1 ), wxDOUBLE_BORDER );
	m_select_preset9->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_preset9->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_preset9->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer321->Add( m_select_preset9, 0, wxALL|wxFIXED_MINSIZE, 5 );
	
	m_select_preset10 = new wxToggleButton( this, wxID_ANY, wxT("10"), wxDefaultPosition, wxSize( 72,-1 ), wxDOUBLE_BORDER );
	m_select_preset10->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_preset10->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_preset10->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer321->Add( m_select_preset10, 0, wxALL|wxFIXED_MINSIZE, 5 );
	
	m_select_preset11 = new wxToggleButton( this, wxID_ANY, wxT("11"), wxDefaultPosition, wxSize( 72,-1 ), wxDOUBLE_BORDER );
	m_select_preset11->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_preset11->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_preset11->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer321->Add( m_select_preset11, 0, wxALL|wxFIXED_MINSIZE, 5 );
	
	m_select_preset12 = new wxToggleButton( this, wxID_ANY, wxT("12"), wxDefaultPosition, wxSize( 72,-1 ), wxDOUBLE_BORDER );
	m_select_preset12->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_preset12->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_preset12->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer321->Add( m_select_preset12, 0, wxALL|wxFIXED_MINSIZE, 5 );
	
	
	bSizer35->Add( bSizer321, 0, 0, 5 );
	
	wxFlexGridSizer* fgSizer3;
	fgSizer3 = new wxFlexGridSizer( 0, 5, 0, 0 );
	fgSizer3->AddGrowableCol( 0 );
	fgSizer3->AddGrowableCol( 1 );
	fgSizer3->AddGrowableCol( 2 );
	fgSizer3->AddGrowableCol( 3 );
	fgSizer3->SetFlexibleDirection( wxBOTH );
	fgSizer3->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer3->SetMinSize( wxSize( 980,452 ) ); 
	m_panel7611 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer51;
	fgSizer51 = new wxFlexGridSizer( 0, 5, 0, 0 );
	fgSizer51->SetFlexibleDirection( wxBOTH );
	fgSizer51->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxVERTICAL );
	
	
	bSizer18->Add( 0, 43, 0, 0, 5 );
	
	m_staticText1121 = new wxStaticText( m_panel7611, wxID_ANY, wxT(" Frequency"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1121->Wrap( -1 );
	bSizer18->Add( m_staticText1121, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxLEFT, 5 );
	
	
	bSizer18->Add( 0, 40, 0, 0, 5 );
	
	m_staticText11121 = new wxStaticText( m_panel7611, wxID_ANY, wxT(" Initial Amnt "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11121->Wrap( -1 );
	m_staticText11121->SetToolTip( wxT("Set level of modulation independent from Wheel position") );
	
	bSizer18->Add( m_staticText11121, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	
	bSizer18->Add( 0, 37, 1, wxEXPAND, 5 );
	
	m_staticText111111 = new wxStaticText( m_panel7611, wxID_ANY, wxT(" Velocity"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText111111->Wrap( -1 );
	m_staticText111111->SetToolTip( wxT("Control level of modulation by keyboard velocity") );
	
	bSizer18->Add( m_staticText111111, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxLEFT, 5 );
	
	
	bSizer18->Add( 0, 21, 0, 0, 5 );
	
	
	bSizer17->Add( bSizer18, 0, 0, 0 );
	
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText711 = new wxStaticText( m_panel7611, wxID_ANY, wxT("Modulation"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE|wxST_NO_AUTORESIZE );
	m_staticText711->Wrap( -1 );
	m_staticText711->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	m_staticText711->SetToolTip( wxT("LFO and Target settings") );
	
	bSizer19->Add( m_staticText711, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizer19->Add( 0, 4, 0, 0, 5 );
	
	m_lfo_freq = new wxSlider( m_panel7611, wxID_ANY, 0, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS|wxSUNKEN_BORDER );
	m_lfo_freq->SetToolTip( wxT("0 = DC routes wheel voltage as offset to target voltage") );
	
	bSizer19->Add( m_lfo_freq, 0, wxBOTTOM|wxRIGHT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer19->Add( 0, 2, 0, 0, 5 );
	
	m_lfo_init_amount = new wxSlider( m_panel7611, wxID_ANY, 0, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS|wxSUNKEN_BORDER, wxDefaultValidator, wxT("Test\n") );
	bSizer19->Add( m_lfo_init_amount, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer19->Add( 0, 2, 0, 0, 5 );
	
	m_lfo_vel_sensitivity = new wxSlider( m_panel7611, wxID_ANY, 0, -127, 127, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS|wxSUNKEN_BORDER, wxDefaultValidator, wxT("Test\n") );
	bSizer19->Add( m_lfo_vel_sensitivity, 0, wxALIGN_RIGHT|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	bSizer17->Add( bSizer19, 0, 0, 0 );
	
	
	bSizer17->Add( 24, 0, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxVERTICAL );
	
	
	bSizer20->Add( 0, 43, 0, 0, 0 );
	
	m_staticText1221 = new wxStaticText( m_panel7611, wxID_ANY, wxT("Pitch"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText1221->Wrap( -1 );
	m_staticText1221->SetToolTip( wxT("Vibrato") );
	
	bSizer20->Add( m_staticText1221, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	
	bSizer20->Add( 0, 40, 0, 0, 5 );
	
	m_staticText12121 = new wxStaticText( m_panel7611, wxID_ANY, wxT("VCF"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12121->Wrap( -1 );
	bSizer20->Add( m_staticText12121, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT, 5 );
	
	
	bSizer20->Add( 0, 36, 0, 0, 5 );
	
	m_staticText121111 = new wxStaticText( m_panel7611, wxID_ANY, wxT("VCA"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText121111->Wrap( -1 );
	bSizer20->Add( m_staticText121111, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5 );
	
	
	bSizer17->Add( bSizer20, 1, wxEXPAND, 0 );
	
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText911 = new wxStaticText( m_panel7611, wxID_ANY, wxT("Target"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText911->Wrap( -1 );
	m_staticText911->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	bSizer21->Add( m_staticText911, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer21->Add( 0, 20, 0, 0, 5 );
	
	wxArrayString m_vibratoChoices;
	m_vibrato = new wxChoice( m_panel7611, wxID_ANY, wxDefaultPosition, wxSize( 100,-1 ), m_vibratoChoices, 0 );
	m_vibrato->SetSelection( -1 );
	bSizer21->Add( m_vibrato, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	
	bSizer21->Add( 0, 31, 0, 0, 5 );
	
	wxArrayString m_lfo_filtChoices;
	m_lfo_filt = new wxChoice( m_panel7611, wxID_ANY, wxDefaultPosition, wxSize( 100,-1 ), m_lfo_filtChoices, 0 );
	m_lfo_filt->SetSelection( -1 );
	bSizer21->Add( m_lfo_filt, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	
	bSizer21->Add( 0, 30, 1, wxEXPAND, 5 );
	
	wxArrayString m_lfo_ampChoices;
	m_lfo_amp = new wxChoice( m_panel7611, wxID_ANY, wxDefaultPosition, wxSize( 100,-1 ), m_lfo_ampChoices, 0 );
	m_lfo_amp->SetSelection( -1 );
	bSizer21->Add( m_lfo_amp, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	
	bSizer17->Add( bSizer21, 0, wxRIGHT, 0 );
	
	
	fgSizer51->Add( bSizer17, 1, wxEXPAND|wxRIGHT, 10 );
	
	
	m_panel7611->SetSizer( fgSizer51 );
	m_panel7611->Layout();
	fgSizer51->Fit( m_panel7611 );
	m_menu21 = new wxMenu();
	wxMenuItem* m_menuItem41;
	m_menuItem41 = new wxMenuItem( m_menu21, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu21->Append( m_menuItem41 );
	
	wxMenuItem* m_menuItem51;
	m_menuItem51 = new wxMenuItem( m_menu21, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu21->Append( m_menuItem51 );
	
	m_menu21->AppendSeparator();
	
	wxMenuItem* m_menuItem61;
	m_menuItem61 = new wxMenuItem( m_menu21, wxID_ANY, wxString( wxT("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu21->Append( m_menuItem61 );
	
	m_panel7611->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( PresetPanel::m_panel7611OnContextMenu ), NULL, this ); 
	
	fgSizer3->Add( m_panel7611, 1, wxALL|wxEXPAND, 5 );
	
	
	fgSizer3->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_panel764 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer61;
	fgSizer61 = new wxFlexGridSizer( 4, 4, 0, 0 );
	fgSizer61->SetFlexibleDirection( wxBOTH );
	fgSizer61->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText651 = new wxStaticText( m_panel764, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText651->Wrap( -1 );
	fgSizer61->Add( m_staticText651, 0, wxALL, 5 );
	
	m_staticText661 = new wxStaticText( m_panel764, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText661->Wrap( -1 );
	m_staticText661->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer61->Add( m_staticText661, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );
	
	m_staticText671 = new wxStaticText( m_panel764, wxID_ANY, wxT("Controls"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText671->Wrap( -1 );
	m_staticText671->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer61->Add( m_staticText671, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	m_staticText681 = new wxStaticText( m_panel764, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText681->Wrap( -1 );
	fgSizer61->Add( m_staticText681, 0, wxALL, 5 );
	
	m_staticText692 = new wxStaticText( m_panel764, wxID_ANY, wxT(" Left Map"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText692->Wrap( -1 );
	fgSizer61->Add( m_staticText692, 0, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_left_map_selectionChoices;
	m_left_map_selection = new wxChoice( m_panel764, wxID_ANY, wxDefaultPosition, wxSize( 100,-1 ), m_left_map_selectionChoices, 0 );
	m_left_map_selection->SetSelection( -1 );
	fgSizer61->Add( m_left_map_selection, 0, wxALIGN_BOTTOM|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_staticText6911 = new wxStaticText( m_panel764, wxID_ANY, wxT("Kyb Mode"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6911->Wrap( -1 );
	fgSizer61->Add( m_staticText6911, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	wxArrayString m_keyboard_modeChoices;
	m_keyboard_mode = new wxChoice( m_panel764, wxID_ANY, wxDefaultPosition, wxSize( 130,-1 ), m_keyboard_modeChoices, 0 );
	m_keyboard_mode->SetSelection( -1 );
	fgSizer61->Add( m_keyboard_mode, 0, wxALL|wxALIGN_BOTTOM, 5 );
	
	m_staticText6931 = new wxStaticText( m_panel764, wxID_ANY, wxT(" Right Map"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6931->Wrap( -1 );
	fgSizer61->Add( m_staticText6931, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString m_right_map_selectionChoices;
	m_right_map_selection = new wxChoice( m_panel764, wxID_ANY, wxDefaultPosition, wxSize( 100,-1 ), m_right_map_selectionChoices, 0 );
	m_right_map_selection->SetSelection( -1 );
	fgSizer61->Add( m_right_map_selection, 0, wxALIGN_BOTTOM|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_staticText6941 = new wxStaticText( m_panel764, wxID_ANY, wxT("Split Point"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6941->Wrap( -1 );
	fgSizer61->Add( m_staticText6941, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_split_point = new wxTextCtrl( m_panel764, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 130,-1 ), wxTE_CENTRE|wxTE_PROCESS_ENTER );
	m_split_point->SetMaxLength( 0 ); 
	fgSizer61->Add( m_split_point, 0, wxALL, 5 );
	
	m_staticText6951 = new wxStaticText( m_panel764, wxID_ANY, wxT(" Key Transpose"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6951->Wrap( -1 );
	m_staticText6951->SetToolTip( wxT("Transpose keyboard in semitones") );
	
	fgSizer61->Add( m_staticText6951, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_transpose = new wxSlider( m_panel764, wxID_ANY, 0, -12, 12, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS|wxSUNKEN_BORDER, wxDefaultValidator, wxT("Test\n") );
	m_transpose->SetToolTip( wxT("Transpose keyboard in semitones") );
	
	fgSizer61->Add( m_transpose, 0, wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_staticText6981 = new wxStaticText( m_panel764, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6981->Wrap( -1 );
	fgSizer61->Add( m_staticText6981, 0, wxALL, 5 );
	
	m_dyn_alloc = new wxCheckBox( m_panel764, wxID_ANY, wxT(" Dynamic Allocation"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer61->Add( m_dyn_alloc, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_staticText69511 = new wxStaticText( m_panel764, wxID_ANY, wxT(" Velocity Thres."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText69511->Wrap( -1 );
	m_staticText69511->SetToolTip( wxT("Set the velocity switch threshold for VELOCITY SWITCH and VELOCITY CROSSFADE modes") );
	
	fgSizer61->Add( m_staticText69511, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxLEFT, 5 );
	
	m_vel_switch_threshold = new wxSlider( m_panel764, wxID_ANY, 63, 0, 127, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS|wxSUNKEN_BORDER, wxDefaultValidator, wxT("Test\n") );
	m_vel_switch_threshold->SetToolTip( wxT("Set the velocity switch threshold for VELOCITY SWITCH and VELOCITY CROSSFADE modes") );
	
	fgSizer61->Add( m_vel_switch_threshold, 0, wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_staticText695112 = new wxStaticText( m_panel764, wxID_ANY, wxT("Wheel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText695112->Wrap( -1 );
	m_staticText695112->SetToolTip( wxT("Pitch wheel range in Semitones (+/-)") );
	
	fgSizer61->Add( m_staticText695112, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP|wxLEFT, 5 );
	
	m_pitchwheel_range = new wxSlider( m_panel764, wxID_ANY, 0, 0, 4, wxDefaultPosition, wxSize( 130,-1 ), wxSL_HORIZONTAL|wxSL_LABELS|wxSUNKEN_BORDER, wxDefaultValidator, wxT("Test\n") );
	m_pitchwheel_range->SetToolTip( wxT("Pitch wheel range in Semitones (+/-)") );
	
	fgSizer61->Add( m_pitchwheel_range, 0, wxALL, 5 );
	
	
	fgSizer61->Add( 0, 5, 1, wxEXPAND, 5 );
	
	
	m_panel764->SetSizer( fgSizer61 );
	m_panel764->Layout();
	fgSizer61->Fit( m_panel764 );
	m_menu22 = new wxMenu();
	wxMenuItem* m_menuItem42;
	m_menuItem42 = new wxMenuItem( m_menu22, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu22->Append( m_menuItem42 );
	
	wxMenuItem* m_menuItem52;
	m_menuItem52 = new wxMenuItem( m_menu22, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu22->Append( m_menuItem52 );
	
	m_menu22->AppendSeparator();
	
	wxMenuItem* m_menuItem62;
	m_menuItem62 = new wxMenuItem( m_menu22, wxID_ANY, wxString( wxT("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu22->Append( m_menuItem62 );
	
	m_panel764->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( PresetPanel::m_panel764OnContextMenu ), NULL, this ); 
	
	fgSizer3->Add( m_panel764, 1, wxALL|wxEXPAND, 5 );
	
	
	fgSizer3->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_panel25 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer62;
	fgSizer62 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer62->SetFlexibleDirection( wxBOTH );
	fgSizer62->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	fgSizer62->Add( 40, 0, 0, 0, 5 );
	
	m_staticText45 = new wxStaticText( m_panel25, wxID_ANY, wxT("Stacking  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText45->Wrap( -1 );
	m_staticText45->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer62->Add( m_staticText45, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	fgSizer62->Add( 20, 0, 1, wxEXPAND, 5 );
	
	m_staticText279 = new wxStaticText( m_panel25, wxID_ANY, wxT(" Voices"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText279->Wrap( -1 );
	fgSizer62->Add( m_staticText279, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_stack_voicesChoices;
	m_stack_voices = new wxChoice( m_panel25, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_stack_voicesChoices, 0 );
	m_stack_voices->SetSelection( 0 );
	m_stack_voices->SetMinSize( wxSize( 100,-1 ) );
	
	fgSizer62->Add( m_stack_voices, 0, wxALL, 5 );
	
	
	fgSizer62->Add( 0, 0, 0, 0, 5 );
	
	
	fgSizer62->Add( 0, 25, 0, 0, 5 );
	
	m_stack_voices_preset_on = new wxCheckBox( m_panel25, wxID_ANY, wxT(" Stacking enable"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer62->Add( m_stack_voices_preset_on, 0, wxTOP|wxRIGHT|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	fgSizer62->Add( 0, 0, 0, 0, 5 );
	
	m_staticText280 = new wxStaticText( m_panel25, wxID_ANY, wxT(" Delay"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText280->Wrap( -1 );
	fgSizer62->Add( m_staticText280, 0, wxTOP|wxLEFT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_stack_delay = new wxSlider( m_panel25, wxID_ANY, 0, 0, 127, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS|wxSUNKEN_BORDER );
	fgSizer62->Add( m_stack_delay, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	fgSizer62->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText281 = new wxStaticText( m_panel25, wxID_ANY, wxT(" Detune"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText281->Wrap( -1 );
	fgSizer62->Add( m_staticText281, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxLEFT, 5 );
	
	m_stack_detune = new wxSlider( m_panel25, wxID_ANY, 0, 0, 63, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_LABELS|wxSUNKEN_BORDER );
	fgSizer62->Add( m_stack_detune, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	m_panel25->SetSizer( fgSizer62 );
	m_panel25->Layout();
	fgSizer62->Fit( m_panel25 );
	m_menu23 = new wxMenu();
	wxMenuItem* m_menuItem43;
	m_menuItem43 = new wxMenuItem( m_menu23, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu23->Append( m_menuItem43 );
	
	wxMenuItem* m_menuItem53;
	m_menuItem53 = new wxMenuItem( m_menu23, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu23->Append( m_menuItem53 );
	
	m_menu23->AppendSeparator();
	
	wxMenuItem* m_menuItem63;
	m_menuItem63 = new wxMenuItem( m_menu23, wxID_ANY, wxString( wxT("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu23->Append( m_menuItem63 );
	
	m_panel25->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( PresetPanel::m_panel25OnContextMenu ), NULL, this ); 
	
	fgSizer3->Add( m_panel25, 1, wxEXPAND|wxALL, 5 );
	
	m_panel26 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer7;
	fgSizer7 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer7->SetFlexibleDirection( wxBOTH );
	fgSizer7->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxBoxSizer* bSizer241;
	bSizer241 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxVERTICAL );
	
	
	bSizer25->Add( 0, 28, 0, 0, 5 );
	
	m_staticText4461 = new wxStaticText( m_panel26, wxID_ANY, wxT(" Arp Mode"), wxDefaultPosition, wxSize( 55,-1 ), 0 );
	m_staticText4461->Wrap( -1 );
	bSizer25->Add( m_staticText4461, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer25->Add( 0, 17, 0, 0, 5 );
	
	m_staticText4466 = new wxStaticText( m_panel26, wxID_ANY, wxT(" Octaves"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4466->Wrap( -1 );
	bSizer25->Add( m_staticText4466, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer25->Add( 0, 17, 0, 0, 5 );
	
	m_staticText44661 = new wxStaticText( m_panel26, wxID_ANY, wxT(" Repeats"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText44661->Wrap( -1 );
	bSizer25->Add( m_staticText44661, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer25->Add( 0, 18, 0, 0, 5 );
	
	m_staticText86 = new wxStaticText( m_panel26, wxID_ANY, wxT(" Arp Latch"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText86->Wrap( -1 );
	bSizer25->Add( m_staticText86, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer25->Add( 0, 0, 0, 0, 5 );
	
	
	bSizer241->Add( bSizer25, 0, 0, 0 );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText443 = new wxStaticText( m_panel26, wxID_ANY, wxT("Arpeggiator"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText443->Wrap( -1 );
	m_staticText443->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	bSizer26->Add( m_staticText443, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxBOTTOM, 5 );
	
	
	bSizer26->Add( 0, 1, 0, 0, 5 );
	
	wxArrayString m_arp_modeChoices;
	m_arp_mode = new wxChoice( m_panel26, wxID_ANY, wxDefaultPosition, wxSize( 100,-1 ), m_arp_modeChoices, 0 );
	m_arp_mode->SetSelection( -1 );
	bSizer26->Add( m_arp_mode, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizer26->Add( 0, 10, 1, wxEXPAND, 5 );
	
	wxArrayString m_arp_octChoices;
	m_arp_oct = new wxChoice( m_panel26, wxID_ANY, wxDefaultPosition, wxSize( 100,-1 ), m_arp_octChoices, 0 );
	m_arp_oct->SetSelection( -1 );
	bSizer26->Add( m_arp_oct, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	
	bSizer26->Add( 0, 10, 0, 0, 5 );
	
	wxArrayString m_arp_repeatsChoices;
	m_arp_repeats = new wxChoice( m_panel26, wxID_ANY, wxDefaultPosition, wxSize( 100,-1 ), m_arp_repeatsChoices, 0 );
	m_arp_repeats->SetSelection( -1 );
	bSizer26->Add( m_arp_repeats, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer26->Add( 0, 10, 0, 0, 5 );
	
	wxArrayString m_arp_latch_modeChoices;
	m_arp_latch_mode = new wxChoice( m_panel26, wxID_ANY, wxDefaultPosition, wxSize( 100,-1 ), m_arp_latch_modeChoices, 0 );
	m_arp_latch_mode->SetSelection( -1 );
	bSizer26->Add( m_arp_latch_mode, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer26->Add( 0, 2, 0, 0, 5 );
	
	
	bSizer241->Add( bSizer26, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxVERTICAL );
	
	
	bSizer27->Add( 0, 28, 0, 0, 5 );
	
	m_staticText4462 = new wxStaticText( m_panel26, wxID_ANY, wxT("Split Point"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4462->Wrap( -1 );
	bSizer27->Add( m_staticText4462, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer27->Add( 0, 17, 0, 0, 5 );
	
	m_staticText44651 = new wxStaticText( m_panel26, wxID_ANY, wxT("Split Type"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText44651->Wrap( -1 );
	bSizer27->Add( m_staticText44651, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer27->Add( 0, 17, 0, 0, 5 );
	
	m_staticText446611 = new wxStaticText( m_panel26, wxID_ANY, wxT("Rate"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText446611->Wrap( -1 );
	bSizer27->Add( m_staticText446611, 1, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_staticText4411 = new wxStaticText( m_panel26, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4411->Wrap( -1 );
	bSizer27->Add( m_staticText4411, 0, wxALIGN_RIGHT|wxTOP|wxBOTTOM|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer241->Add( bSizer27, 0, 0, 5 );
	
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxVERTICAL );
	
	
	bSizer28->Add( 0, 24, 1, wxEXPAND, 5 );
	
	m_arp_split_point = new wxTextCtrl( m_panel26, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_PROCESS_ENTER );
	m_arp_split_point->SetMaxLength( 0 ); 
	bSizer28->Add( m_arp_split_point, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer28->Add( 0, 9, 0, 0, 5 );
	
	wxArrayString m_arp_split_typeChoices;
	m_arp_split_type = new wxChoice( m_panel26, wxID_ANY, wxDefaultPosition, wxSize( 100,-1 ), m_arp_split_typeChoices, 0 );
	m_arp_split_type->SetSelection( -1 );
	m_arp_split_type->SetToolTip( wxT("Below Split: Arpeggiator active below split point\nAbove Split: Arpeggiator active above split point") );
	
	bSizer28->Add( m_arp_split_type, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizer28->Add( 0, 15, 0, 0, 5 );
	
	m_arp_rate = new wxSlider( m_panel26, wxID_ANY, 1, 0, 199, wxDefaultPosition, wxDefaultSize, wxSL_LABELS|wxSL_TOP|wxSUNKEN_BORDER );
	m_arp_rate->SetToolTip( wxT("0 synchronizes the Arpeggiator to the MIDI Clock") );
	
	bSizer28->Add( m_arp_rate, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );
	
	
	bSizer28->Add( 0, 2, 0, wxEXPAND, 5 );
	
	m_arp_preset_on = new wxCheckBox( m_panel26, wxID_ANY, wxT(" Arp enable"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer28->Add( m_arp_preset_on, 0, wxALIGN_TOP|wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 4 );
	
	
	bSizer241->Add( bSizer28, 0, 0, 5 );
	
	
	fgSizer7->Add( bSizer241, 1, wxRIGHT|wxEXPAND, 10 );
	
	
	m_panel26->SetSizer( fgSizer7 );
	m_panel26->Layout();
	fgSizer7->Fit( m_panel26 );
	m_menu24 = new wxMenu();
	wxMenuItem* m_menuItem44;
	m_menuItem44 = new wxMenuItem( m_menu24, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu24->Append( m_menuItem44 );
	
	wxMenuItem* m_menuItem54;
	m_menuItem54 = new wxMenuItem( m_menu24, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu24->Append( m_menuItem54 );
	
	m_menu24->AppendSeparator();
	
	wxMenuItem* m_menuItem64;
	m_menuItem64 = new wxMenuItem( m_menu24, wxID_ANY, wxString( wxT("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu24->Append( m_menuItem64 );
	
	m_panel26->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( PresetPanel::m_panel26OnContextMenu ), NULL, this ); 
	
	fgSizer3->Add( m_panel26, 1, wxALL|wxEXPAND, 5 );
	
	
	fgSizer3->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_panel27 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer8;
	fgSizer8 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer8->SetFlexibleDirection( wxBOTH );
	fgSizer8->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText1012 = new wxStaticText( m_panel27, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1012->Wrap( -1 );
	fgSizer8->Add( m_staticText1012, 0, wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_staticText102 = new wxStaticText( m_panel27, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText102->Wrap( -1 );
	m_staticText102->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer8->Add( m_staticText102, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxTOP, 5 );
	
	m_staticText103 = new wxStaticText( m_panel27, wxID_ANY, wxT("MIDI"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText103->Wrap( -1 );
	m_staticText103->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer8->Add( m_staticText103, 0, wxTOP, 5 );
	
	
	fgSizer8->Add( 0, 10, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	fgSizer8->Add( 0, 5, 0, 0, 5 );
	
	
	fgSizer8->Add( 0, 0, 0, 0, 5 );
	
	
	fgSizer8->Add( 0, 0, 0, 0, 5 );
	
	
	fgSizer8->Add( 0, 0, 0, 0, 5 );
	
	m_staticText108 = new wxStaticText( m_panel27, wxID_ANY, wxT(" Left Channel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText108->Wrap( -1 );
	fgSizer8->Add( m_staticText108, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_midi_left_chChoices;
	m_midi_left_ch = new wxChoice( m_panel27, wxID_ANY, wxDefaultPosition, wxSize( 100,-1 ), m_midi_left_chChoices, 0 );
	m_midi_left_ch->SetSelection( -1 );
	m_midi_left_ch->SetToolTip( wxT("Base or Left Channel") );
	
	fgSizer8->Add( m_midi_left_ch, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_rx_mod_wheel = new wxCheckBox( m_panel27, wxID_ANY, wxT("RX Mod Wheel"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8->Add( m_rx_mod_wheel, 0, wxALIGN_CENTER_VERTICAL|wxEXPAND|wxALL, 5 );
	
	m_tx_mod_wheel = new wxCheckBox( m_panel27, wxID_ANY, wxT("TX Mod Wheel"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8->Add( m_tx_mod_wheel, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	
	fgSizer8->Add( 0, 0, 0, 0, 5 );
	
	
	fgSizer8->Add( 0, 10, 0, 0, 5 );
	
	
	fgSizer8->Add( 0, 0, 0, 0, 5 );
	
	
	fgSizer8->Add( 0, 0, 0, 0, 5 );
	
	m_staticText111 = new wxStaticText( m_panel27, wxID_ANY, wxT(" Right Channel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText111->Wrap( -1 );
	fgSizer8->Add( m_staticText111, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString m_midi_right_chChoices;
	m_midi_right_ch = new wxChoice( m_panel27, wxID_ANY, wxDefaultPosition, wxSize( 100,-1 ), m_midi_right_chChoices, 0 );
	m_midi_right_ch->SetSelection( -1 );
	m_midi_right_ch->SetToolTip( wxT("Right Channel (Modes 3A only)") );
	
	fgSizer8->Add( m_midi_right_ch, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_rx_pitch_wheel = new wxCheckBox( m_panel27, wxID_ANY, wxT("RX Pitch Wheel"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8->Add( m_rx_pitch_wheel, 0, wxALIGN_CENTER_VERTICAL|wxEXPAND|wxALL, 5 );
	
	m_tx_pitch_wheel = new wxCheckBox( m_panel27, wxID_ANY, wxT("TX Pitch Wheel"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8->Add( m_tx_pitch_wheel, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );
	
	
	fgSizer8->Add( 0, 0, 0, 0, 5 );
	
	
	fgSizer8->Add( 0, 10, 0, 0, 5 );
	
	
	fgSizer8->Add( 0, 0, 0, 0, 5 );
	
	
	fgSizer8->Add( 0, 0, 0, 0, 5 );
	
	m_staticText109 = new wxStaticText( m_panel27, wxID_ANY, wxT(" MIDI Mode"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText109->Wrap( -1 );
	fgSizer8->Add( m_staticText109, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxArrayString m_midi_modeChoices;
	m_midi_mode = new wxChoice( m_panel27, wxID_ANY, wxDefaultPosition, wxSize( 100,-1 ), m_midi_modeChoices, 0 );
	m_midi_mode->SetSelection( -1 );
	m_midi_mode->SetToolTip( wxT("Mode 0   : SYSEX only  \nMode 1   : Omni \nMode 3A : Operate on Base Channel \nMode 3B : Assign left Map to left Channel and right Map to right Channel \nMode 4   : MIDI note on/off RX only, Sound# = Channel#\n- - - - Voice Expansion Modes/MIDI Overflow - - - - \nMode 1.   : Omni, no voice stealing\nMode 3.A: 3A, no MIDI TX outside of Channel \nMode 3.B: 3B, no modulations on right Channel \nMode 4.   : Mode 4, w/ local OFF") );
	
	fgSizer8->Add( m_midi_mode, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_rx_program_chg = new wxCheckBox( m_panel27, wxID_ANY, wxT("RX Prg Change"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8->Add( m_rx_program_chg, 0, wxALIGN_CENTER_VERTICAL|wxEXPAND|wxALL, 5 );
	
	m_tx_program_chg = new wxCheckBox( m_panel27, wxID_ANY, wxT("TX Prg Change"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8->Add( m_tx_program_chg, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	
	fgSizer8->Add( 0, 0, 0, 0, 5 );
	
	
	fgSizer8->Add( 0, 16, 0, 0, 5 );
	
	
	fgSizer8->Add( 0, 0, 0, 0, 5 );
	
	
	fgSizer8->Add( 0, 0, 0, 0, 5 );
	
	m_staticText101213 = new wxStaticText( m_panel27, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( -1,8 ), 0 );
	m_staticText101213->Wrap( -1 );
	fgSizer8->Add( m_staticText101213, 0, 0, 5 );
	
	m_staticText1122 = new wxStaticText( m_panel27, wxID_ANY, wxT("Pressure as Mod Wheel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1122->Wrap( -1 );
	fgSizer8->Add( m_staticText1122, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_rx_pressure_as_mod_wheel = new wxCheckBox( m_panel27, wxID_ANY, wxT("RX Pressure"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8->Add( m_rx_pressure_as_mod_wheel, 0, wxEXPAND|wxALIGN_BOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_tx_mod_wheel_as_pressure = new wxCheckBox( m_panel27, wxID_ANY, wxT("TX Pressure"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer8->Add( m_tx_mod_wheel_as_pressure, 1, wxEXPAND|wxRIGHT|wxLEFT|wxALIGN_BOTTOM, 5 );
	
	
	m_panel27->SetSizer( fgSizer8 );
	m_panel27->Layout();
	fgSizer8->Fit( m_panel27 );
	m_menu25 = new wxMenu();
	wxMenuItem* m_menuItem45;
	m_menuItem45 = new wxMenuItem( m_menu25, wxID_ANY, wxString( wxT("Load") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu25->Append( m_menuItem45 );
	
	wxMenuItem* m_menuItem55;
	m_menuItem55 = new wxMenuItem( m_menu25, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu25->Append( m_menuItem55 );
	
	m_menu25->AppendSeparator();
	
	wxMenuItem* m_menuItem65;
	m_menuItem65 = new wxMenuItem( m_menu25, wxID_ANY, wxString( wxT("Copy") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu25->Append( m_menuItem65 );
	
	m_panel27->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( PresetPanel::m_panel27OnContextMenu ), NULL, this ); 
	
	fgSizer3->Add( m_panel27, 1, wxALL|wxEXPAND, 5 );
	
	
	fgSizer3->Add( 0, 0, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer59;
	fgSizer59 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer59->SetFlexibleDirection( wxBOTH );
	fgSizer59->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	
	fgSizer59->Add( 0, 0, 0, 0, 5 );
	
	
	fgSizer59->Add( 0, 8, 0, wxALIGN_RIGHT|wxEXPAND, 5 );
	
	
	fgSizer59->Add( 10, 0, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxFlexGridSizer* fgSizer57;
	fgSizer57 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer57->AddGrowableCol( 0 );
	fgSizer57->AddGrowableCol( 2 );
	fgSizer57->AddGrowableRow( 0 );
	fgSizer57->AddGrowableRow( 2 );
	fgSizer57->SetFlexibleDirection( wxBOTH );
	fgSizer57->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_panel41 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( 60,-1 ), wxTAB_TRAVERSAL );
	m_panel41->SetMaxSize( wxSize( 60,-1 ) );
	
	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxVERTICAL );
	
	
	bSizer23->Add( 0, 1, 0, 0, 5 );
	
	m_left_map_selector = new wxToggleButton( m_panel41, wxID_ANY, wxT("Map 1"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_left_map_selector->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	m_left_map_selector->SetToolTip( wxT("Push to go to left Map") );
	m_left_map_selector->SetMinSize( wxSize( 60,-1 ) );
	
	bSizer23->Add( m_left_map_selector, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	wxFlexGridSizer* fgSizer571;
	fgSizer571 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer571->AddGrowableRow( 0 );
	fgSizer571->AddGrowableRow( 1 );
	fgSizer571->AddGrowableRow( 2 );
	fgSizer571->AddGrowableRow( 3 );
	fgSizer571->SetFlexibleDirection( wxBOTH );
	fgSizer571->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_using_snd_1 = new wxToggleButton( m_panel41, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_using_snd_1->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	m_using_snd_1->SetMinSize( wxSize( 30,-1 ) );
	
	fgSizer571->Add( m_using_snd_1, 1, wxEXPAND|wxBOTTOM, 5 );
	
	m_using_snd_2 = new wxToggleButton( m_panel41, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_using_snd_2->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	m_using_snd_2->SetMinSize( wxSize( 30,-1 ) );
	
	fgSizer571->Add( m_using_snd_2, 1, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxEXPAND, 5 );
	
	m_using_snd_3 = new wxToggleButton( m_panel41, wxID_ANY, wxT("3"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_using_snd_3->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	m_using_snd_3->SetMinSize( wxSize( 30,-1 ) );
	
	fgSizer571->Add( m_using_snd_3, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND|wxBOTTOM, 5 );
	
	m_using_snd_4 = new wxToggleButton( m_panel41, wxID_ANY, wxT("4"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_using_snd_4->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	m_using_snd_4->SetMinSize( wxSize( 30,-1 ) );
	
	fgSizer571->Add( m_using_snd_4, 1, wxEXPAND|wxBOTTOM, 5 );
	
	m_using_snd_5 = new wxToggleButton( m_panel41, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_using_snd_5->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	m_using_snd_5->SetMinSize( wxSize( 30,-1 ) );
	
	fgSizer571->Add( m_using_snd_5, 1, wxEXPAND|wxBOTTOM, 5 );
	
	m_using_snd_6 = new wxToggleButton( m_panel41, wxID_ANY, wxT("6"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_using_snd_6->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	m_using_snd_6->SetMinSize( wxSize( 30,-1 ) );
	
	fgSizer571->Add( m_using_snd_6, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxBOTTOM, 5 );
	
	m_using_snd_7 = new wxToggleButton( m_panel41, wxID_ANY, wxT("7"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_using_snd_7->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	m_using_snd_7->SetMinSize( wxSize( 30,-1 ) );
	
	fgSizer571->Add( m_using_snd_7, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_using_snd_8 = new wxToggleButton( m_panel41, wxID_ANY, wxT("8"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_using_snd_8->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	m_using_snd_8->SetMinSize( wxSize( 30,-1 ) );
	
	fgSizer571->Add( m_using_snd_8, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer23->Add( fgSizer571, 1, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 0 );
	
	
	m_panel41->SetSizer( bSizer23 );
	m_panel41->Layout();
	fgSizer57->Add( m_panel41, 0, wxALIGN_RIGHT, 5 );
	
	
	fgSizer57->Add( 10, 0, 0, 0, 5 );
	
	m_panel42 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( 60,-1 ), wxTAB_TRAVERSAL );
	m_panel42->SetMaxSize( wxSize( 60,200 ) );
	
	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxVERTICAL );
	
	
	bSizer24->Add( 0, 1, 0, 0, 5 );
	
	m_right_map_selector = new wxToggleButton( m_panel42, wxID_ANY, wxT("Map 9"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_right_map_selector->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	m_right_map_selector->SetToolTip( wxT("Push to go to right Map") );
	m_right_map_selector->SetMinSize( wxSize( 60,-1 ) );
	
	bSizer24->Add( m_right_map_selector, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	wxFlexGridSizer* fgSizer58;
	fgSizer58 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer58->AddGrowableRow( 0 );
	fgSizer58->AddGrowableRow( 1 );
	fgSizer58->AddGrowableRow( 2 );
	fgSizer58->AddGrowableRow( 3 );
	fgSizer58->SetFlexibleDirection( wxBOTH );
	fgSizer58->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_using_snd_9 = new wxToggleButton( m_panel42, wxID_ANY, wxT("9"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_using_snd_9->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	m_using_snd_9->SetMinSize( wxSize( 30,-1 ) );
	
	fgSizer58->Add( m_using_snd_9, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_using_snd_10 = new wxToggleButton( m_panel42, wxID_ANY, wxT("10"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_using_snd_10->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	m_using_snd_10->SetMinSize( wxSize( 30,-1 ) );
	
	fgSizer58->Add( m_using_snd_10, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_using_snd_11 = new wxToggleButton( m_panel42, wxID_ANY, wxT("11"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_using_snd_11->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	m_using_snd_11->SetMinSize( wxSize( 30,-1 ) );
	
	fgSizer58->Add( m_using_snd_11, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxTOP, 5 );
	
	m_using_snd_12 = new wxToggleButton( m_panel42, wxID_ANY, wxT("12"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_using_snd_12->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	m_using_snd_12->SetMinSize( wxSize( 30,-1 ) );
	
	fgSizer58->Add( m_using_snd_12, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxTOP, 5 );
	
	m_using_snd_13 = new wxToggleButton( m_panel42, wxID_ANY, wxT("13"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_using_snd_13->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	m_using_snd_13->SetMinSize( wxSize( 30,-1 ) );
	
	fgSizer58->Add( m_using_snd_13, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxTOP, 5 );
	
	m_using_snd_14 = new wxToggleButton( m_panel42, wxID_ANY, wxT("14"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_using_snd_14->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	m_using_snd_14->SetMinSize( wxSize( 30,-1 ) );
	
	fgSizer58->Add( m_using_snd_14, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxTOP, 5 );
	
	m_using_snd_15 = new wxToggleButton( m_panel42, wxID_ANY, wxT("15"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_using_snd_15->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	m_using_snd_15->SetMinSize( wxSize( 30,-1 ) );
	
	fgSizer58->Add( m_using_snd_15, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxTOP, 5 );
	
	m_using_snd_16 = new wxToggleButton( m_panel42, wxID_ANY, wxT("16"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_using_snd_16->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	m_using_snd_16->SetMinSize( wxSize( 30,-1 ) );
	
	fgSizer58->Add( m_using_snd_16, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxTOP, 5 );
	
	
	bSizer24->Add( fgSizer58, 1, wxRIGHT|wxLEFT|wxALIGN_CENTER_HORIZONTAL, 0 );
	
	
	m_panel42->SetSizer( bSizer24 );
	m_panel42->Layout();
	fgSizer57->Add( m_panel42, 1, 0, 5 );
	
	
	fgSizer57->Add( 0, 0, 0, 0, 0 );
	
	
	fgSizer59->Add( fgSizer57, 0, wxALIGN_RIGHT, 0 );
	
	
	fgSizer3->Add( fgSizer59, 1, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 0 );
	
	
	bSizer35->Add( fgSizer3, 0, 0, 0 );
	
	
	this->SetSizer( bSizer35 );
	this->Layout();
	
	// Connect Events
	this->Connect( m_menuItem4->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnLoad ) );
	this->Connect( m_menuItem5->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnSave ) );
	this->Connect( m_menuItem6->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnCopy ) );
	m_select_preset1->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnSelectPreset1 ), NULL, this );
	m_select_preset2->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnSelectPreset2 ), NULL, this );
	m_select_preset3->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnSelectPreset3 ), NULL, this );
	m_select_preset4->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnSelectPreset4 ), NULL, this );
	m_select_preset5->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnSelectPreset5 ), NULL, this );
	m_select_preset6->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnSelectPreset6 ), NULL, this );
	m_select_preset7->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnSelectPreset7 ), NULL, this );
	m_select_preset8->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnSelectPreset8 ), NULL, this );
	m_select_preset9->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnSelectPreset9 ), NULL, this );
	m_select_preset10->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnSelectPreset10 ), NULL, this );
	m_select_preset11->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnSelectPreset11 ), NULL, this );
	m_select_preset12->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnSelectPreset12 ), NULL, this );
	m_lfo_freq->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( PresetPanel::OnLFOFreqSliderChange ), NULL, this );
	m_lfo_freq->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( PresetPanel::OnLFOFreqSliderChange ), NULL, this );
	m_lfo_freq->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( PresetPanel::OnLFOFreqSliderChange ), NULL, this );
	m_lfo_freq->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( PresetPanel::OnLFOFreqSliderChange ), NULL, this );
	m_lfo_freq->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( PresetPanel::OnLFOFreqSliderChange ), NULL, this );
	m_lfo_freq->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( PresetPanel::OnLFOFreqSliderChange ), NULL, this );
	m_lfo_freq->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( PresetPanel::OnLFOFreqSliderChange ), NULL, this );
	m_lfo_freq->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( PresetPanel::OnLFOFreqSliderChange ), NULL, this );
	m_lfo_freq->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( PresetPanel::OnLFOFreqSliderChange ), NULL, this );
	m_lfo_init_amount->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( PresetPanel::OnLFOInitAmountSliderChange ), NULL, this );
	m_lfo_init_amount->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( PresetPanel::OnLFOInitAmountSliderChange ), NULL, this );
	m_lfo_init_amount->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( PresetPanel::OnLFOInitAmountSliderChange ), NULL, this );
	m_lfo_init_amount->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( PresetPanel::OnLFOInitAmountSliderChange ), NULL, this );
	m_lfo_init_amount->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( PresetPanel::OnLFOInitAmountSliderChange ), NULL, this );
	m_lfo_init_amount->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( PresetPanel::OnLFOInitAmountSliderChange ), NULL, this );
	m_lfo_init_amount->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( PresetPanel::OnLFOInitAmountSliderChange ), NULL, this );
	m_lfo_init_amount->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( PresetPanel::OnLFOInitAmountSliderChange ), NULL, this );
	m_lfo_init_amount->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( PresetPanel::OnLFOInitAmountSliderChange ), NULL, this );
	m_lfo_vel_sensitivity->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( PresetPanel::OnLFOVelocitySliderChange ), NULL, this );
	m_lfo_vel_sensitivity->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( PresetPanel::OnLFOVelocitySliderChange ), NULL, this );
	m_lfo_vel_sensitivity->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( PresetPanel::OnLFOVelocitySliderChange ), NULL, this );
	m_lfo_vel_sensitivity->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( PresetPanel::OnLFOVelocitySliderChange ), NULL, this );
	m_lfo_vel_sensitivity->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( PresetPanel::OnLFOVelocitySliderChange ), NULL, this );
	m_lfo_vel_sensitivity->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( PresetPanel::OnLFOVelocitySliderChange ), NULL, this );
	m_lfo_vel_sensitivity->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( PresetPanel::OnLFOVelocitySliderChange ), NULL, this );
	m_lfo_vel_sensitivity->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( PresetPanel::OnLFOVelocitySliderChange ), NULL, this );
	m_lfo_vel_sensitivity->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( PresetPanel::OnLFOVelocitySliderChange ), NULL, this );
	m_vibrato->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PresetPanel::OnComboChanged ), NULL, this );
	m_lfo_filt->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PresetPanel::OnComboChanged ), NULL, this );
	m_lfo_amp->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PresetPanel::OnComboChanged ), NULL, this );
	this->Connect( m_menuItem41->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnLoad ) );
	this->Connect( m_menuItem51->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnSave ) );
	this->Connect( m_menuItem61->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnCopy ) );
	m_left_map_selection->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PresetPanel::OnLeftMapSelect ), NULL, this );
	m_keyboard_mode->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PresetPanel::OnComboChanged ), NULL, this );
	m_right_map_selection->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PresetPanel::OnRightMapSelect ), NULL, this );
	m_split_point->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( PresetPanel::OnSplitPoint ), NULL, this );
	m_transpose->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( PresetPanel::OnKeyboardTransposeSliderChange ), NULL, this );
	m_transpose->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( PresetPanel::OnKeyboardTransposeSliderChange ), NULL, this );
	m_transpose->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( PresetPanel::OnKeyboardTransposeSliderChange ), NULL, this );
	m_transpose->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( PresetPanel::OnKeyboardTransposeSliderChange ), NULL, this );
	m_transpose->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( PresetPanel::OnKeyboardTransposeSliderChange ), NULL, this );
	m_transpose->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( PresetPanel::OnKeyboardTransposeSliderChange ), NULL, this );
	m_transpose->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( PresetPanel::OnKeyboardTransposeSliderChange ), NULL, this );
	m_transpose->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( PresetPanel::OnKeyboardTransposeSliderChange ), NULL, this );
	m_transpose->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( PresetPanel::OnKeyboardTransposeSliderChange ), NULL, this );
	m_dyn_alloc->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PresetPanel::OnCheckboxChange ), NULL, this );
	m_vel_switch_threshold->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( PresetPanel::OnKeyboardVelocitySwitchSliderChange ), NULL, this );
	m_vel_switch_threshold->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( PresetPanel::OnKeyboardVelocitySwitchSliderChange ), NULL, this );
	m_vel_switch_threshold->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( PresetPanel::OnKeyboardVelocitySwitchSliderChange ), NULL, this );
	m_vel_switch_threshold->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( PresetPanel::OnKeyboardVelocitySwitchSliderChange ), NULL, this );
	m_vel_switch_threshold->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( PresetPanel::OnKeyboardVelocitySwitchSliderChange ), NULL, this );
	m_vel_switch_threshold->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( PresetPanel::OnKeyboardVelocitySwitchSliderChange ), NULL, this );
	m_vel_switch_threshold->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( PresetPanel::OnKeyboardVelocitySwitchSliderChange ), NULL, this );
	m_vel_switch_threshold->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( PresetPanel::OnKeyboardVelocitySwitchSliderChange ), NULL, this );
	m_vel_switch_threshold->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( PresetPanel::OnKeyboardVelocitySwitchSliderChange ), NULL, this );
	m_pitchwheel_range->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( PresetPanel::OnPitchwheelSliderChange ), NULL, this );
	m_pitchwheel_range->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( PresetPanel::OnPitchwheelSliderChange ), NULL, this );
	m_pitchwheel_range->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( PresetPanel::OnPitchwheelSliderChange ), NULL, this );
	m_pitchwheel_range->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( PresetPanel::OnPitchwheelSliderChange ), NULL, this );
	m_pitchwheel_range->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( PresetPanel::OnPitchwheelSliderChange ), NULL, this );
	m_pitchwheel_range->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( PresetPanel::OnPitchwheelSliderChange ), NULL, this );
	m_pitchwheel_range->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( PresetPanel::OnPitchwheelSliderChange ), NULL, this );
	m_pitchwheel_range->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( PresetPanel::OnPitchwheelSliderChange ), NULL, this );
	m_pitchwheel_range->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( PresetPanel::OnPitchwheelSliderChange ), NULL, this );
	this->Connect( m_menuItem42->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnLoad ) );
	this->Connect( m_menuItem52->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnSave ) );
	this->Connect( m_menuItem62->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnCopy ) );
	m_stack_voices->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PresetPanel::OnComboChanged ), NULL, this );
	m_stack_voices_preset_on->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PresetPanel::OnCheckboxChange ), NULL, this );
	m_stack_delay->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( PresetPanel::OnStackDelaySliderChange ), NULL, this );
	m_stack_delay->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( PresetPanel::OnStackDelaySliderChange ), NULL, this );
	m_stack_delay->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( PresetPanel::OnStackDelaySliderChange ), NULL, this );
	m_stack_delay->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( PresetPanel::OnStackDelaySliderChange ), NULL, this );
	m_stack_delay->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( PresetPanel::OnStackDelaySliderChange ), NULL, this );
	m_stack_delay->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( PresetPanel::OnStackDelaySliderChange ), NULL, this );
	m_stack_delay->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( PresetPanel::OnStackDelaySliderChange ), NULL, this );
	m_stack_delay->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( PresetPanel::OnStackDelaySliderChange ), NULL, this );
	m_stack_delay->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( PresetPanel::OnStackDelaySliderChange ), NULL, this );
	m_stack_detune->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( PresetPanel::OnStackDetuneSliderChange ), NULL, this );
	m_stack_detune->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( PresetPanel::OnStackDetuneSliderChange ), NULL, this );
	m_stack_detune->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( PresetPanel::OnStackDetuneSliderChange ), NULL, this );
	m_stack_detune->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( PresetPanel::OnStackDetuneSliderChange ), NULL, this );
	m_stack_detune->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( PresetPanel::OnStackDetuneSliderChange ), NULL, this );
	m_stack_detune->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( PresetPanel::OnStackDetuneSliderChange ), NULL, this );
	m_stack_detune->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( PresetPanel::OnStackDetuneSliderChange ), NULL, this );
	m_stack_detune->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( PresetPanel::OnStackDetuneSliderChange ), NULL, this );
	m_stack_detune->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( PresetPanel::OnStackDetuneSliderChange ), NULL, this );
	this->Connect( m_menuItem43->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnLoad ) );
	this->Connect( m_menuItem53->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnSave ) );
	this->Connect( m_menuItem63->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnCopy ) );
	m_arp_mode->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PresetPanel::OnComboChanged ), NULL, this );
	m_arp_oct->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PresetPanel::OnComboChanged ), NULL, this );
	m_arp_repeats->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PresetPanel::OnComboChanged ), NULL, this );
	m_arp_latch_mode->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PresetPanel::OnComboChanged ), NULL, this );
	m_arp_split_point->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( PresetPanel::OnArpSplitPoint ), NULL, this );
	m_arp_split_type->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PresetPanel::OnComboChanged ), NULL, this );
	m_arp_rate->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( PresetPanel::OnArpRateSliderChange ), NULL, this );
	m_arp_rate->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( PresetPanel::OnArpRateSliderChange ), NULL, this );
	m_arp_rate->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( PresetPanel::OnArpRateSliderChange ), NULL, this );
	m_arp_rate->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( PresetPanel::OnArpRateSliderChange ), NULL, this );
	m_arp_rate->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( PresetPanel::OnArpRateSliderChange ), NULL, this );
	m_arp_rate->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( PresetPanel::OnArpRateSliderChange ), NULL, this );
	m_arp_rate->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( PresetPanel::OnArpRateSliderChange ), NULL, this );
	m_arp_rate->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( PresetPanel::OnArpRateSliderChange ), NULL, this );
	m_arp_rate->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( PresetPanel::OnArpRateSliderChange ), NULL, this );
	m_arp_preset_on->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PresetPanel::OnCheckboxChange ), NULL, this );
	this->Connect( m_menuItem44->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnLoad ) );
	this->Connect( m_menuItem54->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnSave ) );
	this->Connect( m_menuItem64->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnCopy ) );
	m_midi_left_ch->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PresetPanel::OnComboChanged ), NULL, this );
	m_rx_mod_wheel->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PresetPanel::OnCheckboxChange ), NULL, this );
	m_tx_mod_wheel->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PresetPanel::OnCheckboxChange ), NULL, this );
	m_midi_right_ch->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PresetPanel::OnComboChanged ), NULL, this );
	m_rx_pitch_wheel->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PresetPanel::OnCheckboxChange ), NULL, this );
	m_tx_pitch_wheel->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PresetPanel::OnCheckboxChange ), NULL, this );
	m_midi_mode->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PresetPanel::OnComboChanged ), NULL, this );
	m_rx_program_chg->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PresetPanel::OnCheckboxChange ), NULL, this );
	m_tx_program_chg->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PresetPanel::OnCheckboxChange ), NULL, this );
	m_rx_pressure_as_mod_wheel->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PresetPanel::OnCheckboxChange ), NULL, this );
	m_tx_mod_wheel_as_pressure->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PresetPanel::OnCheckboxChange ), NULL, this );
	this->Connect( m_menuItem45->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnLoad ) );
	this->Connect( m_menuItem55->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnSave ) );
	this->Connect( m_menuItem65->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnCopy ) );
	m_left_map_selector->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnLeftMapSelector ), NULL, this );
	m_using_snd_1->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound1 ), NULL, this );
	m_using_snd_2->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound2 ), NULL, this );
	m_using_snd_3->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound3 ), NULL, this );
	m_using_snd_4->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound4 ), NULL, this );
	m_using_snd_5->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound5 ), NULL, this );
	m_using_snd_6->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound6 ), NULL, this );
	m_using_snd_7->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound7 ), NULL, this );
	m_using_snd_8->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound8 ), NULL, this );
	m_right_map_selector->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnRightMapSelector ), NULL, this );
	m_using_snd_9->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound9 ), NULL, this );
	m_using_snd_10->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound10 ), NULL, this );
	m_using_snd_11->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound11 ), NULL, this );
	m_using_snd_12->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound12 ), NULL, this );
	m_using_snd_13->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound13 ), NULL, this );
	m_using_snd_14->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound14 ), NULL, this );
	m_using_snd_15->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound15 ), NULL, this );
	m_using_snd_16->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound16 ), NULL, this );
}

PresetPanel::~PresetPanel()
{
	// Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnCopy ) );
	m_select_preset1->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnSelectPreset1 ), NULL, this );
	m_select_preset2->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnSelectPreset2 ), NULL, this );
	m_select_preset3->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnSelectPreset3 ), NULL, this );
	m_select_preset4->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnSelectPreset4 ), NULL, this );
	m_select_preset5->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnSelectPreset5 ), NULL, this );
	m_select_preset6->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnSelectPreset6 ), NULL, this );
	m_select_preset7->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnSelectPreset7 ), NULL, this );
	m_select_preset8->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnSelectPreset8 ), NULL, this );
	m_select_preset9->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnSelectPreset9 ), NULL, this );
	m_select_preset10->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnSelectPreset10 ), NULL, this );
	m_select_preset11->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnSelectPreset11 ), NULL, this );
	m_select_preset12->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnSelectPreset12 ), NULL, this );
	m_lfo_freq->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( PresetPanel::OnLFOFreqSliderChange ), NULL, this );
	m_lfo_freq->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( PresetPanel::OnLFOFreqSliderChange ), NULL, this );
	m_lfo_freq->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( PresetPanel::OnLFOFreqSliderChange ), NULL, this );
	m_lfo_freq->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( PresetPanel::OnLFOFreqSliderChange ), NULL, this );
	m_lfo_freq->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( PresetPanel::OnLFOFreqSliderChange ), NULL, this );
	m_lfo_freq->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( PresetPanel::OnLFOFreqSliderChange ), NULL, this );
	m_lfo_freq->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( PresetPanel::OnLFOFreqSliderChange ), NULL, this );
	m_lfo_freq->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( PresetPanel::OnLFOFreqSliderChange ), NULL, this );
	m_lfo_freq->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( PresetPanel::OnLFOFreqSliderChange ), NULL, this );
	m_lfo_init_amount->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( PresetPanel::OnLFOInitAmountSliderChange ), NULL, this );
	m_lfo_init_amount->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( PresetPanel::OnLFOInitAmountSliderChange ), NULL, this );
	m_lfo_init_amount->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( PresetPanel::OnLFOInitAmountSliderChange ), NULL, this );
	m_lfo_init_amount->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( PresetPanel::OnLFOInitAmountSliderChange ), NULL, this );
	m_lfo_init_amount->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( PresetPanel::OnLFOInitAmountSliderChange ), NULL, this );
	m_lfo_init_amount->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( PresetPanel::OnLFOInitAmountSliderChange ), NULL, this );
	m_lfo_init_amount->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( PresetPanel::OnLFOInitAmountSliderChange ), NULL, this );
	m_lfo_init_amount->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( PresetPanel::OnLFOInitAmountSliderChange ), NULL, this );
	m_lfo_init_amount->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( PresetPanel::OnLFOInitAmountSliderChange ), NULL, this );
	m_lfo_vel_sensitivity->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( PresetPanel::OnLFOVelocitySliderChange ), NULL, this );
	m_lfo_vel_sensitivity->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( PresetPanel::OnLFOVelocitySliderChange ), NULL, this );
	m_lfo_vel_sensitivity->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( PresetPanel::OnLFOVelocitySliderChange ), NULL, this );
	m_lfo_vel_sensitivity->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( PresetPanel::OnLFOVelocitySliderChange ), NULL, this );
	m_lfo_vel_sensitivity->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( PresetPanel::OnLFOVelocitySliderChange ), NULL, this );
	m_lfo_vel_sensitivity->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( PresetPanel::OnLFOVelocitySliderChange ), NULL, this );
	m_lfo_vel_sensitivity->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( PresetPanel::OnLFOVelocitySliderChange ), NULL, this );
	m_lfo_vel_sensitivity->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( PresetPanel::OnLFOVelocitySliderChange ), NULL, this );
	m_lfo_vel_sensitivity->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( PresetPanel::OnLFOVelocitySliderChange ), NULL, this );
	m_vibrato->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PresetPanel::OnComboChanged ), NULL, this );
	m_lfo_filt->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PresetPanel::OnComboChanged ), NULL, this );
	m_lfo_amp->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PresetPanel::OnComboChanged ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnCopy ) );
	m_left_map_selection->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PresetPanel::OnLeftMapSelect ), NULL, this );
	m_keyboard_mode->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PresetPanel::OnComboChanged ), NULL, this );
	m_right_map_selection->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PresetPanel::OnRightMapSelect ), NULL, this );
	m_split_point->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( PresetPanel::OnSplitPoint ), NULL, this );
	m_transpose->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( PresetPanel::OnKeyboardTransposeSliderChange ), NULL, this );
	m_transpose->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( PresetPanel::OnKeyboardTransposeSliderChange ), NULL, this );
	m_transpose->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( PresetPanel::OnKeyboardTransposeSliderChange ), NULL, this );
	m_transpose->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( PresetPanel::OnKeyboardTransposeSliderChange ), NULL, this );
	m_transpose->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( PresetPanel::OnKeyboardTransposeSliderChange ), NULL, this );
	m_transpose->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( PresetPanel::OnKeyboardTransposeSliderChange ), NULL, this );
	m_transpose->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( PresetPanel::OnKeyboardTransposeSliderChange ), NULL, this );
	m_transpose->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( PresetPanel::OnKeyboardTransposeSliderChange ), NULL, this );
	m_transpose->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( PresetPanel::OnKeyboardTransposeSliderChange ), NULL, this );
	m_dyn_alloc->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PresetPanel::OnCheckboxChange ), NULL, this );
	m_vel_switch_threshold->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( PresetPanel::OnKeyboardVelocitySwitchSliderChange ), NULL, this );
	m_vel_switch_threshold->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( PresetPanel::OnKeyboardVelocitySwitchSliderChange ), NULL, this );
	m_vel_switch_threshold->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( PresetPanel::OnKeyboardVelocitySwitchSliderChange ), NULL, this );
	m_vel_switch_threshold->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( PresetPanel::OnKeyboardVelocitySwitchSliderChange ), NULL, this );
	m_vel_switch_threshold->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( PresetPanel::OnKeyboardVelocitySwitchSliderChange ), NULL, this );
	m_vel_switch_threshold->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( PresetPanel::OnKeyboardVelocitySwitchSliderChange ), NULL, this );
	m_vel_switch_threshold->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( PresetPanel::OnKeyboardVelocitySwitchSliderChange ), NULL, this );
	m_vel_switch_threshold->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( PresetPanel::OnKeyboardVelocitySwitchSliderChange ), NULL, this );
	m_vel_switch_threshold->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( PresetPanel::OnKeyboardVelocitySwitchSliderChange ), NULL, this );
	m_pitchwheel_range->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( PresetPanel::OnPitchwheelSliderChange ), NULL, this );
	m_pitchwheel_range->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( PresetPanel::OnPitchwheelSliderChange ), NULL, this );
	m_pitchwheel_range->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( PresetPanel::OnPitchwheelSliderChange ), NULL, this );
	m_pitchwheel_range->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( PresetPanel::OnPitchwheelSliderChange ), NULL, this );
	m_pitchwheel_range->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( PresetPanel::OnPitchwheelSliderChange ), NULL, this );
	m_pitchwheel_range->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( PresetPanel::OnPitchwheelSliderChange ), NULL, this );
	m_pitchwheel_range->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( PresetPanel::OnPitchwheelSliderChange ), NULL, this );
	m_pitchwheel_range->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( PresetPanel::OnPitchwheelSliderChange ), NULL, this );
	m_pitchwheel_range->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( PresetPanel::OnPitchwheelSliderChange ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnCopy ) );
	m_stack_voices->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PresetPanel::OnComboChanged ), NULL, this );
	m_stack_voices_preset_on->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PresetPanel::OnCheckboxChange ), NULL, this );
	m_stack_delay->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( PresetPanel::OnStackDelaySliderChange ), NULL, this );
	m_stack_delay->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( PresetPanel::OnStackDelaySliderChange ), NULL, this );
	m_stack_delay->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( PresetPanel::OnStackDelaySliderChange ), NULL, this );
	m_stack_delay->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( PresetPanel::OnStackDelaySliderChange ), NULL, this );
	m_stack_delay->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( PresetPanel::OnStackDelaySliderChange ), NULL, this );
	m_stack_delay->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( PresetPanel::OnStackDelaySliderChange ), NULL, this );
	m_stack_delay->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( PresetPanel::OnStackDelaySliderChange ), NULL, this );
	m_stack_delay->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( PresetPanel::OnStackDelaySliderChange ), NULL, this );
	m_stack_delay->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( PresetPanel::OnStackDelaySliderChange ), NULL, this );
	m_stack_detune->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( PresetPanel::OnStackDetuneSliderChange ), NULL, this );
	m_stack_detune->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( PresetPanel::OnStackDetuneSliderChange ), NULL, this );
	m_stack_detune->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( PresetPanel::OnStackDetuneSliderChange ), NULL, this );
	m_stack_detune->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( PresetPanel::OnStackDetuneSliderChange ), NULL, this );
	m_stack_detune->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( PresetPanel::OnStackDetuneSliderChange ), NULL, this );
	m_stack_detune->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( PresetPanel::OnStackDetuneSliderChange ), NULL, this );
	m_stack_detune->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( PresetPanel::OnStackDetuneSliderChange ), NULL, this );
	m_stack_detune->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( PresetPanel::OnStackDetuneSliderChange ), NULL, this );
	m_stack_detune->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( PresetPanel::OnStackDetuneSliderChange ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnCopy ) );
	m_arp_mode->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PresetPanel::OnComboChanged ), NULL, this );
	m_arp_oct->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PresetPanel::OnComboChanged ), NULL, this );
	m_arp_repeats->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PresetPanel::OnComboChanged ), NULL, this );
	m_arp_latch_mode->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PresetPanel::OnComboChanged ), NULL, this );
	m_arp_split_point->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( PresetPanel::OnArpSplitPoint ), NULL, this );
	m_arp_split_type->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PresetPanel::OnComboChanged ), NULL, this );
	m_arp_rate->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( PresetPanel::OnArpRateSliderChange ), NULL, this );
	m_arp_rate->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( PresetPanel::OnArpRateSliderChange ), NULL, this );
	m_arp_rate->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( PresetPanel::OnArpRateSliderChange ), NULL, this );
	m_arp_rate->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( PresetPanel::OnArpRateSliderChange ), NULL, this );
	m_arp_rate->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( PresetPanel::OnArpRateSliderChange ), NULL, this );
	m_arp_rate->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( PresetPanel::OnArpRateSliderChange ), NULL, this );
	m_arp_rate->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( PresetPanel::OnArpRateSliderChange ), NULL, this );
	m_arp_rate->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( PresetPanel::OnArpRateSliderChange ), NULL, this );
	m_arp_rate->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( PresetPanel::OnArpRateSliderChange ), NULL, this );
	m_arp_preset_on->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PresetPanel::OnCheckboxChange ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnCopy ) );
	m_midi_left_ch->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PresetPanel::OnComboChanged ), NULL, this );
	m_rx_mod_wheel->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PresetPanel::OnCheckboxChange ), NULL, this );
	m_tx_mod_wheel->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PresetPanel::OnCheckboxChange ), NULL, this );
	m_midi_right_ch->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PresetPanel::OnComboChanged ), NULL, this );
	m_rx_pitch_wheel->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PresetPanel::OnCheckboxChange ), NULL, this );
	m_tx_pitch_wheel->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PresetPanel::OnCheckboxChange ), NULL, this );
	m_midi_mode->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( PresetPanel::OnComboChanged ), NULL, this );
	m_rx_program_chg->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PresetPanel::OnCheckboxChange ), NULL, this );
	m_tx_program_chg->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PresetPanel::OnCheckboxChange ), NULL, this );
	m_rx_pressure_as_mod_wheel->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PresetPanel::OnCheckboxChange ), NULL, this );
	m_tx_mod_wheel_as_pressure->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( PresetPanel::OnCheckboxChange ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnLoad ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnSave ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PresetPanel::OnCopy ) );
	m_left_map_selector->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnLeftMapSelector ), NULL, this );
	m_using_snd_1->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound1 ), NULL, this );
	m_using_snd_2->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound2 ), NULL, this );
	m_using_snd_3->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound3 ), NULL, this );
	m_using_snd_4->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound4 ), NULL, this );
	m_using_snd_5->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound5 ), NULL, this );
	m_using_snd_6->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound6 ), NULL, this );
	m_using_snd_7->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound7 ), NULL, this );
	m_using_snd_8->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound8 ), NULL, this );
	m_right_map_selector->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnRightMapSelector ), NULL, this );
	m_using_snd_9->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound9 ), NULL, this );
	m_using_snd_10->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound10 ), NULL, this );
	m_using_snd_11->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound11 ), NULL, this );
	m_using_snd_12->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound12 ), NULL, this );
	m_using_snd_13->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound13 ), NULL, this );
	m_using_snd_14->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound14 ), NULL, this );
	m_using_snd_15->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound15 ), NULL, this );
	m_using_snd_16->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetPanel::OnUsingSound16 ), NULL, this );
	
	delete m_menu2; 
	delete m_menu21; 
	delete m_menu22; 
	delete m_menu23; 
	delete m_menu24; 
	delete m_menu25; 
}

MapScaledValuesDialog::MapScaledValuesDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxFlexGridSizer* fgSizer24;
	fgSizer24 = new wxFlexGridSizer( 2, 2, 0, 0 );
	fgSizer24->SetFlexibleDirection( wxBOTH );
	fgSizer24->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_NONE );
	
	m_panel64111 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer26111;
	fgSizer26111 = new wxFlexGridSizer( 2, 5, 0, 0 );
	fgSizer26111->SetFlexibleDirection( wxBOTH );
	fgSizer26111->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText235111 = new wxStaticText( m_panel64111, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText235111->Wrap( -1 );
	fgSizer26111->Add( m_staticText235111, 0, wxALL, 5 );
	
	m_staticText234111 = new wxStaticText( m_panel64111, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText234111->Wrap( -1 );
	fgSizer26111->Add( m_staticText234111, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	m_staticText238111 = new wxStaticText( m_panel64111, wxID_ANY, wxT("Velocity"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText238111->Wrap( -1 );
	m_staticText238111->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer26111->Add( m_staticText238111, 0, wxTOP|wxBOTTOM|wxALIGN_RIGHT, 5 );
	
	m_staticText239111 = new wxStaticText( m_panel64111, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText239111->Wrap( -1 );
	fgSizer26111->Add( m_staticText239111, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_staticText230 = new wxStaticText( m_panel64111, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText230->Wrap( -1 );
	fgSizer26111->Add( m_staticText230, 0, wxALL, 5 );
	
	m_staticText247111 = new wxStaticText( m_panel64111, wxID_ANY, wxT("Attack "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText247111->Wrap( -1 );
	fgSizer26111->Add( m_staticText247111, 0, wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText248111 = new wxStaticText( m_panel64111, wxID_ANY, wxT("Release"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText248111->Wrap( -1 );
	fgSizer26111->Add( m_staticText248111, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText246111 = new wxStaticText( m_panel64111, wxID_ANY, wxT("VCA Peak"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText246111->Wrap( -1 );
	fgSizer26111->Add( m_staticText246111, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText249111 = new wxStaticText( m_panel64111, wxID_ANY, wxT("VCF Peak"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText249111->Wrap( -1 );
	fgSizer26111->Add( m_staticText249111, 0, wxBOTTOM|wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText229 = new wxStaticText( m_panel64111, wxID_ANY, wxT("S. Start"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText229->Wrap( -1 );
	m_staticText229->SetToolTip( wxT("Sample Start Point") );
	
	fgSizer26111->Add( m_staticText229, 0, wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_attack_vel_sensitivity = new wxTextCtrl( m_panel64111, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_attack_vel_sensitivity->SetMaxLength( 4 ); 
	m_attack_vel_sensitivity->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer26111->Add( m_attack_vel_sensitivity, 0, wxALIGN_RIGHT|wxRIGHT|wxLEFT, 5 );
	
	m_release_vel_sensitivity = new wxTextCtrl( m_panel64111, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_release_vel_sensitivity->SetMaxLength( 4 ); 
	m_release_vel_sensitivity->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer26111->Add( m_release_vel_sensitivity, 0, wxALIGN_RIGHT|wxRIGHT|wxLEFT, 5 );
	
	m_amp_peak_vel_sensitivity = new wxTextCtrl( m_panel64111, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_amp_peak_vel_sensitivity->SetMaxLength( 4 ); 
	m_amp_peak_vel_sensitivity->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer26111->Add( m_amp_peak_vel_sensitivity, 0, wxALIGN_RIGHT|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_filt_peak_vel_sensitivity = new wxTextCtrl( m_panel64111, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_filt_peak_vel_sensitivity->SetMaxLength( 4 ); 
	m_filt_peak_vel_sensitivity->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer26111->Add( m_filt_peak_vel_sensitivity, 0, wxALIGN_RIGHT|wxRIGHT|wxLEFT, 5 );
	
	m_velocity_start_point = new wxTextCtrl( m_panel64111, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_velocity_start_point->SetMaxLength( 4 ); 
	m_velocity_start_point->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer26111->Add( m_velocity_start_point, 0, wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
	m_panel64111->SetSizer( fgSizer26111 );
	m_panel64111->Layout();
	fgSizer26111->Fit( m_panel64111 );
	fgSizer24->Add( m_panel64111, 0, wxALL|wxEXPAND, 5 );
	
	m_panel6411 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer2611;
	fgSizer2611 = new wxFlexGridSizer( 0, 4, 0, 0 );
	fgSizer2611->SetFlexibleDirection( wxBOTH );
	fgSizer2611->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText23511 = new wxStaticText( m_panel6411, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23511->Wrap( -1 );
	fgSizer2611->Add( m_staticText23511, 0, wxALL, 5 );
	
	m_staticText23811 = new wxStaticText( m_panel6411, wxID_ANY, wxT("Fil"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23811->Wrap( -1 );
	m_staticText23811->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer2611->Add( m_staticText23811, 0, wxALIGN_RIGHT|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_staticText23911 = new wxStaticText( m_panel6411, wxID_ANY, wxT("ter"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23911->Wrap( -1 );
	m_staticText23911->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer2611->Add( m_staticText23911, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_staticText23411 = new wxStaticText( m_panel6411, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23411->Wrap( -1 );
	fgSizer2611->Add( m_staticText23411, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	m_staticText24611 = new wxStaticText( m_panel6411, wxID_ANY, wxT("Cutoff "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24611->Wrap( -1 );
	fgSizer2611->Add( m_staticText24611, 0, wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText24711 = new wxStaticText( m_panel6411, wxID_ANY, wxT("Reson."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24711->Wrap( -1 );
	fgSizer2611->Add( m_staticText24711, 0, wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText24811 = new wxStaticText( m_panel6411, wxID_ANY, wxT("Env. Amt"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24811->Wrap( -1 );
	fgSizer2611->Add( m_staticText24811, 0, wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText24911 = new wxStaticText( m_panel6411, wxID_ANY, wxT("KB Track"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24911->Wrap( -1 );
	fgSizer2611->Add( m_staticText24911, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM|wxLEFT, 5 );
	
	m_filt_cutoff = new wxTextCtrl( m_panel6411, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_filt_cutoff->SetMaxLength( 4 ); 
	m_filt_cutoff->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer2611->Add( m_filt_cutoff, 0, wxALIGN_RIGHT|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_filt_resonance = new wxTextCtrl( m_panel6411, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_filt_resonance->SetMaxLength( 4 ); 
	m_filt_resonance->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer2611->Add( m_filt_resonance, 0, wxRIGHT|wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_filt_env_amount = new wxTextCtrl( m_panel6411, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_filt_env_amount->SetMaxLength( 4 ); 
	m_filt_env_amount->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer2611->Add( m_filt_env_amount, 0, wxALIGN_RIGHT|wxRIGHT|wxLEFT, 5 );
	
	m_filt_keyboard_tracking = new wxTextCtrl( m_panel6411, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_filt_keyboard_tracking->SetMaxLength( 4 ); 
	m_filt_keyboard_tracking->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer2611->Add( m_filt_keyboard_tracking, 0, wxRIGHT|wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	m_panel6411->SetSizer( fgSizer2611 );
	m_panel6411->Layout();
	fgSizer2611->Fit( m_panel6411 );
	fgSizer24->Add( m_panel6411, 0, wxALL|wxEXPAND, 5 );
	
	m_vca_env_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_vca_env_panel->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( m_vca_env_panel, wxID_ANY, wxT("VCA Envelope Graph") ), wxVERTICAL );
	
	m_vca_env_disp = new EnvDisp(m_vca_env_panel, wxID_ANY, wxDefaultPosition, wxSize(245, 150));
	sbSizer1->Add( m_vca_env_disp, 1, wxEXPAND, 0 );
	
	
	m_vca_env_panel->SetSizer( sbSizer1 );
	m_vca_env_panel->Layout();
	sbSizer1->Fit( m_vca_env_panel );
	fgSizer24->Add( m_vca_env_panel, 1, wxALL|wxEXPAND, 5 );
	
	m_vcf_env_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_vcf_env_panel->SetFont( wxFont( 8, 70, 90, 92, false, wxEmptyString ) );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( m_vcf_env_panel, wxID_ANY, wxT("VCF Envelope Graph") ), wxVERTICAL );
	
	m_vcf_env_disp = new EnvDisp(m_vcf_env_panel, wxID_ANY, wxDefaultPosition, wxSize(245, 150));
	m_vcf_env_disp->SetToolTip( wxT("Click to switch between VCF Envelope Settings and VCF Cutoff Modulation by the Envelope Settings") );
	
	sbSizer2->Add( m_vcf_env_disp, 1, wxEXPAND|wxALIGN_RIGHT, 0 );
	
	
	m_vcf_env_panel->SetSizer( sbSizer2 );
	m_vcf_env_panel->Layout();
	sbSizer2->Fit( m_vcf_env_panel );
	fgSizer24->Add( m_vcf_env_panel, 1, wxEXPAND | wxALL, 5 );
	
	m_panel59 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer26;
	fgSizer26 = new wxFlexGridSizer( 0, 5, 0, 0 );
	fgSizer26->SetFlexibleDirection( wxBOTH );
	fgSizer26->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText235 = new wxStaticText( m_panel59, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText235->Wrap( -1 );
	fgSizer26->Add( m_staticText235, 0, wxALL, 5 );
	
	m_staticText234 = new wxStaticText( m_panel59, wxID_ANY, wxT("VCA"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText234->Wrap( -1 );
	m_staticText234->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer26->Add( m_staticText234, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	m_staticText238 = new wxStaticText( m_panel59, wxID_ANY, wxT("Envelope"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText238->Wrap( -1 );
	m_staticText238->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer26->Add( m_staticText238, 0, wxTOP|wxBOTTOM, 5 );
	
	m_staticText239 = new wxStaticText( m_panel59, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText239->Wrap( -1 );
	fgSizer26->Add( m_staticText239, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_staticText240 = new wxStaticText( m_panel59, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText240->Wrap( -1 );
	fgSizer26->Add( m_staticText240, 0, wxALL, 5 );
	
	m_staticText246 = new wxStaticText( m_panel59, wxID_ANY, wxT("Attack"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText246->Wrap( -1 );
	fgSizer26->Add( m_staticText246, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText247 = new wxStaticText( m_panel59, wxID_ANY, wxT("Decay"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText247->Wrap( -1 );
	fgSizer26->Add( m_staticText247, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText248 = new wxStaticText( m_panel59, wxID_ANY, wxT("Sustain"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText248->Wrap( -1 );
	fgSizer26->Add( m_staticText248, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText249 = new wxStaticText( m_panel59, wxID_ANY, wxT("Release"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText249->Wrap( -1 );
	fgSizer26->Add( m_staticText249, 0, wxBOTTOM|wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText250 = new wxStaticText( m_panel59, wxID_ANY, wxT("  2nd Rel."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText250->Wrap( -1 );
	fgSizer26->Add( m_staticText250, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM, 5 );
	
	m_amp_attack_rate = new wxTextCtrl( m_panel59, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_amp_attack_rate->SetMaxLength( 4 ); 
	m_amp_attack_rate->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer26->Add( m_amp_attack_rate, 0, wxALIGN_RIGHT|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_amp_decay_rate = new wxTextCtrl( m_panel59, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_amp_decay_rate->SetMaxLength( 4 ); 
	m_amp_decay_rate->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer26->Add( m_amp_decay_rate, 0, wxALIGN_RIGHT|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_amp_sustain_level = new wxTextCtrl( m_panel59, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_amp_sustain_level->SetMaxLength( 4 ); 
	m_amp_sustain_level->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer26->Add( m_amp_sustain_level, 0, wxRIGHT|wxLEFT, 5 );
	
	m_amp_release_rate = new wxTextCtrl( m_panel59, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_amp_release_rate->SetMaxLength( 4 ); 
	m_amp_release_rate->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer26->Add( m_amp_release_rate, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );
	
	m_amp_2nd_release_rate = new wxTextCtrl( m_panel59, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_amp_2nd_release_rate->SetMaxLength( 4 ); 
	m_amp_2nd_release_rate->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer26->Add( m_amp_2nd_release_rate, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );
	
	
	m_panel59->SetSizer( fgSizer26 );
	m_panel59->Layout();
	fgSizer26->Fit( m_panel59 );
	fgSizer24->Add( m_panel59, 0, wxALL|wxEXPAND|wxALIGN_BOTTOM, 5 );
	
	m_panel641 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer261;
	fgSizer261 = new wxFlexGridSizer( 0, 5, 0, 0 );
	fgSizer261->SetFlexibleDirection( wxBOTH );
	fgSizer261->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText2351 = new wxStaticText( m_panel641, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2351->Wrap( -1 );
	fgSizer261->Add( m_staticText2351, 0, wxALL, 5 );
	
	m_staticText2341 = new wxStaticText( m_panel641, wxID_ANY, wxT("VCF"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2341->Wrap( -1 );
	m_staticText2341->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer261->Add( m_staticText2341, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	m_staticText2381 = new wxStaticText( m_panel641, wxID_ANY, wxT("Envelope"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2381->Wrap( -1 );
	m_staticText2381->SetFont( wxFont( 8, 74, 90, 92, false, wxT("Tahoma") ) );
	
	fgSizer261->Add( m_staticText2381, 0, wxTOP|wxBOTTOM, 5 );
	
	m_staticText2391 = new wxStaticText( m_panel641, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2391->Wrap( -1 );
	fgSizer261->Add( m_staticText2391, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_staticText2401 = new wxStaticText( m_panel641, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2401->Wrap( -1 );
	fgSizer261->Add( m_staticText2401, 0, wxALL, 5 );
	
	m_staticText2461 = new wxStaticText( m_panel641, wxID_ANY, wxT("Attack"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2461->Wrap( -1 );
	fgSizer261->Add( m_staticText2461, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText2471 = new wxStaticText( m_panel641, wxID_ANY, wxT("Decay"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2471->Wrap( -1 );
	fgSizer261->Add( m_staticText2471, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText2481 = new wxStaticText( m_panel641, wxID_ANY, wxT("Sustain"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2481->Wrap( -1 );
	fgSizer261->Add( m_staticText2481, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText2491 = new wxStaticText( m_panel641, wxID_ANY, wxT("Release"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2491->Wrap( -1 );
	fgSizer261->Add( m_staticText2491, 0, wxBOTTOM|wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText2501 = new wxStaticText( m_panel641, wxID_ANY, wxT("  2nd Rel."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2501->Wrap( -1 );
	fgSizer261->Add( m_staticText2501, 0, wxALIGN_CENTER_HORIZONTAL|wxBOTTOM, 5 );
	
	m_filt_attack_rate = new wxTextCtrl( m_panel641, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_filt_attack_rate->SetMaxLength( 4 ); 
	m_filt_attack_rate->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer261->Add( m_filt_attack_rate, 0, wxALIGN_RIGHT|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_filt_decay_rate = new wxTextCtrl( m_panel641, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_filt_decay_rate->SetMaxLength( 4 ); 
	m_filt_decay_rate->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer261->Add( m_filt_decay_rate, 0, wxALIGN_RIGHT|wxRIGHT|wxLEFT, 5 );
	
	m_filt_sustain_level = new wxTextCtrl( m_panel641, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_filt_sustain_level->SetMaxLength( 4 ); 
	m_filt_sustain_level->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer261->Add( m_filt_sustain_level, 0, wxRIGHT|wxLEFT, 5 );
	
	m_filt_release_rate = new wxTextCtrl( m_panel641, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_filt_release_rate->SetMaxLength( 4 ); 
	m_filt_release_rate->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer261->Add( m_filt_release_rate, 0, wxALIGN_CENTER_HORIZONTAL|wxRIGHT|wxLEFT, 5 );
	
	m_filt_2nd_release_rate = new wxTextCtrl( m_panel641, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 40,-1 ), wxTE_CAPITALIZE|wxTE_CENTRE|wxTE_READONLY );
	m_filt_2nd_release_rate->SetMaxLength( 4 ); 
	m_filt_2nd_release_rate->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	fgSizer261->Add( m_filt_2nd_release_rate, 0, wxRIGHT|wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	m_panel641->SetSizer( fgSizer261 );
	m_panel641->Layout();
	fgSizer261->Fit( m_panel641 );
	fgSizer24->Add( m_panel641, 0, wxALL|wxEXPAND|wxALIGN_BOTTOM, 5 );
	
	
	this->SetSizer( fgSizer24 );
	this->Layout();
	fgSizer24->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_vcf_env_disp->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( MapScaledValuesDialog::OnLeftDown ), NULL, this );
}

MapScaledValuesDialog::~MapScaledValuesDialog()
{
	// Disconnect Events
	m_vcf_env_disp->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( MapScaledValuesDialog::OnLeftDown ), NULL, this );
	
}

ConfigDlg::ConfigDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxFlexGridSizer* fgSizer37;
	fgSizer37 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer37->SetFlexibleDirection( wxBOTH );
	fgSizer37->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_NONE );
	
	wxFlexGridSizer* fgSizer61;
	fgSizer61 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer61->SetFlexibleDirection( wxBOTH );
	fgSizer61->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText278 = new wxStaticText( this, wxID_ANY, wxT("Font Size"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText278->Wrap( -1 );
	m_staticText278->SetToolTip( wxT("Compensate GUI issues caused by custom DPI settings") );
	m_staticText278->SetMinSize( wxSize( 100,-1 ) );
	
	fgSizer61->Add( m_staticText278, 0, wxALL, 5 );
	
	m_fontsize = new wxOwnerDrawnComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 220,-1 ), 0, NULL, 0 ); 
	fgSizer61->Add( m_fontsize, 1, wxALL|wxEXPAND, 5 );
	
	
	fgSizer37->Add( fgSizer61, 1, wxEXPAND, 5 );
	
	m_staticline9 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	fgSizer37->Add( m_staticline9, 0, wxEXPAND | wxALL, 5 );
	
	wxFlexGridSizer* fgSizer1591;
	fgSizer1591 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer1591->SetFlexibleDirection( wxBOTH );
	fgSizer1591->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText12701 = new wxStaticText( this, wxID_ANY, wxT("Audio Device"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12701->Wrap( -1 );
	m_staticText12701->SetMinSize( wxSize( 100,-1 ) );
	
	fgSizer1591->Add( m_staticText12701, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_audio_device = new wxOwnerDrawnComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 220,-1 ), 0, NULL, 0 ); 
	fgSizer1591->Add( m_audio_device, 1, wxEXPAND | wxALL, 5 );
	
	
	fgSizer37->Add( fgSizer1591, 1, wxEXPAND, 5 );
	
	m_staticline251 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	m_staticline251->SetMinSize( wxSize( 400,-1 ) );
	m_staticline251->SetMaxSize( wxSize( 400,-1 ) );
	
	fgSizer37->Add( m_staticline251, 0, wxEXPAND | wxALL, 5 );
	
	wxFlexGridSizer* fgSizer159;
	fgSizer159 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer159->SetFlexibleDirection( wxBOTH );
	fgSizer159->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText1270 = new wxStaticText( this, wxID_ANY, wxT("MIDI Input Device"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1270->Wrap( -1 );
	m_staticText1270->SetMinSize( wxSize( 100,-1 ) );
	
	fgSizer159->Add( m_staticText1270, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_midi_in_device = new wxOwnerDrawnComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 220,-1 ), 0, NULL, 0 ); 
	fgSizer159->Add( m_midi_in_device, 0, wxALL, 5 );
	
	m_staticText1271 = new wxStaticText( this, wxID_ANY, wxT("MIDI Output Device"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1271->Wrap( -1 );
	m_staticText1271->SetMinSize( wxSize( 100,-1 ) );
	
	fgSizer159->Add( m_staticText1271, 0, wxALL, 5 );
	
	m_midi_out_device = new wxOwnerDrawnComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 220,-1 ), 0, NULL, 0 ); 
	fgSizer159->Add( m_midi_out_device, 0, wxALL, 5 );
	
	m_staticText1272 = new wxStaticText( this, wxID_ANY, wxT("MIDI Channel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1272->Wrap( -1 );
	m_staticText1272->SetMinSize( wxSize( 100,-1 ) );
	
	fgSizer159->Add( m_staticText1272, 0, wxALL, 5 );
	
	m_midi_ch = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 1, 16, 1 );
	m_midi_ch->SetMinSize( wxSize( 50,-1 ) );
	m_midi_ch->SetMaxSize( wxSize( 50,-1 ) );
	
	fgSizer159->Add( m_midi_ch, 0, wxALL, 5 );
	
	
	fgSizer37->Add( fgSizer159, 1, wxEXPAND, 5 );
	

	
	
	fgSizer37->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( fgSizer37 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_fontsize->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( ConfigDlg::OnFontSize ), NULL, this );
	m_audio_device->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( ConfigDlg::OnAudioDevice ), NULL, this );
	m_midi_in_device->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( ConfigDlg::OnInDevice ), NULL, this );
	m_midi_out_device->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( ConfigDlg::OnOutDevice ), NULL, this );
	m_midi_ch->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ConfigDlg::OnChannel ), NULL, this );
}

ConfigDlg::~ConfigDlg()
{
	// Disconnect Events
	m_fontsize->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( ConfigDlg::OnFontSize ), NULL, this );
	m_audio_device->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( ConfigDlg::OnAudioDevice ), NULL, this );
	m_midi_in_device->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( ConfigDlg::OnInDevice ), NULL, this );
	m_midi_out_device->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( ConfigDlg::OnOutDevice ), NULL, this );
	m_midi_ch->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( ConfigDlg::OnChannel ), NULL, this );
	
}

SoundSelectionPanel::SoundSelectionPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	this->SetMinSize( wxSize( 980,-1 ) );
	this->SetMaxSize( wxSize( 980,-1 ) );
	
	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxHORIZONTAL );
	
	m_select_sound1 = new wxToggleButton( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_sound1->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_sound1->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_sound1->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer32->Add( m_select_sound1, 0, wxALL, 5 );
	
	m_select_sound2 = new wxToggleButton( this, wxID_ANY, wxT("2"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_sound2->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_sound2->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_sound2->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer32->Add( m_select_sound2, 0, wxALL, 5 );
	
	m_select_sound3 = new wxToggleButton( this, wxID_ANY, wxT("3"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_sound3->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_sound3->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_sound3->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer32->Add( m_select_sound3, 0, wxALL, 5 );
	
	m_select_sound4 = new wxToggleButton( this, wxID_ANY, wxT("4"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_sound4->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_sound4->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_sound4->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer32->Add( m_select_sound4, 0, wxALL, 5 );
	
	m_select_sound5 = new wxToggleButton( this, wxID_ANY, wxT("5"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_sound5->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_sound5->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_sound5->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer32->Add( m_select_sound5, 0, wxALL, 5 );
	
	m_select_sound6 = new wxToggleButton( this, wxID_ANY, wxT("6"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_sound6->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_sound6->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_sound6->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer32->Add( m_select_sound6, 0, wxALL, 5 );
	
	m_select_sound7 = new wxToggleButton( this, wxID_ANY, wxT("7"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_sound7->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_sound7->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_sound7->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer32->Add( m_select_sound7, 0, wxALL, 5 );
	
	m_select_sound8 = new wxToggleButton( this, wxID_ANY, wxT("8"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_sound8->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_sound8->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_sound8->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer32->Add( m_select_sound8, 0, wxALL, 5 );
	
	m_staticline18 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_VERTICAL );
	bSizer32->Add( m_staticline18, 0, wxEXPAND | wxALL, 9 );
	
	m_select_sound9 = new wxToggleButton( this, wxID_ANY, wxT("9"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_sound9->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_sound9->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_sound9->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer32->Add( m_select_sound9, 0, wxALL, 5 );
	
	m_select_sound10 = new wxToggleButton( this, wxID_ANY, wxT("10"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_sound10->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_sound10->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_sound10->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer32->Add( m_select_sound10, 0, wxALL, 5 );
	
	m_select_sound11 = new wxToggleButton( this, wxID_ANY, wxT("11"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_sound11->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_sound11->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_sound11->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer32->Add( m_select_sound11, 0, wxALL, 5 );
	
	m_select_sound12 = new wxToggleButton( this, wxID_ANY, wxT("12"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_sound12->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_sound12->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_sound12->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer32->Add( m_select_sound12, 0, wxALL, 5 );
	
	m_select_sound13 = new wxToggleButton( this, wxID_ANY, wxT("13"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_sound13->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_sound13->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_sound13->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer32->Add( m_select_sound13, 0, wxALL, 5 );
	
	m_select_sound14 = new wxToggleButton( this, wxID_ANY, wxT("14"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_sound14->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_sound14->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_sound14->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer32->Add( m_select_sound14, 0, wxALL, 5 );
	
	m_select_sound15 = new wxToggleButton( this, wxID_ANY, wxT("15"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_sound15->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_sound15->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_sound15->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer32->Add( m_select_sound15, 0, wxALL, 5 );
	
	m_select_sound16 = new wxToggleButton( this, wxID_ANY, wxT("16"), wxDefaultPosition, wxSize( 50,-1 ), wxDOUBLE_BORDER );
	m_select_sound16->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_sound16->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_sound16->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer32->Add( m_select_sound16, 0, wxALL, 5 );
	
	
	this->SetSizer( bSizer32 );
	this->Layout();
	
	// Connect Events
	m_select_sound1->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound1 ), NULL, this );
	m_select_sound2->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound2 ), NULL, this );
	m_select_sound3->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound3 ), NULL, this );
	m_select_sound4->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound4 ), NULL, this );
	m_select_sound5->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound5 ), NULL, this );
	m_select_sound6->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound6 ), NULL, this );
	m_select_sound7->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound7 ), NULL, this );
	m_select_sound8->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound8 ), NULL, this );
	m_select_sound9->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound9 ), NULL, this );
	m_select_sound10->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound10 ), NULL, this );
	m_select_sound11->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound11 ), NULL, this );
	m_select_sound12->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound12 ), NULL, this );
	m_select_sound13->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound13 ), NULL, this );
	m_select_sound14->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound14 ), NULL, this );
	m_select_sound15->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound15 ), NULL, this );
	m_select_sound16->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound16 ), NULL, this );
}

SoundSelectionPanel::~SoundSelectionPanel()
{
	// Disconnect Events
	m_select_sound1->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound1 ), NULL, this );
	m_select_sound2->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound2 ), NULL, this );
	m_select_sound3->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound3 ), NULL, this );
	m_select_sound4->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound4 ), NULL, this );
	m_select_sound5->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound5 ), NULL, this );
	m_select_sound6->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound6 ), NULL, this );
	m_select_sound7->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound7 ), NULL, this );
	m_select_sound8->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound8 ), NULL, this );
	m_select_sound9->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound9 ), NULL, this );
	m_select_sound10->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound10 ), NULL, this );
	m_select_sound11->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound11 ), NULL, this );
	m_select_sound12->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound12 ), NULL, this );
	m_select_sound13->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound13 ), NULL, this );
	m_select_sound14->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound14 ), NULL, this );
	m_select_sound15->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound15 ), NULL, this );
	m_select_sound16->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundSelectionPanel::OnSelectSound16 ), NULL, this );
	
}

MIDIKeyboardPresetSelection::MIDIKeyboardPresetSelection( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style ) : wxPanel( parent, id, pos, size, style )
{
	this->SetMinSize( wxSize( 995,-1 ) );
	this->SetMaxSize( wxSize( 995,-1 ) );
	
	wxBoxSizer* bSizer321;
	bSizer321 = new wxBoxSizer( wxHORIZONTAL );
	
	m_select_preset1 = new wxToggleButton( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_select_preset1->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_preset1->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_preset1->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer321->Add( m_select_preset1, 1, wxALL, 5 );
	
	m_select_preset2 = new wxToggleButton( this, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_select_preset2->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_preset2->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_preset2->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer321->Add( m_select_preset2, 1, wxALL, 5 );
	
	m_select_preset3 = new wxToggleButton( this, wxID_ANY, wxT("3"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_select_preset3->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_preset3->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_preset3->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer321->Add( m_select_preset3, 1, wxALL, 5 );
	
	m_select_preset4 = new wxToggleButton( this, wxID_ANY, wxT("4"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_select_preset4->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_preset4->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_preset4->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer321->Add( m_select_preset4, 1, wxALL, 5 );
	
	m_select_preset5 = new wxToggleButton( this, wxID_ANY, wxT("5"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_select_preset5->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_preset5->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_preset5->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer321->Add( m_select_preset5, 1, wxALL, 5 );
	
	m_select_preset6 = new wxToggleButton( this, wxID_ANY, wxT("6"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_select_preset6->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_preset6->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_preset6->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer321->Add( m_select_preset6, 1, wxALL, 5 );
	
	m_select_preset7 = new wxToggleButton( this, wxID_ANY, wxT("7"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_select_preset7->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_preset7->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_preset7->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer321->Add( m_select_preset7, 1, wxALL, 5 );
	
	m_select_preset8 = new wxToggleButton( this, wxID_ANY, wxT("8"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_select_preset8->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_preset8->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_preset8->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer321->Add( m_select_preset8, 1, wxALL, 5 );
	
	m_select_preset9 = new wxToggleButton( this, wxID_ANY, wxT("9"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_select_preset9->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_preset9->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_preset9->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer321->Add( m_select_preset9, 1, wxALL, 5 );
	
	m_select_preset10 = new wxToggleButton( this, wxID_ANY, wxT("10"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_select_preset10->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_preset10->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_preset10->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer321->Add( m_select_preset10, 1, wxALL, 5 );
	
	m_select_preset11 = new wxToggleButton( this, wxID_ANY, wxT("11"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_select_preset11->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_preset11->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_preset11->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer321->Add( m_select_preset11, 1, wxALL, 5 );
	
	m_select_preset12 = new wxToggleButton( this, wxID_ANY, wxT("12"), wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER );
	m_select_preset12->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), 74, 94, 92, false, wxEmptyString ) );
	m_select_preset12->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_select_preset12->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	bSizer321->Add( m_select_preset12, 1, wxALL, 5 );
	
	
	this->SetSizer( bSizer321 );
	this->Layout();
	
	// Connect Events
	m_select_preset1->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MIDIKeyboardPresetSelection::OnSelectPreset1 ), NULL, this );
	m_select_preset2->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MIDIKeyboardPresetSelection::OnSelectPreset2 ), NULL, this );
	m_select_preset3->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MIDIKeyboardPresetSelection::OnSelectPreset3 ), NULL, this );
	m_select_preset4->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MIDIKeyboardPresetSelection::OnSelectPreset4 ), NULL, this );
	m_select_preset5->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MIDIKeyboardPresetSelection::OnSelectPreset5 ), NULL, this );
	m_select_preset6->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MIDIKeyboardPresetSelection::OnSelectPreset6 ), NULL, this );
	m_select_preset7->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MIDIKeyboardPresetSelection::OnSelectPreset7 ), NULL, this );
	m_select_preset8->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MIDIKeyboardPresetSelection::OnSelectPreset8 ), NULL, this );
	m_select_preset9->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MIDIKeyboardPresetSelection::OnSelectPreset9 ), NULL, this );
	m_select_preset10->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MIDIKeyboardPresetSelection::OnSelectPreset10 ), NULL, this );
	m_select_preset11->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MIDIKeyboardPresetSelection::OnSelectPreset11 ), NULL, this );
	m_select_preset12->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MIDIKeyboardPresetSelection::OnSelectPreset12 ), NULL, this );
}

MIDIKeyboardPresetSelection::~MIDIKeyboardPresetSelection()
{
	// Disconnect Events
	m_select_preset1->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MIDIKeyboardPresetSelection::OnSelectPreset1 ), NULL, this );
	m_select_preset2->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MIDIKeyboardPresetSelection::OnSelectPreset2 ), NULL, this );
	m_select_preset3->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MIDIKeyboardPresetSelection::OnSelectPreset3 ), NULL, this );
	m_select_preset4->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MIDIKeyboardPresetSelection::OnSelectPreset4 ), NULL, this );
	m_select_preset5->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MIDIKeyboardPresetSelection::OnSelectPreset5 ), NULL, this );
	m_select_preset6->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MIDIKeyboardPresetSelection::OnSelectPreset6 ), NULL, this );
	m_select_preset7->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MIDIKeyboardPresetSelection::OnSelectPreset7 ), NULL, this );
	m_select_preset8->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MIDIKeyboardPresetSelection::OnSelectPreset8 ), NULL, this );
	m_select_preset9->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MIDIKeyboardPresetSelection::OnSelectPreset9 ), NULL, this );
	m_select_preset10->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MIDIKeyboardPresetSelection::OnSelectPreset10 ), NULL, this );
	m_select_preset11->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MIDIKeyboardPresetSelection::OnSelectPreset11 ), NULL, this );
	m_select_preset12->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MIDIKeyboardPresetSelection::OnSelectPreset12 ), NULL, this );
	
}

AboutDlg::AboutDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText265 = new wxStaticText( this, wxID_ANY, wxT("Prophet 2012"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText265->Wrap( -1 );
	m_staticText265->SetFont( wxFont( 12, 70, 90, 92, false, wxEmptyString ) );
	
	bSizer16->Add( m_staticText265, 0, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxFlexGridSizer* fgSizer50;
	fgSizer50 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer50->SetFlexibleDirection( wxBOTH );
	fgSizer50->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText272 = new wxStaticText( this, wxID_ANY, wxT("Version"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText272->Wrap( -1 );
	fgSizer50->Add( m_staticText272, 0, wxALL, 5 );
	
	m_version_label = new wxStaticText( this, wxID_ANY, wxT("VERSION_STR"), wxDefaultPosition, wxDefaultSize, 0 );
	m_version_label->Wrap( -1 );
	fgSizer50->Add( m_version_label, 0, wxALL, 5 );
	
	m_staticText276 = new wxStaticText( this, wxID_ANY, wxT("Build"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText276->Wrap( -1 );
	fgSizer50->Add( m_staticText276, 0, wxALL, 5 );
	
	m_build_date_label = new wxStaticText( this, wxID_ANY, wxT("__DATE__"), wxDefaultPosition, wxDefaultSize, 0 );
	m_build_date_label->Wrap( -1 );
	fgSizer50->Add( m_build_date_label, 0, wxALL, 5 );
	
	m_staticText273 = new wxStaticText( this, wxID_ANY, wxT("Author"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText273->Wrap( -1 );
	fgSizer50->Add( m_staticText273, 0, wxALL, 5 );
	
	m_staticText267 = new wxStaticText( this, wxID_ANY, wxT("Marius Goebel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText267->Wrap( -1 );
	fgSizer50->Add( m_staticText267, 0, wxALL, 5 );
	
	m_staticText274 = new wxStaticText( this, wxID_ANY, wxT("Support"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText274->Wrap( -1 );
	fgSizer50->Add( m_staticText274, 0, wxALL, 5 );
	
	m_staticText268 = new wxStaticText( this, wxID_ANY, wxT("Bertil Munde"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText268->Wrap( -1 );
	fgSizer50->Add( m_staticText268, 0, wxALL, 5 );
	
	m_staticText275 = new wxStaticText( this, wxID_ANY, wxT("Web"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText275->Wrap( -1 );
	fgSizer50->Add( m_staticText275, 0, wxALL, 5 );
	
	m_hyperlink1 = new wxHyperlinkCtrl( this, wxID_ANY, wxT("http://prophet2012.curlsystems.de"), wxT("http://prophet2012.curlsystems.de"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	fgSizer50->Add( m_hyperlink1, 0, wxALL, 5 );
	
	m_staticText286 = new wxStaticText( this, wxID_ANY, wxT("Disclaimer"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText286->Wrap( -1 );
	fgSizer50->Add( m_staticText286, 0, wxALL, 5 );
	
	m_textCtrl125 = new wxTextCtrl( this, wxID_ANY, wxT("This program is free software. Use it at your own risk. This program is without any warranty. You may copy and distribute the software unmodified as it is."), wxDefaultPosition, wxSize( 250,-1 ), wxTE_MULTILINE|wxTE_READONLY|wxVSCROLL );
	m_textCtrl125->SetMaxLength( 0 ); 
	fgSizer50->Add( m_textCtrl125, 0, wxALL, 5 );
	
	
	bSizer16->Add( fgSizer50, 0, 0, 5 );
	
	
	bSizer16->Add( 0, 10, 0, 0, 5 );
	
	m_copyright_text = new wxStaticText( this, wxID_ANY, wxT("Copyright text will bet set by code"), wxDefaultPosition, wxDefaultSize, 0 );
	m_copyright_text->Wrap( -1 );
	bSizer16->Add( m_copyright_text, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizer16->Add( 0, 10, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	this->SetSizer( bSizer16 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

AboutDlg::~AboutDlg()
{
}

SoundCopyDlg::SoundCopyDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxFlexGridSizer* fgSizer52;
	fgSizer52 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer52->SetFlexibleDirection( wxBOTH );
	fgSizer52->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_NONE );
	
	m_staticText279 = new wxStaticText( this, wxID_ANY, wxT("Destination:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText279->Wrap( -1 );
	fgSizer52->Add( m_staticText279, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_destination_number = new wxSpinCtrl( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 16, 1 );
	fgSizer52->Add( m_destination_number, 0, wxALL|wxEXPAND, 5 );
	
	m_copy_parameters_only = new wxCheckBox( this, wxID_ANY, wxT("Copy Parameters only"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_copy_parameters_only, 0, wxALL, 5 );
	
	m_staticText280 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText280->Wrap( -1 );
	fgSizer52->Add( m_staticText280, 0, wxALL, 5 );
	
	m_toggleBtn58 = new wxToggleButton( this, wxID_ANY, wxT("Copy"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_toggleBtn58, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_toggleBtn59 = new wxToggleButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_toggleBtn59, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	this->SetSizer( fgSizer52 );
	this->Layout();
	fgSizer52->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_toggleBtn58->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundCopyDlg::OnOK ), NULL, this );
	m_toggleBtn59->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundCopyDlg::OnCancel ), NULL, this );
}

SoundCopyDlg::~SoundCopyDlg()
{
	// Disconnect Events
	m_toggleBtn58->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundCopyDlg::OnOK ), NULL, this );
	m_toggleBtn59->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( SoundCopyDlg::OnCancel ), NULL, this );
	
}

MapCopyDlg::MapCopyDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxFlexGridSizer* fgSizer52;
	fgSizer52 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer52->SetFlexibleDirection( wxBOTH );
	fgSizer52->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_NONE );
	
	m_staticText279 = new wxStaticText( this, wxID_ANY, wxT("Destination:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText279->Wrap( -1 );
	fgSizer52->Add( m_staticText279, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_destination_number = new wxOwnerDrawnComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 70,-1 ), 0, NULL, 0 ); 
	m_destination_number->SetMinSize( wxSize( 70,-1 ) );
	m_destination_number->SetMaxSize( wxSize( 70,-1 ) );
	
	fgSizer52->Add( m_destination_number, 0, wxALL, 5 );
	
	m_copy_snd_mapping = new wxCheckBox( this, wxID_ANY, wxT("Copy Sound Mappings"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_copy_snd_mapping, 0, wxALL, 5 );
	
	m_staticText280 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText280->Wrap( -1 );
	fgSizer52->Add( m_staticText280, 0, wxALL, 5 );
	
	m_toggleBtn58 = new wxToggleButton( this, wxID_ANY, wxT("Copy"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_toggleBtn58, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_toggleBtn59 = new wxToggleButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_toggleBtn59, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	this->SetSizer( fgSizer52 );
	this->Layout();
	fgSizer52->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_destination_number->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MapCopyDlg::OnDestinationChange ), NULL, this );
	m_toggleBtn58->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapCopyDlg::OnOK ), NULL, this );
	m_toggleBtn59->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapCopyDlg::OnCancel ), NULL, this );
}

MapCopyDlg::~MapCopyDlg()
{
	// Disconnect Events
	m_destination_number->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MapCopyDlg::OnDestinationChange ), NULL, this );
	m_toggleBtn58->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapCopyDlg::OnOK ), NULL, this );
	m_toggleBtn59->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MapCopyDlg::OnCancel ), NULL, this );
	
}

PresetCopyDlg::PresetCopyDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxFlexGridSizer* fgSizer52;
	fgSizer52 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer52->SetFlexibleDirection( wxBOTH );
	fgSizer52->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_NONE );
	
	m_staticText279 = new wxStaticText( this, wxID_ANY, wxT("Destination:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText279->Wrap( -1 );
	fgSizer52->Add( m_staticText279, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_destination_number = new wxSpinCtrl( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxSize( 50,-1 ), wxSP_ARROW_KEYS, 1, 12, 1 );
	fgSizer52->Add( m_destination_number, 0, wxALL|wxEXPAND, 5 );
	
	m_toggleBtn58 = new wxToggleButton( this, wxID_ANY, wxT("Copy"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_toggleBtn58, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_toggleBtn59 = new wxToggleButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer52->Add( m_toggleBtn59, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	this->SetSizer( fgSizer52 );
	this->Layout();
	fgSizer52->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_toggleBtn58->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetCopyDlg::OnOK ), NULL, this );
	m_toggleBtn59->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetCopyDlg::OnCancel ), NULL, this );
}

PresetCopyDlg::~PresetCopyDlg()
{
	// Disconnect Events
	m_toggleBtn58->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetCopyDlg::OnOK ), NULL, this );
	m_toggleBtn59->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( PresetCopyDlg::OnCancel ), NULL, this );
	
}

LoadSampleDialog::LoadSampleDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxFlexGridSizer* fgSizer65;
	fgSizer65 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer65->SetFlexibleDirection( wxBOTH );
	fgSizer65->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_NONE );
	
	m_wavedisp_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( 570,185 ), wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );
	
	m_wave_disp = new WaveDisp(m_wavedisp_panel, wxID_ANY, wxDefaultPosition, wxSize(570, 185));
	m_wave_disp->SetMinSize( wxSize( -1,185 ) );
	
	bSizer11->Add( m_wave_disp, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	
	m_wavedisp_panel->SetSizer( bSizer11 );
	m_wavedisp_panel->Layout();
	fgSizer65->Add( m_wavedisp_panel, 1, wxEXPAND | wxALL, 5 );
	
	wxFlexGridSizer* fgSizer66;
	fgSizer66 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer66->SetFlexibleDirection( wxBOTH );
	fgSizer66->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_panel47 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer68;
	fgSizer68 = new wxFlexGridSizer( 1, 2, 0, 0 );
	fgSizer68->SetFlexibleDirection( wxBOTH );
	fgSizer68->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxString m_dest_sample_rateChoices[] = { wxT("15.625kHz"), wxT("31.250kHz"), wxT("41.667kHz") };
	int m_dest_sample_rateNChoices = sizeof( m_dest_sample_rateChoices ) / sizeof( wxString );
	m_dest_sample_rate = new wxRadioBox( m_panel47, wxID_ANY, wxT("Sample rate"), wxDefaultPosition, wxDefaultSize, m_dest_sample_rateNChoices, m_dest_sample_rateChoices, 1, wxRA_SPECIFY_COLS );
	m_dest_sample_rate->SetSelection( 0 );
	fgSizer68->Add( m_dest_sample_rate, 0, wxALL, 5 );
	
	wxFlexGridSizer* fgSizer62;
	fgSizer62 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer62->SetFlexibleDirection( wxBOTH );
	fgSizer62->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText279 = new wxStaticText( m_panel47, wxID_ANY, wxT("Input sample rate:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText279->Wrap( -1 );
	fgSizer62->Add( m_staticText279, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_sample_rate_orig_txt = new wxTextCtrl( m_panel47, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_sample_rate_orig_txt->SetMaxLength( 0 ); 
	fgSizer62->Add( m_sample_rate_orig_txt, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText280 = new wxStaticText( m_panel47, wxID_ANY, wxT("Sample words:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText280->Wrap( -1 );
	fgSizer62->Add( m_staticText280, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_sample_words_txt = new wxTextCtrl( m_panel47, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_sample_words_txt->SetMaxLength( 0 ); 
	fgSizer62->Add( m_sample_words_txt, 0, wxALL, 5 );
	
	m_staticText283 = new wxStaticText( m_panel47, wxID_ANY, wxT("Start point:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText283->Wrap( -1 );
	fgSizer62->Add( m_staticText283, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_start_point = new wxSpinCtrl( m_panel47, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 0, 0 );
	fgSizer62->Add( m_start_point, 0, wxEXPAND|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	m_staticText284 = new wxStaticText( m_panel47, wxID_ANY, wxT("End point:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText284->Wrap( -1 );
	fgSizer62->Add( m_staticText284, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_end_point = new wxSpinCtrl( m_panel47, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 0, 0 );
	fgSizer62->Add( m_end_point, 0, wxEXPAND|wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	fgSizer68->Add( fgSizer62, 1, wxEXPAND, 5 );
	
	wxString m_src_channelChoices[] = { wxT("both (merge)"), wxT("left"), wxT("right") };
	int m_src_channelNChoices = sizeof( m_src_channelChoices ) / sizeof( wxString );
	m_src_channel = new wxRadioBox( m_panel47, wxID_ANY, wxT("Channel"), wxDefaultPosition, wxDefaultSize, m_src_channelNChoices, m_src_channelChoices, 1, wxRA_SPECIFY_COLS );
	m_src_channel->SetSelection( 2 );
	fgSizer68->Add( m_src_channel, 0, wxALL, 5 );
	
	wxFlexGridSizer* fgSizer64;
	fgSizer64 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer64->AddGrowableCol( 0 );
	fgSizer64->SetFlexibleDirection( wxBOTH );
	fgSizer64->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText2831 = new wxStaticText( m_panel47, wxID_ANY, wxT("Sound:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2831->Wrap( -1 );
	fgSizer64->Add( m_staticText2831, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_selected_sound = new wxOwnerDrawnComboBox( m_panel47, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 120,-1 ), 0, NULL, 0 ); 
	fgSizer64->Add( m_selected_sound, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	m_staticText2841 = new wxStaticText( m_panel47, wxID_ANY, wxT("Root key:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2841->Wrap( -1 );
	fgSizer64->Add( m_staticText2841, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_rootkey_txt = new wxTextCtrl( m_panel47, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_rootkey_txt->SetMaxLength( 0 ); 
	fgSizer64->Add( m_rootkey_txt, 0, wxALL, 5 );
	
	
	fgSizer68->Add( fgSizer64, 1, wxEXPAND, 5 );
	
	
	m_panel47->SetSizer( fgSizer68 );
	m_panel47->Layout();
	fgSizer68->Fit( m_panel47 );
	fgSizer66->Add( m_panel47, 0, wxEXPAND | wxALL, 5 );
	
	m_panel46 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer67;
	fgSizer67 = new wxFlexGridSizer( 0, 0, 0, 0 );
	fgSizer67->SetFlexibleDirection( wxBOTH );
	fgSizer67->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	load_but = new wxButton( m_panel46, wxID_ANY, wxT("Load"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer67->Add( load_but, 0, wxALL, 5 );
	
	play_but = new wxButton( m_panel46, wxID_ANY, wxT("Play"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer67->Add( play_but, 0, wxALL, 5 );
	
	import_but = new wxButton( m_panel46, wxID_ANY, wxT("Import"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer67->Add( import_but, 0, wxALL, 5 );
	
	cancel_but = new wxButton( m_panel46, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer67->Add( cancel_but, 0, wxALL, 5 );
	
	
	m_panel46->SetSizer( fgSizer67 );
	m_panel46->Layout();
	fgSizer67->Fit( m_panel46 );
	fgSizer66->Add( m_panel46, 0, wxEXPAND | wxALL, 5 );
	
	
	fgSizer65->Add( fgSizer66, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( fgSizer65 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_dest_sample_rate->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( LoadSampleDialog::OnDestSampleRate ), NULL, this );
	m_start_point->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( LoadSampleDialog::OnStartPoint ), NULL, this );
	m_end_point->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( LoadSampleDialog::OnEndPoint ), NULL, this );
	m_src_channel->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( LoadSampleDialog::OnChannelSelect ), NULL, this );
	m_selected_sound->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( LoadSampleDialog::OnSoundChange ), NULL, this );
	load_but->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadSampleDialog::OnLoad ), NULL, this );
	play_but->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadSampleDialog::OnPlay ), NULL, this );
	import_but->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadSampleDialog::OnImport ), NULL, this );
	cancel_but->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadSampleDialog::OnCancel ), NULL, this );
}

LoadSampleDialog::~LoadSampleDialog()
{
	// Disconnect Events
	m_dest_sample_rate->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( LoadSampleDialog::OnDestSampleRate ), NULL, this );
	m_start_point->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( LoadSampleDialog::OnStartPoint ), NULL, this );
	m_end_point->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( LoadSampleDialog::OnEndPoint ), NULL, this );
	m_src_channel->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( LoadSampleDialog::OnChannelSelect ), NULL, this );
	m_selected_sound->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( LoadSampleDialog::OnSoundChange ), NULL, this );
	load_but->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadSampleDialog::OnLoad ), NULL, this );
	play_but->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadSampleDialog::OnPlay ), NULL, this );
	import_but->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadSampleDialog::OnImport ), NULL, this );
	cancel_but->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoadSampleDialog::OnCancel ), NULL, this );
	
}
