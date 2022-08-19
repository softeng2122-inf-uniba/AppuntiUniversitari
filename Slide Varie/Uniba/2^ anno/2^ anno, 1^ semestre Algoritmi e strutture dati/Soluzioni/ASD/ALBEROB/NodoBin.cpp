//IMPLEMENTAZIONE DELLA CLASSE NODO DELL'ALBERO BINARIO
#include "NodoBin.h"

NodoBin::NodoBin(){sx=dx=padre=0;};
NodoBin::~NodoBin(){};

void NodoBin::setelem(tipoelem e)
{this->elem=e; return;};

void NodoBin::setsx(cellap p)
{this->sx=p; return;};

void NodoBin::setdx(cellap p)
{this->dx=p; return;};

void NodoBin::setpadre(cellap p)
{this->padre=p; return;};

tipoelem NodoBin::getelem()
{return this->elem;};

cellap NodoBin::getsx()
{return this->sx;};

cellap NodoBin::getdx()
{return this->dx;};

cellap NodoBin::getpadre()
{return this->padre;};