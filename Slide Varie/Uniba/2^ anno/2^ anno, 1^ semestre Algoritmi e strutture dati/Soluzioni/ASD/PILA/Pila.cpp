//IMPLEMENTAZIONE DELLA CLASSE PILA
#include <iostream.h>
#include <stdlib.h>
#include "Nodo.h"
#include "Pila.h"

Pila::Pila()
	{this->creapila(); return;}

Pila::~Pila(){}

void Pila::creapila()
	{this->testa=0; return;}

bool Pila::pilavuota()
	{return this->testa==0;}

tipoelem Pila::leggipila()    //legge il primo elemento(testa)
	{if(!this->pilavuota())
   	return this->testa->getElem();
    else {cout<<"\n\t Pila vuota!\n";
    		return 0;}
   }

void Pila::fuoripila()       //eleimina l'elemento in testa
	{posizione temp= new Nodo();
    if (!this->pilavuota())
    	{ temp=this->testa;
        this->testa=temp->getNext();
        delete temp;}
    else cout<< "\n\tPila vuota!\n";
    return;
   }

void Pila::inpila(tipoelem e)
	{posizione temp=new Nodo();
    temp->setElem(e);
    if (this->pilavuota())
    	{temp->setNext(0);
    	 this->testa=temp;}
    else	{temp->setNext(this->testa);
    		 this->testa=temp;}
    return;}

void Pila::stampa()
{  tipoelem e;
	if(!this->pilavuota())
   	{cout<<"\tEcco la pila...\n\n";
       do
   		{e=leggipila();
       	 fuoripila();
          cout <<"\n\t||"<< e <<" ||";
       }while (!pilavuota());
   	 cout<<"\n\n";}
       else
       cout<< "  Pila vuota! \n";
   return;
};
