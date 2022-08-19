#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *paf;
struct file{
    int numero_studenti[150];
    int giorno_del_mese[150];
    int mese[150];
};
struct file elenco[150];

void caricare_file();
int individuare_la_prima_lezione_del_corso();

int main()
{
    int scelta;
    int risultato;
    do{
        printf("\n Inserire 1 se si vuole creare il file, 2 se il file e' gia' presente\n");
        scanf("%d",&scelta);
    }while(scelta!=1 && scelta!=2);
    if(scelta==1)
        caricare_file();
    else
        risultato=individuare_la_prima_lezione_del_corso();
    if(risultato!=0)
        printf("\n Il numero di studenti e' di %d",risulteto);
    else
        printf("\n La data inserita e' sbagliata\n");

    return 0;
}

void caricare_file()
{
    int giorno;
    int mese;
    int studenti;
    int scelta;
    paf=fopen("Lezioni.txt","w");
    do{
        printf("\n Inserire il numero degli studenti presenti alla lezione\n");
        scanf("%d",&studenti);
        do{
            printf("\n Inserire il giorno della lezione\n");
            scanf("%d",&giorno);
        }while(giorno!=1 && giorno!=2 && giorno!=3 && giorno!=4 && giorno!=5 && giorno!=6 && giorno!=7 && giorno!=8 && giorno!=9 && giorno!=10 && giorno!=11 && giorno!=12 && giorno!=13 && giorno!=14 && giorno!=15 && giorno!=16 && giorno!=17 && giorno!=18 && giorno!=19 && giorno!=20 && giorno!=21 && giorno!=22 && giorno!=23 && giorno!=24 && giorno!=25 && giorno!=26 && giorno!=27 && giorno!=28 && giorno!=29 && giorno!=30 && giorno!=31)
        do{
            printf("\n Inserire il mese in cui si e' tenita la lezione\n")
            scanf("%d", &mese);
        }while(mese!=1 && mese!=2 && mese!=3 && mese!=4 && mese!=5 && mese!=6 && mese!=7 && mese!=8 && mese!=9 && mese!=10 && mese!=11 && mese!=12)
        do{
            printf("\n Inserire 1 per continuare, 2 per terminare");
            scanf("%d",&scelta);
        }while(scelta!=1 && scelta!=2);
        fscanf(paf,"%d %d %d\n",studenti,giorno,mese);
    }while(scelta!=1 && scelta!=2);
    fclose(paf);
}
int individuare_la_prima_lezione_del_corso()
{
    int numero_studenti;
    int numero_lezioni;
    int i;
    int minimo_mese;
    int minimo_giorno;
    paf=fopen("Lezioni.txt","r");
    i=0;
    numero_lezioni=0;
    while(!feof(paf))
    {
        fscanf(paf,"%d %d %d",elenco[i].numero_studenti,elenco[i].giorno_del_mese,elenco[i].mese);
        i++;
        numero_lezioni++;
    }
    minimo_mese=12;
    i=0;
    while(i<numero_lezioni)
    {
        if(elenco[i].mese<minimo_mese)
            minimo_mese=elenco[i].mese;
        i++;
    }
    i=0;
    minimo_giorno=31
    while(i<numero_lezioni)
    {
        if(elenco[i].mese==minimo_mese && elenco[i].giorno_del_mese<minimo_giorno)
            minimo_giorno==elenco[i].giorno_del_mese;
        i++;
    }
    i=0;
    while(i<numero_lezioni)
    {
        if(elenco[i].mese==minimo_mese && elenco[i].giorno_del_mese==minimo_giorno)
            numero_studenti=elenco[i].numero_studenti;
        i++;
    }
    return(numero_studenti);
}
