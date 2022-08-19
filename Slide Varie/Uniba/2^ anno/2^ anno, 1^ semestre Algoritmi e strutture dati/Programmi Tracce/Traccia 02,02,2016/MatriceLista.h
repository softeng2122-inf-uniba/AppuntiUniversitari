#ifndef MATRICELISTA_H
#define MATRICELISTA_H
#include"MatriceNodo.h"


class Lista{
    private:
        campo inizio,ultimo;
    public:
        Lista();
        ~Lista();
        void crea();
        bool vuota();
        void inserisci();
        campo primonodo();
        campo ultimonodo();
        void aggiungi(campo,tipoelem,tipoelem,tipoelem);
        void rimuovi(tipoelem,tipoelem);
        int leggi(tipoelem, tipoelem);
        Lista trapsosta();
        Lista somma(Lista);
        void visualizza();
};
#endif // MATRICELISTA_H
