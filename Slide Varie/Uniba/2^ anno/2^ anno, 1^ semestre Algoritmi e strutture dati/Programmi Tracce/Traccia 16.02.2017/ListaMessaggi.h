#ifndef LISTAMESSAGGI_H
#define LISTAMESSAGGI_H
#include "Messaggi.h"


class ListaMessaggi{
    private:
            messaggio inizio;
    public:
        void crealista();
        ListaMessaggi();
        ~ListaMessaggi();
        void inseriscimessaggio(mess,mess,mess,mess,mess);
        void visualizzamessaggio();
        bool listavuota();
        void inserimento();
};
#endif // LISTAMESSAGGI_H
