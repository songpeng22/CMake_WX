#include <wx/wx.h> 
#include <wx/notebook.h> 

#define MODIFY_MENU					1
#define MODIFY_PANEL				1

class CKroemApp : public wxApp
{
    bool OnInit();
};

class CKroemFrame : public wxFrame
{
public:
	CKroemFrame(wxWindow *parent,
				wxWindowID id,
				const wxString& title);
	CKroemFrame(wxPoint pos, float sizeFactorH, float sizeFactorW);
public:

	// any class wishing to process wxWidgets events must use this macro
    DECLARE_EVENT_TABLE()
	//Show
	// On Paint Methode
    void OnPaint(wxPaintEvent & WXUNUSED (event));
    void OnEraseBackground(wxEraseEvent& WXUNUSED(event));
	void OnShow(wxShowEvent& event);
	//Mouse
	void OnMouseEvent(wxMouseEvent& event);
	wxDateTime m_TimeMouseLeftDown;
public:
#if defined( MODIFY_PANEL )
	wxNotebook    *m_book;
#endif
};

