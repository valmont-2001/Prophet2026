#ifndef __MAPSCALVALDLGH__
#define __MAPSCALVALDLGH__

class Proph2000;
class MapScaledValuesDialog;

class MapScaleValuesDlg : public MapScaledValuesDialog
{
public:
   MapScaleValuesDlg(wxWindow* parent, wxWindowID id, Proph2000 *proph, uint8_t sound_u8, uint8_t map_u8, const wxPoint& pos = wxDefaultPosition);
   ~MapScaleValuesDlg();

   void updateGUI(void);


private:
   Proph2000 *m_proph;
   uint8_t m_sound_u8;
   uint8_t m_map_u8;
   bool show_vcf_env_amount;

   uint8_t calcPercentage(int8_t value);
   void OnLeftDown(wxMouseEvent& event);
};



#endif
