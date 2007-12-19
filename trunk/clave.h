#ifndef CLAVE_H
#define CLAVE_H

#include <QtGui/QWidget>

#include "ui_clave.h"
#include "Ficha.h"
#include "Tablero.h"
#include "FichaView.h"
#include "Jugar.h"


class Clave : public QWidget
{
    Q_OBJECT

public:
    Clave(QWidget *parent = 0);
    ~Clave();
    Tablero t;
    int C;
    int N;
    int margenX;
    int margenY;    
    
    int lado;
    int coordX;
    int coordY;
    Ficha *f;
    
protected:
	void paintEvent(QPaintEvent *event);
	void mousePressEvent(QMouseEvent *event);
	
private slots:
    void on_botonCrear_clicked();
    void on_botonMezclar_clicked();
    void on_botonResolver_clicked();
    // cuando hago click me dice si en donde lohice pertene al tablero
    bool perteneceTablero(int,int);

    // me retorna una posicion para poder acceder a la 
    // ficha de esa posicion en el tablero.
    int posicion(int); 
    
    // Giro la ficha, modifico el tablero y llamo al evento paint
    void on_botonGirar_clicked();
    
    
private:
	Ui::ClaveClass ui;

};

#endif // CLAVE_H
