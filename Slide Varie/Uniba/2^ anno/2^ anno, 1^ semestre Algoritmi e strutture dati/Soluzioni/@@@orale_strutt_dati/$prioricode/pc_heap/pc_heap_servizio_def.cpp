#include <stdlib.h>
#include <iostream.h>
#define N 10

//definizione funzioni di servizio
void pc_sort(tipoelem* vettore)
	{
 		Prioricoda C;
      int i;

      for(i=0;i<N;i++)
			C.inserisci(vettore[i]);

      for(i=0;i<N;i++)
      	{
				vettore[i]=C.min();
         	C.cancellamin();
         }
		return;
  	}

void printvettore(tipoelem* vettore)
	{
      int i;
		cout<<"\n Il vettore e': ";

      for(i=0;i<N;i++)
      	{
				cout<<"["<<vettore[i]<<"]";
         }
 	}

void setvettore(tipoelem* vettore)
	{
      int i=0;

      cout<<"\n Inserire di seguito i valori delle componenti del vettore:\n\n";
      while(i<N)
      	{
            cout<<"  V["<<i<<"]=";
            cin>>vettore[i];
            i++;
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
