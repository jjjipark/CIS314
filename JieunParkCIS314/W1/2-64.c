#include <stdio.h>

int any_odd_one(unsigned x){
	//0xaaaaaaaa is a 32bit number with 
	//all odd bits set as 1 and all even bits set as 101010

	if ((x & 0xAAAAAAAA) != 0){
		printf("0x%X: 1\n", x);
	}
	else{
		printf("0x%X: 0\n", x);
	}
	return 0;
}

int main(){
	any_odd_one(0x0);
	any_odd_one(0x1);
	any_odd_one(0x2);
	any_odd_one(0x3);
	any_odd_one(0xFFFFFFFF);
	any_odd_one(0x55555555);
}