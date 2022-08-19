/*
  Nome: GrafoMatAdExt.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa il grafo con matrice di adiacenza estesa
*/

#ifndef GRAFOMATADEXT_H
#define GRAFOMATADEXT_H
#define MAXNODI 20
#include <iostream>
#include "ListaAdiacenti.h"

typedef int Nodo;
typedef std::string tipolabel;
struct tipoNodi{
   tipolabel label;
   int archi;
   bool esiste, visitato;
};

class GrafoMatAdExt{
public:
	GrafoMatAdExt();
	~GrafoMatAdExt();
	
	void creaGrafo();
	bool grafoVuoto();
	bool esisteNodo(Nodo);
	bool esisteArco(Nodo, Nodo);
	bool insNodo(Nodo, tipolabel);
	bool insArco(Nodo, Nodo);
	bool cancNodo(Nodo);
	bool cancArco(Nodo, Nodo);
	void adiacenti(Nodo, ListaAdiacenti &);
	
	bool getVisitato(Nodo);
	void setVisitato(bool, Nodo);
	bool getLabel(Nodo, tipolabel &);
	bool setLabel(Nodo, tipolabel);
	bool getArchi(Nodo, int &);
	
	void azzeraVisitato();

private:
   tipoNodi nodi[MAXNODI];
   bool grafo[MAXNODI][MAXNODI];
};

#endif

