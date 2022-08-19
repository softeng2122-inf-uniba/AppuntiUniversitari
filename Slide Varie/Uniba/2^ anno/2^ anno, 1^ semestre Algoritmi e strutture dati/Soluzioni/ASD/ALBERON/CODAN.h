//definizione della classe coda
#ifndef CODAN_H
#define CODAN_H
#include "NodoCN.h"
class CodaN{
	private:
   	posizione testa;   //puntatore alla testa della coda
      posizione fondo;	 //puntatore al fondo della coda
   public:
   	CodaN();
      ~CodaN();
      void creacoda();
      bool codavuota();
      cellap leggicoda();
      void fuoricoda();
      void incoda(cellap);
      void stampa();   //operatore aggiuntivo per la stampa del contenuto
};//end-class
#endif