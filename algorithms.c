#include "algorithms.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int linearSearch(void * array, int arraySize, int elementSize, int (*compare)(const void *, const void *), const void * value)
{
	for (int i = 0; i < arraySize; i++) {
		if (compare(array+i*elementSize, value) == 0)
			return i;
	}
	return -1;
}

void sumBinaryNumbers(int * A, int * B, int * sum, int numberLength)
{
	for (int i = 0; i < numberLength + 1; i++)
		sum[i] = 0;
	for (int i = 0; i < numberLength; i++) {
		if (A[i] == 1 && B[i] == 1) {
			sum[i+1] += 1;
		}
		else if (A[i] == 0 && B[i] == 0)
			;
		else
			sum[i] += 1;
	}
	// C[i] <= 2 for every i[0, n]
	for (int i = 0; i < numberLength + 1; i++)
		if (sum[i] == 2) {
			sum[i+1] += 1;
			sum[i] = 0;
		}
}

int binarySearch(void * array, int left, int right, int elementSize, int (*compare)(const void *, const void *), const void * value)
{
	if (right < left)
		return -1;
	int middle = (right + left) / 2;
	int cmpResult = compare(array+middle*elementSize, value);
	if (cmpResult == 0)
		return middle;
	else if (cmpResult < 0)
		return binarySearch(array, middle+1, right, elementSize, compare, value);
	else
		return binarySearch(array, left, middle-1, elementSize, compare, value);
}

int countInversions(void * array, int left, int right, int elementSize, int (*compare)(const void *, const void *))
{
	int inversions = 0;
	if (left < right) {
		int middle = (left + right) / 2;
		inversions += countInversions(array, left, middle, elementSize, compare);
		inversions += countInversions(array, middle+1, right, elementSize, compare);
		inversions += merge(array, left, middle, right, elementSize, compare, 1);
	}
	return inversions;
}
