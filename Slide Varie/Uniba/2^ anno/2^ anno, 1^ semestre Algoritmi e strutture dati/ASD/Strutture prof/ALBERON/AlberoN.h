#ifndef ALBERON_H
#define ALBERON_H
#include "NodoN.h"
class AlberoN{
private:
	cellap radice;

public:
	AlberoN();
   ~AlberoN();
   void creaalbero();
   bool alberovuoto();
   void insradice();
   cellap dairadice();
   cellap primofiglio(cellap);
   cellap padre(cellap);
   bool foglia(cellap);
   bool ultimofratello(cellap);
   cellap succfratello(cellap);
   void scrivinodo(tipoelem, cellap);
   tipoelem legginodo(cellap);
   void insprimofiglio(cellap);
   void insaltrofiglio(cellap);
   void inssottoalbero(cellap);
   void previsita(cellap);
   void postvisita(cellap);
   int numero_nodi(cellap);
   int profondita(cellap);
   void visita_livello();
};
#endif