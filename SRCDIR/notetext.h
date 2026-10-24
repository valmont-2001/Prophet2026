#ifndef __NOTETEXTH__
#define __NOTETEXTH__

class NoteText
{
public:
   NoteText(const wxString &text, const wxColour &textcolour);
   NoteText(const NoteText &rhnd);
   ~NoteText();

   const wxString &getText(void) const { return m_text; };
   const wxColour &getColour(void) const { return m_text_colour; };

	bool operator<(const NoteText& rhnd) const
	{
		return (m_text < rhnd.m_text);
	}


private:
   wxString m_text;
   wxColour m_text_colour;
};

#endif
