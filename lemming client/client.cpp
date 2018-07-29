#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <ctime>
#include ".\tcp-ip\network.h"

int main(){
	cout << "Lemming - client version NOV-21-2002.\n";
	cout << "System speed: ";

	float test1 = 0;

	float start = time(0);
	//Calculate the system gigaflops
	while(time(0) - start < 10){
		test1 = test1 + 0.125;	//see how many FLOPS we can do in 10 secs
	}
	test1 = (test1 / 1.25) / 1000000.0;	//then divide that by 10 to get a 1 sec average
	//then divide out so we have gigaflops, not flops

	cout << test1 << " Gigaflops\n";

	cout << "Starting network services...";
	network client(2001);	//attempt to listen to port 2001
	cout << "Done.\n";

	char name[80];
	char ip[14];
	client.WhoAmI(name, ip);
	cout << "Client name: " << name << endl;
	cout << "IP address: " << ip << endl;

	cout << "Looking for server...";
	SOCKET server;

	do{
		//connect to a server at 10.0.0.1 and port 2002
	}while((server = client.connectTo("10.0.0.1", 2002)) == NULL);
	cout << "Done.\n";

	cout << "Connecting to server...";

	bool connected = false;	//we have not connected yet

	char buffer[0xFFFF];	//I/O buffer

	do{
		client.TCPSend("Connect/0.1/1.67772", server);	//send connection request to server
		start = time(0);
		while(time(0) - start < 10){	//give the server up to 10 sec to respond, before resending request
			client.clear(buffer, 0xFFFF);	//clear the buffer
			if(0 < client.TCPReceive(buffer, server) ){	//if we received something
				if( strcmp(buffer, "Ok") == 0){		//if we connected
					connected = true;
					break;	//break out of loop
				}
			}
		}
	}while(!connected);	//loop until we are connected
	cout << "Done.\n";

	cout << "\nLemming online.\n\n";

	while(true){	//run time loop
		client.clear(buffer, 0xFFFF);	//clear the buffer
		do{
			//loop until we receive something
			__asm HLT	;use the HALT opcode to idle the cpu down, so save power and run cooler

			/*
			Check for power down
			IF power is going down, we need to....
			{
				client.TCPSend("Disconnect", server);	//disconnect from the server
				exit(1);	//exit the program
			}
			*/
		}while(0 < client.TCPReceive(buffer, server) );
		//get, we received something

		/*
		..............
		..............
		..............
		..............
		..............
		.execute code.
		..............
		..............
		..............
		..............
		..............
		*/
		client.TCPSend("Done", server);	//tell the server we are done executing their code
	}

	return 0;
}