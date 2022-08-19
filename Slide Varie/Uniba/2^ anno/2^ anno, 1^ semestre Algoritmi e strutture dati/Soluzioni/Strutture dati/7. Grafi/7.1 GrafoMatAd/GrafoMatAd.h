/*
  Nome: GrafoMatAd.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa il grafo con matrice di adiacenza
*/


#ifndef GRAFOMATAD_H
#define GRAFOMATAD_H
#define MAXNODI 20
#include <iostream>
#include "ListaAdiacenti.h"

typedef int Nodo;
struct tipoNodi{
   bool esiste, visitato;
};

class GrafoMatAd{
public:
	GrafoMatAd();
	~GrafoMatAd();
	
	void creaGrafo();
	bool grafoVuoto();
	bool esisteNodo(Nodo);
	bool esisteArco(Nodo, Nodo);
	void insNodo(Nodo);
	bool insArco(Nodo, Nodo);
	bool cancNodo(Nodo);
	bool cancArco(Nodo, Nodo);
	void adiacenti(Nodo, ListaAdiacenti &);
	
	bool getVisitato(Nodo);
	void setVisitato(bool, Nodo);
	
	void azzeraVisitato();

private:
   tipoNodi nodi[MAXNODI];
   bool grafo[MAXNODI][MAXNODI];
};

#endif

