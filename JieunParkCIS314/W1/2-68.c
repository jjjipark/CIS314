#include <stdio.h>

int lower_one_mask(int n){
	//idea: 001000-1 = 000111

	unsigned i = 2 << (n-1);
	
	printf("%d: %d\n", n, i-1);
	printf("")

	return 0;
}

int main(){
	lower_one_mask(1);
	lower_one_mask(2);
	lower_one_mask(3);
	lower_one_mask(5);
}

//0x3F == 0011 1111
// 100 - 01 = 011
