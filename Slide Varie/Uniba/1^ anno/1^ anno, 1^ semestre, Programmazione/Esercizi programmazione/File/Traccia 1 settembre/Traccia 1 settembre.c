#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Albergo{
    char id[10];
    char citta[20];
    int cat;
    int stanze;
    float prezzo;
};
struct NP{
    char id[10];
    float prezzo;
};



/*Si deve costruire un modulo fusione che ha in input due file di testo: il primo “alberghi.txt” contiene le informazioni sugli alberghi di una determinata città.
Ogni linea contiene le seguenti informazioni:
codice_albergo citta_albergo categoria camere prezzo.
Il file è ordinato per codice_albergo.
Il secondo file di testo “nuovi_prezzi.txt” contiene le informazioni relative all’aggiornamento dei prezzi. Ogni linea contiene solo le seguenti informazioni:
Anche questo file è ordinato per codice_albergo.
Il modulo fornisce in output: il file di testo “prezzi_aggiornati.txt” che si ottiene aggiornando i prezzi del primo file di input .
Il modulo deve fornire un codice d'errore dovuto all’eventuale presenza nel secondo file di input di un codice_albergo non presente nel primo file di input .
Il programma deve contenere anche un ulteriore modulo visualizza che mostra sullo schermo il contenuto del primo file di input e il contenuto del file di output visualizzando, contemporaneamente, una linea di ciascun file.
*/
void creazionealberghitxt(FILE *PuntatoreFileAlberghi);//funzione che crea il file alberghi,txt
void creazionenuoviprezzi(FILE *PuntatoreFileNuoviPrezzi);//funzione che crea il file nuovi prezzi
void creazioneprezziaggiornati(FILE *puntatoreFileAggiornati, FILE *PuntatoreFileAlberghi, FILE *PuntatoreFileNuoviPrezzi);//creazione del file con i prezzi aggiornati
void messaggiodierrore();
void visualizzarefilesingolo(FILE *puntatoreafile);
int main()
{
    FILE *PuntatoreFileAlberghi;//puntatore al file alberghi
    FILE *PuntatoreFileNuoviPrezzi;//puntatore al file nuovi prezzi
    FILE *puntatoreFileAggiornati;//puntatore al file pezzi aggiornati

   // PuntatoreFileAlberghi=fopen("alberghi.txt","w");
    //PuntatoreFileNuoviPrezzi=fopen("nuoviprezzi.txt","w");

   // printf("\n Caricamento file alberghi\n");
   // creazionealberghitxt(PuntatoreFileAlberghi);
    //printf("\n Caricamento file Nuovi Prezzi\n");
    //creazionenuoviprezzi(PuntatoreFileNuoviPrezzi);
    PuntatoreFileAlberghi=fopen("alberghi.txt","r");
    PuntatoreFileNuoviPrezzi=fopen("nuoviprezzi.txt","r");
    puntatoreFileAggiornati=fopen("prezzi_aggiornati.txt","w");
    creazioneprezziaggiornati(puntatoreFileAggiornati,PuntatoreFileAlberghi,PuntatoreFileNuoviPrezzi);

    //visualizzarefile(FILE *PuntatoreFileAlberghi,FILE *puntatoreFileAggiornati);
    //PuntatoreFileAlberghi=fopen("alberghi.txt","r");
    //visualizzarefilesingolo(PuntatoreFileAlberghi);
    return(0);
    system("pause");
}

void creazionealberghitxt(FILE *PuntatoreFileAlberghi)
{
    char CodiceAlbergo[10];
    char Citta[20];
    int Categoria;
    int Camere;
    float Prezzo;
    int finefile=1;
    if(PuntatoreFileAlberghi==NULL)
        printf("IL FILE ALBERGHI NON PUO' ESSERE APERTO");
    else
    {
        while(finefile==1)
        {
            printf("Inserire il codice dell'albergo\n");
            scanf("%s",&CodiceAlbergo);
            printf("Inserire la città\n");
            scanf("%s",Citta);
            printf("Inserire la categoria\n");
            scanf("%d",&Categoria);
            printf("Inserire il numero delle camere dell'albergo\n");
            scanf("%d",&Camere);
            printf("Inserire il prezzo\n");
            scanf("%f",&Prezzo);
            fprintf(PuntatoreFileAlberghi,"%s %s %d %d %f\n",CodiceAlbergo,Citta,Categoria,Camere,Prezzo);
            do
            {
                printf("\n Inserire 1 per continuare e 2 per terminare\n");
                scanf("%d",&finefile);
            }while((finefile!=1)&&(finefile!=2));
        }
     fclose(PuntatoreFileAlberghi);
    }
}
void creazionenuoviprezzi(FILE *PuntatoreFileNuoviPrezzi)
{
    char codicealbergo2[10];
    float nuovoprezzo;
    int finefile=1;
    printf("\n INSERIRE IL CODICE DEGLI ALBERGHI E IL PREZZO PER LA MODIFICA\n");
    if(PuntatoreFileNuoviPrezzi==NULL)
        printf("\n IL FILE NON PUO' ESSERE APERTO\n");
    else
    {
        while(finefile==1)
        {
            printf("\n Inserire il codice dell'albergo\n");
            scanf("%s",codicealbergo2);
            printf("\n Inserire il prezzo\n");
            scanf("%f",&nuovoprezzo);
            fprintf(PuntatoreFileNuoviPrezzi,"%s %f\n",codicealbergo2,nuovoprezzo);
            do
            {
                printf("\n Inserire 1 per continuare, 2 per terminare\n");
                scanf("%d",&finefile);
            } while((finefile!=1)&&(finefile!=2));
        }
    fclose(PuntatoreFileNuoviPrezzi);
    }
}
void creazioneprezziaggiornati(FILE *puntatoreFileAggiornati, FILE *PuntatoreFileAlberghi, FILE *PuntatoreFileNuoviPrezzi)
{
    char CodiceAlbergo[10];
    char Citta[20];
    int Categoria;
    int Camere;
    float Prezzo;
    int nh;
    int qnp;
    // si mettono i dati dei file e lo mette nella struttura albergo e NP
    struct Albergo h[100];
    nh=0;
    while (fscanf(PuntatoreFileAlberghi,"%s %s %d %d %f",h[nh].id,h[nh].citta,&h[nh].cat,&h[nh].stanze,&h[nh].prezzo)!=EOF)
        nh++;

    int i=0;
    while(i<nh)
    {
        printf("\n%s %s %d %d %f\n",h[i].id,h[i].citta,h[i].cat,h[i].stanze,h[i].prezzo);
        i++;
    }

    struct NP np[100];
    qnp=0;
    while (fscanf(PuntatoreFileNuoviPrezzi,"%s %f",np[qnp].id,&np[qnp].prezzo)!=EOF)
        qnp++;

    int j=0;
    while(j<qnp)
    {
        printf("\n %s %f \n",np[j].id,np[j].prezzo);
        j++;
    }

    j=0;

    while(j<qnp)
    {
        int trovato=0;
        i=0;
        while(i<nh)
        {
            if (strcmp(np[j].id,h[i].id)==0)//0 se sono uguali, maggiore di 0 se la prima è maggiore della seconda, minore di 0 se la prima è minore della seconda
               {
                    h[i].prezzo=np[j].prezzo;
                    trovato=1;
               }

            i++;
        }
        if (trovato==0)
            printf ("\n Il codice identificativo %s non esiste\n",np[j].id);
        j++;
    }

    i=0;
    while(i<nh)
    {
        printf("\n%s %s %d %d %f\n", h[i].id,h[i].citta,h[i].cat,h[i].stanze,h[i].prezzo);
        i++;
    }
    if(puntatoreFileAggiornati==NULL)
        printf("\n Impossibile aprire il file prezzi_aggiornati.txt\n");
    else
    {
        i=0;
        while(i<nh)
        {
            fprintf(puntatoreFileAggiornati,"%s %s %d %d %f \n",h[i].id,h[i].citta,h[i].cat,h[i].stanze,h[i].prezzo);
            i++;
        }
        fclose(puntatoreFileAggiornati);
    }
    fclose(PuntatoreFileAlberghi);
    puntatoreFileAggiornati=fopen("prezzi_aggiornati.txt","r");
    PuntatoreFileAlberghi=fopen("alberghi.txt","r");
    while(!feof(puntatoreFileAggiornati))
    {
        fscanf(puntatoreFileAggiornati,"\n %s %s %d %d %f", CodiceAlbergo, Citta,& Categoria, &Camere, &Prezzo);
        if(!feof(puntatoreFileAggiornati))
            printf("\n %s %s %d %d %f\n", CodiceAlbergo, Citta,Categoria,Camere,Prezzo);
        fscanf(PuntatoreFileAlberghi,"\n %s %s %d %d %f",CodiceAlbergo, Citta,& Categoria, &Camere, &Prezzo);
        if(!feof(PuntatoreFileAlberghi))
            printf("\n %s %s %d %d %f\n", CodiceAlbergo, Citta,Categoria,Camere,Prezzo);
    }
    fclose(puntatoreFileAggiornati);
    fclose(PuntatoreFileAlberghi);
}

void visualizzarefilesingolo(FILE *puntatoreafile)
{
    int CodiceAlbergo;
    char Citta[20];
    char Categoria[20];
    int Prezzo;
    while(!feof(puntatoreafile))
		{
		 	fscanf(puntatoreafile,"%d",&CodiceAlbergo);
		 	if(!feof(puntatoreafile))
				printf("\n Codice albergo: %d ",CodiceAlbergo);
	 		fscanf(puntatoreafile,"%s",Citta);
			if (!feof(puntatoreafile))
				printf("\t Citta: %s \t",Citta);
            fscanf(puntatoreafile,"%s",Categoria);
			if (!feof(puntatoreafile))
				printf("\t Citta: %s \t",Categoria);
            fscanf(puntatoreafile,"%d",&Prezzo);
			if (!feof(puntatoreafile))
				printf(" Prezzo: %d \n",Prezzo);
		}
    fclose(puntatoreafile);
}
