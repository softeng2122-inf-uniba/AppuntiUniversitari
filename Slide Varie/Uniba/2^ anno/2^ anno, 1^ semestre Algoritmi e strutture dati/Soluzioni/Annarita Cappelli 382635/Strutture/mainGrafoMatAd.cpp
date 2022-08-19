#ifndef MAIN_H
#include "main.h"
#endif

#ifndef GRAFOMATAD_H
#include "GrafoMatAd.h"
#endif

#ifndef LISTAVET_H
#include "ListaVet.h"
#endif

void inserimento(GrafoMatAd<string> &g) {
     char risp,scelta;
     string elem;
     nodo n,v;
     risp='s';
     while (risp=='s') {
        cout << "Digitare 'n' per inserire un nodo, 'a' per inserire un arco : ";
        cin >> scelta;
        cout<<"\n";
        if (scelta=='n') {
           cout << "Inserire il nodo : ";
           cin >> n;
           g.insNodo(n);
           cout << "\n";
           cout << "Inserire l'etichetta del nodo " << n << " : ";
           cin >> elem;
           g.scriviNodo(elem, n);
           cout << "\n";
        }
        if (scelta=='a') {
           cout << "Si digiti il nodo di partenza : ";
           cin >> n;
           cout << "\n";
           cout << "Si digiti il nodo di arrivo : ";
           cin >> v;
           cout << "\n";
           g.insArco(n,v);
        }
        cout << "Si vuole continuare l'inserimento (s/n)? ";
        cin >> risp;
        cout << "\n";
     }
};

void stampa(GrafoMatAd<string> &g) {
     ListaVet<string> l;
     posizione p;
     cout << "Nodo\tEtichetta\n";
     for (int i=0; i<maxlung; i++) {
        if (g.esisteNodo(i))
           cout << "  " << i << "\t    " << g.leggiNodo(i) << "\n";
     }
     cout << "\nListe di adiacenza\n\n";
     for (int i=0; i<maxlung; i++) {
        if (g.esisteNodo(i)) {
           cout << "Nodo " << i << " : ";
	       l=g.adiacente(i);
           p=l.primoLista();
           if (l.listaVuota())
              cout << "il nodo non ha adiacenti\n";
           else {
              while (!l.fineLista(p)) {
                 cout << l.leggiLista(p) << "  ";
                 p=l.succLista(p);
              }
              cout << "\n";
           }
        }
     }
     cout << "\n";
};

// Main
int main() {
     GrafoMatAd<string> g;
     g.creaGrafo();
     cout << "\t\t* * * Inserimento degli elementi di un grafo * * *\n\n";
     inserimento(g);
     cout << "\t\t* * Stampa dei nodi e dei relativi adiacenti * *\n\n";
     stampa(g);
     system("pause");
     return 0;
}
