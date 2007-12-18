//---------------------------------------------------------------------------
//
// Name:        EternityApp.cpp
// Author:      
// Created:     17/12/2007 03:59:29 p.m.
// Description: 
//
//---------------------------------------------------------------------------

#include "EternityApp.h"
#include "EternityFrm.h"

IMPLEMENT_APP(EternityFrmApp)

bool EternityFrmApp::OnInit()
{
    EternityFrm* frame = new EternityFrm(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int EternityFrmApp::OnExit()
{
	return 0;
}
