#ifndef PRIME_SIEVE
#define PRIME_SIEVE

template <class T>
struct PrimeNode{
public:
	PrimeNode<T> * down;
	T data;
};

template <class T>
class prime_sieve{
public:
	prime_sieve<T>(){	//default constructor
		TopPtr = NULL;
		OutPtr = NULL;
	}
	T insert(T item){
	//insert new item
	//if item is not prime, it will return its first factor
	//if it is prime, then it will return 0
		PrimeNode<T> * current = TopPtr;
		PrimeNode<T> * prev = NULL;
		while(current != NULL){	//loop until we hit the bottom
			if( item % (*current).data == 0 ){	//if we find an item evenly divisable
				return (*current).data;	//return the item
			}
			prev = current;
			current = (*current).down;	//else, we should continue downward
		}
		//well, it must be prime
		if(prev == NULL){	//if the prime_sieve is empty
			TopPtr = new PrimeNode<T>;	//create a new node
			(*TopPtr).data = item;		//and set the data
			(*TopPtr).down = NULL;		//maintain the Node Structure
		}else{	//else, their is already primes in the sieve
			(*prev).down = new PrimeNode<T>;	//create a new node
			(*(*prev).down).data = item;		//and set the data
			(*(*prev).down).down = NULL;		//maintain the Node Structure
		}
		return 0;	//we inserted it

	}
	T getNext(bool reset = false){
		if(reset){	//if they want to reset out position
			OutPtr = NULL;	//then we just reset the pointer
		}
		if(OutPtr == NULL){	//either this is our first time, or we just reseted
			OutPtr = TopPtr;
		}
		if(OutPtr == NULL){	//if it is still null, then the sieve is emtpy
			return 0;	//return empty
		}
		//else
		T tempData = (*OutPtr).data;
		OutPtr = (*OutPtr).down;
		return tempData;
	}
private:
	PrimeNode<T> * TopPtr;
	PrimeNode<T> * OutPtr;
};

#endif