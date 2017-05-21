/***************************************************************
 * Name:      SpaceInvadersLauncherMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2017-05-20
 * Copyright:  ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "SpaceInvadersLauncherMain.h"
#include <wx/msgdlg.h>
#include <windows.h>
#include <SFML/Network.hpp>
#include <wx/textfile.h>
#include <math.h>
#include <cmath>


double value=0,value1=0,valueneu=1,value1neu=1;


//(*InternalHeaders(SpaceInvadersLauncherFrame)
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(SpaceInvadersLauncherFrame)
const long SpaceInvadersLauncherFrame::ID_BUTTON1 = wxNewId();
const long SpaceInvadersLauncherFrame::ID_BUTTON2 = wxNewId();
const long SpaceInvadersLauncherFrame::ID_GAUGE1 = wxNewId();
const long SpaceInvadersLauncherFrame::ID_LISTBOX1 = wxNewId();
const long SpaceInvadersLauncherFrame::ID_BUTTON3 = wxNewId();
const long SpaceInvadersLauncherFrame::ID_BUTTON4 = wxNewId();
const long SpaceInvadersLauncherFrame::ID_BUTTON5 = wxNewId();
const long SpaceInvadersLauncherFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SpaceInvadersLauncherFrame,wxFrame)
    //(*EventTable(SpaceInvadersLauncherFrame)
    //*)
END_EVENT_TABLE()

SpaceInvadersLauncherFrame::SpaceInvadersLauncherFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(SpaceInvadersLauncherFrame)
    Create(parent, id, _("SpaceInvadersLauncher"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(420,260));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("C:\\Users\\Christian\\git\\SpaceInvaders\\bin\\Release\\Images\\SpaceInvaders.ico"))));
    	SetIcon(FrameIcon);
    }
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(0,0), wxSize(200,100), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    btnupdate = new wxButton(Panel1, ID_BUTTON1, _("Update"), wxPoint(330,180), wxSize(80,30), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    btnplay = new wxButton(Panel1, ID_BUTTON2, _("Play"), wxPoint(330,140), wxSize(80,30), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    gupdate = new wxGauge(Panel1, ID_GAUGE1, 100, wxPoint(10,220), wxSize(400,30), 0, wxDefaultValidator, _T("ID_GAUGE1"));
    lbupdate = new wxListBox(Panel1, ID_LISTBOX1, wxPoint(10,10), wxSize(310,200), 0, 0, wxNO_BORDER, wxDefaultValidator, _T("ID_LISTBOX1"));
    btnchangelog = new wxButton(Panel1, ID_BUTTON3, _("ChangeLog"), wxPoint(330,10), wxSize(80,30), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    btninfo = new wxButton(Panel1, ID_BUTTON4, _("Info"), wxPoint(330,50), wxSize(80,30), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    btnbug = new wxButton(Panel1, ID_BUTTON5, _("Bug report"), wxPoint(330,90), wxSize(80,30), 0, wxDefaultValidator, _T("ID_BUTTON5"));

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SpaceInvadersLauncherFrame::OnbtnupdateClick2);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SpaceInvadersLauncherFrame::OnbtnplayClick2);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SpaceInvadersLauncherFrame::OnbtnchangelogClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SpaceInvadersLauncherFrame::OnbtninfoClick);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SpaceInvadersLauncherFrame::OnbtnbugClick);
    //*)
}

SpaceInvadersLauncherFrame::~SpaceInvadersLauncherFrame()
{
    //(*Destroy(SpaceInvadersLauncherFrame)
    //*)
}

void SpaceInvadersLauncherFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void SpaceInvadersLauncherFrame::OnbtnplayClick2(wxCommandEvent& event)
{
      system ("start /B SpaceInvaders.exe");

     Close();

}

sf::Ftp::Response response;

void SpaceInvadersLauncherFrame::OnbtnupdateClick2(wxCommandEvent& event)
{
remove("log.txt");
wxTextFile updatelogTXT( wxT("log.txt") );
updatelogTXT.Create("log.txt");             ///erstellt nur, falls nicht vorhanden
updatelogTXT.Open("log.txt");

        double value;
        wxTextFile versionInfoTXT( wxT("version.txt") );
        versionInfoTXT.Create("version.txt");
        versionInfoTXT.Open();
        wxString tmp=versionInfoTXT.GetFirstLine();
        if(!tmp.ToDouble(&value)){ /* error! */ }
            if (value>0)
            {
            value=value/10;
            tmp = wxString::Format(wxT("%.1lf"), value);
             versionInfoTXT.Close();

        updatelogTXT.AddLine( "Updating from Version: " +  tmp);
            } else
            {
             updatelogTXT.AddLine( "Clean Install"  );       }



gupdate->SetValue(0);
lbupdate->Clear();

    if (valueneu>value || value1neu>value1)
    {

    lbupdate->Append( wxT("connecting to File Server ...") );
    updatelogTXT.AddLine("connecting to File Server ...");
    sf::Ftp ftp;
    response = ftp.connect("staacraft.square7.ch", 21, sf::seconds(2));
    lbupdate->Append( response.getMessage());
    updatelogTXT.AddLine(response.getMessage());

    response = ftp.login("staacraft_SpaceInvaders", "1324");
     lbupdate->Append( response.getMessage());
     updatelogTXT.AddLine(response.getMessage());


    Update();



    if (response.isOk())
    {

        gupdate->SetValue(gupdate->GetValue()+10);
        lbupdate->Append( wxT("connected to File Server") );
        updatelogTXT.AddLine("connected to File Server");
        lbupdate->Append( wxT("") );
        updatelogTXT.AddLine("");

        lbupdate->Append( wxT("starting Update ...") );
        updatelogTXT.AddLine("starting Update ...");
        Update();

        response = ftp.download("Updates/7za.exe", "", sf::Ftp::Binary);
        lbupdate->Append( response.getMessage());
        updatelogTXT.AddLine(response.getMessage());
        lbupdate->Append( wxT("") );
        updatelogTXT.AddLine("");
        gupdate->SetValue(gupdate->GetValue()+10);

        Update();

        if (valueneu>value)
        {
        lbupdate->Append( wxT("Game downloading ...") );
        updatelogTXT.AddLine("Game downloading ...");
        Update();
        response = ftp.download("Updates/App.zip", "", sf::Ftp::Binary);
        lbupdate->Append( response.getMessage());
        updatelogTXT.AddLine(response.getMessage());
        lbupdate->Append( wxT("Game downloaded") );
        updatelogTXT.AddLine("Game downloaded");
        lbupdate->Append( wxT("") );
        updatelogTXT.AddLine("");
        if (value1neu>value1)
        {gupdate->SetValue(gupdate->GetValue()+30);}
        else
        {gupdate->SetValue(gupdate->GetValue()+60);}
        }
        Update();



        if (value1neu>value1)
        {
        lbupdate->Append( wxT("Gamefiles downloading ...") );
        updatelogTXT.AddLine("Gamefiles downloading ...");
        Update();
        response = ftp.download("Updates/Images.zip", "", sf::Ftp::Binary);
        lbupdate->Append( response.getMessage());
        updatelogTXT.AddLine(response.getMessage());
        lbupdate->Append( wxT("Gamefiles downloaded") );
        updatelogTXT.AddLine("Gamefiles downloaded");
        lbupdate->Append( wxT("") );
        updatelogTXT.AddLine("");
        if (valueneu>value)
        {gupdate->SetValue(gupdate->GetValue()+30);}
        else
        {gupdate->SetValue(gupdate->GetValue()+60);}
        }
        Update();


        lbupdate->Append( wxT("finished Downloads") );
        updatelogTXT.AddLine("finished Downloads");
        Update();

        response = ftp.download("Updates/version.txt", "", sf::Ftp::Ascii);
        lbupdate->Append( response.getMessage());
        updatelogTXT.AddLine(response.getMessage());
        lbupdate->Append( wxT("updated VersionInfo") );
        updatelogTXT.AddLine("updated VersionInfo");
        Update();

        lbupdate->Append( wxT("unpacking Files ...") );
        updatelogTXT.AddLine("unpacking Files ...");
        Update();




            if (valueneu>value)
            {
                system ("7za x -aoa App.zip");
                lbupdate->Append( wxT("unpacked App") );
                updatelogTXT.AddLine("unpacked App");
                Update();
                remove( "App.zip" );

            }

            if (value1neu>value1)
            {
                system ("7za x -aoa Images.zip");
                lbupdate->Append( wxT("unpacked Gamefiles") );
                updatelogTXT.AddLine("unpacked Gamefiles");

                Update();
                remove( "Images.zip" );

            }
            gupdate->SetValue(gupdate->GetValue()+20);

            lbupdate->Append( wxT("Update Ready") );
            updatelogTXT.AddLine("Update Ready");
            lbupdate->Append( wxT("Press Play") );
                Update();
    }
    else
    {
        lbupdate->Append( wxT("no connection...") );
        updatelogTXT.AddLine("no connection...");
        Update();
    }

    } else
    {
        lbupdate->Append( wxT("already Up-to-Date") );
        Update();
    }


         versionInfoTXT.Open();
        tmp=versionInfoTXT.GetFirstLine();
        if(!tmp.ToDouble(&value)){ /* error! */ }
            value=value/10;
            tmp = wxString::Format(wxT("%.1lf"), value);

        updatelogTXT.AddLine( "Updated to Version: " +  tmp);
         versionInfoTXT.Close();



    updatelogTXT.Write();
    updatelogTXT.Close();
}

void SpaceInvadersLauncherFrame::OnbtnchangelogClick(wxCommandEvent& event)
{
        lbupdate->Clear();

         sf::Ftp ftp;
        ftp.connect("staacraft.square7.ch", 21, sf::seconds(2));
        ftp.login("staacraft_SpaceInvaders", "1324");
        ftp.download("Updates/changelog.txt", "", sf::Ftp::Ascii);



        wxTextFile changelogTXT( wxT("changelog.txt") );
        changelogTXT.Create("changelog.txt");
        changelogTXT.Open();

        lbupdate->Append( changelogTXT.GetFirstLine() );
        while (!changelogTXT.Eof())
        {
            lbupdate->Append( changelogTXT.GetNextLine() );
        }

        changelogTXT.Close();

}

void SpaceInvadersLauncherFrame::OnbtninfoClick(wxCommandEvent& event)
{

        lbupdate->Clear();

        wxTextFile versionInfoTXT( wxT("version.txt") );
        versionInfoTXT.Create("version.txt");
        versionInfoTXT.Open();




        lbupdate->Append( "Auf dem PC vorhanden:" );
        if (!versionInfoTXT.Eof())
        {
            wxString tmp=versionInfoTXT.GetFirstLine();

            if(!tmp.ToDouble(&value)){ /* error! */ }
            value=value/10;
            tmp = wxString::Format(wxT("%.1lf"), value);

        lbupdate->Append( "Game:         " +  tmp);



            tmp=versionInfoTXT.GetNextLine();
            if(!tmp.ToDouble(&value1)){ /* error! */ }
            value1=value1/10;
            tmp = wxString::Format(wxT("%.1lf"), value1);
        lbupdate->Append( "Gamefiles:  " + tmp );
        }
        else
        {
         lbupdate->Append( "Game: Nicht installiert" );
        lbupdate->Append( "Gamefiles: Nicht installiert");
        }
        Update();


    sf::Ftp ftp;
    ftp.connect("staacraft.square7.ch", 21, sf::seconds(2));
    response = ftp.login("staacraft_SpaceInvaders", "1324");

       lbupdate->Append( "" );
        lbupdate->Append( "" );
    if (response.isOk())
    {
        rename( "version.txt" , "version1.txt" );
        remove( "version.txt" );
        ftp.download("Updates/version.txt", "", sf::Ftp::Ascii);
        rename( "version.txt" , "versionAktuell.txt" );
        remove( "version.txt" );
        rename( "version1.txt" , "version.txt" );

        wxTextFile versionNEUInfoTXT( wxT("versionAktuell.txt") );
        versionNEUInfoTXT.Create("versionAktuell.txt");
        versionNEUInfoTXT.Open();



        lbupdate->Append( "Aktuell verfügbar:" );
       if (!versionNEUInfoTXT.Eof())
        {
            wxString tmp=versionNEUInfoTXT.GetFirstLine();
            if(!tmp.ToDouble(&valueneu)){ /* error! */ }
            valueneu=valueneu/10;
            tmp = wxString::Format(wxT("%.1lf"), valueneu);

        lbupdate->Append( "Game:         " +  tmp);



            tmp=versionNEUInfoTXT.GetNextLine();
            if(!tmp.ToDouble(&value1neu)){ /* error! */ }
            value1neu=value1neu/10;
            tmp = wxString::Format(wxT("%.1lf"), value1neu);
        lbupdate->Append( "Gamefiles:  " + tmp );


        }
        else
        {
         lbupdate->Append( "Fehler: Keine Internetverbindung" );
        }

        versionNEUInfoTXT.Close();


            lbupdate->Append( "" );
            lbupdate->Append( "" );

            if (valueneu>value || value1neu>value)
            {
              lbupdate->Append( "Es ist eine neue Version verfügbar!" );
            } else
            {
            lbupdate->Append( "Dein Spiel ist Up-to-Date" );
            }

    }
    else
    {
    lbupdate->Append( "Fehler: Keine Internetverbindung" );
    }

        versionInfoTXT.Close();

}

void SpaceInvadersLauncherFrame::OnbtnbugClick(wxCommandEvent& event)
{
    wxTextFile logTXT("log.txt");
    lbupdate->Clear();
    bool bugtextwritten=false;

     wxTextEntryDialog *dlg = new wxTextEntryDialog((wxFrame *)NULL,wxT("Schreibe hier deinen Spielfehler rein:"),wxT("Bugreport"),wxT(""));
             if ( dlg->ShowModal() == wxID_OK )
                {
                wxString bugtext=dlg->GetValue();
                bugtextwritten=true;
                logTXT.Create("log.txt");             ///erstellt nur, falls nicht vorhanden
                logTXT.Open("log.txt");
                logTXT.InsertLine(bugtext,0);
                logTXT.InsertLine("",1);
                logTXT.InsertLine("",1);
                logTXT.InsertLine("Log:",3);
                logTXT.Write();
                logTXT.Close();




   sf::Ftp ftp;
    response = ftp.connect("staacraft.square7.ch", 21, sf::seconds(2));
    response = ftp.login("staacraft_SpaceInvaders", "1324");
    ftp.changeDirectory("Log");
    response = ftp.getDirectoryListing();





 int i;
     sf::Ftp::ListingResponse response = ftp.getDirectoryListing();
     const std::vector<std::string>& listing = response.getListing();
      for (std::vector<std::string>::const_iterator it = listing.begin(); it != listing.end(); ++it)
        i++;
        wxString tmp="bugreport";
        tmp << i-1;
        tmp+=".txt";


            rename( "log.txt" , tmp );
            ftp.upload(std::string(tmp.mb_str()), "", sf::Ftp::Ascii);
            rename( tmp,"log.txt" );

            lbupdate->Append("Bug reported");



                    logTXT.Create("log.txt");             ///erstellt nur, falls nicht vorhanden
                logTXT.Open("log.txt");
                    logTXT.RemoveLine(0);
                    logTXT.RemoveLine(0);
                    logTXT.RemoveLine(0);
                    logTXT.RemoveLine(0);
                logTXT.Write();
                logTXT.Close();
 }
                dlg->Destroy();
}
