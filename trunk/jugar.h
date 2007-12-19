
#ifndef JUGAR_H
#define JUGAR_H

class Jugar: Eternity
{
	private:
        int N;
        int cantColores;
        
        bool poda(Tablero *t,Ficha *hijo,int fila,int columna)
        {
            int arriba; //lo que hay arriba de HIJO
            int derecha; //lo que hay a la derecha de HIJO
            int abajo; //idem
            int izquierda; //idem
            
            bool compArriba, compAbajo, compIzquierda, compDerecha;
            
			//que neceisto tener ARRIBA para ser compatible?
            if (fila == 0)
                arriba = 0;
            else
                arriba = (t->get(fila-1,columna))->getAbajo();
			compArriba = (hijo->getArriba() == arriba);
            
			//que neceisto tener a IZQUIERDA para ser compatible?
            if (columna == 0)
                izquierda = 0;
            else
                izquierda = (t->get(fila,columna-1))->getDerecha();
			compIzquierda = (hijo->getIzquierda() == izquierda);

			//que neceisto tener ABAJO para ser compatible?
            if (fila == N-1)
            {
                abajo = 0;
                compAbajo = (hijo->getAbajo() == abajo);
            }
            else
				//mientras que no sea un 0, ABAJO puedo tener cualquier cosa
				compAbajo = (hijo->getAbajo() != 0);

			//que neceisto tener a DERECHA para ser compatible?
            if (columna == N-1)
            {
                derecha = 0;
                compDerecha = (hijo->getDerecha() == derecha);
            }
            else
				//mientras que no sea un 0, a la DERECHA puedo tener cualquier cosa
				compDerecha = (hijo->getDerecha() != 0);
            
            return !(compArriba && compDerecha && compAbajo && compIzquierda);
        
        }

	    bool solucion(Tablero *t)
	    {
            int i=0;
            int j;
            bool ningunNull = true;
            while ((i<N) && (ningunNull))
            {
                j=0;
                while ((j<N) && (ningunNull))
                {
                    if (t->get(i,j) == NULL)
                        ningunNull = false;
                    j++;
                }
                i++;
            }
            return ningunNull;
        }
  
        void back(Tablero *t,Ficha *fichas[],int fila, int columna, bool visitado[],int &c, int nivel)
        {
			if (nivel>0)
            {
                if (solucion(t))
    			{
                    c++;
                }
                else
    	        {
                   for (int nroFicha = 0 ; nroFicha<N*N ; nroFicha++)
                        for (int rotaciones = 0;rotaciones<4 && !visitado[nroFicha];rotaciones++)
                        {
                            if (!poda(t,fichas[nroFicha],fila,columna))
                            {
        					   t->set(fichas[nroFicha],fila,columna);
        					   t->get(fila,columna)->setX(fila+1);
        					   t->get(fila,columna)->setY(columna+1);
        					   visitado[nroFicha] = true;
    	                       if ((columna == N-1) && (fila < N-1))
        	                    	back(t,fichas,fila+1,0,visitado,c,nivel-1);
        	                    else
        	                       	if (columna < N-1)
        								back(t,fichas,fila,columna+1,visitado,c,nivel-1);
        							else
        								//solo en la ultima... ubiqué todas las fichas!
        								back(t,fichas,fila,columna,visitado,c,nivel-1);

        					    if (c==0)
                            	{	
                                    visitado[nroFicha]=false;
        	                       	t->set(NULL,fila,columna);
                                }
                            }
                            if (c==0)
        	                    fichas[nroFicha]->Rotar();
                        }
            }
        }
    }
 
    public:
		// class constructor
		Jugar(int p,int c)
        {    
            N = p;
            cantColores = c;
        }
        
		void Resolver(Tablero* t,Ficha* f[])
		{
            bool visitado[N*N];
            for (int i=0;i<N*N;i++)
                visitado[i] = false;
            int contador = 0;
            int nivel = (N*N*3)+1;
            this->back(t,f,0,0,visitado,contador,nivel);
        }
		~Jugar(){}
};

#endif // JUGAR_H
