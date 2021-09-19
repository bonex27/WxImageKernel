//
// Created by Pietro Bonechi on 18/09/21.
//

#ifndef WXIMAGEKERNEL_WXIMAGEPANEL_H
#define WXIMAGEKERNEL_WXIMAGEPANEL_H

#include "wx/wx.h"


#endif //WXIMAGEKERNEL_WXIMAGEPANEL_H

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