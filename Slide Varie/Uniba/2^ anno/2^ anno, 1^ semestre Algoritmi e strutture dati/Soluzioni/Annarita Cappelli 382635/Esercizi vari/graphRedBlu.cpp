/*Appello laboratorio 27 giugno 2006
Dato il tipo di dato astratto Grafo orientato realizzato con matrici di 
adiacenza in cui i nodi sono etichettati con valori nell'isieme {RED. BLUE}, 
realizzare almeno due delle seguenti funzioni (oltre a quelle di 
inserimento e stampa):
o REDGraph: restituisce il sottografo G' di G in cui tutti i nodi sono 
etichettati RED
o BLUEGraph: restituisce il sottografo G' di G in cui tutti i nodi sono 
etichettati BLUE
Suggerimento: implementare l'operatore SUBGraph che restituisce il sottografo 
G' di G in cui tutti i nodi sono etichettati con valore x
o ACICLICO: stabilisce se un grafo G è aciclico
Suggerimento: utilizzare l'operatore ADIACENTI
o RBGraph: dato un grafo Red-Blue G determina il numero di nodi rispettivamente 
con etichetta RED ed il numero di nodi con etichetta BLUE, e il numero di 
archi entranti rispettivamente nei nodi con etichetta RED e con etichetta BLUE
Nota: l'implementazione *corretta* di un solo punto comporta 
l'ammissione con riserva.
*/

#ifndef MAIN_H
#include "main.h"
#endif

#ifndef GRAFOMATADEXT_H
#include "GrafoMatAdExt.h"
#endif

#ifndef CODAPTR_H
#include "CodaPtr.h"
#endif

void insGrafo(GrafoMatAdExt<string> &g, GrafoMatAdExt<string> &f) {
     char risp = 's';
     int i, j;
     string k;
     cout << endl << "Inserimento nodi:" << endl;
     cout << "-----------------" << endl;
     while ((risp == 's') || (risp =='S')) {
        do {
           cout << "Inserisci numero nodo: ";
           cin >> i;
        } while (!((i >= 0) && (i < MAXNODI) && (!g.esisteNodo(i))));
        do {
           cout << "Inserisci label per il nodo " << i << ": ('red' o 'blu') ";
           cin >> k;
        } while (!((k == "red")||(k == "blu")||(k=="RED")||(k=="BLU")));
        g.insNodo(k, i);
        f.insNodo(k, i);
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
           cin >> i;
        } while (!((i >= 0) && (i < MAXNODI) && (g.esisteNodo(i))));
        do {
           cout << "Inserisci numero nodo di arrivo: ";
           cin >> j;
        } while (!((j >= 0) && (j < MAXNODI) && (g.esisteNodo(j))));
        if (g.esisteArco(i, j))
           cout << "Arco (" << i << ", " << j << ") esistente" << endl;
        else
           g.insArco(i, j);
           f.insArco(i, j);
        do {
           cout << "Altro arco? (S/N) ";
           cin >> risp;
        } while (!((risp =='s') || (risp == 'S') || (risp == 'n') || (risp == 'N')));
     }
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

void stampaGrafo(GrafoMatAdExt<string> &g) {
     string k;
     int a;
     cout << "Elenco nodi (N):" << endl;
     cout << "----------------" << endl;
     cout << endl;
     for (int i = 0; i < MAXNODI; i++)
        if (g.esisteNodo(i)) {
           cout << "Nodo " << i << ":" << endl;
           k=g.getLabel(i);
           g.getArchi(i, a);
           cout << "Label: " << k << " - Archi: " << a << endl;
        }
     cout << endl << endl;
     cout << "Elenco archi (A):" << endl;
     cout << "-----------------" << endl;
     for (int i = 0; i < MAXNODI; i++)
        for (int j = 0; j < MAXNODI; j++)
           if (g.esisteArco(i, j))
              cout << "(" << i << ", " << j << ") ";
     cout << endl;
};

void isolaNodo(Nodo n, GrafoMatAdExt<string> &g) {
     if (g.esisteNodo(n)) {
   	    for (int i = 0; i < MAXNODI; i++)
       	   if (g.esisteArco(i, n))
              g.cancArco(i, n);
        ListaPtr<Nodo> l;
        g.adiacenti(n, l);
	    lpcell<Nodo> *p = l.primoLista();
	    Nodo a;
	    while(!l.fineLista(p)) {
	       a=l.leggiLista(p);
	       g.cancArco(n, a);
	       p = l.succLista(p);
	    }
     }
};

void subGraph(string col, Nodo u, GrafoMatAdExt<string> &g, GrafoMatAdExt<string> &f) {
     if ((!g.grafoVuoto() && g.esisteNodo(u))) {
        CodaPtr<Nodo> q;
        bool temp;
        Nodo v;
        string k;
        int i = 0;
        q.inCoda(u);
        while (!q.codaVuota()) {
           u=q.leggiCoda();
           k=g.getLabel(u);
           if (k!=col) {
              isolaNodo(u, f); 
              f.cancNodo(u);
           }
		   g.setVisitato(true, u);
		   q.fuoriCoda();
		   ListaPtr<Nodo> l;
           g.adiacenti(u, l);
           lpcell<Nodo> *p = l.primoLista();
           while (!l.fineLista(p)) {
              v=l.leggiLista(p);
              if (!(g.getVisitato(v) || ricercaCoda(v, q))) {
                 q.inCoda(v);
              }
              p = l.succLista(p);
           }
        }
        cout << endl;
        g.azzeraVisitato();
     } else cout << "subGraph non applicabile" << endl;
};

bool camminoAperto(Nodo u, GrafoMatAdExt<string> &g) {
     if ((!g.grafoVuoto() && g.esisteNodo(u))) {
        CodaPtr<Nodo> q;
        bool temp;
        Nodo v;
        Nodo corrente;
        string k;
        int i = 0;
        q.inCoda(u);
        g.setVisitato(true, u);
        q.fuoriCoda();
        ListaPtr<Nodo> l;
        g.adiacenti(u, l);
        lpcell<Nodo> *p = l.primoLista();
        while (!l.fineLista(p)) {
           v=l.leggiLista(p);
           if (!(g.getVisitato(v) || ricercaCoda(v, q))) {
              q.inCoda(v);
           }
           p = l.succLista(p);
        }
        while (!q.codaVuota()) {
           corrente=q.leggiCoda();
           if (corrente==u)
              return false;
		   g.setVisitato(true, corrente);
		   q.fuoriCoda();
		   ListaPtr<Nodo> l;
           g.adiacenti(corrente, l);
           lpcell<Nodo> *p = l.primoLista();
           while (!l.fineLista(p)) {
              v=l.leggiLista(p);
             if (!(ricercaCoda(v, q))) {
                 q.inCoda(v);
              }
              p = l.succLista(p);
           }
        }
        cout << endl;
        g.azzeraVisitato();
     } else cout << "grafo vuoto, oppure non esiste il nodo" << endl;
     return true;
};

bool aciclico(GrafoMatAdExt<string> &g) {
     int max=g.numNodi();
     bool ret;
     for (int i=1; (i<max&&(ret=camminoAperto(i, g))); i++);
     return ret;
};   

void RBGraph(int &sommared, int &sommablu, int &entrantired, int &entrantiblu, GrafoMatAdExt<string> &g) {
     if (!g.grafoVuoto()) {
        for(int i = 0; i < MAXNODI; i++)
           if (g.esisteNodo(i)) {
              if (g.getLabel(i)=="red") {
                 sommared++;
                 for(int j = 0; j < MAXNODI; j++)
                 if (g.esisteArco(j, i))
                    entrantired++;
              } else {
                 sommablu++;        
                 for(int j = 0; j < MAXNODI; j++)
                 if (g.esisteArco(j, i))
                    entrantiblu++;
              }
           }
     } else cout << "Grafo vuoto" << endl;
};

int main(int argc, char *argv[]) {
     GrafoMatAdExt<string> g, f;
     Nodo a;
     int sommared=0,
         sommablu=0,
         entrantired=0,
         entrantiblu=0;
     string col;
     int i, j;
     cout << "Inserimento del grafo G:" << endl;
     insGrafo(g, f);
     system("PAUSE");
     system("CLS");
     cout << "Stampa del grafo G:" << endl << endl;
     stampaGrafo(g);
     cout << "Inserisci colore per sottografo da creare: (red/blu) ";
     cin >> col;
     subGraph(col, 1, g, f);
     stampaGrafo(f);
     cout << endl << endl;
     if (aciclico(g))
        cout << "Il grafo e' aciclico!" << endl;
     else cout << "Il grafo e' ciclico!" << endl;
     cout << endl;
     RBGraph(sommared, sommablu, entrantired, entrantiblu, g);
     cout << endl;
     cout << "Totale nodi rossi: " << sommared << endl;
     cout << "Totale nodi blu: " << sommablu << endl;
     cout << "Totale archi entranti nei nodi con etichetta red: " << entrantired << endl;
     cout << "Totale archi entranti nei nodi con etichetta blu: " << entrantiblu << endl;
     system("pause");
     return 0;
}

