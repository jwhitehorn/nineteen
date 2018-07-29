//#include "int64.h"
#include <iostream>
//#include <ctime>


//using std::cout;
using std::endl;
//using std::cin;

int main(){
	prime_sieve< long unsigned int > list;
	long unsigned int number;
	long unsigned int stop;
	bool prime = true;
	int len;

	std::cout << "Factor test program.\n";
	std::cout << "Please input a number to factor.\n\n";
	std::cin >> number;
	std::cout << "Calculating stoping point... ";
//	stop = sqrt(number)+1;
	stop = number / 2;
	std::cout << stop << endl;
	std::cout << "Factoring " << number << "...\n\n";

	list.insert(2);
	if(number % 2 == 0){
		std::cout << 2 << " * " << number / 2 << std::endl;
		prime = false;
	}

	len = time(0);

//quadratic sieve sample
	for(long unsigned int i = 3; i < stop; i+=2){	//count by odds
		if(list.insert(i) == 0){
			if(number % i == 0){
				std::cout << i << " * " << number / i << std::endl;
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