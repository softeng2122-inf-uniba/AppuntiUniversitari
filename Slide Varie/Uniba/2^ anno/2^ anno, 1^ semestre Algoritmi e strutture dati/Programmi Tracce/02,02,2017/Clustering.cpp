#include<string.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include"Clustering.h"

using namespace std;


Clustering::Clustering(){
    crea();
}
Clustering::~Clustering(){

}
void Clustering::crea(){
    primo=ultimo=0;
}
bool Clustering::vuoto(){
    return primo==0;
}
bool Clustering::fineclustering(){
    return ultimo==0;
}
cluster Clustering::primocluster(){
    return primo;
}
cluster Clustering::ultimocluster(){
    return ultimo;
}
cluster Clustering::sucluster(cluster p){
    return p->getsuc();
}
cluster Clustering::precluster(cluster p){
    return p->getprec();
}
void Clustering::stampa1(){
    int scelta;
    cluster temp=new Cluster;
    temp=primocluster();
    while(temp!=0){
        cout<<"\n "<<temp->getnome()<<"\n";
        cout<<"\nviusalizzare elementi?\n";
        cin>>scelta;
        if(scelta==1)
            temp->stampa();
        temp=temp->getsuc();
    }
}
void Clustering::inserimento(){
    int scelta;
    string n;
    do{
        cout<<"Inserire nome del cluster\n";
        cin>>n;
        inserisci(0,n);
        cout<<"\nContinuare?(1/0)\n";
        cin>>scelta;
    }while(scelta!=0);
}
void Clustering::inserisci(cluster p,tipoelem n){
    int scelta;
    cluster temp=new Cluster;
    temp->setnome(n);
    if(vuoto()){

        temp->setsuc(0);
		temp->setprec(0);
		primo = ultimo = temp;
    }else if (p == this->primocluster())
	{  //inserimento in testa
		primocluster()->setprec(temp);
		temp->setsuc(primocluster());
		primo = temp;
	}else if (p == 0) {
		ultimocluster()->setsuc(temp);
		temp->setsuc(0);
		temp->setprec(ultimocluster());
		ultimo = temp;
	}else {
		p->getprec()->setsuc(temp);
		temp->setprec(p->getprec());
		temp->setsuc(p);
		p->setprec(temp);
	}
	cout<<"\nCluster inserito, vuoi inserire oggetti?(1/0)\n";
	cin>>scelta;
	if(scelta==1)
        temp->inserimento();
}

int Clustering::nCluster(){
    cluster temp= new Cluster;
    int cont=0;
    while(!fineclustering()){
        cont++;
        temp=temp->getsuc();
    }
    return cont;
}

void Clustering::stampaCluster(tipoelem nom){
    cluster temp=new Cluster;
    bool trovato=false;
    temp=primocluster();
    while(!fineclustering()&&trovato==false){
        if(temp->getnome()==nom){
            temp->stampa();
            trovato=true;
        }
        temp=temp->getsuc();
    }
}
