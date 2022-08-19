/*
  Nome: NodoBinCur.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa il nodo dell'albero binario con cursore
*/

#ifndef NODOBINCUR_H
#define NODOBINCUR_H
#include "Nodo.h"
#define NIL -1

typedef int nodoBin;

class NodoBinCur: public Nodo{ // NodoCur estende Nodo
public:
   NodoBinCur(); 
   NodoBinCur(tipoelem);  // costruttore che inizializza l'etichetta
   NodoBinCur(tipoelem, nodoBin, nodoBin, nodoBin); // etichetta + sx dx dad
   ~NodoBinCur(); 
   
   nodoBin getSx();
	nodoBin getDx();
	nodoBin getDaddy();
	void setSx(nodoBin);
	void setDx(nodoBin);
	void setDaddy(nodoBin);
	
private:
	nodoBin sx, dx, daddy;
};

#endif
