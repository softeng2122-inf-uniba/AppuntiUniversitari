#ifndef MAIN_H
#include "main.h"
#endif

#ifndef PILAPTR_H
#include "PilaPtr.h"
#endif

void inserimento(PilaPtr<string> &p) {
     int i=0;
     char risp='y';
     string val;
     cout << endl;
     cout << "*** Inserimento della pila ***" << endl << endl;
     while ((risp=='y')||(risp=='Y')) {
        i++;
        cout << "Inserisci elemento: ";
        cin >> val;
        p.inPila(val);
        do {
           cout << "Altro elemento? (y/n) ";
           cin >> risp;
        } while (!((risp=='y')||(risp=='Y')||(risp=='n')||(risp=='N')));
     }
     cout << "Inserimento eseguito senza problemi!" << endl;
     cout << "Hai inserito " << i << " elementi!" << endl;
     cout << endl;
};

void stampa(PilaPtr<string> &p) {
     PilaPtr<string> appoggio;
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
     cout << "Stampa eseguita con successo!" << endl;
     cout << endl;
};

int main() {
     PilaPtr<string> pil;
     inserimento(pil);
     stampa(pil);
     system("pause");
     return 0;
};


        
