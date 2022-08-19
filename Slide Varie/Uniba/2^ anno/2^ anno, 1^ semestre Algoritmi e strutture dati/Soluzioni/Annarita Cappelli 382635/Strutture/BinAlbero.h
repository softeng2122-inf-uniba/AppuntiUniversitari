/*
Autore: Annarita Cappelli 
Matricola: 382635
Nome file: BinAlbero.h
Commento: Classe che implementa un albero binario mediante la rappresentazione 
collegata con puntatori.
*/

#ifndef BINALBERO_H
#define BINALBERO_H

#ifndef MAIN_H
#include "main.h"
#endif

template <class B>
struct nodoBin {
       B valore;
	   nodoBin<B> *sx;
       nodoBin<B> *padre;
       nodoBin<B> *dx;
};

template <class B>
class BinAlbero {
      public:
             BinAlbero();  // costruttore
             ~BinAlbero();  // distruttore
             
             // operatori
             void creaBinAlbero();
             bool binAlberoVuoto() const;
             nodoBin<B> *binRadice()const;
             nodoBin<B> *binPadre(nodoBin<B> *)const;
             nodoBin<B> *figlioSx(nodoBin<B> *)const;
             nodoBin<B> *figlioDx(nodoBin<B> *)const;
             bool sxVuoto(nodoBin<B> *)const;
             bool dxVuoto(nodoBin<B> *)const;
             B leggiNodo(nodoBin<B> *)const;
             void scriviNodo(B, nodoBin<B> *);
             void insBinRadice(nodoBin<B> *);
             void insFiglioSx(nodoBin<B> *);
             void insFiglioDx(nodoBin<B> *);
             void costrBinAlbero(nodoBin<B> *, nodoBin<B> *);
             void cancSottoBinAlbero(nodoBin<B> *);
      private:
              nodoBin<B> *radice;
};


template <class B>
BinAlbero<B>::BinAlbero() {
     creaBinAlbero();
};

template <class B>
BinAlbero<B>::~BinAlbero() {
     if(!binAlberoVuoto())
        cancSottoBinAlbero(binRadice());
};

template <class B>
void BinAlbero<B>::creaBinAlbero() {
     radice=NULL;
};

template <class B>
bool BinAlbero<B>::binAlberoVuoto()const
{
     return(radice==NULL);
};

template <class B>
nodoBin<B> *BinAlbero<B>::binRadice()const {
     if(!binAlberoVuoto())
      	return radice;
};

template <class B>
nodoBin<B> *BinAlbero<B>::binPadre(nodoBin<B> *n)const {
     if(!binAlberoVuoto()&& n!=binRadice())
        return(n->padre);
     else
        return NULL;
};

template <class B>
nodoBin<B> *BinAlbero<B>::figlioSx(nodoBin<B> *n)const {
     if(!binAlberoVuoto())
        return(n->sx);
     else
        return NULL;
};

template <class B>
nodoBin<B> *BinAlbero<B>::figlioDx(nodoBin<B> *n)const {
     if(!binAlberoVuoto())
        return(n->dx);
     else
        return NULL;
};

template <class B>
bool BinAlbero<B>::sxVuoto(nodoBin<B> *n)const {
     if(!binAlberoVuoto())
        return((n->sx)==NULL);
};

template <class B>
bool BinAlbero<B>::dxVuoto(nodoBin<B> *n)const {
     if(!binAlberoVuoto())
        return((n->dx)==NULL);
};

template <class B>
B BinAlbero<B>::leggiNodo(nodoBin<B> *n)const {
     if(!binAlberoVuoto())
        return(n->valore);
};

template <class B>
void BinAlbero<B>::scriviNodo(B e, nodoBin<B> *n) {
     n->valore=e;
};

template <class B>
void BinAlbero<B>::insBinRadice(nodoBin<B> *n) {
     if (binAlberoVuoto()) {
        n->sx=n->dx=n->padre=NULL;
        radice=n;
     }
};

template <class B>
void BinAlbero<B>::insFiglioSx(nodoBin<B> *n) {
     if(!binAlberoVuoto()&& sxVuoto(n)) {
        nodoBin<B> *nuovo=new (nodoBin<B>);  // creo la var nuovo di tipo nodo e gli alloco la memoria
        nuovo->sx=nuovo->dx=NULL; // il nuovo nodo ha figlio sx e dx pari a NULL
        nuovo->padre=n;  // il nuovo nodo ha padre n
        n->sx=nuovo; // il nuovo nodo è il figlio sinistro di n
     } else {
        cout<<"Operazione non applicabile!"<<endl;
        exit(-1);
     }
};

template <class B>
void BinAlbero<B>::insFiglioDx(nodoBin<B> *n) {
     if(!binAlberoVuoto()&& dxVuoto(n)) {
        nodoBin<B> *nuovo=new (nodoBin<B>);
        nuovo->sx=nuovo->dx=NULL;
        nuovo->padre=n;
        n->dx=nuovo;
     } else {
        cout<<"Operazione non applicabile!"<<endl;
        exit(-1);
     }
};

template <class B>
void BinAlbero<B>::costrBinAlbero(nodoBin<B> *p, nodoBin<B> *q) {
     nodoBin<B> *nuovo=new (nodoBin<B>);
     nuovo->sx=p;
     nuovo->dx=q;
     nuovo->padre=NULL;
     if (p!=NULL)
        p->padre=nuovo;
     if (q!=NULL)
        q->padre=nuovo;
     radice=nuovo;
};

template <class B>
void BinAlbero<B>::cancSottoBinAlbero(nodoBin<B> *n) {
     if(!binAlberoVuoto()) {  //controlla che l'albero non sia vuoto
        if(!sxVuoto(n)) {
        //controlla che abbia un figlio sinistro e procede ricorsivamente
        //con la cancellazione più in profondità
           if(figlioSx(n)->sx!=NULL||figlioSx(n)->dx!=NULL)
      	      cancSottoBinAlbero(figlioSx(n));
        }
        if(!dxVuoto(n)) {
        //controllo che abbia un figlio sinistro e procedere ricorsivamente
        //con la cancellazione più in profondità
           if(figlioDx(n)->sx!=NULL||figlioDx(n)->dx!=NULL)
       	      cancSottoBinAlbero(figlioDx(n));
        }
        if(n==binRadice()) {
        //se dopo la cancellazione resta solo la radice si cancella
        // anch'essa stabilendo lo stato di albero vuoto
           radice=NULL;
           delete(n);
        } else {
     //altrimenti mi sposto sul padre e, dopo aver verificato se fosse
     //figlio destro o sinistro, cancello opportunamente anche n
           nodoBin<B> *temp=binPadre(n); // creo la var temp di tipo nodo e gli assegno il padre di n
   	       if(temp->sx==n) {
              temp->sx=NULL;
              delete(n);
           } else {
              temp->dx=NULL;
              delete(n);
           }
        }
     }
};

#endif

