#include<stdio.h>
#include<stdlib.h>

void Caricarevettore(int n, int Vettore[]);
void Visualizzarevettore(int n, int Vettore[]);
int MassimaFrequenza(int n, int Vettore[]);
int MinimaFrequenza(int n, int Vettore[]);
int ElementoMinFrequenza(int n,int Vettore[]);
int ElementoMassFrequenza(int n, int Vettore[]);
int main() {
	int m,massfrequenza, minfrequenza, NumMassFre,NumMinFreq;
	massfrequenza=0;
	 NumMassFre=0;
	 NumMinFreq=0;
	minfrequenza=0;
	printf("\nInserire dimensione del vettore: \n");
	scanf("%d", &m);
	int V[m];
	Caricarevettore( m, V);
	Visualizzarevettore( m, V);
	massfrequenza=MassimaFrequenza( m, V);
	minfrequenza=MinimaFrequenza( m, V);
	NumMinFreq=ElementoMinFrequenza( m, V);
	NumMassFre=ElementoMassFrequenza( m, V);
    printf ("\nl'elemento di massima frequenza è %d\n",NumMassFre);
    printf("\nLa sua frequenza è %d\n",massfrequenza);
    printf ("\nl'elemento di minima frequenza è %d\n",NumMinFreq);
    printf("\nLa sua frequenza è %d\n",minfrequenza);
	system("pause");
    return 0;
}

void Caricarevettore(int n, int Vettore[])
{
	int i;
	i = 0;
	while (i < n)
	{
		printf("\n Inserire elemento del vettore in posizione %d:\n",i);
		scanf("%d", &Vettore[i]);
		i++;

	}
}

void Visualizzarevettore(int n, int Vettore[])
{
	int i;
	i=0;
	 printf("\n Elenco elementi nel vettore:\n");
	while (i<n)
	{   
		printf(" %d\t",Vettore[i]);
		i=i+1;
	}

}

int MassimaFrequenza(int n,int Vettore[])
{
	int Maxfrequenza, i, cont, j;
    Maxfrequenza=-1;

    cont=0;
    i=0;
    while(i<n)
    {
    	cont=0;
    	j=0;
    	while(j<n)
    	{
    		if(Vettore[i] == Vettore[j])
    		 cont++;

    	j++;
    	}
    if (Maxfrequenza<cont)
       Maxfrequenza=cont;

     i++;
       }
    return(Maxfrequenza);
    }
int MinimaFrequenza(int n,int Vettore[])
{
	int Minfrequenza, i, cont, j;
    Minfrequenza=1;
    cont=0;
    i=0;
    while(i<n)
    {
    	cont=0;
    	j=0;
    	while(j<n)
    	{
    		if(Vettore[i]==Vettore[j])
    		 cont++;

    	j++;
    	}
    if (Minfrequenza>cont)
    	Minfrequenza=cont;

     i++;
      }
  return(Minfrequenza);
    }

int ElementoMinFrequenza(int n,int Vettore[]){
	int Minfrequenza, i, salvapos, cont, j;
	    Minfrequenza=1;

	    cont=0;
	    i=0;
	    salvapos=0;
	    while(i<n)
	    {
	    	cont=0;
	    	j=0;
	    	while(j<n)
	    	{
	    		if(Vettore[i]==Vettore[j])
	    		 cont++;

	    	j++;
	    	}
	    if (Minfrequenza>=cont)
	       {
	    	Minfrequenza=cont;
	         salvapos=i;
	       }
	     i++;
	      }
	  return(Vettore[salvapos]);
}

int ElementoMassFrequenza(int n, int Vettore[]){
	int Maxfrequenza, i, salvapos, cont, j;
	Maxfrequenza=-1;

	cont=0;
	i=0;
	salvapos=0;
	while(i<n)
	{
		cont=0;
		j=0;
		while(j<n)
		{
			if(Vettore[i]==Vettore[j])
			 cont++;

		j++;
		}
		if (Maxfrequenza<cont)
		   {Maxfrequenza=cont;
			 salvapos=i;
		   }
		 i++;
	   }
	return(Vettore[salvapos]);
}
