/*GIUSEPPE LACRIOLA 425621
 *STRUTTURA DATI INSIEME
 *IMPLEMENTAZIONE CON PUNTATORI*/
#include <iostream.h>
#include "Insieme.h"
#include "Nodoptr.h"
#include <stdlib>

int main()
{	Insieme x, y;
	tipoelem e;
   int risp;

   cout<<"\n\n\tSTRUTTURA DATI INSIEME\n\n";
   do{
   	cout<<"\n\t1. Inserire l'insieme A";
      cout<<"\n\t2. Inserire l'insieme B";
      cout<<"\n\t3. Inserire elemento in...";
      cout<<"\n\t4. Cancellare elemento da...";
      cout<<"\n\t5. Stampa gli insiemi A e B";
      cout<<"\n\t6. Unione";
      cout<<"\n\t7. Intersezione";
      cout<<"\n\t8. Differenza";
      cout<<"\n\tAltro int x Uscire\n\t";
      cin>>risp;

      switch(risp){
      	case 1:{x.inserimento(); break;}
         case 2:{y.inserimento(); break;}
         case 3:{cout<<"\n  In A(1) o B(2)...";
                 cin>>risp;
                 if (risp==1)
                 		{cout<<"\n  Inserisci l'elemento...";
                      cin>>e;
                 		 x.inserisci(e);}
                 else if(risp==2)
                 		{cout<<"\n  Inserisci l'elemento...";
                      cin>>e;
                 		 y.inserisci(e);}
                 break;}
         case 4: {cout<<"\n  Da A(1) o B(2)...";
                 cin>>risp;
                 if (risp==1)
                 		{x.stampa();
                      cout<<"\n  Inserisci l'elemento da cancellare...";
                      cin>>e;
                 		 x.cancella(e);}
                 else if(risp==2)
                 		{y.stampa();
                      cout<<"\n  Inserisci l'elemento da cancellare...";
                      cin>>e;
                 		 y.inserisci(e);}
                 break;}
         case 5:{cout<<"\n  Insieme A...\n  ";
         		  x.stampa();
                 cout<<"\n  Insieme B...\n  ";
         		  y.stampa();
                 break; }
         case 6:{cout<<"\n\t A unione B\n\t";
         		  x.unione(y);
                 cout<<"\n\t B unione A\n\t";
                 y.unione(x);
                 break;}
         case 7:{cout<<"\n\t A intersezione B\n\t";
         		  x.intersezione(y);
                 cout<<"\n\t B intersezione A\n\t";
                 y.intersezione(x);
                 break;}
         case 8:{cout<<"\n\t A meno B\n\t";
         		  x.differenza(y);
                 cout<<"\n\t B meno A\n\t";
                 y.differenza(x);
                 break;}}//end-switch
   }while(risp<=8);
   cout<<"\n\n";
   system("PAUSE");
};

