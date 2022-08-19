/*
Autore: Annarita Cappelli 
Matricola: 382635
Nome file: ListaCur.h
Commento: Classe che implementa una lista mediante la rappresentazione 
collegata con cursori.
*/

#ifndef LISTACUR_H
#define LISTACUR_H
#define MAXLUNG 1024 // lunghezza massima del vettore
#define NIL -1

#ifndef MAIN_H
#include "main.h"
#endif

typedef int posizione;

template <class L>
struct lccell {
       L valore;
       posizione successivo;
};

template <class L>
class ListaCur {
      public:
             ListaCur();  // costruttore
             ~ListaCur();  // distruttore
             
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
              lccell<L> spazio[MAXLUNG];
              posizione listaLibera;  // primo elemento della lista libera
              int lunghezza;  // lunghezza della lista
              posizione primo; // primo elemento della lista
              
              // funzione di servizio per la lista libera
              void sposta(posizione &, posizione &);  // sposta la cella dalla lista
                                                      // libera alla lista e 
                                                      // viceversa
};

template <class L>
ListaCur<L>::ListaCur() {
     creaLista();
};

template <class L>
ListaCur<L>::~ListaCur() { };

template <class L>
void ListaCur<L>::creaLista() {
     primo=NIL;
     lunghezza=0;
     listaLibera=0;
     for (int i=0; i<(MAXLUNG-1); i++)
        spazio[i].successivo=i+1;
     spazio[MAXLUNG-1].successivo=NIL;
};

template <class L>
bool ListaCur<L>::listaVuota() {
     return (lunghezza==0);
};

template <class L>
L ListaCur<L>::leggiLista(posizione p) {
     if ((lunghezza>0)&&(p!=NIL))
        return (spazio[p].valore);
};

template <class L>
void ListaCur<L>::scriviLista(L elem, posizione p) {
     if ((lunghezza>0)&&(p!=NIL))
        spazio[p].valore=elem;
};

template <class L>
posizione ListaCur<L>::primoLista() {
     return (primo);
};

template <class L>
posizione ListaCur<L>::succLista(posizione p) {
     return (spazio[p].successivo);
};

template <class L>
posizione ListaCur<L>::predLista(posizione p) {
     posizione temp=primo;
     while (spazio[temp].successivo != p)
        temp=spazio[temp].successivo;
     return (temp);
};

template <class L>
bool ListaCur<L>::fineLista(posizione p) {
     return (p==NIL);
};

template <class L>
void ListaCur<L>::insLista(L elem, posizione p) {
     if (listaLibera != NIL) {
        if (p==primo) {
           sposta(listaLibera, p);
           spazio[p].valore=elem;
           primo=p;
        } else {
           posizione q=predLista(p);  // ultimo lista (p==NIL)
           sposta(listaLibera, p);
           spazio[p].valore=elem;
           spazio[q].successivo=p;
        }
        lunghezza++;
     } 
};

template <class L>
void ListaCur<L>::cancLista(posizione p) {
     if ((lunghezza > 0)&&(p != NIL)) {
        if (p != primo) {
           spazio[predLista(p)].successivo=spazio[p].successivo;
        }
        sposta(p, listaLibera);
      lunghezza--;
     } 
};

template <class L>
void ListaCur<L>::sposta(posizione &h, posizione &k) {
     posizione temp=spazio[h].successivo;
     spazio[h].successivo=k;
     k=h;
     h=temp;
};

#endif


     

     
     
     

       
