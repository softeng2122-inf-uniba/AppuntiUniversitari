/*
Autore: Annarita Cappelli 
Matricola: 382635
Nome file: CodaPtr.h
Commento: Classe che implementa una coda mediante la rappresentazione 
collegata con puntatori monodirezionale.
*/

#ifndef CODAPTR_H
#define CODAPTR_H

#ifndef MAIN_H
#include "main.h"
#endif

template <class C>
struct cpcell {
       C valore;
       struct cpcell<C> *successivo;
};

template <class C>
struct queue {
       struct cpcell<C> *testa;
       struct cpcell<C> *fondo;
};

template <class C>
class CodaPtr {
      public:
             CodaPtr();  // costruttore
             ~CodaPtr();  // distruttore
             
             // operatori
             void creaCoda();
             bool codaVuota();
             C leggiCoda();
             void fuoriCoda();
             void inCoda(C);
             
             // operatore aggiunto per l'uso della coda nelle visite in ampiezza
             bool appartiene(C);
      private:
              struct queue<C> coda;
};

template <class C>
CodaPtr<C>::CodaPtr() {
     creaCoda();
}

template <class C>
CodaPtr<C>::~CodaPtr() {
     if (!codaVuota()) {
        cpcell<C> *temp=coda.testa;
        while (temp!=NULL) {
           cpcell<C> *atemp=temp->successivo;
           delete (temp);
           temp=atemp;
        }
     }
};

template <class C>
void CodaPtr<C>::creaCoda() {
     coda.testa=coda.fondo=NULL;
};

template <class C>
bool CodaPtr<C>::codaVuota() {
     return (coda.testa==NULL);
};

template <class C>
C CodaPtr<C>::leggiCoda() {
     if (!codaVuota())
        return (coda.testa->valore);
};

template <class C>
void CodaPtr<C>::fuoriCoda() {
     if (!codaVuota()) {
        cpcell<C> *temp=coda.testa->successivo;
        delete (coda.testa);
        coda.testa=temp;
     }
};

template <class C>
void CodaPtr<C>::inCoda(C elem) {
     if (codaVuota())
        coda.testa=coda.fondo=new(cpcell<C>);
     else {
        coda.fondo->successivo=new(cpcell<C>);
        coda.fondo=coda.fondo->successivo;
     }
     coda.fondo->valore=elem;
     coda.fondo->successivo=NULL;
};

// operatore aggiunto per l'uso della coda nelle visite in ampiezza
template <class C>
bool CodaPtr<C>::appartiene(C elem) {
     bool ret=false;
     cpcell<C> *temp=coda.testa;
     while ((temp!=NULL)&&(!ret)) {
        if (temp->valore==elem)
           ret=true;
        else
           temp=temp->successivo;
     }
     return (ret);
};

#endif


