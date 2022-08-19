//Università degli Studi di Bari
//facoltà di Informatica
//sede distaccata di Brindisi


//Esame di Algoritmi e Strutture Dati


//Autore: Nico Spadoni
//matr.428389



//..............................................................................
//................ REALIZZAZIONE INSIEME COME LISTA ORDINATA ...................
//..............................................................................




#include <stdlib.h>
#include <iostream.h>
#include "ins_class.h"




//definizione operatori




void Ins :: creains()
   {
      I=NULL;
		return;
   }




Ins :: boolean Ins :: insvuoto()
   {
      return I==NULL;
   }




Ins :: boolean Ins :: appartiene(tipoelem a)
//poichè la lista è ordinata in taluni casi (come ad esempio quando gli elementi
//dell'insieme sono degli interi) può essere conveniente procedere alla ricerca
//di appartenenza attraverso algoritmi più efficienti come la ricerca binaria
//in generale però si applica la solita ricerca lineare (cone di seguito).
   {
      pos p=I;
      boolean found=0;

    	while(p!=NULL)
      	{
          	if(a==p->elem)
            	return true;
            else
               p=p->succ;
         }
     	return false;
   }








void Ins :: inserisci(tipoelem a)
//l'inserimento deve essere opportunamente controllato per mantenere
//la relazione d'ordine
   {
      pos p=I,
      	 prec=p;

	  	while(p!=NULL && a>=p->elem)
      //scarta tutti gli elementi minori di a e ne traccia la posizione
         {
           	prec=p;
        		p=p->succ;
         }

 		pos newNodo=new nodo;
  		newNodo->elem=a;
  		newNodo->succ=p;

      if(prec==NULL)
      //condizione che si verifica se a è minore del primo elemento
        	I=newNodo;
      else
        	prec->succ=newNodo;
		return;
  }





void Ins :: cancella(tipoelem a)
   {
      pos 	p=I;
		if(!appartiene(a))
         	cout<<"\nElemento non presente\n";
		else
      	{
    			while(p!=NULL)
            //scandisce la lista fino a trovare la posizione dell'elemento
            //da rimuovere, controllando l'eventualità che tale elemento
            //sia il primo della lista (in tal caso occorre aggiornare la I)
      			{
               	if(a==p->elem)
            			{
                     	if(p=I)
                        	{
                  				I=I->succ;
				               	delete p;
                              return;
               				}
            				else
            					{
               					pos temp=I;
                              while(temp->succ!=p)
                              	temp->succ=p->succ;
                              delete p;
                              return;
				               }
         				}
                  else
                  	p=p->succ;
   				}
          }
		return;
    }




void Ins :: unione(Ins &A, Ins &B)
//merge tra liste ordinate
   {
      pos 	p=A.I,
      		q=B.I;

      creains();

      while(p!=NULL && q!=NULL)
         if(p->elem < q->elem)
        		{
           		inserisci(p->elem);
            	p=p->succ;
         	}
         else
	        	{
   	        	inserisci(q->elem);
      	      q=q->succ;
        		}
//al termine di una delle due liste...
         if(p==NULL)
      		while(q!=NULL)
	        		{
   	        		inserisci(q->elem);
      	      	q=q->succ;
         		}
			else
      		while(p!=NULL)
	        		{
   	        		inserisci(p->elem);
      	      	p=p->succ;
         		}
		return;
   }

void Ins :: intersezione(Ins &A, Ins &B)
   {
	   pos p=A.I;
      pos q=B.I;
	   creains();

      while(p!=NULL && q!=NULL)
      //grazie alla relazione d'ordine si può evitare un controllo
      //sulla duplice appartenenza, inoltre non è necessario scandire entrambi
      //gli insiemi per intero, infatti ci si ferma quando una delle
      //due scansioni giunge al termine
        	{
				if(p->elem==q->elem)
            //se i due elementi sono uguali si inserisce uno dei due
            //e si avanza nella scansione su entrambi gli insiemi
            	{
						inserisci(p->elem);
            		p=p->succ;
                  q=q->succ;
            	}
            else
            //altrimenti semplicemente si avanza nella scansione dell'insieme
            //in cui l'elemento puntato è il minore.
            	if(p->elem<q->elem)
            		p=p->succ;
               else
                  q=q->succ;
         }
		return;
   }










void Ins :: differenza(Ins &A, Ins &B)
   {
	   pos p=A.I;
      pos q=B.I;
	   creains();

      while(p!=NULL && q!=NULL)
      //grazie alla relazione d'ordine si può evitare un controllo
      //sulla duplice appartenenza, inoltre non è necessario scandire entrambi
      //gli insiemi per intero, infatti ci si ferma quando una delle
      //due scansioni giunge al termine
        	{
				if(p->elem==q->elem)
            //se i due elementi sono uguali allora
            //si avanza nella scansione su entrambi gli insiemi
            	{
            		p=p->succ;
                  q=q->succ;
            	}
            else
            //altrimenti si avanza nella scansione dell'insieme
            //in cui l'elemento puntato è il minore.
            //ma prima di avanzare sull'insieme A si inserisce l'elem puntato.
            	if(p->elem<q->elem)
               	{
                     inserisci(p->elem);
            			p=p->succ;
                  }
               else
                  q=q->succ;
         }
		return;
   }


//costruttori e distruttori

Ins :: Ins()
//crea ins vuota
   {
      creains();
		return;
   }

Ins :: Ins(Ins &A)
	{
   	pos p=A.I;
		creains();
		while (p!=NULL)
   		{
         	inserisci(p->elem);
        		p=p->succ;
      	}
		return;
	}

Ins & Ins :: operator = (Ins &A)
	{
   	pos p=A.I;
		creains();
		while (p!=NULL)
   		{
         	inserisci(p->elem);
        		p=p->succ;
      	}
		return *this;
   }

Ins :: ~Ins()
	{
   	pos p=I,temp;
		while (p!=NULL)
   		{
         	temp=p->succ;
        		cancella(p->elem);
        		p=temp;
      	}
		return;
	}
