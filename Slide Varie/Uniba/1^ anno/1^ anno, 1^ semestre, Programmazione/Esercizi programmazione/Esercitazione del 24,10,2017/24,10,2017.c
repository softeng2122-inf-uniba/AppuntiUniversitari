/*Realizzare gli algoritmi delle seguenti operazioni sul tipo di dato vettore:
- Lettura di un elemento del vettore
- Scrittura di un elemento nel vettore
- Inversione di posizione di tutti gli elementi del vettore
- Conteggio del numero di presenze di un elemento in un vettore
- Verifica della presenza di un elemento in un vettore
- Individuazione della prima posizione in cui si trova un elemento del vettore*/
#include<stdio.h>
#include<stdlib.h>

void CaricareVettore(int x, int V[]);
void VisualizzareVettore(int x, int V[]);
void LeggereElementoVettore(int x,int V[],int y);
void ScrivereElementoVettore(int x,int V[],int y,int l);
void InversioneElementiVettore(int x, int V[]);
int ConteggioPresenzeElemento(int x, int V[], int z);
int VerificarePresenzaElemento(int x, int V[], int z);
int IndividuarePrimaPosizioneElemento(int x, int V[], int z);

int main()
{
    int n,m=-1,cont=0,presenza=0,posizione=0, elemento=0;
    printf("\n Inserire la dimensione del vettore \n");
    scanf("%d",&n);
    int Vettore[n];
    CaricareVettore(n,Vettore);
    VisualizzareVettore(n,Vettore);
    do
    {
		printf("\n Inserire la posizione dell'elemento che si vuole scrivere\n");
    	scanf("%d",&m);
	}while((m<n)&&(m>n));
	printf("\n Inserire l'elemento che si vuole scrivere\n");
	scanf("%d",&elemento);
   
    ScrivereElementoVettore(n,Vettore,m,elemento);
    VisualizzareVettore(n,Vettore);
    printf("\n Inserire posizione dell'elemento che si vuole leggere\n");
    scanf("%d",&m);
    LeggereElementoVettore(n,Vettore,m);
    InversioneElementiVettore(n,Vettore);
    VisualizzareVettore(n,Vettore);
    printf("\n Inserire elemento di cui si vuole contare il numero di volte che compare\n");
    scanf("%d",&m);
    cont=ConteggioPresenzeElemento(n,Vettore,m);
    printf("\n L'elemento %d e' presente %d volte\n",m,cont);
    printf("\n Inserire elemento da controllare\n");
    scanf("%d",&m);
    presenza=VerificarePresenzaElemento(n,Vettore,m);
    if(presenza=1)
        printf("\n L'elemento %d si trova nel vettore\n",m);
    else
        Printf("\n L'elemento %d non è stato trovato nel vettore\n",m);
    printf("\n Inserire elemento di cui si vuole conoscere la prima posizione\n");
    scanf("%d",&m);
    posizione=IndividuarePrimaPosizioneElemento(n,Vettore,m);
    printf("\n l'elemento %d si trova in posizione %d",m,posizione);
}
void CaricareVettore(int x, int V[])
{
    int i;
	i = 0;
	while (i < x)
        {
            printf("\n Inserire elemento del vettore in posizione %d:\n",i);
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
            i=i+1;
        }
}
void LeggereElementoVettore(int x,int V[],int y)
{
    printf("\n %d Questo e' l'elemento in posizione %d\n",V[y],y);
}
void ScrivereElementoVettore(int x,int V[],int y,int l)
{
    V[y]=l;
}
void InversioneElementiVettore(int x, int V[])
{
    int i=0,j=x,f=0;
    while(i<j)
        {
            f=V[i];
            V[i]=V[j];
            V[j]=f;
            i++;
            j--;
        }
}
int ConteggioPresenzeElemento(int x, int V[], int z)
{
    int cont=0,i=0,j=0;
    while(i<x)
        {
            while(j<=x)
                {
                    if(V[i]==z)
                        cont++;
                    j++;
                }
            i++;
        }
    return(cont);
}
int VerificarePresenzaElemento(int x, int V[], int z)
{
    int i=0,presenza=0;
    while((i<x)&&(presenza=0))
        {
            if(V[i]==z)
                presenza=1;
            i++;
        }
return(presenza);
}
int IndividuarePrimaPosizioneElemento(int x, int V[], int z)
{
    int i=0,salva=-1,trovato=0;
    while((i<x)&&(salva==-1))
        {
            if(V[i]==z)
                salva=i;

            i++;
        }
  return (salva);
}
