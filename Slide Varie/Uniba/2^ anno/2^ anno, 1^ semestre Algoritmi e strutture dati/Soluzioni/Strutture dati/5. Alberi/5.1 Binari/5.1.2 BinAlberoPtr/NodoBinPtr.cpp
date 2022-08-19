#include "NodoBinPtr.h"
#include <iostream>

NodoBinPtr::NodoBinPtr() : Nodo(){
	sx = dx = daddy = NULL;
}

NodoBinPtr::NodoBinPtr(tipoelem a) : Nodo(a){
	sx = dx = daddy = NULL;   
}

NodoBinPtr::NodoBinPtr(tipoelem a, nodoBin s, nodoBin d) : Nodo(a){
	sx = s;
	dx = d;
	daddy = NULL;
}

NodoBinPtr::~NodoBinPtr(){}

nodoBin NodoBinPtr::getSx(){
	return sx;
}

nodoBin NodoBinPtr::getDx(){
	return dx;
}

nodoBin NodoBinPtr::getDaddy(){
	return daddy;
}

bool NodoBinPtr::setSx(nodoBin s){
	if (sx == NULL || s == NULL){
		sx = s;
		return true;
	}else return false;
}

bool NodoBinPtr::setDx(nodoBin d){
	if (dx == NULL || d == NULL){
		dx = d;
		return true;
	}else return false;
}

bool NodoBinPtr::setDaddy(nodoBin ddd){
	if (daddy == NULL){
		daddy = ddd;
		return true;
	}else return false;
}

