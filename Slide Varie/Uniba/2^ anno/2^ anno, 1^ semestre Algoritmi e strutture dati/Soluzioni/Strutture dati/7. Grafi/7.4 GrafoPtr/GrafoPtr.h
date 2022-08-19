/*
  Nome: GrafoPtr.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa il grafo con lista di liste
               COMPRENDE 4 CLASSI:
               -  class NodoAdiacenti
                  Classe che implementa il nodo della lista di adiacenza								
               -  class ListaAdiacenti
                  Classe che implementa la lista di adiacenza
               -  class NodoGrafoPtr
                  Classe che implementa il nodo del grafo con puntatore
               -  class GrafoPtr
                  Classe che implementa il grafo con puntatore
*/

#ifndef GRAFOPTR_H
#define GRAFOPTR_H

#include <string>
#include <cstdlib>

#define NIL -1

typedef struct tipo tipoelem;
typedef int tipoPeso;
typedef std::string label;

//*******classi definite in questo file: ***********
class NodoAdiacenti;								
class ListaAdiacenti;
class NodoGrafoPtr;
class GrafoPtr;
//**************************************************


typedef NodoAdiacenti *NodoAd;
typedef NodoGrafoPtr *NodoGrafo;

//definizione della classe NodoAdiacenti
class NodoAdiacenti { // NodoPtr estende Nodo
public:
   NodoAdiacenti(); // costruttore standard
   ~NodoAdiacenti(); // distruttore

   void setPtrNodo(NodoGrafo);
   NodoGrafo getPtrNodo();
   void setPeso(tipoPeso);
   tipoPeso getPeso();
   
   NodoAd getSuccessivo();
   void setSuccessivo(NodoAd);
   
private:
   NodoGrafo ptrNodo;
   tipoPeso peso;
   NodoAd successivo;
};

//lista dei nodi adiacenti di un nodo
class ListaAdiacenti{
public:
	ListaAdiacenti();
	~ListaAdiacenti();
	
	void creaLista();
  	bool listaVuota();
  	NodoAd primoLista();
  
  	NodoAd predLista(NodoAd);
  	NodoAd succLista(NodoAd);
  	bool fineLista(NodoAd);
  
  	void insLista(NodoGrafo, tipoPeso, NodoAd);
  	bool cancLista(NodoAd);
  	bool scriviLista(NodoGrafo, tipoPeso, NodoAd);
  	bool leggiLista(NodoGrafo &, tipoPeso &, NodoAd);
  
	ListaAdiacenti &operator=(ListaAdiacenti &);
  	NodoAd pos(int); // mapping della NodoAd

private:
   NodoAd primo;
};

//definizione della classe NodoGrafoPtr
class NodoGrafoPtr {
public:
   NodoGrafoPtr(); // costruttore standard
   ~NodoGrafoPtr(); // distruttore
   
   void setLabelNodo(label);
   label getLabelNodo();
   void setVisitato(bool);
   bool getVisitato();
   void setAdiacenti(ListaAdiacenti &);   
   void getAdiacenti(ListaAdiacenti &);
   
   NodoGrafo getSuccessivo();
   void setSuccessivo(NodoGrafo);
   
private:
	label labelNodo;
	bool visitato;
	ListaAdiacenti adiacenti;
   NodoGrafo successivo;
};

// grafo
class GrafoPtr{
public:
	GrafoPtr();
	~GrafoPtr();
	
	void creaGrafo();
	bool grafoVuoto();
	bool esisteNodo(NodoGrafo);
	bool esisteArco(NodoGrafo, NodoGrafo);
	bool insNodo(NodoGrafo);
	bool insArco(NodoGrafo, NodoGrafo);
	bool cancNodo(NodoGrafo);
	bool cancArco(NodoGrafo, NodoGrafo);
	void adiacenti(NodoGrafo, ListaAdiacenti &);
	bool scriviNodo(NodoGrafo, label);
	bool leggiNodo(NodoGrafo, label &);  
	bool scriviArco(NodoGrafo, NodoGrafo, tipoPeso);
	bool leggiArco(NodoGrafo, NodoGrafo, tipoPeso &);
	
	bool getVisitato(NodoGrafo);
	void setVisitato(bool, NodoGrafo);
	NodoGrafo getGrafo();
	
	NodoGrafo pos(label);
	void azzeraVisitato();
	GrafoPtr &operator=(GrafoPtr &);

private:
	NodoGrafo grafo;
};

#endif
