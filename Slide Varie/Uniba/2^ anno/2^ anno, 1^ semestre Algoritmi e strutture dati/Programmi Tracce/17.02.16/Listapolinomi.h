#ifndef Listapolinomi_H
#define Listapolinomi_H
#include "Nodo.h"

class Lista{
    private:
        polinomio inizio,ultimo;
    public:
        Lista();
        ~Lista();
        void inserisci();
        void crea();
        void settaEsponente(tipoelem, tipoelem);
        void rimuoviEsponente(tipoelem);
        tipoelem leggiCoefficiente(tipoelem);
        tipoelem grado();
        Lista somma(Lista);
        Lista prodotto(Lista);
        polinomio successivo(polinomio);
        polinomio precedente(polinomio);
        tipoelem leggiEsponente(polinomio);
        polinomio primopolinomio();
        polinomio ultimopolinomio();
        void normalizza();
        void stampa();
        void inserimento(polinomio, tipoelem, tipoelem);
        bool listavuota();

};
#endif // Listapolinomi_H
