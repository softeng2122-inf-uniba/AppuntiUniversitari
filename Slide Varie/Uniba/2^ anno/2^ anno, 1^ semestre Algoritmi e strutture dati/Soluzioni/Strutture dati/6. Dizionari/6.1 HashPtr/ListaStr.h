/*
  Nome: ListaStr.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa la lista di stringhe
*/

#ifndef LISTASTR_H
#define LISTASTR_H

#include "NodoStr.h"

class ListaStr{
public:
   ListaStr(); // costruttore
   ~ListaStr(); // distruttore
   
   void creaLista();
   bool listaVuota();
   posizione primoLista();
   
   posizione predLista(posizione);
   posizione succLista(posizione);
   bool fineLista(posizione);
   
   void insLista(tipoelem, posizione);
   bool cancLista(posizione);
   bool scriviLista(tipoelem, posizione);
   bool leggiLista(tipoelem &, posizione);
   
	ListaStr &operator=(ListaStr &);
 	posizione pos(int); // mapping della posizione

private:
   posizione primo;
};

#endif
