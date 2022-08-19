#include "AlberoN.h"
#include <iostream.h>
#include <stdlib.h>
#include "CodaN.h"

AlberoN::AlberoN()
{ this->creaalbero();
  return;
  };

AlberoN::~AlberoN(){};

void AlberoN::creaalbero()
{ radice=0; return;};

bool AlberoN::alberovuoto()
{return radice==0;};

void AlberoN::insradice()
{ radice=new NodoN();
  return;};

cellap AlberoN::dairadice()
{return radice;};

cellap AlberoN::primofiglio(cellap u)
{if(u!=0)
	return u->getprimof();
   else return 0;};

cellap AlberoN::padre(cellap u)
{ if(u!=0)
		return u->getpadre();
      else return 0;};

bool AlberoN::foglia(cellap u)
{if (u!=0)
	return (u->getprimof()==0);
};

bool AlberoN::ultimofratello(cellap u)
{ if (u!=0)
		return u->getfratello()==0;
   else return 0;
};

cellap AlberoN::succfratello(cellap u)
{return u->getfratello(); };

void AlberoN::scrivinodo(tipoelem e, cellap u)
{	if (u!=0)
		u->setelem(e);
	return;
};

tipoelem AlberoN::legginodo(cellap u)
{return u->getelem();};

void AlberoN::insprimofiglio(cellap u)
{tipoelem x;

 if (u->getprimof()==0)
	{u->setprimof(new NodoN());
    u->getprimof()->setpadre(u);
    cout<<"\n Inserisci il valore del primo figlio del nodo "<<u->getelem()<<"...";
    cin>>x;
    this->scrivinodo(x, u->getprimof());
    this->inssottoalbero(u->getprimof());
   }
  return;
};

void AlberoN::insaltrofiglio(cellap u)
{ tipoelem x;

	if (u!=0)
		{ cellap temp=u->getprimof();
           while (!this->ultimofratello(temp))  {temp=temp->getfratello();}
           temp->setfratello(new NodoN());
           temp->getfratello()->setpadre(u);
           cout<<"\n Inserisci il valore del figlio di "<<u->getelem()<<"...";
           cin>> x;
           this->scrivinodo(x, temp->getfratello());
           this->inssottoalbero(temp->getfratello());
       }
   return;
};

void AlberoN::inssottoalbero(cellap u)
{char risp;
		cout<<"\n Inserire il primo figlio del nodo "<<u->getelem()<<"? (s-n)...";
      cin>>risp;
      if (risp=='s')
      {
			this->insprimofiglio(u);
        	do{
      		cout<<"\nInserire altro figlio dell nodo "<<u->getelem()<<"? (s-n)...";
      		cin>>risp;
      		if (risp=='s')
					this->insaltrofiglio(u);
      	}while (risp=='s');
      }
  return;
};


void AlberoN::previsita(cellap u)
{ cellap temp;
   if (u==dairadice())
		cout<<"  "<<this->legginodo(u)<<" -->";
   else cout<<"  "<<this->legginodo(u)<<"("<<u->getpadre()->getelem()<<")"<<"-->";
   if (!this->foglia(u))
   {	temp=this->primofiglio(u);
   	while(!this->ultimofratello(temp))
      	{this->previsita(temp);
          temp=succfratello(temp);}
      previsita(temp);
   }
return;
};

void AlberoN::postvisita(cellap u)
{ cellap temp;
   if (!this->foglia(u))
   {	temp=this->primofiglio(u);
   	while(!this->ultimofratello(temp))
      	{this->postvisita(temp);
          temp=succfratello(temp);}
      postvisita(temp);}
   if(u==dairadice())
   		cout<<"  "<<this->legginodo(u)<<"-->";
   else cout<<"  "<<this->legginodo(u)<<"("<<u->getpadre()->getelem()<<")"<<"-->";
return;
};

// calcolo del numero dei nodi dell'albero;
int AlberoN::numero_nodi (cellap n)
{
   if (this->foglia(n)) return 1;
   else {
   		int temp=0;
         cellap c = primofiglio(n);
         while (!ultimofratello(c))
         {temp += numero_nodi(c);
          c = succfratello(c);}
         temp += numero_nodi(c);  // per l'ultimo fratello
         return temp+1;
        }
}

// calcolo della profondità di un nodo n; se n è radice dà l'altezza dell'albero
int AlberoN::profondita(cellap n)
{  cellap n_cor = new NodoN;
   int temp=0;
   int max=0;
   if (!alberovuoto())
   { if (!foglia(n))
   	{n_cor=primofiglio(n);
       while (!ultimofratello(n_cor))
       	{temp=profondita(n_cor) + 1;
        	 if (temp > max) max=temp;
        	 n_cor=succfratello(n_cor);}
       temp=profondita(n_cor) + 1;  // per l'ultimofratello
       if (temp > max) max=temp;      // altrimenti tralasciato
       return max;}
     else return 0;}
   else
     {cout << "Attenzione: albero vuoto!\n";
      return 0;
         }
}

void AlberoN::visita_livello()
{	CodaN q;
   cellap temp;

   q.incoda(dairadice());
   while(!q.codavuota())
   {temp=q.leggicoda();
    if(temp==dairadice())
    	cout<<"  "<<legginodo(temp)<<" -->";
    else cout<<"  "<<legginodo(temp)<<"("<<temp->getpadre()->getelem()<<")"<<" -->";
    q.fuoricoda();
    if (!foglia(temp))
    	{cellap n=primofiglio(temp);
       while(!ultimofratello(n))
        {q.incoda(n);
         n=succfratello(n);}
       q.incoda(n);}
   }
};
