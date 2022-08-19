#include <cstdlib>
#include <iostream>
#include "ListaCur.h"

using namespace std;

void inserisciLista(ListaCur &l){
   int i = 0;
   char risp = 's';
   tipoelem a;
   posizione p;
   while ((risp == 's') || (risp == 's')){
      i++;
      cout << "Inserisci elemento " << i << ": ";
      cin >> a;
      cout << "Posizione in cui inserire " << a << ": ";
      cin >> p;
      l.insLista(a, l.pos(p));
      do{
         cout << "Altri elementi? (S/N) ";
         cin >> risp;
      } while (!((risp == 'S') || (risp == 's') || (risp == 'N') || (risp == 'n')));
   }
   cout << "Hai inserito " << i << " elementi" << endl;
}        

void stampaLista(ListaCur l){
   if (!l.listaVuota()){
      posizione p = l.primoLista();
      tipoelem a;
      while (!l.fineLista(p)){
         l.leggiLista(a, p);
         cout << a << " ";
         p = l.succLista(p);
      }
      cout << endl;
   } else cout << "Lista vuota" << endl;
}

bool ricercaLista(ListaCur l, tipoelem a, int &i){
   bool trovato = false;
   if (!l.listaVuota()){
      posizione p = l.primoLista();
      tipoelem b;
      while (!(l.fineLista(p) || trovato)){
         l.leggiLista(b, p);
         if (a == b){
            i = 1;
            posizione q = l.primoLista();
            while (q != p){
               i++;
               q = l.succLista(q);
            }
            trovato = true;
         }
         else
            p = l.succLista(p);
      }
   }
   return trovato;
}

bool invertiLista(ListaCur l, ListaCur &m){
   if (!l.listaVuota()){
      posizione p = l.primoLista();
      tipoelem a;
      while (!l.fineLista(l.succLista(p)))
         p = l.succLista(p); //prende l'ultimoLista di l
      while (p != l.primoLista()){
         l.leggiLista(a, p);
         m.insLista(a, NIL);
         p = l.predLista(p);
      }
      l.leggiLista(a, p); //primo elemento di l
      m.insLista(a, NIL);
      return true;
   } else return false;
}

ListaCur epuraLista(tipoelem a, ListaCur l){
   ListaCur m;
   tipoelem b;
   posizione p = l.primoLista();
   while (!l.fineLista(p)){
      l.leggiLista(b, p);
      if (b <= a) //parametro di epurazione
         m.insLista(b, NIL);
      p = l.succLista(p);
   }
   return m;
}

bool doppioniLista(ListaCur l, ListaCur &m){
   if(!l.listaVuota()){
      tipoelem a;
      posizione p = l.primoLista();
      posizione q;
      int i = 0;
      while (!l.fineLista(p)){
         l.leggiLista(a, p);
         if (!ricercaLista(m, a, q))
            m.insLista(a, NIL);
         p = l.succLista(p);
      }
      return true;
   } else return false;
}

posizione recuperaPos(tipoelem a, ListaCur l){ //verrà richiamata sempre quando l NON è vuota
   posizione p = l.primoLista();
   tipoelem b;
   bool trovato = false;
   while (!(l.fineLista(p) || trovato)){
      l.leggiLista(b, p);
      if (b >= a)
         trovato = true;
      else
         p = l.succLista(p);
   }
   return p;
}

void inserisciListaOrd(ListaCur &l){
   int i = 0;
   char risp = 's';
   tipoelem a;
   posizione p;
   while ((risp == 's') || (risp == 's')){
      i++;
      cout << "Inserisci elemento " << i << ": ";
      cin >> a;
      p = recuperaPos(a, l);
      l.insLista(a, p);
      do{
         cout << "Altri elementi? (S/N) ";
         cin >> risp;
      } while (!((risp == 'S') || (risp == 's') || (risp == 'N') || (risp == 'n')));
   }
   cout << "Hai inserito " << i << " elementi" << endl;
}
 
bool fondiLista(ListaCur l, ListaCur m, ListaCur &n){ //le liste devono essere ordinate
   posizione p = l.primoLista();
	posizione q = m.primoLista();
	tipoelem a, b, c;
   if (!(l.listaVuota() || m.listaVuota())){
	   while(!(l.fineLista(p)||m.fineLista(q))){
         l.leggiLista(a, p);
         m.leggiLista(b, q);
         if(a <= b){
            c = a;
			   p = l.succLista(p);	
		   } else{
		      c = b;
			   q = m.succLista(q);	
		   }
		   n.insLista(c, NIL);
		}
   }   
	while(!l.fineLista(p)){
	   l.leggiLista(a, p);
		n.insLista(a, NIL);
		p = l.succLista(p);
	}
	while(!m.fineLista(q)){
	   m.leggiLista(b, q);
		n.insLista(b, NIL);
		q = m.succLista(q);
	}
   if (n.listaVuota())
      return true;
   else return false;
}
 
int main(int argc, char *argv[])
{
   ListaCur l, m, n;
   tipoelem a;
   posizione p;
   int i;
   cout << "Inserimento non ordinato della lista L:" << endl << endl;
   inserisciLista(l);
   cout << endl << "L: ";
   stampaLista(l);
   cout << endl << "Epurazione della lista L:" << endl << "Parametro di epurazione: ";
   cin >> a;
   l = epuraLista(a, l);
   cout << "L: ";
   stampaLista(l);
   cout << endl << "Ricerca di un elemento nella lista L:" << endl << "Inserisci elemento: ";
   cin >> a;  
   if (ricercaLista(l, a, i))
      cout << a << " trovato in posizione " << i << endl;
   else 
      cout << a << " non trovato" << endl;
   cout << endl << "Inversione della lista L:" << endl << "L: ";
   invertiLista(l, n);
   stampaLista(n);
   n.creaLista();
   cout << endl << "Eliminazione dei doppioni della lista L" << endl << "L: ";
   doppioniLista(l, n);
   stampaLista(n);
   l.creaLista();
   m.creaLista();
   n.creaLista();
   cout << endl << "Inserimento ordinato della lista L:" << endl << endl;
   inserisciListaOrd(l);
   cout << endl << "Inserimento ordinato della lista M:" << endl << endl;
   inserisciListaOrd(m);
   fondiLista(l, m, n);
   cout << endl << "Fusione delle due liste in un'unica lista N" << endl << "N: ";
   stampaLista(n);
   cout << endl;
   system("PAUSE");
   return 0;
}
