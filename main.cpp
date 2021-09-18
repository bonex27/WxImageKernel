
#include <iostream>
#include "wx/wx.h"


class MyApp: public wxApp
{

    //wxFrame *frame;
    //wxImagePanel * drawPane;
    //wxButton *HelloWorld;
public:
    virtual bool OnInit();
};

class wxImagePanel : public wxPanel{
    wxImage image;
    wxBitmap resized;
    int w, h;

public:
    wxImagePanel(wxFrame* parent, wxString file, wxBitmapType format);
    wxImagePanel() {}

    void paintEvent(wxPaintEvent & evt);
    void paintNow();
    void OnSize(wxSizeEvent& event);
    void render(wxDC& dc);



DECLARE_EVENT_TABLE()

};
BEGIN_EVENT_TABLE(wxImagePanel, wxPanel)
                EVT_PAINT(wxImagePanel::paintEvent)
//Size event
                EVT_SIZE(wxImagePanel::OnSize)
END_EVENT_TABLE()
class MyFrame : public wxFrame
{
public:
    MyFrame();
    wxImagePanel * drawPane;
private:
    void OpenFile(wxCommandEvent& event);
    wxString CurrentDocPath;
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
    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    //drawPane = new wxImagePanel;
    //sizer->Add(drawPane, 1, wxEXPAND);

    //this->SetSizer(sizer);
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_ImgLoad, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    SetMenuBar( menuBar );
    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");
    Bind(wxEVT_MENU, &MyFrame::OpenFile, this, ID_ImgLoad);
}

void MyFrame::OpenFile(wxCommandEvent& WXUNUSED(event))
{
    wxFileDialog *OpenDialog = new wxFileDialog(
            this, _("Choose a file to open"), wxEmptyString, wxEmptyString,
            _("Text files (*.txt)|*.txt|C++ Source Files (*.cpp, *.cxx)|*.cpp;*.cxx|C Source files (*.c)|*.c|C header files (*.h)|*.h"),
                      wxFD_OPEN, wxDefaultPosition);

    // Creates a "open file" dialog with 4 file types
    if (OpenDialog->ShowModal() == wxID_OK) // if the user click "Open" instead of "cancel"
    {
        CurrentDocPath = OpenDialog->GetPath();
        std::cout << CurrentDocPath << std::endl;
    }
}
wxImagePanel::wxImagePanel(wxFrame* parent, wxString file, wxBitmapType format) :
        wxPanel(parent)
{
    // load the file... ideally add a check to see if loading was successful
    image.LoadFile(file, format);
    w = -1;
    h = -1;
}

/*
 * Called by the system of by wxWidgets when the panel needs
 * to be redrawn. You can also trigger this call by
 * calling Refresh()/Update().
 */

void wxImagePanel::paintEvent(wxPaintEvent & evt)
{
    // depending on your system you may need to look at double-buffered dcs
    wxPaintDC dc(this);
    render(dc);
}

/*
 * Alternatively, you can use a clientDC to paint on the panel
 * at any time. Using this generally does not free you from
 * catching paint events, since it is possible that e.g. the window
 * manager throws away your drawing when the window comes to the
 * background, and expects you will redraw it when the window comes
 * back (by sending a paint event).
 */
void wxImagePanel::paintNow()
{
    // depending on your system you may need to look at double-buffered dcs
    wxClientDC dc(this);
    render(dc);
}

/*
 * Here we do the actual rendering. I put it in a separate
 * method so that it can work no matter what type of DC
 * (e.g. wxPaintDC or wxClientDC) is used.
 */
void wxImagePanel::render(wxDC&  dc)
{
    int neww, newh;
    dc.GetSize( &neww, &newh );

    if( neww != w || newh != h )
    {
        resized = wxBitmap( image.Scale( neww, newh /*, wxIMAGE_QUALITY_HIGH*/ ) );
        w = neww;
        h = newh;
        dc.DrawBitmap( resized, 0, 0, false );
    }else{
        dc.DrawBitmap( resized, 0, 0, false );
    }
}

/*
 * Here we call refresh to tell the panel to draw itself again.
 * So when the user resizes the image panel the image should be resized too.
 */
void wxImagePanel::OnSize(wxSizeEvent& event){
    Refresh();
    //skip the event.
    event.Skip();
}




IMPLEMENT_APP(MyApp)