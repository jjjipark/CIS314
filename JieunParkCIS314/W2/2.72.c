//source code: https://stackoverflow.com/questions/5583910/copy-integer-to-buffer-if-buffer-have-enough-space-in-c

#include <stdio.h>
#include <string.h>

//A. Since the type of sizeof(val) is size_t, which is unsigned value.
//So it is always greater or equal to 0 even if the maxbyte is too small
//because when maxbytes - sizeof(val) <0, 
//it is also true due to comparison of signed and unsigned value.

void copy_int(int val, void *buf, int maxbytes) {

	if (maxbytes >= sizeof(val)) {
		
		memcpy(buf, (void *) &val, sizeof(val));
		printf("print : %d\n", buf);
		printf("printed!\n");
		printf(sizeof(val));
	}
}

int main(){

	char array[50];

	copy_int(1, array, 4);
	//printf("printed!\n");

	copy_int(1, array, 1);
	//printf("printed!\n");
 
	//Int is size of 4 so maxbytes has to be larger than
	// that size to let an int be copied.
}

//temporary storage area = buffer
//size_t represents size of an object.