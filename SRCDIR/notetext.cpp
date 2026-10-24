#include <wx/wx.h>
#include <wx/string.h>

#include "types.h"
#include "notetext.h"

NoteText::NoteText(const wxString &text, const wxColour &textcolour) : m_text(text), m_text_colour(textcolour)
{
}

NoteText::NoteText(const NoteText &rhnd) : m_text(rhnd.m_text), m_text_colour(rhnd.m_text_colour)
{
}

NoteText::~NoteText()
{
}


