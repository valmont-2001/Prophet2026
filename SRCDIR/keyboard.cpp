#include "types.h"
#include <stdio.h>
#include <wx/wx.h>

#include "notetext.h"
#include <map>
#include <list>
using namespace std;
#include "clickarea.h"
#include "keyboard.h"
#include "stopwatch.h"
#include "proph2000.h"


BEGIN_EVENT_TABLE(Keyboard, wxPanel)
   EVT_PAINT(Keyboard::OnPaint)
   EVT_LEFT_DOWN(Keyboard::OnMouseLeftDown)
   EVT_LEFT_DCLICK(Keyboard::OnMouseLeftDown)
   EVT_LEFT_UP(Keyboard::OnMouseLeftUp)
   EVT_RIGHT_DOWN(Keyboard::OnMouseRightDown)
   EVT_MOTION(Keyboard::OnMouseMotion)
END_EVENT_TABLE()


Keyboard::Keyboard(wxWindow *parent, wxWindowID id, const wxPoint& pos, const wxSize& size) :
   wxPanel(parent, id, pos, size),
   m_size(size), m_note(0), m_velocity(0)
{
   uint16_t x;
   uint8_t i;
   uint8_t key_width;
/* 
   wxPoint m_origin;
   m_origin = pos;
   wxLogMessage("-Keyboard- x: %d, y: %d", m_origin.x,m_origin.y);
*/
   //SetScrollbars(20, 20, 50, 50);

   key_width = (m_size.GetWidth()) / (60 - (5 * 5)) ; // #keys - #black_keys

   x = (key_width / 2) + (key_width / 5);

   for(i = 0; i < ((60 - (5 * 5))); i++)
   {
      bool blackkey = false;
      uint8_t keyval = 0;

      switch(i % 7)
      {
         case 0:
            blackkey = true;
            keyval = 1;
            break;
         case 1:
            blackkey = true;
            keyval = 3;
            break;
         case 3:
            blackkey = true;
            keyval = 6;
            break;
         case 4:
            blackkey = true;
            keyval = 8;
            break;
         case 5:
            blackkey = true;
            keyval = 10;
            break;
      }

      keyval += ((i / 7) * 12) + KEYBOARD_C1_OFFSET;

      if(blackkey)
      {
         ClickArea area(x, 0, (key_width / 2) + (key_width / 5), (m_size.GetHeight() / 2), keyval);
         m_click_list.push_back(area);
      }
      x += key_width;
   }

   x = 0;
   for(i = 0; i < ((61 - (5 * 5))); i++)
   {
      uint16_t keyval = 0;

      switch(i % 7)
      {
         case 0:
            keyval = 0;
            break;
         case 1:
            keyval = 2;
            break;
         case 2:
            keyval = 4;
            break;
         case 3:
            keyval = 5;
            break;
         case 4:
            keyval = 7;
            break;
         case 5:
            keyval = 9;
            break;
         case 6:
            keyval = 11;
            break;
      }

      keyval += ((i / 7) * 12) + KEYBOARD_C1_OFFSET;

      ClickArea area(x, 0, key_width, m_size.GetHeight(), keyval);
      m_click_list.push_back(area);
      x += key_width;
   }
   resetKeyboardColours();
   render();
}


Keyboard::~Keyboard()
{
}


void Keyboard::resetKeyboard(void)
{
   map<uint8_t, list<NoteText> > empty_texts;
   m_lower_key_texts = empty_texts;
   m_upper_key_texts = empty_texts;
}

void Keyboard::resetKeyboardColours(void)
{
   wxColour white(255, 255, 255);
   wxColour black(0, 0, 0);
   uint8_t i;

   for(i = KEYBOARD_C1_OFFSET; i < (KEYBOARD_MAX_KEY + 1); i++)
   {
      if(isBlackKey(i))
      {
         m_upper_note_colour[i] = black;
         m_lower_note_colour[i] = black;
      }
      else
      {
         m_upper_note_colour[i] = white;
         m_lower_note_colour[i] = white;
      }
   }
}

void Keyboard::setUpperNoteColour(uint8_t note, wxColour &col)
{
   m_upper_note_colour[note] = col;
}


void Keyboard::setLowerNoteColour(uint8_t note, wxColour &col)
{
   m_lower_note_colour[note] = col;
}


void Keyboard::render(void)
{
   uint16_t x;
   uint8_t i;
   uint8_t key_width;

   resetKeyboard();
   setupKeyboadInfo();

   wxPaintDC dc( this );
   PrepareDC( dc );

   /* Burt*/
   uint16_t horizontal_size;
   uint8_t small_key_width;
   horizontal_size=  m_size.GetWidth();
   



   wxColour black(0, 0, 0);
   wxBrush black_border_brush(black, wxTRANSPARENT);
   wxBrush black_brush(black, wxSOLID);

   wxColour white(255, 255, 255);
   wxBrush white_brush(white, wxSOLID);

   key_width = getWhiteKeyWidth();

   x = 0;
   for(i = KEYBOARD_C1_OFFSET; i < (KEYBOARD_MAX_KEY + 1); i++)
   {
      if(!isBlackKey(i))
      {
         wxPen upper_pen(m_upper_note_colour[i]);
         wxPen lower_pen(m_lower_note_colour[i]);
         wxBrush upper_white_brush(m_upper_note_colour[i], wxSOLID);
         wxBrush lower_white_brush(m_lower_note_colour[i], wxSOLID);

         dc.SetPen(upper_pen);
         dc.SetBrush(upper_white_brush);
         dc.DrawRectangle(x, 0, key_width-1, (getWhiteKeyHeight() / 2));

         dc.SetPen(lower_pen);
         dc.SetBrush(lower_white_brush);
         dc.DrawRectangle(x, (getWhiteKeyHeight() / 2), key_width-1, (getWhiteKeyHeight() / 2));

         dc.SetPen(*wxBLACK_PEN);
         dc.SetBrush(black_border_brush);
//         dc.DrawRectangle(x, 0, key_width, getWhiteKeyHeight()); //original code
// Burt code begin
		 if ( (x + key_width-1) >= horizontal_size)
		 {
			 small_key_width = horizontal_size - x;
			 dc.DrawRectangle(x, 0, small_key_width, getWhiteKeyHeight());
		 }
		 else
			dc.DrawRectangle(x, 0, key_width-1, getWhiteKeyHeight()); // nicer look /*BURT*/
//Burt code end
         x += key_width;
      }
   }

   x = (key_width / 2) + (key_width / 5);

   dc.SetPen(*wxBLACK_PEN);
   dc.SetBrush(black_brush);
   for(i = (KEYBOARD_C1_OFFSET + 1); i < (KEYBOARD_MAX_KEY + 1); i++)
   {
      if(isBlackKey(i))
      {
         wxPen upper_pen(m_upper_note_colour[i]);
         wxPen lower_pen(m_lower_note_colour[i]);
         wxBrush upper_black_brush(m_upper_note_colour[i], wxSOLID);
         wxBrush lower_black_brush(m_lower_note_colour[i], wxSOLID);

         dc.SetPen(upper_pen);
         dc.SetBrush(upper_black_brush);
         dc.DrawRectangle(x, 0, getBlackKeyWidth(), (getBlackKeyHeight() / 2));

         dc.SetPen(lower_pen);
         dc.SetBrush(lower_black_brush);
         dc.DrawRectangle(x, (getBlackKeyHeight() / 2), getBlackKeyWidth(), (getBlackKeyHeight() / 2));

         dc.SetPen(*wxBLACK_PEN);
         dc.SetBrush(black_border_brush);
         dc.DrawRectangle(x, 0, getBlackKeyWidth(), getBlackKeyHeight());
      }
      else
      {
         x += key_width;
      }
      
   }

   renderTexts();
}


void Keyboard::renderTexts(void)
{
   uint16_t x;
   uint16_t y;
   uint8_t i;
   wxSize font_dim;

   wxPaintDC dc( this );
   PrepareDC( dc );

   map<uint8_t, list<NoteText> >::iterator myNoteItr = m_lower_key_texts.begin();

   for(i = KEYBOARD_C1_OFFSET; i < (KEYBOARD_MAX_KEY + 1); i++)
   {
      m_lower_key_texts[i].sort();
      list<NoteText>::const_iterator myItr = m_lower_key_texts[i].begin();
      uint8_t y_offset = 0;
      while(myItr != m_lower_key_texts[i].end())
      {
         if((*myItr).getText() != "")
         {
            wxBrush text_brush((*myItr).getColour(), wxSOLID);
            wxPen textpen((*myItr).getColour(), 1);

            dc.SetTextForeground((*myItr).getColour());
            dc.SetPen(textpen);
            dc.SetBrush(text_brush);

            font_dim = dc.GetTextExtent((*myItr).getText());

            x = getKeyCoordinate(i);
            if(!isBlackKey(i))
            {
               x = x + ((getWhiteKeyWidth() - font_dim.GetWidth()) / 2);
               y = getWhiteKeyHeight() - font_dim.GetHeight();
            }
            else
            {
               x = x + ((getBlackKeyWidth() - font_dim.GetWidth()) / 2) + 2;
               y = getBlackKeyHeight() - font_dim.GetHeight();
            }

            y -= y_offset;

            y_offset += font_dim.GetHeight();

            dc.DrawText((*myItr).getText(), x, y);
         }

         ++myItr;
      }
   }

   myNoteItr = m_upper_key_texts.begin();

   for(i = KEYBOARD_C1_OFFSET; i < (KEYBOARD_MAX_KEY + 1); i++)
   {
      m_upper_key_texts[i].sort();
      list<NoteText>::const_iterator myItr = m_upper_key_texts[i].begin();
      uint8_t y_offset = 0;
      while(myItr != m_upper_key_texts[i].end())
      {
         if((*myItr).getText() != "")
         {
            wxBrush text_brush((*myItr).getColour(), wxSOLID);
            wxPen textpen((*myItr).getColour(), 1);

            dc.SetTextForeground((*myItr).getColour());
            dc.SetPen(textpen);
            dc.SetBrush(text_brush);

            font_dim = dc.GetTextExtent((*myItr).getText());

            x = getKeyCoordinate(i);
            if(!isBlackKey(i))
            {
               //x = x + ((getWhiteKeyWidth() - font_dim.GetWidth()) / 2);
               y = (getWhiteKeyHeight() / 2) - font_dim.GetHeight();
            }
            else
            {
               x = x + ((getBlackKeyWidth() - font_dim.GetWidth()) / 2) + 2;
               y = (getBlackKeyHeight() / 2) - font_dim.GetHeight();
            }

            y -= y_offset;

            y_offset += font_dim.GetHeight();

            dc.DrawText((*myItr).getText(), x, y);
         }

         ++myItr;
      }
   }
}


void Keyboard::addBlackNoteText(uint8_t note, wxString &text, bool upperflag)
{
   addNoteText(note, text, *wxBLACK, upperflag);
}

void Keyboard::addNoteText(uint8_t note, wxString &text, const wxColour &colour, bool upperflag)
{
   NoteText nt(text, colour);
   //upperflag = true;
   if(upperflag)
   {
      m_upper_key_texts[note].push_back(nt);
   }
   else
   {
      m_lower_key_texts[note].push_back(nt);
   }
}


uint16_t Keyboard::getBlackKeyHeight(void) const
{
   return (m_size.GetHeight() / 2);
}

uint16_t Keyboard::getWhiteKeyHeight(void) const
{
   return m_size.GetHeight();
}

uint16_t Keyboard::getWhiteKeyWidth(void) const
{
   return ((m_size.GetWidth()) / (60 - (5 * 5))); 
}

uint16_t Keyboard::getBlackKeyWidth(void) const
{
   return (getWhiteKeyWidth() / 2) + (getWhiteKeyWidth() / 5);
}

uint16_t Keyboard::getKeyCoordinate(uint8_t note)
{
   uint16_t x;
   uint16_t xw;
   uint8_t i;
   uint16_t key_width;

   note -= KEYBOARD_C1_OFFSET;

   key_width = getWhiteKeyWidth();

   x = 0;
   xw = 0;

   for(i = 0; i < note; i++)
   {
      switch(i % 12)
      {
         case 0:
            x = xw;
            x += ((key_width / 2) + (key_width / 5) / 2);
            xw += key_width;
            break;
         case 1:
            x = xw;
            xw += key_width;
            break;
         case 2:
            xw = x;
            x += ((key_width / 2) + (key_width / 5) / 2);
            xw += key_width;
            break;
         case 3:
            x = xw;
            xw += key_width;
            break;
         case 4:
            x = xw;
            xw += key_width;
            break;
         case 5:
            xw = x;
            x += ((key_width / 2) + (key_width / 5) / 2);
            xw += key_width;
            break;
         case 6:
            x = xw;
            xw += key_width;
            break;
         case 7:
            xw = x;
            x += ((key_width / 2) + (key_width / 5) / 2);
            xw += key_width;
            break;
         case 8:
            x = xw;
            xw += key_width;
            break;
         case 9:
            xw = x;
            x += ((key_width / 2) + (key_width / 5) / 2);
            xw += key_width;
            break;
         case 10:
            x = xw;
            xw += key_width;
            break;
         case 11:
            x = xw;
            break;
      }         
   }
   return x;
}


bool Keyboard::isBlackKey(uint8_t note)
{
   uint8_t i;
   bool blackkey = false;

   note -= KEYBOARD_C1_OFFSET;

   for(i = 0; i < note; i++)
   {
      switch(i % 12)
      {
         case 0:
            blackkey = true;
            break;
         case 1:
            blackkey = false;
            break;
         case 2:
            blackkey = true;
            break;
         case 3:
            blackkey = false;
            break;
         case 4:
            blackkey = false;
            break;
         case 5:
            blackkey = true;
            break;
         case 6:
            blackkey = false;
            break;
         case 7:
            blackkey = true;
            break;
         case 8:
            blackkey = false;
            break;
         case 9:
            blackkey = true;
            break;
         case 10:
            blackkey = false;
            break;
         case 11:
            blackkey = false;
            break;
      }         
   }
   return blackkey;
}


void Keyboard::OnPaint(wxPaintEvent& WXUNUSED(event))
{
   render();
}


void Keyboard::OnMouseLeftDown(wxMouseEvent &event)
{
   list<ClickArea>::iterator myItr = m_click_list.begin();
   bool clicked = false;

   while((!clicked) && (myItr != m_click_list.end()))
   {
      clicked = (*myItr).isClicked(event.GetPosition().x, event.GetPosition().y);
      if(!clicked)
      {
         ++myItr;
      }
   }

   if(clicked)
   {
      m_note = (*myItr).getValue();
      m_velocity = ((*myItr).getHeightPercent() * 127) / 100;
      m_key_clicked = true;    
      noteOn();
   }
}


void Keyboard::OnMouseLeftUp(wxMouseEvent &event)
{
   m_key_clicked = false;
   noteOff();
}


void Keyboard::OnMouseMotion(wxMouseEvent &event)
{
   if(event.LeftIsDown())
   {
      list<ClickArea>::iterator myItr = m_click_list.begin();
      bool clicked = false;

      while((!clicked) && (myItr != m_click_list.end()))
      {
         clicked = (*myItr).isClicked(event.GetPosition().x, event.GetPosition().y);
         if(!clicked)
         {
            ++myItr;
         }
      }

      if(clicked)
      {
         if(m_note != (*myItr).getValue())
         {
            m_key_clicked = false;
            noteOff();
            m_note = (*myItr).getValue();
            m_velocity = ((*myItr).getHeightPercent() * 127) / 100;
            m_key_clicked = true;  
            noteOn();
         }
      }
   }
}

void Keyboard::OnMouseRightDown(wxMouseEvent &event)
{
   list<ClickArea>::iterator myItr = m_click_list.begin();
   bool clicked = false;

   while((!clicked) && (myItr != m_click_list.end()))
   {
      clicked = (*myItr).isClicked(event.GetPosition().x, event.GetPosition().y);
      if(!clicked)
      {
         ++myItr;
      }
   }

   if(clicked)
   {
      m_note = (*myItr).getValue();
      m_velocity = ((*myItr).getHeightPercent() * 127) / 100;
      rightClick();
   }
}


