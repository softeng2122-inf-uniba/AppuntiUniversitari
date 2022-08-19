#ifndef MAIN_H
#include "main.h"
#endif

#ifndef CODAVET_H
#include "CodaVet.h"
#endif

void inserisci(CodaVet<int> &c) {
     cout << endl;
     cout << "*** Inserimento della coda ***" << endl << endl;
     int i=0;
     int el;
     char risp='y';
     while ((risp=='y')||(risp=='Y')) {
        i++;
        cout << "Inserisci elemento: ";
        cin >> el;
        c.inCoda(el);
        do {
           cout << "Altro elemento? (y/n) ";
           cin >> risp;
        } while (!((risp=='y')||(risp=='Y')||(risp=='n')||(risp=='N')));
     }
     cout << "Inserimento della coda eseguito senza problemi!" << endl;
     cout << "Hai inserito " << i << " elementi!" << endl;
     cout << endl;
};

void stampa(CodaVet<int> &c) {
     cout << endl;
     cout << "*** Stampa della coda ***" << endl << endl;
     CodaVet<int> appoggio;
     if (c.codaVuota()) {
        cout << "Spiacente, la coda da stampare e' vuota!" << endl;
        return;
     } else {
        while (!c.codaVuota()) {
           cout << c.leggiCoda() << " ";
           appoggio.inCoda(c.leggiCoda());
           c.fuoriCoda();
        }
        while (!appoggio.codaVuota()) {
           c.inCoda(appoggio.leggiCoda());
           appoggio.fuoriCoda();
        }
     }
     cout << endl;
     cout << "Stampa eseguita senza problemi!" << endl;
     cout << endl;
};

int main() {
     CodaVet<int> cod;
     inserisci(cod);
     stampa(cod);
     system("pause");
     return 0;
};

