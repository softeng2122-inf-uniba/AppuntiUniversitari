/*
  Nome: NodoStr.h 
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa il nodo della lista di stringhe
*/

#ifndef NODOSTR_H
#define NODOSTR_H

typedef std::string tipochiave;

struct attrib{
   int num;
};
struct rec{
   tipochiave chiave;
   attrib attributo;  
};
typedef rec tipoelem;

class NodoStr; // dichiarazione anticipata
typedef NodoStr *posizione; //necessita della dichiarazione anticipata

class NodoStr{ // NodoPtr estende Nodo
public:
   NodoStr(); 
   NodoStr(tipoelem);  // costruttore che inizializza l'etichetta
   NodoStr(tipoelem, posizione); // etichetta + puntatore
   ~NodoStr(); 
   
   tipoelem getEtichetta();
   void setEtichetta(tipoelem);
   
   posizione getSuccessivo();
   void setSuccessivo(posizione);
   
private:
   tipoelem etichetta;
   posizione successivo;
};

#endif
