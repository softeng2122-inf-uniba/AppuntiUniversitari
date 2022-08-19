//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//............... REALIZZAZIONE DIZIONARIO CON VETTORE ORDINATO ................
//..............................................................................



#include <stdlib.h>
#include <iostream.h>
#include <string.h>
#include "diz.h"




//Specifica delle interfacce

void Diz :: crea()
   {
		ultimo=0;
   }



Diz :: boolean Diz :: appartiene(tipoelem a)
   {
     	if(ricbin(a.key,0,ultimo)>=0)
      	return true;
      else
      	return false;
   }



void Diz :: cancella(tipochiave k)
   {
      int primo=0;

      if(strcmp(k,diz[ultimo-1].key)==0)
      //confronto con l'ultimo elemento per risparmiare il ciclo
      //di ricompattamento
      	{
            ultimo--;
            return;
         }

		int i=ricbin(k, 1, ultimo);

      if(i>=0)
			{
                  for(int j=i;j<ultimo;j++)
                  //ciclo di ricompattamento
                  	diz[j].key=diz[j+1].key;
       				ultimo--;
                  return;
         }
      else
      	cout<<"\n Articolo inesistente.";
	}



void Diz :: inserisci(tipoelem a)
   {

      int primo=1;

   	if(ultimo==0)	//controllo sul dizionario vuoto
        	{
         	diz[primo-1]=a;
            ultimo=primo;
            return;
         }
      else
        	if(ultimo==N)  //controllo sul dizionario pieno
           	{
           		cout<<"\n Hai superato il limite di memoria disponibile";
               return;
            }

      if(strcmp(a.key,diz[ultimo-1].key)>0)
      //confronto con l'ultimo elemento per risparmiare il ciclo
      //di inserimento ordinato
      	{
            ultimo++;
         	diz[ultimo-1]=a;
            return;
         }

   	for(int i=primo;i<=ultimo;i++)
      //ciclo di inserimento
      	{
            if(strcmp(a.key,diz[i-1].key)==0) //controllo contro inserimenti ripetuti
               return;
            else
            	if(strcmp(a.key,diz[i-1].key)<0) //controllo relazione d'ordine
               	{
                     for(int j=ultimo;j>=i;j--)
                     //ciclo di spostamento elementi maggiori di a per libararne
                     //la locazione necessaria per conservare l'ordinamento
                     	diz[j]=diz[j-1];
                     diz[i-1]=a;
         				ultimo++;
                     return;
                  }
         }
	}




Diz :: tipoelem Diz :: recupera(tipochiave k)
	{
      int i=ricbin(k, 1, ultimo);
      if(i>=0)
   		return diz[i];
      else
      	{
     			cout<<"\n Articolo inesistente.";
            tipoelem bucket;
            bucket.key=k;
            bucket.pezzi=-1;
	   		return bucket;
         }
   }


void Diz :: aggiorna(tipochiave k,attributo n)
	{
      int i=ricbin(k, 1, ultimo);
      if(i>=0)
   		diz[i].pezzi=n;
	}

//costruttori e distruttori

Diz :: Diz()
//crea Diz vuota
   {
      crea();
   }


Diz :: ~Diz()
	{}



//funzione di ricerca binaria
int Diz :: ricbin(tipochiave key, int i, int j)
   {
      int medio;
      if(i>j)
      	return -1;
      else
      	{
            medio=(i+j)/2;
      		if(strcmp(key,diz[medio-1].key)==0)
            	return medio-1;
            else
            	if(strcmp(key,diz[medio-1].key)<0)
               	ricbin(key,i,medio-1);
               else
               	ricbin(key,medio+1,j);
         }
   }

