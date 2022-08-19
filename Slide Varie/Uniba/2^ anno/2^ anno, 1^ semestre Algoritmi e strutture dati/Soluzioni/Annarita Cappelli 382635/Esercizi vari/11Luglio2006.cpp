/*
Appello laboratorio 11 luglio 2006
Scrivere un programma in C++ che, data una lista ordinata di elementi di tipo 
intero costruisca un albero binario di ricerca. Implementare le seguenti 
funzioni/metodi:
1. Lista caricaElementi() - crea una lista costituita dai seguenti 
elementi: 4, 7, 9, 10, 13, 14, 15;
2. int lunghezza (Lista l, pos inizio, pos fine) - restituisce la lunghezza 
della sottolista l' di l costituita dagli elementi ordinati compresi tra le 
posizioni inizio e fine della lista l;
3. pos salta (Lista l, pos inizio, int k) - restituisce la posizione 
dell'elemento della lista l ottenuta saltando k elementi a partire dalla 
posizione inizio;
4. pos mediano (Lista l, pos inizio, pos fine) - restituisce la posizione 
dell'elemento mediano della lista l; (suggerimento: utilizzare le 
funzioni/metodi lunghezza e salta);
5. Lista creaSottoLista(Lista l, pos inizio, pos fine) - restituisce la 
sottolista l' di l costituita dagli elementi compresi tra le posizioni inizio 
e fine della lista l;
6. Albero caricaAlberoBinario(Lista l) - costruisce un albero binario di 
ricerca utilizzando gli elementi presenti nella lista ordinata;
Algoritmo per caricare l'albero binario:
T = caricaAlberoBinario(partizione sinistra di L rispetto a mediano(L))
U = caricaAlberoBinario(partizione destra di L rispetto a mediano(L))
T' = costrBinAlbero(T,U) in cui la radice u di T' è mediano(L)
7. stampaAlberoBinario(Albero t) - stampa l'albero binario t;
Si è ammessi risolvendo correttamente i primi quattro punti (con riserva 
risolvendo correttamente solo i primi tre).
*/

#ifndef MAIN_H
#include "main.h"
#endif

#ifndef LISTAPTR_H
#include "ListaPtr.h"
#endif

#ifndef BINALBERO_H
#include "BinAlbero.h"
#endif

typedef lpcell<int> *posizione;

void stampa(ListaPtr<int> &l) {
     cout << endl;
     cout << "*** Stampa della lista ***" << endl << endl;
     if (l.listaVuota()) {
        cout << "Spiacente, ma la lista da stampare e' vuota!" << endl;
        return;
     } else {
        posizione p=l.primoLista();
        while (!l.fineLista(p)) {
           cout << l.leggiLista(p) << " ";
           p=l.succLista(p);
        }
        cout << endl;
        cout << "Lista stampata con successo!" << endl;
        cout << endl;
     }
};

ListaPtr<int> &caricaElementi() {
     ListaPtr<int> *l=new(ListaPtr<int>);
     l->insLista(4, l->pos(1));
     l->insLista(7, l->pos(2));
     l->insLista(9, l->pos(3));
     l->insLista(10, l->pos(4));
     l->insLista(13, l->pos(5));
     l->insLista(14, l->pos(6));
     l->insLista(15, l->pos(7));
     return (*l);
};

int lunghezza(ListaPtr<int> &l, posizione inizio, posizione fine) {
     int c=0;
     posizione p=inizio;
     while (p!=fine) {
        c++;
        p=l.succLista(p);
     }
     if (p==fine)
        c++;
     return c;
};

posizione salta(ListaPtr<int> &l, posizione inizio, int k) {
     posizione p=inizio;
     for (int j=0; j<k; j++)
        p=l.succLista(p);
     return p;
};

posizione mediano(ListaPtr<int> &l, posizione inizio, posizione fine) {
     posizione ret;
     int m;
     int len=lunghezza(l, inizio, fine);
     m=len/2;
     ret=salta(l, inizio, m);
     return ret;
};     

ListaPtr<int> &creaSottoLista(ListaPtr<int> &l, posizione inizio, posizione fine) {
     ListaPtr<int> *m=new (ListaPtr<int>);
     posizione q=m->primoLista();
     int a;
     while (inizio!=fine) {
        a=l.leggiLista(inizio);
        inizio=l.succLista(inizio);
        m->insLista(a, q);
        q=m->succLista(q);
     }
     if (inizio==fine) {
        a=l.leggiLista(inizio);
        m->insLista(a, q);
     }
     return (*m);
};

void riempiBinAlbero(int e, nodoBin<int> *n, BinAlbero<int> &albero) {
     if (albero.binAlberoVuoto()) {
        nodoBin<int> *nuovo=new (nodoBin<int>);
        albero.insBinRadice(nuovo);
        albero.scriviNodo(e, albero.binRadice());
     } else {
        if (e<albero.leggiNodo(n)) {
           if (albero.sxVuoto(n)) {
              albero.insFiglioSx(n);
              albero.scriviNodo(e, albero.figlioSx(n));
           } else
              riempiBinAlbero(e, albero.figlioSx(n), albero);
        }
        if (e>albero.leggiNodo(n)) {
           if (albero.dxVuoto(n)) {
              albero.insFiglioDx(n);
              albero.scriviNodo(e,albero.figlioDx(n));
           } else
              riempiBinAlbero(e,albero.figlioDx(n),albero);
        }
     }
};

void stampaBinAlbero(BinAlbero<int> &tree, nodoBin<int> *n, int counter, int &numnodi) {
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
  	    stampaBinAlbero(tree, tree.figlioSx(n),counter+1,numnodi);
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
 	    stampaBinAlbero(tree, tree.figlioDx(n),counter+1,numnodi);
     else {
	    for(i=0;i<counter;i++)
	       cout<<"    ";
        if(counter>0)
           cout<<"+---";
        cout<<"<>\n";
     }
     return;
};

void inserisciBinAlbero(ListaPtr<int> &l, BinAlbero<int> &t){
   int a;  // elemento dell'albero
   int b;     // elemento della lista
   posizione p = l.primoLista();
   
   while (!l.fineLista(p)) {
      b=l.leggiLista(p);
      cout << "Elemento da inserire: " << b << endl;
      riempiBinAlbero(b, t.binRadice(), t);
      p = l.succLista(p);
   }
};

void costrBinAlbero(BinAlbero<int> &T, int a, BinAlbero<int> &U, BinAlbero<int> &V) {
   nodoBin<int> *t = new (nodoBin<int>);
   nodoBin<int> *u;
   nodoBin<int> *v;
   u = U.binRadice();
   v = V.binRadice();

   T.insBinRadice(t);
   T.scriviNodo(a, T.binRadice());

   t->sx=u;
   t->dx=v;

   if (!U.binAlberoVuoto()) u->padre=t;
   if (!V.binAlberoVuoto()) v->padre=t;   
};     

int main () {
    ListaPtr<int> l, s, d;
    l=caricaElementi();
    int len, inizio, fine, k;
    int liv=0;
    int numNodi=0;
    int a, b;
    BinAlbero<int> T, U, V;
    posizione pos;
    posizione p, q;
    stampa(l);
    cout << "Inserisci posizione inizio sotto lista: ";
    cin >> inizio;
    cout << "Inserisci posizione fine sotto lista: ";
    cin >> fine;
    len=lunghezza(l, l.pos(inizio), l.pos(fine));
    cout << "La sottolista L' ha lunghezza " << len << "!" << endl;
    cout << endl;
    cout << "Inserisci posizione da cui saltare: ";
    cin >> inizio;
    cout << "Di quante posizioni vuoi saltare? ";
    cin >> k;
    pos=salta(l, l.pos(inizio), k);
    cout << "La posizione trovata contiene l'elemento: " << l.leggiLista(pos) << endl;
    cout << endl;
    cout << "Inserisci posizione inizio sotto lista: ";
    cin >> inizio;
    cout << "Inserisci posizione fine sotto lista: ";
    cin >> fine;
    pos=mediano(l, l.pos(inizio), l.pos(fine));
    cout << "La posizione del punto medio, contiene l'elemento: " << l.leggiLista(pos) << endl;
    cout << endl;
    cout << "Inserisci posizione inizio sotto lista: ";
    cin >> inizio;
    cout << "Inserisci posizione fine sotto lista: ";
    cin >> fine;
    s=creaSottoLista(l, l.pos(inizio), l.pos(fine));
    stampa(s); 
    cout << endl;
    cout << "Creo la partizione sinistra della lista: ";
    pos=mediano(l, l.primoLista(), l.pos(7));
    s=creaSottoLista(l, l.primoLista(), l.predLista(pos));
    stampa(s);
    cout << "Creo la partizione destra della lista: ";
    d=creaSottoLista(l, l.succLista(pos), l.pos(7));
    stampa(d);
    cout << endl;
    system("pause");
    system("cls");
    cout << endl << "Inserimento ordinato dell'albero binario U:" << endl;
    inserisciBinAlbero(s, U);
    cout << endl << "Stampa dell'albero appena inserito:" << endl;
    stampaBinAlbero(U, U.binRadice(), liv, numNodi);
    cout << endl << "Inserimento ordinato dell'albero binario V:" << endl;
    inserisciBinAlbero(d, V);
    cout << endl << "Stampa dell'albero appena inserito:" << endl;
    stampaBinAlbero(V, V.binRadice(), liv, numNodi);
    cout << endl << endl;
    cout << "Costuzione dell'albero T a partire dagli alberi U e V" << endl;
    a=l.leggiLista(pos);
    costrBinAlbero(T, a, U, V);
    stampaBinAlbero(T, T.binRadice(), liv, numNodi);   
    cout << endl;
    system("pause");
    return 0;
}
