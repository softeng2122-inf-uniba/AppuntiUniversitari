/*
Autore: Annarita Cappelli 
Matricola: 382635
Nome file: InsiemeVetBool.h
Commento: Classe che implementa un insieme mediante la rappresentazione 
sequenziale con vettore booleano.
*/

#ifndef INSIEMEVETBOOL_H
#define INSIEMEVETBOOL_H
#define MAXLUNG 100

#ifndef MAIN_H
#include "main.h"
#endif

typedef int tipoelem;

class InsiemeVetBool {
      public:
             InsiemeVetBool();  // costruttore
             ~InsiemeVetBool();  // distruttore
             
             // operatori
             void creaInsieme();
             bool insiemeVuoto();
             bool appartiene(tipoelem);
             void inserisci(tipoelem);
             void cancella(tipoelem);
             InsiemeVetBool unione(InsiemeVetBool);
             InsiemeVetBool intersezione(InsiemeVetBool);
             InsiemeVetBool differenza(InsiemeVetBool);
      private:
              bool insieme[MAXLUNG];
};

InsiemeVetBool::InsiemeVetBool() {
     creaInsieme();
};

InsiemeVetBool::~InsiemeVetBool() {
     for (int i=0; i<MAXLUNG; i++)
        insieme[i]=false;
};

void InsiemeVetBool::creaInsieme() {
     for (int i=0; i<MAXLUNG; i++)
        insieme[i]=false;
};

bool InsiemeVetBool::insiemeVuoto() {
     bool flag=false;
     for (int i=0; ((i<MAXLUNG)&&(!flag)); i++)
        flag=insieme[i];
     return (!flag);
};

bool InsiemeVetBool::appartiene(tipoelem a) {
     return (insieme[a]);
};

void InsiemeVetBool::inserisci(tipoelem a) {
     insieme[a]=true;
};

void InsiemeVetBool::cancella(tipoelem a) {
     insieme[a]=false;
};

InsiemeVetBool InsiemeVetBool::unione(InsiemeVetBool A) {
     InsiemeVetBool C;
     for (int i=0; i<MAXLUNG; i++)
        if ((insieme[i]||A.appartiene(i)))
           C.inserisci(i);
     return C;
};

InsiemeVetBool InsiemeVetBool::intersezione(InsiemeVetBool A) {
     InsiemeVetBool C;
     for (int i=0; i<MAXLUNG; i++)
        if ((insieme[i]&&A.appartiene(i)))
           C.inserisci(i);
     return C;
};

InsiemeVetBool InsiemeVetBool::differenza(InsiemeVetBool A) {
     InsiemeVetBool C;
     for (int i=0; i<MAXLUNG; i++)
        if ((insieme[i]&&(!A.appartiene(i))))
           C.inserisci(i);
     return C;
};

#endif

