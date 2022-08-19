#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *paf;
int cont;
struct studenti{
    char nome[25];
    char cognome[25];
    float media;
};
struct studenti std[200];
void caricafile();
void caricastruttura();
void mediadecrescente();
void visualizzastudenti();
void main()
{
    caricafile();
    caricastruttura();
    mediadecrescente();
    visualizzastudenti();
}

void caricafile()
{
    char nome[25],cognome[25];
    float media;
    int scelta=1;
    printf("\n Carica file\n");
    paf=fopen("Studenti.txt","w");
    if(paf==NULL)
        printf("\n Impossibile aprire il file in modalità scrittura\n");
    else
        {
            while(scelta==1)
            {
                printf("\n Inserire nome dello studente\n");
                fflush(stdin);
                scanf("%s", nome);
                printf("\n Inserire cognome dello studente\n");
                fflush(stdin);
                scanf("%s", cognome);
                printf("\n Inserire media dello studente\n");
                fflush(stdin);
                scanf("%s", &media);
                fprintf(paf,"%s %s %f\n", nome,cognome,media);
                do{
                    printf("\n Inserire 1 per continuare 2 per terminare\n");
                    fflush(stdin);
                    scanf("%d",&scelta);
                }while(scelta!=1 && scelta!=2);
            }
        }
        fclose(paf);
}
void caricastruttura()
{
    paf=fopen("Studenti.txt","r");
    cont=0;
    while(fscanf(paf,"%s %s %f",std[cont].nome,std[cont].cognome,&std[cont].media)!=EOF)
        cont++;
}

void mediadecrescente()
{
    float x;
    char y[25];
    int i,j;
    while(i<cont-1)
    {
        j=i+1;
        while(j<=cont)
        {
            if(std[i].media<std[j].media)
            {
                x=std[i].media;
                std[i].media=std[j].media;
                std[j].media=x;
                strcpy(y,std[i].nome);
                strcpy(std[i].nome,std[j].nome);
                strcpy(std[j].nome,y);
                strcpy(y,std[i].cognome);
                strcpy(std[i].cognome,std[j].cognome);
                strcpy(std[j].cognome,y);
            }
            j++;
        }
        i++;
    }
}

void visualizzastudenti()
{
    int i=0;
    printf("\n Lista ordinata\n");
    while(i<cont)
    {
        printf("\n %s %s %f\n",std[i].nome,std[i].cognome,std[i].media);
        i++;
    }
}
