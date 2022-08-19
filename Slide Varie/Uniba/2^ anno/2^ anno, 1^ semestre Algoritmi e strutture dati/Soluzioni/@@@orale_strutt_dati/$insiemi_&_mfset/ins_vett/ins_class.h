//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//............. REALIZZAZIONE INSIEME CON VETTORE CARATTERISTICO ...............
//..............................................................................



#ifndef INS_CLASS_H
#define INS_CLASS_H
#define N 100			//dimensione del vettore

//definizione della classe Ins

class Ins
   {
      public:
//definizione dei tipi
            typedef bool boolean;
            typedef int tipoelem;

//Specifica delle interfacce
            void     creains();
            boolean  insvuoto();
            boolean  appartiene(tipoelem);
            void     inserisci(tipoelem);
            void     cancella(tipoelem);
            void     unione(Ins &, Ins &);
            void     intersezione(Ins &, Ins &);
            void     differenza(Ins &, Ins &);

//costruttori e distruttori
            Ins(); //richiede come argomanto il valore del membro private N
           ~Ins();

      private:
 				boolean ins[N];
   };
#endif

