#include <iostream>
#include <stdlib.h>
#include "./Nodo.h"
#include "./Pila.h"

using namespace std;

Pila::Pila()
{
    this->creapila();
    return;
}

Pila::~Pila(){}

void Pila::creapila()
{
    this->testa=0;
    return;
}

bool Pila::pilavuota()
{
    return this->testa==0;
}

tipoelem Pila::leggipila()    //legge il primo elemento(testa)
{
    if(!this->pilavuota())
        return this->testa->getElem();
    else
        cout<<"\n\t Pila vuota!\n";
    return 0;
   }

void Pila::fuoripila()       //eleimina l'elemento in testa
{
    posizione temp= new Nodo();
    if (!this->pilavuota())
    	{
            temp=this->testa;
            this->testa=temp->getNext();
            delete temp;
        }
    else
        cout<< "\n\tPila vuota!\n";
    return;
   }

void Pila::inpila(tipoelem e)
{
        posizione temp=new Nodo();
        temp->setElem(e);
    if (this->pilavuota())
        temp->setNext(0);
    else
        temp->setNext(this->testa);
    this->testa=temp;
    return;
}

void Pila::stampa()
{

    posizione temp;
    temp=this->testa;
	if(!this->pilavuota()) {
            cout<<"\tEcco la pila...\n\n";

            do {
                cout <<"\n\t"<< temp->getElem();
                temp=temp->getNext();
            }while (temp!=0);
            cout<<"\n\n";
    }
    else
        cout<< "  Pila vuota! \n";
   return;
};
