#include <stdio.h>

int count(unsigned long x){

	int i;
	int shift;
	int count;
	for (i=0; i <sizeof(x)/2; i++){
		shift = i*8;
		unsigned mask = 0xff << shift;
		unsigned remove = mask & x;
		if (remove!=0){
			count = count+1;
		}
	}
	return count;
}

int main(){

	printf("%d\n", count(0x001112));
	//printf("%X\n", count(0x001100));
	//count(0x001100);

}