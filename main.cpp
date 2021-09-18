#include <wx/wx.h>
#include <wx/sizer.h>



class MyApp: public wxApp
{

    //wxFrame *frame;
    //wxImagePanel * drawPane;
    //wxButton *HelloWorld;
public:
    virtual bool OnInit();


};


class MyFrame : public wxFrame
{
public:
    MyFrame();
private:
    void OnImgLoad(wxCommandEvent& event);
};
enum
{
    ID_ImgLoad = 1
};
bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame();
    frame->Show(true);
    return true;
}
MyFrame::MyFrame()
        : wxFrame(NULL, wxID_ANY, "Hello World")
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_ImgLoad, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    SetMenuBar( menuBar );
    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");
    Bind(wxEVT_MENU, &MyFrame::OnImgLoad, this, ID_ImgLoad);
}
void MyFrame::OnImgLoad(wxCommandEvent &event) {
    wxLogMessage("Hello world from wxWidgets!");
}






IMPLEMENT_APP(MyApp)