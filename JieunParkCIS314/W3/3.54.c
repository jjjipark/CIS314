#include <stdio.h>

int decode2(int x, int y, int z){

	int a = ((y-z) <<31 ) >>31;
	int b = (y-z)*x;

	return a^b;
}

int main(){
	
	printf("%d\n", decode2(1, 2, 4));
	printf("%d\n", decode2(-4, -8, -12));
}






//x at %ebp+8, y at %ebp+12, z at %ebp+16

//1 movl   12(%ebp), %edx		// edx <- y
//2 subl   16(%ebp), %edx		// edx = edx - z = y-z
//3 movl   %edx, %eax			// eax<- y-z
//4 sall   $31, %eax			    // eax<<31: y-z <<31
//5 sarl   $31, %eax			    // eax >> 31 : y-z<<31 >>31
//6 imull   8(%ebp), %edx		// y-z * x
//7 xorl   %edx, %eax			// y-z<<31 >>31 ^ y-z * x
