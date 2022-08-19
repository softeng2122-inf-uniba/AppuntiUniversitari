#include <iostream>
#include <stdlib.h>
#include "Nodo.h"
#include "Coda.h"

using namespace std;

int main()
{
    Coda q;
	tipoelem e;
    int scelta;
    int risp;
    cout<<"\n\t STRUTTURA DATI CODA...\n\n";
    do{
   	cout<<"\n\n  1. Inserisci elementi \n";
   	cout<<"  2. Estrai elementi \n";
   	cout<<"  3. Stampa la coda\n";
   	cout<<"  4. Per uscire\n\n";
    cin>>scelta;

    switch(scelta)
    {
        case 1:
                do{
                        cout<<" Inserisci l'elemento...\n";
                        cin>>e;
                        q.incoda(e);
                        cout<<"\n  Ancora? (1/0)...";
                        cin>>risp;
                   }while(risp==1);
        break;

        case 2:
                do{
                        if(q.codavuota())
                                cout<<"\n Coda vuota!\n";
                  		else
                            {
                                e=q.leggicoda();
                                q.fuoricoda();
                                cout<<"  POP --> "<<e;
                                cout<<"\n  Ancora una POP? (1/0)...";
                                cin>>risp;
                            }
                }while(risp==1);
        break;

         case 3:
                q.stampa();
                break;

   }
   }while(scelta==1 || scelta==2 || scelta==3);

    system("PAUSE");
    return 0;
}


