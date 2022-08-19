#include <cstdlib>
#include <iostream>
#include "BinAlbero.h"
#include "CodaPtr.h"

using namespace std;

void riempiBinAlbero(tipoelem a, nodoBin n, BinAlbero &t){
   if (n != NULL){
      tipoelem b;
      t.leggiNodo(n, b);
      if (a < b){
         if (t.sxVuoto(n)){
            t.insFiglioSx(n);
            t.scriviNodo(t.figlioSx(n), a);
         } else riempiBinAlbero(a, t.figlioSx(n), t);
      } else if (a > b){
         if (t.dxVuoto(n)){
            t.insFiglioDx(n);
            t.scriviNodo(t.figlioDx(n), a);            
         } else riempiBinAlbero(a, t.figlioDx(n), t);
      } else cout << "Elemento esistente: " << a << endl;      
   } else {
      n = new NodoBinPtr();
      t.insBinRadice(n);
      t.scriviNodo(t.binRadice(), a);
   }
}

void stampaBinAlbero(nodoBin p, BinAlbero &t){
	if (p != NULL){
      tipoelem a;
      t.leggiNodo(p, a);
    	cout << "(" << a;
		if (!t.sxVuoto(p)){
			stampaBinAlbero(t.figlioSx(p), t);
		} else cout << "()";
		if (!t.dxVuoto(p)){
			stampaBinAlbero(t.figlioDx(p), t);
		} else cout << "()";
		cout << ")";
	}
}

void preVisita(nodoBin p, BinAlbero &t){
	if (p != NULL){
      tipoelem a;
      t.leggiNodo(p, a);
    	cout << a << " ";
		if (!t.sxVuoto(p)){
			preVisita(t.figlioSx(p), t);
		}
		if (!t.dxVuoto(p)){
			preVisita(t.figlioDx(p), t);
		}
	}
}

void postVisita(nodoBin p, BinAlbero &t){
	if (p != NULL){
		if (!t.sxVuoto(p)){
			preVisita(t.figlioSx(p), t);
		}
		if (!t.dxVuoto(p)){
			preVisita(t.figlioDx(p), t);
		}
		tipoelem a;
      t.leggiNodo(p, a);
    	cout << a << " ";
	}
}

void inVisita(nodoBin p, BinAlbero &t){
	if (p != NULL){
    	if (!t.sxVuoto(p)){
			inVisita(t.figlioSx(p), t);
		}
		tipoelem a;
      t.leggiNodo(p, a);
    	cout << a << " ";
		if (!t.dxVuoto(p)){
			inVisita(t.figlioDx(p), t);
		}
	}
}

void ampiezzaBin(nodoBin p, BinAlbero &t){
   	CodaPtr q;
   	q.inCoda(p);
   	while (!q.codaVuota()){
      	q.leggiCoda(p);
      	tipoelem a;
      	t.leggiNodo(p,a);
		cout << a << " ";
		q.fuoriCoda();
    	if (!t.sxVuoto(p)){
			q.inCoda(t.figlioSx(p));
		}
		if (!t.dxVuoto(p)){
			q.inCoda(t.figlioDx(p));
		}
   }
}

bool trovaParola(tipoelem &a, nodoBin n, BinAlbero &t, int &i, nodoBin &pota){
   if (n != NULL){
      tipoelem b;
      t.leggiNodo(n, b);
      if (a < b){
         if (!t.sxVuoto(n)) 
            return (false || trovaParola(a, t.figlioSx(n), t, ++i, pota));
         else return false;
      } else if (a > b){
         if (!t.dxVuoto(n))
            return (false || trovaParola(a, t.figlioDx(n), t, ++i, pota));
         else return false;
      } else {
         pota = n;
         return true;
      }      
   } else return false;
}

void inserisciBinAlbero(BinAlbero &t){
   char risp = 's';
   tipoelem a;
   while ((risp == 's') || (risp == 'S')){
      cout << "Inserisci elemento: ";
      cin >> a;
      riempiBinAlbero(a, t.binRadice(), t);
      do{
         cout << "Altro? (S/N) ";
         cin >> risp;
      }
      while (!((risp == 's') || (risp == 'S') || (risp == 'N') || (risp == 'n')));
   }
}

int main(int argc, char *argv[])
{
   BinAlbero t;
   tipoelem a;
   int i = 0;
   char risp;
   nodoBin pota;
   cout << "Inserimento ordinato dell'albero binario T:" << endl;
   inserisciBinAlbero(t);
   cout << endl << "Stampa dell'albero appena inserito:" << endl << "T: ";
   stampaBinAlbero(t.binRadice(), t);
   cout << endl << endl << "Visite:" << endl << "preVisita -> T: ";
   preVisita(t.binRadice(), t);
   cout << endl << "postVisita -> T: ";
   postVisita(t.binRadice(), t);
   cout << endl << "inVisita -> T: ";
   inVisita(t.binRadice(), t);
   cout << endl << "Ampiezza -> T: ";
   ampiezzaBin(t.binRadice(), t);
   cout << endl << endl << "Ricerca di una parola:" << endl << "Parola: ";
   cin >> a;
   if (trovaParola(a, t.binRadice(), t, i, pota)){
      cout << a << " trovata al livello " << i << endl;
      do{
         cout << endl << "Vuoi potare l'albero a partire da questa parola? (S/N) ";
         cin >> risp;
      } while (!((risp == 'S') || (risp == 's') || (risp == 'N') || (risp == 'n')));
      if ((risp == 's') || (risp == 'S')){
         t.cancSottoBinAlbero(pota);
         cout << "Albero potato!" << endl << (!t.binAlberoVuoto()? "T: ": "Albero vuoto");
         stampaBinAlbero(t.binRadice(), t);
         cout << endl;
      }
   } else
      cout << a << " non trovata" << endl;
   system("PAUSE");
   return 0;
}

