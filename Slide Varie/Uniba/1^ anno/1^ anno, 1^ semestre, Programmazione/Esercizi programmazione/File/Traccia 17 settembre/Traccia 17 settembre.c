#include<stdio.h>
#include<stdlib.h>
int trovatarget(FILE *pt, int col, float target);
FILE *pt;
int nc;
int nr;
void caricarefile();
int main()
{
    //pt=fopen("Tabelle.txt","w");
    //caricarefile();
   // fclose(pt);
   int col;
    float target;
    printf("Inserisci il numero della colonna\n");
    scanf("%d",&col);
    printf("\n Inserire il terget\n");
    scanf("%f",&target);
    pt=fopen("Tabelle.txt","r");
    int risultato;
    risultato=trovatarget(pt, col,target);
    if(risultato==-1)
        printf("\n Il target non è presente nel file\n");
    else
       printf("\n Il target è presente nella colonna %d e in corrispondenza della riga %d",col,risultato);
}
void caricarefile()
{
    printf("\n Inserire numero colonne\n");
    scanf("%d",&nc);
    printf("\n Inserire numero righe\n");
    scanf("%d",&nr);
    int i,j;
    float elemento;
    i=0;
    while(i<nr)
    {
        j=0;
        while(j<nc)
        {
            printf("\n inserire elemento\n");
            scanf("%f",&elemento);
            fprintf(pt,"%f  ",elemento);
            j++;
        }
        fprintf(pt,"\n");
        i++;
    }
}
int trovatarget(FILE *pt, int col, float target)
{
    float M[nr][nc];
    int i,j;
    printf("\n inserisci numero colonne della matrice\n");
    scanf("%d",&nc);
    printf("\n inserisci numero righe della matrici\n");
    scanf("%d",&nr);
    while(!feof(pt))
    {
        i=0;
        while(i<nr)
        {
            j=0;
            while(j<nc)
            {
                    fscanf(pt,"%f",&M[i][j]);
                    j++;
            }
            i++;
        }
    }
    i=0;
    while(i<nr)
    {
        j=0;
        while(j<nc)
        {
            printf("\n Elemento in posizione %dx%d è %f",i,j,M[i][j]);
            j++;
        }
        i++;
    }
    i=0;
    int trovato=0;
    int salva;
    while(i<nr)
    {
        if(M[i][col]==target)
        {
            salva=i;
            trovato=1;
        }
    i++;
    }
    if (trovato==0)
        salva=-1;
    return(salva);
}
