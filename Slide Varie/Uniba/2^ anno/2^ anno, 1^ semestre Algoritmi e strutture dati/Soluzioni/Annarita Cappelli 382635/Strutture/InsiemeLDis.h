/*
Autore: Annarita Cappelli 
Matricola: 382635
Nome file: InsiemeLDis.h
Commento: Classe che implementa un insieme mediante la rappresentazione 
con uso di lista non ordinata.
*/

#ifndef INSIEMELDIS_H
#define INSIEMELDIS_H
#define dim 1024  // lunghezza massima del vettore

#ifndef MAIN_H
#include "main.h"
#endif


template <class I>
struct icell {
       I val;
       icell<I> *successivo;
};

template <class I>
class InsiemeLDis {
      public:
             InsiemeLDis();  // costruttore
             ~InsiemeLDis();  // distruttore
             
             // operatori
             void creaInsieme();
             bool insiemeVuoto();
             bool appartiene(I);
             void inserisci(I);
             void cancella(I);
             I leggi();
             void unione(InsiemeLDis<I> &, InsiemeLDis<I> &);
             void intersezione(InsiemeLDis<I> &, InsiemeLDis<I> &);
             void differenza(InsiemeLDis<I> &, InsiemeLDis<I> &);
             
             // operatori aggiuntivi
             void mostraInsieme();
             int cardinality();
      private:
              icell<I> *primo;
};

template <class I>
InsiemeLDis<I>::InsiemeLDis() {
     creaInsieme();
};

template <class I>
InsiemeLDis<I>::~InsiemeLDis() {
     icell<I> *p=primo;
     icell<I> *temp;
     while (p!=NULL) {
        temp=p->successivo;
        cancella(p->val);
        p=temp;
     }
}

template <class I>
void InsiemeLDis<I>::creaInsieme() {
     primo=NULL;
};

template <class I>
bool InsiemeLDis<I>::insiemeVuoto() {
     return (primo==NULL);
};

template <class I>
bool InsiemeLDis<I>::appartiene(I el) {
     icell<I> *p=primo;
     while (p!=NULL) {
        if (el==p->val)
           return true;
        else
           p=p->successivo;
     }
     return false;
};

template <class I>
void InsiemeLDis<I>::inserisci(I el) {
     if (!appartiene(el)) {
        icell<I> *nuovo=new (icell<I>);
        nuovo->val=el;
        nuovo->successivo=primo;
        primo=nuovo;
     }
};

template <class I>
void InsiemeLDis<I>::cancella(I el) {
     if (appartiene(el)) {
        icell<I> *p=primo;
        icell<I> *q=p;
        while ((p!=NULL)&&(p->val!=el)) {
           q=p;
           p=p->successivo;
        }
        if (p==primo) {
           if (p->successivo==NULL)
              primo=NULL;
           else
              primo=p->successivo;
        } else
           q->successivo=p->successivo;
        delete (p);
     } 
};

template <class I>
void InsiemeLDis<I>::unione(InsiemeLDis<I> &ins1, InsiemeLDis<I> &ins2) {
     icell<I> *p=ins1.primo;
     creaInsieme();
     while (p!=NULL) {
        inserisci(p->val);
        p=p->successivo;
     }
     p=ins2.primo;
     while (p!=NULL) {
        if (!appartiene(p->val))
          inserisci(p->val);
        p=p->successivo;
     }
};

template <class I>
void InsiemeLDis<I>::intersezione(InsiemeLDis<I> &ins1, InsiemeLDis<I> &ins2) {
     icell<I> *p=ins1.primo;
     creaInsieme();
     while (p!=NULL) {
        if (ins2.appartiene(p->val))
          inserisci(p->val);
        p=p->successivo;
     }
};

template <class I>
void InsiemeLDis<I>::differenza(InsiemeLDis<I> &ins1, InsiemeLDis<I> &ins2) {
     icell<I> *p=ins1.primo;
     creaInsieme();
     while (p!=NULL) {
        if (!ins2.appartiene(p->val))
          inserisci(p->val);
        p=p->successivo;
     }
};

template <class I>
I InsiemeLDis<I>::leggi() {
     return primo->val;
};
     

template <class I>
void InsiemeLDis<I>::mostraInsieme() {
     if (!insiemeVuoto()) {
         icell<I> *p=primo;
         cout << "{ ";
         while (p!=NULL) {
            cout << p->val << " ";
            p=p->successivo;
         }
         cout << "}" << endl;
     }
};

template <class I>
int InsiemeLDis<I>::cardinality() {
     int conto=0;
     icell<I> *p=primo;
     while (p!=NULL) {
        conto++;
        p=p->successivo;
     }
     return conto;
};

#endif
        




