#include<stdio.h>
#include<stdlib.h>
//Eserciio1
int main()
{
    int n,k,somma,i,mult;/*n=numero che indica i multipli di k,
                    k=numero di cui bisogna calcolare i multipli
                    somma=somma i multipli di k
                    i=indice per calcolare i multipli*/
    k=0;
    n=0;
    i=1;
    mult=0;
    printf("\n Inserire il numero di cui si vuole calcolare i multipli \n");
    scanf("%d",&k);
    printf("\n Inserire quanti multipli si vogliono calcolare \n");
    scanf("%d",&n);
    printf("\n I multipli sono: \n");
    while(i<=n)
            {
               mult=k*i;
               printf("\n %d \n",mult);
               i++;
            }
}

