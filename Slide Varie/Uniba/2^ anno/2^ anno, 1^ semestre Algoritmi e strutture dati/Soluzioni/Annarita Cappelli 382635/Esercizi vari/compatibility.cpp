#ifndef MAIN_H
#include "main.h"
#endif

#ifndef INSIEMELDIS_H
#include "InsiemeLDis.h"
#endif

#ifndef LISTAPTR_H
#include "ListaPtr.h"
#endif

struct persona {
     string nome;
     InsiemeLDis<string> *preferenze;
};

void menu(int i) {
     cout << "********** COMPATIBILITA' ********** (" << i << " persone inserite)" << endl << endl;
     cout << "1. Inserimento nominativi e preferenze" << endl;
     cout << "2. Stampa nominativi e preferenze" << endl;
     cout << "3. Stampa preferenze dato un nominativo" << endl;
     cout << "4. Trova persona compatibile dato un nominativo" << endl;
     cout << "5. Fine" << endl;
     cout << endl;
};

void inserimento(ListaPtr<persona> &l) {
     persona a;
     string s;
     int num;
     lpcell<persona> *p=l.primoLista();
     cout << "*****Inserimento nominativi e preferenze*****" << endl << endl;
     cout << "Inserisci nome: ";
     cin >> a.nome;
     cout << "Quante preferenze vuoi inserire? ";
     cin >> num;
     a.preferenze=new (InsiemeLDis<string>);
     for (int j=0; j<num; j++) {
        cout << "Inserisci preferenza: ";
        cin >> s;
        a.preferenze->inserisci(s);
     }
     l.insLista(a, p);
     p=l.succLista(p);
     cout << endl;
};

void stampa(ListaPtr<persona> &l) {
     persona a;
     lpcell<persona> *p=l.primoLista();
     cout << "*****Stampa nominativi e preferenze*****" << endl << endl;
     while (!l.fineLista(p)) {
        a=l.leggiLista(p);
        cout << "Nome: " << a.nome << endl;
        cout << "Preferenze=";
        a.preferenze->mostraInsieme();
        cout << endl;
        p=l.succLista(p);
     }
};

lpcell<persona> *ricerca(ListaPtr<persona> l, string s) {
     if (l.listaVuota()) {
        cout << "Spiacente, la lista e' vuota, non posso cercare nulla!" << endl;
        return NULL;
     } else {
        persona a;
        bool trovato=false;
        lpcell<persona> *ret=NULL;
        lpcell<persona> *q=l.primoLista();
        while (!(l.fineLista(q)||trovato)) {
           a=l.leggiLista(q);
           if (a.nome==s) {
              ret=q;
              trovato=true;
           } else
              q=l.succLista(q);
        }
        return (ret);
     }
};

void stampaPreferenze(ListaPtr<persona> &l) {
     cout << "*****Stampa preferenze dato un nominativo*****" << endl << endl;
     if (l.listaVuota()) {
        cout << "Spiacente la lista e' vuota!" << endl;
        return;
     }
     string s;
     lpcell<persona> *pos;
     persona a;
     cout << "Inserisci nome: ";
     cin >> s;
     pos=ricerca(l, s);
     if (pos!=NULL) {
        a=l.leggiLista(pos);
        cout << "Nome: " << a.nome << endl;
        cout << "Preferenze=";
        a.preferenze->mostraInsieme();
     } else
        cout << "Nominativo non trovato!" << endl;
     cout << endl;
};

void compatibility(ListaPtr<persona> &l, string people) {
     lpcell<persona> *pos;
     InsiemeLDis<string> lust;
     lust.creaInsieme();
     pos=ricerca(l,people);
     if (pos!=NULL) {
        if (pos!=NULL) {
           lpcell<persona> *p=l.primoLista();
           persona b, a;
           a=l.leggiLista(pos);
           InsiemeLDis<string> inter, diff;
           while (!l.fineLista(p)) {
              if (p!=pos) {
                 b=l.leggiLista(p);
                 inter.intersezione(*(a.preferenze), *(b.preferenze));
                 diff.differenza(*a.preferenze, *b.preferenze);
                 if (inter.cardinality()>diff.cardinality()) 
                    lust.inserisci(b.nome);
              }
              p=l.succLista(p);
           }
        }
        if (!lust.insiemeVuoto()) {
         cout << "EUREKA!!!!!!" << endl;
         cout << "Ho trovato " << lust.cardinality() << " persone compatibili!!" << endl;
         lust.mostraInsieme();
        } else {
         cout << "Non ho trovato una persona compatibile, mi spiace....." << endl;
         cout << endl;
         cout << "Non e' vero... non mi dispiace bwahahahahah!!!!!" << endl;
         cout << "Resterai single a vita!!! ahahahah!!!" << endl;
      }
     } else
         cout << "Nominativo non trovato!" << endl;
};

int main() {
     ListaPtr<persona> lis;
     string uffa;
     int num, scelta;
     int i=0;
     do {
         menu(i);
         do {
            cout << "Scelta: ";
            cin >> scelta;
         } while (!((scelta>0)&&(scelta<6)));
         switch (scelta) {
                case 1:
                     i++;
                     inserimento(lis);
                     break;
                case 2:
                     stampa(lis);
                     break;
                case 3:
                     stampaPreferenze(lis);
                     break;
                case 4:
                     cout << "*****Trova persona compatibile dato un nominativo*****" << endl << endl;
                     cout << "Inserisci persona per compatibilita': ";
                     cin >> uffa;
                     compatibility(lis, uffa);
                     break;
                case 5:
                     cout << "Grazie per aver utilizzato il sistema!! Bye bye.." << endl;
                     break;
         }
         system("PAUSE");
         system("CLS");
     } while (scelta != 5);
     return 0;
}         
        
