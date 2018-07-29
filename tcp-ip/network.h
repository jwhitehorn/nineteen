#ifndef NETWORK_H
#define NETWORK_H

#include <winsock.h>
#include <ctime>

#pragma comment(lib, "wsock32.lib")

/*
  Network.h Version 1.01
  Copyright 2002, Jason Whitehorn
  
  initial release
	September 16, 2002 version 0.9

  updates:
	September 17, 2002 version 1.0
		-fixed packet size bug
	September 23, 2002 version 1.01
		-fixed receive data size bug

  Simple C++ class which allows connection oriented
  TCP/IP communications over WinSock version 1.1 or
  higher.
*/

class network{
public:
	network(int port);

	SOCKET TCPReceive(char * data, char * ip_add, int time_out = 1);      // Receive Messages over TCP 
	int TCPReceive(char * data, SOCKET s, int time_out = 1);

	SOCKET connectTo(char * ip_add, int port);
	int TCPSend(char * data, SOCKET s);          // Send Messages over TCP 

	bool WhoAmI(char * name, char * ip);

	void clear(char * string, int len){
		for(int i = 0; i != len; i++)
			string[i] = 0;
	}

private:
	WSADATA w;
	WSADATA wsa;
	SOCKET sock;
	SOCKADDR_IN sock_info;

};	//end of class

network::network(int port){
	WSAStartup(MAKEWORD(1, 1), &wsa);	//startup WSA, and hope it works
	//use WinSock version 1.1
	
	sock = socket(AF_INET, SOCK_STREAM, 0);	//create socket

	sock_info.sin_port = htons(port);	//listen on the port they told us
	sock_info.sin_family = AF_INET;	//using AF_INET
	sock_info.sin_addr.S_un.S_addr = INADDR_ANY;	//listening on all IP address

	bind(sock, (SOCKADDR *)(&sock_info), sizeof(sock_info)); //bind out socket to the port
//	WSAAsyncSelect(sock, NULL, NULL, FD_ACCEPT);	//set the socket to non-blocking mode

	listen(sock, FD_SETSIZE);	//set the port for listening
	//FD_SETSIZE is the max allowed for the listening buffer

}

SOCKET network::TCPReceive(char * data, char * ip_add, int time_out){

	SOCKADDR_IN addr_Cli;	//info for the remote system
	SOCKET sock_Accept;      // another SOCKET for connection acception
	int value;
	int len = sizeof(addr_Cli);
	fd_set set;
	timeval timeOut;

	timeOut.tv_sec = time_out;

	set.fd_array[0] = sock;
	set.fd_count = 1;

	value = select(NULL, &set, NULL, NULL, &timeOut);	//check to see if calling accept or recv will block thread
	if(value == 0)	//if it timed out, then it will block
		return SOCKET(0);
	if(value == SOCKET_ERROR)	//if there was an error, then it will block
		return SOCKET(0);

	int start_time = time(0);
	while(time(0) - start_time < time_out){	//loop until time_out occurs
		sock_Accept = accept(sock, (SOCKADDR *) &addr_Cli, &len); 	//try and accept
		if(sock_Accept != SOCKET_ERROR)	//if we get something that is valid
			break;	//break out of the loop
	}
	if(sock_Accept == SOCKET_ERROR)	//if the socket failed to accept
		return SOCKET(0);	//return false

	start_time = time(0);
	while(time(0) - start_time < time_out){	//loop until time_out occurs
		value = recv(sock_Accept, data, sizeof(data)/sizeof(char)-1, 0);
		if(value != SOCKET_ERROR)	//if we recevie something valid
			break;	//break;
	}
	if(value == SOCKET_ERROR)	//if their was an error
		return SOCKET(0);	//return false

	strcpy(ip_add, inet_ntoa(addr_Cli.sin_addr));

//	strcpy(ip_add, IPString(&addr_Cli, temp, 255));
	
//	closesocket(sock_Accept);      // close the acception socket 
	
	return sock_Accept;	//return the connected socket for future use
}

int network::TCPReceive(char * data, SOCKET s, int time_out){
//returns the bytes received
//or SOCKET_ERROR if no data was present
//or 0 if the remote side closed the socket
	fd_set set;
	timeval timeOut;

	timeOut.tv_sec = time_out;
	set.fd_array[0] = s;
	set.fd_count = 1;

	int value = select(NULL, &set, NULL, NULL, &timeOut);	//check to see if we will block the thread
	if(value == 0)	//i dont know what 0 is suppose to mean, but we dont need it here
		return SOCKET_ERROR;	//we just want to know that it wont work
	if(value == SOCKET_ERROR)
		return SOCKET_ERROR;

	value = recv(s, data, sizeof(data)/sizeof(char)-1, 0);	//recv the data
	
	return value;	//here is the thing we really need, either recv length, 0, or SOCKET_ERROR
}

SOCKET network::connectTo(char * ip_add, int port){
	SOCKET connection = socket(AF_INET, SOCK_STREAM, NULL);	//create a new socket
	SOCKADDR_IN sock_info;
	int value;

	sock_info.sin_family = AF_INET;	//set type
	sock_info.sin_addr.s_addr = inet_addr(ip_add);	//set ip address
	sock_info.sin_port = htons(port);	//set port number in network byte order

	value = connect(connection, (sockaddr * )&sock_info, sizeof(sock_info));	//try and connect
	if(value == SOCKET_ERROR)	//if we failed to connect
		return NULL; //return NULL

	return connection;	//return the connected socket
}

int network::TCPSend(char * data, SOCKET s) { 
//returns bytes sent
//or, SOCKET_ERROR
//or, 0 if remote closed connection
	fd_set set;
	timeval timeOut;
	int value = 0;
	int sum;

	timeOut.tv_sec = 2;

	set.fd_array[0] = s;
	set.fd_count = 1;
/*
	value = select(NULL, &set, NULL, NULL, &timeOut);	//check to see if calling connect or send will block thread
	if(value == 0)	//if it timed out, then it will block
		return SOCKET_ERROR;
	if(value == SOCKET_ERROR)	//if there was an error, then it will block
		return SOCKET_ERROR;*/

	// Send it 
	value = send(s, data, strlen(data), 0); //send the data, record the bytes sent
//send will only send 4bytes, so we have to break the data into chunks
/*	for(int i = 0; i != strlen(data); i++){
		sum = send(s, &data[i], 1, 0);
		if(sum == 0)
			return 0;
		value += sum;
	}*/

	return value; //return value
} 


bool network::WhoAmI(char * name, char * ip){
	HOSTENT * computer;
	int a, b, c, d;
	char temp[4];
	
	gethostname(name, strlen(name));	//get the name of our computer

	computer = gethostbyname(name);
	if(computer == NULL)
		return false;


	a = (int)(*computer).h_addr_list[0][0];
	if(a < 0)
		a += 256;
	b = (int)(*computer).h_addr_list[0][1];
	if(b < 0)
		b += 256;
	c = (int)(*computer).h_addr_list[0][2];
	if(c < 0)
		c += 256;
	d = (int)(*computer).h_addr_list[0][3];
	if(d < 0)
		d += 256;
	
	strcpy(ip, itoa(a, temp, 10));	//copy the first part of the address over
	strcat(ip, ".");	//add a point

	strcat(ip, itoa(b, temp, 10));	//add the next part of the address
	strcat(ip, ".");	//add another point
	
	strcat(ip, itoa(c, temp, 10));	//add the next part
	strcat(ip, ".");	//add the last point
	
	strcat(ip, itoa(d, temp, 10));	//add the last part of the address

	return true;
}

#endif