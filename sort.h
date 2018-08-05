#ifndef SORT_H_
#define SORT_H_

void selectionSort(void * array, int arraySize, int elementSize, int (*compare)(const void *, const void *), int var);
void insertionSort(void * array, int arraySize, int elementSize, int (*compare)(const void *, const void *), int var);
void bubbleSort(void * array, int arraySize, int elementSize, int (*compare)(const void *, const void *), int var);
void mergeSort(void * array, int left, int right, int elementSize, int (*compare)(const void *, const void *), int var);
void newMergeSort(void * array, int left, int right, int elementSize, int (*compare)(const void *, const void *), int var);

#endif /* SORT_H_ */
