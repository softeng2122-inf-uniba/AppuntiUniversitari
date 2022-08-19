/*
  Nome: CodaVet.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa la coda con vettore circolare
*/

#ifndef CODAVET_H
#define CODAVET_H

#include "Nodo.h"
#define MAXLUNG 100
#define NIL -1

class CodaVet {
public:
   CodaVet();
   ~CodaVet();
   
   void creaCoda();
   bool codaVuota();
   
   bool leggiCoda(tipoelem &);
   
   bool inCoda(tipoelem);
   bool fuoriCoda();

private:
   Nodo coda[MAXLUNG];
   int testa, fondo;   
};

#endif
