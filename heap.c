#include "heap.h"
#include "common.h"

void initHeap(void * array, int size, int elementSize, Heap * heap)
{
    heap->array = array;
    heap->elementSize = elementSize;
    heap->size = heap->heapSize = size;
}

void maxHeapify(Heap * heap, int i, int (*compare)(const void *, const void *))
{
    int left = left(i);
    int right = right(i);
    int largest;
    if (left < heap->heapSize && compare(heap->array+left*heap->elementSize, heap->array+i*heap->elementSize) > 0) 
        largest = left;
    else
        largest = i;
    if (right < heap->heapSize && compare(heap->array+right*heap->elementSize, heap->array+largest*heap->elementSize) > 0) 
        largest = right;
    if (largest != i) {
        swap(heap->array+i*heap->elementSize, heap->array+largest*heap->elementSize, heap->elementSize);
        maxHeapify(heap, largest, compare);
    }
}

void buildMaxHeap(Heap * heap, int (*compare)(const void *, const void *))
{
    heap->heapSize = heap->size;
    for (int i = (heap->size-1) / 2; i >= 0; i--)
        maxHeapify(heap, i, compare);
}

void heapsort(Heap * heap, int (*compare)(const void *, const void *))
{
    buildMaxHeap(heap, compare);
    for (int i = heap->size - 1; i > 0; i--) {
        swap(heap->array, heap->array+i*heap->elementSize, heap->elementSize);
        heap->heapSize--;
        maxHeapify(heap, 0, compare);
    }
}
