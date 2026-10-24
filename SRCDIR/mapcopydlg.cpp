#include "types.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include "GUILayout.h"
#include "mapcopydlg.h"


MapCopyDialog::MapCopyDialog(wxWindow* parent, uint8_t srcmap):
   MapCopyDlg(parent), 
   m_copy_flag(false), m_copy_snd_mapping_flag(false), m_srcmap(srcmap), m_copy_snd_mapping_enabled(true)
{
   m_destination_number->AppendString(wxT("1"));
   m_destination_number->AppendString(wxT("2"));
   m_destination_number->AppendString(wxT("3"));
   m_destination_number->AppendString(wxT("4"));
   m_destination_number->AppendString(wxT("5"));
   m_destination_number->AppendString(wxT("6"));
   m_destination_number->AppendString(wxT("7"));
   m_destination_number->AppendString(wxT("8"));

   m_destination_number->AppendString(wxT("9"));
   m_destination_number->AppendString(wxT("A"));
   m_destination_number->AppendString(wxT("B"));
   m_destination_number->AppendString(wxT("C"));
   m_destination_number->AppendString(wxT("D"));
   m_destination_number->AppendString(wxT("E"));
   m_destination_number->AppendString(wxT("F"));
   m_destination_number->AppendString(wxT("G"));

   m_destination_number->SetSelection(m_srcmap);

   copyEnableHandler();
}

MapCopyDialog::~MapCopyDialog()
{
}


void MapCopyDialog::copyEnableHandler(void)
{
   if(m_srcmap < 8)
   {
      if(m_destination_number->GetSelection() < 8)
      {
         m_copy_snd_mapping->Enable();
         m_copy_snd_mapping_enabled = true;
      }
      else
      {
         m_copy_snd_mapping->Disable();
         m_copy_snd_mapping_enabled = false;
      }
   }
   else
   {
      if(m_destination_number->GetSelection() < 8)
      {
         m_copy_snd_mapping->Disable();
         m_copy_snd_mapping_enabled = false;
      }
      else
      {
         m_copy_snd_mapping->Enable();
         m_copy_snd_mapping_enabled = true;
      }
   }
}

void MapCopyDialog::OnDestinationChange(wxCommandEvent &event)
{
   copyEnableHandler();
}


int MapCopyDialog::getDestination(void) const 
{
   uint8_t retval;
   retval = m_destination_number->GetSelection(); 
   return retval;
}


void MapCopyDialog::OnOK(wxCommandEvent& event)
{
   m_copy_flag = true;
   m_copy_snd_mapping_flag = m_copy_snd_mapping->GetValue();
   Hide();
}

void MapCopyDialog::OnCancel(wxCommandEvent& event)
{
   m_copy_flag = false;
   m_copy_snd_mapping_flag = m_copy_snd_mapping->GetValue();
   Hide();
}

bool MapCopyDialog::getCopySoundMappingFlag(void) const
{
   bool retval = false;

   if(m_copy_snd_mapping_flag && m_copy_snd_mapping_enabled)
   {
      retval = true;
   }

   return retval;
}

