/*
  Nome: PilaVet.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa la pila con vettore
*/

#ifndef PILAVET_H
#define PILAVET_H
#include "Nodo.h"
#define MAXLUNG 100

class PilaVet {
public:
   PilaVet();
   ~PilaVet();
   
   void creaPila();
   bool pilaVuota();
   
   bool leggiPila(tipoelem &);
   
   bool inPila(tipoelem);
   bool fuoriPila();

private:
   Nodo pila[MAXLUNG];
   int testa;   
};

#endif
