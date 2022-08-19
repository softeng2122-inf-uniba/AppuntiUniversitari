//IMPLEMENTAZIONE CLASSE NODO
#include "NodoCN.h"
#include <iostream.h>
#include <stdlib.h>

NodoCN::NodoCN()
	{this->next=0;
    return;};

NodoCN::~NodoCN(){};

cellap NodoCN::getElem()
	{return this->elem;};

posizione NodoCN::getNext()
	{return this->next;};

void NodoCN::setElem(cellap e)
	{this->elem=e; return;};

void NodoCN::setNext(posizione p)
	{this->next=p; return;};


