/*
Autore: Annarita Cappelli 
Matricola: 382635
Nome file: ListaBi.h
Commento: Classe che implementa una lista mediante la rappresentazione 
collegata con puntatori bidirezionale.
*/

#ifndef LISTABI_H
#define LISTABI_H

#ifndef MAIN_H
#include "main.h"
#endif

template <class L>
struct lbcell {
       L valore;
       lbcell<L> *precedente;
       lbcell<L> *successivo;
};

template <class L>
class ListaBi {
      public:
             ListaBi();  // costruttore
             ~ListaBi();  // distruttore
             
             // operatori
             void creaLista();
             bool listaVuota();
             L leggiLista(lbcell<L> *);
             void scriviLista(L, lbcell<L> *);
             lbcell<L> *primoLista();
             lbcell<L> *succLista(lbcell<L> *);
             lbcell<L> *predLista(lbcell<L> *);
             bool fineLista(lbcell<L> *);
             void insLista(L, lbcell<L> *&);
             void cancLista(lbcell<L> *&);
             // sovraccarico dell'operatore =
             ListaBi<L> & operator = (ListaBi<L> &);
      private:
              lbcell<L> *lista;
};

template <class L>
ListaBi<L>::ListaBi() {
     creaLista();
};

template <class L>
ListaBi<L>::~ListaBi() { };

template <class L>
void ListaBi<L>::creaLista() {
     L elementoNullo;
     lista=new (lbcell<L>);
     lista->valore=elementoNullo;
     lista->successivo=lista;
     lista->precedente=lista;
     // la sentinella punta a se stessa
};

template <class L>
bool ListaBi<L>::listaVuota() {
     return ((lista->successivo==lista)&&(lista->precedente==lista));
};

template <class L>
L ListaBi<L>::leggiLista(lbcell<L> *p) {
     return (p->valore);
};

template <class L>
void ListaBi<L>::scriviLista(L elem, lbcell<L> *p) {
     p->valore=elem;
};

template <class L>
lbcell<L> *ListaBi<L>::primoLista() {
     return (lista->successivo);
};

template <class L>
lbcell<L> *ListaBi<L>::succLista(lbcell<L> *p) {
     return (p->successivo);
};

template <class L>
lbcell<L> *ListaBi<L>::predLista(lbcell<L> *p) {
     return (p->precedente);
};

template <class L>
bool ListaBi<L>::fineLista(lbcell<L> *p) {
     return (p==lista);
};

template <class L>
void ListaBi<L>::insLista(L elem, lbcell<L> *&p) {
     lbcell<L> *temp;
     temp= new (lbcell<L>);
     temp->valore=elem;
     temp->precedente=p->precedente;
     temp->successivo=p;
     p->precedente->successivo=temp;
     p->precedente=temp;
     p=temp;
};

template <class L>
void ListaBi<L>::cancLista(lbcell<L> *&p) {
     lbcell<L> *temp;
     temp=p;
     p->successivo->precedente=p->precedente;
     p->precedente->successivo=p->successivo;
     p=p->successivo;
     delete (temp);
};

template <class L>
ListaBi<L> &ListaBi<L>::operator=(ListaBi<L> &l) {
     lista=l.lista;
     return *this;
};

#endif



     
     
     
