#include <iostream>
#include <cstdlib>
#include "NodoStr.h"

NodoStr::NodoStr(){
   etichetta.chiave = "\0";
   etichetta.attributo.num = 0;
   successivo = NULL;
};

NodoStr::NodoStr(tipoelem a){
   etichetta = a;
   successivo = NULL;
};

NodoStr::NodoStr(tipoelem a, posizione p){
   etichetta = a;
   successivo = p;
};

NodoStr::~NodoStr(){};

tipoelem NodoStr::getEtichetta(){
	return etichetta;
};

void NodoStr::setEtichetta(tipoelem a){
   etichetta = a;  
}  
 
posizione NodoStr::getSuccessivo(){
   return successivo;
};

void NodoStr::setSuccessivo(posizione p){
   successivo = p;     
};
