#ifndef MAIN_H
#include "main.h"
#endif

#ifndef LISTABI_H
#include "ListaBi.h"
#endif

typedef lbcell<string> *posizione;

void menu() {
     cout << endl;
     cout << "********** MENU' LISTA BIDIREZIONALE A DOPPI PUNTATORI **********";
     cout << endl << endl;
     cout << "1. Inserimento dei valori" << endl;
     cout << "2. Stampa della lista" << endl;
     cout << "3. Epurazione della lista" << endl;
     cout << "4. Ricerca minimo" << endl;
     cout << "5. Ricerca massimo" << endl;
     cout << "6. Ricerca di un elemento (funziona solo con liste ordinate)" << endl;
     cout << "7. Fusione (funziona solo con liste ordinate)" << endl;
     cout << "8. Ordinamento" << endl;
     cout << "9. Quit" << endl;
     cout << endl;
};

void inserimento(ListaBi<string> &l) {
     cout << endl;
     cout << "*** Inseriemento della lista ***" << endl << endl;
     posizione p=l.primoLista();
     string elemento;
     char risp='y';
     int i=0;
     while ((risp=='y')||(risp=='Y')) {
        i++;
        cout << "Inserisci elemento: ";
        cin >> elemento;
        l.insLista(elemento, p);
        p=l.succLista(p);
        do {
            cout << "Altro elemento? (y/n) ";
            cin >> risp;
        } while (!((risp=='y')||(risp=='Y')||(risp=='n')||(risp=='N')));
     }
     cout << "Lista inserita con successo!" << endl;
     cout << "Hai inserito " << i << " elementi!" << endl;
     cout << endl;
};

void stampa(ListaBi<string> l) {
     cout << endl;
     cout << "*** Stampa della lista ***" << endl << endl;
     if (l.listaVuota()) {
        cout << "La lista e' vuota!" << endl;
        return;
     } else {
        posizione p=l.primoLista();
        while (!l.fineLista(p)) {
           cout << l.leggiLista(p) << " ";
           p=l.succLista(p);
        }
        cout << endl;
        cout << "Lista stampata con successo!" << endl << endl;
     }
};

void epurazione(ListaBi<string> &l) {
     cout << endl;
     cout << "*** Epurazione della lista ***" << endl << endl;
     if (l.listaVuota()) {
        cout << "Spiacente, ma la lista da epurare e' vuota!" << endl;
        return;
     } else {
        posizione p=l.primoLista();
        while (!l.fineLista(p)) {
           posizione q=l.succLista(p);
           while (!l.fineLista(q)) {
              if (l.leggiLista(p)==l.leggiLista(q))
                 l.cancLista(q);
              else
                 q=l.succLista(q);
           }
           p=l.succLista(p);
        }
     }
     cout << "Lista epurata con successo!" << endl;
     cout << endl;
};

void minimo(ListaBi<string> l, string &min) {
     cout << endl;
     cout << "*** Ricerca elemento minimo ***" << endl << endl;
     if (l.listaVuota()) {
        cout << "Spiacente, ma la lista e' vuota, non posso cercare il minimo!" << endl;
        return;
     } else {
        posizione p=l.primoLista();
        min=l.leggiLista(p);
        while (!l.fineLista(p)) {
           if (l.leggiLista(p)<min)
              min=l.leggiLista(p);
           else
              p=l.succLista(p);
        }
        cout << "Minimo trovato!" << endl;
     }
};

void massimo(ListaBi<string> l, string &max) {
     cout << endl;
     cout << "*** Ricerca elemento massimo ***" << endl << endl;
     if (l.listaVuota()) {
        cout << "Spiacente, ma la lista e' vuota, non posso cercare il massimo!" << endl;
        return;
     } else {
        posizione p=l.primoLista();
        max=l.leggiLista(p);
        while (!l.fineLista(p)) {
           if (l.leggiLista(p)>max)
              max=l.leggiLista(p);
           else
              p=l.succLista(p);
        }
        cout << "Massimo trovato!" << endl;
     }
};

bool ricercaOrdinata(ListaBi<string> l) {
     cout << endl;
     cout << "*** Ricerca elemento ***" << endl << endl;
     string cercato;
     cout << "Inserisci elemento da cercare: ";
     cin >> cercato;
     if (l.listaVuota()) {
        cout << "Spiacente, la lista e' vuota, non posso cercare nulla!" << endl;
        return false;
     } else {
        bool continua, trovato;
        string el_corrente;
        posizione prec, corrente;
        corrente=l.primoLista();
        prec=corrente;
        continua=true;
        trovato=false;
        while((continua)&&(!l.fineLista(corrente)))
        {
           el_corrente=l.leggiLista(corrente);
           if (cercato <= el_corrente)
              continua=false;
           else
           {
              prec=corrente;
              corrente=l.succLista(corrente);
           }
           if (!l.fineLista(corrente))
              trovato=(cercato==el_corrente);
        }
        return trovato;
     }
};

bool ricerca(ListaBi<string> l) {
     cout << endl;
     cout << "*** Ricerca elemento ***" << endl << endl;
     string cercato;
     cout << "Inserisci elemento da cercare: ";
     cin >> cercato;
     if (l.listaVuota()) {
        cout << "Spiacente, la lista e' vuota, non posso cercare nulla!" << endl;
        return false;
     } else {
        bool trovato;
        posizione p=l.primoLista();
        while (!(l.fineLista(p)||trovato)) {
           if (l.leggiLista(p)==cercato)
              trovato=true;
           else
              p=l.succLista(p);
        }
        return (trovato);
     }
};
           
void fusione(ListaBi<string> &lis1, ListaBi<string> &lis3)
{    
     cout << endl;
     cout << "*** Fusione di due liste ordinate ***" << endl << endl;
     ListaBi<string> lis2;
     inserimento(lis2);
     posizione p1, p2, p3;
     
     p1=lis1.primoLista();
     p2=lis2.primoLista();
     p3=lis3.primoLista();
     if ((lis1.listaVuota())||(lis2.listaVuota()))
     {
        cout << "Una delle due liste e' vuota, non posso fare la fusione!" << endl;
        return;
     }
     while ((!lis1.fineLista(p1))&&(!lis2.fineLista(p2)))
     {
        if (lis1.leggiLista(p1)<lis2.leggiLista(p2))
        {
          lis3.insLista(lis1.leggiLista(p1), p3);
          p1=lis1.succLista(p1);
        }
        else
        {
          lis3.insLista(lis2.leggiLista(p2), p3);
          p2=lis2.succLista(p2);
        }
        p3=lis3.succLista(p3);
     }
     while (!lis1.fineLista(p1))
     {
        lis3.insLista(lis1.leggiLista(p1), p3);
        p1=lis1.succLista(p1);
        p3=lis3.succLista(p3);
     }
     while (!lis2.fineLista(p2))
     {
        lis3.insLista(lis2.leggiLista(p2), p3);
        p2=lis2.succLista(p2);
        p3=lis3.succLista(p3);
     }
     cout << "\nFusione eseguita con successo!" << endl;
}

void ordinamento(ListaBi<string> &lis)
{
     cout << endl;
     cout << "*** Ordinamento della lista ***" << endl << endl;
     posizione p, q, pos_minimo;
     p=lis.primoLista();
     string minimo, temp;
     if (lis.listaVuota())
     {
        cout << "\nLa lista da ordinare e' vuota!" << endl;
        return;
     }
     while (!lis.fineLista(p))
     {
           q=lis.succLista(p);
           minimo=lis.leggiLista(p);
           pos_minimo=p;
           while (!lis.fineLista(q))
           {
                 if (lis.leggiLista(q)<minimo)
                 {
                    minimo=lis.leggiLista(q);
                    pos_minimo=q;
                    q=lis.succLista(q);
                 }
                 else
                    q=lis.succLista(q);
           }
           temp=lis.leggiLista(p);  // temp contiene l'elemento corrente da sostituire 
                                   // se più grande con quello trovato in pos_minimo
           lis.scriviLista(minimo, p);
           lis.scriviLista(temp, pos_minimo);
           p=lis.succLista(p);
     }
     cout << "\nLista ordinata!" << endl;
}

int main() {
    ListaBi<string> lis, fusa;
    int scelta;
    string min, max;
    char risp;
    bool presente;
    do {
       menu();
       do {
          cout << "Scelta: ";
          cin >> scelta;
       } while (!((scelta>0)&&(scelta<10)));
       switch (scelta) {
          case 1:
               inserimento(lis);
               break;
          case 2:
               stampa(lis);
               break;
          case 3:
               epurazione(lis);
               break;
          case 4:
               minimo(lis, min);
               cout << "Elemento minimo: " << min << endl;
               break;
          case 5:
               massimo(lis, max);
               cout << "Elemento massimo: " << max << endl;
               break;
          case 6:
               cout << "La lista e' ordinata? (y/n)" << endl;
               cin >> risp;
               if ((risp=='y')||(risp=='Y'))
                  presente=ricercaOrdinata(lis);
               else
                  presente=ricerca(lis);
               if (presente==true)
                  cout << "Elemento presente nella lista!!" << endl;
               else
                  cout << "Spiacente, elemento assente!" << endl;
               break;
          case 7:
               fusione(lis, fusa);
               stampa(fusa);
               break;
          case 8:
               ordinamento(lis);
               break;
          case 9:
               cout << "Ciao ciao..!!! A presto!!!" << endl;
               break;
       }
       system("pause");
       system("cls");
    } while (scelta!=9);            
    return 0;
}

