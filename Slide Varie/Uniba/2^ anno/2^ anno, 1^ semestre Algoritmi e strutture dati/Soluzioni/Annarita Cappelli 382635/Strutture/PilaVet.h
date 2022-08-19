/*
Autore: Annarita Cappelli 
Matricola: 382635
Nome file: PilaVet.h
Commento: Classe che implementa una pila mediante la rappresentazione 
sequenziale con vettore.
*/

#ifndef PILAVET_H
#define PILAVET_H
#define MAXLUNG 1024

#ifndef MAIN_H
#include "main.h"
#endif

template <class P>
struct pvcell {
       P valore;
};

template <class P>
class PilaVet {
      public:
             PilaVet();  // costruttore
             ~PilaVet();  // distruttore
             
             // operatori
             void creaPila();
             bool pilaVuota();
             P leggiPila();
             void fuoriPila();
             void inPila(P);
      private:
              pvcell<P> pila[MAXLUNG];
              int testa;
};

template <class P>
PilaVet<P>::PilaVet() {
     creaPila();
};

template <class P>
PilaVet<P>::~PilaVet() { };

template <class P>
void PilaVet<P>::creaPila() {
     testa=0;  // testa e' l'indice del successivo inserimento
};

template <class P>
bool PilaVet<P>::pilaVuota() {
     return (testa==0);
};

template <class P>
P PilaVet<P>::leggiPila() {
     if (testa>0)
        return pila[testa-1].valore;
};

template <class P>
void PilaVet<P>::fuoriPila() {
     if (testa>0)
        testa--;
};

template <class P>
void PilaVet<P>::inPila(P elem) {
     if (testa<MAXLUNG) {
        pila[testa].valore=elem;
        testa++;
     }
};

#endif


