// miscSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>


int compareFunc(const void *, const void *);
void insertionSort(void);


const int ARRAY_SIZE = 10;
int intArray[ARRAY_SIZE] = { 87,28,100,78,84,98,75,70,81,68 };


int compareFunc(const void * voidA, const void * voidB) {
	int * intA = (int *)(voidA);
	int * intB = (int *)(voidB);
	return *intA - *intB;
}


// the basic insertion sort
void insertionSort(){

	int start = 0;
	int end = ARRAY_SIZE - 1;

	for (int i = start + 1; i <= end; i++){
		for( int j = i; j > start && intArray[j-1] > intArray[j]; j--){
			int temp = intArray[j - 1];
			intArray[j - 1] = intArray[j];
			intArray[j] = temp;
		}
	}
}



int main()
{

	// call the standard lib quick sort routine, note need to define
	// a compare function for this call.
//	qsort(intArray, ARRAY_SIZE, sizeof(int), compareFunc);

	insertionSort();

    return 0;
}

