#include "./AlberoBinario.h"
#include <iostream>
#include <stdlib.h>
#include "./Coda.h"

using namespace std;

AlberoBinario::AlberoBinario(){
    creabinalbero();
}
AlberoBinario::~AlberoBinario(){

}

void AlberoBinario::creabinalbero(){
    radice=0;
    return;
}

bool AlberoBinario::binalberovuoto(){
    return (radice==0);
}

cellap AlberoBinario::binradice(){
    return radice;
}

cellap AlberoBinario::binpadre(cellap n){
    if (n!=0)
        return n->getpadre();
    else
        return 0;
};

cellap AlberoBinario::figliosx(cellap n){
    if (n !=0)
        return n->getsx();
    else
        return 0;
};

cellap AlberoBinario::figliodx(cellap n){
    if (n !=0)
        return n->getdx();
    else
        return 0;
};

bool AlberoBinario::sinistrovuoto(cellap n){
    if (n!=0)
        return (n->getsx()==0);
	else
        return true;
}

bool AlberoBinario::destrovuoto(cellap n){
    if (n!=0)
        return (n->getdx()==0) ;
	else
        return true;
}

void AlberoBinario::cancsottobinalbero(cellap n)
{  if (n!=0)
   	{	if(n->getsx()->getsx()!=0 || n->getsx()->getdx()!=0)
      		cancsottobinalbero(n->getsx());
         if(n->getdx()->getsx()!=0 || n->getdx()->getdx()!=0)
         	cancsottobinalbero(n->getdx());
         if(n->getsx()!=0)
            delete(n->getsx());
         if(n->getdx()!=0)
            delete(n->getdx());
      }
    return;
}

tipoelem AlberoBinario::legginodo(cellap n){
    return n->getelem();
}

void AlberoBinario::scrivinodo(cellap n, tipoelem e){
    if (n!=0)
		n->setelem(e);
    return;
}

void AlberoBinario::insbinradice(){
    cellap n=new NodoBinario();
    radice=n;
    return;
}

void AlberoBinario::insfigliosx(cellap p){
    cellap n=new NodoBinario();
    p->setsx(n);
    n->setpadre(p);
    return;
}

void AlberoBinario::insfigliodx(cellap p){
    cellap n=new NodoBinario();
    p->setdx(n);
    n->setpadre(p);
    return;
}

void AlberoBinario::insalbero(cellap u){
    int risp;
    tipoelem e;

    cout<<"\nInserire il figlio sx del nodo "<<u->getelem()<<" ? (1/0)... ";
    cin>>risp;
    if(risp==1)
        {
            this->insfigliosx(u);
            cout<<"\nInserire l'elemento...";
            cin>>e;
            this->scrivinodo(u->getsx(),e);
            this->insalbero(u->getsx());
        }
    cout<<"\nInserire il figlio dx del nodo "<<u->getelem()<<" ? (1/0)... ";
    cin>>risp;
    if(risp==1)
  			{
  			    this->insfigliodx(u);
                cout<<"\nInserire l'elemento...";
                cin>>e;
                this->scrivinodo(u->getdx(),e);
                this->insalbero(u->getdx());
            }
    return;
  }

void AlberoBinario::previsita(cellap u){
    if(u!=binradice())
        cout << "\t"<<u->getelem()<<"("<<u->getpadre()->getelem()<<")";
    else
        cout << "\t"<<u->getelem();
    if(!sinistrovuoto(u))
        previsita(u->getsx());
    if(!destrovuoto(u))
   		previsita(u->getdx());
   return;
}

void AlberoBinario::postvisita(cellap u){
    if (!this->binalberovuoto())
	{
	    if(!this->sinistrovuoto(u))
            this->postvisita(u->getsx());
        if(!this->destrovuoto(u))
            this->postvisita(u->getdx());
        //cout<<"\t"<<u->getelem()<<"("<<u->getpadre()->getelem()<<")";
        if(u!=binradice())
			cout << "\t"<<u->getelem()<<"("<<u->getpadre()->getelem()<<")\n";
        else
            cout << "\t"<<u->getelem();
      }
   return;
}

void AlberoBinario::invisita(cellap u)
{
     if (!this->binalberovuoto())
        {
            if(!this->sinistrovuoto(u))
                this->invisita(u->getsx());
            //cout<<"\t"<<u->getelem()<<"("<<u->getpadre()->getelem()<<")";
            if(u!=binradice())
                cout << "\t"<<u->getelem()<<"("<<u->getpadre()->getelem()<<")\n";
            else
                cout << "\t"<<u->getelem();
            if(!this->destrovuoto(u))
                this->invisita(u->getdx());
      }
   return;
}

void AlberoBinario::visita_livello()
{
   Coda c;
	cellap u;
    int e;

    u=binradice();
    c.incoda(u);
    e=u->getelem();
    cout<<"\t"<<u->getelem()<<"("<<u->getpadre()->getelem()<<")";
    while(c.codavuota()==false)
    {
        u=c.leggicoda();
        c.fuoricoda();
        //e=u->getelem();
        //cout<<"\t"<<u->getelem()<<"("<<u->getpadre()->getelem()<<")";
        if(u!=binradice())
            cout << "\t"<<u->getelem()<<"("<<u->getpadre()->getelem()<<")";
        else
            cout << "\t"<<u->getelem();
        if(sinistrovuoto(u)==false)
            c.incoda(figliosx(u));
        if(destrovuoto(u)==false)
            c.incoda(figliodx(u));
    }
}
