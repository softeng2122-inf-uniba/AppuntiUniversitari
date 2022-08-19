#include <iostream>
#include <cstdlib>
#include "NodoBinCur.h"

NodoBinCur::NodoBinCur(): Nodo(0){
   sx = dx = daddy = NIL;
}

NodoBinCur::NodoBinCur(tipoelem a): Nodo(a){
   sx = dx = daddy = NIL;
}
NodoBinCur::NodoBinCur(tipoelem a, nodoBin s, nodoBin d, nodoBin p): Nodo(a){
   sx = s;
   dx = d;
   daddy = p;
}

NodoBinCur::~NodoBinCur(){}
   
nodoBin NodoBinCur::getSx(){
   return sx;
}

nodoBin NodoBinCur::getDx(){
   return dx;
}

nodoBin NodoBinCur::getDaddy(){
   return daddy;
}

void NodoBinCur::setSx(nodoBin s){
   sx = s;
}

void NodoBinCur::setDx(nodoBin d){
	dx = d;
}

void NodoBinCur::setDaddy(nodoBin p){
	daddy = p;
}

