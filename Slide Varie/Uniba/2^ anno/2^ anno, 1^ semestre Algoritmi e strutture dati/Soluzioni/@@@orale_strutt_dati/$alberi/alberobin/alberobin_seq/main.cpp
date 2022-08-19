//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389

/*
- Costruire un albero binario
- Ricercare un elemento
- Potare un sottoalbero
- Calcolare il numero di nodi
- Stampare l'albero
*/


#include <stdlib.h>
#include <iostream.h>
#include "alberobin.h"
#include "alberobin.cpp"
#include "alberobin_servizio_def.cpp"


int main()
   {
      Alberobin Betulla;

      char repeat='s';

      int 	liv=0,
      		toFind=0,
            numNodi=0;

     	Betulla.insbinradice();
   	costruisci(Betulla,Betulla.binradice(),liv);
      cout<<"\n\n Schema di rappresentazione dell'albero\n\n";
      visitaOutput(Betulla, Betulla.binradice(), liv,numNodi);
      cout<<"\n Numero di nodi: "<<numNodi<<"\n";

      while(repeat=='s')
      	{
		  		cout<<"\n Inserisci il valore da cercare: ";
  				cin>>toFind;
		  		if(search(Betulla,Betulla.binradice(),toFind))
  					cout<<"\n Trovato";
		  		else
  					cout<<"\n Non Trovato";

		      cout<<"\n\n Vuoi cercare un'altro valore?"
      		 	 <<"\n Digita 's' in caso affermativo"
          		 <<"\n Digita altro in caso contrario:  ";

      		cin>>repeat;
         }

      cout<<"\n\n Potatura del sottoalbero destro della radice.\n";
      Betulla.cancsottobinalbero(Betulla.figliodestro(Betulla.binradice()));
      cout<<"\n\n Schema di rappresentazione dell'albero dopo la potatura\n";
      visitaOutput(Betulla, Betulla.binradice(), liv,numNodi);

      wait("\n\n Programma terminato\n per uscire digita [Y]+[invio]: ");
   }
