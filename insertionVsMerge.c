#include "sort.h"
#include "compare.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int * generateRandomArray(int n, int elementSize)
{
   int * array = malloc(n * elementSize);
   if (array == NULL)
       exit(EXIT_FAILURE);
   for (int i = 0; i < n; i++)
       array[i] = rand() % 20;
   return array;
}

int main()
{
   srand(time(NULL));
   int i =3; 
   double insertionSortTime, mergeSortTime;
   do {
    int * array = generateRandomArray(i, sizeof(int));
    int * copy = malloc(sizeof(int)*i);
    memcpy(copy, array, sizeof(int)*i);
    clock_t beginInsertionSort = clock();
    insertionSort(copy, i, sizeof(int), compareInts, 1);
    clock_t endInsertionSort = clock();
    insertionSortTime = (double) (endInsertionSort - beginInsertionSort) / CLOCKS_PER_SEC;
    memcpy(copy, array, sizeof(int)*i);
    clock_t beginMergeSort = clock();
    mergeSort(copy, 0, i-1, sizeof(int), compareInts, 1);
    clock_t endMergeSort = clock();
    mergeSortTime = (double) (endMergeSort - beginMergeSort) / CLOCKS_PER_SEC;
    free(array);
    free(copy);
    i++;
   } while (mergeSortTime >= insertionSortTime);
   printf("Merge sort begins to run faster than insertion sort for the array of size %d\n", i-1);
   printf("Merge sort time: %f\nInsertion sort time: %f\n", mergeSortTime, insertionSortTime);

   int * array = generateRandomArray(i, sizeof(int));
   for (int j = 0; j < i; j++)
       printf("%d ", array[j]);
   putchar('\n');
   mergeSort(array, 0, i-1, sizeof(int), compareInts, -1);
   for (int j = 0; j < i; j++)
       printf("%d ", array[j]);
   putchar('\n');
   insertionSort(array, i, sizeof(int), compareInts, 1);
   for (int j = 0; j < i; j++)
       printf("%d ", array[j]);
   putchar('\n');

   exit(EXIT_SUCCESS);
}
