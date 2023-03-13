#include "create_matrix_frame.h"
#include <wx/icon.h>

enum
{
    ID_Fill_Manually,
    ID_Fill_Random
};

BEGIN_EVENT_TABLE(CreateMatrixFrame, wxFrame)
    EVT_MENU(ID_Fill_Manually, CreateMatrixFrame::FillManually)
    EVT_MENU(ID_Fill_Random, CreateMatrixFrame::FillRandom)
END_EVENT_TABLE()

CreateMatrixFrame::CreateMatrixFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title)
{
    SetIcon(wxICON(icon_frame));

    wxFont buttonFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    wxFont bigTextFont(16, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

    wxPanel *panel_up_void = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(0, 70));
    panel_up_void->SetBackgroundColour(wxColor(240, 244, 245));

    wxPanel *panel_up_left = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(250, 70));
    panel_up_left->SetBackgroundColour(wxColor(240, 244, 245));

    wxStaticText *createText = new wxStaticText(panel_up_left, wxID_ANY, wxT("Заполнить матрицу:"), wxPoint(-1, -1));
    createText->SetFont(bigTextFont);
    createText->Center(wxVERTICAL);
    createText->Center(wxHORIZONTAL);

    wxPanel *panel_up_right = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(250, 70));
    panel_up_right->SetBackgroundColour(wxColor(240, 244, 245));

    wxButton *button_fill_manually = new wxButton(panel_up_right, ID_Fill_Manually, wxT("Вручную"), wxPoint(10, -1), wxSize(110, 40), wxBORDER_THEME);

    button_fill_manually->Bind(wxEVT_BUTTON, CreateMatrixFrame::FillManually, this);
    button_fill_manually->SetBackgroundColour(*wxWHITE);
    button_fill_manually->SetFont(buttonFont);
    button_fill_manually->Center(wxVERTICAL);

    wxButton *button_fill_random = new wxButton(panel_up_right, ID_Fill_Random, wxT("Случайно"), wxPoint(130, -1), wxSize(110, 40), wxBORDER_THEME);

    button_fill_random->Bind(wxEVT_BUTTON, CreateMatrixFrame::FillRandom, this);
    button_fill_random->SetBackgroundColour(*wxWHITE);
    button_fill_random->SetFont(buttonFont);
    button_fill_random->Center(wxVERTICAL);

    wxBoxSizer *sizer_up = new wxBoxSizer(wxHORIZONTAL);
    sizer_up->Add(panel_up_void, 1, wxEXPAND);
    sizer_up->Add(panel_up_left, 0, wxEXPAND);
    sizer_up->Add(panel_up_right, 0, wxEXPAND);

    wxPanel *panel_right = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(500, 400));
    panel_right->SetBackgroundColour(wxColor(*wxWHITE));

    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(sizer_up, 0, wxEXPAND);
    sizer->Add(panel_right, 1, wxEXPAND);

    this->SetSizerAndFit(sizer);
}

void CreateMatrixFrame::FillManually(wxCommandEvent &WXUNUSED(event))
{

}

void CreateMatrixFrame::FillRandom(wxCommandEvent &WXUNUSED(event))
{

}