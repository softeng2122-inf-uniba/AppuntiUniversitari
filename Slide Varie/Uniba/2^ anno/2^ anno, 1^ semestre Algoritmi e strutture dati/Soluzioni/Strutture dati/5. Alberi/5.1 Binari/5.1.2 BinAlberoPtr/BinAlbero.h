/*
  Nome: BinAlbero.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa l'albero binario con puntatore
*/

#ifndef BINABERO_H
#define BINALBERO_H
#include "NodoBinPtr.h"

class BinAlbero{
public:
	BinAlbero();
	~BinAlbero();
	
	void creaBinAlbero();
	bool binAlberoVuoto();
	
	nodoBin binRadice();
	nodoBin binPadre(nodoBin);
	nodoBin figlioSx(nodoBin);
	nodoBin figlioDx(nodoBin);
	bool sxVuoto(nodoBin);
	bool dxVuoto(nodoBin);
	
	bool insBinRadice(nodoBin);
	bool insFiglioSx(nodoBin);
	bool insFiglioDx(nodoBin);
	
	void cancSottoBinAlbero(nodoBin);
	
	bool leggiNodo(nodoBin, tipoelem &);
	bool scriviNodo(nodoBin, tipoelem);
	
private:
	nodoBin radice;
};

#endif
