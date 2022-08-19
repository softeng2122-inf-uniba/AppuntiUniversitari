//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389

/*
- Costruire un albero binario
- Ricercare un elemento
- Calcolare il numero dei nodi
- Potare un sottoalbero
- Stampare l'albero
*/


#include <stdlib.h>
#include <iostream.h>
#include "alberobin_class.h"
#include "alberobin_class_def.cpp"
#include "alberobin_servizio_def.cpp"


int main()
   {
      AlberoBin Tree;

      char repeat='s';

      int 	liv=0,
      		toFind=0,
            numNodi=0;

     	Tree.insBinRadice();
   	costruisci(Tree,Tree.binRadice(),liv);
      cout<<"\n\n Schema di rappresentazione dell'albero\n\n";
      visitaOutput(Tree, Tree.binRadice(), liv,numNodi);
      cout<<"\n Numero di nodi: "<<numNodi<<"\n";

      while(repeat=='s')
      	{
		  		cout<<"\n Inserisci il valore da cercare: ";
  				cin>>toFind;
		  		if(search(Tree,Tree.binRadice(),toFind))
  					cout<<"\n Trovato";
		  		else
  					cout<<"\n Non Trovato";

		      cout<<"\n\n Vuoi cercare un'altro valore?"
      		 	 <<"\n Digita 's' in caso affermativo"
          		 <<"\n Digita altro in caso contrario:  ";

      		cin>>repeat;
         }

      cout<<"\n\n Potatura del sottoalbero destro della radice.\n";
      Tree.cancSottoBinAlbero(Tree.figlioDestro(Tree.binRadice()));
      cout<<"\n\n Schema di rappresentazione dell'albero dopo la potatura\n";
      visitaOutput(Tree, Tree.binRadice(), liv,numNodi);

      wait("\n\n Programma terminato\n per uscire digita [Y]+[invio]: ");
   }
