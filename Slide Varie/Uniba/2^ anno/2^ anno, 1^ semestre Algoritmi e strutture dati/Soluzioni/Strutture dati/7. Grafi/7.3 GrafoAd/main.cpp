#include <iostream>
#include <cstdlib>
#include "ListaAdiacenti.h"
#include "GrafoAdiacenti.h"
#include "CodaPtr.h"

using namespace std;

void insGrafo(GrafoAdiacenti &g){
   int i = 0;
   int index, part, arr, w;
   label a;
   char risp = 's';
   cout << "Inserimento nodi:" << endl;
   cout << "-----------------" << endl;
   while ((i < MAXNODI) && ((risp == 's') || (risp == 'S'))){
      do{
         cout << "Inserisci numero nodo: ";
         cin >> index;
      } while ((index < 0) || (index >= MAXNODI) || (g.esisteNodo(index)));
      cout << "Inserisci etichetta: ";
      cin >> a;
      g.insNodo(index);
      g.scriviNodo(index, a);
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
         cin >> part;
      } while (!((part >= 0) && (part < MAXNODI) && (g.esisteNodo(part))));
      do{
         cout << "Inserisci numero nodo di arrivo: ";
         cin >> arr;
      } while (!((arr >= 0) && (arr < MAXNODI) && (g.esisteNodo(arr))));
      cout << "Inserisci peso arco (" << part << ", " << arr << "): ";
      cin >> w;
      if (!g.insArco(part, arr))
         cout << "Arco esistente" << endl;
      else
         g.scriviArco(part, arr, w);
      do{
         cout << "Altro arco? (S/N) ";
         cin >> risp;
      } while (!((risp =='s') || (risp == 'S') || (risp == 'n') || (risp == 'N')));
   }
}

void stampaArchi(int i, GrafoAdiacenti &g){
   ListaAdiacenti l;
	g.adiacenti(i, l);
   posizione p = l.primoLista();
	tipoelem a;
	while (!l.fineLista(p)){
		l.leggiLista(a, p);
		cout << "(" << i << ", " << a.nodoCur << ") con peso " << a.peso << endl;
		p = l.succLista(p);
	}
}

void stampaGrafo(GrafoAdiacenti &g){
   if (!g.grafoVuoto()){
      label a;
      cout << "Insieme nodi (N):" << endl;
      for (int i = 0; i < MAXNODI; i++){
         if (g.esisteNodo(i)){
            g.leggiNodo(i, a);
            cout << i << ". " << a << endl;
         }
      }
      cout << endl << "Insieme archi (A): " << endl;
      for (int i = 0; i < MAXNODI; i++){
         if (g.esisteNodo(i))
            stampaArchi(i, g);
      }
   } else cout << "Grafo vuoto" << endl;
}

void isolaNodo(Nodo n, GrafoAdiacenti &g){
   if (g.esisteNodo(n)){
   	for (int i = 0; i < MAXNODI; i++)
        	if (g.esisteArco(i, n))
            g.cancArco(i,n);
      ListaAdiacenti l;
      g.adiacenti(n,l);
	   posizione p = l.primoLista();
	   tipoelem a;
	   while(!l.fineLista(p)){
	     l.leggiLista(a,p);
	     g.cancArco(n,a.nodoCur);
	     p = l.succLista(p);
	    }
    }
}

void dfs(Nodo u, GrafoAdiacenti &g){
   if ((!g.grafoVuoto() && g.esisteNodo(u))){
      Nodo v;
      label a;
      tipoelem temp;
      g.leggiNodo(u, a);
      cout << a << " ";
      g.setVisitato(true, u);
      ListaAdiacenti l;
      g.adiacenti(u, l);
      posizione p = l.primoLista();
      while (!l.fineLista(p)){
         //esamina il peso dell'arco
         l.leggiLista(temp, p);
         v = temp.nodoCur;
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

void bfs(Nodo u, GrafoAdiacenti &g){
   if ((!g.grafoVuoto() && g.esisteNodo(u))){
      CodaPtr q;
      label a;
      tipoelem temp;
      Nodo v;
      q.inCoda(u);
      while (!q.codaVuota()){
         q.leggiCoda(u);
         g.leggiNodo(u, a);
		   cout << a << " ";
		   g.setVisitato(true, u);
		   q.fuoriCoda();
		   ListaAdiacenti l;
         g.adiacenti(u, l);
         posizione p = l.primoLista();
         while (!l.fineLista(p)){
            //esamina il peso dell'arco
            l.leggiLista(temp, p);
            v = temp.nodoCur;
            if (!(g.getVisitato(v) || ricercaCoda(v, q)))
               q.inCoda(v);
            p = l.succLista(p);
         }
      }
      g.azzeraVisitato();
      cout << endl;
   } else cout << "bfs non applicabile" << endl;
}

bool nodiConnessi(Nodo u, Nodo z, GrafoAdiacenti &g){
   bool connessi = false;
   if (!g.grafoVuoto() && g.esisteNodo(u) && g.esisteNodo(z)){
      CodaPtr q;
      tipoelem v;
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
            if (v.nodoCur == z)
               connessi = true;
            else if (!(g.getVisitato(v.nodoCur) || ricercaCoda(v.nodoCur, q)))
               q.inCoda(v.nodoCur);
            p = l.succLista(p);
         }
      }
      g.azzeraVisitato();
   } else cout << "Funzione non applicabile" << endl;
   return connessi;
}

void maxEntranti(GrafoAdiacenti &g, label &a, int &entranti){
   if (!g.grafoVuoto()){
      int max = 0;
      int maxTemp;
      for(int i = 0; i<MAXNODI; i++)
         if(g.esisteNodo(i)){
            maxTemp = 0;         
            for(int j = 0; j<MAXNODI; j++)
               if (g.esisteArco(j,i))
                  maxTemp++;
            if(maxTemp > max){
               g.leggiNodo(i, a);
               max = maxTemp;
            }
         }
      entranti = max;
   } else cout << "Grafo vuoto" << endl;
}

void maxUscenti(GrafoAdiacenti &g, label &a, int &uscenti){
   if (!g.grafoVuoto()){
      int max = 0;
      int maxTemp;
      for(int i = 0; i<MAXNODI; i++)
         if(g.esisteNodo(i)){
            ListaAdiacenti l;
            g.adiacenti(i,l);
            posizione p = l.primoLista();
            maxTemp = 0;
            while(!l.fineLista(p)){
               maxTemp++;
               p = l.succLista(p);
            }
            if(maxTemp > max){
               g.leggiNodo(i, a);
               max = maxTemp;
            }
         }
      uscenti = max;
   } else cout << "Grafo vuoto" << endl;
}

bool grafoConnesso(GrafoAdiacenti &g){
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
   GrafoAdiacenti g;
   label a;
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

