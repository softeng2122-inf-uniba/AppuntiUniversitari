#include "./NodoBinario.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

NodoBinario::NodoBinario(){
    sx=dx=padre=0;
}

NodoBinario::~NodoBinario(){

}

void NodoBinario::setelem(tipoelem e){
    this->elem=e;
    return;
}

void NodoBinario::setsx(cellap p)
{
    this->sx=p;
    return;
}

void NodoBinario::setdx(cellap p)
{
    this->dx=p;
    return;
}

void NodoBinario::setpadre(cellap p)
{
    this->padre=p;
    return;
}

tipoelem NodoBinario::getelem()
{
    return this->elem;
}

NodoBinario* NodoBinario::getdx()
{
    return this->dx;
}

NodoBinario* NodoBinario::getsx()
{
    return this->sx;
}

NodoBinario* NodoBinario::getpadre()
{
    return this->padre;
}
