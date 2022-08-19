/*
  Nome: NodoCur.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa il nodo della lista con cursore
*/

#include "Nodo.h"
#define NIL -1

typedef int posizione;

class NodoCur: public Nodo{ // NodoCur estende Nodo
public:
   NodoCur();
   NodoCur(tipoelem);  // costruttore che inizializza l'etichetta
   NodoCur(tipoelem, posizione); // etichetta + cursore
   ~NodoCur();
   
   posizione getSuccessivo();
   void setSuccessivo(posizione);
   
private:
   posizione successivo;
};
