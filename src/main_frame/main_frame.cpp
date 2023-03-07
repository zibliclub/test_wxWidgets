#include "main_frame.h"

enum
{
    ID_Create_Matrix,
    ID_Open_From_A_File
};

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(ID_Open_From_A_File, MainFrame::OpenFile)
END_EVENT_TABLE()


MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title)
{
    wxMenu *menuFile = new wxMenu;
    wxMenu *menuNewMatrix = new wxMenu;
    menuFile->Append(wxID_ANY, "New Matrix...\t Ctrl+N", menuNewMatrix, "Open the file with the matrix or create a new one");
    menuNewMatrix->Append(ID_Create_Matrix, "Create Matrix", "Create a new matrix (fill manually or with random values)");
    menuNewMatrix->Append(ID_Open_From_A_File, "Open from a file", "Open the file with the matrix (binary or typed)");

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");

    SetMenuBar(menuBar);

    wxPanel *panel = new wxPanel(this);

    CreateStatusBar();
}

void MainFrame::OpenFile(wxCommandEvent &WXUNUSED(event))
{
    wxFileDialog *OpenDialog = new wxFileDialog(
        this, _("Choose a file to open"), wxEmptyString, wxEmptyString,
        ("Text files (*.txt)|*.txt"), wxFD_OPEN);

    if (OpenDialog->ShowModal() == wxID_OK)
    {
        CurrentDocPath = OpenDialog->GetPath();
        wxLogMessage("The path of the selected file: %s", CurrentDocPath);
    }
}