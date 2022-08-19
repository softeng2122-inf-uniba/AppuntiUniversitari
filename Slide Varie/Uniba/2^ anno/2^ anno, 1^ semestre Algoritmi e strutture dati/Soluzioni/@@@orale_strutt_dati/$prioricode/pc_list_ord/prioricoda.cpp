//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389


//..............................................................................
//........... REALIZZAZIONE CODA CON PRIORITA' COME LISTA ORDINATA .............
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


void Prioricoda :: inserisci(tipoelem a)
//l'inserimento deve essere opportunamente controllato per mantenere
//la relazione d'ordine
   {
      pos prec,p=prec=I;
 		pos newNodo=new nodo;

	  	newNodo->priority=a;

      if(p==NULL)
      	{
				newNodo->priority=a;
				newNodo->succ=NULL;
		  		I=newNodo;
			}
		else
			{
			  	while(p!=NULL && a>p->priority)
   		   //scarta tutti gli elementi minori di a e ne traccia la posizione
      		   {
         		  	prec=p;
        				p=p->succ;
		         }

            if(p==NULL) //se il ciclo termina perchè p==NULL, allora
            	{
  						prec->succ=newNodo;
                  newNodo->succ=NULL;
               }
            else	//altrimenti
      			if(p==I) //se a è minore del primo elemento
                  {
	  	   	  			newNodo->succ=p;
                     I=newNodo;
                  }
	   	   	else //altrimenti, in tutti gli altri casi
               	{
   	   	  			prec->succ=newNodo;
	                  newNodo->succ=p;
                  }
			}
		return;
   }



Prioricoda :: tipoelem Prioricoda :: min()
//poichè la lista è ordinata il minimo è il primo elemento
   {
      if(I!=NULL)
     		return I->priority;
      else
      	cout<<"\n La coda con priorità è vuota!";
   }



void Prioricoda :: cancellamin()
   {
      pos p=I;
      I=I->succ;
   	delete p;
   }



//costruttori e distruttori



Prioricoda :: Prioricoda()
//crea ins vuota
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
