//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389

//..............................................................................
//......... REALIZZAZIONE CODA CON PRIORITA' COME LISTA NON ORDINATA ...........
//..............................................................................

#include <stdlib.h>
#include <iostream.h>
#include "prioricoda.h"

//definizione operatori

void Prioricoda :: creaprioricoda()
   {
      I=NULL;
		return;
   }

tipoelem Prioricoda :: min()
   {
      pos 	pmin,p=I;
      tipoelem min;
		if(p!=NULL)
      	{
		      min=p->priority;
      		if(p->succ==NULL)
					return p->priority;
            else
            	{
		      		p=p->succ;
						while(p!=NULL)
  							{
            				if(min>p->priority)
            					{
		            				pmin=p;
		      		         	min=p->priority;
      		      		   }
		      		      p=p->succ;
      		   		}
       				return min;
            	}
         }
      else
      	cout<<"\n La coda con priorità e' vuota!";
   }

void Prioricoda :: inserisci(tipoelem a)
   {
   	pos p=I;
		pos newNodo=new nodo;

      if(I==NULL)
      	{
				newNodo->priority=a;
				newNodo->succ=NULL;
		  		I=newNodo;
			}
		else
      	{  //inserimento in testa
				newNodo->priority=a;
				newNodo->succ=I;
  				I=newNodo;
 			}
		return;
   }




void Prioricoda :: cancellamin()
   {
      pos p,pred=p=I;
      tipoelem a=min();

		while(p->priority!=a)
  			{
            pred=p;
            p=p->succ;
         }

      if(p==I)
      	I=p->succ;
      else
	      pred->succ=p->succ;

     	delete p;
    }




//costruttori e distruttori


Prioricoda :: Prioricoda()
//crea prioricoda vuota
   {
      creaprioricoda();
		return;
   }


Prioricoda :: ~Prioricoda()
	{
		while (I!=NULL)
     		cancellamin();
  		return;
	}
