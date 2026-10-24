#include "types.h"
//#include <unistd.h>
#include <wx/wx.h>
//#include <wx/spinctrl.h>
#include "GUILayout.h"
#include "about.h"
#include "main.h"


About::About(wxWindow* parent, wxWindowID id):
   AboutDlg(parent)
{
   m_build_date_label->SetLabel(__DATE__);
   m_version_label->SetLabel(VERSION_STR);
   m_copyright_text->SetLabel(wxT("(C) by Marius Goebel"));
}


About::~About()
{
}
