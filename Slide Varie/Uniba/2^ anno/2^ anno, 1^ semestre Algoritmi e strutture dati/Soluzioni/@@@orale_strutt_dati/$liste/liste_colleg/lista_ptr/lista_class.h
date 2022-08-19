//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//.............. REALIZZAZIONE LISTA COLLEGATA CON PUNTATORI ...................
//..............................................................................



#ifndef LISTA_CLASS_H
#define LISTA_CLASS_H

class Lista
   {
      public:
//definizione dei tipi
            typedef bool boolean;
            typedef int tipoelem;

            struct nodo
               {
                  tipoelem elem;
                  struct nodo* succ;
               };

            typedef struct nodo* pos;



//costruttori e distruttori
            Lista();
	    Lista& operator = (Lista &);
           ~Lista();

//Specifica delle interfacce
            void     crealista();
            boolean  listavuota();
            boolean  finelista(pos);
            pos      primolista();
            pos      ultimolista();
            pos      succlista(pos);
            pos      predlista(pos);
            tipoelem leggilista(pos);
            void     scrivilista(pos,tipoelem);
            void     inslista(pos,tipoelem);
            void     canclista(pos);

      private:
            pos L; //riferimento iniziale
   };
#endif

