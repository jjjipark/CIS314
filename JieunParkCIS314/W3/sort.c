#include <stdio.h>

void swap(int *xp, int *yp){
    
    int temp = *xp;
    *xp = *yp;
    *yp = temp;

}

void sortArray(int *array, int length){
	for (int i=0; i < length-1; i++){
		int min = i;
		for (int j = i+1; j<length; j++){
			if (array[min] > array[j]){
				min = j;
			}
		}
		if (min != i){
			swap(&array[i], &array[min]);
      }
	}
}

void main(){
	
}
// a heap is an area of pre-reserved computer main storage ( memory ) 
//that a program process can use to store data in 
//some variable amount that won't be known until the program is running.