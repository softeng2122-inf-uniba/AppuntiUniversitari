//definizione della classe coda adattata ai nodi dell'albero binario
#ifndef CODA_H
#define CODA_H
#include "NodoCB.h"
class Coda{
	private:
   	posizione testa;   //puntatore alla testa della coda
      posizione fondo;	 //puntatore al fondo della coda
   public:
   	Coda();
      ~Coda();
      void creacoda();
      bool codavuota();
      cellap leggicoda();
      void fuoricoda();
      void incoda(cellap);
      void stampa();   //operatore aggiuntivo per la stampa del contenuto
};//end-class
#endif