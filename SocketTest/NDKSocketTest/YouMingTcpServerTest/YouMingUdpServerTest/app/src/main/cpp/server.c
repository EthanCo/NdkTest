/* Tom Miller
 * Setting up a basic BSD socket in C */

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>
#include "base.h"

#define PORT 12669 //Unassigned port by IANA standards

int main_recv(){
	//defining socket variables
	int server_fd, new_socket, recdata;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[1024] = {0};
	char *hello = "Hello from server!";
	// Creating file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("Socket failed");
		exit(EXIT_FAILURE);
	}
    LOGI("recv 1");
	//attaching to port 26490
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
		&opt, sizeof(opt)))
	{
		perror("setsockopt failure");
		exit(EXIT_FAILURE);
	}
    LOGI("recv 2");
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons( PORT );
	//setting socket, steps are bind, listen, accept, read, send
    LOGI("recv 3");
	if (bind(server_fd, (struct sockaddr *)&address,
		sizeof(address))<0)
	{
		perror("Bind failed");
		exit(EXIT_FAILURE);
	}
    LOGI("recv 4");
	if (listen(server_fd, 3) < 0)
	{
		perror("Listen failed");
		exit(EXIT_FAILURE);
	}
    LOGI("recv 5");
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address,(socklen_t*)&addrlen))<0)
	{
        LOGI("recv 5-1 Accept failure");
		perror("Accept failure");
		exit(EXIT_FAILURE);
	}
    LOGI("recv 6");
	recdata = read( new_socket , buffer , 1024);
	printf("%s\n", buffer );
    LOGI("recv %s\n", buffer);
	send(new_socket , hello , strlen(hello) , 0);
	printf("Said hello to the client!\n");
    LOGI("Said hello to the client!");
	return 0;
}
