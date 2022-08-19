/*
  Nome: ListaCur.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa la lista con cursore
*/

#ifndef LISTACUR_H
#define LISTACUR_H

#include "NodoCur.h"
#define MAXLUNG 100

class ListaCur{
public:
   ListaCur(); // costruttore
   ~ListaCur(); // distruttore
   
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
   void spostaNodo(posizione &, posizione &);
   
   NodoCur spazio[MAXLUNG];   //definizione del vettore spazio
   posizione primo;
   posizione primoVuoto;
   int lunghezza;
};

#endif
