//Leggere in input una matrice di interi (n righe ed m colonne). Stampare l'indice della riga la cui somma degli elementi è massima.
//Il tipo di dato matrice deve essere rappresentato come un vettore di reali a 2 dimensioni variabili
#include<stdio.h>
#include<stdlib.h>
void CaricareMatrice(int x, int y, int Matrice[x][y]);
void VisualizzareMatrice(int x,int y,int Matrice[x][y]);
void IndiceRigaSommaMassima(int x, int y, int Matrice[x][y]);
int main()
{
    int n=0,m=0,indice=0;
    printf("\n Inserire numero delle righe: \n");
    scanf("%d",&n);
    printf("\n inserire numero delle colonne: \n");
    scanf("%d",&m);
    int Mat[n][m];
    CaricareMatrice(n,m,Mat);
    VisualizzareMatrice(n,m,Mat);
    IndiceRigaSommaMassima(n,m,Mat);

    system("pause");
    return(0);

}

void CaricareMatrice(int x, int y, int Matrice[x][y])
{
    int i,j;
    i=0;
    while(i<x)
        {
            j=0;
            while(j<y)
                {
                    printf("\n Inserire elemento in posizione %d %d \n",i,j);
                    scanf("%d",&Matrice[i][j]);
                    j++;
                }
            i++;
        }
}
void VisualizzareMatrice(int x,int y,int Matrice[x][y])
{
    int i,j;
    i=0;
    while(i<x)
        {
            j=0;
            while(j<y)
                {
                    printf("\n L'elemento in posizione %d %d e' %d",i,j,Matrice[i][j]);
                    j++;
                }
            i++;
        }
}
void IndiceRigaSommaMassima(int x, int y, int Matrice[x][y])
{
    int somma, salva=0, max=0,i,j;
    i=0;
    while(i<x)
        {
            j=0;
           somma=0;
            while(j<y)
                {
                    somma=somma+Matrice[i][j];
                    j++;
                }
          if(somma>max)
            {
                max=somma;
                salva=i;
            }
          i++;
        }
printf("\n Riga Massima %d \n",salva);
}
