//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//................ REALIZZAZIONE ALBERO BINARIO CON PUNTATORI ..................
//.................. (orientato alla costruzione top down) .....................
//..............................................................................



#ifndef ALBEROBIN_H
#define ALBEROBIN_H


class Alberobin
	{
		public:
//definizione dei tipi
      	typedef char tipoelem;
			typedef bool boolean;

			struct nodobin
         	{
					struct nodobin *sinistro;
               struct nodobin *padre;
               struct nodobin *destro;
               boolean lato;
               tipoelem elem;
          	};
			typedef struct nodobin *nodo;

//Specifica delle interfacce

//operatori di costruzione top-down
			void 		creabinalbero();
			boolean 	binalberovuoto();
			nodo 		binradice();
			nodo 		binpadre(nodo);
			nodo 		figliosinistro(nodo);
			nodo 		figliodestro(nodo);
			boolean 	sinistrovuoto(nodo);
			boolean	destrovuoto(nodo);
			void 		cancsottobinalbero(nodo);

//operatori di accesso al contenuto dei nodi
			tipoelem legginodo(nodo);
			void 		scrivinodo(tipoelem,nodo);

//operatori di costruzione top-down
			void 		insbinradice();
			void 		insfigliosinistro(nodo);
			void 		insfigliodestro(nodo);

//costruttori e distruttori
		   Alberobin();
		  ~Alberobin();


		private:
			nodo T;
	};
#endif
