#ifndef NALBERO_H
#define NALBERO_H

#ifndef MAIN_H
#include "main.h"
#endif

template <class A> struct apunt;

template <class A>
struct anodo {
       A etichetta;
       struct anodo<A> *padre;
       struct apunt<A> *punt;
};

template <class A>
struct apunt {
       unsigned int peso;
       struct anodo<A> *adiac;
       struct apunt <A> *next;
};

template <class A>
class Nalbero {
      public:
             Nalbero();  // costruttore
             ~Nalbero();  // distruttore
             
             // operatori
             void creaAlbero();
             bool alberoVuoto();
             anodo<A> *insRadice();
             anodo<A> *radice();
             anodo<A> *padre(anodo<A> *);
             bool foglia(anodo<A> *);
             anodo<A> *primoFiglio(anodo<A> *);
             bool ultimoFratello(anodo<A> *);
             anodo<A> *succFratello(anodo<A> *);
             anodo<A> *insNodo(anodo<A> *);
             void insSottoAlbero(anodo<A> *, anodo<A> *, Nalbero);
             void cancSottoAlbero(anodo<A> *);
             A leggiNodo(anodo<A> *);
             void scriviNodo(A, anodo<A> *);
      private:
              void cancFoglia(anodo<A> *);
              anodo<A> *albero;
};

template <class A>
Nalbero<A>::Nalbero() {
     creaAlbero();
};

template <class A>
Nalbero<A>::~Nalbero() { };

template <class A>
void Nalbero<A>::creaAlbero() {
     albero=NULL;
};

template <class A>
bool Nalbero<A>::alberoVuoto() {
     return (albero==NULL);
};

template <class A>
anodo<A> *Nalbero<A>::insRadice() {
     if (!alberoVuoto())
        _gerr("Nalbero::insRadice: albero non vuoto!");
     albero=new(anodo<A>);
     albero->padre=NULL;
     albero->punt=NULL;
     return (albero);
};

template <class A>
anodo<A> *Nalbero<A>::radice() {
     if (alberoVuoto())
        _gerr("Nalbero::radice: l'albero e' vuoto!");
     return (albero);
};

template <class A>
anodo<A> *Nalbero<A>::padre(anodo<A> *u) {
     if (alberoVuoto())
        _gerr("Nalbero::padre: il nodo e' una radice!");
     return (u->padre);
};

template <class A>
bool Nalbero<A>::foglia(anodo<A> *u) {
     return (u->punt==NULL);
};

template <class A>
anodo<A> *Nalbero<A>::primoFiglio(anodo<A> *u) {
     if (foglia(u))
        _gerr("Nalbero::primoFiglio: il nodo e' una foglia!");
     anodo<A> *ret=NULL;
     if (u->punt)
        ret=u->punt->adiac;
     return (ret);
};

template <class A>
bool Nalbero<A>::ultimoFratello(anodo<A> *u) {
     if (!u->padre)
        _gerr("Nalbero::ultimoFratello: il nodo e' una radice!");
     bool ret=false;
     apunt<A> *punt=u->padre->punt;
     while (punt) {
        if ((punt->adiac==u)&&(punt->next==NULL))
           ret=true;
        punt=punt->next;
     }
     return (ret);
};

template <class A>
anodo<A> *Nalbero<A>::succFratello(anodo<A> *u) {
     if (!u->padre)
        _gerr("Nalbero::succFratello: il nodo e' una radice!");
     if (ultimoFratello(u))
        _gerr("Nalbero::succFratello: il nodo non ha fratelli successivi!");
     bool found=false;
     anodo<A> *ret=NULL;
     apunt<A> *punt=u->padre->punt;
     while ((punt!=NULL)&&(!found)) {
        if (punt->adiac==u)
           found=true;
        punt=punt->next;
     }
     ret=punt->adiac;
     return (ret);
};

template <class A>
anodo<A> *Nalbero<A>::insNodo(anodo<A> *u) {
     anodo<A> *ret=new(anodo<A>);
     ret->padre=u;
     ret->punt=NULL;
     apunt<A> *tmp=new(apunt<A>);
     tmp->next=NULL;
     tmp->adiac=ret;
     if (u->punt==NULL)
        u->punt=tmp;
     else {
        apunt<A> *tmp2=u->punt;
        while (tmp2->next!=NULL)
           tmp2=tmp2->next;
        tmp2->next=tmp;
     }
     return (ret);
};

template <class A>
void Nalbero<A>::insSottoAlbero(anodo<A> *u, anodo<A> *v, Nalbero t) {
     anodo<A> *tmp=insNodo(u);
     tmp->etichetta=t.leggiNodo(v);
     if (!t.foglia(v)) {
        anodo<A> *tmp2=t.primoFiglio(v);
        while (!t.ultimoFratello(tmp2)) {
           insSottoAlbero(tmp, tmp2, t);
           tmp2=t.succFratello(tmp2);
        }
        insSottoAlbero(tmp, tmp2, t);
     }
};

template <class A>
void Nalbero<A>::cancSottoAlbero(anodo<A> *u) {
     if (!foglia(u)) {
        apunt<A> *primo=u->punt;
        while (primo) {
           apunt<A> *temp=primo->next;
           cancSottoAlbero(primo->adiac);
           primo=temp;
        }
     }
     cancFoglia(u);
};

template <class A>
void Nalbero<A>::cancFoglia(anodo<A> *u) {
     if (u!=albero) {
        apunt<A> *punt=u->padre->punt;
        bool found=false;
        if (punt->adiac==u) {
           apunt<A> *temp=u->padre->punt;
           u->padre->punt=punt->next;
           delete (temp);
           found=true;
        }
        while ((punt->next)&&(!found)) {
           if (punt->next->adiac==u) {
              apunt<A> *temp=punt->next;
              punt->next=punt->next->next;
              delete (temp);
              found=true;
           }
        }
     } else
        albero=NULL;
     delete (u);
};

template <class A>
A Nalbero<A>::leggiNodo(anodo<A> *u) {
     return (u->etichetta);
};

template <class A>
void Nalbero<A>::scriviNodo(A val, anodo<A> *u) {
     u->etichetta=val;
};


#endif

