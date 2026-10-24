#ifndef __PRESETCPYDLGH__
#define __PRESETCPYDLGH__

class PresetCopyDlg;

class PresetCopyDialog : public PresetCopyDlg
{
public:
   PresetCopyDialog(wxWindow* parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition);
   ~PresetCopyDialog();

   bool getCopyFlag(void) const { return m_copy_flag; };
   int getDestination(void) const { return m_destination_number->GetValue(); };

private:
   bool m_copy_flag;

   void OnOK(wxCommandEvent& event);
   void OnCancel(wxCommandEvent& event);
};




#endif
