#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b){

    int shift = i*8;

    unsigned mask = 0xff << shift;             //0xff: last 8bits==1
    unsigned remove_ibyte = ~mask & x; 		// by ~, 1 of mask became 0 
    						// and 0 became 1. able to make i byte of x to 0 by using AND

    unsigned add_b = remove_ibyte | (b << shift); 
    // add b to x by using OR 
    //to make 0 of x that is made by mask to b

    printf("new_byte: 0x%X\n", add_b);

}

int main(){
    replace_byte(0x12345678, 1, 0xAB);
    replace_byte(0x12345678, 0, 0xAB);

    return 0;
}