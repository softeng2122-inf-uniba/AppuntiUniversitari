#include<stdio.h>
#include<stdlib.h>
//Prototipi funzioni
void CaricareVettore1(int n, int Vettore1[]);//Funzione che carica il primo elenco
void CaricareVettore2(int m, int Vettore2[]);//Funzione che carica il secondo elenco
void VisualizzareVettore1(int n, int Vettore1[]);//Funzione che visualizza gli elemneti del primo elenco
void VisualizzareVettore2(int m, int Vettore2[]);//Funzione che visualizza gli elementi del secondo elenco
int VisualizzareElementiComuni(int n,int m,int Vettore1[],int Vettore2[]);/*Funzione che confronta gli elementi del primo elenco
                                                                            con quelli del secondo e visualizza gli elementi comuni*/
int main()
{
    int n,m;//n=dimensione del primo elenco, m=dimensione del secodno elenco
    n=0;
    m=0;
    printf("\n Inserire la dimensione del primo elenco\n");
    scanf("%d", &n);
    int Elenco1[n];//Elenco numero 1
    printf("\n Inserire la dimensione del secondo elenco\n");
    scanf("%d",&m);
    int Elenco2[m];//Elenco numero 2
    //Richiamo funzioni
    printf("\n\t Inserire primo elenco\t\n");
    CaricareVettore1(n,Elenco1);
    printf("\n\t Inserire secondo elenco\t\n");
    CaricareVettore2(m,Elenco2);
    printf("\n\t Questo è il primo elenco\t\n");
    VisualizzareVettore1(n,Elenco1);
    printf("\n\t Questo è il secondo elenco\t\n");
    VisualizzareVettore2(m, Elenco2);
    printf("\n\t Queti sono gli elementi comuni\t\n");
    VisualizzareElementiComuni(n,m,Elenco1,Elenco2);
    system("pause");
    return(0);
}

//Svolgimento funzioni
void CaricareVettore1(int n, int Vettore1[])//Funzione che carica il secondo elenco
{
    int i;//Indice per la posizione degli elementi dell'elenco
    i=0;
    while(i<n)
    {
        printf("\nInerire l'elemento del primo elenco in posizione %d\n",i);
        scanf("%d",&Vettore1[i]);
        i++;
    }
}

void CaricareVettore2(int m, int Vettore2[])//Funzione che carica il secondo elenco
{
    int j;//Indice per la posizione degli elementi dell'elenco
    j=0;
    while(j<m)
    {
        printf("\nInerire l'elemento del secondo elenco in posizione %d\n",j);
        scanf("%d",&Vettore2[j]);
        j++;
    }
}
void VisualizzareVettore1(int n, int Vettore1[])//Funzione che visualizza gli elemneti del primo elenco
{
    int i;//Indice per la posizione degli elementi dell'elenco
    i=0;
    while(i<n)
    {
        printf("\nL'elemento del primo elenco in posizione %d e' %d\n",i,Vettore1[i]);
        i++;
    }
}

void VisualizzareVettore2(int m, int Vettore2[])//Funzione che visualizza gli elemneti del secondo elenco
{
    int j;//Indice per la posizione degli elementi dell'elenco
    j=0;
    while(j<m)
    {
        printf("\nL'elemento del primo elenco in posizione %d e' %d\n",j,Vettore2[j]);
        j++;
    }
}

int VisualizzareElementiComuni(int n,int m,int Vettore1[],int Vettore2[])/*Funzione che confronta gli elementi del primo elenco
                                                                            con quelli del secondo e visualizza gli elementi comuni*/
{
   int i,j;//i=indice per gli elementi del primo elenco,j=indice per gli elementi del secondo elenco
   i=0;
   printf("\nGli elementi in comune sono:\n");
   while(i<n)//Due cicli annidati per percorre gli elementi del primo elenco e confrontarli con gli elementi del secondo elenco e stampare quelli uguali
   {
       j=0;
       while(j<m)
       {
           if(Vettore1[i]==Vettore2[j])
            printf("\n%d\n",Vettore1[i]);
         j++;
       }
    i++;
   }
}
