#include "Nodo.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Nodo::Nodo(){
    this->succ=this->prec=0;
}

Nodo::~Nodo(){

}

void Nodo::setesponente(tipoelem e){
    esponente=e;
    return;
}

void Nodo::setcoefficiente(tipoelem e){
    coefficiente=e;
    return;
}

void Nodo::setsucc(polinomio p){
    this->succ=p;

}

void Nodo::setprec(polinomio p){
    this->prec=p;
    return;
}

tipoelem Nodo::getcoefficiente(){
    return this->coefficiente;
}

tipoelem Nodo::getesponente(){
    return this->esponente;
}

polinomio Nodo::getsucc(){
    return this->succ;
}

polinomio Nodo::getprec(){
    return this->prec;
}
