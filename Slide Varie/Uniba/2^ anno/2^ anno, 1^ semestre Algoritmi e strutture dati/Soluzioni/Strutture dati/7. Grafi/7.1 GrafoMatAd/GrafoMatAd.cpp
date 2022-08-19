#include <iostream>
#include <cstdlib>
#include "GrafoMatAd.h"

GrafoMatAd::GrafoMatAd(){
   creaGrafo();
}

GrafoMatAd::~GrafoMatAd(){}
	
void GrafoMatAd::creaGrafo(){
   for (int i = 0; i < MAXNODI; i++){
      nodi[i].esiste = false;
      nodi[i].visitato = false;
      for (int j = 0; j < MAXNODI; j++)
         grafo[i][j] = false;
   }
}

bool GrafoMatAd::grafoVuoto(){
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

bool GrafoMatAd::esisteNodo(Nodo i){
   return (nodi[i].esiste == true);
}

bool GrafoMatAd::esisteArco(Nodo i, Nodo j){
   return (grafo[i][j] == true);
}

void GrafoMatAd::insNodo(Nodo i){
   nodi[i].esiste = true;
}

bool GrafoMatAd::insArco(Nodo i, Nodo j){
   if (!grafo[i][j]){
      grafo[i][j] = true;
      return true;
   } else return false;
}

bool GrafoMatAd::cancNodo(Nodo i){
   if (nodi[i].esiste){
      nodi[i].esiste = false;
      return true;
   } else return false;
}

bool GrafoMatAd::cancArco(Nodo i, Nodo j){
   if (grafo[i][j]){
      grafo[i][j] = false;
      return true;
   } else return false;
}

void GrafoMatAd::adiacenti(Nodo i, ListaAdiacenti &l){
   for (int j = 0; j < MAXNODI; j++)
      if (grafo[i][j])
         l.insLista(j, l.primoLista());
}

bool GrafoMatAd::getVisitato(Nodo i){
   return nodi[i].visitato;
}

void GrafoMatAd::setVisitato(bool b, Nodo i){
   nodi[i].visitato = b;
}

void GrafoMatAd::azzeraVisitato(){
   for (int i = 0; i < MAXNODI; i++)
      nodi[i].visitato = false;
}

