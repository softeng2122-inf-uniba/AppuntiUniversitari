//IMPLEMENTAZIONE DI LISTA CON DOPPI PUNTATORI
#include "Nodoptr.h"
#include "lista.h"
#include <iostream.h>
#include <stdlib>

Lista::Lista(){this->crealista();};
Lista::~Lista(){};

void Lista::crealista(){begin=end=0;return;};

bool Lista::listavuota(){return (begin==0);};

posizione Lista::primolista(){return begin;};

posizione Lista::ultimolista(){return end;};

bool Lista::finelista(posizione p)
	{ return (p->getsucc()==0);};

tipoelem Lista::leggi(posizione p)
	{return p->getelem();};

void Lista::scrivi(posizione p, tipoelem e)
	{if(p!=0)
   	{p->setelem(e);}
    else cout<<"\n\tElemento nullo!\n";
    return;};

void Lista::cancella(posizione p)
	{posizione temp=new Nodoptr();

   	if (p==this->ultimolista())      //se è l'ultimo nodo
      	{p->getpred()->setsucc(0);
          end=p->getpred();
          temp=p;}
          else if(p==this->primolista())  //se è il primo nodo
          			{p->getsucc()->setpred(0);
                   begin=p->getsucc();
                   temp=p;}
    		 else{                           //altri casi
          		temp=p;
   				predlista(p)->setsucc(succlista(p));
    				succlista(p)->setpred(predlista(p));}
    delete(temp);
    return;};

void Lista::inserisci(posizione p, tipoelem e)
	{posizione temp=new Nodoptr();
    temp->setelem(e);

    if(this->listavuota()) 		//primo inserimento
    	{temp->setsucc(0);
       temp->setpred(0);
       begin=end=temp;
      }
    else if (p==this->primolista()) //inserimento in testa
      	 {primolista()->setpred(temp);
           temp->setsucc(primolista());
           begin=temp;}
    else if (p==0) 						//inserimento in coda
     		{ultimolista()->setsucc(temp);
          temp->setsucc(0);
          temp->setpred(ultimolista());
          end=temp;}
          else{p->getpred()->setsucc(temp);		//casi restanti
           temp->setpred(p->getpred());
           temp->setsucc(p);
           p->setpred(temp);}
   return;};

posizione Lista::succlista(posizione p)
{return p->getsucc();};

posizione Lista::predlista(posizione p)
{return p->getpred();};

void Lista::stampa()
{posizione temp;
	temp=primolista();
   do{
   	cout<<"\t"<<temp->getelem();
      temp=temp->getsucc();
   }while(temp!=0);
return;
};

posizione Lista::cerca(tipoelem e)
{posizione temp=this->primolista();
 bool trovato=false;
	do{
   	if (temp->getelem()==e)
      	{trovato=true; break;}
   	temp=temp->getsucc();

   }while((temp->getsucc()!=0));
   if (trovato)
   	return temp;
      else return 0;
};




