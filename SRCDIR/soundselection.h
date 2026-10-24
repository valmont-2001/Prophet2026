#ifndef __SNDSELECTIONH__
#define __SNDSELECTIONH__


class MySoundParam;
class Proph2000;

class SoundSelectionPanelImpl : public SoundSelectionPanel
{
public:
    SoundSelectionPanelImpl(wxWindow *parent, MySoundParam *panel, Proph2000 *proph);
    ~SoundSelectionPanelImpl();

    void setEmptySlot(uint8_t sound, bool flag);
    void makeActive(uint8_t sound_u8);

    void updateGUI(void);

private:
   MySoundParam *m_panel;
   Proph2000 *m_proph;

   void OnSelectSound1(wxCommandEvent &event);
   void OnSelectSound2(wxCommandEvent &event);
   void OnSelectSound3(wxCommandEvent &event);
   void OnSelectSound4(wxCommandEvent &event);
   void OnSelectSound5(wxCommandEvent &event);
   void OnSelectSound6(wxCommandEvent &event);
   void OnSelectSound7(wxCommandEvent &event);
   void OnSelectSound8(wxCommandEvent &event);
   void OnSelectSound9(wxCommandEvent &event);
   void OnSelectSound10(wxCommandEvent &event);
   void OnSelectSound11(wxCommandEvent &event);
   void OnSelectSound12(wxCommandEvent &event);
   void OnSelectSound13(wxCommandEvent &event);
   void OnSelectSound14(wxCommandEvent &event);
   void OnSelectSound15(wxCommandEvent &event);
   void OnSelectSound16(wxCommandEvent &event);

   void deselectAllSoundButtons(void);


};




#endif
