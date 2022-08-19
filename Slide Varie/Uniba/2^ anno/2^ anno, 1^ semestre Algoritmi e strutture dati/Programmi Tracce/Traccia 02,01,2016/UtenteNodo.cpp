#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"UtenteNodo.h"

using namespace std;

Utentenodo::Utentenodo(){
    this->suc=this->prec=0;
}

Utentenodo::~Utentenodo(){

}

void Utentenodo::setnome(string e){
    strcpy(nome,e);
}
void Utentenodo::setcognome(string e){
    strcpy(cognome,e);
}
void Utentenodo::setprodotto(string e){
    strcpy(prodotto,e);
}
void Utentenodo::setgradimento(int e){
    gradimento=e;
}
void Utentenodo::setsuc(nodo p){
    this->suc=p;
}
void Utentenodo::setprec(nodo p){
    this->prec=p;
}
string Utentenodo::getnome(){
    return this->nome;
}
string Utentenodo::getcognome(){
    return this->cognome;
}
string Utentenodo::getprodotto(){
    return this->prodotto;
}
int Utentenodo::getgradimento(){
    return this->gradimento;
}
nodo Utentenodo::getsuc(){
    return this->suc;
}
nodo Utentenodo::getprec(){
    return this->prec;
}
