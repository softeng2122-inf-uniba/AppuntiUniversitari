/*
Autore: Annarita Cappelli 
Matricola: 382635
Nome file: GrafoMatAdExt.h
Commento: Classe che implementa un grafo mediante la 
rappresentazione con matrice di adiacenza estesa.
*/

#ifndef GRAFOMATADEXT_H
#define GRAFOMATADEXT_H
#define MAXNODI 100

#ifndef MAIN_H
#include "main.h"
#endif

#ifndef LISTAPTR_H
#include "ListaPtr.h"
#endif

typedef int Nodo;

template <class G>
struct tipoNodi {
   G label;
   int archi;
   bool esiste, visitato;
};

template <class G>
class GrafoMatAdExt {
      public:
             GrafoMatAdExt();  // costruttore
             ~GrafoMatAdExt();  // distruttore
             
             // operatori
             void creaGrafo();
             bool grafoVuoto();
             bool esisteNodo(Nodo);
             bool esisteArco(Nodo, Nodo);
             bool insNodo(G, Nodo);
             bool insArco(Nodo, Nodo);
             bool cancNodo(Nodo);
             bool cancArco(Nodo, Nodo);
             void adiacenti(Nodo, ListaPtr<Nodo> &);
             bool getVisitato(Nodo);
             void setVisitato(bool, Nodo);
             G getLabel(Nodo);
             bool setLabel(G, Nodo);
             bool getArchi(Nodo, int &);
             void azzeraVisitato();
             int numNodi();
      private:
              tipoNodi<G> nodi[MAXNODI];
              bool grafo[MAXNODI][MAXNODI];
};

template <class G>
GrafoMatAdExt<G>::GrafoMatAdExt() {
     creaGrafo();
};

template <class G>
GrafoMatAdExt<G>::~GrafoMatAdExt() { };

template <class G>	
void GrafoMatAdExt<G>::creaGrafo() {
     for (int i = 0; i < MAXNODI; i++) {
        nodi[i].archi = 0;
        nodi[i].esiste = false;
        nodi[i].visitato = false;
        for (int j = 0; j < MAXNODI; j++)
           grafo[i][j] = false;
     }
};

template <class G>
bool GrafoMatAdExt<G>::grafoVuoto() {
     bool vuoto = true;
     int i = 0;
     while ((i < MAXNODI) && (vuoto)) {
        if (nodi[i].esiste == true)
           vuoto = false;
        else
           i++;
     }
     return vuoto; 
};

template <class G>
bool GrafoMatAdExt<G>::esisteNodo(Nodo i) {
     return (nodi[i].esiste == true);
};

template <class G>
bool GrafoMatAdExt<G>::esisteArco(Nodo i, Nodo j) {
     return (grafo[i][j] == true);
};

template <class G>
bool GrafoMatAdExt<G>::insNodo(G a, Nodo i) {
     if (!nodi[i].esiste) {
        nodi[i].esiste = true;
        nodi[i].label = a;
        return true;
     } else return false;
};

template <class G>
bool GrafoMatAdExt<G>::insArco(Nodo i, Nodo j) {
     if (!grafo[i][j]) {
        grafo[i][j] = true;
        nodi[i].archi++;
        nodi[j].archi++;
        return true;
     } else return false;
};

template <class G>
bool GrafoMatAdExt<G>::cancNodo(Nodo i) {
     if (nodi[i].esiste) {
        nodi[i].esiste = false;
        return true;
     } else return false;
};

template <class G>
bool GrafoMatAdExt<G>::cancArco(Nodo i, Nodo j) {
     if (grafo[i][j]) {
        grafo[i][j] = false;
        nodi[i].archi--;
        nodi[j].archi--;
        return true;
     } else return false;
};

template <class G>
void GrafoMatAdExt<G>::adiacenti(Nodo i, ListaPtr<Nodo> &l) {
     for (int j = 0; j < MAXNODI; j++)
        if (grafo[i][j])
           l.insLista(j, l.primoLista());
};

template <class G>
bool GrafoMatAdExt<G>::getVisitato(Nodo i) {
     return nodi[i].visitato;
};

template <class G>
void GrafoMatAdExt<G>::setVisitato(bool b, Nodo i) {
     nodi[i].visitato = b;
};

template <class G>
G GrafoMatAdExt<G>::getLabel(Nodo i) {
     G k;
     if (nodi[i].esiste) 
        k = nodi[i].label;
     return k;
};

template <class G>
bool GrafoMatAdExt<G>::setLabel(G k, Nodo i) {
     if (nodi[i].esiste) {
        nodi[i].label = k;
        return true;
     } else return false;
};

template <class G>
bool GrafoMatAdExt<G>::getArchi(Nodo i, int &a){
     if (nodi[i].esiste){
        a = nodi[i].archi;
        return true;
     } else return false;
};

template <class G>
void GrafoMatAdExt<G>::azzeraVisitato() {
     for (int i = 0; i < MAXNODI; i++)
        nodi[i].visitato = false;
};

template <class G>
int GrafoMatAdExt<G>::numNodi() {
     int count=0;
     for (int i=0; i<MAXNODI; i++) {
        if (nodi[i].esiste)
           count++;
     }
     return count;
};

#endif



