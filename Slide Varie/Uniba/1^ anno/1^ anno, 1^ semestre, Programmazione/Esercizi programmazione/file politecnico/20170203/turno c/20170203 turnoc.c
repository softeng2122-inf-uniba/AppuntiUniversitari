#include<stdio.h>
#include<stdlib.h>
FILE *plim;
FILE *pm;
int nmi;
int nl;
struct limiti{
    float min;
    float max;
};
struct limiti lmt[10];
struct misure{
    float val1;
    float val2;
    float val3;
    float val4;
    float val5;
    float val6;
    float val7;
    float val8;
    float val9;
    float val10;
};
struct misure ms[300];
 void caricarefilelimiti();
 void caricarefilemisure();
 void analizzafile();
int main()
{
    /*plim=fopen("limiti.txt","w");

    if (plim==NULL)
        printf("\n impossible aprire il file limiti\n");
    else
        caricarefilelimiti();*/
    /*pm=fopen("misure.txt","w");
    if(pm==NULL)
        printf("\n immpossibile aprire il file misure\n");
    else
        caricarefilemisure();
    fclose(plim);
    fclose(pm);*/
    plim=fopen("limiti.txt","r");
    pm=fopen("misure.txt","r");
    analizzafile();
    fclose(plim);
    fclose(pm);

}
 void caricarefilelimiti()
 {
     printf("\n caricare limiti\n");
     float min;
     float max;
     int i=0;
     int sensore=1;
     while (i<10)
     {
         printf("\n inserire valore minimo del sensore numero %d\n",sensore);
         scanf("%f", &min);
         printf("\n inserire valore massimo del sensore numero %d\n",sensore);
         scanf("%f", &max);
         fprintf(plim,"%f %f\n",min,max);
         i++;
         sensore++;
     }
 }
 void caricarefilemisure()
 {
     printf("\n caricare valori\n");
     float v1,v2,v3,v4,v5,v6,v7,v8,v9,v10;
     int scelta=1;
     while(scelta==1)
     {
         printf("\n Inserire il valore numero 1\n");
         scanf("%f",&v1);
         printf("\n Inserire il valore numero 2\n");
         scanf("%f",&v2);
         printf("\n Inserire il valore numero 3\n");
         scanf("%f",&v3);
         printf("\n Inserire il valore numero 4\n");
         scanf("%f",&v4);
         printf("\n Inserire il valore numero 5\n");
         scanf("%f",&v5);
         printf("\n Inserire il valore numero 6\n");
         scanf("%f",&v6);
         printf("\n Inserire il valore numero 7\n");
         scanf("%f",&v7);
         printf("\n Inserire il valore numero 8\n");
         scanf("%f",&v8);
         printf("\n Inserire il valore numero 9\n");
         scanf("%f",&v9);
         printf("\n Inserire il valore numero 10\n");
         scanf("%f",&v10);
         printf("\n inserire 1 per continuare e 2 per terminare\n");
         scanf("%d",&scelta);
         fprintf(pm,"%f %f %f %f %f %f %f %f %f %f\n",v1,v2,v3,v4,v5,v6,v7,v8,v9,v10);
     }

 }
 void analizzafile()
 {
     nl=0;
     while(fscanf(plim,"%f %f",&lmt[nl].min,&lmt[nl].max)!=EOF)
        nl++;
    nmi=0;
    while(fscanf(pm,"%f %f %f %f %f %f %f %f %f %f",&ms[nmi].val1,&ms[nmi].val2,&ms[nmi].val3,&ms[nmi].val4,&ms[nmi].val5,&ms[nmi].val6,&ms[nmi].val7,&ms[nmi].val8,&ms[nmi].val9,&ms[nmi].val10)!=EOF)
        nmi++;
    int L;
    printf("\n Inserire il limite di errori che si possono avere contemporaneamente\n");
    scanf("%d",&L);
    float media1[300];
    float media2[300];
    float media3[300];
    float media4[300];
    float media5[300];
    float media6[300];
    float media7[300];
    float media8[300];
    float media9[300];
    float media10[300];
    int i, j;
    i=0;
    float somma=0;
    while(i<nmi)
    {
        j=i;
        while((j<i+5)&&(j<nmi))
        {
            somma=somma+ms[j].val1;
            j++;
        }
        somma=somma/5;
        media1[i]=somma;
        i++;
    }
    i=0;
    somma=0;
    while(i<nmi)
    {
        j=i;
        while((j<i+5)&&(j<nmi))
        {
            somma=somma+ms[j].val2;
            j++;
        }
        somma=somma/5;
        media2[i]=somma;
        i++;
    }
    i=0;
    somma=0;
    while(i<nmi)
    {
        j=i;
        while((j<i+5)&&(j<nmi))
        {
            somma=somma+ms[j].val3;
            j++;
        }
        somma=somma/5;
        media3[i]=somma;
        i++;
    }
    i=0;
    somma=0;
    while(i<nmi)
    {
        j=i;
        while((j<i+5)&&(j<nmi))
        {
            somma=somma+ms[j].val4;
            j++;
        }
        somma=somma/5;
        media4[i]=somma;
        i++;
    }
    i=0;
    somma=0;
    while(i<nmi)
    {
        j=i;
        while((j<i+5)&&(j<nmi))
        {
            somma=somma+ms[j].val5;
            j++;
        }
        somma=somma/5;
        media5[i]=somma;
        i++;
    }
    i=0;
    somma=0;
    while(i<nmi)
    {
        j=i;
        while((j<i+5)&&(j<nmi))
        {
            somma=somma+ms[j].val6;
            j++;
        }
        somma=somma/5;
        media6[i]=somma;
        i++;
    }
    i=0;
    somma=0;
    while(i<nmi)
    {
        j=i;
        while((j<i+5)&&(j<nmi))
        {
            somma=somma+ms[j].val7;
            j++;
        }
        somma=somma/5;
        media7[i]=somma;
        i++;
    }
    i=0;
    somma=0;
    while(i<nmi)
    {
        j=i;
        while((j<i+5)&&(j<nmi))
        {
            somma=somma+ms[j].val8;
            j++;
        }
        somma=somma/5;
        media8[i]=somma;
        i++;
    }
    i=0;
    somma=0;
    while(i<nmi)
    {
        j=i;
        while((j<i+5)&&(j<nmi))
        {
            somma=somma+ms[j].val9;
            j++;
        }
        somma=somma/5;
        media9[i]=somma;
        i++;
    }
    i=0;
    somma=0;
    while(i<nmi)
    {
        j=i;
        while((j<i+5)&&(j<nmi))
        {
            somma=somma+ms[j].val10;
            j++;
        }
        somma=somma/5;
        media10[i]=somma;
        i++;
    }
    int cont=0;
    i=0;
    int xyz=0;
    while(i<nmi/5)
    {
        cont=0;
        if((media1[i]<lmt[0].min)||(media1[i]>lmt[0].max))
            cont++;
        if((media2[i]<lmt[1].min)||(media2[i]>lmt[1].max))
            cont++;
         if((media3[i]<lmt[2].min)||(media3[i]>lmt[2].max))
            cont++;
         if((media4[i]<lmt[3].min)||(media4[i]>lmt[3].max))
            cont++;
         if((media5[i]<lmt[4].min)||(media5[i]>lmt[4].max))
            cont++;
         if((media6[i]<lmt[5].min)||(media6[i]>lmt[5].max))
            cont++;
         if((media7[i]<lmt[6].min)||(media7[i]>lmt[6].max))
            cont++;
         if((media8[i]<lmt[7].min)||(media8[i]>lmt[7].max))
            cont++;
         if((media9[i]<lmt[8].min)||(media9[i]>lmt[8].max))
            cont++;
         if((media10[i]<lmt[9].min)||(media10[i]>lmt[9].max))
            cont++;
        xyz=i+5;
        if(cont>L)
        printf("\n Si è verificata l'anomalia nella riga %d",xyz);
        i++;

    }

 }
