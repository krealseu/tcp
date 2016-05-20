CC=gcc

all :client service
	
client:tcpclient.cpp tcphelp.o
	$(CC) tcpclient.cpp tcphelp.o -o client

service:tcpservice.cpp tcphelp.o
	$(CC) tcpservice.cpp tcphelp.o -o service

tcphelp.o:tcphelp.c tcphelp.h
clean:
	rm *.exe *.o