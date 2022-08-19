#ifndef OGGETTO_H
#define OGGETTO_H
#include<string.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef string tipoelem;
class Oggetto{
    private:
        tipoelem nome;
        Oggetto *suc,*prec;
    public:
        Oggetto();
        ~Oggetto();
        void setnome(tipoelem);
        void setsuc(Oggetto*);
        void setprec(Oggetto*);
        tipoelem getnome();
        Oggetto* getsuc();
        Oggetto* getprec();
};
typedef Oggetto* oggetto;
#endif // OGGETTO_H

