#ifndef LISTAPTR_H
#define LISTAPTR_H
#include "Nodoptr.h"

//DEFINIZIONE DELLA CLASSE LISTA
class Lista{
private:
    posizione begin,		//puntatore al primo elemento della lista
    			  end;		//puntatore all'ultimo elemento della lista
public:
    Lista();      		//costruttore
    ~Lista();           //distruttore

    void crealista();
    bool listavuota();
    posizione primolista();
    posizione ultimolista();
    bool finelista(posizione);
    tipoelem leggi(posizione);
    void scrivi(posizione, tipoelem);
    void cancella(posizione);
    void inserisci(posizione, tipoelem);
    posizione succlista(posizione);
    posizione predlista(posizione);
    void stampa();                //operatore aggiuntivo x la stampa
    posizione cerca(tipoelem);    //operatore aggiuntivo
    										 //per la ricerca di un elemento

};
#endif
