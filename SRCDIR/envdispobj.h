#ifndef __ENVDISPOBJH__
#define __ENVDISPOBJH__


class EnvDispObj
{
public:
   EnvDispObj(uint8_t a, uint8_t d, uint8_t s, uint8_t r, uint8_t r_2nd, int16_t vol, wxColour col, uint8_t pos_x_offset_u8, uint8_t pos_y_offset_u8);
   EnvDispObj(const EnvDispObj &rhnd);
   ~EnvDispObj();

   uint8_t getA(void) const { return m_a; };
   uint8_t getD(void) const { return m_d; };
   uint8_t getS(void) const { return m_s; };
   uint8_t getR(void) const { return m_r; };
   uint8_t getR2nd(void) const { return m_r_2nd; };
   int16_t getVol(void) const { return m_vol; };
   wxColour getColour(void) const { return m_colour; };
   uint8_t getPosXOffset(void) const { return m_pos_x_offset_u8; };
   uint8_t getPosYOffset(void) const { return m_pos_y_offset_u8; };

private:
   uint8_t m_a;
   uint8_t m_d;
   uint8_t m_s;
   uint8_t m_r;
   uint8_t m_r_2nd;
   int16_t m_vol;
   wxColour m_colour;
   uint8_t m_pos_x_offset_u8;
   uint8_t m_pos_y_offset_u8;
};

#endif
