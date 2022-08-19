/*
 ============================================================================
 Name        : Esonero2_Client.c
 Author      : Marco Spagnolo
 Version     :
 Copyright   : Your copyright notice
 Description : UDP Simulation in C - Client
 ============================================================================
 */

#if defined WIN32
#include <winsock.h>
#else
#define closesocket close
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#define DIM_BUFFER 256
/* Funzione che elimina la socket. */
void ClearWinSock() {
#if defined WIN32
	WSACleanup();
#endif
}
int main(void) {
	/* Specifica modalità e grandezza buffer */
	setvbuf(stdout, NULL, _IONBF, 0);
	/* Controllo supporto socket. */
	WSADATA wsaData;
	int init = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (init != 0) {
		/* Socket non supportate. */
		puts("Errore  WSAStartup.");
		return 0;
	}
	/* Socket supportate.
	 * 	Inizio programma lato client. */
	/* Inizializzazione descrittore socket:
	 *  PF_INET --> famiglia di protocolli
	 *  SOCK_DGRAM --> Comunicazione UDP
	 *  IPPORTTO_UDP --> UDP. */
	/* Descrittore socket (lato client). */
	int descrittoreSocket;
	descrittoreSocket = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	/* Controllo valore descrittore. */
	if (descrittoreSocket < 0) {
		puts("Errore creazione socket.");
		return 0;
	}
	/* Inizializzaizone dati della socket del server. */
	struct sockaddr_in server;
	char nomeServer[40];
	int numeroPorta;
	/* Input indirizzo server e numero di porta processo. */
	puts("Inserire il nome del server: ");
	gets(nomeServer);
	puts("Inserire il numero di porta del processo: ");
	scanf("%d", &numeroPorta);
	/* Risoluzione nome inserito e assegnamento alla struttura hostRemoto. */
	struct hostent *hostRemoto = gethostbyname(nomeServer);
	/* Controllo esito risoluzione nome. */
	if (hostRemoto == NULL) {
		/* Errore nella risoluzione del nome. */
		puts("Nome risolto non correttamente; chiusura programma.");
		return 0;
	}
	/* Conversione del nome risolto in un indirizzo in notazione puntata (del tipo x.y.z.j). */
	struct in_addr *ina = (struct in_addr*) hostRemoto->h_addr_list[0];
	/* Assicura che i byte del server siano tutti a 0. */
	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr(inet_ntoa(*ina));
	server.sin_port = htons(numeroPorta);
	/* Variabili usate nella comunciazione per lo scambio di informazioni. */
	char messaggio[128];
	unsigned int lunghezza_server = sizeof(server);
	/* Invio stringa 'Hello'. */
	strcpy(messaggio, "Hello");
	sendto(descrittoreSocket, messaggio, sizeof(messaggio), 0,
			(struct sockaddr*) &server, sizeof(server));
	/* Ricezione risposta dal server. */
	recvfrom(descrittoreSocket, messaggio, sizeof(messaggio), 0,
			(struct sockaddr*) &server, &lunghezza_server);
	puts(messaggio);
	/* Struct da inviare al server; essa è composta da:
	 * 	-una prima stringa (da prendere in input);
	 * 	-una seconda stringa (da prendere in input);
	 * 	-una terza stringa (da ricevere dal server). */
	struct {
		char stringa1[DIM_BUFFER / 4];
		char stringa2[DIM_BUFFER / 4];
		char risposta[DIM_BUFFER / 2];
	} stringhe;
	/* Variabile booleana che indica la richiesta da parte del client
	 * 	di terminare la comunicazione. */
	bool fine = false;
	/* Ciclo di comunicazione tra client e server. */
	do {
		/* Lo stream dello standard di input viene svuotato (per non incappare in errori
		 * 	sull'input precedente tramite la funzione gets(). */
		fflush(stdin);
		/* Input prima stringa. */
		puts("Inserire un primo messaggio: ");
		gets(stringhe.stringa1);
		/* Svuotamento stream standard di input. */
		fflush(stdin);
		/* Input seconda stringa. */
		puts("Inserire un secondo messaggio: ");
		gets(stringhe.stringa2);
		fflush(stdin);
		/* Invio messaggio al server. */
		if (sendto(descrittoreSocket, &stringhe, sizeof(stringhe), 0,
				(struct sockaddr*) &server, sizeof(server)) < 0) {
			/* Invio non riuscito, chiusura socket. */
			close(descrittoreSocket);
			puts("Invio non riuscito; fine programma. ");
			system("PAUSE");
			return 0;
		}
		/* Ricezione risposta server. */
		if (recvfrom(descrittoreSocket, &stringhe, sizeof(stringhe), 0,
				(struct sockaddr*) &server, &lunghezza_server) < 0) {
			/* Ricezione non riuscita, chiusura socket. */
			close(descrittoreSocket);
			puts("Ricezione non riuscita; fine programma. ");
			system("PAUSE");
			return 0;
		}
		/* Stampa risposta server. */
		printf("SERVER: ");
		puts(stringhe.risposta);
		/* Controllo che la comunicazione non debba terminare. */
		if (strcmp(stringhe.risposta, "Bye") == 0) {
			/* La comunicazione deve terminare. */
			fine = true;
		}
	} while (fine == false);
	system("PAUSE");
}
