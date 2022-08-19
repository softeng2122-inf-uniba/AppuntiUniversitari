/*
  Nome: PilaPtr.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa la pila con puntatore
*/

#ifndef PILAPTR_H
#define PILAPTR_H
#include "NodoPtr.h"

class PilaPtr {
public:
   PilaPtr();
   ~PilaPtr();
   
   void creaPila();
   bool pilaVuota();
   
   bool leggiPila(tipoelem &);
   
   void inPila(tipoelem);
   void fuoriPila();

private:
   posizione testa;   
};


#endif
