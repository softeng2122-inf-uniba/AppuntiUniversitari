/*Esercitazione del 23 novembre 2017
Realizzare le operazioni di somma di 2 matrici, prodotto di 2 matrici, prodotto scalare di una matrice per un reale e trasposta di 1 matrice.
Il tipo di dato matrice deve essere rappresentato come un vettore di reali a 1 dimensione variabile*/

#include<stdio.h>
#include<stdlib.h>

void CaricareMatrice(int x, int y, int Mat[x][y]);
void VisualizzareMatrice(int x,int y, int Mat[x][y]);
void SommareDueMatrici(int x,int y,int x1, int y1, int Mat[x][y],int Mat2[x1][y1]);
//void ProdottoDiDueMatrici(int x,int y,int x1, int y1, int Mat[x][y],int Mat2[x1][y1]);
void ProdottoScalare(int x, int y, int Mat[x][y], int num);
void TrasportoMatrice(int x, int y, int Mat[x][y]);

int main()
{
    int n,m,n1,m1;
    printf("\n Inserire numero righe della prima matrice\n");
    scanf("%d",&n);
    printf("\nInserire numero colonne della prima matrice\n");
    scanf("%d",&m);
    printf("\n Inserire numero righe della seconda matrice\n");
    scanf("%d",&n1);
    printf("\n Inserire numero colonne della seconda matrice\n");
    scanf("%d",&m1);
    int Matrice1[n][m];
    int Matrice2[n1][m1];
    CaricareMatrice(n,m,Matrice1);
    CaricareMatrice(n1,m1,Matrice2);
    if((n==n1)&&(m==m1))
        SommareDueMatrici(n,m,n1,m1,Matrice1,Matrice2);
  //  if(n==m1)
    //    ProdottoDiDueMatrici(n,m,n1,m1,Matrice1,Matrice2);
    int reale;
    printf("\n Inserire il numero che per il quale si deve moltiplicare la matrice\n");
    scanf("%d",&reale);
    int numeromatrice;
    printf("\n Inserire 1 se si vuole moltiplicare la prima matrice 2 se si vuole moltiplicare la seconda matrice\n");
    scanf("%d",&numeromatrice);
    if(numeromatrice==1)
        ProdottoScalare(n,m,Matrice1,reale);
    else
        ProdottoScalare(n1,m1,Matrice2,reale);
    printf("\n Inserire 1 per trasportare la prima matrice, 2 per trasportare la seconda matrice\n");
    scanf("%d",&numeromatrice);
    if(numeromatrice==1)
        TrasportoMatrice(n,m,Matrice1);
    else
        TrasportoMatrice(n1,m1,Matrice2);

}
void CaricareMatrice(int x, int y, int Mat[x][y])
{
    int i,j;
    i=0;
    while(i<x)
    {
        j=0;
        while(j<y)
        {
            printf("\n Inserire elemento in posizione %d x %d\n",i,j);
            scanf("%d",&Mat[i][j]);
            j++;
        }
    i++;
    }
}
void VisualizzareMatrice(int x,int y, int Mat[x][y])
{
    int i,j;
    i=0;
    while(i<x)
    {
        j=0;
        while(j<y)
        {
            printf("\n L'elemento in posizione %d x %d �: %d",i,j,Mat[i][j]);
        }
    }
}
void SommareDueMatrici(int x,int y,int x1, int y1, int Mat[x][y],int Mat1[x1][y1])
{
    int Mat3[x][y];
    int i,j;
    i=0;
    while(i<x)
    {
        j=0;
        while(j<y)
        {
            Mat3[i][j]=Mat[i][j]+Mat1[i][j];
            j++;
        }
        i++;
    }
}
/*void ProdottoDiDueMatrici(int x,int y,int x1, int y1, int Mat[x][y],int Mat1[x1][y1])
{

}*/
void ProdottoScalare(int x, int y, int Mat[x][y],int num)
{
   int Mat3[x][y];
    int i,j;
    i=0;
    while(i<x)
    {
        j=0;
        while(j<y)
        {
            Mat3[i][j]=Mat[i][j]*num;
            j++;
        }
        i++;
    }
}
void TrasportoMatrice(int x, int y, int Mat[x][y])
{

}
