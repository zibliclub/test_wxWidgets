#include "app.h"
#include "../main_frame/main_frame.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
    MainFrame *mainFrame = new MainFrame("Testing Program");
    mainFrame->SetClientSize(800, 600);
    mainFrame->Center();
    mainFrame->Show();
    return true;
}