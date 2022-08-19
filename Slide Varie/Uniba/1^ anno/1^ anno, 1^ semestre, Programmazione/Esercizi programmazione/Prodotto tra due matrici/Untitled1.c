#include<stdio.h>
#include<stdlib.h>
void prodottomatrici(int nr1,int nc1,int nr2,int nc2, float M1[nr1][nc1],float M2[nr2][nc2]);
int main()
{
    int nc1,nc2,nr1,nr2;
    printf("inserire il numero di righe della prima matrice\n");
    scanf("%d",&nr1);
    printf("\n inserire il numero di colonne della prima matrice\n");
    scanf("%d",&nc1);
    printf("\n inserire il numero di righe della seconda matrice\n");
    scanf("%d",&nr2);
    printf("\n inserire il numero di colonne della seconda matrice\n");
    scanf("%d",&nc2);
    float M1[nr1][nc1],M2[nr2][nc2];
    int i,j;
    i=0;
    while(i<nr1)
    {
        j=0;
        while(j<nc1)
        {
            printf("inserire il valore della prima matrice in posizione %dx%d\n",i,j);
            scanf("%f",&M1[i][j]);
            j++;
        }
        i++;
    }
    printf("\n");
    i=0;
    while(i<nr2)
    {
        j=0;
        while(j<nc2)
        {
            printf("inserire il valore della seconda matrice in posizione %dx%d\n",i,j);
            scanf("%f",&M2[i][j]);
            j++;
        }
        i++;
    }
    i=0;
    while(i<nr1)
    {
        j=0;
        while(j<nc1)
        {
            printf("elemento della prima matrice in posizione %dx%d : %f\n",i,j,M1[i][j]);
            j++;
        }
        i++;
    }
    printf("\n");
     i=0;
    while(i<nr2)
    {
        j=0;
        while(j<nc2)
        {
            printf("elemento della seconda matrice in posizione %dx%d : %f\n",i,j,M2[i][j]);
            j++;
        }
        printf("\t");
        i++;
    }
    if(nc1==nr2)
        prodottomatrici(nr1,nr2,nc1,nc2,M1,M2);
    else
        printf("Le due matrici non hanno i requisiti necessari per effettuare il loro prodotto\n");
}
void prodottomatrici(int nr1,int nc1,int nr2,int nc2, float M1[nr1][nc1],float M2[nr2][nc2])
{
    int i,j,x,y,k;
    float M3[nr1][nc2],s;
    x=0;
    while(x<nc2)
    {
        y=0;
        while(y<nr1)
        {
            M3[x][y]=0;
            y++;
        }
        x++;
    }
    i=0;
    while(i<nr1){
        j=0;
        while(j<nc2){
            k=0;
            s=0;
            while (k<nc1){
                s+=M1[i][k]*M2[k][j];
                k++;
            }
            M3[i][j]=s;
            j++;
        }
        i++;
    }

printf("\n");
    x=0;
    while(x<nc2)
    {
        y=0;
        while(y<nr1)
        {
            printf("matrice prodotto elemento in posizione %dx%d: %f\n",x,y,M3[x][y]);
            y++;
        }
        x++;
    }
}
