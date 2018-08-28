#include "sort.h"
#include "compare.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main()
{
    int array[10];
    srand(time(NULL));
    for (int i = 0; i <10; i++) {
        array[i] = rand() % 11;
        printf("%d ", array[i]);
    }
    putchar('\n');
    newMergeSort(array, 0,9, sizeof(int), compareInts, false);
    for (int i = 0; i <10; i++)
        printf("%d ", array[i]);
    putchar('\n');
    return 0;
}
