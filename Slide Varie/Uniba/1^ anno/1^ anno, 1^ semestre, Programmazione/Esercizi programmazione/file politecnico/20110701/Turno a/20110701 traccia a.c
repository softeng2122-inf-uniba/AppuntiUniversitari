#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<CUnit-2.1-0/doc/CUnit/headers/Basic.h>
FILE *pc;
void caricafile();
char ntel[15];
void minusc();
void durlun();
void costotel();

struct telefono{
    char numero_telefono[15];
    char data[10];
    int durata;
    char tipo;
};
struct telefono tel[150];

int nt;

int main()
{
    /*pc=fopen("conto.dat","w");
    if(pc==NULL)
        printf("\n Il file non può essere aperto");
    else
        caricafile();
    fclose(pc);*/
    pc=fopen("conto.dat","r");
    printf("\n inserire numero telefono di cui si vuole conoscere il totale dei minuti in uscita\n");
    scanf("%s",ntel);
    minusc();
    fclose(pc);
}

void caricafile()
{
    char Tel[16];
    char Data[11];
    int durata;
    char Tipo;
    int scelta=1;
    while(scelta==1)
    {
        printf("\n Inserisci numero di telefono\n");
        fflush(stdin);
        scanf("%s",Tel);
        printf("\n Inserisci data nel formato GG/MM/AAAA\n");
        fflush(stdin);
        scanf("%s",Data);
        printf("\n Inserisci durata telefonata\n");
        fflush(stdin);
        scanf("%d",&durata);
        printf("\n Inserire tipo U per chiamata in uscita E per chiamata in entrata\n");
        fflush(stdin);
        scanf("%c",&Tipo);
        fprintf(pc,"%s %s %d %c\n",Tel,Data,durata,Tipo);
        printf("\n Inserire 1 per continuare 2 per terminare\n");
        scanf("%d",&scelta);
    }
}

void minusc()
{
    nt=0;
    while(fscanf(pc,"%s %s %d %c",tel[nt].numero_telefono,tel[nt].data, &tel[nt].durata,&tel[nt].tipo)!=EOF)
        nt++;
    float minusc=0;
    int i=0;
    while(i<nt)
    {
        if((strcmp(tel[i].numero_telefono,ntel))&&(tel[nt].tipo=='U'))
            minusc=minusc+tel[i].durata;
        i++;
    }
    minusc=minusc/60;
    printf("\n i minuti in uscita verso il numero %s sono %.2f",ntel,minusc);
}

void durlun()
{
    int i=0;
    float max;
    int salva;
    max=0;
    while(i<nt)
    {
        if((tel[i].durata>max)&&(tel[i].tipo=='U'))
        {
            max=tel[i].durata;
            salva=i;
        }
        i++;
    }
    max=max/60;
    printf("\n la chiamata in uscita più lunga è stata di %f minuti in data %s",max,tel[salva].data);
}

void costotel()
{
    int i=0;
    float costo=0;
    while(i<nt)
    {
        if(tel[i].tipo=='U')
            costo=costo+0.1+0.12*(tel[i].durata/60);
        i++;
    }
    printf("\n Il costo totale delle chiamate è %.2f",costo);
}
