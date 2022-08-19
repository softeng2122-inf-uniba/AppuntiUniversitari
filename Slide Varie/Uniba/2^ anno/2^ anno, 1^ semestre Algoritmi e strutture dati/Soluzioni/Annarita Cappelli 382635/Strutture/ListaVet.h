/*
Autore: Annarita Cappelli 
Matricola: 382635
Nome file: ListaVet.h
Commento: Classe che implementa una lista mediante la rappresentazione 
sequenziale con vettore.
*/

#ifndef LISTAVET_H
#define LISTAVET_H
#define MAXLUNG 1024  // lunghezza massima del vettore

#ifndef MAIN_H
#include "main.h"
#endif

template <class L>
struct lvcell {
       L valore;
};

typedef int posizione;

template <class L>
class ListaVet {
      public:
             ListaVet();  // costruttore
             ~ListaVet();  // distruttore
             
             // operatori
             void creaLista();
             bool listaVuota();
             L leggiLista(posizione);
             void scriviLista(L, posizione);
             posizione primoLista();
             posizione succLista(posizione);
             posizione predLista(posizione);
             bool fineLista(posizione);
             void insLista(L, posizione);
             void cancLista(posizione);
      private:
              lvcell<L> lista[MAXLUNG];
              int lunghezza;
};

template <class L>
ListaVet<L>::ListaVet() {
     creaLista();
};

template <class L>
ListaVet<L>::~ListaVet() { };

template <class L>
void ListaVet<L>::creaLista() {
     lunghezza=0;
};

template <class L>
bool ListaVet<L>::listaVuota() {
     return (fineLista(primoLista()));
};

template <class L>
L ListaVet<L>::leggiLista(posizione p) {
     if (!listaVuota()) 
        return (lista[p-1].valore);
};

template <class L>
void ListaVet<L>::scriviLista(L elem, posizione p) {
     if (!listaVuota())
        lista[p-1].valore=elem;
};

template <class L>
posizione ListaVet<L>::primoLista() {
     return 1;
};

template <class L>
posizione ListaVet<L>::succLista(posizione p) {
     if (!fineLista(p))
        return (p+1);
};

template <class L>
posizione ListaVet<L>::predLista(posizione p) {
     if (p!=primoLista())
        return (p-1);
};

template <class L>
bool ListaVet<L>::fineLista(posizione p) {
     return (lunghezza==p-1);
};

template <class L>
void ListaVet<L>::insLista(L elem, posizione p) {
     if (p!=MAXLUNG) {
        for (int i=lunghezza; i>=p; i--)
           lista[i]=lista[i-1];
        lista[p-1].valore=elem;
        lunghezza++;
     }
};

template <class L>
void ListaVet<L>::cancLista(posizione p) {
     if (!listaVuota())
     {
        if ((!fineLista(p))&&(p<=lunghezza))
        {
           for (int i=p-1; i<(lunghezza-1); i++)
              lista[i]=lista[i+1];
           lunghezza--;
        }
     }
};

#endif


              
     



     




