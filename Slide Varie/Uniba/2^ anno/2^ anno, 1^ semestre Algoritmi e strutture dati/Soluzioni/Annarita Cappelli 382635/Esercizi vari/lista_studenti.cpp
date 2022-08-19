/*
Fornire una realizzazione in C/C++ di una struttura lineare che 
contenga un elenco di studenti. Di ogni studente si vuole 
memorizzare: nominativo, matricola, elenco di esami sostenuti. 
Entrambi gli elenchi vanno realizzati tramite l'implementazione 
di una opportuna struttura dati. 
Realizzare i punti richiesti di seguito: 
- funzione di inserimento dell'elenco degli studenti; 
- funzione di stampa dell'elenco degli studenti; 
- funzione di inserimento degli esami sostenuti da uno studente, 
data la matricola; 
- funzione di stampa degli esami, data una matricola; 
- funzione che, data una matricola, stampa la media degli esami 
sostenuti dallo studente. 
Dimostrare il funzionamento delle funzioni mediante chiamate 
alle funzioni realizzate nel main.
*/

#ifndef MAIN_H
#include "main.h"
#endif

#ifndef LISTABI_H
#include "ListaBi.h"
#endif

struct studente;
typedef lbcell<studente> *posizione;

struct esame {
       string nome;
       int voto;
};

struct studente {
       string cognome;
       string nome;
       string matricola;
       ListaBi<esame> *exam;
};

void inserimento(ListaBi<studente> &l) {
     posizione p=l.primoLista();
     char risp='y';
     studente a;
     int i=0;
     while ((risp=='y')||(risp=='Y')) {
        i++;
        cout << "Inserisci cognome studente: ";
        cin >> a.cognome;
        cout << "Inserisci nome studente: ";
        cin >> a.nome;
        cout << "Inserisci matricola: ";
        cin >> a.matricola;
        a.exam=new (ListaBi<esame>);
        int num_esami;
        cout << "Quanti esami vuoi inserire? ";
        cin >> num_esami;
        esame b;
        lbcell<esame> *q=new (lbcell<esame>);
        q=a.exam->primoLista();
        for (int i=0; i<num_esami; i++) {
           cout << "Inserisci nome esame: ";
           cin >> b.nome;
           do {
              cout << "Inserisci voto: (18-30) ";
              cin >> b.voto;
           } while (!((b.voto>=18)&&(b.voto<=30)));
           a.exam->insLista(b, q);
           q=a.exam->succLista(q);
        }
        l.insLista(a, p);
        p=l.succLista(p);
       do {
            cout << "Altro studente? (y/n) ";
            cin >> risp;
        } while (!((risp=='y')||(risp=='Y')||(risp=='n')||(risp=='N')));
     }
     cout << endl;
     cout << "Inserimento eseguito!" << endl;
     cout << "Hai inserito " << i << " studenti!" << endl;
     cout << endl;
};

bool ricercaMat(ListaBi<studente> &l, string mat, studente &stu, posizione &pos) {
     bool trovato=false;
     posizione p=l.primoLista();
     if (l.listaVuota()) {
        cout << "Spiacente, la lista studenti e' vuota, non posso cercare!" << endl;
        return false;
     } else {
        while (!(l.fineLista(p)||trovato)) {
           stu=l.leggiLista(p);
           if (stu.matricola==mat) {
              trovato=true;
              pos=p;
           }
           else
              p=l.succLista(p);
        }
     }
     return trovato;
};

void inserimentoMatricola(ListaBi<studente> &l, string mat) {
     studente a;
     posizione pos;
     if (ricercaMat(l, mat, a, pos)) {
        int num_esami;
        cout << "Quanti esami vuoi inserire? ";
        cin >> num_esami;
        esame b;
        lbcell<esame> *q=new (lbcell<esame>);
        q=a.exam->primoLista();
        while (!a.exam->fineLista(q))
           q=a.exam->succLista(q);
        for (int i=0; i<num_esami; i++) {
           cout << "Inserisci nome esame: ";
           cin >> b.nome;
           do {
              cout << "Inserisci voto: (18-30) ";
              cin >> b.voto;
           } while (!((b.voto>=18)&&(b.voto<=30)));
           a.exam->insLista(b, q);
           q=a.exam->succLista(q);
        }
        l.scriviLista(a, pos);
     } else {
        cout << "Matricola inesistente!" << endl;
        return;
     }
};

void stampa(ListaBi<studente> &l) {
     posizione p=l.primoLista();
     studente appoggio;
     esame happosai;
     lbcell<esame> *q=new (lbcell<esame>);
     if (l.listaVuota()) {
        cout << "Spiacente, ma la lista studenti da stampare e' vuota!" << endl;
        return;
     }
     while (!l.fineLista(p)) {
        appoggio=l.leggiLista(p);
        cout << "Studente: " << appoggio.cognome << " " << appoggio.nome << endl; 
        cout << "Matricola: " << appoggio.matricola << endl;
        q=appoggio.exam->primoLista();
        while(!appoggio.exam->fineLista(q)) {
           happosai=appoggio.exam->leggiLista(q);
           cout << "Esame: " << happosai.nome << " Voto: " << happosai.voto << endl;
           q=appoggio.exam->succLista(q);
        }
        p=l.succLista(p);
        cout << endl;
     }
     cout << "Stampa eseguita con successo!" << endl;
};

void stampaEsami(ListaBi<studente> &l, string mat) {
     studente a;
     posizione pos;
     esame test;
     lbcell<esame> *q=new (lbcell<esame>);
     if (ricercaMat(l, mat, a, pos)) {
        cout << "Studente: " << a.cognome << " " << a.nome << endl;
        q=a.exam->primoLista();
        while (!a.exam->fineLista(q)) {
           test=a.exam->leggiLista(q);
           cout << "Esame: " << test.nome << " Voto: " << test.voto << endl;
           q=a.exam->succLista(q);
        }
     } else {
        cout << "Matricola inesistente!" << endl;
        return;
     }
};

void mediaEsami(ListaBi<studente> &l, string mat, int &media) {
     studente a;
     posizione pos;
     int i=0;
     int conto=0;
     if (ricercaMat(l, mat, a, pos)) {
        esame b;
        lbcell<esame> *q=new (lbcell<esame>);
        q=a.exam->primoLista();
        while (!a.exam->fineLista(q)) {
           i++;
           b=a.exam->leggiLista(q);
           conto=conto+b.voto;
           q=a.exam->succLista(q);
        }
        media=conto/i;
        cout << endl;
     } else {
        cout << "Matricola inesistente!" << endl;
        return;
     }
};

int main() {
    ListaBi<studente> lis;
    string mat;
    int media=0;
    cout << "***** Programma elenco studenti *****" << endl;
    cout << endl;
    cout << "*** Inserimento lista studenti ***" << endl << endl;
    inserimento(lis);
    cout << endl;
    cout << "*** Stampa lista studenti ***" << endl << endl;
    stampa(lis);
    cout << endl;
    cout << "*** Inserimento ulteriori esami di uno studente, data la matricola ***" << endl << endl;
    cout << "Inserisci matricola studente: ";
    cin >> mat;
    inserimentoMatricola(lis, mat);
    cout << endl;
    cout << "*** Stampa esami studente data la matricola ***" << endl << endl;
    cout << "Inserisci matricola studente: ";
    cin >> mat;
    stampaEsami(lis, mat);
    cout << endl;
    cout << "*** Media esami studente data la matricola ***" << endl << endl;
    cout << "Inserisci matricola studente: ";
    cin >> mat;
    mediaEsami(lis, mat, media);
    cout << "Media: " << media << endl;
    cout << endl;
    system("pause");
    return 0;
};
