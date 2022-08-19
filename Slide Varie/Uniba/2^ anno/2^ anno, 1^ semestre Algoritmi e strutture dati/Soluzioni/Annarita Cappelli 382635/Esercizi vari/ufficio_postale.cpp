/*
In un ufficio postale c'è una fila di persone, ognuna avente un 
nome e un numero di sequenza ritirato all'ingresso per la fila. 
Ogni persona deve fare un numero (non noto a priori) di 
versamenti in conto corrente. 
Ciascun versamento è caratterizzato da numero di conto, 
nome dell'intestatario del bollettino e importo. Rappresentare 
questo scenario mediante l'implementazione 
(SENZA usare la rappresentazione a puntatori) delle opportune 
strutture dati che rappresentano la fila di persone e, per 
ciascuna, il gruppo di bollettini. 

   Implementare le seguenti funzioni/metodi: 
   1. Acquisizione da tastiera o da funzione/metodo delle persone;
   2. Aquisizione da tastiera o da funzione/metodo dei bollettini 
      in possesso di ogni persona;
   3. Stampa dell'elenco di persone con i dati relativi ai 
      bollettini;
   4. Stampa dell'elenco di persone con l'importo totale 
      versato, comprendendo la 
      tassa di 1 Euro per ciascun bollettino.
*/

#ifndef MAIN_H
#include "main.h"
#endif

#ifndef CODAVET_H
#include "CodaVet.h"
#endif

#ifndef LISTAPTR_H
#include "ListaPtr.h"
#endif

struct versamento {
     string num_conto;
     string intestatario;
     double importo;
};

struct persona {
     string cognome;
     string nome;
     string sequenza;
     ListaPtr<versamento> *lv;
};

void inserimento(CodaVet<persona> &c) {
     cout << endl;
     cout << "*** Inserimento della coda di persone ***" << endl << endl;
     int i=0;
     int num;
     persona el;
     versamento vers;
     char risp='y';
     while ((risp=='y')||(risp=='Y')) {
        i++;
        cout << "Inserisci cognome: ";
        cin >> el.cognome;
        cout << "Inserisci nome: ";
        cin >> el.nome;
        cout << "Inserisci numero sequenza: ";
        cin >> el.sequenza;
        el.lv=new(ListaPtr<versamento>);
        lpcell<versamento> *p=new (lpcell<versamento>);
        p=el.lv->primoLista();
        cout << "Inserisci numero di versamenti da effettuare: ";
        cin >> num;
        for (int j=0; j<num; j++) {
           cout << "Inserisci numero conto: ";
           cin >> vers.num_conto;
           cout << "Inserisci intestatario: ";
           cin >> vers.intestatario;
           cout << "Inserisci importo da versare: ";
           cin >> vers.importo;
           el.lv->insLista(vers, p);
           p=el.lv->succLista(p);
        }        
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

void copiaCoda(CodaVet<persona> &c, CodaVet<persona> &d) {
     CodaVet<persona> appoggio;
     persona p;
     if (c.codaVuota()) {
        cout << "La coda da copiare e' vuota!" << endl;
        return;
     } else {
        while (!c.codaVuota()) {
           p=c.leggiCoda();
           d.inCoda(p);
           appoggio.inCoda(p);
           c.fuoriCoda();
        }
        while (!appoggio.codaVuota()) {
           p=appoggio.leggiCoda();
           c.inCoda(p);
           appoggio.fuoriCoda();
        }
     }
};

void stampa(CodaVet<persona> &c) {
     cout << "*** Stampa della coda di persone e dei dati dei versamenti ***" << endl << endl;
     CodaVet<persona> appoggio;
     persona pers;
     versamento vers;
     lpcell<versamento> *p;
     if (c.codaVuota()) {
        cout << "Spiacente, la coda da stampare e' vuota!" << endl;
        return;
     } else {
        copiaCoda(c, appoggio);
        while (!appoggio.codaVuota()) {
           pers=appoggio.leggiCoda();
           cout << "Cliente: " << pers.cognome << " " << pers.nome << endl;
           cout << "Numero sequenza: " << pers.sequenza << endl;
           p=pers.lv->primoLista();
           cout << endl;
           cout << "*** Versamenti da effettuare ***" << endl << endl;
           while(!pers.lv->fineLista(p)) {
              vers=pers.lv->leggiLista(p);
              cout << "Numero conto: " << vers.num_conto << endl;
              cout << "Intestatario: " << vers.intestatario << endl;
              cout << "Importo da versare: " << vers.importo << endl;
              p=pers.lv->succLista(p);
              cout << endl;
           }
           appoggio.fuoriCoda();
           cout << endl;
        }
     }
     cout << endl;
};

void stampaImportoTot(CodaVet<persona> &c) {
     cout << "*** Stampa della coda di persone e degli importi totali versati ***" << endl;
     cout << "L'importo totale comprende la tassa di 1 euro x ogni bollettino versato." << endl;
     cout << endl;
     CodaVet<persona> appoggio;
     persona pers;
     int i=0;
     int conto=0;
     double importoTot=0;
     versamento vers;
     lpcell<versamento> *p;
     if (c.codaVuota()) {
        cout << "Spiacente, la coda da stampare e' vuota!" << endl;
        return;
     } else {
        copiaCoda(c, appoggio);
        while (!appoggio.codaVuota()) {
           pers=appoggio.leggiCoda();
           cout << "Cliente: " << pers.cognome << " " << pers.nome << endl;
           p=pers.lv->primoLista();
           while(!pers.lv->fineLista(p)) {
              i++;
              vers=pers.lv->leggiLista(p);
              conto=conto+vers.importo;
              p=pers.lv->succLista(p);
           }
           importoTot=conto+i;
           appoggio.fuoriCoda();
           cout << "Importo totale versato: " 
                << importoTot << endl;
           i=0;
           conto=0;
        }
     }
     cout << endl;
};

int main() {
     CodaVet<persona> cod;
     cout << "***** GESTIONE CODA IN UFFICIO POSTALE *****" << endl << endl;
     inserimento(cod);
     stampa(cod);
     stampaImportoTot(cod);
     cout << "Grazie e...asta la vista!" << endl;
     system("pause");
     return 0;
}

