//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389


//..............................................................................
//.............. REALIZZAZIONE LISTA COLLEGATA CON PUNTATORI ...................
//..............................................................................


#include <stdlib.h>
#include <iostream.h>
#include "lista_class.h"


void Lista :: crealista()
   {
      L=NULL;
   }



Lista :: boolean Lista :: listavuota()
   {
      return L==NULL;
   }



Lista :: boolean Lista :: finelista(pos p)
   {
      return p==NULL;
   }



Lista :: pos Lista :: primolista()
   {
	   return L;
   }



Lista :: pos Lista :: succlista(pos p)
   {
      if(p==NULL)
      	return NULL;
      else
         return p->succ;
   }



Lista :: pos Lista :: predlista(pos p)
   {
      pos pivot=L;
      if(p==L)
      	return NULL;
      else
         {
            while(pivot->succ!=p)
               pivot=pivot->succ;
		      return pivot;
         }
   }


Lista :: pos Lista :: ultimolista()
   {
      pos pivot=L;
      while(pivot->succ!=NULL)
         pivot=pivot->succ;
      return pivot;
   }


Lista :: tipoelem Lista :: leggilista(pos p)
   {
      if(!finelista(p))
            return p->elem;
      else
         {
            cout<<"\n Lista terminata...\n";
            return NULL;
         }
   }


void Lista :: scrivilista(pos p,tipoelem a)
   {
      if(!finelista(p))
            p->elem=a;
      else
         cout<<"\n Sei uscito dai margini della lista...\n";
   }


void Lista :: inslista(pos p,tipoelem a)
   {
		pos newNodo;
      newNodo=new nodo;
      newNodo->elem=a;

   	if(p==NULL)
      	{
            L=newNodo;
            L->succ=NULL;
      	}
      else
      	if(p==L)
         	{
	            newNodo->succ=L;
   	         L=newNodo;
            }
         else
         	 {
   				predlista(p)->succ=newNodo;
   				newNodo->succ=p;
             }
  }

void Lista :: canclista(pos p)
   {
		if(finelista(p))
      	{
         	cout<<"Nessun nodo da cancellare.";
            return;
         }

		pos pre=predlista(p);
   	if(pre==NULL)
      	{
         	L=L->succ;
            delete(p);
            return;
         }
   	pre->succ=p->succ;
   	delete(p);
   }


//costruttori e distruttori

Lista :: Lista()
//crea lista vuota
   {
      crealista();
   }





Lista& Lista::operator = (Lista &lista)
//crea una copia di una lista come overloading dell'assegnamento
	{
   	tipoelem e;
		pos p,p_2;
		p=lista.primolista();
		crealista();
		p_2=primolista();
   	while(!lista.finelista(p))
   		{
         	e=lista.leggilista(p);
           	inslista(p_2,e);
           	p=lista.succlista(p);
         }

      return *this;
}


Lista :: ~Lista()
//rilascia la memoria impegnata da una lista
   {
      pos pivot=L;
      while(pivot!=NULL)
         {
            canclista(pivot);
            pivot=L;
         }
   }

