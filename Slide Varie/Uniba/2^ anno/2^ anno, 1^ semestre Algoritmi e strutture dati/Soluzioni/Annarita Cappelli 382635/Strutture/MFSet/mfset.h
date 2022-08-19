#ifndef MFSET_H
#define MFSET_H

#ifndef LISTA_H
#include "lista.h"
#endif

#ifndef NALBERO_H
#include "nalbero.h"
#endif

#ifndef CODA_H
#include "coda.h"
#endif

template <class M>
class MFSet {
      public:
             MFSet();  // costruttore
             ~MFSet();  // distruttore
             
             // operatori
             void creaMFSet(Lista<M>);
             void fondi(M, M);
             Nalbero<M> trova(M);
      private:
              bool appartiene(M, Nalbero<M>);
              unsigned int conta(Nalbero<M>);
              Lista<Nalbero<M> > mfset;
};

template <class M>
MFSet<M>::MFSet() { };

template <class M>
MFSet<M>::~MFSet() { };

template <class M>
void MFSet<M>::creaMFSet(Lista<M> l) {
     mfset.creaLista();
     lcell<M> *lp=l.primoLista();
     while (!l.fineLista(lp)) {
        Nalbero<M> elem;
        elem.creaAlbero();
        anodo<M> *temp=elem.insRadice();
        elem.scriviNodo(l.leggiLista(lp), temp);
        mfset.insLista(elem, NULL);
        lp=l.succLista(lp);
     }
};

template <class M>
void MFSet<M>::fondi(M val1, M val2) {
     Nalbero<M> v1=trova(val1), v2=trova(val2);
     if (v1.leggiNodo(v1.radice())==v2.leggiNodo(v2.radice()))
        _gerr("MFSet:fondi: gli elementi appartengono allo stesso insieme!");
     if (conta(v1)<conta(v2)) {
        Nalbero<M> temp;
        temp=v1;
        v1=v2;
        v2=temp;
     }
     v1.insSottoAlbero(v1.radice(), v2.radice(), v2);
     lcell<Nalbero<M> > *tmp=mfset.primoLista();
     bool f1=false;
     while ((!mfset.fineLista(tmp))&&(!f1)) {
        Nalbero<M> tmpt =mfset.leggiLista(tmp);
        if (tmpt.leggiNodo(tmpt.radice())==v2.leggiNodo(v2.radice())) {
           mfset.cancLista(tmp);
           f1=true;
        }
        tmp=mfset.succLista(tmp);
     }
};

template <class M>
Nalbero<M> MFSet<M>::trova(M val) {
     Nalbero<M> ret;
     lcell<Nalbero<M> > *tmp=mfset.primoLista();
     bool found=false;
     while ((!mfset.fineLista(tmp))&&(!found)) {
        if (appartiene(val,mfset.leggiLista(tmp))) {
           found=true;
           ret=mfset.leggiLista(tmp);
        }
        tmp=mfset.succLista(tmp);
     }
     if (!found)
        _gerr("MFSet::trova: elemento non trovato!");
     return (ret);
};

template <class M>
bool MFSet<M>::appartiene(M val, Nalbero<M> t) {
     bool ret=false;
     anodo<M> *u=t.radice();
     Coda<anodo<M> *> q;
     q.creaCoda();
     q.inCoda(u);
     while ((!q.codaVuota())&&(!ret)) {
        anodo<M> *tmp=q.leggiCoda();
        if (t.leggiNodo(tmp)==val)
           ret=true;
        else {
           q.fuoriCoda();
           if (!t.foglia(tmp)) {
              anodo<M> *tmp2=t.primoFiglio(tmp);
              while (!t.ultimoFratello(tmp2)) {
                 q.inCoda(tmp2);
                 tmp2=t.succFratello(tmp2);
              }
              q.inCoda(tmp2);
           }
        }
     }
     return (ret);
};

template <class M>
unsigned int MFSet<M>::conta(Nalbero<M> t) {
     unsigned int ret=0;
     Coda<anodo<M> *> q;
     q.creaCoda();
     q.inCoda(t.radice());
     while (!q.codaVuota()) {
        anodo<M> *tmp=q.leggiCoda();
        ret++;
        q.fuoriCoda();
        if (!t.foglia(tmp)) {
           anodo<M> *tmp2=t.primoFiglio(tmp);
           while (!t.ultimoFratello(tmp2)) {
              q.inCoda(tmp2);
              tmp2=t.succFratello(tmp2);
           }
           q.inCoda(tmp2);
        }
     }
     return (ret);
};


#endif


             
