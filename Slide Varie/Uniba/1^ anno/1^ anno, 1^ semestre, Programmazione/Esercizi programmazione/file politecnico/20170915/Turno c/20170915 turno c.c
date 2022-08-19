#include<stdio.h>
#include<stdlib.h>
#define NMAX 200
FILE *pafi;
FILE *pafo;


int qn,numero[NMAX];
void creazionedelfile();
void numeritroncati();
int main()
{
    /*pafi=fopen("numeri.txt","w");
    if(pafi==NULL)
        printf("\n il file non può essere aperto\n");
    else
        creazionedelfile();
    fclose(pafi);
    pafi=fopen("numeri.txt","r");
    pafo=fopen("numeri_filtrati.txt","w");
    numeritroncati();
    fclose(pafi);
    fclose(pafo);*/
    pafo=fopen("numeri_filtrati.txt","r");
    float n;
    while(!feof(pafo))
    {
        fscanf(pafo,"%f",&n);
        if(!feof(pafo))
            printf("\n %f\n",n);
    }
}
void creazionedelfile()
{
    int x;
    int scelta=1;
    while(scelta==1)
    {
        printf("\n Inserire numero \n");
        scanf("%d", &x);
        printf("\n inserire 1 per continuare e 2 per terminare\n");
        scanf("%d",&scelta);
        fprintf(pafi," %d ",x);
    }
}
void numeritroncati()
{
    qn=0;
    while(fscanf(pafi," %d ",&numero[qn])!=EOF)
        qn++;
    int i;
    int divisore=2;
    int resto;
    int trovato=0;
    int num;
    int nt=0;
    int y;
    i=0;
    while(i<qn)
    {
        num=numero[i];
        y=num;
        while(y>0)
        {
             while((divisore<=y/2)&&(trovato==0))
             {
                resto=y%divisore;
                if(resto==0)
                    trovato=1;
                divisore++;
             }
             y=y/10;
        }
        if(trovato==0)
        {
            nt++;
            fprintf(pafo," %d ",num);
        }
        i++;
    }
    if(nt==0)
        printf("\n nessun numero trovato\n");

}
