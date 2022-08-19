//implementazione della classe Nodoptr
#include <iostream.h>
#include <stdlib.h>
#include "Nodoptr.h"

Nodoptr::Nodoptr()
	{this->succ=this->pred=0;};

Nodoptr::~Nodoptr()
	{};

void Nodoptr::setelem(tipoelem e)
	{elem=e; return;};

void Nodoptr::setsucc(posizione p)
{this->succ=p; return;};

void Nodoptr::setpred(posizione p)
{this->pred=p; return;};

tipoelem Nodoptr::getelem()
{return this->elem;};

posizione Nodoptr::getsucc()
{return this->succ;};

posizione Nodoptr::getpred()
{return this->pred;};

