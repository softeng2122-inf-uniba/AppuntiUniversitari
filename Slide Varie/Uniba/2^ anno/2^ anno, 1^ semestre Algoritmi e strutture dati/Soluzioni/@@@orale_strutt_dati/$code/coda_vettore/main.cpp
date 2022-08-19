#include <stdlib.h>
#include <iostream.h>
#include "coda.h"
#include "coda.cpp"
#include "coda_servizio_def.cpp"


//main
void main()
	{
 		Coda queue1, queue2, queue3;

 		setcoda(queue1);
 		printcoda(queue1);
      wait("\n\n Programma in StandBy\n per continuare digita [Y]+[invio]: ");

		cout<<"\n\n Questa e' una copia della coda:";
 		queue2=queue1;
 		printcoda(queue2);
      wait("\n\n Programma in StandBy\n per continuare digita [Y]+[invio]: ");

		cout<<"\n\n Questa e' una copia della coda invertita:";
 		queue3^queue1;
 		printcoda(queue3);

      wait("\n\n Programma terminato\n per uscire digita [Y]+[invio]: ");
 	}




