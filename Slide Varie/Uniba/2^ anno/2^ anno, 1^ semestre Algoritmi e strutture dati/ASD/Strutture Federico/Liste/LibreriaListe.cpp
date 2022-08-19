#include ".\LibreriaListe.h"
#include <iostream>
#include <stdlib.h>


using namespace std;


Lista::Lista()
{
    this->crealista();
};

Lista::~Lista()
{

};

void Lista::crealista()
{
    inizio=ultimo=0;
    return;
};

bool Lista::listavuota()
{
    return (inizio==0);
};

posizione Lista::primolista()
{
    return inizio;
};

posizione Lista::ultimolista()
{
    return ultimo;
};

bool Lista::finelista(posizione p)
{
    return (p->getsucc()==0);
};

tipoelem Lista::leggi(posizione p)
{
    return p->getelem();
};

posizione Lista::succlista(posizione p)
{
    return p->getsucc();
};

posizione Lista::predlista(posizione p)
{
    return p->getpred();
};

void Lista::scrivi(posizione p, tipoelem e){
    if(p!=0)
        p->setelem(e);
    else
        cout<<"\n\tElemento nullo!\n";
    return;
};

void Lista::cancella(posizione p)
	{posizione temp=new Nodoptr();

   	if (p==this->ultimolista()){      //se è l'ultimo nodo
        if (p->getpred()!=0){
            p->getpred()->setsucc(0);
            ultimo=p->getpred();
        }
        else
            inizio=ultimo=0;
        temp=p;
    }
    else if(p==this->primolista()){  //se è il primo nodo
        p->getsucc()->setpred(0);
        inizio=p->getsucc();
        temp=p;
    } else{                           //altri casi
    	temp=p;
        predlista(p)->setsucc(succlista(p));
        succlista(p)->setpred(predlista(p));
    }
    delete(temp);
    return;
};

void Lista::inserisci(posizione p, tipoelem e)
	{posizione temp=new Nodoptr();

    temp->setelem(e);

    if(this->listavuota())
    { 		//primo inserimento
        temp->setsucc(0);
        temp->setpred(0);
        inizio=ultimo=temp;
    }
    else if (p==this->primolista())
    {  //inserimento in testa
      	 primolista()->setpred(temp);
         temp->setsucc(primolista());
         inizio=temp;
    }
    else if (p==0){ 						//inserimento in coda
        ultimolista()->setsucc(temp);
        temp->setsucc(0);
        temp->setpred(ultimolista());
        ultimo=temp;
    }
    else{                               //casi restanti
        p->getpred()->setsucc(temp);
        temp->setpred(p->getpred());
        temp->setsucc(p);
        p->setpred(temp);}
    return;
};


void Lista::stampa()
{
    posizione temp;
	temp=primolista();
    while(temp!=0){
        cout<<"\t"<<temp->getelem();
        temp=temp->getsucc();
    }
    return;
}

posizione Lista::cerca(tipoelem e){
    posizione temp=this->primolista();
    bool trovato=false;
	do{
        if (temp->getelem()==e)
            trovato=true;
        else
            temp=temp->getsucc();

   }while((temp!=0) && !trovato);

   if (trovato)
   	   return temp;
    else
       return 0;
};

void Lista::ordinarelista()
{
    posizione temp, temp1, temp2;
    temp=this->primolista();
    temp1=this->primolista();
    temp2=new Nodoptr;
    while(temp!=0)
    {
        temp1=temp->getsucc();
        if(temp->getelem()>temp1->getelem())
            {
                temp2->getsucc()=temp1->getsucc();
                temp1->getsucc()=temp->getsucc();
                temp->getsucc()=temp2->getsucc();
                temp2->getpred()=temp1->getpred();
                temp1->getpred()=temp->getpred();
                temp->getpred()=temp2->getpred();
            }
        temp=temp->getsucc();
    }
}




