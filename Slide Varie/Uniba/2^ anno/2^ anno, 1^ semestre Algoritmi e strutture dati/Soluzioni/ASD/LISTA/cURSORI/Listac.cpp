



#include <iostream>
#include "Listac.h"

Listac::Listac(){crealista();};

Listac::~Listac(){};

void Listac::crealista()
{
	inizio=0;
   inizializzall();
};

void Listac::inizializzall()
{
	int c, g;
   inizioll=1;
   for (c=0; c<100;c++)
   {
   	g=c;
      g++;
      elemento[c].scrivisucc(g);
   };
};

bool Listac::listavuota()
{
	return inizio==0;
};

int Listac::primolista()
{
	pos=inizio;
   return inizio;
};

bool Listac::finelista(int x)
{
	if (elemento[x].leggisucc()==-1)
   	return true;
   else
   	return false;
};

int Listac::successivo(int x)
{
	if (!finelista(x))
   {
   	return pos=elemento[x].leggisucc();
   }
   else
   {
   	cout << "la lista e' al termine! \n";
      return -1;
   };
};

tipoelem Listac::leggi(int x)
{
	return elemento[x].leggivalore();
};

void Listac::scrivi(int x, tipoelem val)
{
	elemento[x].scrivivalore(val);
};

void Listac::inserisci(int x, tipoelem val)
{
   if (inizio==0)
   {
   	inizio=1;
      inizioll=2;
      pos=inizio;
      elemento[inizio].scrivivalore(val);
      elemento[inizio].scrivisucc(-1);
   }
   else
   {
   	int p, temp;
      temp=elemento[x].leggisucc();
      elemento[x].scrivisucc(inizioll);
      elemento[inizioll].scrivivalore(val);
      inizioll=elemento[inizioll].leggisucc();
      p=successivo(x);
      elemento[p].scrivisucc(temp);
   };
};

void Listac::cancella(int x)
{
	int i, c=1;
   int comodo;
   if (x==inizio)
   {
    	inizio=elemento[x].leggisucc();
      elemento[x].scrivisucc(inizioll);
     	inizioll=x;
   }
   else
   {
      comodo=Listac::primolista();
      while (pos!=x)
      {
      	comodo=successivo(comodo);
         c++;
      }
      c--;
      comodo=primolista();
      for (i=1;i<c;i++)
   	{
      	comodo=successivo(comodo);
      }
		elemento[comodo].scrivisucc(elemento[x].leggisucc());
      elemento[x].scrivisucc(inizioll);
      inizioll=x;
   };
};
