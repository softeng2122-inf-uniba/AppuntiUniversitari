#include <cstdlib>
#include <iostream>
#include "GrafoMatAd.h"
#include "CodaPtr.h"

using namespace std;

void insGrafo(GrafoMatAd &g){
   char risp = 's';
   int i, j;
   cout << "Inserimento nodi:" << endl;
   cout << "-----------------" << endl;
   while ((risp == 's') || (risp =='S')){
      cout << "Inserisci numero nodo: ";
      cin >> i;
      g.insNodo(i);
      do{
         cout << "Altro nodo? (S/N) ";
         cin >> risp;
      } while (!((risp =='s') || (risp == 'S') || (risp == 'n') || (risp == 'N')));
   }
   risp = 's';
   cout << endl;
   cout << "Inserimento archi:" << endl;
   cout << "------------------" << endl;
   while ((risp == 's') || (risp =='S')){
      do{
         cout << "Inserisci numero nodo di partenza: ";
         cin >> i;
      } while (!((i >= 0) && (i < MAXNODI) && (g.esisteNodo(i))));
      do{
         cout << "Inserisci numero nodo di arrivo: ";
         cin >> j;
      } while (!((j >= 0) && (j < MAXNODI) && (g.esisteNodo(j))));
      if (g.esisteArco(i, j))
         cout << "Arco (" << i << ", " << j << ") esistente" << endl;
      else
         g.insArco(i, j);
      do{
         cout << "Altro arco? (S/N) ";
         cin >> risp;
      } while (!((risp =='s') || (risp == 'S') || (risp == 'n') || (risp == 'N')));
   }
}

void stampaGrafo(GrafoMatAd &g){
   cout << "Elenco nodi (N):" << endl;
   cout << "----------------" << endl;
   cout << endl;
   for (int i = 0; i < MAXNODI; i++)
      if (g.esisteNodo(i))
         cout << i << " ";
   cout << endl << endl;
   cout << "Elenco archi (A):" << endl;
   cout << "-----------------" << endl;
   for (int i = 0; i < MAXNODI; i++)
      for (int j = 0; j < MAXNODI; j++)
         if (g.esisteArco(i, j))
            cout << "(" << i << ", " << j << ") ";
   cout << endl;
}

void stampaLista(ListaAdiacenti &l){
	posizione p = l.primoLista();
	Nodo a;
	while (!l.fineLista(p)){
		l.leggiLista(a, p);
		cout << a << " " << endl;
		p = l.succLista(p);
	}
}

void isolaNodo(Nodo n, GrafoMatAd &g){
   if (g.esisteNodo(n)){
   	for (int i = 0; i < MAXNODI; i++)
        	if (g.esisteArco(i, n))
            g.cancArco(i,n);
      ListaAdiacenti l;
      g.adiacenti(n, l);
	   posizione p = l.primoLista();
	   Nodo a;
	   while(!l.fineLista(p)){
	     l.leggiLista(a, p);
	     g.cancArco(n, a);
	     p = l.succLista(p);
	    }
    }
}

void dfs(Nodo u, GrafoMatAd &g){
   if ((!g.grafoVuoto() && g.esisteNodo(u))){
      Nodo v;
      cout << u << " ";
      g.setVisitato(true, u);
      ListaAdiacenti l;
      g.adiacenti(u, l);
      posizione p = l.primoLista();
      while (!l.fineLista(p)){
         //esamina il peso dell'arco
         l.leggiLista(v, p);
         if (!g.getVisitato(v))
            dfs(v, g);
         p = l.succLista(p);
      }
   } else cout << "dfs non applicabile" << endl;
}

bool copiaCoda(CodaPtr &q, CodaPtr &r){
   if (!q.codaVuota()){
      CodaPtr s;
      elemCoda a;
      while (!q.codaVuota()){
         q.leggiCoda(a);
         r.inCoda(a);
         s.inCoda(a);
         q.fuoriCoda();
      }
      while (!s.codaVuota()){
         s.leggiCoda(a);
         q.inCoda(a);
         s.fuoriCoda();
      }
      return true;
   } else return false;
}

bool ricercaCoda(elemCoda a, CodaPtr &q){
   bool trovato = false;
   if (!q.codaVuota()){
      CodaPtr r; //appoggio per q
      copiaCoda(q, r);
      elemCoda b;
      while (!(r.codaVuota() || trovato)){
         r.leggiCoda(b);
         if (b == a)
            trovato = true;
         else
            r.fuoriCoda();
      }
   }
   return trovato;
}

void bfs(Nodo u, GrafoMatAd &g){
   if ((!g.grafoVuoto() && g.esisteNodo(u))){
      CodaPtr q;
      bool temp;
      Nodo v;
      q.inCoda(u);
      while (!q.codaVuota()){
         q.leggiCoda(u);
		   cout << u << " ";
		   g.setVisitato(true, u);
		   q.fuoriCoda();
		   ListaAdiacenti l;
         g.adiacenti(u, l);
         posizione p = l.primoLista();
         while (!l.fineLista(p)){
            //esamina il peso dell'arco
            l.leggiLista(v, p);
            if (!(g.getVisitato(v) || ricercaCoda(v, q)))
               q.inCoda(v);
            p = l.succLista(p);
         }
      }
      g.azzeraVisitato();
      cout << endl;
   } else cout << "bfs non applicabile" << endl;
}

bool nodiConnessi(Nodo u, Nodo z, GrafoMatAd &g){
   bool connessi = false;
   if (!g.grafoVuoto() && g.esisteNodo(u) && g.esisteNodo(z)){
      CodaPtr q;
      Nodo v;
      q.inCoda(u);
      while (!(q.codaVuota() || connessi)){
         q.leggiCoda(u);
		   g.setVisitato(true, u);
		   q.fuoriCoda();
		   ListaAdiacenti l;
         g.adiacenti(u, l);
         posizione p = l.primoLista();
         while (!(l.fineLista(p) || connessi)){
            l.leggiLista(v, p);
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
}

void maxEntranti(GrafoMatAd &g, Nodo &a, int &entranti){
   if (!g.grafoVuoto()){
      int max = 0;
      int maxTemp;
      for(int i = 0; i < MAXNODI; i++)
         if (g.esisteNodo(i)){
            maxTemp = 0;         
            for(int j = 0; j < MAXNODI; j++)
               if (g.esisteArco(j, i))
                  maxTemp++;
            if(maxTemp > max){
               //g.leggiNodo(i, a);
               a = i;
               max = maxTemp;
            }
         }
      entranti = max;
   } else cout << "Grafo vuoto" << endl;
}

void maxUscenti(GrafoMatAd &g, Nodo &a, int &uscenti){
   if (!g.grafoVuoto()){
      int max = 0;
      int maxTemp;
      for(int i = 0; i < MAXNODI; i++)
         if (g.esisteNodo(i)){
            ListaAdiacenti l;
            g.adiacenti(i, l);
            posizione p = l.primoLista();
            maxTemp = 0;
            while(!l.fineLista(p)){
               maxTemp++;
               p = l.succLista(p);
            }
            if(maxTemp > max){
               //g.leggiNodo(i, a);
               a = i;
               max = maxTemp;
            }
         }
      uscenti = max;
   } else cout << "Grafo vuoto" << endl;
}

bool grafoConnesso(GrafoMatAd &g){
   bool connesso;
   if (!g.grafoVuoto()){
      connesso = true;
      for (int i = 0; (i < MAXNODI && connesso); i++){
         if (g.esisteNodo(i)){
            for (int j = 0; (j < MAXNODI && connesso); j++)
               if (g.esisteNodo(j) && (i != j)){
                  connesso = (nodiConnessi(i, j, g));
               }
         }
      }
   } else
      connesso = false;
   return connesso;
}


int main(int argc, char *argv[])
{
   GrafoMatAd g;
   Nodo a;
   int i, j;
   cout << "Inserimento del grafo G:" << endl << endl;
   insGrafo(g);
   system("PAUSE");
   system("CLS");
   cout << "Stampa del grafo G:" << endl << endl;
   stampaGrafo(g);
   cout << endl << "Visite:" << endl;
   do{
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
   cout << endl << "Connessione fra due nodi:" << endl;
   do{
      cout << "Inserisci numero nodo di partenza: ";
      cin >> i;
   } while (!((i >= 0) && (i < MAXNODI) && (g.esisteNodo(i))));
   do{
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
   do{
      cout << "Inserisci numero nodo: ";
      cin >> i;
   } while (!((i >= 0) && (i < MAXNODI)));
   if (g.esisteNodo(i)){
      isolaNodo(i, g);
      g.cancNodo(i);
      cout << "Nodo " << i << " cancellato" << endl << endl;
      stampaGrafo(g);
   } else
      cout << "Nodo " << i << "inesistente" << endl << endl;
   system("PAUSE");
   return 0;
}
