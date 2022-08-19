#include<string.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include"Clustering.h"

using namespace std;

int main()
{
    Clustering c;
    string nm;
    int scelta;
    do{
        do{
            cout<<"1.Crea Clustering\n";
            cout<<"2.Inserisci Cluster\n";
            cout<<"3.Inserisci oggetto\n";
            cout<<"4.Visualizza Clustering\n";
            cout<<"5.Visualizzza Cluster\n";
            cout<<"6.Uscita\n";
            cin>>scelta;
        }while(scelta>=7);
        switch(scelta){
            case 1:
                c.crea();
                c.inserimento();
                break;
            case 2:
                c.inserimento();
                break;
            case 3:

                break;
            case 4:
                c.stampa1();
                break;
            case 5:
                cout<<"Inserisci il nome del cluster che vuoi visualizzare\n";
                cin>>nm;
                c.stampaCluster(nm);
        }
    }while(scelta!=6);
    return 0;
}
