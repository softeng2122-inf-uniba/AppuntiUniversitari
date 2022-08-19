/*
Autore: Annarita Cappelli 
Matricola: 382635
Nome file: PilaPtr.h
Commento: Classe che implementa una pila mediante la rappresentazione 
collegata con puntatori monodirezionale.
*/

#ifndef PILAPTR_H
#define PILAPTR_H

#ifndef MAIN_H
#include "main.h"
#endif

template <class P>
struct ppcell {
       P valore;
       struct ppcell<P> *successivo;
};

template <class P>
struct stack {
       struct ppcell<P> *primo;
};

template <class P>
class PilaPtr {
      public:
             PilaPtr();  // costruttore
             ~PilaPtr();  // distruttore
             
             // operatori
             void creaPila();
             bool pilaVuota();
             P leggiPila();
             void fuoriPila();
             void inPila(P);
      private:
              struct stack<P> pila;
};

template <class P>
PilaPtr<P>::PilaPtr() {
     creaPila();
};

template <class P>
PilaPtr<P>::~PilaPtr() { };

template <class P>
void PilaPtr<P>::creaPila() {
     pila.primo=NULL;
};

template <class P>
bool PilaPtr<P>::pilaVuota() {
     return (pila.primo==NULL);
};

template <class P>
P PilaPtr<P>::leggiPila() {
     if (!pilaVuota())
        return (pila.primo->valore);
};

template <class P>
void PilaPtr<P>::fuoriPila() {
     if (!pilaVuota()) {
        ppcell<P> *temp=pila.primo->successivo;
        delete(pila.primo);
        pila.primo=temp;
     }
};

template <class P>
void PilaPtr<P>::inPila(P elem) {
     ppcell<P> *temp=new(ppcell<P>);
     temp->valore=elem;
     if (pilaVuota()) {
        pila.primo=temp;
        temp->successivo=NULL;  
     } else {
        temp->successivo=pila.primo;
        pila.primo=temp;
     }
};

#endif
