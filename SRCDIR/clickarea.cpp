#include "types.h"
#include "clickarea.h"



ClickArea::ClickArea(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t val) :
   m_x(x), m_y(y), m_width(w), m_height(h), m_val(val), m_height_percent(0)
{
}


ClickArea::ClickArea(const ClickArea &rhnd) :
   m_x(rhnd.m_x), m_y(rhnd.m_y), m_width(rhnd.m_width), m_height(rhnd.m_height), m_val(rhnd.m_val)
{
}


ClickArea::~ClickArea()
{
}


bool ClickArea::isClicked(uint16_t x, uint16_t y)
{
   bool retval = false;

   if((x >= m_x) && (x <= (m_x + m_width)) && (y >= m_y) && (y <= (m_y + m_height)))
   {
      retval = true;
      m_height_percent = (uint8_t)((y * 100) / m_height);
   }

   return retval;
}

