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

struct nodoLivello {
     nodoBin<string> *node;
     int livello;
};

void inserisci(string e, nodoBin<string> *n, BinAlbero<string> &albero) {
     if (albero.binAlberoVuoto()) {
        nodoBin<string> *nuovo=new (nodoBin<string>);
        albero.insBinRadice(nuovo);
        albero.scriviNodo(e, albero.binRadice());
     } else {
        if (e<albero.leggiNodo(n)) {
           if (albero.sxVuoto(n)) {
              albero.insFiglioSx(n);
              albero.scriviNodo(e,albero.figlioSx(n));
           } else
              inserisci(e,albero.figlioSx(n),albero);
        }
        if (e>albero.leggiNodo(n)) {
           if (albero.dxVuoto(n)) {
              albero.insFiglioDx(n);
              albero.scriviNodo(e,albero.figlioDx(n));
           } else
              inserisci(e,albero.figlioDx(n),albero);
        }
     }
};

void visitaOutputB(BinAlbero<string> &tree, nodoBin<string> *n, int counter, int &numnodi) {
     int i;
     numnodi++;
     if (tree.binAlberoVuoto()) {
        cout<<"\tAlbero privo di elementi!"<<endl;
        return;
     }
     for(i=0;i<counter-1;i++)
 	    cout<<"    ";
     if(counter>0)
 	    cout<<"+---";
     cout<<tree.leggiNodo(n)<<"\n";
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

void stampaBinAlbero(nodoBin<string> *p, BinAlbero<string> &t) {
	 if (p != NULL){
        string a;
        a=t.leggiNodo(p);
    	cout << "(" << a;
		if (!t.sxVuoto(p)){
		   stampaBinAlbero(t.figlioSx(p), t);
		} else cout << "()";
		if (!t.dxVuoto(p)){
			stampaBinAlbero(t.figlioDx(p), t);
		} else cout << "()";
		cout << ")";
	}
};

void preVisita(nodoBin<string> *p, BinAlbero<string> &t){
	 if (p != NULL) {
        string a;
        a=t.leggiNodo(p);
    	cout << a << " ";
		if (!t.sxVuoto(p)){
		   preVisita(t.figlioSx(p), t);
		}
		if (!t.dxVuoto(p)){
		   preVisita(t.figlioDx(p), t);
		}
	 }
};

void postVisita(nodoBin<string> *p, BinAlbero<string> &t){
	 if (p != NULL) {
		if (!t.sxVuoto(p)) {
		   preVisita(t.figlioSx(p), t);
		}
		if (!t.dxVuoto(p)){
		   preVisita(t.figlioDx(p), t);
		}
		string a;
        a=t.leggiNodo(p);
    	cout << a << " ";
	 }
};

void inVisita(nodoBin<string> *p, BinAlbero<string> &t){
	 if (p != NULL) {
    	if (!t.sxVuoto(p)) {
		   inVisita(t.figlioSx(p), t);
		}
		string a;
        a=t.leggiNodo(p);
    	cout << a << " ";
		if (!t.dxVuoto(p)){
		   inVisita(t.figlioDx(p), t);
		}
	 }
};

void ampiezzaBin(nodoBin<string> *p, BinAlbero<string> &t){
   	 CodaPtr<nodoBin<string> *> q;
   	 q.inCoda(p);
   	 while (!q.codaVuota()) {
        p=q.leggiCoda();
      	string a;
      	a=t.leggiNodo(p);
		cout << a << " ";
		q.fuoriCoda();
    	if (!t.sxVuoto(p)){
		   q.inCoda(t.figlioSx(p));
		}
		if (!t.dxVuoto(p)){
		   q.inCoda(t.figlioDx(p));
		}
     }
};

nodoBin<string> *ricerca(string e, nodoBin<string> *n, const BinAlbero<string> &albero) {
     if (albero.binAlberoVuoto()) {
        cout<<"\tAlbero privo di elementi!"<<endl;
        return NULL;
     }
     nodoBin<string> *ret=new (nodoBin<string>);
     if (e==albero.leggiNodo(n)) {
        ret=n;
        return ret;
     }
     if (e<albero.leggiNodo(n)) {
        if (!albero.sxVuoto(n))
      	   ret=ricerca(e, albero.figlioSx(n), albero);
        else
           return NULL;
     }
     if (e>albero.leggiNodo(n)) {
        if (!albero.dxVuoto(n))
           ret=ricerca(e, albero.figlioDx(n), albero);
        else
           return NULL;
     }
     return ret;
};



nodoBin<string> *maxDestro(BinAlbero<string> &t, int k) {
      int conto=0;
      CodaPtr<nodoLivello *> m;
      PilaPtr<nodoBin<string> *> p;
      nodoLivello *u =new nodoLivello;
      nodoLivello *f;
      nodoBin<string> *supp=t.binRadice();
      u->node=supp;
      u->livello=0;
      m.inCoda(u);
    
   while (!m.codaVuota())
         {
          u = m.leggiCoda();
          if (u->livello==k)
             p.inPila(u->node); 
          m.fuoriCoda();          
          if (!t.sxVuoto(u->node)) {
             f=new nodoLivello;
             f->node=u->node->sx;
             f->livello=u->livello+1;
             m.inCoda(f);
          }               
          if (!t.dxVuoto(u->node)) {
             f=new nodoLivello;
             f->node=u->node->dx;
             f->livello=u->livello+1;
             m.inCoda(f);
          }
          }; 
   return p.leggiPila();
};
     

int altezza(nodoBin<string> *n,const BinAlbero<string> &albero) {
     int prosx=0,prodx=0;
     if (albero.sxVuoto(n)&& albero.dxVuoto(n))
        return 0;
     if (!albero.sxVuoto(n)) {
        ++prosx;
        prosx=prosx+altezza(albero.figlioSx(n), albero);
     }
     if (!albero.dxVuoto(n)) {
        ++prodx;
        prodx=prodx+altezza(albero.figlioDx(n), albero);
     }
	 if (prosx>prodx)
        return prosx;
     else
        return prodx;
};

// funzione che vale solo se il tipoelem e' un int
/*int sommanodi(string e, nodoBin<string> *n, const BinAlbero<string> &albero) {
     int somma=0;
     bool presente=true;
	 if (albero.binAlberoVuoto())
        return -1;
     if (e==albero.leggiNodo(n))
        return albero.leggiNodo(n);
     if (e<albero.leggiNodo(n)) {
        if (albero.sxVuoto(n))
           presente=false;
        else {
           somma=somma+albero.leggiNodo(n);
           if (sommanodi(e, albero.figlioSx(n), albero)==-1)
              presente=false;
           else
              somma=somma+sommanodi(e, albero.figlioSx(n), albero);
        }
     } else {
        if (e>albero.leggiNodo(n)) {
           if (albero.dxVuoto(n))
              presente=false;
   		   else {
              somma=somma+albero.leggiNodo(n);
       	      if (sommanodi(e, albero.figlioDx(n), albero)==-1)
                 presente=false;
       	      else
                 somma=somma+sommanodi(e, albero.figlioDx(n), albero);
           }
        }
     }
     if(presente)
        return somma;
     else
        return -1;
};*/

int profondity(nodoBin<string> *n, BinAlbero<string> &t) {
     int count=0;
     if (n==t.binRadice())
        return count;
     while (n!=t.binRadice()) {
        count++;
        n=t.binPadre(n);
     }
     return count;
};

int ricercaprof(string e, nodoBin<string> *n, const BinAlbero<string> &albero) {
     if (albero.binAlberoVuoto())
        return -1;
     bool trovato=true;
     int prof=0;
     if (e==albero.leggiNodo(n))
        return prof;
     if (e<albero.leggiNodo(n)) {
        if (albero.sxVuoto(n))
           trovato=false;
        else {
           prof=prof+1;
           if(ricercaprof(e, albero.figlioSx(n), albero)==-1)
              trovato=false;
           else {
              prof=prof+ricercaprof(e, albero.figlioSx(n), albero);
           }
        }
     }
     if (e>albero.leggiNodo(n)) {
        if (albero.dxVuoto(n))
            trovato=false;
        else {
           prof=prof+1;
	       if(ricercaprof(e, albero.figlioDx(n), albero)==-1)
              trovato=false;
           else {
              prof=prof+ricercaprof(e, albero.figlioDx(n), albero);
           }
        }
     }
     if(trovato)
        return prof;
     else
        return -1;
};

int main() {
     string e;
     BinAlbero<string> albero_01, albero_02, albero_03;
     char risp='y';
     nodoBin<string> *bubu=new (nodoBin<string>);
     nodoBin<string> *sp=new (nodoBin<string>);
     char rispa='y';
     int liv=0;
     int numNodi=0;
     int height;
     cout<<"* * *  Acquisizione di un albero binario di ricerca di stringhe di nomi  * * *"<<endl;
     cout << endl;
     while ((risp=='y')||(risp=='Y')) {
        cout << "Inserisci un nome: ";
        cin >> e;
        inserisci(e, albero_01.binRadice(), albero_01);
        do {
           cout << "Altro nome? (y/n) ";
           cin >> risp;
        } while (!((risp=='y')||(risp=='Y')||(risp=='n')||(risp=='N')));
     }
     cout << "\nStampa Albero 1: \n";
     visitaOutputB(albero_01, albero_01.binRadice(), liv,numNodi);
     cout << "\nStampa Albero: \n";
     stampaBinAlbero(albero_01.binRadice(), albero_01);
     cout << endl << endl << "Visite:" << endl << "preVisita -> T: ";
     preVisita(albero_01.binRadice(), albero_01);
     cout << endl << "postVisita -> T: ";
     postVisita(albero_01.binRadice(), albero_01);
     cout << endl << "inVisita -> T: ";
     inVisita(albero_01.binRadice(), albero_01);
     cout << endl << "Ampiezza -> T: ";
     ampiezzaBin(albero_01.binRadice(), albero_01);
     cout << "\n\nInserisci il nome da ricercare: ";
     cin >> e;
     bubu=ricerca(e, albero_01.binRadice(), albero_01);
     if (bubu!=NULL) {
	    cout << "\nL'elemento " << e << " e' presente alla profondita' " 
             << ricercaprof(e, albero_01.binRadice(), albero_01) << endl;
     cout << albero_01.leggiNodo(bubu) << " <-- questo qui!!" << endl;
     }
     else cout << "\nL'elemento " << e << " non e' presente.\n" << endl;
     //height=altezza(bubu, albero_01);
     cout << "Altezza nodo bubu --> " << height << endl;
     //cout << "\nCalcolo della somma dei nodi che si trovano tra la radice e l'elemento trovato:\n";
     //cout << "(se l'elemento non e' presente il risultato sara' -1)" << endl;
     //cout << "\nRisultato:  ";
     //cout << sommanodi(e, albero_01.binRadice(), albero_01);
     cout << "\n\nL'altezza del nodo e': " << altezza(bubu, albero_01) << endl;
     cout << "\n\nLa profondita' del nodo e': " << profondity(bubu, albero_01) << endl;
     cout<<"\n";
     sp=maxDestro(albero_01, 2);
     cout << albero_01.leggiNodo(sp) << " sara' lui??? " << endl;
     cout << endl;
     system("PAUSE");
     return 0;
}

