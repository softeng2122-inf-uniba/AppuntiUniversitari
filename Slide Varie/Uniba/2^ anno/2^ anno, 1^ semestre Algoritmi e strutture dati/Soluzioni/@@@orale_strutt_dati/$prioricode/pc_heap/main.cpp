#include <stdlib.h>
#include <iostream.h>
#include "pc_heap.h"
#include "pc_heap.cpp"
#include "pc_heap_servizio_def.cpp"


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