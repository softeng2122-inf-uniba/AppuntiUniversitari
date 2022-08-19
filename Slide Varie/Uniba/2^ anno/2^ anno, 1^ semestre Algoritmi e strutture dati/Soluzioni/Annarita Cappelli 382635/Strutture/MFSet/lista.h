#ifndef LISTA_H
#define LISTA_H

#ifndef MAIN_H
#include "main.h"
#endif

template <class L>
struct lcell {
       L val;
       lcell<L> *next;
};

template <class L>
class Lista {
      public:
             Lista();  // costruttore
             ~Lista();  // distruttore
             
             // operatori
             void creaLista();
             bool listaVuota();
             L leggiLista(lcell<L> *);
             void scriviLista(L, lcell<L> *);
             lcell<L> *primoLista();
             bool fineLista(lcell<L> *);
             lcell<L> *succLista(lcell<L> *);
             lcell<L> *predLista(lcell<L> *);
             lcell<L> *ultimoLista();
             
             lcell<L> *insLista(L, lcell<L> *);
             void cancLista(lcell<L> *);
             
      private:
              lcell<L> *lista;
};

template <class L>
Lista<L>::Lista() {
     creaLista();
};

template <class L>
Lista<L>::~Lista() { };

template <class L>
void Lista<L>::creaLista() {
     lista=NULL;
};

template <class L>
bool Lista<L>::listaVuota() {
     return (lista==NULL);
};

template <class L>
L Lista<L>::leggiLista(lcell<L> *p) {
     L ret;
     if (p!=NULL)
        ret=p->val;
     return (ret);
};

template <class L>
void Lista<L>::scriviLista(L elem, lcell<L> *p) {
     if (p!=NULL)
        p->val=elem;
};

template <class L>
lcell<L> *Lista<L>::primoLista() {
     return (lista);
};

template <class L>
bool Lista<L>::fineLista(lcell<L> *p) {
     return (p==NULL);
};

template <class L>
lcell<L> *Lista<L>::succLista(lcell<L> *p) {
     if (listaVuota())
        _gerr("Lista::succLista: la lista e' vuota!");
     lcell<L> *ret=NULL;
     if (p!=NULL)
        ret=p->next;
     return (ret);
};

template <class L>
lcell<L> *Lista<L>::predLista(lcell<L> *p) {
     if (listaVuota())
        _gerr("Lista::predLista: la lista e' vuota!");
     if (p==lista)
        _gerr("Lista::predLista: l'elemento e' il primo elemento della lista!");
     lcell<L> *ret=NULL, temp=lista;
     while ((temp->next != NULL)&&(ret != NULL)) {
        if (temp->next == p)
           ret=temp;
        else
           temp=temp->next;
     }
     return (ret);
};

template <class L>
lcell<L> *Lista<L>::ultimoLista() {
     if (listaVuota())
        _gerr("Lista::ultimoLista: la lista e' vuota!");
     lcell<L> *ret=lista;
     while (ret->next != NULL)
        ret=ret->next;
     return (ret);
};

template <class L>
lcell<L> *Lista<L>::insLista(L elem, lcell<L> *p) {
     lcell<L> *ret=new(lcell<L>);
     ret->val=elem;
     if (p==NULL) {
        ret->next=NULL;
        if (lista==NULL) {
           lista=ret;
        } else {
           lcell<L> *temp=lista;
           while (temp->next != NULL)
              temp=temp->next;
           temp->next=ret;
        }
     } else {
        if (p==primoLista()) {
           ret->next=lista;
           lista=ret;
        } else {
           lcell<L> *temp=lista;
           while (temp->next != p)
              temp=temp->next;
           ret->next=temp->next;
        }
     }
     return (ret);
};

template <class L>
void Lista<L>::cancLista(lcell<L> *p) {
     if (listaVuota())
        _gerr("Lista::cancLista: la lista e' vuota!");
     lcell<L> *temp=lista;
     if (temp==p) {
        lista=temp->next;
        delete (temp);
     } else {
        bool found=false;
        while ((temp->next != NULL)&&(!found)) {
           if (temp->next==p) {
              lcell<L> *temp2=temp->next->next;
              delete (temp->next);
              temp->next=temp2;
              found=true;
           } else {
              temp=temp->next;
           }
        }
     }
};

#endif


