//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//............... REALIZZAZIONE LISTA COLLEGATA CON CURSORI ....................
//..............................................................................



#ifndef LISTA_H
#define LISTA_H
#define N 100		//dimensione del vettore

class Lista
	{
		public:
			typedef bool boolean;
 			typedef int tipoelem;
			typedef int pos;

         struct nodo
         	{
            	pos succ;
               tipoelem elem;
            };
         typedef struct nodo elemento;

 			//operatori
 			void 		crealista();
 			boolean 	listavuota();
 			tipoelem leggilista(pos);
 			void 		scrivilista(tipoelem, pos);
 			pos 		primolista();
 			pos 		ultimolista();
 			boolean 	finelista(pos);
 			pos 		succlista(pos);
 			pos 		predlista(pos);
 			void 		inslista(pos&,tipoelem);
 			void 		canclista(pos);

   		//costruttore e distruttore
   		Lista();
   	  ~Lista();

 		private:
			pos L; //primo elemento lista
			pos listalibera; //primo elemento della lista libera
         elemento spazio[N];


			//operatori di gestione lista libera

         void init_listalibera(); 			//inizializza la lista libera

         void sposta_elemento(pos&,pos&); 	//sposta la componente dalla
         										 	//lista libera alla lista corrente e
         											//viceversa, in ausilio a inslista()
                                          //e a canclista().
	};

#endif
