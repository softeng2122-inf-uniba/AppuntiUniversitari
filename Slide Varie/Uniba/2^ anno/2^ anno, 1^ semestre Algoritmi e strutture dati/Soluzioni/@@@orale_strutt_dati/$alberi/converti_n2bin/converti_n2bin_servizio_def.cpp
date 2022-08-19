
/*definizione di funzioni di servizio per:

- Costruire interattivamente l'albero n-ario
- Visita e stampa dell'albero in preordine
- Conversione dell'albero n-ario in albero binario
- Calcolo del numero di nodi

*/




#include <stdlib.h>
#include <iostream.h>


//definizione delle funzione ricorsiva di conversione

void converti(Alberon T, Alberobin &B, Alberon :: nodo t, Alberobin :: nodo b)
	{
//esame dell'eventuale primofiglio di t
      if(!T.foglia(t))
      	{
            B.insfigliosinistro(b);
            B.scrivinodo(T.legginodo(T.primofiglio(t)),B.figliosinistro(b));
         	converti(T,B,T.primofiglio(t),B.figliosinistro(b));
         }


//esame dell'eventuale fratello successivo di t
      Alberon :: nodo v=T.succfratello(t);
      if(v!=NULL)
         {
            B.insfigliodestro(b);
            B.scrivinodo(T.legginodo(T.succfratello(t)),B.figliodestro(b));
         	converti(T,B,T.succfratello(t),B.figliodestro(b));
         }
   }

