#ifndef _INSIEME_H
#define _INSIEME_H
#include "./Nodo.h"

class Insieme{
    private:
        posizione inizio;
    public:
        Insieme();
        ~Insieme();
        void creainsieme();
        bool insiemevuoto();
        bool appartiene(tipoelem); //verifica appartenenza di un elemento
        void inserisci(tipoelem);
        void cancella(tipoelem);
        void unione(Insieme);      //unione dell'insieme corrente con un altro
        void intersezione(Insieme);//intersez dell'insieme corrente con un altro
        void differenza(Insieme);  //differenza de insieme corrente con un altro
        void stampa();     			//stampa l'insieme
        void inserimento();
        posizione primolista();
};

#endif // _INSIEME_H
