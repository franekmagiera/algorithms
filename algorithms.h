#ifndef ALGORITHMS_H_
#define ALGORITHMS_H_

int linearSearch(void * array, int arraySize, int elementSize, int (*compare)(const void *, const void *), const void * value);
void sumBinaryNumbers(int * A, int * B, int * sum, int numberLength); // A + B = sum
int binarySearch(void * array, int left, int right, int elementSize, int (*compare)(const void *, const void *), const void * value);
int countInversions(void * array, int left, int right, int elementSize, int (*compare)(const void *, const void *));

#endif /* ALGORITHMS_H_ */
