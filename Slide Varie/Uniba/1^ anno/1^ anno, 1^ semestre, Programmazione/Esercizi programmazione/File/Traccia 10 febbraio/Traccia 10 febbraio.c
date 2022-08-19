#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct consumo{
    char nome[20];
    float vlidr;//volume idrico
};
struct consumo cn[100];

FILE *pfcon;//puntatore al file consumi.txt
int na;
void creafile(FILE *pfcon);
int letturafile(FILE *pfcon);
float importo( );
void impstru();
int main()
{
   //pfcon=fopen("consumi.txt","w");
   // if(pfcon==NULL)
   //     printf("\n Il file consumi.txt non può essere aperto\n");
   // else
     //   creafile(pfcon);
    pfcon=fopen("consumi.txt","r");
    letturafile(pfcon);
    float importotot=0;
    importotot=importo();
    if(importotot!=0)
        printf("\n%f\n",importotot);
    impstru();
}

void creafile(FILE *pfcon)
{
    int ff=1;
    char nome[20];
    float conidr;
    while(ff==1)
    {
        printf("\nInserire il nome dell'unità abitativa\n");
        scanf("%s",&nome);
        printf("\n Inserire il consumo abitativo\n");
        scanf("%f",&conidr);
        fprintf(pfcon," %s %f\n",nome, conidr);
        do{
            printf("\n inserire 1 per continuare e 2 per terminare\n");
            scanf("%d",&ff);
        }while((ff!=1)&&(ff!=2));
    }
    fclose(pfcon);
}
int letturafile(FILE *pfcon)
{

    na=0;
    while(fscanf(pfcon,"%s %f",cn[na].nome,&cn[na].vlidr)!=EOF)
        na++;

    int i=0;
    while(i<na)
    {
        printf("\n %s %f",cn[i].nome,cn[i].vlidr);
        i++;
    }
    fclose(pfcon);
}
float importo()
{
    int i=0;
    int solve;
    char nome[20];
    float imptot=0;
    printf("\n inserire il nome del'unità abitativa di cui calcolare l'importo\n");
    scanf("%s", nome);
    while(i<na)
    {

        if (strcmp(nome,cn[i].nome))
        {
            if ((cn[i].vlidr>0)&&(cn[i].vlidr<75))
                imptot=12.55+12.55+(cn[i].vlidr*0.460468)+(cn[i].vlidr*0.116788 )+(cn[i].vlidr*0.335273 );
            if((cn[i].vlidr>75.01)&&(cn[i].vlidr<110))
                imptot=12.55+12.55+(cn[i].vlidr*0.604245)+(cn[i].vlidr*0.116788 )+(cn[i].vlidr*0.335273 );
            if((cn[i].vlidr>110.01)&&(cn[i].vlidr<146))
                imptot=12.55+12.55+(cn[i].vlidr*0.994113)+(cn[i].vlidr*0.116788 )+(cn[i].vlidr*0.335273 );
            if((cn[i].vlidr>146.01)&&(cn[i].vlidr<256))
                imptot=12.55+12.55+(cn[i].vlidr*1.487911)+(cn[i].vlidr*0.116788 )+(cn[i].vlidr*0.335273 );
            if(cn[i].vlidr>256)
                imptot=12.55+12.55+(cn[i].vlidr*1.825007)+(cn[i].vlidr*0.116788 )+(cn[i].vlidr*0.335273 );

        }
        i++;
    }
fclose(pfcon);
return(imptot);
}
void impstru()
{
    int i=0;
    float imp;
    while(i<na)
    {
        if ((cn[i].vlidr>0)&&(cn[i].vlidr<75))
            imp=12.55+12.55+(cn[i].vlidr*0.116788 )+(cn[i].vlidr*0.335273 )+(cn[i].vlidr*0.460468);
        if((cn[i].vlidr>75.01)&&(cn[i].vlidr<110))
            imp=12.55+12.55+(cn[i].vlidr*0.116788 )+(cn[i].vlidr*0.335273 )+(cn[i].vlidr*0.604245);
        if((cn[i].vlidr>110.01)&&(cn[i].vlidr<146))
            imp=12.55+12.55+(cn[i].vlidr*0.116788 )+(cn[i].vlidr*0.335273 )+(cn[i].vlidr*0.994113);
        if((cn[i].vlidr>146.01)&&(cn[i].vlidr<256))
            imp=12.55+12.55+(cn[i].vlidr*0.116788 )+(cn[i].vlidr*0.335273 )+(cn[i].vlidr*1.487911);
        if(cn[i].vlidr>256)
            imp=12.55+12.55+(cn[i].vlidr*0.116788 )+(cn[i].vlidr*0.335273 )+(cn[i].vlidr*1.825007);
        printf("%f\n",imp);
        i++;
    }
}

