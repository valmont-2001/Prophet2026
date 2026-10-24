#ifndef __CLICKAREAH__
#define __CLICKAREAH__

class ClickArea
{
public:
   ClickArea(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t val);
   ClickArea(const ClickArea &rhnd);
   ~ClickArea();

   bool isClicked(uint16_t x, uint16_t y);
   uint16_t getValue(void) const { return m_val; };
   uint8_t getHeightPercent(void) const { return m_height_percent; };

private:
   uint16_t m_width;
   uint16_t m_height;
   uint16_t m_x;
   uint16_t m_y;
   uint16_t m_val;

   uint8_t m_height_percent;

};




#endif

