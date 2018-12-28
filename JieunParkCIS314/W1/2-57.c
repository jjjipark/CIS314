#include <stdio.h>

typedef unsigned char *byte_pointer;

//%X => hexdeminal

void show_bytes(byte_pointer start, int len){
    int i;
    for (i=0; i<len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_short(short x){
    show_bytes((byte_pointer) &x, sizeof(short));
}
//& save x address into byte_pointer --> show_bytes(x, sizeof(short))

void show_long(long x){
    show_bytes((byte_pointer) &x, sizeof(long));
}
void show_double(double x){
    show_bytes((byte_pointer) &x, sizeof(double));
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

int main(void){
    int i_val = 8;
    
    short s_val=(short) i_val;
    long l_val=(long) i_val;
    double d_val=(double) i_val;
    
    
    show_short(s_val);
    show_long(l_val);
    show_double(d_val);
}
