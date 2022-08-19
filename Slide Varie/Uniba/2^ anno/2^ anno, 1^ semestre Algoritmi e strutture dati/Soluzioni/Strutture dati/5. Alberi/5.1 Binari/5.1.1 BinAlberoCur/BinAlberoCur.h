/*
  Nome: BinAlberoCur.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa l'albero binario con cursore
*/

#ifndef BINALBEROCUR_H
#define BINALBEROCUR_H

#include "NodoBinCur.h"
#define MAXLUNG 100

class BinAlberoCur{
public:
	BinAlberoCur();
	~BinAlberoCur();
	
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
	
	nodoBin pos(int);
private:
   
	NodoBinCur spazio[MAXLUNG];   //definizione del vettore spazio
   nodoBin primo; //radice
   nodoBin primoVuoto;
   int totNodi;
};

#endif
