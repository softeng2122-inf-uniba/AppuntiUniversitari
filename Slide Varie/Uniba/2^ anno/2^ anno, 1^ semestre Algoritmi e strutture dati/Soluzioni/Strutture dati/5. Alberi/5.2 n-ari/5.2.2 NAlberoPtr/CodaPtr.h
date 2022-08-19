/*
  Nome: CodaPtr.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa la coda con puntatore
*/

#ifndef CODAPTR_H
#define CODAPTR_H

#include "NodoPtr.h"

class CodaPtr {
public:
   CodaPtr();
   ~CodaPtr();
   
   void creaCoda();
   bool codaVuota();
   
   bool leggiCoda(elemCoda &);
   
   void inCoda(elemCoda);
   bool fuoriCoda();

private:
   posizione testa, fondo;   
};


#endif
