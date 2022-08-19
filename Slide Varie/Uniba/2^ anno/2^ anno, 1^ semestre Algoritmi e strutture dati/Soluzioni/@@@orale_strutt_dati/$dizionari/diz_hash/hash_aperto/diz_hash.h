//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//.................... REALIZZAZIONE DIZIONARIO HASH APERTO ....................
//..............................................................................


#ifndef DIZ_HASH_H
#define DIZ_HASH_H
#include "lista.h"
#include "bucket.h"

//definizione della classe Diz

class Diz
   {
      public:
//definizione dei tipi

            typedef Lista trabocco;
            typedef bool boolean;
            typedef Bucket tipoelem;

//Specifica delle interfacce
            void     crea();
            boolean  appartiene(tipoelem);
            void     inserisci(tipoelem);
            void     cancella(tipochiave);

            tipoelem recupera(tipochiave);
            void aggiorna(tipochiave,attributo);

//costruttori e distruttori
            Diz();
           ~Diz();

      private:
      		//dimensione del vettore (volutamente un numero primo)
            //per garantire la circolarità della ricerca hash
				enum{MAX_LISTE_TRABOCCO=11};

 				trabocco diz[MAX_LISTE_TRABOCCO];

//funzione calcolo hash e funzione di ricerca hash
				int hash(tipochiave);
   };
#endif

