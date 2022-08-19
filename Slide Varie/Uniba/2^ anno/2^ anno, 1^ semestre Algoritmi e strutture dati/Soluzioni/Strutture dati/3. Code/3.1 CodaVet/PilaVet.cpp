#include <iostream>
#include <cstdlib>
#include "PilaVet.h"

PilaVet::PilaVet(){
   creaPila();
};

PilaVet::~PilaVet(){};
   
void PilaVet::creaPila(){
   testa = 0; // testa è l'indice del successivo inserimento
};
   
bool PilaVet::pilaVuota(){
   return (testa == 0);
};
   
bool PilaVet::leggiPila(tipoelem &a){
   if (testa > 0){
      a = pila[testa-1].getEtichetta();
      return true;
   } else return false; // pila vuota
};
   
bool PilaVet::inPila(tipoelem a){
   if (testa < MAXLUNG){
      pila[testa].setEtichetta(a);
      testa++;
      return true;
   } else return false; // pila piena
};

bool PilaVet::fuoriPila(){
   if (testa > 0){
      testa--;
      return true;
   } else return false; // pila vuota
};
