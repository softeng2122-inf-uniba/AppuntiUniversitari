#ifndef MAIN_H
#include "main.h"
#endif

#ifndef CODAPTR_H
#include "CodaPtr.h"
#endif

void inserimento(CodaPtr<string> &c) {
     int i=0;
     char risp='y';
     string val;
     cout << endl;
     cout << "*** Inserimento della coda ***" << endl << endl;
     while ((risp=='y')||(risp=='Y')) {
        i++;
        cout << "Inserisci elemento: ";
        cin >> val;
        c.inCoda(val);
        do {
           cout << "Altro elemento? (y/n) ";
           cin >> risp;
        } while (!((risp=='y')||(risp=='Y')||(risp=='n')||(risp=='N')));
     }
     cout << "Inserimento eseguito senza problemi!" << endl;
     cout << "Hai inserito " << i << " elementi!" << endl;
     cout << endl;
};

void stampa(CodaPtr<string> &c) {
     CodaPtr<string> appoggio;
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
     cout << "Stampa eseguita con successo!" << endl;
     cout << endl;
};

int main() {
     CodaPtr<string> cod;
     inserimento(cod);
     stampa(cod);
     system("pause");
     return 0;
};


        
