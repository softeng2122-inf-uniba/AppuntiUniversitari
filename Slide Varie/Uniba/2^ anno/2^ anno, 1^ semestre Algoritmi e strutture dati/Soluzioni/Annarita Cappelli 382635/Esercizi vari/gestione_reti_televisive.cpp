/*
Implementare la struttura dati di tipo lista che consente di 
memorizzare 
le reti televisive. Ogni elemento contiene
- il nome della rete (univoco) 
- la frequenza (variabile tra 1 e 100Hz)

Per ogni rete si memorizzi i programmi di un giorno specifico, 
in particolare si memorizzi l'ora e il titolo del programma. 
Creare un programma che permette l'inserimento e la stampa dei 
dati della struttura. Realizzare, inoltre, una funzione che dato 
in ingresso un intervallo di orari stampi i programmi televisi in 
programmazione in tutte le reti, suddiviso per rete, 
visualizzando le reti in ordine di frequenza.
*/

#ifndef MAIN_H
#include "main.h"
#endif

#ifndef LISTABI_H
#include "ListaBi.h"
#endif

struct canale;
typedef lbcell<canale> *posizione;

struct programma {
     string nome;
     int ora;
};

struct canale {
     string nome;
     int frequenza;
     ListaBi<programma> *palinsesto;
};

void inserimento(ListaBi<canale> &l) {
     posizione p=l.primoLista();
     char risp='y';
     canale a;
     int i=0;
     while ((risp=='y')||(risp=='Y')) {
        i++;
        cout << "Inserisci nome canale: ";
        cin >> a.nome;
        cout << "Inserisci frequenza: ";
        cin >> a.frequenza;
        a.palinsesto=new (ListaBi<programma>);
        int num_prog;
        cout << "Quanti programmi vuoi inserire? ";
        cin >> num_prog;
        programma b;
        lbcell<programma> *q=new (lbcell<programma>);
        q=a.palinsesto->primoLista();
        for (int i=0; i<num_prog; i++) {
           cout << "Inserisci nome programma: ";
           cin >> b.nome;
           cout << "Inserisci ora: (0-23) ";
           cin >> b.ora;
           a.palinsesto->insLista(b, q);
           q=a.palinsesto->succLista(q);
        }
        l.insLista(a, p);
        p=l.succLista(p);
       do {
            cout << "Altra rete? (y/n) ";
            cin >> risp;
        } while (!((risp=='y')||(risp=='Y')||(risp=='n')||(risp=='N')));
     }
     cout << endl;
     cout << "Inserimento eseguito!" << endl;
     cout << "Hai inserito " << i << " canali!" << endl;
     cout << endl;
};

void stampa(ListaBi<canale> &l) {
     posizione p=l.primoLista();
     canale appoggio;
     programma happosai;
     lbcell<programma> *q=new (lbcell<programma>);
     if (l.listaVuota()) {
        cout << "Spiacente, ma la lista dei canali da stampare e' vuota!" << endl;
        return;
     }
     while (!l.fineLista(p)) {
        appoggio=l.leggiLista(p);
        cout << "Nome rete: " << appoggio.nome << ";" << " Frequenza: " << appoggio.frequenza << "Hz." << endl; 
        q=appoggio.palinsesto->primoLista();
        while(!appoggio.palinsesto->fineLista(q)) {
           happosai=appoggio.palinsesto->leggiLista(q);
           cout << "Nome programma: " << happosai.nome << ";" << " Ore: " << happosai.ora << endl;
           q=appoggio.palinsesto->succLista(q);
        }
        p=l.succLista(p);
        cout << endl;
     }
     cout << "Stampa eseguita con successo!" << endl;
};

void ordinamento(ListaBi<canale> &lis)
{
     cout << endl;
     posizione p, q, pos_minimo;
     p=lis.primoLista();
     int minimo, temp;
     canale appoggio, appoggio2;
     if (lis.listaVuota())
     {
        cout << "\nLa lista dei canali da ordinare e' vuota!" << endl;
        return;
     }
     while (!lis.fineLista(p))
     {
           q=lis.succLista(p);
           appoggio=lis.leggiLista(p);
           minimo=appoggio.frequenza;
           pos_minimo=p;
           while (!lis.fineLista(q))
           {
                 appoggio2=lis.leggiLista(q);
                 if (appoggio2.frequenza<minimo)
                 {
                    minimo=appoggio2.frequenza;
                    pos_minimo=q;
                 }
                  q=lis.succLista(q);
           }
           appoggio2=lis.leggiLista(pos_minimo);
           lis.scriviLista(appoggio2, p);
           lis.scriviLista(appoggio, pos_minimo);
           p=lis.succLista(p);
     }
     cout << endl;
}

void multiFilter(ListaBi<canale> &l, int orario, int orario2) {
     posizione p=l.primoLista();
     canale appoggio;
     programma aiuto;
     lbcell<programma> *q=new (lbcell<programma>);
     ordinamento(l);
     while (!l.fineLista(p)) {
        appoggio=l.leggiLista(p);
        q=appoggio.palinsesto->primoLista();
        while (!appoggio.palinsesto->fineLista(q)) {
           aiuto=appoggio.palinsesto->leggiLista(q);
           if ((aiuto.ora>=orario)&&(aiuto.ora<=orario2)) {
              cout << "Nome rete: " << appoggio.nome << ";" << " Frequenza: " << appoggio.frequenza << "Hz." << endl;
              cout << "Nome programma: " << aiuto.nome << ";" << " Ore: " << aiuto.ora << endl;
              cout << endl;
           }
           q=appoggio.palinsesto->succLista(q);
        }
        p=l.succLista(p);
     }
     cout << "Stampa palinsesto nell'orario richiesto eseguita con successo!" << endl;
};

bool controllo(int a, int b) {
   if (a<b)
      return true;
   return false;
}; 

int main() {
     ListaBi<canale> lis;
     int uno, due;
     cout << "***** Gestione reti televisive *****" << endl << endl;
     cout << "Inserimento canali: " << endl << endl;
     inserimento(lis);
     cout << "Stampa canali inseriti: " << endl << endl;
     stampa(lis);
     do {
       cout << "Inserisci orario iniziale dell'intervallo (0-23): ";
       cin >> uno;
       cout << "Inserisci orario finale dell'intervallo (0-23): ";
       cin >> due;
     } while (!controllo(uno,due));
     multiFilter(lis, uno, due);
     cout << endl;
     cout << "Grazie mille e arrivederci!" << endl << endl;
     system("pause");
     return 0;
}
     
