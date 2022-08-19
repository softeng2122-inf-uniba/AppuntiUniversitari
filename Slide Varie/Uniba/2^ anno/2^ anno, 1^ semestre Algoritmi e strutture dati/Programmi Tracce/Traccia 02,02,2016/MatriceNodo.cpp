#include"MatriceNodo.h"
#include<stdlib.h>
#include<stdio.h>

using namespace std;

void Nodo::creanodo(){
    this->suc=this->prec=0;
}

Nodo::Nodo(){
    creanodo();
}

Nodo::~Nodo(){

}

void Nodo::setriga(tipoelem e){
    this->r=e;
}

void Nodo::setcolonna(tipoelem e){
    this->c=e;
}

void Nodo::setvalore(tipoelem e){
    this->v=e;
}

void Nodo::setsuc(Nodo* p){
    this->suc=p;
}

void Nodo::setprec(Nodo* p){
    this->prec=p;
}

int Nodo::getvalore(){
    return this->v;
}

int Nodo::getcolonna(){
    return this->c;
}

int Nodo::getriga(){
    return this->r;
}

Nodo* Nodo::getsuc(){
    return this->suc;
}

Nodo* Nodo::getprec(){
    return this->prec;
}
