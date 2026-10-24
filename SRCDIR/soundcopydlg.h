#ifndef __SNDCPYDLGH__
#define __SNDCPYDLGH__

class SoundCopyDlg;

class SoundCopyDialog : public SoundCopyDlg
{
public:
   SoundCopyDialog(wxWindow* parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition);
   ~SoundCopyDialog();

   bool getCopyFlag(void) const { return m_copy_flag; };
   int getDestination(void) const { return m_destination_number->GetValue(); };
   bool getCopyParametersOnly(void) const { return m_copy_parameters_only->GetValue(); };

private:
   bool m_copy_flag;

   void OnOK(wxCommandEvent& event);
   void OnCancel(wxCommandEvent& event);
};




#endif
