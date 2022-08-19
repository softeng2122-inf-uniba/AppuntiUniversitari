//definizione della classe insieme
#ifndef INSIEME_H
#define INSIEME_H
#include "Nodoptr.h"

class Insieme{
	private:
	 posizione inizio;       //punt. alla testa
   public:
   	Insieme();				 //costruttore
      ~Insieme();           //distruttore
      void creainsieme();
      bool insiemevuoto();
      bool appartiene(tipoelem); //verifica appartenenza di un elemento
      void inserisci(tipoelem);
      void cancella(tipoelem);
      void unione(Insieme);      //unione dell'insieme corrente con un altro
      void intersezione(Insieme);//intersez dell'insieme corrente con un altro
      void differenza(Insieme);  //differenza de insieme corrente con un altro
      void stampa();     			//stampa l'insieme
      void inserimento();        //inserimento ciclico di elementi
};
#endif
