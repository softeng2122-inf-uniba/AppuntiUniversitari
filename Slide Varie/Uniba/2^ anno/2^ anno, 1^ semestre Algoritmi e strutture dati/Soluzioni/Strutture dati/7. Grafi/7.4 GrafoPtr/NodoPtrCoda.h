/*
  Nome: NodoPtrCoda.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa il nodo della coda con puntatore
*/

#ifndef NODOPTRCODA_H
#define NODOPTRCODA_H

#include "NodoCoda.h"

class NodoPtrCoda; // dichiarazione anticipata
typedef NodoPtrCoda *posizioneCoda; //necessita della dichiarazione anticipata

class NodoPtrCoda: public NodoCoda{ // NodoPtrCoda estende NodoCoda
public:
   NodoPtrCoda(); 
   NodoPtrCoda(elemCoda);  // costruttore che inizializza l'etichetta
   NodoPtrCoda(elemCoda, posizioneCoda); // etichetta + puntatore
   ~NodoPtrCoda(); 
   
   posizioneCoda getSuccessivo();
   void setSuccessivo(posizioneCoda);
   
private:
   posizioneCoda successivo;
};

#endif
