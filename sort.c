#include "sort.h"
#include "common.h"
#include <string.h>
#include <stdlib.h>

#define BORDER_VALUE 17 // moreless for this value or lower insertion sort runs faster than mergesort

void selectionSort(void * array, int arraySize, int elementSize, int (*compare)(const void *, const void *), int var)
{
	int index;
	for (int i = 0; i < arraySize - 1; i++) {
		index = i;
		for (int j = i + 1; j < arraySize; j++)
			if (compare(array+j*elementSize, array+index*elementSize) * var < 0) {
				index = j;
			}
		if (index != i)
			swap(array+i*elementSize, array+index*elementSize, elementSize);
	}
}

void insertionSort(void * array, int arraySize, int elementSize, int (*compare)(const void *, const void *), int var)
{
	for (int i = 1; i < arraySize; i++) {
		int j = i - 1;
		while (j >= 0 && compare(array+(j+1)*elementSize, array+j*elementSize) * var < 0) {
			swap(array+j*elementSize, array+(j+1)*elementSize, elementSize);
			j--;
		}
	}
}

void bubbleSort(void * array, int arraySize, int elementSize, int (*compare)(const void *, const void *), int var)
{
	for (int j = 0; j < arraySize; j++) {
		for (int i = 1; i < arraySize - j; i++) {
			if (compare(array+i*elementSize, array+(i-1)*elementSize) * var < 0)
				swap(array+i*elementSize, array+(i-1)*elementSize, elementSize);
		}
	}
}

void mergeSort(void * array, int left, int right, int elementSize, int (*compare)(const void *, const void *), int var)
{
	if (left < right) {
		int middle = (left + right) / 2;
		mergeSort(array, left, middle, elementSize, compare, var);
		mergeSort(array, middle + 1, right, elementSize, compare, var);
		merge(array, left, middle, right, elementSize, compare, var);
	}
}

void newMergeSort(void * array, int left, int right, int elementSize, int (*compare)(const void*, const void*), int var)
{
    if (right - left + 1 > BORDER_VALUE) {
        int middle = (left + right) / 2;
		mergeSort(array, left, middle, elementSize, compare, var);
		mergeSort(array, middle + 1, right, elementSize, compare, var);
		merge(array, left, middle, right, elementSize, compare, var);
    } else
        insertionSort(array, right-left+1, elementSize, compare, var);
}
