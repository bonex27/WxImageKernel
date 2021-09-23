//
// Created by lorenzo on 19/09/21.
//

#ifndef WXIMAGEKERNEL_MAINFRAME_H
#define WXIMAGEKERNEL_MAINFRAME_H


#include "wxImagePanel.h"


class MainFrame : public wxFrame {
public:
    MainFrame();

    wxImagePanel * drawPane;
    wxPanel *panel;
    wxBoxSizer *vbox;
    wxBoxSizer *hbox;

private:
    void OpenFile(wxCommandEvent& event);
    void imageSave(wxCommandEvent& event);
    wxString CurrentDocPath;
    void LoadMenu();

    enum{
        ID_ImgLoad = 1,
        ID_ImgSave = 2
    };
};


#endif //WXIMAGEKERNEL_MAINFRAME_H
