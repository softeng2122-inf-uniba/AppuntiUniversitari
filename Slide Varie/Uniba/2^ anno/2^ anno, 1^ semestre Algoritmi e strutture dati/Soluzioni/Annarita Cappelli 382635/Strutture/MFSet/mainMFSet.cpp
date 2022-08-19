#ifndef MAIN_H
#include "main.h"
#endif

#ifndef MFSET_H
#include "mfset.h"
#endif

#ifndef NALBERO_H
#include "nalbero.h"
#endif

typedef anodo<int> *nodo;

void preVisita(nodo u, Nalbero<int> t) {
     cout << t.leggiNodo(u) << " (";
     if (!t.foglia(u)) {
        nodo tmp=t.primoFiglio(u);
        while (!t.ultimoFratello(tmp)) {
           preVisita(tmp, t);
           tmp=t.succFratello(tmp);
        }
        preVisita(tmp, t);
     }
     cout << " ) ";
};

int main() {
    MFSet<int> m;
    Lista<int> l;
    int i;
    for (i=0; i<8; i++)
       l.insLista(i, NULL);
    m.creaMFSet(l);
    m.fondi(1, 2);
    m.fondi(1, 3);
    m.fondi(5, 6);
    m.fondi(6, 3);
    m.fondi(4, 7);
    Nalbero<int> t=m.trova(1);
    preVisita(t.radice(), t);
    cout << endl;
    system("pause");
    return 0;
};
    
    
    
