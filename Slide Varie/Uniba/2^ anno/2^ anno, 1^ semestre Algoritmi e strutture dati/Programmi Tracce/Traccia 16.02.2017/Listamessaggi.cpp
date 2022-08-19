#include<iostream>
#include<stdio.h>
#include"ListaMessaggi.h"

ListaMessaggi::ListaMessaggi(){
    crealista();
}

ListaMessaggi::~ListaMessaggi(){

}

void ListaMessaggi::crealista(){
    inizio=0;
}

bool ListaMessaggi::listavuota(){
    return (inizio==0);
}

void ListaMessaggi::inserimento(){
    int scelta;
    string danome,dacognome,anome,acognome,messaggio;
    do{
        cout<<"Inserisci nome utente che deve inviare il messaggio\n";
        cin>>danome;
        cout<<"Inserisci cognome utente che deve inviare il messaggio\n";
        cin>>dacognome;
        cout<<"Inserisci nome utente che deve ricevere il messaggio\n";
        cin>>anome;
        cout<<"Inserisci cognome utente che deve ricevere il messaggio\n";
        cin>>acognome;
        cout<<"Inserisci il messaggio\n";
        cin>>messaggio;
        inseriscimessaggio(danome,dacognome,anome,acognome,messaggio);
        cout<<"Continuare? (1/0)\n";
        cin>>scelta;
    }while(scelta==1);
}

void ListaMessaggi::inseriscimessaggio(mess dan, mess dac, mess an,mess ac,mess mess){
    messaggio temp=new Messaggio;
    if(listavuota()==true){
        temp->setdacognomeutente(dac);
        temp->setdanomeutente(dan);
        temp->setanomeutente(an);
        temp->setacognomeutente(ac);
        temp->setmessaggio(mess);
        temp->setprec(0);
        temp->setsucc(0);
        inizio=temp;
    }
    else if(appartiene(n,c)==false){
        temp->setsucc(inizio);
        temp->setdacognomeutente(dac);
        temp->setdanomeutente(dan);
        temp->setanomeutente(an);
        temp->setacognomeutente(ac);
        temp->setmessaggio(messaggio);
        inizio->setprec(temp);
        inizio=temp;
    }else
        cout<<"\nElemento presente\n";
}

void LiataMessaggi::visualizzamessaggio(){
    messaggio temp=new Messaggio();
    temp=inizio;
    while(temp!=0){
        cout<<"DA: "<<temp->getdacognomeutente()<<"  "<<temp->getdanomeutente()<<"\n";
        cout<<"A: "<<temp->getacognomeutente()<<"  "<<temp->getanomeutente()<<"\n";
        cout<<"MESSAGGIO:\n";
        cout<<temp->getmessaggio()<<"\n";
        temp=temp->getsuc();
    }

}
