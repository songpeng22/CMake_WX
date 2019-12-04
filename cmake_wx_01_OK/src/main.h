#include <wx/wx.h> 

class CKroemApp : public wxApp
{
    bool OnInit()
    {
        //wxSring 
        //Find vs find in wxString
        wxString        strDir = _T("ago - Angola");
        int nIndex = -2;
        // searching (return starting index, or -1 if not found)
        nIndex = strDir.Find(_T("go"));
        wxLogDebug("Find index:%d.\n",nIndex);
        // find first n characters of sz
        nIndex = strDir.find(_T("goabc"),0,2);
        wxLogDebug("find index:%d.\n",nIndex);

        //wxArrayString

        //wxDateTime
        wxDateTime  oldDateTime = wxDateTime::Now();
        wxDateTime  currentTime = wxDateTime::Now();
        currentTime += wxTimeSpan(0,0,1,0);
        if(!currentTime.IsLaterThan(oldDateTime)){
            wxLogDebug(wxString::Format(wxT("!Later currentTime::Hour=%i Minute=%i Second=%i"),currentTime.GetHour(),currentTime.GetMinute(),currentTime.GetSecond()));
            wxLogDebug(wxString::Format(wxT("!Later oldDateTime::Hour=%i Minute=%i Second=%i"),oldDateTime.GetHour(),oldDateTime.GetMinute(),oldDateTime.GetSecond()));
        }
        else{
            wxLogDebug(wxString::Format(wxT("Later currentTime::Hour=%i Minute=%i Second=%i"),currentTime.GetHour(),currentTime.GetMinute(),currentTime.GetSecond()));
            wxLogDebug(wxString::Format(wxT("Later oldDateTime::Hour=%i Minute=%i Second=%i"),oldDateTime.GetHour(),oldDateTime.GetMinute(),oldDateTime.GetSecond()));
        }

        //wxFrame
        wxFrame* frame = new wxFrame(NULL, wxID_ANY, "Our First App"); 
        frame->Show();
        return true;
    }
 
 
};


