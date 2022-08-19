/*
  Nome: NodoPtr.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa il nodo della coda con puntatore
*/

#ifndef NODOPTR_H
#define NODOPTR_H

#include "NodoCoda.h"

class NodoPtr; // dichiarazione anticipata
typedef NodoPtr *posizioneCoda; //necessita della dichiarazione anticipata

class NodoPtr: public NodoCoda{ // NodoPtr estende NodoCoda
public:
   NodoPtr(); 
   NodoPtr(elemCoda);  // costruttore che inizializza l'etichetta
   NodoPtr(elemCoda, posizioneCoda); // etichetta + puntatore
   ~NodoPtr(); 
   
   posizioneCoda getSuccessivo();
   void setSuccessivo(posizioneCoda);
   
private:
   posizioneCoda successivo;
};

#endif
