/*
  Nome: Nodo.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa il nodo della lista sequenziale
*/


#ifndef NODO_H
#define NODO_H

typedef int tipoelem;


class Nodo {
public:
   Nodo();
   Nodo(tipoelem);  
   ~Nodo();
   
   tipoelem getEtichetta();
   void setEtichetta(tipoelem);
   
private:
   tipoelem etichetta;
};

#endif
