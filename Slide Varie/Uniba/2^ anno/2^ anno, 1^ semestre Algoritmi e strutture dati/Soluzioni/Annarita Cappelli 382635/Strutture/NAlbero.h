/*
Autore: Annarita Cappelli 
Matricola: 382635
Nome file: NAlbero.h
Commento: Classe che implementa un albero n-ario mediante la rappresentazione 
collegata con puntatori.
*/

#ifndef NALBERO_H
#define NALBERO_H

template <class N>
struct nodoN {
       N elem;
       nodoN<N> *padre;
       nodoN<N> *primofiglio;
       nodoN<N> *fratello;
};

template <class N>
class NAlbero {
      public:
             NAlbero();  // costruttore
             ~NAlbero();  //distruttore
             
             // operatori
	         void creaNAlbero();
             bool nAlberoVuoto();
             nodoN<N> *radice();
             nodoN<N> *padre(nodoN<N> *);
             nodoN<N> *primoFiglio(nodoN<N> *);
             nodoN<N> *succFratello(nodoN<N> *);
             bool ultimoFratello(nodoN<N> *);
             bool foglia(nodoN<N> *);
             void cancSottoAlbero(nodoN<N> *);
             N leggiNodo(nodoN<N> *);
             void scriviNodo(N, nodoN<N> *);
             void insRadice();
             void insSottoAlbero(nodoN<N> *,nodoN<N> *, NAlbero<N> &);
             
             // funzione ausiliaria
             void insNodo(nodoN<N> *, nodoN<N> *);
      private:
              nodoN<N> * T;
};

template <class N>
NAlbero<N>::NAlbero() {
     creaNAlbero();
};

template <class N>
NAlbero<N>::~NAlbero() {
 //if(!alberovuoto())
  	//cancsottoalbero(radice());
};

template <class N>
void NAlbero<N>::creaNAlbero() {
     T=NULL;
};

template <class N>
bool NAlbero<N>::nAlberoVuoto() {
     return T==NULL;
};

template <class N>
nodoN<N> *NAlbero<N>::radice() {
     if(!nAlberoVuoto())
  	    return T;
     else
  	    cout<<"\n L'albero e' vuoto";
};

template <class N>
nodoN<N> *NAlbero<N>::padre(nodoN<N> *u) {
     if(!nAlberoVuoto()&& u!=radice())
  	    return u->padre;
     else
  	    return NULL;
};

template <class N>
nodoN<N> *NAlbero<N>::primoFiglio(nodoN<N> *u) {
     if(!nAlberoVuoto())
  	    return u->primofiglio;
     else
  	    return NULL;
};

template <class N>
nodoN<N> *NAlbero<N>::succFratello(nodoN<N> *u) {
     if(!nAlberoVuoto())
  	    return u->fratello;
};

template <class N>
bool NAlbero<N>::ultimoFratello(nodoN<N> *u) {
     if(succFratello(u)==NULL)
        return true;
     else
  	    return false;
};

template <class N>
bool NAlbero<N>::foglia(nodoN<N> *u) {
     return u->primofiglio==NULL;
};

template <class N>
void NAlbero<N>::cancSottoAlbero(nodoN<N> *u) {
     nodoN<N> *corrente;
     nodoN<N> *prec;
     if(!nAlberoVuoto()) {//controlla che l'albero non sia vuoto
        if(!foglia(u))
	 	   cancSottoAlbero(primoFiglio(u));
        else {
     	//individuo il primo tra i fratelli di u e lo pongo in corrente
           corrente=u->padre->primofiglio;
           if(corrente==u) //se il corrente è proprio u
       //pongo come primo figlio il fratello successivo di u
       	      u->padre->primofiglio=u->fratello;
           else {  //altrimenti
          //scandisco i fratelli fino a trovare u
              while(corrente!=u) {
             //memorizzando in prec il fratello che lo precede
	             prec=corrente;
   	             corrente=corrente->fratello;
              }
          //trovato u pongo come fratello del suo predecessore,
   	    //il fratello dello stesso u (scavalcandolo)
      	      prec->fratello=u->fratello;
       	   }
	       delete u;
        }
     }
     return;
};

template <class N>
N NAlbero<N>::leggiNodo(nodoN<N> *u) {
     if(!nAlberoVuoto())
  	    return u->elem;
};

template <class N>
void NAlbero<N>::scriviNodo(N a,nodoN<N> * u) {
     u->elem=a;
     return;
};

template <class N>
void NAlbero<N>::insRadice() {
     nodoN<N> *u=new (nodoN<N>);
     u->padre=NULL;
     u->primofiglio=NULL;
     u->fratello=NULL;
     T=u;
     return;
};

template <class N>
void NAlbero<N>::insSottoAlbero(nodoN<N> *u, nodoN<N> *v, NAlbero<N> &S) {
     if(!nAlberoVuoto()) {
	    if(u==v) {
           S.radice()->padre=u;
           S.radice()->fratello=u->primofiglio;
           u->primofiglio=S.radice();
        } else {
           S.radice()->padre=u;
           S.radice()->fratello=v->fratello;
           v->fratello=S.radice();
        }
     } else
 	    T=S.radice();
     return;
};

#endif
