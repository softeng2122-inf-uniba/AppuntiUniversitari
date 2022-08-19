#ifndef NODO_H
#define NODO_H
#include<string.h>
#include<string.h>
#include <iostream>
#include<stdio.h>

using namespace std;

typedef string tipoelem;
typedef int tipoelem2;

class Nodo{
    private:
        tipoelem nome,cognome;
        Nodo *prec,*suc;
    public:
        Nodo();
        ~Nodo();
        void setsucc(Nodo*);
        void setprec(Nodo*);
        void setnome(tipoelem);
        void setcognome(tipoelem);
        Nodo* getprec();
        Nodo* getsucc();
        tipoelem getnome();
        tipoelem getcognome();

};
typedef Nodo* elemento;
#endif // NODO_H
