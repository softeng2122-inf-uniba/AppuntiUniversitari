#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *paf;
int numero_righe;
const char luce='KW';
const char gas='m^3';

struct tipo{
    char tipo_consumo;
    float n1;
    float n2;
    float n3;
    float n4;
}file_consumo[100];

void caricare_file();
void visualizzare_file();
void verificare_consumo_crescente();
void verificare_uguaglianza();
void visualizzare_informazioni();

int main()
{

    return 0;
}

void caricare_file()
{
    int scelta;
    float n1,n2,n3,n4;
    char tipo_consumo;
    paf=fopen("consumi.txt","w");
    scelta=1;
    while(scelta==1)
    {
        printf("\n Inserire il tipo di consumo: (L per luce, G per gas, A per acqua)\n");
        scanf("%c",tipo_consumo);
        printf("\n Inserire il valore di n1\n");
        scanf("%f",&n1);
        printf("\n Inserire il valore di n2\n");
        scanf("%f",&n2);
        printf("\n Inserire il valore di n3\n");
        scanf("%f",&n3);
        printf("\n Inserire il valore di n4\n");
        scanf("%f",&n4);
        fscanf(paf,"%c %f %f %f %f\n",tipo_consumo,n1,n2,n3,n4);
        do{
            printf("\n premere 1 per continuare e 2 per terminare\n");
            scanf("%d",&scelta);
        }while(scelta!=1 && scelta!=2);
    }
    fclose(paf);
}
void visualizzare_file();
void verificare_consumo_crescente();
void verificare_uguaglianza();
void visualizzare_informazioni();
