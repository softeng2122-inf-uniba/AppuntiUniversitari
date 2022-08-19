#include <stdio.h>
#include <stdlib.h>
FILE *paf;
int somma();
int conversione(int x);
int main()
{
    int risultato;
    risultato=somma();
    switch(risultato)
    {
        case -1:
            printf("Il file non esiste\n");
            break;
        case 0:
            printf("Il file è vuoto\n");
            break;
        default:
            printf("Il risultato e' %d",risultato);
            break;
    }
    return 0;
}

int somma()
{
    int somma=0, num;
    char nmfl[20];
    printf("\n Inserire il nome del file\n");
    scanf("%s",nmfl);
    paf=(nmfl,"r");
    if(paf==NULL)
        printf("\n Il file non può essere aperto\n");
    else
    {
        while(!feof(paf))
        {
            fscanf(paf,"%d",&num);
            num=conversione(num);
            somma=somma+num;
        }
    }
    return(somma);
}
int conversione(int x)
{
    int y,z=0;
    int potenza=0,i,modulo=10;
    while(y>0)
    {
        y=x%modulo;
        i=0;
        while(i<=potenza)
        {
            z=z+y*(10^potenza);
            i++;
        }
        modulo=modulo*10;
    }
    return(y);
}
