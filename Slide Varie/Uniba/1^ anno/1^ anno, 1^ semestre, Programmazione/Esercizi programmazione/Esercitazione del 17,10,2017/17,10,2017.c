/*
Leggere in input un elenco E di numeri interi compresi tra 18 e 90, estremi inclusi, contenente almeno 10 elementi.
Calcolare il valore di E piu’ presente e quello meno presente in E.
Visualizzare i risultati ottenuti.
*/
#include<stdio.h>
#include<stdlib.h>

void CaricareElenco(int x, int Ele[x]);
int TrovareValorePiuPresente(int x, int Ele[x]);
int TrovareValoreMenoPresente(int x, int Ele[x]);
int main()
{
    int n;
    do
    {
        printf("\nInserire dimensione elenco >=10\n");
        scanf("%d",&n);
    }
    while(n<10);
    int Elenco[n];
    CaricareElenco(n,Elenco);
    int ValorePiuPresente=0 , ValoreMenoPresente=0;
    ValorePiuPresente=TrovareValorePiuPresente(n,Elenco);
    ValoreMenoPresente=TrovareValoreMenoPresente(n,Elenco);
    printf("\nIl valore più presente è: %d",ValorePiuPresente);
    printf("\nIl valore meno presente è: %d",ValoreMenoPresente);
    system("pause");
    return(0);
}
void CaricareElenco(int x, int Ele[x])
{
    int i=0;
    while(i<x)
    {
        printf("\n Inserire elemento in posizione %d \n",i);
        scanf("%d",&Ele [i]);
        i++;
        
    }
}
int TrovareValorePiuPresente(int x, int Ele[x])
{
    int i,j,presenza,massimapresenza,solve;
    i=0;
    massimapresenza=0;
    while(i<x)
    {
        j=0;
        while(j<x)
        {
            if(Ele[i]==Ele[j])
                presenza++;
            j++;
        }
        if(presenza>massimapresenza)
            {
                massimapresenza=presenza;
                solve=Ele[i];
            }
        i++;
    }
return(solve);
}
int TrovareValoreMenoPresente(int x, int Ele[x])
{
    int i,j,presenza,minimapresenza,solve;
    i=0;
    minimapresenza=9;
    presenza=0;
    while(i<x)
    {
        j=0;
        while(j<x)
        {
            if(Ele[i]==Ele[j])
                presenza++;
            j++;
        }
        if(presenza<minimapresenza)
            {
                minimapresenza=presenza;
                solve=Ele[i];
            }
        i++;
    }
return(solve);
}
