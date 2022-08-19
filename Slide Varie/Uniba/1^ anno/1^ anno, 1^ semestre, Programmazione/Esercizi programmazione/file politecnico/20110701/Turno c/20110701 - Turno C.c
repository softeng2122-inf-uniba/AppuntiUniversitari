#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct file{
    char merce[20];
    char data[11];
    float peso;//espresso in kili
} merce[150];

FILE *puntatore_a_file_merce;
int elementi_nel_file;

void caricare_file();
float totale_quintali_merce();
char ultimo_carico();
float gudagno();

int main(){



    system("pause");
    return 0;
}
void caricare_file()
{
   int scelta;
   char data[11], merce[20];
   float peso;
   puntatore_a_file_merce=fopen("merce.txt","w");
   scelta=1;
   while(scelta==1)
   {
       printf("\n inserire il nome della merce\n");
       scanf("%c",merce);
       printf("\n inserire la data dell'operazione nel formato gg-mm-aaaa\n");
       scanf("%c",data);
       printf("\n inserire il quantitativo della merce, preceduto dal segno + se e' un carico - se e' uno scarico\n");
       scanf("%f",&peso);
       fprintf(puntatore_a_file_merce,"%c %c %f\n", merce, data, peso);
       do{
            printf("\n Inserire 1 per continuare 2 per terminare\n");
            scanf("%d",&scelta);
       }while((scelta!=1)&&(scelta!=2));
       elementi_del_file++;

   }
   fclose(puntatore_a_file_merce);
}
float totale_quintali_merce()
{
    while(fscanf(puntatore_a_file_merce,"%c %c %f",merce[elementi_nel_file].merce,merce))
}
char ultimo_carico();
float gudagno();
