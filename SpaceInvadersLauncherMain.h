/***************************************************************
 * Name:      SpaceInvadersLauncherMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2017-05-20
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef SPACEINVADERSLAUNCHERMAIN_H
#define SPACEINVADERSLAUNCHERMAIN_H

//(*Headers(SpaceInvadersLauncherFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/gauge.h>
#include <wx/listbox.h>
#include <wx/panel.h>
//*)

class SpaceInvadersLauncherFrame: public wxFrame
{
    public:

        SpaceInvadersLauncherFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~SpaceInvadersLauncherFrame();


    private:


        //(*Handlers(SpaceInvadersLauncherFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnbtnplayClick(wxCommandEvent& event);
        void OnbtnupdateClick(wxCommandEvent& event);
        void OnbtnplayClick1(wxCommandEvent& event);
        void OnbtnupdateClick1(wxCommandEvent& event);
        void OnbtnplayClick2(wxCommandEvent& event);
        void OnbtnupdateClick2(wxCommandEvent& event);
        void OnbtnchangelogClick(wxCommandEvent& event);
        void OnbtninfoClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(SpaceInvadersLauncherFrame)
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_GAUGE1;
        static const long ID_LISTBOX1;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_PANEL1;
        //*)

        //(*Declarations(SpaceInvadersLauncherFrame)
        wxButton* btnchangelog;
        wxButton* btninfo;
        wxButton* btnplay;
        wxButton* btnupdate;
        wxGauge* gupdate;
        wxListBox* lbupdate;
        wxPanel* Panel1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // SPACEINVADERSLAUNCHERMAIN_H
