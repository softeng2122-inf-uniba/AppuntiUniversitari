#include<stdio.h>
#include<stdlib.h>
/*Si realizzi un algoritmo per poter analizzare una sequenza di numeri.
Letti N numeri interi, calcolare e visualizzare i seguenti risultati:
• quanti sono i numeri positivi, nulli e negativi
• quanti sono i numeri pari e dispari
• se la sequenza dei numeri inseriti è crescente, decrescente oppure né crescente né decrescente.
*/

void CaricareVettore(int x,int V[]);//Funzione per caricare il Vettore
void VisualizzareVettore(int x, int V[]);//funzione per visualizzare il vettore
int CalcolareNumeriPari(int x,int V[]);//Funzione che calcola quanti sono i numeri pari
int CalcolareNumeriDispari(int x, int V[]);//Funzione che calcola quanti sono i numeri dispari
int CalcolareNumeriPositivi(int x, int V[]);//Funzione che calcola quanti sono i numeri positivi
int CalcolareNumeriNegativi(int x,int V[]);//Funzione che calcola quanti sono i numeri negativi
int ControllareSeuquenzaCrescente(int x, int V[]);//Funzione che controlla se il vettore è ordinato in maniera crescente
int ControllareSequenzaDecrescente(int x, int V[]);//Funzione che controlla se il vettore è ordinato in maniera decrescente
int main()
{
    int n=0,numpar=0,numdisp=0,numnull=0,numpos=0,numneg=0;/*n=dimensione del vettore
                                                              numpar=quantità dei numeri pari
                                                              numdisp=quantità dei numeri dispari
                                                              numnull=quantità dei numeri nulli
                                                              numpos=quantità dei numeri positivi
                                                              numneg=quantità dei numeri negativi*/

    int seqcresc=0,seqdecr=0;/*seqcresc=valore che ci indica se il vettore è ordinato in maniera crescente
                               seqdecr=valore che ci indica se il vettore è ordinato in maniera decrescente */
    printf("\n Inserire la dimensione dell'elenco:\n");
    scanf("%d",&n);
    int Vettore[n];
    CaricareVettore(n,Vettore);
    VisualizzareVettore(n,Vettore);
    numpar=CalcolareNumeriPari(n,Vettore);
    printf("\n I numeri pari sono: \n");
    printf("\n %d\n",numpar);
    numdisp=CalcolareNumeriDispari(n,Vettore);
    printf("\n I numeri dispari sono: \n");
    printf("\n %d\n",numdisp);
    numpos=CalcolareNumeriPositivi(n,Vettore);
    printf("\n I numeri positivi sono: \n");
    printf("\n %d\n",numpos);
    numneg=CalcolareNumeriNegativi(n,Vettore);
    printf("\n I numeri negativi sono: \n");
    printf("\n %d\n",numneg);
    seqcresc=ControllareSeuquenzaCrescente(n, Vettore);
    seqdecr=ControllareSequenzaDecrescente(n, Vettore);
    numnull=n-numpos-numneg;
    printf("\n I numeri nullo sono: \n");
    printf("\n %d\n",numnull);
    if(seqcresc==1)
        printf("\n L'elenco e' in ordine crescente \n");
    if(seqdecr==1)
        printf("\n L'elenco e' in ordine decrescente\n");
    if((seqcresc==0)&&(seqdecr==0))
        printf("\n L'elenco è in ordine casuale\n");

}

void CaricareVettore(int x,int V[])
{

	int i;
	i = 0;
	while (i < x)
	{
		printf("\n Inserire elemento del vettore in posizione %d\n",i);
		scanf("%d", &V[i]);
		i++;

	}
}
void VisualizzareVettore(int x, int V[])
{
    int i;
	i=0;
	printf("\n Elenco elementi nel vettore:\n");
	while (i<x)
	{
		printf(" %d\t",V[i]);
		i=i+1;}
}
int CalcolareNumeriPari(int x,int V[])
{
    int i=0,cont=0,z=0;
    while(i<x)
        {
            z=V[i];
            while(z>0)
                {
                    z=z-2;

                }
          if(z==0)
             cont++;

          i++;
        }
 return (cont);
}
int CalcolareNumeriDispari(int x, int V[])
{
    int i=0,cont=0,z=0;
    while(i<x)
        {
            z=V[i];
            while(z>0)
                {
                    z=z-2;

                }
          if(z!=0)
             cont++;

          i++;
        }
 return (cont);
}
int CalcolareNumeriPositivi(int x, int V[])
{
    int i=0,cont=0;
    while(i<x)
            {
                if(V[i]>0)
                    cont++;
             i++;
            }
return(cont);
}
int CalcolareNumeriNegativi(int x,int V[])
{
    int i=0,cont=0;
    while(i<x)
        {
            if(V[i]<0)
                cont++;
         i++;
        }
return(cont);
}

int ControllareSeuquenzaCrescente(int x, int V[])
{
    int i=0,j=1;
    int k=0;
    while((i<x-1) && (j<x) && (k=0))
        {
            if(V[i]<V[j])
                k=1;
         i++;
         j++;
         }
return(k);
}

int ControllareSequenzaDecrescente(int x, int V[])
{
     int i=0,j=1;
     int k=0;
    while((i<x-1)&&(j<x)&&(k=0))
        {
            if(V[i]>V[j])
                k=1;
         i++;
         j++;
         }
return(k);
}

