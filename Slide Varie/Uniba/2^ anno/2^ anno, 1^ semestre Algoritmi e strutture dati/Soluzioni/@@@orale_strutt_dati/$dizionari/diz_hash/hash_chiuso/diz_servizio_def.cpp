#include <stdlib.h>
#include <iostream.h>
#include <iomanip.h>
#define MAX_CHAR 50
#define MAX_WORD 3



//definizione delle funzioni di servizio


void set_diz(Diz &dizionario)
	{
      Diz :: attributo pz;
      Diz :: tipochiave s;
      Diz :: tipoelem bucket;

   	dizionario.crea();
      cout<<"\n\n Inserire la serie di articoli desiderata,"
      	 <<"\n (immettendo codici esclusivamente numerici).\n";

      for(int i=0;i<MAX_WORD;i++)
      	{
            cout<<"\n Codice Articolo"<<(i+1)<<" : ";
				cin>>s;
            bucket.key=s;
            cout<<" Quanti pezzi?: ";
            cin>>pz;
            bucket.pezzi=pz;
            dizionario.inserisci(bucket);
         }

   }


void interroga(Diz tab)
	{
      Diz :: attributo n_pezzi;
      Diz :: tipochiave key;

		cout<<"\n\n Inserire il key dell'articolo desiderato: ";
      cin>>key;

      n_pezzi=tab.recupera(key).pezzi;
      if(n_pezzi==0)
      	cout<<"\n Articolo esaurito.";
      else
      	if(n_pezzi>0)
      		cout<<"\n Quantita' disponibile: "<<n_pezzi<<" pz.";
    }


void aggiornamento(Diz &tab)
	{
      Diz :: attributo n_pezzi;
      Diz :: tipochiave key;

		cout<<"\n\n Inserire il key dell'articolo desiderato: ";
      cin>>key;
		cout<<"\n Inserire la quantità di pezzi aggiornata: ";
      cin>>n_pezzi;

		tab.aggiorna(key,n_pezzi);

      int p=tab.recupera(key).pezzi;
      if(p>=0)
      	cout<<"\n\n Verifica aggiornamento, Articolo: ["<<key<<"],"
		  	 	 <<" pz: "<<p;
	}

void cancellazione(Diz &tab)
	{
      Diz :: tipochiave key;
      Diz :: boolean conferma;

		cout<<"\n\n Inserire il key dell'articolo da rimuovere: ";
      cin>>key;

		cout<<"\n\n Sei sicuro di voler cancellare l'Articolo ["<<key<<"]?";
		cout<<"\n Per confermare digita 1: ";
		cout<<"\n Per rinunciare digita 0: ";
      cin>>conferma;

      if(conferma)
      	{
				tab.cancella(key);
            cout<<"\n\n Articolo cancellato";
         }
      else
      	cout<<"\n\n L'Articolo non è stato cancellato";
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