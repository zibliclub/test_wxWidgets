#ifndef MAIN_FRAME_H
#define MAIN_FRAME_H

#include <wx/wx.h>

class MainFrame : public wxFrame
{
private:
public:
    MainFrame(const wxString &);
    void OpenFile(wxCommandEvent &);
    void CreateMatrix(wxCommandEvent &);

    wxString CurrentDocPath;

    DECLARE_EVENT_TABLE()
};

#endif