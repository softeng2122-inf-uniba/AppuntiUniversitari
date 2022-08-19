#ifndef MAIN_H
#include "main.h"
#endif

#ifndef GRAFOMATADEXT_H
#include "GrafoMatAdExt.h"
#endif

#ifndef CODAPTR_H
#include "CodaPtr.h"
#endif

void insGrafo(GrafoMatAdExt<string> &g) {
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
        cout << "Inserisci label per il nodo " << i << ": ";
        cin >> k;
        g.insNodo(k, i);
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
        do {
           cout << "Altro arco? (S/N) ";
           cin >> risp;
        } while (!((risp =='s') || (risp == 'S') || (risp == 'n') || (risp == 'N')));
     }
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

void stampaLista(ListaPtr<Nodo> &l) {
     lpcell<Nodo> *p = l.primoLista();
     Nodo a;
     while (!l.fineLista(p)) {
        a=l.leggiLista(p);
		cout << a << " " << endl;
		p = l.succLista(p);
	 }
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

void dfs(Nodo u, GrafoMatAdExt<string> &g) {
     if ((!g.grafoVuoto() && g.esisteNodo(u))) {
        Nodo v;
        string k;
        k=g.getLabel(u);
        cout << k << "(" << u << ") ";
        g.setVisitato(true, u);
        ListaPtr<Nodo> l;
        g.adiacenti(u, l);
        lpcell<Nodo> *p = l.primoLista();
        while (!l.fineLista(p)) {
        //esamina il peso dell'arco
           v=l.leggiLista(p);
           if (!g.getVisitato(v))
              dfs(v, g);
           p = l.succLista(p);
        }
     } else cout << "dfs non applicabile" << endl;
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

void bfs(Nodo u, GrafoMatAdExt<string> &g) {
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
		   cout << k << "(" << u << ") ";
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
     } else cout << "bfs non applicabile" << endl;
};

bool nodiConnessi(Nodo u, Nodo z, GrafoMatAdExt<string> &g) {
     bool connessi = false;
     if (!g.grafoVuoto() && g.esisteNodo(u) && g.esisteNodo(z)) {
        CodaPtr<Nodo> q;
        Nodo v;
        q.inCoda(u);
        while (!(q.codaVuota() || connessi)) {
           u=q.leggiCoda();
		   g.setVisitato(true, u);
		   q.fuoriCoda();
		   ListaPtr<Nodo> l;
           g.adiacenti(u, l);
           lpcell<Nodo> *p = l.primoLista();
           while (!(l.fineLista(p) || connessi)) {
              v=l.leggiLista(p);
              //v = temp.nodoCur;
              if (v == z)
                 connessi = true;
              else if (!(g.getVisitato(v) || ricercaCoda(v, q)))
                 q.inCoda(v);
              p = l.succLista(p);
           }
        }
        g.azzeraVisitato();
     } else cout << "Funzione non applicabile" << endl;
     return connessi;
};

void maxEntranti(GrafoMatAdExt<string> &g, Nodo &a, int &entranti) {
     if (!g.grafoVuoto()) {
        int max = 0;
        int maxTemp;
        for(int i = 0; i < MAXNODI; i++)
           if (g.esisteNodo(i)) {
              maxTemp = 0;         
              for(int j = 0; j < MAXNODI; j++)
                 if (g.esisteArco(j, i))
                    maxTemp++;
              if(maxTemp > max) {
                 a = i;
                 max = maxTemp;
              }
        }
        entranti = max;
     } else cout << "Grafo vuoto" << endl;
};

void maxUscenti(GrafoMatAdExt<string> &g, Nodo &a, int &uscenti) {
     if (!g.grafoVuoto()) {
        int max = 0;
        int maxTemp;
        for(int i = 0; i < MAXNODI; i++)
           if (g.esisteNodo(i)) {
              ListaPtr<Nodo> l;
              g.adiacenti(i, l);
              lpcell<Nodo> *p = l.primoLista();
              maxTemp = 0;
              while(!l.fineLista(p)) {
                 maxTemp++;
                 p = l.succLista(p);
              }
              if(maxTemp > max) {
                 a = i;
                 max = maxTemp;
              }
           }
        uscenti = max;
     } else cout << "Grafo vuoto" << endl;
};

bool grafoConnesso(GrafoMatAdExt<string> &g) {
     bool connesso;
     if (!g.grafoVuoto()) {
        connesso = true;
        for (int i = 0; (i < MAXNODI && connesso); i++) {
           if (g.esisteNodo(i)) {
              for (int j = 0; (j < MAXNODI && connesso); j++)
                 if (g.esisteNodo(j) && (i != j)) {
                    connesso = (nodiConnessi(i, j, g));
                 }
           }
        }
     } else
        connesso = false;
     return connesso;
};

int main(int argc, char *argv[]) {
     GrafoMatAdExt<string> g;
     Nodo a;
     int i, j;
     cout << "Inserimento del grafo G:" << endl;
     insGrafo(g);
     system("PAUSE");
     system("CLS");
     cout << "Stampa del grafo G:" << endl << endl;
     stampaGrafo(g);
     cout << endl << "Visite:" << endl;
     do {
        cout << endl << "Inserisci nodo per la visita: ";
        cin >> i;
     } while (!((i >= 0) && (i < MAXNODI) && (g.esisteNodo(i))));
     cout << endl << "dfs G: ";
     dfs(i, g);
     g.azzeraVisitato();
     cout << endl << "bfs G: ";
     bfs(i, g);
     maxEntranti(g, a, i);
     cout << endl << "Il nodo con il maggior numero di nodi entranti: " << a << " (" << i << ")" << endl;
     maxUscenti(g, a, i);
     cout << "Il nodo con il maggior numero di nodi uscenti: " << a << " (" << i << ")" << endl;
     /*cout << endl << "Connessione fra due nodi:" << endl;
     do {
        cout << "Inserisci numero nodo di partenza: ";
        cin >> i;
     } while (!((i >= 0) && (i < MAXNODI) && (g.esisteNodo(i))));
     do {
        cout << "Inserisci numero nodo di arrivo: ";
        cin >> j;
     } while (!((j >= 0) && (j < MAXNODI) && (g.esisteNodo(j))));
     if (nodiConnessi(i, j, g))
        cout << "Nodi " << i << ", " << j << " connessi" << endl;
     else
        cout << "Nodi " << i << ", " << j << " non connessi" << endl;
     if (grafoConnesso(g)) 
        cout << endl << "Grafo G totalmente connesso" << endl;
     else
        cout << endl << "Grafo G non totalmente connesso" << endl;
     cout << endl << "Cancellazione di un nodo:" << endl;
     do {
        cout << "Inserisci numero nodo: ";
        cin >> i;
     } while (!((i >= 0) && (i < MAXNODI)));
     if (g.esisteNodo(i)) {
        isolaNodo(i, g);
        g.cancNodo(i);
        cout << "Nodo " << i << " cancellato" << endl << endl;
        stampaGrafo(g);
     } else
        cout << "Nodo " << i << "inesistente" << endl << endl;*/
     system("PAUSE");
     return 0;
}
