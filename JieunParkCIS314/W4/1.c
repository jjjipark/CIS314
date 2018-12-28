#include <stdio.h>

int loop(int x, int n) {
    int result = -1;
	for(int mask = 1; mask != 0; mask = mask<<n){ 
		result ^= (mask&x);
}
    return result;
}

int main(void){
	printf("%d\n", loop(1, 1));
	printf("%d\n", loop(3, 1));
}