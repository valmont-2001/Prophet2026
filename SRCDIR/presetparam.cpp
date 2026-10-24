#include "types.h"


#include <wx/wx.h>
#include <wx/string.h>
#include <wx/file.h>
#include <wx/spinctrl.h>

#include "presetparam.h"
#include "main.h"
#include "stopwatch.h"
#include "proph2000.h"
#include <map>
#include <list>
using namespace std;
#include "clickarea.h"
#include "keyboard.h"
#include "presetkeyboard.h"
#include "GUILayout.h"
#include "presetcopydlg.h"
#include "presetpanel.h"

// 2do: MIDI Overflow mode!!! (->midi_mode) & m_midi_opts

//#define __DEACTIVATE_PARAM


typedef enum
{
   GUI_ELEMENT_CHANGED = 3000,
   GUI_LEFT_MAP_SELECT,
   GUI_RIGHT_MAP_SELECT,
   GUI_SLIDER_CHANGED,
   GUI_COMBO_CHANGED,
   GUI_CHECKBOX_CHANGED,
   GUI_KEYBOARD_EDIT_SELECTION,
   GUI_LOAD_PRESET,
   GUI_SAVE_PRESET,
   GUI_COPY,
   GUI_SPLIT_POINT,
   GUI_ARP_SPLIT_POINT
};


BEGIN_EVENT_TABLE(MyPresetParam, wxPanel)
   EVT_RIGHT_DOWN(MyPresetParam::OnMouseRightDown)
   EVT_MENU(GUI_LOAD_PRESET, MyPresetParam::OnLoad)
   EVT_MENU(GUI_SAVE_PRESET, MyPresetParam::OnSave)
   EVT_MENU(GUI_COPY, MyPresetParam::OnCopy)
END_EVENT_TABLE()


MyPresetParam::MyPresetParam(wxWindow *parent, MyPanel *topframe, Proph2000 *proph, uint8_t preset_u8) :
   wxPanel(parent, wxID_ANY),
   m_topframe(topframe), m_proph(proph), m_preset_u8(preset_u8)
{

   wxBoxSizer *vsizer = new wxBoxSizer( wxVERTICAL );


   m_panel = new PresetPanelImpl(this, topframe, proph, preset_u8, this);
   vsizer->Add(m_panel);

   //vsizer->AddSpacer(20); 
   vsizer->AddSpacer(7);
   wxBoxSizer *hsizer = new wxBoxSizer( wxHORIZONTAL );
   hsizer->AddSpacer(6);
   wxStaticText *txt = new wxStaticText(this, wxID_ANY, wxT("Edit:"));
   hsizer->Add(txt);
   hsizer->AddSpacer(20); //Horizontal offset of ComboBox
   m_edit_selection = new wxComboBox(this, GUI_KEYBOARD_EDIT_SELECTION);
   hsizer->Add(m_edit_selection);

   vsizer->Add(hsizer);
   vsizer->AddSpacer(10); //Vertical offset to Keyboard

   m_edit_selection->Append(wxT("Map Split Point"));
   m_edit_selection->Append(wxT("Arp Split Point"));
   m_edit_selection->SetSelection(0);

   m_preset_keyboard = new PresetKeyboard(this, wxID_ANY, wxDefaultPosition, wxSize(970, 100), this, m_proph, NULL, preset_u8);
   hsizer = new wxBoxSizer( wxHORIZONTAL );
   hsizer->SetMinSize( wxSize( -1,140) ); 
   hsizer->AddSpacer(5);
   hsizer->Add(m_preset_keyboard,wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_BOTTOM);
 //  vsizer->Fit( this );
   vsizer->Add(hsizer);

   SetSizer(vsizer);

   updateGUI();
}


MyPresetParam::~MyPresetParam()
{
   delete m_preset_keyboard;
   delete m_panel;
}

void MyPresetParam::activatePreset(uint8_t preset_u8)
{
   m_preset_u8 = preset_u8;
   m_panel->activatePreset(preset_u8);
   m_preset_keyboard->setPreset(preset_u8);
   updateGUI();
}

void MyPresetParam::updateGUI(void)
{
   m_panel->displaySettings();
   m_panel->updateGUI();

   m_preset_keyboard->Refresh(true);
}


void MyPresetParam::handleKeyboardNoteEvent(uint8_t note)
{
   switch(m_edit_selection->GetSelection())
   {
      case 0:
         m_proph->m_preset_param_as[m_preset_u8].val_s.split_point = note;
         break;
      case 1:
         m_proph->m_preset_param_as[m_preset_u8].val_s.arp_split_point = note;
         break;
   }

   m_proph->updateParamBytesFromStruct();
   m_topframe->updateGUI();
   if(m_topframe->getOnlineUpdateActive())
   {
      if(m_proph->transferPreset2Proph(m_preset_u8))
      {
         m_topframe->transferStarted();
      }
   }
}

void MyPresetParam::OnLoad(wxCommandEvent& event)
{
   wxString wildcards =
                 wxString::Format
                 (
                     wxT("Preset files (*.p2p)|*.p2p"),
                     wxFileSelectorDefaultWildcardStr,
                     wxFileSelectorDefaultWildcardStr
                 );

   wxFileDialog indialog(this, wxT("Load preset file"),
                     wxEmptyString, wxEmptyString, wildcards,
                     wxFD_OPEN);

   if (indialog.ShowModal() == wxID_OK)
   {
      FILE *mf;
      mf = fopen(indialog.GetPath().mb_str(), "rb");

      if(mf)
      {
         fread(&m_proph->m_presetparam_au8[m_preset_u8], 1, PRESET_PARAM_BYTES * 2, mf);
         fclose(mf);
         m_proph->updateStructsFromParamBytes();
         m_proph->remapMemory();
         m_topframe->updateGUI();
         if(m_topframe->getOnlineUpdateActive())
         {
            if(m_proph->transferPreset2Proph(m_preset_u8))
            {
               m_topframe->transferStarted();
            }
         }
      }
      else
      {
         wxMessageDialog edialog(this, wxT("Could not load Preset File"), wxT("Error"));
         edialog.ShowModal();
      }
   }
}

void MyPresetParam::OnSave(wxCommandEvent& event)
{
   wxFileDialog outdialog(this,
                  wxT("Save Preset File"),
                  wxEmptyString,
                  wxEmptyString,
                  wxT("Preset Files (*.p2p)|*.p2p"),
                  wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
   if (outdialog.ShowModal() == wxID_OK)
   {
      wxString filen = outdialog.GetPath();
      if(filen.find(wxT(".p2p")) == wxString::npos)
      {
         filen += wxT(".p2p");
      }
      FILE *mf;
      mf = fopen(filen.mb_str(), "wb");

      if(mf)
      {
         fwrite(&m_proph->m_presetparam_au8[m_preset_u8], 1, PRESET_PARAM_BYTES * 2, mf);
         fclose(mf);
      }
      else
      {
         wxMessageDialog edialog(this, wxT("Could not save Preset File"), wxT("Error"));
         edialog.ShowModal();
      }
   }
}

void MyPresetParam::OnCopy(wxCommandEvent& event)
{
   PresetCopyDialog dlg(this, wxID_ANY);

   dlg.ShowModal();

   if(dlg.getCopyFlag())
   {
      uint32_t i;
      for(i = 0; i < (PRESET_PARAM_BYTES * 2); i++)
      {
         m_proph->m_presetparam_au8[dlg.getDestination() - 1][i] = m_proph->m_presetparam_au8[m_preset_u8][i];
      }

      m_proph->updateStructsFromParamBytes();
      m_topframe->updateGUI();

      if(m_topframe->getOnlineUpdateActive())
      {
         if(m_proph->transferPreset2Proph(dlg.getDestination() - 1))
         {
            m_topframe->transferStarted();
         }
      }
   }
}

void MyPresetParam::transferStarted(void)
{
}

void MyPresetParam::transferEnded(void)
{
}

void MyPresetParam::OnMouseRightDown(wxMouseEvent &event)
{
   //PopupMenu(m_menu, event.GetPosition());
}

