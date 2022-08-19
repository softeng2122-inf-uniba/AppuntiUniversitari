/*
  Nome: NAlbero.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa l'albero n-ario con cursore
*/

#ifndef NALBERO_H
#define NALBERO_H
#include "NodoNCur.h"
#define MAXLUNG 100

class NAlbero{
public:
	NAlbero();
	~NAlbero();
	
	void creaNAlbero();
	bool nAlberoVuoto();
	bool insRadice(nodoN);
	nodoN radice();
	nodoN padre(nodoN);
	bool foglia(nodoN);
	nodoN primoFiglio(nodoN);
	bool ultimoFratello(nodoN);
	nodoN succFratello(nodoN);
	bool insPrimoSottoAlbero(nodoN, nodoN);
	bool insSottoAlbero(nodoN, nodoN);
	bool cancSottoAlbero(nodoN);
	
	tipoelem leggiNodo(nodoN);
	bool scriviNodo(nodoN, tipoelem);
	
	nodoN newNodo();
	
private:
   nodoN root, primoVuoto;
   NodoNCur spazio[MAXLUNG];   
};

#endif // NALBERO_H
