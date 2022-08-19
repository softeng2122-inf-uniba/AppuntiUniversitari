/*Leggere da tastiera un vettore di n interi.
Trovare il valore minimo e il valore massimo del vettore.
Stampare a video i valori trovati.*/
#include<stdio.h>
#include<stdlib.h>

void CaricareVettore(int x, int Vet[x]);
int TrovareMassimo(int x, int Vet[x]);
int TrovareMinimo(int x, int Vet[x]);

int main()
{
    int n;
    printf("\n Inserire la dimensione del vettore\n");
    scanf("%d",&n);
    int Vettore[n];
    CaricareVettore(n,Vettore);
    int massimo, minimo;
    massimo=TrovareMassimo(n,Vettore);
    minimo=TrovareMinimo(n,Vettore);
    printf("\n Il numero minimo è: %d\n",minimo);
    printf("\n Il numero massimo è: %d",massimo);
}

void CaricareVettore(int x, int Vet[x])
{
    int i=0;
    while (i<x);
    {
        printf("\n Inserire elemento in posizione %d",i);
        scanf("%d",&Vet[i]);
        i++;
    }
}
int TrovareMassimo(int x, int Vet[x])
{
    int max=0, i=0;
    while(i<x)
    {
        if (Vet[i]>max)
            max=Vet[i];
        i++;
    }
return(max);
}
int TrovareMinimo(int x, int Vet[x])
{
    int min,i=0;
    min=Vet[0];
    while(i<x)
    {
        if(min>Vet[i])
            min=Vet[i];
    }
return(min);
}
