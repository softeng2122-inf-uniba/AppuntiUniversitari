#include "./NodoCoda.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

NodoCoda::NodoCoda()
{
    this->next=0;
    return;
}

NodoCoda::~NodoCoda(){

}

NodoCoda* NodoCoda:: getNext()
{
    return this->next;
}

cellap NodoCoda::getElem(){
    return this->nodo;
}

void NodoCoda::setElem(cellap e){
    this->nodo=e;
    return;
}

void NodoCoda::setNext(posizione p){
    this->next=p;
    return;
}
