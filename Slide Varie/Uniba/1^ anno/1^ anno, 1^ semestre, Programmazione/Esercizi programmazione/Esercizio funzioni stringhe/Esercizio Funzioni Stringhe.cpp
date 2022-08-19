/*
Esercizio con tutte le funzioni delle stringhe
*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
	printf("%s \n %s%s \n %s%s \n \n","Funzione isdigit: ",//La funzione isdigit determina e il suo argomento è una cifra
			isdigit('8') ? "8 è un" : "8 non è un", "numero",
			isdigit('#') ? "# è un" : "# non è un", "numero");
	printf("%s \n %s%s \n %s%s \n %s%s \n %s%s \n \n","Funzione isalpha: ",//La funzione isalpha determina se il suo argomento è una lettera
			isalpha('A') ? "A è una" : "A non è una", "lettera",
			isalpha('b') ? "b è una" : "b non è una", "lettera",
			isalpha('&') ? "& è una" : "& non è una", "lettera",
			isalpha('4') ? "4 è una" : "4 non è una", "lettera");
    printf("%s \n %s%s \n %s%s \n %s%s \n \n","Funzione isalnum: ",//La funzione islanum determina se il suo argomento è un numero p una lettera
			isalnum('A') ? "A è un" : "A non è un", "numero o una lettera",
			isalnum('#') ? "# è un" : "# non è un", " numero o una lettera",
			isalnum('8') ? "8 è un" : "8 non è un ", "numero o una lettera");
	printf("%s \n %s%s \n %s%s \n %s%s \n %s%s \n %s%s \n \n","Funzione isxdigit: ",//La funzione isxxdigit determina se il suo argomento è un numero esaecimale
			isxdigit('F') ? "F è un" : "F non è un", "numero esadecimale",
			isxdigit('J') ? "J è un" : "J non è un", "numero esadecimale",
			isxdigit('7') ? "7 è un" : "7 non è un", "numero esadecimale",
			isxdigit('$') ? "$ è un" : "$ non è un", "numero esadecimale",
			isxdigit('f') ? "f è un" : "f non è un", "numero esadecimale");
	printf("%s \n %s%s \n %s%s \n %s%s \n %s%s \n \n","Funzione islower: ",//La funzione islower determina se il suo argomento è una lettera minuscola
			islower('p') ? "p è una" : "p non è una", "lettera minuscola",
			islower('p') ? "p è una" : "p non è una", "lettera minuscola",
			islower('p') ? "p è una" : "p non è una", "lettera minuscola",
			islower('p') ? "p è una" : "p non è una", "lettera minuscola");
	printf("%s \n %s%s \n %s%s \n %s%s \n %s%s \n \n","Funzione isupper: ",//La funzione isupper determina se il suo argomento è una lettera maiuscola
			isupper('D') ? "D è una" : "D non è una", "lettera maiuscola",
			isupper('d') ? "d è una" : "d non è una", "lettera maiuscola",
			isupper('8') ? "8 è una" : "8 non è una", "lettera maiuscola",
			isupper('$') ? "$ è una" : "$ non è una", "lettera maiuscola");
	printf("%s\n %s%c \n %s%c \n %s%c \n %s%c \n \n","Funzione toupper e tolower",/*La funzione toupper converte il suo argomento in minuscolo o in maiuscolo, 
																					 la funzione tollower converte il uo argomento da maisucolo in minusoclo,
																					 se nel loro argomento vi è un errore, restituisocno il loro argomento così com'è.*/
			"u convertita in maiuscolo è: ", toupper('u'),
			"7 convertita in maiuscolo è: ", toupper('7'),
			"$ convertita in maiuscolo è: ", toupper('$'),
			"L convertita in minuscolo è: ", tolower('L'));
}
