/*Esonero laboratorio del 19 dicembre 2002
Fornendo una realizzazione in C++ della struttura dati di coda di caratteri 
numerici rappresentanti numeri interi lunghi a piacere, si implementino le 
funzioni richieste di seguito: 
-	inserimento nella coda di stringa di caratteri numerici letti da tastiera 
-	creazione della funzione di stampa a video del contenuto della coda 
-	funzione che calcola la coda contenente la somma dei numeri contenuti 
nelle due code passate in input 
Dimostrare il corretto funzionamento delle funzioni mediante opportuno main.
*/

#ifndef MAIN_H
#include "main.h"
#endif

#ifndef CODAPTR_H
#include "CodaPtr.h"
#endif

#ifndef PILAPTR_H
#include "PilaPtr.h"
#endif

void inserimento(CodaPtr<int> *m, string numero)
{                        
   for(int i=0; numero[i]!='\0'; i++)        
       {                                   
        numero[i] = numero[i] - 48;     
        int el=(int)numero[i];
        m->inCoda(el);
       };     
};

void copiaCoda(CodaPtr<int> &q, CodaPtr<int> &s) {
     CodaPtr<int> r;
     while (!q.codaVuota()) {
        s.inCoda(q.leggiCoda());
        r.inCoda(q.leggiCoda());
        q.fuoriCoda();
     }
     while (!r.codaVuota()) {
        q.inCoda(r.leggiCoda());
        r.fuoriCoda();
     }
};

void stampa(CodaPtr<int> &q) {
     CodaPtr<int> appoggio;
     copiaCoda(q, appoggio);
     while (!appoggio.codaVuota()) {
        cout << appoggio.leggiCoda() << " ";
        appoggio.fuoriCoda();
     }
     cout << endl;
};

void copiaPila(CodaPtr<int> &q, PilaPtr<int> &p) {
   CodaPtr<int> appoggio;
   copiaCoda(q, appoggio);
   while (!appoggio.codaVuota()) {
      p.inPila(appoggio.leggiCoda());
      appoggio.fuoriCoda();
   }
};

int lunghezza(string numero) {
     int i;
     for(i=0; numero[i]!='\0'; i++);
     return i--;
};  

void somma(CodaPtr<int> &n1, CodaPtr<int> &n2, CodaPtr<int> &ris, int max) {
     PilaPtr<int> pn1, pn2;
     copiaPila(n1, pn1);
     copiaPila(n2, pn2);
     int riporto=0;
     int risultato[++max];
     for (int j=0; j<max; j++)
        risultato[j]=0;
     int a, b;
     int ind=0;
     while (!pn1.pilaVuota()) {
        a=pn1.leggiPila();
        if (!pn2.pilaVuota()) {
           b=pn2.leggiPila();
           risultato[ind]=a+b+riporto;
           if (risultato[ind]>9) {
              riporto=risultato[ind]/10;
              risultato[ind]=risultato[ind]%10;
           } else 
              riporto=0;
           pn2.fuoriPila();
        } else {
           risultato[ind]=a+riporto;  
           if (risultato[ind]>9) {
              riporto=risultato[ind]/10;
              risultato[ind]=risultato[ind]%10;
           } else 
              riporto=0;
        }
        ind++;
        pn1.fuoriPila();
     }
     while (!pn2.pilaVuota()) {
        risultato[ind]=pn2.leggiPila()+riporto;
        if (risultato[ind]>9) {
              riporto=risultato[ind]/10;
              risultato[ind]=risultato[ind]%10;
           } else 
              riporto=0;
        ind++;
        pn2.fuoriPila();
     }
     if (riporto!=0)
        risultato[ind]=riporto;
     for (int j=max-1; j>=0; j--) {
        ris.inCoda(risultato[j]);
     }
};    
             
int main()
{
   int lung1, lung2, max;
   CodaPtr<int> *n1 = new(CodaPtr<int>),
                *n2 = new(CodaPtr<int>),
                *ris = new(CodaPtr<int>); 
   string numero1, numero2;
   cout<< "digita l'addendo della somma" <<endl;
   cin >> numero1;
   cout<< "digita l'addendo della somma" <<endl;
   cin >> numero2;
   inserimento(n1, numero1);
   inserimento(n2, numero2);
   stampa(*n1);
   stampa(*n2);
   lung1=lunghezza(numero1);
   lung2=lunghezza(numero2);
   if (lung1>lung2)
      max=lung1;
   else max=lung2;
   somma(*n1, *n2, *ris, max);
   stampa(*ris);
   cout << endl << endl;
   system("pause");
   return 0;
} 
