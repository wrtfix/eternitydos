//---------------------------------------------------------------------------
//
// Name:        Dibujar.cpp
// Author:      
// Created:     17/12/2007 04:16:35 p.m.
// Description: Dibujar class implementation
//
//---------------------------------------------------------------------------

#include "Dibujar.h"

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// Dibujar
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(Dibujar, wxDialog)
	////Manual Code Start
	////Manual Code End
	EVT_CLOSE(Dibujar::OnClose)
END_EVENT_TABLE()
////Event Table End

Dibujar::Dibujar(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

Dibujar::~Dibujar()
{
} 

void Dibujar::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start
	////GUI Items Creation End
}

void Dibujar::OnClose(wxCloseEvent& /*event*/)
{
	Destroy();
}
