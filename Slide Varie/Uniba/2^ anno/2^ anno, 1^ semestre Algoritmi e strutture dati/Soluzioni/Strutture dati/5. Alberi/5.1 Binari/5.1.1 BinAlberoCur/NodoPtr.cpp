#include <iostream>
#include <cstdlib>
#include "NodoPtr.h"

NodoPtr::NodoPtr(): NodoCoda(NIL){
   successivo = NULL;
};

NodoPtr::NodoPtr(elemCoda a): NodoCoda(a){
   successivo = NULL;
};

NodoPtr::NodoPtr(elemCoda a, posizione p): NodoCoda(a){
   successivo = p;
};

NodoPtr::~NodoPtr(){};
   
posizione NodoPtr::getSuccessivo(){
   return successivo;
};

void NodoPtr::setSuccessivo(posizione p){
   successivo = p;     
};
