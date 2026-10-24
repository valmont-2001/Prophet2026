#ifndef __MAPCPYDLGH__
#define __MAPCPYDLGH__

class MapCopyDlg;

class MapCopyDialog : public MapCopyDlg
{
public:
   MapCopyDialog(wxWindow* parent, uint8_t srcmap);
   ~MapCopyDialog();

   bool getCopyFlag(void) const { return m_copy_flag; };
   int getDestination(void) const;
   bool getCopySoundMappingFlag(void) const;

private:
   bool m_copy_flag;
   bool m_copy_snd_mapping_flag;
   bool m_copy_snd_mapping_enabled;
   uint8_t m_srcmap;

   void OnOK(wxCommandEvent& event);
   void OnCancel(wxCommandEvent& event);
   void OnDestinationChange(wxCommandEvent &event);

   void copyEnableHandler(void);
};




#endif
