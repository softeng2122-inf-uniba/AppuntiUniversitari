#include <stdlib.h>
#include <iostream.h>
#include "prioricoda.h"
#include "prioricoda.cpp"
#include "prioricoda_servizio_def.cpp"


//main
void main()
	{

      tipoelem vettore[N];

      cout<<"\n\n Definizione di un vettore non ordinato.";
      setvettore(vettore);
      printvettore(vettore);

      cout<<"\n\n Ordinamento del vettore per mezzo di una coda con priorita'.";
      wait("\n\n per procedere digita [Y]+[invio]: ");
      pc_sort(vettore);
      printvettore(vettore);

      wait("\n\n Programma terminato\n per uscire digita [Y]+[invio]: ");
 	}