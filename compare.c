#include "compare.h"
#include <string.h>

int compareInts(const void * a, const void * b)
{
	const int *x = (int *) a;
	const int *y = (int *) b;
	if (*x < *y) return -1;
	else if (*x == *y) return 0;
	else return 1;
}

int compareDoubles(const void * a, const void * b)
{
	const double *x = (double *) a;
	const double *y = (double *) b;
	if (*x < *y) return -1;
	else if (*x == *y) return 0;
	else return 1;
}

int compareStrings(const void * a, const void * b)
{
	const char *x = *(const char **) a;
	const char *y = *(const char **) b;

	return strcmp(x,y);
}
