#include<stdio.h>
#include<stdlib.h>
int main()
{
	printf("%d\n",455);
	printf("%i\n",455);
	printf("%d\n",+455);//non viene stampato il segno più
	printf("%d\n",-455);//viene stamapto il segno meno
	printf("%+d\n",-745);//stampa il segno
	printf("%hd\n",32000);
	printf("%ld\n",2000000000);//long int
	printf("%o\n",455);//ottale
	printf("%u\n",455);
	printf("%u\n",-455);
	printf("%x\n",455);//esadecimale con lettere minuscole
	printf("%X\n",455);// esadecimale con lettere maiuscole
	printf("%e\n",1234567.89);//notazione esponenziale
	printf("%e\n",+1234567.89);
	printf("%E\n",1234567.89);
	printf("%f\n",1234567.89);
	printf("%g\n",1234567.89);
	printf("%G\n",1234567.89);
	printf("%+09d\n",452);
	printf("%09d\n",452);
	/*
		\' invia in uscita una virgoletta
		\" invia in uscita una doppia virgoletta
		\? invia in uscita un punto interrogativo
		\\ invia in uscita un carattere di blackslash
		\a invia in uscita un segnale acustico e visivo
		\b sposta il cursore di una posizione indietro sulla riga corrente
		\f sposta il cursore all'inizio della successiva pagina logica
		\n sposta il cursore all'inizio della riga successiva
		\r sposta il cursore all'inizio della riga corrente
		\t sposta il cursore alla posizione  del tab orizzontale successivo
		\v sposta il cursore alla posizione del tab verticale successivo
	*/
}
