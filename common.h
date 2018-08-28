#ifndef COMMON_H_
#define COMMON_H_

#include <stdbool.h>

void swap(void * a, void * b, int elementSize);
int merge(void * array, int left, int middle, int right, int elementSize, int (*compare)(const void *, const void *),
          bool reverse);

#endif
