//IMPLEMENTAZIONE CLASSE NODO
#include "Nodo.h"
#include <iostream.h>
#include <stdlib.h>

Nodo::Nodo()
	{this->next=0;
    return;};

Nodo::~Nodo(){};

tipoelem Nodo::getElem()
	{return this->elem;};

posizione Nodo::getNext()
	{return this->next;};

void Nodo::setElem(tipoelem e)
	{this->elem=e; return;};

void Nodo::setNext(posizione p)
	{this->next=p; return;};


