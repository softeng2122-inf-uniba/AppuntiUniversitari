#include <stdlib.h>
#include <iostream.h>
#define N 10


//definizione delle funzioni di servizio

void setIns(Ins &ins)
//funzione che popola un'insieme con inserimento dei valori
//da parte dell'utente
   {
      Ins :: tipoelem val;
      int num;

      cout<<"\n Con quanti elementi vuoi inizializzare l'insieme? ";
      cin>>num;
      while(num<=0)
         {
            cout<<"\n Il numero degli elementi deve essere maggiore"
                <<" o uguale a 1.\n Inserire nuovamente il numero: ";
            cin>>num;
         }

      cout<<"\n Inserisci ora il valore che "
          <<"vuoi assegnare a ciascun elemento:\n\n";

      for(int i=0;i<num;i++)
         {
            cin>>val;
            ins.inserisci(val);
         }
		return;
	}



void test(Ins &ins, int* el)
	{
		for(int i=0;i<N;i++)
      	{
      		if(ins.appartiene(el[i]))
      			cout<<"\n l'elemento "<<el[i]<<" appartiene all'insieme";
      		else
      			cout<<"\n l'elemento "<<el[i]<<" non appartiene all'insieme";
      	}
      return;
	}

void test_canc(Ins &ins, int* el)
	{
		for(int i=0;i<N;i++)
      	{
      		if(ins.appartiene(el[i]))
            	{
      				cout<<"\n l'elemento "<<el[i]<<" appartiene all'insieme";
                  ins.cancella(el[i]);
               }
      		else
      			cout<<"\n l'elemento "<<el[i]<<" non appartiene all'insieme";
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