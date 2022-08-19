#include<stdio.h>
#include<stdlib.h>


struct Date{
    int giorno;
    int mese;
    int anno;
};
struct conteggio
{
    int cont;
};
struct conteggio conta[100];
struct Date data[100];
FILE *pd;
int nd;
void leggeredata();
void controllodata();
void visualizza();
int main()
{
    pd=fopen("Date.txt","w");
    leggeredata();
    fclose(pd);
    pd=fopen("Date.txt","r");
    controllodata();
    fclose(pd);
    visualizza();
}
void leggeredata()
{
    int g, m, a;
    int scelta=1;
    while(scelta==1)
    {
         printf("\n Inserire giorno\n");
         scanf("%d",&g);
         printf("\n Inserire mese\n");
         scanf("%d",&m);
         printf("\n Inserire anno\n");
         scanf("%d",&a);
         printf("\n inserire 1 per continuare, 2 per terminare\n");
         scanf("%d",&scelta);
         fprintf(pd,"%d %d %d\n",g,m,a);
    }

    }

void controllodata()
{
    int salva, salva2;
    nd=0;
    while(fscanf(pd,"%d %d %d",&data[nd].giorno,&data[nd].mese,&data[nd].anno)!=EOF)
        nd++;

    int contr=1;
    int i=0;
    while(i<nd)
    {

        if((data[i].giorno<1)||(data[i].giorno>31))
            contr=-1;
        if((data[i].mese<1)||(data[i].mese>12))
            contr=-2;
        if(data[i].anno<0)
            contr=-3;
        if((data[i].giorno==30)&&(data[i].mese==2))
            contr=-4;
        if((data[i].giorno==31)&&(data[i].mese==2))
            contr=-4;
        if((data[i].giorno==31)&&(data[i].mese==4))
            contr=-4;
        if((data[i].giorno==31)&&(data[i].mese==6))
            contr=-4;
        if((data[i].giorno==31)&&(data[i].mese==9))
            contr=-4;
        if((data[i].giorno==31)&&(data[i].mese==11))
            contr=-4;
        if((data[i].giorno==29)&&(data[i].mese=2)&&(((data[i].anno%4)!=0)||(((data[i].anno%100)!=0)&&((data[i].anno%400)!=0))))
            contr=0;
        salva=i;
        if((contr==-1)||(contr==-2)||(contr==-3)||(contr==-4)||(contr==0))
            printf("\n La data %d %d %d presenta un errore in quanto restituisce un controllo pari a %d",data[i].giorno,data[i].mese,data[i].anno,contr);
        else
        {
             printf("\n La data %d %d %d non presenta errori",data[i].giorno,data[i].mese,data[i].anno);
             contr=data[i].giorno;
             while(salva>0)
             {
                 salva--;
                if(data[salva].mese==1)
                    contr=contr+31;
                if((data[salva].mese==2)&&(((data[i].anno%4)==0)||(((data[i].anno%100)==0)&&((data[i].anno%400)==0))))
                    contr=contr+29;
                if((data[salva].mese==2)&&(((data[i].anno%4)!=0)||(((data[i].anno%100)!=0)&&((data[i].anno%400)!=0))))
                    contr=contr+28;
                if(data[salva].mese==3)
                    contr=contr+31;
                if(data[salva].mese==4)
                    contr=contr+30;
                if(data[salva].mese==5)
                    contr=contr+31;
                if(data[salva].mese==6)
                    contr=contr+30;
                if(data[salva].mese==7)
                    contr=contr+31;
                if(data[salva].mese==8)
                    contr=contr+31;
                if(data[salva].mese==9)
                    contr=contr+30;
                if(data[salva].mese==10)
                    contr=contr+31;
                if(data[salva].mese==11)
                    contr=contr+30;
             }
             printf("\n Da questa data %d %d %d sono trascorsi %d giorni dall'inizio dell'anno",data[i].giorno,data[i].mese,data[i].anno,contr);
        }
        conta[i].cont=contr;
        i++;
    }
}
void visualizza()
{
 int i=0;
 while(i<nd)
 {
     printf("%d/%d/%d %d ",data[i].giorno,data[i].mese,data[i].anno, conta[i].cont);
     i++;
 }
}
