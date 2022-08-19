//creazione di un file sequenziale
#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *puntatoreafile;
	int numeromatricola;
	char nome[25];
	char cognome[25];
	int finefile=2;
	puntatoreafile=fopen("Hello.doc","w");
	if(puntatoreafile==NULL)
		printf("\n il file non è stato aperto correttamente\n");
	else
		{
			while(finefile==2)
			{
				printf("\n Inserisci numero matricola\n");
				scanf("%d",&numeromatricola);
				printf("\n Inserire nome studente\n");
				scanf("%s",&nome);
				printf("\n Inserire cognome studente\n");
				scanf("%s",&cognome);
				fprintf(puntatoreafile,"%d %s %s\n",numeromatricola,nome,cognome);
				printf("\n Inserire 1 per terminare, 2 per continuare\n");
				scanf("%d",&finefile);
			}
			fclose(puntatoreafile);
		}
	
	puntatoreafile=fopen("Hello.doc","r");
	if(puntatoreafile==NULL)
		printf("\n Il file non è stato aperto correttamente\n");
	else
	{
		while(!feof(puntatoreafile))
		{	
		 	fscanf(puntatoreafile,"%d",&numeromatricola);
		 	if(!feof(puntatoreafile))
				printf("\n Numero Matricola: %d ",numeromatricola);
	 		fscanf(puntatoreafile,"%s",&nome);
			if (!feof(puntatoreafile))				
				printf("\t Nome: %s \t",nome);	
		}
	fclose(puntatoreafile);
	}
}
