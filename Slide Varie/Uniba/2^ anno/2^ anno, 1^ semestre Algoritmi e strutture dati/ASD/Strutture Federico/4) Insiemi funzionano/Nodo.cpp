#include<stdlib.h>
#include<iostream>
#include "./Nodo.h"

using namespace std;

Nodo::Nodo(){
     this->succ=this->prec=0;
}

Nodo::~Nodo(){

}

void Nodo::setelem(tipoelem e)
{
    elemento=e;
    return;
}

void Nodo::setsucc(posizione p)
{
    this->succ=p;
    return;
}

void Nodo::setprec(posizione p)
{
    this->prec=p;
    return;
}

posizione Nodo::getprec()
{
    return this->prec;
}

posizione Nodo::getsucc()
{
    return this->succ;
}

tipoelem Nodo::getelem()
{
    return this->elemento;
}
