#include "tcphelp.h"
#include <sys/socket.h>

int main(){
int sfd = create_service_socket(8088);
listen(sfd,5);
accept(sfd,NULL,NULL);
}