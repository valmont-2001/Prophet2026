#include "types.h"


#include <wx/wx.h>
#include <wx/string.h>
#include <wx/file.h>
#include <wx/spinctrl.h>
#include <wx/slider.h>
#include "GUILayout.h"
#include "mapparam.h"
#include "main.h"
#include "stopwatch.h"
#include "proph2000.h"
#include <map>
#include <list>
#include "clickarea.h"
#include "keyboard.h"
#include "mapkeyboard.h"
#include "GUILayout.h"
#include "mapcopydlg.h"
#include "mapscaledvaldlg.h"
#include "mappanel.h"


//#define __DEACTIVATE_PARAM


typedef enum
{
   GUI_LOAD_MAP = 1000,
   GUI_SAVE_MAP,
   GUI_COPY
};

BEGIN_EVENT_TABLE(MyMapParam, wxPanel)
   EVT_RIGHT_DOWN(MyMapParam::OnMouseRightDown)
   EVT_MENU(GUI_COPY, MyMapParam::OnCopy)
   EVT_MENU(GUI_LOAD_MAP, MyMapParam::OnLoad)
   EVT_MENU(GUI_SAVE_MAP, MyMapParam::OnSave)
END_EVENT_TABLE()


MyMapParam::MyMapParam(wxWindow *parent, MyPanel *topframe, Proph2000 *proph, uint8_t map_u8) :
   wxPanel(parent, wxID_ANY),
   m_topframe(topframe), m_proph(proph), m_map_u8(map_u8), m_mapkeyboard(NULL)
{

   wxBoxSizer *vsizer = new wxBoxSizer( wxVERTICAL );
   // vsizer->AddSpacer(10); // vertical offset of MapPanel

   m_panel = new MapPanelImpl(this, topframe, proph, map_u8, this);
   vsizer->Add(m_panel);
   vsizer->AddSpacer(36); // vertical offset to keyboard

   wxBoxSizer *hsizer = new wxBoxSizer( wxHORIZONTAL );
   hsizer->AddSpacer(5); // horizontal offset of keyboard

   m_mapkeyboard = new MapKeyboard(this, wxID_ANY, wxDefaultPosition, wxSize(970, 100), this, m_proph, m_map_u8);
   hsizer->SetMinSize( wxSize( -1,140) ); 
   hsizer->Add(m_mapkeyboard,wxALIGN_BOTTOM);
 //  vsizer->Fit( this );  
   vsizer->Add(hsizer);
 
   SetSizer(vsizer);

   updateGUI();
}


MyMapParam::~MyMapParam()
{
   delete m_panel;
}


void MyMapParam::activateMap(uint8_t map_u8)
{
   m_map_u8 = map_u8;
   m_panel->activateMap(map_u8);
   if(m_mapkeyboard)
   {
      m_mapkeyboard->activateMap(map_u8);
   }
   //updateGUI();
}

void MyMapParam::updateGUI(void)
{
   m_panel->displaySettings();
   m_panel->updateGUI();
   m_mapkeyboard->Refresh(true);
}

void MyMapParam::makeActive(uint8_t map_u8)
{
   m_panel->makeActive(map_u8);
}

void MyMapParam::OnLoad(wxCommandEvent& event)
{
   wxString wildcards =
                 wxString::Format
                 (
                     wxT("Map files (*.p2m)|*.p2m"),
                     wxFileSelectorDefaultWildcardStr,
                     wxFileSelectorDefaultWildcardStr
                 );

   wxFileDialog indialog(this, wxT("Load map file"),
                     wxEmptyString, wxEmptyString, wildcards,
                     wxFD_OPEN);

   if (indialog.ShowModal() == wxID_OK)
   {
      FILE *mf;
      mf = fopen(indialog.GetPath().mb_str(), "rb");

      if(mf)
      {
         fread(&m_proph->m_mapparam_au8[m_map_u8], 1, MAP_PARAM_BYTES * 2, mf);
         fclose(mf);
         m_proph->updateStructsFromParamBytes();
         m_proph->remapMemory();
         m_topframe->updateGUI();
         if(m_topframe->getOnlineUpdateActive())
         {
            if(m_proph->transferMap2Proph(m_map_u8))
            {
               m_topframe->transferStarted();
            }
         }
      }
      else
      {
         wxMessageDialog edialog(this, wxT("Could not load map file"), wxT("Error"));
         edialog.ShowModal();
      }
   }
}

void MyMapParam::OnSave(wxCommandEvent& event)
{
   wxFileDialog outdialog(this,
                  wxT("Save map file"),
                  wxEmptyString,
                  wxEmptyString,
                  wxT("Map files (*.p2m)|*.p2m"),
                  wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
   if (outdialog.ShowModal() == wxID_OK)
   {
      wxString filen = outdialog.GetPath();
      if(filen.find(wxT(".p2m")) == wxString::npos)
      {
         filen += wxT(".p2m");
      }
      FILE *mf;
      mf = fopen(filen.mb_str(), "wb");

      if(mf)
      {
         fwrite(&m_proph->m_mapparam_au8[m_map_u8], 1, MAP_PARAM_BYTES * 2, mf);
         fclose(mf);
      }
      else
      {
         wxMessageDialog edialog(this, wxT("Could not save map file"), wxT("Error"));
         edialog.ShowModal();
      }
   }
}


void MyMapParam::OnCopy(wxCommandEvent& event)
{
   MapCopyDialog dlg(this, m_map_u8);

   dlg.ShowModal();

   if(dlg.getCopyFlag())
   {
      uint32_t i;
      for(i = 0; i < (MAP_PARAM_BYTES * 2); i++)
      {
         m_proph->m_mapparam_au8[dlg.getDestination()][i] = m_proph->m_mapparam_au8[m_map_u8][i];
      }

      m_proph->updateStructsFromParamBytes();

      if(dlg.getCopySoundMappingFlag())
      {
         uint8_t i;
         uint8_t s;
         uint8_t e;
         uint8_t o;

         if(m_map_u8 < 8)
         {
            s = 0;
            e = 8;
            o = 0;
         }
         else
         {
            o = 8;
            s = 8;
            e = 16;
         }
         for(i = s; i < e; i++)
         {
            switch(m_map_u8 - o)
            {
               case 0:
                  switch(dlg.getDestination() - o)
                  {
                     case 0:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map1 = m_proph->m_sound_param_as[i].val_s.hi_key_map1;
                        m_proph->m_sound_param_as[i].val_s.transpose_map1 = m_proph->m_sound_param_as[i].val_s.transpose_map1;
                        break;
                     case 1:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map2 = m_proph->m_sound_param_as[i].val_s.hi_key_map1;
                        m_proph->m_sound_param_as[i].val_s.transpose_map2 = m_proph->m_sound_param_as[i].val_s.transpose_map1;
                        break;
                     case 2:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map3 = m_proph->m_sound_param_as[i].val_s.hi_key_map1;
                        m_proph->m_sound_param_as[i].val_s.transpose_map3 = m_proph->m_sound_param_as[i].val_s.transpose_map1;
                        break;
                     case 3:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map4 = m_proph->m_sound_param_as[i].val_s.hi_key_map1;
                        m_proph->m_sound_param_as[i].val_s.transpose_map4 = m_proph->m_sound_param_as[i].val_s.transpose_map1;
                        break;
                     case 4:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map5 = m_proph->m_sound_param_as[i].val_s.hi_key_map1;
                        m_proph->m_sound_param_as[i].val_s.transpose_map5 = m_proph->m_sound_param_as[i].val_s.transpose_map1;
                        break;
                     case 5:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map6 = m_proph->m_sound_param_as[i].val_s.hi_key_map1;
                        m_proph->m_sound_param_as[i].val_s.transpose_map6 = m_proph->m_sound_param_as[i].val_s.transpose_map1;
                        break;
                     case 6:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map7 = m_proph->m_sound_param_as[i].val_s.hi_key_map1;
                        m_proph->m_sound_param_as[i].val_s.transpose_map7 = m_proph->m_sound_param_as[i].val_s.transpose_map1;
                        break;
                     case 7:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map8 = m_proph->m_sound_param_as[i].val_s.hi_key_map1;
                        m_proph->m_sound_param_as[i].val_s.transpose_map8 = m_proph->m_sound_param_as[i].val_s.transpose_map1;
                        break;
                  }
                  break;
               case 1:
                  switch(dlg.getDestination() - o)
                  {
                     case 0:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map1 = m_proph->m_sound_param_as[i].val_s.hi_key_map2;
                        m_proph->m_sound_param_as[i].val_s.transpose_map1 = m_proph->m_sound_param_as[i].val_s.transpose_map2;
                        break;
                     case 1:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map2 = m_proph->m_sound_param_as[i].val_s.hi_key_map2;
                        m_proph->m_sound_param_as[i].val_s.transpose_map2 = m_proph->m_sound_param_as[i].val_s.transpose_map2;
                        break;
                     case 2:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map3 = m_proph->m_sound_param_as[i].val_s.hi_key_map2;
                        m_proph->m_sound_param_as[i].val_s.transpose_map3 = m_proph->m_sound_param_as[i].val_s.transpose_map2;
                        break;
                     case 3:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map4 = m_proph->m_sound_param_as[i].val_s.hi_key_map2;
                        m_proph->m_sound_param_as[i].val_s.transpose_map4 = m_proph->m_sound_param_as[i].val_s.transpose_map2;
                        break;
                     case 4:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map5 = m_proph->m_sound_param_as[i].val_s.hi_key_map2;
                        m_proph->m_sound_param_as[i].val_s.transpose_map5 = m_proph->m_sound_param_as[i].val_s.transpose_map2;
                        break;
                     case 5:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map6 = m_proph->m_sound_param_as[i].val_s.hi_key_map2;
                        m_proph->m_sound_param_as[i].val_s.transpose_map6 = m_proph->m_sound_param_as[i].val_s.transpose_map2;
                        break;
                     case 6:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map7 = m_proph->m_sound_param_as[i].val_s.hi_key_map2;
                        m_proph->m_sound_param_as[i].val_s.transpose_map7 = m_proph->m_sound_param_as[i].val_s.transpose_map2;
                        break;
                     case 7:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map8 = m_proph->m_sound_param_as[i].val_s.hi_key_map2;
                        m_proph->m_sound_param_as[i].val_s.transpose_map8 = m_proph->m_sound_param_as[i].val_s.transpose_map2;
                        break;
                  }
                  break;
               case 2:
                  switch(dlg.getDestination() - o)
                  {
                     case 0:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map1 = m_proph->m_sound_param_as[i].val_s.hi_key_map3;
                        m_proph->m_sound_param_as[i].val_s.transpose_map1 = m_proph->m_sound_param_as[i].val_s.transpose_map3;
                        break;
                     case 1:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map2 = m_proph->m_sound_param_as[i].val_s.hi_key_map3;
                        m_proph->m_sound_param_as[i].val_s.transpose_map2 = m_proph->m_sound_param_as[i].val_s.transpose_map3;
                        break;
                     case 2:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map3 = m_proph->m_sound_param_as[i].val_s.hi_key_map3;
                        m_proph->m_sound_param_as[i].val_s.transpose_map3 = m_proph->m_sound_param_as[i].val_s.transpose_map3;
                        break;
                     case 3:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map4 = m_proph->m_sound_param_as[i].val_s.hi_key_map3;
                        m_proph->m_sound_param_as[i].val_s.transpose_map4 = m_proph->m_sound_param_as[i].val_s.transpose_map3;
                        break;
                     case 4:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map5 = m_proph->m_sound_param_as[i].val_s.hi_key_map3;
                        m_proph->m_sound_param_as[i].val_s.transpose_map5 = m_proph->m_sound_param_as[i].val_s.transpose_map3;
                        break;
                     case 5:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map6 = m_proph->m_sound_param_as[i].val_s.hi_key_map3;
                        m_proph->m_sound_param_as[i].val_s.transpose_map6 = m_proph->m_sound_param_as[i].val_s.transpose_map3;
                        break;
                     case 6:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map7 = m_proph->m_sound_param_as[i].val_s.hi_key_map3;
                        m_proph->m_sound_param_as[i].val_s.transpose_map7 = m_proph->m_sound_param_as[i].val_s.transpose_map3;
                        break;
                     case 7:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map8 = m_proph->m_sound_param_as[i].val_s.hi_key_map3;
                        m_proph->m_sound_param_as[i].val_s.transpose_map8 = m_proph->m_sound_param_as[i].val_s.transpose_map3;
                        break;
                  }
                  break;
               case 3:
                  switch(dlg.getDestination() - o)
                  {
                     case 0:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map1 = m_proph->m_sound_param_as[i].val_s.hi_key_map4;
                        m_proph->m_sound_param_as[i].val_s.transpose_map1 = m_proph->m_sound_param_as[i].val_s.transpose_map4;
                        break;
                     case 1:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map2 = m_proph->m_sound_param_as[i].val_s.hi_key_map4;
                        m_proph->m_sound_param_as[i].val_s.transpose_map2 = m_proph->m_sound_param_as[i].val_s.transpose_map4;
                        break;
                     case 2:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map3 = m_proph->m_sound_param_as[i].val_s.hi_key_map4;
                        m_proph->m_sound_param_as[i].val_s.transpose_map3 = m_proph->m_sound_param_as[i].val_s.transpose_map4;
                        break;
                     case 3:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map4 = m_proph->m_sound_param_as[i].val_s.hi_key_map4;
                        m_proph->m_sound_param_as[i].val_s.transpose_map4 = m_proph->m_sound_param_as[i].val_s.transpose_map4;
                        break;
                     case 4:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map5 = m_proph->m_sound_param_as[i].val_s.hi_key_map4;
                        m_proph->m_sound_param_as[i].val_s.transpose_map5 = m_proph->m_sound_param_as[i].val_s.transpose_map4;
                        break;
                     case 5:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map6 = m_proph->m_sound_param_as[i].val_s.hi_key_map4;
                        m_proph->m_sound_param_as[i].val_s.transpose_map6 = m_proph->m_sound_param_as[i].val_s.transpose_map4;
                        break;
                     case 6:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map7 = m_proph->m_sound_param_as[i].val_s.hi_key_map4;
                        m_proph->m_sound_param_as[i].val_s.transpose_map7 = m_proph->m_sound_param_as[i].val_s.transpose_map4;
                        break;
                     case 7:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map8 = m_proph->m_sound_param_as[i].val_s.hi_key_map4;
                        m_proph->m_sound_param_as[i].val_s.transpose_map8 = m_proph->m_sound_param_as[i].val_s.transpose_map4;
                        break;
                  }
                  break;
               case 4:
                  switch(dlg.getDestination() - o)
                  {
                     case 0:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map1 = m_proph->m_sound_param_as[i].val_s.hi_key_map5;
                        m_proph->m_sound_param_as[i].val_s.transpose_map1 = m_proph->m_sound_param_as[i].val_s.transpose_map5;
                        break;
                     case 1:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map2 = m_proph->m_sound_param_as[i].val_s.hi_key_map5;
                        m_proph->m_sound_param_as[i].val_s.transpose_map2 = m_proph->m_sound_param_as[i].val_s.transpose_map5;
                        break;
                     case 2:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map3 = m_proph->m_sound_param_as[i].val_s.hi_key_map5;
                        m_proph->m_sound_param_as[i].val_s.transpose_map3 = m_proph->m_sound_param_as[i].val_s.transpose_map5;
                        break;
                     case 3:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map4 = m_proph->m_sound_param_as[i].val_s.hi_key_map5;
                        m_proph->m_sound_param_as[i].val_s.transpose_map4 = m_proph->m_sound_param_as[i].val_s.transpose_map5;
                        break;
                     case 4:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map5 = m_proph->m_sound_param_as[i].val_s.hi_key_map5;
                        m_proph->m_sound_param_as[i].val_s.transpose_map5 = m_proph->m_sound_param_as[i].val_s.transpose_map5;
                        break;
                     case 5:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map6 = m_proph->m_sound_param_as[i].val_s.hi_key_map5;
                        m_proph->m_sound_param_as[i].val_s.transpose_map6 = m_proph->m_sound_param_as[i].val_s.transpose_map5;
                        break;
                     case 6:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map7 = m_proph->m_sound_param_as[i].val_s.hi_key_map5;
                        m_proph->m_sound_param_as[i].val_s.transpose_map7 = m_proph->m_sound_param_as[i].val_s.transpose_map5;
                        break;
                     case 7:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map8 = m_proph->m_sound_param_as[i].val_s.hi_key_map5;
                        m_proph->m_sound_param_as[i].val_s.transpose_map8 = m_proph->m_sound_param_as[i].val_s.transpose_map5;
                        break;
                  }
                  break;
               case 5:
                  switch(dlg.getDestination() - o)
                  {
                     case 0:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map1 = m_proph->m_sound_param_as[i].val_s.hi_key_map6;
                        m_proph->m_sound_param_as[i].val_s.transpose_map1 = m_proph->m_sound_param_as[i].val_s.transpose_map6;
                        break;
                     case 1:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map2 = m_proph->m_sound_param_as[i].val_s.hi_key_map6;
                        m_proph->m_sound_param_as[i].val_s.transpose_map2 = m_proph->m_sound_param_as[i].val_s.transpose_map6;
                        break;
                     case 2:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map3 = m_proph->m_sound_param_as[i].val_s.hi_key_map6;
                        m_proph->m_sound_param_as[i].val_s.transpose_map3 = m_proph->m_sound_param_as[i].val_s.transpose_map6;
                        break;
                     case 3:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map4 = m_proph->m_sound_param_as[i].val_s.hi_key_map6;
                        m_proph->m_sound_param_as[i].val_s.transpose_map4 = m_proph->m_sound_param_as[i].val_s.transpose_map6;
                        break;
                     case 4:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map5 = m_proph->m_sound_param_as[i].val_s.hi_key_map6;
                        m_proph->m_sound_param_as[i].val_s.transpose_map5 = m_proph->m_sound_param_as[i].val_s.transpose_map6;
                        break;
                     case 5:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map6 = m_proph->m_sound_param_as[i].val_s.hi_key_map6;
                        m_proph->m_sound_param_as[i].val_s.transpose_map6 = m_proph->m_sound_param_as[i].val_s.transpose_map6;
                        break;
                     case 6:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map7 = m_proph->m_sound_param_as[i].val_s.hi_key_map6;
                        m_proph->m_sound_param_as[i].val_s.transpose_map7 = m_proph->m_sound_param_as[i].val_s.transpose_map6;
                        break;
                     case 7:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map8 = m_proph->m_sound_param_as[i].val_s.hi_key_map6;
                        m_proph->m_sound_param_as[i].val_s.transpose_map8 = m_proph->m_sound_param_as[i].val_s.transpose_map6;
                        break;
                  }
                  break;
               case 6:
                  switch(dlg.getDestination() - o)
                  {
                     case 0:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map1 = m_proph->m_sound_param_as[i].val_s.hi_key_map7;
                        m_proph->m_sound_param_as[i].val_s.transpose_map1 = m_proph->m_sound_param_as[i].val_s.transpose_map7;
                        break;
                     case 1:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map2 = m_proph->m_sound_param_as[i].val_s.hi_key_map7;
                        m_proph->m_sound_param_as[i].val_s.transpose_map2 = m_proph->m_sound_param_as[i].val_s.transpose_map7;
                        break;
                     case 2:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map3 = m_proph->m_sound_param_as[i].val_s.hi_key_map7;
                        m_proph->m_sound_param_as[i].val_s.transpose_map3 = m_proph->m_sound_param_as[i].val_s.transpose_map7;
                        break;
                     case 3:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map4 = m_proph->m_sound_param_as[i].val_s.hi_key_map7;
                        m_proph->m_sound_param_as[i].val_s.transpose_map4 = m_proph->m_sound_param_as[i].val_s.transpose_map7;
                        break;
                     case 4:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map5 = m_proph->m_sound_param_as[i].val_s.hi_key_map7;
                        m_proph->m_sound_param_as[i].val_s.transpose_map5 = m_proph->m_sound_param_as[i].val_s.transpose_map7;
                        break;
                     case 5:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map6 = m_proph->m_sound_param_as[i].val_s.hi_key_map7;
                        m_proph->m_sound_param_as[i].val_s.transpose_map6 = m_proph->m_sound_param_as[i].val_s.transpose_map7;
                        break;
                     case 6:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map7 = m_proph->m_sound_param_as[i].val_s.hi_key_map7;
                        m_proph->m_sound_param_as[i].val_s.transpose_map7 = m_proph->m_sound_param_as[i].val_s.transpose_map7;
                        break;
                     case 7:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map8 = m_proph->m_sound_param_as[i].val_s.hi_key_map7;
                        m_proph->m_sound_param_as[i].val_s.transpose_map8 = m_proph->m_sound_param_as[i].val_s.transpose_map7;
                        break;
                  }
                  break;
               case 7:
                  switch(dlg.getDestination() - o)
                  {
                     case 0:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map1 = m_proph->m_sound_param_as[i].val_s.hi_key_map8;
                        m_proph->m_sound_param_as[i].val_s.transpose_map1 = m_proph->m_sound_param_as[i].val_s.transpose_map8;
                        break;
                     case 1:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map2 = m_proph->m_sound_param_as[i].val_s.hi_key_map8;
                        m_proph->m_sound_param_as[i].val_s.transpose_map2 = m_proph->m_sound_param_as[i].val_s.transpose_map8;
                        break;
                     case 2:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map3 = m_proph->m_sound_param_as[i].val_s.hi_key_map8;
                        m_proph->m_sound_param_as[i].val_s.transpose_map3 = m_proph->m_sound_param_as[i].val_s.transpose_map8;
                        break;
                     case 3:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map4 = m_proph->m_sound_param_as[i].val_s.hi_key_map8;
                        m_proph->m_sound_param_as[i].val_s.transpose_map4 = m_proph->m_sound_param_as[i].val_s.transpose_map8;
                        break;
                     case 4:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map5 = m_proph->m_sound_param_as[i].val_s.hi_key_map8;
                        m_proph->m_sound_param_as[i].val_s.transpose_map5 = m_proph->m_sound_param_as[i].val_s.transpose_map8;
                        break;
                     case 5:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map6 = m_proph->m_sound_param_as[i].val_s.hi_key_map8;
                        m_proph->m_sound_param_as[i].val_s.transpose_map6 = m_proph->m_sound_param_as[i].val_s.transpose_map8;
                        break;
                     case 6:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map7 = m_proph->m_sound_param_as[i].val_s.hi_key_map8;
                        m_proph->m_sound_param_as[i].val_s.transpose_map7 = m_proph->m_sound_param_as[i].val_s.transpose_map8;
                        break;
                     case 7:
                        m_proph->m_sound_param_as[i].val_s.hi_key_map8 = m_proph->m_sound_param_as[i].val_s.hi_key_map8;
                        m_proph->m_sound_param_as[i].val_s.transpose_map8 = m_proph->m_sound_param_as[i].val_s.transpose_map8;
                        break;
                  }
                  break;
            }
         }
      }

      m_proph->updateParamBytesFromStruct();

      
      m_topframe->updateGUI();

      if(m_topframe->getOnlineUpdateActive())
      {
         if(m_proph->transferMap2Proph(dlg.getDestination() - 1))
         {
            m_topframe->transferStarted();
         }
      }
   }
}

void MyMapParam::transferStarted(void)
{
}

void MyMapParam::transferEnded(void)
{
}

void MyMapParam::showScaledSampleValues(uint8_t sample_id)
{
   MapScaleValuesDlg dlg(this, wxID_ANY, m_proph, sample_id, m_map_u8);
   dlg.ShowModal();
}

void MyMapParam::OnMouseRightDown(wxMouseEvent &event)
{
   //PopupMenu(m_menu, event.GetPosition());
}
