#include"cluster.h"
#include<string.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

Cluster::Cluster(){
    inizio=fine=0;
    this->suc=this->prec=0;
}

Cluster::~Cluster(){

}

void Cluster::setnome(tipoelem p){
    this->nm=p;
}
void Cluster::setsuc(Cluster* p){
    this->suc=p;
}
void Cluster::setprec(Cluster* p){
    this->prec=p;
}
tipoelem Cluster::getnome(){
    return this->nm;
}
Cluster* Cluster::getsuc(){
    return this->suc;
}
Cluster* Cluster::getprec(){
    return this->prec;
}
bool Cluster::vuoto(){
    return inizio==0;
}
oggetto Cluster::primocluster(){
    return inizio;
}
oggetto Cluster::finecluster(){
    return fine;
}
oggetto Cluster::sucluster(oggetto p){
    return p->getsuc();
}
oggetto Cluster::precluster(oggetto p){
    return p->getprec();
}
void Cluster::stampa(){
    oggetto temp=new Oggetto;
    temp=inizio;
    cout<<"Elementi nel cluster:  "<<this->getnome()<<"\n";
    while(temp!=0){

        cout<<"\n "<<temp->getnome()<<"\n";
        temp=temp->getsuc();
    }
}
void Cluster::inserimento(){
    int scelta;
    string n;
    do{
        cout<<"Inserire nome elemento nel cluster\n";
        cin>>n;
        inserisci(0,n);
        cout<<"\nContinuare?(1/0)\n";
        cin>>scelta;
    }while(scelta!=0);

}
void Cluster::inserisci(oggetto p,tipoelem n){
    oggetto temp=new Oggetto;
    temp->setnome(n);
    if(vuoto()){

        temp->setsuc(0);
		temp->setprec(0);
		inizio = fine = temp;
    }else if (p == this->primocluster())
	{  //inserimento in testa
		primocluster()->setprec(temp);
		temp->setsuc(primocluster());
		inizio = temp;
	}else if (p == 0) {
		finecluster()->setsuc(temp);
		temp->setsuc(0);
		temp->setprec(finecluster());
		fine = temp;
	}else {
		p->getprec()->setsuc(temp);
		temp->setprec(p->getprec());
		temp->setsuc(p);
		p->setprec(temp);
	}
}
bool Cluster::finelista(){
    return fine==0;
}
