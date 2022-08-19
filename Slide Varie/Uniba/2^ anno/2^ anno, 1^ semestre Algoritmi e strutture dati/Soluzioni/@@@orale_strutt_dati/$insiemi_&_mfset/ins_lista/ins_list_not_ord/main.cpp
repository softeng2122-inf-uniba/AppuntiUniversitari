#include <stdlib.h>
#include <iostream.h>
#include "ins_class.h"
#include "ins_class_def.cpp"
#include "ins_servizio_def.cpp"


main()
	{
      Ins A,B,C,D,E;
      int el[N]={1,2,3,4,5,6,7,8,9,10}; //dominio di riferimento

      cout<<"\n Dominio di riferimento = [1..10]";

      cout<<"\n\n Definizione dell'Insieme A:";
      setIns(A);
      test(A,el);
      cout<<"\n insieme A popolato!";

      cout<<"\n\n Definizione dell'Insieme B:";
      setIns(B);
      test(B,el);
      cout<<"\n insieme B popolato!";
      wait("\n\n Programma in stand by\n per continuare digita [Y]+[invio]: ");

      cout<<"\n\n Calcolo dell'Insieme C=unione(A,B):";
		C.unione(A,B);
      cout<<"\n verifichiamo quali tra gli elementi del dominio"
      	   "\n di riferimento, appartengono a C\n";
      test(C,el);
      wait("\n\n Programma in stand by\n per continuare digita [Y]+[invio]: ");

      cout<<"\n\n Calcolo dell'Insieme D=intersezione(A,B):";
      D.intersezione(A,B);
      cout<<"\n verifichiamo quali tra gli elementi del dominio"
      	   "\n di riferimento, appartengono a D\n";
      test(D,el);
      wait("\n\n Programma in stand by\n per continuare digita [Y]+[invio]: ");

      cout<<"\n\n Calcolo dell'Insieme E=differenza(A,B):";
      E.differenza(A,B);
      cout<<"\n verifichiamo gli elementi che appartengono a E"
      	 	"\n ed eventualmente li cancelliamo\n";
      test_canc(E,el);
      wait("\n\n Programma in stand by\n per continuare digita [Y]+[invio]: ");

      cout<<"\n infine verifichiamo se l'insieme E e' ora vuoto\n";

      if(E.insvuoto())
      	cout<<"\n Come previsto l'insieme E e' vuoto.";
      else
      	cout<<"\n Attenzione, l'insieme non e' vuoto come dovrebbe.";
      wait("\n\n Programma terminato\n per uscire digita [Y]+[invio]: ");

		return 0;
   }
