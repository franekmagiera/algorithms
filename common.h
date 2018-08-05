#ifndef COMMON_H_
#define COMMON_H_

void swap(void * a, void * b, int elementSize);
int merge(void * array, int left, int middle, int right, int elementSize, int (*compare)(const void *, const void *), int var);

#endif
