/*15/9/2005
Il percorso di un autobus urbano e' costituito da un ciclo chiuso di 5 fermate. 
Ciascuna fermata e' caratterizzata dal nome e dal numero di passeggeri in 
attesa di salire per ciascuna delle due direzioni. Ciascun tratto di strada 
fra due fermate consecutive possiede una capienza massima di passeggeri per 
ciascuna direzione. Implementare le seguenti funzioni/metodi:
1. Acquisizione/stampa della struttura e relative informazioni;
2. Date una stazione di partenza ed una di arrivo
- visualizzare il percorso (stazioni attraversate), possibilmente il piu' breve;
- effettuare il percorso,
leggendo da tastiera a ciascuna fermata il numero di passeggeri che scendono 
ed imbarcandone il massimo possibile per non superare 
la capienza del tratto successivo;
- stampare il numero totale di passeggeri giunti a destinazione.
Dimostrare il funzionamento delle funzioni mediante chiamate alle 
funzioni realizzate nel main.
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

struct fermata {
       string nome;
       int passeggeri;
};

void insGrafo(GrafoAdiacenti<fermata> &g) {
     int i = 0;
     int index, part, arr, w;
     fermata a;
     char risp = 's';
     cout << "Inserimento nodi:" << endl;
     cout << "-----------------" << endl;
     for (int i=0; i<5; i++) {
        index=i+1;
        cout << "Inserisci nome fermata: ";
        cin >> a.nome;
        a.passeggeri=0;
        g.insNodo(index);
        g.scriviNodo(index, a);
     }
     risp = 's';
     cout << endl;
     cout << "Inserimento archi:" << endl;
     cout << "------------------" << endl;
     while ((risp == 's') || (risp =='S')) {
        do {
           cout << "Inserisci numero nodo fermata partenza: ";
           cin >> part;
        } while (!((part >= 0) && (part < MAXNODI) && (g.esisteNodo(part))));
        do {
           cout << "Inserisci numero nodo fermata arrivo: ";
           cin >> arr;
        } while (!((arr >= 0) && (arr < MAXNODI) && (g.esisteNodo(arr))));
        cout << "Inserisci capienza percorso (" << part << ", " << arr << "): ";
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

void stampaArchi(int i, GrafoAdiacenti<fermata> &g) {
     ListaAdiacenti<tipo> l;
     g.adiacenti(i, l);
     NodoAdiacenti<tipo> *p = l.primoLista();
	 tipo a;
	 while (!l.fineLista(p)) {
		l.leggiLista(a, p);
		cout << "(" << i << ", " << a.nodoCur << ") con capienza massima passeggeri: " << a.peso << endl;
		p = l.succLista(p);
	 }
};

void stampaGrafo(GrafoAdiacenti<fermata> &g) {
     if (!g.grafoVuoto()) {
        fermata a;
        cout << "Insieme nodi (N):" << endl;
        for (int i = 0; i < MAXNODI; i++) {
           if (g.esisteNodo(i)) {
              g.leggiNodo(i, a);
              cout << i << ". " << a.nome << " numero passeggeri: " << a.passeggeri << endl;
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


void camminiMinimi(GrafoAdiacenti<fermata> &g, Nodo start, distanze d, padri p){
   if (g.esisteNodo(start)){
      Nodo i;
      for (i = 0; i < MAXNODI; i++){
         p[i] = i;
         (i == start? d[i] = 0: d[i] = MAXINT);
      }    
      CodaPtr<Nodo> q;
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
void stampaCammini(GrafoAdiacenti<fermata> &g, Nodo start, Nodo end, distanze d, padri p, CodaPtr<Nodo> &c){
   int path[MAXNODI];
   fermata a;
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
            cout << "[" << a.nome <<  "]" << " --> ";
            c.inCoda(path[j]);
         }
         //cout << path[j] << " (distanza totale: " << d[end] << ")" << endl;
         g.leggiNodo(path[j], a);
         cout << "[" << a.nome << "]" << endl;
         c.inCoda(path[j]);
      }
};

void percorso(CodaPtr<Nodo> &c, GrafoAdiacenti<fermata> &g) {
     Nodo n, m;
     fermata a, b;
     tipoPeso w;
     int appo, esubero, uscenti;
     int bus;
     cout << "Quanti passeggeri contiene il bus inizialmente? ";
     cin >> bus;
     while (!c.codaVuota()) {
        n=c.leggiCoda();
        c.fuoriCoda();
        g.leggiNodo(n, a);
        if (!c.codaVuota()) {
           do {
              cout << "Quanti passeggeri sono in partenza dalla fermata " << a.nome << "? ";
              cin >> appo;
           } while (!(appo>=0));
           cout << "Quanti passeggeri scendono dal bus alla fermata " << a.nome << "? ";
           cin >> uscenti;
           bus=(bus-uscenti)+appo; 
           m=c.leggiCoda();
           g.leggiNodo(m, b);
           g.leggiArco(n, m, w);
           cout << "Il percorso tra " << a.nome << " e " << b.nome << " consente di trasportare " << w << " passeggeri." << endl;
           if (bus>w) {
              cout << "Spiacente, ma ci sono dei passeggeri in esubero che resteranno a terra!" << endl;
              esubero=appo-w;
              bus=appo-esubero;
           } 
        } 
     }
     cout << "Il numero totale dei passeggeri giunti a destinazione e': " << bus << endl;
};
           
int main() {
     GrafoAdiacenti<fermata> g;
     CodaPtr<Nodo> c;
     fermata a;
     distanze d;
     padri p;
     Nodo arr, part;
     cout << "Inserimento del grafo G:" << endl << endl;
     insGrafo(g);
     system("PAUSE");
     system("CLS");
     cout << "Stampa del grafo G:" << endl << endl;
     stampaGrafo(g);
     cout << endl;
     do {
        cout << "Inserisci numero nodo della fermata di partenza: ";
        cin >> part;
     } while (!((part>0)&&(part<MAXNODI)));
     do {
        cout << "Inserisci numero nodo della fermata di arrivo: ";
        cin >> arr;
     } while (!((arr>0)&&(arr<MAXNODI)));
     camminiMinimi(g, part, d, p);
     stampaCammini(g, part, arr, d, p, c);
     percorso(c, g);
     cout << endl;
     system("PAUSE");
     return 0;
}

