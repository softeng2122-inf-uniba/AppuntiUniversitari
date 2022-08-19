#include "NodoN.h"
#include <iostream.h>

NodoN::NodoN()
{	padre=primof=fratello=0;
	return;
   };

NodoN::~NodoN(){};

void NodoN::setelem(tipoelem e)
{elem=e; return;};

void NodoN::setpadre(NodoN* p)
{padre=p; return;};

void NodoN::setprimof(NodoN* p)
{primof=p; return;};

void NodoN::setfratello(NodoN* p)
{fratello=p; return;};

tipoelem NodoN::getelem()
{return this->elem;};

NodoN* NodoN::getpadre()
{return this->padre;};

NodoN* NodoN::getprimof()
{return this->primof;};

NodoN* NodoN::getfratello()
{return this->fratello;};