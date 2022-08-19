#include <iostream>
#include <cstdlib>
#include "BinAlberoCur.h"

BinAlberoCur::BinAlberoCur(){ 
	creaBinAlbero();
}

BinAlberoCur::~BinAlberoCur(){
	cancSottoBinAlbero(primo);
}

void BinAlberoCur::creaBinAlbero(){ 
	primo = NIL;
   totNodi = 0;
   primoVuoto = 0;
   for (int i = 0; i < MAXLUNG-1; i++){
      spazio[i].setSx(i+1);
      spazio[i].setDx(NIL);
      spazio[i].setDaddy(NIL);
   }
   spazio[MAXLUNG-1].setSx(NIL);
}

bool BinAlberoCur::binAlberoVuoto(){ 
	return totNodi == 0;
}	
	
nodoBin BinAlberoCur::binRadice(){ 
	return primo;
}

nodoBin BinAlberoCur::binPadre(nodoBin p){
	return spazio[p].getDaddy();
}

nodoBin BinAlberoCur::figlioSx(nodoBin p){ 
	return spazio[p].getSx();
}

nodoBin BinAlberoCur::figlioDx(nodoBin p){ 
	return spazio[p].getDx();
}

bool BinAlberoCur::sxVuoto(nodoBin p){
	return (spazio[p].getSx() == NIL);
}

bool BinAlberoCur::dxVuoto(nodoBin p){
	return (spazio[p].getDx() == NIL);
}	

bool BinAlberoCur::insBinRadice(nodoBin p){
   if (primo == NIL){
      primo = primoVuoto;
      primoVuoto = spazio[primoVuoto].getSx();
      spazio[primo].setDaddy(NIL);
      spazio[primo].setSx(NIL);
      spazio[primo].setDx(NIL);
      totNodi++;
      return true;
   } else return false;
}
   

bool BinAlberoCur::insFiglioSx(nodoBin p){
   if (primo != NIL && p!= NIL && spazio[p].getSx() == NIL && totNodi < MAXLUNG){
		nodoBin q = primoVuoto;
		primoVuoto = spazio[primoVuoto].getSx();
		spazio[p].setSx(q);
		spazio[q].setDaddy(p);
		spazio[q].setSx(NIL);
		spazio[q].setDx(NIL);
		totNodi++;
		return true;
	} else return false;
}

bool BinAlberoCur::insFiglioDx(nodoBin p){
	if (primo != NIL && p!= NIL && spazio[p].getDx() == NIL && totNodi < MAXLUNG){
		nodoBin q = primoVuoto;
		primoVuoto = spazio[primoVuoto].getSx();
		spazio[p].setDx(q);
		spazio[q].setDaddy(p);
		spazio[q].setSx(NIL);
		spazio[q].setDx(NIL);
		totNodi++;
		return true;
	} else return false;
}

void BinAlberoCur::cancSottoBinAlbero(nodoBin p){
	if (p != NIL){
		if (!sxVuoto(p)){
			cancSottoBinAlbero(spazio[p].getSx());
		}
		if (!dxVuoto(p)){
			cancSottoBinAlbero(spazio[p].getDx());
		}
		if (p != primo){
			nodoBin q = spazio[p].getDaddy();
     		if (spazio[q].getSx() == p){
	    		spazio[q].setSx(NIL);
		    } else {
			    spazio[q].setDx(NIL);
		   	}
		} else primo = NIL;
		totNodi--;
		spazio[p].setSx(primoVuoto);
      primoVuoto = p;
	}	
}
	
bool BinAlberoCur::leggiNodo(nodoBin p, tipoelem &a){
	if (p != NIL){
		a = spazio[p].getEtichetta();
		return true;
	} else return false;
}

bool BinAlberoCur::scriviNodo(nodoBin p, tipoelem a){
	if (p != NIL){
		spazio[p].setEtichetta(a);
		return true;
	} else return false;
}

nodoBin BinAlberoCur::pos(int n){
   nodoBin p = primo;
   if (n <= 0)
      p = NIL;
   else{
      int i = 1;
      while ((p != NIL)&&(i < n)){
         p = spazio[p].getSx();
         i++;
      }
   }
   return p;
};
