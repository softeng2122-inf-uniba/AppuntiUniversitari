/*
  Nome: ListaAdiacenti.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa la lista di adiacenza dei nodi
*/

#ifndef LISTAADIACENTI_H
#define LISTAADIACENTI_H

#define NIL -1

typedef struct NodoAdiacenti *posizione;
typedef struct tipo tipoelem;
typedef int Nodo;
typedef int tipoPeso;

struct NodoAdiacenti{
	Nodo etichetta;
	posizione successivo;
};

class ListaAdiacenti{
public:
	ListaAdiacenti();
	~ListaAdiacenti();
	
	void creaLista();
   bool listaVuota();
   posizione primoLista();
   	
   posizione predLista(posizione);
   posizione succLista(posizione);
   bool fineLista(posizione);
   
   void insLista(Nodo, posizione);
   bool cancLista(posizione);
   bool scriviLista(Nodo, posizione);
   bool leggiLista(Nodo &, posizione);
   
	ListaAdiacenti &operator=(ListaAdiacenti &);
   posizione pos(int); // mapping della posizione

private:
   posizione primo;
};

#endif // LISTAADIACENTI_H
