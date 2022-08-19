/* Giuseppe Lacriola matr. 425621
 * STRUTTURA DATI LISTA
 * IMPLEMENTAZIONE CON STRUTTURE DINAMICHE
 * CON SENTINELLA E A DOPPIO PUNTATORE*/

#include "lista.h"
#include "nodoptr.h"
#include <iostream>
#include <stdlib>

int main(){
Lista l;
posizione temp;
tipoelem e,mod;
int risp;
char r;
	temp=0;
  do{
   cout<<"\n\n\t::: STRUTTURA DATI LISTA :::\n\n";
   cout<<"\t 1. Inserimento di elementi\n";
   cout<<"\t 2. Modifica di elementi\n";
   cout<<"\t 3. Cancellazione di elementi\n";
   cout<<"\t 4. Stampa della lista\n";
   cout<<"\t Any to ESC\n";
   cin>>risp;

   switch(risp){
   case 1:
   	{do{cout<<" Inserisci l'elemento...";
      	 cin>>e;
          l.inserisci(0, e);
          cout<<" ancora? (s-n)...";
          cin>>r;
         }while(r=='s');
         break;
       };
   case 2:
   	{l.stampa();
       cout<<"\n\tQuale elemento vuoi modificare?...";
       cin>>mod;
       cout<<"\n\tQuale sarà il nuovo elemento?...";
       cin>>e;
       temp=l.cerca(mod);
       if (temp!=0)
       	{l.scrivi(temp, e);}
         else cout<<"\n  L'elemento da sostituire non esiste!";
         break;
       };
   case 3:
   	{l.stampa();
       cout<<"\n\tQuale elemento vuoi cancellare?...";
       cin>>mod;
       temp=l.cerca(mod);
       if (temp!=0)
       	{l.cancella(temp);}
         else cout<<"\n  L'elemento da cancellare non esiste!";
         break;
      };
   case 4:{l.stampa();break;}
   };
   }while(risp==1 || risp==2 || risp==3 || risp==4);
 system("PAUSE");


return 0;
}