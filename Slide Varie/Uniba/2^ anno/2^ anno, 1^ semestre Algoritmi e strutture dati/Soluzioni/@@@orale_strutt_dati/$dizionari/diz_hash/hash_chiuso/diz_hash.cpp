//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//.................... REALIZZAZIONE DIZIONARIO HASH CHIUSO ....................
//..............................................................................



#include <stdlib.h>
#include <iostream.h>
#include "diz_hash.h"





//Specifica delle interfacce

void Diz :: crea()
   {
		for(int i=0;i<=MAX_BUCKET;i++)
      	diz[i].key=LIBERO;
   }



Diz :: boolean Diz :: appartiene(tipoelem b)
   {
      boolean trovato=false;

		if(diz[scan(b.key,&trovato)].key==b.key)
     		return true;
   }



void Diz :: inserisci(tipoelem b)
   {
      boolean trovato=false;
      int newindice=scan(b.key,trovato);

		if(trovato)
      	cout<<"\n Chiave già presente";
      else
      	if(newindice<MAX_BUCKET)
				diz[newindice]=b;
         else
      		cout<<"\n Dizionario pieno";
	}



void Diz :: cancella(tipochiave k)
   {
      boolean trovato=false;
      int newindice=scan(k,trovato);

		if(trovato)
			diz[newindice].key=CANCELLATO;
      else
     		cout<<"\n Chiave non presente";
	}




Diz :: tipoelem Diz :: recupera(tipochiave k)
	{
      boolean trovato=false;
      int i=scan(k,trovato);

		if(trovato)
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
      boolean trovato=false;
      int i=scan(k,trovato);
		if(trovato)
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





//funzione calcolo hash
int Diz :: hash(tipochiave k)
	   	{
           	return k%MAX_BUCKET;
         }












//funzione ricerca hash
int Diz :: scan(tipochiave k, boolean &trovato)
	   	{
 				int 		indice,		//punta alla chiave corrente
                     primo,      //se indice torna ad assumere il suo valore
                     				//il ciclo di scansione si considera terminato
                     candidato;  //conserverà la posizione della prima chiave
                     				//che risulterà cancellata

            boolean  terminato,  //nel while varrà true quando primo==indice
            			prenotato;  //nel while varrà true quando sarà incontrata
                     				//la prima chiave cancellata

            //inizializzazione
            primo=indice=hash(k);
            terminato=prenotato=false;

            while(!terminato && diz[indice].key!=LIBERO)
            //ci sono tre vie per uscire dal ciclo:
            //1) quando si ritorna alla chiave di partenza (terminato)
            //2) quando si trova la prima chiave libera
            //3) quando quando si trova la chiave cercata
            	{
               	if(diz[indice].key==k) //se la chiave è quella cercata
                  	{
                     	trovato=true;
                        return indice;
                     }
                  else
                  	{
                        indice=(indice+1)%MAX_BUCKET; //calcolo del prox indice

                        //se l'indice corrente coincide col primo
                        //allora considero il ciclo terminato
		                  if(primo==indice)
      		            	terminato=true;
                        //altrimenti se la corrispondente chiave risulta
                        //cancellata ne memorizzo la posizione e blocco
                        //l'accesso alla variabile per eventuali successive
                        //chiavi cancellate.
                        else
	                        if(diz[indice].key==CANCELLATO && !prenotato)
   	                     	{
      	                     	candidato=indice;
         	                     prenotato=true;
            	               }
                     }
               } //fine del ciclo while
            //se all'uscita del ciclo di scansione risultasse una locazione
            //prenotata allora si restituisce l'indice ti tale locazione
            if(prenotato)
           		return candidato;
            else
            	//se la scansione risultasse completa (senza alcuna prenotazione)
               //allora si restituisce un valore di indice non non ammissibile
               //che sarà interpretato dall'esterno della funzione
            	if(terminato)
               	return MAX_BUCKET;
               //altrimenti si dedurrebbe che sia stata incontrata una locazione
               //libera e quindi se ne restituisce l'indice
               else
              		return indice;
         }
