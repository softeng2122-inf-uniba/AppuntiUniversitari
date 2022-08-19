#include<iostream>
#include<stdio.h>
#include<string.h>
#include"UtenteLista.h"
#include"UtenteNodo.h"

using namespace std;

Utentelista::Utentelista(){
    crealista();
}

Utentelista::~Utentelista(){

}
void Utentelista::crealista(){
    this->inizio=this->ultimo=0;
}

nodo Utentelista::primolista(){
    return inizio;
}
bool Utentelista::listavuota(){
    return(inizio==0)
}
nodo Utentelista::primolista(){
    return inizio;
}
nodo Utentelista::preclista(nodo p){
    return p->getprec();
}
nodo Utentelista::suclista(nodo p){
    return p->getsuc();
}
void Utentelista::aggiungiProdotto(nodo l,string p){
    nodo temp=new nodo;
    temp->setprodotto(p);
    if(listavuota())
        {
            temp->setsucc(0);
            temp->setprec(0);
            inizio=ultimo=temp;
        }
    else if(l==this->primolista())
        {
            primolista()->setprec(temp);
            temp->setsucc(primolista());
            inizio=temp;
        }
    else if(l==0)
        {
            ultimopolinomio()->setsucc(temp);
            temp->setsucc(0);
            temp->setprec(ultimopolinomio());
            ultimo = temp;
        }
    else
        {
            l->getprec()->setsucc(temp);
            temp->setprec(l->getprec());
            temp->setsucc(l);
            l->setprec(temp);
        }
}
void Utentelista::resgistraUtente(nodo l,string n,string c){
    nodo temp=new nodo;
    temp->setcognome(c);
    temp->setnome(n);
     if(listavuota())
        {
            temp->setsucc(0);
            temp->setprec(0);
            inizio=ultimo=temp;
        }
    else if(l==this->primolista())
        {
            primolista()->setprec(temp);
            temp->setsucc(primolista());
            inizio=temp;
        }
    else if(l==0)
        {
            ultimopolinomio()->setsucc(temp);
            temp->setsucc(0);
            temp->setprec(ultimopolinomio());
            ultimo = temp;
        }
    else
        {
            l->getprec()->setsucc(temp);
            temp->setprec(l->getprec());
            temp->setsucc(l);
            l->setprec(temp);
        }
}
void Utentelista::gradisce(nodo l,string n,string c,string p,int g){
    nodo temp=new nodo;
    temp=primolista();
    temp->setnome(n);
    temp->setcognome(c);
    temp->setprodotto(p);
    temp->setgradimento(g);
    if(listavuota())
        {
            temp->setsucc(0);
            temp->setprec(0);
            inizio=ultimo=temp;
        }
    else if(l==this->primolista())
        {
            primolista()->setprec(temp);
            temp->setsucc(primolista());
            inizio=temp;
        }
    else if(l==0)
        {
            ultimopolinomio()->setsucc(temp);
            temp->setsucc(0);
            temp->setprec(ultimopolinomio());
            ultimo = temp;
        }
    else
        {
            l->getprec()->setsucc(temp);
            temp->setprec(l->getprec());
            temp->setsucc(l);
            l->setprec(temp);
        }

}
int Utentelista::gradimento(string p){
    int cont=0;
    nodo temp=new nodo;
    temp=primolista();
    while(temp!=0){
        if(strcmp(temp->getprodotto(),p)==0);
            cont++;
        temp=temp->getsuc();
    }
    return(cont);
}
float Utentelista::mediaGradimenti(string p){
    float media=0;
    int cont=0;
    nodo temp=new nodo;
    temp=primolista();
    while(temp!=0){
        if(strcmp(temp->getprodotto(),p)==0){
            media=media+temp->getgradimento();
            cont++;
        }
        temp=temp->getsuc();
    }
    media=media/cont;
    return(media);

}
int Utentelista::gradimentiSimili(string n1,string n2){
    int cont=0;
    nodo temp=new nodo;
    nodo temp2=new nodo;
    temp=primolista();
    while(temp!=0){
        temp2=temp->getsuc();
        while(temp2!=0){
            if(strcmp(temp->getnome(),n1)==0 && strcmp(temp2->getnome(),n2)==0){
                if(strcmp(temp->getprodotto(),temp2->getprodotto()))
                    cont++;
            }
            temp2=temp2->gp->getprec()->setsucc(temp);
            temp->setprec(p->getprec());
            temp->setsucc(p);
            p->setprec(temp);etsuc();
        }
        temp=temp->getsuc();
    }
    return(cont);

}
void Utentelista::inserisci(nodo l,string n,string c,string p,int g){
    nodo temp=new nodo;
    nodo temp2=new nodo;
    temp->setcognome(c);
    temp->setnome(n);
    temp->setgradimento(g);
    temp->setprodotto(p);
    if(listavuota())
        {
            temp->setsucc(0);
            temp->setprec(0);
            inizio=ultimo=temp;
        }
    else if(l==this->primolista())
        {
            primolista()->setprec(temp);
            temp->setsucc(primolista());
            inizio=temp;
        }
    else if(l==0)
        {
            ultimopolinomio()->setsucc(temp);
            temp->setsucc(0);
            temp->setprec(ultimopolinomio());
            ultimo = temp;
        }
    else
        {
            l->getprec()->setsucc(temp);
            temp->setprec(l->getprec());
            temp->setsucc(l);
            l->setprec(temp);
        }

}
void Utentelista::inserimento(){
    int scelta,gr;
    string nome,cognome,prodotto;
    do{

        cout<<"\nInserisci nome utente\n";
        cin>>nome;
        cout<<"\nInserisci conome utente\n";
        cin>>conome;
        cout<"Se il cliente non ha acquistato nessun prodotto, mettere Null, e se non ha inserito un gradimento, mettere 0\n";
        cout<<"\nInserisci nome prodotto\n";
        cin>>prodotto;
        cout<<"\nInserisci gradimento\n";
        cin>>gr;
        inserimento(nome,cognome,prodotto,gr);
        cout<<"\nContinuare ad inserire\n";
        cin>>scelta;
    }while(scelta!=0);
}

void Utentelista::visualizza(){
    nodo temp=new nodo;
    temp=primolista();
    while(temp!=0){
        cout<<"\n Nome: "<<temp->getnome();
        cout<<"\n Conome: "<<temp->getconome();
        cout<<"\n Prodotto: "<<temp->getprodotto();
        cout<<"\n Gradimento: "<<temp->getgradimento();
        temp=temp->getsuc();
    }
}
