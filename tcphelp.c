#include<stdio.h>


#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define mprintf printf

int create_client_socket(char * address,int port)
{
  int sock = -1;
  if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
    mprintf("Cannot open socket");
    return -1;
  }
  struct sockaddr_in client_address = (struct sockaddr_in){  
     AF_INET,
     htons(port),
     inet_addr(address)
  };
  if(connect(sock,(struct sockaddr *)&client_address ,sizeof(client_address))==-1)
  {
    mprintf("connect error\n");
    return -1;
  }
  return sock;
}

int create_service_socket(int port){
  int sock;
  int reuse = 1;
  /* Server addess */
  struct sockaddr_in server_address = (struct sockaddr_in){  
     AF_INET,
     htons(port),
     (struct in_addr){INADDR_ANY}
  };
  if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
    mprintf("Cannot open socket");
    return -1;
  }
  /* Address can be reused instantly after program exits */
  setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof reuse);
  /* Bind socket to server address */
  if(bind(sock,(struct sockaddr*) &server_address, sizeof(server_address)) < 0){
    mprintf("Cannot bind socket to address");
    return -1;
  }
  return sock;
}
