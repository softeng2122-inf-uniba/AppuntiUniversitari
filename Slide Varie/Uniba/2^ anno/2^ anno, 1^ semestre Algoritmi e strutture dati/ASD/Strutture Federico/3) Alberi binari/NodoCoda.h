#ifndef _NODOCODA_H
#define _NODOCODA_H
#include "./NodoBinario.h"

class NodoCoda{

	private:
        cellap nodo;
        NodoCoda* next;
    public:
        NodoCoda();
        ~NodoCoda();
        cellap getElem();
        NodoCoda* getNext();
        void setElem(cellap);
        void setNext(NodoCoda*);
};//end-class
typedef NodoCoda* posizione;

#endif // _NODOCODA_H
