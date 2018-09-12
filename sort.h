#ifndef SORT_H_
#define SORT_H_

#include <stdbool.h>

void selectionSort(void * array, int arraySize, int elementSize, int (*compare)(const void *, const void *), bool reverse);
void insertionSort(void * array, int arraySize, int elementSize, int (*compare)(const void *, const void *), bool reverse);
void bubbleSort(void * array, int arraySize, int elementSize, int (*compare)(const void *, const void *), bool reverse);
void mergeSort(void * array, int left, int right, int elementSize, int (*compare)(const void *, const void *), bool reverse);
void newMergeSort(void * array, int left, int right, int elementSize, int (*compare)(const void *, const void *), bool reverse);
int partition(void * array, int left, int right, int elementSize, int (*compare)(const void *, const void *), bool reverse);
void quicksort(void * array, int left, int right, int elementSize, int (*compare)(const void *, const void *), bool reverse);
int randomizedPartition(void * array, int left, int right, int elementSize, int (*compare)(const void *, const void *), bool reverse);
void randomizedQuicksort(void * array, int left, int right, int elementSize, int (*compare)(const void *, const void *), bool reverse);
void countingSort(int *A, int *B, int k, int size);

#endif /* SORT_H_ */
