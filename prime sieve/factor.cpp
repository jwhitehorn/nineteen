//Test program to test prime_sieve
//The program takes an inputed number, and checks it for divisibility
//by only prime numbers. Prime numbers are determined by successful 
//insertion into the prime_sieve list.


#include <iostream>
#include "primeS.h"
#include <math.h> 
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

int main(){
	prime_sieve< long unsigned int > list;
	long unsigned int number;
	long unsigned int stop;
	bool prime = true;
	int len;

	cout << "Factor test program.\n";
	cout << "Please input a number to factor.\n\n";
	cin >> number;
	cout << "Calculating stoping point... ";
	stop = sqrt(number)+1;
	cout << stop << endl;
	cout << "Factoring " << number << "...\n\n";

	list.insert(2);
	if(number % 2 == 0){
		cout << 2 << " * " << number / 2 << endl;
		prime = false;
	}

	len = time(0);

//quadratic sieve sample
	for(long unsigned int i = 3; i < stop; i+=2){	//count by odds
		if(list.insert(i) == 0){
			if(number % i == 0){
				cout << i << " * " << number / i << endl;
				prime = false;
			}
		}
	}
	if(prime)
		cout << "The number is prime.\n";
	cout << "Found in less than " << time(0) - len + 1 << " sec(s).\n";
	while(true){}

	return 0;
}