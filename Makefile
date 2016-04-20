CC=gcc

client:
	$(CC) tcpclient.cpp *.c -o tcpclient

service:
	$(CC) tcpservice.cpp *.c -o tcpservice
