//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: nico Spadoni
//matr.428389



//..............................................................................
//............ Implementazione dell'algoritmo per la conversione ...............
//.................... da albero n-ario in albero binario ......................
//..............................................................................


#include <stdlib.h>
#include <iostream.h>
#include "alberobin.h"
#include "alberon.h"
#include "alberobin.cpp"
#include "alberon.cpp"
#include "converti_n2bin_servizio_def.cpp"
#include "alberobin_servizio_def.cpp"
#include "alberon_servizio_def.cpp"


int main()
   {
      Alberobin B;
      Alberon T;

      char repeat='s';

      int 	liv=0,
      		toFind=0,
            numNodi=0;

//costruzione e stampa dell'albero n-ario da convertire
      cout<<"\n\n Costruzione dell'albero T.\n";
     	T.insradice();
   	costruisci(T,T.radice(),liv);

      cout<<"\n\n Schema di rappresentazione dell'albero\n\n";
      visitaOutputN(T, T.radice(), liv,numNodi);
      cout<<"\n Numero di nodi: "<<numNodi<<"\n";
      numNodi=0;
      cout<<"\n La profondita' dell'albero T e': "<<depth(T,T.radice());

      wait("\n\n Per procedere alla conversione digita [Y]+[invio]: ");

//inizializzazione albero binario
		B.insbinradice();
      B.scrivinodo(T.legginodo(T.radice()),B.binradice());

//conversione dell'albero n-ario in binario
   	converti(T,B,T.radice(),B.binradice());
      cout<<"\n\n Schema di rappresentazione dell'albero convertito\n\n";
      visitaOutputB(B, B.binradice(), liv,numNodi);
      cout<<"\n Numero di nodi: "<<numNodi<<"\n";

      wait("\n\n Programma terminato\n per uscire digita [Y]+[invio]: ");
   }
