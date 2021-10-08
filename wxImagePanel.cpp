//
// Created by Pietro Bonechi on 18/09/21.
//

#include "wxImagePanel.h"
#include <iostream>
#include "./Utility/ApplicationUtility.h"



wxImagePanel::wxImagePanel(wxPanel* parent, wxString file, wxBitmapType format) :
        wxPanel(parent,wxID_ANY,wxDefaultPosition,wxSize(1280,600))
{
    // load the file... ideally add a check to see if loading was successful
    std::cout <<  this->image.LoadFile(file, format) << std::endl;

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
    resized = ImageScaler(this->GetSize(), image);
    int imgMargin = dc.GetSize().GetWidth() - resized.GetWidth();
    dc.DrawBitmap(resized,wxPoint(imgMargin/2,0),false);
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

void wxImagePanel::changeImage(wxString file, wxBitmapType format) {
    image.LoadFile(file, format);
    Refresh();
    Update();
}

void wxImagePanel::saveImage(wxString fileName, wxBitmapType format) {
    image.SaveFile(fileName, format);
}