#ifndef FICHA_H
#define FICHA_H

//<sacar>
//#include <iostream>
#include <cstdlib>

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
		// class constructor

    	Ficha(){}
        bool compatible(Ficha *otra, int posicion)
        {
            if (posicion == ARRIBA) // posicion 1 Arriba
                return (otra->getArriba() == ab);
            else
                if (posicion == DERECHA) // posicion 2 Derecha                
                    return (otra->getDerecha() == izq);
                else
                    if (posicion == ABAJO) // posicion 3 Abajo                
                         return (otra->getAbajo() == arr);
                    else
                        if (posicion == IZQUIERDA) // posicion 4 Izquierda
                            return (otra->getIzquierda() == der);
                        else
                            return false;
        }
        
        void Rotar()
        {
            int a = arr;
            arr = izq;
            izq = ab;
            ab = der;
            der = a;
        }
        
        //Devuelve TRUE si "this" es compatible()con f, hace rotaciones
        bool compatibleRotacion(Ficha *f,int posicion)
        {
			if (compatible(f,posicion))
				return true;
			else
				f->Rotar();
				if (compatible(f,posicion))
					return true;
				else
					f->Rotar();
					if (compatible(f,posicion))
						return true;
					else
						f->Rotar();
						return (compatible(f,posicion));
		}
		
		bool compatibleEsq(int valor1, int valor2)
		{
			return false;
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
