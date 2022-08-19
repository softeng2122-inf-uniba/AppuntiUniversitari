#include<stdio.h>
#include<iostream>
#include"Insieme.h"
#include <string.h>

using namespace std;

void Insieme::creaRete(){
    inizio=0;
}

bool Insieme::vuota(){
    return(inizio==0);
}

void Insieme::inserimento(){
    int scelta;
    string nome,cognome;
    do{
        cout<<"Inserisci nome utente\n";
        cin>>nome;
        cout<<"Inserisci cognome utente\n";
        cin>>cognome;
        aggiungiUtente(nome,cognome);
        cout<<"Continuare? (1/0)\n";
        cin>>scelta;
    }while(scelta==1);
}

void Insieme::aggiungiUtente(tipoelem n, tipoelem c){
    elemento temp=new Nodo;
    if(vuota==true){
        temp->setnome(n);
        temp->setcognome(c);
        temp->setprec(0);
        temp->setsucc(0);
        inizio=temp;
    }
    else if(appartiene(n,c)==false){
        temp->setsucc(inizio);
        temp->setnome(n);
        temp->setcognome(c);
        inizio->setprec(temp);
        inizio=temp;
    }else
        cout<<"\nElemento presente\n";
}

bool Insieme::appartiene(tipoelem n,tipoelem c){
    elemento temp= new Nodo();
    bool trovato=false;
    if(vuota()==false) {
            temp=inizio;
            do{
                if(strcmp(n,temp->getnome())==0 && strcmp(c,temp->getcognome())==0)
                    trovato=true;
                temp=temp->getsucc();
            }while((temp!=0) && (trovato!=false));
    }
    return (trovato);
}



