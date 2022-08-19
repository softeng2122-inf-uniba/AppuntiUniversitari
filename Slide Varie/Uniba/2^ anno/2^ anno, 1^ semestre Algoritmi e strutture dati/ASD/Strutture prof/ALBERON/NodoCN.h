//DEFINIZIONE DELLA CLASSE NODO 
#ifndef NODOCN_H
#define NODOCN_H
//typedef int tipoelem;
#include "NodoN.h"
class NodoCN{
	private:
   	cellap elem;
      NodoCN* next;
   public:
   	NodoCN();
      ~NodoCN();
      cellap getElem();
      NodoCN* getNext();
      void setElem(cellap);
      void setNext(NodoCN*);
};//end-class
typedef NodoCN* posizione;
#endif