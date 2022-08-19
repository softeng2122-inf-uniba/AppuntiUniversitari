#ifndef LISTASTRINGA_H
#define LISTASTRINGA_H
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"ClasseStringa.h"

using namespace std;

typedef string tipoelem;
class Listastringa{
    private:
        Stringa inizio,ultimo;
    public:
        Listastringa();
        ~Listastringa();
        void crealista();
        bool vuota();
        Stringa primolista();
        Stringa ultimolista();
};
typedef Listastringa liststr;

#endif // LISTASTRINGA_H
