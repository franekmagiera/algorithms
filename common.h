#ifndef COMMON_H_
#define COMMON_H_

#include <stdbool.h>

void swap(void * a, void * b, int elementSize);
int merge(void * array, int left, int middle, int right, int elementSize, int (*compare)(const void *, const void *),
          bool reverse);
int minimum(void * array, int arraySize, int elementSize, int (*compare)(const void *, const void *));
int maximum(void * array, int arraySize, int elementSize, int (*compare)(const void *, const void *));
void minmax(void * array, int arraySize, int elementSize, int (*compare)(const void *, const void *), int * min, int * max);
int partition(void * array, int left, int right, int elementSize, int (*compare)(const void *, const void *), bool reverse);
int randomizedPartition(void * array, int left, int right, int elementSize, int (*compare)(const void *, const void *), bool reverse);

#endif
