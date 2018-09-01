#include "heap.h"
#include "common.h"

void initHeap(void * array, int size, int elementSize, Heap * heap)
{
    heap->array = array;
    heap->elementSize = elementSize;
    heap->size = heap->heapSize = size;
}

void heapify(Heap * heap, int i, int (*compare)(const void *, const void *), bool min)
{
    int coefficient = (min) ? (-1) : (1);
    int left = left(i);
    int right = right(i);
    int extremum;
    if (left < heap->heapSize && compare(heap->array+left*heap->elementSize, heap->array+i*heap->elementSize)*coefficient > 0) 
        extremum = left;
    else
        extremum = i;
    if (right < heap->heapSize && compare(heap->array+right*heap->elementSize, heap->array+extremum*heap->elementSize)*coefficient > 0) 
        extremum = right;
    if (extremum != i) {
        swap(heap->array+i*heap->elementSize, heap->array+extremum*heap->elementSize, heap->elementSize);
        heapify(heap, extremum, compare, min);
    }
}

void buildHeap(Heap * heap, int (*compare)(const void *, const void *), bool min)
{
    heap->heapSize = heap->size;
    for (int i = (heap->size-1) / 2; i >= 0; i--)
        heapify(heap, i, compare, min);
}

void heapsort(Heap * heap, int (*compare)(const void *, const void *), bool reversed)
{
    buildHeap(heap, compare, reversed);
    for (int i = heap->size - 1; i > 0; i--) {
        swap(heap->array, heap->array+i*heap->elementSize, heap->elementSize);
        heap->heapSize--;
        heapify(heap, 0, compare, reversed);
    }
}
