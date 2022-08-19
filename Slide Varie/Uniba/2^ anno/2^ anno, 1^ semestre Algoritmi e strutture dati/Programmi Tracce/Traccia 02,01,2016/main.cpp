#include <iostream>

using namespace std;

int main()
{
    Utentelista l;
    int scelta;
    string nome, cognome,prodotto,nome2;
    int gradimento;
    float media;
    do{
        do{
            cout<<"\n1.Caricare lista\n";
            cout<<"\n2.Visualizzare lista\n";
            cout<<"\n3.Registrare utente\n";
            cout<<"\n4.Aggiungere gradimento\n";
            cout<<"\n5.Numero di gradimenti di un prodotto\n";
            cout<<"\n6.Media gradimenti di un prodotto\n";
            cout<<"\n7.Prodotti con gradimenti simili\n";
            cout<<"\n8.Uscire\n";
            cin>>scelta;
        }while(scelta<=8)
        switch(scelta){
            case 1:
                l.inserimento();
                break;
            case 2:
                l.visualizza();
                break;
            case 3:
                cout<<"\n Inserisci nome utente\n";
                cin>>nome;
                cout<<"\n Inserisci cognome utente\n";
                cin>>cognome;
                l.resgistraUtente(0,nome,cognome);
                break;
            case 4:
                cout<<"\n Inserisci nome utente\n";
                cin>>nome;
                cout<<"\n Inserisci cognome utente\n";
                cin>>cognome;
                cout<<"\n Inserisci nome prodotto\n";
                cin>>prodotto;
                cout<<"\n Inserisci gradimento\n";
                cin>>gradimento;
                l.inserisci(0,nome,cognome,prodotto,gradimento);
                break;
            case 5:
                cout<<"\n Inserisci nome prodotto\n";
                cin>>prodotto;
                gradimento=l.gradimento(prodotto);
                cout<<"Gradimento:  "<<gradimento;
                break;
            case 6:
                cout<<"\n Inserisci nome prodotto\n";
                cin>>prodotto;
                media=l.mediaGradimenti(prodotto);
                cout<<"\n Media: "<<media;
                break;
            case 7:
                cout<<"\n Inserisci il primo nome utente\n";
                cin>>nome;
                cout<<"\n Inserisci il secondo nome utente\n";
                cin>>nome2;
                gradimento=l.gradimentiSimili(nome1,nome2);
                cout<<"\n numero gradimenti: "<<gradimento;

        }
    }while(scelta!=8)
    return 0;
}
