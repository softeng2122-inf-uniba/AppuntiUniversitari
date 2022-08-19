#include <iostream>
#include <cstdlib>
#include "NAlbero.h"

NAlbero::NAlbero(){
   creaNAlbero();
}

NAlbero::~NAlbero(){
   cancSottoAlbero(root);
}

void NAlbero::creaNAlbero(){
   	root = NIL;
   	primoVuoto = 0; //prima posizione libera nel vettore spazio
   	for(int i = 0; i < MAXLUNG-1; i++)
   		spazio[i].setNextBro(i+1);
   	spazio[MAXLUNG-1].setNextBro(NIL); // l'ultimo elemento punta a NIL
}

bool NAlbero::nAlberoVuoto(){
   return (root == NIL);
}

bool NAlbero::insRadice(nodoN n){
   	if (root == NIL){
   		if ((n >= 0)&&(n < MAXLUNG)){
      		root = n;
   			primoVuoto = spazio[n].getNextBro();
    		spazio[n].setNextBro(NIL); // elimina il vecchio collegamento della lista dei liberi
      		return true;
   		} else return false;
   	} else return false;
}

nodoN NAlbero::radice(){
	return root; //se l'albero è vuoto, ritorna NIL
}

nodoN NAlbero::padre(nodoN n){
	if ((n >= 0)&&(n < MAXLUNG)){
		return spazio[n].getDaddy(); //se n è la radice, ritorna NIL
	} else return NIL;
}

bool NAlbero::foglia(nodoN n){
	if ((n >= 0)&&(n < MAXLUNG)){
   		return (spazio[n].getFirstSon() == NIL);
	}else return NIL;
}

nodoN NAlbero::primoFiglio(nodoN n){
	if ((n >= 0)&&(n < MAXLUNG)){
		return spazio[n].getFirstSon(); //se n non ha figli, ritorna NIL
	} else return NIL;
}

bool NAlbero::ultimoFratello(nodoN n){
	if ((n >= 0)&&(n < MAXLUNG)){
		return (spazio[n].getNextBro() == NIL);
	}else return NIL;
}

nodoN NAlbero::succFratello(nodoN n){
	if ((n >= 0)&&(n < MAXLUNG)){
   		return spazio[n].getNextBro(); //se n è ultimo fratello, ritorna NIL
	}else return NIL;
}

bool NAlbero::insPrimoSottoAlbero(nodoN n, nodoN r){
	if(primoVuoto != NIL)
		if ((root != NIL) && (r != NIL) && (n != NIL)){			
			if ((n >= 0)&&(n < MAXLUNG)&&(r >= 0)&&(r < MAXLUNG)){
   				primoVuoto = spazio[r].getNextBro(); // aggiorna la lista dei liberi
				spazio[r].setNextBro(spazio[n].getFirstSon());
  				spazio[r].setDaddy(n);
   				spazio[n].setFirstSon(r);
   				return true;
			}else return false;
		} else return false;
	else return false;
}

bool NAlbero::insSottoAlbero(nodoN n, nodoN r){
	if(primoVuoto != NIL)
		if ((root!=NIL) && (r!=NIL) && (n!=NIL) && (n!=root)){
			if ((n >= 0)&&(n < MAXLUNG)&&(r >= 0)&&(r < MAXLUNG)){
   				primoVuoto = spazio[r].getNextBro(); // aggiorna la lista dei liberi
				spazio[r].setDaddy(spazio[n].getDaddy());
				spazio[r].setNextBro(spazio[n].getNextBro());
				spazio[n].setNextBro(r);
				return true;
			}else return false;
		}else return false;
	else return false;
}

bool NAlbero::cancSottoAlbero(nodoN n){
   	if ((n!=NIL) && (root!=NIL)){
      	while (spazio[n].getFirstSon()!=NIL)
         	cancSottoAlbero(spazio[n].getFirstSon());
      	if (spazio[n].getDaddy()!=NIL){
      		nodoN padre = spazio[n].getDaddy();
         	if (spazio[padre].getFirstSon() == n)
           	 	spazio[padre].setFirstSon(spazio[n].getNextBro());
         	else{
            	nodoN m = spazio[padre].getFirstSon();
            	while (spazio[m].getNextBro() != n)
               		m = spazio[m].getNextBro();
            	spazio[m].setNextBro(spazio[n].getNextBro());
         	}
      	} else {
      		root = NIL;
      	}
      	// riassegna il nodo alle risorse disponibili
      	spazio[n].setNextBro(primoVuoto);
      	primoVuoto = n;
		return true;
	} else return false;
}

tipoelem NAlbero::leggiNodo(nodoN n){
	return spazio[n].getEtichetta();	
}

bool NAlbero::scriviNodo(nodoN n, tipoelem a){
	if(n!=NIL){
		spazio[n].setEtichetta(a);	
		return true;
	}else return false;
}

nodoN NAlbero::newNodo(){
	return primoVuoto;
}

