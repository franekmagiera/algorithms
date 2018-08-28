#ifndef HEAP_H_
#define HEAP_H_

#define parent(i) ((i-1)/2)
#define left(i) (2*i+1)
#define right(i) (2*i+2)

typedef struct Heap {
    void * array;
    int size;
    int elementSize;
    int heapSize;
} Heap;

void initHeap(void * array, int size, int elementSize, Heap * heap);
void maxHeapify(Heap * heap, int i, int (*compare)(const void *, const void *));
void buildMaxHeap(Heap * heap, int (*compare)(const void *, const void *));
void heapsort(Heap * heap, int (*compare)(const void *, const void *));

#endif
