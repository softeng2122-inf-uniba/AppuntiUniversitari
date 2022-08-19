/*8/7/2004
Fornire una realizzazione in C/C++ di un albero n-ario per rappresentare un 
albero genealogico semplificato (solo relazione padre-figli). Per ogni persona, 
si deve memorizzare nome, cognome, data di nascita. 
Realizzare i punti richiesti di seguito : 
- funzioni di inserimento e stampa dell'albero genealogico 
- funzione che calcola l'età di una persona nell'albero genealogico 
- funzione che, date due persone, stabilisce se la prima è antenata della 
seconda, e in caso positivo di quante generazioni (0 = non è antenata) 
Dimostrare il corretto funzionamento delle funzioni mediante opportuno main 
con chiamate alle funzioni realizzate. 
Il main deve minimalmente richiedere l'immissione di 2 strutture, controllare 
che siano ordinate, fonderle e stampare la struttura risultante. 
Si fornisca una realizzazione (C o C++) che dimostri l'utilizzo delle primitive 
delle strutture dati e la correttezza delle implementazioni. 
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

struct data {
       int giorno;
       int mese;
       int anno;
};

struct persona {
       string nome;
       string cognome;
       struct data nascita;
};

typedef nodoN<persona> *nodo;

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
void visitaOutputN(NAlbero<persona> &tree, nodo u, int counter, int &numNodi)
{
 int i;
 numNodi++;
 persona a;
 for(i=0;i<counter-1;i++)
 	cout<<"    ";
 if(counter>0)
 	cout<<"+---";
 a=tree.leggiNodo(u);
 cout << "[" << a.nome << " " << a.cognome << ", " << a.nascita.giorno << "/" 
        << a.nascita.mese << "/" << a.nascita.anno << "]" <<"\n";
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
void costruisciNARIO(NAlbero<persona> &tree, nodo u, int counter)
{
 char again;
 persona val, appoggio, temp;
 NAlbero<persona> appo;
 appo.creaNAlbero();
 if(u==tree.radice())
  	{
    cout<<"\n Livello"<<counter;
	 cout<<"\nInserisci nome della persona corrente: ";
    cin >> val.nome;
    cout << "Inserisci cognome della persona corrente: ";
    cin >> val.cognome;
    cout << "Inserisci giorno nascita della persona corrente: ";
    cin >> val.nascita.giorno;
    cout << "Inserisci mese nascita della persona corrente: ";
    cin >> val.nascita.mese;
    cout << "Inserisci anno nascita della persona corrente: ";
    cin >> val.nascita.anno;
	 tree.scriviNodo(val,u);
    cout<<"\n nodo Radice etichetta:["<<val.nome << " " << val.cognome <<"]";
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
	 cout<<"\nInserisci nome della persona corrente: ";
    cin >> val.nome;
    cout << "Inserisci cognome della persona corrente: ";
    cin >> val.cognome;
    cout << "Inserisci giorno nascita della persona corrente: ";
    cin >> val.nascita.giorno;
    cout << "Inserisci mese nascita della persona corrente: ";
    cin >> val.nascita.mese;
    cout << "Inserisci anno nascita della persona corrente: ";
    cin >> val.nascita.anno;
    appo.insRadice();
	 tree.scriviNodo(val,appo.radice());
    tree.insSottoAlbero(u,u,appo);
	 cout<<"\n nodo["<<val.nome << " " << val.cognome <<"] - figlio del";
	 appoggio=tree.leggiNodo(u);
    cout << " nodo[" << appoggio.nome << " " << appoggio.cognome << "]";
	 costruisciNARIO(tree, tree.primoFiglio(u), counter+1);
    cout<<"\n Livello"<<counter;
    cout<<"\n nodo["<<val.nome << " " << val.cognome <<"] - figlio del";
    appoggio=tree.leggiNodo(u);
    cout<<" nodo["<< appoggio.nome << " " << appoggio.cognome <<"]";
    again='?';
	 cout<<"\n vuoi aggiungere un fratello?"<<"\n\n digita:\n   '2' in caso affermativo,\n"
    <<"   '0' per non aggiungere fratelli: ";
	 while(again!='2' && again!='0')
     	cin>>again;
   }
 while(again=='2')
   {
    cout<<"\n Livello"<<counter;
	 cout<<"\nInserisci nome della persona corrente: ";
    cin >> val.nome;
    cout << "Inserisci cognome della persona corrente: ";
    cin >> val.cognome;
    cout << "Inserisci giorno nascita della persona corrente: ";
    cin >> val.nascita.giorno;
    cout << "Inserisci mese nascita della persona corrente: ";
    cin >> val.nascita.mese;
    cout << "Inserisci anno nascita della persona corrente: ";
    cin >> val.nascita.anno;
    appo.insRadice();
	 tree.scriviNodo(val,appo.radice());
    tree.insSottoAlbero(u,u,appo);
	 cout<<"\n nodo["<<val.nome << " " << val.cognome <<"] - figlio del";
	 appoggio=tree.leggiNodo(u);
    cout<<" nodo["<< appoggio.nome << " " << appoggio.cognome <<"]";
	 costruisciNARIO(tree, tree.primoFiglio(u), counter);
	 cout<<"\n Livello"<<counter;
    cout<<"\n nodo["<<val.nome << " " << val.cognome <<"] - fratello del";
    nodo v=tree.succFratello(tree.primoFiglio(u));
    temp=tree.leggiNodo(v);
    cout<<" nodo["<< temp.nome << " " << temp.cognome <<"]";
    again='?';
	 cout<<"\n vuoi aggiungere un altro fratello?"<<"\n\n digita:\n   '2' in caso affermativo,\n"
    <<"   '0' per non aggiungere altri fratelli: ";
	 while(again!='2' && again!='0')
    cin>>again;
   }
 return;
};

int anni(string et, string et2, nodo n, NAlbero<persona> &t){
     CodaPtr<nodo> q;
     persona pers;
     int age=0;
     bool trovato=false;
     q.inCoda(n);
     while (!q.codaVuota()&&!trovato){
        n=q.leggiCoda();
        pers=t.leggiNodo(n);
        if ((pers.nome==et)&&(pers.cognome==et2)) {
           trovato=true;
           age=2007-pers.nascita.anno;
        }
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
     return age;
};

nodo ricerca(string et, string et2, nodo n, NAlbero<persona> &t){
   CodaPtr<nodo> q;
   q.inCoda(n);
   persona a;
   nodo ret=NULL;
   bool trovato=false;
   while (!q.codaVuota()&&!trovato){
      n=q.leggiCoda();
      a=t.leggiNodo(n);
      if ((a.nome==et)&&(a.cognome==et2)) {
         ret=n;
         trovato=true;
      }
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
   return ret;
};

int profondita(nodo n, nodo p, NAlbero<persona> t) {
     nodo radice=new (nodoN<persona>);
     int profon=0;
     radice=n;
     while (p!=radice) {
        p=t.padre(p);
        profon++;
     }
     return profon;
}
    

int main()
{
 NAlbero<persona> T;
 char repeat='s';
 int 	liv=0,
  		toFind=0,
      numNodi=0;
 string a, b;
 nodo n1=new (nodoN<persona>);
 nodo n2=new (nodoN<persona>);
 int age=0;
 int parent=0;
 persona p1, p2;
 cout<<"\t\t* * * Costruzione dell'albero n-rio * * *\n";
 T.insRadice();
 costruisciNARIO(T,T.radice(),liv);
 cout<< endl << "* * Schema di rappresentazione dell'albero n-rio * *\n\n";
 visitaOutputN(T, T.radice(), liv,numNodi);
 cout << endl;
 cout << "*** Calcolo dell'eta' di una persona ***" << endl << endl;
 cout << "Inserisci nome persona di cui vuoi calcolare l'eta': ";
 cin >> a;
 cout << "Inserisci cognome persona di cui vuoi calcolare l'eta': ";
 cin >> b;
 age=anni(a, b, T.radice(), T);
 cout << a << " " << b << " ha " << age << " anni!" << endl;
 cout << endl;
 cout << "Inserisci nome persona di cui vuoi trovare la parentela: ";
 cin >> a;
 cout << "Inserisci cognome persona di cui vuoi trovare la parentela: ";
 cin >> b;
 n1=ricerca(a, b, T.radice(), T);
 cout << "Inserisci nome persona di cui vuoi trovare la parentela: ";
 cin >> a;
 cout << "Inserisci cognome persona di cui vuoi trovare la parentela: ";
 cin >> b;
 n2=ricerca(a, b, T.radice(), T);
 p1=T.leggiNodo(n1);
 p2=T.leggiNodo(n2);
 parent=profondita(n1, n2, T);
 if (parent>0)
    cout << "[" << p1.nome << " " << p1.cognome << "]" << " e' antenato di " 
         << "[" << p2.nome << " " << p2.cognome << "]" << " di " << parent 
         << " generazioni!" << endl << endl;
 else
    cout << "[" << p1.nome << " " << p1.cognome << "]" << " non e' antenato di " 
         << "[" << p2.nome << " " << p2.cognome << "]" << endl << endl; 
 system("pause");
 return 0;
}
