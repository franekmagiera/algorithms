#include "algorithms.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int linearSearch(void * array, int arraySize, int elementSize, int (*compare)(const void *, const void *), const void * value)
{
	for (int i = 0; i < arraySize; i++) {
		if (compare(array+i*elementSize, value) == 0)
			return i;
	}
	return -1;
}

void sumBinaryNumbers(int * A, int * B, int * sum, int numberLength)
{
	for (int i = 0; i < numberLength + 1; i++)
		sum[i] = 0;
	for (int i = 0; i < numberLength; i++) {
		if (A[i] == 1 && B[i] == 1) {
			sum[i+1] += 1;
		}
		else if (A[i] == 0 && B[i] == 0)
			;
		else
			sum[i] += 1;
	}
	// C[i] <= 2 for every i[0, n]
	for (int i = 0; i < numberLength + 1; i++)
		if (sum[i] == 2) {
			sum[i+1] += 1;
			sum[i] = 0;
		}
}

int binarySearch(void * array, int left, int right, int elementSize, int (*compare)(const void *, const void *), const void * value)
{
	if (right < left)
		return -1;
	int middle = (right + left) / 2;
	int cmpResult = compare(array+middle*elementSize, value);
	if (cmpResult == 0)
		return middle;
	else if (cmpResult < 0)
		return binarySearch(array, middle+1, right, elementSize, compare, value);
	else
		return binarySearch(array, left, middle-1, elementSize, compare, value);
}

int countInversions(void * array, int left, int right, int elementSize, int (*compare)(const void *, const void *))
{
	int inversions = 0;
	if (left < right) {
		int middle = (left + right) / 2;
		inversions += countInversions(array, left, middle, elementSize, compare);
		inversions += countInversions(array, middle+1, right, elementSize, compare);
		inversions += merge(array, left, middle, right, elementSize, compare, 1);
	}
	return inversions;
}

void findMaximalSubarray(double * array, int arraySize, Vector3d * results)
{
   int left_index = 0, right_index = 0;
   double sum = array[0];
   for (int i = 0; i < arraySize; i++) {
       double helper_sum = 0;
       for (int j = i; j < arraySize; j++) {
           helper_sum += array[j];
           if (helper_sum > sum) {
              sum = helper_sum;
              left_index = i;
              right_index = j;
           }
       }
   }
   results->x = left_index;
   results->y = right_index;
   results->z = sum;
}

void findMaximalCrossingSubarray(double * array, int left, int middle, int right, Vector3d * results)
{
    double left_sum = array[middle];
    double sum = array[middle];
    int left_index = middle;
    for (int i = middle - 1; i >= 0; i--) {
        sum += array[i];
        if (sum > left_sum) {
            left_sum = sum;
            left_index = i;
        }
    }
    double right_sum = array[middle + 1];
    int right_index = middle + 1;
    sum = array[middle + 1];
    for (int i = middle + 2; i <= right; i++) {
        sum += array[i];
        if (sum > right_sum) {
            right_sum = sum;
            right_index = i;
        }
    }
    results->x = left_index;
    results->y = right_index;
    results->z = left_sum + right_sum;
}

void findMaximalSubarray2(double * array, int left, int right, Vector3d * results)
{
   if (left == right) {
       results->x = left;
       results->y = right;
       results->z = array[left];
       return;
   } else {
       int middle = (left + right) / 2;
       Vector3d left_results, right_results, cross_results;
       findMaximalSubarray2(array, left, middle, &left_results);
       findMaximalSubarray2(array, middle + 1, right, &right_results);
       findMaximalCrossingSubarray(array, left, middle, right, &cross_results);
       if (left_results.z >= right_results.z && left_results.z >=
           cross_results.z) {
           results->x = left_results.x;
           results->y = left_results.y;
           results->z = left_results.z;
           return;
       } else if (right_results.z >= left_results.z && right_results.z >=
       cross_results.z) {
           results->x = right_results.x;
           results->y = right_results.y;
           results->z = right_results.z;
           return;
       } else {
           results->x = cross_results.x;
           results->y = cross_results.y;
           results->z = cross_results.z;
           return;
       }
   }
}

void findMaximalSubarrayLinear(double * array, int arraySize, Vector3d * results)
{
    double sum = 0, helper_sum = 0;
    int left_index = 0, right_index = 0, helper_left = 0;
    for (int i = 0; i < arraySize; i++) {
        helper_sum = (array[i] > helper_sum + array[i] ? array[i] : helper_sum + array[i]);
        if (helper_sum > sum) {
            sum = helper_sum;
            right_index = i;
            left_index = helper_left;
        } 
        if (helper_sum == array[i])
            helper_left = i;
    }
    results->x = left_index;
    results->y = right_index;
    results->z = sum;
}

int randomizedSelect(void * array, int left, int right, int i, int elementSize, int (*compare)(const void *, const void *))
{
    if (left == right) 
        return left;
    int q = randomizedPartition(array, left, right, elementSize, compare, false); 
    int k = q-left+1;
    if (i == k)
        return q;
    else if (i < k)
        return randomizedSelect(array, left, q-1, i, elementSize, compare);
    else return randomizedSelect(array, q+1, right, i-k, elementSize, compare);
}

