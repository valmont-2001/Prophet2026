#include "progresswin.h"

ProgressWindow::ProgressWindow(const wxString &title, int maximum)
   : m_dialog(NULL), m_text(NULL), m_gauge(NULL), m_maximum(maximum), m_positioned(false)
{
   m_dialog = new wxDialog(NULL, wxID_ANY, title, wxDefaultPosition, wxDefaultSize,
                           wxCAPTION | wxSTAY_ON_TOP);
   wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
   m_text = new wxStaticText(m_dialog, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(380, -1));
   m_gauge = new wxGauge(m_dialog, wxID_ANY, maximum, wxDefaultPosition, wxSize(380, 18));
   sizer->Add(m_text, 0, wxALL | wxEXPAND, 10);
   sizer->Add(m_gauge, 0, wxLEFT | wxRIGHT | wxBOTTOM | wxEXPAND, 10);
   m_dialog->SetSizerAndFit(sizer);
   m_dialog->Hide();
}


ProgressWindow::~ProgressWindow()
{
   if(m_dialog)
   {
      m_dialog->Destroy();
   }
}


bool ProgressWindow::Update(int value, const wxString &message)
{
   if(wxIsMainThread())
   {
      doUpdate(value, message);
   }
   else
   {
      wxString msg(message.c_str());   // copie independante pour le fil principal
      CallAfter([this, value, msg]() { doUpdate(value, msg); });
   }
   return true;
}


bool ProgressWindow::Show(bool show)
{
   if(wxIsMainThread())
   {
      doShow(show);
   }
   else
   {
      CallAfter([this, show]() { doShow(show); });
   }
   return true;
}


void ProgressWindow::doUpdate(int value, const wxString &message)
{
   if(value < 0)
   {
      value = 0;
   }
   if(value > m_maximum)
   {
      value = m_maximum;
   }
   m_gauge->SetValue(value);
   if(!message.IsEmpty())
   {
      m_text->SetLabel(message);
   }
}


void ProgressWindow::doShow(bool show)
{
   if(show && !m_positioned)
   {
      m_dialog->CentreOnScreen();
      m_positioned = true;
   }
   m_dialog->Show(show);
   if(show)
   {
      m_dialog->Raise();
   }
}
