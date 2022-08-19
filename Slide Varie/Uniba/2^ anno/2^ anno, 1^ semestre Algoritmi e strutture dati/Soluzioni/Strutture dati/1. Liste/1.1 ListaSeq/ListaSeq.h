/*
  Nome: ListaSeq.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa la lista sequenziale
*/

#ifndef LISTASEQ_H
#define LISTASEQ_H

#include "Nodo.h"
#define MAXLUNG 100
#define NIL -1

typedef int posizione;

class ListaSeq{
public:
   ListaSeq(); // costruttore
   ~ListaSeq(); // distruttore
   
   void creaLista();
   bool listaVuota();
   posizione primoLista();
   
   posizione predLista(posizione);
   posizione succLista(posizione);
   bool fineLista(posizione);
   
   bool insLista(tipoelem, posizione);
   bool cancLista(posizione);
   bool scriviLista(tipoelem, posizione);
   bool leggiLista(tipoelem &, posizione);

   posizione pos(int);
private:   
   
   Nodo lista[MAXLUNG];
   posizione primo;
   int lunghezza;
};

#endif
