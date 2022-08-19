/*
  Nome: InsiemeBool.h
  Autori: Bux Massimo (424854) & Annese Giuseppe Luca (424802)
  Descrizione: Classe che implementa l'insieme con vettore di booleani
*/

#ifndef INSIEMEBOOL_H
#define INSIEMEBOOL_H
#define MAXLUNG 100

typedef int tipoelem;

class InsiemeBool{
public:
  	InsiemeBool();
	~InsiemeBool();
		
	void creaInsieme();
  	bool insiemeVuoto();
  	bool appartiene(tipoelem);
  	void inserisci(tipoelem);
  	void cancella(tipoelem);
  	InsiemeBool unione(InsiemeBool);
  	InsiemeBool intersezione(InsiemeBool);
  	InsiemeBool differenza(InsiemeBool);
   
private:
  	bool insieme[MAXLUNG];
};

#endif
