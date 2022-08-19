#include <iostream>
#include <stdlib.h>
#include "./Nodo.h"
#include "./Pila.h"

using namespace std;

int main()
{
    Pila p;
	tipoelem e;
    int scelta;
    int risp;
    cout<<"\n\t STRUTTURA DATI PILA...\n\n";
    do{
   	cout<<"  1. Inserisci elementi -- push\n";
   	cout<<"  2. Estrai elementi -- pop\n";
   	cout<<"  3. Stampa la pila\n";
   	cout<<"  0. Per uscire\n";
    cin>>scelta;

    switch(scelta){
        case 1:

                do{
                    cout<<"Inserisci l'elemento: ";
                  	cin>>e;
                  	p.inpila(e);
                  	cout<<"Ancora? (1/0)\n";
                  	cin>>risp;
                }while(risp==1);
        break;

        case 2:
            do{
                if(p.pilavuota())
                    {
                        cout<<"\n Pila vuota!\n";
                        break;
                    }
                else
                    {
                        e=p.leggipila();
                        p.fuoripila();
                        cout<<"  POP --> "<<e;
                        cout<<"\n  Ancora una POP? (1/0)...";
                        cin>>risp;}
                      }while( risp==1);
        break;

         case 3:
             p.stampa();
             break;
    }

}while(scelta==2||scelta==1||scelta==3);

   system("PAUSE");

   return 0;
}
