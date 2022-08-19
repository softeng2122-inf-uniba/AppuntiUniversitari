//IMPLEMENTAZIONE DELL'INSIEME TIPO
//LISTA A DOPPI PUNTATORI.
#include <iostream.h>
#include <stdlib.h>
#include "insieme.h"

Insieme::Insieme()
{creainsieme(); return;}

Insieme::~Insieme(){}

void Insieme::creainsieme()
{inizio=0; return;}

bool Insieme::insiemevuoto()
{return (inizio==0);};

bool Insieme::appartiene(tipoelem e)
{ posizione temp;
  bool trovato=false;
  if(!insiemevuoto())
   	{temp=inizio;
  		do{
   	   if (temp->getelem()==e)
      	  {trovato=true; break;}
         temp=temp->getsucc();
      }while((temp!=0));
      }//end-if
   return trovato;};

void Insieme::inserisci(tipoelem e)
{ posizione n= new Nodoptr();
  if(appartiene(e)==false)
    {n->setelem(e);
       if (insiemevuoto()==true)
       	{n->setpred(0);
          n->setsucc(0);
          inizio=n;}
       else
         {n->setsucc(inizio);
          inizio->setpred(n);
          inizio=n;}
    }else cout<<"\n  Elemento presente!\n\n";
 return;
};

void Insieme::cancella(tipoelem e)
{ posizione temp;
  bool trovato=false;

  if (appartiene(e))
	 {temp=inizio;
     while (temp!=0 || trovato==false)
      	{if (temp->getelem()==e)
         	{trovato=true;
             if(temp==inizio)
             	{temp->getsucc()->setpred(0);
                inizio=temp->getsucc();
                delete(temp);}
             else if (temp->getsucc()==0)
             		  {temp->getpred()->setsucc(0);
                     delete temp;}
             else {temp->getpred()->setsucc(temp->getsucc());
                   temp->getsucc()->setpred(temp->getpred());
                   delete temp;}
             break;}
          else temp=temp->getsucc();
         }//end-while
         }//end1°if
    else cout<<"\n  Elemento non presente\n";
return;};

void Insieme::unione(Insieme y) // x unione y = z
{Insieme z;
 posizione temp;
  z.inizio=this->inizio;
  temp=y.inizio;
  while(temp!=0)
  		{if (z.appartiene(temp->getelem())==false)
      		{z.inserisci(temp->getelem());}
       temp=temp->getsucc();}
  z.stampa();
  system("PAUSE");
  return;
};

void Insieme::intersezione(Insieme y)//x intersezione y = z
{ Insieme z;
  posizione temp;

  temp=this->inizio;
  while(temp!=0)
  	{if (y.appartiene(temp->getelem()))
   	  z.inserisci(temp->getelem());
    temp=temp->getsucc();}
  z.stampa();
  system("PAUSE");
};

void Insieme::differenza(Insieme y) //x - y = z
{ Insieme z;
  posizione temp=this->inizio;
  while(temp!=0)
  		{if(y.appartiene(temp->getelem())==false)
      	z.inserisci(temp->getelem());
       temp=temp->getsucc();  }
  z.stampa();
  system("PAUSE");
};

void Insieme::stampa()  //stampa a video dell'insieme
{ posizione temp=this->inizio;
  while(temp!=0)
  	{cout<<"   "<<temp->getelem();
    temp=temp->getsucc();}
  cout<<"\n\n";
  return;
};

//operatore che effettua l'inserimento ciclico degli elementi
void Insieme::inserimento()
{ tipoelem j;
  char r;
  do{
  		cout<<"\n  Inserisci l'elemento...";
      cin>>j;
      inserisci(j);
      cout<<"\n  Ancora? (s/n)...";
      cin>>r;
  }while(r=='s');
};
