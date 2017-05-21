/***************************************************************
 * Name:      SpaceInvadersLauncherApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2017-05-20
 * Copyright:  ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "SpaceInvadersLauncherApp.h"

//(*AppHeaders
#include "SpaceInvadersLauncherMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(SpaceInvadersLauncherApp);

bool SpaceInvadersLauncherApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	SpaceInvadersLauncherFrame* Frame = new SpaceInvadersLauncherFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
