#include <stdlib.h>
#include <iostream.h>
#include "alberon.h"
#include "alberon.cpp"
#include "alberon_servizio_def.cpp"

int main()
   {
      Alberon Tree,Fronda;
      char elemento='?',ripeti='s';
      nodo n;
      int 	liv=0,
      		toFind=0,
            numNodi=0;
      cout<<"\n\n Costruzione dell'albero Tree.\n";
     	Tree.insradice();
   	costruisci(Tree,Tree.radice(),liv);

      cout<<"\n\n Schema di rappresentazione dell'albero\n\n";
      visitaOutput(Tree, Tree.radice(), liv,numNodi);
      cout<<"\n Numero di nodi: "<<numNodi<<"\n";
      numNodi=0;

      cout<<"\n\n Costruzione dell'albero Fronda da innestare in seguito.\n";
     	Fronda.insradice();
   	costruisci(Fronda,Fronda.radice(),liv);

      cout<<"\n\n Schema di rappresentazione della Fronda\n\n";
      visitaOutput(Tree, Fronda.radice(), liv,numNodi);
      cout<<"\n Numero di nodi: "<<numNodi<<"\n";
      numNodi=0;

      cout<<"\n\n Ricerca del nodo n tale che l'etichetta"
      	 <<" sia pari ad un valore dato.\n";
      while(ripeti=='s')
			{
      	 	cout<<"\n\n Digita il carattere da ricercare:";
      		while(elemento<='A' || elemento>='z')
  					cin>>elemento;

      		n=search(Tree, Tree.radice(),elemento);
            if(n!=NULL)
     				cout<<"\n trovato: "<<Tree.legginodo(n)<<"\n";
            else
  					cout<<"\n Elemento non trovato!\n";

      	 	cout<<"\n\n Se vuoi ricercare un altro elemento\n digita 's': ";
				cin>>ripeti;
				elemento='?';
         }
      if(n!=NULL)
      	{
      		cout<<"\n\n Innesto  della Fronda come fratello di n.\n";
      		Tree.insottoalbero(Tree.padre(n),Tree.padre(n),Fronda);
      		cout<<"\n\n Schema di rappresentazione dell'albero dopo l'innesto\n";
      		visitaOutput(Tree, Tree.radice(), liv,numNodi);
      		cout<<"\n Numero di nodi: "<<numNodi<<"\n";
      		numNodi=0;
      		wait("\n\n Per procedere digita [Y]+[invio]: ");

		      cout<<"\n\n Potatura del sottoalbero con radice in n.\n";
      		Tree.cancsottoalbero(n);
		      cout<<"\n\n Schema di rappresentazione dell'albero post potatura\n";
      		visitaOutput(Tree, Tree.radice(), liv,numNodi);
		      cout<<"\n Numero di nodi: "<<numNodi<<"\n";
      		wait("\n\n Per procedere digita [Y]+[invio]: ");
			}
      cout<<"\n\n Calcolo della profondita' dell'albero.\n";
      wait("\n\n Per procedere digita [Y]+[invio]: ");
      cout<<"La profondita' dell'albero e': "<<depth(Tree,Tree.radice());
      wait("\n\n Programma terminato\n per uscire digita [Y]+[invio]: ");
   }
