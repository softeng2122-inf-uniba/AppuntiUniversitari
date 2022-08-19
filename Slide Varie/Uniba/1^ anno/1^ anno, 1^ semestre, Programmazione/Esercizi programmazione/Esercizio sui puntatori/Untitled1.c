#include<stdio.h>
#include<stdlib.h>
void caricavettore(int *punt);
void visualizzarevettore(int *punt);
int main()
{
     int a;
     int *pt;
     a=7;
     pt=&a;
     printf("punt %p\n", pt);
     printf("punt %d\n", *pt);
     int vettore[5];
     int i=0;
     while(i<5)
     {
         printf("inserire elemento\n");
         scanf("%d",&vettore[i]);
         i++;
     }
     pt=&vettore;
     i=0;
     while(i<5)
     {
         printf(" puntatore a vettore %d\n",*pt+i);
         i++;
     }
     int M[2][2];
     int *ptm;
     int j;
     i=0;
     while(i<2)
     {
         j=0;
         while(j<2)
         {
             printf("\n inserire elemento matrice\n");
             scanf("%d",&M[i][j]);
             j++;
         }
         i++;
     }
     ptm=&M;

     i=0;
     while(i<4)
     {
        printf("puntatore a matrice %d\n",*ptm+i);
        i++;
     }
     int Vett2[5];
     int *p;
     p=&Vett2;
     caricavettore(p);
     p=&Vett2;
     visualizzarevettore(p);
}
void caricavettore(int *punt)
{
    int i;
    i=0;
    while(i<5)
    {
        printf("inserire elemeto vettore con la funzione\n");
        scanf("%d",&punt+i);
        i++;
    }

}
void visualizzarevettore(int *punt)
{
    int i=0;
    while(i<5)
    {
        printf("elemento del vettore attraverso il puntatore %d\n", *punt+i);
        i++;
    }
}
