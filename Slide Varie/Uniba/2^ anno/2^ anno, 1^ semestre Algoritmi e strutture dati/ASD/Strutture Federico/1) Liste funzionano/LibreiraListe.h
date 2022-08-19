#ifndef LIBRERIALISTE_H
#define LIBRERIALISTE_H


//DEFINIZIONE DELLA CLASSE LISTA
class Lista {
private:
	posizione inizio,		//puntatore al primo elemento della lista
		ultimo;  		//puntatore all'ultimo elemento della lista
public:
	Lista();      		//costruttore
	~Lista();           //distruttore

	void crealista();
	bool listavuota();
	posizione primolista();
	posizione ultimolista();
	bool finelista(posizione);
	tipoelem leggi(posizione);
	void scrivi(posizione, tipoelem);
	void cancella(posizione);
	void inserisci(posizione, tipoelem);
	posizione succlista(posizione);
	posizione predlista(posizione);
	void stampa();//operatore aggiuntivo x la stampa
	Lista ordinarelista();
	posizione cerca(tipoelem);    //operatore aggiuntivo
											 //per la ricerca di un elemento

};
#endif

