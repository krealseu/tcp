#ifndef TCPHELP_H
#define TCPHELP_H
extern "C" {
    int create_client_socket(const char * address,int port);
    int create_service_socket(int port);
}

#endif //TCPHELP_H
