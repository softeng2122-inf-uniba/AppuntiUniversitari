/*
Autore: Annarita Cappelli 
Matricola: 382635
Nome file: Dizionario.h
Commento: Classe che implementa un dizionario mediante la rappresentazione 
con uso di liste di trabocco.
*/

#ifndef DIZIONARIO_H
#define DIZIONARIO_H
#define M 20  //grandezza massima del dizionario

#ifndef MAIN_H
#include "main.h"
#endif

#ifndef LISTAPTR_H
#include "ListaPtr.h"
#endif

template <class B, class A>
struct bucket {
       B chiave;
       A attributo;
};

template <class B, class A>
class Dizionario {
      public:
             Dizionario();  // costruttore
             ~Dizionario();  // distruttore
             
             // operatori
             void creaDizionario();
             bool appartiene(B);
             void inserisci(bucket<B, A>);
             void cancella(B);
             bool recupera(B, bucket<B, A> &);
             bool aggiorna(B, bucket<B, A>);
             void stampa();
             
             // operatore aggiuntivo per stampare un dizionario 
             // che ha un attributo strutturato
             ListaPtr<bucket<B, A> > copiaDizionario();
      private:
              int hashWord(string);
              ListaPtr<bucket<B, A> > dizionario[M];
};

template <class B, class A>
Dizionario<B, A>::Dizionario() {
     creaDizionario();
};

template <class B, class A>
Dizionario<B, A>::~Dizionario() {
     lpcell<bucket<B, A> > *p;
     for (int i=0; i<M; i++) {
        p=dizionario[i].primoLista();
        while (!dizionario[i].fineLista(p)) {
           dizionario[i].cancLista(p);
           p=dizionario[i].primoLista();
        }
     }
};

template <class B, class A>
void Dizionario<B, A>::creaDizionario() {
     for (int i=0; i<M; i++)
        dizionario[i].creaLista();
};

template <class B, class A>
bool Dizionario<B, A>::appartiene(B k) {
     int h=hashWord(k);
     bool trovato=false;
     bucket<B, A> a;
     lpcell<bucket<B, A> > *p=dizionario[h].primoLista();
     while (!(dizionario[h].fineLista(p)||trovato)) {
        a=dizionario[h].leggiLista(p);
        if (a.chiave==k)
           trovato=true;
        p=dizionario[h].succLista(p);
     }
     return trovato;
};

template <class B, class A>
void Dizionario<B, A>::inserisci(bucket<B, A> a) {
     int h=hashWord(a.chiave);
     if (!appartiene(a.chiave)) {
        cout << a.chiave << " inserita in posizione " << h << endl;
        dizionario[h].insLista(a, NULL);
     } else
        cout << a.chiave << " presente in posizione " << h << endl;
};

template <class B, class A>
void Dizionario<B, A>::cancella(B k) {
     int h=hashWord(k);
     bool trovato=false;
     bucket<B, A> a;
     lpcell<bucket<B, A> > *p=dizionario[h].primoLista();
     while (!(dizionario[h].fineLista(p)||trovato)) {
        a=dizionario[h].leggiLista(p);
        if (a.chiave==k) {
           dizionario[h].cancLista(p);
           cout << "Parola trovata in posizione " << h << " e cancellata" << endl;
           trovato=true;
        }
        p=dizionario[h].succLista(p);
     }
};

template <class B, class A>
bool Dizionario<B, A>::recupera(B k, bucket<B, A> &a) {
     int h=hashWord(k);
     bool trovato=false;
     lpcell<bucket<B, A> > *p=dizionario[h].primoLista();
     while (!(dizionario[h].fineLista(p)||trovato)) {
        a=dizionario[h].leggiLista(p);
        if (a.chiave==k)
           trovato=true;
        else
           p=dizionario[h].succLista(p);
     }
     return trovato;
};

template <class B, class A>
bool Dizionario<B, A>::aggiorna(B k, bucket<B, A> a) {
     int h=hashWord(k);
     bool trovato=false;
     bucket<B, A> temp;
     lpcell<bucket<B, A> > *p=dizionario[h].primoLista();
     while (!(dizionario[h].fineLista(p)||trovato)) {
        temp=dizionario[h].leggiLista(p);
        if (temp.chiave==k) {
           dizionario[h].scriviLista(a, p);
           trovato=true;
        } else
           dizionario[h].succLista(p);
     }
     return trovato;
};

template <class B, class A>
void Dizionario<B, A>::stampa() {
     for (int i=0; i<M; i++) {
        if (!dizionario[i].listaVuota()) {
           lpcell<bucket<B, A> > *p=dizionario[i].primoLista();
           bucket<B, A> a;
           while (!dizionario[i].fineLista(p)) {
              a=dizionario[i].leggiLista(p);
              cout << "Chiave: " << a.chiave << endl;
              cout << "Attributo: " << a.attributo << endl;
              cout << endl;
              p=dizionario[i].succLista(p);
           }
        }
     }
};

template <class B, class A>
ListaPtr<bucket<B, A> > Dizionario<B, A>::copiaDizionario() {   
    ListaPtr<bucket<B, A> > lis;
    lpcell<bucket<B, A> > *p;
    lpcell<bucket<B, A> > *f;
     bucket<B, A> a;
      for (int i=0; i<M; i++) {
        if (!dizionario[i].listaVuota()) {
           p=dizionario[i].primoLista();           
           f=lis.primoLista();
           while (!dizionario[i].fineLista(p)) {
              a=dizionario[i].leggiLista(p);
              lis.insLista(a, f);
              f=lis.succLista(f);
              p=dizionario[i].succLista(p);
           }
        }
     }
     return (lis);
};

template <class B, class A>
int Dizionario<B, A>::hashWord(string k) {
     unsigned temp=0;
     for(int i=0; k[i]!='\0'; i++)
        temp=((unsigned)k[i])+(31*temp);
     return temp%M;
};

#endif



