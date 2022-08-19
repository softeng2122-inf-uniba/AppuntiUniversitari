//IMPLEMENTAZIONE DELLA STRUTTURA DATI ALBERO BINARIO CON
//STRUTTURE DINAMICHE
#include "BinTree.h"
#include <iostream>
#include <stdlib>
#include "CodaB.h"

Bintree::Bintree(){creabinalbero();};
Bintree::~Bintree(){};

void Bintree::creabinalbero(){radice=0; return;};

bool Bintree::binalberovuoto(){return (radice==0);};

cellap Bintree::binradice(){return radice;};

cellap Bintree::binpadre(cellap n)
{ if (n!=0) return n->getpadre();
		else return 0;
};

cellap Bintree::figliosx(cellap n)
{ if (n !=0)  return n->getsx();
		else return 0;
};

cellap Bintree::figliodx(cellap n)
{ if (n !=0)  return n->getdx();
		else return 0;
};

bool Bintree::sinistrovuoto(cellap n)
{if (n!=0) return (n->getsx()==0);
	else return true;
};

bool Bintree::destrovuoto(cellap n)
{if (n!=0) return (n->getdx()==0) ;
	else return true;
};

void Bintree::cancsottobinalbero(cellap n)
{  if (n!=0)
   	{	if(n->getsx()->getsx()!=0 || n->getsx()->getdx()!=0)
      		cancsottobinalbero(n->getsx());
         if(n->getdx()->getsx()!=0 || n->getdx()->getdx()!=0)
         	cancsottobinalbero(n->getdx());
         if(n->getsx()!=0) delete(n->getsx());
         if(n->getdx()!=0) delete(n->getdx());
      }
    return;
};

tipoelem Bintree::legginodo(cellap n)
	{return n->getelem();};

void Bintree::scrivinodo(cellap n, tipoelem e)
{	if (n!=0)
		{ n->setelem(e);}
    return;
};

void Bintree::insbinradice()
{ cellap n=new NodoBin();
  radice=n;
  return;
};

void Bintree::insfigliosx(cellap p)
{ cellap n=new NodoBin();
  p->setsx(n);
  n->setpadre(p);
  return;
};

void Bintree::insfigliodx(cellap p)
{ cellap n=new NodoBin();
  p->setdx(n);
  n->setpadre(p);
  return;
};

void Bintree::insalbero(cellap u)
{ char risp;
  tipoelem e;

  cout<<"\nInserire il figlio sx del nodo "<<u->getelem()<<" ? (s/n)... ";
  cin>>risp;
  if(risp=='s')
  			{this->insfigliosx(u);
          cout<<"\nInserire l'elemento...";
          cin>>e;
          this->scrivinodo(u->getsx(),e);
            this->insalbero(u->getsx());}
  cout<<"\nInserire il figlio dx del nodo "<<u->getelem()<<" ? (s/n)... ";
  cin>>risp;
  if(risp=='s')
  			{this->insfigliodx(u);
          cout<<"\nInserire l'elemento...";
          cin>>e;
          this->scrivinodo(u->getdx(),e);
          this->insalbero(u->getdx());}
    return;
  };

void Bintree::previsita(cellap u)
{  if(u!=binradice())
	cout << "\t"<<u->getelem()<<"("<<u->getpadre()->getelem()<<")";
   else  cout << "\t"<<u->getelem();
   if(!sinistrovuoto(u))
   		previsita(u->getsx());
   if(!destrovuoto(u))
   		previsita(u->getdx());
   return;
   };

void Bintree::postvisita(cellap u)
{	if (!this->binalberovuoto())
	{	if(!this->sinistrovuoto(u))
   		this->postvisita(u->getsx());
   	if(!this->destrovuoto(u))
   		this->postvisita(u->getdx());
      //cout<<"\t"<<u->getelem()<<"("<<u->getpadre()->getelem()<<")";
      if(u!=binradice())
			cout << "\t"<<u->getelem()<<"("<<u->getpadre()->getelem()<<")";
   	else  cout << "\t"<<u->getelem();
      }
   return;
};

void Bintree::invisita(cellap u)
{    if (!this->binalberovuoto())
	{	if(!this->sinistrovuoto(u))
   		this->invisita(u->getsx());
   	//cout<<"\t"<<u->getelem()<<"("<<u->getpadre()->getelem()<<")";
      if(u!=binradice())
			cout << "\t"<<u->getelem()<<"("<<u->getpadre()->getelem()<<")";
   	else  cout << "\t"<<u->getelem();
   	if(!this->destrovuoto(u))
   		this->invisita(u->getdx());
      }
   return;
};

void Bintree::visita_livello()
{	Coda c;
	cellap u;
   int e;

   u=binradice();
   c.incoda(u);
   while(c.codavuota()==false)
   {u=c.leggicoda();
    c.fuoricoda();
    //e=u->getelem();
    //cout<<"\t"<<u->getelem()<<"("<<u->getpadre()->getelem()<<")";
    if(u!=binradice())
		cout << "\t"<<u->getelem()<<"("<<u->getpadre()->getelem()<<")";
    else  cout << "\t"<<u->getelem();
    if(sinistrovuoto(u)==false)
    	c.incoda(figliosx(u));
    if(destrovuoto(u)==false)
    	c.incoda(figliodx(u));
    }
};









