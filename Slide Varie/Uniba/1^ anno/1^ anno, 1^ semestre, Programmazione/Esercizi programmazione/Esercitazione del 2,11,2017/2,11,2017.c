/*Data una matrice di n righe ed m colonne, di numeri interi minori di 10.
Individuare e stampare le colonne della matrice che contengono tre elementi consecutivi che abbiano valori successivi.*/

#include<stdio.h>
#include<stdlib.h>

void CaricareMatrice(int x, int y, int Mat[x][y]);
void IndividuareColonne(int x, int y, int Mat[x][y]);
void StampareColonna(int x,int y,int Mat[x][y],int j);
int main()
{
    int n, m;
    printf("\nInserire il numero delle rihe della matrice\n");
    scanf("%d",&n);
    printf("\nInserire il numero delle colonne della matrice\n");
    scanf("%d",&m);
    int Matrice[n][m];
    CaricareMatrice(n,m,Matrice);
    IndividuareColonne(n,m,Matrice);

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
            printf("\n Inserire Elemento nella matrice in posizione %d x %d\n",i,j);
            scanf("%d",&Mat[i][j]);
            j++;
        }
        i++;
    }
}
void IndividuareColonne(int x, int y, int Mat[x][y])
{
    int i,j,controllo1=0,controllo2=0;
    i=0;
    while(i<x)
    {
        j=0;
        while(j<y)
        {
            if(Mat[i+1][j+1]==(Mat[i][j]+1))
               controllo1=1;
            if(Mat[i+2][j+2]==(Mat[i+1][j+1]+1))
                controllo2=1;
            if((controllo1==1)&&(controllo2==1))
                printf("\n inzio stampa colonna\n");
                StampareColonna(x,y,Mat,j);
            j++;
        }
        i++;
    }
}

void StampareColonna(int x,int y,int Mat[x][y],int j)
{
    int i=0;
    printf("\n Stampa della colonna con elementi consecutivi\n");
    while(i<x)
    {
       printf("\n %d\n",Mat[i][j]);
       i++;
    }
}
