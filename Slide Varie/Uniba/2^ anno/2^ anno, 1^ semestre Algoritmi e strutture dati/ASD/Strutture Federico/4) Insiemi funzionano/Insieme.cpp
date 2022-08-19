#include<iostream>
#include <stdlib.h>
#include "./Nodo.h"
#include "./Insieme.h"

using namespace std;

Insieme::Insieme(){
    creainsieme();
    return;
}

Insieme::~Insieme(){

}

void Insieme::creainsieme(){
    inizio=0;
    return;
}

bool Insieme::insiemevuoto(){
    return(inizio==0);
}

posizione Insieme::primolista()
{
    return inizio;
}

bool Insieme::appartiene(tipoelem e){
    posizione temp= new Nodo();
    bool trovato=false;
    if(insiemevuoto()==false) {
            temp=inizio;
            do{
                if(temp->getelem()==e)
                    trovato=true;
                temp=temp->getsucc();
            }while((temp!=0) && (trovato!=false));
    }
    return (trovato);
}

void Insieme::inserisci(tipoelem e){
    posizione n=new Nodo();
    if(insiemevuoto()==true)
        {
            n->setelem(e);
            n->setprec(0);
            n->setsucc(0);
            inizio=n;
        }
    else if(appartiene(e)==false)
            {
                n->setsucc(inizio);
                n->setelem(e);
                inizio->setprec(n);
                inizio=n;
            }
        else
            cout<<"\n Elemento presente!!\n\n";
    return;
}

//operatore che effettua l'inserimento ciclico degli elementi
void Insieme::inserimento()
{
    tipoelem j;
    int r;
    do{
        cout<<"\n  Inserisci l'elemento...";
        cin>>j;
        inserisci(j);
        cout<<"\n  Ancora? (1/2)...";
        cin>>r;
    }while(r==1);
}

void Insieme::cancella(tipoelem e){
    posizione temp;
    bool trovato=false;
    if(appartiene(e))
        {
            temp=inizio;
            while((temp!=0)|| trovato==false)
            {
                if(temp->getelem()==e)
                    {
                        trovato=true;
                        if(temp==inizio)
                            {
                                temp->getsucc()->setprec(0);
                                inizio=temp->getsucc();
                                delete(temp);
                            }
                        else if(temp->getsucc()==0)
                                {
                                    temp->getprec()->setsucc(0);
                                    delete(temp);
                                }
                            else
                                {
                                    temp->getprec()->setsucc(temp->getsucc());
                                    temp->getsucc()->setprec(temp->getprec());
                                    delete(temp);
                                }
                    }
                        else
                            temp=temp->getsucc();
                    }
            }
    else
        cout<<"\n Elemento non presente\n";
    return;
}

void Insieme::unione(Insieme y) // x unione y = z
{
    Insieme z;
    posizione temp;
    z.inizio=this->inizio;
    temp=y.inizio;
    while(temp!=0){
            if (z.appartiene(temp->getelem())==false)
                z.inserisci(temp->getelem());
       temp=temp->getsucc();
    }
  z.stampa();
  return;
}

void Insieme::intersezione(Insieme y)//x intersezione y = z
{
    Insieme z;
    posizione temp;

    temp=this->inizio;
    while(temp!=0){
            if (y.appartiene(temp->getelem()))
                    z.inserisci(temp->getelem());
            temp=temp->getsucc();
    }
    z.stampa();
}

void Insieme::differenza(Insieme y) //x - y = z
{
    Insieme z;
    posizione temp=this->inizio;
    while(temp!=0){
            if(y.appartiene(temp->getelem())==false)
            z.inserisci(temp->getelem());
            temp=temp->getsucc();
    }
  z.stampa();
}

void Insieme::stampa()  //stampa a video dell'insieme
{
    posizione temp=this->primolista();
    cout<<"\n";
    while(temp!=0){
            cout<<"\t"<<temp->getelem();
            temp=temp->getsucc();
    }
    cout<<"\n\n";
    return;
}


