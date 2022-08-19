/*
 ============================================================================
 Name        : Esonero2_Server.c
 Author      : Marco Spagnolo
 Version     :
 Copyright   : Your copyright notice
 Description : UDP Simulation in C - Server
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
#include <stdbool.h>
#define DIM_BUFFER 256
/* Funzione che elimina la socket. */
void ClearWinSock() {
#if defined WIN32
	WSACleanup();
#endif
}
int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	/* Controllo supporto socket. */
	WSADATA wsaData;
	int init = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (init != 0) {
		/** Socket non supportate. **/
		puts("Errore  WSAStartup.");
		return 0;
	}
	/* Socket supportate.
	 * 	Inizio programma lato server. */
	/* Inizializzazione descrittore socket (lato server):
	 *  PF_INET --> famiglia di protocolli
	 *  SOCK_DGRAM --> Comunicazione UDP
	 *  IPPROTO_UDP --> UDP. */
	int descrittoreSocket; /* Descrittore socket server. */
	descrittoreSocket = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	/* Controllo valore descrittore. */
	if (descrittoreSocket < 0) {
		puts("Errore creazione socket.");
		return 0;
	}
	/* Struttura socket server e inizilizzazione:
	 * 	AF_INET --> Protocolli IP
	 * 	inet_addr("127.0.0.1") --> Converte l'indirizzo id localhost in notazione 32 bit
	 * 	htons(12000) --> Converte il numero di porta in notazione Big-Endian */
	struct sockaddr_in server;
	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_port = htons(12000);
	/* Binding struttura e descrittore. */
	if (bind(descrittoreSocket, (struct sockaddr*) &server, sizeof(server))
			< 0) {
		/* Errore bining ed uscita. */
		puts("Binding non riuscito.");
		return 0;
	}
	while (1) {
		puts("In attesa di richieste...");
		/* Variabili struct usate per la risoluzione del nome del client. */
		struct sockaddr_in client;
		struct hostent *hostClient;
		/* Variabili usate per lo scambio di messaggi. */
		char messaggio[128];
		unsigned int lunghezza_client = sizeof(client);
		/* Ricezione messaggio 'Hello'. */
		recvfrom(descrittoreSocket, messaggio, sizeof(messaggio), 0,
				(struct sockaddr*) &client, &lunghezza_client);
		puts(messaggio);
		/* Risoluzione nome del client. */
		hostClient = gethostbyaddr((char *) &client.sin_addr, 4, AF_INET);
		char* nomeClient = hostClient->h_name;
		/* Stampa nome del client. */
		puts("Comunicazione con l'host: ");
		puts(nomeClient);
		/* Invio messaggio al client. */
		strcpy(messaggio, "Messaggio ricevuto");
		sendto(descrittoreSocket, messaggio, sizeof(messaggio), 0,
				(struct sockaddr*) &client, sizeof(client));
		/* Struct da ricevere dal client; essa è composta da:
		 * 	-una prima stringa (da ricevere dal client);
		 * 	-una seconda stringa (da ricevere dal client);
		 * 	-una terza stringa (da inviare al client). */
		struct {
			char stringa1[DIM_BUFFER / 4];
			char stringa2[DIM_BUFFER / 4];
			char risposta[DIM_BUFFER / 2];
		} stringhe;
		/* Variabile booleana che indica la richiesta da parte del client
		 * 	di terminare la comunicazione. */
		bool fine = false;
		do {
			puts("In attesa del messaggio dal client...");

			/* Ricezione struttura dal client. */
			if (recvfrom(descrittoreSocket, &stringhe, sizeof(stringhe), 0,
					(struct sockaddr*) &client, &lunghezza_client) < 0) {
				/* Ricezione non riuscita. */
				close(descrittoreSocket);
				puts("Ricezione non riuscita; fine programma. ");
				system("PAUSE");
				return 0;
			}
			/* Controllo che una delle due stringhe sia "quit", cioè l'indicazione della
			 * 	terminazione della comunicazione.
			 * 	Per farlo, le due stringhe vengono convertite in minuscolo, salvate
			 * 	in altre due stringhe, e vengono confrontate queste ultime;
			 * 	in tal modo si rende il controllo case insensitive. */
			char s1[strlen(stringhe.stringa1)], s2[strlen(stringhe.stringa2)];
			strcpy(s1, stringhe.stringa1);
			strcpy(s2, stringhe.stringa2);
			/* Conversione delle stringhe in minuscolo. */
			for (int i = 0; i < strlen(s1); i++) {
				s1[i] = tolower(s1[i]);
			}
			for (int i = 0; i < strlen(s2); i++) {
				s2[i] = tolower(s2[i]);
			}
			/* Controllo stringhe. */
			if (strcmp(s1, "quit") == 0 || strcmp(s2, "quit") == 0) {
				/* Si copia nella stringa di risposta la stringa "bye",
				 *  e si segna che la comunicazione deve terminare (flag fine). */
				strcpy(stringhe.risposta, "Bye");
				fine = true;
			} else {
				/* Si copia nella stringa di risposta la concatenazione delle
				 * 	due stringhe ricevute. */
				strcpy(stringhe.risposta, stringhe.stringa1);
				strcat(stringhe.risposta, stringhe.stringa2);
			}
			/* Invio struttura. */
			if (sendto(descrittoreSocket, &stringhe, sizeof(stringhe), 0,
					(struct sockaddr*) &client, sizeof(client)) < 0) {
				/* Invio non riuscito. */
				close(descrittoreSocket);
				puts("Invio non riuscito; fine programma. ");
				system("PAUSE");
				return 0;
			}
		} while (fine == false);
	}
}
