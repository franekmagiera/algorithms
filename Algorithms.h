/*
 * Algorithms.h
 *
 *  Created on: 15 lip 2018
 *      Author: Franek
 */

#ifndef ALGORITHMS_H_
#define ALGORITHMS_H_

void swap(void * a, void * b, int elementSize);
int compareInts(const void * a, const void * b);
void insertionSort(void * array, int arraySize, int elementSize, int (*compare)(const void *, const void *));
int linearSearch(void * array, int arraySize, int elementSize, int (*compare)(const void *, const void *), const void * value);
void sumBinaryNumbers(int * A, int * B, int * sum, int numberLength); // A + B = sum
int binarySearch(void * array, int left, int right, int elementSize, int (*compare)(const void *, const void *), const void * value);
int merge(void * array, int left, int middle, int right, int elementSize, int (*compare)(const void *, const void *));
int countInversions(void * array, int left, int right, int elementSize, int (*compare)(const void *, const void *));

#endif /* ALGORITHMS_H_ */
