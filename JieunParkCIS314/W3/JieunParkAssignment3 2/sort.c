#include <stdio.h>
//
int* readArray(int length){

	int* array = malloc(length* sizeof(int));

	for (int i=0; i<length; i++){
		int input;
		printf("Enter a element of arrary: ");
		scanf("%d", &input);
		array[i] = input;
	}
	return array;

}
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

void printArray(int *array, int length){

	printf("[ ");
	int i;
	for (i =0; i<length-1; i++){
		printf("%d, ", array[i]);
	}
	printf("%d ]", array[length-1]);
}

int main(){

	int length;
	printf("Enter a array length: ");
	scanf("%d", &length);

	int* array = readArray(length);

	sortArray(array, length);
	printArray(array, length);

	free(array);
}

// a heap is an area of pre-reserved computer main storage ( memory ) 
//that a program process can use to store data in 
//some variable amount that won't be known until the program is running.