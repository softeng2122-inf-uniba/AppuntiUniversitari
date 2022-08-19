// UDP client program
#include <winsock.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void requester(char sendBuffer[]);
void user(char recvBuffer[]);


int main(int argc, char* argv[])	//Three arguments to be checked later
{
	// Declare and define variables    
	int s;						// Socket descriptor
	int len;						// Length of string to be echoed
	char* servName;				// Server name
	int servPort;					// Server port
	char sendBuffer[256 + 1];		//Send data buffer
	char recvBuffer[256 + 1];		// Receive data buffer
	struct sockaddr_in servAddr; 	// Server socket address
	
	// Check and set program arguments    
	if (argc != 2)                                              
	{
		perror ("Error: three arguments are needed!"); 
		exit(1); 
	}
	servName = argv[1];                                           
	servPort = atoi(argv[2]);                                           
	
	// Build server socket address
	memset (&servAddr, 0, sizeof (servAddr));
	servAddr.sin_family = AF_INET; 
	inet_pton (AF_INET, servName, &servAddr.sin_addr);
	servAddr.sin_port = htons (servPort);
	// Create socket
	if ((s = socket (PF_INET, SOCK_DGRAM, 0) < 0))
	{
		perror ("Error: Socket failed!"); 
		exit(1); 
	}

	// Make request creates the sendbuffer to be sent
	requester(sendBuffer);
	
	// Send request
	len = sendto(s, sendBuffer, strlen(sendBuffer), 0, (struct sockaddr*)&servAddr, sizeof (servAddr));
	
	// Receive request
	recvfrom(s, recvBuffer, len, 0, NULL, NULL);
	
	// Use Response
	user(recvBuffer);
	
	// Close the socket
	close(s);
	
	// Stop the program
	exit(0);
	
	void requester(char sendBuffer[])
	{
		//  Wirte the code to create the request as a byte array
	}
	
	void user(char recvBuffer[])
	{
		// Write the code to use the response
	}
	
} // End of echo client program