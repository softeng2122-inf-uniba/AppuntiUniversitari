#include <iostream>
#include <cstdlib>
#include "NodoCur.h"

NodoCur::NodoCur(): Nodo(0){
   successivo = NIL; // posizione vettore non valida
};

NodoCur::NodoCur(tipoelem a): Nodo(a){
   successivo = NIL; // IDEM come sopra
};

NodoCur::NodoCur(tipoelem a, posizione p): Nodo(a){
   successivo = p;
};

NodoCur::~NodoCur(){};
   
posizione NodoCur::getSuccessivo(){
   return successivo;
};

void NodoCur::setSuccessivo(posizione p){
   successivo = p;     
};
