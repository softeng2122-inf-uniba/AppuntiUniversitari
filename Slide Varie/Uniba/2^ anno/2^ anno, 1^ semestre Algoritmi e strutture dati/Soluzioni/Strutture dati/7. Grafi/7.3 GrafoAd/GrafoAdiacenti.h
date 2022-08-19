/*
  Nome: GrafoAdiacenti.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa il grafo con liste di adiacenza
*/

#ifndef GRAFOADIACENTI_H
#define GRAFOADIACENTI_H
#define MAXNODI 20

#include <iostream>
#include "ListaAdiacenti.h"

typedef std::string label;

struct NodoGrafo{
	label etichetta;
	bool presente, visitato;
	ListaAdiacenti neighbours;
};

class GrafoAdiacenti{
public:
	GrafoAdiacenti();
	~GrafoAdiacenti();
	
	void creaGrafo();
	bool grafoVuoto();
	bool esisteNodo(Nodo);
	bool esisteArco(Nodo, Nodo);
	bool insNodo(Nodo);
	bool insArco(Nodo, Nodo);
	bool cancNodo(Nodo);
	bool cancArco(Nodo, Nodo);
	void adiacenti(Nodo, ListaAdiacenti &);
	bool scriviNodo(Nodo, label);
	bool leggiNodo(Nodo, label &);  
	bool scriviArco(Nodo, Nodo, tipoPeso);
	bool leggiArco(Nodo, Nodo, tipoPeso &);
	
	bool getVisitato(Nodo);
	void setVisitato(bool, Nodo);
	
	void azzeraVisitato();
	GrafoAdiacenti &operator=(GrafoAdiacenti &);

private:
	NodoGrafo grafo[MAXNODI];
};

#endif // GRAFOADIACENTI_H
