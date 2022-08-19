/*
  Nome: NodoPtr.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa il nodo della coda con puntatore
*/

#ifndef NODOPTR_H
#define NODOPTR_H

#include "NodoCoda.h"

class NodoPtr; // dichiarazione anticipata
typedef NodoPtr *posizione; //necessita della dichiarazione anticipata

class NodoPtr: public NodoCoda{ // NodoPtr estende NodoCoda
public:
   NodoPtr(); // costruttore standard
   NodoPtr(elemCoda);  // costruttore che inizializza l'etichetta
   NodoPtr(elemCoda, posizione); // etichetta + puntatore
   ~NodoPtr(); // distruttore
   
   posizione getSuccessivo();
   void setSuccessivo(posizione);
   
private:
   posizione successivo;
};

#endif
