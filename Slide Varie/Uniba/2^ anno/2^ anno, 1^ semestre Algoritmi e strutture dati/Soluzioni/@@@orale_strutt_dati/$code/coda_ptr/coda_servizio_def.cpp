#include <stdlib.h>
#include <iostream.h>


//prototipi funzioni di servizio
void setCoda(Coda &);
void printCoda(Coda &);
void printInvertCoda(Coda);
void wait(char *);




//definizione funzioni di servizio
void setCoda(Coda &coda)
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
	        	coda.inCoda(a);
         }
  	}





void printCoda(Coda &coda)
	{
		Coda :: tipoelem a;
      Coda coda_appoggio;

		cout<<"\n TOP <-";
		while(!coda.codaVuota())
  			{
     			a=coda.leggiCoda();
     			cout<<"["<<a<<"]\n       ";
            coda_appoggio.inCoda(a);
     			coda.fuoriCoda();
         }
cout<<" ^  FONDO";
		while(!coda_appoggio.codaVuota())
  			{
     			a=coda_appoggio.leggiCoda();
            coda.inCoda(a);
     			coda_appoggio.fuoriCoda();
         }
 	}









void printInvertCoda(Coda coda)
	{
		Coda inversa;
		Coda :: tipoelem a;
		while(!coda.codaVuota())
			{
     			a=coda.leggiCoda();
     			coda.fuoriCoda();
     			inversa.inCoda(a);
   			}
  		cout<<"\n TOP ->";
		while(!inversa.codaVuota())
  			{
     			a=inversa.leggiCoda();
     			cout<<"["<<a<<"]\n       ";
     			inversa.fuoriCoda();
     			coda.inCoda(a);
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
