//sorce code : http://people.cs.aau.dk/~adavid/teaching/CART-11/03-sol.txt

#include <stdio.h>

unsigned f2u(float f) { 
	return *((unsigned*)&f);
}


int float_le(float x, float y) { 
	unsigned ux = f2u(x); 
	unsigned uy = f2u(y);
/* Get the sign bits */
	unsigned sx = ux >> 31;
	unsigned sy = uy >> 31;
/* Give an expression using only ux, uy, sx, and sy */ 
	return (sx && !sy) ||              // x<0, y>0
			(!sx && !sy && ux <= uy)|| // x>=0, y>=0
			(sx && sy && ux>= uy) ||   //x=<0, y=<0
			(ux ==0 && uy==0); // x=0,y=0
}


int main(){
	int test1 = float_le(0.0f, 0.0f);
	int test2 = float_le(-0.0f, 0.0f);
	int test3 = float_le(-1.0f, 0.0f);
	int test4 = float_le(0.0f, 1.0f);
	int test5 = float_le(1.0f, 0.0f);
	int test6 = float_le(0.0f, -1.0f);

	printf("test1: %d\n", test1);
	printf("test2: %d\n", test2);
	printf("test3: %d\n", test3);
	printf("test4: %d\n", test4);
	printf("test5: %d\n", test5);
	printf("test6: %d\n", test6);

}

//'1': False
//'0': True