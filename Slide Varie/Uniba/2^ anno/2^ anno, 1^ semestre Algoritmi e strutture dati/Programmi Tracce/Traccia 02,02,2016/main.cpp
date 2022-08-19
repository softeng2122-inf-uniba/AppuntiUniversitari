#include <iostream>
#include"MatriceLista.h"

using namespace std;

int main()
{
    Lista a,b,s,t;
    int elem,r,c;
    int scelta;
    do{
        do{
            cout<<"1.Inserire prima matrice\n";
            cout<<"2.Inserire seconda matrice\n";
            cout<<"3.Visualizzare matrice\n";
            cout<<"4.Somma di matrici\n";
            cout<<"5.Trasposta di matrici\n";
            cout<<"6.Aggiungi valore\n";
            cout<<"7.Leggi valore\n";
            cout<<"8.Rimuovi elemento\n";
            cout<<"9.Uscire\n";
            cin>>scelta;
        }while(scelta>9);
        switch(scelta){
            case 1:
                a.inserisci();
                break;
            case 2:
                b.inserisci();
                break;
            case 3:
                cout<<"\nQuale matrice si vuole fare visualizzare?\n";
                cin>>scelta;
                if(scelta==1)
                    a.visualizza();
                else
                    b.visualizza();
                break;
            case 4:
                s=a.somma(b);
                cout<<"\n La matrice somma e':\n";
                s.visualizza();
                break;
            case 5:
                cout<<"\nQuale matrice si vuole fare la trasposta?\n";
                cin>>scelta;
                if(scelta == 1)
                    t=a.trapsosta();
                else
                    t=b.trapsosta();
                break;
            case 6:
                cout<<"\n A quale matrice si vuole aggiungere un valore?\n";
                cin>>scelta;
                if(scelta==1)
                    a.inserisci();
                else
                    b.inserisci();
                break;
            case 7:
                cout<<"\n Di quale matrice si vuole leggere l'elemento?\n";
                cin>>scelta;
                cout<<"\n Di quale riga si vuole leggere l'elemento?\n";
                cin>>r;
                cout<<"\n Di quale colonna si vuole leggere l'elemento?\n";
                cin>>c;
                if(scelta==1)
                    elem=a.leggi(r,c);
                else
                    elem=b.leggi(r,c);
                cout<<"\n\n L'elemento è: "<<elem;
                break;
            case 8:
                cout<<"\n Da quale matrice si vuole rimuovere l'elemento?";
                cin>>scelta;
                cout<<"\n Inserire la riga dell'elemento che si vuole cancellare\n";
                cin>>r;
                cout<<"\n Inserire la colonna dell'elemento che si vuole cancellare\n";
                cin>>c;
                if(scelta==1)
                    a.rimuovi(r,c);
                else
                    b.rimuovi(r,c);
                break;
        }
    }while(scelta!=9);
    return 0;
}
