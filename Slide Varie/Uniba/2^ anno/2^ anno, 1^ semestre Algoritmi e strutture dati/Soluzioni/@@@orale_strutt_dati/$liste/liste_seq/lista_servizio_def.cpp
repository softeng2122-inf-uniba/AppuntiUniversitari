

#include <stdlib.h>
#include <iostream.h>


//dichiarazione delle funzioni di servizio
void           setlista(Lista &);
void           printlista(Lista &);
void           epuralista(Lista &lista);
void           sortlista(Lista &);
Lista :: pos   searchlista(Lista &, Lista :: tipoelem);
void wait(char *);




//definizione delle funzioni di servizio


void setlista(Lista &lista)
//funzione che popola una lista con inserimento dei valori
//da parte dell'utente
   {
      Lista :: tipoelem val;
      int num;

      cout<<"\n Con quanti elementi vuoi inizializzare la lista? ";
      cin>>num;
      while(num<=0)
         {
            cout<<"\n Il numero degli elementi deve essere maggiore"
                <<" o uguale a 1.\n Inserire nuovamente il numero: ";
            cin>>num;
         }

      cout<<" \n Inserisci ora il valore che "
          <<"vuoi assegnare a ciascun elemento:\n\n";

      for(int i=1;i<=num;i++)
         {
            cin>>val;
            lista.inslista(lista.primolista(),val);
         }
}



void printlista(Lista &lista)
//stampa a video la lista con accorgimenti grafici
   {
      Lista :: pos p=lista.primolista();
      cout<<"\n\n ";
      while(!lista.finelista(p))
         {
            cout<<"["<<lista.leggilista(p)<<"]->";
            p=lista.succlista(p);
         }
      cout<<"[NULL]";
   }




void epuralista(Lista &lista)
//elimina i doppioni nella lista
   {
      Lista :: pos p=lista.primolista(),
               pivot=lista.succlista(p);
      while(p!=lista.ultimolista())
         {
            while(!lista.finelista(pivot))
               {
                  if(lista.leggilista(pivot)==lista.leggilista(p))
                     {
                        lista.canclista(pivot);
                        pivot=lista.succlista(p);
                     }
                  else
                     pivot=lista.succlista(pivot);
               }
            if(p!=lista.ultimolista())
               p=lista.succlista(p);
            else
               p=lista.ultimolista();
            pivot=lista.succlista(p);
         }
  }





void sortlista(Lista &lista)
//ordina i nodi di una lista in modo crescente (insert sort)
   {
      Lista :: pos p=lista.primolista(),
                   min,
                   pivot;
      while(!lista.finelista(p)) //scandisce il resto della lista
         {
            min=p;
            pivot=lista.succlista(p); //passa al pivot successivo
            while(!lista.finelista(pivot))  //trova minimo relativo
               {
                  //confronta il min assunto con il pivot scandito
                  if(lista.leggilista(pivot)<lista.leggilista(min))
                     min=pivot;
                  pivot=lista.succlista(pivot); //passa al pivot successivo
               }

            if(p==min)
            	p=lista.succlista(p);
            else
            	{
            		//si inserisce un nuovo nodo contenente il valore min
            		//in testa alla parte di lista non ancora scandita
            		lista.inslista(p,lista.leggilista(min));
            		//si elimina il nodo nella posizione originale di min
            		lista.canclista(min);
               }
         }
   }



Lista :: pos searchlista(Lista &lista, Lista :: tipoelem elem)
//rileva la presenza o meno di un valore (digitato dall'utente)
//tra i nodi della lista
   {
   	Lista :: pos p=lista.primolista();

     	while(!lista.finelista(p) && lista.leggilista(p)!=elem)
	      p=lista.succlista(p);

      if(!lista.finelista(p))
      	cout<<"\n Elemento presente!";
      else
         cout<<"\n Elemento non presente!";
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
   }