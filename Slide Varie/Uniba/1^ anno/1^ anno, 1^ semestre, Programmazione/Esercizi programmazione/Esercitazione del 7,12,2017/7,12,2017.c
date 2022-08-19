/*Generare una matrice quadrata di dimensione n di numeri interi casuali.
Scrivere una funzione che restituisca 1 se la matrice è un quadrato magico e zero altrimenti.
 Una matrice nxn è un quadrato magico se la somma degli elementi su ogni riga, su ogni colonna e sulle due diagonali principali è costante.
*/
#include<stdio.h>
#include<stdlib.h>

void CaricareMatrice(int n,int Mat[n][n]);
int VerificareQuadratoMagico(int n, int Mat[n][n]);
int main()
{
    int n;
    printf("\n Inserire la dimensione della matrice\n");
    scanf("%d",&n);
    int Matrice[n][n];
    printf("\n\t Inserimento elementi degli elementi nella matrici\t\n");
    CaricareMatrice(n,Matrice);
    int QuadratoMagico;
    QuadratoMagico=VerificareQuadratoMagico(n,Matrice);
    if(QuadratoMagico==1)
        printf("\n\tLa matrice è un quadrato magico\t\n");
    else
        printf("\n\tLa matrice non è un quadrato magico\t\n");
}

void CaricareMatrice(int n,int Mat[n][n])
{
    int i,j;
    i=0;
    while(i<n)
    {
        j=0;
        while(j<n)
        {
            printf("\nInserire elemento nella matrice in posizione %d x %d\n",i,j);
            scanf("%d",&Mat[i][j]);
            j++;
        }
        i++;
    }
}
int VerificareQuadratoMagico(int n, int Mat[n][n])
{
    int k,i,j,somma,QuadratoMagico=1;
    k=0;
    i=0;
    j=0;
    while(i<n)
    {
        k=k+Mat[i][j];
        i++;
    }
    i=0;
    while(i<n)
    {
        somma=0;
        j=0;
        while(j<n)
        {
            somma=somma+Mat[i][j];
            j++;
        }
        if(somma!=k)
        QuadratoMagico=0;
        i++;
    }

    j=0;

    while(j<n)
    {
        somma=0;
        i=0;
        while(i<n)
        {
            somma=somma+Mat[i][j];
            i++;
        }
        if(somma!=k)
        QuadratoMagico=0;
        j++;
    }
   i=0;
   j=0;
   somma=0;
   while(i<n)
   {
       somma=somma+Mat[i][j];
       i++;
       j++;
   }
    if(somma!=k)
        QuadratoMagico=0;
return(QuadratoMagico);
}
