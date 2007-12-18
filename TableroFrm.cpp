//---------------------------------------------------------------------------
//
// Name:        TableroFrm.cpp
// Author:      
// Created:     17/12/2007 04:20:08 p.m.
// Description: TableroFrm class implementation
//
//---------------------------------------------------------------------------

#include "TableroFrm.h"

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// TableroFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(TableroFrm,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(TableroFrm::OnClose)
	EVT_PAINT(TableroFrm::TableroFrmPaint)
	EVT_ACTIVATE(TableroFrm::TableroFrmActivate)
END_EVENT_TABLE()
////Event Table End

TableroFrm::TableroFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

TableroFrm::~TableroFrm()
{
} 

void TableroFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	SetTitle(wxT("Tablero"));
	SetIcon(wxNullIcon);
	SetSize(8,8,320,334);
	Center();
	
	////GUI Items Creation End
}

void TableroFrm::OnClose(wxCloseEvent& /*event*/)
{
	Destroy();
}


wxColor TableroFrm::Color(int c)
{
    wxColor col;
    if (c == 0)
		 col = (wxColor(0,0,0));
    else
    if (c == 1)
	     col = (wxColor(255,0,0));
    else
    if (c == 2)
		 col =  (wxColor(0,255,0));
    else
    if (c == 3)
		 col =  (wxColor(255,255,0));
    else
    if (c == 4)
		 col =  (wxColor(0,0,255));
    else
    if (c == 5)
		 col =  (wxColor(255,0,255));
    else
    if (c == 6)
		 col =  (wxColor(255,255,255));
    else
    if (c == 7)
		 col =  (wxColor(255,128,128));
    else
    if (c == 8)
		 col =  (wxColor(32,64,128));
    else
    if (c == 9)
		 col =  (wxColor(18,18,128));
    else
    if (c == 10)
		 col =  (wxColor(32,32,128));
    else
    if (c == 11)
		 col =  (wxColor(32,255,16));
    else
    if (c == 12)
		 col =  (wxColor(128,64,8));
    else
    if (c == 13)
		 col =  (wxColor(64,64,64));
    else
    if (c == 14)
		 col =  (wxColor(32,64,8));
    else
    if (c == 15)
		 col =  (wxColor(2,2,128));
    else
    if (c == 16)
		 col =  (wxColor(8,8,16));
    else
    if (c == 17)
		 col =  (wxColor(4,32,4));
    else
    if (c == 18)
		 col =  (wxColor(255,2,0));
    else
    if (c == 19)
		 col =  (wxColor(105,104,100));
    else
    if (c == 20)
		 col =  (wxColor(55,25,205));
    else
    if (c == 21)
		 col =  (wxColor(116,164,116));

    return col;
}




/*
 * TableroFrmPaint
 */
void TableroFrm::TableroFrmPaint(wxPaintEvent& event)
{
	wxPaintDC dc(this);
	wxPoint a[3];
	wxPoint b[3];
	wxPoint c[3];
	wxPoint d[3];

	for (int j=0;j<N;j++)
		for (int i=0;i<N;i++)
		{

	//		Traingulo derecho
			a[0].x = 2*tx+(i*tx);
		  	a[0].y = ty+(j*ty);

		    a[1].x = (tx+(tx/2))+(i*tx);
		  	a[1].y = (ty+(ty/2))+(j*ty);

			a[2].x = (2*tx)+(i*tx);
		  	a[2].y = (2*ty)+(j*ty);

	//		Triangulo de izquierda
			b[0].x = tx+(i*tx);
		  	b[0].y = ty+(j*ty);

			b[1].x = (tx+(tx/2))+(i*tx);
		  	b[1].y = (ty+(ty/2))+(j*ty);

			b[2].x = tx+(i*tx);
		  	b[2].y = (2*ty)+(j*ty);

	//	  	Triangulo de arriba
			c[0].x = tx+(i*tx);
		  	c[0].y = ty+(j*ty);

			c[1].x = (tx+(tx/2))+(i*tx);
		  	c[1].y = (ty+(ty/2))+(j*ty);

			c[2].x = (2*tx)+(i*tx);
		  	c[2].y = ty+(j*ty);

	//		Triangulo de abajo
			d[0].x = tx+(i*tx);
		  	d[0].y = (2*ty)+(j*ty);

			d[1].x = (tx+(tx/2))+(i*tx);
		  	d[1].y = (ty+(ty/2))+(j*ty);

			d[2].x = 2*tx+(i*tx);
		  	d[2].y = 2*ty+(j*ty);
		  	if (t->get(j,i)!= NULL)
			{
				dc.SetBrush(Color(t->get(j,i)->getDerecha()));
				dc.DrawPolygon(3,a,0);

				dc.SetBrush(Color(t->get(j,i)->getIzquierda()));
				dc.DrawPolygon(3,b,0);

				dc.SetBrush(Color(t->get(j,i)->getArriba()));
			 	dc.DrawPolygon(3,c,0);

				dc.SetBrush(Color(t->get(j,i)->getAbajo()));
			 	dc.DrawPolygon(3,d,0);
			}


        }
}
void TableroFrm::iniciarTablero(Tablero *elemento,int tamanio,int colores,int ancho, int alto)
{
	N = tamanio;
	C = colores;
	tx = ancho;
	ty = alto;
	t = elemento;
}

/*
 * TableroFrmActivate
 */
void TableroFrm::TableroFrmActivate(wxActivateEvent& event)
{
	Refresh();
}
