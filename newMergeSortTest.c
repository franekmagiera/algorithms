#include "sort.h"
#include "compare.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int array[150];
    srand(time(NULL));
    for (int i = 0; i <150; i++) {
        array[i] = rand() % 11;
        printf("%d ", array[i]);
    }
    putchar('\n');
    newMergeSort(array, 0,149, sizeof(int), compareInts, 1);
    for (int i = 0; i <150; i++)
        printf("%d ", array[i]);
    putchar('\n');
    return 0;
}
