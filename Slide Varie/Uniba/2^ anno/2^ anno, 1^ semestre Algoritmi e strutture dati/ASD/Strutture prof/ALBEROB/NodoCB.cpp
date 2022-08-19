//IMPLEMENTAZIONE CLASSE NODO della coda
#include "NodoCB.h"
#include <iostream.h>
#include <stdlib.h>

NodoCB::NodoCB()
	{this->next=0;
    return;};

NodoCB::~NodoCB(){};

cellap NodoCB::getElem()
	{return this->nodo;};

posizione NodoCB::getNext()
	{return this->next;};

void NodoCB::setElem(cellap e)
	{this->nodo=e; return;};

void NodoCB::setNext(posizione p)
	{this->next=p; return;};


