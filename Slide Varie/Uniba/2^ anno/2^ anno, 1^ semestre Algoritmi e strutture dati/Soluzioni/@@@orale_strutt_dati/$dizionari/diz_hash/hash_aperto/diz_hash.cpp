//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//.................... REALIZZAZIONE DIZIONARIO HASH APERTO ....................
//..............................................................................



#include <stdlib.h>
#include <iostream.h>
#include "diz_hash.h"





//Specifica delle interfacce

void Diz :: crea()
   {
		for(int i=0;i<=MAX_LISTE_TRABOCCO;i++)
      	{
            Lista t;
      		diz[i]=t;
         }
   }



Diz :: boolean Diz :: appartiene(tipoelem b)
   {
      boolean trovato=false;

      int i=hash(b.key);
      pos p=diz[i].primolista();

      while(!diz[i].finelista(p))
      	{
         	if(diz[i].leggilista(p).key==b.key)
					return true;
            p=diz[i].succlista(p);
         }
      return false;
   }



void Diz :: inserisci(tipoelem b)
   {
      boolean trovato=false;

      int i=hash(b.key);
      pos p=diz[i].primolista();

		if(appartiene(b))
      	cout<<"\n Chiave gia' presente";
      else
			diz[i].inslista(p,b);
	}




void Diz :: cancella(tipochiave k)
   {
      int i=hash(k);
      pos p=diz[i].primolista();

      while(!diz[i].finelista(p))
      	{
         	if(diz[i].leggilista(p).key==k)
					{
                  diz[i].canclista(p);
               	return;
               }
            else
     				cout<<"\n Chiave non presente";
            p=diz[i].succlista(p);
         }
      return;
	}

Diz :: tipoelem Diz :: recupera(tipochiave k)
	{
      int i=hash(k);
      pos p=diz[i].primolista();

      while(!diz[i].finelista(p))
      	{
         	if(diz[i].leggilista(p).key==k)
            	return diz[i].leggilista(p);
            p=diz[i].succlista(p);
         }
      tipoelem fittizio;
      fittizio.key=0;
      fittizio.pezzi=-1;
 		return fittizio;
   }

void Diz :: aggiorna(tipochiave k,attributo n)
	{
      int i=hash(k);
      pos p=diz[i].primolista();

      tipoelem b;
      b.key=k;
      b.pezzi=n;

      while(!diz[i].finelista(p))
      	{
         	if(diz[i].leggilista(p).key==k)
            	diz[i].scrivilista(p,b);

            p=diz[i].succlista(p);
         }
      return;
	}

//costruttori e distruttori

Diz :: Diz()
//crea Diz vuota
   {
      crea();
   }

Diz :: ~Diz()
	{}


//funzione calcolo hash
int Diz :: hash(tipochiave k)
	{
     	return k%MAX_LISTE_TRABOCCO;
   }
