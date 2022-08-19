#include<stdio.h>
#include<stdlib.h>
FILE *paf;
void crearefilemagazzino();
void calcoloordine(int *punt);
int main()
{
    paf=fopen("magazzino.txt","w");
    if(paf==NULL)
        printf("\n Impossibile aprire il file\n");
    else
        crearefilemagazzino();
    fclose(paf);
    paf=fopen("magazzino.txt","r");
    int gelati;
    printf("\n Inserire numero gelati che si vuole ordinare\n");
    scanf("%d",&gelati);
    int *pg;
    pg=&gelati;
    calcoloordine(*pg);
    fclose(paf);
}
void crearefilemagazzino()
{
    int grandi, piccole, medie;
    printf("\n inserire numero scatole grandi\n");
    scanf("%d",&grandi);
    printf("\n inserire numero scatole medie\n");
    scanf("%d",&medie);
    printf("\n inserire numero scatole piccole\n");
    scanf("%d",&piccole);
    fprintf(paf,"%d %d %d",grandi,medie,piccole);
}
void calcoloordine(int *punt)
{
    int salva;
    salva= *punt;
    int scgr,scme,scpi;
    int i=0;
    while(fscanf(paf,"%d %d %d",&scgr,&scme,&scpi)!=EOF)
        i++;
    int numgr,numpi,numme;
    numgr=scgr*100;
    numme=scme*40;
    numpi=scpi*10;
    int contgra=0;
    while(punt>=100)
    {
        punt=punt-100;
        contgra++;
    }
    int contmedie=0;
    while(punt>=40)
    {
        punt=punt-40;
        contmedie++;

    }
    int contpicc=0;
    while(punt>=10)
    {
        punt=punt-10;
        contpicc++;
    }
    int avanzi;
    if((punt>0)&&(punt<10))
    {
        avanzi=10-punt;
        printf("\nl'ordine contiene %d gelati extra",avanzi);
    }
    int geltot;
    geltot=(contgra*100)+(contmedie*40)+(contpicc*10);
    if(salva==geltot)
        printf("\n l'ordine può essere soddisfatto con %d scatole grandi, %d scatole medie, %d scatole piccole",contgra,contmedie,contpicc);
    else
    {
        float per;
        per=(geltot*100)/salva;
        printf("\n si può soddisfare solo il %.2f %100 dell'ordine",per);
    }

}
