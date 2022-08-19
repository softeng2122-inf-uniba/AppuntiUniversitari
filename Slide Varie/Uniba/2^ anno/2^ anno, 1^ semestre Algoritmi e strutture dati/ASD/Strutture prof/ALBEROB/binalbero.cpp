/*GIUSEPPE LACRIOLA 425621
 *STRUTTURA DATI ALBERO BINARIO
 *IMPLEMENTAZIONE CON STRUTTURE DINAMICHE A PUNTATORI*/

#include <iostream.h>
#include <stdlib.h>
#include "nodobin.h"
#include "bintree.h"

void main(){

Bintree tree;
tipoelem e;
char r;

	cout<<"\n\n\tSTRUTTURA DATI ALBERO BINARIO\\n\n";
   cout<<"\nVuoi creare l'albero? (s/n)...";
	cin>>r;
	if(r=='s')
		{	cout<<"\n\nInserisci la radice...";
    		cin >> e;
    		tree.insbinradice();
    		tree.scrivinodo(tree.binradice(), e);
    		tree.insalbero(tree.binradice());
    		cout<<"\n\n\t Ecco l'albero in previsita\n\n";
    		tree.previsita(tree.binradice());
    		cout<<endl;
    		cout<<"\n\n\t Ecco l'albero in postvisita\n\n";
    		tree.postvisita(tree.binradice());
    		cout<<endl;
    		cout<<"\n\n\t Ecco l'albero in invisita\n\n";
    		tree.invisita(tree.binradice());
	 		cout<<endl<<endl;
    		cout<<"\n\n\t Ecco l'albero in livello\n\n";
    		tree.visita_livello();
	 		cout<<endl<<endl;}
	system("PAUSE");
	return;
}


