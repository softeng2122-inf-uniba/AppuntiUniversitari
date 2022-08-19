#include "Listapolinomi.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Lista::Lista(){
    crea();
}

Lista::~Lista(){

}

void Lista::crea(){
    this->inizio=this->ultimo=0;
}

polinomio Lista::successivo(polinomio f){
    return f->getsucc();
}

polinomio Lista::precedente(polinomio f){
    return f->getprec();
}

tipoelem Lista::leggiEsponente(polinomio esp){
    return esp->getesponente();
}

polinomio Lista::primopolinomio(){
    return inizio;
}

polinomio Lista::ultimopolinomio(){
    return ultimo;
}

void Lista::settaEsponente(tipoelem coef, tipoelem esp){
    polinomio temp=primopolinomio();
    while(temp!=0){
        if(temp->getcoefficiente()==coef)
            temp->setesponente(esp);
        temp=temp->getsucc();
    }
}

void Lista::rimuoviEsponente(tipoelem esp){
    polinomio temp=primopolinomio();
    while(temp!=0){
        if(temp->getesponente()==esp)
            temp->setcoefficiente(0);
        temp=temp->getsucc();
    }
}

tipoelem Lista::leggiCoefficiente(tipoelem espon){
    polinomio temp=primopolinomio();
    int solve;
    while(temp!=0){
        if(temp->getesponente()==espon)
            solve=temp->getcoefficiente();
        temp=temp->getsucc();
    }
    return(solve);
}

tipoelem Lista::grado(){
    tipoelem c=0;
    polinomio p=this->primopolinomio();
    while( p!=0)
    {
        if(p->getesponente()>=c)
            c=p->getesponente();
        p=p->getsucc();
    }
    return c;
}

Lista Lista::somma(Lista p){
    int somma;
    polinomio temp1,temp2;
    Lista q;
    bool trovato=false;
    q.ultimo=NULL;
    q.inizio=NULL;

    temp1=q.primopolinomio();

    //cpia primo polinomio (l)
    temp2=this->primopolinomio();

    while(temp2!=0){

        polinomio m=new Nodo();
        m->setcoefficiente(temp2->getcoefficiente());
        m->setesponente(temp2->getesponente());

        if(q.listavuota())
        {
            q.inizio=m;
            q.ultimo=m;
            m->setprec(NULL);
            m->setsucc(NULL);
        }
        else{
            q.ultimo->setsucc(m);
            m->setprec(q.ultimo);
            m->setsucc(NULL);
            q.ultimo=m;
        }
      temp2=temp2->getsucc();
    }
        cout<<"\nstampa l\n";
    this->stampa();
    cout<<"\nstampa q\n";
    q.stampa();
    cout<<"\nstampa p\n";
    p.stampa();
    //gestione secondo polinomio
    temp2=p.primopolinomio();
    while(temp2!=0)
    {
        temp1=q.primopolinomio();
        while(temp1!=0&&trovato==false){
            if(temp1->getesponente()==temp2->getesponente()){
                    somma=temp2->getcoefficiente()+temp1->getcoefficiente();
                    temp1->setcoefficiente(somma);
                    trovato=true;
            }
            temp1=temp1->getsucc();
        }
         if(trovato==false){
            polinomio m=new Nodo();
            q.ultimo->setsucc(m);
            m->setesponente(temp2->getesponente());
            m->setprec(q.ultimo);
            m->setsucc(NULL);
            q.ultimo=m;
         }
        temp2=temp2->getsucc();
    }
return(q);
}

Lista Lista::prodotto(Lista k){
    int prcof,presp;
    polinomio temp1,temp2;
    Lista q;
    temp1=this->primopolinomio();
    while(temp1!=0){
        temp2=k.primopolinomio();
        while(temp2!=0)
        {
            prcof=temp1->getcoefficiente()*temp2->getcoefficiente();
            presp=temp1->getesponente()+temp2->getesponente();
            polinomio m=new Nodo();
            m->setcoefficiente(prcof);
            m->setesponente(presp);
            if(q.listavuota())
            {
                q.inizio=m;
                q.ultimo=m;
                m->setprec(NULL);
                m->setsucc(NULL);
            }
            else{
                q.ultimo->setsucc(m);
                m->setprec(q.ultimo);
                m->setsucc(NULL);
                q.ultimo=m;
            }
            temp2=temp2->getsucc();
        }
        temp1=temp1->getsucc();
    }
    q.normalizza();
    return(q);
}

void Lista::stampa(){
    polinomio temp;
	temp = primopolinomio();
	while (temp != 0) {
		cout << "\t" << temp->getcoefficiente()<<","<<temp->getesponente();
		temp = temp->getsucc();
	}
	return;
}

void Lista::inserimento(polinomio p ,tipoelem coef, tipoelem esp){
    polinomio temp= new Nodo();
    temp->setcoefficiente(coef);
    temp->setesponente(esp);
    if(listavuota())
        {
            temp->setsucc(0);
            temp->setprec(0);
            inizio=ultimo=temp;
        }
    else if(p==this->primopolinomio())
        {
            primopolinomio()->setprec(temp);
            temp->setsucc(primopolinomio());
            inizio=temp;
        }
    else if(p==0)
        {
            ultimopolinomio()->setsucc(temp);
            temp->setsucc(0);
            temp->setprec(ultimopolinomio());
            ultimo = temp;
        }
    else
        {
            p->getprec()->setsucc(temp);
            temp->setprec(p->getprec());
            temp->setsucc(p);
            p->setprec(temp);
        }

}

bool Lista::listavuota(){
    return(inizio==0);
}

void Lista::normalizza(){
    polinomio temp1,temp2,temp3;
    temp1=this->primopolinomio();
    while(temp1!=0){
        temp2=temp1->getsucc();
        while(temp2!=0){
            if(temp1->getesponente()==temp2->getesponente()){
                temp1->setcoefficiente(temp1->getcoefficiente()+temp2->getcoefficiente());
                temp3=temp2->getsucc();
                temp3->setprec(temp2->getprec());
                temp3=temp2->getprec();
                temp3->setsucc(temp2->getsucc());
            }
            temp2=temp2->getsucc();
        }
        temp1=temp1->getsucc();
    }

}
void Lista::inserisci(){
    int coefficiente,esponente;
    int scelta;
    do{
        cout<<"\n Inserisci coefficiente:  ";
        cin>>coefficiente;
        cout<<"\n Inserisci esponente:  ";
        cin>> esponente;
        inserimento(0,coefficiente,esponente);
        cout<<"Continuare? (1/0)";
        cin>>scelta;
    }while(scelta==1);
}
