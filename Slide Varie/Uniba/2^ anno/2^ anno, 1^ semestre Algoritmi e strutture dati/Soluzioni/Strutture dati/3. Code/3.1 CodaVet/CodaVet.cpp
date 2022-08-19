#include <iostream>
#include <cstdlib>
#include "CodaVet.h"

CodaVet::CodaVet(){
   creaCoda();
};

CodaVet::~CodaVet(){};
   
void CodaVet::creaCoda(){
   testa = fondo = NIL;
};
   
bool CodaVet::codaVuota(){
   return (testa == NIL);
};
   
bool CodaVet::leggiCoda(tipoelem &a){
   if (testa != NIL){
      a = coda[testa].getEtichetta();
      return true;
   } else return false; // coda vuota
};
   
bool CodaVet::inCoda(tipoelem a){
   if (((fondo - testa + 1) % MAXLUNG)){
      fondo = ++fondo % MAXLUNG;
      if (testa == NIL)
         testa = fondo;
      coda[fondo].setEtichetta(a);
      return true;
   } else return false; // coda piena
};

bool CodaVet::fuoriCoda(){
   if (testa != NIL){
      if (testa == fondo)
         testa = fondo = NIL;
      else 
         testa = ++testa % MAXLUNG;
      return true;
   } else return false; // coda vuota
};
