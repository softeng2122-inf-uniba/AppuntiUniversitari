//Università degli studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e strutture dati

//Autore: Nico spadoni
//matr.428389



//..............................................................................
//................ REALIZZAZIONE ALBERO BINARIO SEQUENZIALE ..................
//.................. (orientato alla costruzione top down) .....................
//..............................................................................



#include <iostream.h>
#include <stdlib.h>
#include "alberobin.h"

//definizione degli operatori

void Alberobin :: creabinalbero()
   {
      for(int i=0;i<N;i++)
			alberobin[i].exist=false;
   }

Alberobin :: boolean Alberobin :: binalberovuoto()
   {
   	return alberobin[1].exist==false;
   }

Alberobin :: nodo Alberobin :: binradice()
   {
      if(!binalberovuoto())
   		return 1;
   }

Alberobin :: nodo Alberobin :: binpadre(nodo n)
   {
      if(n>2)
	   	return (n/2);
   }

Alberobin :: nodo Alberobin :: figliosinistro(nodo n)
   {
      if(alberobin[2*n].exist)
    		return 2*n;
      else
      	cout<<"\n Il nodo non ha figlio sinistro";
   }

Alberobin :: nodo Alberobin :: figliodestro(nodo n)
   {
      if(alberobin[2*n+1].exist)
    		return 2*n+1;
      else
      	cout<<"\n Il nodo non ha figlio destro";
   }

Alberobin :: boolean Alberobin :: sinistrovuoto(nodo n)
   {
  		return !(alberobin[2*n].exist);
   }

Alberobin :: boolean Alberobin :: destrovuoto(nodo n)
   {
  		return !(alberobin[2*n+1].exist);
   }

void Alberobin :: cancsottobinalbero(nodo n)
   {
		if(alberobin[2*n].exist)
      	cancsottobinalbero(2*n);

		if(alberobin[2*n+1].exist)
      	cancsottobinalbero(2*n+1);

      alberobin[n].exist=false;
   }

Alberobin :: tipoelem Alberobin :: legginodo(nodo n)
   {
   	return alberobin[n].elem;
   }

void Alberobin :: scrivinodo(tipoelem a,nodo n)
   {
		alberobin[n].elem=a;
   }

void Alberobin :: insbinradice()
   {
   	if(binalberovuoto())
			alberobin[1].exist=true;
   }

void Alberobin :: insfigliosinistro(nodo n)
   {
		if(2*n<=N)
			alberobin[2*n].exist=true;
      else
      	cout<<"\n Hai oltrepassato il limite di memoria disponibile";
   }

void Alberobin :: insfigliodestro(nodo n)
   {
		if(2*n+1<=N)
			alberobin[2*n+1].exist=true;
      else
      	cout<<"\n Hai oltrepassato il limite di memoria disponibile";
   }


//implementazione dei costruttori e del distruttore
Alberobin::Alberobin()
	{
   	creabinalbero();
   }

Alberobin::~Alberobin()
	{}
