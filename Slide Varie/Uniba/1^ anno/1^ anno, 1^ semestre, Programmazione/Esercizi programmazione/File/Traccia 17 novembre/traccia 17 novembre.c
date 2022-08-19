#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct CapiAbbigliamento{
    char codpro[30];
    char descr[30];
    char comp[30];
    float taglia;
    float prz;
};
struct CapiAbbigliamento capi[100];
struct NuoviPrezzi{
    char codpro[30];
    float prz;
};
int qc;
int qnp;
struct NuoviPrezzi nupr[100];
FILE *pc;
FILE *np;
FILE *pca;
void creazionecapi();
void creazionenuoviprezzi();
void aggiornamento();
void visualizza();
int main()
{
   /* pc=fopen("capi.txt","w");
    np=fopen("nuoviprezzi.txt","w");
    creazionecapi();
    creazionenuoviprezzi();
    fclose(pc);
    fclose(np);*/
    pc=fopen("capi.txt","r");
    np=fopen("nuoviprezzi.txt","r");
    pca=fopen("prezziaggiornati.txt","w");
    aggiornamento();
    fclose(pc);
    fclose(np);
    fclose(pca);
    pc=fopen("capi.txt","r");
    pca=fopen("prezziaggiornati.txt","r");
    visualizza();
}
void creazionecapi()
{
    char codpr[30];
    char desc[30];
    char comp[30];
    float taglia;
    float prezzo;
    int ff=1;
    while(ff==1)
    {
        printf("Inserire codice prodotto\n");
        scanf("%s",codpr);
        printf("\n Inserire descrizione\n");
        scanf("%s", desc);
        printf("\n Inserire composizione del prodotto\n");
        scanf("%s",comp);
        printf("\n Inserire taglia\n");
        scanf("%f",&taglia);
        printf("\n Inserire prezzo\n");
        scanf("%f",&prezzo);
        fprintf(pc,"%s %s %s %f %f \n",codpr,desc,comp,taglia,prezzo);
        printf("\n Premere 1 per continuare, 2 per terminare\n");
        scanf("%d", &ff);
    }
}
void creazionenuoviprezzi()
{
    char cp[30];
    float nprz;
    int ff=1;
    while(ff==1)
    {
        printf("\n Inserire il codice del prezzo che si vuole cambiare\n");
        scanf("%s",cp);
        printf("\n Inserire il nuovo prezzo\n");
        scanf("%f",&nprz);
        fprintf(np,"%s %f\n",cp, nprz);
        printf("\n Inserire 1 per continuare e 2 per terminare\n");
        scanf("%d",&ff);
    }
}
void aggiornamento()
{
    qc=0;
    while(fscanf(pc,"%s %s %s %f %f",capi[qc].codpro,capi[qc].descr,capi[qc].comp,&capi[qc].taglia,&capi[qc].prz)!=EOF)
        qc++;
    qnp=0;
    while(fscanf(np,"%s %f",nupr[qnp].codpro,&nupr[qnp].prz)!=EOF)
        qnp++;
    int i=0;
    int j;
    int trovato=0;
    while(i<qnp)
    {
        j=0;
        while(j<qc)
        {
            if(strcmp(nupr[i].codpro,capi[j].codpro)==0)
            {
                capi[j].prz=nupr[i].prz;
                trovato=1;
            }
            j++;
        }
        if(trovato==0)
            printf("\n Il codice %s non è stato trovato\n",nupr[i].codpro);
        i++;
    }
    i=0;
    while(i<qc)
    {
        fprintf(pca,"%s %s %s %f %f\n",capi[i].codpro,capi[i].descr,capi[i].comp,capi[i].taglia,capi[i].prz);
        i++;
    }
}
void visualizza()
{
    char codpro[30];
    char descrizione[30];
    char composizione[30];
    float taglia;
    float prezzo;
    while(!feof(pc))
    {
        fscanf(pc,"%s %s %s %f %f",codpro,descrizione,composizione,&taglia,&prezzo);
        if(!feof(pc))
            printf("\n%s %s %s %f %f\n",codpro,descrizione,composizione,taglia,prezzo);
        fscanf(pca,"%s %s %s %f %f",codpro,descrizione,composizione,&taglia,&prezzo);
        if(!feof(pca))
            printf("\n%s %s %s %f %f\n",codpro,descrizione,composizione,taglia,prezzo);
    }
}
