/*13/1/2005
Sia dato un grafo rappresentante 15 stazioni ferroviarie ed i relativi 
collegamenti diretti. Ciascuna stazione ha un nome ed e' caratterizzata dal 
numero di passeggeri in partenza. Implementare le seguenti funzioni/metodi: 
- Acquisizione del grafo; 
- Stampa del grafo visualizzando l'elenco dei nodi e quello degli archi; 
Date una stazione di partenza ed una di arrivo, visualizzare:
- percorso (stazioni attraversate); 
- numero di passeggeri per ciascuna stazione; 
- numero totale di passeggeri lungo il percorso; 
Dimostrare il funzionamento delle funzioni mediante chiamate alle funzioni 
realizzate nel main.
*/

#ifndef MAIN_H
#include "main.h"
#endif

#ifndef GRAFOADIACENTI_H
#include "GrafoAdiacenti.h"
#endif

#ifndef CODAPTR_H
#include "CodaPtr.h"
#endif

#define MAXINT 32767

typedef int distanze[MAXNODI];
typedef Nodo padri[MAXNODI];

struct stazione {
     string nome;
     int numPasseggeri;
};

void insGrafo(GrafoAdiacenti<stazione> &g, int &numNodi) {
     int i = 0;
     int index, part, arr, w;
     stazione a;
     char risp = 's';
     cout << "Inserimento nodi:" << endl;
     cout << "-----------------" << endl;
     while ((i < MAXNODI) && ((risp == 's') || (risp == 'S'))) {
        numNodi++;
        do {
           cout << "Inserisci numero nodo: ";
           cin >> index;
        } while ((index < 0) || (index >= MAXNODI) || (g.esisteNodo(index)));
        cout << "Inserisci nome stazione: ";
        cin >> a.nome;
        cout << "Inserisci numero passeggeri: ";
        cin >> a.numPasseggeri;
        g.insNodo(index);
        g.scriviNodo(index, a);
        do {
           cout << "Altra stazione? (S/N) ";
           cin >> risp;
        } while (!((risp =='s') || (risp == 'S') || (risp == 'n') || (risp == 'N')));
     }
     risp = 's';
     cout << endl;
     cout << "Inserimento archi:" << endl;
     cout << "------------------" << endl;
     while ((risp == 's') || (risp =='S')) {
        do {
           cout << "Inserisci numero nodo di partenza: ";
           cin >> part;
        } while (!((part >= 0) && (part < MAXNODI) && (g.esisteNodo(part))));
        do {
           cout << "Inserisci numero nodo di arrivo: ";
           cin >> arr;
        } while (!((arr >= 0) && (arr < MAXNODI) && (g.esisteNodo(arr))));
        cout << "Inserisci peso arco (" << part << ", " << arr << "): ";
        cin >> w;
        if (!g.insArco(part, arr))
           cout << "Arco esistente" << endl;
        else
           g.scriviArco(part, arr, w);
        do {
           cout << "Altro arco? (S/N) ";
           cin >> risp;
        } while (!((risp =='s') || (risp == 'S') || (risp == 'n') || (risp == 'N')));
     }
};

void stampaArchi(int i, GrafoAdiacenti<stazione> &g) {
     ListaAdiacenti<tipo> l;
     g.adiacenti(i, l);
     NodoAdiacenti<tipo> *p = l.primoLista();
	 tipo a;
	 while (!l.fineLista(p)) {
		l.leggiLista(a, p);
		cout << "(" << i << ", " << a.nodoCur << ") con peso " << a.peso << endl;
		p = l.succLista(p);
	 }
};

void stampaGrafo(GrafoAdiacenti<stazione> &g) {
     if (!g.grafoVuoto()) {
        stazione a;
        cout << "Insieme nodi (N):" << endl;
        for (int i = 0; i < MAXNODI; i++) {
           if (g.esisteNodo(i)) {
              g.leggiNodo(i, a);
              cout << i << ". " << a.nome << " numero passeggeri: " << a.numPasseggeri << endl;
           }
        }
        cout << endl << "Insieme archi (A): " << endl;
        for (int i = 0; i < MAXNODI; i++) {
           if (g.esisteNodo(i))
              stampaArchi(i, g);
        }
     } else cout << "Grafo vuoto" << endl;
};

bool copiaCoda(CodaPtr<Nodo> &q, CodaPtr<Nodo> &r) {
     if (!q.codaVuota()) {
        CodaPtr<Nodo> s;
        Nodo a;
        while (!q.codaVuota()) {
           a=q.leggiCoda();
           r.inCoda(a);
           s.inCoda(a);
           q.fuoriCoda();
        }
        while (!s.codaVuota()) {
           a=s.leggiCoda();
           q.inCoda(a);
           s.fuoriCoda();
        }
        return true;
     } else return false;
};

bool ricercaCoda(Nodo a, CodaPtr<Nodo> &q) {
     bool trovato = false;
     if (!q.codaVuota()) {
        CodaPtr<Nodo> r; //appoggio per q
        copiaCoda(q, r);
        Nodo b;
        while (!(r.codaVuota() || trovato)) {
           b=r.leggiCoda();
           if (b == a)
              trovato = true;
           else
              r.fuoriCoda();
        }
     }
     return trovato;
};

void camminiMinimi(GrafoAdiacenti<stazione> &g, Nodo start, distanze d, padri p){
   if (g.esisteNodo(start)){
      Nodo i;
      for (i = 0; i < MAXNODI; i++){
         p[i] = i;
         (i == start? d[i] = 0: d[i] = MAXINT);
      }    
      CodaPtr<Nodo> q;
      stazione a;
      tipo temp;
      Nodo u = start;
      Nodo v;
      q.inCoda(u);
      while (!q.codaVuota()){
         u=q.leggiCoda();
         q.fuoriCoda();
	      ListaAdiacenti<tipo> l;
         g.adiacenti(u, l);
         NodoAdiacenti<tipo> *pl = l.primoLista();
         while (!l.fineLista(pl)){
            l.leggiLista(temp, pl);
            v = temp.nodoCur;
            tipoPeso w;
            g.leggiArco(u, v, w);
            //relax
            if (d[u] + w < d[v]){
               d[v] = d[u] + w;
               p[v] = u;
               if (!ricercaCoda(v, q))
                  q.inCoda(v);
            }
            pl = l.succLista(pl);
         }
      }  
   } 
};

// stampa il percorso tra due nodi dati in input
void stampaCammini(GrafoAdiacenti<stazione> &g, Nodo start, Nodo end, distanze d, padri p){
   int path[MAXNODI];
   stazione a;
   int conto=0;
   if (g.esisteNodo(end)){
         int j;
         path[0] = end;
         int tot = 0;
         for(j = 1; ((j < MAXNODI) && (path[j-1] != start)); j++){ //creazione del path
            path[j] = p[path[j-1]];
            tot++;
         }
         tipoPeso w;
         for(j = tot; j >0; j--){ //creazione del path
            g.leggiArco(path[j], path[j-1], w);
            //cout << path[j] << " (" << w << " peso dell'arco) -> ";
            g.leggiNodo(path[j], a);
            conto+=a.numPasseggeri;
            cout << "[" << a.nome << "," << a.numPasseggeri << "]" << " --> ";
         }
         //cout << path[j] << " (distanza totale: " << d[end] << ")" << endl;
         g.leggiNodo(path[j], a);
         cout << "[" << a.nome << "]" << endl;
         cout << "Passeggeri totali lungo il percorso: " << conto << endl;
      }
};
     
int main(int argc, char *argv[]) {
     GrafoAdiacenti<stazione> g;
     stazione a;
     distanze d;
     padri p;
     Nodo arr, part;
     int num=0;
     cout << "Inserimento del grafo G:" << endl << endl;
     insGrafo(g, num);
     cout << endl << "Hai inserito " << num << " nodi!" << endl;
     system("PAUSE");
     system("CLS");
     cout << "Stampa del grafo G:" << endl << endl;
     stampaGrafo(g);
     cout << endl;
     do {
        cout << "Inserisci numero nodo della stazione di partenza: ";
        cin >> part;
     } while (!((part>0)&&(part<MAXNODI)));
     do {
        cout << "Inserisci numero nodo della stazione di arrivo: ";
        cin >> arr;
     } while (!((arr>0)&&(arr<MAXNODI)));
     camminiMinimi(g, part, d, p);
     stampaCammini(g, part, arr, d, p);
     cout << endl;
     system("pause");
     return 0;
}

