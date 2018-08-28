#include "sort.h"
#include "compare.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int isSorted(void * array, int arraySize, int elementSize, int (*compare)(const void *, const void *), int var)
{
    for (int i = 0; i < arraySize-1; i++)
        if (compare(array+i*elementSize, array+(i+1)*elementSize) * var > 0)
            return 0;
    return 1;
}

int main()
{
    const int SIZE = 15000000;
    int * array = malloc(SIZE*sizeof(int));
    int * copy = malloc(SIZE*sizeof(int));
    if (array == NULL || copy == NULL)
        exit(EXIT_FAILURE);
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
        array[i] = rand();
    memcpy(copy, array, SIZE*sizeof(int));
    if (isSorted(copy, SIZE, sizeof(int), compareInts, 1) == 0)
        printf("It is unsorted.\n");
    clock_t start = clock();
    mergeSort(copy, 0, SIZE-1, sizeof(int), compareInts, false);
    clock_t end = clock();
    if (isSorted(copy, SIZE, sizeof(int), compareInts, 1) == 0)
        exit(EXIT_FAILURE);
    double oldTime = (double) (end - start) / CLOCKS_PER_SEC;
    memcpy(copy, array, SIZE*sizeof(int));
    start = clock();
    newMergeSort(copy, 0, SIZE-1, sizeof(int), compareInts, false);
    end = clock();
    if (isSorted(copy, SIZE, sizeof(int), compareInts, 1) == 0)
        exit(EXIT_FAILURE);
    double newTime = (double) (end - start) / CLOCKS_PER_SEC;
    printf("New algorithm's time: %f\n", newTime);
    printf("Old algorithm's time: %f\n", oldTime);
    printf("The difference: %f\n", oldTime - newTime);
    free(array);
    free(copy);
    exit(EXIT_SUCCESS);
}
