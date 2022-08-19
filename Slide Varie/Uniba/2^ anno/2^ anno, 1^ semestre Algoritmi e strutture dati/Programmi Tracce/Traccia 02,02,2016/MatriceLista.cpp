#include"MatriceLista.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

Lista::Lista(){
    crea();
}

Lista::~Lista(){

}

void Lista::crea(){
    inizio=ultimo=0;
}

bool Lista::vuota(){
    return inizio==0;
}

campo Lista::primonodo(){
    return inizio;
}

campo Lista::ultimonodo(){
    return ultimo;
}

void Lista::inserisci(){
    int valore,riga,colonna,scelta;
    do{
        cout<<"Inserisci la riga\n";
        cin>>riga;
        cout<<"Inserisci la colonna\n";
        cin>>colonna;
        cout<<"Inserisci il valore\n";
        cin>>valore;
        aggiungi(0,riga,colonna,valore);
        cout<<"Continuare?(1/0)\n";
        cin>>scelta;
    }while(scelta!=0);
}

void Lista::aggiungi(campo p,tipoelem r,tipoelem c,tipoelem v){
    campo temp=new Nodo;
    temp->setcolonna(c);
    temp->setriga(r);
    temp->setvalore(v);
    if(vuota())
        {
            temp->setsuc(0);
            temp->setprec(0);
            inizio=ultimo=temp;
        }
    else if(p==this->primonodo())
        {
            primonodo()->setprec(temp);
            temp->setsuc(primonodo());
            inizio=temp;
        }
    else if(p==0)
        {
            ultimonodo()->setsuc(temp);
            temp->setsuc(0);
            temp->setprec(ultimonodo());
            ultimo = temp;
        }
    else
        {
            p->getprec()->setsuc(temp);
            temp->setprec(p->getprec());
            temp->setsuc(p);
            p->setprec(temp);
        }
}

void Lista::rimuovi(tipoelem r,tipoelem c){
    campo temp=new Nodo;
    temp=inizio;
    bool trovato=false;
    while(temp!=0&&trovato==false)
    {
        if(temp->getriga()==r&&temp->getcolonna()==c){
            temp->setvalore(0);
            trovato=true;
        }
        temp=temp->getsuc();
    }
}

int Lista::leggi(tipoelem r, tipoelem c){
    campo temp=new Nodo;
    temp=inizio;
    while(temp!=0){
        if(temp->getriga()==r && temp->getcolonna()==c){
            return temp->getvalore();
        }
        temp=temp->getsuc();
    }
}

void Lista::visualizza(){
    campo temp=new Nodo;
    temp=inizio;
    while(temp!=0){
        cout<<"Riga: "<<temp->getriga()<<" Colonna: "<<temp->getcolonna()<<" Valore: "<<temp->getvalore()<<"\n";
        temp=temp->getsuc();
    }
}

Lista Lista::somma(Lista m){
    Lista s;
    campo temp=new Nodo;
    temp=s.inizio;
    campo temp2=new Nodo;
    campo temp3=new Nodo;
    temp2=this->inizio;
    temp3=m.inizio;
    while(temp2!=0)
    {
        campo n=new Nodo;
        n->setcolonna(temp2->getcolonna());
        n->setriga(temp2->getriga());
        if(s.vuota())
        {
            s.inizio=n;
            s.ultimo=n;
            n->setprec(NULL);
            n->setsuc(NULL);
        }
        else{
            s.ultimo->setsuc(n);
            n->setprec(s.ultimo);
            n->setsuc(NULL);
            s.ultimo=n;
        }
        temp2=temp2->getsuc();
    }
    int so;

    temp3=inizio;
    while(temp3!=0)
    {
        temp2=s.inizio;
        while(temp2!=0)
        {
            if(temp3->getcolonna()==temp2->getcolonna() && temp3->getriga()==temp2->getriga())
                {
                    so=temp3->getvalore()+temp2->getvalore();
                    temp3->setvalore(so);
                }
            temp2=temp2->getsuc();
        }
        temp3=temp3->getsuc();
    }

    return(s);
}

Lista Lista::trapsosta(){
    Lista tr;
    campo temp=new Nodo;
    campo temp2=new Nodo;
    temp=this->inizio;
    tr.crea();
    temp2=tr.inizio;
    while(temp!=0){
        campo n=new Nodo;
        n->setcolonna(temp->getriga());
        n->setriga(temp->getcolonna());
        if(!tr.vuota()){
            tr.inizio=n;
            tr.ultimo=n;
            n->setprec(NULL);
            n->setsuc(NULL);
        }
        else
        {
            tr.ultimo->setsuc(n);
            n->setprec(tr.ultimo);
            n->setsuc(NULL);
            tr.ultimo=n;
        }
        temp=temp->getsuc();
    }
}
