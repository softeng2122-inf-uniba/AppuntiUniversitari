//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: nico Spadoni
//matr.428389



//..............................................................................
//................ REALIZZAZIOnE ALBERO BInARIO COn PUnTATORI ..................
//.................. (orientato alla costruzione top down) .....................
//..............................................................................



#include <stdlib.h>
#include <iostream.h>
#include "alberobin.h"



//Specifica delle interfacce comuni

void Alberobin :: creabinalbero()
   {
      T=NULL;
   }

Alberobin :: boolean Alberobin :: binalberovuoto()
   {
      return T==NULL;
   }

Alberobin :: nodo Alberobin :: binradice()
   {
      if(!binalberovuoto())
      	return T;
      else
      	cout<<"\n L'albero e' vuoto";
			return NULL;
   }

Alberobin :: nodo Alberobin :: binpadre(nodo n)
   {
      if(!binalberovuoto()&& n!=binradice())
      	return n->padre;
   	else
      	return NULL;
   }

Alberobin :: nodo Alberobin :: figliosinistro(nodo n)
   {
      if(!binalberovuoto())
      	return n->sinistro;
   	else
      	return NULL;
   }

Alberobin :: nodo Alberobin :: figliodestro(nodo n)
   {
      if(!binalberovuoto())
      	return n->destro;
   	else
      	return NULL;
   }


Alberobin :: boolean Alberobin :: sinistrovuoto(nodo n)
   {
      if(!binalberovuoto())
      	return figliosinistro(n)==NULL;
   }



Alberobin :: boolean Alberobin :: destrovuoto(nodo n)
   {
      if(!binalberovuoto())


      	return figliodestro(n)==NULL;
   }





//Specifica delle interfacce di costruzione e potatura


void Alberobin :: insbinradice()
   {
  		nodo newnodo=new nodobin;
      newnodo->sinistro=NULL;
      newnodo->destro=NULL;
      newnodo->padre=NULL;
      T=newnodo;
      return;
   }



void Alberobin :: insfigliosinistro(nodo n)
   {
		if(!binalberovuoto() && sinistrovuoto(n))
         {
      		nodo newfiglio=new nodobin;
      		newfiglio->sinistro=NULL;
      		newfiglio->destro=NULL;
      		newfiglio->padre=n;
            n->sinistro=newfiglio;
         }


      return;
   }



void Alberobin :: insfigliodestro(nodo n)
   {
		if(!binalberovuoto() && destrovuoto(n))
         {
      		nodo newfiglio=new nodobin;
      		newfiglio->sinistro=NULL;
      		newfiglio->destro=NULL;
      		newfiglio->padre=n;
		      n->destro=newfiglio;
         }


      return;
   }



void Alberobin :: cancsottobinalbero(nodo n)
{
   if(!binalberovuoto())//controlla che l'albero non sia vuoto
	   {
         if(!sinistrovuoto(n))
         //controlla che abbia un figlio sinistro e procede ricorsivamente con la cancellazione più in profondità
         	{
              	if(figliosinistro(n)->sinistro!=NULL||figliosinistro(n)->destro!=NULL)
         			cancsottobinalbero(figliosinistro(n));
         	}
        	if(!destrovuoto(n))
         //controllo che abbia un figlio sinistro e procedere ricorsivamente con la cancellazione più in profondità
         	{
              	if(figliodestro(n)->sinistro!=NULL||figliodestro(n)->destro!=NULL)
         			cancsottobinalbero(figliodestro(n));
         	}
        	if(n==binradice())
         //se dopo la cancellazione resta solo la radice cancello anch'essa stabilendo lo stato di albero vuoto
           	{
              	T=NULL;
               delete(n);
            }
        	else
         //altrimenti mi sposto sul padre e, dopo aver verificato se fosse
         //figlio destro o sinistro, cancello opportunamente anche n
          	{
              	nodo temp=binpadre(n);
        	  		if(temp->sinistro==n)
                 	{
                    	temp->sinistro=NULL;
                     delete(n);
                  }
           		else
                 	{
                    	temp->destro=NULL;
                     delete(n);
                  }
           	}
     	}
	return;
}


//Specifica delle interfacce di utilizzo dei dati contenuti
Alberobin :: tipoelem Alberobin :: legginodo(nodo n)
   {
      if(!binalberovuoto())
      	return n->elem;
   }

void Alberobin :: scrivinodo(tipoelem e,nodo n)
   {
     	n->elem=e;
      return;
   }


//Specifica delle interfacce costrutttore e distruttore
Alberobin :: Alberobin()
	{
   	creabinalbero();
   }


//definizione del distruttore
Alberobin :: ~Alberobin()
	{
//   	if(!binalberovuoto())
  //    	cancsottobinalbero(binradice());
   }