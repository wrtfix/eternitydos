#include "clave.h"

Clave::Clave(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	setBackgroundRole(QPalette::Light);
	setAutoFillBackground(true);
	this->N=3;
	this->C=2;
	
	this->margenX = 310;
	this->margenY = 10;
}

Clave::~Clave()
{}

void Clave::on_botonCrear_clicked()
{
	this->N = ui.spinN->value();
	this->C = ui.spinCC->value();
	this->t.generarPuzzle(C,N);
	ui.botonMezclar->setEnabled(true);
	ui.botonCrear->setEnabled(false);
	this->repaint();
}
void Clave::on_botonMezclar_clicked()
{
	Ficha *arreglo[N*N];
	this->t.armandoUno(arreglo);
	this->t.mezclar(arreglo);
	this->t.rotarAzar(arreglo);
	this->t.Paso(arreglo);
	ui.botonResolver->setEnabled(true);
	this->repaint();
}

void Clave::on_botonResolver_clicked()
{
	Jugar persona(N,C);
	Ficha *arreglo[N*N];
	this->t.armandoUno(arreglo);
	persona.Resolver(&t,arreglo);
	ui.botonCrear->setEnabled(true);
	ui.botonMezclar->setEnabled(false);
	ui.botonResolver->setEnabled(false);
	this->repaint();
}

void Clave::paintEvent(QPaintEvent *event)
{	
    FichaView ficha(1,2,3,0);
    this->lado = ficha.getLado(); // guardo el lado en una variable
    
	for(int i=0;i<this->N;i++)
		for(int j=0;j<this->N;j++)
			if (t.get(i,j)!=NULL)
			{
				ficha.setColorArriba(t.get(i,j)->getArriba());
				ficha.setColorDerecha(t.get(i,j)->getDerecha());
				ficha.setColorAbajo(t.get(i,j)->getAbajo());
				ficha.setColorIzquierda(t.get(i,j)->getIzquierda());
 				ficha.dibujarFicha(this,this->margenX+j*this->lado,this->margenY+i*this->lado);
			}

}
