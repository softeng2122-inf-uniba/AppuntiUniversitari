#include <iostream>
#include <stdlib.h>
#include "./NodoBinario.h"
#include "./AlberoBinario.h"

using namespace std;

int main(){

    AlberoBinario tree;
    tipoelem e;
    int r;

	cout<<"\n\n\tSTRUTTURA DATI ALBERO BINARIO\\n\n";
    cout<<"\nVuoi creare l'albero? (1/0)...";
	cin>>r;
	if(r==1)
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
	return 0;
}
