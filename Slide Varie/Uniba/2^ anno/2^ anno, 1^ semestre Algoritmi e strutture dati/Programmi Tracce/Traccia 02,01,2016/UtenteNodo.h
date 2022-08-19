#ifndef UTENTENODO_H
#define UTENTENODO_H
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;
class Utentenodo{
    private:
        string nome,cognome,prodotto;
        int gradimento;
        Utentenodo *prec,*suc;
    public:
        Utentenodo();
        ~Utentenodo();
        void setnome(string);
        void setcognome(string);
        void setprodotto(string);
        void setgradimento(int);
        void setsuc(Utentenodo*);
        void setprec(Utentenodo*);
        string getnome();
        string getcognome();
        string getprodotto();
        int getgradimento();
        Utentenodo* getsuc();
        Utentenodo* getprec();


};
typedef Utentenodo nodo;
#endif // UTENTENODO_H
