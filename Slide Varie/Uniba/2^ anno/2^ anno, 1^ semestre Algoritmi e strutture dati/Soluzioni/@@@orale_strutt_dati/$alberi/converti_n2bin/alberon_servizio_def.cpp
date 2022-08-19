
/*definizione di funzioni di servizio per:

- Costruire interattivamente l'albero
- visita e stampa dell'albero in preordine
- ricerca di un elemento
- Calcolo della profondità

*/




#include <stdlib.h>
#include <iostream.h>



//definizione delle funzioni di servizio

void visitaOutputN(Alberon &tree, Alberon::nodo u, int counter, int &numNodi)
//previsita con conteggio del numero di nodi
//e stampa del contenuto
	{
      int i;
      numNodi++;

      for(i=0;i<counter-1;i++)
 			cout<<"    ";
  		if(counter>0)
  			cout<<"+---";
      cout<<tree.legginodo(u)<<"\n";

      if(!tree.foglia(u))
			{
            Alberon::nodo v=tree.primofiglio(u);
            counter++;
            while(!tree.ultimofratello(v))
            	{
		            visitaOutputN(tree, v, counter, numNodi);
      				v=tree.succfratello(v);
               }
            visitaOutputN(tree, v, counter, numNodi);
         }

   	return;
   }




Alberon :: nodo search(Alberon &tree, Alberon::nodo u, Alberon::tipoelem e)
//preordine con segnalazione di elemento trovato
	{
      char corrente;
      Alberon::nodo riporto;

      corrente=tree.legginodo(u);
      if(corrente==e)
      	return u;
		else
      	{
		  		if(!tree.foglia(u))
					{
        				Alberon::nodo v=tree.primofiglio(u);
		  	         while(!tree.ultimofratello(v))
   			      	{
	   	   		      riporto=search(tree, v, e);
  								v=tree.succfratello(v);
		        	   	}
                  if(tree.legginodo(riporto)!=e)
	     		     		riporto=search(tree, v, e);
		  	      }
		      return riporto;
	 		}
   }


void costruisci(Alberon &tree, Alberon::nodo u, int counter)
//Crea e popola un albero
	{
      char val, again;
      Alberon appo;
      appo.crealbero();

		if(u==tree.radice())
      	{
            cout<<"\n Livello"<<counter;
				cout<<"\n Inserisci il valore del nodo corrente: ";
      		cin>>val;
		      tree.scrivinodo(val,u);
            cout<<"\n nodo Radice etichetta:["<<tree.legginodo(u)<<"]";
            counter++;
         }

      again='?';
      cout<<"\n vuoi aggiungere un figlio?"
  		    <<"\n\n digita:\n   '1' in caso affermativo,\n"
        	 <<"   '0' per non aggiungere figli: ";
      while(again!='1' && again!='0')
  			cin>>again;

      if(again=='1')
        	{
            cout<<"\n Livello"<<counter;
				cout<<"\n Inserisci il valore del nodo corrente: ";

      		cin>>val;
            appo.insradice();
		      tree.scrivinodo(val,appo.radice());
         	tree.insottoalbero(u,u,appo);

            cout<<"\n nodo["<<val<<"] - figlio del";
            cout<<" nodo["<<tree.legginodo(u)<<"]";

           	costruisci(tree, tree.primofiglio(u), counter+1);

            cout<<"\n Livello"<<counter;
            cout<<"\n nodo["<<val<<"] - figlio del";
            cout<<" nodo["<<tree.legginodo(u)<<"]";
            again='?';
		      cout<<"\n vuoi aggiungere un fratello?"
              	 <<"\n\n digita:\n   '2' in caso affermativo,\n"
            	 <<"   '0' per non aggiungere fratelli: ";
		      while(again!='2' && again!='0')
      	   	cin>>again;
         }

      while(again=='2')
        	{
            cout<<"\n Livello"<<counter;
				cout<<"\n Inserisci il valore del nodo corrente: ";

      		cin>>val;
            appo.insradice();
		      tree.scrivinodo(val,appo.radice());
         	tree.insottoalbero(u,u,appo);

            cout<<"\n nodo["<<val<<"] - figlio del";
            cout<<" nodo["<<tree.legginodo(u)<<"]";

           	costruisci(tree, tree.primofiglio(u), counter);

            cout<<"\n Livello"<<counter;
            cout<<"\n nodo["<<val<<"] - fratello del";
            Alberon::nodo v=tree.succfratello(tree.primofiglio(u));
            cout<<" nodo["<<tree.legginodo(v)<<"]";
            again='?';
		      cout<<"\n vuoi aggiungere un altro fratello?"
              	 <<"\n\n digita:\n   '2' in caso affermativo,\n"
            	 <<"   '0' per non aggiungere altri fratelli: ";
		      while(again!='2' && again!='0')
      	   	cin>>again;
         }
      return;
   }


int depth(Alberon &tree, Alberon::nodo u)
	{
      Alberon::nodo corrente;
      int max,temp;

      if(tree.foglia(u))
      	return 0;
      else
      	{
         	corrente=tree.primofiglio(u);
            max=0;
            while(!tree.ultimofratello(corrente))
            	{
               	temp=depth(tree,corrente);
                  if(max<=temp)
                  	max=temp;
                  corrente=tree.succfratello(corrente);
               }
           	temp=depth(tree,corrente);
            if(max<=temp)
              	max=temp;
           	corrente=tree.succfratello(corrente);
      return max+1;
         }
   }



