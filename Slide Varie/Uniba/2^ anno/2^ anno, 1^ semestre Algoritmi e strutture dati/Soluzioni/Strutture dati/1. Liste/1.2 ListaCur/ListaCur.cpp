#include <iostream>
#include <cstdlib>
#include "ListaCur.h"

ListaCur::ListaCur(){
   creaLista();
};
                      
ListaCur::~ListaCur(){};
   
void ListaCur::creaLista(){
   primo = NIL;
   lunghezza = 0;
   primoVuoto = 0;
   for (int i = 0; i < MAXLUNG-1; i++){
      spazio[i].setSuccessivo(i+1);
   }
   spazio[MAXLUNG-1].setSuccessivo(NIL);      
};

bool ListaCur::listaVuota(){
   return (lunghezza == 0);
};

posizione ListaCur::primoLista(){
   return primo;
};
   
posizione ListaCur::predLista(posizione p){
   posizione temp = primo;
   while (spazio[temp].getSuccessivo() != p)
      temp = spazio[temp].getSuccessivo();
   return temp;
};

posizione ListaCur::succLista(posizione p){
   return spazio[p].getSuccessivo();
};

bool ListaCur::fineLista(posizione p){
   return p == NIL;
};
   
bool ListaCur::insLista(tipoelem a, posizione p){
   if (primoVuoto != NIL){
      if (p == primo){ //inserimento in testa
         spostaNodo(primoVuoto, p);
         spazio[p].setEtichetta(a);
         primo = p;
      } else{ //inserimento in mezzo o in coda
         posizione q = predLista(p); //ultimo lista (p == NIL)
         spostaNodo(primoVuoto, p);
         spazio[p].setEtichetta(a);
         spazio[q].setSuccessivo(p);
      }
      lunghezza++;
      return true;
   } else return false; // inserimento fallito (lista piena)            
};

bool ListaCur::cancLista(posizione p){
   if ((lunghezza > 0)&&(p != NIL)) {
      if (p != primo){
         spazio[predLista(p)].setSuccessivo(spazio[p].getSuccessivo());
      }
      spostaNodo(p, primoVuoto);
      lunghezza--;
      return true;
   } else return false; // posizione non valida o lista vuota
};

bool ListaCur::scriviLista(tipoelem a, posizione p){
   if ((lunghezza > 0)&&(p != NIL)) {
      spazio[p].setEtichetta(a);
      return true;
   } else return false;
};

bool ListaCur::leggiLista(tipoelem &a, posizione p){
   if ((lunghezza > 0)&&(p != NIL)) {
      a = spazio[p].getEtichetta();
      return true;
   } else return false;
};

void ListaCur::spostaNodo(posizione &da, posizione &a){
   posizione temp = spazio[da].getSuccessivo();
   spazio[da].setSuccessivo(a);
   a = da;
   da = temp;
};

posizione ListaCur::pos(int n){
   posizione p = primo;
   if (n <= 0)
      p = NIL;
   else{
      int i = 1;
      while ((p != NIL)&&(i < n)){
         p = spazio[p].getSuccessivo();
         i++;
      }
   }
   return p;
};

