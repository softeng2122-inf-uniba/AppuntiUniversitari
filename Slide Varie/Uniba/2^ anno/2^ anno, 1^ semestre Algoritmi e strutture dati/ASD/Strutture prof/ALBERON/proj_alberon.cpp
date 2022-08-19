#include <iostream.h>
#include "NodoN.h"
#include "AlberoN.h"
#include <stdlib.h>
#include "NodoCN.h"
#include "CodaN.h"
int main(){

AlberoN tree;
tipoelem e;
char risp;
   cout<<"\n\n\tALBERO N-RIO\n\n";
   cout<<"\n\n  Vuoi creare l'albero n-rio? (s-n)...";
   cin>>risp;
   if (risp=='s')
   {
		tree.insradice();
   	cout<<"\n Inserire la radice dell'albero n-rio...";
   	cin>>e;
   	tree.scrivinodo(e, tree.dairadice());
   	tree.inssottoalbero(tree.dairadice());
   	cout<<"\n\n  Stampa dell'albero n-rio in previsita...\n\n";
   	tree.previsita(tree.dairadice());
   	cout<<endl<<endl;
   	system("PAUSE");
   	cout<<"\n\n  Stampa dell'albero n-rio in postvisita...\n\n";
   	tree.postvisita(tree.dairadice());
   	cout<<endl<<endl;
   	system("PAUSE");
   	cout<<"\n\n  Stampa dell'albero n-rio per livelli...\n\n";
   	tree.visita_livello();
   	cout<<endl<<endl;
   	system("PAUSE");
   	cout<<"\n\n\tNUMERO DI NODI = "<<tree.numero_nodi(tree.dairadice())<<"\n\n";
   	system("PAUSE");
   	cout<<"\n\n\tPROFONDITA' = "<<tree.profondita(tree.dairadice())<<"\n\n";
   	system("PAUSE");}

    return 0;
   }

