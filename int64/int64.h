#ifndef INT64
#define INT64

//int64 (c) copyright 2002, Jason Whitehorn
//The class seamlessly supports numbers up to 2^3200 - 1 size

#include <iostream>

//using std::ostream;

#include <iomanip.h>
#define SIZE 100	//define our max number of words


class int64{
//class to implement 64-bit numbers
public:
	friend ostream &operator<< ( ostream &out, const int64& item ){
	//function outputs the number in hex. Hex was chosen mainly because it required the least amount
	//of work to get a number, regardless of length, to be outputed.
		bool zero = true;
		out << "0x";
		for(int i = SIZE - 1; i != 0; i--){
			if((item.word[i] == 0) && zero == true){
				//dont do anything
			}else{
				if(!zero){
					
					out << setw(8) << setfill('0') << hex << item.word[i];
				}
				else{
					out << hex << item.word[i];
				}
				zero = false;
			}
		}
		if(!zero){
			out << setw(8) << setfill('0') << hex << item.word[0];	//and we will always print out our last element
		}else
			out << hex << item.word[i];

		return out;
	}

	int64(long unsigned int value = 0){
	//this is our constructor
	//it will zero out all word fields
		word[0] = value;
		for(int i = 1; i != SIZE; i++){
			word[i] = 0;	//zero out all elements
		}
	}

	int64 operator+(const int64 b) const{
	//the plus operator
		int64 result;
		int64 a = (*this);
	
		//we will use some Intel Assembly to allow us to acces the Carry Flag (CF) to allow us to
		//add numbers longer than 1 words length

		//for simplisity, and speed, i used a code bot to create this code
		//unlike looping (which was the only other option) this code saves
		//valuable time by not having to increment a counter (1 clock cycle), check
		// and exit condition (1 clock cycle), if not true jump back up (3 clock cycles)
		// else fall out (1 clock cycle).
		// so this is a total of 1+1+3*999 = 4995 clock cycles + 1 (fall out)
		// for a total of 4996 clock cycles saved on every add.
		__asm{
			MOV EAX, a.word[0]
			MOV EBX, b.word[0]
			ADD EAX, EBX
			MOV result.word[0], EAX

			MOV EAX, a.word[4]	;add the next word, with carry
			MOV EBX, b.word[4]
			ADC EAX, EBX
			MOV result.word[4], EAX

			MOV EAX, a.word[8]	;add the next word, with carry
			MOV EBX, b.word[8]
			ADC EAX, EBX
			MOV result.word[8], EAX

			MOV EAX, a.word[12]	;add the next word, with carry
			MOV EBX, b.word[12]
			ADC EAX, EBX
			MOV result.word[12], EAX

			MOV EAX, a.word[16]	;add the next word, with carry
			MOV EBX, b.word[16]
			ADC EAX, EBX
			MOV result.word[16], EAX

			MOV EAX, a.word[20]	;add the next word, with carry
			MOV EBX, b.word[20]
			ADC EAX, EBX
			MOV result.word[20], EAX

			MOV EAX, a.word[24]	;add the next word, with carry
			MOV EBX, b.word[24]
			ADC EAX, EBX
			MOV result.word[24], EAX

			MOV EAX, a.word[28]	;add the next word, with carry
			MOV EBX, b.word[28]
			ADC EAX, EBX
			MOV result.word[28], EAX

			MOV EAX, a.word[32]	;add the next word, with carry
			MOV EBX, b.word[32]
			ADC EAX, EBX
			MOV result.word[32], EAX

			MOV EAX, a.word[36]	;add the next word, with carry
			MOV EBX, b.word[36]
			ADC EAX, EBX
			MOV result.word[36], EAX

			MOV EAX, a.word[40]	;add the next word, with carry
			MOV EBX, b.word[40]
			ADC EAX, EBX
			MOV result.word[40], EAX

			MOV EAX, a.word[44]	;add the next word, with carry
			MOV EBX, b.word[44]
			ADC EAX, EBX
			MOV result.word[44], EAX

			MOV EAX, a.word[48]	;add the next word, with carry
			MOV EBX, b.word[48]
			ADC EAX, EBX
			MOV result.word[48], EAX

			MOV EAX, a.word[52]	;add the next word, with carry
			MOV EBX, b.word[52]
			ADC EAX, EBX
			MOV result.word[52], EAX

			MOV EAX, a.word[56]	;add the next word, with carry
			MOV EBX, b.word[56]
			ADC EAX, EBX
			MOV result.word[56], EAX

			MOV EAX, a.word[60]	;add the next word, with carry
			MOV EBX, b.word[60]
			ADC EAX, EBX
			MOV result.word[60], EAX

			MOV EAX, a.word[64]	;add the next word, with carry
			MOV EBX, b.word[64]
			ADC EAX, EBX
			MOV result.word[64], EAX

			MOV EAX, a.word[68]	;add the next word, with carry
			MOV EBX, b.word[68]
			ADC EAX, EBX
			MOV result.word[68], EAX

			MOV EAX, a.word[72]	;add the next word, with carry
			MOV EBX, b.word[72]
			ADC EAX, EBX
			MOV result.word[72], EAX

			MOV EAX, a.word[76]	;add the next word, with carry
			MOV EBX, b.word[76]
			ADC EAX, EBX
			MOV result.word[76], EAX

			MOV EAX, a.word[80]	;add the next word, with carry
			MOV EBX, b.word[80]
			ADC EAX, EBX
			MOV result.word[80], EAX

			MOV EAX, a.word[84]	;add the next word, with carry
			MOV EBX, b.word[84]
			ADC EAX, EBX
			MOV result.word[84], EAX

			MOV EAX, a.word[88]	;add the next word, with carry
			MOV EBX, b.word[88]
			ADC EAX, EBX
			MOV result.word[88], EAX

			MOV EAX, a.word[92]	;add the next word, with carry
			MOV EBX, b.word[92]
			ADC EAX, EBX
			MOV result.word[92], EAX

			MOV EAX, a.word[96]	;add the next word, with carry
			MOV EBX, b.word[96]
			ADC EAX, EBX
			MOV result.word[96], EAX

			MOV EAX, a.word[100]	;add the next word, with carry
			MOV EBX, b.word[100]
			ADC EAX, EBX
			MOV result.word[100], EAX

			MOV EAX, a.word[104]	;add the next word, with carry
			MOV EBX, b.word[104]
			ADC EAX, EBX
			MOV result.word[104], EAX

			MOV EAX, a.word[108]	;add the next word, with carry
			MOV EBX, b.word[108]
			ADC EAX, EBX
			MOV result.word[108], EAX

			MOV EAX, a.word[112]	;add the next word, with carry
			MOV EBX, b.word[112]
			ADC EAX, EBX
			MOV result.word[112], EAX

			MOV EAX, a.word[116]	;add the next word, with carry
			MOV EBX, b.word[116]
			ADC EAX, EBX
			MOV result.word[116], EAX

			MOV EAX, a.word[120]	;add the next word, with carry
			MOV EBX, b.word[120]
			ADC EAX, EBX
			MOV result.word[120], EAX

			MOV EAX, a.word[124]	;add the next word, with carry
			MOV EBX, b.word[124]
			ADC EAX, EBX
			MOV result.word[124], EAX

			MOV EAX, a.word[128]	;add the next word, with carry
			MOV EBX, b.word[128]
			ADC EAX, EBX
			MOV result.word[128], EAX

			MOV EAX, a.word[132]	;add the next word, with carry
			MOV EBX, b.word[132]
			ADC EAX, EBX
			MOV result.word[132], EAX

			MOV EAX, a.word[136]	;add the next word, with carry
			MOV EBX, b.word[136]
			ADC EAX, EBX
			MOV result.word[136], EAX

			MOV EAX, a.word[140]	;add the next word, with carry
			MOV EBX, b.word[140]
			ADC EAX, EBX
			MOV result.word[140], EAX

			MOV EAX, a.word[144]	;add the next word, with carry
			MOV EBX, b.word[144]
			ADC EAX, EBX
			MOV result.word[144], EAX

			MOV EAX, a.word[148]	;add the next word, with carry
			MOV EBX, b.word[148]
			ADC EAX, EBX
			MOV result.word[148], EAX

			MOV EAX, a.word[152]	;add the next word, with carry
			MOV EBX, b.word[152]
			ADC EAX, EBX
			MOV result.word[152], EAX

			MOV EAX, a.word[156]	;add the next word, with carry
			MOV EBX, b.word[156]
			ADC EAX, EBX
			MOV result.word[156], EAX

			MOV EAX, a.word[160]	;add the next word, with carry
			MOV EBX, b.word[160]
			ADC EAX, EBX
			MOV result.word[160], EAX

			MOV EAX, a.word[164]	;add the next word, with carry
			MOV EBX, b.word[164]
			ADC EAX, EBX
			MOV result.word[164], EAX

			MOV EAX, a.word[168]	;add the next word, with carry
			MOV EBX, b.word[168]
			ADC EAX, EBX
			MOV result.word[168], EAX

			MOV EAX, a.word[172]	;add the next word, with carry
			MOV EBX, b.word[172]
			ADC EAX, EBX
			MOV result.word[172], EAX

			MOV EAX, a.word[176]	;add the next word, with carry
			MOV EBX, b.word[176]
			ADC EAX, EBX
			MOV result.word[176], EAX

			MOV EAX, a.word[180]	;add the next word, with carry
			MOV EBX, b.word[180]
			ADC EAX, EBX
			MOV result.word[180], EAX

			MOV EAX, a.word[184]	;add the next word, with carry
			MOV EBX, b.word[184]
			ADC EAX, EBX
			MOV result.word[184], EAX

			MOV EAX, a.word[188]	;add the next word, with carry
			MOV EBX, b.word[188]
			ADC EAX, EBX
			MOV result.word[188], EAX

			MOV EAX, a.word[192]	;add the next word, with carry
			MOV EBX, b.word[192]
			ADC EAX, EBX
			MOV result.word[192], EAX

			MOV EAX, a.word[196]	;add the next word, with carry
			MOV EBX, b.word[196]
			ADC EAX, EBX
			MOV result.word[196], EAX

			MOV EAX, a.word[200]	;add the next word, with carry
			MOV EBX, b.word[200]
			ADC EAX, EBX
			MOV result.word[200], EAX

			MOV EAX, a.word[204]	;add the next word, with carry
			MOV EBX, b.word[204]
			ADC EAX, EBX
			MOV result.word[204], EAX

			MOV EAX, a.word[208]	;add the next word, with carry
			MOV EBX, b.word[208]
			ADC EAX, EBX
			MOV result.word[208], EAX

			MOV EAX, a.word[212]	;add the next word, with carry
			MOV EBX, b.word[212]
			ADC EAX, EBX
			MOV result.word[212], EAX

			MOV EAX, a.word[216]	;add the next word, with carry
			MOV EBX, b.word[216]
			ADC EAX, EBX
			MOV result.word[216], EAX

			MOV EAX, a.word[220]	;add the next word, with carry
			MOV EBX, b.word[220]
			ADC EAX, EBX
			MOV result.word[220], EAX

			MOV EAX, a.word[224]	;add the next word, with carry
			MOV EBX, b.word[224]
			ADC EAX, EBX
			MOV result.word[224], EAX

			MOV EAX, a.word[228]	;add the next word, with carry
			MOV EBX, b.word[228]
			ADC EAX, EBX
			MOV result.word[228], EAX

			MOV EAX, a.word[232]	;add the next word, with carry
			MOV EBX, b.word[232]
			ADC EAX, EBX
			MOV result.word[232], EAX

			MOV EAX, a.word[236]	;add the next word, with carry
			MOV EBX, b.word[236]
			ADC EAX, EBX
			MOV result.word[236], EAX

			MOV EAX, a.word[240]	;add the next word, with carry
			MOV EBX, b.word[240]
			ADC EAX, EBX
			MOV result.word[240], EAX

			MOV EAX, a.word[244]	;add the next word, with carry
			MOV EBX, b.word[244]
			ADC EAX, EBX
			MOV result.word[244], EAX

			MOV EAX, a.word[248]	;add the next word, with carry
			MOV EBX, b.word[248]
			ADC EAX, EBX
			MOV result.word[248], EAX

			MOV EAX, a.word[252]	;add the next word, with carry
			MOV EBX, b.word[252]
			ADC EAX, EBX
			MOV result.word[252], EAX

			MOV EAX, a.word[256]	;add the next word, with carry
			MOV EBX, b.word[256]
			ADC EAX, EBX
			MOV result.word[256], EAX

			MOV EAX, a.word[260]	;add the next word, with carry
			MOV EBX, b.word[260]
			ADC EAX, EBX
			MOV result.word[260], EAX

			MOV EAX, a.word[264]	;add the next word, with carry
			MOV EBX, b.word[264]
			ADC EAX, EBX
			MOV result.word[264], EAX

			MOV EAX, a.word[268]	;add the next word, with carry
			MOV EBX, b.word[268]
			ADC EAX, EBX
			MOV result.word[268], EAX

			MOV EAX, a.word[272]	;add the next word, with carry
			MOV EBX, b.word[272]
			ADC EAX, EBX
			MOV result.word[272], EAX

			MOV EAX, a.word[276]	;add the next word, with carry
			MOV EBX, b.word[276]
			ADC EAX, EBX
			MOV result.word[276], EAX

			MOV EAX, a.word[280]	;add the next word, with carry
			MOV EBX, b.word[280]
			ADC EAX, EBX
			MOV result.word[280], EAX

			MOV EAX, a.word[284]	;add the next word, with carry
			MOV EBX, b.word[284]
			ADC EAX, EBX
			MOV result.word[284], EAX

			MOV EAX, a.word[288]	;add the next word, with carry
			MOV EBX, b.word[288]
			ADC EAX, EBX
			MOV result.word[288], EAX

			MOV EAX, a.word[292]	;add the next word, with carry
			MOV EBX, b.word[292]
			ADC EAX, EBX
			MOV result.word[292], EAX

			MOV EAX, a.word[296]	;add the next word, with carry
			MOV EBX, b.word[296]
			ADC EAX, EBX
			MOV result.word[296], EAX

			MOV EAX, a.word[300]	;add the next word, with carry
			MOV EBX, b.word[300]
			ADC EAX, EBX
			MOV result.word[300], EAX

			MOV EAX, a.word[304]	;add the next word, with carry
			MOV EBX, b.word[304]
			ADC EAX, EBX
			MOV result.word[304], EAX

			MOV EAX, a.word[308]	;add the next word, with carry
			MOV EBX, b.word[308]
			ADC EAX, EBX
			MOV result.word[308], EAX

			MOV EAX, a.word[312]	;add the next word, with carry
			MOV EBX, b.word[312]
			ADC EAX, EBX
			MOV result.word[312], EAX

			MOV EAX, a.word[316]	;add the next word, with carry
			MOV EBX, b.word[316]
			ADC EAX, EBX
			MOV result.word[316], EAX

			MOV EAX, a.word[320]	;add the next word, with carry
			MOV EBX, b.word[320]
			ADC EAX, EBX
			MOV result.word[320], EAX

			MOV EAX, a.word[324]	;add the next word, with carry
			MOV EBX, b.word[324]
			ADC EAX, EBX
			MOV result.word[324], EAX

			MOV EAX, a.word[328]	;add the next word, with carry
			MOV EBX, b.word[328]
			ADC EAX, EBX
			MOV result.word[328], EAX

			MOV EAX, a.word[332]	;add the next word, with carry
			MOV EBX, b.word[332]
			ADC EAX, EBX
			MOV result.word[332], EAX

			MOV EAX, a.word[336]	;add the next word, with carry
			MOV EBX, b.word[336]
			ADC EAX, EBX
			MOV result.word[336], EAX

			MOV EAX, a.word[340]	;add the next word, with carry
			MOV EBX, b.word[340]
			ADC EAX, EBX
			MOV result.word[340], EAX

			MOV EAX, a.word[344]	;add the next word, with carry
			MOV EBX, b.word[344]
			ADC EAX, EBX
			MOV result.word[344], EAX

			MOV EAX, a.word[348]	;add the next word, with carry
			MOV EBX, b.word[348]
			ADC EAX, EBX
			MOV result.word[348], EAX

			MOV EAX, a.word[352]	;add the next word, with carry
			MOV EBX, b.word[352]
			ADC EAX, EBX
			MOV result.word[352], EAX

			MOV EAX, a.word[356]	;add the next word, with carry
			MOV EBX, b.word[356]
			ADC EAX, EBX
			MOV result.word[356], EAX

			MOV EAX, a.word[360]	;add the next word, with carry
			MOV EBX, b.word[360]
			ADC EAX, EBX
			MOV result.word[360], EAX

			MOV EAX, a.word[364]	;add the next word, with carry
			MOV EBX, b.word[364]
			ADC EAX, EBX
			MOV result.word[364], EAX

			MOV EAX, a.word[368]	;add the next word, with carry
			MOV EBX, b.word[368]
			ADC EAX, EBX
			MOV result.word[368], EAX

			MOV EAX, a.word[372]	;add the next word, with carry
			MOV EBX, b.word[372]
			ADC EAX, EBX
			MOV result.word[372], EAX

			MOV EAX, a.word[376]	;add the next word, with carry
			MOV EBX, b.word[376]
			ADC EAX, EBX
			MOV result.word[376], EAX

			MOV EAX, a.word[380]	;add the next word, with carry
			MOV EBX, b.word[380]
			ADC EAX, EBX
			MOV result.word[380], EAX

			MOV EAX, a.word[384]	;add the next word, with carry
			MOV EBX, b.word[384]
			ADC EAX, EBX
			MOV result.word[384], EAX

			MOV EAX, a.word[388]	;add the next word, with carry
			MOV EBX, b.word[388]
			ADC EAX, EBX
			MOV result.word[388], EAX

			MOV EAX, a.word[392]	;add the next word, with carry
			MOV EBX, b.word[392]
			ADC EAX, EBX
			MOV result.word[392], EAX

			MOV EAX, a.word[396]	;add the next word, with carry
			MOV EBX, b.word[396]
			ADC EAX, EBX
			MOV result.word[396], EAX

		}
		return result;		//return the int64 value
	}

	int64 operator-(const int64 b) const{
	//the minus operator
		int64 result;
		int64 a = (*this);
		__asm{
			MOV EAX, a.word[0]		;subtract the lower word
			MOV EBX, b.word[0]
			SUB EAX, EBX
			MOV result.word[0], EAX

			MOV EAX, a.word[4]	;subtract the next word, with borrow
			MOV EBX, b.word[4]
			SBB EAX, EBX
			MOV result.word[4], EAX

			MOV EAX, a.word[8]	;subtract the next word, with borrow
			MOV EBX, b.word[8]
			SBB EAX, EBX
			MOV result.word[8], EAX

			MOV EAX, a.word[12]	;subtract the next word, with borrow
			MOV EBX, b.word[12]
			SBB EAX, EBX
			MOV result.word[12], EAX

			MOV EAX, a.word[16]	;subtract the next word, with borrow
			MOV EBX, b.word[16]
			SBB EAX, EBX
			MOV result.word[16], EAX

			MOV EAX, a.word[20]	;subtract the next word, with borrow
			MOV EBX, b.word[20]
			SBB EAX, EBX
			MOV result.word[20], EAX

			MOV EAX, a.word[24]	;subtract the next word, with borrow
			MOV EBX, b.word[24]
			SBB EAX, EBX
			MOV result.word[24], EAX

			MOV EAX, a.word[28]	;subtract the next word, with borrow
			MOV EBX, b.word[28]
			SBB EAX, EBX
			MOV result.word[28], EAX

			MOV EAX, a.word[32]	;subtract the next word, with borrow
			MOV EBX, b.word[32]
			SBB EAX, EBX
			MOV result.word[32], EAX

			MOV EAX, a.word[36]	;subtract the next word, with borrow
			MOV EBX, b.word[36]
			SBB EAX, EBX
			MOV result.word[36], EAX

			MOV EAX, a.word[40]	;subtract the next word, with borrow
			MOV EBX, b.word[40]
			SBB EAX, EBX
			MOV result.word[40], EAX

			MOV EAX, a.word[44]	;subtract the next word, with borrow
			MOV EBX, b.word[44]
			SBB EAX, EBX
			MOV result.word[44], EAX

			MOV EAX, a.word[48]	;subtract the next word, with borrow
			MOV EBX, b.word[48]
			SBB EAX, EBX
			MOV result.word[48], EAX

			MOV EAX, a.word[52]	;subtract the next word, with borrow
			MOV EBX, b.word[52]
			SBB EAX, EBX
			MOV result.word[52], EAX

			MOV EAX, a.word[56]	;subtract the next word, with borrow
			MOV EBX, b.word[56]
			SBB EAX, EBX
			MOV result.word[56], EAX

			MOV EAX, a.word[60]	;subtract the next word, with borrow
			MOV EBX, b.word[60]
			SBB EAX, EBX
			MOV result.word[60], EAX

			MOV EAX, a.word[64]	;subtract the next word, with borrow
			MOV EBX, b.word[64]
			SBB EAX, EBX
			MOV result.word[64], EAX

			MOV EAX, a.word[68]	;subtract the next word, with borrow
			MOV EBX, b.word[68]
			SBB EAX, EBX
			MOV result.word[68], EAX

			MOV EAX, a.word[72]	;subtract the next word, with borrow
			MOV EBX, b.word[72]
			SBB EAX, EBX
			MOV result.word[72], EAX

			MOV EAX, a.word[76]	;subtract the next word, with borrow
			MOV EBX, b.word[76]
			SBB EAX, EBX
			MOV result.word[76], EAX

			MOV EAX, a.word[80]	;subtract the next word, with borrow
			MOV EBX, b.word[80]
			SBB EAX, EBX
			MOV result.word[80], EAX

			MOV EAX, a.word[84]	;subtract the next word, with borrow
			MOV EBX, b.word[84]
			SBB EAX, EBX
			MOV result.word[84], EAX

			MOV EAX, a.word[88]	;subtract the next word, with borrow
			MOV EBX, b.word[88]
			SBB EAX, EBX
			MOV result.word[88], EAX

			MOV EAX, a.word[92]	;subtract the next word, with borrow
			MOV EBX, b.word[92]
			SBB EAX, EBX
			MOV result.word[92], EAX

			MOV EAX, a.word[96]	;subtract the next word, with borrow
			MOV EBX, b.word[96]
			SBB EAX, EBX
			MOV result.word[96], EAX

			MOV EAX, a.word[100]	;subtract the next word, with borrow
			MOV EBX, b.word[100]
			SBB EAX, EBX
			MOV result.word[100], EAX

			MOV EAX, a.word[104]	;subtract the next word, with borrow
			MOV EBX, b.word[104]
			SBB EAX, EBX
			MOV result.word[104], EAX

			MOV EAX, a.word[108]	;subtract the next word, with borrow
			MOV EBX, b.word[108]
			SBB EAX, EBX
			MOV result.word[108], EAX

			MOV EAX, a.word[112]	;subtract the next word, with borrow
			MOV EBX, b.word[112]
			SBB EAX, EBX
			MOV result.word[112], EAX

			MOV EAX, a.word[116]	;subtract the next word, with borrow
			MOV EBX, b.word[116]
			SBB EAX, EBX
			MOV result.word[116], EAX

			MOV EAX, a.word[120]	;subtract the next word, with borrow
			MOV EBX, b.word[120]
			SBB EAX, EBX
			MOV result.word[120], EAX

			MOV EAX, a.word[124]	;subtract the next word, with borrow
			MOV EBX, b.word[124]
			SBB EAX, EBX
			MOV result.word[124], EAX

			MOV EAX, a.word[128]	;subtract the next word, with borrow
			MOV EBX, b.word[128]
			SBB EAX, EBX
			MOV result.word[128], EAX

			MOV EAX, a.word[132]	;subtract the next word, with borrow
			MOV EBX, b.word[132]
			SBB EAX, EBX
			MOV result.word[132], EAX

			MOV EAX, a.word[136]	;subtract the next word, with borrow
			MOV EBX, b.word[136]
			SBB EAX, EBX
			MOV result.word[136], EAX

			MOV EAX, a.word[140]	;subtract the next word, with borrow
			MOV EBX, b.word[140]
			SBB EAX, EBX
			MOV result.word[140], EAX

			MOV EAX, a.word[144]	;subtract the next word, with borrow
			MOV EBX, b.word[144]
			SBB EAX, EBX
			MOV result.word[144], EAX

			MOV EAX, a.word[148]	;subtract the next word, with borrow
			MOV EBX, b.word[148]
			SBB EAX, EBX
			MOV result.word[148], EAX

			MOV EAX, a.word[152]	;subtract the next word, with borrow
			MOV EBX, b.word[152]
			SBB EAX, EBX
			MOV result.word[152], EAX

			MOV EAX, a.word[156]	;subtract the next word, with borrow
			MOV EBX, b.word[156]
			SBB EAX, EBX
			MOV result.word[156], EAX

			MOV EAX, a.word[160]	;subtract the next word, with borrow
			MOV EBX, b.word[160]
			SBB EAX, EBX
			MOV result.word[160], EAX

			MOV EAX, a.word[164]	;subtract the next word, with borrow
			MOV EBX, b.word[164]
			SBB EAX, EBX
			MOV result.word[164], EAX

			MOV EAX, a.word[168]	;subtract the next word, with borrow
			MOV EBX, b.word[168]
			SBB EAX, EBX
			MOV result.word[168], EAX

			MOV EAX, a.word[172]	;subtract the next word, with borrow
			MOV EBX, b.word[172]
			SBB EAX, EBX
			MOV result.word[172], EAX

			MOV EAX, a.word[176]	;subtract the next word, with borrow
			MOV EBX, b.word[176]
			SBB EAX, EBX
			MOV result.word[176], EAX

			MOV EAX, a.word[180]	;subtract the next word, with borrow
			MOV EBX, b.word[180]
			SBB EAX, EBX
			MOV result.word[180], EAX

			MOV EAX, a.word[184]	;subtract the next word, with borrow
			MOV EBX, b.word[184]
			SBB EAX, EBX
			MOV result.word[184], EAX

			MOV EAX, a.word[188]	;subtract the next word, with borrow
			MOV EBX, b.word[188]
			SBB EAX, EBX
			MOV result.word[188], EAX

			MOV EAX, a.word[192]	;subtract the next word, with borrow
			MOV EBX, b.word[192]
			SBB EAX, EBX
			MOV result.word[192], EAX

			MOV EAX, a.word[196]	;subtract the next word, with borrow
			MOV EBX, b.word[196]
			SBB EAX, EBX
			MOV result.word[196], EAX

			MOV EAX, a.word[200]	;subtract the next word, with borrow
			MOV EBX, b.word[200]
			SBB EAX, EBX
			MOV result.word[200], EAX

			MOV EAX, a.word[204]	;subtract the next word, with borrow
			MOV EBX, b.word[204]
			SBB EAX, EBX
			MOV result.word[204], EAX

			MOV EAX, a.word[208]	;subtract the next word, with borrow
			MOV EBX, b.word[208]
			SBB EAX, EBX
			MOV result.word[208], EAX

			MOV EAX, a.word[212]	;subtract the next word, with borrow
			MOV EBX, b.word[212]
			SBB EAX, EBX
			MOV result.word[212], EAX

			MOV EAX, a.word[216]	;subtract the next word, with borrow
			MOV EBX, b.word[216]
			SBB EAX, EBX
			MOV result.word[216], EAX

			MOV EAX, a.word[220]	;subtract the next word, with borrow
			MOV EBX, b.word[220]
			SBB EAX, EBX
			MOV result.word[220], EAX

			MOV EAX, a.word[224]	;subtract the next word, with borrow
			MOV EBX, b.word[224]
			SBB EAX, EBX
			MOV result.word[224], EAX

			MOV EAX, a.word[228]	;subtract the next word, with borrow
			MOV EBX, b.word[228]
			SBB EAX, EBX
			MOV result.word[228], EAX

			MOV EAX, a.word[232]	;subtract the next word, with borrow
			MOV EBX, b.word[232]
			SBB EAX, EBX
			MOV result.word[232], EAX

			MOV EAX, a.word[236]	;subtract the next word, with borrow
			MOV EBX, b.word[236]
			SBB EAX, EBX
			MOV result.word[236], EAX

			MOV EAX, a.word[240]	;subtract the next word, with borrow
			MOV EBX, b.word[240]
			SBB EAX, EBX
			MOV result.word[240], EAX

			MOV EAX, a.word[244]	;subtract the next word, with borrow
			MOV EBX, b.word[244]
			SBB EAX, EBX
			MOV result.word[244], EAX

			MOV EAX, a.word[248]	;subtract the next word, with borrow
			MOV EBX, b.word[248]
			SBB EAX, EBX
			MOV result.word[248], EAX

			MOV EAX, a.word[252]	;subtract the next word, with borrow
			MOV EBX, b.word[252]
			SBB EAX, EBX
			MOV result.word[252], EAX

			MOV EAX, a.word[256]	;subtract the next word, with borrow
			MOV EBX, b.word[256]
			SBB EAX, EBX
			MOV result.word[256], EAX

			MOV EAX, a.word[260]	;subtract the next word, with borrow
			MOV EBX, b.word[260]
			SBB EAX, EBX
			MOV result.word[260], EAX

			MOV EAX, a.word[264]	;subtract the next word, with borrow
			MOV EBX, b.word[264]
			SBB EAX, EBX
			MOV result.word[264], EAX

			MOV EAX, a.word[268]	;subtract the next word, with borrow
			MOV EBX, b.word[268]
			SBB EAX, EBX
			MOV result.word[268], EAX

			MOV EAX, a.word[272]	;subtract the next word, with borrow
			MOV EBX, b.word[272]
			SBB EAX, EBX
			MOV result.word[272], EAX

			MOV EAX, a.word[276]	;subtract the next word, with borrow
			MOV EBX, b.word[276]
			SBB EAX, EBX
			MOV result.word[276], EAX

			MOV EAX, a.word[280]	;subtract the next word, with borrow
			MOV EBX, b.word[280]
			SBB EAX, EBX
			MOV result.word[280], EAX

			MOV EAX, a.word[284]	;subtract the next word, with borrow
			MOV EBX, b.word[284]
			SBB EAX, EBX
			MOV result.word[284], EAX

			MOV EAX, a.word[288]	;subtract the next word, with borrow
			MOV EBX, b.word[288]
			SBB EAX, EBX
			MOV result.word[288], EAX

			MOV EAX, a.word[292]	;subtract the next word, with borrow
			MOV EBX, b.word[292]
			SBB EAX, EBX
			MOV result.word[292], EAX

			MOV EAX, a.word[296]	;subtract the next word, with borrow
			MOV EBX, b.word[296]
			SBB EAX, EBX
			MOV result.word[296], EAX

			MOV EAX, a.word[300]	;subtract the next word, with borrow
			MOV EBX, b.word[300]
			SBB EAX, EBX
			MOV result.word[300], EAX

			MOV EAX, a.word[304]	;subtract the next word, with borrow
			MOV EBX, b.word[304]
			SBB EAX, EBX
			MOV result.word[304], EAX

			MOV EAX, a.word[308]	;subtract the next word, with borrow
			MOV EBX, b.word[308]
			SBB EAX, EBX
			MOV result.word[308], EAX

			MOV EAX, a.word[312]	;subtract the next word, with borrow
			MOV EBX, b.word[312]
			SBB EAX, EBX
			MOV result.word[312], EAX

			MOV EAX, a.word[316]	;subtract the next word, with borrow
			MOV EBX, b.word[316]
			SBB EAX, EBX
			MOV result.word[316], EAX

			MOV EAX, a.word[320]	;subtract the next word, with borrow
			MOV EBX, b.word[320]
			SBB EAX, EBX
			MOV result.word[320], EAX

			MOV EAX, a.word[324]	;subtract the next word, with borrow
			MOV EBX, b.word[324]
			SBB EAX, EBX
			MOV result.word[324], EAX

			MOV EAX, a.word[328]	;subtract the next word, with borrow
			MOV EBX, b.word[328]
			SBB EAX, EBX
			MOV result.word[328], EAX

			MOV EAX, a.word[332]	;subtract the next word, with borrow
			MOV EBX, b.word[332]
			SBB EAX, EBX
			MOV result.word[332], EAX

			MOV EAX, a.word[336]	;subtract the next word, with borrow
			MOV EBX, b.word[336]
			SBB EAX, EBX
			MOV result.word[336], EAX

			MOV EAX, a.word[340]	;subtract the next word, with borrow
			MOV EBX, b.word[340]
			SBB EAX, EBX
			MOV result.word[340], EAX

			MOV EAX, a.word[344]	;subtract the next word, with borrow
			MOV EBX, b.word[344]
			SBB EAX, EBX
			MOV result.word[344], EAX

			MOV EAX, a.word[348]	;subtract the next word, with borrow
			MOV EBX, b.word[348]
			SBB EAX, EBX
			MOV result.word[348], EAX

			MOV EAX, a.word[352]	;subtract the next word, with borrow
			MOV EBX, b.word[352]
			SBB EAX, EBX
			MOV result.word[352], EAX

			MOV EAX, a.word[356]	;subtract the next word, with borrow
			MOV EBX, b.word[356]
			SBB EAX, EBX
			MOV result.word[356], EAX

			MOV EAX, a.word[360]	;subtract the next word, with borrow
			MOV EBX, b.word[360]
			SBB EAX, EBX
			MOV result.word[360], EAX

			MOV EAX, a.word[364]	;subtract the next word, with borrow
			MOV EBX, b.word[364]
			SBB EAX, EBX
			MOV result.word[364], EAX

			MOV EAX, a.word[368]	;subtract the next word, with borrow
			MOV EBX, b.word[368]
			SBB EAX, EBX
			MOV result.word[368], EAX

			MOV EAX, a.word[372]	;subtract the next word, with borrow
			MOV EBX, b.word[372]
			SBB EAX, EBX
			MOV result.word[372], EAX

			MOV EAX, a.word[376]	;subtract the next word, with borrow
			MOV EBX, b.word[376]
			SBB EAX, EBX
			MOV result.word[376], EAX

			MOV EAX, a.word[380]	;subtract the next word, with borrow
			MOV EBX, b.word[380]
			SBB EAX, EBX
			MOV result.word[380], EAX

			MOV EAX, a.word[384]	;subtract the next word, with borrow
			MOV EBX, b.word[384]
			SBB EAX, EBX
			MOV result.word[384], EAX

			MOV EAX, a.word[388]	;subtract the next word, with borrow
			MOV EBX, b.word[388]
			SBB EAX, EBX
			MOV result.word[388], EAX

			MOV EAX, a.word[392]	;subtract the next word, with borrow
			MOV EBX, b.word[392]
			SBB EAX, EBX
			MOV result.word[392], EAX

			MOV EAX, a.word[396]	;subtract the next word, with borrow
			MOV EBX, b.word[396]
			SBB EAX, EBX
			MOV result.word[396], EAX
		}
		return result;	//return the int64 result
	}

	int64 operator*(const int64 b) const{
	//multiplication operator
		int64 result;
		int64 temp;
//		int64 a = (*this);
		struct{
		long unsigned int low, high;
		} wordPair;

		for(int i = 0; i != SIZE; i++){
			for(int x = 0; x != SIZE; x++){

				if((*this).word[i] == 0 || b.word[x] == 0){
					//do nothing
				}else{

					wordPair.low = (*this).word[i];		//load high and low word pairs
					wordPair.high = b.word[x];

					__asm{

						MOV EAX, wordPair.low
						MOV EBX, wordPair.high
						MUL EBX
						MOV wordPair.low, EAX		;copy out low word
						MOV wordPair.high, EDX		;copy out high word
					}

					temp.word[i] =	wordPair.low;			//set temp with low word
					if(i+1 < SIZE)							//we dont want to fall off the end
						temp.word[i+1] = wordPair.high;		//and high word

					result = result + temp;					//add to the result
	
					temp.word[i] = 0;
					if(i+1 < SIZE)
						temp.word[i+1] = 0;
				}
			}
		}

		return result;	//done
	}
	int64 operator/(const int64 b) const{
/*		int64 rem = b;
		int64 result = 1;
		int64 a = (*this);
		while(result * b < a)
			result.ShiftL();
		while(result * b > a)
			result = result - 1;*/

		if(b == 0)	// you can not divide by zero, so we will want to check for that
			return 0;
		if(b == 1)	//also, we want to do this to save some time
			return (*this);

		int64 result = 0;
		int64 rem = (*this);
		while( rem >= b){
			result = result + 1;	//increment product by 1
			rem = rem - b;
		}
/*		int64 p;
		p.word[SIZE - 1] = 1;	//load 1 into the least significant bit of the most significant word
//		p.word[SIZE - 1] = 0x80000000;
		__asm{
			MOV EAX, p.word[396]
			ROR EAX, 1	;rotate the 1 bit into the highest order position
			MOV p.word[396], EAX

		go_left:
		;first we need to shift the number over left until we set our final carry out flag

			MOV EAX, a.word[0]	;load from memory
			SHL EAX, 1			;Shift Left 1 bit, dropped bit is stored in the CF
			MOV a.word[0], EAX

			MOV EAX, a.word[4]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[4], EAX

			MOV EAX, a.word[8]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[8], EAX

			MOV EAX, a.word[12]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[12], EAX

			MOV EAX, a.word[16]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[16], EAX

			MOV EAX, a.word[20]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[20], EAX

			MOV EAX, a.word[24]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[24], EAX

			MOV EAX, a.word[28]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[28], EAX

			MOV EAX, a.word[32]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[32], EAX

			MOV EAX, a.word[36]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[36], EAX

			MOV EAX, a.word[40]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[40], EAX

			MOV EAX, a.word[44]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[44], EAX

			MOV EAX, a.word[48]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[48], EAX

			MOV EAX, a.word[52]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[52], EAX

			MOV EAX, a.word[56]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[56], EAX

			MOV EAX, a.word[60]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[60], EAX

			MOV EAX, a.word[64]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[64], EAX

			MOV EAX, a.word[68]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[68], EAX

			MOV EAX, a.word[72]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[72], EAX

			MOV EAX, a.word[76]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[76], EAX

			MOV EAX, a.word[80]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[80], EAX

			MOV EAX, a.word[84]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[84], EAX

			MOV EAX, a.word[88]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[88], EAX

			MOV EAX, a.word[92]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[92], EAX

			MOV EAX, a.word[96]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[96], EAX

			MOV EAX, a.word[100]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[100], EAX

			MOV EAX, a.word[104]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[104], EAX

			MOV EAX, a.word[108]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[108], EAX

			MOV EAX, a.word[112]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[112], EAX

			MOV EAX, a.word[116]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[116], EAX

			MOV EAX, a.word[120]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[120], EAX

			MOV EAX, a.word[124]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[124], EAX

			MOV EAX, a.word[128]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[128], EAX

			MOV EAX, a.word[132]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[132], EAX

			MOV EAX, a.word[136]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[136], EAX

			MOV EAX, a.word[140]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[140], EAX

			MOV EAX, a.word[144]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[144], EAX

			MOV EAX, a.word[148]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[148], EAX

			MOV EAX, a.word[152]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[152], EAX

			MOV EAX, a.word[156]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[156], EAX

			MOV EAX, a.word[160]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[160], EAX

			MOV EAX, a.word[164]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[164], EAX

			MOV EAX, a.word[168]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[168], EAX

			MOV EAX, a.word[172]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[172], EAX

			MOV EAX, a.word[176]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[176], EAX

			MOV EAX, a.word[180]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[180], EAX

			MOV EAX, a.word[184]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[184], EAX

			MOV EAX, a.word[188]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[188], EAX

			MOV EAX, a.word[192]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[192], EAX

			MOV EAX, a.word[196]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[196], EAX

			MOV EAX, a.word[200]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[200], EAX

			MOV EAX, a.word[204]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[204], EAX

			MOV EAX, a.word[208]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[208], EAX

			MOV EAX, a.word[212]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[212], EAX

			MOV EAX, a.word[216]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[216], EAX

			MOV EAX, a.word[220]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[220], EAX

			MOV EAX, a.word[224]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[224], EAX

			MOV EAX, a.word[228]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[228], EAX

			MOV EAX, a.word[232]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[232], EAX

			MOV EAX, a.word[236]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[236], EAX

			MOV EAX, a.word[240]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[240], EAX

			MOV EAX, a.word[244]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[244], EAX

			MOV EAX, a.word[248]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[248], EAX

			MOV EAX, a.word[252]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[252], EAX

			MOV EAX, a.word[256]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[256], EAX

			MOV EAX, a.word[260]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[260], EAX

			MOV EAX, a.word[264]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[264], EAX

			MOV EAX, a.word[268]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[268], EAX

			MOV EAX, a.word[272]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[272], EAX

			MOV EAX, a.word[276]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[276], EAX

			MOV EAX, a.word[280]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[280], EAX

			MOV EAX, a.word[284]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[284], EAX

			MOV EAX, a.word[288]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[288], EAX

			MOV EAX, a.word[292]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[292], EAX

			MOV EAX, a.word[296]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[296], EAX

			MOV EAX, a.word[300]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[300], EAX

			MOV EAX, a.word[304]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[304], EAX

			MOV EAX, a.word[308]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[308], EAX

			MOV EAX, a.word[312]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[312], EAX

			MOV EAX, a.word[316]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[316], EAX

			MOV EAX, a.word[320]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[320], EAX

			MOV EAX, a.word[324]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[324], EAX

			MOV EAX, a.word[328]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[328], EAX

			MOV EAX, a.word[332]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[332], EAX

			MOV EAX, a.word[336]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[336], EAX

			MOV EAX, a.word[340]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[340], EAX

			MOV EAX, a.word[344]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[344], EAX

			MOV EAX, a.word[348]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[348], EAX

			MOV EAX, a.word[352]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[352], EAX

			MOV EAX, a.word[356]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[356], EAX

			MOV EAX, a.word[360]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[360], EAX

			MOV EAX, a.word[364]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[364], EAX

			MOV EAX, a.word[368]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[368], EAX

			MOV EAX, a.word[372]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[372], EAX

			MOV EAX, a.word[376]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[376], EAX

			MOV EAX, a.word[380]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[380], EAX

			MOV EAX, a.word[384]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[384], EAX

			MOV EAX, a.word[388]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[388], EAX

			MOV EAX, a.word[392]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[392], EAX

			MOV EAX, a.word[396]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[396], EAX

			MOV EBX, 0	;load register b with zero
			ADC EBX, 0	;get ahold of our carry flag
			CMP EBX, 0	;if our carry flag was 0, continue
			JE go_left	;if equal, continue
			;else, we carried a number off the end, we need to go right once

			STC		; we need to set the carry flag, because we have lost it when we compared
			
			;however, unlike our normal shift right function, we want the highest order word to also
			;rotate through our carry flag so we can restore the number
			MOV EAX, a.word[396]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[396], EAX

			MOV EAX, a.word[392]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[392], EAX

			MOV EAX, a.word[388]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[388], EAX

			MOV EAX, a.word[384]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[384], EAX

			MOV EAX, a.word[380]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[380], EAX

			MOV EAX, a.word[376]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[376], EAX

			MOV EAX, a.word[372]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[372], EAX

			MOV EAX, a.word[368]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[368], EAX

			MOV EAX, a.word[364]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[364], EAX

			MOV EAX, a.word[360]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[360], EAX

			MOV EAX, a.word[356]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[356], EAX

			MOV EAX, a.word[352]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[352], EAX

			MOV EAX, a.word[348]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[348], EAX

			MOV EAX, a.word[344]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[344], EAX

			MOV EAX, a.word[340]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[340], EAX

			MOV EAX, a.word[336]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[336], EAX

			MOV EAX, a.word[332]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[332], EAX

			MOV EAX, a.word[328]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[328], EAX

			MOV EAX, a.word[324]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[324], EAX

			MOV EAX, a.word[320]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[320], EAX

			MOV EAX, a.word[316]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[316], EAX

			MOV EAX, a.word[312]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[312], EAX

			MOV EAX, a.word[308]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[308], EAX

			MOV EAX, a.word[304]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[304], EAX

			MOV EAX, a.word[300]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[300], EAX

			MOV EAX, a.word[296]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[296], EAX

			MOV EAX, a.word[292]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[292], EAX

			MOV EAX, a.word[288]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[288], EAX

			MOV EAX, a.word[284]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[284], EAX

			MOV EAX, a.word[280]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[280], EAX

			MOV EAX, a.word[276]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[276], EAX

			MOV EAX, a.word[272]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[272], EAX

			MOV EAX, a.word[268]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[268], EAX

			MOV EAX, a.word[264]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[264], EAX

			MOV EAX, a.word[260]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[260], EAX

			MOV EAX, a.word[256]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[256], EAX

			MOV EAX, a.word[252]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[252], EAX

			MOV EAX, a.word[248]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[248], EAX

			MOV EAX, a.word[244]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[244], EAX

			MOV EAX, a.word[240]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[240], EAX

			MOV EAX, a.word[236]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[236], EAX

			MOV EAX, a.word[232]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[232], EAX

			MOV EAX, a.word[228]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[228], EAX

			MOV EAX, a.word[224]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[224], EAX

			MOV EAX, a.word[220]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[220], EAX

			MOV EAX, a.word[216]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[216], EAX

			MOV EAX, a.word[212]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[212], EAX

			MOV EAX, a.word[208]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[208], EAX

			MOV EAX, a.word[204]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[204], EAX

			MOV EAX, a.word[200]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[200], EAX

			MOV EAX, a.word[196]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[196], EAX

			MOV EAX, a.word[192]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[192], EAX

			MOV EAX, a.word[188]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[188], EAX

			MOV EAX, a.word[184]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[184], EAX

			MOV EAX, a.word[180]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[180], EAX

			MOV EAX, a.word[176]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[176], EAX

			MOV EAX, a.word[172]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[172], EAX

			MOV EAX, a.word[168]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[168], EAX

			MOV EAX, a.word[164]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[164], EAX

			MOV EAX, a.word[160]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[160], EAX

			MOV EAX, a.word[156]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[156], EAX

			MOV EAX, a.word[152]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[152], EAX

			MOV EAX, a.word[148]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[148], EAX

			MOV EAX, a.word[144]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[144], EAX

			MOV EAX, a.word[140]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[140], EAX

			MOV EAX, a.word[136]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[136], EAX

			MOV EAX, a.word[132]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[132], EAX

			MOV EAX, a.word[128]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[128], EAX

			MOV EAX, a.word[124]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[124], EAX

			MOV EAX, a.word[120]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[120], EAX

			MOV EAX, a.word[116]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[116], EAX

			MOV EAX, a.word[112]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[112], EAX

			MOV EAX, a.word[108]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[108], EAX

			MOV EAX, a.word[104]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[104], EAX

			MOV EAX, a.word[100]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[100], EAX

			MOV EAX, a.word[96]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[96], EAX

			MOV EAX, a.word[92]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[92], EAX

			MOV EAX, a.word[88]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[88], EAX

			MOV EAX, a.word[84]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[84], EAX

			MOV EAX, a.word[80]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[80], EAX

			MOV EAX, a.word[76]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[76], EAX

			MOV EAX, a.word[72]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[72], EAX

			MOV EAX, a.word[68]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[68], EAX

			MOV EAX, a.word[64]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[64], EAX

			MOV EAX, a.word[60]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[60], EAX

			MOV EAX, a.word[56]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[56], EAX

			MOV EAX, a.word[52]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[52], EAX

			MOV EAX, a.word[48]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[48], EAX

			MOV EAX, a.word[44]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[44], EAX

			MOV EAX, a.word[40]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[40], EAX

			MOV EAX, a.word[36]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[36], EAX

			MOV EAX, a.word[32]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[32], EAX

			MOV EAX, a.word[28]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[28], EAX

			MOV EAX, a.word[24]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[24], EAX

			MOV EAX, a.word[20]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[20], EAX

			MOV EAX, a.word[16]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[16], EAX

			MOV EAX, a.word[12]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[12], EAX

			MOV EAX, a.word[8]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[8], EAX

			MOV EAX, a.word[4]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[4], EAX

			MOV EAX, a.word[0]
			RCR EAX, 1
			MOV a.word[0], EAX

			;now we have our number, shifted all the way to the left
		}
//		int test = 0;
		while(p != 0){	//while our pointer does not equal zero
			if(rem > a)	{	//if we can divide into it
				rem = rem - a;	//subtract it out
				result = result + p;	//add our pointer to the result
			}else{			//else, we cant
				//do nothing
			}
			p.ShiftR();	//shift our pointer right one bit
			a.ShiftR();	//shift our number over one bit also
//			test++;
		}
//		if(test == 0)
//			result = 0x1982;
*/
		return result;
//		return a;
	}//END OF DIVISION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	int64 operator%(const int64 b) const{
		if(b == 0)	// you can not divide by zero, so we will want to check for that
			return 0;
		if(b == 1)	//also, we want to do this to save some time
			return 0;

		int64 result = 0;
		int64 rem = (*this);
		while( rem >= b){
			result = result + 1;	//increment product by 1
			rem = rem - b;
		}
		return rem;	//return the remander
	}

	bool operator>(const int64 b) const{
		int result = (*this).relation(b);	//find our relationship with b
		if(result == 1){//if we are greater than
			return true;
		}else{	//else we are either equal or less than b
			return false;
		}
	}
	bool operator>=(const int64 b)const{
		int result = (*this).relation(b);	//find our relationship with b
		if( (result == 1) || (result == 0) ){	//if we are either greater than or equal
			return true;
		}else{	//else, we are greater than
			return false;
		}
	}
	bool operator<(const int64 b)const{
		int result = (*this).relation(b);	//find our relationship with b
		if(result == -1){	//if we are less than
			return true;
		}else{				//we are either greater than or equal to b
			return false;
		}
	}
	bool operator<=(const int64 b)const{
		int result = (*this).relation(b);	//find our relationship with b
		if( (result == -1) || (result == 0) ){	//if we are less than or equal
			return true;
		}else{	//else, we are greater than
			return false;
		}
	}
	bool operator==(const int64 b)const{
		int result = (*this).relation(b);	//find our relationship with b
		if(result == 0){	//if we are equal
			return true;
		}else{	//we are either greater than or less than
			return false;
		}
	}
	bool operator!=(const int64 b)const{
		int result = (*this).relation(b);	//find our relationship with b
		if(result != 0){	//if we are not equal
			return true;
		}else{			//else, we are equal
			return false;
		}
	}
	void ShiftR(){
	//Shift right 1 bit
		int64 a = (*this);
		__asm{
			MOV EAX, a.word[396]	;load from memory
			SHR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[396], EAX

			MOV EAX, a.word[392]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[392], EAX

			MOV EAX, a.word[388]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[388], EAX

			MOV EAX, a.word[384]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[384], EAX

			MOV EAX, a.word[380]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[380], EAX

			MOV EAX, a.word[376]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[376], EAX

			MOV EAX, a.word[372]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[372], EAX

			MOV EAX, a.word[368]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[368], EAX

			MOV EAX, a.word[364]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[364], EAX

			MOV EAX, a.word[360]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[360], EAX

			MOV EAX, a.word[356]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[356], EAX

			MOV EAX, a.word[352]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[352], EAX

			MOV EAX, a.word[348]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[348], EAX

			MOV EAX, a.word[344]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[344], EAX

			MOV EAX, a.word[340]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[340], EAX

			MOV EAX, a.word[336]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[336], EAX

			MOV EAX, a.word[332]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[332], EAX

			MOV EAX, a.word[328]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[328], EAX

			MOV EAX, a.word[324]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[324], EAX

			MOV EAX, a.word[320]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[320], EAX

			MOV EAX, a.word[316]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[316], EAX

			MOV EAX, a.word[312]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[312], EAX

			MOV EAX, a.word[308]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[308], EAX

			MOV EAX, a.word[304]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[304], EAX

			MOV EAX, a.word[300]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[300], EAX

			MOV EAX, a.word[296]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[296], EAX

			MOV EAX, a.word[292]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[292], EAX

			MOV EAX, a.word[288]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[288], EAX

			MOV EAX, a.word[284]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[284], EAX

			MOV EAX, a.word[280]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[280], EAX

			MOV EAX, a.word[276]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[276], EAX

			MOV EAX, a.word[272]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[272], EAX

			MOV EAX, a.word[268]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[268], EAX

			MOV EAX, a.word[264]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[264], EAX

			MOV EAX, a.word[260]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[260], EAX

			MOV EAX, a.word[256]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[256], EAX

			MOV EAX, a.word[252]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[252], EAX

			MOV EAX, a.word[248]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[248], EAX

			MOV EAX, a.word[244]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[244], EAX

			MOV EAX, a.word[240]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[240], EAX

			MOV EAX, a.word[236]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[236], EAX

			MOV EAX, a.word[232]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[232], EAX

			MOV EAX, a.word[228]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[228], EAX

			MOV EAX, a.word[224]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[224], EAX

			MOV EAX, a.word[220]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[220], EAX

			MOV EAX, a.word[216]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[216], EAX

			MOV EAX, a.word[212]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[212], EAX

			MOV EAX, a.word[208]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[208], EAX

			MOV EAX, a.word[204]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[204], EAX

			MOV EAX, a.word[200]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[200], EAX

			MOV EAX, a.word[196]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[196], EAX

			MOV EAX, a.word[192]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[192], EAX

			MOV EAX, a.word[188]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[188], EAX

			MOV EAX, a.word[184]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[184], EAX

			MOV EAX, a.word[180]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[180], EAX

			MOV EAX, a.word[176]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[176], EAX

			MOV EAX, a.word[172]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[172], EAX

			MOV EAX, a.word[168]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[168], EAX

			MOV EAX, a.word[164]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[164], EAX

			MOV EAX, a.word[160]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[160], EAX

			MOV EAX, a.word[156]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[156], EAX

			MOV EAX, a.word[152]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[152], EAX

			MOV EAX, a.word[148]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[148], EAX

			MOV EAX, a.word[144]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[144], EAX

			MOV EAX, a.word[140]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[140], EAX

			MOV EAX, a.word[136]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[136], EAX

			MOV EAX, a.word[132]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[132], EAX

			MOV EAX, a.word[128]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[128], EAX

			MOV EAX, a.word[124]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[124], EAX

			MOV EAX, a.word[120]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[120], EAX

			MOV EAX, a.word[116]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[116], EAX

			MOV EAX, a.word[112]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[112], EAX

			MOV EAX, a.word[108]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[108], EAX

			MOV EAX, a.word[104]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[104], EAX

			MOV EAX, a.word[100]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[100], EAX

			MOV EAX, a.word[96]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[96], EAX

			MOV EAX, a.word[92]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[92], EAX

			MOV EAX, a.word[88]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[88], EAX

			MOV EAX, a.word[84]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[84], EAX

			MOV EAX, a.word[80]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[80], EAX

			MOV EAX, a.word[76]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[76], EAX

			MOV EAX, a.word[72]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[72], EAX

			MOV EAX, a.word[68]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[68], EAX

			MOV EAX, a.word[64]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[64], EAX

			MOV EAX, a.word[60]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[60], EAX

			MOV EAX, a.word[56]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[56], EAX

			MOV EAX, a.word[52]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[52], EAX

			MOV EAX, a.word[48]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[48], EAX

			MOV EAX, a.word[44]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[44], EAX

			MOV EAX, a.word[40]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[40], EAX

			MOV EAX, a.word[36]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[36], EAX

			MOV EAX, a.word[32]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[32], EAX

			MOV EAX, a.word[28]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[28], EAX

			MOV EAX, a.word[24]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[24], EAX

			MOV EAX, a.word[20]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[20], EAX

			MOV EAX, a.word[16]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[16], EAX

			MOV EAX, a.word[12]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[12], EAX

			MOV EAX, a.word[8]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[8], EAX

			MOV EAX, a.word[4]	;load from memory
			RCR EAX, 1			;Shift Right 1 bit, insert CF as left bit, and store dropped bit in CF
			MOV a.word[4], EAX

			MOV EAX, a.word[0]
			RCR EAX, 1
			MOV a.word[0], EAX
		}
		(*this) = a;
	}
	void ShiftL(){
	//Shift left 1 bit
		int64 a = (*this);
		__asm{
			MOV EAX, a.word[0]	;load from memory
			SHL EAX, 1			;Shift Left 1 bit, dropped bit is stored in the CF
			MOV a.word[0], EAX

			MOV EAX, a.word[4]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[4], EAX

			MOV EAX, a.word[8]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[8], EAX

			MOV EAX, a.word[12]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[12], EAX

			MOV EAX, a.word[16]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[16], EAX

			MOV EAX, a.word[20]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[20], EAX

			MOV EAX, a.word[24]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[24], EAX

			MOV EAX, a.word[28]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[28], EAX

			MOV EAX, a.word[32]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[32], EAX

			MOV EAX, a.word[36]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[36], EAX

			MOV EAX, a.word[40]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[40], EAX

			MOV EAX, a.word[44]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[44], EAX

			MOV EAX, a.word[48]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[48], EAX

			MOV EAX, a.word[52]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[52], EAX

			MOV EAX, a.word[56]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[56], EAX

			MOV EAX, a.word[60]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[60], EAX

			MOV EAX, a.word[64]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[64], EAX

			MOV EAX, a.word[68]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[68], EAX

			MOV EAX, a.word[72]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[72], EAX

			MOV EAX, a.word[76]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[76], EAX

			MOV EAX, a.word[80]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[80], EAX

			MOV EAX, a.word[84]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[84], EAX

			MOV EAX, a.word[88]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[88], EAX

			MOV EAX, a.word[92]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[92], EAX

			MOV EAX, a.word[96]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[96], EAX

			MOV EAX, a.word[100]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[100], EAX

			MOV EAX, a.word[104]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[104], EAX

			MOV EAX, a.word[108]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[108], EAX

			MOV EAX, a.word[112]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[112], EAX

			MOV EAX, a.word[116]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[116], EAX

			MOV EAX, a.word[120]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[120], EAX

			MOV EAX, a.word[124]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[124], EAX

			MOV EAX, a.word[128]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[128], EAX

			MOV EAX, a.word[132]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[132], EAX

			MOV EAX, a.word[136]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[136], EAX

			MOV EAX, a.word[140]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[140], EAX

			MOV EAX, a.word[144]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[144], EAX

			MOV EAX, a.word[148]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[148], EAX

			MOV EAX, a.word[152]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[152], EAX

			MOV EAX, a.word[156]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[156], EAX

			MOV EAX, a.word[160]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[160], EAX

			MOV EAX, a.word[164]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[164], EAX

			MOV EAX, a.word[168]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[168], EAX

			MOV EAX, a.word[172]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[172], EAX

			MOV EAX, a.word[176]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[176], EAX

			MOV EAX, a.word[180]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[180], EAX

			MOV EAX, a.word[184]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[184], EAX

			MOV EAX, a.word[188]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[188], EAX

			MOV EAX, a.word[192]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[192], EAX

			MOV EAX, a.word[196]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[196], EAX

			MOV EAX, a.word[200]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[200], EAX

			MOV EAX, a.word[204]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[204], EAX

			MOV EAX, a.word[208]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[208], EAX

			MOV EAX, a.word[212]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[212], EAX

			MOV EAX, a.word[216]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[216], EAX

			MOV EAX, a.word[220]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[220], EAX

			MOV EAX, a.word[224]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[224], EAX

			MOV EAX, a.word[228]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[228], EAX

			MOV EAX, a.word[232]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[232], EAX

			MOV EAX, a.word[236]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[236], EAX

			MOV EAX, a.word[240]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[240], EAX

			MOV EAX, a.word[244]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[244], EAX

			MOV EAX, a.word[248]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[248], EAX

			MOV EAX, a.word[252]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[252], EAX

			MOV EAX, a.word[256]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[256], EAX

			MOV EAX, a.word[260]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[260], EAX

			MOV EAX, a.word[264]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[264], EAX

			MOV EAX, a.word[268]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[268], EAX

			MOV EAX, a.word[272]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[272], EAX

			MOV EAX, a.word[276]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[276], EAX

			MOV EAX, a.word[280]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[280], EAX

			MOV EAX, a.word[284]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[284], EAX

			MOV EAX, a.word[288]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[288], EAX

			MOV EAX, a.word[292]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[292], EAX

			MOV EAX, a.word[296]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[296], EAX

			MOV EAX, a.word[300]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[300], EAX

			MOV EAX, a.word[304]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[304], EAX

			MOV EAX, a.word[308]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[308], EAX

			MOV EAX, a.word[312]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[312], EAX

			MOV EAX, a.word[316]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[316], EAX

			MOV EAX, a.word[320]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[320], EAX

			MOV EAX, a.word[324]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[324], EAX

			MOV EAX, a.word[328]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[328], EAX

			MOV EAX, a.word[332]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[332], EAX

			MOV EAX, a.word[336]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[336], EAX

			MOV EAX, a.word[340]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[340], EAX

			MOV EAX, a.word[344]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[344], EAX

			MOV EAX, a.word[348]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[348], EAX

			MOV EAX, a.word[352]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[352], EAX

			MOV EAX, a.word[356]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[356], EAX

			MOV EAX, a.word[360]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[360], EAX

			MOV EAX, a.word[364]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[364], EAX

			MOV EAX, a.word[368]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[368], EAX

			MOV EAX, a.word[372]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[372], EAX

			MOV EAX, a.word[376]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[376], EAX

			MOV EAX, a.word[380]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[380], EAX

			MOV EAX, a.word[384]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[384], EAX

			MOV EAX, a.word[388]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[388], EAX

			MOV EAX, a.word[392]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[392], EAX

			MOV EAX, a.word[396]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[396], EAX
		}

		(*this) = a;
	}
//private:
	long unsigned int word[SIZE];

	signed int relation(const int64 b)const{
	//Shows the relationship between (*this) and b
	//returns a 0 for equal
	//returns a -1 for a < b
	//returns a 1 for a > b
		int64 a = (*this);
		int64 temp = b;	//we want something we can destroy
		signed int result = 0;	//load with default of zero
		__asm{
			MOV ECX, 0	;load zero into our counter register
		top:
			CMP ECX, 3200	;compare the counter to the number of bits in our number
			JE relation_out	;if they are equal, then we need to jump out
		//First shift a left 1 bit
			MOV EAX, a.word[0]	;load from memory
			SHL EAX, 1			;Shift Left 1 bit, dropped bit is stored in the CF
			MOV a.word[0], EAX

			MOV EAX, a.word[4]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[4], EAX

			MOV EAX, a.word[8]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[8], EAX

			MOV EAX, a.word[12]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[12], EAX

			MOV EAX, a.word[16]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[16], EAX

			MOV EAX, a.word[20]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[20], EAX

			MOV EAX, a.word[24]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[24], EAX

			MOV EAX, a.word[28]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[28], EAX

			MOV EAX, a.word[32]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[32], EAX

			MOV EAX, a.word[36]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[36], EAX

			MOV EAX, a.word[40]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[40], EAX

			MOV EAX, a.word[44]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[44], EAX

			MOV EAX, a.word[48]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[48], EAX

			MOV EAX, a.word[52]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[52], EAX

			MOV EAX, a.word[56]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[56], EAX

			MOV EAX, a.word[60]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[60], EAX

			MOV EAX, a.word[64]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[64], EAX

			MOV EAX, a.word[68]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[68], EAX

			MOV EAX, a.word[72]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[72], EAX

			MOV EAX, a.word[76]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[76], EAX

			MOV EAX, a.word[80]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[80], EAX

			MOV EAX, a.word[84]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[84], EAX

			MOV EAX, a.word[88]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[88], EAX

			MOV EAX, a.word[92]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[92], EAX

			MOV EAX, a.word[96]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[96], EAX

			MOV EAX, a.word[100]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[100], EAX

			MOV EAX, a.word[104]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[104], EAX

			MOV EAX, a.word[108]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[108], EAX

			MOV EAX, a.word[112]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[112], EAX

			MOV EAX, a.word[116]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[116], EAX

			MOV EAX, a.word[120]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[120], EAX

			MOV EAX, a.word[124]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[124], EAX

			MOV EAX, a.word[128]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[128], EAX

			MOV EAX, a.word[132]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[132], EAX

			MOV EAX, a.word[136]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[136], EAX

			MOV EAX, a.word[140]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[140], EAX

			MOV EAX, a.word[144]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[144], EAX

			MOV EAX, a.word[148]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[148], EAX

			MOV EAX, a.word[152]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[152], EAX

			MOV EAX, a.word[156]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[156], EAX

			MOV EAX, a.word[160]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[160], EAX

			MOV EAX, a.word[164]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[164], EAX

			MOV EAX, a.word[168]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[168], EAX

			MOV EAX, a.word[172]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[172], EAX

			MOV EAX, a.word[176]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[176], EAX

			MOV EAX, a.word[180]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[180], EAX

			MOV EAX, a.word[184]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[184], EAX

			MOV EAX, a.word[188]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[188], EAX

			MOV EAX, a.word[192]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[192], EAX

			MOV EAX, a.word[196]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[196], EAX

			MOV EAX, a.word[200]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[200], EAX

			MOV EAX, a.word[204]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[204], EAX

			MOV EAX, a.word[208]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[208], EAX

			MOV EAX, a.word[212]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[212], EAX

			MOV EAX, a.word[216]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[216], EAX

			MOV EAX, a.word[220]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[220], EAX

			MOV EAX, a.word[224]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[224], EAX

			MOV EAX, a.word[228]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[228], EAX

			MOV EAX, a.word[232]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[232], EAX

			MOV EAX, a.word[236]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[236], EAX

			MOV EAX, a.word[240]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[240], EAX

			MOV EAX, a.word[244]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[244], EAX

			MOV EAX, a.word[248]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[248], EAX

			MOV EAX, a.word[252]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[252], EAX

			MOV EAX, a.word[256]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[256], EAX

			MOV EAX, a.word[260]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[260], EAX

			MOV EAX, a.word[264]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[264], EAX

			MOV EAX, a.word[268]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[268], EAX

			MOV EAX, a.word[272]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[272], EAX

			MOV EAX, a.word[276]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[276], EAX

			MOV EAX, a.word[280]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[280], EAX

			MOV EAX, a.word[284]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[284], EAX

			MOV EAX, a.word[288]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[288], EAX

			MOV EAX, a.word[292]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[292], EAX

			MOV EAX, a.word[296]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[296], EAX

			MOV EAX, a.word[300]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[300], EAX

			MOV EAX, a.word[304]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[304], EAX

			MOV EAX, a.word[308]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[308], EAX

			MOV EAX, a.word[312]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[312], EAX

			MOV EAX, a.word[316]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[316], EAX

			MOV EAX, a.word[320]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[320], EAX

			MOV EAX, a.word[324]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[324], EAX

			MOV EAX, a.word[328]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[328], EAX

			MOV EAX, a.word[332]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[332], EAX

			MOV EAX, a.word[336]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[336], EAX

			MOV EAX, a.word[340]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[340], EAX

			MOV EAX, a.word[344]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[344], EAX

			MOV EAX, a.word[348]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[348], EAX

			MOV EAX, a.word[352]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[352], EAX

			MOV EAX, a.word[356]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[356], EAX

			MOV EAX, a.word[360]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[360], EAX

			MOV EAX, a.word[364]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[364], EAX

			MOV EAX, a.word[368]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[368], EAX

			MOV EAX, a.word[372]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[372], EAX

			MOV EAX, a.word[376]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[376], EAX

			MOV EAX, a.word[380]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[380], EAX

			MOV EAX, a.word[384]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[384], EAX

			MOV EAX, a.word[388]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[388], EAX

			MOV EAX, a.word[392]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[392], EAX

			MOV EAX, a.word[396]	;load from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF as right bit, and store dropped bit in CF
			MOV a.word[396], EAX
		//done
		//now we need to keep out CFlag, so we are going to load 0 into EBX, and add with carry 0 to it
			MOV EBX, 0	; load with zero
			ADC EBX, 0	; add the carry flag into the register

		//now we need to do the same for temp
					MOV EAX, temp.word[0]	;loAd from memory
			SHL EAX, 1			;Shift Left 1 bit, dropped bit is stored in the CF
			MOV temp.word[0], EAX

			MOV EAX, temp.word[4]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[4], EAX

			MOV EAX, temp.word[8]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[8], EAX

			MOV EAX, temp.word[12]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[12], EAX

			MOV EAX, temp.word[16]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[16], EAX

			MOV EAX, temp.word[20]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[20], EAX

			MOV EAX, temp.word[24]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[24], EAX

			MOV EAX, temp.word[28]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[28], EAX

			MOV EAX, temp.word[32]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[32], EAX

			MOV EAX, temp.word[36]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[36], EAX

			MOV EAX, temp.word[40]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[40], EAX

			MOV EAX, temp.word[44]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[44], EAX

			MOV EAX, temp.word[48]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[48], EAX

			MOV EAX, temp.word[52]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[52], EAX

			MOV EAX, temp.word[56]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[56], EAX

			MOV EAX, temp.word[60]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[60], EAX

			MOV EAX, temp.word[64]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[64], EAX

			MOV EAX, temp.word[68]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[68], EAX

			MOV EAX, temp.word[72]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[72], EAX

			MOV EAX, temp.word[76]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[76], EAX

			MOV EAX, temp.word[80]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[80], EAX

			MOV EAX, temp.word[84]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[84], EAX

			MOV EAX, temp.word[88]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[88], EAX

			MOV EAX, temp.word[92]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[92], EAX

			MOV EAX, temp.word[96]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[96], EAX

			MOV EAX, temp.word[100]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[100], EAX

			MOV EAX, temp.word[104]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[104], EAX

			MOV EAX, temp.word[108]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[108], EAX

			MOV EAX, temp.word[112]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[112], EAX

			MOV EAX, temp.word[116]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[116], EAX

			MOV EAX, temp.word[120]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[120], EAX

			MOV EAX, temp.word[124]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[124], EAX

			MOV EAX, temp.word[128]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[128], EAX

			MOV EAX, temp.word[132]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[132], EAX

			MOV EAX, temp.word[136]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[136], EAX

			MOV EAX, temp.word[140]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[140], EAX

			MOV EAX, temp.word[144]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[144], EAX

			MOV EAX, temp.word[148]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[148], EAX

			MOV EAX, temp.word[152]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[152], EAX

			MOV EAX, temp.word[156]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[156], EAX

			MOV EAX, temp.word[160]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[160], EAX

			MOV EAX, temp.word[164]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[164], EAX

			MOV EAX, temp.word[168]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[168], EAX

			MOV EAX, temp.word[172]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[172], EAX

			MOV EAX, temp.word[176]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[176], EAX

			MOV EAX, temp.word[180]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[180], EAX

			MOV EAX, temp.word[184]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[184], EAX

			MOV EAX, temp.word[188]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[188], EAX

			MOV EAX, temp.word[192]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[192], EAX

			MOV EAX, temp.word[196]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[196], EAX

			MOV EAX, temp.word[200]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[200], EAX

			MOV EAX, temp.word[204]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[204], EAX

			MOV EAX, temp.word[208]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[208], EAX

			MOV EAX, temp.word[212]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[212], EAX

			MOV EAX, temp.word[216]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[216], EAX

			MOV EAX, temp.word[220]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[220], EAX

			MOV EAX, temp.word[224]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[224], EAX

			MOV EAX, temp.word[228]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[228], EAX

			MOV EAX, temp.word[232]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[232], EAX

			MOV EAX, temp.word[236]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[236], EAX

			MOV EAX, temp.word[240]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[240], EAX

			MOV EAX, temp.word[244]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[244], EAX

			MOV EAX, temp.word[248]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[248], EAX

			MOV EAX, temp.word[252]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[252], EAX

			MOV EAX, temp.word[256]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[256], EAX

			MOV EAX, temp.word[260]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[260], EAX

			MOV EAX, temp.word[264]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[264], EAX

			MOV EAX, temp.word[268]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[268], EAX

			MOV EAX, temp.word[272]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[272], EAX

			MOV EAX, temp.word[276]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[276], EAX

			MOV EAX, temp.word[280]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[280], EAX

			MOV EAX, temp.word[284]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[284], EAX

			MOV EAX, temp.word[288]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[288], EAX

			MOV EAX, temp.word[292]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[292], EAX

			MOV EAX, temp.word[296]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[296], EAX

			MOV EAX, temp.word[300]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[300], EAX

			MOV EAX, temp.word[304]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[304], EAX

			MOV EAX, temp.word[308]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[308], EAX

			MOV EAX, temp.word[312]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[312], EAX

			MOV EAX, temp.word[316]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[316], EAX

			MOV EAX, temp.word[320]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[320], EAX

			MOV EAX, temp.word[324]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[324], EAX

			MOV EAX, temp.word[328]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[328], EAX

			MOV EAX, temp.word[332]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[332], EAX

			MOV EAX, temp.word[336]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[336], EAX

			MOV EAX, temp.word[340]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[340], EAX

			MOV EAX, temp.word[344]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[344], EAX

			MOV EAX, temp.word[348]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[348], EAX

			MOV EAX, temp.word[352]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[352], EAX

			MOV EAX, temp.word[356]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[356], EAX

			MOV EAX, temp.word[360]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[360], EAX

			MOV EAX, temp.word[364]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[364], EAX

			MOV EAX, temp.word[368]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[368], EAX

			MOV EAX, temp.word[372]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[372], EAX

			MOV EAX, temp.word[376]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[376], EAX

			MOV EAX, temp.word[380]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[380], EAX

			MOV EAX, temp.word[384]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[384], EAX

			MOV EAX, temp.word[388]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[388], EAX

			MOV EAX, temp.word[392]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[392], EAX

			MOV EAX, temp.word[396]	;loAd from memory
			RCL EAX, 1			;Shift Left 1 bit, insert CF As right bit, And store dropped bit in CF
			MOV temp.word[396], EAX
		//done
		//now we need to keep the Carry Flag, by adding with carry again
			MOV EDX, 0
			ADC EDX, 0	;now we have our carry flag in register D
			INC ECX		;increment our counter by 1
			CMP EBX, EDX	;compare out two carry flags
			JE top			; jump back to the top if the two carry flags are equal
			;else they are not equal and we can return
			SUB EBX, EDX	;subtract the two
			MOV result, EBX	;save the result
			;we are done
		relation_out:
		}

		return result;
	}

};

#endif