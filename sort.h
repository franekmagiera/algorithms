#ifndef SORT_H_
#define SORT_H_

#include <stdbool.h>

void selectionSort(void * array, int arraySize, int elementSize, int (*compare)(const void *, const void *), bool reverse);
void insertionSort(void * array, int arraySize, int elementSize, int (*compare)(const void *, const void *), bool reverse);
void bubbleSort(void * array, int arraySize, int elementSize, int (*compare)(const void *, const void *), bool reverse);
void mergeSort(void * array, int left, int right, int elementSize, int (*compare)(const void *, const void *), bool reverse);
void newMergeSort(void * array, int left, int right, int elementSize, int (*compare)(const void *, const void *), bool reverse);

#endif /* SORT_H_ */
