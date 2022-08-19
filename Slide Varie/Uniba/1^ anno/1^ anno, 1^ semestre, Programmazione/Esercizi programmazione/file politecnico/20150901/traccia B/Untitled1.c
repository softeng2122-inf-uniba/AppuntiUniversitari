#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *paf;
void caricarefilestudenti();
struct voti{
    int voto1;
    int voto2;
    int voto3;
    int voto4;
    int voto5;
    int voto6;
    int voto7;
    int voto8;
    int voto9;
    int voto10;
};
struct voti votstu[100];
void soglia();
int main()
{
    paf=fopen("studenti.dat","w");
    if(paf==NULL)
        printf("\n il file non può essere aperto\n");
    else
        caricarefilestudenti();
    fclose(paf);
    paf=fopen("studenti.dat","r");
    if(paf==NULL)
        printf("\n Il file non può essere aperto\n");
    else
        soglia();

}
void caricarefilestudenti()
{
    int scelta=1;
    int v1,v2,v3,v4,v5,v6,v7,v8,v9,v10;
    while(scelta==1)
    {
        printf("\n Inserire voto numero 1 \n");
        scanf("%d",&v1);
        printf("\n Inserire voto numero 2 \n");
        scanf("%d",&v2);
        printf("\n Inserire voto numero 3\n");
        scanf("%d",&v3);
        printf("\n Inserire voto numero 4\n");
        scanf("%d",&v4);
        printf("\n Inserire voto numero 5\n");
        scanf("%d",&v5);
        printf("\n Inserire voto numero 6\n");
        scanf("%d",&v6);
        printf("\n Inserire voto numero 7\n");
        scanf("%d",&v7);
        printf("\n Inserire voto numero 8\n");
        scanf("%d",&v8);
        printf("\n Inserire voto numero 9\n");
        scanf("%d",&v9);
        printf("\n Inserire voto numero 10\n");
        scanf("%d",&v10);
        printf("\n inserire 1 per continuare 2 per terminare\n");
        scanf("%d",&scelta);
        fprintf(paf,"%d %d %d %d %d %d %d %d %d %d\n",v1,v2,v3,v4,v5,v6,v7,v8,v9,v10);

    }
}
void soglia()
{
    int so;
    printf("\n inserire soglia\n");
    scanf("%d",so);
    int q=0;
    while(fscanf(paf,"%d %d %d %d %d %d %d %d %d %d ",&votstu[q].voto1,&votstu[q].voto2,&votstu[q].voto3,&votstu[q].voto4,&votstu[q].voto5,&votstu[q].voto6,&votstu[q].voto7,&votstu[q].voto8,&votstu[q].voto9,&votstu[q].voto10)!=EOF)
        q++;
    int i=0;
    int massimo=0;
    int cont=0;
    while(i<q)
    {
        if(votstu[i].voto1==so)
            cont++;
        if(votstu[i].voto2==so)
            cont++;
        if(votstu[i].voto3==so)
            cont++;
        if(votstu[i].voto4==so)
            cont++;
        if(votstu[i].voto5==so)
            cont++;
        if(votstu[i].voto6==so)
            cont++;
        if(votstu[i].voto7==so)
            cont++;
        if(votstu[i].voto8==so)
            cont++;
        if(votstu[i].voto9==so)
            cont++;
        if(votstu[i].voto10==so)
            cont++;
        if(cont>=massimo)
            {
                massimo=cont;
                printf("\n %d : questo e' uno studente con un numero maggiore ",i);
            }
        i++;
    }
    if(cont==0)
        printf("nessun studente ha almeno un voto uguale alla soglia");
}
