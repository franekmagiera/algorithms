/*
 * main.c
 *
 *  Created on: 15 lip 2018
 *      Author: Franek
 */

#include "Algorithms.h"
#include <stdio.h>

int main()
{
	int A[] = {31, 41, 59, 26, 41, 58};

	int Alength = sizeof(A) / sizeof(A[0]);

	printf("Before sorting:\n");
	for (int i = 0; i < Alength; i++)
		printf("%d ", A[i]);
	putchar('\n');

	insertionSort(A, Alength, sizeof(A[0]), compareInts);

	printf("After sorting:\n");
	for (int i = 0; i < Alength; i++)
		printf("%d ", A[i]);
	putchar('\n');

	int value = 31;
	printf("The index of number 31 in A is: %d\n", linearSearch(A, Alength, sizeof(A[0]), compareInts, &value) + 1);

	printf("The index of number 31 in A is: %d\n", binarySearch(A, 0, Alength-1, sizeof(A[0]), compareInts, &value) + 1);

	int TAB[] = {2,3,8,6,1};
	int TABlength = sizeof(TAB)/sizeof(TAB[0]);

	for (int i = 0; i < TABlength; i++)
		printf("%d ", TAB[i]);
	putchar('\n');

	printf("The number of inversions in TAB = %d\n", countInversions(TAB, 0, TABlength - 1, sizeof(TAB[0]), compareInts));

	for (int i = 0; i < TABlength; i++)
		printf("%d ", TAB[i]);
	putchar('\n');

	return 0;
}
