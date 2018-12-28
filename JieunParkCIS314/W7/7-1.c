
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>

#define VECTOR_SIZE 128
typedef float data_t;


void inner2(float *u, float *v, int length, float *dest)
    {
        long int i;
        long int limit = length-3; 

        float sum = 0.0f;
        float sum1 = 0.0f;
        float sum2 = 0.0f;
        float sum3 = 0.0f;

        //unrolls 4 at a time
        for (i = 0; i < limit; i += 4) {
            sum += (u[i] * v[i]);
            sum1 += (u[i+1] * v[i+1]);
            sum2 += (u[i+2] * v[i+2]);
            sum3 += (u[i+3] * v[i+3]);
        }
        for (; i < limit; i++) {
            sum = sum +u[i] + v[i];
        }
        
        *dest = sum + sum1 + sum2 + sum3;
    }

void inner(float *u, float *v, int length, float *dest) { 
	int i;  
	float sum = 0.0f;
	for (i = 0; i < length; ++i) {  
		sum += u[i] * v[i];  
		*dest = sum;   
	} 
}

int main() {
	
	float *u;
	float *v;
	u =(float*) malloc(sizeof(data_t) * VECTOR_SIZE);
    v =(float*) malloc(sizeof(data_t) * VECTOR_SIZE);
    data_t dest = 0.0;

    //for (data_t i = 0; i < VECTOR_SIZE; i++){
   ///     u[i] = i;
    //    v[i] = i;
    

	// load values into a
	//float sum=0;

	struct timeval start;
	gettimeofday(&start, NULL);
	// Do this 1000 times to exaggerate the time taken.	
	for (int i = 0; i < 10000; i++){
		inner(u,v,VECTOR_SIZE, &dest);
		//inner2(u,v,VECTOR_SIZE, &dest);
	}

	struct timeval current;
	gettimeofday(&current, NULL);

	long long elapsed = (current.tv_sec - start.tv_sec)*1000000LL + (current.tv_usec - start.tv_usec);
    printf("%f\n", elapsed/1000000.0);


	}

//when length is 128, time is 0,003416
//when length is 8, time is 0.001392
//for inner function, when length is 8, time is 0.001733
//when length is 128, time is 0.007676

