#ifndef __PROGRESSWINH__
#define __PROGRESSWINH__

#include <wx/wx.h>
#include <wx/gauge.h>

// Petite fenetre de progression des transferts.
//  - Cachee tant qu'aucun transfert n'est en cours (contrairement a wxProgressDialog de wxWidgets 3,
//    qui s'affiche des sa creation et bloque l'application).
//  - Non bloquante pour le reste de l'interface.
//  - Peut etre appelee depuis le fil de transfert: les actions sont executees dans le fil principal.
class ProgressWindow : public wxEvtHandler
{
public:
   ProgressWindow(const wxString &title, int maximum);   // a creer dans le fil principal
   ~ProgressWindow();

   bool Update(int value, const wxString &message = wxEmptyString);
   bool Show(bool show = true);
   bool Hide() { return Show(false); }

private:
   void doUpdate(int value, const wxString &message);
   void doShow(bool show);

   wxDialog *m_dialog;
   wxStaticText *m_text;
   wxGauge *m_gauge;
   int m_maximum;
   bool m_positioned;
};

#endif
