//---------------------------------------------------------------------------
//
// Name:        EternityFrm.cpp
// Author:      
// Created:     17/12/2007 03:59:29 p.m.
// Description: EternityFrm class implementation
//
//---------------------------------------------------------------------------

#include "EternityFrm.h"

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// EternityFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(EternityFrm,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(EternityFrm::OnClose)
	EVT_INIT_DIALOG(EternityFrm::EternityFrmInitDialog)
	EVT_ACTIVATE(EternityFrm::EternityFrmActivate)
	EVT_BUTTON(ID_RESOLVER,EternityFrm::ResolverClick)
	EVT_BUTTON(ID_MEZCLAR,EternityFrm::MezclarClick)
	EVT_BUTTON(ID_CREAR,EternityFrm::CrearClick)
END_EVENT_TABLE()
////Event Table End

EternityFrm::EternityFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

EternityFrm::~EternityFrm()
{
}

void EternityFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	SetTitle(wxT("Eternity"));
	SetIcon(wxNullIcon);
	SetSize(6,-12,517,496);
	Center();
	

	Resolver = new wxButton(this, ID_RESOLVER, wxT("&Resolver"), wxPoint(34,315), wxSize(130,137), 0, wxDefaultValidator, wxT("Resolver"));
	Resolver->SetForegroundColour(wxColour(255,255,255));
	Resolver->SetBackgroundColour(wxColour(255,0,0));
	Resolver->SetFont(wxFont(16, wxSWISS, wxNORMAL,wxBOLD, false, wxT("Tahoma")));

	wxArrayString arrayStringFor_WxListBox1;
	WxListBox1 = new wxListBox(this, ID_WXLISTBOX1, wxPoint(170,313), wxSize(303,140), arrayStringFor_WxListBox1, wxLB_SINGLE);
	WxListBox1->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Microsoft Sans Serif")));

	WxStaticBox5 = new wxStaticBox(this, ID_WXSTATICBOX5, wxT("Resolver"), wxPoint(23,297), wxSize(466,163));
	WxStaticBox5->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Microsoft Sans Serif")));

	Mezclar = new wxButton(this, ID_MEZCLAR, wxT("&Mezclar"), wxPoint(351,229), wxSize(75,25), 0, wxDefaultValidator, wxT("Mezclar"));
	Mezclar->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Microsoft Sans Serif")));

	WxStaticBox4 = new wxStaticBox(this, ID_WXSTATICBOX4, wxT("Mezclar"), wxPoint(22,191), wxSize(467,97));
	WxStaticBox4->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Microsoft Sans Serif")));

	Crear = new wxButton(this, ID_CREAR, wxT("Crear"), wxPoint(351,146), wxSize(75,25), 0, wxDefaultValidator, wxT("Crear"));
	Crear->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Microsoft Sans Serif")));

	WxStaticBox3 = new wxStaticBox(this, ID_WXSTATICBOX3, wxT("Crear"), wxPoint(268,13), wxSize(223,169));
	WxStaticBox3->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Microsoft Sans Serif")));

	WxSpinCtrl4 = new wxSpinCtrl(this, ID_WXSPINCTRL4, wxT("50"), wxPoint(187,136), wxSize(38,22), wxSP_ARROW_KEYS, 0, 100, 50);
	WxSpinCtrl4->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Microsoft Sans Serif")));

	WxStaticText4 = new wxStaticText(this, ID_WXSTATICTEXT4, wxT("Largo:"), wxPoint(150,142), wxDefaultSize, 0, wxT("WxStaticText4"));
	WxStaticText4->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Microsoft Sans Serif")));

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, wxT("Ancho:"), wxPoint(50,138), wxDefaultSize, 0, wxT("WxStaticText3"));
	WxStaticText3->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Microsoft Sans Serif")));

	WxSpinCtrl3 = new wxSpinCtrl(this, ID_WXSPINCTRL3, wxT("50"), wxPoint(94,135), wxSize(36,22), wxSP_ARROW_KEYS, 0, 100, 50);
	WxSpinCtrl3->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Microsoft Sans Serif")));

	WxStaticBox2 = new wxStaticBox(this, ID_WXSTATICBOX2, wxT("Ficha:"), wxPoint(34,106), wxSize(202,62));
	WxStaticBox2->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Microsoft Sans Serif")));

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, wxT("Colores:"), wxPoint(35,78), wxDefaultSize, 0, wxT("WxStaticText2"));
	WxStaticText2->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Microsoft Sans Serif")));

	WxSpinCtrl2 = new wxSpinCtrl(this, ID_WXSPINCTRL2, wxT("2"), wxPoint(115,74), wxSize(121,22), wxSP_ARROW_KEYS, 2, 22, 2);
	WxSpinCtrl2->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Microsoft Sans Serif")));

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, wxT("Tamaño:"), wxPoint(35,44), wxDefaultSize, 0, wxT("WxStaticText1"));
	WxStaticText1->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Microsoft Sans Serif")));

	WxSpinCtrl1 = new wxSpinCtrl(this, ID_WXSPINCTRL1, wxT("2"), wxPoint(116,40), wxSize(121,22), wxSP_ARROW_KEYS, 2, 16, 2);
	WxSpinCtrl1->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Microsoft Sans Serif")));

	WxStaticBox1 = new wxStaticBox(this, ID_WXSTATICBOX1, wxT("Configuracion de tablero"), wxPoint(25,14), wxSize(223,167));
	WxStaticBox1->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Microsoft Sans Serif")));
	////GUI Items Creation End
}

void EternityFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}

/*
 * CrearClick
 */
void EternityFrm::CrearClick(wxCommandEvent& event)
{

//	TableroFrm *dialog = new TableroFrm(this);
	int tamanio = this->WxSpinCtrl1->GetValue();
	int colores = this->WxSpinCtrl2->GetValue();
	int ancho = this->WxSpinCtrl3->GetValue();
	int alto = this->WxSpinCtrl4->GetValue();
	t.generarPuzzle(colores,tamanio);
	dialog->iniciarTablero(&t,tamanio,colores,ancho,alto);
	dialog->Show();
}

/*
 * MezclarClick
 */
void EternityFrm::MezclarClick(wxCommandEvent& event)
{
	int tamanio = this->WxSpinCtrl1->GetValue();
	int colores = this->WxSpinCtrl2->GetValue();
	int ancho = this->WxSpinCtrl3->GetValue();
	int alto = this->WxSpinCtrl4->GetValue();

    Ficha *arreglo[tamanio*tamanio];
    t.armandoUno(arreglo);
    t.rotarAzar(arreglo);
    t.mezclar(arreglo);
    t.Paso(arreglo);
	dialog->iniciarTablero(&t,tamanio,colores,ancho,alto);
	dialog->Refresh();
}

void EternityFrm::agregarLista(int elemento)
{
    this->WxListBox1->Append((wxString::Format(wxT("%d"),elemento)));
}


/*
 * EternityFrmActivate
 */
void EternityFrm::EternityFrmActivate(wxActivateEvent& event)
{
	dialog = new TableroFrm(this);
}

/*
 * EternityFrmInitDialog
 */
void EternityFrm::EternityFrmInitDialog(wxInitDialogEvent& event)
{
}

/*
 * ResolverClick
 */
void EternityFrm::ResolverClick(wxCommandEvent& event)
{
//	TableroFrm *dialog = new TableroFrm(this);
	int tamanio = this->WxSpinCtrl1->GetValue();
	int colores = this->WxSpinCtrl2->GetValue();
	int ancho = this->WxSpinCtrl3->GetValue();
	int alto = this->WxSpinCtrl4->GetValue();
    Ficha *arreglo[tamanio*tamanio];
    t.armandoUno(arreglo);
    Jugar jugador(tamanio,colores);
    jugador.Resolver(&t,arreglo);
	dialog->iniciarTablero(&t,tamanio,colores,ancho,alto);
	dialog->Show();
}
