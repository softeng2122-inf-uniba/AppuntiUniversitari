/*2/2/2005 - Traccia A
Si vuole rappresentare con un grafo la situazione in un campionato di calcio a 
N squadre. I nodi saranno le squadre rappresentate tramite il loro nome, sugli 
archi ci saranno le partite giocate con i risultati. Implementare le seguenti 
funzioni/metodi: 
- Acquisizione del grafo; 
- Stampa del grafo visualizzando l'elenco delle partite con i risultati; 
- Data una squadra, stampare il suo punteggio in classifica (vittoria 3 punti, 
pareggio 1 punto, sconfitta 0 punti); 
- Visualizzare la/le squadre con la migliore difesa (hanno subito meno gol) e 
la/le squadre con il miglior attacco (hanno fatto più gol) 
Dimostrare il funzionamento delle funzioni mediante chiamate alle funzioni 
realizzate nel main per almeno un campionato a 8 squadre.
*/

#ifndef MAIN_H
#include "main.h"
#endif

#ifndef GRAFOADIACENTIMOD_H
#include "GrafoAdiacentiMod.h"
#endif

#ifndef CODAPTR_H
#include "CodaPtr.h"
#endif

#ifndef LISTAPTR_H
#include "ListaPtr.h"
#endif

struct tipoLista {
       Nodo nodoL;
       int fatti;
       int subiti;
};

void insGrafo(GrafoAdiacenti<string> &g, int &num) {
     int index, part, arr, w, z;
     string a;
     char risp = 's';
     cout << "Inserimento nodi:" << endl;
     cout << "-----------------" << endl;
     do {
        cout << endl << "Quante squadre si voglione inserire? (il numero deve essere multiplo di 2) ";
        cin >> num;
     } while (!(num%2==0));
     for (int i=0; i<num; i++) {
        index= i+1;
        cout << "Inserisci nome squadra: ";
        cin >> a;
        g.insNodo(index);
        g.scriviNodo(index, a);
     }
     risp = 's';
     cout << endl;
     cout << "Inserimento archi:" << endl;
     cout << "------------------" << endl;
     while ((risp == 's') || (risp =='S')) {
        do {
           cout << "Inserisci numero nodo squadra che gioca in casa: ";
           cin >> part;
        } while (!((part >= 0) && (part < MAXNODI) && (g.esisteNodo(part))));
        do {
           cout << "Inserisci numero nodo squadra che gioca fuori casa: ";
           cin >> arr;
        } while (!((arr >= 0) && (arr < MAXNODI) && (g.esisteNodo(arr))));
        cout << "Inserisci risultato partita (" << part << ", " << arr << "): " << endl;
        cout << "Goals del nodo " << part << ": ";
        cin >> w;
        cout << "Goals del nodo " << arr << ": ";
        cin >> z;
        if (!g.insArco(part, arr))
           cout << "Arco esistente" << endl;
        else
           g.scriviArco(part, arr, w, z);
        do {
           cout << "Altro arco? (S/N) ";
           cin >> risp;
        } while (!((risp =='s') || (risp == 'S') || (risp == 'n') || (risp == 'N')));
     }
};

void stampaArchi(int i, GrafoAdiacenti<string> &g) {
     ListaAdiacenti<tipo> l;
     g.adiacenti(i, l);
     NodoAdiacenti<tipo> *p = l.primoLista();
	 tipo a;
	 while (!l.fineLista(p)) {
		l.leggiLista(a, p);
		cout << "(" << i << ", " << a.nodoCur << ") con peso " << a.peso1 << " - " << a.peso2 << endl;
		p = l.succLista(p);
	 }
};

void stampaGrafo(GrafoAdiacenti<string> &g) {
     if (!g.grafoVuoto()) {
        string a;
        cout << "Insieme nodi (N):" << endl;
        for (int i = 0; i < MAXNODI; i++) {
           if (g.esisteNodo(i)) {
              g.leggiNodo(i, a);
              cout << i << ". " << a << endl;
           }
        }
        cout << endl << "Insieme archi (A): " << endl;
        for (int i = 0; i < MAXNODI; i++) {
           if (g.esisteNodo(i))
              stampaArchi(i, g);
        }
     } else cout << "Grafo vuoto" << endl;
};

void punteggio(Nodo u, GrafoAdiacenti<string> &g, int &points) {
     ListaAdiacenti<tipo> l;
     g.adiacenti(u, l);
     int w, z;
     NodoAdiacenti<tipo> *p = l.primoLista();
	 tipo a;
	 while (!l.fineLista(p)) {
		l.leggiLista(a, p);
		g.leggiArco(a.nodoCur, u, w, z);
		if (a.peso1>a.peso2) 
		   points=points+3;
        if (a.peso1==a.peso2) 
           points=points+1;
        if (w<z) 
           points=points+3;
        if (w==z) 
           points=points+1;
		p = l.succLista(p);
	 }
};

void contoGoals(Nodo u, GrafoAdiacenti<string> &g, tipoLista &elem) {
     ListaAdiacenti<tipo> l, lis;
     CodaPtr<Nodo> c;
     g.adiacenti(u, l);
     Nodo v;
     int w, z;
     elem.nodoL=u;
     elem.fatti=0;
     elem.subiti=0;
     NodoAdiacenti<tipo> *p = l.primoLista();
     NodoAdiacenti<tipo> *q=lis.primoLista();
	 tipo a, b;
	 while (!l.fineLista(p)) {
		l.leggiLista(a, p);
		elem.fatti=elem.fatti+a.peso1;
		elem.subiti=elem.subiti+a.peso2;
		c.inCoda(a.nodoCur);
		p = l.succLista(p);
	 }
	 while (!c.codaVuota()) {
        v=c.leggiCoda();
        g.leggiArco(v, u, w, z);
        elem.fatti=elem.fatti+z;
        elem.subiti=elem.subiti+w;
        c.fuoriCoda();
     }
};

void maxFatti(ListaPtr<tipoLista> l, tipoLista &max) {
     lpcell<tipoLista> *p=l.primoLista();
     tipoLista a=l.leggiLista(p);
     max.fatti=a.fatti;
     max.nodoL=a.nodoL;
     max.subiti=a.subiti;
     while (!l.fineLista(p)) {
        a=l.leggiLista(p);
        if (max.fatti<a.fatti) {
           max.nodoL=a.nodoL;
           max.fatti=a.fatti;
           max.subiti=a.subiti;
        }
        p=l.succLista(p);
     }
};      

void minSubiti(ListaPtr<tipoLista> l, tipoLista &min) {
     lpcell<tipoLista> *p=l.primoLista();
     tipoLista a=l.leggiLista(p);
     min.fatti=a.fatti;
     min.nodoL=a.nodoL;
     min.subiti=a.subiti;
     while (!l.fineLista(p)) {
        a=l.leggiLista(p);
        if (min.subiti>a.subiti) {
           min.nodoL=a.nodoL;
           min.fatti=a.fatti;
           min.subiti=a.subiti;
        }
        p=l.succLista(p);
     }
};      

int main(int argc, char *argv[]) {
     GrafoAdiacenti<string> g;
     ListaPtr<tipoLista> lista;
     string a;
     Nodo n;
     tipoLista elemento;
     int f, s;
     int num=0;
     int points=0;
     cout << "Inserimento del grafo G:" << endl << endl;
     insGrafo(g, num);
     system("PAUSE");
     system("CLS");
     cout << "Stampa del grafo G:" << endl << endl;
     stampaGrafo(g);
     cout << endl;
     cout << "Inserisci numero nodo della squadra di cui vuoi conoscere il punteggio in classifica: ";
     cin >> n;
     punteggio(n, g, points);
     g.leggiNodo(n, a);
     cout << "La squadra " << a << " ha " << points << " punti in classifica!" << endl;
     cout << endl;
     lpcell<tipoLista> *p=lista.primoLista();
     for (int i=1; i<=num; i++) {
        contoGoals(i, g, elemento);
        lista.insLista(elemento, p);
        p=lista.succLista(p);
     }
     maxFatti(lista, elemento);
     g.leggiNodo(elemento.nodoL, a);
     cout << "La squadra con il migliore attacco e': " << a << " con " << elemento.fatti << " goals fatti!" << endl;
     minSubiti(lista, elemento);
     g.leggiNodo(elemento.nodoL, a);
     cout << "La squadra con la migliore difesa e': " << a << " con " << elemento.subiti << " goals subiti!" << endl; 
     system("pause");
     return 0;
};
