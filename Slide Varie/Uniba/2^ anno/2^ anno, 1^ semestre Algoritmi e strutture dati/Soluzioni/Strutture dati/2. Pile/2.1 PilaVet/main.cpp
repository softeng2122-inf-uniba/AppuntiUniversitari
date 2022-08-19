#include <cstdlib>
#include <iostream>
#include "PilaVet.h"

using namespace std;

void inserisciPila(PilaVet &p){
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

bool invertiPila(PilaVet p, PilaVet &q){
   if (!p.pilaVuota()){
      tipoelem a;
      while (!p.pilaVuota()){
         p.leggiPila(a);
         q.inPila(a);
         p.fuoriPila();
      }
      return true;
   } else return false;
}

bool stampaPila(PilaVet p){
   if (!p.pilaVuota()){
      tipoelem a;
      while (!p.pilaVuota()){
         p.leggiPila(a);
         cout << a << " ";
         p.fuoriPila();
      }
      cout << endl;
      return true;
   } else return false;
}

bool epuraPila(tipoelem a, PilaVet p, PilaVet &q){
   if (!p.pilaVuota()){
      tipoelem b;
      PilaVet r;
      while (!p.pilaVuota()){
         p.leggiPila(b);
         if (b <= a) //parametro di epurazione
            r.inPila(b);
         p.fuoriPila();
      }
      invertiPila(r, q);
      return true;
   } else return false;
}

bool ricercaPila(tipoelem a, PilaVet p, int &i){
   bool trovato = false;
   if (!p.pilaVuota()){
      tipoelem b;
      i = 1;
      while (!(p.pilaVuota() || trovato)){
         p.leggiPila(b);
         if (b == a)
            trovato = true;
         else{
            i++;
            p.fuoriPila();
         }
      }
   }
   return trovato;
}

bool doppioniPila(PilaVet p, PilaVet &q){
   if (!p.pilaVuota()){
      tipoelem a;
      PilaVet r;
      int i;
      while (!p.pilaVuota()){
         p.leggiPila(a);
         if (!ricercaPila(a, r, i))
            r.inPila(a);
         p.fuoriPila();
      }
      invertiPila(r, q);
      return true;
   } else return false;
}

int main(int argc, char *argv[])
{
   PilaVet p, q;
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
