#include <iostream>

#include "network.h"

using std::cout;
using std::cin;
using std::endl;

int main(){

	network lan(2048);
	char buffer[256];
	char ip[30];
	int wait;

	int number = 3243242;
	int i;

	bool working = false;

	SOCKET server = lan.connectTo("127.0.0.1", 2048);
	if(server == NULL){
		cout << "error\n";
	}
	lan.TCPSend("CON", server);
	while(true){
		lan.TCPSend("WHAT", server);
//		while(lan.TCPReceive(buffer, server) < 0){}	//wait
//		number = atoi(buffer);
		
		while(true){
			lan.clear(buffer, 256);
			lan.TCPSend("GET", server);
			lan.TCPReceive(buffer, server);
			i = atoi(buffer);

			cout << "Factoring ";
			cout << i << endl;
			if( (number / i) * i == number ){
				lan.TCPSend("TRUE", server);
			}else{
				lan.TCPSend("FALSE", server);
			}
		}

	}
	
	return 0;
}