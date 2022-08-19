//LACRIOLA GIUSEPPE 425621
//STRUTTURA DATI CODA CON PRIORITA'
#include <iostream>
#include <stdlib.h>

#define maxlung 20

typedef char tipoelem;

class prioricoda
{
   private:
	tipoelem elementi[maxlung];
	int ultimo;

   public:
   void creaprioricoda();
   tipoelem min();
   void inserisci(tipoelem);
   void cancellamin();
};

void prioricoda::creaprioricoda()
{
	ultimo=0;
}

tipoelem prioricoda::min()
{

	if (ultimo==0)
	{
		cout << "errore, coda vuota\n";
   	return ' ';
   }
	else
	{
   	return elementi[1];
   }
}

void prioricoda::inserisci(tipoelem x)
{
   int i, k;
   tipoelem temp;
   if (ultimo==maxlung)
   	cout << "ERRORE\n";
   else
   {
   	ultimo++;
      elementi[ultimo]=x;
      i=ultimo;
      if (i>1)
      	k=i/2;
      while ((i>1) && (elementi[i]<elementi[k]))
      {
      	temp=elementi[i];
         elementi[i]=elementi[k];
         elementi[k]=temp;
         i=k;
         if (i>1)
         	k=i/2;
      }

   }
}

void prioricoda::cancellamin()
{
	int i, k;
   tipoelem temp;
   bool scambio;
   if (ultimo==0)
   {
   	cout << "ERRORE\n";
   }
   else
   {
   	elementi[1]=elementi[ultimo];
      ultimo--;
      i=1;
      scambio=true;
      while (i<=(ultimo/2) && (scambio))
      {
      	k=2*i;
         if (k<ultimo)
         {
         	if (elementi[k]<elementi[k+1])
            	k++;
         }
         if (elementi[k]<elementi[i])
         {
         	temp=elementi[i];
            elementi[i]=elementi[k];
            elementi[k]=temp;
            i=k;
         }
         else
         {
         	scambio=false;
         }
      }

   }

};


void mostramenu()
{
 	cout << "(1) inserisci (2) mostra minimo (3) cancella minimo (9) esci\n";
}

int main()
{
   prioricoda miacoda;
   tipoelem x;
	int sc=0;
   miacoda.creaprioricoda();
   while (sc<9)
   {
   	mostramenu();
    	cin >> sc;
   	switch (sc)
    	{
    		case 1:
      		cout << "che elemento? "; cin >> x; cout << endl;
         	miacoda.inserisci(x);
         	break;
      	case 2:
      		cout << "il minimo e' :" << miacoda.min() << endl;
      		break;
      	case 3:
      		miacoda.cancellamin();
         	break;
    	};
   };
system("pause");
return 0;

}




