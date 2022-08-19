// UDP server program
#include <winsock.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void processor(char recvBuffer[], char sendBuffer[]);

int main (void)
{
	// Declare and define variables
	int s;						// Socket descriptor (reference)
	int len;						// Length of string to be echoed
	char	recvBuffer[65507 + 1];		// Data buffer
	char	sendBuffer[65507 + 1];	// Data buffer
	struct sockaddr_in servAddr;	// Server (local) socket address
	struct sockaddr_in clntAddr;		// Client (remote) socket address
	int  clntAddrLen;				// Length of client socket address
	
	// Build local (server) socket address
	memset (&servAddr, 0, sizeof (servAddr));	// Allocate memory
	servAddr.sin_family = AF_INET;			// Family field
	servAddr.sin_port = htons(80);				// Default port number
	servAddr.sin_addr.s_addr = htonl (INADDR_ANY);	// Default IP address
	
	// Create socket
	if ((s = socket (PF_INET, SOCK_DGRAM, 0) < 0))
	{
		perror ("Error: socket failed!"); 
		exit (1); 
	}
	
	// Bind socket to local address and port
	if ((bind (s,(struct sockaddr*) &servAddr, sizeof (servAddr)) < 0))
	{
		perror ("Error: bind failed!"); 
		exit (1); 
	}
	
	for(;;)						// Run forever
	{
		// Receive String 
		len = recvfrom (s, recvBuffer, sizeof (recvBuffer), 0,  (struct sockaddr*)&clntAddr, &clntAddrLen);
		
		// Process recvBuffer to create sendBuffer
		processor(recvBuffer, sendBuffer);
		
		// Send String 
		sendto (s, sendBuffer, len, 0, (struct sockaddr*)&clntAddr, sizeof(clntAddr));
	} // End of for loop
	
} // End main

void processor(char recvBuffer[], char sendBuffer[])
{
	// Insert processing code here
}


