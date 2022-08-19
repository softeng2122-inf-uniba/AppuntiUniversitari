/*
In un negozio di abbigliamento c'è uno scaffale con delle 
magliette una sull'altra, ciascuna avente un colore, una taglia e 
un prezzo.
Implementare le seguenti funzioni/metodi:
1. Aggiunta di ulteriori magliette alla catasta;
2. Stampa della situazione della catasta di magliette (colore, 
prezzo e taglia di ciascuna);
3. Dati un colore e una taglia, rimozione di una maglietta dalla 
catasta con le caratteristiche date;
4. Ricerca di una maglietta nella catasta, dato il colore e la 
taglia;
5. Dato un colore, stampare le taglie disponibili per quel 
colore, senza ripetizioni.
*/

#ifndef MAIN_H
#include "main.h"
#endif

#ifndef PILAPTR_H
#include "PilaPtr.h"
#endif

struct maglietta {
     string colore;
     string taglia;
     double prezzo;
};

void inserimento(PilaPtr<maglietta> &p) {
     int i=0;
     char risp='y';
     maglietta val;
     cout << endl;
     cout << "*** Inserimento della catasta di magliette ***" << endl << endl;
     while ((risp=='y')||(risp=='Y')) {
        i++;
        cout << "Inserisci colore maglietta: ";
        cin >> val.colore;
        cout << "Inserisci taglia maglietta: ";
        cin >> val.taglia;
        cout << "Inserisci prezzo maglietta: ";
        cin >> val.prezzo;
        p.inPila(val);
        do {
           cout << "Altro elemento? (y/n) ";
           cin >> risp;
        } while (!((risp=='y')||(risp=='Y')||(risp=='n')||(risp=='N')));
     }
     cout << "Inserimento eseguito senza problemi!" << endl;
     cout << "Hai inserito " << i << " magliette!" << endl;
     cout << endl;
     system("pause");
     system("cls");
};

void copiaPila(PilaPtr<maglietta> &p, PilaPtr<maglietta> &q) {
     PilaPtr<maglietta> appoggio;
     maglietta el;
     if (p.pilaVuota()) {
        cout << "La pila da copiare e' vuota!" << endl;
        return;
     } else {
        while (!p.pilaVuota()) {
           el=p.leggiPila();
           q.inPila(el);
           appoggio.inPila(el);
           p.fuoriPila();
        }
        while (!appoggio.pilaVuota()) {
           el=appoggio.leggiPila();
           p.inPila(el);
           appoggio.fuoriPila();
        }
     }
};

void stampa(PilaPtr<maglietta> &p) {
     PilaPtr<maglietta> appoggio;
     maglietta el;
     cout << "*** Stampa della catasta di magliette ***" << endl << endl;
     if (p.pilaVuota()) {
        cout << "Non c'e' nessuna catasta di magliette da stampare!" << endl;
        return;
     } else {
        copiaPila(p, appoggio);
        while (!appoggio.pilaVuota()) {
           el=appoggio.leggiPila();
           cout << "Colore maglietta: " << el.colore << "  taglia: " << el.taglia 
                << "  prezzo: " << el.prezzo << endl;
           appoggio.fuoriPila();
        }
        cout << endl;
        system("pause");
        system("cls");
     }
};

void rimozione(PilaPtr<maglietta> &p) {
     PilaPtr<maglietta> appoggio;
     string col, taglia;
     maglietta el;
     cout << "*** Rimozione di una maglietta dati colore e taglia ***" << endl << endl;
     if (p.pilaVuota()) {
        cout << "Spiacente, la catasta di magliette e' vuota!" << endl;
        return;
     } else {
        cout << "Inserisci il colore della maglietta da rimuovere: ";
        cin >> col;
        cout << "Inserisci la taglia della maglietta da rimuovere: ";
        cin >> taglia;
        while (!p.pilaVuota()) {
           el=p.leggiPila();
           if ((el.colore!=col)||(el.taglia!=taglia)) 
              appoggio.inPila(el);
           p.fuoriPila();
        }
        copiaPila(appoggio, p);
        cout << endl;
        stampa(p);
     }
};

void ricerca(PilaPtr<maglietta> &p) {
     PilaPtr<maglietta> appoggio;
     string col, taglia;
     maglietta el;
     bool trovata=false;
     int i=1;
     cout << "*** Ricerca di una maglietta dati colore e taglia ***" << endl << endl;
     if (p.pilaVuota()) {
        cout << "Spiacente, la catasta di magliette e' vuota!" << endl;
        return;
     } else {
        copiaPila(p, appoggio);
        cout << "Inserisci il colore della maglietta da cercare: ";
        cin >> col;
        cout << "Inserisci la taglia della maglietta da cercare: ";
        cin >> taglia;
        while (!(appoggio.pilaVuota()||trovata)) {
           el=appoggio.leggiPila();
           if ((el.colore==col)&&(el.taglia==taglia)) {
              trovata=true;
              cout << "Maglietta trovata in posizione " << i << endl;
           } else { 
              i++;
              appoggio.fuoriPila();
           }
        }
        if (trovata==false)
           cout << "Maglietta assente!" << endl;
        system("pause");
        system("cls");
     }
};

void ricercaTaglie(PilaPtr<maglietta> &p) {
     PilaPtr<maglietta> appoggio;
     string col;
     maglietta el;
     cout << "*** Disponibilita' taglie di una maglietta dato il colore ***" << endl << endl;
     if (p.pilaVuota()) {
        cout << "Spiacente, la catasta di magliette e' vuota!" << endl;
        return;
     } else {
        copiaPila(p, appoggio);
        cout << "Inserisci il colore della maglietta da cercare: ";
        cin >> col;
        while (!appoggio.pilaVuota()) {
           el=appoggio.leggiPila();
           if (el.colore==col) {
              cout << "Taglia disponibile: " << el.taglia << endl;
           }
           appoggio.fuoriPila();
        }
        cout << endl;
     }

};
              
int main() {
     PilaPtr<maglietta> pil;
     cout << "***** NEGOZIO DI MAGLIETTE *****" << endl << endl;
     inserimento(pil);
     stampa(pil);
     rimozione(pil);
     ricerca(pil);
     ricercaTaglie(pil);
     cout << "Grazie per essere passati in questo negozio, a presto!!!" << endl;
     cout << endl;
     system("pause");
     return 0;
} 
     
