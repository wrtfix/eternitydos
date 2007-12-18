//---------------------------------------------------------------------------
//
// Name:        EternityApp.h
// Author:      
// Created:     17/12/2007 03:59:29 p.m.
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __ETERNITYFRMApp_h__
#define __ETERNITYFRMApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class EternityFrmApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
