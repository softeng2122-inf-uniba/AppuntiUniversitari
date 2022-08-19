/*Esonero laboratorio del 13 febbraio 2003
La profondità di un albero binario è il massimo livello delle sue foglie. 
Si fornisca:
-	la realizzazione in C o C++ di tale struttura, nella quale ogni nodo 
contiene un intero (fornire prove di inserimento e stampa dell'albero); 
-	la funzione che calcola la profondità dell'albero; 
-	la funzione che restituisce il totale degli interi contenuti in tutti i nodi; 
-	la funzione che restituisce il totale degli interi contenuti nelle foglie
*/

#ifndef MAIN_H
#include "main.h"
#endif

#ifndef BINALBERO_h
#include "BinAlbero.h"
#endif

#ifndef CODAPTR_H
#include "CodaPtr.h"
#endif

typedef nodoBin<int> *nodo;

void inserisci(int e, nodo n, BinAlbero<int> &albero) {
     if (albero.binAlberoVuoto()) {
        nodo nuovo=new (nodoBin<int>);
        albero.insBinRadice(nuovo);
        albero.scriviNodo(e, albero.binRadice());
     } else {
        if (e<albero.leggiNodo(n)) {
           if (albero.sxVuoto(n)) {
              albero.insFiglioSx(n);
              albero.scriviNodo(e,albero.figlioSx(n));
           } else
              inserisci(e,albero.figlioSx(n),albero);
        }
        if (e>albero.leggiNodo(n)) {
           if (albero.dxVuoto(n)) {
              albero.insFiglioDx(n);
              albero.scriviNodo(e,albero.figlioDx(n));
           } else
              inserisci(e,albero.figlioDx(n),albero);
        }
     }
};

void visitaOutputB(BinAlbero<int> &tree, nodo n, int counter, int &numnodi) {
     int i;
     numnodi++;
     if (tree.binAlberoVuoto()) {
        cout<<"\tAlbero privo di elementi!"<<endl;
        return;
     }
     for(i=0;i<counter-1;i++)
 	    cout<<"    ";
     if(counter>0)
 	    cout<<"+---";
     cout<<tree.leggiNodo(n)<<"\n";
     if (!tree.sxVuoto(n))
  	    visitaOutputB(tree, tree.figlioSx(n),counter+1,numnodi);
     else {
	    for(i=0;i<counter;i++)
	 	   cout<<"    ";
        if(counter==0)
    	   cout<<"    ";
        if(counter>0)
    	   cout<<"+---";
        cout<<"<>\n";
     }
     if (!tree.dxVuoto(n))
 	    visitaOutputB(tree, tree.figlioDx(n),counter+1,numnodi);
     else {
	    for(i=0;i<counter;i++)
	       cout<<"    ";
        if(counter>0)
           cout<<"+---";
        cout<<"<>\n";
     }
     return;
};

int altezza(nodo n,const BinAlbero<int> &albero) {
     int prosx=0,prodx=0;
     if (albero.sxVuoto(n)&& albero.dxVuoto(n))
        return 0;
     if (!albero.sxVuoto(n)) {
        ++prosx;
        prosx=prosx+altezza(albero.figlioSx(n), albero);
     }
     if (!albero.dxVuoto(n)) {
        ++prodx;
        prodx=prodx+altezza(albero.figlioDx(n), albero);
     }
	 if (prosx>prodx)
        return prosx;
     else
        return prodx;
};

int sommaNodi(nodo p, BinAlbero<int> &t) {
     int conto=0;
     int sommasin=0;
     int sommades=0;
     CodaPtr<nodo> q;
   	 q.inCoda(p);
   	 while (!q.codaVuota()) {
        p=q.leggiCoda();
      	int a;
      	a=t.leggiNodo(p);
		conto=conto+a;
		q.fuoriCoda();
    	if (!t.sxVuoto(p)){
		   q.inCoda(t.figlioSx(p));
		}
		if (!t.dxVuoto(p)){
		   q.inCoda(t.figlioDx(p));
		}
     }
     return conto;
};

int sommaFoglie(BinAlbero<int> &t) {
    nodo p=t.binRadice();
    int conto=0;
    CodaPtr<nodo> q;
    q.inCoda(p);
    while (!q.codaVuota()) {
       p=q.leggiCoda():
       if (t.sxVuoto(p)&&t.dxVuoto(p)) {
   	      int a;
   	      a=t.leggiNodo(p);
		  conto=conto+a;
       }
        q.fuoriCoda();
    	if (!t.sxVuoto(p)){
		   q.inCoda(t.figlioSx(p));
		}
		if (!t.dxVuoto(p)){
		   q.inCoda(t.figlioDx(p));
		}
     }
     return conto;
};

int main() {
     int e;
     int addizione=0;
     BinAlbero<int> albero_01;
     char risp='y';
     int liv=0;
     int numNodi=0;
     int sommaF;
     cout<<"* * *  Acquisizione di un albero binario di ricerca di interi  * * *"<<endl;
     cout << endl;
     while ((risp=='y')||(risp=='Y')) {
        cout << "Inserisci un intero: ";
        cin >> e;
        inserisci(e, albero_01.binRadice(), albero_01);
        do {
           cout << "Altro intero? (y/n) ";
           cin >> risp;
        } while (!((risp=='y')||(risp=='Y')||(risp=='n')||(risp=='N')));
     }
     cout << "\nStampa Albero 1: \n";
     visitaOutputB(albero_01, albero_01.binRadice(), liv,numNodi);
     cout << "\n\nLa profondita' dell'albero e': " << altezza(albero_01.binRadice(), albero_01) << endl;
     addizione=sommaNodi(albero_01.binRadice(), albero_01);
     cout << "La somma di tutte le etichette dell'albero e': " << addizione << endl << endl;
     sommaF=sommaFoglie(albero_01);
     cout << "La somma delle etichette delle foglie e': " << sommaF << endl << endl;
     cout << "bye bye...." << endl << endl;
     system("pause");
     return 0;
}
     
