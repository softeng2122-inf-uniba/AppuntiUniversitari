//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//..................... REALIZZAZIONE PILA CON VETTORE .........................
//..............................................................................



#include <iostream.h>
#include <stdlib.h>
#include "pila.h"

//definizione degli operatori

void Pila::creapila()
//si tratta di settare il top a zero
	{
      top=0;
   }

Pila::boolean Pila::pilavuota()
	{
   	return top==0;
   }

Pila::tipoelem Pila::leggipila()
//la posizione top nell'array corrisponde all'indice top-1
//(perchè in C++ il range degli indici parte da zero)
//il problema si potrebbe aggirare con un overloading
//dell'operatore di indicizzazione  []
//ad esempio ridefinendolo nella classe in questo modo:
/*
tipoelem Pila :: operator[](int top)
	{
   	return pila[top-1];
   }
*/
	{
		return pila[top-1];
   }

void Pila::inpila(tipoelem a)
//
	{
      if(top==N)
      //controllo se l'operazione provoca una violazione di accesso alla memoria
        	cout<<"\n Raggiunto il limite max di elementi della pila.";
      else
			{
            top++;       //incremento il top
				pila[top-1]=a; //inserisco l'elemento
         }
	}

void Pila::fuoripila()
	{
		if(!pilavuota())
      //controllo se l'operazione è effettivamente eseguita su pila non vuota
			top--;
      else
        	cout<<"\n La pila e' vuota.";
	}

//implementazione dei costruttori e del distruttore
Pila::Pila()
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


Pila::~Pila()
	{}

   
