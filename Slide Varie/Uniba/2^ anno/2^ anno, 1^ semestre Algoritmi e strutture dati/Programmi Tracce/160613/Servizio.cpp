#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"ClasseStringa.h"
#include"Servizio.h"
#include"Listastringa.h"

using namespace std;




void eo_strings::inserisci(tipoelem s){
    int dimensione;
    int resto;
    dimensione=strlen(s);
    resto=dimensione;
    Stringa temp=new stringa;
    while(resto!=0){
        resto=resto-2;
    }
    if(resto==0){
        if(pari.vuota()){
            temp->setprec(0);
            temp->setsuc(0);
            inizio=ultimo=temp;
        }
        else{
            ultimolista()->setsucc(temp);
            temp->setsucc(0);
            temp->setpred(ultimolista());
            ultimo = temp;
        }

    }
    else{
        if(dispari.vuota()){
            temp->setprec(0);
            temp->setsuc(0);
            inizio=ultimo=temp;
        }
        else{
            ultimolista()->setsucc(temp);
            temp->setsucc(0);
            temp->setpred(ultimolista());
            ultimo = temp;
        }
    }
}
void eo_strings::rimuovi(tipoelem s){
    bool trovato;
}
void eo_strings::rimuovi(char c);
int eo_strings::freq_pari();
void eo_strings::visualizza_dispari();

