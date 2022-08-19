//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//.............. REALIZZAZIONE LISTA COLLEGATA CON PUNTATORI ...................
//........................ CIRCOLARE BIDIREZIONALE .............................
//..............................................................................



#include <stdlib.h>
#include <iostream.h>
#include "lista_class.h"



//definizione di metodi, costruttori e distruttori della classe Lista

void Lista :: crealista()
//crea il nodo sentinella
   {
      pos newNodo=new nodo;
      L=newNodo;
     	newNodo->pred=L;
     	newNodo->succ=L;
   }



Lista :: boolean Lista :: listavuota()
//la condizione di lista vuota è rilevata i valori
//dei puntatori della sentinella
   {
      return (L->pred=L)&&(L->succ=L);
   }



Lista :: pos Lista :: primolista()
//il primo nodo, cioè L, non è il primo della lista ma la sentinella, quindi
//la funzione deve restituire il successivo di L
   {
	   return L->succ;
   }



Lista :: pos Lista :: ultimolista()
//la circolarità della realizzazione consente l'accesso all'ultimo nodo
//dalla stessa sentinella, restituendo il nodo precedente ad essa
   {
	   return L->pred;
   }


Lista :: pos Lista :: succlista(pos p)
//volendo si può inserire un controllo per evitare che la funzione restituisca
//la sentinella, tuttavia tale controllo può essere eseguito dall'esterno
   {
		return p->succ;
   }



Lista :: pos Lista :: predlista(pos p)
//analogamente a succlista si può inserire un controllo per evitare che
//la funzione restituisca la sentinella.
   {
		return p->pred;
   }


Lista :: boolean Lista :: finelista(pos p)
//il fine lista in presenza della sentinella consiste proprio quando alla
//posizione passata alla funzione corrisponde la sentinella stessa
   {
      return p==L;
   }


Lista :: tipoelem Lista :: leggilista(pos p)
//in queste funzioni è mostrato un possibile controllo interno
//per evitare di leggere nella sentinella
   {
      if(!finelista(p))
            return p->elem;
      else
         {
            cout<<"\n Operazione non ammessa...\n";
            return NULL;
         }
   }


void Lista :: scrivilista(pos p,tipoelem a)
//in queste funzioni è mostrato un possibile controllo interno
//per evitare di scrivere nella sentinella
   {
      if(!finelista(p))
            p->elem=a;
      else
         cout<<"\n Operazione non ammessa...\n";
   }


void Lista :: inslista(pos p,tipoelem a)
   {
		pos newNodo;
		newNodo=new nodo;
   	newNodo->elem=a;
     	newNodo->pred=p->pred;
     	newNodo->succ=p;
      predlista(p)->succ=newNodo;
      p->pred=newNodo;
  }


void Lista :: canclista(pos p)
   {
   	predlista(p)->succ=p->succ;
   	succlista(p)->pred=p->pred;
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
//rilascia la memoria impegnata da una lista.
   {
      pos pivot=L;
      while(pivot!=L)
         {
            canclista(pivot);
            pivot=L;
         }
      delete L;
   }

