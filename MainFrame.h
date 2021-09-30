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
    void btnEffectClick(wxCommandEvent& event);
    wxBitmap ImageScaler(wxSize s,wxImage &img);
    wxBitmapType getFormatFile(const wxString& fileName);

    wxString CurrentDocPath;
    void LoadMenu();

    enum{
        ID_ImgLoad = 1,
        ID_ImgSave = 2,
        Id_EffectNull,
        Id_Effect1,
        Id_Effect2,
        Id_Effect3,
        Id_Effect4,
        Id_Effect5,


    };
};


#endif //WXIMAGEKERNEL_MAINFRAME_H
