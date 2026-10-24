#include <wx/wx.h>
#include "types.h"
#include "envdispobj.h"


EnvDispObj::EnvDispObj(uint8_t a, uint8_t d, uint8_t s, uint8_t r, uint8_t r_2nd, int16_t vol, wxColour col, uint8_t pos_x_offset_u8, uint8_t pos_y_offset_u8) :
   m_a(a), m_d(d), m_s(s), m_r(r), m_colour(col), m_vol(vol),m_pos_x_offset_u8(pos_x_offset_u8), m_r_2nd(r_2nd), m_pos_y_offset_u8(pos_y_offset_u8)
{
}

EnvDispObj::EnvDispObj(const EnvDispObj &rhnd) :
m_a(rhnd.m_a), m_d(rhnd.m_d), m_s(rhnd.m_s), m_r(rhnd.m_r), m_r_2nd(rhnd.m_r_2nd), m_vol(rhnd.m_vol),m_colour(rhnd.m_colour), m_pos_x_offset_u8(rhnd.m_pos_x_offset_u8),
m_pos_y_offset_u8(rhnd.m_pos_y_offset_u8)
{
}


EnvDispObj::~EnvDispObj()
{
}


