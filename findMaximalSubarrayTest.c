#include "algorithms.h"
#include <stdio.h>

void printArrayOfDoubles(double array[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%f ", array[i]);
    putchar('\n');
}

int main()
{
    double array[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    printArrayOfDoubles(array, sizeof(array)/sizeof(array[0]));
    Vector3d results;
//    findMaximalSubarray(array, sizeof(array)/sizeof(array[0]), &results);
//    findMaximalSubarray2(array, 0, sizeof(array)/sizeof(array[0]) - 1, &results);
    findMaximalSubarrayLinear(array, sizeof(array)/sizeof(array[0]), & results);
    printf("The maximal subarray is:\n");
    for (int i = results.x; i < results.y + 1; i++)
        printf("%f ", array[i]);
    putchar('\n');
    printf("The sum of the maximal subarray is: %f\n", results.z);
    return 0;
}
