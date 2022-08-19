#ifndef MAIN_H
#include "main.h"
#endif

#ifndef LISTAVET_H
#include "ListaVet.h"
#endif

void menu() {
     cout << "********** MENU' **********" << endl;
     cout << endl;
     cout << "1. Acquisizione" << endl;
     cout << "2. Stampa" << endl;
     cout << "3. Epurazione" << endl;
     cout << "4. Fine" << endl;
     cout << endl;
};

void acquisizione(ListaVet<string> &l) {
     posizione p=l.primoLista();
     string elemento;
     int num;
     cout << "*** Acquisizione ***" << endl;
     cout << endl;
     cout << "Quanti elementi vuoi inserire?" << endl;
     cin >> num;
     for (int i=0; i<num; i++) {
        cout << "Inserisci elemento: " << endl;
        cin >> elemento;
        l.insLista(elemento, p);
        p=l.succLista(p);
     }
     cout << "Lista acquisita con successo!" << endl;
     cout << endl;
};

void stampa(ListaVet<string> l) {
     cout << "*** Stampa ***" << endl;
     if (l.listaVuota())
     {
        cout << "Spiacente, ma la lista da stampare e' vuota!" << endl;
        return;
     }
     else
     {
        posizione p=l.primoLista();
        while (!l.fineLista(p)) {
           cout << l.leggiLista(p) << " ";
           p=l.succLista(p);
        }
        cout << endl;
        cout << "Lista stampata con successo!" << endl;
        cout << endl;
     }
};

void epurazione(ListaVet<string> &l) {
     cout << "*** Epurazione ***" << endl;
     posizione p, q;
     if (l.listaVuota())
     {
        cout << "Spiacente, ma la lista da epurare e' vuota!" << endl;
        return;
     }
     p=l.primoLista();
     while (!l.fineLista(p)) {
        q=l.succLista(p);
        while (!l.fineLista(q)) {
           if (l.leggiLista(p)==l.leggiLista(q))
              l.cancLista(q);
           else
              q=l.succLista(q);
        }
        p=l.succLista(p);
     }
     cout << "Lista epurata con successo!" << endl;
     cout << endl;
}

int main() {
     int scelta;
     ListaVet<string> lis;
     do {
        menu();
        do {
           cout << "Scelta: " << endl;
           cin >> scelta;
        } while (!((scelta>0)&&(scelta<5)));
        cout << endl;
        switch (scelta) {
           case 1:
                acquisizione(lis);
                break;
           case 2:
                stampa(lis);
                break;
           case 3:
                epurazione(lis);
                break;
           case 4:
                cout << "Ciao ciao!!!" << endl;
                break;
        }
        system("pause");
        system("cls");
     } while (scelta!=4);
     return 0;
}
