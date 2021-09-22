//
// Created by Pietro Bonechi on 18/09/21.
//

#include "wxImagePanel.h"
#include <iostream>

wxImagePanel::wxImagePanel(wxPanel* parent, wxString file, wxBitmapType format) :
        wxPanel(parent)
{
    // load the file... ideally add a check to see if loading was successful
//    std::cout << this->image.LoadFile(file, format) << std::endl;
    std::cout <<  this->img.LoadFile(file,format) << std::endl;
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
//    int neww, newh;
//    dc.GetSize( &neww, &newh );
//
//    if( neww != w || newh != h )
//    {
//        resized = wxBitmap( image.Size( wxSize(neww,newh), wxPoint(0,0) , 29, 31, 32 ) );
//        w = neww;
//        h = newh;
//        dc.DrawBitmap( resized, 0, 0, false);
//    }else{
//        dc.DrawBitmap( resized, 0, 0, false );
//    }
    float fWScale = 1.0f;   // horizontal scaling factor
    float fHScale = 1.0f;   // vertical scaling factor
    int iImageH = -1;       // the bitmap's height
    int iImageW = -1;       // the bitmap's width
    int iThisH = -1;        // the panel's height
    int iThisW = -1;        // the panel's width

    // how is the bitmap's actual size?
    iImageH = img.GetHeight();
    iImageW = img.GetWidth();

    //Panel size
    GetSize(&iThisW, &iThisH);

    // no division by zero !
    if( ( iImageH> 0 ) && ( iImageW> 0 ) )
    {
        // calculate the scaling factor for the 2 dimensions
        fHScale = (float) iThisH / (float) iImageH;
        fWScale = (float) iThisW / (float) iImageW;

        // always take the smaller scaling factor,
        // so that the bitmap will always fit into the panel's paintable area
        if(fHScale < fWScale)
        {
            fWScale = fHScale;
        }
        else
        {
            fHScale = fWScale;
        }

    }

    dc.SetUserScale(fHScale, fWScale);
    dc.DrawBitmap(img,0,0,false);


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
    std::cout<<image.LoadFile(file, format) << std::endl;
}