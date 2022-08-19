#include <stdlib.h>
#include <iostream.h>
#include "lista.h"
#include "lista.cpp"
#include "lista_servizio_def.cpp"


int main()
   {
      Lista dati,clone;


      setlista(dati);

      printlista(dati);
      wait("\n\n Programma in stand by\n per continuare digita [Y]+[invio]: ");

      clone=dati;
      cout<<"\n\n La lista clone e': ";
      printlista(dati);
      wait("\n\n Programma in stand by\n per continuare digita [Y]+[invio]: ");

      epuralista(dati);
      cout<<"\n\n Dopo l'epurazione la lista e': ";
      printlista(dati);
      wait("\n\n Programma in stand by\n per continuare digita [Y]+[invio]: ");

      sortlista(dati);
      cout<<"\n\n Dopo l'ordinamento la lista e': ";
      printlista(dati);
      wait("\n\n Programma in stand by\n per continuare digita [Y]+[invio]: ");

      cout<<"\n\n Digita il valore da ricercare: ";
      tipoelem n;
      cin>>n;

		searchlista(dati,n);

      wait("\n\n Programma terminato\n per uscire digita [Y]+[invio]: ");
   }
