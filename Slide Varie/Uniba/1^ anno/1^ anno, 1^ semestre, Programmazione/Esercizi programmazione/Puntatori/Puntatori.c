#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a,b;
	int *punta;
	int *puntb;
	a=18;
	b=17;
	punta=&a;
	puntb=&b;
	printf("valore a %d\n",a);
	printf("valore b %d\n",b);
	printf("valore puntatore a %d\n",*punta);
	printf("valore puntatore b %d\n",*puntb);
	printf("\n scambio\n");
	int x;
	x=a;
	a=b;
	b=x;
	printf("%d %d scambio senza puntatori\n",a,b);
	punta=&a;
	puntb=&b;
	printf("%d %d valore delle variabili con i puntatori\n",*punta,*puntb);
    x=*punta;
    *punta=*puntb;
    *puntb=x;
    printf("%d %d scambio con i puntatori\n",*punta,*puntb);
}
