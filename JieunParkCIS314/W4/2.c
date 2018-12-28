//I derived code example from https://ideone.com/BfiPM8

#include <stdio.h>

#define M 4
typedef int Marray_t[M][M];

void swap(int *xp, int *yp){
    
    int temp = *xp;
    *xp = *yp;
    *yp = temp;

}

void transpose(Marray_t A) {
    int i, j;
    int* start = &A[0][0];
    for (i = 0; i < M; i++){
        for (j = 0; j < i; j++) {
            int* t = start + (i*M +j); //value at A[i][j]
            int* z = start + (j*M+ i); // value at A[j][i]
            swap(t,z);  ////swaps values to pointers
        }
    }
}
void arrayPrinter(Marray_t A){
    for (int i = 0; i < M; i++){
        printf("[ ");
        for (int j = 0; j < M; j++) {
            int t = A[i][j];
            printf("%d ", t); 
        }
        printf("]\n");
    }
    printf("\n");
}

int main(int argc, char const *argv[]){

    int A[M][M] = {{1,1,1,1}, {2,2,2,2}, {3,3,3,3}, {4,4,4,4}};
    arrayPrinter(A);
    transpose(A);
    arrayPrinter(A);

    return 0;
}


//A[i] at %esi, j at %ecx , i at %edi, M at %ebx
// M: 52/4 = 13

//.L3: movl (%ebx), %eax 			// eax<- %ebx
//movl (%esi,%ecx,4), %edx 			// edx = ecx*4 + esi = A[i][j] 
//movl %eax, (%esi,%ecx,4) 			// eax: probably t
//addl $1, %ecx						// ecx++; = j ++
//movl %edx, (%ebx) 				// A[i][j]
//addl $52, %ebx 					// ebx += 4*13 => (4*M)
//cmpl %edi, %ecx 					// compare i : j
//jl .L3							// if < : goto L3 //////

//(%esi,%ecx,4) ->>> Calculate Address = (ESI + ECX * 4)
