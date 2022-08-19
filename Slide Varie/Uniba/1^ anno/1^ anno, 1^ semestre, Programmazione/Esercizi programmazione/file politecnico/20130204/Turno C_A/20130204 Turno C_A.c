#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *paf;
struct Libri{
    char isbn[18];
    char av;
    char data [11];
    int nmrcp;
    float prezzo;
};
struct Libri lbr[100];
int numl;
void caricarefile();
void magazzino_vendute();
void copievendute();
void copiemassime();
void copieminime();
int main()
{
    paf=fopen("libri.txt","w");
    if(paf==NULL)
        printf("\n Impossibile aprire il file\n");
    else
        caricarefile();
    fclose(paf);
    paf=fopen("libri.txt","r");
    if(paf==NULL)
        printf("\n Impossibile aprire file\n");
    else
        magazzino_vendute();
    fclose(paf);
    copievendute();
    copiemassime();
    copieminime();
}
void caricarefile()
{
    int scelta=1;
    char isbn[18];
    char acquisto_vendita;
    char data[11];
    int ncopie;
    float przun;
    while(scelta==1)
    {
        printf("\n Inserisci ISBN\n");
        fflush(stdin);
        scanf("%s",isbn);
        printf("\n Inserire A per acquisto e V per vendita");
        fflush(stdin);
        scanf("%c",&acquisto_vendita);
        printf("\n Inserire data nel tipo GG/MM/AAAA\n");
        fflush(stdin);
        scanf("%s", data);
        printf("\n inserire il numero di copie\n");
        fflush(stdin);
        scanf("%d",&ncopie);
        printf("\n Inserire prezzo\n");
        fflush(stdin);
        scanf("%f",&przun);
        printf("\n Inserire 1 per continuare e 2 per terminare\n");
        fflush(stdin);
        scanf("%d",&scelta);
        fprintf(paf,"%s %c %s %d %f",isbn,acquisto_vendita,data,ncopie,przun);
    }
}
void magazzino_vendute()
{
    numl=0;
    while(fscanf(paf,"%s %c %s %d %f",lbr[numl].isbn,&lbr[numl].av,lbr[numl].data,&lbr[numl].nmrcp,&lbr[numl].prezzo)!=EOF)
        numl++;
    int i=0;
    int j;
    int mag=0;
    while(i<numl)
    {
        j=0;
        while(j<numl)
        {
            if((strcmp(lbr[i].isbn,lbr[j].isbn)==0)&&(lbr[i].av=='A')&&(lbr[j].av=='A'))
                mag=mag+lbr[j].nmrcp;
            j++;
        }
        printf("\n Il numero di copie in magazzino sono %d",mag);
        i++;
    }
    int ven=0;
    i=0;
    while(i<numl)
    {
        j=0;
        while(j<numl)
        {
            if((strcmp(lbr[i].isbn,lbr[j].isbn)==0)&&(lbr[i].av=='U')&&(lbr[j].av=='U'))
                ven=ven+lbr[j].nmrcp;
            j++;
        }
        printf("\n il numero di copie vendute sono %d",ven);
        i++;
    }


}
void copievendute()
{
    int i=0;
    int numcop1=0;
    int numcop2=0;
    int numcop3=0;
    int numcop4=0;
    int gg,mm,aa;
    while(i<numl)
    {
        sscanf(lbr[i].data,"%2d/%2d/%4d",&gg,&mm,&aa);
        if((mm==9)&&(lbr[i].av='V'))
            numcop1=numcop1+lbr[i].nmrcp;
        if((mm==10)&&(lbr[i].av='V'))
            numcop2=numcop2+lbr[i].nmrcp;
        if((mm==11)&&(lbr[i].av='V'))
            numcop3=numcop3+lbr[i].nmrcp;
        if((mm==12)&&(lbr[i].av='V'))
            numcop4=numcop4+lbr[i].nmrcp;
        i++;
    }
    printf("\n Il numero di copie vendute a settembre è %d",numcop1);
    printf("\n Il numero di copie vendute a ottobre è %d",numcop2);
    printf("\n Il numero di copie vendute a novembre è %d",numcop3);
    printf("\n Il numero di copie vendute a dicembre è %d",numcop4);
}
void copiemassime()
{
    int i,j,ncop,max;
    char salva[18];
    i=0;
    ncop=0;
    max=0;
    ncop=0;
    while(i<numl)
    {
        j=0;
        while(j<numl)
        {
            if((strcmp(lbr[i].isbn,lbr[j].isbn)==0)&&(lbr[i].av=='V')&&(lbr[j].av=='V'))
                ncop=ncop+lbr[i].nmrcp;
            j++;
        }
        if(max<ncop)
        {
             max=ncop;
             strcpy(salva,lbr[i].isbn);
        }
        i++;
    }
    printf("\n %s ha venduto il numero massimo di copie",salva);

}
void copieminime()
{
    int i,j,ncop,min;
    char salva[18];
    i=0;
    int trovato=1;
    while((i<numl)&&(trovato==1))
    {
        if(lbr[i].av=='V')
        {
            min=lbr[i].nmrcp;
            trovato=0;
        }
        i++;
    }
    ncop=0;
    ncop=0;
    i=0;
    while(i<numl)
    {
        j=0;
        while(j<numl)
        {
            if((strcmp(lbr[i].isbn,lbr[j].isbn)==0)&&(lbr[i].av=='V')&&(lbr[j].av=='V'))
                ncop=ncop+lbr[i].nmrcp;
            j++;
        }
        if(min>ncop)
        {
             min=ncop;
             strcpy(salva,lbr[i].isbn);
        }
        i++;
    }
    printf("\n %s ha venduto il numero minimo di copie",salva);

}
