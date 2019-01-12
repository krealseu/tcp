#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#include "tcphelp.h"

#define PORT 8008
#define  IP_ADDRESS "127.0.0.1"


int main(int argc,char **argv)
{
	int sockfd;
	sockfd=create_client_socket(IP_ADDRESS ,PORT);

	int n;
	char sendline[20],recvline[500];
	printf("connect with server...\n");
	send(sockfd,"KEY",strlen("KEY"),0);
	n=recv(sockfd,recvline,500,0);
	recvline[n]='\0';
	printf("recv data is:%s\n",recvline);
	close(sockfd);
	return 0;
}
