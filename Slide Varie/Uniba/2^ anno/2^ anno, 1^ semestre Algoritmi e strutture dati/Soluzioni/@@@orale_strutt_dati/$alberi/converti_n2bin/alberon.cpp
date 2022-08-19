//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//................... REALIZZAZIONE ALBERO N-ario CON LISTA ....................
//........................... PRIMOFIGLIO/FRATELLO .............................
//..............................................................................



#include <stdlib.h>
#include <iostream.h>
#include "alberon.h"



void Alberon :: crealbero()
   {
      T=NULL;
   }

Alberon :: boolean Alberon :: alberovuoto()
   {
      return T==NULL;
   }

Alberon :: nodo Alberon :: radice()
   {
      if(!alberovuoto())
      	return T;
      else
      	cout<<"\u L'albero e' vuoto";
   }

Alberon :: nodo Alberon :: padre(nodo u)
   {
      if(!alberovuoto()&& u!=radice())
      	return u->padre;
   	else
      	return NULL;
   }

Alberon :: nodo Alberon :: primofiglio(nodo u)
   {
      if(!alberovuoto())
      	return u->primofiglio;
   	else
      	return NULL;
   }

Alberon :: nodo Alberon :: succfratello(nodo u)
   {
      if(!alberovuoto())
      	return u->fratello;
   }

Alberon :: boolean Alberon :: ultimofratello(nodo u)
   {
     	if(succfratello(u)==NULL)
  			return true;
      else
      	return false;
   }

Alberon :: boolean Alberon :: foglia(nodo u)
   {
     	return u->primofiglio==NULL;
   }

void Alberon :: cancsottoalbero(nodo u)
	{
      nodo corrente,prec;
   	if(!alberovuoto())//controlla che l'albero non sia vuoto
	   	{
            if(!foglia(u))
					cancsottoalbero(primofiglio(u));
            else
            	{
            	//individuo il primo tra i fratelli di u e lo pongo in corrente
            		corrente=u->padre->primofiglio;
            		if(corrente==u) //se il corrente è proprio u
               		//pongo come primo figlio il fratello successivo di u
            			u->padre->primofiglio=u->fratello;
            		else   //altrimenti
               		{
                     	//scandisco i fratelli fino a trovare u
               			while(corrente!=u)
            	   			{
                  				//memorizzando in prec il fratello che lo precede
	            					prec=corrente;
   	         					corrente=corrente->fratello;
      	      				}
	      	      		//trovato u pongo come fratello del suo predecessore,
   	      	   		//il fratello dello stesso u (scavalcandolo)
      	      			prec->fratello=u->fratello;
cout<<"\n*** "<<prec->elem;
cout<<"\n*** "<<u->elem;
cout<<"\n*** "<<u->fratello;
            			}
 		      		delete u;
            	}
 	    	}
		return;
	}

Alberon :: tipoelem Alberon :: legginodo(nodo u)
   {
      if(!alberovuoto())
      	return u->elem;
   }

void Alberon :: scrivinodo(tipoelem a,nodo u)
   {
     	u->elem=a;
      return;
   }

void Alberon :: insradice()
   {
		nodo u=new componente;
      u->padre=NULL;
      u->primofiglio=NULL;
      u->fratello=NULL;
		T=u;

      return;
   }

void Alberon :: insottoalbero(nodo u,nodo v, Alberon &S)
   {
		if(!alberovuoto())
         {
				if(u==v)
            	{
                  S.radice()->padre=u;
                  S.radice()->fratello=u->primofiglio;
                	u->primofiglio=S.radice();
               }
            else
            	{
                  S.radice()->padre=u;
                  S.radice()->fratello=v->fratello;
                	v->fratello=S.radice();
               }
         }
      else
      	T=S.radice();

      return;
   }

//costruttori e distruttori
Alberon :: Alberon()
   {
   	crealbero();
   }

Alberon :: ~Alberon()
	{
   	//if(!alberovuoto())
      	//cancsottoalbero(radice());
   }
