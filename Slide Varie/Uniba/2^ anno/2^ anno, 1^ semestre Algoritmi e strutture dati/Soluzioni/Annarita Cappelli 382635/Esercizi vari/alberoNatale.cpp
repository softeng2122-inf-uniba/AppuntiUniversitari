/*15/12/2004
Realizzare una struttura che consenta di rappresentare un albero di Natale, 
avente l'addobbo con luci di diverso colore e dimensione. Ogni luce può 
essere collegata ad una o più luci costituendo così una ramificazione. 
Le luci sono caratterizzate dal colore (es. verde, rosso, giallo, ecc..) e 
dalla forma (sfera, cubo, candela, stella).
Implementare, i/le seguenti metodi/funzioni: 
- popolamento della struttura da tastiera; 
- stampa di tutti gli elementi presenti nella struttura corrente; 
- dato un nodo stampare il livello del nodo; 
- stampare la profondità dell'albero; 
- dato un colore ricerca del numero di luci di quel colore; 
- dato un colore stampa dell'elenco di forme e del numero di luci di una 
stessa forma che hanno quel colore.
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

#ifndef LISTAVET_H
#include "ListaVet.h"
#endif

struct pallina {
       string colore;
       string forma;
};

typedef nodoN<pallina> *nodo;

void wait(char *msg) {
   	 char stop='?';
     cout<<msg;
     while(stop!='y' && stop!='Y')
      	cin>>stop;
     return;
};

void costruisciNARIO(NAlbero<pallina> &tree, nodo u, int counter)
{
 char again;
 pallina val, corrente, corr;
 NAlbero<pallina> appo;
 appo.creaNAlbero();
 if(u==tree.radice())
  	{
    cout<<"\n Livello"<<counter;
	 cout<<"\n Inserisci il colore della pallina corrente: ";
    cin>>val.colore;
    cout << "Inserisci la forma della pallina corrente: ";
    cin >> val.forma;
	 tree.scriviNodo(val,u);
	 corrente=tree.leggiNodo(u);
    cout<<"\n nodo Radice etichetta:["<<corrente.colore << "," << corrente.forma <<"]";
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
	 cout<<"\n Inserisci il colore della pallina corrente:  ";
    cin>>val.colore;
    cout << "Inserisci la forma della pallina corrente: ";
    cin >> val.forma;
    appo.insRadice();
	 tree.scriviNodo(val,appo.radice());
    tree.insSottoAlbero(u,u,appo);
	 cout<<"\n nodo["<<val.colore << "," << val.forma<<"] - figlio del";
    corrente=tree.leggiNodo(u);
    cout<<" nodo["<<corrente.colore << "," << corrente.forma <<"]";
	 costruisciNARIO(tree, tree.primoFiglio(u), counter+1);
    cout<<"\n Livello"<<counter;
    cout<<"\n nodo["<<val.colore << "," << val.forma <<"] - figlio del";
    corrente=tree.leggiNodo(u);
    cout<<" nodo["<<corrente.colore << ","<< corrente.forma<<"]";
    again='?';
	 cout<<"\n vuoi aggiungere un fratello?"<<"\n\n digita:\n   '2' in caso affermativo,\n"
    <<"   '0' per non aggiungere fratelli: ";
	 while(again!='2' && again!='0')
     	cin>>again;
   }
 while(again=='2')
   {
    cout<<"\n Livello"<<counter;
	 cout<<"\n Inserisci il colore della pallina corrente:  ";
    cin>>val.colore;
    cout << "Inserisci la forma della pallina corrente: ";
    cin >> val.forma;
    appo.insRadice();
	 tree.scriviNodo(val,appo.radice());
    tree.insSottoAlbero(u,u,appo);
	 cout<<"\n nodo["<<val.colore << "," << val.forma <<"] - figlio del";
	 corrente=tree.leggiNodo(u);
    cout<<" nodo["<<corrente.colore << "," << corrente.forma <<"]";
	 costruisciNARIO(tree, tree.primoFiglio(u), counter);
	 cout<<"\n Livello"<<counter;
    cout<<"\n nodo["<<val.colore << "," << val.forma <<"] - fratello del";
    nodo v=tree.succFratello(tree.primoFiglio(u));
    corr=tree.leggiNodo(v);
    cout<<" nodo["<<corr.colore << "," << corr.forma <<"]";
    again='?';
	 cout<<"\n vuoi aggiungere un altro fratello?"<<"\n\n digita:\n   '2' in caso affermativo,\n"
    <<"   '0' per non aggiungere altri fratelli: ";
	 while(again!='2' && again!='0')
    cin>>again;
   }
 return;
};

void visitaOutputN(NAlbero<pallina> &tree, nodo u, int counter, int &numNodi)
{
 int i;
 pallina a;
 numNodi++;
 for(i=0;i<counter-1;i++)
 	cout<<"    ";
 if(counter>0)
 	cout<<"+---";
 a=tree.leggiNodo(u);
 cout<<"[" << a.colore << "," << a.forma << "]" <<"\n";
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

nodo trovaNodo(pallina et, nodo n, NAlbero<pallina> &t)
{
   if (t.nAlberoVuoto()) {
      cout << "Albero non addobbato! mi spiace :P " << endl << endl;
      return NULL;
   }
  
   CodaPtr< nodo > m;
   bool trovato=false;
   nodo ptr = t.radice();
   nodo u;
   pallina prov;
   m.inCoda(ptr);
   while (!m.codaVuota()&&!trovato)
         {
          u = m.leggiCoda();
          m.fuoriCoda();
          prov=t.leggiNodo(u);
          if ((prov.colore == et.colore)&&(prov.forma==et.forma)) {
             ptr = u;
             trovato=true;
          } else {
               if (u->fratello != NULL)
                  m.inCoda(u->fratello);
               if (u->primofiglio != NULL)
                  m.inCoda(u->primofiglio);
              };
         };
   if ((ptr->elem.colore != et.colore)&&(ptr->elem.forma!=et.forma))
      ptr = NULL; 
   return (ptr);    
};

int numPalline(string col, nodo n, NAlbero<pallina> &t){
     CodaPtr<nodo> q;
     q.inCoda(n);
     pallina corr;
     int num=0;
     while (!q.codaVuota()) {
        n=q.leggiCoda();
        corr=t.leggiNodo(n);
        if (corr.colore==col)
           num=num+1;
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
     return num;
};

int livello(NAlbero<pallina> &t, nodo n) {
     nodo p=new (nodoN<pallina>);
     nodo radice;
     int profon=0;
     radice=t.radice();
     p=n;
     while (p!=radice) {
        p=t.padre(p);
        profon++;
     }
     return profon;
};

int maxprof(nodo u, NAlbero<pallina> &t) {
 nodo corrente=new (nodoN<pallina>);
 int max,temp;
 if(t.foglia(u))
   return 0;
 else
   {
    corrente=t.primoFiglio(u);
    max=0;
    while(!t.ultimoFratello(corrente))
      {
       temp=maxprof(corrente, t);
       if(max<=temp)
        	max=temp;
       corrente=t.succFratello(corrente);
      }
    temp=maxprof(corrente, t);
    if(max<=temp)
     	max=temp;
    corrente=t.succFratello(corrente);
    return max+1;
   }
};   

void elencoForme(string col, nodo n, NAlbero<pallina> &t, ListaVet<pallina> &elenco){
     CodaPtr<nodo> q;
     q.inCoda(n);
     pallina corr;
     int num=0;
     posizione p=elenco.primoLista();
     while (!q.codaVuota()) {
        n=q.leggiCoda();
        corr=t.leggiNodo(n);
        if (corr.colore==col) 
           elenco.insLista(corr, p);
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

void stampaLista(ListaVet<pallina> &elenco) {
     posizione p=elenco.primoLista();
     pallina a;
     while (!elenco.fineLista(p)) {
        a=elenco.leggiLista(p);
        cout << a.forma << " ";
        p=elenco.succLista(p);
     }
     cout << endl;
};

void contaForme(ListaVet<pallina> &elenco) {
     posizione p=elenco.primoLista();
     CodaPtr<string> q;
     pallina a;
     int conto=0;
     string supp;
     while (!elenco.fineLista(p)) {
        a=elenco.leggiLista(p);
        if (!q.appartiene(a.forma))
           q.inCoda(a.forma);
        p=elenco.succLista(p);
     }
     while(!q.codaVuota()) {
        supp=q.leggiCoda();
        p=elenco.primoLista();
        while (!elenco.fineLista(p)) {
           a=elenco.leggiLista(p);
           if (a.forma==supp)
              conto++;
           p=elenco.succLista(p);
        }
        cout << "Numero elementi di forma " << supp << ": " << conto << endl;
        q.fuoriCoda();
        conto=0;
     }
}; 

int main()
{
 NAlbero<pallina> T;
 ListaVet<pallina> elenco;
 char repeat='s';
 int 	liv=0,
  		toFind=0,
      numNodi=0;
      int numP;
 int level, prof;
 pallina ball;
 string col;
 nodo cercato=new (nodoN<pallina>);
 cout<<"\t\t* * * Costruzione dell'albero n-rio * * *\n";
 T.insRadice();
 costruisciNARIO(T,T.radice(),liv);
 cout<< endl << "* * Schema di rappresentazione dell'albero n-rio * *\n\n";
 visitaOutputN(T, T.radice(), liv,numNodi);
 cout << endl << endl;
 cout << "Inserisci colore pallina di cui cercare il livello: ";
 cin >> ball.colore;
 cout << "Inserisci forma pallina di cui cercare il livello: ";
 cin >> ball.forma;
 cercato=trovaNodo(ball, T.radice(), T);
 if (cercato!=NULL) {
    level=livello(T, cercato);
    cout << "Il nodo [" << ball.colore << "," << ball.forma << "] si trova al livello " << level << endl << endl;
 } else
    cout << "Pallina inesistente!" << endl;
 prof=maxprof(T.radice(), T);
 cout << "L'albero di natale ha profondita': " << prof << endl << endl;
 cout << "Inserisci colore di cui vuoi conoscere il totale palline presenti: ";
 cin >> col;
 numP=numPalline(col, T.radice(), T);
 cout << "L'albero contiene " << numP << " palline di colore " << col << endl << endl;
 cout << "Inserisci colore di cui vuoi conoscere l'elenco delle forme presenti: ";
 cin >> col;
 cout << endl;
 elencoForme(col, T.radice(), T, elenco);
 stampaLista(elenco);
 contaForme(elenco);
 cout << endl << endl;
 system("pause");
 return 0;
}
