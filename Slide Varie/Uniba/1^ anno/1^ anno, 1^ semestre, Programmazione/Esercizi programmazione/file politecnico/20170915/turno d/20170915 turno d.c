#include<stdio.h>
#include<stdlib.h>
FILE *pcam;
FILE *ppre;
struct hotel{
    int numcamera;
    int pole;
    int occ;
};
struct hotel stanze[100];
void caricarefilecamere();
void gestioneprenotazioni();
void main()
{
    pcam=fopen("camere.txt","w");
    caricarefilecamere();
    fclose(pcam);
    pcam=fopen("camere.txt","r");
    gestioneprenotazioni();
}
void caricarefilecamere()
{
    int scelta=1;
    int totcam;
    int numcam;
    int posti;
    int occupata;
    while(scelta==1)
    {
        printf("\n inserire il numero della stanza\n");
        scanf("%d",&numcam);
        printf("\n inserire il numero totale dei posti della stanza\n");
        scanf("%d",&posti);
        printf("\n inserire 1 se la camera è occupata 0 se è libera\n");
        scanf("%d",&occupata);
        printf("\n inserire 1 per continuare 2 per terminare\n");
        scanf("%d",&scelta);
        fprintf(pcam,"%d %d %d",totcam,numcam,posti,occupata);
    }
}
void gestioneprenotazioni()
{
    int ncm=0;
    while(fscanf(pcam,"%d %d %d",&stanze[ncm].numcamera,&stanze[ncm].pole,&stanze[ncm].occ)!=EOF)
        ncm++;
    int pren;
    int vet[4];
    printf("\n inserire numero stanze che si devono prenotare, max 4 stanze\n");
    scanf("%d",&pren);
    int i=1;
    while(i<=pren)
    {
        printf("\n Inserire quanti posti letto deve avere la stanza numero %d",i);
        scanf("%d",vet[i]);
        i++;
    }
    i=0;
    int j;
    while(i<pren)
    {
        j=0;
        while(j<ncm)
        {
            if((vet[i]==stanze[j].pole)&&(stanze[j].occ==0))
               {
                   printf("numero camera %d posti letto %d\n",stanze[j].numcamera,stanze[j].pole);
                   stanze[j].occ=1;
               }
            j++;
        }
        i++;

    }
}
