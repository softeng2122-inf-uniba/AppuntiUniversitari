/*
  Nome: NodoBinPtr.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa il nodo dell'albero binario con puntatore
*/

#ifndef NODOBINPTR_H
#define NODOBINPTR_H
#include "Nodo.h"

class NodoBinPtr; // dichiarazione anticipata
typedef  NodoBinPtr *nodoBin;

class NodoBinPtr: public Nodo{
public:
	NodoBinPtr();
	NodoBinPtr(tipoelem);
	NodoBinPtr(tipoelem, nodoBin, nodoBin);
	~NodoBinPtr();
	
	nodoBin getSx();
	nodoBin getDx();
	nodoBin getDaddy();
	bool setSx(nodoBin);
	bool setDx(nodoBin);
	bool setDaddy(nodoBin);
	
private:
	nodoBin sx, dx, daddy;
};

#endif
