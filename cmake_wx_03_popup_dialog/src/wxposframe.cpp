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



/*********************************************************************
*
*   Header %name:   wxposframe.cpp %
*   Instance:       1
*   Description:
*   %created_by:    albeg %
*   %date_created:  Fri Dez 18 14:30:41 2015 %
*
**********************************************************************/
#include <wxposframe.h>

#include "wxwarningdialog.h"

#ifdef __GNUC__
extern bool g_rikonps;
#endif

IMPLEMENT_DYNAMIC_CLASS(wxPosFrame, wxFrame)
BEGIN_EVENT_TABLE(wxPosFrame, wxFrame)
    EVT_BUTTON (ID_BUTTON_01, wxPosFrame::Button01)
END_EVENT_TABLE()

#ifdef __GNUC__
static void embedded(GtkPlug *plug, gpointer user_data)
{
    printf("embedded() --> embedded signal was emitted\n");
}
#endif

wxPosFrame::wxPosFrame()
{
#ifdef __GNUC__
    m_plug = NULL;
#endif
}


wxPosFrame::~wxPosFrame()
{

}


bool wxPosFrame::Create(wxWindow *parent, wxWindowID id, const wxString& titleName, const wxPoint& pos, const wxSize& size, long style, const wxString& name)
{
    bool retval = false;

#ifdef __GNUC__
    if (g_rikonps)
    {
        /////////////////////// Standolone

        //    GtkWidget* mWnd = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        //    gtk_window_set_default_size(GTK_WINDOW(mWnd), size.x, size.y);
        ////  g_object_ref(panel1);

        //    m_plug = gtk_plug_new(NULL);
        ////  gtk_container_add(GTK_CONTAINER(mWnd), m_plug);
        //    GdkColor bgColor;
        //    gdk_color_parse("#0000FF", &bgColor);
        ////  g_object_ref(panel1);
        //
        //
        //    GtkWidget * panel1 = gtk_fixed_new();
        //    gtk_widget_modify_bg(panel1, GTK_STATE_NORMAL, &bgColor);
        //    gtk_container_add(GTK_CONTAINER(m_plug), panel1);
        //    //  gtk_widget_set_size_request(panel1, 490, 390);
        ////  g_object_ref(panel1);
        //
        //
        //    GtkWidget *button1 = gtk_button_new_with_label("Button1");
        //    gtk_widget_set_name(button1, "Button1");
        //    gtk_fixed_put(GTK_FIXED(panel1), button1, 50, 50);
        //    gtk_widget_set_size_request(button1, 100, 100);
        ////  g_object_ref(button1);
        //
        //    gtk_widget_show_all( m_plug );
        //
        /////////////////////////// standalonge end
        m_plug = gtk_plug_new(NULL);
        m_widget = m_plug;
        g_object_ref(m_widget);
        g_signal_connect(G_OBJECT(GTK_PLUG(m_plug)), "embedded", G_CALLBACK(embedded), NULL);

        retval = wxFrame::Create(NULL, id, titleName, pos, size, 0, name);
    }
    else
    {
        retval =  wxFrame::Create(parent, id, titleName, pos, size, style, name);
    }
#else
    retval =  wxFrame::Create(parent, id, titleName, pos, size, style, name);
#endif
    m_Button1 = new wxButton( this, ID_BUTTON_01,  wxT("popup dialog"), wxDefaultPosition, wxSize(100,50) );

    return retval;
}

void* wxPosFrame::getPosFrameHandle()
{
#ifdef __GNUC__
    int plugID = 0;
    if (m_plug)
    {
        plugID = gtk_plug_get_id(GTK_PLUG(m_plug));
        printf("wxPosFrame::getPosFrameHandle() --> PlugID: %d. Wnd size: %d x %d\n", plugID, GetSize().GetWidth(), GetSize().GetHeight());
    }
    return (void*)plugID;
#else
    return GetHandle();
#endif
}

void wxPosFrame::Button01(wxCommandEvent& event)
{
    if (event.GetId() == ID_BUTTON_01)
    {
        wxLogDebug("wxPosFrame::Button01");
        wxString title = wxT("warning dialog");
        wxwarningdialog *AdwLogDialog = new wxwarningdialog(this,wxSize(600,400),wxSTAY_ON_TOP,title  );
        if (AdwLogDialog->ShowModal() == wxID_OK)
        {
        }
        delete AdwLogDialog;
    }
}
