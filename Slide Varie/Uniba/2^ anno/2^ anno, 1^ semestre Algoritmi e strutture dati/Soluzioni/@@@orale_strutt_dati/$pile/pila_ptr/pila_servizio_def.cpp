#include <stdlib.h>
#include <iostream.h>

//prototipi funzioni di servizio
void setpila(Pila &);
void printpila(Pila &);
void printInvertpila(Pila);
void wait(char *);

//definizione funzioni di servizio
void setpila(Pila &pila)
	{
 		Pila :: tipoelem a;
      int num;

      cout<<"\n Con quanti elementi vuoi inizializzare la pila? ";
      cin>>num;
      while(num<=0)
         {
            cout<<"\n Il numero degli elementi deve essere maggiore"
                <<" o uguale a 1.\n Inserire nuovamente il numero: ";
            cin>>num;
         }

      cout<<" \n Inserisci ora il valore che"
          <<" vuoi assegnare a ciascun elemento:\n\n";

      for(int i=1;i<=num;i++)
         {
            cin>>a;
	        	pila.inpila(a);
         }
  	}

void printpila(Pila &pila)
	{
		Pila pila_appoggio;
		Pila :: tipoelem a;
		cout<<"\n TOP ->";
		while(!pila.pilavuota())
  			{
     			a=pila.leggipila();
     			cout<<"["<<a<<"]\n       ";
     			pila_appoggio.inpila(a);
     			pila.fuoripila();
         }
		while(!pila_appoggio.pilavuota())
  			{
     			a=pila_appoggio.leggipila();
     			pila.inpila(a);
     			pila_appoggio.fuoripila();
         }
 	}

void wait(char *msg)
//funzione utility per interrompere l'esecuzione del programma
//attende l'input dell'utente per ripartire
	{
   	char stop='?';

      cout<<msg;
      while(stop!='y' && stop!='Y')
      	cin>>stop;
   }
