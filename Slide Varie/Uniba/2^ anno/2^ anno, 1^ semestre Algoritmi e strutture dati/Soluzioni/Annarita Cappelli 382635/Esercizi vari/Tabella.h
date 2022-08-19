#ifndef TABELLA_H
#define TABELLA_H
#define MAXLUNG 7
#define offset 4

#ifndef MAIN_H
#include "main.h"
#endif

typedef int posizione;

struct turno {
       string id;
       string cognome;
       int inizio;
};

class Tabella {
      public:
             Tabella();  // costruttore
             ~Tabella();  // distruttore
             
             // operatori
             void creaTabella();
             bool tabellaVuota();
             turno leggiTabella(posizione);
             void scriviTabella(string, string, int, posizione);
             void scriviTabella(turno, posizione);
             posizione primoTabella();
             posizione succTabella(posizione);
             posizione predTabella(posizione);
             bool fineTabella(posizione);
             void insTabella(string, string, int, posizione);
             void cancTabella(posizione);
             void caricaTabella();
             void stampaTabella();
             void ruota();
             void incremento(int);
             turno estraiDipendente(posizione);
      private:
              turno tabella[MAXLUNG];
              int lunghezza;
              int alba;
              bool checkTime(int);
};

Tabella::Tabella() {
     creaTabella();
};

Tabella::~Tabella() { };

void Tabella::creaTabella() {
     lunghezza=0;
     alba=0;
};

bool Tabella::tabellaVuota() {
     return (lunghezza==0);
};

turno Tabella::leggiTabella(posizione p) {
     turno a;
     if (!tabellaVuota()) {
        a.id=tabella[p-1].id;
        a.cognome=tabella[p-1].cognome;
        a.inizio=tabella[p-1].inizio;
        return a;
     }
};

void Tabella::scriviTabella(string i, string c, int b, posizione p) {
     if (!tabellaVuota()) {
        tabella[p-1].id=i;
        tabella[p-1].cognome=c;
        tabella[p-1].inizio=b;
     }
};

void Tabella::scriviTabella(turno a, posizione p) {
     if (!tabellaVuota()) {
        tabella[p-1].id=a.id;
        tabella[p-1].cognome=a.cognome;
        tabella[p-1].inizio=a.inizio;
     }
};    

posizione Tabella::primoTabella() {
     return 1;
};

posizione Tabella::succTabella(posizione p) {
     if (!fineTabella(p))
        return (p+1);
};

posizione Tabella::predTabella(posizione p) {
     if (p!=primoTabella())
        return (p-1);
};

bool Tabella::fineTabella(posizione p) {
     return (lunghezza==p-1);
};

void Tabella::insTabella(string j, string c, int b, posizione p) {
     if ((p!=MAXLUNG)&&(checkTime(b))) {
        for (int i=lunghezza; i>=p; i--)
           tabella[i]=tabella[i-1];
        tabella[p-1].id=j;
        tabella[p-1].cognome=c;
        tabella[p-1].inizio=b;
        lunghezza++;
        alba=alba+offset;
     }
};

void Tabella::cancTabella(posizione p) {
     if (!tabellaVuota())
     {
        if ((!fineTabella(p))&&(p<=lunghezza))
        {
           for (int i=p-1; i<(lunghezza-1); i++)
              tabella[i]=tabella[i+1];
           lunghezza--;
           alba=alba-4;
        }
     }
};

void Tabella::caricaTabella() {
     creaTabella();
     posizione p=primoTabella();
     insTabella("001", "Cappelli", 0, p);
     p=succTabella(p);
     insTabella("002", "Marini", 4, p);
     p=succTabella(p);
     insTabella("003", "Liguori", 8, p);
     p=succTabella(p);
     insTabella("004", "Deramo", 12, p);
     p=succTabella(p);
     insTabella("005", "Lorusso", 16, p);
     p=succTabella(p);
     insTabella("006", "Calabrese", 20, p);
};

void Tabella::stampaTabella() {
     posizione p=primoTabella();
     turno a;
     while(!fineTabella(p)) {
        a=leggiTabella(p);
        cout << a.id << "     " << a.cognome << "     " << a.inizio << endl;
        p=succTabella(p);
     }
};

void Tabella::ruota() {
     caricaTabella();
     posizione p=primoTabella();
     turno a;
     while(!fineTabella(p)) {
        a=leggiTabella(p);
        a.inizio=a.inizio+offset;
        if (checkTime(a.inizio)) {
           scriviTabella(a, p);
           p=succTabella(p);
        } else cancTabella(p);
     }
};

bool Tabella::checkTime(int t) {
     if ((t>=0)&&(t<=23))
        return true;
     else
        return false;
};

void Tabella::incremento(int inc) {
     caricaTabella();
     ruota();
     posizione p=primoTabella();
     turno a;
     while(!fineTabella(p)) {
        a=leggiTabella(p);
        a.inizio=a.inizio+inc;
        if (checkTime(a.inizio)) {
           scriviTabella(a, p);
           p=succTabella(p);
        } else cancTabella(p);
     }
};

turno Tabella::estraiDipendente(posizione p) {
      turno a;
      a=leggiTabella(p);
      return a;
};

#endif  
              
