#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct nome{
    char nome[20];
    char cognome [20];
    };
int main()
{

    struct nome elenco[100];
    int scelta=-1;
    int i;
    int cont=0;

    do
    {
        printf("\n inserire nome\n");
        scanf("%s",elenco[cont].nome);
        printf("\n inserire cognome\n");
        scanf("%s",elenco[cont].cognome);
        cont++;
        do{
            fflush(stdin);
            printf("\ninserire 1 per cotinuare e 2 per terminare\n");
            scanf("%d",&scelta);
        }while(scelta!=1 && scelta!=2);
    }while(scelta==1);

    i=0;
    while(i<cont)
    {
        printf("\n %s %s \n",elenco[i].nome,elenco[i].cognome);
        i++;
    }
    i=0;
    int j;
    char vnome[20];
    char vcognome[20];
    while(i<cont-1)
    {
        j=i+1;
        while(j<cont)
        {
            if(strcmp(elenco[i].nome,elenco[j].nome)<0)
            {
                strcpy(vnome,elenco[i].nome);
                strcpy(elenco[i].nome,elenco[j].nome);
                strcpy(elenco[j].nome,vnome);
                strcpy(vcognome,elenco[i].cognome);
                strcpy(elenco[i].cognome,elenco[j].cognome);
                strcpy(elenco[j].cognome,vcognome);
            }
            j++;
        }
        i++;

    }
    printf("\nstruttura ordinata\n");
    i=0;
    while(i<cont)
    {
        printf("%s %s\n",elenco[i].nome,elenco[i].cognome);
        i++;
    }
}
