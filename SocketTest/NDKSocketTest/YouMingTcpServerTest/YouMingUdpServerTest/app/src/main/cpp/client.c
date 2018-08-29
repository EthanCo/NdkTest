/* Tom Miller
 * Client program for socket practice. */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h> 
#include <arpa/inet.h>

#define PORT 12669 //Unassigned port by IANA standards
#define MAX_STRING_LENGTH 1024

int main_send() {
	struct sockaddr_in address;
	int sock = 0, recdata;
	struct sockaddr_in serv_addr;
	char buffer[1024] = {0};
	if (( sock =  socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("\nSocket Creation Error\n");
		exit(EXIT_FAILURE);
	}
	
	//memset(&server_addr, '0', sizeof(server_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	
	if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
	{
		printf("\nAddress not supported\n");
		return -1;
	}
	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection failed\n");
		return -1;
	}
	char sendstring[MAX_STRING_LENGTH];
	printf( "\nEnter a string:\n" );
	fgets( sendstring, MAX_STRING_LENGTH, stdin);
	sendstring[strcspn(sendstring, "\n")] = 0;	
	send(sock, sendstring, strlen(sendstring), 0);
	printf("Sent string to server\n");
	recdata = read(sock, buffer, 1024);
	printf("%s\n", buffer);
	return 0;
}
