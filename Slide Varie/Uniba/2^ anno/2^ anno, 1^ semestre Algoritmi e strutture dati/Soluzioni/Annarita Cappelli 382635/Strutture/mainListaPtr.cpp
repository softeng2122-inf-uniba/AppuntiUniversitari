#ifndef MAIN_H
#include "main.h"
#endif

#ifndef LISTAPTR_H
#include "ListaPtr.h"
#endif

typedef lpcell<string> *posizione;

void acquisizione(ListaPtr<string> &l) {
     cout << endl;
     cout << "*** Acquisizione della lista ***" << endl << endl;
     int i=0;
     string elemento;
     char risp='y';
     posizione p=l.primoLista();
     while ((risp=='y')||(risp=='Y')) {
        i++;
        cout << "Inserisci elemento: ";
        cin >> elemento;
        l.insLista(elemento, p);
        p=l.succLista(p);
        do {
           cout << "Altri elementi? (y/n) ";
           cin >> risp;
        } while (!((risp=='y')||(risp=='Y')||(risp=='n')||(risp=='N')));
     }
     cout << "Lista acuisita con successo!" << endl;
     cout << "Hai inserito " << i << " elementi!" << endl;
     cout << endl;
};

void stampa(ListaPtr<string> l) {
     cout << endl;
     cout << "*** Stampa della lista ***" << endl << endl;
     if (l.listaVuota()) {
        cout << "Spiacente, ma la lista da stampare e' vuota!" << endl;
        return;
     } else {
        posizione p=l.primoLista();
        while (!l.fineLista(p)) {
           cout << l.leggiLista(p) << " ";
           p=l.succLista(p);
        }
        cout << endl;
        cout << "Lista stampata con successo!" << endl;
        cout << endl;
     }
};

int main() {
     ListaPtr<string> lis;
     acquisizione(lis);
     stampa(lis);
     system("pause");
     return 0;
}
