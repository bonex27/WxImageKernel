//
// Created by lorenzo on 19/09/21.
//

#include "MainFrame.h"
#include <wx/tokenzr.h>

MainFrame::MainFrame()
        : wxFrame(NULL, wxID_ANY, "Kernel image processing",wxDefaultPosition,wxSize(1280,720))
{

    panel = new wxPanel(this,wxID_ANY,wxDefaultPosition,wxSize(1280,720));
    //create a column in the layout of the panel
    vbox = new wxBoxSizer(wxVERTICAL);

    drawPane = new wxImagePanel(panel,"./Image/Ferrari-sf21.jpeg",wxBITMAP_TYPE_JPEG);

    vbox->Add(drawPane, 1, wxALIGN_CENTER,0);

    wxBoxSizer *hbox4 = new wxBoxSizer(wxHORIZONTAL);




    wxButton *btn1 = new wxButton(panel, Id_EffectNull, wxT("Nessuno"));
    btn1->Bind(wxEVT_BUTTON, &MainFrame::btnEffectClick, this, Id_EffectNull);
    hbox4->Add(btn1, 1, wxEXPAND, 10);

    wxButton *btn2 = new wxButton(panel, Id_Effect1, wxT("Filtro1"));
    btn2->Bind(wxEVT_BUTTON, &MainFrame::btnEffectClick, this, Id_Effect1);
    hbox4->Add(btn2, 1, wxEXPAND, 10);

    wxButton *btn3 = new wxButton(panel, Id_Effect2, wxT("Filtro2"));
    btn3->Bind(wxEVT_BUTTON, &MainFrame::btnEffectClick, this, Id_Effect2);
    hbox4->Add(btn3, 1, wxEXPAND, 10);

    wxButton *btn4= new wxButton(panel, Id_Effect3, wxT("Filtro3"));
    btn4->Bind(wxEVT_BUTTON, &MainFrame::btnEffectClick, this, Id_Effect3);
    hbox4->Add(btn4, 1, wxEXPAND, 10);

    wxButton *btn5 = new wxButton(panel, Id_Effect4, wxT("Filtro4"));
    btn5->Bind(wxEVT_BUTTON, &MainFrame::btnEffectClick, this, Id_Effect4);
    hbox4->Add(btn5, 1, wxEXPAND, 10);

    wxButton *btn6 = new wxButton(panel, Id_Effect5, wxT("Filtro5"));
    btn6->Bind(wxEVT_BUTTON, &MainFrame::btnEffectClick, this, Id_Effect5);
    hbox4->Add(btn6, 1, wxEXPAND, 10);

    //hbox4->Add(gs,1, wxEXPAND);
    vbox->Add(hbox4, 1, wxALIGN_CENTER|wxBottom,10);

    panel->SetSizer(vbox);

    LoadMenu();
    Bind(wxEVT_MENU, &MainFrame::OpenFile, this, ID_ImgLoad);
    Bind(wxEVT_MENU, &MainFrame::imageSave, this, ID_ImgSave);

    //Bind  button

}

void MainFrame::OpenFile(wxCommandEvent& event)
{
    wxFileDialog *OpenDialog = new wxFileDialog(
            this, _("Choose a file to open"), wxEmptyString, wxEmptyString,
            _("Pictures (*.jpeg,*.png,*.jpg)|*.jpeg;*.png;*.jpg"),
            wxFD_OPEN, wxDefaultPosition);

    // Creates a "open file" dialog with 4 file types
    if (OpenDialog->ShowModal() == wxID_OK) // if the user click "Open" instead of "cancel"
    {
        wxString fileName = OpenDialog->GetFilename();
        wxBitmapType formatFile = getFormatFile(fileName);
        CurrentDocPath = OpenDialog->GetPath();
        drawPane->changeImage(CurrentDocPath, formatFile);
    }
}

void MainFrame::imageSave(wxCommandEvent& event){
    wxFileDialog *saveDialog = new wxFileDialog(
            this, _("Save the current image"), wxEmptyString, wxEmptyString,
            _("JPEG files (*jpg)|*.jpg|PNG files (*png)|*.png"),
            wxFD_SAVE, wxDefaultPosition);
    if (saveDialog->ShowModal() == wxID_OK){
        wxString fileName = saveDialog->GetFilename();
        wxBitmapType formatFile = getFormatFile(fileName);
        CurrentDocPath = saveDialog->GetPath();
        drawPane->saveImage(CurrentDocPath, formatFile);
    }
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

void MainFrame::btnEffectClick(wxCommandEvent &event) {
    switch (event.GetId()) {
        case Id_EffectNull:
            break;
        case Id_Effect1:
            break;

    }
}

/**
 * Function that returns the format of a file
 * @param fileName name of the file in this format (test.jpg, image.png)
 * @return a wxBitmapType like wxBITMAP_TYPE_JPEG, wxBITMAP_TYPE_PNG
 */
wxBitmapType MainFrame::getFormatFile(const wxString &fileName) {
    wxStringTokenizer tokenizer(fileName, ".");
    wxString formatTokenized = "jpg"; //default format to save images

    while (tokenizer.HasMoreTokens())
        formatTokenized = tokenizer.GetNextToken();   //split the given string

    wxBitmapType formatFile = wxBITMAP_TYPE_JPEG;
    if (formatTokenized == "png")
        formatFile = wxBITMAP_TYPE_PNG;
    else if (formatTokenized == "bmp")
        formatFile = wxBITMAP_TYPE_BMP;
    //other format files...
    return formatFile;
}
