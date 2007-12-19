#ifndef TABLERO_H
#define TABLERO_H

#define ARRIBA 1
#define DERECHA 2
#define ABAJO 3
#define IZQUIERDA 4
#include "Ficha.h"
class Tablero
{
    private:
        const static int MAX=16;

        //la matriz real es de 16x16 (el tamaño macolumnaimo)
        Ficha *matriz[MAX][MAX];
        //tamaño de matriz que se usará
        int n;
        int asignarValor(int *arreglo, int colores)
        {
                int random = rand()%colores+1;
                if (arreglo[random]>0)
                    return random;
                else
                    return asignarValor(arreglo,colores);
        }
        
	public:
        Tablero()
        {
            for(int i=0;i<MAX;i++)
                for(int j=0;j<MAX;j++)
                    matriz[i][j] = NULL;
		    
        }
        
        int getN()
        {
            return n;
        }            


        //hace falta esta función? o con la funcion GET alcanza?
        bool Vacia(int columna, int fila)
        {
            if (get(fila,columna) == NULL)
                return true;
            else
                return false;
        }


        Ficha* get(int fila, int columna)
        {
            return this->matriz[fila][columna];
        }

        Ficha* getVecino(int fila, int columna, int posicion)
        {
            if (posicion == ARRIBA)
                return (this->get(fila-1,columna));
            else
                if (posicion == DERECHA)
                    return (this->get(fila,columna+1));
                else
                    if (posicion == ABAJO)
                        return (this->get(fila+1,columna));
                    else
                        if (posicion == IZQUIERDA)
                            return (this->get(fila,columna-1));
        }

        bool borde(int fila, int columna, int posicion)
        {
            if (posicion == ARRIBA)
                return (fila==0);
            else
                if (posicion == DERECHA)
                    return (columna==n-1);
                else
                    if (posicion == ABAJO)
                        return (fila==n-1);
                    else
                        if (posicion == IZQUIERDA)
                            return (columna==0);
                        else
                            return false;
        }

	    void set(Ficha* f, int fila, int columna)
        {
            this->matriz[fila][columna] = f;
        }

        
        Ficha* asignarFicha(int fila, int columna, int* cantColores, int colores)
        {
            int arriba,derecha,abajo,izquierda;            
            
            //ARRIBA
            if (this->borde(fila, columna, ARRIBA))
                arriba = 0;
            else
            {
                arriba = (getVecino(fila,columna,ARRIBA))->getAbajo();
                cantColores[arriba]--;
            }

            //DERECHA
            if (this->borde(fila,columna,DERECHA))
                derecha = 0;
            else
            {
                derecha = asignarValor(cantColores, colores);
                cantColores[derecha]--;
            }


            //ABAJO
            if (this->borde(fila,columna,ABAJO))
                abajo = 0;
            else
            {
                abajo = asignarValor(cantColores,colores);
                cantColores[abajo]--;
            }


            //IZQUIERDA
            if (this->borde(fila,columna,IZQUIERDA))
                izquierda = 0;
            else
            {
                izquierda = (getVecino(fila,columna,IZQUIERDA))->getDerecha();
                cantColores[izquierda]--;
            }

            Ficha *f;
            f = new Ficha;
            f->setArriba(arriba);
            f->setAbajo(abajo);
            f->setIzquierda(izquierda);
            f->setDerecha(derecha);
            f->setX(fila+1);
            f->setY(columna+1);
            return f;
        }
        
       
        // a partir de un arreglo de ficha ordenadas lo desordeno

        void generarPuzzle(int cantColores,int n)
        {
            this->n = n;
            for(int i=0;i<MAX;i++)
                for(int j=0;j<MAX;j++)
                    matriz[i][j] = NULL;
		    //cuantos subfichas de cada tipo puede haber?
            //(total subFichas - subFichas de borde) / cantSub

            
            int s = n*n*4-n*4;
            if (cantColores<=(s/2))
            {    
                int aux = s;

                if (aux%2 == 1)
                    cantColores++;

                s = int(s/cantColores);

                //crear un vector de tamaño cantSub inicializado todo en "s"
                int Colores[cantColores+1];
    
                for(int i=0;i<(cantColores+1);i++)
                    Colores[i]=s;

                
    
                for(int fil=0;fil<n;fil++)
                    for(int col=0;col<n;col++)
                        set(asignarFicha(fil,col,Colores,cantColores),fil,col);
            }
        }
        
        void rotarAzar(Ficha *fichas[])
        {
            int random;
			for (int pos=0;pos<n*n;pos++)
			{
                random = rand()%4;
                while (random > 0)
    			{
                      fichas[pos]->Rotar();
                      random--;
                }
            }
		}

        void mezclar(Ficha *elementos[])
        {
            Ficha *aux;
            int j;
            int t = (n*n)-1;
            while (t > 1)
            {
                j = rand()%n;
                aux = elementos[j];
                elementos[j] = elementos[t];
                elementos[t] = aux;
                t--;
            }
        }
        
        void armandoUno(Ficha *arreglo[])
        {
            for(int i=0;i<n*n;i++)
                    arreglo[i] = NULL;

            int pos=0;
            for (int i=0;i<n;i++)  
                for (int j=0;j<n;j++)  
                {
                    arreglo[pos] = get(i,j);
                    pos++;
                }

          for (int i=0;i<n;i++)
                for (int j=0;j<n;j++)
                    set(NULL,i,j);
        
       } 
        
        void Paso(Ficha *arreglo[])     
        {
            int pos = 0;
            for (int i=0;i<n;i++)
                for (int j=0;j<n;j++)
                {
                    set(arreglo[pos],i,j);
                    pos++;  
                }            
        }
        ~Tablero(){}
};

#endif // TABLERO_H
