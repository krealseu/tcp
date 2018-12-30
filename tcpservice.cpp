#include "tcphelp.h"
#include<stdio.h>
#include<string.h>
#include <sys/socket.h>
#include<unistd.h>
#include <pthread.h>
#include <time.h>

#define msend(fd,x) send(fd, x, strlen(x), 0)

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
   int counts = 0;
   while(1){
       int client = accept(sfd, NULL, NULL);
       char recvline[2000];
       time_t tt = time(NULL);//这句返回的只是一个时间cuo
       tm* t= localtime(&tt);
       char data[100];
       sprintf(data,"HTTP/1.1  200  OK\r\n\r\n\
       <html><head>\
       <meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"/>\
       <meta name=\"viewport\" content=\"width=device-width,initial-scale=1\"/>\
       </head><body>%d-%02d-%02d %02d:%02d:%02d</body></html>", 
              t->tm_year + 1900,t->tm_mon + 1,t->tm_mday,t->tm_hour,t->tm_min,t->tm_sec);
       //int n = recv(client, recvline, 2000, 0);
       //recvline[n] = '\0';
       //printf("recv data frome client:%s\n", recvline);
       msend(client,data);
       char echo[20];
       sprintf(echo,"Ask times%d",++counts);
       puts(echo);
       //msend(client,"HTTP/1.1  200  OK\r\n<html><body>hdhd</body></html>");
       close(client);
    }
	close(sfd);
	return 0;
}
