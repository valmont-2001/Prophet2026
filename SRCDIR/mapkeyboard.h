#ifndef __MAPKEYBOARDH__
#define __MAPKEYBOARDH__

class Keyboard;
class MyMapParam;
class Proph2000;

class MapKeyboard : public Keyboard
{
public:
    MapKeyboard(wxWindow *parent, wxWindowID id, const wxPoint& pos, const wxSize& size, MyMapParam *mapparamdlg,
                   Proph2000 *proph, uint8_t map_u8);
    ~MapKeyboard();

    virtual void setupKeyboadInfo(void);

    void activateMap(uint8_t map_u8);

private:
   MyMapParam *m_mapparamdlg;
   uint8_t m_map_u8;
   Proph2000 *m_proph;
   wxSize m_size;

   virtual void noteOn(void);
   virtual void noteOff(void);

};


#endif
