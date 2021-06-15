#ifndef _1_wxposframe_h_H
#define _1_wxposframe_h_H

/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
 Achtung:                                                            
 Dieses Programmodul enthaelt eichrelevanten Programm Code          
 Bei Aenderungen von eichrelevantem Code muss GUI_SOFT_ID_STD in der Datei eich_defines.h      
 erhoeht werden und eine Neuzulassung veranlasst werden             
 
 Attention:
 This module contains approval relevant code                        
 If you change approval relevant code you have to increase GUI_SOFT_ID_STD in the    
 file eich_defines.h and you have to induce a new authorization     
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

**********************************************************************/

/**********************************************************************
*
*   Header %name:   wxposframe.h %
*   Instance:       1
*   Description:
*   %created_by:    albeg %
*   %date_created:  Fri Dez 18 14:30:41 2015 %
*
**********************************************************************/


#include <wx/frame.h>
#include <wx/toplevel.h>

#ifdef __GNUC__
#include <gtk/gtk.h>
#endif

enum
{
    // menu items
    // WES
    ID_WES_QUIT     = 10000,
    ID_WES_START    = 10001,
    ID_WES_STOP     = 10002,
    // Adjustment
    ID_CALI_GFAK    = 10003,
    ID_CALI_FILT    = 10004,
    ID_CALI_RESULT  = 10005,
    ID_CALI_GF_SET  = 10006,
    ID_CALI_TRALA   = 10007,
    ID_CALI_COUNTRY = 10008,
    ID_CALI_EXPERT  = 10009,
    ID_CALI_LINEAR  = 10010,
    ID_CALI_WSID    = 10011,
    // Buttons
    ID_CALI_START   = 11000,

    // id for sockets
    ID_WES_SERVER = 12000,
    ID_WES_SOCKET = 12001,
};

//class wxPlug : public wxWindow
//{
//
//public:
//    wxPlug();
//    virtual~wxPlug();
//
//    bool wxPlug(wxWindow *parent,
//                wxWindowID id, const wxString& titleName,
//                const wxPoint& pos = wxDefaultPosition,
//                const wxSize& size = wxDefaultSize,
//                long style = 0,
//                const wxString& name = wxPanelNameStr);
//
////  virtual void Hide();
////  virtual void Show();
//
//
//
//
//
//protected:
//    wxFrame m_topWnd;
//    GtkWidget* m_plug;
//
//private:
////  DECLARE_CLASS( wxPosFrame )
////  DECLARE_EVENT_TABLE()
//};
//#endif


class WXDLLIMPEXP_CORE wxPosFrame: public wxFrame
{
public:
    wxPosFrame();
    virtual~wxPosFrame();

    bool Create(wxWindow *parent,
                wxWindowID id, const wxString& titleName,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = 0,
                const wxString& name = wxPanelNameStr);

//  void SetShadowWidth( int WXUNUSED(w) ) { }
//  void SetBezelFace( int WXUNUSED(w) ) { }
//  int GetShadowWidth() const { return 0; };
//  int GetBezelFace() const { return 0; };
//
//  static wxVisualAttributes
//  GetClassDefaultAttributes(wxWindowVariant variant = wxWINDOW_VARIANT_NORMAL);
//
//  virtual wxVisualAttributes GetDefaultAttributes() const;

    // implementation
    void* getPosFrameHandle();


protected:
//  wxPlug* m_wxPlug;
    wxFrame* m_topWnd;
#ifdef __GNUC__
    GtkWidget* m_plug;
    GtkWidget* m_socket;
    GtkWidget* m_vbox;
    GtkWidget* m_ScrollView;
#endif

private:
    DECLARE_DYNAMIC_CLASS(wxPosFrame)
//  DECLARE_EVENT_TABLE()
};
#endif
