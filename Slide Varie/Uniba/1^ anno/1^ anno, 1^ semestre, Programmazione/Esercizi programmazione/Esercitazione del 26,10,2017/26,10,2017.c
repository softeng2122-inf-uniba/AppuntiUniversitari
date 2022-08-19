#include<stdio.h>
#include<stdlib.h>
/*Realizzare gli algoritmi delle seguenti operazioni sul tipo di dato vettore:
- Somma degli elementi di un vettore
- Moltiplicazione degli elementi di un vettore
- Cancellazione di un elemento del vettore
- Stampa degli elementi di un vettore
- Rotazione verso destra e sinistra di tutti gli elementi di un vettore
- Spostamento a destra o sinistra di tutti gli elementi di un vettore
- Calcolo della dimensione di un vettore*/
void CaricareVettore(int x,int V[]);// Funzione che carica il vettore
void VisualizzareVettore(int x, int V[]);//Funzione che visualizza il vettore
int SommareElementiVettore(int x,int V[]);//funzione che Somma gli elementi del vettore
int MoltiplicareElementiVettore(int x, int V[]);//Funzione che moltiplica gli elementi del vettore
void CancellareElementoVettore(int x,int V[],int z);//Funzione che cancella un elemento del vettore
void StampareElementiVettore(int x, int V[],int z);//funzione che stampa un elemento del vettore
void RuotareElementiVettore(int x,int V[]);//Funzione che ruota gli elementi del vettore
//void SpostareElementiVettore(int x,int V[]);

int main()
{
    int n=0,somma=0,moltiplicazione=0,pos=0;/*n=dimensione del vettore
                                              somma=variabile che contiene la somma degli elementi del vettore
                                              moltiplicazione=variabile che contiene il prodotto degli eleemtni del vettore
                                              pos=variabile che contiene la posizione di un elemento del vettore inserito dall'utente*/
    printf("\n Inserire dimensione vettore \n");
    scanf("%d",&n);
    int Vettore[n];
    CaricareVettore(n,Vettore);
    somma=SommareElementiVettore(n,Vettore);
    printf("\n La somma deli elementi del vettore è: %d\n",somma);
    moltiplicazione=MoltiplicareElementiVettore(n,Vettore);
    printf("\n Il prodotto degli elementi del vettore è: %d\n",moltiplicazione);
        do{
                printf("\n Inserire la posizione da cancellare \n");
                scanf("%d",&pos);
                if(pos>n)
                    printf("\n Posizione non ammissibile\n");

            } while(pos>n);
    CancellareElementoVettore(n,Vettore,pos);
    n--;
    VisualizzareVettore(n,Vettore);
    do{
                printf("\n Inserire la posizione da stampare \n");
                scanf("%d",&pos);
                if(pos>n)
                    printf("\n Posizione non ammissibile\n");

            } while(pos>n);
    StampareElementiVettore(n,Vettore,pos);
    SpostareElementiVettore(n,Vettore);
    VisualizzareVettore(n,Vettore);
    /*SpostareElementiVettore(n,Vettore);
    VisualizzareVettore(n,Vettore);*/
}
void CaricareVettore(int x,int V[])
{
    int i;
	i = 0;
	while (i < x)
	{
		printf("\n Inserire elemento del vettore:\n");
		scanf("%d", &V[i]);
		i++;

	}
}

void VisualizzareVettore(int x, int V[])
{
    int i;
	i=0;
	printf("\n Elenco elementi nel vettore:\n");
	while (i<x)
	{
		printf(" %d\t",V[i]);
		i=i+1;
	}
}

int SommareElementiVettore(int x,int V[])
{
    int i=0,s=0;
    while (i<x)
        {
            s=s+V[i];
            i++;
        }
    return(s);
}

int MoltiplicareElementiVettore(int x, int V[])
{
    int i=0,p=1;
    while(i<x)
        {
            p=p*V[i];
            i++;
        }
    return(p);
}

void CancellareElementoVettore(int x,int V[],int z)
{
    int i;
    i =z;
    while (i<(x-1))
        {
            V[i] = V[i + 1];
            i++;
        }
}

void StampareElementiVettore(int x, int V[], int z)
{
    int i=z;
    printf("\n L'elemento in posizione %d e' %d\n",i,V[i]);
}

void SpostareElementiVettore(int x,int V[])
{
    int i=0, j=x,z=0;
    while(i<j)
        {
            z=V[i];
            V[i]=V[j];
            V[j]=z;
            j--;
            x++;
        }
}


