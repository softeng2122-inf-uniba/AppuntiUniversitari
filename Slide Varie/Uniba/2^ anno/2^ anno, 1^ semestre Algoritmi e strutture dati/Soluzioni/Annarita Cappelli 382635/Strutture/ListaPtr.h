/*
Autore: Annarita Cappelli 
Matricola: 382635
Nome file: ListaPtr.h
Commento: Classe che implementa una lista mediante la rappresentazione 
collegata con puntatori monodirezionale.
*/

#ifndef LISTAPTR_H
#define LISTAPTR_H

#ifndef MAIN_H
#include "main.h"
#endif

template <class L>
struct lpcell {
       L valore;
       lpcell<L> *successivo;
};

template <class L>
class ListaPtr {
      public:
             ListaPtr();  // costruttore
             ~ListaPtr();  // distruttore
             
             // operatori
             void creaLista();
             bool listaVuota();
             L leggiLista(lpcell<L> *);
             void scriviLista(L, lpcell<L> *);
             lpcell<L> *primoLista();
             lpcell<L> *succLista(lpcell<L> *);
             lpcell<L> *predLista(lpcell<L> *);
             bool fineLista(lpcell<L> *);
             void insLista(L, lpcell<L> *);
             void cancLista(lpcell<L> *);
             
             lpcell<L> *pos(int);  // mapping della posizione
      private:
              lpcell<L> *lista;
};

template <class L>
ListaPtr<L>::ListaPtr() {
     creaLista();
};

template <class L>
ListaPtr<L>::~ListaPtr() { };

template <class L>
void ListaPtr<L>::creaLista() {
     lista=NULL;
};

template <class L>
bool ListaPtr<L>::listaVuota() {
     return (lista==NULL);
};

template <class L>
L ListaPtr<L>::leggiLista(lpcell<L> *p) {
     L ritorno;
     if (p!=NULL)
        ritorno=p->valore;
     return (ritorno);
};

template <class L>
void ListaPtr<L>::scriviLista(L elem, lpcell<L> *p) {
     if ((lista!=NULL)&&(p!=NULL)) 
        p->valore=elem;
};

template <class L>
lpcell<L> *ListaPtr<L>::primoLista() {
     return (lista);
};

template <class L>
lpcell<L> *ListaPtr<L>::succLista(lpcell<L> *p) {
     lpcell<L> *ritorno=NULL;
     if (p!=NULL)
        ritorno=p->successivo;
     return (ritorno);
};

template <class L>
lpcell<L> *ListaPtr<L>::predLista(lpcell<L> *p) {
     if (p == lista){
        return NULL;
     } else {
        lpcell<L> *q = lista;
        while (q->successivo != p){
           q = q->successivo;
        }
        return q;
     }
};

template <class L>
bool ListaPtr<L>::fineLista(lpcell<L> *p) {
     return (p==NULL);
};

template <class L>
void ListaPtr<L>::insLista(L elem, lpcell<L> *p) {
     lpcell<L> *ritorno=new (lpcell<L>);
     ritorno->valore=elem;
     if (p==NULL) {
        ritorno->successivo=NULL;
        if (lista==NULL)
           lista=ritorno;
        else {
           lpcell<L> *tmp=lista;
           while (tmp->successivo!=NULL)
              tmp=tmp->successivo;
           tmp->successivo=ritorno;
        }
     } else {
        if (p==primoLista()) {
           ritorno->successivo=lista;
           lista=ritorno;
        } else {
           lpcell<L> *tmp=lista;
           while (tmp->successivo!=p) 
              tmp=tmp->successivo;
           ritorno->successivo=tmp->successivo;
           tmp->successivo=ritorno;
        }
     }
};

template <class L>
void ListaPtr<L>::cancLista(lpcell<L> *p) {
     lpcell<L> *tmp=lista;
     if (tmp==p) {
        lista=tmp->successivo;
        delete (tmp);
     } else {
        bool trovato=false;
        while ((tmp->successivo!=NULL)&&(!trovato)) {
           if (tmp->successivo==p) {
              lpcell<L> *tmp2=tmp->successivo->successivo;
              delete (tmp->successivo);
              tmp->successivo=tmp2;
              trovato=true;
           } else {
              tmp=tmp->successivo;
           }
        }
     }
};

template <class L>
lpcell<L> *ListaPtr<L>::pos(int n) {
   lpcell<L> *p = lista;
   int i = 1;
   while ((p != NULL) && (i < n)){
      p = p->successivo;
      i++;
   }
   return p;
};

#endif


                                      
              

