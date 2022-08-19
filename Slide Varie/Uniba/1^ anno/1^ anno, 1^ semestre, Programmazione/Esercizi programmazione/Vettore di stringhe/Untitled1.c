#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void main(){

    int dimensione_vettore;
    int dimensione_stringa;
    printf("\n inserire la dimensione del vettore\n");
    scanf("%d",&dimensione_vettore);
    printf("\n inserire la dimensione massima delle stringhe\n");
    scanf("%d",&dimensione_stringa);
    char vettore[dimensione_vettore][dimensione_stringa];
    int i;
    i=0;
    while(i<dimensione_vettore)
    {
        do{
            printf("\n Inserire stringa in posizione %d\n",i);
            fflush(stdin);
            scanf("%s",vettore[i]);
        }while(strlen(vettore[i])>10);

        i++;
    }
    printf("\n Elementi del vettore\n");
    i=0;
    while(i<dimensione_vettore)
    {
        printf("\n %s\n",vettore[i]);
        i++;
    }
}
