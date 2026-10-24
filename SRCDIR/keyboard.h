#ifndef __KEYBOARDH__
#define __KEYBOARDH__


#define KEYBOARD_MAX_KEY   (KEYBOARD_C1_OFFSET + (12*5))

class NoteText;

class Keyboard : public wxPanel
{
public:
   Keyboard(wxWindow *parent, wxWindowID id, const wxPoint& pos, const wxSize& size);
   ~Keyboard();

   void OnPaint( wxPaintEvent& WXUNUSED(event) );

   uint16_t getBlackKeyHeight(void) const;
   uint16_t getBlackKeyWidth(void) const;

   uint16_t getWhiteKeyHeight(void) const;
   uint16_t getWhiteKeyWidth(void) const;

   uint16_t getKeyCoordinate(uint8_t note);
   bool isBlackKey(uint8_t note);

   virtual void setupKeyboadInfo(void) { };
   
   void addBlackNoteText(uint8_t note, wxString &text, bool upperflag);
   void addNoteText(uint8_t note, wxString &text, const wxColour &colour, bool upperflag);

   void setUpperNoteColour(uint8_t note, wxColour &col);
   void setLowerNoteColour(uint8_t note, wxColour &col);


   void resetKeyboard(void);
   void resetKeyboardColours(void);

protected:
   uint8_t m_note;
   uint8_t m_velocity;
   bool m_key_clicked;

private:
   wxWindow *m_parent;
   wxSize m_size;
   
   list<ClickArea> m_click_list;
   map<uint8_t, wxColour> m_upper_note_colour;
   map<uint8_t, wxColour> m_lower_note_colour;
   map<uint8_t, list<NoteText> > m_lower_key_texts;
   map<uint8_t, list<NoteText> > m_upper_key_texts;

   void render(void);
   void renderTexts(void);

   void OnMouseLeftDown(wxMouseEvent &event);
   void OnMouseRightDown(wxMouseEvent &event);
   void OnMouseLeftUp(wxMouseEvent &event);
   void OnMouseMotion(wxMouseEvent &event);

   virtual void noteOn(void) { };  // override with specific handling
   virtual void noteOff(void) { }; // override with specific handling
   virtual void rightClick(void) { };  // override with specific handling

   DECLARE_EVENT_TABLE()
};


#endif
