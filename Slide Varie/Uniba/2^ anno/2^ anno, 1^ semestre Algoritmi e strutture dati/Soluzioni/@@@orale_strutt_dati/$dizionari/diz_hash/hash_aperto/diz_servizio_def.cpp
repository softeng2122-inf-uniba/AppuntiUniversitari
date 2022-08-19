#include <stdlib.h>
#include <iostream.h>
#include <iomanip.h>
#define MAX_CHAR 50
#define MAX_WORD 5



//definizione delle funzioni di servizio


void set_diz(Diz &dizionario)
	{
      Bucket :: attributo pz;
      Bucket :: tipochiave s;
      Diz :: tipoelem bucket;
      dizionario.crea();

      cout<<"\n\n Inserire la serie di articoli desiderata,"
      	 <<"\n ATTENZIONE: immettere codici esclusivamente numerici.\n";

      for(int i=0;i<MAX_WORD;i++)
      	{
            cout<<"\n Codice Articolo "<<(i+1)<<" : ";
				cin>>s;
            bucket.key=s;
            cout<<" Quanti pezzi?: ";
            cin>>pz;
            bucket.pezzi=pz;
            dizionario.inserisci(bucket);
         }

   }


void interroga(Diz &tab)
	{
      Bucket :: attributo n_pezzi;
      Bucket :: tipochiave key;

		cout<<"\n\n Inserire il codice dell'articolo desiderato: ";
      cin>>key;

      n_pezzi=tab.recupera(key).pezzi;
      if(n_pezzi==0)
      	cout<<"\n Articolo esaurito.";
      else
      	if(n_pezzi>0)
      		cout<<"\n Quantita' disponibile: "<<n_pezzi<<" pz.";
         else
	      	cout<<"\n Articolo inesistente.";
    }


void aggiornamento(Diz &tab)
	{
      Bucket :: attributo n_pezzi;
      Bucket :: tipochiave key;

		cout<<"\n\n Inserire il key dell'articolo desiderato: ";
      cin>>key;
		cout<<"\n Inserire la quantita' di pezzi aggiornata: ";
      cin>>n_pezzi;

		tab.aggiorna(key,n_pezzi);

      int p=tab.recupera(key).pezzi;
      if(p>=0)
      	cout<<"\n\n Verifica aggiornamento, Articolo: ["<<key<<"],"
		  	 	 <<" pz: "<<p;
      else
			cout<<"\n Articolo inesistente: ";
	}

void cancellazione(Diz &tab)
	{
      Bucket :: tipochiave key;
      Diz :: boolean conferma;

		cout<<"\n\n Inserire il codice dell'articolo da rimuovere: ";
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