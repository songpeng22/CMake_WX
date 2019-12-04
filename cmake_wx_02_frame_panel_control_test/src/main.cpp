#include "main.h"
#include "wxposframe.h"

IMPLEMENT_APP(CKroemApp)

bool CKroemApp::OnInit()
{
#if 1
	CKroemFrame* frame = new CKroemFrame(NULL, wxID_ANY, "First App"); 
	frame->Show();
#elif 0
    CKroemFrame* frame = new CKroemFrame(wxPoint(0, 0), 2, 2);
	frame->Show();
#elif 1
	wxPosFrame* frame = new wxPosFrame;
	frame->Create(NULL,wxID_ANY,"First App",wxPoint(0, 0),wxSize(800,600), wxNO_BORDER | wxSTAY_ON_TOP,wxPanelNameStr); 
	frame->Enable(true);
	frame->Show();
#endif

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
    //
    wxArrayString   m_countryArray;
    int index = 0;
    int retIndex = -1;
    wxString        strCountry;
    // country
    char          m_calibCountry[10];
    // order must equal to escaleProperty !!
    static const wxChar *strIsoCountryShortNames[] =
    {
        _T("ago - Angola"),
        _T("alb - Albania"),
        _T("are - United Arab Emirates"),
        _T("arg - Argentina"),
        _T("arm - Armenia"),
        _T("aus - Australia"),
        _T("aut - Austria"),
        _T("aze - Azerbaijan"),
        _T("bel - Belgium"),
        _T("bgr - Bulgaria"),
        _T("bhr - Bahrain"),
        _T("bih - Bosnia and Herzegovina"),
        _T("blr - Belarus"),
        _T("bra - Brazil"),
        _T("can - Canada"),
        _T("che - Switzerland"),
        _T("chl - Chile"),
        _T("chn - China"),
        _T("col - Colombia"),
        _T("cri - Costa Rica"),
        _T("cyp - Cyprus"),
        _T("cze - Czech Republic"),
        _T("deu - Germany"),
        _T("dnk - Denmark"),
        _T("dom - Dominican Republic"),
        _T("dza - Algeria"),
        _T("ecu - Ecuador"),
        _T("egy - Egypt"),
        _T("esp - Spain"),
        _T("est - Estonia"),
        _T("fin - Finland"),
        _T("fra - France"),
        _T("gab - Gabon"),
        _T("gbr - United Kingdom"),
        _T("geo - Georgia"),
        _T("gin - Guinea"),
        _T("grc - Greece"),
        _T("gtm - Guatemala"),
        _T("hrv - Croatia"),
        _T("hun - Hungary"),
        _T("idn - Indonesia"),
        _T("ind - India"),
        _T("irl - Ireland"),
        _T("irn - Iran"),
        _T("irq - Iraq"),
        _T("isl - Iceland"),
        _T("isr - Israel"),
        _T("ita - Italy"),
        _T("jor - Jordan"),
        _T("kaz - Kazakhstan"),
        _T("ken - Kenya"),
        _T("kgz - Kyrgyzstan"),
        _T("kor - Republic of Korea"),
        _T("kwt - Kuwait"),
        _T("lbn - Lebanon"),
        _T("lby - Libya"),
        _T("ltu - Lithuania"),
        _T("lux - Luxembourg"),
        _T("lva - Latvia"),
        _T("mar - Morocco"),
        _T("mda - Moldova"),
        _T("mex - Mexico"),
        _T("mkd - Macedonia"),
        _T("mlt - Malta"),
        _T("mne - Montenegro"),
        _T("mng - Mongolia"),
        _T("mus - Mauritius"),
        _T("mys - Malaysia"),
        _T("nam - Namibia"),
        _T("ncl - New Caledonia"),
        _T("nga - Nigeria"),
        _T("nld - Netherlands"),
        _T("nor - Norway"),
        _T("nzl - New Zealand"),
        _T("omn - Oman"),
        _T("pak - Pakistan"),
        _T("pan - Panama"),
        _T("per - Peru"),
        _T("phl - Philippines"),
        _T("png - Papua New Guinea"),
        _T("pol - Poland"),
        _T("prk - Korea, Democratic"),
        _T("prt - Portugal"),
        _T("pry - Paraguay"),
        _T("qat - Qatar"),
        _T("rou - Romania"),
        _T("rus - Russian Federation"),
        _T("sau - Saudi Arabia"),
        _T("sdn - Sudan"),
        _T("sgp - Singapore"),
        _T("srb - Serbia"),
        _T("svk - Slovakia"),
        _T("svn - Slovenia"),
        _T("swe - Sweden"),
        _T("tha - Thailand"),
        _T("tun - Tunisia"),
        _T("tur - Turkey"),
        _T("ukr - Ukraine"),
        _T("ury - Uruguay"),
        _T("usa - United States"),
        _T("uzb - Uzbekistan"),
        _T("ven - Venezuela"),
        _T("vnm - Viet Nam"),
        _T("zaf - South Africa"),
        _T("zmb - Zambia"),
    };

    for ( index = 0; index < WXSIZEOF(strIsoCountryShortNames); index++ )
    {
        // add string to array
        m_countryArray.Add(strIsoCountryShortNames[index]);

        // search for index
        strCountry = m_countryArray[index];
        if (strCountry.Find(m_calibCountry) == 0)
            retIndex = index;
    }
    wxStaticText    *labelCountry = new wxStaticText ( m_panelCali, wxID_STATIC, wxT("Country:"), wxDefaultPosition,  wxSize(100,-1), 0);
    wxComboBox      *m_ComboCaliCountry = new wxComboBox ( m_panelCali, ID_CALI_COUNTRY, m_countryArray[0], wxDefaultPosition, wxSize(350,20), m_countryArray, wxCB_DROPDOWN, wxDefaultValidator, wxT("Set country"));
    m_ComboCaliCountry->SetEditable(false);
    m_ComboCaliCountry->SetSelection(index);
#endif

	// set mouse events only for main operator display
    Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&CKroemFrame::OnMouseEvent);
    Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&CKroemFrame::OnMouseEvent);
    Connect(wxEVT_RIGHT_UP,(wxObjectEventFunction)&CKroemFrame::OnMouseEvent);

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
