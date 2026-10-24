#include "types.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include "GUILayout.h"
#include "presetcopydlg.h"


PresetCopyDialog::PresetCopyDialog(wxWindow* parent, wxWindowID id, const wxPoint& pos):
   PresetCopyDlg(parent), 
   m_copy_flag(false)
{
}


PresetCopyDialog::~PresetCopyDialog()
{
}


void PresetCopyDialog::OnOK(wxCommandEvent& event)
{
   m_copy_flag = true;
   Hide();
}

void PresetCopyDialog::OnCancel(wxCommandEvent& event)
{
   m_copy_flag = false;
   Hide();
}
