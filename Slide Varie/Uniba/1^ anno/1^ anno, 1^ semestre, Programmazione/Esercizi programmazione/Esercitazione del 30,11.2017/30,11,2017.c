/*
Leggere da tastiera un vettore di n stringhe.
Calcolare la lunghezza della stringa piu’ piccola tra le stringhe inserite.
Stampare a video la stringa corrispondente.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void CaricareVettore(int x, char Vet[x]);
void CalcolareLunghezzaMinima(int x, char Vet[x]);
int main()
{
    int n;
    printf("\nInserire la dimensione del vettore\n");
    scanf("%d",&n);
    char stringhe[n];
    CaricareVettore(n,stringhe);
    CalcolareLunghezzaMinima(n,stringhe);
}

void CaricareVettore(int x, char Vet[x])
{
    int i=0;
    while (i<x)
    {
        printf("\n Inserire chara in posizione %d",i);
        scanf("%d",Vet[i]);
        i++;
    }

}

void CalcolareLunghezzaMinima(int x, char Vet[x])
{
    int i,lunghezzaminima,solve;
    i=0;
    lunghezzaminima=  strlen(char Vet[i]);
    while(i<x)
    {
        if(lunghezzaminima>strlen(char Vet[i]))
            lunghezzaminima=strlen(char Vet[i]);
        {
            solve=i;
        }
        i++;
    }
    printf("\n La chara più piccola è: %c",Vet[solve]);
}
