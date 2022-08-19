/*
  Nome: Dizionario.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa il dizionario (hash chiuso estendibile)
*/

#ifndef DIZIONARIO_H
#define DIZIONARIO_H
#define M 101

#include "ListaStr.h"

class Dizionario{
public:
   
   Dizionario();
   ~Dizionario();
   
   void creaDizionario();
   bool appartiene(tipochiave);
   bool inserisci(tipoelem);
   bool cancella(tipochiave);
   
   bool recupera(tipochiave, tipoelem &);
   bool aggiorna(tipochiave, tipoelem);
   
   void stampa();
   
private:
   int hashWord(tipochiave);
   ListaStr dizionario[M];

};

#endif
