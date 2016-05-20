#include "tcphelp.h"
#include<stdio.h>
#include<string.h>
#include <sys/socket.h>
#include<unistd.h>
#include <pthread.h>
#define msend(x) send(client, x, strlen(x), 0);

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
	int sfd = create_service_socket(21);
	if (sfd == -1)
		return -1;
	listen(sfd, 5);
	int client = accept(sfd, NULL, NULL);
	pthread_t id;
	pthread_create(&id,NULL,ss,&client);
	msend("220 234 ready\r\n");
	char sendline[20];
	char temp[18];
	while(1){
		sprintf(sendline,"%s%s",gets(temp),"\r\n");
		msend(sendline);
	}
	pthread_join(id,NULL);
	close(sfd);
	close(client);
	return 0;
}
