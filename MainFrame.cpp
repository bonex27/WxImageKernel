//
// Created by lorenzo on 19/09/21.
//

#include "MainFrame.h"

MainFrame::MainFrame()
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
    Bind(wxEVT_MENU, &MainFrame::OpenFile, this, ID_ImgLoad);

}

void MainFrame::OpenFile(wxCommandEvent& WXUNUSED(event))
{
    wxFileDialog *OpenDialog = new wxFileDialog(
            this, _("Choose a file to open"), wxEmptyString, wxEmptyString,
            _("pictures (*.jpeg,*.png)|*.jpeg;*.png"),
            wxFD_OPEN, wxDefaultPosition);

    // Creates a "open file" dialog with 4 file types
    if (OpenDialog->ShowModal() == wxID_OK) // if the user click "Open" instead of "cancel"
    {

        CurrentDocPath = OpenDialog->GetPath();
        drawPane = new wxImagePanel(this, CurrentDocPath, wxBITMAP_TYPE_JPEG);
        sizer = new wxBoxSizer(wxHORIZONTAL);
        sizer->Add(drawPane, 1, wxEXPAND);
        this->SetSizer(sizer);

    }
}