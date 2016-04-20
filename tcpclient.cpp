#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define PORT 8080
#define  IP_ADDRESS "127.0.0.1"
#include "tcphelp.h"
int main(int argc,char **argv)
{
int sockfd;
int err,n;
struct sockaddr_in addr_ser;
char sendline[20],recvline[20];

sockfd=create_client_socket(IP_ADDRESS ,8080);


printf("connect with server...\n");
send(sockfd,"KEY",strlen("KEY"),0);
n=recv(sockfd,recvline,100,0);
recvline[n]='\0';
printf("recv data is:%s\n",recvline);

while(1)
{
printf("Input your words:");
scanf("%s",&sendline);

send(sockfd,sendline,strlen(sendline),0);
printf("waiting for server...\n");

}
return 0;
}
