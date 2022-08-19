#include <iostream>
#include <cstdlib>
#include "Nodo.h"

//template <class tipoelem>
Nodo/*<tipoelem>*/::Nodo(){
   etichetta = 0;
};

//template <class tipoelem>
Nodo/*<tipoelem>*/::Nodo(tipoelem a){
   etichetta = a;
};

//template <class tipoelem>
Nodo/*<tipoelem>*/::~Nodo(){};

//template <class tipoelem>
tipoelem Nodo/*<tipoelem>*/::getEtichetta(){
   return etichetta;
};

//template <class tipoelem>
void Nodo/*<tipoelem>*/::setEtichetta(tipoelem a){
   etichetta = a;     
};
