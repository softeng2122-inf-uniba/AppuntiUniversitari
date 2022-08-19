#ifndef _ALBEROBINARIO_H
#define _ALBEROBINARIO_H
#include "./NodoBinario.h"

class AlberoBinario{
    private:
        cellap radice;
    public:
        AlberoBinario();
        ~AlberoBinario();
        void creabinalbero();
        bool binalberovuoto();
        cellap binradice();
        cellap binpadre(cellap);
        cellap figliosx(cellap);
        cellap figliodx(cellap);
        bool sinistrovuoto(cellap);
        bool destrovuoto(cellap);
        void cancsottobinalbero(cellap);
        tipoelem legginodo(cellap);
        void scrivinodo(cellap, tipoelem);
        void insbinradice();
        void insfigliosx(cellap);
        void insfigliodx(cellap);
        void insalbero(cellap);   //OPERATORE CHE EFFETTUA L'INSERIMENTO
                                      //RICORSIVO DEI NODI
        void previsita(cellap);   //OP PER LA VISITA IN PREORDINE
        void postvisita(cellap);  //OP PER LA VISITA IN POSTORDINE
        void invisita(cellap);    //OP PER LA VISITA SIMMENTRICA
        void visita_livello();    //OP PER LA VISITA IN AMPIEZZA(PER LIVELLI)
} ;
#endif // _ALBEROBINARIO_H
