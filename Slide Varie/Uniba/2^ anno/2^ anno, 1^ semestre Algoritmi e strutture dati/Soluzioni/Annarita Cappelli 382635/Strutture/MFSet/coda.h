#ifndef CODA_H
#define CODA_H

#ifndef MAIN_H
#include "main.h"
#endif

template <class C>
struct ccell {
       C val;
       struct ccell<C> *next;
};

template <class C>
struct queue {
       struct ccell<C> *testa;
       struct ccell<C> *fine;
};

template <class C>
class Coda {
      public:
             Coda();  // costruttore
             ~Coda();  // distruttore
             
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
Coda<C>::Coda() {
     creaCoda();
}

template <class C>
Coda<C>::~Coda() {
     if (!codaVuota()) {
        ccell<C> *temp=coda.testa;
        while (temp!=NULL) {
           ccell<C> *atemp=temp->next;
           delete (temp);
           temp=atemp;
        }
     }
};

template <class C>
void Coda<C>::creaCoda() {
     coda.testa=coda.fine=NULL;
};

template <class C>
bool Coda<C>::codaVuota() {
     return (coda.testa==NULL);
};

template <class C>
C Coda<C>::leggiCoda() {
     if (codaVuota())
        _gerr("Coda::leggiCoda: la coda e' vuota!");
     return (coda.testa->val);
};

template <class C>
void Coda<C>::fuoriCoda() {
     if (codaVuota())
        _gerr("Coda::fuoriCoda: la coda e' vuota!");
     ccell<C> *temp=coda.testa->next;
     delete (coda.testa);
     coda.testa=temp;
};

template <class C>
void Coda<C>::inCoda(C elem) {
     if (codaVuota())
        coda.testa=coda.fine=new(ccell<C>);
     else {
        coda.fine->next=new(ccell<C>);
        coda.fine=coda.fine->next;
     }
     coda.fine->val=elem;
     coda.fine->next=NULL;
};

// operatore aggiunto per l'uso della coda nelle visite in ampiezza
template <class C>
bool Coda<C>::appartiene(C elem) {
     bool ret=false;
     ccell<C> *temp=coda.testa;
     while ((temp!=NULL)&&(!ret)) {
        if (temp->val==elem)
           ret=true;
        else
           temp=temp->next;
     }
     return (ret);
};


#endif


