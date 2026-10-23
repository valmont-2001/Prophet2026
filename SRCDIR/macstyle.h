#ifndef __MACSTYLEH__
#define __MACSTYLEH__

#ifdef __WXMAC__
class wxWindow;
class wxLogWindow;

void MacSetupStyle(void);
void MacAdaptLayout(wxWindow *root);
void MacFixLogWindowMenu(wxLogWindow *log);
#endif

#endif
