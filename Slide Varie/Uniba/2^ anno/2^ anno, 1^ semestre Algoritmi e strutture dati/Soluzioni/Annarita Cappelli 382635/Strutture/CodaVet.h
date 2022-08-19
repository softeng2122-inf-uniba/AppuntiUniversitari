/*
Autore: Annarita Cappelli 
Matricola: 382635
Nome file: CodaVet.h
Commento: Classe che implementa una coda mediante la rappresentazione 
sequenziale con vettore circolare.
*/

#ifndef CODAVET_H
#define CODAVET_H
#define MAXLUNG 1024
#define NIL -1

#ifndef MAIN_H
#include "main.h"
#endif

template <class C>
struct cvcell {
       C valore;
};

template <class C>
class CodaVet {
      public:
             CodaVet();  // costruttore
             ~CodaVet();  // distruttore
             
             // operatori
             void creaCoda();
             bool codaVuota();
             C leggiCoda();
             void fuoriCoda();
             void inCoda(C);
             bool appartiene(C);
      private:
              cvcell<C> coda[MAXLUNG];
              int testa, fondo;
};

template <class C>
CodaVet<C>::CodaVet() {
     creaCoda();
};

template <class C>
CodaVet<C>::~CodaVet() { };

template <class C>
void CodaVet<C>::creaCoda() {
     testa=fondo=NIL;
};

template <class C>
bool CodaVet<C>::codaVuota() {
     return (testa==NIL);
};

template <class C>
C CodaVet<C>::leggiCoda() {
     if (!codaVuota())
        return (coda[testa].valore);
};

template <class C>
void CodaVet<C>::fuoriCoda() {
     if (!codaVuota())
        if (testa==fondo)
           testa=fondo=NIL;
        else
           testa=++testa%MAXLUNG;
};

template <class C>
void CodaVet<C>::inCoda(C elem) {
     if (((fondo-testa+1)%MAXLUNG)) {
        fondo=++fondo%MAXLUNG;
        if (testa==NIL)
           testa=fondo;
        coda[fondo].valore=elem;
     }
};        

#endif



       
