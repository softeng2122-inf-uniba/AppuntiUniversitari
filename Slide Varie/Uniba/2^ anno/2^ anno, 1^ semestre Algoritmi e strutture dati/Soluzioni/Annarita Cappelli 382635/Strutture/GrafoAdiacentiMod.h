/*
Autore: Annarita Cappelli 
Matricola: 382635
Nome file: GrafoAdiacentiMod.h
Commento: Classe che implementa un grafo mediante la 
rappresentazione con liste di adiacenza e i pesi sono rappresentati da 
due interi.
*/

#ifndef GRAFOADIACENTIMOD_H
#define GRAFOADIACENTIMOD_H
#define MAXNODI 100

#ifndef LISTAADIACENTI_H
#include "ListaAdiacenti.h"
#endif

struct tipo {
	 Nodo nodoCur;
	 int peso1;
	 int peso2;
};

template <class G>
struct NodoGrafo {
	 G etichetta;
	 bool presente, visitato;
	 ListaAdiacenti<tipo> neighbours;
};

template <class G>
class GrafoAdiacenti {
      public:
             GrafoAdiacenti();  // costruttore
             ~GrafoAdiacenti();  // distruttore
             
             // operatori
             void creaGrafo();
             bool grafoVuoto();
             bool esisteNodo(Nodo);
             bool esisteArco(Nodo, Nodo);
             bool insNodo(Nodo);
             bool insArco(Nodo, Nodo);
             bool cancNodo(Nodo);
             bool cancArco(Nodo, Nodo);
             void adiacenti(Nodo, ListaAdiacenti<tipo> &);
             bool scriviNodo(Nodo, G);
             bool leggiNodo(Nodo, G &);
             bool scriviArco(Nodo, Nodo, int, int);
             bool leggiArco(Nodo, Nodo, int &, int &);
             bool getVisitato(Nodo);
             void setVisitato(bool, Nodo);
             void azzeraVisitato();
             // GrafoAdiacenti<G> &operator=(GrafoAdiacenti<G> &);
      private:
              NodoGrafo<G> grafo[MAXNODI];
};

template <class G>
GrafoAdiacenti<G>::GrafoAdiacenti() {
	 creaGrafo();
};

template <class G>
GrafoAdiacenti<G>::~GrafoAdiacenti() { };

template <class G>
void GrafoAdiacenti<G>::creaGrafo() {
	 for(int i = 0; i<MAXNODI; i++) {
		grafo[i].presente = false;
		grafo[i].visitato = false;
		grafo[i].neighbours.creaLista();
	 }
};

template <class G>
bool GrafoAdiacenti<G>::grafoVuoto() {
	 bool vuoto = true;
	 for(int i = 0; (i<MAXNODI && vuoto); i++) {
		vuoto = (vuoto && (!grafo[i].presente));
	 }
	 return vuoto;
};

template <class G>
bool GrafoAdiacenti<G>::esisteNodo(Nodo n) {
	 return grafo[n].presente;
};

template <class G>
bool GrafoAdiacenti<G>::esisteArco(Nodo n, Nodo m) {
	 if(grafo[n].presente && grafo[m].presente) {
		NodoAdiacenti<tipo> *p = grafo[n].neighbours.primoLista();
		bool trovato = false;
		while (!(grafo[n].neighbours.fineLista(p) || trovato)) {
		   if (p->etichetta.nodoCur == m)
		      trovato = true;
		   else
		      p = grafo[n].neighbours.succLista(p);
		}
		return trovato;
	 } else return false;
};

template <class G>
bool GrafoAdiacenti<G>::insNodo(Nodo n) {
	 if(!grafo[n].presente) {
		grafo[n].presente = true;
		return true;
	 } else return false;
};

template <class G>
bool GrafoAdiacenti<G>::insArco(Nodo n, Nodo m) {
	 if ( esisteNodo(n) && esisteNodo(m) && (!esisteArco(n,m))) {
		tipo a;
		a.nodoCur = m;
		a.peso1 = NIL;
		a.peso2 = NIL;
		grafo[n].neighbours.insLista(a,grafo[n].neighbours.primoLista());
		return true;
	 } else return false;			
};

template <class G>
bool GrafoAdiacenti<G>::cancNodo(Nodo n) {
     if (grafo[n].presente) {
        if (grafo[n].neighbours.listaVuota()) { // vuol dire che n non ha archi uscenti
		   bool trovato = false;        
           for (int i = 0; ((i < MAXNODI) && (!trovato)); i++)
              if (esisteArco(i, n))
                 trovato = true;
           if (!trovato)
              grafo[n].presente = false;
           return !trovato;
        } else return false;
     } else return false;
};

template <class G>
bool GrafoAdiacenti<G>::cancArco(Nodo n , Nodo m) {
   	 if (esisteArco(n, m)) {
    	NodoAdiacenti<tipo> *p = grafo[n].neighbours.primoLista();
  		tipo a;
   		grafo[n].neighbours.leggiLista(a,p);
   		while (a.nodoCur != m) {
           p = grafo[n].neighbours.succLista(p);
           grafo[n].neighbours.leggiLista(a,p);
   		}
      	grafo[n].neighbours.cancLista(p);
      	return true;
   	 } else
     return false;
};

template <class G>
void GrafoAdiacenti<G>::adiacenti(Nodo n, ListaAdiacenti<tipo> &l) {
	 l = grafo[n].neighbours;
};

template <class G>
bool GrafoAdiacenti<G>::scriviNodo(Nodo n, G l) {
	 if(grafo[n].presente) {
        grafo[n].etichetta = l;
        return true;
     } else return false;
};

template <class G>
bool GrafoAdiacenti<G>::leggiNodo(Nodo n, G &l) {
     if (grafo[n].presente) {
        l = grafo[n].etichetta;
        return true;
     } else return false;
};

template <class G>
bool GrafoAdiacenti<G>::scriviArco(Nodo n, Nodo m, int w, int z) {
     if (esisteArco(n, m)) {
        NodoAdiacenti<tipo> *p = grafo[n].neighbours.primoLista();
        while (p->etichetta.nodoCur != m)
           p = grafo[n].neighbours.succLista(p);
        p->etichetta.peso1 = w;
        p->etichetta.peso2 = z;
        return true;
     } else return false;
};

template <class G>
bool GrafoAdiacenti<G>::leggiArco(Nodo n, Nodo m, int &w, int &z) {
     if (esisteArco(n, m)) {
        NodoAdiacenti<tipo> *p = grafo[n].neighbours.primoLista();
        while (p->etichetta.nodoCur != m)
           p = grafo[n].neighbours.succLista(p);
        w = p->etichetta.peso1;
        z = p->etichetta.peso2;
        return true;
     } else return false;
};

template <class G>
bool GrafoAdiacenti<G>::getVisitato(Nodo n) {
     return grafo[n].visitato;
};

template <class G>
void GrafoAdiacenti<G>::setVisitato(bool b, Nodo n) {
     grafo[n].visitato = b;
};

template <class G>
void GrafoAdiacenti<G>::azzeraVisitato() {
     for (int i = 0; i < MAXNODI; i++)
        grafo[i].visitato = false;
};

/*template <class G>
GrafoAdiacenti<G> &GrafoAdiacenti<G>::operator=(GrafoAdiacenti<G> &g) {
	 for(int i = 0; i<MAXNODI; i++) {
		if (grafo[i].presente) {
		   grafo[i].neighbours.~ListaAdiacenti();
		   grafo[i].presente = false;
		   grafo[i].visitato = false;
		}
	 }
	 for(int i = 0; i<MAXNODI; i++) {
        if (g.esisteNodo(i)) {
           grafo[i].presente = true;
           g.leggiNodo(i, grafo[i].etichetta);
           g.adiacenti(i, grafo[i].neighbours);
        }
     }
	 return *this;
};*/

#endif 
