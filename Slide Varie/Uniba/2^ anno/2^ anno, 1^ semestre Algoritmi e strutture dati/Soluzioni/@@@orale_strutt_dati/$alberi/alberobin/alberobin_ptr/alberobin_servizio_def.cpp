//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389


/*
- Costruire interattivamente l'albero
- Visita e stampa dell'albero in preordine
- Verifica presenza di un elemento
- Calcolo del numero di nodi
*/



#include <stdlib.h>
#include <iostream.h>





//definizione delle funzioni di servizio
void	visitaOutput(AlberoBin &, AlberoBin :: nodo, int, int &);
void  costruisci(AlberoBin &, AlberoBin :: nodo, int);
AlberoBin :: boolean search(AlberoBin &,AlberoBin::nodo,AlberoBin::tipoelem);
void wait(char *msg);




void visitaOutput(AlberoBin &tree, AlberoBin::nodo n, int counter, int &numNodi)
//preordine con conteggio del livello di profondità
//e stampa del contenuto
	{
   	int 	i;
      numNodi++;

      for(i=0;i<counter-1;i++)
			cout<<"    ";
      if(counter>0)
   		cout<<"+---";
      cout<<tree.leggiNodo(n)<<"\n";

   	if (!tree.sinistroVuoto(n))
        	visitaOutput(tree, tree.figlioSinistro(n),counter+1,numNodi);
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

      if (!tree.destroVuoto(n))
     		visitaOutput(tree, tree.figlioDestro(n),counter+1,numNodi);
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





AlberoBin :: boolean search(AlberoBin &tree,AlberoBin::nodo n,AlberoBin::tipoelem e)
//preordine con segnalazione di elemento trovato
	{
      boolean found=false;

	  	if(tree.leggiNodo(n)==e)
      	return true;

   	if (!tree.sinistroVuoto(n))
         	found=search(tree, tree.figlioSinistro(n),e);
      if(!found)
      	if (!tree.destroVuoto(n))
      		found=search(tree, tree.figlioDestro(n),e);

		return found;
   }


void costruisci(AlberoBin &tree, AlberoBin::nodo n, int counter)
//Crea e popola un albero
	{
      int val;
      char side='?';

		if(n==tree.binRadice())
      	{
            cout<<"\n Livello"<<counter;
				cout<<"\n Inserisci il valore del nodo corrente: ";
      		cin>>val;
		      tree.scriviNodo(val,n);
            cout<<"\n nodo Radice etichetta:["<<tree.leggiNodo(n)<<"]";
            counter++;
         }

      cout<<"\n Vuoi aggiungere un figlio?"
  		    <<"\n Digita:\n   's' per il sinistro,\n"
          <<"   'd' per il destro (senza il sinistro)\n"
  		    <<"   'x' per non aggiungere figli: ";
      while(side!='s' && side!='d' && side!='x')
  			cin>>side;

      if(side=='s')
        	{
            cout<<"\n Livello"<<counter;
				cout<<"\n Inserisci il valore del nodo corrente: ";
      		cin>>val;
         	tree.insFiglioSinistro(n);
		      tree.scriviNodo(val,tree.figlioSinistro(n));
            cout<<"\n nodo["<<val<<"] - figlio sinistro del";
            cout<<" nodo["<<tree.leggiNodo(n)<<"]";
           	costruisci(tree, tree.figlioSinistro(n), counter+1);
            cout<<"\n Livello"<<counter;
            cout<<"\n nodo["<<val<<"] - figlio sinistro del";
            cout<<" nodo["<<tree.leggiNodo(n)<<"]";
		      cout<<"\n Vuoi aggiungere un fratello a destra?"
              	 <<"\n Digita:\n   'd' in caso affermativo,\n"
            	 <<"   'x' per non aggiungere figli: ";
		      while(side!='d' && side!='x')
      	   	cin>>side;
         }

      if(side=='d')
        	{
            cout<<"\n Livello"<<counter;
				cout<<"\n Inserisci il valore del nodo corrente: ";
      		cin>>val;
         	tree.insFiglioDestro(n);
		      tree.scriviNodo(val,tree.figlioDestro(n));
            cout<<"\n nodo["<<val<<"] - figlio destro del";
            cout<<" nodo["<<tree.leggiNodo(n)<<"]";
           	costruisci(tree, tree.figlioDestro(n), counter+1);
            cout<<"\n Livello"<<counter;
            cout<<"\n nodo["<<val<<"] - figlio destro del";
            cout<<" nodo["<<tree.leggiNodo(n)<<"]";
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

