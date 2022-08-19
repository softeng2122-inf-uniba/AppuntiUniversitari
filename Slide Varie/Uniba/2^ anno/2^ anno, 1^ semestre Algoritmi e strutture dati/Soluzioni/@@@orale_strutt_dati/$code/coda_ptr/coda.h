//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//..................... REALIZZAZIONE CODA CON PUNTATORI .........................
//..............................................................................



#ifndef CODA_CLASS_H
#define CODA_CLASS_H

class Coda
	{
 		public:
//definizione dei tipi
			typedef bool boolean;
			typedef int tipoelem;
			struct nodo
				{
    				tipoelem elem;
    				struct nodo* succPtr;
            };
			typedef struct nodo *pos;

//Specifica delle interfacce
			void		creaCoda();
   		boolean	codaVuota();
      	tipoelem	leggiCoda();
        	void		fuoriCoda();
         void		inCoda(tipoelem);

//definizione costruttori e distruttori
			Coda();
			Coda& operator = (Coda &);
			Coda& operator ^ (Coda &);
		  ~Coda();

		private:			
			pos testa;	//riferimento cima della coda
			pos fondo;	//riferimento fondo della coda
  	};

#endif
