/*
 * Algorithms.c
 *
 *  Created on: 15 lip 2018
 *      Author: Franek
 */

#include "Algorithms.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void * a, void * b, int elementSize)
{
	for (int i = 0; i < elementSize; i++) {
		char temp = ((char *) a)[i];
		((char *) a)[i] = ((char *) b)[i];
		((char *) b)[i] = temp;
	}
}

int compareInts(const void * a, const void * b)
{
	const int *x = (int *) a;
	const int *y = (int *) b;

	if (*x < *y) return -1;
	else if (*x == *y) return 0;
	else return 1;
}

void insertionSort(void * array, int arraySize, int elementSize, int (*compare)(const void *, const void *))
{
	for (int j = 1; j < arraySize; j++) {
		int i = j - 1;
		while (compare(array+(i+1)*elementSize, array+i*elementSize) < 0 && i >=0) {
			swap(array+(i+1)*elementSize, array+i*elementSize, elementSize);
			i--;
		}
	}
}

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

int merge(void * array, int left, int middle, int right, int elementSize, int (*compare)(const void *, const void *))
{
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
		if (compare(A+i*elementSize, B+j*elementSize) <= 0) {
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

int countInversions(void * array, int left, int right, int elementSize, int (*compare)(const void *, const void *))
{
	int inversions = 0;
	if (left < right) {
		int middle = (left + right) / 2;
		inversions += countInversions(array, left, middle, elementSize, compare);
		inversions += countInversions(array, middle+1, right, elementSize, compare);
		inversions += merge(array, left, middle, right, elementSize, compare);
	}
	return inversions;
}
