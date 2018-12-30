#include "tcphelp.h"
#include<stdio.h>
#include<string.h>
#include <sys/socket.h>
#include<unistd.h>
#include <pthread.h>

#define msend(fd,x) send(fd, x, strlen(x), 0);

void mrecv(int fd){
	int n;
	char recvline[20];
	n = recv(fd, recvline, 20, 0);
	recvline[n] = '\0';
	printf("recv data frome client:%s\n", recvline);
}

void * ss(void * arg){
	int fd = *(int*)arg;
	int n;
	char recvline[20];
	while(1){
		n = recv(fd, recvline, 20, 0);
		if(n==0)
			break;
		recvline[n] = '\0';
		printf("recv data frome client:%s\n", recvline);
	}
}

int main() {
	char cna[]="sdf,sdf,adf,asd,f,d";

	//strsep();
	int sfd = create_service_socket(8008);
	if (sfd == -1)
		return -1;
	listen(sfd, 5);
   while(1){
       int client = accept(sfd, NULL, NULL);
       char recvline[2000];
       int n = recv(client, recvline, 2000, 0);
       recvline[n] = '\0';
       printf("recv data frome client:%s\n", recvline);
       char dd[] = "HTTP/1.1  200  OK/r/n/r/n<html><body>hdhd</body></html>";
       msend(client,dd);
       //msend(client,"HTTP/1.1  200  OK\r\n<html><body>hdhd</body></html>");
       close(client);
    }
	close(sfd);
	return 0;
}
