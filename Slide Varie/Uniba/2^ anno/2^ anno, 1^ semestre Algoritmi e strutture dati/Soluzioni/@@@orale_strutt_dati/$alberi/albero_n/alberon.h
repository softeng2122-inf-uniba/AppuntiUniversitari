//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//................... REALIZZAZIONE ALBERO N-ario CON LISTA ....................
//........................... PRIMOFIGLIO/FRATELLO .............................
//..............................................................................



#ifndef ALBERON_H
#define ALBERON_H


class Alberon
	{
		public:
			//definizione dei tipi
			typedef char tipoelem;
			typedef bool boolean;

			struct componente
         	{
               struct componente *padre;
               struct componente *primofiglio;
               struct componente *fratello;
               tipoelem elem;
          	};

			typedef struct componente *nodo;

//Specifica delle interfacce

//operatori

			void 		crealbero();
 			boolean 	alberovuoto();
 			nodo 		radice();
 			nodo 		padre(nodo);
			nodo 		primofiglio(nodo);
			nodo 		succfratello(nodo);
			boolean 	ultimofratello(nodo);
			boolean 	foglia(nodo);
			void 		cancsottoalbero(nodo);
			tipoelem legginodo(nodo);
			void 		scrivinodo(tipoelem,nodo);
			void 		insradice();
			void 		insottoalbero(nodo,nodo,Alberon &);

//costruttori e distruttori
		   Alberon();
		  ~Alberon();

		private:
			nodo T;
	};
#endif
