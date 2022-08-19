#include <cstdlib>
#include <iostream>
#include "CodaPtr.h"
#include "PilaPtr.h"

using namespace std;

void inserisciCoda(CodaPtr &q){
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
      } while (!((risp == 'S') || (risp == 's') || (risp == 'N') || 

(risp == 'n')));
   }
   cout << "Hai inserito " << i << " elementi" << endl;
}

bool copiaCoda(CodaPtr &q, CodaPtr &r){
   if (!q.codaVuota()){
      CodaPtr s;
      tipoelem a;
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

bool stampaCoda(CodaPtr &q){
   if (!q.codaVuota()){
      CodaPtr r;
      copiaCoda(q, r);
      tipoelem a;
      while (!r.codaVuota()){
         r.leggiCoda(a);
         cout << a << " ";
         r.fuoriCoda();
      }
      cout << endl;
      return true;
   } else return false;
}

bool invertiCoda(CodaPtr &q, CodaPtr &r){
   if (!q.codaVuota()){
      tipoelem a;
      CodaPtr s; //appoggio per q
      copiaCoda(q, s);
      PilaPtr p;
      while (!s.codaVuota()){
         s.leggiCoda(a);
         p.inPila(a);
         s.fuoriCoda();
      }
      while (!p.pilaVuota()){
         p.leggiPila(a);
         r.inCoda(a);
         p.fuoriPila();
      }
      return true;
   } else return false;
}

bool epuraCoda(tipoelem a, CodaPtr &q, CodaPtr &r){
   if (!q.codaVuota()){
      tipoelem b;
      CodaPtr s; //appoggio per q
      copiaCoda(q, s);
      while (!s.codaVuota()){
         s.leggiCoda(b);
         if (b <= a) //parametro di epurazione
            r.inCoda(b);
         s.fuoriCoda();
      }
      return true;
   } else return false;
}

bool ricercaCoda(tipoelem a, CodaPtr &q, int &i){
   bool trovato = false;
   if (!q.codaVuota()){
      CodaPtr r; //appoggio per q
      copiaCoda(q, r);
      tipoelem b;
      i = 1;
      while (!(r.codaVuota() || trovato)){
         r.leggiCoda(b);
         if (b == a)
            trovato = true;
         else {
            i++;
            r.fuoriCoda();
         }
      }
   }
   return trovato;
}

bool doppioniCoda(CodaPtr &q, CodaPtr &r){
   if (!q.codaVuota()){
      CodaPtr s;
      copiaCoda(q, s);
      tipoelem a;
      int i;
      while (!s.codaVuota()){
         s.leggiCoda(a);
         if (!ricercaCoda(a, r, i))
            r.inCoda(a);
         s.fuoriCoda();
      }
      return true;
   } else return false;
}

int main(int argc, char *argv[])
{
   CodaPtr q, r;
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
