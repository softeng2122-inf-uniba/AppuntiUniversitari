#include <stdio.h>
#include <stdlib.h>

FILE *paf;
struct struttura{
    int riga;
    int colonna;
    float valore;
};
void gestionefile();

void main()
{
    gestionefile();
}

void gestionefile()
{
    char nomefile[20];
    int i,j;
    int dimensionematrice;
    printf("\n Inserire il nome del file comprensivo di estensione\n");
    scanf("%s",nomefile);
    printf("\n Inserire dimensione matrice\n");
    scanf("%d", &dimensionematrice);
    float mat[dimensionematrice][dimensionematrice];
    while(i<dimensionematrice)
    {
        j=0;
        while(j<dimensionematrice)
        {
            mat[i][j]=0.00;
            j++;
        }
        i++;
    }
    struct struttura matrix[dimensionematrice];

}
