#ifndef MAIN_H
#include "main.h"
#endif

#ifndef LISTACUR_H
#include "ListaCur.h"
#endif

void menu() {
     cout << endl;
     cout << "********** MENU' **********" << endl << endl;
     cout << "1. Acquisizione di una lista" << endl;
     cout << "2. Stampa della lista" << endl;
     cout << "3. Fine" << endl;
     cout << endl;
};

void acquisizione(ListaCur<int> &l) {
     int i = 0;
     int elemento;
     char risp = 'y';
     posizione p=l.primoLista();
     while ((risp == 'y') || (risp == 'Y')) {
        i++;
        cout << "Inserisci elemento: ";
        cin >> elemento;
        l.insLista(elemento, p);
        do{
           cout << "Altri elementi? (y/n) ";
           cin >> risp;
        } while (!((risp == 'Y') || (risp == 'y') || (risp == 'N') || (risp == 'n')));
     }
     cout << "Hai inserito " << i << " elementi" << endl;    
};

void stampa(ListaCur<int> l) {
     cout << endl;
     cout << "*** Stampa della lista ***" << endl << endl;
     if (!l.listaVuota()) {
        posizione p = l.primoLista();
        while (!l.fineLista(p)) {
           cout << l.leggiLista(p)<< " ";
           p = l.succLista(p);
        }
        cout << endl;
     } else cout << "La lista da stampare e' vuota" << endl;
     cout << endl;
};

int main() {
     ListaCur<int> lis;
     int scelta;
     do {
        menu();
        do {
           cout << "Scelta: ";
           cin >> scelta;
        } while (!((scelta>0)&&(scelta<4)));
        cout << endl;
        switch (scelta) {
           case 1:
                acquisizione(lis);
                break;
           case 2:
                stampa(lis);
                break;
           case 3:
                cout << "Ciao ciao!!!!" << endl;
                break;
        }
        system("pause");
        system("cls");
     } while (scelta!=3);
     return 0;
}
        
        
     
        
     
     
     
