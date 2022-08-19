#include <iostream>
#include <cstdlib>
#include "NodoNCur.h"

NodoNCur::NodoNCur(): Nodo(){
	daddy = firstSon = nextBro = NIL;
}

NodoNCur::NodoNCur(tipoelem a): Nodo(a){
	daddy = firstSon = nextBro = NIL;
}

NodoNCur::NodoNCur(tipoelem a, nodoN p, nodoN pf, nodoN sf): Nodo(a){
	daddy = p;
	firstSon = pf;
	nextBro = sf;
}

NodoNCur::~NodoNCur(){}
	
nodoN NodoNCur::getFirstSon(){
	return firstSon;
}

nodoN NodoNCur::getNextBro(){
	return nextBro;
}

nodoN NodoNCur::getDaddy(){
	return daddy;
}

void NodoNCur::setFirstSon(nodoN n){
	firstSon = n;
}

void NodoNCur::setNextBro(nodoN n){
   nextBro = n;
}

void NodoNCur::setDaddy(nodoN n){
	daddy = n;
}
