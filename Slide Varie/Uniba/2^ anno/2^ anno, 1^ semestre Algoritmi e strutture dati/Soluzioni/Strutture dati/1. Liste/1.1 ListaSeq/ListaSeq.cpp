#include <iostream>
#include <cstdlib>
#include "ListaSeq.h"

ListaSeq::ListaSeq(){
   creaLista();
};
                      
ListaSeq::~ListaSeq(){};
   
void ListaSeq::creaLista(){
   primo = NIL;
   lunghezza = 0;
};

bool ListaSeq::listaVuota(){
   return (lunghezza == 0);
};

posizione ListaSeq::primoLista(){
   return primo;
};
   
posizione ListaSeq::predLista(posizione p){
   return (p == NIL ? NIL: p-1);
};

posizione ListaSeq::succLista(posizione p){
   return (((p == NIL)||(p == (primo + lunghezza - 1))) ? NIL: p+1);       
};

bool ListaSeq::fineLista(posizione p){
   return p == NIL;
};
   
bool ListaSeq::insLista(tipoelem a, posizione p){
   if (lunghezza < MAXLUNG) {
      if (p == NIL) {
         posizione temp = 0;
         if (primo == NIL) {
            primo = 0; 
         } else {
            temp = primo + lunghezza;
         }
         lista[temp].setEtichetta(a);
      } else {
         for (posizione i = (primo + lunghezza - 1); i >= p; i--){
            lista[i+1]= lista[i]; 
         }
         lista[p].setEtichetta(a);
      }
      lunghezza++;
      return true;
   } else return false;  // lista piena 
};

bool ListaSeq::cancLista(posizione p){
   if ((lunghezza > 0) && (p != NIL)) {
      for (posizione i = p; i < (primo + lunghezza - 1); i++){
         lista[i] = lista[i+1];
      }
      lunghezza--;
      return true;
   } else return false; // posizione non valida o lista vuota
};

bool ListaSeq::scriviLista(tipoelem a, posizione p){
   if ((lunghezza > 0) && (p != NIL)) {
      lista[p].setEtichetta(a);
      return true;
   } else return false;
};

bool ListaSeq::leggiLista(tipoelem &a, posizione p){
   if ((lunghezza > 0)&&(p != NIL)) {
      a = lista[p].getEtichetta();
      return true;
   } else return false;
};

posizione ListaSeq::pos(int p){
   if ((p >= 1) && (p <= primo + lunghezza + 1))
      return p-1;
   else
      return NIL;
}


