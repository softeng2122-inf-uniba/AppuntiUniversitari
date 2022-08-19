#include<stdio.h>
#include<stdlib.h>
int inserirenumero(int num);
void binario(int num);
void base3(int num);
void base4(int num);
void base5(int num);
void base6(int num);
void base7(int num);
void base8(int num);
void base16(int num);
int cambiarenumero(int num);
int main()
{
    int numero=0;
    int scelta;
    printf("\n ogni risultato va letto da destra a sinistra\n");
    do{
        printf("\n\t Selezionare una di queste scelte\n 1-Inserire numero\n 2-Convertire numero in base 2\n 3-Convertire numero in base 3\n 4-Convertire numero in base 4\n 5-Convertire numero in base 5\n 6-Convertire numero in base 6\n 7-Convertire numero in base 7\n 8-Convertire numero in base 8\n 9-Convertire numero in base 16\n 10-Per cambiare numero\n 11-Per terminare\n");
        fflush(stdin);
        scanf("%d",&scelta);
        switch(scelta)
        {
            case 1:
                numero=inserirenumero(numero);
            break;
            case 2:
                binario(numero);
            break;
            case 3:
                base3(numero);
            break;
            case 4:
                base4(numero);
            break;
            case 5:
                base5(numero);
            break;
            case 6:
                base6(numero);
            break;
            case 7:
                base7(numero);
            break;
            case 8:
                base8(numero);
            break;
            case 9:
                base16(numero);
            break;
            case 10:
                numero=cambiarenumero(numero);
            break;
        }
        }while(scelta!=11);

}
void binario(int num)
{
    int Vet[300];
    int i=0;
    while(i<300)
    {
        Vet[i]=0;
        i++;
    }
    i=0;
    int resto;
    int trovato;
    while(num>0)
    {
        resto=num%2;
        Vet[i]=resto;
        i++;
        num=num/2;
    }
    i=300;
    trovato=0;
    int salva;
    while(i>=0 && trovato==0)
    {
        if(Vet[i]==1)
            trovato=1;
        salva=i;
        i--;
    }
    while(i>=0)
    {
        printf("%d",Vet[i]);
        i--;
    }

}
void base3(int num)
{
    int resto;
    while(num>0)
    {
        resto=num%3;
        printf("%d",resto);
        num=num/3;
    }
}
void base4(int num)
{
    int resto;
    while(num>0)
    {
        resto=num%4;
        printf("%d",resto);
        num=num/4;
    }
}
void base5(int num)
{
    int resto;
    while(num>0)
    {
        resto=num%5;
        printf("%d",resto);
        num=num/5;
    }
}
void base6(int num)
{
    int resto;
    while(num>0)
    {
        resto=num%6;
        printf("%d",resto);
        num=num/6;
    }
}
void base7(int num)
{
    int resto;
    while(num>0)
    {
        resto=num%7;
        printf("%d",resto);
        num=num/7;
    }
}
void base8(int num)
{
    int resto;
    while(num>0)
    {
        resto=num%8;
        printf("%d",resto);
        num=num/8;
    }
}
void base16(int num)
{
    int resto;
    while(num>0)
    {
        resto=num%16;
        if(resto<9)
            printf("%d",resto);
        if(resto==10)
            printf("A");
        if(resto==11)
            printf("B");
        if(resto==12)
            printf("C");
        if(resto==13)
            printf("D");
        if(resto==14)
            printf("E");
        if(resto==15)
            printf("F");
        num=num/16;
    }
}
int cambiarenumero(int num)
{
    printf("\n Inserire nuovo numero\n");
    fflush(stdin);
    scanf("%d",&num);
    return(num);
}
int inserirenumero(int num)
{
    printf("\n Inserire numero da convertire\n");
    fflush(stdin);
    scanf("%d",&num);
    return(num);
}
