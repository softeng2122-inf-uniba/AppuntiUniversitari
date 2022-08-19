#ifndef MAIN_H
#include "main.h"
#endif

#ifndef PILAVET_H
#include "PilaVet.h"
#endif

void inserisci(PilaVet<int> &p) {
     cout << endl;
     cout << "*** Inserimento della pila ***" << endl << endl;
     int i=0;
     int el;
     char risp='y';
     while ((risp=='y')||(risp=='Y')) {
        i++;
        cout << "Inserisci elemento: ";
        cin >> el;
        p.inPila(el);
        do {
           cout << "Altro elemento? (y/n) ";
           cin >> risp;
        } while (!((risp=='y')||(risp=='Y')||(risp=='n')||(risp=='N')));
     }
     cout << "Inserimento della pila eseguito senza problemi!" << endl;
     cout << "Hai inserito " << i << " elementi!" << endl;
     cout << endl;
};

void stampa(PilaVet<int> &p) {
     cout << endl;
     cout << "*** Stampa della pila ***" << endl << endl;
     PilaVet<int> appoggio;
     if (p.pilaVuota()) {
        cout << "Spiacente, la pila da stampare e' vuota!" << endl;
        return;
     } else {
        while (!p.pilaVuota()) {
           cout << p.leggiPila() << " ";
           appoggio.inPila(p.leggiPila());
           p.fuoriPila();
        }
        while (!appoggio.pilaVuota()) {
           p.inPila(appoggio.leggiPila());
           appoggio.fuoriPila();
        }
     }
     cout << endl;
     cout << "Stampa eseguita senza problemi!" << endl;
     cout << endl;
};

int main() {
     PilaVet<int> pil;
     inserisci(pil);
     stampa(pil);
     system("pause");
     return 0;
};

