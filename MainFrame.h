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
    wxBoxSizer* sizer;
private:
    void OpenFile(wxCommandEvent& event);
    wxString CurrentDocPath;
    enum{
        ID_ImgLoad = 1
    };
};


#endif //WXIMAGEKERNEL_MAINFRAME_H
