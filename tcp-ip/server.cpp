#include <iostream>
#include "network.h"
#include "math.h"

using std::endl;
using std::cout;
using std::cin;

struct user_info{
	bool connected;
	SOCKET s;
	char buffer[256];
	int last_responce;
	char ip[17];

	long unsigned int number;
};

int main(){
	char ip[30];
	char server_name[80];

	user_info con_table[FD_SETSIZE];	//connection table set to max allowed size (64 on WinNT)
	int con_table_size = 0;				//keep track of the connection tables size

	char buffer[256];
	network lan(2048);
	SOCKET incoming = NULL;
	int value;
	bool error = false;

	long unsigned int number;
	long unsigned int current = 2;
	long unsigned int stop;

	int wait = time(0);

	lan.WhoAmI(server_name, ip);

	cout << "Server Version 0.1\n";
	cout << "Copyright 2002, Jason Whitehorn\n";

	cout << "Server Name: " << server_name << endl;
	cout << "Server IP: " << ip << endl << endl;

	cout << "Please enter a number to factor\n";
	cin >> number;
	cout << "Computing stoping point...";
	stop = sqrt(number);
	cout << "DONE.\n";

	cout << "Wait for clients...\n";


	while(current < stop){
		lan.clear(buffer, 256);
		lan.clear(ip, 30);

		if(time(0) - wait >= 40){
			if(con_table_size >= 0){
				cout << current << "|" << stop << ": " << float(current) / float(stop) * float(100) << "%" << endl;
				wait = time(0);
			}
		}

		incoming = lan.TCPReceive(buffer, ip, 2);		//check for incoming transmission
//new connection IF/LOOP
		if(incoming != NULL){	//incoming transmission received
			for(int i = 0; i != con_table_size; i++){	//loop for the entire connection table
				//look to see if allready connected
				if(strcmp(con_table[i].ip, ip) == 0){	//if we already have a connection from that IP address
					lan.TCPSend("ALC", incoming);		//respond that multiple connection are not allowed
					error = true;
				}
			}
			if(!error){	//if they were not allready connected
				strcpy(con_table[con_table_size].buffer, buffer);	//copy buffer info
				con_table[con_table_size].connected = false;		//by default a user is not connected
				strcpy(con_table[con_table_size].ip, ip);			//keep a copy of their IP address
				con_table[con_table_size].last_responce = time(0);	//keep track of the time for disconnecting udle users
				con_table[con_table_size].s = incoming;				//keep a copy of the socket for easy communications
				con_table_size++;
			}
			error = false;		//reset the error flag
		}
	//connection maintaince LOOP
		for(int i = 0; i < con_table_size; i++){	//loop for the entire connection table
			//PARSE connection buffer
			if(strcmp(con_table[i].buffer, "CON") == 0){	//if user is trying to connect
				if(con_table[i].connected == false){		//and they have not already connected
					cout << con_table[i].ip << " connected\n";	//post update
					con_table[i].connected = true;				//make a note that they are connected
					con_table[i].last_responce = time(0);		//update last reponce time
				}
			}
			if(strcmp(con_table[i].buffer, "KAL") == 0){	//Keep ALive
				con_table[i].last_responce = time(0);
			}
			if(strcmp(con_table[i].buffer, "WHAT") == 0){	//if they are asking what number we are working on
				itoa(number, buffer, 10);	//store it in an integer in base 10
				lan.TCPSend(buffer, con_table[i].s);	//send data
				con_table[i].last_responce = time(0);	//update time
			}
			if(strcmp(con_table[i].buffer, "GET") == 0){	//if they want a number
				itoa(current, buffer, 10);				//store the current number in a string in base 10
				lan.TCPSend(buffer, con_table[i].s);	//send the data
				con_table[i].last_responce = time(0);	//update time
				current++;		//increase the current number
			}
			if(strcmp(con_table[i].buffer, "TRUE") == 0){	//if they found a factor
				cout << con_table[i].number << endl;	//output the number
				con_table[i].last_responce = time(0);
				con_table[i].number = 0;	//write over the number
			}
			if(strcmp(con_table[i].buffer, "FALSE") == 0){	//if it isnt a factor
				con_table[i].last_responce = time(0);	//update tiem
				con_table[i].number = 0;	//write over the number
			}
			lan.clear(con_table[i].buffer, 256);

			//attempt a new read
			lan.clear(buffer, 256);
			error = false;	//by default assume no error has occured
			value = lan.TCPReceive(buffer, con_table[i].s, 2);	//try reading
			if(value >= 1){	//if data was received
				strcpy(con_table[i].buffer, buffer);	//copy the connection buffer
				con_table[i].last_responce = time(0);	//update time
			}
			if(value == 0)	//this means they disconnected
				error = true;	//so we will remove them soon
			//disconnect dead users
			if(value != 0){	//if no data was received, or an error occured
				if(time(0) - con_table[i].last_responce >= 120){	//if we have not received a responce in 120 secs or more
					error = true;
				}
			}
			if(error){	//if an error occured
				//we need to disconnect them
				cout << con_table[i].ip << " disconnected\n"; //update info
				closesocket(con_table[i].s);	//close socket
				con_table_size--;		//decrease the size of the connection table
				for(int location = i; i != con_table_size; location++){
					//shrink the connection table
					strcpy(con_table[location].buffer, con_table[location+1].buffer);
					con_table[location].connected = con_table[location+1].connected;
					strcpy(con_table[location].ip, con_table[location+1].ip);
					con_table[location].last_responce = con_table[location+1].last_responce;
					con_table[location].s = con_table[location+1].s;
				}
			}
		}//end of connection maintaince LOOP
		lan.clear(buffer, 256);
		error = false;

	}//end of run-time loop

	return 0;
}