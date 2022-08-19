//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//........... REALIZZAZIONE CODA CON PRIORITA' COME ALBERO BINARIO .............
//......................(realizzazione con puntatori)...........................
//..............................................................................



#ifndef PRIORICODA_H
#define PRIORICODA_H


class Prioricoda
	{
		public:
//definizione dei tipi
      	typedef int tipoelem;
			typedef bool boolean;

			struct nodoBin
         	{
					struct nodoBin* sinistro;
               struct nodoBin* padre;
               struct nodoBin* destro;
               tipoelem priority;
          	};

			typedef struct nodoBin *nodo;

//Specifica delle interfacce
            void     creaprioricoda();
            void     inserisci(tipoelem);
            tipoelem min();
            void     cancellamin();


//costruttori e distruttori
		   Prioricoda();
		  ~Prioricoda();


		private:
			nodo P;
         nodo ultimo;
	};
#endif
