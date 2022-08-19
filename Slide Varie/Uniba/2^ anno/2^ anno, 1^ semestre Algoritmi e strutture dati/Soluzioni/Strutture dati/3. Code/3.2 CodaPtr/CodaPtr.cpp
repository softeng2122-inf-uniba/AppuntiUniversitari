#include <iostream>
#include <cstdlib>
#include "CodaPtr.h"

CodaPtr::CodaPtr(){
   creaCoda();
};

CodaPtr::~CodaPtr(){
   posizione q;
   while (testa != NULL){
      q = testa;
      testa = testa->getSuccessivo();
      delete q;
   }
};
   
void CodaPtr::creaCoda(){
   testa = fondo = NULL;
};

bool CodaPtr::codaVuota(){
   return testa == NULL;
};
   
bool CodaPtr::leggiCoda(tipoelem &a){
   if (testa != NULL){
      a = testa->getEtichetta();
      return true;
   } else return false;
};
   
void CodaPtr::inCoda(tipoelem a){
   posizione q = new NodoPtr(a);
   if (testa != NULL){
      fondo->setSuccessivo(q);
      fondo = q;
   }
   else
      testa = fondo = q;   
};

bool CodaPtr::fuoriCoda(){
   if (testa != NULL){
      posizione q = testa;
      testa = testa->getSuccessivo();
      delete q;
      return true;
   } else return false;
};

