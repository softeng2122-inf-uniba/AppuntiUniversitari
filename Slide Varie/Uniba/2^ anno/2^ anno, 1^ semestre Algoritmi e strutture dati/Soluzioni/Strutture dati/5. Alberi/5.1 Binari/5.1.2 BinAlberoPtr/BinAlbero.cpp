#include "BinAlbero.h"
#include <iostream>

BinAlbero::BinAlbero(){
	creaBinAlbero();
}
BinAlbero::~BinAlbero(){
	cancSottoBinAlbero(radice);
}


void BinAlbero::creaBinAlbero(){
	radice = NULL;
}

bool BinAlbero::binAlberoVuoto(){
	return radice == NULL;
}	
	
nodoBin BinAlbero::binRadice(){
	return radice;
}

nodoBin BinAlbero::binPadre(nodoBin p){
	return p->getDaddy(); //se p = radice ritorna NULL
}

nodoBin BinAlbero::figlioSx(nodoBin p){
	return p->getSx(); // se p non ha figlio sx ritorna NULL
}

nodoBin BinAlbero::figlioDx(nodoBin p){
	return p->getDx(); // come sopra
}

bool BinAlbero::sxVuoto(nodoBin p){
	return (p->getSx() == NULL);
}

bool BinAlbero::dxVuoto(nodoBin p){
	return (p->getDx() == NULL);
}	

bool BinAlbero::insBinRadice(nodoBin p){
	if (radice == NULL){
		radice = p;
		radice->setDaddy(NULL);
		radice->setSx(NULL);
		radice->setDx(NULL);
		return true;
	} else return false;
}

bool BinAlbero::insFiglioSx(nodoBin p){
	if (radice != NULL && p!= NULL && p->getSx() == NULL){
		nodoBin q = new NodoBinPtr();
		p->setSx(q);
		q->setDaddy(p);
		return true;
	} else return false;
}

bool BinAlbero::insFiglioDx(nodoBin p){
	if (radice != NULL && p!= NULL && p->getDx() == NULL){
		nodoBin q = new NodoBinPtr();
		p->setDx(q);
		q->setDaddy(p);
		return true;
	} else return false;
}
	
void BinAlbero::cancSottoBinAlbero(nodoBin p){
	if (p != NULL){
		if (!sxVuoto(p))
         cancSottoBinAlbero(p->getSx());
		if (!dxVuoto(p))
			cancSottoBinAlbero(p->getDx());
		if (p != radice){
			nodoBin q = p->getDaddy();
     		if (q->getSx() == p)
	    		q->setSx(NULL);
		   else
			   q->setDx(NULL);
		} else radice = NULL;
		std::cout << "Cancellato: " << p->getEtichetta() << std::endl;
		delete p;
	}	
}
	
bool BinAlbero::leggiNodo(nodoBin p, tipoelem &a){
	if (p != NULL){
		a = p->getEtichetta();
		return true;
	} else return false;
}

bool BinAlbero::scriviNodo(nodoBin p, tipoelem a){
	if (p != NULL){
		p->setEtichetta(a);
		return true;
	} else return false;
}

