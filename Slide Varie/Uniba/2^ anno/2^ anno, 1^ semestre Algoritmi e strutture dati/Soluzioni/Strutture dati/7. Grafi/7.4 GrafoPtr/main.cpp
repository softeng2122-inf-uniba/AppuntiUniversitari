#include <cstdlib>
#include <iostream>
#include "GrafoPtr.h"
#include "CodaPtr.h"

using namespace std;

void insGrafo(GrafoPtr &g){
   int w;
   label a, part, arr;
   char risp = 's';
   cout << "Inserimento nodi:" << endl;
   cout << "-----------------" << endl;
   while ((risp == 's') || (risp == 'S')){
    	cout << "Inserisci etichetta: ";
   	cin >> a;
    	if (g.pos(a) == NULL){
       	NodoGrafo n = new NodoGrafoPtr();
    		if(g.insNodo(n))
   	  		g.scriviNodo(n, a);
    		else
    			cout << "Nodo " << a << " già inserito" << endl;
    	} else
    		cout << "Nodo " << a << " già inserito" << endl;
   	do{
     	   cout << "Altri nodi? (S/N) ";
      	cin >> risp;
   	} while (!((risp == 'S') || (risp == 's') || (risp == 'N') || (risp == 'n')));
   }
   risp = 's';
   cout << endl;
   cout << "Inserimento archi:" << endl;
   cout << "------------------" << endl;
   while ((risp == 's') || (risp == 'S')){
   	do{
      	cout << "Inserisci nodo partenza: ";
      	cin >> part;
   	} while (g.pos(part) == NULL);
   	do{
      	cout << "Inserisci nodo arrivo: ";
      	cin >> arr;
   	} while (g.pos(arr) == NULL);
   	cout << "Inserisci peso arco (" << part << ", " << arr << "): ";
   	cin >> w;
   	if(!g.insArco(g.pos(part), g.pos(arr)))
      	cout << "Arco esistente" << endl;
   	else
   		g.scriviArco(g.pos(part), g.pos(arr), w);
   	do{
      	cout << "Altri archi? (S/N) ";
      	cin >> risp;
   	} while (!((risp == 'S') || (risp == 's') || (risp == 'N') || (risp == 'n')));
   }
}

void stampaArchi(NodoGrafo m, GrafoPtr &g){
   ListaAdiacenti l;
	g.adiacenti(m, l);
   NodoAd p = l.primoLista();
	tipoPeso w;
	NodoGrafo n;
	label a,etich;
	g.leggiNodo(m,etich);
	while (!l.fineLista(p)){
		l.leggiLista(n, w, p);
		g.leggiNodo(n,a);
		cout << "(" << etich << ", " << a << ") con peso " << w << endl;
		p = l.succLista(p);
	}
}

void stampaGrafo(GrafoPtr &g){
	if (!g.grafoVuoto()){
   	label a;
   	cout << "Insieme nodi (N):" << endl;
     	NodoGrafo n = g.getGrafo();
   	while(n != NULL){
   		g.leggiNodo(n,a);
         cout << a << endl;
   		n = n->getSuccessivo();
      }
   	cout << endl << "Insieme archi (A): " << endl;
  	   n = g.getGrafo();
   	while(n != NULL){
   		g.leggiNodo(n,a);
         stampaArchi(n, g);
   		n = n->getSuccessivo();
   	}
	} else 
      cout << "Grafo vuoto" << endl;
}            

void isolaNodo(NodoGrafo n, GrafoPtr &g){
	if (g.esisteNodo(n)){
		NodoGrafo m = g.getGrafo();
		while(m!=NULL){
     	   if (g.esisteArco(m, n))
         	g.cancArco(m,n);
			m = m->getSuccessivo();
		}
   	ListaAdiacenti l;
   	g.adiacenti(n,l);
   	NodoAd p = l.primoLista();
   	while(!l.fineLista(p)){
		   g.cancArco(n,p->getPtrNodo());
     	   p = l.succLista(p);
      }
   }
}

void dfs(NodoGrafo u, GrafoPtr &g){
	if ((!g.grafoVuoto() && g.esisteNodo(u))){
   	label a;
   	tipoPeso w;
   	NodoGrafo v;
      g.leggiNodo(u, a);
   	cout << a << " ";
   	g.setVisitato(true, u);
   	ListaAdiacenti l;
   	g.adiacenti(u, l);
   	NodoAd p = l.primoLista();
   	while (!l.fineLista(p)){
      	//esamina il peso dell'arco
      	l.leggiLista(v, w, p);
      	if (!g.getVisitato(v))
         	dfs(v, g);
      	p = l.succLista(p);
   	}
   } else 
      cout << "dfs non applicabile" << endl;
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

void bfs(NodoGrafo u, GrafoPtr &g){
	if ((!g.grafoVuoto() && g.esisteNodo(u))){
   	CodaPtr q;
   	label a;
   	tipoPeso w;
   	NodoGrafo v;
   	q.inCoda(u);
   	while (!q.codaVuota()){
     	   q.leggiCoda(u);
      	g.leggiNodo(u, a);
	   	cout << a << " ";
	   	g.setVisitato(true, u);
	   	q.fuoriCoda();
	   	ListaAdiacenti l;
      	g.adiacenti(u, l);
      	NodoAd p = l.primoLista();
      	while (!l.fineLista(p)){
         	//esamina il peso dell'arco
         	l.leggiLista(v, w, p);
         	if (!(g.getVisitato(v) || ricercaCoda(v, q)))
            		q.inCoda(v);
         	p = l.succLista(p);
      	}
   	}
   	g.azzeraVisitato();
   	cout << endl;
	} else 
      cout << "bfs non applicabile" << endl;
}

bool nodiConnessi(NodoGrafo u, NodoGrafo z, GrafoPtr &g){
	bool connessi = false;
	if (!g.grafoVuoto() && g.esisteNodo(u) && g.esisteNodo(z)){
   	CodaPtr q;
   	label a;
   	tipoPeso w;
   	NodoGrafo v;
   	q.inCoda(u);
   	while (!(q.codaVuota() || connessi)){
      	q.leggiCoda(u);
      	g.leggiNodo(u, a);
	   	g.setVisitato(true, u);
	   	q.fuoriCoda();
	   	ListaAdiacenti l;
      	g.adiacenti(u, l);
      	NodoAd p = l.primoLista();
      	while (!(l.fineLista(p) || connessi)){
        	 	l.leggiLista(v, w, p);
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

void maxEntranti(GrafoPtr &g, label &a, int &entranti){
	if (!g.grafoVuoto()){
   	int max = 0;
   	int maxTemp;
   	NodoGrafo grafo = g.getGrafo();
   	while(grafo != NULL){
        	maxTemp = 0;
        	NodoGrafo n = g.getGrafo();
        	while(n != NULL){
            if (g.esisteArco(n,grafo))
            	maxTemp++;
        		n = n->getSuccessivo();
     		}
       	if(maxTemp > max){
       		g.leggiNodo(grafo, a);
       		max = maxTemp;
        	}
   	   grafo = grafo->getSuccessivo();
   	}
	   entranti = max;
	} else cout << "Grafo vuoto" << endl;
}

void maxUscenti(GrafoPtr &g, label &a, int &uscenti){
	if (!g.grafoVuoto()){
   	int max = 0;
   	int maxTemp;
   	NodoGrafo grafo = g.getGrafo();
   	while(grafo != NULL){
      	if(g.esisteNodo(grafo)){
         	ListaAdiacenti l;
         	g.adiacenti(grafo,l);
        	 	NodoAd p = l.primoLista();
         	maxTemp = 0;
         	while(!l.fineLista(p)){
            	maxTemp++;
            	p = l.succLista(p);
         	}
         	if(maxTemp > max){
            	g.leggiNodo(grafo, a);
            	max = maxTemp;
        	 	}
      	}
      	grafo = grafo->getSuccessivo();
   	}
   	uscenti = max;
   } else 
      cout << "Grafo vuoto" << endl;
}

bool grafoConnesso(GrafoPtr &g){
	bool connesso;
	if (!g.grafoVuoto()){
      connesso = true;   
   	NodoGrafo grafo = g.getGrafo();
   	while((grafo != NULL) && connesso){
		   NodoGrafo n = g.getGrafo();
	   	while((n != NULL) && connesso){
        	   if (grafo != n)
           	   connesso = nodiConnessi(grafo, n, g);
      	   n = n->getSuccessivo();
      	}
      	grafo = grafo->getSuccessivo();
   	}
   } else
      connesso = false;   
	return connesso;
}

int main(int argc, char *argv[])
{
   GrafoPtr g, h;
   label a;
   label i, j;
   int k;
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
   } while (!(g.esisteNodo(g.pos(i))));
   cout << endl << "dfs G: ";
   dfs(g.pos(i), g);
   g.azzeraVisitato();
   cout << endl << "bfs G: ";
   bfs(g.pos(i), g);
   maxEntranti(g, a, k);
   cout << endl << "Il nodo con il maggior numero di nodi entranti: " << a << " (" << k << ")" << endl;
   maxUscenti(g, a, k);
   cout << "Il nodo con il maggior numero di nodi uscenti: " << a << " (" << k << ")" << endl;
   cout << endl << "Connessione fra due nodi:" << endl;
   do{
      cout << "Inserisci etichetta nodo di partenza: ";
      cin >> i;
   } while (!g.esisteNodo(g.pos(i)));
   do{
      cout << "Inserisci etichetta nodo di arrivo: ";
      cin >> j;
   } while (!g.esisteNodo(g.pos(j)));
   if (nodiConnessi(g.pos(i), g.pos(j), g))
      cout << "Nodi " << i << ", " << j << " connessi" << endl;
   else
      cout << "Nodi " << i << ", " << j << " non connessi" << endl;
   if (grafoConnesso(g)) 
      cout << endl << "Grafo G totalmente connesso" << endl;
   else
      cout << endl << "Grafo G non totalmente connesso" << endl;
   cout << endl << "Cancellazione di un nodo:" << endl;
   cout << "Inserisci etichetta nodo: ";
   cin >> i;
   if (g.esisteNodo(g.pos(i))){
      isolaNodo(g.pos(i), g);
      g.cancNodo(g.pos(i));
      cout << "Nodo " << i << " cancellato" << endl << endl;
      stampaGrafo(g);
   } else
      cout << "Nodo " << i << "inesistente" << endl << endl;
   system("PAUSE");
   return 0;
}
