#ifndef __EnvDispH__
#define __EnvDispH__

#include <list>
using namespace std;
#include "envdispobj.h"

class EnvDisp : public wxScrolledWindow
{
public:
   typedef enum { EnvDisp_NOHIGHLIGHT, EnvDisp_SAMPLERANGE, EnvDisp_SUSTAINLOOP, EnvDisp_RELEASELOOP } hightlighttype_te;

   EnvDisp(wxWindow *parent, wxWindowID id, const wxPoint& pos, const wxSize& size);
   ~EnvDisp();

   void OnPaint( wxPaintEvent& WXUNUSED(event) );

   void clearView(void);
   void drawADSR(uint8_t a, uint8_t d, uint8_t s, uint8_t r, uint8_t r_2nd, int16_t volume, wxColour env_colour, uint8_t pos_x_offset_u8, uint8_t pos_y_offset_u8);
   void draw_smoothed_line(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2, wxMemoryDC *dc);
   void draw_smoothed_lines(wxList *points, wxMemoryDC *dc);


private:
   wxWindow *m_parent;
   wxSize m_size;
   list<EnvDispObj> m_list;
   wxImage m_image;

   double logbase(double a, double base);

   DECLARE_EVENT_TABLE()
};


#endif
