#include<stdio.h>
#include<iostream>
#include "Nodo.h"
#include<string.h>

using namespace std;

Nodo::Nodo(){
    this->suc=this->prec=0;
}

Nodo::~Nodo(){

}

 void Nodo::setprec(elemento p){
    this->prec=p;
}

void Nodo:: setsucc(elemento p){
    this->suc=p;
}

 void Nodo::setcognome(tipoelem p){
    strcpy(this->cognome,p);
}

 void Nodo::setnome(tipoelem p){
    strcpy(this->nome,p);
}

tipoelem Nodo::getcognome(){
    return this->cognome;
}
tipoelem Nodo::getnome(){
    return this->nome;
}

Nodo* Nodo::getprec(){
    return this->prec;
}

Nodo* Nodo::getsuc(){
    return this->suc;
}
