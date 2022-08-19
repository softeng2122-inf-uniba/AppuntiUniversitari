//Università degli studi di bari
//facoltà di Informatica
//sede distaccata di brindisi

//Esame di Algoritmi e strutture dati

//Autore: nico spadoni
//matr.428389



//..............................................................................
//................. 	REALIZZAZIONE ALBERO BINARIO SEQUENZIALE ...................
//.................. (orientato alla costruzione top down) .....................
//..............................................................................



#ifndef ALBEROBIN_H
#define ALBEROBIN_H
#define N 100 			//dimensione del vettore

class Alberobin
	{
		public:
			typedef bool boolean;
 			typedef int tipoelem;
 			typedef int nodo;

         struct nucleo
         	{
            	boolean exist;
               tipoelem elem;
            };
         typedef struct nucleo componente;


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
 			componente alberobin[N];
	};

#endif
