// Implementazione dell'algoritmo per la conversione da albero n-ario in albero binario

#ifndef MAIN_H
#include "main.h"
#endif

#ifndef BINALBERO_H
#include "BinAlbero.h"
#endif

#ifndef NALBERO_H
#include "NAlbero.h"
#endif

// Funzione che stampa un albero binario con conteggio del livello di profondità
void visitaOutputB(BinAlbero<string> &tree, nodoBin<string> *n, int counter, int &numnodi)
{
 int 	i;
 numnodi++;
 for(i=0;i<counter-1;i++)
 	 cout<<"    ";
 if(counter>0)
 	cout<<"+---";
 cout<<tree.leggiNodo(n)<<"\n";
 if (!tree.sxVuoto(n))
  	 visitaOutputB(tree, tree.figlioSx(n),counter+1,numnodi);
 else
   {
	 for(i=0;i<counter;i++)
	 	cout<<"    ";
    if(counter==0)
    	cout<<"    ";
    if(counter>0)
    	 cout<<"+---";
    cout<<"<>\n";
   }
 if (!tree.dxVuoto(n))
 	visitaOutputB(tree, tree.figlioDx(n),counter+1,numnodi);
 else
  	{
	 for(i=0;i<counter;i++)
	 cout<<"    ";
    if(counter>0)
      cout<<"+---";
    cout<<"<>\n";
   }
 return;
};

void wait(char *msg)
//funzione utility per interrompere l'esecuzione del programma
//attende l'input dell'utente per ripartire
//richiede una strinda come argomento, essa sarà visualizzata
//come messaggio per l'utente
	{
   	char stop='?';

      cout<<msg;
      while(stop!='y' && stop!='Y')
      	cin>>stop;
		return;
};

// Funzione che stampa un albero n_rio con conteggio del numero di nodi
void visitaOutputN(NAlbero<string> &tree, nodoN<string> *u, int counter, int &numNodi)
{
 int i;
 numNodi++;
 for(i=0;i<counter-1;i++)
 	cout<<"    ";
 if(counter>0)
 	cout<<"+---";
 cout<<tree.leggiNodo(u)<<"\n";
 if(!tree.foglia(u))
 	{
    nodoN<string> *v=tree.primoFiglio(u);
    counter++;
    while(!tree.ultimoFratello(v))
      {
		 visitaOutputN(tree, v, counter, numNodi);
       v=tree.succFratello(v);
      }
    visitaOutputN(tree, v, counter, numNodi);
   }
 return;
};

// Funzione che crea un albero n_rio
void costruisciNARIO(NAlbero<string> &tree, nodoN<string> *u, int counter)
{
 char again;
 string val;
 NAlbero<string> appo;
 appo.creaNAlbero();
 if(u==tree.radice())
  	{
    cout<<"\n Livello"<<counter;
	 cout<<"\n Inserisci il valore del nodo corrente: ";
    cin>>val;
	 tree.scriviNodo(val,u);
    cout<<"\n nodo Radice etichetta:["<<tree.leggiNodo(u)<<"]";
    counter++;
   }
 again='?';
 cout<<"\n vuoi aggiungere un figlio?"<<"\n\n digita:\n   '1' in caso affermativo,\n"
 <<"   '0' per non aggiungere figli: ";
 while(again!='1' && again!='0')
 	cin>>again;
 if(again=='1')
 	{
    cout<<"\n Livello"<<counter;
	 cout<<"\n Inserisci il valore del nodo corrente: ";
    cin>>val;
    appo.insRadice();
	 tree.scriviNodo(val,appo.radice());
    tree.insSottoAlbero(u,u,appo);
	 cout<<"\n nodo["<<val<<"] - figlio del";
    cout<<" nodo["<<tree.leggiNodo(u)<<"]";
	 costruisciNARIO(tree, tree.primoFiglio(u), counter+1);
    cout<<"\n Livello"<<counter;
    cout<<"\n nodo["<<val<<"] - figlio del";
    cout<<" nodo["<<tree.leggiNodo(u)<<"]";
    again='?';
	 cout<<"\n vuoi aggiungere un fratello?"<<"\n\n digita:\n   '2' in caso affermativo,\n"
    <<"   '0' per non aggiungere fratelli: ";
	 while(again!='2' && again!='0')
     	cin>>again;
   }
 while(again=='2')
   {
    cout<<"\n Livello"<<counter;
	 cout<<"\n Inserisci il valore del nodo corrente: ";
	 cin>>val;
    appo.insRadice();
	 tree.scriviNodo(val,appo.radice());
    tree.insSottoAlbero(u,u,appo);
	 cout<<"\n nodo["<<val<<"] - figlio del";
    cout<<" nodo["<<tree.leggiNodo(u)<<"]";
	 costruisciNARIO(tree, tree.primoFiglio(u), counter);
	 cout<<"\n Livello"<<counter;
    cout<<"\n nodo["<<val<<"] - fratello del";
    nodoN<string> *v=tree.succFratello(tree.primoFiglio(u));
    cout<<" nodo["<<tree.leggiNodo(v)<<"]";
    again='?';
	 cout<<"\n vuoi aggiungere un altro fratello?"<<"\n\n digita:\n   '2' in caso affermativo,\n"
    <<"   '0' per non aggiungere altri fratelli: ";
	 while(again!='2' && again!='0')
    cin>>again;
   }
 return;
};

// funzione che calcola la profondità dell'albero n_rio
int depth(NAlbero<string> &tree, nodoN<string> *u)
{
 nodoN<string> *corrente;
 int max,temp;
 if(tree.foglia(u))
   return 0;
 else
   {
    corrente=tree.primoFiglio(u);
    max=0;
    while(!tree.ultimoFratello(corrente))
      {
       temp=depth(tree,corrente);
       if(max<=temp)
        	max=temp;
       corrente=tree.succFratello(corrente);
      }
    temp=depth(tree,corrente);
    if(max<=temp)
     	max=temp;
    corrente=tree.succFratello(corrente);
    return max+1;
   }
};

//definizione della funzione ricorsiva di conversione da albero n_rio a binario
void converti(NAlbero<string> T, BinAlbero<string> &B, nodoN<string> *t, nodoBin<string> *b)
{
 //esame dell'eventuale primofiglio di t
 if(!T.foglia(t))
 	{
    B.insFiglioSx(b);
    B.scriviNodo(T.leggiNodo(T.primoFiglio(t)),B.figlioSx(b));
    converti(T,B,T.primoFiglio(t),B.figlioSx(b));
   }
 //esame dell'eventuale fratello successivo di t
 nodoN<string> *v=T.succFratello(t);
 if(v!=NULL)
   {
    B.insFiglioDx(b);
    B.scriviNodo(T.leggiNodo(T.succFratello(t)),B.figlioDx(b));
    converti(T,B,T.succFratello(t),B.figlioDx(b));
   }
};

int main()
{
 BinAlbero<string> B;
 NAlbero<string> T;
 char repeat='s';
 int 	liv=0,
  		toFind=0,
      numNodi=0;
 nodoBin<string> *rad=new (nodoBin<string>);
 cout<<"\t\t* * * Costruzione dell'albero n-rio * * *\n";
 T.insRadice();
 costruisciNARIO(T,T.radice(),liv);
 cout<<"\\n\nt\t* * Schema di rappresentazione dell'albero n-rio * *\n\n";
 visitaOutputN(T, T.radice(), liv,numNodi);
 cout<<"\n Numero di nodi: "<<numNodi<<"\n";
 numNodi=0;
 cout<<"\n La profondita' dell'albero n-rio e': "<<depth(T,T.radice());
 wait("\n\n Per procedere alla conversione digita [Y]+[invio]: ");

 //inizializzazione albero binario
 B.insBinRadice(rad);
 B.scriviNodo(T.leggiNodo(T.radice()),B.binRadice());

 //conversione dell'albero n-ario in binario
 cout<<"\n\n\t\t* * * Conversione dell'albero n_rio in binario * * *\n";
 converti(T,B,T.radice(),B.binRadice());
 cout<<"\n\n Schema di rappresentazione dell'albero convertito\n\n";
 visitaOutputB(B, B.binRadice(), liv,numNodi);
 cout<<"\n Numero di nodi: "<<numNodi<<"\n\n";
 system ("Pause");
 return 0;
}
