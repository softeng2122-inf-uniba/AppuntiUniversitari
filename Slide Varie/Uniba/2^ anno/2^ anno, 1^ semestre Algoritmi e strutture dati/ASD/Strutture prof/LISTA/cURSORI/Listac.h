



#ifndef LISTAC_H
#define LISTAC_H
#include "Nodoc.h"

const int maxlung=100;

class Listac
{
    Nodoc elemento[maxlung];
    int inizio, pos, inizioll; // ll = lista libera

public:
    Listac();
    ~Listac();

    void crealista();
    void inizializzall();
    bool listavuota();
    int primolista();
    bool finelista(int);
    tipoelem leggi(int);
    void scrivi(int, tipoelem);
    void cancella(int);
    void inserisci(int, tipoelem);
    int successivo(int);
};

typedef Listac lista;
typedef Nodoc nodo;

#endif
