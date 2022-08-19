// FedericoListe.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include <iostream>
#include <stdlib.h>
#include "./LibreriaListe.h"
#include "./LibreriaCella.h"

using namespace std;

int main() {
	Lista l;
	posizione temp;
	tipoelem e, mod;
	int risp;
	char r;
	temp = 0;
	do {
		cout << "\n\n\t::: STRUTTURA DATI LISTA :::\n\n";
		cout << "\t 1. Inserimento di elementi in coda\n";
		cout << "\t 2. Modifica di elementi\n";
		cout << "\t 3. Cancellazione di elementi\n";
		cout << "\t 4. Stampa della lista\n";
		cout << "\t 5. Ordinare la lista\n";
		cout << "\t 0. Exit\n";
		cin >> risp;

		switch (risp) {
		case 1:
			do {
				cout << " Inserisci in coda dell'elemento: ";
				cin >> e;
				l.inserisci(0, e);
				cout << " ancora? (s-n)...";
				cin >> r;
			} while (r == 's' || r == 'S');
			break;
		case 2:
			l.stampa();
			cout << "\n\tQuale elemento vuoi modificare?...";
			cin >> mod;
			cout << "\n\tQuale sarà il nuovo elemento?...";
			cin >> e;
			temp = l.cerca(mod);
			if (temp != 0)
				l.scrivi(temp, e);
			else
				cout << "\n  L'elemento da sostituire non esiste!";
			break;
		case 3:
			l.stampa();
			cout << "\n\tQuale elemento vuoi cancellare?...";
			cin >> mod;
			temp = l.cerca(mod);
			if (temp != 0)
				l.cancella(temp);
			else
				cout << "\n  L'elemento da cancellare non esiste!";
			break;

		case 4:
			l.stampa();
			break;
		case 5:
			if (l.listavuota() == false)
				l = l.ordinarelista();
			else
				cout << "\n Lista vuota! Nulla da ordinare";
		};
	} while (risp != 0);

	system("PAUSE");


	return 0;
}
