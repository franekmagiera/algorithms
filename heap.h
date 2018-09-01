#ifndef HEAP_H_
#define HEAP_H_

#include <stdbool.h>

// for 0 based arrays
#define parent(i) ((i-1)/2)
#define left(i) (2*i+1)
#define right(i) (2*i+2)

typedef struct Heap {
    void * array;
    int size;
    int elementSize;
    int heapSize;
} Heap;

// initHeap is used to associate an array as a heap
void initHeap(void * array, int size, int elementSize, Heap * heap);
void heapify(Heap * heap, int i, int (*compare)(const void *, const void *), bool min);
void buildHeap(Heap * heap, int (*compare)(const void *, const void *), bool min);
void heapsort(Heap * heap, int (*compare)(const void *, const void *), bool reversed);

#endif
