#include "GrafoPtr.h"
#include <iostream>

using namespace std;

// implementazione dei metodi della classe NodoAdiacenti
NodoAdiacenti::NodoAdiacenti(){
   peso = NIL;
   ptrNodo = NULL;
   successivo = NULL;
}

NodoAdiacenti::~NodoAdiacenti(){
}

void NodoAdiacenti::setPtrNodo(NodoGrafo n){
	ptrNodo = n;
}

NodoGrafo NodoAdiacenti::getPtrNodo(){
	return ptrNodo;	
}

void NodoAdiacenti::setPeso(tipoPeso p){
	peso = p;
}

tipoPeso NodoAdiacenti::getPeso(){
	return peso;
}

NodoAd NodoAdiacenti::getSuccessivo(){
   return successivo;
}

void NodoAdiacenti::setSuccessivo(NodoAd p){
   successivo = p;     
}
// fine implementazione metodi NodoAdiacenti

// Implementazione dei metodi ListaAdiacenti
ListaAdiacenti::ListaAdiacenti(){
	creaLista();
}

ListaAdiacenti::~ListaAdiacenti(){
	NodoAd q;
	while(primo!=NULL){
		q = primo->getSuccessivo();
		delete primo;
		primo = q;
	}
}

void ListaAdiacenti::creaLista(){
	primo = NULL;
}

bool ListaAdiacenti::listaVuota(){
	return (primo == NULL);
}

NodoAd ListaAdiacenti::primoLista(){
	return primo;
}

NodoAd ListaAdiacenti::predLista(NodoAd p){
	if(p!=primo){
		NodoAd q = primo;
		while ((q->getSuccessivo()!=p)&&(q!=NULL))
			q = q->getSuccessivo();
		return q;
	}else 
		return NULL;
}

NodoAd ListaAdiacenti::succLista(NodoAd p){
	return p->getSuccessivo();
}

bool ListaAdiacenti::fineLista(NodoAd p){
	return p == NULL;
}

void ListaAdiacenti::insLista(NodoGrafo n, tipoPeso p, NodoAd m){
	NodoAd q = new NodoAdiacenti();
	q->setPtrNodo(n);
	q->setPeso(p);
	q->setSuccessivo(m); 
	if (m==primo){
		primo = q;
	}else{
		m = predLista(m);
		m->setSuccessivo(q);
	}
}

bool ListaAdiacenti::cancLista(NodoAd p){
	if (p != NULL){
		if(p==primo){
			primo = p->getSuccessivo();
		} else {
			NodoAd q;
			q = predLista(p);
			q->setSuccessivo(p->getSuccessivo());
		}
		delete p;
		return true;
	}else return false; //ERRORE!	
}

bool ListaAdiacenti::scriviLista(NodoGrafo n, tipoPeso p, NodoAd m){
	if(m != NULL){
		m->setPtrNodo(n);
		m->setPeso(p);
		return true;
	}else return false; //ERRORE!
}

bool ListaAdiacenti::leggiLista(NodoGrafo &n, tipoPeso &p, NodoAd m){
	if(m != NULL){
		n = m->getPtrNodo();
		p = m->getPeso();
		return true;
	}else return false; //ERRORE!
}

ListaAdiacenti &ListaAdiacenti::operator=(ListaAdiacenti &l){
	NodoAd m;
	while(primo!=NULL){
		m = primo->getSuccessivo();
		delete primo;
		primo = m;
	}	
	m = l.primoLista();
	tipoPeso p;
	NodoGrafo n;
	while (!l.fineLista(m)){
		l.leggiLista(n,p,m);
		insLista(n, p, NULL);
		m = l.succLista(m);
	}
	return *this;
}

NodoAd ListaAdiacenti::pos(int i){ // mapping della NodoAd
	if(i>=1){
		NodoAd p = primo;
		int j;
		for(j = 0; (j<i)&&(p!=NULL); j++){
			p = p->getSuccessivo();
		}
		return p;
	}else {
	 	return NULL;
	}
}
// Fine implementazione ListaAdiacenti

// implementazione dei metodi della classe NodoGrafoPtr
NodoGrafoPtr::NodoGrafoPtr(){
	labelNodo = "";
	visitato = false;
  	successivo = NULL;
}

NodoGrafoPtr::~NodoGrafoPtr(){
	adiacenti.~ListaAdiacenti();
}

void NodoGrafoPtr::setLabelNodo(label l){
	labelNodo = l;
}

label NodoGrafoPtr::getLabelNodo(){
	return labelNodo;
}

void NodoGrafoPtr::setVisitato(bool b){
	visitato = b;
}

bool NodoGrafoPtr::getVisitato(){
	return visitato;
}

void NodoGrafoPtr::setAdiacenti(ListaAdiacenti &l){
	adiacenti = l;
}

void NodoGrafoPtr::getAdiacenti(ListaAdiacenti &l){
	l = adiacenti;
}

NodoGrafo NodoGrafoPtr::getSuccessivo(){
   return successivo;
}

void NodoGrafoPtr::setSuccessivo(NodoGrafo p){
   successivo = p;     
}
// fine implementazione metodi NodoGrafoPtr

// Implementazione dei metodi del grafo
GrafoPtr::GrafoPtr(){
	creaGrafo();
}

GrafoPtr::~GrafoPtr(){
	NodoGrafo n;
	while(grafo != NULL){
		n = grafo->getSuccessivo();
		delete grafo;
		grafo = n;
	}
}

void GrafoPtr::creaGrafo(){
	grafo = NULL;
}

bool GrafoPtr::grafoVuoto(){
	return (grafo == NULL);
}

bool GrafoPtr::esisteNodo(NodoGrafo n){
	NodoGrafo m = grafo;
	while((m != NULL) && (m != n)){
		m = m->getSuccessivo();
	}
	return (m != NULL);
}

bool GrafoPtr::esisteArco(NodoGrafo n, NodoGrafo m){
	if (esisteNodo(n) && esisteNodo(m)){
		ListaAdiacenti l;
		n->getAdiacenti(l);
		NodoAd p = l.primoLista();
		while(!l.fineLista(p) && p->getPtrNodo()!=m){
			p = l.succLista(p);
		}
		return !l.fineLista(p);
	} else return false;
}

bool GrafoPtr::insNodo(NodoGrafo n){
	if(!esisteNodo(n)){
		n->setSuccessivo(grafo);
		grafo = n;
		return true;
	} else return false;
}

bool GrafoPtr::insArco(NodoGrafo n, NodoGrafo m){
	if(!esisteArco(n,m)){
		ListaAdiacenti l;
		n->getAdiacenti(l);
		l.insLista(m, NIL, NULL); // inserimento in coda
		n->setAdiacenti(l);
		return true;
	} else return false;
}

bool GrafoPtr::cancNodo(NodoGrafo n){
	if(esisteNodo(n)){
		if(n != grafo){
			NodoGrafo m = grafo;
			while(m->getSuccessivo()!=n)
				m = m->getSuccessivo();
			m->setSuccessivo(n->getSuccessivo());
		} else 
			grafo = grafo->getSuccessivo();
		delete n;
		return true;
	} else return false;
}

bool GrafoPtr::cancArco(NodoGrafo n, NodoGrafo m){
	if(esisteArco(n,m)){
		ListaAdiacenti l;
		n->getAdiacenti(l);
		NodoAd p = l.primoLista();
		while(p->getPtrNodo() != m)
			p = l.succLista(p);
		l.cancLista(p);
		n->setAdiacenti(l);
		return true;
	} else return false;
}

void GrafoPtr::adiacenti(NodoGrafo n, ListaAdiacenti &l){
	n->getAdiacenti(l);
}

bool GrafoPtr::scriviNodo(NodoGrafo n, label l){
	if(esisteNodo(n)){
		n->setLabelNodo(l);
		return true;
	} else return false;
}

bool GrafoPtr::leggiNodo(NodoGrafo n, label &l){
	if(esisteNodo(n)){
		l = n->getLabelNodo();
		return true;
	} else return false;	
}

bool GrafoPtr::scriviArco(NodoGrafo n, NodoGrafo m, tipoPeso p){
	if(esisteArco(n,m)){
		ListaAdiacenti l;
		n->getAdiacenti(l);
		NodoAd q = l.primoLista();
		while(q->getPtrNodo()!=m)
			q = q->getSuccessivo();
		l.scriviLista(m,p,q);
		n->setAdiacenti(l);
		return true;
	}else return false;
}

bool GrafoPtr::leggiArco(NodoGrafo n, NodoGrafo m, tipoPeso &p){
	if(esisteArco(n,m)){
		ListaAdiacenti l;
		n->getAdiacenti(l);
		NodoAd q = l.primoLista();
		while(q->getPtrNodo()!=m)
			q = q->getSuccessivo();
		p = q->getPeso();		
		return true;
	}else return false;	
}

bool GrafoPtr::getVisitato(NodoGrafo n){
	return n->getVisitato();
}

void GrafoPtr::setVisitato(bool b, NodoGrafo n){
	if(esisteNodo(n))
		n->setVisitato(b);
}

NodoGrafo GrafoPtr::getGrafo(){
	return grafo;
}

NodoGrafo GrafoPtr::pos(label l){
	NodoGrafo n = grafo;
	while((n != NULL)&&(n->getLabelNodo()!=l))
		n = n->getSuccessivo();
	return n; // restituisce NULL se l non trova corrispondenza
}

void GrafoPtr::azzeraVisitato(){
	NodoGrafo n = grafo;
	while(n != NULL){
		n->setVisitato(false);
		n = n->getSuccessivo();
	}
}

GrafoPtr &GrafoPtr::operator=(GrafoPtr &g){
	NodoGrafo n;
	while(grafo != NULL){
		n = grafo->getSuccessivo();
		delete grafo;
		grafo = n;
	}
	n = g.getGrafo();
	NodoGrafo m;
	ListaAdiacenti l;
	while (n != NULL){
		m = new NodoGrafoPtr();
		m->setLabelNodo(n->getLabelNodo());
		m->setVisitato(false);
		n->getAdiacenti(l);
		m->setAdiacenti(l);
		insNodo(m);
		n = n->getSuccessivo();
	}
	return *this;
}
