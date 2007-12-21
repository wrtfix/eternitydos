#ifndef FICHAVIEW_H_
#define FICHAVIEW_H_

#include <QtGui>
#include <QPainterPath>

class FichaView
{
public:
	FichaView(int colorArriba, int colorDer, int colorIzq, int colorAbajo);
	void dibujarFicha(QWidget *widget, int x, int y);
	
	QColor getColor(int);
	QColor getSubcolor(int);
	
	virtual ~FichaView();
	
	void setColorArriba(int color);
	void setColorDerecha(int color);
	void setColorAbajo(int color);
	void setColorIzquierda(int color);
	
	void setLado(int);
	int getLado();
 
	
private:
	int colorArriba;
	int colorDer;
	int colorIzq;
	int colorAbajo;
	
	int lado;
};

#endif /*FICHAVIEW_H_*/
