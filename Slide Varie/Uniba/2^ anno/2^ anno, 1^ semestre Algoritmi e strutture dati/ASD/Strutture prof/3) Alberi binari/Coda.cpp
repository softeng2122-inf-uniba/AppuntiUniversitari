#include<stdlib.h>
#include<iostream>
#include "./Coda.h"

using namespace std;

Coda::Coda(){
    creacoda();
    return;
}

Coda::~Coda(){
    delete testa;
    delete fondo;
}

void Coda::creacoda(){
    testa=0;
    fondo=0;
}

bool Coda::codavuota(){
    return(testa==0);
}

void Coda::fuoricoda()         //elimina elemento in testa
{
    posizione temp=new NodoCoda();
    if(!codavuota())
        {
            temp=testa;
            testa=testa->getNext();
            delete temp;
        }
     else
        cout << "\n\tCoda vuota!\n";
     return;
}

void Coda::stampa()
{
    posizione temp;
    temp=this->testa;
	if(!this->codavuota())
        do{
             cout<<"\n\t "<<temp->getElem();
             temp=temp->getNext();
          }while(temp!=0);
   else
        cout<<"\n  Coda vuota!\n";
   return;
}

void Coda::incoda(cellap e)  //inserisce elemento dal fondo
{
     posizione temp=new NodoCoda();
     if (codavuota())
     	{
     	    testa=(temp);
            fondo=(temp);
        }
     else
        {
            fondo->setNext(temp);
            fondo=temp;
        }

     fondo->setElem(e);
     return;
}

cellap Coda::leggicoda(){
    if (!codavuota())
   		{
   		    return (testa->getElem());
        }
    else
        cout<<"\nCoda vuota!\n";
}
