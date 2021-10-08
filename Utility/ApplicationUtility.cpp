//
// Created by Pietro Bonechi on 08/10/21.
//

#include "ApplicationUtility.h"

wxBitmap ImageScaler(wxSize s, wxImage &img) {
    float fWScale = 1.0f;   // horizontal scaling factor
    float fHScale = 1.0f;   // vertical scaling factor
    int iImageH = -1;       // the bitmap's height
    int iImageW = -1;       // the bitmap's width
    int iThisH = s.GetHeight();        // the panel's height
    int iThisW = s.GetWidth();        // the panel's width

    // how is the bitmap's actual size?
    iImageH = img.GetHeight();
    iImageW = img.GetWidth();


    if( ( iImageH> 0 ) && ( iImageW> 0 ) )
    {

        fHScale = (float) iThisH / (float) iImageH;
        fWScale = (float) iThisW / (float) iImageW;

        if(fHScale < fWScale)
            fWScale = fHScale;
        else
            fHScale = fWScale;
    }
    //dc.SetUserScale(fHScale, fWScale);
    return wxBitmap(img.Scale(iImageW*fWScale,iImageH*fHScale,wxIMAGE_QUALITY_HIGH));

}