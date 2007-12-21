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
        int N;
        
        /* Funcion utilizada para generar un puzzle.
         * Para generar una ficha. Esta función retorna un color.
         * Lleva un conteo de los colores que ubica en "arreglo"
         */
        int asignarValor(int *arreglo, int colores)
        {
                int random = rand()%colores+1;
                if (arreglo[random]>0)
                    return random;
                else
                    return asignarValor(arreglo,colores);
        }

		/* Funcion utilizada para generar un puzzle.
		 * Dada una posicion devuelve al azar una ficha a ubicar.		 * 
		 */
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
        

	public:
        Tablero()
        {
            for(int i=0;i<MAX;i++)
                for(int j=0;j<MAX;j++)
                    matriz[i][j] = NULL;
			this->N = MAX;
        }
        
        int getN()
        {
            return N;
        }
        
        void setN(int N)
        {
        	this->N = N;
        }

        Ficha* get(int fila, int columna)
        {
            return this->matriz[fila][columna];
        }

        //Devuelve el vecino correspondiente a la ficha ubicada en (fila,columna).
        Ficha* getVecino(int fila, int columna, int orientacion)
        {
            if (orientacion == ARRIBA)
                return (this->get(fila-1,columna));
            else
                if (orientacion == DERECHA)
                    return (this->get(fila,columna+1));
                else
                    if (orientacion == ABAJO)
                        return (this->get(fila+1,columna));
                    else
                        if (orientacion == IZQUIERDA)
                            return (this->get(fila,columna-1));
        }
        
        //Determina si la posicion (fila,columna) se ubica sobre el borde del tablero
        bool borde(int fila, int columna, int orientacion)
        {
            if (orientacion == ARRIBA)
                return (fila==0);
            else
                if (orientacion == DERECHA)
                    return (columna==N-1);
                else
                    if (orientacion == ABAJO)
                        return (fila==N-1);
                    else
                        if (orientacion == IZQUIERDA)
                            return (columna==0);
                        else
                            return false;
        }
        
        //Ubica una Ficha f en una posición del Tablero.
	    void set(Ficha* f, int fila, int columna)
        {
            this->matriz[fila][columna] = f;
        }
       
        // Crea al azar un tablero con fichas (puzzle resuelto).
        void generarPuzzle(int cantColores,int n)
        {
		    //cuantos subfichas de cada tipo puede haber?
            //(total subFichas - subFichas de borde) / cantSub
            
			this->setN(n);

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
        
        //Rota varias veces al azar las fichas contenidas en "fichas". 
		void rotarAzar(Ficha *fichas[])
        {
            int random;
			for (int pos=0;pos<N*N;pos++)
			{
                random = rand()%4;
                while (random > 0)
    			{
                      fichas[pos]->Rotar();
                      random--;
                }
            }
		}
		
		//randomiza las posiciones de las fichas dentro del arreglo elementos.
        void mezclar(Ficha *elementos[])
        {
            Ficha *aux;
            int j;
            int t = (N*N)-1;
            while (t > 1)
            {
                j = rand()%N;
                aux = elementos[j];
                elementos[j] = elementos[t];
                elementos[t] = aux;
                t--;
            }
        }
        
        /*Pasa las Fichas del Tablero a arreglo
         * Setea todo el Tablero a NULL
         * */
        void toArreglo(Ficha *arreglo[])
        {
            for(int i=0;i<N*N;i++)
                    arreglo[i] = NULL;

            int pos=0;
            for (int i=0;i<N;i++)  
                for (int j=0;j<N;j++)  
                {
                    arreglo[pos] = get(i,j);
                    pos++;
                }

          for (int i=0;i<N;i++)
                for (int j=0;j<N;j++)
                    set(NULL,i,j);
        
       } 
        
        //A partir de un arreglo de Fichas*, completa el Tablero.
        void fromArreglo(Ficha *arreglo[])     
        {
            int pos = 0;
            for (int i=0;i<N;i++)
                for (int j=0;j<N;j++)
                {
                    set(arreglo[pos],i,j);
                    pos++;  
                }
        }
        
        ~Tablero(){}
};

#endif // TABLERO_H
