#include<studente es 05102018.h>
#include <iostream>

using namespace std;

void riempistruttura(studente *Studente)
{

    int scelta=1,i;
    i=0;
    while(scelta==1)
    {
        cout<<"Inserire numero matricola"<<endl;
        cin>>Studente[i].matricola;
        cout<<"Inserire nome studente"<<endl;
        cin>>Studente[i].nome;
        cout<<"Inserire cognome studente"<<endl;
        cin>>Studente[i].cognome;
        cout<<"Inserire età studente"<<endl;
        cin>>Studente[i].eta;
        cout<<"Inserire 1 per continuare e 0 per terminare"<<endl;
        cin>>scelta;
        i++;
        dimensione++;
    }
}

void visualizzastruttura(studente *Studente)
{
    int i=0;
    while(i<dimensione)
    {
        cout<<"Nome studente: "<<Studente[i].nome<<endl;
        cout<<"Cognome studente: "<<Studente[i].cognome<<endl;
        cout<<"Matricola studente: "<<Studente[i].matricola<<endl;
        cout<<"Età studente: "<<Studente[i].eta<<endl;
        cout<<endl<<endl;
    }
}



