#include <stdio.h>
#include <stdbool.h>
#include "sort.h"
#include "compare.h"

int main()
{
    int array[] = {2, 8, 7, 1, 3, 5, 6, 4};
    for (int i = 0; i < sizeof(array)/sizeof(*array); i++)
        printf("%d ", array[i]);
    putchar('\n');
    randomizedQuicksort(array, 0, sizeof(array)/sizeof(*array)-1, sizeof(*array), compareInts, false);
    for (int i = 0; i < sizeof(array)/sizeof(*array); i++)
        printf("%d ", array[i]);
    putchar('\n');
    randomizedQuicksort(array, 0, sizeof(array)/sizeof(*array)-1, sizeof(*array), compareInts, true);
    for (int i = 0; i < sizeof(array)/sizeof(*array); i++)
        printf("%d ", array[i]);
    putchar('\n');
    return 0;
}
