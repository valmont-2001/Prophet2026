// macOS specific adaptions of the wxFormBuilder generated layout (GUILayout.cpp),
// so the GUI looks like the Windows version shown in the user manual.
#include <wx/wx.h>
#include <wx/tglbtn.h>
#include <wx/log.h>
#include <wx/slider.h>
#include <map>
#include <set>
#include <wx/eventfilter.h>
#include <wx/osx/core/cfstring.h>
#import <QuartzCore/QuartzCore.h>
#import <Cocoa/Cocoa.h>

#include "macstyle.h"

// The manual shows the classic light look. Custom drawn widgets (keyboard,
// envelope and wave displays) assume a light background as well.
static void MacForceLightAppearance(void)
{
   [NSApp setAppearance:[NSAppearance appearanceNamed:NSAppearanceNameAqua]];
}


// GUILayout.cpp uses Windows point sizes (8pt Tahoma). macOS renders points
// at 72dpi instead of 96dpi, so these fonts become tiny.
static void adaptFont(wxWindow *w)
{
   const wxFont font = w->GetFont();
   if(!font.IsOk())
      return;
   const bool small = font.GetFaceName() == wxT("Tahoma") || font.GetPointSize() <= 9;
   // wxFONTSTYLE_SLANT maps to an odd looking font on macOS, Windows renders it italic
   const bool slant = font.GetStyle() == wxFONTSTYLE_SLANT;
   if(small || slant)
   {
      wxFontInfo info(small ? 11 : font.GetPointSize());
      info.Family(wxFONTFAMILY_SWISS).Bold(font.GetWeight() >= wxFONTWEIGHT_BOLD)
          .Italic(slant || font.GetStyle() == wxFONTSTYLE_ITALIC);
      w->SetFont(wxFont(info));
   }
}


// Titles split in the middle of a word ("Mem" + "ory") are used to center a
// title across two grid columns. On macOS this leaves a visible gap, so the
// fragments are hidden and replaced by one centered title above the grid.
static void joinTitle(wxStaticText *left, wxStaticText *right)
{
   wxWindow *panel = left->GetParent();
   wxSizer *grid = panel->GetSizer();
   if(!grid || right->GetParent() != panel)
      return;

   wxStaticText *title = new wxStaticText(panel, wxID_ANY, left->GetLabel() + right->GetLabel());
   wxFont font = left->GetFont();
   font.SetWeight(wxFONTWEIGHT_BOLD);
   title->SetFont(font);

   left->Hide();
   right->Hide();

   wxBoxSizer *box = new wxBoxSizer(wxVERTICAL);
   panel->SetSizer(box, false);
   box->Add(title, 0, wxALIGN_CENTER_HORIZONTAL | wxTOP, 5);
   box->Add(grid, 1, wxEXPAND);
}


static bool isTitleFragmentPair(wxStaticText *left, wxStaticText *right)
{
   const wxString l = left->GetLabel();
   const wxString r = right->GetLabel();
   if(l.empty() || r.empty() || !left->GetFont().IsOk() || left->GetFont().GetWeight() != wxFONTWEIGHT_BOLD)
      return false;
   // a split word: no blank at the split position and the right part starts lower case
   return !l.EndsWith(wxT(" ")) && !r.StartsWith(wxT(" ")) && wxIslower(r[0]) && wxIsalpha(l.Last());
}


// gives access to the min/max/value labels wxOSX creates for wxSL_LABELS
struct SliderLabels : public wxSlider
{
   using wxSlider::m_macMinimumStatic;
   using wxSlider::m_macMaximumStatic;
   using wxSlider::m_macValueStatic;
};

// wxOSX puts the labels of vertical sliders right of the track (overlapping the
// knob) and those of horizontal sliders below it. The manual shows them left of
// vertical sliders and above horizontal ones, so the native slider and its labels
// are rearranged within the rectangle the sizer assigned to the slider.
static void arrangeSlider(wxSlider *slider)
{
   SliderLabels *labels = static_cast<SliderLabels*>(slider);
   wxStaticText *texts[3] = { labels->m_macMinimumStatic, labels->m_macMaximumStatic, labels->m_macValueStatic };
   if(!texts[0] || !texts[1] || !texts[2])
      return;

   NSView *view = (NSView*)slider->GetHandle();
   const NSRect current = [view frame];
   // per slider: the rectangle assigned by wx and the frame set here
   static std::map<wxSlider*, std::pair<NSRect, NSRect> > s_frames;
   std::pair<NSRect, NSRect> &frames = s_frames[slider];
   // a frame different from the one set here means wx did a new layout
   if(!NSEqualRects(current, frames.second))
      frames.first = current;
   const NSRect r = frames.first;

   NSRect frame;
   if(slider->HasFlag(wxSL_VERTICAL))
   {
      const CGFloat track = 22;
      frame = NSMakeRect(NSMaxX(r) - track, r.origin.y, track, r.size.height);
      for(int i = 0; i < 3; i++)
      {
         const wxSize size = texts[i]->GetBestSize();
         texts[i]->SetSize(NSMinX(frame) - 1 - size.x, texts[i]->GetPosition().y, size.x, size.y);
      }
   }
   else
   {
      const CGFloat label = texts[0]->GetBestSize().y;
      frame = NSMakeRect(r.origin.x, r.origin.y + label, r.size.width, r.size.height - label);
      // wxOSX already swaps the label texts for wxSL_INVERSE
      wxStaticText *left = texts[0];
      wxStaticText *right = texts[1];
      const int x = r.origin.x, width = r.size.width;
      left->SetSize(x, r.origin.y, left->GetBestSize().x, label);
      right->SetSize(x + width - right->GetBestSize().x, r.origin.y, right->GetBestSize().x, label);
      texts[2]->SetSize(x + (width - texts[2]->GetBestSize().x) / 2, r.origin.y, texts[2]->GetBestSize().x, label);
   }
   if(!NSEqualRects(frame, current))
      [view setFrame:frame];
   frames.second = frame;
}


// wxOSX enlarges the native frame of buttons by the bezel insets of older macOS
// versions (6px left/right, 4/7px top/bottom). Current macOS draws the bezel over
// the whole frame, so buttons placed without spacing (e.g. "Used in Map") overlap.
// The native frame is therefore fitted to the rectangle the sizer assigned.
static void fitButtonFrame(wxAnyButton *tb)
{
   NSView *view = (NSView*)tb->GetHandle();
   const NSRect current = [view frame];
   // per button: the rectangle assigned by wx and the frame set here
   static std::map<wxAnyButton*, std::pair<wxRect, NSRect> > s_frames;
   std::pair<wxRect, NSRect> &frames = s_frames[tb];
   // a frame different from the one set here means wx did a new layout
   if(!NSEqualRects(current, frames.second))
      frames.first = tb->GetRect();
   const wxRect &r = frames.first;

   const CGFloat height = wxMax(r.height, 21);
   const NSRect frame = NSMakeRect(r.x + 1, r.y + (r.height - height) / 2, r.width - 2, height);
   if(!NSEqualRects(frame, current))
      [view setFrame:frame];
   frames.second = frame;
}


// draws a selection toggle button flat; see adaptWindow()
static void styleToggleButton(wxToggleButton *tb)
{
   NSButton *button = (NSButton*)tb->GetHandle();
   const bool on = tb->GetValue();
   NSColor *text = on ? [NSColor alternateSelectedControlTextColor] : [NSColor controlTextColor];
   NSColor *fill = on ? [NSColor controlAccentColor] : [NSColor colorWithWhite:0.0 alpha:0.09];

   if([button isBordered])
   {
      [button setBordered:NO];
      // the state is shown by the layer colour, no dimming/inverting by the cell
      [[button cell] setShowsStateBy:NSNoCellMask];
      [[button cell] setHighlightsBy:NSNoCellMask];
   }
   [button setWantsLayer:YES];
   CALayer *layer = [button layer];
   [layer setCornerRadius:5.0];
   [layer setBackgroundColor:[fill CGColor]];

   // borderless buttons tint their title themselves on current macOS
   if(![[button contentTintColor] isEqual:text])
      [button setContentTintColor:text];

   NSAttributedString *title = [button attributedTitle];
   NSColor *current = [title length] ? [title attribute:NSForegroundColorAttributeName atIndex:0 effectiveRange:NULL] : nil;
   if(![current isEqual:text] || ![[button title] isEqualToString:wxCFStringRef(tb->GetLabel()).AsNSString()])
   {
      NSMutableParagraphStyle *para = [[NSMutableParagraphStyle alloc] init];
      [para setAlignment:NSTextAlignmentCenter];
      NSDictionary *attrs = @{ NSFontAttributeName: tb->GetFont().OSXGetNSFont(),
                               NSForegroundColorAttributeName: text,
                               NSParagraphStyleAttributeName: para };
      NSAttributedString *str = [[NSAttributedString alloc] initWithString:wxCFStringRef(tb->GetLabel()).AsNSString() attributes:attrs];
      [button setAttributedTitle:str];
      [button setAttributedAlternateTitle:str]; // shown in the "on" state
   }
}


static void adaptWindow(wxWindow *w)
{
   // every window is adapted only once (event bindings, joined titles)
   static std::set<wxWindow*> s_adapted;
   if(!s_adapted.insert(w).second)
      return;
   w->Bind(wxEVT_DESTROY, [w](wxWindowDestroyEvent &event)
   {
      if(event.GetEventObject() == w)
         s_adapted.erase(w);
      event.Skip();
   });

   if(wxSlider *slider = wxDynamicCast(w, wxSlider))
   {
      // sliders without explicit size get the Windows default length of 100
      // instead of the larger wxOSX default (the manual shows the Windows sizes)
      wxSize min = slider->GetMinSize();
      const wxSize best = slider->GetBestSize();
      if(slider->HasFlag(wxSL_VERTICAL) && min.y == wxDefaultCoord)
         slider->SetMinSize(wxSize(min.x, 100));
      else if(!slider->HasFlag(wxSL_VERTICAL) && min.x == wxDefaultCoord)
         slider->SetMinSize(wxSize(100, min.y == wxDefaultCoord ? best.y : min.y));
      // small label font like the Windows version
      SliderLabels *labels = static_cast<SliderLabels*>(slider);
      wxStaticText *texts[3] = { labels->m_macMinimumStatic, labels->m_macMaximumStatic, labels->m_macValueStatic };
      for(int i = 0; i < 3; i++)
         if(texts[i])
            texts[i]->SetFont(wxFont(wxFontInfo(10).Family(wxFONTFAMILY_SWISS)));
      if(slider->HasFlag(wxSL_LABELS))
         slider->Bind(wxEVT_UPDATE_UI, [slider](wxUpdateUIEvent &event)
         {
            arrangeSlider(slider);
            event.Skip();
         });
   }

   adaptFont(w);

   // labels with a fixed minimum width made for the Windows font would be cut
   if(wxStaticText *st = wxDynamicCast(w, wxStaticText))
   {
      const wxSize min = st->GetMinSize();
      st->SetMinSize(wxDefaultSize);
      const int best = st->GetBestSize().x;
      st->SetMinSize(wxSize(min.x != wxDefaultCoord && best > min.x ? best : min.x, min.y));
   }

   // normal buttons: same frame problem as the toggle buttons below, e.g. the
   // loop point buttons ("<<", "<", ">", ">>") are placed without spacing
   if(wxButton *button = wxDynamicCast(w, wxButton))
   {
      const wxSize min = button->GetMinSize();
      if(button->GetBestSize().y < 21 && min.y < 21)
         button->SetMinSize(wxSize(min.x, 21));
      // narrow buttons: the rounded bezel leaves no room for the label
      const bool narrow = button->GetSize().x < 50;
      button->Bind(wxEVT_UPDATE_UI, [button, narrow](wxUpdateUIEvent &event)
      {
         NSButton *b = (NSButton*)button->GetHandle();
         if(narrow && [b bezelStyle] != NSBezelStyleSmallSquare)
            [b setBezelStyle:NSBezelStyleSmallSquare];
         fitButtonFrame(button);
         event.Skip();
      });
   }

   // The generated layout gives all selection toggle buttons a black background
   // with white text. Windows ignores this for native buttons, macOS doesn't.
   if(wxToggleButton *tb = wxDynamicCast(w, wxToggleButton))
   {
      // some selection buttons are added with wxEXPAND and would be stretched
      // to the full row height
      if(wxSizer *sizer = tb->GetContainingSizer())
         if(wxSizerItem *item = sizer->GetItem(tb))
            if(wxBoxSizer *box = wxDynamicCast(sizer, wxBoxSizer))
               if(box->GetOrientation() == wxHORIZONTAL)
                  item->SetFlag(item->GetFlag() & ~wxEXPAND);

      // wxOSX reports only 13px height for these buttons (it subtracts the bezel
      // insets), reserve the height a button really needs (see fitButtonFrame)
      const wxSize min = tb->GetMinSize();
      if(tb->GetBestSize().y < 21 && min.y < 21)
         tb->SetMinSize(wxSize(min.x, 21));

      tb->SetBackgroundColour(wxNullColour);
      tb->SetForegroundColour(wxNullColour);
      // wxOSX keeps the white attributed title, so reset it natively
      // The native bezels of macOS 26 distort the bold italic labels (and the
      // classic white title stays), so the buttons are drawn as flat rounded
      // areas: grey, and highlighted in the accent colour when selected like in
      // the manual. wxOSX resets the frame on layout and the selection is changed
      // by the application code, so this is kept up to date in the idle UI update.
      if([(NSView*)tb->GetHandle() isKindOfClass:[NSButton class]])
      {
         tb->Bind(wxEVT_UPDATE_UI, [tb](wxUpdateUIEvent &event)
         {
            styleToggleButton(tb);
            fitButtonFrame(tb);
            event.Skip();
         });
         styleToggleButton(tb);
      }
   }

   wxStaticText *prev = NULL;
   wxWindowList children = w->GetChildren();
   for(wxWindowList::compatibility_iterator n = children.GetFirst(); n; n = n->GetNext())
   {
      wxWindow *child = n->GetData();
      adaptWindow(child);

      wxStaticText *st = wxDynamicCast(child, wxStaticText);
      if(st && prev && isTitleFragmentPair(prev, st))
      {
         joinTitle(prev, st);
         st = NULL;
      }
      prev = st;
   }
}


void MacAdaptLayout(wxWindow *root)
{
   adaptWindow(root);
   root->Layout();
}


// Dialogs in GUILayout.cpp have fixed sizes made for the smaller Windows fonts.
// Each top level window is adapted when it is shown first and dialogs are
// enlarged to the size their content needs.
class ShowEventFilter : public wxEventFilter
{
public:
   int FilterEvent(wxEvent &event) override
   {
      if(event.GetEventType() == wxEVT_SHOW && static_cast<wxShowEvent&>(event).IsShown())
      {
         if(wxDialog *dlg = wxDynamicCast(event.GetEventObject(), wxDialog))
         {
            MacAdaptLayout(dlg);
            if(wxSizer *sizer = dlg->GetSizer())
            {
               // plus a small bottom margin, the generated sizers end without border
               const wxSize need = sizer->ComputeFittingWindowSize(dlg) + wxSize(0, 10);
               const wxSize size = dlg->GetSize();
               if(need.x > size.x || need.y > size.y)
               {
                  dlg->SetMaxSize(wxDefaultSize);
                  dlg->SetSize(wxMax(need.x, size.x), wxMax(need.y, size.y));
                  dlg->Layout();
               }
            }
         }
      }
      return Event_Skip;
   }
};


void MacSetupStyle(void)
{
   MacForceLightAppearance();
   static ShowEventFilter s_filter;
   wxEvtHandler::AddFilter(&s_filter);
}


// The "Clear" item of the log window uses wxID_CLEAR, which wxOSX maps to the
// native "delete:" action. macOS enables it only if the focused control can delete,
// which the read only log text can't, so the item stays disabled. It is replaced
// by an item with an own id that clears the log text like wxLogFrame::OnClear().
void MacFixLogWindowMenu(wxLogWindow *log)
{
   wxFrame *frame = log ? log->GetFrame() : NULL;
   wxMenuBar *menubar = frame ? frame->GetMenuBar() : NULL;
   if(!menubar)
      return;

   wxMenu *menu = NULL;
   wxMenuItem *item = menubar->FindItem(wxID_CLEAR, &menu);
   if(!item || !menu)
      return;

   const int pos = menu->GetMenuItems().IndexOf(item);
   const wxString label = item->GetItemLabel();
   const wxString help = item->GetHelp();
   menu->Destroy(item);

   const int id = wxWindow::NewControlId();
   menu->Insert(pos, id, label, help);
   frame->Bind(wxEVT_MENU, [frame](wxCommandEvent &WXUNUSED(event))
   {
      for(wxWindowList::compatibility_iterator n = frame->GetChildren().GetFirst(); n; n = n->GetNext())
      {
         if(wxTextCtrl *text = wxDynamicCast(n->GetData(), wxTextCtrl))
         {
            text->Clear();
         }
      }
   }, id);
}
