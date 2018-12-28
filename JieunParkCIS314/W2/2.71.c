//source credit: https://stackoverflow.com/questions/7284136/get-byte-how-is-this-wrong

#include <stdio.h>
//A. function doesn't consider sign extension, 
//   only works for positive values

typedef unsigned packed_t;
//two complement number 
//right shifts of signed values are performed arithmetically
//1byte = 8bits
//
int xbyte(packed_t word, int bytenum)
{	
	                  // word has 2byte, which is 8bits
					  // left 32-8=24bits -> shift it to extend

	int s = (3-bytenum) << 3;
	int new_word = word << s;

	return new_word >> 24;
	//printf("0x%X\n",  new_word >> 24);  
	//printf("%d\n",  new_word >> 24);
}


int main(){
	printf("0x%X\n", xbyte(0x12345678, 2));
	printf("%d\n",  xbyte(0x12345678, 2));
	printf("0x%X\n", xbyte(0x00EE0000, 2));
	printf("%d\n", xbyte(0x00EE0000, 2));
	printf("0x%X\n", xbyte(0x00007700, 1));
	printf("%d\n",  xbyte(0x00007700, 1));

	//xbyte(0x12345678, 3);
	//xbyte(0x00EE0000, 2);
	//xbyte(0x00007700, 1);  
}


