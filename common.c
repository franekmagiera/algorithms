#include "common.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

void swap(void * a, void * b, int elementSize)
{
	for(int i = 0; i < elementSize; i++) {
		char temp = ((char *) a)[i];
		((char *) a)[i] = ((char *) b)[i];
		((char *) b)[i] = temp;
	}
}

int merge(void * array, int left, int middle, int right, int elementSize, int (*compare)(const void *, const void *),
          bool reverse)
{
    int coefficient = (reverse) ? (-1) : (1);
	int n1 = middle - left + 1;
	void * A = malloc(n1*elementSize);
	if (A == NULL) {
		exit(EXIT_FAILURE);
	}
	int n2 = right - middle;
	void * B = malloc(n2*elementSize);
	if (B == NULL)
		exit(EXIT_FAILURE);
	memcpy(A,array+left*elementSize,n1*elementSize);
	memcpy(B,array+(middle+1)*elementSize,n2*elementSize);
	int i = 0, j = 0, inversions = 0, k = left;
	while (i < n1 && j < n2){
		if (compare(A+i*elementSize, B+j*elementSize) * coefficient <= 0) {
			memcpy(array+k*elementSize, A+i*elementSize, elementSize);
			i++;
			k++;
		} else {
			memcpy(array+k*elementSize, B+j*elementSize, elementSize);
			j++;
			k++;
			inversions += n1 - i;
		}
	}
	if (i < n1)
		memcpy(array+k*elementSize, A+i*elementSize, (n1-i)*elementSize);
	if (j < n2) {
		memcpy(array+k*elementSize, B+j*elementSize, (n2-j)*elementSize);
	}
	free(B);
	free(A);
	return inversions;
}

int minimum(void * array, int arraySize, int elementSize, int (*compare)(const void *, const void *))
{
    int minIndex = 0;
    for (int i = 1; i < arraySize; i++)
        if (compare(array+minIndex*elementSize, array+i*elementSize) > 0)
            minIndex = i;
    return minIndex;
}

int maximum(void * array, int arraySize, int elementSize, int (*compare)(const void *, const void *))
{
    int maxIndex = 0;
    for (int i = 1; i < arraySize; i++)
        if (compare(array+maxIndex*elementSize, array+i*elementSize) < 0)
            maxIndex = i;
    return maxIndex;
}

void minmax(void * array, int arraySize, int elementSize, int (*compare)(const void *, const void *), int * minIndex, int * maxIndex)
{
    int i;
    if (arraySize % 2 != 0) {
        *minIndex = *maxIndex = 0;
        i = 1;
    } else {
        if (compare(array, array+elementSize) > 0) {
            *maxIndex = 0;
            *minIndex = 1;
        } else {
            *maxIndex = 1;
            *minIndex = 0;
        }
        i = 2;
    }
    for (i; i+1 < arraySize; i += 2)
        if (compare(array+i*elementSize, array+(i+1)*elementSize) > 0) {
            if (compare(array+(*minIndex)*elementSize, array+(i+1)*elementSize) > 0)
                *minIndex = i+1;
            if (compare(array+(*maxIndex)*elementSize, array+i*elementSize) < 0)
                *maxIndex = i;
        } else {
           if (compare(array+(*minIndex)*elementSize, array+i*elementSize) > 0) 
                *minIndex = i;
           if (compare(array+(*maxIndex)*elementSize, array+(i+1)*elementSize) < 0)
                *maxIndex = i+1;
        }
}

int partition(void * array, int left, int right, int elementSize, int (*compare)(const void *, const void *), bool reverse)
{
   // last element (array[right]) is the partitioning element
   int coefficient = (reverse) ? (-1) : (1);
   int i = left - 1;
   for (int j = left; j < right; j++) {
       if (compare(array+j*elementSize, array+right*elementSize) * coefficient <= 0) {
           i++;
           swap(array+i*elementSize, array+j*elementSize, elementSize);
       }
   }
   swap(array+(i+1)*elementSize, array+right*elementSize, elementSize);
   return (i+1);
}

int randomizedPartition(void * array, int left, int right, int elementSize, int (*compare)(const void *, const void *), bool reverse)
{
    srand(time(NULL));
    int i = left + rand() / (RAND_MAX / (right-left+1) + 1); 
    swap(array+right*elementSize, array+i*elementSize, elementSize);
    return partition(array, left, right, elementSize, compare, reverse);
}

