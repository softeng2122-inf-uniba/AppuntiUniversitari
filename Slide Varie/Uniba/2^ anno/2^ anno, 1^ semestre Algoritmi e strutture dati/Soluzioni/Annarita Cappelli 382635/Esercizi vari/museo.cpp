/*1/9/2005
Il gestore di un museo desidera un programma che informatizzi la pianta 
dell'edificio al fine di organizzare visite virtuali. Di ogni stanza interessa 
conoscere il nome, il numero di pezzi contenuti ed il loro valore complessivo. 
Il passaggio fra stanze adiacenti, quando esiste, puo' essere a senso unico 
oppure sia in entrata che in uscita. Implementare le seguenti funzioni/metodi:
1. Acquisizione delle informazioni relative ad una pianta valida;
2. Stampa delle informazioni relative alla pianta;
3. Visita interattiva del museo a partire dall'atrio di ingresso, 
stampando al termine:
- il percorso seguito
- il numero di stanze attraversate;
4. A partire dall'atrio di ingresso, stabilire il percorso piu' breve per 
raggiungere ciascuna stanza.
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

struct stanza {
       string nome;
       int num;
       double valore;
};

typedef int distanze[MAXNODI];
typedef Nodo padri[MAXNODI];

void insGrafo(GrafoAdiacenti<stanza> &g) {
     int i = 0;
     int index, part, arr, w;
     stanza a;
     char risp = 's';
     cout << "Inserimento nodi:" << endl;
     cout << "-----------------" << endl;
     while ((i < MAXNODI) && ((risp == 's') || (risp == 'S'))) {
        do {
           cout << "Inserisci numero nodo: ";
           cin >> index;
        } while ((index < 0) || (index >= MAXNODI) || (g.esisteNodo(index)));
        cout << "Inserisci nome stanza: ";
        cin >> a.nome;
        cout << "Inserisci numero pezzi: ";
        cin >> a.num;
        cout << "Inserisci valore complessivo pezzi: ";
        cin >> a.valore;
        g.insNodo(index);
        g.scriviNodo(index, a);
        do {
           cout << "Altro nodo? (S/N) ";
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

void stampaArchi(int i, GrafoAdiacenti<stanza> &g) {
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

void stampaGrafo(GrafoAdiacenti<stanza> &g) {
     if (!g.grafoVuoto()) {
        stanza a;
        cout << "Insieme nodi (N):" << endl;
        for (int i = 0; i < MAXNODI; i++) {
           if (g.esisteNodo(i)) {
              g.leggiNodo(i, a);
              cout << i << ". " << a.nome << " (pezzi: " << a.num << ", valore: " << a.valore << ")" << endl;
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

void dfs(Nodo u, GrafoAdiacenti<stanza> &g){
   if ((!g.grafoVuoto() && g.esisteNodo(u))){
      Nodo v;
      stanza a;
      tipo temp;
      g.leggiNodo(u, a);
      cout << a.nome << " - Numero pezzi: " << a.num << " - Valore pezzi stanza: " << a.valore << endl;
      g.setVisitato(true, u);
      ListaAdiacenti<tipo> l;
      g.adiacenti(u, l);
      NodoAdiacenti<tipo> *p = l.primoLista();
      while (!l.fineLista(p)){
         //esamina il peso dell'arco
         l.leggiLista(temp, p);
         v = temp.nodoCur;
         if (!g.getVisitato(v))
            dfs(v, g);
         p = l.succLista(p);
      }
   } else cout << "Visita non applicabile" << endl;
}

void camminiMinimi(GrafoAdiacenti<stanza> &g, Nodo start, distanze d, padri p){
   if (g.esisteNodo(start)){
      Nodo i;
      for (i = 0; i < MAXNODI; i++){
         p[i] = i;
         (i == start? d[i] = 0: d[i] = MAXINT);
      }    
      CodaPtr<Nodo> q;
      stanza a;
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

// a partire da un nodo stampa tutti i cammini minimi per ciascun nodo del grafo
void stampaCammini(GrafoAdiacenti<stanza> &g, Nodo start, distanze d, padri p){
   int path[MAXNODI];
   stanza a, b;
   int conto=0;
   for(int i = 0; i < MAXNODI; i++){ //cicla su p
      if (g.esisteNodo(i)){
         int j;
         path[0] = i;
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
            cout << "[" << a.nome << "," << a.num << "] " << " (" << w << " peso dell'arco) --> ";
         }
         //cout << path[j] << " (distanza totale: " << d[i] << ")" << endl;
         g.leggiNodo(path[j], b);
         cout << "[" << b.nome << "," << b.num << "]" << " (distanza totale: " << d[i] << ")" << endl;
      }
   }
};

int main(int argc, char *argv[]) {
     GrafoAdiacenti<stanza> g;
     Nodo i;
     distanze d;
     padri p;
     cout << "Inserimento del grafo G:" << endl << endl;
     insGrafo(g);
     system("PAUSE");
     system("CLS");
     cout << "Stampa del grafo G:" << endl << endl;
     stampaGrafo(g);
     cout << endl;
     cout << endl << "Visita interattiva del museo a partire dell'atrio:" << endl;
     do {
        cout << endl << "Inserisci nodo corrispondente all'atrio: ";
        cin >> i;
     } while (!((i >= 0) && (i < MAXNODI) && (g.esisteNodo(i))));
     cout << endl << "Visita museo: ";
     dfs(i, g);
     cout << endl;
     do {
        cout << endl << "Inserisci nodo corrispondente all'atrio: ";
        cin >> i;
     } while (!((i >= 0) && (i < MAXNODI) && (g.esisteNodo(i))));
     camminiMinimi(g, i, d, p);
     stampaCammini(g, i, d, p);
     system("pause");
     return 0;
}

