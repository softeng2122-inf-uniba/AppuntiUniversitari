#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct lista{
    char nome[25];
    char matricola[25];
    float voto;
    int md;
};

struct lista studenti[250];
int num;

void caricarestruttura();
void media();
float votomax();
void nomelungo();
void visualizzarevettore(int x, float vet[x]);

void main()
{
    float votomassimo;
    caricarestruttura();
    media();
    votomassimo=votomax();
    nomelungo();
}

void caricarestruttura()
{
    int scelta=1,i=0;
    while(scelta==1)
    {
        printf("\n Inserire nome\n");
        scanf("%s",studenti[i].nome);
        printf("\n Inserire cognome\n");
        scanf("%s",studenti[i].matricola);
        printf("\n Inserire voto\n");
        scanf("%f",&studenti[i].voto);
        studenti[i].md=0;
        do{
            printf("\n Inserire 1 per continuare e due per terminare\n");
            scanf("%d",&scelta);
        }while(scelta!=1 && scelta!=2);
        num++;
    }
}

void media()
{
    int i=0,cont=0,j,dimvet=0;
    float media;
    float vetmd[num];
    while(i<num)
    {
        media=0;
        j=0;
        while(j<num && studenti[i].md==0)
        {
            if(strcmp(studenti[i].matricola,studenti[j].matricola)==0)
            {
                media=media+studenti[j].voto;
                cont++;
                studenti[j].md=1;
            }
           j++;
        }
        if(media!=0)
        {
            media=media/cont;
            vetmd[i]=media;
            dimvet++;
        }
        i++;
    }
    visualizzarevettore(dimvet,vetmd);
}

float votomax()
{
    int i=0;
    float max=0;
    while(i<num)
    {
        if(max<studenti[i].voto)
            max=studenti[i].voto;
        i++;
    }
    return(max);
}
void nomelungo()
{
    int i=0;
    char max[35]="Fe";
    while(i<num)
    {
        if(strcmp(max,studenti[i].nome)<0)
            strcpy(max,studenti[i].nome);
        i++;
    }
    printf("\n Il nome più lungo e': %s",max);
}

void visualizzavettore(int x, float vet[x])
{
    int i=0;
    while(i<x)
    {
        printf("\n %f\n",vet[i]);
        i++;
    }
}
