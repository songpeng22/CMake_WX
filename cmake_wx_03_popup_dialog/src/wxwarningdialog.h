#pragma once
#include "wx/wxprec.h"
#include <wx/wx.h>
#include <wx/utils.h>

class wxwarningdialog :
    public wxDialog
{
public:
    wxwarningdialog(wxWindow *parent,wxSize size, long style, wxString& title);
    virtual ~wxwarningdialog(void);

private:
    wxSize      m_size;
};
