#include "types.h"
#include <wx/wx.h>
#include <wx/dcbuffer.h>
#include <wx/wupdlock.h>
#include <list>
using namespace std;

#include "envdisp.h"
#include "envdispobj.h"


BEGIN_EVENT_TABLE(EnvDisp, wxScrolledWindow)
   EVT_PAINT(EnvDisp::OnPaint)
END_EVENT_TABLE()

#define UPPER_SPACER 4
#define LINE_INC 4
#define X_OFFSET 4
#define X_INCREMENT 4

#define A_MAX 62
#define D_MAX 63
#define S_MAX 255
#define R_MAX 63


EnvDisp::EnvDisp(wxWindow *parent, wxWindowID id, const wxPoint& pos, const wxSize& size) :
   wxScrolledWindow(parent, id, pos, size),
   m_size(size)
{
   SetBackgroundColour(*wxBLACK);
   Refresh(true);
}


EnvDisp::~EnvDisp()
{
}


void EnvDisp::clearView(void)
{
   list<EnvDispObj> emptylist;
   m_list = emptylist;
}


void EnvDisp::drawADSR(uint8_t a, uint8_t d, uint8_t s, uint8_t r, uint8_t r_2nd, int16_t volume, wxColour env_colour, uint8_t pos_x_offset_u8, uint8_t pos_y_offset_u8)
{
   EnvDispObj env(a, d, s, r, r_2nd, volume, env_colour, pos_x_offset_u8, pos_y_offset_u8);
   m_list.push_back(env);
//   Refresh(true);
}

#define __USE_BUFFER
//#define __SPLINES

void EnvDisp::draw_smoothed_lines(wxList *points, wxMemoryDC *dc)
{
#ifndef __SPLINES
   if(points->size() >= 2)
   {
      // wx 3.x no longer accepts a wxList of wxObject*, so copy the points into an array
      wxVector<wxPoint> pts;
      for(wxList::iterator it = points->begin(); it != points->end(); ++it)
         pts.push_back(*(wxPoint*)(*it));
      dc->DrawLines(pts.size(), &pts[0], -1, 0);
      dc->DrawLines(pts.size(), &pts[0], 0, 0);
      dc->DrawLines(pts.size(), &pts[0], 0, 1);
   }
#else
   if(points->size() >= 2) // draw spline only if there are at least 2 points to draw (otherwise crash!)
   {
	   wxPen pen,pen2;
	   pen=dc->GetPen();
	   pen2=dc->GetPen();
	   pen.SetWidth(2);
	   dc->SetPen(pen);
	   dc->DrawSpline(points);
	   dc->SetPen(pen2);
   }
#endif
// remove contents from list
   wxList::iterator myItr = points->begin();
   while(myItr != points->end())
   {
      wxPoint *p = (wxPoint*)(*myItr);
      delete p;
      ++myItr;
   }
	points->clear();
}


void EnvDisp::draw_smoothed_line(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2, wxMemoryDC *dc)
{
	wxPen pen;
	pen=dc->GetPen();

	if ( x1 == x2 )
	{
		pen.SetWidth(2);
	}
	else
	{
		pen.SetWidth(1);
	}
	dc->SetPen(pen);
    dc->DrawLine(x1, y1-1, x2, y2-1);
    dc->DrawLine(x1, y1, x2, y2);
    dc->DrawLine(x1, y1+1, x2, y2+1);
}


double EnvDisp::logbase(double a, double base)
{
   return log(a) / log(base);
}

void EnvDisp::OnPaint(wxPaintEvent& WXUNUSED(event))
{
// The ADSR vs ADR discussion: Ths SUSTAIN level is irrelevant here, the Release time will immediately start at
// the level of key release, A or D wont be completed. If A and D are completed, the level is 0, R won't come to effect.
// This is of no practical relevance, as SUSTAIN is not relevant in the first case anyhow.
// A feature could been added to show RELEASE timings if the SUSTAIN level is set to OFF or achieves a <1 level
// by scaling it down. This is for visualization of RELEASE timings only.

#ifdef __USE_BUFFER
   wxBitmap drawbuffer(m_size.GetWidth(), m_size.GetHeight());
   {
   wxMemoryDC dc;
   dc.SelectObject(drawbuffer);
   wxWindowUpdateLocker noUpdates(this);
#else
   wxPaintDC dc( this );
   PrepareDC( dc );
#endif
   wxColour clr(0,0,0);
   wxBrush b(clr, wxSOLID);
   dc.SetBackground(b);
   //dc.Clear();

   wxPen black_pen(clr /* *wxBLACK */);
   wxBrush black_brush(clr /* *wxBLACK */, wxSOLID);

   dc.SetPen(black_pen);
   dc.SetBrush(black_brush);
   dc.DrawRectangle(0, 0, m_size.GetWidth(), m_size.GetHeight());

   uint16_t i;
   uint16_t x_old;
   uint16_t y_old;
   uint16_t y_start;
   uint16_t y_offset;
   uint16_t x;
   uint16_t x_offset;
   double x_origin,x_factor,x_buffer;
   uint16_t t1,y2;
   uint16_t height;
   uint16_t	linelength;
   uint16_t time_tmp_u16;
   uint16_t attack;
   uint16_t decay, s_d;
   uint16_t sustain;
   uint16_t dest_s;
   uint16_t dest_level;
   uint16_t release;
   uint16_t alt_release;
   uint16_t num_lines;
   uint16_t lineID;
   uint16_t delta_y;

   int16_t volume_parameter;
   double volume;
   bool flip_x_axis = false;
   uint8_t scaling; //scaling factor for split screen, 1=no scaling, 2= half
   double x_scale;
   
   x_scale= (double)(m_size.GetWidth() - 1) / (double)(A_MAX + D_MAX + R_MAX + X_OFFSET); 


   if(!m_list.empty())
   {
      list<EnvDispObj>::const_iterator myItr = m_list.end();

	  // Initialize frame of reference;
	   scaling = 1;
      lineID = 1;
      do
      {
         myItr--;
		   wxList *points=new(wxList);
//		 wxLogMessage("LineID = %d", lineID);

		   num_lines = (*myItr).getPosYOffset(); // number of lines to draw
		   x_offset = (*myItr).getPosXOffset() * X_INCREMENT; // for each element, increase offset on x-axis
//       The line below will increase 3D effect, but at the cost of clarity
//         x_scale = (double)(m_size.GetWidth() - x_offset) / (double)(A_MAX + D_MAX + R_MAX + X_OFFSET); 

		   delta_y = LINE_INC * (num_lines); // 3D - Box 
		   y_offset = LINE_INC * lineID; //portion which each line is shifted against the next for 3D view 

		   dc.SetPen(*wxWHITE_PEN);
         wxPen pen((*myItr).getColour(),1); // Burt: 2 looks better, but we'll try to address the aliasing
	      dc.SetPen(pen);
         dc.SetBrush(wxBrush((*myItr).getColour(), wxBRUSHSTYLE_SOLID));

		 /* Set up graphical coordinate handling */
         
		 /* Process volume information - it can be negative */
		   volume_parameter = (*myItr).getVol();
		   if ( volume_parameter < 0)
		   {	
			   flip_x_axis = true;
			   volume_parameter = volume_parameter * (-1); // stretch and make positive value
		   }
		   else
		   {
			   flip_x_axis = false;
		   }

		   if (flip_x_axis) 
		   {
			   linelength = m_size.GetHeight() - UPPER_SPACER - delta_y;
			   y_old = y_offset;
			   height = y_offset;
		   }
		   else 
		   {
			   linelength = m_size.GetHeight() - UPPER_SPACER - delta_y;
	 		   y_start = linelength + y_offset;
			   y_old = y_start;
			   height = y_start;
		   }
		   x_factor = x_scale;
		   x_origin = X_OFFSET+x_offset;
	      volume = (((double)volume_parameter)/255)/scaling ; //determine scaling factor introduced by volume

		   x_old = 0;
         x = 0;
		   points->push_back((wxObject*) new wxPoint(x_origin,y_old));

		 /* Draw ATTACK PHASE */
	      attack = (*myItr).getA(); // Get ATTACK data for current sound

	      if ( attack < 2) // ATTACK == INST or close to?
         {
            attack = 1; 
            t1 = linelength; 
            y2 = (uint16_t)((double)t1 * volume); // now t1 will range from 0 to adjusted volume
            if (!flip_x_axis) y2 = linelength - y2 + y_offset ; // as window has 0,0 in the upper left corner, flip y to distance from lower left corner.
				else y2 = y2 + y_offset;
			   points->push_back((wxObject*) new wxPoint( x_origin, y2));
			   x_origin += x_factor;
            y_old = y2;
            x_old = x;
            x++;
         }
         else
         {
            for(i = 1; i <= attack; i++)
            {
               //We'll do the scaling later, the total height is ok here
               time_tmp_u16 = i ; 	
               double mh = (double)(linelength) ;
               t1 = (uint16_t) ((logbase((double)i, attack) * mh));
               // t1 will still span the whole range from 0 to max_vol
               y2 = (uint16_t)((double)t1 * volume); // now t1 will range from 0 to adjusted volume
			      if (!flip_x_axis)y2 =  linelength - y2 + y_offset; 
				      else y2 = y2 + y_offset;
			      points->push_back ((wxObject*)new wxPoint(x_origin, y2));
			      x_origin += x_factor;
               y_old = y2;
               x_old = x;
               x++;
            }
         }
         draw_smoothed_lines(points,&dc);
		   // We're loosing the connecting point to continue the line, add it again
		   if( x > 0 ) 
		   {
            x--;
			   x_origin -= x_factor;
		   }
		   points->push_back ((wxObject*)new wxPoint(x_origin, y2));

		   /* Draw DECAY phase */
	      decay = (*myItr).getD();
	      sustain = (*myItr).getS();
	      // Calculate target SUSTAIN level within box limited by UPPER_SPACER and 3D-offset
         sustain = ((sustain * linelength)/255); 

         if( decay < D_MAX)
         {
            if(decay < 3)
               {
                  decay = 3; // Make decay phase always visible
               } 
			      s_d = decay;

               for(i = 1; i <= s_d; i++) //for DECAY, the last line was an issue - moving the ount index from 0 to 1 fixed it
               {
                  time_tmp_u16 = s_d - i; // We need to count reverse
			         t1 = linelength - sustain; // determine 'box' for Decay level
                  t1 = (uint16_t)(((uint64_t)( t1 * time_tmp_u16) * time_tmp_u16) / (s_d * s_d)) + sustain; // calculate Decay at this time		   
			         y2 = (uint16_t)((double)t1 * volume); // now t1 will range from 0 to adjusted volume
			         if (!flip_x_axis)y2 = linelength - y2 + y_offset; 
					      else y2 = y2 + y_offset;

				      points->push_back ((wxObject*)new wxPoint(x_origin, y2));

				      x_origin += x_factor;
                  y_old = y2;
                  x_old = x;
                  x++;
               }
            }
            else // DECAY is D_MAX
            {
			    for(i = 0; i < D_MAX; i++)
			    {
					points->push_back ((wxObject*)new wxPoint(x_origin, y2));
					x_origin += x_factor;
				   x_old = x;
				   x++;
			    }
            }

		 draw_smoothed_lines(points,&dc);
		 // We're loosing the connecting point to continue the line, add it again
		 if( x > 0 ) 
		 {
			 x--;
			 x_origin -= x_factor;
		 }
		 points->push_back ((wxObject*)new wxPoint(x_origin, y2));

		 /* Draw Sustain line */
	     if((*myItr).getD()!= D_MAX)  // On DECAY = INF, there is no SUSTAIN - RELEASE will start immediately at full level
	     {	
		     if((*myItr).getS()) 
		     {
			     for(i = 0; i < 10; i++) // Draw SUSTAIN line
			     {
					 points->push_back ((wxObject*)new wxPoint(x_origin, y2));
					 x_origin += x_factor;
				     x_old = x;
				     x++;
			     }
				 if( x > 0 ) 
				{
					x--;
					x_origin -= x_factor;
				}
		    }
	     }
		 
		 draw_smoothed_lines(points,&dc);
		 // We're loosing the connecting point to continue the line, add it again

         uint16_t xt = x_old;
         uint16_t yt = y_old;
         uint16_t xt2 = x;
		 uint16_t yt2 = y2;
		 x_buffer = x_origin;
         
         int16_t r = (*myItr).getColour().Red();
         int16_t g = (*myItr).getColour().Green();
         int16_t b = (*myItr).getColour().Blue();

         r -= 70;
         g -= 70;
         b -= 70;

         if(r < 0)
         {
            r = 0;
         }
         if(g < 0)
         {
            g = 0;
         }
         if(b < 0)
         {
            b = 0;
         }
         wxColour col2nd(r, g, b);

         dc.SetPen(wxPen(col2nd,1, wxPENSTYLE_SOLID));
         dc.SetBrush(wxBrush(col2nd, wxBRUSHSTYLE_SOLID));
/*		 if( x > 0 ) 
		 {
			 x--;
			 x_origin -= x_factor;
		 } */
		 points->push_back ((wxObject*)new wxPoint(x_origin, y2));

		 /* Draw 2nd RELEASE */
	     alt_release = (*myItr).getR2nd();
         if( alt_release -1 ) // Draw 2nd Release
         {

		    if (decay == D_MAX) // 
		    {
			    dest_level = 255; // full volume during key press on Dest = INF
		    }
		    else
		    {
			   dest_level = (*myItr).getS();
		    }

		    dest_s = ((dest_level * linelength) / 255);

            if( alt_release != R_MAX)
            {
               for(i = 1; i <= alt_release; i++)
               {
                  time_tmp_u16 = alt_release - i;
                  t1 = (((uint64_t)(dest_s * time_tmp_u16) * time_tmp_u16) / (alt_release * alt_release));
   	   
			      y2 = (uint16_t)((double)t1 * volume); // now t1 will range from 0 to adjusted volume
                  if (!flip_x_axis) y2 = linelength - y2 + y_offset; 
					else y2 = y2 + y_offset;
  				  points->push_back ((wxObject*)new wxPoint(x_origin, y2));
				  x_origin += x_factor;
                  y_old = y2;
                  x_old = x;
                  x++;
               }
            }
            else
            {
				points->push_back ((wxObject*)new wxPoint((uint16_t)(m_size.GetWidth() - 1), y2));
            }
         }
         else
         {		points->push_back ((wxObject*)new wxPoint(x_origin, height));

	     }
		 draw_smoothed_lines(points,&dc);

         x_old = xt;
         y_old = yt;
         x = xt2;
		 y2 = yt2;
		 x_origin = x_buffer;


         dc.SetPen(wxPen((*myItr).getColour(),1, wxPENSTYLE_SOLID));
         dc.SetBrush(wxBrush((*myItr).getColour(), wxBRUSHSTYLE_SOLID));
/*		 
		 if( x > 0 ) 
		 {
			 x--;
			 x_origin -= x_factor;
		 }
*/
		 points->push_back ((wxObject*)new wxPoint(x_origin, y2));

		 /* Draw RELEASE phase */
	     release = (*myItr).getR();
         if( release - 1) // Draw RELEASE
         {
		    if (decay == D_MAX) // 
		    {
			    dest_level = 255; // full volume during key press on Dest = INF
		    }
		    else
		    {
			   dest_level = (*myItr).getS();

		    }
		    dest_s = ((dest_level * linelength) / 255);

		    if(release != R_MAX)
            {
               for(i = 1; i <= release; i++)
               {
                  uint16_t time_tmp_u16;
                  time_tmp_u16 = release - i;
                  t1 = (((uint64_t)(dest_s * time_tmp_u16) * time_tmp_u16) / (release * release));

			      y2 = (uint16_t)((double)t1 * volume); // now t1 will range from 0 to adjusted volume
                  if (!flip_x_axis) y2 = linelength - y2  + y_offset;
					else y2 = y2 + y_offset;
				  points->push_back ((wxObject*)new wxPoint(x_origin, y2));
				  x_origin += x_factor;
                  y_old = y2;
                  x_old = x;
                  x++;
               }
            }
            else
            {
				points->push_back ((wxObject*)new wxPoint((uint16_t)(m_size.GetWidth() - 1), y2));
            }
         }
         else
         {
			points->push_back ((wxObject*)new wxPoint(x_origin, height));
         }
		 draw_smoothed_lines(points,&dc);
		 lineID ++; // Count the lines we are drawing from back to front;
       delete points;
      }
      while(myItr != m_list.begin());
   }

#ifdef __USE_BUFFER
}
   wxPaintDC dc2( this );
   PrepareDC( dc2 );
   dc2.DrawBitmap(drawbuffer, 0 , 0);
//  dc2.Blit(0, 0, m_size.GetWidth(), m_size.GetHeight(), &dc, 0, 0);
#else
#endif
}

