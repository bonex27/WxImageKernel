
#include <iostream>
#include "wx/wx.h"
#include "MainFrame.h"

class MyApp: public wxApp{
public:
    virtual bool OnInit();
};

bool MyApp::OnInit()
{
    MainFrame *frame = new MainFrame;
    frame->Show(true);
    return true;
}

BEGIN_EVENT_TABLE(wxImagePanel, wxPanel)
    EVT_PAINT(wxImagePanel::paintEvent)
//Size event
    EVT_SIZE(wxImagePanel::OnSize)
END_EVENT_TABLE()

IMPLEMENT_APP(MyApp)