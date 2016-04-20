CC=gcc

All:client service
	
client:
	$(CC) tcpclient.cpp *.c -o client

service:
	$(CC) tcpservice.cpp *.c -o service
