#include "FichaView.h"
#include <stdlib.h>

FichaView::FichaView(int colorArriba, int colorDer, int colorIzq, int colorAbajo) {
	this->colorAbajo = colorAbajo;
	this->colorArriba = colorArriba;
	this->colorDer = colorDer;
	this->colorIzq = colorIzq;
	this->lado = 40;
}

void FichaView::setLado(int lado)
{
	this->lado = lado;		
}

int FichaView::getLado()
{
	return this->lado;	
}

void FichaView::setColorArriba(int color)
{
	this->colorArriba = color;	
}

void FichaView::setColorDerecha(int color)
{
	this->colorDer = color;	
}

void FichaView::setColorAbajo(int color)
{
	this->colorAbajo = color;	
}

void FichaView::setColorIzquierda(int color)
{
	this->colorIzq = color;	
}

QColor FichaView::getColor(int color)
{
	//QBrush br;
	switch(color) 
	{
	   case 0:return Qt::gray;
	   case 1:return QColor(255,128,0); //naranja
	   case 2:return QColor(255,128,255);//rosa
	   case 3:return QColor(210,0,0);   //bordo
	   case 4:return QColor(128,190,255); //celeste
	   case 5:return QColor(0,205,0);//verde
	   case 6:return QColor(128,0,255); //violeta
	   case 7:return QColor(255,128,255);//rosa  
	   case 8:return QColor(10,70,186); //azul
	   case 9:return QColor(10,70,186); //azul;
	   case 10:return QColor(128,0,255); //violeta
	   case 11:return QColor(0,128,64);//verde
	   case 12:return Qt::yellow;
	   case 13:return QColor(210,0,0);   //bordo
	   case 14:return QColor(0,205,0);//verde
	   case 15:return Qt::yellow;
	   case 16:return QColor(10,70,186); //azul
	   case 17:return QColor(255,128,255);//rosa  
	   case 18:return Qt::yellow;
	   case 19:return QColor(210,0,0);   //bordo
	   case 20:return QColor(255,128,0); //naranja
	   case 21:return Qt::yellow;
	   case 22:return QColor(10,70,186); //azul
	   break;
	   default: 
	        return Qt::gray;
	}
}

QColor FichaView::getSubcolor(int color)
{
	//QBrush br;
	switch(color) 
	{
	   case 0:return Qt::gray;
	   case 1:return QColor(128,190,255); //celeste
	   case 2:return Qt::yellow;
	   case 3:return QColor(0,205,0);//verde
	   case 4:return QColor(255,128,255);//rosa
	   case 5:return QColor(10,70,186); //azul
	   case 6:return Qt::yellow;
	   case 7:return QColor(128,190,255); //celeste 
	   case 8:return QColor(255,128,0); //naranja
	   case 9:return Qt::yellow;
	   case 10:return QColor(128,190,255); //celeste
	   case 11:return QColor(255,128,0); //naranja
	   case 12:return QColor(10,70,186); //azul
	   case 13:return QColor(255,128,0); //naranja
	   case 14:return QColor(255,128,255); //rosa
	   case 15:return QColor(0,205,0);//verde
	   case 16:return QColor(128,190,255); //celeste
	   case 17:return QColor(0,205,0);//verde
	   case 18:return QColor(128,190,255); //celeste
	   case 19:return Qt::yellow;
	   case 20:return QColor(128,0,255); //violeta
	   case 21:return QColor(255,128,255); //rosa
	   case 22:return QColor(255,128,255); //rosa
	   break;
	   default: 
	        return Qt::gray;
	}
}


void FichaView::dibujarFicha(QWidget *widget, int x, int y) 
{

	QPainter painter(widget);
	
	QPen pen;
	pen.setWidth(2);
	painter.setPen(pen);
	
	painter.translate(x, y);

	QPainterPath path1;
	QPainterPath path11;
	
	QPainterPath path2;
	QPainterPath path21;
	
	QPainterPath path3;
	QPainterPath path31;
	
	QPainterPath path4;
	QPainterPath path41;
	
	int L = this->getLado();
	int medioL = (int)(this->getLado()/2);
	int cuartoL = (int)(medioL / 2);

	// Dibujo el triangulo de arriba
	path1.moveTo(0, 0);
	path1.lineTo(L, 0);
	path1.lineTo(medioL,medioL);
	path1.lineTo(0,0);
	painter.setBrush(this->getColor(this->colorArriba));
	painter.drawPath(path1);

	if (colorArriba != 0)
	{
		path11.moveTo(cuartoL,0);
		path11.lineTo(medioL+cuartoL,0);
		path11.lineTo(medioL,cuartoL);	
		path11.lineTo(cuartoL,0);
		painter.setBrush(this->getSubcolor(this->colorArriba));
		painter.drawPath(path11);
	}
	
	// Dibujo el triangulo de la derecha
	path2.moveTo(L, 0);
	path2.lineTo(L,L);
	path2.lineTo(medioL,medioL);
	path2.lineTo(L,0);
	painter.setBrush(this->getColor(this->colorDer));
	painter.drawPath(path2);

	if (colorDer != 0)
	{
		//Dibuja el subtriagulo de la derecha
		path21.moveTo(L,cuartoL);
		path21.lineTo(L,medioL+cuartoL);
		path21.lineTo(medioL+cuartoL,medioL);
		path21.lineTo(L,cuartoL);
		painter.setBrush(this->getSubcolor(this->colorDer));
		painter.drawPath(path21);
	}
	
	// Dibujo el triangulo de abajo
	path3.moveTo(L, L);
	path3.lineTo(0,L);
	path3.lineTo(medioL, medioL);
	path3.lineTo(L, L);
	painter.setBrush(this->getColor(this->colorAbajo));
	painter.drawPath(path3);

	if (colorAbajo != 0)
	{
		//Dibuja el subtriagulo de abajo
		path31.moveTo(cuartoL,L);
		path31.lineTo(medioL,medioL+cuartoL);
		path31.lineTo(medioL+cuartoL,L);
		path31.lineTo(cuartoL,L);
		painter.setBrush(this->getSubcolor(this->colorAbajo));
		painter.drawPath(path31);
	}
	
	// Dibujo el triangulo de la izquierda
	path4.moveTo(medioL,medioL);
	path4.lineTo(0, L);
	path4.lineTo(0, 0);
	path4.lineTo(medioL,medioL);
	painter.setBrush(this->getColor(this->colorIzq));
	painter.drawPath(path4);
	
	if (colorIzq != 0)
	{
		//Dibuja el subtriagulo de la izquierda
		path41.moveTo(0,cuartoL);
		path41.lineTo(cuartoL,medioL);
		path41.lineTo(0,medioL+cuartoL);
		path41.lineTo(0,cuartoL);
		painter.setBrush(this->getSubcolor(this->colorIzq));
		painter.drawPath(path41);
	}

}

FichaView::~FichaView() {
}
