//DEFINIZIONE DELLA CLASSE NODO per la coda avente come nodi
//dei puntatori ad elementi dell'albero binario
#ifndef NODOCB_H
#define NODOCB_H
#include "NodoBin.h"

class NodoCB{
	private:
   	cellap nodo;
      NodoCB* next;
   public:
   	NodoCB();
      ~NodoCB();
      cellap getElem();
      NodoCB* getNext();
      void setElem(cellap);
      void setNext(NodoCB*);
};//end-class
typedef NodoCB* posizione;
#endif