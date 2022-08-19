/*
Autore: Annarita Cappelli 
Matricola: 382635
Nome file: GrafoMatAd.h
Commento: Classe che implementa un grafo non orientato mediante la 
rappresentazione con matrice di adiacenza.
*/

#ifndef GRAFOMATAD_H
#define GRAFOMATAD_H
#define maxlung 100

#ifndef MAIN_H
#include "main.h"
#endif

#ifndef LISTAVET_H
#include "ListaVet.h"
#endif

typedef int nodo;

template <class G>
class GrafoMatAd {
      public:
             GrafoMatAd();  // costruttore
             ~GrafoMatAd();  // distruttore
             
             // operatori
             void creaGrafo();
             bool grafoVuoto();
             void insNodo(nodo);
             void insArco(nodo,nodo);
             void cancNodo(nodo);
             void cancArco(nodo,nodo);
             bool esisteArco(nodo,nodo);
             bool esisteNodo(nodo);
             ListaVet<G> adiacente(nodo);
             G leggiNodo(nodo);
             void scriviNodo(G, nodo);
      private:
              G label[maxlung];  // vettore delle etichette
              bool mark[maxlung];  // vettore per dire se un nodo esiste o no
              nodo matrice[maxlung][maxlung];  //matrice degli archi
};

template <class G>
GrafoMatAd<G>::GrafoMatAd() { };

template <class G>
GrafoMatAd<G>::~GrafoMatAd() { }; 

template <class G>
void GrafoMatAd<G>::creaGrafo() {
     for(int i=0; i<maxlung; i++) {
        mark[i]=false;
        label[i]="\0";
        for(int j=0; j<maxlung; j++) {
           matrice[i][j]=0;
        }
     }
};

template <class G>
bool GrafoMatAd<G>::grafoVuoto() {
     int i;
     bool vuoto=true;
     while(i<maxlung && vuoto) {
        if (mark[i]==true)
           vuoto=false;
        i++;
     }
     return vuoto;
};

template <class G>
void GrafoMatAd<G>::insNodo(nodo n) {
     if(!esisteNodo(n)) {
        mark[n]=true;
     } else
        cout<<"Il nodo e' gia stato inserito\n";
};

template <class G>
void GrafoMatAd<G>::insArco(nodo n, nodo v) {
     if (esisteNodo(n) && esisteNodo(v) && !esisteArco(n,v)) {
        matrice[n][v]=1;
        matrice[v][n]=1;
     } else
        if (esisteArco(n,v))
           cout<<"L'arco e' gia presente\n";
        else
           cout<<"Uno o entrambi i nodi non sono stati inseriti\n";
};

template <class G>
void GrafoMatAd<G>::cancNodo(nodo n) {
     if (esisteNodo(n) && adiacente(n).listaVuota()) {
        mark[n]=false;
     } else
 	    if(!esisteNodo(n))
           cout<<"Il nodo non esiste\n";
        else
           cout<<"La lista degli adiacenti non e' vuota\n";
};

template <class G>
void GrafoMatAd<G>::cancArco(nodo n, nodo v) {
     if (esisteNodo(n) && esisteNodo(v) && esisteArco(n,v)) {
        matrice[n][v]=0;
        matrice[v][n]=0;
     } else
 	    if (!esisteArco(n,v))
           cout<<"L'arco che si vuole cancellare non esiste";
        else
    	   cout<<"Uno o entrambi i nodi non esistono";
};

template <class G>
bool GrafoMatAd<G>::esisteArco(nodo n, nodo v) {
     bool esiste;
     if (esisteNodo(n) && esisteNodo(v)) {
        esiste=matrice[n][v]==1 && matrice[v][n]==1;
     }
     return esiste;
};

template <class G>
bool GrafoMatAd<G>::esisteNodo(nodo n) {
     return mark[n];
};

template <class G>
ListaVet<G> GrafoMatAd<G>::adiacente(nodo n) {
     ListaVet<G> l;
     l.creaLista();
     posizione p=l.primoLista();
     if (esisteNodo(n)) {
        for(int i=0; i<maxlung; i++) {
           if (esisteArco(n,i)) {
              l.insLista(leggiNodo(i),p);
              p=l.succLista(p);
           }
        }
     } else
        cout<<"Non esiste il nodo\n";
     return l;
};

template <class G>
G GrafoMatAd<G>::leggiNodo(nodo n) {
     return label[n];
};

template <class G>
void GrafoMatAd<G>::scriviNodo(G a, nodo n) {
     label[n]=a;
};

#endif


