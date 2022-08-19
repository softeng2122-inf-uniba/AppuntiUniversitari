/*
Appello laboratorio 18 settembre 2006
Implementare la struttura dati Albero binario di ricerca in cui ogni nodo 
contiene un intervallo chiuso (coppia ordinata di numeri 
reali [t1, t2], con t1<t2). Possiamo rappresentare un intervallo [t1, t2] come 
un oggetto i, con i campi low[i] = t1 (estremo inferiore) e high[i] = t2
(estremo superiore). Per ogni nodo x dell'albero la chiave di x è l'estremo 
inferiore, low[x], dell'intervallo. Realizzare i seguenti operatori:
o Cerca-Intervallo(T: albero-bin, i: intervallo): nodo trova un nodo nell'albero 
T il cui intervallo si sovrappone all'intervallo i (due intervalli a e b si 
sovrappongono se low[a]<high[b] e low[b]<high[a])
o Min-Intervallo(T: albero-bin, i: real): nodo trova il nodo x nell'albero T il 
cui intervallo contiene il numero i ed ha la minima ampiezza (high[x]-low[x]) 
fra tutti gli intervalli che contengono i
o Max(T: albero-bin, n: nodo): real restituisce un valore che è il massimo tra 
tutti gli estremi degli intervalli memorizzati nel sottoalbero con radice in n
*/

#ifndef MAIN_H
#include "main.h"
#endif

#ifndef BINALBERO_H
#include "BinAlbero.h"
#endif

#ifndef CODAPTR_H
#include "CodaPtr.h"
#endif

#ifndef PILAPTR_H
#include "PilaPtr.h"
#endif

struct intervallo {
       double t1;
       double t2;
};

typedef nodoBin<intervallo> *nodo;

bool check(double a, double b) {
     if (a<b)
        return true;
     else
        return false;
};

void inserisci(intervallo e, nodo n, BinAlbero<intervallo> &albero) {
     intervallo b;
     if (albero.binAlberoVuoto()) {
        nodo nuovo=new (nodoBin<intervallo>);
        albero.insBinRadice(nuovo);
        albero.scriviNodo(e, albero.binRadice());
     } else {
        b=albero.leggiNodo(n);
        if (e.t1<b.t1) {
           if (albero.sxVuoto(n)) {
              albero.insFiglioSx(n);
              albero.scriviNodo(e,albero.figlioSx(n));
           } else
              inserisci(e,albero.figlioSx(n),albero);
        }
        if (e.t1>b.t1) {
           if (albero.dxVuoto(n)) {
              albero.insFiglioDx(n);
              albero.scriviNodo(e,albero.figlioDx(n));
           } else
              inserisci(e,albero.figlioDx(n),albero);
        }
     }
};

void visitaOutputB(BinAlbero<intervallo> &tree, nodo n, int counter, int &numnodi) {
     int i;
     numnodi++;
     intervallo a;
     if (tree.binAlberoVuoto()) {
        cout<<"\tAlbero privo di elementi!"<<endl;
        return;
     }
     for(i=0;i<counter-1;i++)
 	    cout<<"    ";
     if(counter>0)
 	    cout<<"+---";
     a=tree.leggiNodo(n);
     cout<< "[" << a.t1 << "," << a.t2 << "]" <<"\n";
     if (!tree.sxVuoto(n))
  	    visitaOutputB(tree, tree.figlioSx(n),counter+1,numnodi);
     else {
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
     else {
	    for(i=0;i<counter;i++)
	       cout<<"    ";
        if(counter>0)
           cout<<"+---";
        cout<<"<>\n";
     }
     return;
};

bool sovrapponibili(intervallo a, intervallo b) {
     if ((a.t1<b.t2)&&(b.t1<a.t2))
        return true;
     else
        return false;
};

nodo cercaIntervallo(BinAlbero<intervallo> &t, intervallo b){
   	 CodaPtr<nodo> q;
   	 nodo p=t.binRadice();
     q.inCoda(p);
   	 nodo ret=NULL;
   	 bool trovato=false;
   	 while (!q.codaVuota()&&!trovato) {
        p=q.leggiCoda();
      	intervallo a;
      	a=t.leggiNodo(p);
		if (sovrapponibili(a, b)) {
		   ret=p;
		   trovato=true;
        }
		q.fuoriCoda();
    	if (!t.sxVuoto(p)){
		   q.inCoda(t.figlioSx(p));
		}
		if (!t.dxVuoto(p)){
		   q.inCoda(t.figlioDx(p));
		}
     }
     return (ret);
};

double ampiezza(intervallo a) {
   return (a.t2-a.t1);
};

bool appartiene(double i, intervallo a) {
    if ((a.t1<=i)&&(i<=a.t2))
       return true;
    else
       return false;
};

nodo minIntervallo(BinAlbero<intervallo> &t, double i){
   	 CodaPtr<nodo> q;
   	 nodo p=t.binRadice();
     q.inCoda(p);
   	 nodo ret=NULL;
   	 double minAmp=ampiezza(t.leggiNodo(q.leggiCoda()));
   	 double appoggio;
   	 while (!q.codaVuota()) {
        p=q.leggiCoda();
      	intervallo a;
      	a=t.leggiNodo(p);
		if (appartiene(i, a)) {
		   appoggio=ampiezza(a);
		   if (appoggio<minAmp) { 
		      minAmp=appoggio;
		      ret=p;
		   }
        }
		q.fuoriCoda();
    	if (!t.sxVuoto(p)){
		   q.inCoda(t.figlioSx(p));
		}
		if (!t.dxVuoto(p)){
		   q.inCoda(t.figlioDx(p));
		}
     }
     return (ret);
};

double max(nodo p, BinAlbero<intervallo> &t){
   	 CodaPtr<nodo> q;
   	 q.inCoda(p);
   	 intervallo primo;
   	 primo=t.leggiNodo(p);
   	 double max_sup=primo.t2;
   	 while (!q.codaVuota()) {
        p=q.leggiCoda();
      	intervallo a;
      	a=t.leggiNodo(p);
		if (a.t2>max_sup)
		   max_sup=a.t2;
		q.fuoriCoda();
    	if (!t.sxVuoto(p)){
		   q.inCoda(t.figlioSx(p));
		}
		if (!t.dxVuoto(p)){
		   q.inCoda(t.figlioDx(p));
		}
     }
     return max_sup;
};

nodo ricerca(BinAlbero<intervallo> &t, intervallo e){
   	 CodaPtr<nodo> q;
   	 nodo p=t.binRadice();
   	 q.inCoda(p);
   	 nodo ret=NULL;
   	 bool trovato=false;
   	 while (!q.codaVuota()&&!trovato) {
        p=q.leggiCoda();
      	intervallo a;
      	a=t.leggiNodo(p);
      	if ((a.t1==e.t1)&&(a.t2==e.t2)) {
      	   trovato=true;
      	   ret=p;
   	   }
		q.fuoriCoda();
    	if (!t.sxVuoto(p)){
		   q.inCoda(t.figlioSx(p));
		}
		if (!t.dxVuoto(p)){
		   q.inCoda(t.figlioDx(p));
		}
     }
     return ret;
};

int main() {
     intervallo e;
     BinAlbero<intervallo> albero_01;
     char risp='y';
     int liv=0;
     double bo;
     nodo bubu=new (nodoBin<intervallo>);
     int numNodi=0;
     int height;
     cout<<"* * *  Acquisizione di un albero binario di ricerca di intervalli di reali  * * *"<<endl;
     cout << endl;
     while ((risp=='y')||(risp=='Y')) {
        do {
           cout << "Inserisci estremo inferiore intervallo: ";
           cin >> e.t1;
           cout << "Inserisci estremo superiore intervallo: ";
           cin >> e.t2;
        } while (!check(e.t1, e.t2));
        inserisci(e, albero_01.binRadice(), albero_01);
        do {
           cout << "Altro nome? (y/n) ";
           cin >> risp;
        } while (!((risp=='y')||(risp=='Y')||(risp=='n')||(risp=='N')));
     }
     cout << "\nStampa Albero 1: \n";
     visitaOutputB(albero_01, albero_01.binRadice(), liv,numNodi);
     cout << endl;
     cout << "\n\nInserisci l'intervallo da sovrapporre: " << endl << endl;
     do {
        cout << "Inserisci estremo inferiore intervallo: ";
        cin >> e.t1;
        cout << "Inserisci estremo superiore intervallo: ";
        cin >> e.t2;
     } while (!check(e.t1, e.t2));
     bubu=cercaIntervallo(albero_01, e);
     if (bubu!=NULL) {
	    cout << "\nL'intervallo cercato e' presente!" << endl;
        e=albero_01.leggiNodo(bubu);
        cout << "[" << e.t1 << "," << e.t2 << "]" << " <-- questo qui!!" << endl;
     }
     else cout << "\nL'intervallo non e' presente.\n" << endl;
     cout << "Inserisci reale di cui trovare l'intervallo con la minima ampiezza: ";
     cin >> bo;
     bubu=minIntervallo(albero_01, bo);
     if (bubu!=NULL) {
        cout << "Ecco l'intervallo: ";
        e=albero_01.leggiNodo(bubu);
        cout << "[" << e.t1 << "," << e.t2 << "]" << " <-- e' lui!!" << endl;
     }
     else cout << "Il reale inserito non e' contenuto in nessun intervallo!" << endl;
     cout << "\n\nInserisci l'intervallo del sotto-albero in cui cercare il sup maggiore: " << endl << endl;
     do {
        cout << "Inserisci estremo inferiore intervallo: ";
        cin >> e.t1;
        cout << "Inserisci estremo superiore intervallo: ";
        cin >> e.t2;
     } while (!check(e.t1, e.t2));
     bubu=ricerca(albero_01, e);
     if (bubu!=NULL){
       bo=max(bubu, albero_01);
       cout << "Il massimo dei sup degli intervalli e' " << bo << endl << endl;
     } else cout << "L'intervallo inserito non e' presente into the tree!" << endl;
     system("pause");
     return 0;
}
