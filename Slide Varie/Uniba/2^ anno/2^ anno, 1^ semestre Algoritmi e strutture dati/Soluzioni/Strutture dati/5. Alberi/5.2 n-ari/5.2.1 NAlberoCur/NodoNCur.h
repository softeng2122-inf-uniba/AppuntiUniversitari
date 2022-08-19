/*
  Nome: NodoNCur.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa il nodo dell'albero n-ario con cursore
*/

#ifndef NODONCUR_H
#define NODONCUR_H
#include "Nodo.h"
#define NIL -1

typedef int nodoN; // cursore al nodo

class NodoNCur: public Nodo{
public:
	NodoNCur();
	NodoNCur(tipoelem);
	NodoNCur(tipoelem, nodoN, nodoN, nodoN);
	~NodoNCur();
	
	nodoN getFirstSon();
	nodoN getNextBro();
	nodoN getDaddy();
	void setFirstSon(nodoN);
	void setNextBro(nodoN);
	void setDaddy(nodoN);
	
private:
	nodoN daddy, firstSon, nextBro;
};

#endif
