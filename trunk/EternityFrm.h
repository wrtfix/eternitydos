//---------------------------------------------------------------------------
//
// Name:        EternityFrm.h
// Author:      
// Created:     17/12/2007 03:59:29 p.m.
// Description: EternityFrm class declaration
//
//---------------------------------------------------------------------------

#ifndef __ETERNITYFRM_h__
#define __ETERNITYFRM_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/listbox.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/spinctrl.h>
#include <wx/statbox.h>
////Header Include End

////Dialog Style Start
#undef EternityFrm_STYLE
#define EternityFrm_STYLE wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxTHICK_FRAME | wxSTAY_ON_TOP | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

#include "TableroFrm.h"
#include "Ficha.h"
#include "Tablero.h"


class EternityFrm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();

	public:
		EternityFrm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Eternity"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = EternityFrm_STYLE);
		virtual ~EternityFrm();
		void CrearClick(wxCommandEvent& event);
		void MezclarClick(wxCommandEvent& event);
		Tablero *t;
		TableroFrm *dialog;
		void EternityFrmActivate(wxActivateEvent& event);
		void ResolverClick(wxCommandEvent& event);
		void agregarLista(int);
   		void resolverTablero();
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxStaticText *WxStaticText6;
		wxStaticText *WxStaticText5;
		wxButton *Resolver;
		wxListBox *WxListBox1;
		wxStaticBox *WxStaticBox5;
		wxButton *Mezclar;
		wxStaticBox *WxStaticBox4;
		wxButton *Crear;
		wxStaticBox *WxStaticBox3;
		wxSpinCtrl *WxSpinCtrl4;
		wxStaticText *WxStaticText4;
		wxStaticText *WxStaticText3;
		wxSpinCtrl *WxSpinCtrl3;
		wxStaticBox *WxStaticBox2;
		wxStaticText *WxStaticText2;
		wxSpinCtrl *WxSpinCtrl2;
		wxStaticText *WxStaticText1;
		wxSpinCtrl *WxSpinCtrl1;
		wxStaticBox *WxStaticBox1;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXSTATICTEXT6 = 1022,
			ID_WXSTATICTEXT5 = 1021,
			ID_RESOLVER = 1020,
			ID_WXLISTBOX1 = 1019,
			ID_WXSTATICBOX5 = 1018,
			ID_MEZCLAR = 1017,
			ID_WXSTATICBOX4 = 1016,
			ID_CREAR = 1014,
			ID_WXSTATICBOX3 = 1013,
			ID_WXSPINCTRL4 = 1012,
			ID_WXSTATICTEXT4 = 1011,
			ID_WXSTATICTEXT3 = 1010,
			ID_WXSPINCTRL3 = 1009,
			ID_WXSTATICBOX2 = 1006,
			ID_WXSTATICTEXT2 = 1005,
			ID_WXSPINCTRL2 = 1004,
			ID_WXSTATICTEXT1 = 1003,
			ID_WXSPINCTRL1 = 1002,
			ID_WXSTATICBOX1 = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
        bool poda(Ficha *hijo,int fila,int columna,int N);
   	    bool solucion(int N);
        void back(Ficha *fichas[],int fila, int columna, bool visitado[],int &c, int nivel,int N);
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
