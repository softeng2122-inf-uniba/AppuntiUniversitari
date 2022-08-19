#include <cstdlib>
#include <iostream>
#include "CodaVet.h"
#include "PilaVet.h"

using namespace std;

void inserisciCoda(CodaVet &q){
   int i = 0;
   char risp = 's';
   tipoelem a;
   while ((risp == 's') || (risp == 's')){
      i++;
      cout << "Inserisci elemento " << i << ": ";
      cin >> a;
      q.inCoda(a);
      do{
         cout << "Altri elementi? (S/N) ";
         cin >> risp;
      } while (!((risp == 'S') || (risp == 's') || (risp == 'N') || (risp == 'n')));
   }
   cout << "Hai inserito " << i << " elementi" << endl;
}  

bool stampaCoda(CodaVet q){
   if (!q.codaVuota()){
      tipoelem a;
      while (!q.codaVuota()){
         q.leggiCoda(a);
         cout << a << " ";
         q.fuoriCoda();
      }
      cout << endl;
      return true;
   } else return false;
}

bool invertiCoda(CodaVet q, CodaVet &r){
   if (!q.codaVuota()){
      tipoelem a;
      PilaVet p;
      while (!q.codaVuota()){
         q.leggiCoda(a);
         p.inPila(a);
         q.fuoriCoda();
      }
      while (!p.pilaVuota()){
         p.leggiPila(a);
         r.inCoda(a);
         p.fuoriPila();
      }
      return true;
   } else return false;
}

bool epuraCoda(tipoelem a, CodaVet q, CodaVet &r){
   if (!q.codaVuota()){
      tipoelem b;
      while (!q.codaVuota()){
         q.leggiCoda(b);
         if (b <= a) //parametro di epurazione
            r.inCoda(b);
         q.fuoriCoda();
      }
      return true;
   } else return false;
}

bool ricercaCoda(tipoelem a, CodaVet q, int &i){
   bool trovato = false;
   if (!q.codaVuota()){
      tipoelem b;
      i = 1;
      while (!(q.codaVuota() || trovato)){
         q.leggiCoda(b);
         if (b == a)
            trovato = true;
         else {
            i++;
            q.fuoriCoda();
         }
      }
   }
   return trovato;
}

bool doppioniCoda(CodaVet q, CodaVet &r){
   if (!q.codaVuota()){
      tipoelem a;
      int i;
      while (!q.codaVuota()){
         q.leggiCoda(a);
         if (!ricercaCoda(a, r, i))
            r.inCoda(a);
         q.fuoriCoda();
      }
      return true;
   } else return false;
}

int main(int argc, char *argv[])
{
   CodaVet q, r;
   tipoelem a;
   int i;
   cout << "Inserimento elementi in coda Q:" << endl;
   inserisciCoda(q);
   cout << endl << "Stampa della coda Q:" << endl << "Q: ";
   stampaCoda(q);
   cout << endl << "Ricerca di un elemento nella coda Q:" << endl << "Inserisci elemento: ";
   cin >> a;
   if (ricercaCoda(a, q, i))
      cout << a << " trovato in posizione " << i << endl;
   else
      cout << a << " non trovato" << endl;
   cout << endl << "Epurazione della coda Q:" << endl << "Parametro di epurazione: ";
   cin >> a;
   epuraCoda(a, q, r);
   cout << "R: ";
   stampaCoda(r);
   r.creaCoda();
   cout << endl << "Inversione della coda Q:" << endl <<"R: ";
   invertiCoda(q, r);
   stampaCoda(r);
   r.creaCoda();
   cout << endl << "Eliminazione dei doppioni dalla coda R:" << endl << "R: ";
   doppioniCoda(q, r);
   stampaCoda(r);
   cout << endl;
   system("PAUSE");
   return 0;
}
