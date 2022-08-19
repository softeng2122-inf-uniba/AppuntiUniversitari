//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389

/*
- Costruire interattivamente l'albero
- visita e stampa dell'albero in preordine
- verifica presenza di un elemento
- Calcolo del numero di nodi
*/




#include <stdlib.h>
#include <iostream.h>





//definizione delle funzioni di servizio


void visitaOutput(Alberobin &tree, Alberobin :: nodo n, int counter, int &numnodi)
//preordine con conteggio del livello di profondità
//e stampa del contenuto
	{
   	int 	i;
      numnodi++;

      for(i=0;i<counter-1;i++)
			cout<<"    ";
      if(counter>0)
   		cout<<"+---";
      cout<<tree.legginodo(n)<<"\n";

   	if (!tree.sinistrovuoto(n))
        	visitaOutput(tree, tree.figliosinistro(n),counter+1,numnodi);
   	else
      	{
		      for(i=0;i<counter;i++)
					cout<<"    ";

				if(counter==0)
      			cout<<"    ";

		      if(counter>0)
   				cout<<"+---";
     			cout<<"<>\n";
         }

      if (!tree.destrovuoto(n))
     		visitaOutput(tree, tree.figliodestro(n),counter+1,numnodi);
   	else
      	{
		      for(i=0;i<counter;i++)
					cout<<"    ";

		      if(counter>0)
   				cout<<"+---";
     			cout<<"<>\n";
         }
		return;
   }


Alberobin :: boolean search(Alberobin &tree,Alberobin::nodo n,Alberobin::tipoelem e)
//preordine con segnalazione di elemento trovato
	{
      boolean found=false;
	  	if(tree.legginodo(n)==e)
      	return true;
   	if (!tree.sinistrovuoto(n))
         	found=search(tree, tree.figliosinistro(n),e);
      if(!found)
      	if (!tree.destrovuoto(n))
      		found=search(tree, tree.figliodestro(n),e);
		return found;
   }

void costruisci(Alberobin &tree, Alberobin::nodo n, int counter)
//Crea e popola un albero
	{
      int val;
      char side='?';

		if(n==tree.binradice())
      	{
            cout<<"\n Livello"<<counter;
				cout<<"\n Inserisci il valore del nodo corrente: ";
      		cin>>val;
		      tree.scrivinodo(val,n);
            cout<<"\n nodo Radice etichetta:["<<tree.legginodo(n)<<"]";
            counter++;
         }

      cout<<"\n vuoi aggiungere un figlio?"
  		    <<"\n digita:\n   's' per il sinistro,\n"
          <<"   'd' per il destro (senza il sinistro)\n"
  		    <<"   'x' per non aggiungere figli: ";
      while(side!='s' && side!='d' && side!='x')
  			cin>>side;

      if(side=='s')
        	{
            cout<<"\n Livello"<<counter;
				cout<<"\n Inserisci il valore del nodo corrente: ";
      		cin>>val;
         	tree.insfigliosinistro(n);
		      tree.scrivinodo(val,tree.figliosinistro(n));
            cout<<"\n nodo["<<val<<"] - figlio sinistro del";
            cout<<" nodo["<<tree.legginodo(n)<<"]";
           	costruisci(tree, tree.figliosinistro(n), counter+1);
            cout<<"\n Livello"<<counter;
            cout<<"\n nodo["<<val<<"] - figlio sinistro del";
            cout<<" nodo["<<tree.legginodo(n)<<"]";
		      cout<<"\n vuoi aggiungere un fratello a destra?"
              	 <<"\n digita:\n   'd' in caso affermativo,\n"
            	 <<"   'x' per non aggiungere figli: ";
		      while(side!='d' && side!='x')
      	   	cin>>side;
         }
      if(side=='d')
        	{
            cout<<"\n Livello"<<counter;
				cout<<"\n Inserisci il valore del nodo corrente: ";
      		cin>>val;
         	tree.insfigliodestro(n);
		      tree.scrivinodo(val,tree.figliodestro(n));
            cout<<"\n nodo["<<val<<"] - figlio destro del";
            cout<<" nodo["<<tree.legginodo(n)<<"]";
           	costruisci(tree, tree.figliodestro(n), counter+1);
            cout<<"\n Livello"<<counter;
            cout<<"\n nodo["<<val<<"] - figlio destro del";
            cout<<" nodo["<<tree.legginodo(n)<<"]";
         }
      return;
   }


void wait(char *msg)
//funzione utility per interrompere l'esecuzione del programma
//attende l'input dell'utente per ripartire
//richiede una strinda come argomento, essa sarà visualizzata
//come messaggio per l'utente
	{
   	char stop='?';

      cout<<msg;
      while(stop!='y' && stop!='Y')
      	cin>>stop;
		return;
   }

