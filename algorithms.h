#ifndef ALGORITHMS_H_
#define ALGORITHMS_H_

typedef struct Vector3d {
    double x;
    double y;
    double z;
} Vector3d;

int linearSearch(void * array, int arraySize, int elementSize, int (*compare)(const void *, const void *), const void * value);
void sumBinaryNumbers(int * A, int * B, int * sum, int numberLength); // A + B = sum
int binarySearch(void * array, int left, int right, int elementSize, int (*compare)(const void *, const void *), const void * value);
int countInversions(void * array, int left, int right, int elementSize, int (*compare)(const void *, const void *));
void findMaximalSubarray(double * array, int arraySize, Vector3d * results);
void findMaximalCrossingSubarray(double * array, int left, int middle, int right, Vector3d * results);
void findMaximalSubarray2(double * array, int left, int right, Vector3d * results);
void findMaximalSubarrayLinear(double * array, int arraySize, Vector3d * results);
// randomizedSelect changes the positions of elements in the array
// i is a measure of position
int randomizedSelect(void * array, int left, int right, int i, int elementSize, int (*compare)(const void *, const void *));

#endif /* ALGORITHMS_H_ */
