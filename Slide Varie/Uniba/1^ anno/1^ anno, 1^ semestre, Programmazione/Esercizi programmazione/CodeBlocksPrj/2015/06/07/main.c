#include <stdio.h>
#include <stdlib.h>
#include<string.h>
FILE *paf;
struct visita{
    char nome[20];
    char cognome[20];
    char data[11];
    int stato;
};
struct visita prenotazioni[100];
int nump=0;
void lista();
void prossimoassistito();
void disdire();
void stamparelista();
int main()
{
    char nome[20],cognome[20],data[11];
    int scelta, st;
    paf=fopen("visita.txt","w");
    scelta=1;
    while(scelta==1)
    {
        printf("\n inserisci nome paziente\n");
        scanf("%s",nome);
        printf("\n inserisci cognome paziente\n");
        scanf("%s",cognome);
        printf("\n inserire data del tipo GG/MM/AAAA\n");
        scanf("%s",data);
        printf("\n inserire stato\n");
        scanf("%d",&st);
        fprintf(paf,"%s %s %s %d\n",nome,cognome,data,st);
        do{
            printf("Inserisci 1 per continuare e 2 per terminare\n");
            scanf("%d",&scelta);
        }while(scelta!=1 && scelta!=2);
    }
    fclose(paf);
    paf=fopen("visita.txt","r");
    lista();
    int scelta1;
    do{
        printf("\n Inserire scelta\n 1- Prossimo assistito\n 2-Inserire assistito che vuole disdire una visita\n 3-Stampa lista\n 4-Termine programma\n");
        scanf("%d",&scelta1);
        if(scelta1==1)
            prossimoassistito();
        if(scelta1==2)
            disdire();
        if(scelta1==3)
            stamparelista();
    }while(scelta1!=4);
}
void lista()
{
    FILE *pal;
    pal=fopen("lista.txt","w");
    while(fscanf(paf,"%s %s %s %d",prenotazioni[nump].nome,prenotazioni[nump].cognome,prenotazioni[nump].data,&prenotazioni[nump].stato)!=EOF)
        nump++;
    char dt[11];
    printf("Inserire data \n");
    scanf("%s",dt);
    int i=0;
    while(i<nump)
    {
        if(strcmp(dt,prenotazioni[i].data)==0)
        {
            fprintf(pal,"%s %s\n",prenotazioni[i].nome,prenotazioni[i].cognome);
        }
    i++;
    }
    fclose(pal);
    pal=fopen("lista.txt","r");
    char nome[20], cognome[20];
    while(!feof(pal))
    {
        fscanf(pal,"%s %s", nome, cognome);
        printf("%s %s\n",nome,cognome);
    }
}
void prossimoassistito()
{
    int i=0;
    char dto[11];
    printf("\n inserire data odierna\n");
    scanf("%s",dto);
    while(i<nump)
    {
        if(strcmp(dto,prenotazioni[i].data)==0 && prenotazioni[i].stato==0)
            printf("%s %s",prenotazioni[i].nome,prenotazioni[i].cognome);
        i++;
    }

}
void disdire()
{
    char nome[20],cognome[20];
    printf("\n Inserire nome del paziente che vuole disdire\n");
    scanf("%s",nome);
    printf("\n Inserire cognome del paziente che vuole disdire\n");
    scanf("%s",cognome);
    int i=0;
    while(i<nump)
    {
        if(strcmp(nome,prenotazioni[i].nome)==0 && strcmp(cognome,prenotazioni[i].cognome)==0)
        {
            prenotazioni[i].stato=-1;
        }
        i++;
    }
}
void stamparelista()
{
    int i=0;
    while(i<nump)
    {
        printf(" %s %s  %s %d\n",prenotazioni[i].nome,prenotazioni[i].cognome,prenotazioni[i].data,prenotazioni[i].stato);
        i++;
    }
}
