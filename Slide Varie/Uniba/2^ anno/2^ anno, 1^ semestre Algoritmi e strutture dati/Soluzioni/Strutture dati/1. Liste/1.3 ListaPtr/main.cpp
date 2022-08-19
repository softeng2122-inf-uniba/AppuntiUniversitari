#include <cstdlib>
#include <iostream>
#include "ListaPtr.h"

using namespace std;

void inserisciLista(ListaPtr &l){
   int i = 0;
   char risp = 's';
   tipoelem a;
   int p;
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

void stampaLista(ListaPtr &l){
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

bool ricercaLista(ListaPtr &l, tipoelem a, posizione &p, int &i){
   bool trovato = false;
   if (!l.listaVuota()){
      p = l.primoLista();
      tipoelem b;
      while (!(l.fineLista(p) || trovato)){
         l.leggiLista(b, p);
         if (a == b){
            i = 1;
            posizione q = l.primoLista();
            while (p != q){
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

bool invertiLista(ListaPtr &l, ListaPtr &m){
   if (!l.listaVuota()){
      posizione p = l.primoLista();
      tipoelem a;
      while (!l.fineLista(l.succLista(p)))
         p = l.succLista(p); //prende l'ultimoLista di l
      while (p != l.primoLista()){
         l.leggiLista(a, p);
         m.insLista(a, NULL);
         p = l.predLista(p);
      }
      l.leggiLista(a, p); //primo elemento di l
      m.insLista(a, NULL);
      return true;
   } else return false;
}

bool epuraLista(tipoelem a, ListaPtr &l, ListaPtr &m){
   bool epura = false;
   if (!l.listaVuota()){
      tipoelem b;
      posizione p = l.primoLista();
      while (!l.fineLista(p)){
         l.leggiLista(b, p);
         if (b <= a) //parametro di epurazione
            m.insLista(b, NULL);
         p = l.succLista(p);
      }
      epura = true;
   }
   return epura;
}

bool doppioniLista(ListaPtr &l, ListaPtr &m){
   if(!l.listaVuota()){
      tipoelem a;
      posizione p = l.primoLista();
      posizione q;
      int i = 0;
      while (!l.fineLista(p)){
         l.leggiLista(a, p);
         if (!ricercaLista(m, a, q, i))
            m.insLista(a, NULL);
         p = l.succLista(p);
      }
      return true;
   } else return false;
}

posizione recuperaPos(tipoelem a, ListaPtr &l){ //verrà richiamata sempre quando l NON è vuota
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

void inserisciListaOrd(ListaPtr &l){
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

bool fondiLista(ListaPtr &l, ListaPtr &m, ListaPtr &n){ //le liste devono essere ordinate
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
		   n.insLista(c, NULL);
		}
   }   
	while(!l.fineLista(p)){
	   l.leggiLista(a, p);
		n.insLista(a, NULL);
		p = l.succLista(p);
	}
	while(!m.fineLista(q)){
	   m.leggiLista(b, q);
		n.insLista(b, NULL);
		q = m.succLista(q);
	}
   if (n.listaVuota())
      return true;
   else return false;
}
 
 
int main(int argc, char *argv[])
{
   ListaPtr l, m, n;
   tipoelem a;
   posizione p;
   int i;
   cout << "Inserimento non ordinato della lista L:" << endl << endl;
   inserisciLista(l);
   cout << endl << "L: ";
   stampaLista(l);
   cout << endl << "Epurazione della lista L:" << endl << "Parametro di epurazione: ";
   cin >> a;
   epuraLista(a, l, m);
   cout << "M: ";
   stampaLista(m);
   cout << endl << "Ricerca di un elemento nella lista M:" << endl << "Inserisci elemento: ";
   cin >> a;  
   if (ricercaLista(m, a, p, i))
      cout << a << " trovato in posizione " << i << endl;
   else 
      cout << a << " non trovato" << endl;
   cout << endl << "Inversione della lista M:" << endl << "M: ";
   invertiLista(m, n);
   stampaLista(n);
   m = n;
   n.creaLista();
   cout << endl << "Eliminazione dei doppioni della lista M" << endl << "M: ";
   doppioniLista(m, n);
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
