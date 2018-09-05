#include "sort.h"
#include "common.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define BORDER_VALUE 17 // moreless for this value or lower insertion sort runs faster than mergesort

void selectionSort(void * array, int arraySize, int elementSize, int (*compare)(const void *, const void *), bool reverse)
{
    int coefficient = (reverse) ? (-1) : (1);
	int index;
	for (int i = 0; i < arraySize - 1; i++) {
		index = i;
		for (int j = i + 1; j < arraySize; j++)
			if (compare(array+j*elementSize, array+index*elementSize) * coefficient < 0) {
				index = j;
			}
		if (index != i)
			swap(array+i*elementSize, array+index*elementSize, elementSize);
	}
}

void insertionSort(void * array, int arraySize, int elementSize, int (*compare)(const void *, const void *), bool reverse)
{
    int coefficient = (reverse) ? (-1) : (1);
	int index;
	for (int i = 1; i < arraySize; i++) {
		int j = i - 1;
		while (j >= 0 && compare(array+(j+1)*elementSize, array+j*elementSize) * coefficient < 0) {
			swap(array+j*elementSize, array+(j+1)*elementSize, elementSize);
			j--;
		}
	}
}

void bubbleSort(void * array, int arraySize, int elementSize, int (*compare)(const void *, const void *), bool reverse)
{
    int coefficient = (reverse) ? (-1) : (1);
	int index;
	for (int j = 0; j < arraySize; j++) {
		for (int i = 1; i < arraySize - j; i++) {
			if (compare(array+i*elementSize, array+(i-1)*elementSize) * coefficient < 0)
				swap(array+i*elementSize, array+(i-1)*elementSize, elementSize);
		}
	}
}

void mergeSort(void * array, int left, int right, int elementSize, int (*compare)(const void *, const void *), bool reverse)
{
	if (left < right) {
		int middle = (left + right) / 2;
		mergeSort(array, left, middle, elementSize, compare, reverse);
		mergeSort(array, middle + 1, right, elementSize, compare, reverse);
		merge(array, left, middle, right, elementSize, compare, reverse);
	}
}

void newMergeSort(void * array, int left, int right, int elementSize, int (*compare)(const void*, const void*), bool reverse)
{
    if (right - left + 1 > BORDER_VALUE) {
        int middle = (left + right) / 2;
		mergeSort(array, left, middle, elementSize, compare, reverse);
		mergeSort(array, middle + 1, right, elementSize, compare, reverse);
		merge(array, left, middle, right, elementSize, compare, reverse);
    } else
        insertionSort(array, right-left+1, elementSize, compare, reverse);
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

void quicksort(void * array, int left, int right, int elementSize, int (*compare)(const void *, const void *), bool reverse)
{
    if (left < right) {
        int q = partition(array, left, right, elementSize, compare, reverse);
        quicksort(array, left, q-1, elementSize, compare, reverse);
        quicksort(array, q+1, right, elementSize, compare, reverse);
    }
}

int randomizedPartition(void * array, int left, int right, int elementSize, int (*compare)(const void *, const void *), bool reverse)
{
    srand(time(NULL));
    int i = left + rand() / (RAND_MAX / (right-left+1) + 1); 
    swap(array+right*elementSize, array+i*elementSize, elementSize);
    return partition(array, left, right, elementSize, compare, reverse);
}

void randomizedQuicksort(void * array, int left, int right, int elementSize, int (*compare)(const void *, const void *), bool reverse)
{
    if (left < right) {
    int q = randomizedPartition(array, left, right, elementSize, compare, reverse);
    randomizedQuicksort(array, left, q-1, elementSize, compare, reverse);
    randomizedQuicksort(array, q+1, right, elementSize, compare, reverse);
    }
}
