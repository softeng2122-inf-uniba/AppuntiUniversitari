#include <iostream>
#include "Nodo.h"
#include "Listapolinomi.h"

using namespace std;



int main()
{
    Lista s,l,m,p;
    tipoelem coefficiente,esponente;

    int scelta=0;
    do{
        cout<<"\n\t 1. Inserire prima polinomi \n";
        cout<<"\n\t 2. Inserire seconda polinomi \n";
        cout<<"\t 3. Visualizza polinomi\n";
        cout<<"\t 4. Setta esponente\n";
        cout<<"\t 5. Somma di due polinomi\n";
        cout<<"\t 6. Prodotto di due polinomi\n";
        cout<<"\t 7. Esponente più grande\n";
        cout<<"\t 8. Per uscire\n";
        cin>>scelta;
        switch(scelta)
        {
            case 1:
                l.inserisci();
                break;
            case 2:
                m.inserisci();
                break;
            case 3:
                cout<<"\n Quale lista vuoi visualizzare? (1/2)";
                cin>>scelta;
                if(scelta==1)
                    l.stampa();
                else
                    m.stampa();
            case 4:
                cout<<"\n Inserisci il nuovo coefficiente:  ";
                cin>>coefficiente;
                cout<<"\n Inserisci l'esponente che si vuole modificare:  ";
                cin>> esponente;
                l.settaEsponente(coefficiente,esponente);
                break;
            case 5:

                s=l.somma(m);
                cout<<"\n Stampa somma\n";
                s.stampa();
                break;
            case 6:
                p=l.prodotto(m);
                p.stampa();
                break;
            case 7:
                esponente=l.grado();
                cout<<"\nIl grado massimo e': "<<esponente;
                break;
        }
    }while(scelta<8);
    return 0;
}


