/*Giuseppe Lacriola matr. 425621
 *Struttura dati CODA
 *implementazione con strutture dinamiche a puntatori*/

#include <iostream.h>
#include <stdlib.h>
#include "Nodo.h"
#include "Coda.h"

int main()
{	Coda q;
	tipoelem e;
   int sel;
   char risp;
   cout<<"\n\t STRUTTURA DATI CODA...\n\n";
   do{
   	cout<<"\n\n  1. Inserisci elementi \n";
   	cout<<"  2. Estrai elementi \n";
   	cout<<"  3. Stampa la coda\n";
   	cout<<"  Any to ESC\n\n\t";
      cin>>sel;

      switch(sel){case 1: {
      				 do{
               	 	cout<<"\n  Inserisci l'elemento...\n\t";
                  	cin>>e;
                  	q.incoda(e);
                  	cout<<"\n\n  Ancora? (s/n)...";
                  	cin>>risp;
                   }while(risp=='s');
                   break;
         		  }//end-case1
         			case 2:{
            			do{
            	 			if(q.codavuota())
                				{cout<<"\n Coda vuota!\n";
                            break;}
                  		else
                        {e=q.leggicoda();
                       	 q.fuoricoda();
                         cout<<"  POP --> "<<e;
                         cout<<"\n  Ancora una POP? (s/n)...";
                         cin>>risp;
                         if(risp=='n') break;}
                      }while(q.codavuota()==false || risp=='s');
                      break;
                    }//end-case2
         case 3:{q.stampa(); break;}
         }

   }while(sel==1 || sel==2 || sel==3);

   system("PAUSE");
    return 0;
}


