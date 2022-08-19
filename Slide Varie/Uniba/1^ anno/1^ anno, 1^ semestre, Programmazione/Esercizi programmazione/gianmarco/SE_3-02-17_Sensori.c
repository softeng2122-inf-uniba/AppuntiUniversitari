#include <stdio.h>
#include <stdlib.h>
#include <math.h>



struct valori{
    float v[10];
};
struct limiti{
    float l1;
    float l2;
};

void calcolamedia(struct valori v[100],float ms[10],int r);



int main(int argc,char *argv[])
{
    int nrow,nlim;
    float media;
    int i,j;
    struct valori v[100];
    struct limiti l[10];

    if(argc!=2){
        printf("Errore parametri linea!!!\n");
        return -1;
    }
    FILE *fp;
    fp=fopen("misure.txt","r");
    if(fp==NULL){
        printf("Errore file!!!\n");
        return -2;
    }
    nrow=0;
    while(fscanf(fp,"%f %f %f %f %f %f %f %f %f %f",&v[nrow].v[0],&v[nrow].v[1],&v[nrow].v[2],&v[nrow].v[3],&v[nrow].v[4],&v[nrow].v[5],&v[nrow].v[6],&v[nrow].v[7],&v[nrow].v[8],&v[nrow].v[9])!=EOF){
        nrow++;
    }
    printf("\nMisure:");
    //visualizzo valori
    for(i=0;i<nrow;i++){
        printf("\n%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f",v[i].v[0],v[i].v[1],v[i].v[2],v[i].v[3],v[i].v[4],v[i].v[5],v[i].v[6],v[i].v[7],v[i].v[8],v[i].v[9]);
    }
    fclose(fp);

    FILE *fp1;
    fp1=fopen("limiti.txt","r");
    if(fp==NULL){
        printf("Errore file!!!\n");
        return -1;
    }
    nlim=0;
    while(fscanf(fp1,"%f %f",&l[nlim].l1,&l[nlim].l2)!=EOF){
        nlim++;
    }
    printf("\nLimiti:");
    //visualizzo limiti
    for(i=0;i<nlim;i++){
        printf("\n%.2f %.2f",l[i].l1,l[i].l2);
    }

    int na,L=atoi(argv[1]);
    float ms[10];
    for (i=4;i<nrow;i++){
        na=0;
        calcolamedia(v,ms,i);
        for (j=0;j<10;j++)
            if(ms[j]<l[j].l1 || ms[j]>l[j].l2)
                na++;
        if (na>L)
            printf("\nAnomalia rilevata alla riga %d",i+1);
    }
    return 0;
}


void calcolamedia(struct valori v[100],float ms[10],int r){
    int i,j;
    for (i=0;i<10;i++)
        ms[i]=0;
    j=0;
    for (i=0;i<5;i++)
        for (j=0;j<10;j++)
            ms[j]+=v[r-i].v[j];

    for (i=0;i<10;i++)
        ms[i]=ms[i]/5;
}
