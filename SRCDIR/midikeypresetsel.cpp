#include "types.h"

#include <wx/wx.h>

#include "GUILayout.h"
#include "main.h"
#include <list>
#include <map>
using namespace std;
#include "midikeypresetsel.h"
#include "midikeyboarddlg.h"



MIDIKeyPresetSelImpl::MIDIKeyPresetSelImpl(wxWindow *parent, MIDIKeyboardDlg *panel) :
   MIDIKeyboardPresetSelection(parent),
   m_panel(panel)
{
   deselectAllPresetButtons();
   m_select_preset1->SetValue(true);
}


MIDIKeyPresetSelImpl::~MIDIKeyPresetSelImpl()
{
}

void MIDIKeyPresetSelImpl::selectPreset1()
{
   deselectAllPresetButtons();
   m_select_preset1->SetValue(true);
}

void MIDIKeyPresetSelImpl::selectPreset2()
{
   deselectAllPresetButtons();
   m_select_preset2->SetValue(true);
}

void MIDIKeyPresetSelImpl::selectPreset3()
{
   deselectAllPresetButtons();
   m_select_preset3->SetValue(true);
}

void MIDIKeyPresetSelImpl::selectPreset4()
{
   deselectAllPresetButtons();
   m_select_preset4->SetValue(true);
}

void MIDIKeyPresetSelImpl::selectPreset5()
{
   deselectAllPresetButtons();
   m_select_preset5->SetValue(true);
}

void MIDIKeyPresetSelImpl::selectPreset6()
{
   deselectAllPresetButtons();
   m_select_preset6->SetValue(true);
}

void MIDIKeyPresetSelImpl::selectPreset7()
{
   deselectAllPresetButtons();
   m_select_preset7->SetValue(true);
}

void MIDIKeyPresetSelImpl::selectPreset8()
{
   deselectAllPresetButtons();
   m_select_preset8->SetValue(true);
}

void MIDIKeyPresetSelImpl::selectPreset9()
{
   deselectAllPresetButtons();
   m_select_preset9->SetValue(true);
}

void MIDIKeyPresetSelImpl::selectPreset10()
{
   deselectAllPresetButtons();
   m_select_preset10->SetValue(true);
}

void MIDIKeyPresetSelImpl::selectPreset11()
{
   deselectAllPresetButtons();
   m_select_preset11->SetValue(true);
}

void MIDIKeyPresetSelImpl::selectPreset12()
{
   deselectAllPresetButtons();
   m_select_preset12->SetValue(true);
}

void MIDIKeyPresetSelImpl::OnSelectPreset1(wxCommandEvent& event)
{
   deselectAllPresetButtons();
   m_select_preset1->SetValue(true);
   m_panel->presetSelected(0);
}

void MIDIKeyPresetSelImpl::OnSelectPreset2(wxCommandEvent& event)
{
   deselectAllPresetButtons();
   m_select_preset2->SetValue(true);
   m_panel->presetSelected(1);
}

void MIDIKeyPresetSelImpl::OnSelectPreset3(wxCommandEvent& event)
{
   deselectAllPresetButtons();
   m_select_preset3->SetValue(true);
   m_panel->presetSelected(2);
}

void MIDIKeyPresetSelImpl::OnSelectPreset4(wxCommandEvent& event)
{
   deselectAllPresetButtons();
   m_select_preset4->SetValue(true);
   m_panel->presetSelected(3);
}

void MIDIKeyPresetSelImpl::OnSelectPreset5(wxCommandEvent& event)
{
   deselectAllPresetButtons();
   m_select_preset5->SetValue(true);
   m_panel->presetSelected(4);
}

void MIDIKeyPresetSelImpl::OnSelectPreset6(wxCommandEvent& event)
{
   deselectAllPresetButtons();
   m_select_preset6->SetValue(true);
   m_panel->presetSelected(5);
}

void MIDIKeyPresetSelImpl::OnSelectPreset7(wxCommandEvent& event)
{
   deselectAllPresetButtons();
   m_select_preset7->SetValue(true);
   m_panel->presetSelected(6);
}

void MIDIKeyPresetSelImpl::OnSelectPreset8(wxCommandEvent& event)
{
   deselectAllPresetButtons();
   m_select_preset8->SetValue(true);
   m_panel->presetSelected(7);
}

void MIDIKeyPresetSelImpl::OnSelectPreset9(wxCommandEvent& event)
{
   deselectAllPresetButtons();
   m_select_preset9->SetValue(true);
   m_panel->presetSelected(8);
}

void MIDIKeyPresetSelImpl::OnSelectPreset10(wxCommandEvent& event)
{
   deselectAllPresetButtons();
   m_select_preset10->SetValue(true);
   m_panel->presetSelected(9);
}

void MIDIKeyPresetSelImpl::OnSelectPreset11(wxCommandEvent& event)
{
   deselectAllPresetButtons();
   m_select_preset11->SetValue(true);
   m_panel->presetSelected(10);
}

void MIDIKeyPresetSelImpl::OnSelectPreset12(wxCommandEvent& event)
{
   deselectAllPresetButtons();
   m_select_preset12->SetValue(true);
   m_panel->presetSelected(11);
}

void MIDIKeyPresetSelImpl::deselectAllPresetButtons(void)
{
   m_select_preset1->SetValue(false);
   m_select_preset2->SetValue(false);
   m_select_preset3->SetValue(false);
   m_select_preset4->SetValue(false);
   m_select_preset5->SetValue(false);
   m_select_preset6->SetValue(false);
   m_select_preset7->SetValue(false);
   m_select_preset8->SetValue(false);
   m_select_preset9->SetValue(false);
   m_select_preset10->SetValue(false);
   m_select_preset11->SetValue(false);
   m_select_preset12->SetValue(false);
}



