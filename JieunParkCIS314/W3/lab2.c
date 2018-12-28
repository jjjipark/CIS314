#include <stdio.h>
//unsigned f2u(float f){
//	return *( (unsigned*) &f);
//}

typedef union{...} u;

unsigned f2u(float f){

	typedef union {float f;unsigned u;} u;
	
	u u1;
	
	u1.f = f;
	return u1.u;
}

void printBinary(unsigned a){
	 int i;
	 for (i=31; i>=0; i--){
	 	print("%d", a>>i &1);
	 }
	 printf("\n");
	 return;
}


int main(){

	float a = 8.5;
	printBinary(f2u(a));
	return 0;
}


'''
///void swap(int *xp, int *yp){
	int t0 = *xp;
	int t1 = *yp;
	*xp = t1;
	*yp = t0;
}
'''