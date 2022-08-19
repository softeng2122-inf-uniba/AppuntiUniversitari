#include <stdlib.h>
#include <iostream.h>
#include "pila.h"
#include "pila.cpp"
#include "pila_servizio_def.cpp"


//main
void main()
	{
 		Pila stack1, stack2, stack3;

 		setpila(stack1);
      cout<<"\n\n La pila che hai creato e':\n";
 		printpila(stack1);

      wait("\n\n Programma in StandBy\n per continuare digita [Y]+[invio]: ");

 		stack2=stack1;
      cout<<"\n\n Creata una copia della pila:\n";
 		printpila(stack2);

      wait("\n\n Programma in StandBy\n per continuare digita [Y]+[invio]: ");

 		stack3^stack1;
      cout<<"\n\n Creata una copia della pila invertita:\n";
 		printpila(stack3);

      wait("\n\n Programma terminato\n per uscire digita [Y]+[invio]: ");
 	}