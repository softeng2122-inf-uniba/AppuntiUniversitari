#ifndef MAIN_H
#include "main.h"
#endif

#ifndef NALBERO_H
#include "NAlbero.h"
#endif

#ifndef CODAPTR_H
#include "CodaPtr.h"
#endif

typedef nodoN<string> *nodo;

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
void visitaOutputN(NAlbero<string> &tree, nodo u, int counter, int &numNodi)
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
void costruisciNARIO(NAlbero<string> &tree, nodo u, int counter)
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

void stampaNAlbero(nodo n, NAlbero<string> &t){
   if (n != NULL){
      while (n != NULL){
         cout << "(" << t.leggiNodo(n);
         stampaNAlbero(t.primoFiglio(n), t);
         cout << ")";
         n = t.succFratello(n);
      }
	} else cout << "()";
};

void preVisita(nodo n, NAlbero<string> &t){
   if (n != NULL){
      while (n != NULL){
         cout << t.leggiNodo(n) << " "; 
         preVisita(t.primoFiglio(n), t);
         n = t.succFratello(n);
      }
	} 
};

void postVisita(nodo n, NAlbero<string> &t){
   if (n != NULL){
      while (n != NULL){
         postVisita(t.primoFiglio(n), t);
         cout << t.leggiNodo(n) << " ";
         n = t.succFratello(n);
      }
	}
};

void inVisita(nodo n, NAlbero<string> &t){
   if (n != NULL){
      if (!t.foglia(n)){
         inVisita(t.primoFiglio(n), t);
         cout << t.leggiNodo(n) << " ";
         n = t.primoFiglio(n);
         while (!t.ultimoFratello(n)){
            n = t.succFratello(n);
            inVisita(n, t);
         }
      } else cout << t.leggiNodo(n) << " ";
	}
};

void ampiezzaN(nodo n, NAlbero<string> &t){
   CodaPtr<nodo> q;
   q.inCoda(n);
   while (!q.codaVuota()){
      n=q.leggiCoda();
		cout << t.leggiNodo(n) << " ";
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

/*nodo trovaNodo(NAlbero<string> &T, nodo genitore, string p) {
     nodo n=new (nodoN<string>);
     nodo f=new (nodoN<string>);
     if (T.leggiNodo(genitore)==p){
        return genitore;
     }
     else {
        n=NULL;
        if (!T.foglia(genitore)) {
           f=T.primoFiglio(genitore);
           while ((n==NULL)&&(!T.ultimoFratello(f))) {
              n=trovaNodo(T, f, p);
              f=T.succFratello(f);
           }
        }
        return n;
     }
};*/

nodo trovaNodo(string et, nodo n, NAlbero<string> &t)
{
   if (t.nAlberoVuoto())
      _gerr( "an error occurred in treeCL<A,B>::trovanodo:\nthe tree is empty" );
  
   CodaPtr< nodo > m;
   nodo ptr = t.radice();
   nodo u;
   m.inCoda(ptr);
   while (!m.codaVuota())
         {
          u = m.leggiCoda();
          m.fuoriCoda();
          if (t.leggiNodo(u) == et)
             ptr = u;
          else
              {
               if (u->fratello != NULL)
                  m.inCoda(u->fratello);
               if (u->primofiglio != NULL)
                  m.inCoda(u->primofiglio);
              };
         };
   if (ptr->elem != et)
      ptr = NULL; 
   return (ptr);    
};      

int main()
{
 NAlbero<string> T;
 char repeat='s';
 int 	liv=0,
  		toFind=0,
      numNodi=0;
 string myr;
 nodo bubu=new (nodoN<string>);
 cout<<"\t\t* * * Costruzione dell'albero n-rio * * *\n";
 T.insRadice();
 costruisciNARIO(T,T.radice(),liv);
 cout<< endl << "* * Schema di rappresentazione dell'albero n-rio * *\n\n";
 visitaOutputN(T, T.radice(), liv,numNodi);
 cout << "\n Stampa dell'albero!" << endl;
 stampaNAlbero(T.radice(), T);
 cout<<"\n Numero di nodi: "<<numNodi<<"\n";
 cout << endl << endl << "Visite:" << endl << "preVisita  -> T: ";
 preVisita(T.radice(), T);
 cout << endl << "postVisita -> T: ";
 postVisita(T.radice(), T);
 cout << endl << "inVisita   -> T: ";
 inVisita(T.radice(), T);
 cout << endl << "Ampiezza   -> T: ";
 ampiezzaN(T.radice(), T);
 cout << endl;
 /*cout << "Inserisci nome da cercare: ";
 cin >> myr;
 bubu=trovaNodo(myr, T.radice(), T);
 if (bubu!=NULL)
    cout << "Ecchilo --> " << T.leggiNodo(bubu);
 else
    cout << "Myr dixit: attaccati " << endl;
 cout << endl;*/
 system ("Pause");
 return 0;
}
