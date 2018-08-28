#include "common.h"
#include <stdlib.h>
#include <string.h>

void swap(void * a, void * b, int elementSize)
{
	for(int i = 0; i < elementSize; i++) {
		char temp = ((char *) a)[i];
		((char *) a)[i] = ((char *) b)[i];
		((char *) b)[i] = temp;
	}
}

int merge(void * array, int left, int middle, int right, int elementSize, int (*compare)(const void *, const void *),
          bool reverse)
{
    int coefficient = (reverse) ? (-1) : (1);
	int n1 = middle - left + 1;
	void * A = malloc(n1*elementSize);
	if (A == NULL) {
		exit(EXIT_FAILURE);
	}
	int n2 = right - middle;
	void * B = malloc(n2*elementSize);
	if (B == NULL)
		exit(EXIT_FAILURE);
	memcpy(A,array+left*elementSize,n1*elementSize);
	memcpy(B,array+(middle+1)*elementSize,n2*elementSize);
	int i = 0, j = 0, inversions = 0, k = left;
	while (i < n1 && j < n2){
		if (compare(A+i*elementSize, B+j*elementSize) * coefficient <= 0) {
			memcpy(array+k*elementSize, A+i*elementSize, elementSize);
			i++;
			k++;
		} else {
			memcpy(array+k*elementSize, B+j*elementSize, elementSize);
			j++;
			k++;
			inversions += n1 - i;
		}
	}
	if (i < n1)
		memcpy(array+k*elementSize, A+i*elementSize, (n1-i)*elementSize);
	if (j < n2) {
		memcpy(array+k*elementSize, B+j*elementSize, (n2-j)*elementSize);
	}
	free(B);
	free(A);
	return inversions;
}
