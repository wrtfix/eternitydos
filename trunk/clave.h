#ifndef CLAVE_H
#define CLAVE_H

#include <QtGui/QWidget>

#include "ui_clave.h"
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
 
protected:
	void paintEvent(QPaintEvent *event);
	
private slots:
    void on_botonCrear_clicked();
    void on_botonMezclar_clicked();
    void on_botonResolver_clicked();
    
    
private:
	Ui::ClaveClass ui;

};

#endif // CLAVE_H
