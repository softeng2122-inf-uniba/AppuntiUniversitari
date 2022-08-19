#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

struct file{
    int numero_mezzo;
    int numero_linea;
    int ascissa;
    int ordinata;
    int tempo;
}tipo_file[20];

FILE *paf;
int numero_elementi;

void caricare_file();
void ordinare_file();
void numero_elementi_file();
void distanza_percorsa();///distanza percorsa durante la giornata indicando l'ora della prima rilevazione e ora dell'ultima
void velocita_media();///velocità= somma delle distanze effetuate/il tempo intercorso tra la prima e l'ultima misurazione

int main()
{
    char flag[3];
    caricare_file();
    numero_elementi_file();
    ordinare_file();
    flag='-c';
    do{
        printf("\n Inserire il flag desiderato:\n");
        scanf("%c",flag);
    }while(strcmp(flag,'-d')<0 && strcmp(flag,'-v')<0);
    if(strcmp(flag,'-d')==0)
        distanza_percorsa();
    else
        velocita_media();
    return 0;
}

void caricare_file()
{
    paf=fopen("trasporti.txt","w");
    int numero_mezzo;
    int numero_linea;
    int ascissa;
    int ordinata;
    int tempo;
    int scelta;
    int elementi_rimasti;
    elementi_rimasti=20;
    scelta=1;
    numero_elementi=0;
    while(scelta==1 && numero_elementi<20)
    {
        printf("\n Inserire il numero del mezzo: \n");
        scanf("%d",&numero_mezzo);
        printf("\n Inserire il numero della linea: \n");
        scanf("%d",&numero_linea);
        printf("\n Inserire l'ascissa: \n");
        scanf("%d",&ascissa);
        printf("\n Inserire l'ordinata: \n");
        scanf("%d",&ordinata);
        printf("\n Inserire il tempo in secondi: \n");
        scanf("%d",&tempo);
        do{
            printf("\n Inserire 1 per continuare e 2 per terminare: \n");
        scanf("%d",&scelta);
        }while(scelta!=1 && scelta!=2);
        elementi_rimasti--;
        numero_elementi++;
        printf("\n Puoi inserire ancora %d elementi\n",elementi_rimasti);
        fprintf(paf,"%d %d %d %d %d\n",numero_mezzo,numero_linea,ascissa,ordinata,tempo);
    }
    fclose(paf);
}

void numero_elementi_file()
{
    paf=fopen("trasporti.txt","r");
    numero_elementi=0;
    while(fscanf(paf,"%d %d %d %d %d",&tipo_file[numero_elementi].numero_mezzo,&tipo_file[numero_elementi].numero_linea,&tipo_file[numero_elementi].ascissa,&tipo_file[numero_elementi].ordinata,&tipo_file[numero_elementi].tempo)!=EOF)
        numeroelementi++;
    fclose(paf);
}

void ordinare_file()
{
    int i,j;
    int x;
    i=0;
    while(i<numero_elementi-1)
    {
        j=0;
        while(j<numero_elementi)
        {
            if(tipo_file[i].tempo>tipo_file[j].tempo)
            {
                x=tipo_file[i].tempo;
                tipo_file[i].tempo=tipo_file[j].tempo;
                tipo_file[j].tempo=x;
                x=tipo_file[i].ascissa;
                tipo_file[i].ascissa=tipo_file[j].ascissa;
                tipo_file[j].ascissa=x;
                x=tipo_file[i].ordinata;
                tipo_file[i].ordianta=tipo_file[j].ordinata;
                tipo_file[j].ordianta=x;
                x=tipo_file[i].numero_linea;
                tipo_file[i].numero_linea=tipo_file[j].numero_linea;
                tipo_file[j].numero_linea=x;
                x=tipo_file[i].numero_mezzo;
                tipo_file[i].numero_mezzo=tipo_file[j].numero_mezzo;
                tipo_file[j].numero_mezzo=x;
            }
            j++;
        }
        i++;
    }
    paf=fopen("trasporti.txt"."w");
    i=0;
    while(i<numero_elementi)
    {
        fprintf(paf,"%d %d %d %d %d\n",tipo_file[i].numero_mezzo,tipo_file[i].numero_linea,tipo_file[i].ascissa,tipo_file[i].ordinata,tipo_file[i].tempo);
        i++;
    }
    fclose(paf);
}
void distanza_percorsa()
{
    int i,j;
    int somma_ordiante,somma_ascisse;
    int somma_quadrati;
    int quadrato_ascisse,quadrato_ordinate;
    float distanza;
    i=0;
    while(i<numero_elementi)
    {
       j=0;
       while(j<numero_elementi)
       {
            if(tipo_file[i].numero_mezzo==tipo_file[j].numero_mezzo)
            {
                somma_ascisse=tipo_file[j].ascissa-tipo_file[i].ascissa;
                somma_ordiante=tipo_file[j].ordinate-tipo_file[i].oridanta;
                quadrato_ascisse=somma_ascisse*somma_ascisse;
                quadrato_ordinate=somma_ordiante*somma_ordiante;
                somma_quadrati=quadrato_ascisse+quadrato_ordinate;
                distanza=sqrt(somma_quadrati);
                printf("\n %d: %.2f m",tipo_file[i].numero_mezzo,distanza);
            }
            j++;
        }
        i++;
    }
}
