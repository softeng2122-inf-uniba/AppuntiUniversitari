#include <iostream>

using namespace std;

int main()
{
    Insieme l;
    int scelta;
    do{
        do{
            cout<<"1. Per creare la rete\n";
            cout<<"2. Per aggiungere utente\n";
            cout<<"3. Connetti due utenti\n";
            cout<<"4. Sconnetti due utenti\n";
            cout<<"5. Aggiungi messaggio\n";
            cout<<"6. Verifica connessione\n";
            cout<<"7. Numero totale amici\n";
            cout<<"8. Numero totale messaggi\n";
            cout<<"9. Uscire\n";
            cin>>scelta;
        }while(scelta!=1 ||scelta!=2 ||scelta!=3 ||scelta!=4 ||scelta!=5 ||scelta!=6 ||scelta!=7 ||scelta!=8 || scelta!=9);
        switch(scelta){
            case 1:
               l.inserimento;
            case 2:
                l.aggiungiUtente();
                break;
            case 3:
                l.connetti();
                break;
            case 4:
                l.sconnetti();
                break;
            case 5:
                l.posta();
                break;
            case 6:
                l.connessi();
                break;
            case 7:
                l.numAmici();
                break;
            case 8:
                l.numMessaggi();
                break;
        }
    }while(scelta<9);
    return 0;
}
