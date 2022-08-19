//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//.................... REALIZZAZIONE DIZIONARIO HASH CHIUSO ....................
//..............................................................................



#ifndef DIZ_HASH_H
#define DIZ_HASH_H
//definizione della classe Diz

class Diz
   {
      public:
//definizione dei tipi
            typedef bool boolean;
            typedef int tipochiave;
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
      		//dimensione del vettore (volutamente un numero primo)
            //per garantire la circolarità della ricerca hash
            //nell'ipotesi che 0 e 1 (chiavi fittizie) non siano ammessi
            //come chiavi appartenenti al dizionario si pone che:
				//LIBERO = 1 per lo stato di posizione libera (mai occupata)
				//CANCELLATO = 0 per lo stato di posizione precedentemente occupata
				enum{MAX_BUCKET=11, LIBERO=1, CANCELLATO=0};

 				tipoelem diz[MAX_BUCKET];

//funzione calcolo hash e funzione di ricerca hash
				int hash(tipochiave);
            int scan(tipochiave,boolean&);
   };
#endif

