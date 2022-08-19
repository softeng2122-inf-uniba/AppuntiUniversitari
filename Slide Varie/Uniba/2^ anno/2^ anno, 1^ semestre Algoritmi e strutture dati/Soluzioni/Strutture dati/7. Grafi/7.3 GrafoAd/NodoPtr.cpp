#include <iostream>
#include <cstdlib>
#include "NodoPtr.h"

NodoPtr::NodoPtr(): NodoCoda(0){
   successivo = 0;
};

NodoPtr::NodoPtr(elemCoda a): NodoCoda(a){
   successivo = NULL;
};

NodoPtr::NodoPtr(elemCoda a, posizioneCoda p): NodoCoda(a){
   successivo = p;
};

NodoPtr::~NodoPtr(){};
   
posizioneCoda NodoPtr::getSuccessivo(){
   return successivo;
};

void NodoPtr::setSuccessivo(posizioneCoda p){
   successivo = p;     
};
