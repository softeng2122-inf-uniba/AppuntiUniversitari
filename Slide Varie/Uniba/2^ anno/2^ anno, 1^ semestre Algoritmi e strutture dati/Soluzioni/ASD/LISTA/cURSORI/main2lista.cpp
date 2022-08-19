#include <iostream>
#include <stdlib.h>
#include "Listac.h"

//programma di prova per verificare che la lista
//con cursori funzioni


int main(){
int c, punto, num;
lista acqua;

c=1;
while (c>=1 && c<=5){
//punto=acqua.primolista();
cout << "(1)inserisci (2)visualizza (3)cancella (4)scorri\n";
cout << "(5)cursore all'inizio (6)esci\n";
cin >> c;
cout << endl;
switch(c){
	case 1:
      cout << "che valore vuoi inserire? ";
      cin >> num;
      if (acqua.listavuota()){
      acqua.inserisci(acqua.primolista(), num);
      punto=acqua.primolista();}
      else{
      acqua.inserisci(punto, num);
      punto=acqua.successivo(punto);}
      break;
   case 2:
   	punto=acqua.primolista();
      cout << acqua.leggi(punto) << endl;
      if (acqua.listavuota())
      	cout << "la lista è vuota....\n";
      else
   	{while (!acqua.finelista(punto)){
         punto=acqua.successivo(punto);
         cout << acqua.leggi(punto) << endl;};};
   break;
   case 3:
		acqua.cancella(punto);
   	break;
   case 4:
   	punto=acqua.successivo(punto);
      break;
   case 5:
   	punto=acqua.primolista();
      break;
   case 6:
   	cout << "byebye\n";
   	break;
   };
};
system ("pause");
return 0;
}
