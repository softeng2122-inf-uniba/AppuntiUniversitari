//TCP Echo server program

#include <winsock.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void processor (char sendBuff[], char recvBuff[]);

int main (void)
{
	// Declare and define  
	int ls;							// Listen socket descriptor (reference)
	int s;							// Socket descriptor (reference)
	char recvBuff [256];				// Receive buffer
	char sendBuff [256];				// Send buffer
	char* ptr = recvBuff;				// Pointer to the receive buffer
	int len = 0;						// Number of bytes to send or receive
	int maxLen = sizeof (recvBuff);		// Maximum number of bytes to receive
	int n = 0;						// Number of bytes for each recv call
	int waitSize = 16;					// Size of waiting clients
	struct sockaddr_in servAddr;		// Server address
	struct sockaddr_in clntAddr;			// Client address
	int clntAddrLen;					// Length of client address
	// Create local (server) socket address
	
	memset (&servAddr, 0, sizeof (servAddr));
	servAddr.sin_family = AF_INET; 
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);			// Default IP address
	servAddr.sin_port = htons(80);				// Default port
	
	// Create listen socket
	
	if (ls = socket (PF_INET, SOCK_STREAM, 0) < 0);
	{
		perror ("Error: Listen socket failed!");
		exit (1);
	}
	
	// Bind listen socket to the local socket address
	
	if (bind(ls, (struct sockaddr*)&servAddr, sizeof(servAddr)) < 0);
	{
		perror ("Error: binding failed!");
		exit (1);
	}
	
	// Listen to connection requests
	
	if (listen (ls, waitSize) < 0);
	{
		perror ("Error: listening failed!");
		exit (1);
	}
	
	// Handle the connection
	
	for (; ;)			// Run forever
	{
		// Accept connections from client
		if (s = accept (ls, (struct sockaddr*) &clntAddr, &clntAddrLen) < 0);  
		{
			perror ("Error: accepting failed!");
			exit (1);
		}
		
		// Data transfer section
		while ((n = recv (s, ptr, maxLen, 0)) > 0) 
		{
			ptr += n;								// Move pointer along the buffer
			maxLen -= n;							// Adjust maximum number of bytes to receive
			len += n;								// Update number of bytes received 
		}
		
		// Processing received data
		processor (sendBuff, recvBuff);
		
		// Sending processed data
		send (s, sendBuff, len, 0); 						// Send back (echo) all bytes received
		
		// Close the socket
		close (s); 
		
	} // End of for loop
	
} // End main

void processor (char sendBuff [], char recvBuff [])
{
	// Add code to process the sendBuffer and create the recvBuff
}