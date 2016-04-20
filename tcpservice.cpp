#include "tcphelp.h"
#include<stdio.h>
#include<string.h>
#include <sys/socket.h>
#include<unistd.h>

int main(){
	int sfd = create_service_socket(8080);
	if(sfd == -1)
		return -1;
	listen(sfd,5);
	int client = accept(sfd,NULL,NULL);
	int n;
	char sendline[20],recvline[20];
	n=recv(client,recvline,20,0);
	recvline[n]='\0';
	printf("recv data frome client:%s\n",recvline);
	send(client,"KEY OK",strlen("KEY OK"),0);
	close(sfd);
	close(client);
}
