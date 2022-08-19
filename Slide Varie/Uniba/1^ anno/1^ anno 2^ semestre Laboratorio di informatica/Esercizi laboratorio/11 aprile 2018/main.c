#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

FILE *paf;
char nome_citta[20];
int dimensione_file;
struct file{
    char nome[20];
    int numero_secondi;
    int numero_scatti;
};
struct file chiamate[100];

int totale_secondi_chiamata();
int totale_scatti(int x);

int main()
{
    int tot_secondi;
    int numero_scatti;
    printf("    n Inserire il nome della citta' di cui si vuole sapere la durata più lunga\n");
    scanf("%s",nome_citta);
    tot_secondi=totale_scatti();
    numero_scatti=totale_scatti(tot_secondi);
    printf("\n La chiamata piu' lunga e' stata di %d e il numero di scatti e' stato di %d", tot_secondi,numero_scatti);
    return 0;
}

int totale_secondi_chiamata()
{

}
int totale_scatti(int x);
