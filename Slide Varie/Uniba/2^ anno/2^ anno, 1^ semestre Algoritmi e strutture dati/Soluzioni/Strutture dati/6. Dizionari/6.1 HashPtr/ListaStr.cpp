#include <iostream>
#include <cstdlib>
#include "ListaStr.h"

ListaStr::ListaStr(){
   creaLista();
};
 
ListaStr::~ListaStr(){
   posizione q;
   while (primo != NULL){
      q = primo;
      primo = primo->getSuccessivo();
      delete q;
   }
};
   
void ListaStr::creaLista(){
   primo = NULL;
};
   
bool ListaStr::listaVuota(){
   return (primo == NULL);
};

posizione ListaStr::primoLista(){
   return primo;
};
   
posizione ListaStr::predLista(posizione p){
   if (p == primo){
      return NULL;
   } else {
      posizione q = primo;
      while (q->getSuccessivo() != p){
         q = q->getSuccessivo();
      }
      return q;
   }
};

posizione ListaStr::succLista(posizione p){
   if (p != NULL) return p->getSuccessivo();      
   else return NULL;
};

bool ListaStr::fineLista(posizione p){
   return (p == NULL);
};
   
void ListaStr::insLista(tipoelem a, posizione p){
   posizione q = new NodoStr(a, p);
   if (p == primo)
      primo = q;
   else {
      p = predLista(p);
      p->setSuccessivo(q);
   }
}

bool ListaStr::cancLista(posizione p){
   if ((primo != NULL)&&(p != NULL)){
      if (p!=primo){
         posizione q = predLista(p);
         q->setSuccessivo(p->getSuccessivo());
      } else
         primo = primo->getSuccessivo();
      delete p;
      return true;
   } else return false;
};

bool ListaStr::scriviLista(tipoelem a, posizione p){
   if ((primo != NULL)&&(p != NULL)){
      p->setEtichetta(a);
      return true;
   } else return false;
}

bool ListaStr::leggiLista(tipoelem &a, posizione p){
   if ((primo != NULL)&&(p != NULL)){
      a = p->getEtichetta();
      return true;
   } else return false;
}
 
ListaStr &ListaStr::operator=(ListaStr &l){
	posizione p;
	while (primo != NULL){
      	p = primo;
      	primo = primo->getSuccessivo();
    	delete p;
   	}
	p = l.primoLista();
	tipoelem a;
	while (!l.fineLista(p)){
		l.leggiLista(a,p);
		insLista(a, NULL);
		p = l.succLista(p);
	}
	return *this;
}
  
posizione ListaStr::pos(int n){
   posizione p = primo;
   int i = 1;
   while ((p != NULL)&&(i < n)){
      p = p->getSuccessivo();
      i++;
   }
   return p;
}
