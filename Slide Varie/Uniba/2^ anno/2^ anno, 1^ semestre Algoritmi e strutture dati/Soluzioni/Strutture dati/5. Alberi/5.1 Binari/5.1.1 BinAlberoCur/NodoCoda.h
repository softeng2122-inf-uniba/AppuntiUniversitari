/*
  Nome: NodoCoda.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa il nodo della coda (visita per livelli)
*/

#ifndef NODOCODA_H
#define NODOCODA_H
#include "NodoBinCur.h"

typedef nodoBin elemCoda;

class NodoCoda {
public:
   NodoCoda(); // costruttore standard
   NodoCoda(elemCoda);  // costruttore che inizializza l'etichetta
   ~NodoCoda(); // distruttore
   
   elemCoda getEtichetta();
   void setEtichetta(elemCoda);
   
private:
   elemCoda etichetta;
};

#endif
