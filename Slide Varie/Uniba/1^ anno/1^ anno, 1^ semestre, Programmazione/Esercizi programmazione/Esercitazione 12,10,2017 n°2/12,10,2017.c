#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("\n Inserire due numeri per vedere se il primo numero è divisibile per il secondo\n");
    int n,k,salva;
    k=0;
    n=0;
    printf("\n Inserire il primo numero \n");
    scanf("%d",&k);
    salva=k;
    printf("\n Inserire il secondo numero \n");
    scanf("%d",&n);
    while(k>0)
        {
          k=k-n;
        }
    if(k==0)
        printf("\nIl numero %d e' divisibile per %d\n",salva,n);
      else
        printf("\nIl numero %d non e' divisibile per %d\n",salva,n);
}
