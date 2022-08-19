//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//........... REALIZZAZIONE CODA CON PRIORITA' COME LISTA ORDINATA .............
//..............................................................................



#ifndef PC_CLASS_H
#define PC_CLASS_H

//definizione della classe Prioricoda

class Prioricoda
   {
      public:
//definizione dei tipi
            typedef bool boolean;
            typedef int tipoelem;
            struct nodo
               {
                  tipoelem priority;
                  struct nodo* succ;
               };
            typedef struct nodo* pos;

//costruttori e distruttori
            Prioricoda();
           ~Prioricoda();

//Specifica delle interfacce
            void     creaprioricoda();
            void     inserisci(tipoelem);
            tipoelem min();
            void     cancellamin();

      private:
            pos I; //riferimento iniziale
   };
#endif
