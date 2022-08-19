#ifndef UTENTELISTA_H
#define UTENTELISTA_H
#include"UtenteNodo.h"
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;
class Utentelista{
    private:
        nodo inizio,ultimo;
    public:
        Utentelista();
        ~Utentelista();
        void crealista();
        void crealista();
        bool listavuota();
        nodo primolista(nodo);
        nodo preclista(nodo);
        nodo suclista(nodo);
        void aggiungiProdotto(string);
        void resgistraUtente(nodo,string,string);
        void gradisce(nodo,string,string,string,int);
        int gradimento(string);
        float mediaGradimenti(string);
        int gradimentiSimili(string,string);
        void inserisci(nodo,string,string,string,int);
        void inserimento();
        void visualizza();

};

#endif // UTENTELISTA_H
