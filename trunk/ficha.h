#ifndef FICHA_H
#define FICHA_H

#define ARRIBA 1
#define DERECHA 2
#define ABAJO 3
#define IZQUIERDA 4

using namespace std;

class Ficha
{
    private:
            int arr;
            int ab;
            int  der;
            int izq;
            int x;
            int y;
	public:

    	Ficha(){}
    	
    	//Rota una ficha una vez, en sentido horario.
        void Rotar()
        {
            int a = arr;
            arr = izq;
            izq = ab;
            ab = der;
            der = a;
        }
	
        int getArriba()
        {
            return arr;
        }
        
        int getAbajo()
        {
            return ab;
        }
             
        int getDerecha()
        {
            return der;
        }
        int getIzquierda()
        {
            return izq;
        }

        void setArriba(int valor)
        {
            arr = valor;
        }
        void setDerecha(int valor)
        {
            der = valor;
        }
        void setAbajo(int valor)
        {
            ab = valor;
        }
        void setIzquierda(int valor)
        {
            izq = valor;
        }
        void setX(int i)
        {
            x = i;
        }
        void setY(int j)
        {
            y = j;
        }
        int getY()
        {
            return y;
        }
        int getX()
        {
            return x;
        }

		~Ficha(){}
};

#endif // FICHA_H
