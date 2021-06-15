#include "main.h"
#include "wxposframe.h"

IMPLEMENT_APP(CKroemApp)

bool CKroemApp::OnInit()
{
	CKroemFrame* frame = new CKroemFrame(NULL, wxID_ANY, "First App"); 
	frame->Show();

    return true;
}

BEGIN_EVENT_TABLE(CKroemFrame, wxFrame)
		EVT_PAINT(CKroemFrame::OnPaint)
		EVT_ERASE_BACKGROUND(CKroemFrame::OnEraseBackground)
        EVT_SHOW(CKroemFrame::OnShow)
END_EVENT_TABLE()

CKroemFrame::CKroemFrame(wxWindow *parent,
				wxWindowID id,
				const wxString& title)
: wxFrame(parent, id, title)
{
    //Frame
#if defined( MODIFY_MENU )
	// Create a menu bar
    wxMenu *fileMenu = new wxMenu;

    // The "About" item should be in the help menu
    wxMenu *helpMenu = new wxMenu;
    helpMenu->Append(wxID_ABOUT, wxT("&About...\tF1"), wxT("Show about dialog"));

    fileMenu->Append(wxID_EXIT, wxT("E&xit\tAlt-X"),  wxT("Quit this program"));

    // Now append the freshly created menu to the menu bar...
    wxMenuBar *menuBar = new wxMenuBar();
    menuBar->Append(fileMenu, wxT("&File"));
    menuBar->Append(helpMenu, wxT("&Help"));

    // ... and attach this menu bar to the frame
    SetMenuBar(menuBar);
#endif
	//MessageBox
/*
	wxString ErrorText = _T("Cannot initialize Basic Class: ");
    wxMessageBox(ErrorText,_T("Bizerba Error"),wxOK|wxICON_INFORMATION|wxSTAY_ON_TOP,parent);
*/
#if defined( MODIFY_PANEL )
    //book
    m_book = new wxNotebook(this, wxID_ANY, wxPoint(0,0), wxSize(200,150));
    //panel
	wxPanel *panel = new wxPanel(m_book, wxID_ANY, wxPoint(0,0), wxSize(200,150));
    wxPanel *m_panelCali = new wxPanel(m_book, wxID_ANY, wxPoint(0,0), wxSize(200,150));
    //add page
    m_book->AddPage(panel, wxT("WES"));
    m_book->AddPage(m_panelCali, wxT("Adjustment"));
#endif

#if 1
    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *hbox1 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *hbox2 = new wxBoxSizer(wxHORIZONTAL);

    wxButton *ok = new wxButton(panel, -1, wxT("Ok"));
    wxButton *cancel = new wxButton(panel, -1, wxT("Cancel"));

    hbox1->Add(new wxPanel(panel, -1));
    vbox->Add(hbox1, 1, wxEXPAND);


    hbox2->Add(ok);
    hbox2->Add(cancel);

    vbox->Add(hbox2, 0, wxALIGN_RIGHT | wxRIGHT | wxBOTTOM, 10);
    panel->SetSizer(vbox);
#elif 1
    //
    wxColour col1, col2;
    col1.Set(wxT("#ff0000"));
    col2.Set(wxT("#00ff00"));

    panel->SetBackgroundColour(col1);
    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

    wxPanel *midPan = new wxPanel(panel, wxID_ANY);
    midPan->SetBackgroundColour(col2);

    vbox->Add(midPan, 1, wxEXPAND | wxALL, 3);
    panel->SetSizer(vbox);
#endif

}

CKroemFrame::CKroemFrame(wxPoint pos, float sizeFactorH, float sizeFactorW) 
: wxFrame(NULL, wxID_ANY, wxT("PosScale"),
    pos, wxSize((int)(700 * sizeFactorW), (int)(400 * sizeFactorH)), wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN | wxSYSTEM_MENU | wxSTAY_ON_TOP)
{
	
}

void CKroemFrame::OnShow(wxShowEvent& event)
{
	//normal message,with dialog
//	wxLogMessage("CKroemFrame::OnShow");
	//debug message , not in release
	wxLogDebug("CKroemFrame::OnShow");



}

void CKroemFrame::OnEraseBackground(wxEraseEvent& event)
{
	wxLogDebug("CKroemFrame::OnEraseBackground");
}

void CKroemFrame::OnPaint(wxPaintEvent &event)
{
	wxLogDebug("CKroemFrame::OnPaint");
}

void CKroemFrame::OnMouseEvent(wxMouseEvent& event)
{
	static int nClickCount = 0;
	wxLogDebug("CKroemFrame::OnMouseEvent:%d.",++nClickCount);

	if(event.LeftDown())
    {
		wxLogDebug("CKroemFrame::OnMouseEvent:LeftDown().");
        m_TimeMouseLeftDown=wxDateTime::Now();
    }

    // Feld gedrueckt oder losgelassen
    if((event.LeftUp()) || event.RightUp())
    {
		wxLogDebug("CKroemFrame::OnMouseEvent:LeftUp().");

		wxTimeSpan diffTime = m_TimeMouseLeftDown.Subtract(wxDateTime::Now()).Abs();
		wxLogDebug("CKroemFrame::OnMouseEvent:%f .",diffTime.GetMilliseconds().ToDouble());
/**/
		// mouse click > 1,5 sec
		if ( (event.LeftUp() && (diffTime.GetMilliseconds() > 1500)) || event.RightUp())
		{
			wxLogDebug("CKroemFrame::OnMouseEvent:%f > 1500 .",diffTime.GetMilliseconds().ToDouble());
		}

	}
}
