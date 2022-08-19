#include <stdio.h>
#include <stdlib.h>
void testxyz();
void crearevettore(int x, float vett[x]);
void crearematrice(int x, float mat[x][x]);
void caricarematrice(float num,int x, float vett[x],float mat[x][x]);
void visualizzavettore(int x, float vett[x]);
void visualizzamatrice(int x, float mat[x][x]);
void main()
{
   int dim;
   float num;
   printf("\n Inserire la dimensione del vettore\n");
   scanf("%d",&dim);
   float vett[dim];
   float mat[dim][dim];
   crearevettore(dim,vett);
   crearematrice(dim, mat);
   visualizzamatrice(dim,mat);
   visualizzavettore(dim, vett);
   printf("\n Inserire il numero che deve corrispondere al massimo della somma degli elementi del vettore\n");
   scanf("%f",&num);
   caricarematrice(num,dim, vett, mat);
   visualizzamatrice(dim,mat);
}

void crearevettore(int x, float vett[x])
{
    printf("\n inizio creare vettore\n");
    int i=0;
    while(i<x)
    {
        printf("\n Inserire elemento nel vettore in posizione %d\n",i);
        scanf("%f",&vett[i]);
        i++;
    }
    printf("\n fine creare vettore\n");
}

void caricarematrice(float num,int x, float vett[x],float mat[x][x])
{
    printf("\n inizio caricarematrice\n");
    int i,j,k,y;
    float somma=0;
    k=0;
    i=0;
    j=0;
    while(k<x)
    {
        somma=0;
        y=k;
        while(y<x)
        {
            somma=somma+vett[y];
            if(somma==num || somma<num)
            {
                mat[i][j]=vett[y];
                y++;
                j++;
            }
            else
            {
                j++;
                somma=vett[y];
                mat[i][j]=somma;
                y++;
            }
        }
        i++;
        k++;
    }

    printf("\n fine caricarematrice\n");
}
void visualizzavettore(int x, float vett[x])
{
    printf("\n inizio visualizza vettore\n");
    int i=0;
    while(i<x)
    {
        printf("\n Elemento in posizione %d: %0.2f\n",i,vett[i]);
        i++;
    }
    printf("\n fine visualizza vettore\n");
}
void visualizzamatrice(int x, float mat[x][x])
{
    printf("\n inizio visualizzare matrice\n");
    int i,j;
    i=0;
    while(i<x)
    {
        j=0;
        while(j<x)
        {
            printf("\nElemento in posizione %dx%d: %0.2f\n",i,j,mat[i][j]);
            j++;
        }
        i++;
    }
    printf("\n fine visualizzare matrice\n");
}
void crearematrice(int x, float mat[x][x])
{
    printf("\n inizio creare matrice\n");
    int i,j;
    i=0;
    while(i<x)
    {
        while(j<x)
        {
            mat[i][j]=0.0;
            j++;
        }
        i++;
    }
    printf("\n fine creare matrice\n");
}
