/*GIUSEPPE LACRIOLA 425621
 *STRUTTURA DATI PILA
 *IMPLEMENTAZIONE CON STRUTTURA DINAMICA
 *A PUNTATORI*/
#include <iostream.h>
#include <stdlib.h>
#include "Nodo.h"
#include "Pila.h"

int main()
{	Pila p;
	tipoelem e;
   int sel;
   char risp;
   cout<<"\n\t STRUTTURA DATI PILA...\n\n";
   do{
   	cout<<"  1. Inserisci elementi -- push\n";
   	cout<<"  2. Estrai elementi -- pop\n";
   	cout<<"  3. Stampa la pila\n";
   	cout<<"  Any to ESC\n\n\t";
      cin>>sel;

      switch(sel){case 1: {
      				 do{
               	 	cout<<"\n  Inserisci l'elemento...\n\t";
                  	cin>>e;
                  	p.inpila(e);
                  	cout<<"\n\n  Ancora? (s/n)...";
                  	cin>>risp;
                   }while(risp=='s');
                   break;
         		  }//end-case1
         			case 2:{
            			do{
            	 			if(p.pilavuota())
                				{cout<<"\n Pila vuota!\n";
                            break;}
                  		else
                        {e=p.leggipila();
                       	 p.fuoripila();
                         cout<<"  POP --> "<<e;
                         cout<<"\n  Ancora una POP? (s/n)...";
                         cin>>risp;}
                      }while(p.pilavuota()==false || risp=='s');
                      break;
                    }//end-case2
         case 3:{p.stampa(); break;}
         }

   }while(sel==1 || sel==2 || sel==3);



   system("PAUSE");

   return 0;
}


