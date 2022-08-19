#include<stdio.h>
#include<stdlib.h>

FILE *paf;
#define N 10
struct Coordinate{
    int x1;
    int x2;
    int y1;
    int y2;
};
struct Coordinate xyz[100];
int nxyz;
void crearefile();
int elaborazione();
int erroreformato();
int main()
{
    int sovr;
    paf=fopen("Coordinate.txt","w");
    if(paf!=NULL)
        crearefile();
    else
        printf("\n Il file non può essere aperto\n");
    fclose(paf);
    paf=fopen("Coordinate.txt","r");
    sovr=elaborazione();
    if(sovr==0)
        printf("\n Non è presente nessuna sovrapposizione\n");
    else
        printf("\n I rettangoli hanno almeno una sovrapposizione\n");
    int err;
    err=erroreformato();
    if(err!=0)
        printf("\n Errore nel formato file\n");

}
 void crearefile()
 {
     int x1;
     int y1;
     int x2;
     int y2;
     int ff=1;
     while(ff==1)
     {
        printf("\n Inserire le coordinate del punto in alto a sinistra\n");
        fflush(stdin);
        scanf("%d",&x1);
        printf("\n Inserire le coordinate del punto in basso a sinistra\n");
        fflush(stdin);
        scanf("%d",&y1);
        printf("\n Inserire le coordinate del punto in alto a destra\n");
        fflush(stdin);
        scanf("%d",&x2);
        printf("\n Inserire le coordinate del punto in basso a destra\n");
        fflush(stdin);
        scanf("%d",&y2);
        fprintf(paf,"%d %d %d %d\n",x1,y1,x2,y2);
        printf("\n inserire 1 per continuare 2 per terminare\n ");
     }


 }
int elaborazione()
{
    nxyz=0;
    while(fscanf(paf,"%d %d %d %d",&xyz[nxyz].x1,&xyz[nxyz].y1,&xyz[nxyz].x2,&xyz[nxyz].y2)!=EOF)
        nxyz++;
    int sovrapposizione=0;
    int i;
    i=0;
    while(i<nxyz)
    {
        if((xyz[i].x1!=xyz[i+1].x1)&&(xyz[i].y1!=xyz[i+1].y1)&&(xyz[i].x2!=xyz[i+1].x2)&&(xyz[i].y2!=xyz[i+1].y2))
            sovrapposizione=0;
        else
            sovrapposizione=1;
        i++;
    }
    return(sovrapposizione);

}
int erroreformato()
{
    int errore;
    int i=0;
    while(i<nxyz)
    {
        if((xyz[i].x1<0)&&(xyz[i].x1>N)&&(xyz[i].y1<0)&&(xyz[i].y1>N)&&(xyz[i].x2<0)&&(xyz[i].x2>N)&&(xyz[i].y2<0)&&(xyz[i].y2>N))
            errore=0;
        else
            errore=1;
        i++;
    }
    return(errore);
}
