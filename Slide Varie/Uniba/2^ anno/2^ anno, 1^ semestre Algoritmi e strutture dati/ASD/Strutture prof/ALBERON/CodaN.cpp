//IMPLEMENTAZIONE DELLA CLASSE CODA
#include "NodoCN.h"
#include "CodaN.h"
#include <iostream.h>
#include <stdlib.h>

CodaN::CodaN()
	{creacoda(); return;}

CodaN::~CodaN()
	{delete testa;
    delete fondo;}

void CodaN::creacoda()
	{testa=0;
    fondo=0;
    }

bool CodaN::codavuota()
	{return (testa==0);}

cellap CodaN::leggicoda()     //legge elemento in testa
	{if (!codavuota())
   		{return (testa->getElem());}
          //cout<<"\nletto";}
    else cout <<"\nCoda vuota!\n";
    system("PAUSE");
    }

void CodaN::fuoricoda()         //elimina elemento in testa
	{ posizione temp=new NodoCN();
     if(!codavuota())
     		{temp=testa;
          testa=testa->getNext();
          delete temp;
          }
     else cout << "\n\tCoda vuota!\n";
     return;
    }

void CodaN::incoda(cellap e)  //inserisce elemento dal fondo
	{ posizione temp=new NodoCN();
     if (codavuota())
     	{testa=(temp);
       fondo=(temp);}
     else
     		{fondo->setNext(temp);
          fondo=temp;}
     fondo->setElem(e);
     return;
   }
//operatore aggiuntivo che stampa e svuota la coda
void CodaN::stampa()
{ cellap e;
	if(this->codavuota()==false)
   	do{
      	e=leggicoda();
         cout<<"\n\t-- "<<e;
         fuoricoda();
      }while(codavuota()==false);
   else cout<<"\n  Coda vuota!\n";
   return;
};


