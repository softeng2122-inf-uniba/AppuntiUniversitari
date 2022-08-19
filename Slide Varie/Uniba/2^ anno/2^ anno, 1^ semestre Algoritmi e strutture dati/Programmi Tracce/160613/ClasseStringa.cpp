#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"ClasseStringa.h"

using namespace std;

stringa(){
    this->suc=this->prec=0;
}
~stringa(){

}
void stringa::setstr(tipoelem n){
    str=n;
}
void stringa::setsuc(Stringa p){
    this->suc=p;
}
void stringa::setprec(Stringa p){
    this->prec=p;
}
tipoelem stringa::getvalore(){
    return str;
}
stringa* stringa::getsuc(){
    return this->suc;
}
stringa* stringa::getprec(){
    return this->prec;
}
