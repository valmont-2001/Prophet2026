#include "types.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include "GUILayout.h"
#include "soundcopydlg.h"



SoundCopyDialog::SoundCopyDialog(wxWindow* parent, wxWindowID id, const wxPoint& pos):
   SoundCopyDlg(parent), 
   m_copy_flag(false)
{
   m_copy_parameters_only->SetValue(true);
}


SoundCopyDialog::~SoundCopyDialog()
{
}


void SoundCopyDialog::OnOK(wxCommandEvent& event)
{
   m_copy_flag = true;
   Hide();
}

void SoundCopyDialog::OnCancel(wxCommandEvent& event)
{
   m_copy_flag = false;
   Hide();
}
