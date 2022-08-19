#include"oggetto.h"
#include<string.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

Oggetto::Oggetto(){
    this->suc=this->prec=0;
}

Oggetto::~Oggetto(){

}

void Oggetto::setnome(tipoelem p){
    this->nome=p;
}

void Oggetto::setsuc(Oggetto* p){
    this->suc=p;
}

void Oggetto::setprec(Oggetto* p){
    this->prec=p;
}

tipoelem Oggetto::getnome(){
    return this->nome;
}

Oggetto* Oggetto::getsuc(){
    return this->suc;
}

Oggetto* Oggetto::getprec(){
    return this->prec;
}

