//definizione della classe coda
#ifndef CODA_H
#define CODA_H
#include "Nodo.h"
class Coda{
	private:
   	posizione testa;   //puntatore alla testa della coda
      posizione fondo;	 //puntatore al fondo della coda
   public:
   	Coda();
      ~Coda();
      void creacoda();
      bool codavuota();
      tipoelem leggicoda();
      void fuoricoda();
      void incoda(tipoelem);
      void stampa();   //operatore aggiuntivo per la stampa del contenuto
};//end-class
#endif