//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi


//Esame di Algoritmi e Strutture Dati


//Autore: Nico Spadoni
//matr.428389




//..............................................................................
//............. REALIZZAZIONE INSIEME CON VETTORE CARATTERISTICO ...............
//..............................................................................




#include <stdlib.h>
#include <iostream.h>
#include "ins_class.h"




//definizione degli operatori


void Ins :: creains()
   {
      for(int i=0;i<N;i++)
      	ins[i]=false;
   }



Ins :: boolean Ins :: insvuoto()
   {
      int i=0;
      while(i<N && !ins[i])
      	i++;

      return !ins[i];
   }



Ins :: boolean Ins :: appartiene(tipoelem a)
   {
     	return ins[a];
   }



void Ins :: inserisci(tipoelem a)
   {
   	ins[a]=true;
	}



void Ins :: cancella(tipoelem a)
   {
   	ins[a]=false;
	}




void Ins :: unione(Ins &A, Ins &B)
//questo operatore è realizzato nell'ipotesi che i vettori caratteristici
//di A e B abbiano cardinalità minore o uguale a Ins altrimenti si incorrerebbe
//ad una violazione della memoria, pertanto si rende necessario un controllo sul
//valore di N a carico del programmatore che utilizza la classe.
//un'altra possibilità è quella di definire una costante a livello
//di preprocessore in modo che tutti gli oggetti istanziati abbiano lo stesso
//valore di N (es. #define N 100)
   {
      for(int i=0;i<N;i++)
      	ins[i]=A.ins[i]||B.ins[i];
   }



void Ins :: intersezione(Ins &A, Ins &B)
//anche qui vale il commento sull'unione
   {
      for(int i=0;i<N;i++)
      	ins[i]=A.ins[i]&&B.ins[i];
   }



void Ins :: differenza(Ins &A, Ins &B)
//anche qui vale il commento sull'unione
   {
      for(int i=0;i<N;i++)
      	ins[i]=A.ins[i]&&(!B.ins[i]);
   }



//costruttori e distruttori


Ins :: Ins()
//crea Ins vuota
   {
      creains();
   }



Ins :: ~Ins()
	{}
