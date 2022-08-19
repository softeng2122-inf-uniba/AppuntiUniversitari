#include <cstdlib>
#include <iostream>
#include "NAlbero.h"
#include "CodaPtr.h"

using namespace std;

void inserisciNAlbero(nodoN n, NAlbero &t){
   tipoelem a;
   if (t.nAlberoVuoto()){
      cout << "Inserisci etichetta radice: ";
      cin >> a;
      if (n == NIL)
         n = t.newNodo();
      t.insRadice(n);
      t.scriviNodo(n,a);
      inserisciNAlbero(n, t);
   } else{
      int i, j;
      cout << "Quanti figli ha " << t.leggiNodo(n) << "? ";
      cin >> j;
      if (j > 0){
         for (i = 1; i <= j; i++){
            nodoN m = t.newNodo();
            cout << "Inserisci " << i << "^ figlio di " << t.leggiNodo(n) <<": ";
            cin >> a;
            if (i == 1)
               t.insPrimoSottoAlbero(n, m);
            else{
               nodoN p = t.primoFiglio(n);
               while (!(t.ultimoFratello(p)))
                  p = t.succFratello(p);
               t.insSottoAlbero(p, m);
            }
            cout << endl;
         	t.scriviNodo(m, a);           
            inserisciNAlbero(m, t);
         }
      } else cout << endl;
   } 
}

void stampaNAlbero(nodoN n, NAlbero &t){
   if (n != NIL){
      while (n != NIL){
         cout << "(" << t.leggiNodo(n);
         stampaNAlbero(t.primoFiglio(n), t);
         cout << ")";
         n = t.succFratello(n);
      }
	} else cout << "()";
}

void preVisita(nodoN n, NAlbero &t){
   if (n != NIL)
      while (n != NIL){
         cout << t.leggiNodo(n) << " "; 
         preVisita(t.primoFiglio(n), t);
         n = t.succFratello(n);
      }
}

void postVisita(nodoN n, NAlbero &t){
   if (n != NIL)
     	while (n != NIL){
         postVisita(t.primoFiglio(n), t);
         cout << t.leggiNodo(n) << " ";
         n = t.succFratello(n);
      }
}

void inVisita(nodoN n, NAlbero &t){
   if (n != NIL)
      if (!t.foglia(n)){
         inVisita(t.primoFiglio(n), t);
         cout << t.leggiNodo(n) << " ";
         n = t.primoFiglio(n);
         while (!t.ultimoFratello(n)){
         	n = t.succFratello(n);
            inVisita(n, t);
         }
      } 
   else 
      cout << t.leggiNodo(n) << " ";
}


void ampiezzaN(nodoN p, NAlbero &t){
   CodaPtr q;
	q.inCoda(p);
	while (!q.codaVuota()){
      q.leggiCoda(p);
	   cout << t.leggiNodo(p) << " ";
	   q.fuoriCoda();
	   if (!t.foglia(p)){
         nodoN x = t.primoFiglio(p);
 	      while (!t.ultimoFratello(x)){
            q.inCoda(x);
            x = t.succFratello(x);
         }
     	q.inCoda(x);
 	   }
	}
}

void cancella(tipoelem a, NAlbero &t, nodoN n, int prof){
   char risp;
   cout << a << " trovata al livello " << prof << endl;
   do{
      cout << endl << "Vuoi potare l'albero a partire da questa parola? (S/N) ";
      cin >> risp;
   } while (!((risp == 'S') || (risp == 's') || (risp == 'N') || (risp == 'n')));
   if ((risp == 's') || (risp == 'S')){
      t.cancSottoAlbero(n);
      cout << "Albero potato!" << endl << "T: ";
      } else
         cout << "Albero non potato!" << endl << "T: ";
      stampaNAlbero(t.radice(), t);
}

bool profNodo(tipoelem a, nodoN n, int &prof, NAlbero &t, bool &cancellata){
   bool trovata = false;
   cancellata = false;
   if (n != NIL){
      while ((n != NIL)&& !trovata){
         tipoelem b = t.leggiNodo(n);
         if (b == a)
            trovata = true;
         else {
            trovata = profNodo(a, t.primoFiglio(n), ++prof, t, cancellata);
            if (!trovata){
               prof--;
               n = t.succFratello(n);
            }
         }
      }
      if (trovata && !cancellata){
         cancella(a, t, n, prof);
         cancellata = true;
      }
   }
   return trovata;
}

int main(int argc, char *argv[])
{
   NAlbero t;
   tipoelem a;
   int i = 0;
   bool cancellata;
   char risp;
   nodoN n = t.radice();
   cout << "Inserimento dell'albero n-ario T:" << endl;
   inserisciNAlbero(t.radice(), t);
   cout << endl << "Stampa dell'albero appena inserito:" << endl << "T: ";
   stampaNAlbero(t.radice(), t);
   cout << endl << endl << "Visite:" << endl << "preVisita  -> T: ";
   preVisita(t.radice(), t);
   cout << endl << "postVisita -> T: ";
   postVisita(t.radice(), t);
   cout << endl << "inVisita   -> T: ";
   inVisita(t.radice(), t);
   cout << endl << "Ampiezza   -> T: ";
   ampiezzaN(t.radice(), t);
   cout << endl << endl << "Ricerca di una parola:" << endl << "Parola: ";
   cin >> a;
   if (!profNodo(a, t.radice(), i, t, cancellata))      
      cout << "Parola " << a << " non trovata";
   cout << endl;
   system("PAUSE");
   return 0;
}
