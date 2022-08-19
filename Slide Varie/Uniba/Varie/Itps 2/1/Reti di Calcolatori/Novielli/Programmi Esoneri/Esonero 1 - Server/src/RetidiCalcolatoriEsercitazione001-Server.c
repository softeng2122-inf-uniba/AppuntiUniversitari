#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#if defined WIN32
#include <winsock.h>
#else
#define closesocket close
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif

#define BUFFERSIZE 512		// Dimensione Buffer
#define PROTOPORT 5193		// Numero di porta
#define QLEN 6

void ErrorHandler (char *errorMessage){
	printf ("%s",errorMessage);
}

void ClearWinSock (){
#if defined WIN32
	WSACleanup();
#endif
}

int main(int argc, char *argv[]){

	int port;
	if (argc > 1){
		port = atoi(argv[1]);
	}
	else port = PROTOPORT;	// Default
	if (port < 0){
		printf ("Bad port number %s \n",argv[1]);
		return -1;
	}

#if defined WIN32
	WSADATA WSAData;
	int iresult = WSAStartup(MAKEWORD(2,2), &WSAData);
	if (iresult!=0){
		ErrorHandler("Error at WSAStartup\n");
		return -1;
	}
#endif

	// New Socket
	int NewSocket;
	NewSocket=socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
	if (NewSocket < 0){
		ErrorHandler("Creazione Socket fallita.\n");
		closesocket(NewSocket);
		ClearWinSock();
		return -1;
	}

	// Indirizzo per la socket
	struct sockaddr_in sad;
	memset(&sad,0,sizeof(sad));
	sad.sin_family=AF_INET;
	sad.sin_addr.s_addr=inet_addr("127.0.0.1");
	sad.sin_port=htons(5193);

	// Binding e errorhandler
	if (bind(NewSocket,(struct sockaddr*)&sad,sizeof(sad))<0){
		ErrorHandler("Bind failed.\n");
		closesocket(NewSocket);
		ClearWinSock();
		return 0;
	}

	// Listen di NewSocket
	if (listen(NewSocket,QLEN)<0){
		ErrorHandler("Listen Failed!\n");
		closesocket(NewSocket);
		ClearWinSock();
		return -1;
	}

	// New Connection
	struct sockaddr_in cad;
	int clientSocket;
	int clientLen;
	int stringLen=0;
	printf ("Listen for Client..");
	while(1){
		clientLen=sizeof(cad);
		if ((clientSocket=accept(NewSocket,(struct sockaddr*)&cad,&clientLen))<0){
			ErrorHandler("Accept failed\n");
			closesocket(NewSocket);
			ClearWinSock();
			return-1;
		}
		printf ("Indirizzo client %s\n",inet_ntoa(cad.sin_addr));
		char*buf="Connessione Stabilita";
		stringLen=strlen(buf);
		if (send(clientSocket,buf,stringLen,0)!=stringLen){
			ErrorHandler("Send sent different No of Bytes");
			closesocket(clientSocket);
			ClearWinSock();
			system("PAUSE");
			return -1;
		}
		int bytestring1;
		char string1[BUFFERSIZE];
		bytestring1=recv(clientSocket,string1,BUFFERSIZE-1,0);
		string1[bytestring1]='\0';
		printf ("Client: %s\n",string1);
		char welcome[BUFFERSIZE]="ack";
		if(send(clientSocket,welcome,strlen(welcome),0)!=strlen(welcome)){
			ErrorHandler("Send sent a different No of bytes");
			closesocket(clientSocket);
			ClearWinSock();
			system("PAUSE");
			return -1;
		}
	}
}
