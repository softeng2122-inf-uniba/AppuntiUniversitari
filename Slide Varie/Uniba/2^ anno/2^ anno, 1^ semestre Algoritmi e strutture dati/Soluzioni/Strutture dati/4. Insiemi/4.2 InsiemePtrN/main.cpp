#include <cstdlib>
#include <iostream>
#include "InsiemePtrN.h"

using namespace std;

void inserisciInsieme(InsiemePtrN &i){
   char risp = 's';
   tipoelem a;
   int index = 0;
   while ((risp == 's') || (risp == 'S')){
      index++;
      cout << "Inserisci elemento " << index << ": ";
      cin >> a;
      if (!i.appartiene(a))
         i.inserisci(a);
      else{
         cout << "Elemento " << a << " esistente" << endl;
         index--;
      }
      do{
         cout << "Altri elementi? (S/N) ";
         cin >> risp;
      } while (!((risp == 's') || (risp == 'S') || (risp == 'n') || (risp == 'N')));
   }
   cout << "Hai inserito " << index << " elementi" << endl;
}

void stampaInsieme(InsiemePtrN &i){
	cout << "{";
	posizione p = i.getInsieme();
	while(p != NULL){
		cout << " " << p->getEtichetta();
		p = p->getSuccessivo();
	}
	cout << " }" << endl;
}

int main(int argc, char *argv[]){
	InsiemePtrN i, j, k;
	cout << "Inserimento insieme I:" << endl;
   inserisciInsieme(i);
	cout << endl << "I = ";
	stampaInsieme(i);
	cout << endl << "Inserimento insieme J:" << endl;
   inserisciInsieme(j);
	cout << endl << "J = ";
	stampaInsieme(j);
	cout << endl << endl << "Operazioni su insiemi:" << endl;
	k = j.intersezione(i);
	cout << "I intersecato J = K = ";
	stampaInsieme(k);
	k = j.unione(i);
	cout << "I    unito    J = K = ";
	stampaInsieme(k);
	k = i.differenza(j);
	cout << "I     meno    J = K = ";
	stampaInsieme(k);
	cout << endl;
	system("PAUSE");
	return 0;
}
