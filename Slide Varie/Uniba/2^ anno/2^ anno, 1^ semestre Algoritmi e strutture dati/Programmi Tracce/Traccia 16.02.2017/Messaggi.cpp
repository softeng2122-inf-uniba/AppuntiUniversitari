#include <iostream>
#include <stdio.h>
#include<string.h>
#include"Messaggi.h"

using namespace std;

Messaggio::Messaggio(){
    this->prec=this->suc=0;
}

Messaggio::~Messaggio(){

}

void Messaggio::setmessaggio(mess e){
    strcpy(this->messaggio,e);
}

void Messaggio::setanomeutente(mess e){
    strcpy(this->anomeutente,e);
}

void Messaggio::setacognomeutente(mess e){
    strcpy(this->acognomeutente,e);
}

void Messaggio::setdacognomeutente(mess e){
    strcpy(this->dacognomeutente,e);
}

void Messaggio::setdanomeutente(mess e){
    strcpy(this->danomeutente,e);
}

void Messaggio::setprec(messaggio p){
    this->prec=p;
}

void Messaggio::setsuc(messaggio p){
    this->prec=p;
}

mess Messaggio::getmessaggio(){
    return this->messaggio;
}

messaggio* Messaggio::getprec(){
    return this->pec;
}

messaggio* Messaggio::getsuc(){
    return this->suc;
}

mess Messaggio::getdanomeutente(){
    return this->danomeutente;
}

mess Messaggio::getdacognomeutente(){
    return this->dacognomeutente;
}

mess Messaggio::getanomeutente(){
    return this->anomeutente;
}

mess Messaggio::getacognomeutente(){
    return this->acognomeutente;
}
