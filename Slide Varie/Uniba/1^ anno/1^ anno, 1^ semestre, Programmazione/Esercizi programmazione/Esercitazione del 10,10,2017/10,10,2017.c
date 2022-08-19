#include<stdio.h>
#include<stdio.h>
//Prototipi funzioni
int SommarePotenze(int x,int y);//Funzione che calcola la sommatoria delle potenze di x
int main()
{
    int m,n,sommapot;/*m=numero di cui si vuole calcolare le potenze,
                       n=esponente a cui si vuole arrivare,
                       sommapot=variabile che conterrà la somma delle potenze*/
    n=0;
    m=0;
    printf("\n Inserire il numero di cui si deve calcolare le potenze\n");
    scanf("%d",&m);
    printf("\n Inserire l'esponente della potenza a cui si vuole arrivare\n");
    scanf("%d",&n);
    sommapot=SommarePotenze(m,n);//Richiamo la funzione per la somma delle potenze del numero m
    printf("La somma delle potenze di questo numero e' %d",sommapot);
}

int SommarePotenze(int x,int y)
{
    int i;//indice che ci serve per il ciclo del calcolo della potenza
    int somma=x;//variabile che serve a sommare le potenze
    int pot=x;//variabile che calcola la potenza
    i=2;
        while(i<=y)
            {
                pot=pot*x;
                somma=somma+pot;
                i++;
            }
return(somma);
}
