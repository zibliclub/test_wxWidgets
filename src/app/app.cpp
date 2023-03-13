#include "app.h"
#include "../main_frame/main_frame.h"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
    MainFrame *mainFrame = new MainFrame(wxT("Тестирующая программа"));
    mainFrame->Center();
    mainFrame->Show();
    

    return true;
}