/*[11/07]	Si fornisca una realizzazione (in C o C++) che dimostri il corretto 
utilizzo della struttura dati ad albero di interi e delle funzioni richieste 
di seguito: 
1.	definizione delle funzioni di immissione e stampa del contenuto dell'albero
(un nodo per riga e indentato a seconda della sua profondità); 
2.	definizione di una funzione (ricorsiva o iterativa con stack ausiliario) 
di stampa la somma dei pesi dei nodi dell'albero, dove il peso di un nodo è 
pari al numero dei suoi discendenti 
*/

#ifndef MAIN_H
#include "main.h"
#endif

#ifndef NALBERO_H
#include "NAlbero.h"
#endif

#ifndef CODAPTR_H
#include "CodaPtr.h"
#endif

#ifndef PILAPTR_H
#include "PilaPtr.h"
#endif

typedef nodoN<int> *nodo;

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
   }

// Funzione che stampa un albero n_rio con conteggio del numero di nodi
void visitaOutputN(NAlbero<int> &tree, nodo u, int counter, int &numNodi)
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
    nodo v=tree.primoFiglio(u);
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
void costruisciNARIO(NAlbero<int> &tree, nodo u, int counter)
{
 char again;
 int val;
 NAlbero<int> appo;
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
    nodo v=tree.succFratello(tree.primoFiglio(u));
    cout<<" nodo["<<tree.leggiNodo(v)<<"]";
    again='?';
	 cout<<"\n vuoi aggiungere un altro fratello?"<<"\n\n digita:\n   '2' in caso affermativo,\n"
    <<"   '0' per non aggiungere altri fratelli: ";
	 while(again!='2' && again!='0')
    cin>>again;
   }
 return;
};

int sommaPesi(nodo n, NAlbero<int> &t){
   CodaPtr<nodo> q;
   q.inCoda(n);
   int conto=0;
   while (!q.codaVuota()){
      conto++;
      n=q.leggiCoda();
		q.fuoriCoda();
		if (!t.foglia(n)){
         nodo m = t.primoFiglio(n);
    	   while (!t.ultimoFratello(m)){
            q.inCoda(m);
            m = t.succFratello(m);
         }
         q.inCoda(m);
      }
   }
   return conto-1;
};

void insPila(nodo n, NAlbero<int> &t, PilaPtr<nodo> &p){
   CodaPtr<nodo> q;
   q.inCoda(n);
   while (!q.codaVuota()){
      n=q.leggiCoda();
		p.inPila(n);
		q.fuoriCoda();
		if (!t.foglia(n)){
         nodo m = t.primoFiglio(n);
    	   while (!t.ultimoFratello(m)){
            q.inCoda(m);
            m = t.succFratello(m);
         }
         q.inCoda(m);
      }
   }
};

void scriviPesi(NAlbero<int> &t) {
     PilaPtr<nodo> pil;
     insPila(t.radice(), t, pil);
     nodo a;
     int el;
     int pes;
     while (!pil.pilaVuota()) {
        a=pil.leggiPila();
        el=t.leggiNodo(a);
        pes=sommaPesi(a, t);
        cout << "Il nodo " << el << " ha peso " << pes << endl;
        pil.fuoriPila();
     }
};
        
int main()
{
 NAlbero<int> T;
 int 	liv=0,
  		toFind=0,
      numNodi=0;
 int somma=0;
 nodo v=new (nodoN<int>);
 cout<<"\t\t* * * Costruzione dell'albero n-rio * * *\n";
 T.insRadice();
 costruisciNARIO(T,T.radice(),liv);
 cout<< endl << "* * Schema di rappresentazione dell'albero n-rio * *\n\n";
 visitaOutputN(T, T.radice(), liv,numNodi);
 scriviPesi(T);
 system("pause");
 return 0;
}
