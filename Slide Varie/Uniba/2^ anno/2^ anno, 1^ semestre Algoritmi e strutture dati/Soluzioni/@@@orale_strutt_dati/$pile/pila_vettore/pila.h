//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//..................... REALIZZAZIONE PILA CON VETTORE .........................
//..............................................................................



#ifndef PILA_H
#define PILA_H
#define N 100			//dimensione del vettore

class Pila
	{
		public:
			typedef bool boolean;
 			typedef int tipoelem;
			typedef int pos;

//Specifica delle interfacce
			void		creapila();
   		boolean	pilavuota();
      	tipoelem	leggipila();
        	void		fuoripila();
         void		inpila(tipoelem);

//definizione costruttori e distruttori
			Pila();
			Pila& operator = (Pila &);
			Pila& operator ^ (Pila &);
		  ~Pila();

 		private:
      	pos top;
 			tipoelem pila[N];
	};

#endif

