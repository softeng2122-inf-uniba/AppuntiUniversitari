#ifndef INSIME_H
#define INSIEME_H
#include "Nodo.h"
#include "Messaggi.h"
#include "Amicizia.h"

class Insieme{
    private:
        elemento inizio;
    public:
        Insieme();
        ~Insieme();
        void inserimento();
        void creaRete();
        void aggiungiUtente(tipoelem,tipoelem);
        bool appartiene(tipoelem,tipoelem);
        bool vuota();
        void connetti();
        void sconnetti();
        void posta();
        bool connessi();
        int numAmici();
        int numMessaggi();
};
#endif // INSIME_H
