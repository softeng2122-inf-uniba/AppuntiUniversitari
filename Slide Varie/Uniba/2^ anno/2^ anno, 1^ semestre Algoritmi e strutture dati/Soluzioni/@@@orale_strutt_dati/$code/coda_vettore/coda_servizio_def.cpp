

#include <stdlib.h>
#include <iostream.h>


//prototipi funzioni di servizio
void setcoda(Coda &);
void printcoda(Coda &);
void printInvertcoda(Coda);
void wait(char *);




//definizione funzioni di servizio
void setcoda(Coda &coda)
	{
 		Coda :: tipoelem a;
      int num;

      cout<<"\n Con quanti elementi vuoi inizializzare la coda? ";
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
	        	coda.incoda(a);
         }
  	}


void printcoda(Coda &coda)
	{
		Coda :: tipoelem a;
      Coda coda_appoggio;

		cout<<"\n TOP <-";
		while(!coda.codavuota())
  			{
     			a=coda.leggicoda();
     			cout<<"["<<a<<"]\n       ";
            coda_appoggio.incoda(a);
     			coda.fuoricoda();
         }
cout<<" ^  FONDO";
		while(!coda_appoggio.codavuota())
  			{
     			a=coda_appoggio.leggicoda();
            coda.incoda(a);
     			coda_appoggio.fuoricoda();
         }
 	}



void wait(char *msg)
//funzione utility per interrompere l'esecuzione del programma
//attende l'input dell'utente per ripartire
	{
   	char stop='?';

      cout<<msg;
      while(stop!='Y' && stop!='y')
      	cin>>stop;
   }
