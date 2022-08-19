#include <cstdlib>
#include <iostream>
#include "PilaPtr.h"

using namespace std;

void inserisciPila(PilaPtr &p){
   int i = 0;
   char risp = 's';
   tipoelem a;
   while ((risp == 's') || (risp == 's')){
      i++;
      cout << "Inserisci elemento " << i << ": ";
      cin >> a;
      p.inPila(a);
      do{
         cout << "Altri elementi? (S/N) ";
         cin >> risp;
      } while (!((risp == 'S') || (risp == 's') || (risp == 'N') || (risp == 'n')));
   }
   cout << "Hai inserito " << i << " elementi" << endl;
}

bool copiaPila(PilaPtr &p, PilaPtr &q){
   PilaPtr r;
   if (!p.pilaVuota()){
      tipoelem a;
      while (!p.pilaVuota()){
         p.leggiPila(a);
         r.inPila(a);
         p.fuoriPila();
      }
      while (!r.pilaVuota()){
         r.leggiPila(a);
         p.inPila(a);
         q.inPila(a);
         r.fuoriPila();
      }
      return true;
   } else return false;
}

bool invertiPila(PilaPtr &p, PilaPtr &q){
   if (!p.pilaVuota()){
      tipoelem a;
      PilaPtr r;
      copiaPila(p, r);
      while (!r.pilaVuota()){
         r.leggiPila(a);
         q.inPila(a);
         r.fuoriPila();
      }
      //copiaPila(r, p);
      return true;
   } else return false;
}

bool stampaPila(PilaPtr &p){
   if (!p.pilaVuota()){
      PilaPtr q;
      copiaPila(p, q);
      tipoelem a;
      while (!q.pilaVuota()){
         q.leggiPila(a);
         cout << a << " ";
         q.fuoriPila();
      }
      cout << endl;
      //copiaPila(q, p);
      return true;
   } else return false;
}

bool epuraPila(tipoelem a, PilaPtr &p, PilaPtr &q){
   if (!p.pilaVuota()){
      tipoelem b;
      PilaPtr r; //appoggio per p
      PilaPtr s; //appoggio per q
      copiaPila(p, r);
      while (!r.pilaVuota()){
         r.leggiPila(b);
         if (b <= a) //parametro di epurazione
            s.inPila(b);
         r.fuoriPila();
      }
      //copiaPila(r, p);
      invertiPila(s, q);
      return true;
   } else return false;
}

bool ricercaPila(tipoelem a, PilaPtr &p, int &i){
   bool trovato = false;
   if (!p.pilaVuota()){
      tipoelem b;
      PilaPtr q;
      copiaPila(p, q);
      i = 1;
      while (!(q.pilaVuota() || trovato)){
         q.leggiPila(b);
         if (b == a){
            trovato = true;
            //cout << "Elemento " << a << " trovato in posizione " << i << endl;
         }
         else{
            i++;
            q.fuoriPila();
         }
      }
   }
   return trovato;
}

bool doppioniPila(PilaPtr &p, PilaPtr &q){
   if (!p.pilaVuota()){
      tipoelem a;
      int i;
      PilaPtr r; //appoggio per p
      PilaPtr s; //appoggio per q
      copiaPila(p, r);
      while (!r.pilaVuota()){
         r.leggiPila(a);
         if (!ricercaPila(a, s, i))
            s.inPila(a);
         r.fuoriPila();
      }
      invertiPila(s, q);
      return true;
   } else return false;
}

int main(int argc, char *argv[])
{
   PilaPtr p, q;
   tipoelem a;
   int i;
   cout << "Inserimento elementi in pila P:" << endl;
   inserisciPila(p);
   cout << endl << "Stampa della pila P:" << endl << "P: ";
   stampaPila(p);
   cout << endl << "Ricerca di un elemento nella pila P:" << endl << "Inserisci elemento: ";
   cin >> a;
   if (ricercaPila(a, p, i))
      cout << a << " trovato in posizione " << i << endl;
   else
      cout << a << " non trovato" << endl;
   cout << endl << "Epurazione della pila P:" << endl << "Parametro di epurazione: ";
   cin >> a;
   epuraPila(a, p, q);
   cout << "Q: ";
   stampaPila(q);
   q.creaPila();
   cout << endl << "Inversione della pila P:" << endl <<"Q: ";
   invertiPila(p, q);
   stampaPila(q);
   q.creaPila();
   cout << endl << "Eliminazione dei doppioni dalla pila P:" << endl << "Q: ";
   doppioniPila(p, q);
   stampaPila(q);
   cout << endl;
   system("PAUSE");
   return 0;
}
