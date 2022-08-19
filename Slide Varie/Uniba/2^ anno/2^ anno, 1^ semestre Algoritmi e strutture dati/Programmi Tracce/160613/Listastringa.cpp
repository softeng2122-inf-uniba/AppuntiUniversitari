#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"Listastringa.h"

Listastringa(){
    crealista();
}
~Listastringa(){}
void crealista(){
    inizio=ultimo=0;
}
bool vuota(){
    return inizio==0;
}
Stringa primolista(){
    return inizio;
}
Stringa ultimolista(){
    return ultimo;
}


