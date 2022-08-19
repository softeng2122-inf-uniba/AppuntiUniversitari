#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *pa;
FILE *pv;
FILE *pag;
int nv;
int nva;
struct Voli{
    char cv[20];
    float op;
    char des[30];
    float oa;
    int pt;
    float prz;
};
struct Voli voli[100];
struct Aumenti{
    char cv[20];
    float nprz;
};
struct Aumenti aumenti[100];
void creazionevolo(FILE *pv);
void creazioneaumenti(FILE *pa);
void creazioneaggiornamento(FILE *pag);
void visualizzafile();
int main()
{
    pv=fopen("voli.txt","w");
    if(pv==NULL)
        printf("\n il file voli non può essere aperto\n");
    else
        creazionevolo(pv);

    //pa=fopen("aumenti.txt","w");
    //if(pa==NULL)
        //printf("\n Il file aumenti.txt non può essere aperto\n");
    //else
        //creazioneaumenti(pa);

   pag=fopen("VoliAggiornati.txt","w");
   pv=fopen("voli.txt","r");
   pa=fopen("aumenti.txt","r");
   if(pag==NULL)
      printf("\n Il file VoliAggiornati.txt non può essere aperto\n");
   else
      creazioneaggiornamento(pag);
    pv=fopen("voli.txt","r");
    pag=fopen("VoliAggiornati.txt","r");
    visualizzafile();
}
void creazionevolo(FILE *pv)
{
    char codicevolo[20];
    float orariopartenza;
    char destinazione[30];
    float orarioarrivo;
    int postitotali;
    float prezzo;
    int finefile=1;
    while(finefile==1)
    {
        printf("\n Inserire codicevolo\n");
        scanf("%s",codicevolo);
        printf("\n Inserire orario partenza del tipo XX.XX\n");
        scanf("%f",&orariopartenza);
        printf("\n Inserire destinazione\n");
        scanf("%s",destinazione);
        printf("\n Inserire orario arrivo del tipo XX.XX\n");
        scanf("%f",&orarioarrivo);
        printf("\n Inserire il numero di posti\n");
        scanf("%d",&postitotali);
        printf("\n Inserire il prezzo\n");
        scanf("%f",&prezzo);
        printf("\n Inserire 1 per continuare, 2 per terminare\n");
        scanf("%d",&finefile);
        fprintf(pv,"%s %f %s %f %d %f\n",codicevolo,orariopartenza,destinazione,orarioarrivo,postitotali,prezzo);
        }
        fclose(pv);
}
void creazioneaumenti(FILE *pa)
{
    char codicevolo[20];
    float nuovoprezzo;
    int finefile=1;
    while(finefile==1)
    {
        printf("\n Inserire il codice del volo di cui si vuole modificare il prezzo\n");
        scanf("%s",codicevolo);
        printf("\n Inserire il nuovo prezzo\n");
        scanf("%f",&nuovoprezzo);
        printf("\n Inserire 1 per continuare, 2 per terminare\n");
        scanf("%d",&finefile);
        fprintf(pa," %s %f\n",codicevolo,nuovoprezzo);
    }
    fclose(pa);
}
void creazioneaggiornamento(FILE *pag)
{
    nv=0;
    while(fscanf(pv,"%s %f %s %f %d %f",voli[nv].cv,&voli[nv].op,voli[nv].des,&voli[nv].oa,&voli[nv].pt,&voli[nv].prz)!=EOF)
        nv++;
    nva=0;
    while(fscanf(pa,"%s %f",aumenti[nva].cv,&aumenti[nva].nprz)!=EOF)
        nva++;
    int i=0;
    while(i<nv)
    {
        printf("%s %f %s %f %d %f\n",voli[i].cv,voli[i].op,voli[i].des,voli[i].oa,voli[i].pt,voli[i].prz);
        i++;
    }
    i=0;
    while(i<nva)
    {
        printf("%s %f\n",aumenti[i].cv,aumenti[i].nprz);
        i++;
    }
    i=0;
    int j=0;
    int trovato=0;
    while(i<nva)
    {
        j=0;
        trovato=0;
        while(j<nv)
        {
            if(strcmp(voli[j].cv,aumenti[i].cv)==0)
            {
                voli[j].prz=aumenti[i].nprz;
                trovato=1;
            }
            j++;
        }
        if(trovato==0)
            printf("\n Il volo di codice %s non è stato trovato",aumenti[i].cv);
        i++;
    }
    i=0;
    while(i<nv)
    {
        fprintf(pag,"%s %f %s %f %d %f",voli[i].cv,voli[i].op,voli[i].des,voli[i].oa,voli[i].pt,voli[i].prz);
        i++;
    }
    fclose(pag);
    fclose(pv);
    fclose(pa);
}
void visualizzafile()
{
    char cv[20];
    float op;
    char des[30];
    float oa;
    int pt;
    float prz;
    while(!feof(pv))
    {
        fscanf(pv,"%s %f %s %f %d %f",cv,&op,des,&oa,&pt,&prz);
        if(!feof(pv))
            printf("%s %f %s %f %d %f\n",cv,op,des,oa,pt,prz);
        fscanf(pag,"%s %f %s %f %d %f",cv,&op,des,&oa,&pt,&prz);
        if(!feof(pv))
            printf("%s %f %s %f %d %f\n",cv,op,des,oa,pt,prz);
    }
    fclose(pag);
    fclose(pv);
}
