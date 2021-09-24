//
// Created by Pietro Bonechi on 18/09/21.
//

#include "wxImagePanel.h"
#include <iostream>

wxImagePanel::wxImagePanel(wxPanel* parent, wxString file, wxBitmapType format) :
        wxPanel(parent,wxID_ANY,wxDefaultPosition,wxSize(1280,600),wxBORDER_SIMPLE)
{
    // load the file... ideally add a check to see if loading was successful
    std::cout << this->image.LoadFile(file, format) << std::endl;
//    std::cout <<  this->img.LoadFile(file,format) << std::endl;

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
    float fWScale = 1.0f;   // horizontal scaling factor
    float fHScale = 1.0f;   // vertical scaling factor
    int iImageH = -1;       // the bitmap's height
    int iImageW = -1;       // the bitmap's width
    int iThisH = -1;        // the panel's height
    int iThisW = -1;        // the panel's width

    // how is the bitmap's actual size?
    iImageH = image.GetHeight();
    iImageW = image.GetWidth();

    //Panel size
    GetSize(&iThisW, &iThisH);

    if( ( iImageH> 0 ) && ( iImageW> 0 ) )
    {

        fHScale = (float) iThisH / (float) iImageH;
        fWScale = (float) iThisW / (float) iImageW;

        if(fHScale < fWScale)
        {
            fWScale = fHScale;
        }
        else
        {
            fHScale = fWScale;
        }
    }
    //dc.SetUserScale(fHScale, fWScale);
    resized = wxBitmap(image.Scale(iImageW*fWScale,iImageH*fHScale,wxIMAGE_QUALITY_HIGH));
    int imgMargin = dc.GetSize().GetWidth() - (iImageW * fWScale);

    dc.DrawBitmap(resized,wxPoint(imgMargin/2,0),false);
    std::cout<< dc.GetSize().GetWidth() << std::endl;
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
    std::cout << "Load file: " << file << std::endl;
    std::cout<<image.LoadFile(file, format) << std::endl;
    std::cout << image.GetHeight() << std::endl;
    Refresh();
    Update();
}

void wxImagePanel::saveImage() {
    //image.SaveFile("test1", wxBITMAP_TYPE_JPEG);
}