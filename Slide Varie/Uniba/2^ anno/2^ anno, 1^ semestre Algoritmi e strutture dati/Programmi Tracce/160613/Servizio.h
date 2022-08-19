#ifndef EOSTRINGS_H
#define EOSTRINGS_H

#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"ClasseStringa.h"

using namespace std;

class eo_strings{
    void inserisci(tipoelem s);
    void rimuovi(tipoelem s);
    void rimuovi(char c);
    int freq_pari();
    void visualizza_dispari();

    private:
        liststr pari;
        liststr dispari;
};
#endif // EOSTRINGS_H



