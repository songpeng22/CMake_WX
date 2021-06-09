#include "wx/wxprec.h"

#include "wx/statline.h"
#include "wx/minifram.h"
#include "wx/settings.h"

#include "wxwarningdialog.h"

wxwarningdialog::wxwarningdialog(wxWindow *parent, wxSize size, long style, wxString& title)
                 : wxDialog(NULL, -1, title, wxPoint(800, 800),size,wxNO_BORDER | style )
{
    m_size = size;  //wxSize(470,170)
    wxArrayString  adwStrings;

    wxString OneAdwString;
    wxString partnerAdwString;
    char szAdwString[100];
    int i;
    int iStrLen;


}

wxwarningdialog::~wxwarningdialog(void)
{
}
