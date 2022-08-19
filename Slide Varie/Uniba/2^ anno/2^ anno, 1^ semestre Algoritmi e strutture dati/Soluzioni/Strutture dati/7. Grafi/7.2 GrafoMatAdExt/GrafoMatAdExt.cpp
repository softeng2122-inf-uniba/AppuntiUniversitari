#include <iostream>
#include <cstdlib>
#include "GrafoMatAdExt.h"

GrafoMatAdExt::GrafoMatAdExt(){
   creaGrafo();
}

GrafoMatAdExt::~GrafoMatAdExt(){}
	
void GrafoMatAdExt::creaGrafo(){
   for (int i = 0; i < MAXNODI; i++){
      nodi[i].label = "";
      nodi[i].archi = 0;
      nodi[i].esiste = false;
      nodi[i].visitato = false;
      for (int j = 0; j < MAXNODI; j++)
         grafo[i][j] = false;
   }
}

bool GrafoMatAdExt::grafoVuoto(){
   bool vuoto = true;
   int i = 0;
   while ((i < MAXNODI) && (vuoto)){
      if (nodi[i].esiste == true)
         vuoto = false;
      else
         i++;
   }
   return vuoto; 
}

bool GrafoMatAdExt::esisteNodo(Nodo i){
   return (nodi[i].esiste == true);
}

bool GrafoMatAdExt::esisteArco(Nodo i, Nodo j){
   return (grafo[i][j] == true);
}

bool GrafoMatAdExt::insNodo(Nodo i, tipolabel a){
   if (!nodi[i].esiste){
      nodi[i].esiste = true;
      nodi[i].label = a;
      return true;
   } else return false;
}

bool GrafoMatAdExt::insArco(Nodo i, Nodo j){
   if (!grafo[i][j]){
      grafo[i][j] = true;
      nodi[i].archi++;
      nodi[j].archi++;
      return true;
   } else return false;
}

bool GrafoMatAdExt::cancNodo(Nodo i){
   if (nodi[i].esiste){
      nodi[i].esiste = false;
      return true;
   } else return false;
}

bool GrafoMatAdExt::cancArco(Nodo i, Nodo j){
   if (grafo[i][j]){
      grafo[i][j] = false;
      nodi[i].archi--;
      nodi[j].archi--;
      return true;
   } else return false;
}

void GrafoMatAdExt::adiacenti(Nodo i, ListaAdiacenti &l){
   for (int j = 0; j < MAXNODI; j++)
      if (grafo[i][j])
         l.insLista(j, l.primoLista());
}

bool GrafoMatAdExt::getVisitato(Nodo i){
   return nodi[i].visitato;
}

void GrafoMatAdExt::setVisitato(bool b, Nodo i){
   nodi[i].visitato = b;
}

bool GrafoMatAdExt::getLabel(Nodo i, tipolabel &k){
   if (nodi[i].esiste){
      k = nodi[i].label;
      return true;
   } else return false;
}

bool GrafoMatAdExt::setLabel(Nodo i, tipolabel k){
   if (nodi[i].esiste){
      nodi[i].label = k;
      return true;
   } else return false;
}

bool GrafoMatAdExt::getArchi(Nodo i, int &a){
   if (nodi[i].esiste){
      a = nodi[i].archi;
      return true;
   } else return false;
}

void GrafoMatAdExt::azzeraVisitato(){
   for (int i = 0; i < MAXNODI; i++)
      nodi[i].visitato = false;
}
