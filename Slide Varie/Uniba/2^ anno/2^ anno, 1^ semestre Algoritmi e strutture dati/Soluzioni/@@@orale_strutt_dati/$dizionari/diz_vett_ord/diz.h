//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//............... REALIZZAZIONE DIZIONARIO CON VETTORE ORDINATO ................
//..............................................................................



#ifndef DIZ_H
#define DIZ_H

//definizione della classe Diz

class Diz
   {
      public:
//definizione dei tipi
            typedef bool boolean;
            typedef char* tipochiave;
            typedef int attributo;

            struct bucket
            	{
                  tipochiave key;
               	attributo pezzi;
               };
            typedef struct bucket tipoelem;

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
      		//dimensione del vettore
      		enum{N=10};
            
 				tipoelem diz[N];
            int ultimo;    //cursore di indicizzazione dell'ultimo elemento

//funzione di ricerca binaria
            int ricbin(tipochiave,int,int);
   };
#endif

