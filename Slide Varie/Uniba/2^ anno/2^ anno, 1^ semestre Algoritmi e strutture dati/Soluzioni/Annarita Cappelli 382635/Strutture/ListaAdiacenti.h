/*
Autore: Annarita Cappelli 
Matricola: 382635
Nome file: ListaAdiacenti.h
Commento: Classe che implementa la lista di adiacenza dei nodi per la classe
GrafoAdiacenti.h
*/

#ifndef LISTAADIACENTI_H
#define LISTAADIACENTI_H

#define NIL -1

#ifndef MAIN_H
#include "main.h"
#endif


typedef int Nodo;
typedef int tipoPeso;


template <class L>
struct NodoAdiacenti {
	 L etichetta;
	 NodoAdiacenti<L> *successivo;
};

template <class L>
class ListaAdiacenti {
      public:
             ListaAdiacenti();  // costruttore
             ~ListaAdiacenti();  // distruttore
             
             // operatori
             void creaLista();
             bool listaVuota();
             NodoAdiacenti<L> *primoLista();
             NodoAdiacenti<L> *predLista(NodoAdiacenti<L> *);
             NodoAdiacenti<L> *succLista(NodoAdiacenti<L> *);
             bool fineLista(NodoAdiacenti<L> *);
             void insLista(L, NodoAdiacenti<L> *);
             bool cancLista(NodoAdiacenti<L> *);
             bool scriviLista(L, NodoAdiacenti<L> *);
             bool leggiLista(L &, NodoAdiacenti<L> *);
             ListaAdiacenti<L> &operator=(ListaAdiacenti<L> &);
             NodoAdiacenti<L> *pos(int); // mapping della posizione
      private:
              NodoAdiacenti<L> *primo;
};

template <class L>
ListaAdiacenti<L>::ListaAdiacenti() {
	 creaLista();
};

template <class L>
ListaAdiacenti<L>::~ListaAdiacenti() {
	 NodoAdiacenti<L> *q;
	 while(primo!= NULL) {
		q = primo->successivo;
		delete primo;
		primo = q;
	 }
};

template <class L>
void ListaAdiacenti<L>::creaLista() {
	 primo = NULL;
};

template <class L>
bool ListaAdiacenti<L>::listaVuota() {
	 return (primo == NULL);
};

template <class L>
NodoAdiacenti<L> *ListaAdiacenti<L>::primoLista() {
	 return primo;
};

template <class L>
NodoAdiacenti<L> *ListaAdiacenti<L>::predLista(NodoAdiacenti<L> *p) {
	 if(p!=primo) {
		NodoAdiacenti<L> *q = primo;
		while ((q->successivo!=p)&&(q!=NULL))
		   q = q->successivo;
		return q;
	 } else 
        return NULL;
};

template <class L>
NodoAdiacenti<L> *ListaAdiacenti<L>::succLista(NodoAdiacenti<L> *p) {
	 return p->successivo;
};

template <class L>
bool ListaAdiacenti<L>::fineLista(NodoAdiacenti<L> *p) {
	 return (p==NULL);
};

template <class L>
void ListaAdiacenti<L>::insLista(L a, NodoAdiacenti<L> *p) {
	 NodoAdiacenti<L> *q = new (NodoAdiacenti<L>);
	 q->etichetta = a;
	 q->successivo = p; 
	 if (p==primo) {
		primo = q;
	 } else {
		p = predLista(p);
		p->successivo = q;
	 }
};

template <class L>
bool ListaAdiacenti<L>::cancLista(NodoAdiacenti<L> *p) {
	 if (p!=NULL) {
		if(p==primo) {
		   primo = p->successivo;
		} else {
		   NodoAdiacenti<L> *q;
		   q = predLista(p);
		   q->successivo = p->successivo;
		}
		delete p;
		return true;
	 } else return false; //ERRORE!	
};

template <class L>
bool ListaAdiacenti<L>::scriviLista(L a, NodoAdiacenti<L> *p) {
	 if(p!=NULL) {
		p->etichetta = a;
		return true;
	 } else return false; //ERRORE!
};

template <class L>
bool ListaAdiacenti<L>::leggiLista(L &a, NodoAdiacenti<L> *p) {
	 if(p!=NULL) {
		a = p->etichetta;
		return true;
	 } else return false; //ERRORE!
};

template <class L>
ListaAdiacenti<L> &ListaAdiacenti<L>::operator=(ListaAdiacenti<L> &l) {
	 NodoAdiacenti<L> *p;
	 while(primo!=NULL) {
		p = primo->successivo;
		delete primo;
		primo = p;
	 }	
	 p = l.primoLista();
	 L a;
	 while (!l.fineLista(p)) {
		l.leggiLista(a,p);
		insLista(a, NULL);
		p = l.succLista(p);
	 }
	 return *this;
};

template <class L>
NodoAdiacenti<L> *ListaAdiacenti<L>::pos(int i) {  // mapping della posizione
	 if(i>=1) {
		NodoAdiacenti<L> *p = primo;
		int j;
		for(j = 0; (j<i)&&(p!=NULL); j++) {
		   p = p->successivo;
		}
		return p;
	 } else {
	 	return NULL;
	 }
};

#endif 
