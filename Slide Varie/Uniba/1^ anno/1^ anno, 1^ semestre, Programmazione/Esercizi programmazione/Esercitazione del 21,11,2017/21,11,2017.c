/*Realizzare le operazioni di prodotto di 2 matrici e trasposta di 1 matrice.
Il tipo di dato matrice deve essere rappresentato come un vettore di reali a 2 dimensioni variabili.*/
#include<stdlib.h>
#include<stdio.h>
void CaricareMatrice(int x,int y,int M5[x][y]);
void VisualizzareMatrice(int x,int y,int M6[x][y]);
//void MoltiplicareDueMatrici(int n,int m,int n1,int m1,int M1[n][m],int M2[n1][m1]);
void TrasportareUnaMatrice(int n,int m,int M3[n][m]);
int main()
{
   int n,m,n1,m1;
   printf("\n Inserire numero righe prima matrice\n");
   scanf("%d",&n);
   printf("1n Inserire numero colonne prima matrice\n");
   scanf("%d",&m);
   printf("\n Inserire numero rihe seconda matrice\n");
   scanf("%d",&n1);
   printf("\n inserire numero colonne seconda colonna\n");
   scanf("%d",&m1);
   int Matrice1[n][m];
   int Matrice2[n1][m1];
   printf("\n Inserire elementi nella prima matrice\n");
   CaricareMatrice(n,m,Matrice1);
   printf("\n Inserire elementi nella seconda matrice\n");
   CaricareMatrice(n1,m1,Matrice2);
   printf("\n Ecco la prima matrice\n");
   VisualizzareMatrice(n,m,Matrice1);
   printf("\n Ecco la seconda matrice\n");
   VisualizzareMatrice(n1,m1,Matrice2);
   //MoltiplicareDueMatrici(n,m,n1,m1,Matrice1,Matrice2);
   int scelta=4;
   printf("\n Inserire 1 per trasportare la prima matrice, 2 per trasportare la seconda matrice");
   scanf("%d",&scelta);
   if(scelta==1)
        TrasportareUnaMatrice(n,m,Matrice1);
   else
        TrasportareUnaMatrice(n1,m1,Matrice2);


}
void CaricareMatrice(int x,int y,int M5[x][y])
{
	int i,j;
	i=0;
	while(i<x)
	{
    	j=0;
    	while(j<y)
    	{
    	    printf("\n Inserire il valore nella matrice in posizione %d  %d\n ",i,j);
        	scanf("%d",&M5[i][j]);
        	j++;
    	}
    	i++;
	}

}
void VisualizzareMatrice(int x,int y,int M6[x][y])
{
    int i,j;
    i=0;
    while(i<x)
    {
        j=0;
        while(j<y)
        {
            printf("\n L'elemento in posizione %dx%d:   %d\n",i,j,M6[i][j]);
            j++;
        }
    i++;
    }
}
/*void MoltiplicareDueMatrici(int n,int m,int n1,int m1,int M1[n][m],int M2[n1][m1])
{
    int M4[n][m1];
    int i,j;
    i=0;
    while(i<n)
    {
        j=0;

    }
}*/
void TrasportareUnaMatrice(int n,int m,int M3[n][m])
{
    int i,j;
    int M5[m][n];
    i=0;
    while(i<n)
    {
        j=0;
        while(j<m)
        {
            M5[j][i]=M3[i][j];
            j++;
        }
    i++;
    }
}
