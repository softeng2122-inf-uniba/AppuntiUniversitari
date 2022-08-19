#include <iostream>
#include <cstdlib>
#include "PilaPtr.h"

PilaPtr::PilaPtr(){
   creaPila();
};

PilaPtr::~PilaPtr(){
   posizione q;
   while (testa != NULL){
      q = testa;
      testa = testa->getSuccessivo();
      delete q;
   }
};
   
void PilaPtr::creaPila(){
   testa = NULL;
};

bool PilaPtr::pilaVuota(){
   return testa == NULL;
};
   
bool PilaPtr::leggiPila(tipoelem &a){
   if (testa != NULL){
      a = testa->getEtichetta();
      return true;
   } else return false;
};
   
void PilaPtr::inPila(tipoelem a){
   posizione q = new NodoPtr(a, testa);
   testa = q;
};

void PilaPtr::fuoriPila(){
   posizione q = testa;
   testa = testa->getSuccessivo();
   delete q;
};
