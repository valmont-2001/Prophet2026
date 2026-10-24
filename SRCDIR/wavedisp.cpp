#include "types.h"
#include <wx/wx.h>
#include "wavedisp.h"


BEGIN_EVENT_TABLE(WaveDisp, wxScrolledWindow)
   EVT_PAINT(WaveDisp::OnPaint)
   EVT_MOUSEWHEEL(WaveDisp::OnMouseWheel) 
   EVT_KEY_DOWN(WaveDisp::OnKeyEvent) 
END_EVENT_TABLE()


WaveDisp::WaveDisp(wxWindow *parent, wxWindowID id, const wxPoint& pos, const wxSize& size) :
wxScrolledWindow(parent, id, pos, size),
m_size(size), m_sample_words(0), m_zoom_scale(1), m_start_point(0), m_end_point(0),
   m_sustainloop_start(0), m_sustainloop_end(0), m_display_sustain_loop(false),
   m_releaseloop_start(0), m_releaseloop_end(0), m_display_release_loop(false),
   hightlighttype_e(WAVEDISP_NOHIGHLIGHT), m_sample_data_u16(NULL)
{
   SetScrollbars(20, 0, 50, 0);
   m_width = size.GetWidth();
   m_height = size.GetHeight();

   SetVirtualSize(m_width, m_height);

   render();
}


WaveDisp::~WaveDisp()
{
}


void WaveDisp::setHighlightType(hightlighttype_te type)
{
   hightlighttype_e = type;
   Refresh(true);
}

void WaveDisp::render(void)
{
   uint16_t old_x;
   uint16_t old_y;
   uint16_t x;
   uint16_t y;
    uint16_t t = 0;
//   int xs;
//   int ys;

   wxPaintDC dc( this );
   PrepareDC( dc );


   wxColour clr(0,0,0);
   wxBrush b(clr, wxSOLID);
   dc.SetBackground(b);
   //dc.Clear();

   wxPen black_pen(*wxBLACK);
   wxBrush black_brush(*wxBLACK, wxSOLID);

   dc.SetPen(black_pen);
   dc.SetBrush(black_brush);
   dc.DrawRectangle(0, 0, m_width, m_height);




   dc.SetPen(*wxWHITE_PEN);
   //dc.SetBrush( *wxTRANSPARENT_BRUSH );

   if(m_sample_words)
   {
      old_x = 0;
      old_y = m_height / 2;
      //float stepsize = (float)m_size.GetWidth() / (float)m_sample_words;
      float stepsize;
      float step = 0;
      uint32_t old_step = 0;

      stepsize = (float)(m_width) / (float)m_sample_words;

      switch(hightlighttype_e)
      {
         case WAVEDISP_NOHIGHLIGHT:
            break;
         case WAVEDISP_SAMPLERANGE:
            {
               wxColour startend_colour(60, 60, 60);
               dc.SetPen(wxPen(startend_colour));
               dc.SetBrush(wxBrush(startend_colour, wxSOLID));
               dc.DrawRectangle((uint16_t)((float)m_start_point * stepsize), 0, (uint16_t)((float)m_end_point * stepsize) - (uint16_t)((float)m_start_point * stepsize), m_height);
            }
            break;
         case WAVEDISP_SUSTAINLOOP:
            {
               wxColour startend_colour(60, 60, 60);
               dc.SetPen(wxPen(startend_colour));
               dc.SetBrush(wxBrush(startend_colour, wxSOLID));
               dc.DrawRectangle((uint16_t)((float)m_start_point * stepsize), 0, (uint16_t)((float)m_end_point * stepsize) - (uint16_t)((float)m_start_point * stepsize), m_height);
            }
            //if(m_display_sustain_loop)
            {
               wxColour suststartend_colour(90, 90, 0);
               dc.SetPen(wxPen(suststartend_colour));
               dc.SetBrush(wxBrush(suststartend_colour, wxSOLID));
               dc.DrawRectangle((uint16_t)((float)m_sustainloop_start * stepsize), 0, (uint16_t)((float)m_sustainloop_end * stepsize) - (uint16_t)((float)m_sustainloop_start * stepsize), m_height);
            }
            break;
         case WAVEDISP_RELEASELOOP:
            {
               wxColour startend_colour(60, 60, 60);
               dc.SetPen(wxPen(startend_colour));
               dc.SetBrush(wxBrush(startend_colour, wxSOLID));
               dc.DrawRectangle((uint16_t)((float)m_start_point * stepsize), 0, (uint16_t)((float)m_end_point * stepsize) - (uint16_t)((float)m_start_point * stepsize), m_height);
            }
            //if(m_display_release_loop)
            {
               wxColour relstartend_colour(0, 90, 0);
               dc.SetPen(wxPen(relstartend_colour));
               dc.SetBrush(wxBrush(relstartend_colour, wxSOLID));
               dc.DrawRectangle((uint16_t)((float)m_releaseloop_start * stepsize), 0, (uint16_t)((float)m_releaseloop_end * stepsize) - (uint16_t)((float)m_releaseloop_start * stepsize), m_height);
            }
            break;
         default:
            break;
      }

      dc.SetPen(*wxGREEN_PEN);
      dc.DrawLine(0, m_height / 2, m_width, m_height / 2);

      // draw start line
      dc.SetPen(*wxRED_PEN);
      x = (uint16_t)((float)m_start_point * stepsize);
      dc.DrawLine(x, 0, x, m_height);

      // draw end line
      dc.SetPen(*wxRED_PEN);
      x = (uint16_t)((float)m_end_point * stepsize);
      dc.DrawLine(x, 0, x, m_height);

      //if(m_display_sustain_loop)
      {
         // draw sustain loop start line
         dc.SetPen(wxColour(255, 255, 0));
         x = (uint16_t)((float)m_sustainloop_start * stepsize);
         dc.DrawLine(x, 0, x, m_height);

         // draw sustain loop end line
         dc.SetPen(wxColour(255, 255, 0));
         x = (uint16_t)((float)m_sustainloop_end * stepsize);
         dc.DrawLine(x, 0, x, m_height);
      }

      //if(m_display_release_loop)
      {
         // draw release loop start line
         dc.SetPen(wxColour(0, 255, 0));
         x = (uint16_t)((float)m_releaseloop_start * stepsize);
         dc.DrawLine(x, 0, x, m_height);

         // draw release loop end line
         dc.SetPen(wxColour(0, 255, 0));
         x = (uint16_t)((float)m_releaseloop_end * stepsize);
         dc.DrawLine(x, 0, x, m_height);
      }

      stepsize = (float)m_sample_words / (float)(m_width);

      dc.SetPen(*wxWHITE_PEN);

      if(m_sample_data_u16)
      {
         for(x = 0; x < m_width; x++)
         {
             float v = (float)m_sample_data_u16[(uint32_t)step] - (4096 / 2);
             float v2 = v / 4096;
             float v3 = v2 * m_height;
             y = (int16_t) v3;
             int32_t yt = (int32_t)v3;
            //wxLogMessage("%d : dat: %d idx:%f", y, m_sample_data_u16[(uint32_t)step], step);
             //wxLogMessage("%d", (uint16_t)((int32_t) 400 - (4096 / 2)) );
            y = (uint16_t)((-yt) + m_height / 2);
             
             
             
            old_step = (uint32_t)step;

            //dc.DrawPoint(x, y);
            dc.DrawLine(x, y, old_x, old_y);

            old_x = x;
            old_y = y;
            step += stepsize;
         }
      }
   }
   else
   {
      dc.SetPen(*wxGREEN_PEN);
      dc.DrawLine(0, m_height / 2, m_width, m_height / 2);
   }
}


void WaveDisp::OnPaint(wxPaintEvent& WXUNUSED(event))
{
   render();
}


void WaveDisp::setSampleWords(uint32_t samplewords)
{
   m_sample_words = samplewords;
}


void WaveDisp::OnMouseWheel(wxMouseEvent &event)
{
   if(event.GetWheelRotation() > 0)
   {
      zoomOut();
   }
   else
   {
      zoomIn();
   }
}


void WaveDisp::OnKeyEvent(wxKeyEvent &event)
{
   if((event.GetKeyCode() == '+') || (event.GetKeyCode() == WXK_NUMPAD_ADD))
   {
      zoomIn();
   }
   if((event.GetKeyCode() == '-') || (event.GetKeyCode() == WXK_NUMPAD_SUBTRACT))
   {
      zoomOut();
   }
}



void WaveDisp::resetZoom(void)
{
   m_zoom_scale = 1;
   m_width = m_size.GetWidth();

   SetVirtualSize(m_width, m_size.GetHeight());
}


void WaveDisp::zoomIn(void)
{
   if(m_zoom_scale > 0.03125)
   {
      m_zoom_scale /= 2;
      m_width *= 2;

      m_height = m_size.GetHeight() - 15;
      int x;
      int y;
      GetViewStart(&x, &y);

      SetVirtualSize(m_width, m_height);

      Scroll(x * 2, y);

      render();
      Refresh(true);
   }
}


void WaveDisp::zoomOut(void)
{
   if(m_zoom_scale < 1)
   {
      m_zoom_scale *= 2;
      m_width /= 2;
      if(m_zoom_scale == 1)
      {
         m_height = m_size.GetHeight();
      }
   }
   else
   {
      m_zoom_scale = 1;
      m_width = m_size.GetWidth();
      m_height = m_size.GetHeight();
   }

   int x;
   int y;
   GetViewStart(&x, &y);

   SetVirtualSize(m_width, m_height);

   Scroll(x / 2, y);

   render();
   Refresh(true);
}




void WaveDisp::setStartPoint(uint32_t startpoint)
{
   m_start_point = startpoint;
}


void WaveDisp::setEndPoint(uint32_t endpoint)
{
   m_end_point = endpoint;
}

void WaveDisp::setSustainLoopStart(uint32_t pos)
{
   m_sustainloop_start = pos;
}

void WaveDisp::setSustainLoopEnd(uint32_t pos)
{
   m_sustainloop_end = pos;
}

void WaveDisp::setDisplaySustainLoop(bool flag) 
{ 
   m_display_sustain_loop = flag; 
}

void WaveDisp::setReleaseLoopStart(uint32_t pos)
{
   m_releaseloop_start = pos;
}

void WaveDisp::setReleaseLoopEnd(uint32_t pos)
{
   m_releaseloop_end = pos;
}

void WaveDisp::setDisplayReleaseLoop(bool flag) 
{ 
   m_display_release_loop = flag; 
}


