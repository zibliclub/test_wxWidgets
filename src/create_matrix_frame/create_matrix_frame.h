#ifndef CREATE_MATRIX_FRAME_H
#define CREATE_MATRIX_FRAME_H

#include <wx/wx.h>

class CreateMatrixFrame : public wxFrame
{
private:
public:
    CreateMatrixFrame(const wxString &);

    void FillManually(wxCommandEvent &);
    void FillRandom(wxCommandEvent &);

    DECLARE_EVENT_TABLE()
};

#endif