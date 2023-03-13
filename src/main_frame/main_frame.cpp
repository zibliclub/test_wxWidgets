#include "main_frame.h"
#include "../create_matrix_frame/create_matrix_frame.h"
#include <wx/icon.h>

enum
{
    ID_Create_Matrix,
    ID_Open_From_A_File
};

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(ID_Create_Matrix, MainFrame::CreateMatrix)
    EVT_MENU(ID_Open_From_A_File, MainFrame::OpenFile)
END_EVENT_TABLE()

MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title)
{
    SetIcon(wxICON(icon_frame));

    wxPanel *panel_left = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(150, 370));
    panel_left->SetBackgroundColour(wxColor(240, 244, 245));

    wxFont buttonFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    wxFont bigTextFont(20, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

    wxButton *button_open = new wxButton(panel_left, ID_Open_From_A_File, wxT("Открыть"), wxPoint(-1, 25), wxSize(110, 40), wxBORDER_THEME);

    button_open->Bind(wxEVT_BUTTON, MainFrame::OpenFile, this);
    button_open->SetBackgroundColour(*wxWHITE);
    button_open->SetFont(buttonFont);
    button_open->Center(wxHORIZONTAL);

    wxButton *button_create = new wxButton(panel_left, ID_Create_Matrix, wxT("Создать"), wxPoint(-1, 80), wxSize(110, 40), wxBORDER_THEME);

    button_create->Bind(wxEVT_BUTTON, MainFrame::CreateMatrix, this);
    button_create->SetBackgroundColour(*wxWHITE);
    button_create->SetFont(buttonFont);
    button_create->Center(wxHORIZONTAL);

    wxPanel *panel_right = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(550, 370));
    panel_right->SetBackgroundColour(wxColor(*wxWHITE));

    wxStaticText *bigText = new wxStaticText(panel_right, wxID_ANY, wxT("Индивидуальное задание №5"), wxPoint(20, 20));
    wxStaticText *smallText = new wxStaticText(panel_right, wxID_ANY,
                                               wxT("Отсортировать строки матрицы по неубыванию абсолютных величин сумм их элементов.\nСортировка бинарными включениями."),
                                               wxPoint(20, 70));

    bigText->SetFont(bigTextFont);

    wxPNGHandler *handler = new wxPNGHandler;
    wxImage::AddHandler(handler);
    wxStaticBitmap *image = new wxStaticBitmap(panel_right, wxID_ANY, wxBitmap("../images/sort_matrix.png", wxBITMAP_TYPE_PNG), wxPoint(20, 150));

    wxBoxSizer *sizer = new wxBoxSizer(wxHORIZONTAL);
    sizer->Add(panel_left, 0, wxEXPAND);
    sizer->Add(panel_right, 1, wxEXPAND);

    this->SetSizerAndFit(sizer);
}

void MainFrame::OpenFile(wxCommandEvent &WXUNUSED(event))
{
    wxFileDialog *OpenDialog = new wxFileDialog(
        this, _(wxT("Выберите файл с матрицей")), wxEmptyString, wxEmptyString,
        ("Text files (*.txt)|*.txt"), wxFD_OPEN);

    if (OpenDialog->ShowModal() == wxID_OK)
    {
        CurrentDocPath = OpenDialog->GetPath();
        wxLogMessage(wxT("Путь к выбранному файлу: %s"), CurrentDocPath);
    }
}

void MainFrame::CreateMatrix(wxCommandEvent &WXUNUSED(event))
{
    CreateMatrixFrame *createMatrixFrame = new CreateMatrixFrame(wxT("Создание матрицы"));
    createMatrixFrame->Center();
    createMatrixFrame->Show();
}