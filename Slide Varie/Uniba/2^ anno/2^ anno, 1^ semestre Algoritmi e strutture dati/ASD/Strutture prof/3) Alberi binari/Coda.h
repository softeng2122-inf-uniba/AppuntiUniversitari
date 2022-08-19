#ifndef _CODA_H
#define _CODA_H
#include "./NodoCoda.h"

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
};typedef Coda coda;

#endif // _CODA_H
