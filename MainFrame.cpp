//
// Created by lorenzo on 19/09/21.
//

#include "MainFrame.h"

MainFrame::MainFrame()
        : wxFrame(NULL, wxID_ANY, "Hello World")
{
    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    drawPane = new wxImagePanel;
    sizer->Add(drawPane, 1, wxEXPAND);

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
    Bind(wxEVT_MENU, &MainFrame::OpenFile, this, ID_ImgLoad);

}

void MainFrame::OpenFile(wxCommandEvent& WXUNUSED(event))
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