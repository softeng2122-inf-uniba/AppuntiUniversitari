#include <stdlib.h>
#include <iostream.h>
#include "diz_hash.h"
#include "lista.h"
#include "lista.cpp"
#include "diz_hash.cpp"
#include "diz_servizio_def.cpp"


main()
	{
      Diz tabella;
		char ripeti,opzione_menu;
		while(ripeti!='n')
      	{
            ripeti='?';
            opzione_menu='0';
  				cout<<"\n =============================================";
		  		cout<<"\n Gestione Articoli di magazzino con Dizionario";
  				cout<<"\n =============================================";
		  		cout<<"\n\n  MENU'\n";
  				cout<<"\n  1 - Inizializzazione Dizionario.";
		  		cout<<"\n  2 - Interrogazione Dizionario.";
  				cout<<"\n  3 - Cancellazione Articoli dal Dizionario.";
		  		cout<<"\n  4 - Aggiornamento Dizionario.\n";
  				cout<<"\n =============================================";
		  		cout<<"\n\n Digita il numero dell'operazione desiderata: ";
      		cin>>opzione_menu;

		      switch(opzione_menu)
            	{
      			case '1':
		  				cout<<"\n Inizializzazione Dizionario.";
			   		set_diz(tabella);
		  				cout<<"\n Inizializzazione Completata.";
      		      break;

      			case '2':
				  		cout<<"\n\n\n Interrogazione Dizionario.";
						while(ripeti!='n')
				        	{
      				      interroga(tabella);
  								cout<<"\n\n\n Per terminare l'interrogazione digita [n]: ";
		  						cout<<"\n Per effettuarne un'altra digita [y]: ";
		      		      cin>>ripeti;
      		   		}
		      		ripeti='?';
		            break;

      			case '3':
		  				cout<<"\n\n\n Cancellazione Articoli dal Dizionario.";
						while(ripeti!='n')
      				  	{
            				cancellazione(tabella);
				  				cout<<"\n\n\n Per terminare l'operazione digita [n]: ";
  								cout<<"\n Per effettuarne un'altra digita [y]: ";
            				cin>>ripeti;
		         		}
				      ripeti='?';
         			break;

      			case '4':
  						cout<<"\n\n\n Aggiornamento Dizionario.";
						while(ripeti!='n')
		      		  	{
				      		aggiornamento(tabella);
		  						cout<<"\n\n\n Per terminare l'aggiornamento digita [n]: ";
  								cout<<"\n Per effettuarne un altro digita [y]: ";
		            		cin>>ripeti;
      		   		}
            		break;

   	  			default:
  						cout<<"\n\n\n Attenzione, il numero digitato non è valido.";
				      ripeti='?';
                  break;
               }

  				cout<<"\n\n\n Per ritornare al menu' digita [y]: ";
				cout<<"\n Per uscire digita [n]: ";
		      cin>>ripeti;
         }


  		wait("\n\n Programma terminato\n per uscire digita [Y]+[invio]: ");
		return 0;
   }
