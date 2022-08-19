//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi

//Esame di Algoritmi e Strutture Dati

//Autore: Nico Spadoni
//matr.428389


//..............................................................................
//..................... REALIZZAZIONE CODA CON PUNTATORI .........................
//..............................................................................




#include <stdlib.h>
#include <iostream.h>
#include "coda.h"




//definizione operatori



void Coda :: creaCoda()
	{
 		testa=NULL;
 	}



 	
Coda :: boolean	Coda :: codaVuota()
	{
		return testa==NULL;
 	}




Coda :: tipoelem Coda :: leggiCoda()
	{
		if(testa==NULL)
			return NULL;
		else
  			return testa->elem;
 	}




void Coda :: fuoriCoda()
	{
		Coda :: pos recycle=testa;
		if(testa!=NULL)
  			{
				testa=testa->succPtr;
				delete(recycle);
			}
		else
			cout<<"La Coda e' vuota";
 	}
 	







void Coda :: inCoda(tipoelem a)
	{
		pos newNodo=new nodo;
		newNodo->elem=a;
		newNodo->succPtr=NULL;
		if(testa==NULL)
    			testa=fondo=newNodo;
		else
			{
         	fondo->succPtr=newNodo;
				newNodo->succPtr=NULL;
            fondo=newNodo;
			}
 	}





//costruttori e distruttori





Coda :: Coda()
//crea coda vuota
	{
		creaCoda();
	}




Coda& Coda::operator=(Coda &coda)
//crea una coda copia come overloading dell'assegnamento
	{
		Coda coda_appoggio;
   	tipoelem a;
   	while(!coda.codaVuota())
   		{
      		a=coda.leggiCoda();
      		coda_appoggio.inCoda(a);
      		coda.fuoriCoda();
      	}
   	creaCoda();
   	while(!coda_appoggio.codaVuota())
   		{
      		a=coda_appoggio.leggiCoda();
      		coda.inCoda(a);
	      	inCoda(a);
   	   	coda_appoggio.fuoriCoda();
      	}

		return *this;
}














Coda& Coda::operator ^ (Coda &coda)
	{
		Coda coda_appo1,coda_appo2;
		tipoelem a;
    int 	 num_elem=0,
     		   sentinella,
           i,j;
		creaCoda();
    while (!coda.codaVuota())
		//popola la coda di appoggio e copia gli elementi in una nuova coda
      	{
      		a=coda.leggiCoda();
      		coda_appo1.inCoda(a);
            inCoda(a);
      		coda.fuoriCoda();
            num_elem++;
         }
    while (!codaVuota())
		//ripristina la coda originaria e svuota la nuova coda
      	{
      		a=leggiCoda();
      		coda.inCoda(a);
      		fuoriCoda();
        }
    sentinella=num_elem;
    for(i=0;i<num_elem;i++)
		//scandisce ripetutamente la prima coda di appoggio ed
      //copia sempre l'ultimo dei non estratti per inserirlo
      //nella coda appena creata (cioè l'inversa)
      	{
            sentinella--;
         	for(j=0;j<sentinella;j++)
            //trasferisce dalla prima coda appoggio alla seconda
            //gli elementi che precedono quello cercato
            	{
      				a=coda_appo1.leggiCoda();
      				coda_appo2.inCoda(a);
      				coda_appo1.fuoriCoda();
               }
            //copia l'elemento cercato nell'inversa e poi lo trasferisce
            //nella seconda coda appoggio
  				a=coda_appo1.leggiCoda();
            coda_appo2.inCoda(a);
            inCoda(a);
            coda_appo1.fuoriCoda();

          while(!coda_appo1.codaVuota())
            //trasferisce dalla prima coda appoggio alla seconda
            //gli elementi che seguono quello cercato
      			{
     					a=coda_appo1.leggiCoda();
		     			coda_appo2.inCoda(a);
     					coda_appo1.fuoriCoda();
		         }

				  while(!coda_appo2.codaVuota())
            //ripristina la prima coda appoggio per il prossimo ciclo
      			{
     					a=coda_appo2.leggiCoda();
		     			coda_appo1.inCoda(a);
     					coda_appo2.fuoriCoda();
		         }
         }
		return *this;
    }

Coda :: ~Coda()
//rilascia la memoria impegnata di una coda
	{
		while(testa!=NULL)
			fuoriCoda();
	}
