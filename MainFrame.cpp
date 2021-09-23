//
// Created by lorenzo on 19/09/21.
//

#include "MainFrame.h"

MainFrame::MainFrame()
        : wxFrame(NULL, wxID_ANY, "Kernel image processing",wxDefaultPosition,wxSize(1280,720))
{
    panel = new wxPanel(this, -1);
    //create a column in the layout of the panel
    vbox = new wxBoxSizer(wxVERTICAL);

    //Appends a spacer child to the sizer.
    vbox->Add(-1, 10);

    wxBoxSizer *hbox3 = new wxBoxSizer(wxHORIZONTAL);

    drawPane = new wxImagePanel(panel,"./Image/Ferrari-sf21.jpeg",wxBITMAP_TYPE_JPEG);


    hbox3->Add(drawPane, 1, wxEXPAND);
    vbox->Add(hbox3, 1, wxLEFT | wxRIGHT | wxEXPAND,10);

    vbox->Add(-1, 25);

    wxBoxSizer *hbox4 = new wxBoxSizer(wxHORIZONTAL);
    //wxFlexGridSizer *fgs = new wxFlexGridSizer(1, 6, 5, 5);

//    fgs->Add(new wxButton(this, -1, wxT("1")), 0, wxEXPAND);
//    fgs->Add(new wxButton(this, -1, wxT("2")), 0, wxEXPAND);
//    fgs->Add(new wxButton(this, -1, wxT("3")), 0, wxEXPAND);
//    fgs->Add(new wxButton(this, -1, wxT("1")), 0, wxEXPAND);
//    fgs->Add(new wxButton(this, -1, wxT("2")), 0, wxEXPAND);
//    fgs->Add(new wxButton(this, -1, wxT("3")), 0, wxEXPAND);

    wxButton *btn1 = new wxButton(panel, wxID_ANY, wxT("Nessuno"));
    hbox4->Add(btn1, 1, wxEXPAND, 10);

    wxButton *btn2 = new wxButton(panel, wxID_ANY, wxT("Filtro1"));
    hbox4->Add(btn2, 1, wxEXPAND, 10);

    wxButton *btn3 = new wxButton(panel, wxID_ANY, wxT("Filtro2"));
    hbox4->Add(btn3, 1, wxEXPAND, 10);

    wxButton *btn4= new wxButton(panel, wxID_ANY, wxT("Filtro3"));
    hbox4->Add(btn4, 1, wxEXPAND, 10);

    wxButton *btn5 = new wxButton(panel, wxID_ANY, wxT("Filtro4"));
    hbox4->Add(btn5, 1, wxEXPAND, 10);

    wxButton *btn6 = new wxButton(panel, wxID_ANY, wxT("Filtro5"));
    hbox4->Add(btn6, 1, wxEXPAND, 10);

    //hbox4->Add(gs,1, wxEXPAND);
    vbox->Add(hbox4, 1, wxALIGN_CENTER|wxBottom,10);

    panel->SetSizer(vbox);

    LoadMenu();
    Bind(wxEVT_MENU, &MainFrame::OpenFile, this, ID_ImgLoad);
    Bind(wxEVT_MENU, &MainFrame::imageSave, this, ID_ImgSave);
}

void MainFrame::OpenFile(wxCommandEvent& event)
{
    wxFileDialog *OpenDialog = new wxFileDialog(
            this, _("Choose a file to open"), wxEmptyString, wxEmptyString,
            _("pictures (*.jpeg,*.png)|*.jpeg;*.png"),
            wxFD_OPEN, wxDefaultPosition);

    // Creates a "open file" dialog with 4 file types
    if (OpenDialog->ShowModal() == wxID_OK) // if the user click "Open" instead of "cancel"
    {
        CurrentDocPath = OpenDialog->GetPath();
        drawPane->changeImage(CurrentDocPath, wxBITMAP_TYPE_JPEG);
    }
}

void MainFrame::imageSave(wxCommandEvent& event){
    drawPane->saveImage();
}

void MainFrame::LoadMenu() {
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_ImgLoad, "&Open...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->Append(ID_ImgSave, "&Save...\tCtrl-H",
                     "Save the current Image");
    menuFile->AppendSeparator();
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    SetMenuBar( menuBar );
    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");

}
