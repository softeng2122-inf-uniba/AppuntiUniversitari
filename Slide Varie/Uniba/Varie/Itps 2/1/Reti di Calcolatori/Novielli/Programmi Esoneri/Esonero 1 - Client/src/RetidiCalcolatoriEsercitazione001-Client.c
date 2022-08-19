#include <stdio.h>
#include <stdlib.h>
#if defined WIN32
#include <winsock.h>
#else
#define closesocket close
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif

#define BUFFERSIZE 512
#define PROTOPROT 27015

void ErrorHandler (char *errorMessage){
	printf ("%s",errorMessage);
}

void ClearWinSock() {
#if defined WIN32
	WSACleanup();
#endif
}

int main(void){
#if defined WIN32
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD (2,2), &wsaData);
	if (iResult!=0){
		printf ("error at WSASturtup\n");
		return -1;
	}
#endif

	char welcome[BUFFERSIZE];

	/* New Socket */
	int Csocket;
	Csocket = socket(PF_INET, SOCK_STREAM,IPPROTO_TCP);
	if (Csocket<0){
		ErrorHandler ("socket creation failed\n");
		closesocket(Csocket);
		ClearWinSock();
		return -1;
	}

	char address[15]="\0";
	int port;
	printf ("Server to connecto to: ");
	scanf("\n");
	gets(address);
	printf ("Insert Port Number: ");
	scanf("%d",&port);
	/* Indirizzo Server */
	struct sockaddr_in sad;
	memset(&sad,0,sizeof(sad));
	sad.sin_family = AF_INET;
	sad.sin_addr.s_addr = inet_addr(address);
	sad.sin_port = htons(port);

	/* Connessione al server */
	if (connect(Csocket,(struct sockaddr *)&sad,sizeof(sad))<0){
		ErrorHandler ("Failed to connect.\n");
		system("PAUSE");
		closesocket(Csocket);
		ClearWinSock();
		return -1;
	}else {
		printf("Connesione effettuata\n");
	}

	/* Ricezione da server */
	int bytesRcvd;
	int totalBytesRcvd = 0;
	char buf[BUFFERSIZE];

	printf ("Received: ");
	if ((bytesRcvd = recv(Csocket,buf,BUFFERSIZE - 1,0))<=0){
		ErrorHandler("recv() failed or connection closed prematurely");
		closesocket(Csocket);
		ClearWinSock();
		return -1;
	}
	totalBytesRcvd += bytesRcvd;	// Numero byte ricevuti
	buf[bytesRcvd] = '\0';	// Terminatore di stringa
	printf ("%s\n",buf);	// buffer

	printf ("Scrivi Hello\n");
	scanf ("%s",welcome);

	/* Inviare welcome a server */
	if (send(Csocket,welcome,strlen(welcome),0)!=strlen(welcome)){
		ErrorHandler("Errore nell'invio messaggio");
		closesocket(Csocket);
		ClearWinSock();
		return -1;
	}

	/* Ricezione stringa dal server */
	int bytestring1;
	char strwelcome[BUFFERSIZE];
	bytestring1=recv(Csocket,strwelcome,BUFFERSIZE-1,0);
	strwelcome[bytestring1]='\0';
	printf ("Server: %s\n",strwelcome);

	bytestring1=recv(Csocket,strwelcome,BUFFERSIZE-1,0);
	strwelcome[bytestring1]='\0';
	printf ("Server: %s\n",strwelcome);
/*	int n1,n2;
	printf ("Inserisci due interi.\n");
	scanf ("%d %d",&n1,&n2);

	if (send(Csocket,n1,strlen(n1),0)!=strlen(n1)){
		ErrorHandler("Errore nell'invio del messaggio");
		closesocket(Csocket);
		ClearWinSock();
		return -1;
	} */

	closesocket(Csocket);
	ClearWinSock();
	printf ("\n");
	system("PAUSE");
	return 0;

}
