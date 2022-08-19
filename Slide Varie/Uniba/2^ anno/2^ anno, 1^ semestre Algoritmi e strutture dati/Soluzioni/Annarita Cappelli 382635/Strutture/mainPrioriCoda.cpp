#ifndef MAIN_H
#include "main.h"
#endif

#ifndef PRIORICODA_H
#include "PrioriCoda.h"
#endif

#define N 10


void pc_sort(int *vettore) {
     PrioriCoda<int> C;
     int i;
     for(i=0;i<N;i++)
 	    C.inserisci(vettore[i]);
     for(i=0;i<N;i++)
  	 {
	    vettore[i]=C.min();
        C.cancellaMin();
     }
};

void printVettore(int *vettore) {
     int i;
     cout<<"\n Il vettore e': ";
     for(i=0;i<N;i++)
  	 {
	    cout<<"["<<vettore[i]<<"]";
     }
};

void setVettore(int *vettore) {
     int i=0;
     cout<<"\n Inserire di seguito i valori delle componenti del vettore";
     cout<<"\n E' possibile inserire al massimo 10 valori:\n\n";
     while(i<N)
     {
        cout<<"  V["<<i<<"]=";
        cin>>vettore[i];
        i++;
     };
};

int main() {
     int vettore[N];
     cout<<"\n\n Definizione di un vettore non ordinato.";
     setVettore(vettore);
     printVettore(vettore);
     cout<<"\n\n Ordinamento del vettore per mezzo di una coda con priorita'.";
     pc_sort(vettore);
     printVettore(vettore);
     cout<<"\n\n";
     system("PAUSE");
     return 0;
}
