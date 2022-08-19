//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//..................... REALIZZAZIONE PILA CON PUNTATORI .......................
//..............................................................................



#include <stdlib.h>
#include <iostream.h>
#include "pila.h"



//definizione operatori

void Pila :: creapila()
	{
 		top=NULL;
 	}
 	
Pila :: boolean	Pila :: pilavuota()
	{
		return top==NULL;
 	}

Pila :: tipoelem Pila :: leggipila()
	{
		if(top==NULL)
			return NULL;
		else
  			return top->elem;
 	}

void Pila :: fuoripila()
	{
		Pila :: pos recycle=top;
		if(top!=NULL)
  			{
				top=top->succPtr;
				delete(recycle);
			}
		else
			cout<<"La pila è vuota";
 	}
 	
void Pila :: inpila(tipoelem a)
	{
		pos newNodo=new nodo;
		newNodo->elem=a;
		if(top==NULL)
			{
				newNodo->succPtr=NULL;
    			top=newNodo;
			}
		else
			{
         	newNodo->succPtr=top;
				top=newNodo;
			}
 	}


//costruttori e distruttori

Pila :: Pila()
//crea una pila vuota
	{
		creapila();
	}

Pila& Pila::operator=(Pila &pila)
//crea una pila copia come overloading dell'assegnamento
	{
		Pila pila_appoggio;
   	tipoelem a;
   	while(!pila.pilavuota())
   		{
      		a=pila.leggipila();
      		pila_appoggio.inpila(a);
      		pila.fuoripila();
      	}
   	creapila();
   	while(!pila_appoggio.pilavuota())
   		{
      		a=pila_appoggio.leggipila();
      		pila.inpila(a);
	      	inpila(a);
   	   	pila_appoggio.fuoripila();
      	}

		return *this;
}

Pila& Pila::operator^(Pila &pila)
//crea una pila inversa come overloading dell'operatore ^
	{
		Pila pila_appoggio,pila_appoggio_inv;
   	tipoelem a;
   	while(!pila.pilavuota())
   		{
      		a=pila.leggipila();
      		pila_appoggio.inpila(a);
      		pila.fuoripila();
      	}
   	while(!pila_appoggio.pilavuota())
   		{
      		a=pila_appoggio.leggipila();
      		pila_appoggio_inv.inpila(a);
      		pila_appoggio.fuoripila();
      	}
   	creapila();
   	while(!pila_appoggio_inv.pilavuota())
   		{
      		a=pila_appoggio_inv.leggipila();
      		pila.inpila(a);
	      	inpila(a);
   	   	pila_appoggio_inv.fuoripila();
      	}

		return *this;
}


Pila :: ~Pila()
//rilascia la memoria impegmata dalla pila
	{
		while(top!=NULL)
			fuoripila();
	}
