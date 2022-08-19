//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//..................... REALIZZAZIONE PILA CON PUNTATORI .......................
//..............................................................................



#ifndef PILA_CLASS_H
#define PILA_CLASS_H

class Pila
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

//definizione costruttori e distruttori
			Pila();
			Pila& operator = (Pila &);
			Pila& operator ^ (Pila &);
		   ~Pila();                       

//Specifica delle interfacce
			void		creapila();
   		boolean	pilavuota();
      	tipoelem	leggipila();
        	void		fuoripila();
         void		inpila(tipoelem);


		private:			
			pos top;	//riferimento cima della pila
  	};
  	
#endif
