//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//............... REALIZZAZIONE LISTA COLLEGATA CON CURSORI ....................
//..............................................................................



#include <iostream.h>
#include <stdlib.h>
#include "lista.h"

//definizione degli operatori di ausilio per la gestione della freelist

void Lista :: init_listalibera()
	{
      listalibera=1;
   	for(int i=1; i<N; i++)
         {
    			spazio[i].succ=i+1;
         }
	}

void Lista :: sposta_elemento(pos &h,pos &k)
	{
		if(k==0)
      	{
      		k=h;
      		h=spazio[h].succ;
      		spazio[k].succ=0;
         }
		else
     		{
  				pos temp=k;
     			k=h;
      		h=spazio[h].succ;
  	   		spazio[k].succ=temp;
     	   }
   }

//definizione degli operatori della classe Lista

void Lista::crealista()
	{
   	init_listalibera();
      L=0;
   }

Lista::boolean Lista::listavuota()
	{
   	return L==0;
   }

pos Lista::primolista()
	{
   	return L;
   }






Lista :: pos Lista :: ultimolista()
   {
      pos pre,p=L;
      while(!finelista(p))
         {
         	pre=p;
         	p=succlista(p);
         }
      return pre;
   }

Lista::boolean Lista::finelista(pos p)
	{
   	return p==0;
   }

Lista::tipoelem Lista::leggilista(pos p)
	{
		return spazio[p].elem;
   }

void Lista::scrivilista(tipoelem a, pos p)
	{
   	spazio[p].elem=a;
   }

pos Lista::succlista(pos p)
	{
		if(!finelista(p))
   		return spazio[p].succ;;
	}

pos Lista::predlista(pos p)
	{
    pos pivot,pre=primolista();
    if(p!=primolista())
       while(spazio[pivot].succ!=p)
       	{
				pre=pivot;
         	pivot=succlista(pivot);
         }
	    return pre;
	}

void Lista::inslista(pos &p,tipoelem a)
	{
      if(listalibera==N)
      	cout<<"\n ATTENZIONE: limite di spazio raggiunto";
      else
    		{
            if(p==L)
            	{
						sposta_elemento(listalibera,p);
     					spazio[p].elem=a;
                  L=p;
               }
            else
            	{
		         	pos pivot=primolista();
						while(spazio[pivot].succ!=p)
      					pivot=succlista(pivot);
						sposta_elemento(listalibera,spazio[pivot].succ);
     					spazio[spazio[pivot].succ].elem=a;
               }
			}
	}






void Lista::canclista(pos p)
	{
   	if(p==L)
        	{
				sposta_elemento(p,listalibera);
            L=p;
         }
      else
      	{
         	pos pivot=primolista();
				while(spazio[pivot].succ!=p)
      			pivot=succlista(pivot);
				sposta_elemento(spazio[pivot].succ,listalibera);
   		}
	}

//implementazione dei costruttori e del distruttore

Lista::Lista()
	{
   	crealista();
   }

Lista::~Lista(){}
